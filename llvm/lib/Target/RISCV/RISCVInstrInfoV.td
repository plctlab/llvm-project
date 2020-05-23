//===-- RISCVInstrInfoV.td - RISC-V 'V' instructions -------*- tablegen -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file describes the RISC-V instructions from the standard 'V',
// Vector instruction set extension.
//
// BOTH THE VECTOR ISA SPEC AND THIS CODE ARE EXTREMELY WIP
//
//===----------------------------------------------------------------------===//

include "RISCVInstrFormatsV.td"

//===----------------------------------------------------------------------===//
// RISC-V vector extension specific DAG Nodes.
//===----------------------------------------------------------------------===//


def SDT_RISCVSETVL : SDTypeProfile<2, 2, [SDTCisVT<0, i32>,
                                          SDTCisSameAs<0, 1>,
                                          SDTCisSameAs<0, 2>,
                                          SDTCisSameAs<0, 3>]>;

def RISCVSETVL : SDNode<"RISCVISD::SETVL", SDT_RISCVSETVL>;

def SDT_RISCVBROADCAST : SDTypeProfile<1, 1, [SDTCisVT<0, nxv1i32>,
                                              SDTCisVT<1, i32>]>;

def RISCVBROADCAST : SDNode<"RISCVISD::BROADCAST", SDT_RISCVBROADCAST>;

//===----------------------------------------------------------------------===//
// Operand and SDNode transformation definitions.
//===----------------------------------------------------------------------===//

def simm5 : Operand<XLenVT>, ImmLeaf<XLenVT, [{return isInt<5>(Imm);}]> {
  let ParserMatchClass = SImmAsmOperand<5>;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeSImmOperand<5>";
}

def simm5PlusOne : Operand<XLenVT>, ImmLeaf<XLenVT, [{return isInt<5>(Imm - 1);}]> {
  let ParserMatchClass = SImmAsmOperand<5, "PlusOne">;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeSImmOperand<5>";
}

def uimm11 : Operand<XLenVT>, ImmLeaf<XLenVT, [{return isUInt<11>(Imm);}]> {
  let ParserMatchClass = UImmAsmOperand<11>;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeUImmOperand<11>";
}

def VTypeImmOperand : AsmOperandClass {
  let Name = "VTypeI";
  let ParserMethod = "parseVTypeImmOperand";
  let DiagnosticType = "InvalidVTypeIAsmOperand";
}

def vtypei : Operand<XLenVT> {
  let ParserMatchClass = VTypeImmOperand;
  let PrintMethod = "printVTypeI";
  let DecoderMethod = "decodeUImmOperand<11>";
}

def VRMaskAsmOperand : AsmOperandClass {
  let Name = "RVVMaskRegOpOperand";
  let RenderMethod = "addRegOperands";
  let PredicateMethod = "isV0Reg";
  let ParserMethod = "parseMaskRegister";
  let IsOptional = 1;
  let DefaultMethod = "defaultRVVMaskRegOp";
  let DiagnosticType = "InvalidVRMaskAsmOperand";
}

def VMR: RegisterOperand<VRV0> {
  let ParserMatchClass = VRMaskAsmOperand;
  let PrintMethod = "printVMR";
  let EncoderMethod = "getVMR";
  // let DecoderMethod = "decodeVMR";
}

def Zero : Operand<XLenVT>, ImmLeaf<XLenVT, [{return Imm == 0;}]> {
  let ParserMatchClass = ImmZeroAsmOperand;
  let PrintMethod = "printZero";
}

//===----------------------------------------------------------------------===//
// Instruction class templates
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
multiclass VLoad_UnitStride<bits<3> nf, bits<3> mop,
                            bits<3> width, string opcodestr> {
  def _m  : RVInstVLoad<nf, mop, width, RVV_Masked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, Zero:$zero, VMR:$vm),
                  opcodestr, "$vd, ${zero}(${rs1}), $vm"> {
    let Inst{24-20} = 0b00000;
  }
  def _um : RVInstVLoad<nf, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, Zero:$zero),
                  opcodestr, "$vd, ${zero}(${rs1})"> {
    let Inst{24-20} = 0b00000;
  }
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
multiclass VLoad_UnitStrideFF<bits<3> nf, bits<3> mop,
                              bits<3> width, string opcodestr> {
  def _m  : RVInstVLoad<nf, mop, width, RVV_Masked, OPC_LOAD_FP,
                    (outs VR:$vd), (ins GPR:$rs1, Zero:$zero, VMR:$vm),
                    opcodestr, "$vd, ${zero}(${rs1}), $vm"> {
    let Inst{24-20} = 0b10000;
  }
  def _um : RVInstVLoad<nf, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                    (outs VR:$vd), (ins GPR:$rs1, Zero:$zero),
                    opcodestr, "$vd, ${zero}(${rs1})"> {
    let Inst{24-20} = 0b10000;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
multiclass VStore_UnitStride<bits<3> nf, bits<3> mop,
                             bits<3> width, string opcodestr> {
  def _m  : RVInstVStore<nf, mop, width, RVV_Masked, OPC_STORE_FP,
                     (outs), (ins VR:$vs3, GPR:$rs1, Zero:$zero, VMR:$vm),
                     opcodestr, "$vs3, ${zero}(${rs1}), $vm"> {
    let Inst{24-20} = 0b00000;
  }
  def _um : RVInstVStore<nf, mop, width, RVV_Unmasked, OPC_STORE_FP,
                     (outs), (ins VR:$vs3, GPR:$rs1, Zero:$zero),
                     opcodestr, "$vs3, ${zero}(${rs1})"> {
    let Inst{24-20} = 0b00000;
  }
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
multiclass VLoad_Strided<bits<3> nf, bits<3> mop,
                         bits<3> width, string opcodestr> {
  def _m  : RVInstVLoad<nf, mop, width, RVV_Masked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, GPR:$rs2, Zero:$zero, VMR:$vm),
                  opcodestr, "$vd, ${zero}(${rs1}), $rs2, $vm"> {
    bits<5> rs2;
    let Inst{24-20} = rs2;
  }
  def _um : RVInstVLoad<nf, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, GPR:$rs2, Zero:$zero),
                  opcodestr, "$vd, ${zero}(${rs1}), $rs2"> {
    bits<5> rs2;
    let Inst{24-20} = rs2;
  }
}
  
let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
multiclass VStore_Strided<bits<3> nf, bits<3> mop,
                          bits<3> width, string opcodestr> {
  def _m  : RVInstVStore<nf, mop, width, RVV_Masked, OPC_STORE_FP,
                   (outs), (ins VR:$vs3, GPR:$rs1, GPR:$rs2, Zero:$zero, VMR:$vm),
                   opcodestr, "$vs3, ${zero}(${rs1}), $rs2, $vm"> {
    bits<5> rs2;
    let Inst{24-20} = rs2;
  }
  def _um : RVInstVStore<nf, mop, width, RVV_Unmasked, OPC_STORE_FP,
                   (outs), (ins VR:$vs3, GPR:$rs1, GPR:$rs2, Zero:$zero),
                   opcodestr, "$vs3, ${zero}(${rs1}), $rs2"> {
    bits<5> rs2;
    let Inst{24-20} = rs2;
  }
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
multiclass VLoad_Indexed<bits<3> nf, bits<3> mop,
                         bits<3> width, string opcodestr> {
  def _m  : RVInstVLoad<nf, mop, width, RVV_Masked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, VR:$vs2, Zero:$zero, VMR:$vm),
                  opcodestr, "$vd, ${zero}(${rs1}), $vs2, $vm"> {
    bits<5> vs2;
    let Inst{24-20} = vs2;
  }
  def _um : RVInstVLoad<nf, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, VR:$vs2, Zero:$zero),
                  opcodestr, "$vd, ${zero}(${rs1}), $vs2"> {
    bits<5> vs2;
    let Inst{24-20} = vs2;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
multiclass VStore_Indexed<bits<3> nf, bits<3> mop,
                          bits<3> width, string opcodestr> {
  def _m  : RVInstVStore<nf, mop, width, RVV_Masked, OPC_STORE_FP,
                   (outs), (ins VR:$vs3, GPR:$rs1, VR:$vs2, Zero:$zero, VMR:$vm),
                   opcodestr, "$vs3, ${zero}(${rs1}), $vs2, $vm"> {
    bits<5> vs2;
    let Inst{24-20} = vs2;
  }
  def _um : RVInstVStore<nf, mop, width, RVV_Unmasked, OPC_STORE_FP,
                   (outs), (ins VR:$vs3, GPR:$rs1, VR:$vs2, Zero:$zero),
                   opcodestr, "$vs3, ${zero}(${rs1}), $vs2"> {
    bits<5> vs2;
    let Inst{24-20} = vs2;
  }
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
class VLoad_WholeReg<bits<3> nf, string opcodestr>
    : RVInstVLoad<nf, 0b000, 0b111, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, Zero:$zero),
                  opcodestr, "$vd, ${zero}(${rs1})"> {
  let Inst{24-20} = 0b01000;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
class VStore_WholeReg<bits<3> nf, string opcodestr>
    : RVInstVStore<nf, 0b000, 0b111, RVV_Unmasked, OPC_STORE_FP,
                   (outs), (ins VR:$vs3, GPR:$rs1, Zero:$zero),
                   opcodestr, "$vs3, ${zero}(${rs1})"> {
  let Inst{24-20} = 0b01000;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_AMO_W<bits<5> amoop, string opcodestr> {
  def _wd_m  : RVInstVAMO<amoop, 0b1, 0b110, RVV_Masked, OPC_AMO,
               (outs VR:$vd_wd),
               (ins GPR:$rs1, VR:$vs2, VR:$vd, Zero:$zero, VMR:$vm),
               opcodestr, "$vd_wd, ${zero}(${rs1}), $vs2, $vd, $vm"> {
    let Constraints = "$vd = $vd_wd";
    bits<5> vd;
    let Inst{11-7}  = vd;
  }
  def _wd_um : RVInstVAMO<amoop, 0b1, 0b110, RVV_Unmasked, OPC_AMO,
               (outs VR:$vd_wd),
               (ins GPR:$rs1, VR:$vs2, VR:$vd, Zero:$zero),
               opcodestr, "$vd_wd, ${zero}(${rs1}), $vs2, $vd"> {
    let Constraints = "$vd = $vd_wd";
    bits<5> vd;
    let Inst{11-7}  = vd;
  }
  def _m  : RVInstVAMO<amoop, 0b0, 0b110, RVV_Masked, OPC_AMO,
               (outs),
               (ins GPR:$rs1, VR:$vs2, VR:$vs3, Zero:$zero, VMR:$vm),
               opcodestr, "x0, ${zero}(${rs1}), $vs2, $vs3, $vm"> {
    bits<5> vs3;
    let Inst{11-7}  = vs3;
  }
  def _um : RVInstVAMO<amoop, 0b0, 0b110, RVV_Unmasked, OPC_AMO,
               (outs), (ins GPR:$rs1, VR:$vs2, VR:$vs3, Zero:$zero),
               opcodestr, "x0, ${zero}(${rs1}), $vs2, $vs3"> {
    bits<5> vs3;
    let Inst{11-7}  = vs3;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_AMO_E<bits<5> amoop, string opcodestr> {
  def _wd_m  : RVInstVAMO<amoop, 0b1, 0b111, RVV_Masked, OPC_AMO,
               (outs VR:$vd_wd),
               (ins GPR:$rs1, VR:$vs2, VR:$vd, Zero:$zero, VMR:$vm),
               opcodestr, "$vd_wd, ${zero}(${rs1}), $vs2, $vd, $vm"> {
    let Constraints = "$vd = $vd_wd";
    bits<5> vd;
    let Inst{11-7}  = vd;
  }
  def _wd_um : RVInstVAMO<amoop, 0b1, 0b111, RVV_Unmasked, OPC_AMO,
               (outs VR:$vd_wd),
               (ins GPR:$rs1, VR:$vs2, VR:$vd, Zero:$zero),
               opcodestr, "$vd_wd, ${zero}(${rs1}), $vs2, $vd"> {
    let Constraints = "$vd = $vd_wd";
    bits<5> vd;
    let Inst{11-7}  = vd;
  }
  def _m  : RVInstVAMO<amoop, 0b0, 0b111, RVV_Masked, OPC_AMO,
               (outs),
               (ins GPR:$rs1, VR:$vs2, VR:$vs3, Zero:$zero, VMR:$vm),
               opcodestr, "x0, ${zero}(${rs1}), $vs2, $vs3, $vm"> {
    bits<5> vs3;
    let Inst{11-7}  = vs3;
  }
  def _um : RVInstVAMO<amoop, 0b0, 0b111, RVV_Unmasked, OPC_AMO,
               (outs), (ins GPR:$rs1, VR:$vs2, VR:$vs3, Zero:$zero),
               opcodestr, "x0, ${zero}(${rs1}), $vs2, $vs3"> {
    bits<5> vs3;
    let Inst{11-7}  = vs3;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPIVV<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b000, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1, VMR:$vm),
               opcodestr, "$vd, $vs2, $vs1, $vm"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<funct6, 0b000, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1),
               opcodestr, "$vd, $vs2, $vs1"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVV_m<bits<6> funct6, string opcodestr> 
    : RVInstVA<funct6, 0b000, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1, VRV0:$v0),
               opcodestr, "$vd, $vs2, $vs1, v0"> {
  bits<5> vs1;
  let Inst{19-15} = vs1;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVV_um<bits<6> funct6, string opcodestr> 
    : RVInstVA<funct6, 0b000, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1),
               opcodestr, "$vd, $vs2, $vs1"> {
  bits<5> vs1;
  let Inst{19-15} = vs1;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPIVV_MulAdd<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b000, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VMR:$vm),
               opcodestr, "$vd, $vs1, $vs2, $vm"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<funct6, 0b000, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2),
               opcodestr, "$vd, $vs1, $vs2"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPFVV<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b001, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1, VMR:$vm),
               opcodestr, "$vd, $vs2, $vs1, $vm"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<funct6, 0b001, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1),
               opcodestr, "$vd, $vs2, $vs1"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPFVV_VFUNARY0<bits<5> vs1, string opcodestr> {
  def _m  : RVInstVA<0b100010, 0b001, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VMR:$vm),
               opcodestr, "$vd, $vs2, $vm"> {
    let Inst{19-15} = vs1;
  }  
  def _um : RVInstVA<0b100010, 0b001, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2),
               opcodestr, "$vd, $vs2"> {
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPFVV_VFUNARY1<bits<5> vs1, string opcodestr> {
  def _m  : RVInstVA<0b100011, 0b001, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VMR:$vm),
               opcodestr, "$vd, $vs2, $vm"> {
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<0b100011, 0b001, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2),
               opcodestr, "$vd, $vs2"> {
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPFVV_MulAdd<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b001, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VMR:$vm),
               opcodestr, "$vd, $vs1, $vs2, $vm"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<funct6, 0b001, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2),
               opcodestr, "$vd, $vs1, $vs2"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPMVV<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b010, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1, VMR:$vm),
               opcodestr, "$vd, $vs2, $vs1, $vm"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<funct6, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1),
               opcodestr, "$vd, $vs2, $vs1"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPMVV_um<bits<6> funct6, string opcodestr>
    : RVInstVA<funct6, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1),
               opcodestr, "$vd, $vs2, $vs1"> {
  bits<5> vs1;
  let Inst{19-15} = vs1;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPMVV_VWXUNARY0<bits<5> vs1, string opcodestr> {
  def _m  : RVInstVA<0b010000, 0b010, RVV_Masked, OPC_OP_V,
               (outs GPR:$rd), (ins VR:$vs2, VMR:$vm),
               opcodestr, "$rd, $vs2, $vm"> {
    let Inst{19-15} = vs1;
    let Inst{11-7} = rd;
  }
  def _um : RVInstVA<0b010000, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs GPR:$rd), (ins VR:$vs2),
               opcodestr, "$rd, $vs2"> {
    let Inst{19-15} = vs1;
    let Inst{11-7} = rd;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPMVV_VMUNARY0<bits<5> vs1, string opcodestr> {
  def _m  : RVInstVA<0b010100, 0b010, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VMR:$vm),
               opcodestr, "$vd, $vs2, $vm"> {
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<0b010100, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2),
               opcodestr, "$vd, $vs2"> {
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPMVV_MulAdd<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b010, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VMR:$vm),
               opcodestr, "$vd, $vs1, $vs2, $vm"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<funct6, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2),
               opcodestr, "$vd, $vs1, $vs2"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPIVI_signed<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b011, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, simm5:$simm, VMR:$vm),
               opcodestr, "$vd, $vs2, $simm, $vm"> {
    bits<5> simm;
    let Inst{19-15} = simm;
  }
  def _um : RVInstVA<funct6, 0b011, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, simm5:$simm),
               opcodestr, "$vd, $vs2, $simm"> {
    bits<5> simm;
    let Inst{19-15} = simm;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPIVI_unsigned<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b011, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, uimm5:$uimm, VMR:$vm),
               opcodestr, "$vd, $vs2, $uimm, $vm"> {
    bits<5> uimm;
    let Inst{19-15} = uimm;
  }
  def _um : RVInstVA<funct6, 0b011, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, uimm5:$uimm),
               opcodestr, "$vd, $vs2, $uimm"> {
    bits<5> uimm;
    let Inst{19-15} = uimm;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVI_m<bits<6> funct6, string opcodestr> 
    : RVInstVA<funct6, 0b011, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, simm5:$simm, VRV0:$v0),
               opcodestr, "$vd, $vs2, $simm, v0"> {
  bits<5> simm;
  let Inst{19-15} = simm;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVI_um<bits<6> funct6, string opcodestr> 
    : RVInstVA<funct6, 0b011, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, simm5:$simm),
               opcodestr, "$vd, $vs2, $simm"> {
  bits<5> simm;
  let Inst{19-15} = simm;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVI_VMVWholeReg<bits<5> simm, string opcodestr>
    : RVInstVA<0b100111, 0b011, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2),
               opcodestr, "$vd, $vs2"> {
  let Inst{19-15} = simm;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPIVX<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b100, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VMR:$vm),
               opcodestr, "$vd, $vs2, $rs1, $vm"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
  def _um : RVInstVA<funct6, 0b100, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, GPR:$rs1),
               opcodestr, "$vd, $vs2, $rs1"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVX_m<bits<6> funct6, string opcodestr> 
    : RVInstVA<funct6, 0b100, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VRV0:$v0),
               opcodestr, "$vd, $vs2, $rs1, v0"> {
  bits<5> rs1;
  let Inst{19-15} = rs1;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVX_um<bits<6> funct6, string opcodestr> 
    : RVInstVA<funct6, 0b100, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, GPR:$rs1),
               opcodestr, "$vd, $vs2, $rs1"> {
  bits<5> rs1;
  let Inst{19-15} = rs1;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPIVX_MulAdd<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b100, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins GPR:$rs1, VR:$vs2, VMR:$vm),
               opcodestr, "$vd, $rs1, $vs2, $vm"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
  def _um : RVInstVA<funct6, 0b100, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins GPR:$rs1, VR:$vs2),
               opcodestr, "$vd, $rs1, $vs2"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPFVF<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b101, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, FPR32:$rs1, VMR:$vm),
               opcodestr, "$vd, $vs2, $rs1, $vm"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
  def _um : RVInstVA<funct6, 0b101, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, FPR32:$rs1),
               opcodestr, "$vd, $vs2, $rs1"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPFVF_MulAdd<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b101, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins FPR32:$rs1, VR:$vs2, VMR:$vm),
               opcodestr, "$vd, $rs1, $vs2, $vm"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
  def _um : RVInstVA<funct6, 0b101, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins FPR32:$rs1, VR:$vs2),
               opcodestr, "$vd, $rs1, $vs2"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPMVX<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b110, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VMR:$vm),
               opcodestr, "$vd, $vs2, $rs1, $vm"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
  def _um : RVInstVA<funct6, 0b110, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, GPR:$rs1),
               opcodestr, "$vd, $vs2, $rs1"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPMVX_MulAdd<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b110, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins GPR:$rs1, VR:$vs2, VMR:$vm),
               opcodestr, "$vd, $rs1, $vs2, $vm"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
  def _um : RVInstVA<funct6, 0b110, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins GPR:$rs1, VR:$vs2),
               opcodestr, "$vd, $rs1, $vs2"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
}

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

