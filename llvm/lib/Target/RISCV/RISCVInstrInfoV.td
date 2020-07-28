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
  let DecoderMethod = "decodeVMR";
}

def Zero : Operand<XLenVT>, ImmLeaf<XLenVT, [{return Imm == 0;}]> {
  let ParserMatchClass = ImmZeroAsmOperand;
  let PrintMethod = "printZero";
}

//===----------------------------------------------------------------------===//
// Instruction class templates
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
multiclass VLoad_UnitStride<bits<3> nf, bits<1> mew, bits<2> mop,
                            bits<3> width, string opcodestr> {
  def _m  : RVInstVLoad<nf, mew, mop, width, RVV_Masked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, Zero:$zero, VMR:$vm),
                  opcodestr, "$vd, ${zero}(${rs1}), $vm"> {
    let Inst{24-20} = 0b00000;
  }
  def _um : RVInstVLoad<nf, mew, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, Zero:$zero),
                  opcodestr, "$vd, ${zero}(${rs1})"> {
    let Inst{24-20} = 0b00000;
  }
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
multiclass VLoad_UnitStrideFF<bits<3> nf, bits<1> mew, bits<2> mop,
                              bits<3> width, string opcodestr> {
  def _m  : RVInstVLoad<nf, mew, mop, width, RVV_Masked, OPC_LOAD_FP,
                    (outs VR:$vd), (ins GPR:$rs1, Zero:$zero, VMR:$vm),
                    opcodestr, "$vd, ${zero}(${rs1}), $vm"> {
    let Inst{24-20} = 0b10000;
  }
  def _um : RVInstVLoad<nf, mew, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                    (outs VR:$vd), (ins GPR:$rs1, Zero:$zero),
                    opcodestr, "$vd, ${zero}(${rs1})"> {
    let Inst{24-20} = 0b10000;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
multiclass VStore_UnitStride<bits<3> nf, bits<1> mew, bits<2> mop,
                             bits<3> width, string opcodestr> {
  def _m  : RVInstVStore<nf, mew, mop, width, RVV_Masked, OPC_STORE_FP,
                     (outs), (ins VR:$vs3, GPR:$rs1, Zero:$zero, VMR:$vm),
                     opcodestr, "$vs3, ${zero}(${rs1}), $vm"> {
    let Inst{24-20} = 0b00000;
  }
  def _um : RVInstVStore<nf, mew, mop, width, RVV_Unmasked, OPC_STORE_FP,
                     (outs), (ins VR:$vs3, GPR:$rs1, Zero:$zero),
                     opcodestr, "$vs3, ${zero}(${rs1})"> {
    let Inst{24-20} = 0b00000;
  }
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
multiclass VLoad_Strided<bits<3> nf, bits<1> mew, bits<2> mop,
                         bits<3> width, string opcodestr> {
  def _m  : RVInstVLoad<nf, mew, mop, width, RVV_Masked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, GPR:$rs2, Zero:$zero, VMR:$vm),
                  opcodestr, "$vd, ${zero}(${rs1}), $rs2, $vm"> {
    bits<5> rs2;
    let Inst{24-20} = rs2;
  }
  def _um : RVInstVLoad<nf, mew, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, GPR:$rs2, Zero:$zero),
                  opcodestr, "$vd, ${zero}(${rs1}), $rs2"> {
    bits<5> rs2;
    let Inst{24-20} = rs2;
  }
}
  
let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
multiclass VStore_Strided<bits<3> nf, bits<1> mew, bits<2> mop,
                          bits<3> width, string opcodestr> {
  def _m  : RVInstVStore<nf, mew, mop, width, RVV_Masked, OPC_STORE_FP,
                   (outs), (ins VR:$vs3, GPR:$rs1, GPR:$rs2, Zero:$zero, VMR:$vm),
                   opcodestr, "$vs3, ${zero}(${rs1}), $rs2, $vm"> {
    bits<5> rs2;
    let Inst{24-20} = rs2;
  }
  def _um : RVInstVStore<nf, mew, mop, width, RVV_Unmasked, OPC_STORE_FP,
                   (outs), (ins VR:$vs3, GPR:$rs1, GPR:$rs2, Zero:$zero),
                   opcodestr, "$vs3, ${zero}(${rs1}), $rs2"> {
    bits<5> rs2;
    let Inst{24-20} = rs2;
  }
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
multiclass VLoad_Indexed<bits<3> nf, bits<1> mew, bits<2> mop,
                         bits<3> width, string opcodestr> {
  def _m  : RVInstVLoad<nf, mew, mop, width, RVV_Masked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, VR:$vs2, Zero:$zero, VMR:$vm),
                  opcodestr, "$vd, ${zero}(${rs1}), $vs2, $vm"> {
    bits<5> vs2;
    let Inst{24-20} = vs2;
  }
  def _um : RVInstVLoad<nf, mew, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, VR:$vs2, Zero:$zero),
                  opcodestr, "$vd, ${zero}(${rs1}), $vs2"> {
    bits<5> vs2;
    let Inst{24-20} = vs2;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
multiclass VStore_Indexed<bits<3> nf, bits<1> mew, bits<2> mop,
                          bits<3> width, string opcodestr> {
  def _m  : RVInstVStore<nf, mew, mop, width, RVV_Masked, OPC_STORE_FP,
                   (outs), (ins VR:$vs3, GPR:$rs1, VR:$vs2, Zero:$zero, VMR:$vm),
                   opcodestr, "$vs3, ${zero}(${rs1}), $vs2, $vm"> {
    bits<5> vs2;
    let Inst{24-20} = vs2;
  }
  def _um : RVInstVStore<nf, mew, mop, width, RVV_Unmasked, OPC_STORE_FP,
                   (outs), (ins VR:$vs3, GPR:$rs1, VR:$vs2, Zero:$zero),
                   opcodestr, "$vs3, ${zero}(${rs1}), $vs2"> {
    bits<5> vs2;
    let Inst{24-20} = vs2;
  }
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
class VLoad_WholeReg<bits<3> nf, string opcodestr>
    : RVInstVLoadNoMew<nf, 0b000, 0b000, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, Zero:$zero),
                  opcodestr, "$vd, ${zero}(${rs1})"> {
  let Inst{24-20} = 0b01000;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
class VStore_WholeReg<bits<3> nf, string opcodestr>
    : RVInstVStoreNoMew<nf, 0b000, 0b000, RVV_Unmasked, OPC_STORE_FP,
                   (outs), (ins VR:$vs3, GPR:$rs1, Zero:$zero),
                   opcodestr, "$vs3, ${zero}(${rs1})"> {
  let Inst{24-20} = 0b01000;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_AMO<bits<5> amoop, bits<3> width, string opcodestr> {
  def _wd_m  : RVInstVAMO<amoop, 0b1, width, RVV_Masked, OPC_AMO,
               (outs VR:$vd_wd),
               (ins GPR:$rs1, VR:$vs2, VR:$vd, Zero:$zero, VMR:$vm),
               opcodestr, "$vd_wd, ${zero}(${rs1}), $vs2, $vd, $vm"> {
    let Constraints = "$vd = $vd_wd";
    bits<5> vd;
    let Inst{11-7}  = vd;
  }
  def _wd_um : RVInstVAMO<amoop, 0b1, width, RVV_Unmasked, OPC_AMO,
               (outs VR:$vd_wd),
               (ins GPR:$rs1, VR:$vs2, VR:$vd, Zero:$zero),
               opcodestr, "$vd_wd, ${zero}(${rs1}), $vs2, $vd"> {
    let Constraints = "$vd = $vd_wd";
    bits<5> vd;
    let Inst{11-7}  = vd;
  }
  def _m  : RVInstVAMO<amoop, 0b0, width, RVV_Masked, OPC_AMO,
               (outs),
               (ins GPR:$rs1, VR:$vs2, VR:$vs3, Zero:$zero, VMR:$vm),
               opcodestr, "x0, ${zero}(${rs1}), $vs2, $vs3, $vm"> {
    bits<5> vs3;
    let Inst{11-7}  = vs3;
  }
  def _um : RVInstVAMO<amoop, 0b0, width, RVV_Unmasked, OPC_AMO,
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
multiclass VALU_OPMVV_VXUNARY0<bits<5> vs1, string opcodestr> {
  def _m : RVInstVA<0b010010, 0b000, RVV_Masked, OPC_OP_V,
              (outs VR:$vd), (ins VR:$vs2, VMR:$vm),
              opcodestr, "$vd, $vs2, $vm"> {
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<0b010010, 0b000, RVV_Unmasked, OPC_OP_V,
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
               (outs VR:$vd), (ins VR:$vd_in, FPR32:$rs1, VR:$vs2, VMR:$vm),
               opcodestr, "$vd, $rs1, $vs2, $vm"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
    let Constraints = "$vd = $vd_in";
  }
  def _um : RVInstVA<funct6, 0b101, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vd_in, FPR32:$rs1, VR:$vs2),
               opcodestr, "$vd, $rs1, $vs2"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
    let Constraints = "$vd = $vd_in";
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

let hasSideEffects = 1, mayLoad = 0, mayStore = 0 in
def VSETVLI: RVInstVSet<0b0, OPC_OP_V, 
                      (outs GPR:$rd),
                      (ins GPR:$rs1, vtypei:$vtyi),
                      "vsetvli", "$rd, $rs1, $vtyi">, Sched<[]> {
  bits<11> vtyi;
  let Inst{30-20} = vtyi;
}
let hasSideEffects = 1, mayLoad = 0, mayStore = 0 in
def VSETVL: RVInstVSet<0b1, OPC_OP_V, 
                      (outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
                      "vsetvl", "$rd, $rs1, $rs2">, Sched<[]> {
  bits<5> rs2;
  let Inst{30-25} = 0b000000;
  let Inst{24-20} = rs2;
}


// Vector Unit-Stride Instructions

defm VLE8_V : VLoad_UnitStride<0b000, 0b0, 0b00, 0b000, "vle8.v">, Sched<[]>;
defm VLE16_V : VLoad_UnitStride<0b000, 0b0, 0b00, 0b101, "vle16.v">, Sched<[]>;
defm VLE32_V : VLoad_UnitStride<0b000, 0b0, 0b00, 0b110, "vle32.v">, Sched<[]>;
defm VLE64_V : VLoad_UnitStride<0b000, 0b0, 0b00, 0b111, "vle64.v">, Sched<[]>;
defm VLE128_V : VLoad_UnitStride<0b000, 0b1, 0b00, 0b000, "vle128.v">, Sched<[]>;
defm VLE256_V : VLoad_UnitStride<0b000, 0b1, 0b00, 0b101, "vle256.v">, Sched<[]>;
defm VLE512_V : VLoad_UnitStride<0b000, 0b1, 0b00, 0b110, "vle512.v">, Sched<[]>;
defm VLE1024_V : VLoad_UnitStride<0b000, 0b1, 0b00, 0b111, "vle1024.v">, Sched<[]>;

defm VSE8_V : VStore_UnitStride<0b000, 0b0, 0b00, 0b000, "vse8.v">, Sched<[]>;
defm VSE16_V : VStore_UnitStride<0b000, 0b0, 0b00, 0b101, "vse16.v">, Sched<[]>;
defm VSE32_V : VStore_UnitStride<0b000, 0b0, 0b00, 0b110, "vse32.v">, Sched<[]>;
defm VSE64_V : VStore_UnitStride<0b000, 0b0, 0b00, 0b111, "vse64.v">, Sched<[]>;
defm VSE128_V : VStore_UnitStride<0b000, 0b1, 0b00, 0b000, "vse128.v">, Sched<[]>;
defm VSE256_V : VStore_UnitStride<0b000, 0b1, 0b00, 0b101, "vse256.v">, Sched<[]>;
defm VSE512_V : VStore_UnitStride<0b000, 0b1, 0b00, 0b110, "vse512.v">, Sched<[]>;
defm VSE1024_V : VStore_UnitStride<0b000, 0b1, 0b00, 0b111, "vse1024.v">, Sched<[]>;


// Vector Strided Instructions

defm VLSE8_V : VLoad_Strided<0b000, 0b0, 0b10, 0b000, "vlse8.v">, Sched<[]>;
defm VLSE16_V : VLoad_Strided<0b000, 0b0, 0b10, 0b101, "vlse16.v">, Sched<[]>;
defm VLSE32_V : VLoad_Strided<0b000, 0b0, 0b10, 0b110, "vlse32.v">, Sched<[]>;
defm VLSE64_V : VLoad_Strided<0b000, 0b0, 0b10, 0b111, "vlse64.v">, Sched<[]>;
defm VLSE128_V : VLoad_Strided<0b000, 0b1, 0b10, 0b000, "vlse128.v">, Sched<[]>;
defm VLSE256_V : VLoad_Strided<0b000, 0b1, 0b10, 0b101, "vlse256.v">, Sched<[]>;
defm VLSE512_V : VLoad_Strided<0b000, 0b1, 0b10, 0b110, "vlse512.v">, Sched<[]>;
defm VLSE1024_V : VLoad_Strided<0b000, 0b1, 0b10, 0b111, "vlse1024.v">, Sched<[]>;

defm VSSE8_V : VStore_Strided<0b000, 0b0, 0b10, 0b000, "vsse8.v">, Sched<[]>;
defm VSSE16_V : VStore_Strided<0b000, 0b0, 0b10, 0b101, "vsse16.v">, Sched<[]>;
defm VSSE32_V : VStore_Strided<0b000, 0b0, 0b10, 0b110, "vsse32.v">, Sched<[]>;
defm VSSE64_V : VStore_Strided<0b000, 0b0, 0b10, 0b111, "vsse64.v">, Sched<[]>;
defm VSSE128_V : VStore_Strided<0b000, 0b1, 0b10, 0b000, "vsse128.v">, Sched<[]>;
defm VSSE256_V : VStore_Strided<0b000, 0b1, 0b10, 0b101, "vsse256.v">, Sched<[]>;
defm VSSE512_V : VStore_Strided<0b000, 0b1, 0b10, 0b110, "vsse512.v">, Sched<[]>;
defm VSSE1024_V : VStore_Strided<0b000, 0b1, 0b10, 0b111, "vsse1024.v">, Sched<[]>;


// Vector Indexed Instructions

defm VLXEI8_V : VLoad_Indexed<0b000, 0b0, 0b11, 0b000, "vlxei8.v">, Sched<[]>;
defm VLXEI16_V : VLoad_Indexed<0b000, 0b0, 0b11, 0b101, "vlxei16.v">, Sched<[]>;
defm VLXEI32_V : VLoad_Indexed<0b000, 0b0, 0b11, 0b110, "vlxei32.v">, Sched<[]>;
defm VLXEI64_V : VLoad_Indexed<0b000, 0b0, 0b11, 0b111, "vlxei64.v">, Sched<[]>;
defm VLXEI128_V : VLoad_Indexed<0b000, 0b1, 0b11, 0b000, "vlxei128.v">, Sched<[]>;
defm VLXEI256_V : VLoad_Indexed<0b000, 0b1, 0b11, 0b101, "vlxei256.v">, Sched<[]>;
defm VLXEI512_V : VLoad_Indexed<0b000, 0b1, 0b11, 0b110, "vlxei512.v">, Sched<[]>;
defm VLXEI1024_V : VLoad_Indexed<0b000, 0b1, 0b11, 0b111, "vlxei1024.v">, Sched<[]>;

defm VSXEI8_V : VStore_Indexed<0b000, 0b0, 0b11, 0b000, "vsxei8.v">, Sched<[]>;
defm VSXEI16_V : VStore_Indexed<0b000, 0b0, 0b11, 0b101, "vsxei16.v">, Sched<[]>;
defm VSXEI32_V : VStore_Indexed<0b000, 0b0, 0b11, 0b110, "vsxei32.v">, Sched<[]>;
defm VSXEI64_V : VStore_Indexed<0b000, 0b0, 0b11, 0b111, "vsxei64.v">, Sched<[]>;
defm VSXEI128_V : VStore_Indexed<0b000, 0b1, 0b11, 0b000, "vsxei128.v">, Sched<[]>;
defm VSXEI256_V : VStore_Indexed<0b000, 0b1, 0b11, 0b101, "vsxei256.v">, Sched<[]>;
defm VSXEI512_V : VStore_Indexed<0b000, 0b1, 0b11, 0b110, "vsxei512.v">, Sched<[]>;
defm VSXEI1024_V : VStore_Indexed<0b000, 0b1, 0b11, 0b111, "vsxei1024.v">, Sched<[]>;

defm VSUXEI8_V : VStore_Indexed<0b000, 0b0, 0b01, 0b000, "vsuxei8.v">, Sched<[]>;
defm VSUXEI16_V : VStore_Indexed<0b000, 0b0, 0b01, 0b101, "vsuxei16.v">, Sched<[]>;
defm VSUXEI32_V : VStore_Indexed<0b000, 0b0, 0b01, 0b110, "vsuxei32.v">, Sched<[]>;
defm VSUXEI64_V : VStore_Indexed<0b000, 0b0, 0b01, 0b111, "vsuxei64.v">, Sched<[]>;
defm VSUXEI128_V : VStore_Indexed<0b000, 0b1, 0b01, 0b000, "vsuxei128.v">, Sched<[]>;
defm VSUXEI256_V : VStore_Indexed<0b000, 0b1, 0b01, 0b101, "vsuxei256.v">, Sched<[]>;
defm VSUXEI512_V : VStore_Indexed<0b000, 0b1, 0b01, 0b110, "vsuxei512.v">, Sched<[]>;
defm VSUXEI1024_V : VStore_Indexed<0b000, 0b1, 0b01, 0b111, "vsuxei1024.v">, Sched<[]>;

// Unit-stride Fault-Only-First Loads Instructions

defm VLE8FF_V : VLoad_UnitStrideFF<0b000, 0b0, 0b00, 0b000, "vle8ff.v">, Sched<[]>;
defm VLE16FF_V : VLoad_UnitStrideFF<0b000, 0b0, 0b00, 0b101, "vle16ff.v">, Sched<[]>;
defm VLE32FF_V : VLoad_UnitStrideFF<0b000, 0b0, 0b00, 0b110, "vle32ff.v">, Sched<[]>;
defm VLE64FF_V : VLoad_UnitStrideFF<0b000, 0b0, 0b00, 0b111, "vle64ff.v">, Sched<[]>;
defm VLE128FF_V : VLoad_UnitStrideFF<0b000, 0b1, 0b00, 0b000, "vle128ff.v">, Sched<[]>;
defm VLE256FF_V : VLoad_UnitStrideFF<0b000, 0b1, 0b00, 0b101, "vle256ff.v">, Sched<[]>;
defm VLE512FF_V : VLoad_UnitStrideFF<0b000, 0b1, 0b00, 0b110, "vle512ff.v">, Sched<[]>;
defm VLE1024FF_V : VLoad_UnitStrideFF<0b000, 0b1, 0b00, 0b111, "vle1024ff.v">, Sched<[]>;


// Vector Load/Store Segment Instructions

foreach nf = 2-8 in {

  // Vector Unit-Stride Segment Loads and Stores
  defm VLSEG#nf#E8_V : VLoad_UnitStride<!add(nf, -1), 0b0, 0b00,
                                       0b000, "vlseg"#nf#"e8.v">, Sched<[]>;
  defm VLSEG#nf#E16_V : VLoad_UnitStride<!add(nf, -1), 0b0, 0b00,
                                       0b101, "vlseg"#nf#"e16.v">, Sched<[]>;
  defm VLSEG#nf#E32_V : VLoad_UnitStride<!add(nf, -1), 0b0, 0b00,
                                       0b110, "vlseg"#nf#"e32.v">, Sched<[]>;
  defm VLSEG#nf#E64_V : VLoad_UnitStride<!add(nf, -1), 0b0, 0b00,
                                       0b111, "vlseg"#nf#"e64.v">, Sched<[]>;
  defm VLSEG#nf#E128_V : VLoad_UnitStride<!add(nf, -1), 0b1, 0b00,
                                       0b000, "vlseg"#nf#"e128.v">, Sched<[]>;
  defm VLSEG#nf#E256_V : VLoad_UnitStride<!add(nf, -1), 0b1, 0b00,
                                       0b101, "vlseg"#nf#"e256.v">, Sched<[]>;
  defm VLSEG#nf#E512_V : VLoad_UnitStride<!add(nf, -1), 0b1, 0b00,
                                       0b110, "vlseg"#nf#"e512.v">, Sched<[]>;
  defm VLSEG#nf#E1024_V : VLoad_UnitStride<!add(nf, -1), 0b1, 0b00,
                                       0b111, "vlseg"#nf#"e1024.v">, Sched<[]>;
                    
  defm VSSEG#nf#E8_V : VStore_UnitStride<!add(nf, -1), 0b0, 0b00,
                                       0b000, "vsseg"#nf#"e8.v">, Sched<[]>;
  defm VSSEG#nf#E16_V : VStore_UnitStride<!add(nf, -1), 0b0, 0b00,
                                       0b101, "vsseg"#nf#"e16.v">, Sched<[]>;
  defm VSSEG#nf#E32_V : VStore_UnitStride<!add(nf, -1), 0b0, 0b00,
                                       0b110, "vsseg"#nf#"e32.v">, Sched<[]>;
  defm VSSEG#nf#E64_V : VStore_UnitStride<!add(nf, -1), 0b0, 0b00,
                                       0b111, "vsseg"#nf#"e64.v">, Sched<[]>;
  defm VSSEG#nf#E128_V : VStore_UnitStride<!add(nf, -1), 0b1, 0b00,
                                       0b000, "vsseg"#nf#"e128.v">, Sched<[]>;
  defm VSSEG#nf#E256_V : VStore_UnitStride<!add(nf, -1), 0b1, 0b00,
                                       0b101, "vsseg"#nf#"e256.v">, Sched<[]>;
  defm VSSEG#nf#E512_V : VStore_UnitStride<!add(nf, -1), 0b1, 0b00,
                                       0b110, "vsseg"#nf#"e512.v">, Sched<[]>;
  defm VSSEG#nf#E1024_V : VStore_UnitStride<!add(nf, -1), 0b1, 0b00,
                                       0b111, "vsseg"#nf#"e1024.v">, Sched<[]>;

  // Vector Strided Segment Loads and Stores
  defm VLSSEG#nf#E8_V : VLoad_Strided<!add(nf, -1), 0b0, 0b10,
                                       0b000, "vlsseg"#nf#"e8.v">, Sched<[]>;
  defm VLSSEG#nf#E16_V : VLoad_Strided<!add(nf, -1), 0b0, 0b10,
                                       0b101, "vlsseg"#nf#"e16.v">, Sched<[]>;
  defm VLSSEG#nf#E32_V : VLoad_Strided<!add(nf, -1), 0b0, 0b10,
                                       0b110, "vlsseg"#nf#"e32.v">, Sched<[]>;
  defm VLSSEG#nf#E64_V : VLoad_Strided<!add(nf, -1), 0b0, 0b10,
                                       0b111, "vlsseg"#nf#"e64.v">, Sched<[]>;
  defm VLSSEG#nf#E128_V : VLoad_Strided<!add(nf, -1), 0b1, 0b10,
                                       0b000, "vlsseg"#nf#"e128.v">, Sched<[]>;
  defm VLSSEG#nf#E256_V : VLoad_Strided<!add(nf, -1), 0b1, 0b10,
                                       0b101, "vlsseg"#nf#"e256.v">, Sched<[]>;
  defm VLSSEG#nf#E512_V : VLoad_Strided<!add(nf, -1), 0b1, 0b10,
                                       0b110, "vlsseg"#nf#"e512.v">, Sched<[]>;
  defm VLSSEG#nf#E1024_V : VLoad_Strided<!add(nf, -1), 0b1, 0b10,
                                       0b111, "vlsseg"#nf#"e1024.v">, Sched<[]>;

  defm VSSSEG#nf#E8_V : VStore_Strided<!add(nf, -1), 0b0, 0b10,
                                       0b000, "vssseg"#nf#"e8.v">, Sched<[]>;
  defm VSSSEG#nf#E16_V : VStore_Strided<!add(nf, -1), 0b0, 0b10,
                                       0b101, "vssseg"#nf#"e16.v">, Sched<[]>;
  defm VSSSEG#nf#E32_V : VStore_Strided<!add(nf, -1), 0b0, 0b10,
                                       0b110, "vssseg"#nf#"e32.v">, Sched<[]>;
  defm VSSSEG#nf#E64_V : VStore_Strided<!add(nf, -1), 0b0, 0b10,
                                       0b111, "vssseg"#nf#"e64.v">, Sched<[]>;
  defm VSSSEG#nf#E128_V : VStore_Strided<!add(nf, -1), 0b1, 0b10,
                                       0b000, "vssseg"#nf#"e128.v">, Sched<[]>;
  defm VSSSEG#nf#E256_V : VStore_Strided<!add(nf, -1), 0b1, 0b10,
                                       0b101, "vssseg"#nf#"e256.v">, Sched<[]>;
  defm VSSSEG#nf#E512_V : VStore_Strided<!add(nf, -1), 0b1, 0b10,
                                       0b110, "vssseg"#nf#"e512.v">, Sched<[]>;
  defm VSSSEG#nf#E1024_V : VStore_Strided<!add(nf, -1), 0b1, 0b10,
                                       0b111, "vssseg"#nf#"e1024.v">, Sched<[]>;

  // Vector Indexed Segment Loads and Stores
  defm VLXSEG#nf#EI8_V : VLoad_Indexed<!add(nf, -1), 0b0, 0b11,
                                       0b000, "vlxseg"#nf#"ei8.v">, Sched<[]>;
  defm VLXSEG#nf#EI16_V : VLoad_Indexed<!add(nf, -1), 0b0, 0b11,
                                       0b101, "vlxseg"#nf#"ei16.v">, Sched<[]>;
  defm VLXSEG#nf#EI32_V : VLoad_Indexed<!add(nf, -1), 0b0, 0b11,
                                       0b110, "vlxseg"#nf#"ei32.v">, Sched<[]>;
  defm VLXSEG#nf#EI64_V : VLoad_Indexed<!add(nf, -1), 0b0, 0b11,
                                       0b111, "vlxseg"#nf#"ei64.v">, Sched<[]>;
  defm VLXSEG#nf#EI128_V : VLoad_Indexed<!add(nf, -1), 0b1, 0b11,
                                       0b000, "vlxseg"#nf#"ei128.v">, Sched<[]>;
  defm VLXSEG#nf#EI256_V : VLoad_Indexed<!add(nf, -1), 0b1, 0b11,
                                       0b101, "vlxseg"#nf#"ei256.v">, Sched<[]>;
  defm VLXSEG#nf#EI512_V : VLoad_Indexed<!add(nf, -1), 0b1, 0b11,
                                       0b110, "vlxseg"#nf#"ei512.v">, Sched<[]>;
  defm VLXSEG#nf#EI1024_V : VLoad_Indexed<!add(nf, -1), 0b1, 0b11,
                                       0b111, "vlxseg"#nf#"ei1024.v">, Sched<[]>;

  defm VSXSEG#nf#EI8_V : VStore_Indexed<!add(nf, -1), 0b0, 0b11,
                                       0b000, "vsxseg"#nf#"ei8.v">, Sched<[]>;
  defm VSXSEG#nf#EI16_V : VStore_Indexed<!add(nf, -1), 0b0, 0b11,
                                       0b101, "vsxseg"#nf#"ei16.v">, Sched<[]>;
  defm VSXSEG#nf#EI32_V : VStore_Indexed<!add(nf, -1), 0b0, 0b11,
                                       0b110, "vsxseg"#nf#"ei32.v">, Sched<[]>;
  defm VSXSEG#nf#EI64_V : VStore_Indexed<!add(nf, -1), 0b0, 0b11,
                                       0b111, "vsxseg"#nf#"ei64.v">, Sched<[]>;
  defm VSXSEG#nf#EI128_V : VStore_Indexed<!add(nf, -1), 0b1, 0b11,
                                       0b000, "vsxseg"#nf#"ei128.v">, Sched<[]>;
  defm VSXSEG#nf#EI256_V : VStore_Indexed<!add(nf, -1), 0b1, 0b11,
                                       0b101, "vsxseg"#nf#"ei256.v">, Sched<[]>;
  defm VSXSEG#nf#EI512_V : VStore_Indexed<!add(nf, -1), 0b1, 0b11,
                                       0b110, "vsxseg"#nf#"ei512.v">, Sched<[]>;
  defm VSXSEG#nf#EI1024_V : VStore_Indexed<!add(nf, -1), 0b1, 0b11,
                                       0b111, "vsxseg"#nf#"ei1024.v">, Sched<[]>;

  // Vector Unit-Stride Fault-Only-First Segment Loads
  defm VLSEG#nf#E8FF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b0, 0b00,
                                       0b000, "vlseg"#nf#"e8ff.v">, Sched<[]>;
  defm VLSEG#nf#E16FF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b0, 0b00,
                                       0b101, "vlseg"#nf#"e16ff.v">, Sched<[]>;
  defm VLSEG#nf#E32FF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b0, 0b00,
                                       0b110, "vlseg"#nf#"e32ff.v">, Sched<[]>;
  defm VLSEG#nf#E64FF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b0, 0b00,
                                       0b111, "vlseg"#nf#"e64ff.v">, Sched<[]>;
  defm VLSEG#nf#E128FF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b1, 0b00,
                                       0b000, "vlseg"#nf#"e128ff.v">, Sched<[]>;
  defm VLSEG#nf#E256FF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b1, 0b00,
                                       0b101, "vlseg"#nf#"e256ff.v">, Sched<[]>;
  defm VLSEG#nf#E512FF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b1, 0b00,
                                       0b110, "vlseg"#nf#"e512ff.v">, Sched<[]>;
  defm VLSEG#nf#E1024FF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b1, 0b00,
                                       0b111, "vlseg"#nf#"e1024ff.v">, Sched<[]>;
}


// Vector Load/Store Whole Register Instructions

foreach nf = 1-8 in {
  def VL#nf#R_V : VLoad_WholeReg<!add(nf, -1), "vl"#nf#"r.v">, Sched<[]>;
  def VS#nf#R_V : VStore_WholeReg<!add(nf, -1), "vs"#nf#"r.v">, Sched<[]>;
}


// Vector AMO Operations

defm VAMOSWAPEI8_V : VALU_AMO<0b00001, 0b000, "vamoswapei8.v">, Sched<[]>;
defm VAMOADDEI8_V : VALU_AMO<0b00000, 0b000, "vamoaddei8.v">, Sched<[]>;
defm VAMOXOREI8_V : VALU_AMO<0b00100, 0b000, "vamoxorei8.v">, Sched<[]>;
defm VAMOANDEI8_V : VALU_AMO<0b01100, 0b000, "vamoandei8.v">, Sched<[]>;
defm VAMOOREI8_V : VALU_AMO<0b01000, 0b000, "vamoorei8.v">, Sched<[]>;
defm VAMOMINEI8_V : VALU_AMO<0b10000, 0b000, "vamominei8.v">, Sched<[]>;
defm VAMOMAXEI8_V : VALU_AMO<0b10100, 0b000, "vamomaxei8.v">, Sched<[]>;
defm VAMOMINUEI8_V : VALU_AMO<0b11000, 0b000, "vamominuei8.v">, Sched<[]>;
defm VAMOMAXUEI8_V : VALU_AMO<0b11100, 0b000, "vamomaxuei8.v">, Sched<[]>;

defm VAMOSWAPEI16_V : VALU_AMO<0b00001, 0b101, "vamoswapei16.v">, Sched<[]>;
defm VAMOADDEI16_V : VALU_AMO<0b00000, 0b101, "vamoaddei16.v">, Sched<[]>;
defm VAMOXOREI16_V : VALU_AMO<0b00100, 0b101, "vamoxorei16.v">, Sched<[]>;
defm VAMOANDEI16_V : VALU_AMO<0b01100, 0b101, "vamoandei16.v">, Sched<[]>;
defm VAMOOREI16_V : VALU_AMO<0b01000, 0b101, "vamoorei16.v">, Sched<[]>;
defm VAMOMINEI16_V : VALU_AMO<0b10000, 0b101, "vamominei16.v">, Sched<[]>;
defm VAMOMAXEI16_V : VALU_AMO<0b10100, 0b101, "vamomaxei16.v">, Sched<[]>;
defm VAMOMINUEI16_V : VALU_AMO<0b11000, 0b101, "vamominuei16.v">, Sched<[]>;
defm VAMOMAXUEI16_V : VALU_AMO<0b11100, 0b101, "vamomaxuei16.v">, Sched<[]>;

defm VAMOSWAPEI32_V : VALU_AMO<0b00001, 0b110, "vamoswapei32.v">, Sched<[]>;
defm VAMOADDEI32_V : VALU_AMO<0b00000, 0b110, "vamoaddei32.v">, Sched<[]>;
defm VAMOXOREI32_V : VALU_AMO<0b00100, 0b110, "vamoxorei32.v">, Sched<[]>;
defm VAMOANDEI32_V : VALU_AMO<0b01100, 0b110, "vamoandei32.v">, Sched<[]>;
defm VAMOOREI32_V : VALU_AMO<0b01000, 0b110, "vamoorei32.v">, Sched<[]>;
defm VAMOMINEI32_V : VALU_AMO<0b10000, 0b110, "vamominei32.v">, Sched<[]>;
defm VAMOMAXEI32_V : VALU_AMO<0b10100, 0b110, "vamomaxei32.v">, Sched<[]>;
defm VAMOMINUEI32_V : VALU_AMO<0b11000, 0b110, "vamominuei32.v">, Sched<[]>;
defm VAMOMAXUEI32_V : VALU_AMO<0b11100, 0b110, "vamomaxuei32.v">, Sched<[]>;

defm VAMOSWAPEI64_V : VALU_AMO<0b00001, 0b111, "vamoswapei64.v">, Sched<[]>;
defm VAMOADDEI64_V : VALU_AMO<0b00000, 0b111, "vamoaddei64.v">, Sched<[]>;
defm VAMOXOREI64_V : VALU_AMO<0b00100, 0b111, "vamoxorei64.v">, Sched<[]>;
defm VAMOANDEI64_V : VALU_AMO<0b01100, 0b111, "vamoandei64.v">, Sched<[]>;
defm VAMOOREI64_V : VALU_AMO<0b01000, 0b111, "vamoorei64.v">, Sched<[]>;
defm VAMOMINEI64_V : VALU_AMO<0b10000, 0b111, "vamominei64.v">, Sched<[]>;
defm VAMOMAXEI64_V : VALU_AMO<0b10100, 0b111, "vamomaxei64.v">, Sched<[]>;
defm VAMOMINUEI64_V : VALU_AMO<0b11000, 0b111, "vamominuei64.v">, Sched<[]>;
defm VAMOMAXUEI64_V : VALU_AMO<0b11100, 0b111, "vamomaxuei64.v">, Sched<[]>;


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
defm VFCVT_RTZ_XU_F_V : VALU_OPFVV_VFUNARY0<0b00110, "vfcvt.rtz.xu.f.v">, Sched<[]>;
defm VFCVT_RTZ_X_F_V : VALU_OPFVV_VFUNARY0<0b00111, "vfcvt.rtz.x.f.v">, Sched<[]>;


// Widening Floating-Point/Integer Type-Convert Instructions

defm VFWCVT_XU_F_V : VALU_OPFVV_VFUNARY0<0b01000, "vfwcvt.xu.f.v">, Sched<[]>;
defm VFWCVT_X_F_V : VALU_OPFVV_VFUNARY0<0b01001, "vfwcvt.x.f.v">, Sched<[]>;
defm VFWCVT_F_XU_V : VALU_OPFVV_VFUNARY0<0b01010, "vfwcvt.f.xu.v">, Sched<[]>;
defm VFWCVT_F_X_V : VALU_OPFVV_VFUNARY0<0b01011, "vfwcvt.f.x.v">, Sched<[]>;
defm VFWCVT_F_F_V : VALU_OPFVV_VFUNARY0<0b01100, "vfwcvt.f.f.v">, Sched<[]>;
defm VFWCVT_RTZ_XU_F_V : VALU_OPFVV_VFUNARY0<0b01110, "vfwcvt.rtz.xu.f.v">, Sched<[]>;
defm VFWCVT_RTZ_X_F_V : VALU_OPFVV_VFUNARY0<0b01111, "vfwcvt.rtz.x.f.v">, Sched<[]>;


// Narrowing Floating-Point/Integer Type-Convert Instructions

defm VFNCVT_XU_F_W : VALU_OPFVV_VFUNARY0<0b10000, "vfncvt.xu.f.w">, Sched<[]>;
defm VFNCVT_X_F_W : VALU_OPFVV_VFUNARY0<0b10001, "vfncvt.x.f.w">, Sched<[]>;
defm VFNCVT_F_XU_W : VALU_OPFVV_VFUNARY0<0b10010, "vfncvt.f.xu.w">, Sched<[]>;
defm VFNCVT_F_X_W : VALU_OPFVV_VFUNARY0<0b10011, "vfncvt.f.x.w">, Sched<[]>;
defm VFNCVT_F_F_W : VALU_OPFVV_VFUNARY0<0b10100, "vfncvt.f.f.w">, Sched<[]>;
defm VFNCVT_ROD_F_F_W : VALU_OPFVV_VFUNARY0<0b10101, "vfncvt.rod.f.f.w">, Sched<[]>;
defm VFNCVT_RTZ_XU_F_W : VALU_OPFVV_VFUNARY0<0b10110, "vfncvt.rtz.xu.f.w">, Sched<[]>;
defm VFNCVT_RTZ_X_F_W : VALU_OPFVV_VFUNARY0<0b10111, "vfncvt.rtz.x.f.w">, Sched<[]>;


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

// Vector Integer Extension Instructions
defm VZEXT_VF8 : VALU_OPMVV_VXUNARY0<0b00010, "vzext.vf8">, Sched<[]>;
defm VSEXT_VF8 : VALU_OPMVV_VXUNARY0<0b00011, "vsext.vf8">, Sched<[]>;
defm VZEXT_VF4 : VALU_OPMVV_VXUNARY0<0b00100, "vzext.vf4">, Sched<[]>;
defm VSEXT_VF4 : VALU_OPMVV_VXUNARY0<0b00101, "vsext.vf4">, Sched<[]>;
defm VZEXT_VF2 : VALU_OPMVV_VXUNARY0<0b00110, "vzext.vf2">, Sched<[]>;
defm VSEXT_VF2 : VALU_OPMVV_VXUNARY0<0b00111, "vsext.vf2">, Sched<[]>;

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
defm VFSLIDE1UP_VF : VALU_OPFVF<0b001110, "vfslide1up.vf">, Sched<[]>;

defm VSLIDE1DOWN_VX : VALU_OPMVX<0b001111, "vslide1down.vx">, Sched<[]>;
defm VDSLIDE1DOWN_VF : VALU_OPFVF<0b001111, "vfslide1down.vf">, Sched<[]>;


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


def : InstAlias<"vle8.v $vd, (${rs1})",
                (VLE8_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle8.v $vd, (${rs1}), $vm",
                (VLE8_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vle16.v $vd, (${rs1})",
                (VLE16_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle16.v $vd, (${rs1}), $vm",
                (VLE16_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vle32.v $vd, (${rs1})",
                (VLE32_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle32.v $vd, (${rs1}), $vm",
                (VLE32_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vle64.v $vd, (${rs1})",
                (VLE64_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle64.v $vd, (${rs1}), $vm",
                (VLE64_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vle128.v $vd, (${rs1})",
                (VLE128_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle128.v $vd, (${rs1}), $vm",
                (VLE128_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vle256.v $vd, (${rs1})",
                (VLE256_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle256.v $vd, (${rs1}), $vm",
                (VLE256_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vle512.v $vd, (${rs1})",
                (VLE512_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle512.v $vd, (${rs1}), $vm",
                (VLE512_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vle1024.v $vd, (${rs1})",
                (VLE1024_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle1024.v $vd, (${rs1}), $vm",
                (VLE1024_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;

// def : InstAlias<"vfmacc.vf $vd, $rs1, $vs2",
//                 (VFMACC_VF_um VR:$vd, FPR32:$rs1, VR:$vs2)>;

def : InstAlias<"vse8.v $vs3, (${rs1})",
                (VSE8_V_um  VR:$vs3, GPR:$rs1, 0)>;
def : InstAlias<"vse8.v $vs3, (${rs1}), $vm",
                (VSE8_V_m  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vse16.v $vs3, (${rs1})",
                (VSE16_V_um  VR:$vs3, GPR:$rs1, 0)>;
def : InstAlias<"vse16.v $vs3, (${rs1}), $vm",
                (VSE16_V_m  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vse32.v $vs3, (${rs1})",
                (VSE32_V_um  VR:$vs3, GPR:$rs1, 0)>;
def : InstAlias<"vse32.v $vs3, (${rs1}), $vm",
                (VSE32_V_m  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vse64.v $vs3, (${rs1})",
                (VSE64_V_um  VR:$vs3, GPR:$rs1, 0)>;
def : InstAlias<"vse64.v $vs3, (${rs1}), $vm",
                (VSE64_V_m  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vse128.v $vs3, (${rs1})",
                (VSE128_V_um  VR:$vs3, GPR:$rs1, 0)>;
def : InstAlias<"vse128.v $vs3, (${rs1}), $vm",
                (VSE128_V_m  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vse256.v $vs3, (${rs1})",
                (VSE256_V_um  VR:$vs3, GPR:$rs1, 0)>;
def : InstAlias<"vse256.v $vs3, (${rs1}), $vm",
                (VSE256_V_m  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vse512.v $vs3, (${rs1})",
                (VSE512_V_um  VR:$vs3, GPR:$rs1, 0)>;
def : InstAlias<"vse512.v $vs3, (${rs1}), $vm",
                (VSE512_V_m  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vse1024.v $vs3, (${rs1})",
                (VSE1024_V_um  VR:$vs3, GPR:$rs1, 0)>;
def : InstAlias<"vse1024.v $vs3, (${rs1}), $vm",
                (VSE1024_V_m  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
              

// def : InstAlias<"vse.v $vs3, (${rs1})",
//                 (VSE_V_um  VR:$vs3, GPR:$rs1, 0)>;
// def : InstAlias<"vse.v $vs3, (${rs1}), $vm",
//                 (VSE_V_m  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;


def : InstAlias<"vlse8.v $vd, (${rs1}), $rs2",
                (VLSE8_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vlse8.v $vd, (${rs1}), $rs2, $vm",
                (VLSE8_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vlse16.v $vd, (${rs1}), $rs2",
                (VLSE16_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vlse16.v $vd, (${rs1}), $rs2, $vm",
                (VLSE16_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vlse32.v $vd, (${rs1}), $rs2",
                (VLSE32_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vlse32.v $vd, (${rs1}), $rs2, $vm",
                (VLSE32_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vlse64.v $vd, (${rs1}), $rs2",
                (VLSE64_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vlse64.v $vd, (${rs1}), $rs2, $vm",
                (VLSE64_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vlse128.v $vd, (${rs1}), $rs2",
                (VLSE128_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vlse128.v $vd, (${rs1}), $rs2, $vm",
                (VLSE128_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vlse256.v $vd, (${rs1}), $rs2",
                (VLSE256_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vlse256.v $vd, (${rs1}), $rs2, $vm",
                (VLSE256_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vlse512.v $vd, (${rs1}), $rs2",
                (VLSE512_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vlse512.v $vd, (${rs1}), $rs2, $vm",
                (VLSE512_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vlse1024.v $vd, (${rs1}), $rs2",
                (VLSE1024_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vlse1024.v $vd, (${rs1}), $rs2, $vm",
                (VLSE1024_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;


def : InstAlias<"vsse8.v $vs3, (${rs1}), $rs2",
                (VSSE8_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vsse8.v $vs3, (${rs1}), $rs2, $vm",
                (VSSE8_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vsse16.v $vs3, (${rs1}), $rs2",
                (VSSE16_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vsse16.v $vs3, (${rs1}), $rs2, $vm",
                (VSSE16_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vsse32.v $vs3, (${rs1}), $rs2",
                (VSSE32_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vsse32.v $vs3, (${rs1}), $rs2, $vm",
                (VSSE32_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vsse64.v $vs3, (${rs1}), $rs2",
                (VSSE64_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vsse64.v $vs3, (${rs1}), $rs2, $vm",
                (VSSE64_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vsse128.v $vs3, (${rs1}), $rs2",
                (VSSE128_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vsse128.v $vs3, (${rs1}), $rs2, $vm",
                (VSSE128_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vsse256.v $vs3, (${rs1}), $rs2",
                (VSSE256_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vsse256.v $vs3, (${rs1}), $rs2, $vm",
                (VSSE256_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vsse512.v $vs3, (${rs1}), $rs2",
                (VSSE512_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vsse512.v $vs3, (${rs1}), $rs2, $vm",
                (VSSE512_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
def : InstAlias<"vsse1024.v $vs3, (${rs1}), $rs2",
                (VSSE1024_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
def : InstAlias<"vsse1024.v $vs3, (${rs1}), $rs2, $vm",
                (VSSE1024_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;

def : InstAlias<"vlxei8.v $vd, (${rs1}), $vs2",
                (VLXEI8_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vlxei8.v $vd, (${rs1}), $vs2, $vm",
                (VLXEI8_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vlxei16.v $vd, (${rs1}), $vs2",
                (VLXEI16_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vlxei16.v $vd, (${rs1}), $vs2, $vm",
                (VLXEI16_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vlxei32.v $vd, (${rs1}), $vs2",
                (VLXEI32_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vlxei32.v $vd, (${rs1}), $vs2, $vm",
                (VLXEI32_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vlxei64.v $vd, (${rs1}), $vs2",
                (VLXEI64_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vlxei64.v $vd, (${rs1}), $vs2, $vm",
                (VLXEI64_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vlxei128.v $vd, (${rs1}), $vs2",
                (VLXEI128_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vlxei128.v $vd, (${rs1}), $vs2, $vm",
                (VLXEI128_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vlxei256.v $vd, (${rs1}), $vs2",
                (VLXEI256_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vlxei256.v $vd, (${rs1}), $vs2, $vm",
                (VLXEI256_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vlxei512.v $vd, (${rs1}), $vs2",
                (VLXEI512_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vlxei512.v $vd, (${rs1}), $vs2, $vm",
                (VLXEI512_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vlxei1024.v $vd, (${rs1}), $vs2",
                (VLXEI1024_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vlxei1024.v $vd, (${rs1}), $vs2, $vm",
                (VLXEI1024_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;

// def : InstAlias<"vlxbu.v $vd, (${rs1}), $vs2",
//                 (VLXBU_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
// def : InstAlias<"vlxbu.v $vd, (${rs1}), $vs2, $vm",
//                 (VLXBU_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
// def : InstAlias<"vlxhu.v $vd, (${rs1}), $vs2",
//                 (VLXHU_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
// def : InstAlias<"vlxhu.v $vd, (${rs1}), $vs2, $vm",
//                 (VLXHU_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
// def : InstAlias<"vlxwu.v $vd, (${rs1}), $vs2",
//                 (VLXWU_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
// def : InstAlias<"vlxwu.v $vd, (${rs1}), $vs2, $vm",
//                 (VLXWU_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
// def : InstAlias<"vlxe.v $vd, (${rs1}), $vs2",
//                 (VLXE_V_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
// def : InstAlias<"vlxe.v $vd, (${rs1}), $vs2, $vm",
//                 (VLXE_V_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;

def : InstAlias<"vsxei8.v $vs3, (${rs1}), $vs2",
                (VSXEI8_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsxei8.v $vs3, (${rs1}), $vs2, $vm",
                (VSXEI8_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsxei16.v $vs3, (${rs1}), $vs2",
                (VSXEI16_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsxei16.v $vs3, (${rs1}), $vs2, $vm",
                (VSXEI16_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsxei32.v $vs3, (${rs1}), $vs2",
                (VSXEI32_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsxei32.v $vs3, (${rs1}), $vs2, $vm",
                (VSXEI32_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsxei64.v $vs3, (${rs1}), $vs2",
                (VSXEI64_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsxei64.v $vs3, (${rs1}), $vs2, $vm",
                (VSXEI64_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsxei128.v $vs3, (${rs1}), $vs2",
                (VSXEI128_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsxei128.v $vs3, (${rs1}), $vs2, $vm",
                (VSXEI128_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsxei256.v $vs3, (${rs1}), $vs2",
                (VSXEI256_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsxei256.v $vs3, (${rs1}), $vs2, $vm",
                (VSXEI256_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsxei512.v $vs3, (${rs1}), $vs2",
                (VSXEI512_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsxei512.v $vs3, (${rs1}), $vs2, $vm",
                (VSXEI512_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsxei1024.v $vs3, (${rs1}), $vs2",
                (VSXEI1024_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsxei1024.v $vs3, (${rs1}), $vs2, $vm",
                (VSXEI1024_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;


def : InstAlias<"vsuxei8.v $vs3, (${rs1}), $vs2",
                (VSUXEI8_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsuxei8.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXEI8_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsuxei16.v $vs3, (${rs1}), $vs2",
                (VSUXEI16_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsuxei16.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXEI16_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsuxei32.v $vs3, (${rs1}), $vs2",
                (VSUXEI32_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsuxei32.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXEI32_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsuxei64.v $vs3, (${rs1}), $vs2",
                (VSUXEI64_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsuxei64.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXEI64_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsuxei128.v $vs3, (${rs1}), $vs2",
                (VSUXEI128_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsuxei128.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXEI128_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsuxei256.v $vs3, (${rs1}), $vs2",
                (VSUXEI256_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsuxei256.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXEI256_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsuxei512.v $vs3, (${rs1}), $vs2",
                (VSUXEI512_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsuxei512.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXEI512_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vsuxei1024.v $vs3, (${rs1}), $vs2",
                (VSUXEI1024_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vsuxei1024.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXEI1024_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;


def : InstAlias<"vle8ff.v $vd, (${rs1})",
                (VLE8FF_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle8ff.v $vd, (${rs1}), $vm",
                (VLE8FF_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vle16ff.v $vd, (${rs1})",
                (VLE16FF_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle16ff.v $vd, (${rs1}), $vm",
                (VLE16FF_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vle32ff.v $vd, (${rs1})",
                (VLE32FF_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle32ff.v $vd, (${rs1}), $vm",
                (VLE32FF_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vle64ff.v $vd, (${rs1})",
                (VLE64FF_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle64ff.v $vd, (${rs1}), $vm",
                (VLE64FF_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vle128ff.v $vd, (${rs1})",
                (VLE128FF_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle128ff.v $vd, (${rs1}), $vm",
                (VLE128FF_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vle256ff.v $vd, (${rs1})",
                (VLE256FF_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle256ff.v $vd, (${rs1}), $vm",
                (VLE256FF_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vle512ff.v $vd, (${rs1})",
                (VLE512FF_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle512ff.v $vd, (${rs1}), $vm",
                (VLE512FF_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
def : InstAlias<"vle1024ff.v $vd, (${rs1})",
                (VLE1024FF_V_um  VR:$vd, GPR:$rs1, 0)>;
def : InstAlias<"vle1024ff.v $vd, (${rs1}), $vm",
                (VLE1024FF_V_m  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;

foreach nf = 2-8 in {

  def : InstAlias<"vlseg"#nf#"e8.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E8_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e8.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E8_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e16.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E16_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e16.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E16_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e32.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E32_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e32.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E32_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e64.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E64_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e64.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E64_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e128.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E128_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e128.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E128_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e256.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E256_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e256.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E256_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e512.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E512_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e512.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E512_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e1024.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E1024_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e1024.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E1024_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;

  def : InstAlias<"vsseg"#nf#"e8.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E8_V_um")
                  VR:$vs3, GPR:$rs1, 0)>;
  def : InstAlias<"vsseg"#nf#"e8.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E8_V_m")
                  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vsseg"#nf#"e16.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E16_V_um")
                  VR:$vs3, GPR:$rs1, 0)>;
  def : InstAlias<"vsseg"#nf#"e16.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E16_V_m")
                  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vsseg"#nf#"e32.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E32_V_um")
                  VR:$vs3, GPR:$rs1, 0)>;
  def : InstAlias<"vsseg"#nf#"e32.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E32_V_m")
                  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vsseg"#nf#"e64.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E64_V_um")
                  VR:$vs3, GPR:$rs1, 0)>;
  def : InstAlias<"vsseg"#nf#"e64.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E64_V_m")
                  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vsseg"#nf#"e128.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E128_V_um")
                  VR:$vs3, GPR:$rs1, 0)>;
  def : InstAlias<"vsseg"#nf#"e128.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E128_V_m")
                  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vsseg"#nf#"e256.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E256_V_um")
                  VR:$vs3, GPR:$rs1, 0)>;
  def : InstAlias<"vsseg"#nf#"e256.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E256_V_m")
                  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vsseg"#nf#"e512.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E512_V_um")
                  VR:$vs3, GPR:$rs1, 0)>;
  def : InstAlias<"vsseg"#nf#"e512.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E512_V_m")
                  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vsseg"#nf#"e1024.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E1024_V_um")
                  VR:$vs3, GPR:$rs1, 0)>;
  def : InstAlias<"vsseg"#nf#"e1024.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E1024_V_m")
                  VR:$vs3, GPR:$rs1, 0, VMR:$vm)>;


  def : InstAlias<"vlsseg"#nf#"e8.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E8_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vlsseg"#nf#"e8.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E8_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"e16.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E16_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vlsseg"#nf#"e16.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E16_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"e32.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E32_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vlsseg"#nf#"e32.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E32_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"e64.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E64_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vlsseg"#nf#"e64.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E64_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"e128.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E128_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vlsseg"#nf#"e128.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E128_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"e256.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E256_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vlsseg"#nf#"e256.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E256_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"e512.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E512_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vlsseg"#nf#"e512.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E512_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"e1024.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E1024_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vlsseg"#nf#"e1024.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E1024_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;

  def : InstAlias<"vssseg"#nf#"e8.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E8_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vssseg"#nf#"e8.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E8_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vssseg"#nf#"e16.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E16_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vssseg"#nf#"e16.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E16_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vssseg"#nf#"e32.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E32_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vssseg"#nf#"e32.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E32_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vssseg"#nf#"e64.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E64_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vssseg"#nf#"e64.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E64_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vssseg"#nf#"e128.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E128_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vssseg"#nf#"e128.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E128_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vssseg"#nf#"e256.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E256_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vssseg"#nf#"e256.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E256_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vssseg"#nf#"e512.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E512_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vssseg"#nf#"e512.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E512_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;
  def : InstAlias<"vssseg"#nf#"e1024.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E1024_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0)>;
  def : InstAlias<"vssseg"#nf#"e1024.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E1024_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, 0, VMR:$vm)>;


  def : InstAlias<"vlxseg"#nf#"ei8.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI8_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vlxseg"#nf#"ei8.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI8_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"ei16.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI16_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vlxseg"#nf#"ei16.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI16_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"ei32.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI32_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vlxseg"#nf#"ei32.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI32_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"ei64.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI64_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vlxseg"#nf#"ei64.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI64_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"ei128.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI128_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vlxseg"#nf#"ei128.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI128_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"ei256.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI256_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vlxseg"#nf#"ei256.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI256_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"ei512.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI512_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vlxseg"#nf#"ei512.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI512_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"ei1024.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI1024_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vlxseg"#nf#"ei1024.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"EI1024_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;

  def : InstAlias<"vsxseg"#nf#"ei8.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI8_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vsxseg"#nf#"ei8.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI8_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vsxseg"#nf#"ei16.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI16_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vsxseg"#nf#"ei16.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI16_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vsxseg"#nf#"ei32.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI32_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vsxseg"#nf#"ei32.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI32_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vsxseg"#nf#"ei64.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI64_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vsxseg"#nf#"ei64.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI64_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vsxseg"#nf#"ei128.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI128_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vsxseg"#nf#"ei128.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI128_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vsxseg"#nf#"ei256.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI256_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vsxseg"#nf#"ei256.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI256_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vsxseg"#nf#"ei512.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI512_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vsxseg"#nf#"ei512.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI512_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
  def : InstAlias<"vsxseg"#nf#"ei1024.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI1024_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0)>;
  def : InstAlias<"vsxseg"#nf#"ei1024.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"EI1024_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;

  def : InstAlias<"vlseg"#nf#"e8ff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E8FF_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e8ff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E8FF_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e16ff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E16FF_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e16ff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E16FF_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e32ff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E32FF_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e32ff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E32FF_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e64ff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E64FF_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e64ff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E64FF_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e128ff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E128FF_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e128ff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E128FF_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e256ff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E256FF_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e256ff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E256FF_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e512ff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E512FF_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e512ff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E512FF_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e1024ff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E1024FF_V_um")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vlseg"#nf#"e1024ff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E1024FF_V_m")
                  VR:$vd, GPR:$rs1, 0, VMR:$vm)>;
}


foreach nf = 1-8 in {

  def : InstAlias<"vl"#nf#"r.v $vd, (${rs1})",
                  (!cast<RVInstVLoadNoMew>("VL"#nf#"R_V")
                  VR:$vd, GPR:$rs1, 0)>;
  def : InstAlias<"vs"#nf#"r.v $vs3, (${rs1})",
                  (!cast<RVInstVStoreNoMew>("VS"#nf#"R_V")
                  VR:$vs3, GPR:$rs1, 0)>;
}


def : InstAlias<"vamoswapei8.v $vd, (${rs1}), $vs2, $vd",
                (VAMOSWAPEI8_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoswapei8.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOSWAPEI8_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoswapei8.v x0, (${rs1}), $vs2, $vd",
                (VAMOSWAPEI8_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoswapei8.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOSWAPEI8_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamoswapei16.v $vd, (${rs1}), $vs2, $vd",
                (VAMOSWAPEI16_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoswapei16.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOSWAPEI16_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoswapei16.v x0, (${rs1}), $vs2, $vd",
                (VAMOSWAPEI16_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoswapei16.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOSWAPEI16_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamoswapei32.v $vd, (${rs1}), $vs2, $vd",
                (VAMOSWAPEI32_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoswapei32.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOSWAPEI32_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoswapei32.v x0, (${rs1}), $vs2, $vd",
                (VAMOSWAPEI32_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoswapei32.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOSWAPEI32_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamoswapei64.v $vd, (${rs1}), $vs2, $vd",
                (VAMOSWAPEI64_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoswapei64.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOSWAPEI64_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoswapei64.v x0, (${rs1}), $vs2, $vd",
                (VAMOSWAPEI64_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoswapei64.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOSWAPEI64_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamoaddei8.v $vd, (${rs1}), $vs2, $vd",
                (VAMOADDEI8_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoaddei8.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOADDEI8_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoaddei8.v x0, (${rs1}), $vs2, $vd",
                (VAMOADDEI8_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoaddei8.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOADDEI8_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamoaddei16.v $vd, (${rs1}), $vs2, $vd",
                (VAMOADDEI16_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoaddei16.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOADDEI16_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoaddei16.v x0, (${rs1}), $vs2, $vd",
                (VAMOADDEI16_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoaddei16.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOADDEI16_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamoaddei32.v $vd, (${rs1}), $vs2, $vd",
                (VAMOADDEI32_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoaddei32.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOADDEI32_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoaddei32.v x0, (${rs1}), $vs2, $vd",
                (VAMOADDEI32_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoaddei32.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOADDEI32_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamoaddei64.v $vd, (${rs1}), $vs2, $vd",
                (VAMOADDEI64_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoaddei64.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOADDEI64_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoaddei64.v x0, (${rs1}), $vs2, $vd",
                (VAMOADDEI64_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoaddei64.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOADDEI64_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamoxorei8.v $vd, (${rs1}), $vs2, $vd",
                (VAMOXOREI8_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoxorei8.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOXOREI8_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoxorei8.v x0, (${rs1}), $vs2, $vd",
                (VAMOXOREI8_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoxorei8.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOXOREI8_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamoxorei16.v $vd, (${rs1}), $vs2, $vd",
                (VAMOXOREI16_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoxorei16.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOXOREI16_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoxorei16.v x0, (${rs1}), $vs2, $vd",
                (VAMOXOREI16_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoxorei16.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOXOREI16_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamoxorei32.v $vd, (${rs1}), $vs2, $vd",
                (VAMOXOREI32_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoxorei32.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOXOREI32_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoxorei32.v x0, (${rs1}), $vs2, $vd",
                (VAMOXOREI32_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoxorei32.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOXOREI32_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamoxorei64.v $vd, (${rs1}), $vs2, $vd",
                (VAMOXOREI64_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoxorei64.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOXOREI64_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoxorei64.v x0, (${rs1}), $vs2, $vd",
                (VAMOXOREI64_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoxorei64.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOXOREI64_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamoandei8.v $vd, (${rs1}), $vs2, $vd",
                (VAMOANDEI8_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoandei8.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOANDEI8_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoandei8.v x0, (${rs1}), $vs2, $vd",
                (VAMOANDEI8_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoandei8.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOANDEI8_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamoandei16.v $vd, (${rs1}), $vs2, $vd",
                (VAMOANDEI16_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoandei16.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOANDEI16_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoandei16.v x0, (${rs1}), $vs2, $vd",
                (VAMOANDEI16_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoandei16.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOANDEI16_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamoandei32.v $vd, (${rs1}), $vs2, $vd",
                (VAMOANDEI32_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoandei32.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOANDEI32_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoandei32.v x0, (${rs1}), $vs2, $vd",
                (VAMOANDEI32_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoandei32.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOANDEI32_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamoandei64.v $vd, (${rs1}), $vs2, $vd",
                (VAMOANDEI64_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoandei64.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOANDEI64_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoandei64.v x0, (${rs1}), $vs2, $vd",
                (VAMOANDEI64_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoandei64.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOANDEI64_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamoorei8.v $vd, (${rs1}), $vs2, $vd",
                (VAMOOREI8_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoorei8.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOOREI8_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoorei8.v x0, (${rs1}), $vs2, $vd",
                (VAMOOREI8_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoorei8.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOOREI8_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamoorei16.v $vd, (${rs1}), $vs2, $vd",
                (VAMOOREI16_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoorei16.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOOREI16_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoorei16.v x0, (${rs1}), $vs2, $vd",
                (VAMOOREI16_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoorei16.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOOREI16_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamoorei32.v $vd, (${rs1}), $vs2, $vd",
                (VAMOOREI32_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoorei32.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOOREI32_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoorei32.v x0, (${rs1}), $vs2, $vd",
                (VAMOOREI32_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoorei32.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOOREI32_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamoorei64.v $vd, (${rs1}), $vs2, $vd",
                (VAMOOREI64_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamoorei64.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOOREI64_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamoorei64.v x0, (${rs1}), $vs2, $vd",
                (VAMOOREI64_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamoorei64.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOOREI64_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamominei8.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMINEI8_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamominei8.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINEI8_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamominei8.v x0, (${rs1}), $vs2, $vd",
                (VAMOMINEI8_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamominei8.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINEI8_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamominei16.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMINEI16_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamominei16.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINEI16_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamominei16.v x0, (${rs1}), $vs2, $vd",
                (VAMOMINEI16_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamominei16.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINEI16_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamominei32.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMINEI32_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamominei32.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINEI32_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamominei32.v x0, (${rs1}), $vs2, $vd",
                (VAMOMINEI32_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamominei32.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINEI32_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamominei64.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMINEI64_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamominei64.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINEI64_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamominei64.v x0, (${rs1}), $vs2, $vd",
                (VAMOMINEI64_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamominei64.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINEI64_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamomaxei8.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMAXEI8_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamomaxei8.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXEI8_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamomaxei8.v x0, (${rs1}), $vs2, $vd",
                (VAMOMAXEI8_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamomaxei8.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXEI8_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamomaxei16.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMAXEI16_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamomaxei16.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXEI16_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamomaxei16.v x0, (${rs1}), $vs2, $vd",
                (VAMOMAXEI16_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamomaxei16.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXEI16_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamomaxei32.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMAXEI32_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamomaxei32.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXEI32_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamomaxei32.v x0, (${rs1}), $vs2, $vd",
                (VAMOMAXEI32_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamomaxei32.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXEI32_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamomaxei64.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMAXEI64_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamomaxei64.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXEI64_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamomaxei64.v x0, (${rs1}), $vs2, $vd",
                (VAMOMAXEI64_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamomaxei64.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXEI64_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamominuei8.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMINUEI8_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamominuei8.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINUEI8_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamominuei8.v x0, (${rs1}), $vs2, $vd",
                (VAMOMINUEI8_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamominuei8.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINUEI8_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamominuei16.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMINUEI16_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamominuei16.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINUEI16_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamominuei16.v x0, (${rs1}), $vs2, $vd",
                (VAMOMINUEI16_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamominuei16.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINUEI16_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamominuei32.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMINUEI32_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamominuei32.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINUEI32_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamominuei32.v x0, (${rs1}), $vs2, $vd",
                (VAMOMINUEI32_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamominuei32.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINUEI32_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamominuei64.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMINUEI64_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamominuei64.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINUEI64_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamominuei64.v x0, (${rs1}), $vs2, $vd",
                (VAMOMINUEI64_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamominuei64.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMINUEI64_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

def : InstAlias<"vamomaxuei8.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMAXUEI8_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamomaxuei8.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXUEI8_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamomaxuei8.v x0, (${rs1}), $vs2, $vd",
                (VAMOMAXUEI8_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamomaxuei8.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXUEI8_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamomaxuei16.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMAXUEI16_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamomaxuei16.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXUEI16_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamomaxuei16.v x0, (${rs1}), $vs2, $vd",
                (VAMOMAXUEI16_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamomaxuei16.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXUEI16_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamomaxuei32.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMAXUEI32_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamomaxuei32.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXUEI32_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamomaxuei32.v x0, (${rs1}), $vs2, $vd",
                (VAMOMAXUEI32_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamomaxuei32.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXUEI32_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;
def : InstAlias<"vamomaxuei64.v $vd, (${rs1}), $vs2, $vd",
                (VAMOMAXUEI64_V_wd_um  VR:$vd, GPR:$rs1, VR:$vs2, 0)>;
def : InstAlias<"vamomaxuei64.v $vd, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXUEI64_V_wd_m  VR:$vd, GPR:$rs1, VR:$vs2, 0, VMR:$vm)>;
def : InstAlias<"vamomaxuei64.v x0, (${rs1}), $vs2, $vd",
                (VAMOMAXUEI64_V_um GPR:$rs1, VR:$vs2, VR:$vd, 0)>;
def : InstAlias<"vamomaxuei64.v x0, (${rs1}), $vs2, $vd, $vm",
                (VAMOMAXUEI64_V_m  GPR:$rs1, VR:$vs2, VR:$vd, 0, VMR:$vm)>;

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


def : InstAlias<"vmmv.m $vd, $vs2",
                (VMAND_MM  VR:$vd, VR:$vs2, VR:$vs2)>;
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
  def PseudoCSRR_VLENB : Pseudo<(outs GPR:$rd), (ins VLR:$vlenb), []>,
                      PseudoInstExpansion<(CSRRS GPR:$rd, 0xC22, X0)>;
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

// // TODO exploit immediate offset
// def : Pat<(int_riscv_vlw GPR:$rs1),
//           (VLE32_V_um GPR:$rs1, 0)>;

// def : Pat<(int_riscv_vsw VR:$vs3, GPR:$rs1),
//           (VSE32_V_um VR:$vs3, GPR:$rs1, 0)>;

class PatLE32<SDPatternOperator OpNode>
    : Pat<(OpNode GPR:$src), (VLE32_V_um $src, 0)>;

def : PatLE32<int_riscv_vle32_v_f32m1>;

def : PatLE32<int_riscv_vle32_v_f32m8>;


class PatSE32<SDPatternOperator OpNode>
    : Pat<(OpNode VR:$src, GPR:$dst), (VSE32_V_um $src, $dst, 0)>;

def : PatSE32<int_riscv_vse32_v_f32m1>;

def : PatSE32<int_riscv_vse32_v_f32m8>;

// def : Pat<(int_riscv_vse32_v_f32m8 VR:$src, GPR:$dst),
//           (VSE32_V_um $src, $dst, 0)>;

// def : Pat<(int_riscv_vse32_v_f32m1 VR:$src, GPR:$dst),
//           (VSE32_V_um $src, $dst, 0)>;
 

def : Pat<(int_riscv_vfmacc_vf_f32m1 VR:$acc, FPR32:$op1, VR:$op2),
          (VFMACC_VF_um $acc, $op1, $op2)>;

def : Pat<(int_riscv_vfmacc_vf_f32m8 VR:$acc, FPR32:$op1, VR:$op2),
          (VFMACC_VF_um $acc, $op1, $op2)>;


def : Pat<(int_riscv_vfmv_f_s_f32m1_f32 VR:$src), (VFMV_F_S $src)>;

def : Pat<(nxv1f32 (int_riscv_vfadd_vv_f32m1 VR:$vs2, VR:$vs1)), (VFADD_VV_um VR:$vs2, VR:$vs1)>;



def : Pat<(nxv1f32 (load GPR:$src)), (VLE32_V_um $src, 0)>;

def : Pat<(nxv8f32 (load GPR:$src)), (VLE32_V_um $src, 0)>;


def : Pat<(store nxv8f32:$src, GPR:$dst), (VSE32_V_um $src, $dst, 0)>;

def : Pat<(store nxv1f32:$src, GPR:$dst), (VSE32_V_um $src, $dst, 0)>;


def : Pat<(vscale GPR:$mul), (MUL VLENB, $mul)>;

// def : Pat<(store VR:$src, GPR:$dst), (VSE32_V_um $src, $dst, 0)>;

def : Pat<(int_riscv_vsetvl GPR:$rs1, GPR:$rs2), (VSETVL $rs1, $rs2)>;

} // Predicates = [HasStdExtV]