//Instruction encoding table: https://github.com/riscv/riscv-v-spec/blob/master/inst-table.adoc

let Predicates = [HasStdExtV] in {

// Configuration-Setting Instructions

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VSETVLI: RVInstVSet<0b0, OPC_OP_V, 
                      (outs GPR:$rd),
                      (ins GPR:$rs1, vtypei:$vtyi),
                      "vsetvli", "$rd, $rs1, $vtyi">, Sched<[]> {
  bits<11> vtyi;
  let Inst{30-20} = vtyi;
}
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VSETVL: RVInstVSet<0b1, OPC_OP_V, 
                      (outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
                      "vsetvl", "$rd, $rs1, $rs2">, Sched<[]> {
  bits<5> rs2;
  let Inst{30-25} = 0b000000;
  let Inst{24-20} = rs2;
}


// Vector Unit-Stride Instructions

defm VLB_V : VLoad_UnitStride<0b000, 0b100, 0b000, "vlb.v">, Sched<[]>;
defm VLH_V : VLoad_UnitStride<0b000, 0b100, 0b101, "vlh.v">, Sched<[]>;
defm VLW_V : VLoad_UnitStride<0b000, 0b100, 0b110, "vlw.v">, Sched<[]>;
defm VLBU_V : VLoad_UnitStride<0b000, 0b000, 0b000, "vlbu.v">, Sched<[]>;
defm VLHU_V : VLoad_UnitStride<0b000, 0b000, 0b101, "vlhu.v">, Sched<[]>;
defm VLWU_V : VLoad_UnitStride<0b000, 0b000, 0b110, "vlwu.v">, Sched<[]>;
defm VLE_V : VLoad_UnitStride<0b000, 0b000, 0b111, "vle.v">, Sched<[]>;

defm VSB_V : VStore_UnitStride<0b000, 0b000, 0b000, "vsb.v">, Sched<[]>;
defm VSH_V : VStore_UnitStride<0b000, 0b000, 0b101, "vsh.v">, Sched<[]>;
defm VSW_V : VStore_UnitStride<0b000, 0b000, 0b110, "vsw.v">, Sched<[]>;
defm VSE_V : VStore_UnitStride<0b000, 0b000, 0b111, "vse.v">, Sched<[]>;


// Vector Strided Instructions

defm VLSB_V : VLoad_Strided<0b000, 0b110, 0b000, "vlsb.v">, Sched<[]>;
defm VLSH_V : VLoad_Strided<0b000, 0b110, 0b101, "vlsh.v">, Sched<[]>;
defm VLSW_V : VLoad_Strided<0b000, 0b110, 0b110, "vlsw.v">, Sched<[]>;
defm VLSBU_V : VLoad_Strided<0b000, 0b010, 0b000, "vlsbu.v">, Sched<[]>;
defm VLSHU_V : VLoad_Strided<0b000, 0b010, 0b101, "vlshu.v">, Sched<[]>;
defm VLSWU_V : VLoad_Strided<0b000, 0b010, 0b110, "vlswu.v">, Sched<[]>;
defm VLSE_V : VLoad_Strided<0b000, 0b010, 0b111, "vlse.v">, Sched<[]>;

defm VSSB_V : VStore_Strided<0b000, 0b010, 0b000, "vssb.v">, Sched<[]>;
defm VSSH_V : VStore_Strided<0b000, 0b010, 0b101, "vssh.v">, Sched<[]>;
defm VSSW_V : VStore_Strided<0b000, 0b010, 0b110, "vssw.v">, Sched<[]>;
defm VSSE_V : VStore_Strided<0b000, 0b010, 0b111, "vsse.v">, Sched<[]>;


// Vector Indexed Instructions

defm VLXB_V : VLoad_Indexed<0b000, 0b111, 0b000, "vlxb.v">, Sched<[]>;
defm VLXH_V : VLoad_Indexed<0b000, 0b111, 0b101, "vlxh.v">, Sched<[]>;
defm VLXW_V : VLoad_Indexed<0b000, 0b111, 0b110, "vlxw.v">, Sched<[]>;
defm VLXBU_V : VLoad_Indexed<0b000, 0b011, 0b000, "vlxbu.v">, Sched<[]>;
defm VLXHU_V : VLoad_Indexed<0b000, 0b011, 0b101, "vlxhu.v">, Sched<[]>;
defm VLXWU_V : VLoad_Indexed<0b000, 0b011, 0b110, "vlxwu.v">, Sched<[]>;
defm VLXE_V : VLoad_Indexed<0b000, 0b011, 0b111, "vlxe.v">, Sched<[]>;

defm VSXB_V : VStore_Indexed<0b000, 0b011, 0b000, "vsxb.v">, Sched<[]>;
defm VSXH_V : VStore_Indexed<0b000, 0b011, 0b101, "vsxh.v">, Sched<[]>;
defm VSXW_V : VStore_Indexed<0b000, 0b011, 0b110, "vsxw.v">, Sched<[]>;
defm VSXE_V : VStore_Indexed<0b000, 0b011, 0b111, "vsxe.v">, Sched<[]>;
defm VSUXB_V : VStore_Indexed<0b000, 0b111, 0b000, "vsuxb.v">, Sched<[]>;
defm VSUXH_V : VStore_Indexed<0b000, 0b111, 0b101, "vsuxh.v">, Sched<[]>;
defm VSUXW_V : VStore_Indexed<0b000, 0b111, 0b110, "vsuxw.v">, Sched<[]>;
defm VSUXE_V : VStore_Indexed<0b000, 0b111, 0b111, "vsuxe.v">, Sched<[]>;


// Unit-stride Fault-Only-First Loads Instructions

defm VLBFF_V : VLoad_UnitStrideFF<0b000, 0b100, 0b000, "vlbff.v">, Sched<[]>;
defm VLHFF_V : VLoad_UnitStrideFF<0b000, 0b100, 0b101, "vlhff.v">, Sched<[]>;
defm VLWFF_V : VLoad_UnitStrideFF<0b000, 0b100, 0b110, "vlwff.v">, Sched<[]>;
defm VLBUFF_V : VLoad_UnitStrideFF<0b000, 0b000, 0b000, "vlbuff.v">, Sched<[]>;
defm VLHUFF_V : VLoad_UnitStrideFF<0b000, 0b000, 0b101, "vlhuff.v">, Sched<[]>;
defm VLWUFF_V : VLoad_UnitStrideFF<0b000, 0b000, 0b110, "vlwuff.v">, Sched<[]>;
defm VLEFF_V : VLoad_UnitStrideFF<0b000, 0b000, 0b111, "vleff.v">, Sched<[]>;


// Vector Load/Store Segment Instructions

foreach nf = 2-8 in {

  // Vector Unit-Stride Segment Loads and Stores
  defm VLSEG#nf#B_V : VLoad_UnitStride<!add(nf, -1), 0b100,
                                       0b000, "vlseg"#nf#"b.v">, Sched<[]>;
  defm VLSEG#nf#H_V : VLoad_UnitStride<!add(nf, -1), 0b100,
                                       0b101, "vlseg"#nf#"h.v">, Sched<[]>;
  defm VLSEG#nf#W_V : VLoad_UnitStride<!add(nf, -1), 0b100,
                                       0b110, "vlseg"#nf#"w.v">, Sched<[]>;
  defm VLSEG#nf#BU_V : VLoad_UnitStride<!add(nf, -1), 0b000,
                                       0b000, "vlseg"#nf#"bu.v">, Sched<[]>;
  defm VLSEG#nf#HU_V : VLoad_UnitStride<!add(nf, -1), 0b000,
                                       0b101, "vlseg"#nf#"hu.v">, Sched<[]>;
  defm VLSEG#nf#WU_V : VLoad_UnitStride<!add(nf, -1), 0b000,
                                       0b110, "vlseg"#nf#"wu.v">, Sched<[]>;
  defm VLSEG#nf#E_V : VLoad_UnitStride<!add(nf, -1), 0b000,
                                       0b111, "vlseg"#nf#"e.v">, Sched<[]>;
  defm VSSEG#nf#B_V : VStore_UnitStride<!add(nf, -1), 0b000,
                                       0b000, "vsseg"#nf#"b.v">, Sched<[]>;
  defm VSSEG#nf#H_V : VStore_UnitStride<!add(nf, -1), 0b000,
                                       0b101, "vsseg"#nf#"h.v">, Sched<[]>;
  defm VSSEG#nf#W_V : VStore_UnitStride<!add(nf, -1), 0b000,
                                       0b110, "vsseg"#nf#"w.v">, Sched<[]>;
  defm VSSEG#nf#E_V : VStore_UnitStride<!add(nf, -1), 0b000,
                                       0b111, "vsseg"#nf#"e.v">, Sched<[]>;

  // Vector Strided Segment Loads and Stores
  defm VLSSEG#nf#B_V : VLoad_Strided<!add(nf, -1), 0b110,
                                       0b000, "vlsseg"#nf#"b.v">, Sched<[]>;
  defm VLSSEG#nf#H_V : VLoad_Strided<!add(nf, -1), 0b110,
                                       0b101, "vlsseg"#nf#"h.v">, Sched<[]>;
  defm VLSSEG#nf#W_V : VLoad_Strided<!add(nf, -1), 0b110,
                                       0b110, "vlsseg"#nf#"w.v">, Sched<[]>;
  defm VLSSEG#nf#BU_V : VLoad_Strided<!add(nf, -1), 0b010,
                                       0b000, "vlsseg"#nf#"bu.v">, Sched<[]>;
  defm VLSSEG#nf#HU_V : VLoad_Strided<!add(nf, -1), 0b010,
                                       0b101, "vlsseg"#nf#"hu.v">, Sched<[]>;
  defm VLSSEG#nf#WU_V : VLoad_Strided<!add(nf, -1), 0b010,
                                       0b110, "vlsseg"#nf#"wu.v">, Sched<[]>;
  defm VLSSEG#nf#E_V : VLoad_Strided<!add(nf, -1), 0b010,
                                       0b111, "vlsseg"#nf#"e.v">, Sched<[]>;
  defm VSSSEG#nf#B_V : VStore_Strided<!add(nf, -1), 0b010,
                                       0b000, "vssseg"#nf#"b.v">, Sched<[]>;
  defm VSSSEG#nf#H_V : VStore_Strided<!add(nf, -1), 0b010,
                                       0b101, "vssseg"#nf#"h.v">, Sched<[]>;
  defm VSSSEG#nf#W_V : VStore_Strided<!add(nf, -1), 0b010,
                                       0b110, "vssseg"#nf#"w.v">, Sched<[]>;
  defm VSSSEG#nf#E_V : VStore_Strided<!add(nf, -1), 0b010,
                                       0b111, "vssseg"#nf#"e.v">, Sched<[]>;

  // Vector Indexed Segment Loads and Stores
  defm VLXSEG#nf#B_V : VLoad_Indexed<!add(nf, -1), 0b111,
                                       0b000, "vlxseg"#nf#"b.v">, Sched<[]>;
  defm VLXSEG#nf#H_V : VLoad_Indexed<!add(nf, -1), 0b111,
                                       0b101, "vlxseg"#nf#"h.v">, Sched<[]>;
  defm VLXSEG#nf#W_V : VLoad_Indexed<!add(nf, -1), 0b111,
                                       0b110, "vlxseg"#nf#"w.v">, Sched<[]>;
  defm VLXSEG#nf#BU_V : VLoad_Indexed<!add(nf, -1), 0b011,
                                       0b000, "vlxseg"#nf#"bu.v">, Sched<[]>;
  defm VLXSEG#nf#HU_V : VLoad_Indexed<!add(nf, -1), 0b011,
                                       0b101, "vlxseg"#nf#"hu.v">, Sched<[]>;
  defm VLXSEG#nf#WU_V : VLoad_Indexed<!add(nf, -1), 0b011,
                                       0b110, "vlxseg"#nf#"wu.v">, Sched<[]>;
  defm VLXSEG#nf#E_V : VLoad_Indexed<!add(nf, -1), 0b011,
                                       0b111, "vlxseg"#nf#"e.v">, Sched<[]>;
  defm VSXSEG#nf#B_V : VStore_Indexed<!add(nf, -1), 0b011,
                                       0b000, "vsxseg"#nf#"b.v">, Sched<[]>;
  defm VSXSEG#nf#H_V : VStore_Indexed<!add(nf, -1), 0b011,
                                       0b101, "vsxseg"#nf#"h.v">, Sched<[]>;
  defm VSXSEG#nf#W_V : VStore_Indexed<!add(nf, -1), 0b011,
                                       0b110, "vsxseg"#nf#"w.v">, Sched<[]>;
  defm VSXSEG#nf#E_V : VStore_Indexed<!add(nf, -1), 0b011,
                                       0b111, "vsxseg"#nf#"e.v">, Sched<[]>;

  // Vector Unit-Stride Fault-Only-First Segment Loads
  defm VLSEG#nf#BFF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b100,
                                       0b000, "vlseg"#nf#"bff.v">, Sched<[]>;
  defm VLSEG#nf#HFF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b100,
                                       0b101, "vlseg"#nf#"hff.v">, Sched<[]>;
  defm VLSEG#nf#WFF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b100,
                                       0b110, "vlseg"#nf#"wff.v">, Sched<[]>;
  defm VLSEG#nf#BUFF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b000,
                                       0b000, "vlseg"#nf#"buff.v">, Sched<[]>;
  defm VLSEG#nf#HUFF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b000,
                                       0b101, "vlseg"#nf#"huff.v">, Sched<[]>;
  defm VLSEG#nf#WUFF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b000,
                                       0b110, "vlseg"#nf#"wuff.v">, Sched<[]>;
  defm VLSEG#nf#EFF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b000,
                                       0b111, "vlseg"#nf#"eff.v">, Sched<[]>;
}


// Vector Load/Store Whole Register Instructions

foreach nf = 1-8 in {
  def VL#nf#R_V : VLoad_WholeReg<!add(nf, -1), "vl"#nf#"r.v">, Sched<[]>;
  def VS#nf#R_V : VStore_WholeReg<!add(nf, -1), "vs"#nf#"r.v">, Sched<[]>;
}


// Vector AMO Operations

defm VAMOSWAPW_V : VALU_AMO_W<0b00001, "vamoswapw.v">, Sched<[]>;
defm VAMOADDW_V : VALU_AMO_W<0b00000, "vamoaddw.v">, Sched<[]>;
defm VAMOXORW_V : VALU_AMO_W<0b00100, "vamoxorw.v">, Sched<[]>;
defm VAMOANDW_V : VALU_AMO_W<0b01100, "vamoandw.v">, Sched<[]>;
defm VAMOORW_V : VALU_AMO_W<0b01000, "vamoorw.v">, Sched<[]>;
defm VAMOMINW_V : VALU_AMO_W<0b10000, "vamominw.v">, Sched<[]>;
defm VAMOMAXW_V : VALU_AMO_W<0b10100, "vamomaxw.v">, Sched<[]>;
defm VAMOMINUW_V : VALU_AMO_W<0b11000, "vamominuw.v">, Sched<[]>;
defm VAMOMAXUW_V : VALU_AMO_W<0b11100, "vamomaxuw.v">, Sched<[]>;

defm VAMOSWAPE_V : VALU_AMO_E<0b00001, "vamoswape.v">, Sched<[]>;
defm VAMOADDE_V : VALU_AMO_E<0b00000, "vamoadde.v">, Sched<[]>;
defm VAMOXORE_V : VALU_AMO_E<0b00100, "vamoxore.v">, Sched<[]>;
defm VAMOANDE_V : VALU_AMO_E<0b01100, "vamoande.v">, Sched<[]>;
defm VAMOORE_V : VALU_AMO_E<0b01000, "vamoore.v">, Sched<[]>;
defm VAMOMINE_V : VALU_AMO_E<0b10000, "vamomine.v">, Sched<[]>;
defm VAMOMAXE_V : VALU_AMO_E<0b10100, "vamomaxe.v">, Sched<[]>;
defm VAMOMINUE_V : VALU_AMO_E<0b11000, "vamominue.v">, Sched<[]>;
defm VAMOMAXUE_V : VALU_AMO_E<0b11100, "vamomaxue.v">, Sched<[]>;


// Vector Single-Width Integer Add and Subtract Instructions

defm VADD_VV : VALU_OPIVV<0b000000, "vadd.vv">, Sched<[]>;
defm VADD_VX : VALU_OPIVX<0b000000, "vadd.vx">, Sched<[]>;
defm VADD_VI : VALU_OPIVI_signed<0b000000, "vadd.vi">, Sched<[]>;

defm VSUB_VV : VALU_OPIVV<0b000010, "vsub.vv">, Sched<[]>;
defm VSUB_VX : VALU_OPIVX<0b000010, "vsub.vx">, Sched<[]>;

defm VRSUB_VX : VALU_OPIVX<0b000011, "vrsub.vx">, Sched<[]>;
defm VRSUB_VI : VALU_OPIVI_signed<0b000011, "vrsub.vi">, Sched<[]>;


// Vector Widening Integer Add and Subtract Instructions

defm VWADDU_VV : VALU_OPMVV<0b110000, "vwaddu.vv">, Sched<[]>;
defm VWADDU_VX : VALU_OPMVX<0b110000, "vwaddu.vx">, Sched<[]>;
defm VWSUBU_VV : VALU_OPMVV<0b110010, "vwsubu.vv">, Sched<[]>;
defm VWSUBU_VX : VALU_OPMVX<0b110010, "vwsubu.vx">, Sched<[]>;

defm VWADD_VV : VALU_OPMVV<0b110001, "vwadd.vv">, Sched<[]>;
defm VWADD_VX : VALU_OPMVX<0b110001, "vwadd.vx">, Sched<[]>;
defm VWSUB_VV : VALU_OPMVV<0b110011, "vwsub.vv">, Sched<[]>;
defm VWSUB_VX : VALU_OPMVX<0b110011, "vwsub.vx">, Sched<[]>;

defm VWADDU_WV : VALU_OPMVV<0b110100, "vwaddu.wv">, Sched<[]>;
defm VWADDU_WX : VALU_OPMVX<0b110100, "vwaddu.wx">, Sched<[]>;
defm VWSUBU_WV : VALU_OPMVV<0b110110, "vwsubu.wv">, Sched<[]>;
defm VWSUBU_WX : VALU_OPMVX<0b110110, "vwsubu.wx">, Sched<[]>;

defm VWADD_WV : VALU_OPMVV<0b110101, "vwadd.wv">, Sched<[]>;
defm VWADD_WX : VALU_OPMVX<0b110101, "vwadd.wx">, Sched<[]>;
defm VWSUB_WV : VALU_OPMVV<0b110111, "vwsub.wv">, Sched<[]>;
defm VWSUB_WX : VALU_OPMVX<0b110111, "vwsub.wx">, Sched<[]>;


// Vector Integer Add-with-Carry / Subtract-with-Borrow Instructions

def VADC_VVM : VALU_OPIVV_m<0b010000, "vadc.vvm">, Sched<[]>;
def VADC_VXM : VALU_OPIVX_m<0b010000, "vadc.vxm">, Sched<[]>;
def VADC_VIM : VALU_OPIVI_m<0b010000, "vadc.vim">, Sched<[]>;

def VMADC_VVM : VALU_OPIVV_m<0b010001, "vmadc.vvm">, Sched<[]>;
def VMADC_VXM : VALU_OPIVX_m<0b010001, "vmadc.vxm">, Sched<[]>;
def VMADC_VIM : VALU_OPIVI_m<0b010001, "vmadc.vim">, Sched<[]>;

def VMADC_VV : VALU_OPIVV_um<0b010001, "vmadc.vv">, Sched<[]>;
def VMADC_VX : VALU_OPIVX_um<0b010001, "vmadc.vx">, Sched<[]>;
def VMADC_VI : VALU_OPIVI_um<0b010001, "vmadc.vi">, Sched<[]>;

def VSBC_VVM : VALU_OPIVV_m<0b010010, "vsbc.vvm">, Sched<[]>;
def VSBC_VXM : VALU_OPIVX_m<0b010010, "vsbc.vxm">, Sched<[]>;

def VMSBC_VVM : VALU_OPIVV_m<0b010011, "vmsbc.vvm">, Sched<[]>;
def VMSBC_VXM : VALU_OPIVX_m<0b010011, "vmsbc.vxm">, Sched<[]>;

def VMSBC_VV : VALU_OPIVV_um<0b010011, "vmsbc.vv">, Sched<[]>;
def VMSBC_VX : VALU_OPIVX_um<0b010011, "vmsbc.vx">, Sched<[]>;


// Vector Bitwise Logical Instructions

defm VAND_VV : VALU_OPIVV<0b001001, "vand.vv">, Sched<[]>;
defm VAND_VX : VALU_OPIVX<0b001001, "vand.vx">, Sched<[]>;
defm VAND_VI : VALU_OPIVI_signed<0b001001, "vand.vi">, Sched<[]>;

defm VOR_VV : VALU_OPIVV<0b001010, "vor.vv">, Sched<[]>;
defm VOR_VX : VALU_OPIVX<0b001010, "vor.vx">, Sched<[]>;
defm VOR_VI : VALU_OPIVI_signed<0b001010, "vor.vi">, Sched<[]>;

defm VXOR_VV : VALU_OPIVV<0b001011, "vxor.vv">, Sched<[]>;
defm VXOR_VX : VALU_OPIVX<0b001011, "vxor.vx">, Sched<[]>;
defm VXOR_VI : VALU_OPIVI_signed<0b001011, "vxor.vi">, Sched<[]>;


// Vector Single-Width Bit Shift Instructions

defm VSLL_VV : VALU_OPIVV<0b100101, "vsll.vv">, Sched<[]>;
defm VSLL_VX : VALU_OPIVX<0b100101, "vsll.vx">, Sched<[]>;
defm VSLL_VI : VALU_OPIVI_unsigned<0b100101, "vsll.vi">, Sched<[]>;

defm VSRL_VV : VALU_OPIVV<0b101000, "vsrl.vv">, Sched<[]>;
defm VSRL_VX : VALU_OPIVX<0b101000, "vsrl.vx">, Sched<[]>;
defm VSRL_VI : VALU_OPIVI_unsigned<0b101000, "vsrl.vi">, Sched<[]>;

defm VSRA_VV : VALU_OPIVV<0b101001, "vsra.vv">, Sched<[]>;
defm VSRA_VX : VALU_OPIVX<0b101001, "vsra.vx">, Sched<[]>;
defm VSRA_VI : VALU_OPIVI_unsigned<0b101001, "vsra.vi">, Sched<[]>;


// Vector Narrowing Integer Right Shift Instructions

defm VNSRL_WV : VALU_OPIVV<0b101100, "vnsrl.wv">, Sched<[]>;
defm VNSRL_WX : VALU_OPIVX<0b101100, "vnsrl.wx">, Sched<[]>;
defm VNSRL_WI : VALU_OPIVI_unsigned<0b101100, "vnsrl.wi">, Sched<[]>;

defm VNSRA_WV : VALU_OPIVV<0b101101, "vnsra.wv">, Sched<[]>;
defm VNSRA_WX : VALU_OPIVX<0b101101, "vnsra.wx">, Sched<[]>;
defm VNSRA_WI : VALU_OPIVI_unsigned<0b101101, "vnsra.wi">, Sched<[]>;


// Vector Integer Comparison Instructions

defm VMSEQ_VV : VALU_OPIVV<0b011000, "vmseq.vv">, Sched<[]>;
defm VMSEQ_VX : VALU_OPIVX<0b011000, "vmseq.vx">, Sched<[]>;
defm VMSEQ_VI : VALU_OPIVI_signed<0b011000, "vmseq.vi">, Sched<[]>;

defm VMSNE_VV : VALU_OPIVV<0b011001, "vmsne.vv">, Sched<[]>;
defm VMSNE_VX : VALU_OPIVX<0b011001, "vmsne.vx">, Sched<[]>;
defm VMSNE_VI : VALU_OPIVI_signed<0b011001, "vmsne.vi">, Sched<[]>;

defm VMSLTU_VV : VALU_OPIVV<0b011010, "vmsltu.vv">, Sched<[]>;
defm VMSLTU_VX : VALU_OPIVX<0b011010, "vmsltu.vx">, Sched<[]>;

defm VMSLT_VV : VALU_OPIVV<0b011011, "vmslt.vv">, Sched<[]>;
defm VMSLT_VX : VALU_OPIVX<0b011011, "vmslt.vx">, Sched<[]>;

defm VMSLEU_VV : VALU_OPIVV<0b011100, "vmsleu.vv">, Sched<[]>;
defm VMSLEU_VX : VALU_OPIVX<0b011100, "vmsleu.vx">, Sched<[]>;
defm VMSLEU_VI : VALU_OPIVI_signed<0b011100, "vmsleu.vi">, Sched<[]>;

defm VMSLE_VV : VALU_OPIVV<0b011101, "vmsle.vv">, Sched<[]>;
defm VMSLE_VX : VALU_OPIVX<0b011101, "vmsle.vx">, Sched<[]>;
defm VMSLE_VI : VALU_OPIVI_signed<0b011101, "vmsle.vi">, Sched<[]>;

defm VMSGTU_VX : VALU_OPIVX<0b011110, "vmsgtu.vx">, Sched<[]>;
defm VMSGTU_VI : VALU_OPIVI_signed<0b011110, "vmsgtu.vi">, Sched<[]>;

defm VMSGT_VX : VALU_OPIVX<0b011111, "vmsgt.vx">, Sched<[]>;
defm VMSGT_VI : VALU_OPIVI_signed<0b011111, "vmsgt.vi">, Sched<[]>;


// Vector Integer Min/Max Instructions

defm VMINU_VV : VALU_OPIVV<0b000100, "vminu.vv">, Sched<[]>;
defm VMINU_VX : VALU_OPIVX<0b000100, "vminu.vx">, Sched<[]>;

defm VMIN_VV : VALU_OPIVV<0b000101, "vmin.vv">, Sched<[]>;
defm VMIN_VX : VALU_OPIVX<0b000101, "vmin.vx">, Sched<[]>;

defm VMAXU_VV : VALU_OPIVV<0b000110, "vmaxu.vv">, Sched<[]>;
defm VMAXU_VX : VALU_OPIVX<0b000110, "vmaxu.vx">, Sched<[]>;

defm VMAX_VV : VALU_OPIVV<0b000111, "vmax.vv">, Sched<[]>;
defm VMAX_VX : VALU_OPIVX<0b000111, "vmax.vx">, Sched<[]>;


// Vector Single-Width Integer Multiply Instructions

defm VMUL_VV : VALU_OPMVV<0b100101, "vmul.vv">, Sched<[]>;
defm VMUL_VX : VALU_OPMVX<0b100101, "vmul.vx">, Sched<[]>;

defm VMULH_VV : VALU_OPMVV<0b100111, "vmulh.vv">, Sched<[]>;
defm VMULH_VX : VALU_OPMVX<0b100111, "vmulh.vx">, Sched<[]>;

defm VMULHU_VV : VALU_OPMVV<0b100100, "vmulhu.vv">, Sched<[]>;
defm VMULHU_VX : VALU_OPMVX<0b100100, "vmulhu.vx">, Sched<[]>;

defm VMULHSU_VV : VALU_OPMVV<0b100110, "vmulhsu.vv">, Sched<[]>;
defm VMULHSU_VX : VALU_OPMVX<0b100110, "vmulhsu.vx">, Sched<[]>;


// Vector Integer Divide Instructions

defm VDIVU_VV : VALU_OPMVV<0b100000, "vdivu.vv">, Sched<[]>;
defm VDIVU_VX : VALU_OPMVX<0b100000, "vdivu.vx">, Sched<[]>;

defm VDIV_VV : VALU_OPMVV<0b100001, "vdiv.vv">, Sched<[]>;
defm VDIV_VX : VALU_OPMVX<0b100001, "vdiv.vx">, Sched<[]>;

defm VREMU_VV : VALU_OPMVV<0b100010, "vremu.vv">, Sched<[]>;
defm VREMU_VX : VALU_OPMVX<0b100010, "vremu.vx">, Sched<[]>;

defm VREM_VV : VALU_OPMVV<0b100011, "vrem.vv">, Sched<[]>;
defm VREM_VX : VALU_OPMVX<0b100011, "vrem.vx">, Sched<[]>;


// Vector Widening Integer Multiply Instructions

defm VWMUL_VV : VALU_OPMVV<0b111011, "vwmul.vv">, Sched<[]>;
defm VWMUL_VX : VALU_OPMVX<0b111011, "vwmul.vx">, Sched<[]>;

defm VWMULU_VV : VALU_OPMVV<0b111000, "vwmulu.vv">, Sched<[]>;
defm VWMULU_VX : VALU_OPMVX<0b111000, "vwmulu.vx">, Sched<[]>;

defm VWMULSU_VV : VALU_OPMVV<0b111010, "vwmulsu.vv">, Sched<[]>;
defm VWMULSU_VX : VALU_OPMVX<0b111010, "vwmulsu.vx">, Sched<[]>;


// Vector Single-Width Integer Multiply-Add Instructions

defm VMACC_VV : VALU_OPMVV_MulAdd<0b101101, "vmacc.vv">, Sched<[]>;
defm VMACC_VX : VALU_OPMVX_MulAdd<0b101101, "vmacc.vx">, Sched<[]>;

defm VNMSAC_VV : VALU_OPMVV_MulAdd<0b101111, "vnmsac.vv">, Sched<[]>;
defm VNMSAC_VX : VALU_OPMVX_MulAdd<0b101111, "vnmsac.vx">, Sched<[]>;

defm VMADD_VV : VALU_OPMVV_MulAdd<0b101001, "vmadd.vv">, Sched<[]>;
defm VMADD_VX : VALU_OPMVX_MulAdd<0b101001, "vmadd.vx">, Sched<[]>;

defm VNMSUB_VV : VALU_OPMVV_MulAdd<0b101011, "vnmsub.vv">, Sched<[]>;
defm VNMSUB_VX : VALU_OPMVX_MulAdd<0b101011, "vnmsub.vx">, Sched<[]>;


// Vector Widening Integer Multiply-Add Instructions

defm VWMACCU_VV : VALU_OPMVV_MulAdd<0b111100, "vwmaccu.vv">, Sched<[]>;
defm VWMACCU_VX : VALU_OPMVX_MulAdd<0b111100, "vwmaccu.vx">, Sched<[]>;

defm VWMACC_VV : VALU_OPMVV_MulAdd<0b111101, "vwmacc.vv">, Sched<[]>;
defm VWMACC_VX : VALU_OPMVX_MulAdd<0b111101, "vwmacc.vx">, Sched<[]>;

defm VWMACCSU_VV : VALU_OPMVV_MulAdd<0b111111, "vwmaccsu.vv">, Sched<[]>;
defm VWMACCSU_VX : VALU_OPMVX_MulAdd<0b111111, "vwmaccsu.vx">, Sched<[]>;

defm VWMACCUS_VX : VALU_OPMVX_MulAdd<0b111110, "vwmaccus.vx">, Sched<[]>;


// Vector Quad-Widening Integer Multiply-Add Instructions

defm VQMACCU_VV : VALU_OPIVV_MulAdd<0b111100, "vqmaccu.vv">, Sched<[]>;
defm VQMACCU_VX : VALU_OPIVX_MulAdd<0b111100, "vqmaccu.vx">, Sched<[]>;

defm VQMACC_VV : VALU_OPIVV_MulAdd<0b111101, "vqmacc.vv">, Sched<[]>;
defm VQMACC_VX : VALU_OPIVX_MulAdd<0b111101, "vqmacc.vx">, Sched<[]>;

defm VQMACCSU_VV : VALU_OPIVV_MulAdd<0b111111, "vqmaccsu.vv">, Sched<[]>;
defm VQMACCSU_VX : VALU_OPIVX_MulAdd<0b111111, "vqmaccsu.vx">, Sched<[]>;

defm VQMACCUS_VX : VALU_OPIVX_MulAdd<0b111110, "vqmaccus.vx">, Sched<[]>;


// Vector Integer Merge Instructions

def VMERGE_VVM : VALU_OPIVV_m<0b010111, "vmerge.vvm">, Sched<[]>;
def VMERGE_VXM : VALU_OPIVX_m<0b010111, "vmerge.vxm">, Sched<[]>;
def VMERGE_VIM : VALU_OPIVI_m<0b010111, "vmerge.vim">, Sched<[]>;


// Vector Integer Move Instructions

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VMV_V_V : RVInstVA<0b010111, 0b000, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1),
               "vmv.v.v", "$vd, $vs1">, Sched<[]> {
  bits<5> vs1;
  let vs2 = 0b00000;
  let Inst{19-15} = vs1;
}
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VMV_V_X : RVInstVA<0b010111, 0b100, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins GPR:$rs1),
               "vmv.v.x", "$vd, $rs1">, Sched<[]> {
  bits<5> rs1;
  let vs2 = 0b00000;
  let Inst{19-15} = rs1;
}
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VMV_V_I : RVInstVA<0b010111, 0b011, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins simm5:$simm),
               "vmv.v.i", "$vd, $simm">, Sched<[]> {
  bits<5> simm;
  let vs2 = 0b00000;
  let Inst{19-15} = simm;
}


// Vector Single-Width Saturating Add and Subtract Instructions

defm VSADDU_VV : VALU_OPIVV<0b100000, "vsaddu.vv">, Sched<[]>;
defm VSADDU_VX : VALU_OPIVX<0b100000, "vsaddu.vx">, Sched<[]>;
defm VSADDU_VI : VALU_OPIVI_signed<0b100000, "vsaddu.vi">, Sched<[]>;

defm VSADD_VV : VALU_OPIVV<0b100001, "vsadd.vv">, Sched<[]>;
defm VSADD_VX : VALU_OPIVX<0b100001, "vsadd.vx">, Sched<[]>;
defm VSADD_VI : VALU_OPIVI_signed<0b100001, "vsadd.vi">, Sched<[]>;

defm VSSUBU_VV : VALU_OPIVV<0b100010, "vssubu.vv">, Sched<[]>;
defm VSSUBU_VX : VALU_OPIVX<0b100010, "vssubu.vx">, Sched<[]>;

defm VSSUB_VV : VALU_OPIVV<0b100011, "vssub.vv">, Sched<[]>;
defm VSSUB_VX : VALU_OPIVX<0b100011, "vssub.vx">, Sched<[]>;


// Vector Single-Width Averaging Add and Subtract Instructions

defm VAADDU_VV : VALU_OPMVV<0b001000, "vaaddu.vv">, Sched<[]>;
defm VAADDU_VX : VALU_OPMVX<0b001000, "vaaddu.vx">, Sched<[]>;

defm VAADD_VV : VALU_OPMVV<0b001001, "vaadd.vv">, Sched<[]>;
defm VAADD_VX : VALU_OPMVX<0b001001, "vaadd.vx">, Sched<[]>;

defm VASUBU_VV : VALU_OPMVV<0b001010, "vasubu.vv">, Sched<[]>;
defm VASUBU_VX : VALU_OPMVX<0b001010, "vasubu.vx">, Sched<[]>;

defm VASUB_VV : VALU_OPMVV<0b001011, "vasub.vv">, Sched<[]>;
defm VASUB_VX : VALU_OPMVX<0b001011, "vasub.vx">, Sched<[]>;


// Vector Single-Width Fractional Multiply Instructions with Rounding and Saturation

defm VSMUL_VV : VALU_OPIVV<0b100111, "vsmul.vv">, Sched<[]>;
defm VSMUL_VX : VALU_OPIVX<0b100111, "vsmul.vx">, Sched<[]>;


// Vector Single-Width Scaling Shift Instructions

defm VSSRL_VV : VALU_OPIVV<0b101010, "vssrl.vv">, Sched<[]>;
defm VSSRL_VX : VALU_OPIVX<0b101010, "vssrl.vx">, Sched<[]>;
defm VSSRL_VI : VALU_OPIVI_unsigned<0b101010, "vssrl.vi">, Sched<[]>;

defm VSSRA_VV : VALU_OPIVV<0b101011, "vssra.vv">, Sched<[]>;
defm VSSRA_VX : VALU_OPIVX<0b101011, "vssra.vx">, Sched<[]>;
defm VSSRA_VI : VALU_OPIVI_unsigned<0b101011, "vssra.vi">, Sched<[]>;


// Vector Narrowing Fixed-Point Clip Instructions

defm VNCLIPU_WV : VALU_OPIVV<0b101110, "vnclipu.wv">, Sched<[]>;
defm VNCLIPU_WX : VALU_OPIVX<0b101110, "vnclipu.wx">, Sched<[]>;
defm VNCLIPU_WI : VALU_OPIVI_unsigned<0b101110, "vnclipu.wi">, Sched<[]>;

defm VNCLIP_WV : VALU_OPIVV<0b101111, "vnclip.wv">, Sched<[]>;
defm VNCLIP_WX : VALU_OPIVX<0b101111, "vnclip.wx">, Sched<[]>;
defm VNCLIP_WI : VALU_OPIVI_unsigned<0b101111, "vnclip.wi">, Sched<[]>;


// Vector Single-Width Floating-Point Add/Subtract Instructions

defm VFADD_VV : VALU_OPFVV<0b000000, "vfadd.vv">, Sched<[]>;
defm VFADD_VF : VALU_OPFVF<0b000000, "vfadd.vf">, Sched<[]>;

defm VFSUB_VV : VALU_OPFVV<0b000010, "vfsub.vv">, Sched<[]>;
defm VFSUB_VF : VALU_OPFVF<0b000010, "vfsub.vf">, Sched<[]>;
defm VFRSUB_VF : VALU_OPFVF<0b100111, "vfrsub.vf">, Sched<[]>;


// Vector Widening Floating-Point Add/Subtract Instructions

defm VFWADD_VV : VALU_OPFVV<0b110000, "vfwadd.vv">, Sched<[]>;
defm VFWADD_VF : VALU_OPFVF<0b110000, "vfwadd.vf">, Sched<[]>;
defm VFWSUB_VV : VALU_OPFVV<0b110010, "vfwsub.vv">, Sched<[]>;
defm VFWSUB_VF : VALU_OPFVF<0b110010, "vfwsub.vf">, Sched<[]>;

defm VFWADD_WV : VALU_OPFVV<0b110100, "vfwadd.wv">, Sched<[]>;
defm VFWADD_WF : VALU_OPFVF<0b110100, "vfwadd.wf">, Sched<[]>;
defm VFWSUB_WV : VALU_OPFVV<0b110110, "vfwsub.wv">, Sched<[]>;
defm VFWSUB_WF : VALU_OPFVF<0b110110, "vfwsub.wf">, Sched<[]>;


// Vector Single-Width Floating-Point Multiply/Divide Instructions

defm VFMUL_VV : VALU_OPFVV<0b100100, "vfmul.vv">, Sched<[]>;
defm VFMUL_VF : VALU_OPFVF<0b100100, "vfmul.vf">, Sched<[]>;

defm VFDIV_VV : VALU_OPFVV<0b100000, "vfdiv.vv">, Sched<[]>;
defm VFDIV_VF : VALU_OPFVF<0b100000, "vfdiv.vf">, Sched<[]>;
defm VFRDIV_VF : VALU_OPFVF<0b100001, "vfrdiv.vf">, Sched<[]>;


// Vector Widening Floating-Point Multiply Instructions

defm VFWMUL_VV : VALU_OPFVV<0b111000, "vfwmul.vv">, Sched<[]>;
defm VFWMUL_VF : VALU_OPFVF<0b111000, "vfwmul.vf">, Sched<[]>;


// Vector Single-Width Floating-Point Fused Multiply-Add Instructions

defm VFMACC_VV : VALU_OPFVV_MulAdd<0b101100, "vfmacc.vv">, Sched<[]>;
defm VFMACC_VF : VALU_OPFVF_MulAdd<0b101100, "vfmacc.vf">, Sched<[]>;

defm VFNMACC_VV : VALU_OPFVV_MulAdd<0b101101, "vfnmacc.vv">, Sched<[]>;
defm VFNMACC_VF : VALU_OPFVF_MulAdd<0b101101, "vfnmacc.vf">, Sched<[]>;

defm VFMSAC_VV : VALU_OPFVV_MulAdd<0b101110, "vfmsac.vv">, Sched<[]>;
defm VFMSAC_VF : VALU_OPFVF_MulAdd<0b101110, "vfmsac.vf">, Sched<[]>;

defm VFNMSAC_VV : VALU_OPFVV_MulAdd<0b101111, "vfnmsac.vv">, Sched<[]>;
defm VFNMSAC_VF : VALU_OPFVF_MulAdd<0b101111, "vfnmsac.vf">, Sched<[]>;

defm VFMADD_VV : VALU_OPFVV_MulAdd<0b101000, "vfmadd.vv">, Sched<[]>;
defm VFMADD_VF : VALU_OPFVF_MulAdd<0b101000, "vfmadd.vf">, Sched<[]>;

defm VFNMADD_VV : VALU_OPFVV_MulAdd<0b101001, "vfnmadd.vv">, Sched<[]>;
defm VFNMADD_VF : VALU_OPFVF_MulAdd<0b101001, "vfnmadd.vf">, Sched<[]>;

defm VFMSUB_VV : VALU_OPFVV_MulAdd<0b101010, "vfmsub.vv">, Sched<[]>;
defm VFMSUB_VF : VALU_OPFVF_MulAdd<0b101010, "vfmsub.vf">, Sched<[]>;

defm VFNMSUB_VV : VALU_OPFVV_MulAdd<0b101011, "vfnmsub.vv">, Sched<[]>;
defm VFNMSUB_VF : VALU_OPFVF_MulAdd<0b101011, "vfnmsub.vf">, Sched<[]>;


// Vector Widening Floating-Point Fused Multiply-Add Instructions

defm VFWMACC_VV : VALU_OPFVV_MulAdd<0b111100, "vfwmacc.vv">, Sched<[]>;
defm VFWMACC_VF : VALU_OPFVF_MulAdd<0b111100, "vfwmacc.vf">, Sched<[]>;

defm VFWNMACC_VV : VALU_OPFVV_MulAdd<0b111101, "vfwnmacc.vv">, Sched<[]>;
defm VFWNMACC_VF : VALU_OPFVF_MulAdd<0b111101, "vfwnmacc.vf">, Sched<[]>;

defm VFWMSAC_VV : VALU_OPFVV_MulAdd<0b111110, "vfwmsac.vv">, Sched<[]>;
defm VFWMSAC_VF : VALU_OPFVF_MulAdd<0b111110, "vfwmsac.vf">, Sched<[]>;

defm VFWNMSAC_VV : VALU_OPFVV_MulAdd<0b111111, "vfwnmsac.vv">, Sched<[]>;
defm VFWNMSAC_VF : VALU_OPFVF_MulAdd<0b111111, "vfwnmsac.vf">, Sched<[]>;


// Vector Floating-Point Square-Root Instruction

defm VFSQRT_V : VALU_OPFVV_VFUNARY1<0b00000, "vfsqrt.v">, Sched<[]>;


// Vector Floating-Point MIN/MAX Instructions

defm VFMIN_VV : VALU_OPFVV<0b000100, "vfmin.vv">, Sched<[]>;
defm VFMIN_VF : VALU_OPFVF<0b000100, "vfmin.vf">, Sched<[]>;

defm VFMAX_VV : VALU_OPFVV<0b000110, "vfmax.vv">, Sched<[]>;
defm VFMAX_VF : VALU_OPFVF<0b000110, "vfmax.vf">, Sched<[]>;


// Vector Floating-Point Sign-Injection Instructions

defm VFSGNJ_VV : VALU_OPFVV<0b001000, "vfsgnj.vv">, Sched<[]>;
defm VFSGNJ_VF : VALU_OPFVF<0b001000, "vfsgnj.vf">, Sched<[]>;

defm VFSGNJN_VV : VALU_OPFVV<0b001001, "vfsgnjn.vv">, Sched<[]>;
defm VFSGNJN_VF : VALU_OPFVF<0b001001, "vfsgnjn.vf">, Sched<[]>;

defm VFSGNJX_VV : VALU_OPFVV<0b001010, "vfsgnjx.vv">, Sched<[]>;
defm VFSGNJX_VF : VALU_OPFVF<0b001010, "vfsgnjx.vf">, Sched<[]>;


// Vector Floating-Point Compare Instructions

defm VMFEQ_VV : VALU_OPFVV<0b011000, "vmfeq.vv">, Sched<[]>;
defm VMFEQ_VF : VALU_OPFVF<0b011000, "vmfeq.vf">, Sched<[]>;

defm VMFNE_VV : VALU_OPFVV<0b011100, "vmfne.vv">, Sched<[]>;
defm VMFNE_VF : VALU_OPFVF<0b011100, "vmfne.vf">, Sched<[]>;

defm VMFLT_VV : VALU_OPFVV<0b011011, "vmflt.vv">, Sched<[]>;
defm VMFLT_VF : VALU_OPFVF<0b011011, "vmflt.vf">, Sched<[]>;

defm VMFLE_VV : VALU_OPFVV<0b011001, "vmfle.vv">, Sched<[]>;
defm VMFLE_VF : VALU_OPFVF<0b011001, "vmfle.vf">, Sched<[]>;

defm VMFGT_VF : VALU_OPFVF<0b011101, "vmfgt.vf">, Sched<[]>;
defm VMFGE_VF : VALU_OPFVF<0b011111, "vmfge.vf">, Sched<[]>;


// Vector Floating-Point Classify Instruction

defm VFCLASS_V : VALU_OPFVV_VFUNARY1<0b10000, "vfclass.v">, Sched<[]>;


// Vector Floating-Point Merge Instruction

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VFMERGE_VFM : RVInstVA<0b010111, 0b101, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins FPR32:$rs1, VR:$vs2, VRV0:$v0),
               "vfmerge.vfm", "$vd, $vs2, $rs1, v0">, Sched<[]> {
  bits<5> rs1;
  let Inst{19-15} = rs1;
}


// Vector Floating-Point Move Instruction

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VFMV_V_F : RVInstVA<0b010111, 0b101, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins FPR32:$rs1),
               "vfmv.v.f", "$vd, $rs1">, Sched<[]> {
  bits<5> rs1;
  let vs2 = 0b00000;
  let Inst{19-15} = rs1;
}


// Single-Width Floating-Point/Integer Type-Convert Instructions

defm VFCVT_XU_F_V : VALU_OPFVV_VFUNARY0<0b00000, "vfcvt.xu.f.v">, Sched<[]>;
defm VFCVT_X_F_V : VALU_OPFVV_VFUNARY0<0b00001, "vfcvt.x.f.v">, Sched<[]>;
defm VFCVT_F_XU_V : VALU_OPFVV_VFUNARY0<0b00010, "vfcvt.f.xu.v">, Sched<[]>;
defm VFCVT_F_X_V : VALU_OPFVV_VFUNARY0<0b00011, "vfcvt.f.x.v">, Sched<[]>;


// Widening Floating-Point/Integer Type-Convert Instructions

defm VFWCVT_XU_F_V : VALU_OPFVV_VFUNARY0<0b01000, "vfwcvt.xu.f.v">, Sched<[]>;
defm VFWCVT_X_F_V : VALU_OPFVV_VFUNARY0<0b01001, "vfwcvt.x.f.v">, Sched<[]>;
defm VFWCVT_F_XU_V : VALU_OPFVV_VFUNARY0<0b01010, "vfwcvt.f.xu.v">, Sched<[]>;
defm VFWCVT_F_X_V : VALU_OPFVV_VFUNARY0<0b01011, "vfwcvt.f.x.v">, Sched<[]>;
defm VFWCVT_F_F_V : VALU_OPFVV_VFUNARY0<0b01100, "vfwcvt.f.f.v">, Sched<[]>;


// Narrowing Floating-Point/Integer Type-Convert Instructions

defm VFNCVT_XU_F_W : VALU_OPFVV_VFUNARY0<0b10000, "vfncvt.xu.f.w">, Sched<[]>;
defm VFNCVT_X_F_W : VALU_OPFVV_VFUNARY0<0b10001, "vfncvt.x.f.w">, Sched<[]>;
defm VFNCVT_F_XU_W : VALU_OPFVV_VFUNARY0<0b10010, "vfncvt.f.xu.w">, Sched<[]>;
defm VFNCVT_F_X_W : VALU_OPFVV_VFUNARY0<0b10011, "vfncvt.f.x.w">, Sched<[]>;
defm VFNCVT_F_F_W : VALU_OPFVV_VFUNARY0<0b10100, "vfncvt.f.f.w">, Sched<[]>;
defm VFNCVT_ROD_F_F_W : VALU_OPFVV_VFUNARY0<0b10101, "vfncvt.rod.f.f.w">, Sched<[]>;


// Vector Single-Width Integer Reduction Instructions

defm VREDSUM_VS : VALU_OPMVV<0b000000, "vredsum.vs">, Sched<[]>;
defm VREDMAXU_VS : VALU_OPMVV<0b000110, "vredmaxu.vs">, Sched<[]>;
defm VREDMAX_VS : VALU_OPMVV<0b000111, "vredmax.vs">, Sched<[]>;
defm VREDMINU_VS : VALU_OPMVV<0b000100, "vredminu.vs">, Sched<[]>;
defm VREDMIN_VS : VALU_OPMVV<0b000101, "vredmin.vs">, Sched<[]>;
defm VREDAND_VS : VALU_OPMVV<0b000001, "vredand.vs">, Sched<[]>;
defm VREDOR_VS : VALU_OPMVV<0b000010, "vredor.vs">, Sched<[]>;
defm VREDXOR_VS : VALU_OPMVV<0b000011, "vredxor.vs">, Sched<[]>;


// Vector Widening Integer Reduction Instructions

defm VWREDSUMU_VS : VALU_OPIVV<0b110000, "vwredsumu.vs">, Sched<[]>;
defm VWREDSUM_VS : VALU_OPIVV<0b110001, "vwredsum.vs">, Sched<[]>;


// Vector Single-Width Floating-Point Reduction Instructions

defm VFREDOSUM_VS : VALU_OPFVV<0b000011, "vfredosum.vs">, Sched<[]>;
defm VFREDSUM_VS : VALU_OPFVV<0b000001, "vfredsum.vs">, Sched<[]>;
defm VFREDMAX_VS : VALU_OPFVV<0b000111, "vfredmax.vs">, Sched<[]>;
defm VFREDMIN_VS : VALU_OPFVV<0b000101, "vfredmin.vs">, Sched<[]>;


// Vector Widening Floating-Point Reduction Instructions

defm VFWREDOSUM_VS : VALU_OPFVV<0b110011, "vfwredosum.vs">, Sched<[]>;
defm VFWREDSUM_VS : VALU_OPFVV<0b110001, "vfwredsum.vs">, Sched<[]>;


// Vector Mask-Register Logical Instructions

def VMAND_MM : VALU_OPMVV_um<0b011001, "vmand.mm">, Sched<[]>;
def VMNAND_MM : VALU_OPMVV_um<0b011101, "vmnand.mm">, Sched<[]>;
def VMANDNOT_MM : VALU_OPMVV_um<0b011000, "vmandnot.mm">, Sched<[]>;
def VMXOR_MM : VALU_OPMVV_um<0b011011, "vmxor.mm">, Sched<[]>;
def VMOR_MM : VALU_OPMVV_um<0b011010, "vmor.mm">, Sched<[]>;
def VMNOR_MM : VALU_OPMVV_um<0b011110, "vmnor.mm">, Sched<[]>;
def VMORNOT_MM : VALU_OPMVV_um<0b011100, "vmornot.mm">, Sched<[]>;
def VMXNOR_MM : VALU_OPMVV_um<0b011111, "vmxnor.mm">, Sched<[]>;


// Vector mask population count Instruction

defm VPOPC_M : VALU_OPMVV_VWXUNARY0<0b10000, "vpopc.m">, Sched<[]>;


// find-first-set mask bit Instruction

defm VFIRST_M : VALU_OPMVV_VWXUNARY0<0b10001, "vfirst.m">, Sched<[]>;


// set-before-first mask bit Instruction

defm VMSBF_M : VALU_OPMVV_VMUNARY0<0b00001, "vmsbf.m">, Sched<[]>;


// set-including-first mask bit Instruction

defm VMSIF_M : VALU_OPMVV_VMUNARY0<0b00011, "vmsif.m">, Sched<[]>;


// set-only-first mask bit Instruction

defm VMSOF_M : VALU_OPMVV_VMUNARY0<0b00010, "vmsof.m">, Sched<[]>;


// Vector Iota Instruction

defm VIOTA_M : VALU_OPMVV_VMUNARY0<0b10000, "viota.m">, Sched<[]>;


// Vector Element Index Instruction

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VID_V_m : RVInstVA<0b010100, 0b010, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VMR:$vm), "vid.v", "$vd, $vm">,
              Sched<[]> {
  bits<5> vs1;
  let vs1 = 0b10001;
  let vs2 = 0b00000;
  let Inst{19-15} = vs1;
}
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VID_V_um : RVInstVA<0b010100, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins), "vid.v", "$vd">, Sched<[]> {
  bits<5> vs1;
  let vs1 = 0b10001;
  let vs2 = 0b00000;
  let Inst{19-15} = vs1;
}


// Integer Scalar Move Instruction

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VMV_X_S : RVInstVA<0b010000, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs GPR:$rd), (ins VR:$vs2),
               "vmv.x.s", "$rd, $vs2">, Sched<[]> {
  bits<5> vs1;
  let vs1 = 0b00000;
  let Inst{19-15} = vs1;
  let Inst{11-7} = rd;
}
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VMV_S_X : RVInstVA<0b010000, 0b110, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins GPR:$rs1),
               "vmv.s.x", "$vd, $rs1">, Sched<[]> {
  bits<5> rs1;
  let vs2 = 0b00000;
  let Inst{19-15} = rs1;
}


// Floating-Point Scalar Move Instructions

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VFMV_F_S : RVInstVA<0b010000, 0b001, RVV_Unmasked, OPC_OP_V,
               (outs FPR32:$rd), (ins VR:$vs2),
               "vfmv.f.s", "$rd, $vs2">, Sched<[]> {
  bits<5> vs1;
  let vs1 = 0b00000;
  let Inst{19-15} = vs1;
  let Inst{11-7} = rd;
}
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VFMV_S_F : RVInstVA<0b010000, 0b101, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins FPR32:$rs1),
               "vfmv.s.f", "$vd, $rs1">, Sched<[]> {
  bits<5> rs1;
  let vs2 = 0b00000;
  let Inst{19-15} = rs1;
}


// Vector Slide Instructions

defm VSLIDEUP_VX : VALU_OPIVX<0b001110, "vslideup.vx">, Sched<[]>;
defm VSLIDEUP_VI : VALU_OPIVI_unsigned<0b001110, "vslideup.vi">, Sched<[]>;

defm VSLIDEDOWN_VX : VALU_OPIVX<0b001111, "vslidedown.vx">, Sched<[]>;
defm VSLIDEDOWN_VI : VALU_OPIVI_unsigned<0b001111, "vslidedown.vi">, Sched<[]>;

defm VSLIDE1UP_VX : VALU_OPMVX<0b001110, "vslide1up.vx">, Sched<[]>;

defm VSLIDE1DOWN_VX : VALU_OPMVX<0b001111, "vslide1down.vx">, Sched<[]>;


// Vector Register Gather Instructions

defm VRGATHER_VV : VALU_OPIVV<0b001100, "vrgather.vv">, Sched<[]>;
defm VRGATHER_VX : VALU_OPIVX<0b001100, "vrgather.vx">, Sched<[]>;
defm VRGATHER_VI : VALU_OPIVI_unsigned<0b001100, "vrgather.vi">, Sched<[]>;


// Vector Compress Instruction

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VCOMPRESS_VM : RVInstVA<0b010111, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VLR:$vl),
               "vcompress.vm", "$vd, $vs2, $vs1">, Sched<[]> {
  bits<5> vs1;
  let Inst{19-15} = vs1;
}


// Whole Vector Register Move Instructions

foreach nf = 1-8 in {
  def VMV#nf#R_V : VALU_OPIVI_VMVWholeReg<!add(nf, -1), "vmv"#nf#"r.v">,
                   Sched<[]>;
}


// Vector Integer Dot-Product Instructions

defm VDOTU_VV : VALU_OPIVV<0b111000, "vdotu.vv">, Sched<[]>;
defm VDOT_VV : VALU_OPIVV<0b111001, "vdot.vv">, Sched<[]>;


// Vector Floating-Point Dot-Product Instruction

defm VFDOT_VV : VALU_OPFVV<0b111001, "vfdot.vv">, Sched<[]>;


} // Predicates = [HasStdExtV]

//===----------------------------------------------------------------------===//
// Assembler Pseudo Instructions
//===----------------------------------------------------------------------===//

let EmitPriority = 0 in {


def : InstAlias<"vsetvli $rd, $rs1, $uimm",
                (VSETVLI  GPR:$rd, GPR:$rs1, uimm11:$uimm)>;


def : InstAlias<"vlb.v $vd, (${rs1})",
                (VLB_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vlb.v $vd, (${rs1}), $vm",
                (VLB_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vlh.v $vd, (${rs1})",
                (VLH_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vlh.v $vd, (${rs1}), $vm",
                (VLH_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vlw.v $vd, (${rs1})",
                (VLW_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vlw.v $vd, (${rs1}), $vm",
                (VLW_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vlbu.v $vd, (${rs1})",
                (VLBU_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vlbu.v $vd, (${rs1}), $vm",
                (VLBU_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vlhu.v $vd, (${rs1})",
                (VLHU_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vlhu.v $vd, (${rs1}), $vm",
                (VLHU_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vlwu.v $vd, (${rs1})",
                (VLWU_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vlwu.v $vd, (${rs1}), $vm",
                (VLWU_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vle.v $vd, (${rs1})",
                (VLE_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle.v $vd, (${rs1}), $vm",
                (VLE_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;

def : InstAlias<"vsb.v $vs3, (${rs1})",
                (VSB_V_um  VR:$vs3, GPR:$rs1, 0)>;
def : InstAlias<"vsb.v $vs3, (${rs1}), $vm",
                (VSB_V_m  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vsh.v $vs3, (${rs1})",
                (VSH_V_um  VR:$vs3, GPR:$rs1, 0)>;
def : InstAlias<"vsh.v $vs3, (${rs1}), $vm",
                (VSH_V_m  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vsw.v $vs3, (${rs1})",
                (VSW_V_um  VR:$vs3, GPR:$rs1, 0)>;
def : InstAlias<"vsw.v $vs3, (${rs1}), $vm",
                (VSW_V_m  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vse.v $vs3, (${rs1})",
                (VSE_V_um  VR:$vs3, GPR:$rs1, 0)>;
def : InstAlias<"vse.v $vs3, (${rs1}), $vm",
                (VSE_V_m  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;


def : InstAlias<"vlsb.v $vd, (${rs1}), $rs2",
                (VLSB_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vlsb.v $vd, (${rs1}), $rs2, $vm",
                (VLSB_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vlsh.v $vd, (${rs1}), $rs2",
                (VLSH_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vlsh.v $vd, (${rs1}), $rs2, $vm",
                (VLSH_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vlsw.v $vd, (${rs1}), $rs2",
                (VLSW_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vlsw.v $vd, (${rs1}), $rs2, $vm",
                (VLSW_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vlsbu.v $vd, (${rs1}), $rs2",
                (VLSBU_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vlsbu.v $vd, (${rs1}), $rs2, $vm",
                (VLSBU_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vlshu.v $vd, (${rs1}), $rs2",
                (VLSHU_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vlshu.v $vd, (${rs1}), $rs2, $vm",
                (VLSHU_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vlswu.v $vd, (${rs1}), $rs2",
                (VLSWU_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vlswu.v $vd, (${rs1}), $rs2, $vm",
                (VLSWU_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vlse.v $vd, (${rs1}), $rs2",
                (VLSE_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vlse.v $vd, (${rs1}), $rs2, $vm",
                (VLSE_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;

def : InstAlias<"vssb.v $vs3, (${rs1}), $rs2",
                (VSSB_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vssb.v $vs3, (${rs1}), $rs2, $vm",
                (VSSB_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vssh.v $vs3, (${rs1}), $rs2",
                (VSSH_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vssh.v $vs3, (${rs1}), $rs2, $vm",
                (VSSH_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vssw.v $vs3, (${rs1}), $rs2",
                (VSSW_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vssw.v $vs3, (${rs1}), $rs2, $vm",
                (VSSW_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vsse.v $vs3, (${rs1}), $rs2",
                (VSSE_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vsse.v $vs3, (${rs1}), $rs2, $vm",
                (VSSE_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;


def : InstAlias<"vlxb.v $vd, (${rs1}), $vs2",
                (VLXB_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vlxb.v $vd, (${rs1}), $vs2, $vm",
                (VLXB_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vlxh.v $vd, (${rs1}), $vs2",
                (VLXH_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vlxh.v $vd, (${rs1}), $vs2, $vm",
                (VLXH_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vlxw.v $vd, (${rs1}), $vs2",
                (VLXW_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vlxw.v $vd, (${rs1}), $vs2, $vm",
                (VLXW_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vlxbu.v $vd, (${rs1}), $vs2",
                (VLXBU_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vlxbu.v $vd, (${rs1}), $vs2, $vm",
                (VLXBU_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vlxhu.v $vd, (${rs1}), $vs2",
                (VLXHU_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vlxhu.v $vd, (${rs1}), $vs2, $vm",
                (VLXHU_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vlxwu.v $vd, (${rs1}), $vs2",
                (VLXWU_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vlxwu.v $vd, (${rs1}), $vs2, $vm",
                (VLXWU_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vlxe.v $vd, (${rs1}), $vs2",
                (VLXE_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vlxe.v $vd, (${rs1}), $vs2, $vm",
                (VLXE_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;

def : InstAlias<"vsxb.v $vs3, (${rs1}), $vs2",
                (VSXB_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsxb.v $vs3, (${rs1}), $vs2, $vm",
                (VSXB_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsxh.v $vs3, (${rs1}), $vs2",
                (VSXH_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsxh.v $vs3, (${rs1}), $vs2, $vm",
                (VSXH_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsxw.v $vs3, (${rs1}), $vs2",
                (VSXW_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsxw.v $vs3, (${rs1}), $vs2, $vm",
                (VSXW_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsxe.v $vs3, (${rs1}), $vs2",
                (VSXE_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsxe.v $vs3, (${rs1}), $vs2, $vm",
                (VSXE_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsuxb.v $vs3, (${rs1}), $vs2",
                (VSUXB_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsuxb.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXB_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsuxh.v $vs3, (${rs1}), $vs2",
                (VSUXH_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsuxh.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXH_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsuxw.v $vs3, (${rs1}), $vs2",
                (VSUXW_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsuxw.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXW_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsuxe.v $vs3, (${rs1}), $vs2",
                (VSUXE_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsuxe.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXE_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;


def : InstAlias<"vlbff.v $vd, (${rs1})",
                (VLBFF_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vlbff.v $vd, (${rs1}), $vm",
                (VLBFF_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vlhff.v $vd, (${rs1})",
                (VLHFF_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vlhff.v $vd, (${rs1}), $vm",
                (VLHFF_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vlwff.v $vd, (${rs1})",
                (VLWFF_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vlwff.v $vd, (${rs1}), $vm",
                (VLWFF_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vlbuff.v $vd, (${rs1})",
                (VLBUFF_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vlbuff.v $vd, (${rs1}), $vm",
                (VLBUFF_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vlhuff.v $vd, (${rs1})",
                (VLHUFF_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vlhuff.v $vd, (${rs1}), $vm",
                (VLHUFF_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vlwuff.v $vd, (${rs1})",
                (VLWUFF_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vlwuff.v $vd, (${rs1}), $vm",
                (VLWUFF_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vleff.v $vd, (${rs1})",
                (VLEFF_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vleff.v $vd, (${rs1}), $vm",
                (VLEFF_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;


foreach nf = 2-8 in {

  def : InstAlias<"vlseg"#nf#"b.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"B_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"b.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"B_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"h.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"H_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"h.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"H_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"w.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"W_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"w.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"W_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"bu.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"BU_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"bu.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"BU_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"hu.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"HU_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"hu.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"HU_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"wu.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"WU_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"wu.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"WU_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;

  def : InstAlias<"vsseg"#nf#"b.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"B_V_um")
                  VR:$vs3, GPR:$rs1, 0)>;
  def : InstAlias<"vsseg"#nf#"b.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"B_V_m")
                  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vsseg"#nf#"h.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"H_V_um")
                  VR:$vs3, GPR:$rs1, 0)>;
  def : InstAlias<"vsseg"#nf#"h.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"H_V_m")
                  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vsseg"#nf#"w.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"W_V_um")
                  VR:$vs3, GPR:$rs1, 0)>;
  def : InstAlias<"vsseg"#nf#"w.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"W_V_m")
                  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vsseg"#nf#"e.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E_V_um")
                  VR:$vs3, GPR:$rs1, 0)>;
  def : InstAlias<"vsseg"#nf#"e.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E_V_m")
                  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;


  def : InstAlias<"vlsseg"#nf#"b.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"B_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vlsseg"#nf#"b.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"B_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"h.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"H_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vlsseg"#nf#"h.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"H_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"w.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"W_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vlsseg"#nf#"w.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"W_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"bu.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"BU_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vlsseg"#nf#"bu.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"BU_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"hu.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"HU_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vlsseg"#nf#"hu.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"HU_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"wu.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"WU_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vlsseg"#nf#"wu.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"WU_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"e.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vlsseg"#nf#"e.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;

  def : InstAlias<"vssseg"#nf#"b.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"B_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vssseg"#nf#"b.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"B_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vssseg"#nf#"h.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"H_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vssseg"#nf#"h.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"H_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vssseg"#nf#"w.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"W_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vssseg"#nf#"w.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"W_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vssseg"#nf#"e.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vssseg"#nf#"e.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;


  def : InstAlias<"vlxseg"#nf#"b.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"B_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vlxseg"#nf#"b.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"B_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"h.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"H_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vlxseg"#nf#"h.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"H_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"w.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"W_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vlxseg"#nf#"w.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"W_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"bu.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"BU_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vlxseg"#nf#"bu.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"BU_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"hu.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"HU_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vlxseg"#nf#"hu.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"HU_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"wu.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"WU_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vlxseg"#nf#"wu.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"WU_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"e.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"E_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vlxseg"#nf#"e.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"E_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;

  def : InstAlias<"vsxseg"#nf#"b.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"B_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vsxseg"#nf#"b.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"B_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vsxseg"#nf#"h.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"H_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vsxseg"#nf#"h.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"H_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vsxseg"#nf#"w.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"W_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vsxseg"#nf#"w.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"W_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vsxseg"#nf#"e.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"E_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vsxseg"#nf#"e.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"E_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;


  def : InstAlias<"vlseg"#nf#"bff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"BFF_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"bff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"BFF_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"hff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"HFF_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"hff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"HFF_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"wff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"WFF_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"wff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"WFF_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"buff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"BUFF_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"buff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"BUFF_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"huff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"HUFF_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"huff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"HUFF_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"wuff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"WUFF_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"wuff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"WUFF_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"eff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"EFF_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"eff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"EFF_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
}


foreach nf = 1-8 in {

  def : InstAlias<"vl"#nf#"r.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VL"#nf#"R_V")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vs"#nf#"r.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VS"#nf#"R_V")
                  VR:$vs3, GPR:$rs1, 0)>;
}


def : InstAlias<"vamoswapw.v $vd, (${rs1}), $vs2, $vd",
                (VAMOSWAPW_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoswapw.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOSWAPW_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoswapw.v x0, (${rs1}), $vs2, $vd",
                (VAMOSWAPW_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoswapw.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOSWAPW_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamoaddw.v $vd, (${rs1}), $vs2, $vd",
                (VAMOADDW_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoaddw.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOADDW_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoaddw.v x0, (${rs1}), $vs2, $vd",
                (VAMOADDW_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoaddw.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOADDW_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamoxorw.v $vd, (${rs1}), $vs2, $vd",
                (VAMOXORW_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoxorw.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOXORW_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoxorw.v x0, (${rs1}), $vs2, $vd",
                (VAMOXORW_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoxorw.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOXORW_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamoandw.v $vd, (${rs1}), $vs2, $vd",
                (VAMOANDW_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoandw.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOANDW_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoandw.v x0, (${rs1}), $vs2, $vd",
                (VAMOANDW_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoandw.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOANDW_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamoorw.v $vd, (${rs1}), $vs2, $vd",
                (VAMOORW_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoorw.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOORW_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoorw.v x0, (${rs1}), $vs2, $vd",
                (VAMOORW_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoorw.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOORW_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamominw.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMINW_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamominw.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINW_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamominw.v x0, (${rs1}), $vs2, $vd",
                (VAMOMINW_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamominw.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINW_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamomaxw.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMAXW_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamomaxw.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXW_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamomaxw.v x0, (${rs1}), $vs2, $vd",
                (VAMOMAXW_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamomaxw.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXW_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamominuw.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMINUW_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamominuw.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINUW_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamominuw.v x0, (${rs1}), $vs2, $vd",
                (VAMOMINUW_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamominuw.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINUW_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamomaxuw.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMAXUW_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamomaxuw.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXUW_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamomaxuw.v x0, (${rs1}), $vs2, $vd",
                (VAMOMAXUW_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamomaxuw.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXUW_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamoswape.v $vd, (${rs1}), $vs2, $vd",
                (VAMOSWAPE_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoswape.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOSWAPE_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoswape.v x0, (${rs1}), $vs2, $vd",
                (VAMOSWAPE_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoswape.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOSWAPE_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamoadde.v $vd, (${rs1}), $vs2, $vd",
                (VAMOADDE_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoadde.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOADDE_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoadde.v x0, (${rs1}), $vs2, $vd",
                (VAMOADDE_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoadde.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOADDE_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamoxore.v $vd, (${rs1}), $vs2, $vd",
                (VAMOXORE_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoxore.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOXORE_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoxore.v x0, (${rs1}), $vs2, $vd",
                (VAMOXORE_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoxore.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOXORE_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamoande.v $vd, (${rs1}), $vs2, $vd",
                (VAMOANDE_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoande.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOANDE_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoande.v x0, (${rs1}), $vs2, $vd",
                (VAMOANDE_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoande.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOANDE_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamoore.v $vd, (${rs1}), $vs2, $vd",
                (VAMOORE_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoore.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOORE_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoore.v x0, (${rs1}), $vs2, $vd",
                (VAMOORE_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoore.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOORE_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamomine.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMINE_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamomine.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINE_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamomine.v x0, (${rs1}), $vs2, $vd",
                (VAMOMINE_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamomine.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINE_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamomaxe.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMAXE_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamomaxe.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXE_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamomaxe.v x0, (${rs1}), $vs2, $vd",
                (VAMOMAXE_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamomaxe.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXE_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamominue.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMINUE_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamominue.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINUE_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamominue.v x0, (${rs1}), $vs2, $vd",
                (VAMOMINUE_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamominue.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINUE_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamomaxue.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMAXUE_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamomaxue.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXUE_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamomaxue.v x0, (${rs1}), $vs2, $vd",
                (VAMOMAXUE_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamomaxue.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXUE_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;


def : InstAlias<"vwcvt.x.x.v $vd, $vs2",
                (VWADD_VX_um  VR:$vd, VR:$vs2, X0)>;
def : InstAlias<"vwcvt.x.x.v $vd, $vs2, $vm",
                (VWADD_VX_m  VR:$vd, VR:$vs2, X0, VMR:$vm)>;
def : InstAlias<"vwcvtu.x.x.v $vd, $vs2",
                (VWADDU_VX_um  VR:$vd, VR:$vs2, X0)>;
def : InstAlias<"vwcvtu.x.x.v $vd, $vs2, $vm",
                (VWADDU_VX_m  VR:$vd, VR:$vs2, X0, VMR:$vm)>;


def : InstAlias<"vnot.v $vd, $vs2",
                (VXOR_VI_um  VR:$vd, VR:$vs2, -1)>;
def : InstAlias<"vnot.v $vd, $vs2, $vm",
                (VXOR_VI_m  VR:$vd, VR:$vs2, -1, VMR:$vm)>;


def : InstAlias<"vmsgt.vv $vd, $vs2, $vs1",
                (VMSLT_VV_um  VR:$vd, VR:$vs1, VR:$vs2)>;
def : InstAlias<"vmsgt.vv $vd, $vs2, $vs1, $vm",
                (VMSLT_VV_m  VR:$vd, VR:$vs1, VR:$vs2, VMR:$vm)>;
def : InstAlias<"vmsgtu.vv $vd, $vs2, $vs1",
                (VMSLTU_VV_um  VR:$vd, VR:$vs1, VR:$vs2)>;
def : InstAlias<"vmsgtu.vv $vd, $vs2, $vs1, $vm",
                (VMSLTU_VV_m  VR:$vd, VR:$vs1, VR:$vs2, VMR:$vm)>;
def : InstAlias<"vmsge.vv $vd, $vs2, $vs1",
                (VMSLE_VV_um  VR:$vd, VR:$vs1, VR:$vs2)>;
def : InstAlias<"vmsge.vv $vd, $vs2, $vs1, $vm",
                (VMSLE_VV_m  VR:$vd, VR:$vs1, VR:$vs2, VMR:$vm)>;
def : InstAlias<"vmsgeu.vv $vd, $vs2, $vs1",
                (VMSLEU_VV_um  VR:$vd, VR:$vs1, VR:$vs2)>;
def : InstAlias<"vmsgeu.vv $vd, $vs2, $vs1, $vm",
                (VMSLEU_VV_m  VR:$vd, VR:$vs1, VR:$vs2, VMR:$vm)>;


def : InstAlias<"vmfgt.vv $vd, $vs2, $vs1",
                (VMFLT_VV_um  VR:$vd, VR:$vs1, VR:$vs2)>;
def : InstAlias<"vmfgt.vv $vd, $vs2, $vs1, $vm",
                (VMFLT_VV_m  VR:$vd, VR:$vs1, VR:$vs2, VMR:$vm)>;
def : InstAlias<"vmfge.vv $vd, $vs2, $vs1",
                (VMFLE_VV_um  VR:$vd, VR:$vs1, VR:$vs2)>;
def : InstAlias<"vmfge.vv $vd, $vs2, $vs1, $vm",
                (VMFLE_VV_m  VR:$vd, VR:$vs1, VR:$vs2, VMR:$vm)>;


def : InstAlias<"vmcpy.m $vd, $vs2",
                (VMAND_MM  VR:$vd, VR:$vs2, VR:$vs2)>;
def : InstAlias<"vmclr.m $vd",
                (VMXOR_MM  VR:$vd, VR:$vd, VR:$vd)>;
def : InstAlias<"vmset.m $vd",
                (VMXNOR_MM  VR:$vd, VR:$vd, VR:$vd)>;
def : InstAlias<"vmnot.m $vd, $vs2",
                (VMNAND_MM  VR:$vd, VR:$vs2, VR:$vs2)>;

}

//===----------------------------------------------------------------------===//
// Pseudo-instructions and codegen patterns
//===----------------------------------------------------------------------===//

let Predicates = [HasStdExtV] in {

let hasSideEffects = 0, mayLoad = 0, mayStore = 0,
    isCodeGenOnly = 0, isAsmParserOnly = 1 in {
def PseudoVMSLT_VI_um : Pseudo<(outs VR:$vd), (ins VR:$vs2, simm5PlusOne:$imm), [],
                      "vmslt.vi", "$vd, $vs2, $imm">;
def PseudoVMSLT_VI_m : Pseudo<(outs VR:$vd), (ins VR:$vs2, simm5PlusOne:$imm,
                      VMR:$vm), [], "vmslt.vi", "$vd, $vs2, $imm, $vm">;
def PseudoVMSLTU_VI_um : Pseudo<(outs VR:$vd), (ins VR:$vs2, simm5PlusOne:$imm), [],
                      "vmsltu.vi", "$vd, $vs2, $imm">;
def PseudoVMSLTU_VI_m : Pseudo<(outs VR:$vd), (ins VR:$vs2, simm5PlusOne:$imm,
                      VMR:$vm), [], "vmsltu.vi", "$vd, $vs2, $imm, $vm">;
def PseudoVMSGE_VI_um : Pseudo<(outs VR:$vd), (ins VR:$vs2, simm5PlusOne:$imm), [],
                      "vmsge.vi", "$vd, $vs2, $imm">;
def PseudoVMSGE_VI_m : Pseudo<(outs VR:$vd), (ins VR:$vs2, simm5PlusOne:$imm,
                      VMR:$vm), [], "vmsge.vi", "$vd, $vs2, $imm, $vm">;
def PseudoVMSGEU_VI_um : Pseudo<(outs VR:$vd), (ins VR:$vs2, simm5PlusOne:$imm), [],
                      "vmsgeu.vi", "$vd, $vs2, $imm">;
def PseudoVMSGEU_VI_m : Pseudo<(outs VR:$vd), (ins VR:$vs2, simm5PlusOne:$imm,
                      VMR:$vm), [], "vmsgeu.vi", "$vd, $vs2, $imm, $vm">;
def PseudoVMSGE_VX_um : Pseudo<(outs VR:$vd), (ins VR:$vs2, GPR:$rs1), [],
                      "vmsge.vx", "$vd, $vs2, $rs1">;
def PseudoVMSGE_VX_m : Pseudo<(outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VMR:$vm), [],
                      "vmsge.vx", "$vd, $vs2, $rs1, $vm">;
def PseudoVMSGEU_VX_um : Pseudo<(outs VR:$vd), (ins VR:$vs2, GPR:$rs1), [],
                      "vmsgeu.vx", "$vd, $vs2, $rs1">;
def PseudoVMSGEU_VX_m : Pseudo<(outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VMR:$vm), [],
                      "vmsgeu.vx", "$vd, $vs2, $rs1, $vm">;

def PseudoVMSGE_VX_m_VT : Pseudo<(outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VMR:$vm,
                      VR:$vt), [], "vmsge.vx", "$vd, $vs2, $rs1, $vm, $vt">;
def PseudoVMSGEU_VX_m_VT : Pseudo<(outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VMR:$vm,
                      VR:$vt), [], "vmsgeu.vx", "$vd, $vs2, $rs1, $vm, $vt">;
}

let hasSideEffects = 1, mayLoad = 0, mayStore = 0,
    isCodeGenOnly = 1, isAsmParserOnly = 0 in {
  def PseudoCSRR_VL : Pseudo<(outs GPR:$rd), (ins VLR:$vl), []>,
                      PseudoInstExpansion<(CSRRS GPR:$rd, 0xCC0, X0)>;
}


class PatVrVr<SDPatternOperator OpNode, RVInst Inst>
    : Pat<(OpNode VR:$rs1, VR:$rs2), (Inst VR:$rs1, VR:$rs2)>;

class PatVrIm<SDPatternOperator OpNode, RVInst Inst>
    : Pat<(OpNode VR:$rs1, (RISCVBROADCAST simm5:$imm)), (Inst VR:$rs1, simm5:$imm)>; 

def : PatVrVr<int_riscv_vadd, VADD_VV_um>;
def : PatVrVr<int_riscv_vsub, VSUB_VV_um>;
def : PatVrIm<int_riscv_vadd, VADD_VI_um>;
/*
def : PatVrVr<int_riscv_vmul, VMUL_VV_um>;
def : PatVrVr<int_riscv_vand, VAND_VV_um>;
def : PatVrVr<int_riscv_vor, VOR_VV_um>;
def : PatVrVr<int_riscv_vxor, VXOR_VV_um>;
*/

// TODO exploit immediate offset
def : Pat<(int_riscv_vlw GPR:$rs1),
          (VLW_V_um GPR:$rs1, 0)>;

def : Pat<(int_riscv_vsw VR:$vs3, GPR:$rs1),
          (VSW_V_um VR:$vs3, GPR:$rs1, 0)>;

def : Pat<(RISCVSETVL GPR:$rs1, GPR:$rs2), (VSETVL GPR:$rs1, GPR:$rs2)>;

} // Predicates = [HasStdExtV]
