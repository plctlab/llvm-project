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

def uimm11 : Operand<XLenVT>, ImmLeaf<XLenVT, [{return isUInt<11>(Imm);}]> {
  let ParserMatchClass = UImmAsmOperand<11>;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeUImmOperand<11>";
}

//===----------------------------------------------------------------------===//
// Instruction class templates
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
multiclass VLoad_UnitStride<bits<3> nf, bits<3> mop,
                            bits<3> width, string opcodestr> {
  def _m  : RVInstVLoad<nf, mop, width, RVV_Masked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, VLR:$vl, simm5:$imm5, VMR:$vm),
                  opcodestr, "$vd, ${imm5}(${rs1}), $vm"> {
    let Inst{24-20} = 0b00000;
  }
  def _um : RVInstVLoad<nf, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, VLR:$vl, simm5:$imm5),
                  opcodestr, "$vd, ${imm5}(${rs1})"> {
    let Inst{24-20} = 0b00000;
  }
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
multiclass VLoad_UnitStrideFF<bits<3> nf, bits<3> mop,
                              bits<3> width, string opcodestr> {
  def _m  : RVInstVLoad<nf, mop, width, RVV_Masked, OPC_LOAD_FP,
                    (outs VR:$vd), (ins GPR:$rs1, VLR:$vl, simm5:$imm5, VMR:$vm),
                    opcodestr, "$vd, ${imm5}(${rs1}), $vm"> {
    let Inst{24-20} = 0b10000;
  }
  def _um : RVInstVLoad<nf, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                    (outs VR:$vd), (ins GPR:$rs1, VLR:$vl, simm5:$imm5),
                    opcodestr, "$vd, ${imm5}(${rs1})"> {
    let Inst{24-20} = 0b10000;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
multiclass VStore_UnitStride<bits<3> nf, bits<3> mop,
                             bits<3> width, string opcodestr> {
  def _m  : RVInstVStore<nf, mop, width, RVV_Masked, OPC_STORE_FP,
                     (outs), (ins VR:$vs3, GPR:$rs1, VLR:$vl, simm5:$imm5, VMR:$vm),
                     opcodestr, "$vs3, ${imm5}(${rs1}), $vm"> {
    let Inst{24-20} = 0b00000;
  }
  def _um : RVInstVStore<nf, mop, width, RVV_Unmasked, OPC_STORE_FP,
                     (outs), (ins VR:$vs3, GPR:$rs1, VLR:$vl, simm5:$imm5),
                     opcodestr, "$vs3, ${imm5}(${rs1})"> {
    let Inst{24-20} = 0b00000;
  }
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
multiclass VLoad_Strided<bits<3> nf, bits<3> mop,
                         bits<3> width, string opcodestr> {
  def _m  : RVInstVLoad<nf, mop, width, RVV_Masked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, GPR:$rs2, VLR:$vl, simm5:$imm5, VMR:$vm),
                  opcodestr, "$vd, ${imm5}(${rs1}), $rs2, $vm"> {
    bits<5> rs2;
    let Inst{24-20} = rs2;
  }
  def _um : RVInstVLoad<nf, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, GPR:$rs2, VLR:$vl, simm5:$imm5),
                  opcodestr, "$vd, ${imm5}(${rs1}), $rs2"> {
    bits<5> rs2;
    let Inst{24-20} = rs2;
  }
}
  
let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
multiclass VStore_Strided<bits<3> nf, bits<3> mop,
                          bits<3> width, string opcodestr> {
  def _m  : RVInstVStore<nf, mop, width, RVV_Masked, OPC_STORE_FP,
                   (outs), (ins VR:$vs3, GPR:$rs1, GPR:$rs2, VLR:$vl, simm5:$imm5, VMR:$vm),
                   opcodestr, "$vs3, ${imm5}(${rs1}), $rs2, $vm"> {
    bits<5> rs2;
    let Inst{24-20} = rs2;
  }
  def _um : RVInstVStore<nf, mop, width, RVV_Unmasked, OPC_STORE_FP,
                   (outs), (ins VR:$vs3, GPR:$rs1, GPR:$rs2, VLR:$vl, simm5:$imm5),
                   opcodestr, "$vs3, ${imm5}(${rs1}), $rs2"> {
    bits<5> rs2;
    let Inst{24-20} = rs2;
  }
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
multiclass VLoad_Indexed<bits<3> nf, bits<3> mop,
                         bits<3> width, string opcodestr> {
  def _m  : RVInstVLoad<nf, mop, width, RVV_Masked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, VR:$vs2, VLR:$vl, simm5:$imm5, VMR:$vm),
                  opcodestr, "$vd, ${imm5}(${rs1}), $vs2, $vm"> {
    bits<5> vs2;
    let Inst{24-20} = vs2;
  }
  def _um : RVInstVLoad<nf, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, VR:$vs2, VLR:$vl, simm5:$imm5),
                  opcodestr, "$vd, ${imm5}(${rs1}), $vs2"> {
    bits<5> vs2;
    let Inst{24-20} = vs2;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
multiclass VStore_Indexed<bits<3> nf, bits<3> mop,
                          bits<3> width, string opcodestr> {
  def _m  : RVInstVStore<nf, mop, width, RVV_Masked, OPC_STORE_FP,
                   (outs), (ins VR:$vs3, GPR:$rs1, VR:$vs2, VLR:$vl, simm5:$imm5, VMR:$vm),
                   opcodestr, "$vs3, ${imm5}(${rs1}), $vs2, $vm"> {
    bits<5> vs2;
    let Inst{24-20} = vs2;
  }
  def _um : RVInstVStore<nf, mop, width, RVV_Unmasked, OPC_STORE_FP,
                   (outs), (ins VR:$vs3, GPR:$rs1, VR:$vs2, VLR:$vl, simm5:$imm5),
                   opcodestr, "$vs3, ${imm5}(${rs1}), $vs2"> {
    bits<5> vs2;
    let Inst{24-20} = vs2;
  }
}

/*
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_AMO<bits<5> amoop, bits<1> wd, bits<3> width, string opcodestr>
    : RVInstVAMO<amoop, wd, width, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vs3), (ins GPR:$rs1, VR:$vs2, VLR:$vl),
               opcodestr, "$vs3, $vs1, $vs2">
*/

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPIVV<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b000, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $vs2, $vs1, $vm"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<funct6, 0b000, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1, VLR:$vl),
               opcodestr, "$vd, $vs2, $vs1"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVV_m<bits<6> funct6, string opcodestr> 
    : RVInstVA<funct6, 0b000, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1, VLR:$vl, VRV0:$v0),
               opcodestr, "$vd, $vs2, $vs1, $v0"> {
  bits<5> vs1;
  let Inst{19-15} = vs1;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVV_um<bits<6> funct6, string opcodestr> 
    : RVInstVA<funct6, 0b000, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1, VLR:$vl),
               opcodestr, "$vd, $vs2, $vs1"> {
  bits<5> vs1;
  let Inst{19-15} = vs1;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPIVV_MulAdd<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b000, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $vs1, $vs2, $vm"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<funct6, 0b000, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VLR:$vl),
               opcodestr, "$vd, $vs1, $vs2"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPFVV<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b001, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $vs2, $vs1, $vm"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<funct6, 0b001, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1, VLR:$vl),
               opcodestr, "$vd, $vs2, $vs1"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPFVV_VFUNARY0<bits<5> vs1, string opcodestr> {
  def _m  : RVInstVA<0b100010, 0b001, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $vs2, $vm"> {
    let Inst{19-15} = vs1;
  }  
  def _um : RVInstVA<0b100010, 0b001, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VLR:$vl),
               opcodestr, "$vd, $vs2"> {
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPFVV_VFUNARY1<bits<5> vs1, string opcodestr> {
  def _m  : RVInstVA<0b100011, 0b001, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $vs2, $vm"> {
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<0b100011, 0b001, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VLR:$vl),
               opcodestr, "$vd, $vs2"> {
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPFVV_MulAdd<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b001, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $vs1, $vs2, $vm"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<funct6, 0b001, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VLR:$vl),
               opcodestr, "$vd, $vs1, $vs2"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPMVV<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b010, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $vs2, $vs1, $vm"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<funct6, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1, VLR:$vl),
               opcodestr, "$vd, $vs2, $vs1"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPMVV_um<bits<6> funct6, string opcodestr>
    : RVInstVA<funct6, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VR:$vs1, VLR:$vl),
               opcodestr, "$vd, $vs2, $vs1"> {
  bits<5> vs1;
  let Inst{19-15} = vs1;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPMVV_VWXUNARY0<bits<5> vs1, string opcodestr> {
  def _m  : RVInstVA<0b010000, 0b010, RVV_Masked, OPC_OP_V,
               (outs GPR:$rd), (ins VR:$vs2, VLR:$vl, VMR:$vm),
               opcodestr, "$rd, $vs2, $vm"> {
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<0b010000, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs GPR:$rd), (ins VR:$vs2, VLR:$vl),
               opcodestr, "$rd, $vs2"> {
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPMVV_VMUNARY0<bits<5> vs1, string opcodestr> {
  def _m  : RVInstVA<0b010100, 0b010, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $vs2, $vm"> {
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<0b010100, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, VLR:$vl),
               opcodestr, "$vd, $vs2"> {
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPMVV_MulAdd<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b010, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $vs1, $vs2, $vm"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
  def _um : RVInstVA<funct6, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VLR:$vl),
               opcodestr, "$vd, $vs1, $vs2"> {
    bits<5> vs1;
    let Inst{19-15} = vs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPIVI_signed<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b011, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, simm5:$simm, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $vs2, $simm, $vm"> {
    bits<5> simm;
    let Inst{19-15} = simm;
  }
  def _um : RVInstVA<funct6, 0b011, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, simm5:$simm, VLR:$vl),
               opcodestr, "$vd, $vs2, $simm"> {
    bits<5> simm;
    let Inst{19-15} = simm;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPIVI_unsigned<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b011, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, uimm5:$uimm, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $vs2, $uimm, $vm"> {
    bits<5> uimm;
    let Inst{19-15} = uimm;
  }
  def _um : RVInstVA<funct6, 0b011, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, uimm5:$uimm, VLR:$vl),
               opcodestr, "$vd, $vs2, $uimm"> {
    bits<5> uimm;
    let Inst{19-15} = uimm;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVI_m<bits<6> funct6, string opcodestr> 
    : RVInstVA<funct6, 0b011, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, simm5:$simm, VLR:$vl, VRV0:$v0),
               opcodestr, "$vd, $vs2, $simm, $v0"> {
  bits<5> simm;
  let Inst{19-15} = simm;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVI_um<bits<6> funct6, string opcodestr> 
    : RVInstVA<funct6, 0b011, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, simm5:$simm, VLR:$vl),
               opcodestr, "$vd, $vs2, $simm"> {
  bits<5> simm;
  let Inst{19-15} = simm;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPIVX<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b100, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $vs2, $rs1, $vm"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
  def _um : RVInstVA<funct6, 0b100, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VLR:$vl),
               opcodestr, "$vd, $vs2, $rs1"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVX_m<bits<6> funct6, string opcodestr> 
    : RVInstVA<funct6, 0b100, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VLR:$vl, VRV0:$v0),
               opcodestr, "$vd, $vs2, $rs1, $v0"> {
  bits<5> rs1;
  let Inst{19-15} = rs1;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVX_um<bits<6> funct6, string opcodestr> 
    : RVInstVA<funct6, 0b100, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VLR:$vl),
               opcodestr, "$vd, $vs2, $rs1"> {
  bits<5> rs1;
  let Inst{19-15} = rs1;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPIVX_MulAdd<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b100, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins GPR:$rs1, VR:$vs2, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $rs1, $vs2, $vm"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
  def _um : RVInstVA<funct6, 0b100, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins GPR:$rs1, VR:$vs2, VLR:$vl),
               opcodestr, "$vd, $rs1, $vs2"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPFVF<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b101, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, FPR32:$rs1, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $vs2, $rs1, $vm"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
  def _um : RVInstVA<funct6, 0b101, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, FPR32:$rs1, VLR:$vl),
               opcodestr, "$vd, $vs2, $rs1"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPFVF_MulAdd<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b101, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins FPR32:$rs1, VR:$vs2, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $rs1, $vs2, $vm"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
  def _um : RVInstVA<funct6, 0b101, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins FPR32:$rs1, VR:$vs2, VLR:$vl),
               opcodestr, "$vd, $rs1, $vs2"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPMVX<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b110, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $vs2, $rs1, $vm"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
  def _um : RVInstVA<funct6, 0b110, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VLR:$vl),
               opcodestr, "$vd, $vs2, $rs1"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
multiclass VALU_OPMVX_MulAdd<bits<6> funct6, string opcodestr> {
  def _m  : RVInstVA<funct6, 0b110, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins GPR:$rs1, VR:$vs2, VLR:$vl, VMR:$vm),
               opcodestr, "$vd, $rs1, $vs2, $vm"> {
    bits<5> rs1;
    let Inst{19-15} = rs1;
  }
  def _um : RVInstVA<funct6, 0b110, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins GPR:$rs1, VR:$vs2, VLR:$vl),
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
                      (outs VLR:$vl, GPR:$rd), (ins GPR:$rs1, uimm11:$vtypei),
                      "vsetvli", "$rd, $rs1, $vtypei"> {
  bits<11> vtypei;
  let Inst{30-20} = vtypei;
}
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VSETVL: RVInstVSet<0b1, OPC_OP_V, 
                      (outs VLR:$vl, GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
                      "vsetvl", "$rd, $rs1, $rs2"> {
  bits<5> rs2;
  let Inst{30-25} = 0b000000;
  let Inst{24-20} = rs2;
}


// Vector Unit-Stride Instructions

defm VLB_V : VLoad_UnitStride<0b000, 0b100, 0b000, "vlb.v">;
defm VLH_V : VLoad_UnitStride<0b000, 0b100, 0b101, "vlh.v">;
defm VLW_V : VLoad_UnitStride<0b000, 0b100, 0b110, "vlw.v">;
defm VLBU_V : VLoad_UnitStride<0b000, 0b000, 0b000, "vlbu.v">;
defm VLHU_V : VLoad_UnitStride<0b000, 0b000, 0b101, "vlhu.v">;
defm VLWU_V : VLoad_UnitStride<0b000, 0b000, 0b110, "vlwu.v">;
defm VLE_V : VLoad_UnitStride<0b000, 0b000, 0b111, "vle.v">;

defm VSB_V : VStore_UnitStride<0b000, 0b000, 0b000, "vsb.v">;
defm VSH_V : VStore_UnitStride<0b000, 0b000, 0b101, "vsh.v">;
defm VSW_V : VStore_UnitStride<0b000, 0b000, 0b110, "vsw.v">;
defm VSE_V : VStore_UnitStride<0b000, 0b000, 0b111, "vse.v">;


// Vector Strided Instructions

defm VLSB_V : VLoad_Strided<0b000, 0b110, 0b000, "vlsb.v">;
defm VLSH_V : VLoad_Strided<0b000, 0b110, 0b101, "vlsh.v">;
defm VLSW_V : VLoad_Strided<0b000, 0b110, 0b110, "vlsw.v">;
defm VLSBU_V : VLoad_Strided<0b000, 0b010, 0b000, "vlsbu.v">;
defm VLSHU_V : VLoad_Strided<0b000, 0b010, 0b101, "vlshu.v">;
defm VLSWU_V : VLoad_Strided<0b000, 0b010, 0b110, "vlswu.v">;
defm VLSE_V : VLoad_Strided<0b000, 0b010, 0b111, "vlse.v">;

defm VSSB_V : VStore_Strided<0b000, 0b010, 0b000, "vssb.v">;
defm VSSH_V : VStore_Strided<0b000, 0b010, 0b101, "vssh.v">;
defm VSSW_V : VStore_Strided<0b000, 0b010, 0b110, "vssw.v">;
defm VSSE_V : VStore_Strided<0b000, 0b010, 0b111, "vsse.v">;


// Vector Indexed Instructions

defm VLXB_V : VLoad_Indexed<0b000, 0b111, 0b000, "vlxb.v">;
defm VLXH_V : VLoad_Indexed<0b000, 0b111, 0b101, "vlxh.v">;
defm VLXW_V : VLoad_Indexed<0b000, 0b111, 0b110, "vlxw.v">;
defm VLXBU_V : VLoad_Indexed<0b000, 0b011, 0b000, "vlxbu.v">;
defm VLXHU_V : VLoad_Indexed<0b000, 0b011, 0b101, "vlxhu.v">;
defm VLXWU_V : VLoad_Indexed<0b000, 0b011, 0b110, "vlxwu.v">;
defm VLXE_V : VLoad_Indexed<0b000, 0b011, 0b111, "vlxe.v">;

defm VSXB_V : VStore_Indexed<0b000, 0b011, 0b000, "vsxb.v">;
defm VSXH_V : VStore_Indexed<0b000, 0b011, 0b101, "vsxh.v">;
defm VSXW_V : VStore_Indexed<0b000, 0b011, 0b110, "vsxw.v">;
defm VSXE_V : VStore_Indexed<0b000, 0b011, 0b111, "vsxe.v">;
defm VSUXB_V : VStore_Indexed<0b000, 0b111, 0b000, "vsuxb.v">;
defm VSUXH_V : VStore_Indexed<0b000, 0b111, 0b101, "vsuxh.v">;
defm VSUXW_V : VStore_Indexed<0b000, 0b111, 0b110, "vsuxw.v">;
defm VSUXE_V : VStore_Indexed<0b000, 0b111, 0b111, "vsuxe.v">;


// Unit-stride Fault-Only-First Loads Instructions

defm VLBFF_V : VLoad_UnitStrideFF<0b000, 0b100, 0b000, "vlbff.v">;
defm VLHFF_V : VLoad_UnitStrideFF<0b000, 0b100, 0b101, "vlhff.v">;
defm VLWFF_V : VLoad_UnitStrideFF<0b000, 0b100, 0b110, "vlwff.v">;
defm VLBUFF_V : VLoad_UnitStrideFF<0b000, 0b000, 0b000, "vlbuff.v">;
defm VLHUFF_V : VLoad_UnitStrideFF<0b000, 0b000, 0b101, "vlhuff.v">;
defm VLWUFF_V : VLoad_UnitStrideFF<0b000, 0b000, 0b110, "vlwuff.v">;
defm VLEFF_V : VLoad_UnitStrideFF<0b000, 0b000, 0b111, "vleff.v">;


// Vector Load/Store Segment Instructions
// TODO

foreach nf = 2-8 in {

  // Vector Unit-Stride Segment Loads and Stores
  defm VLSEG#nf#B_V : VLoad_UnitStride<!add(nf, -1), 0b100,
                                       0b000, "vlseg"#nf#"b.v">;
  defm VLSEG#nf#H_V : VLoad_UnitStride<!add(nf, -1), 0b100,
                                       0b101, "vlseg"#nf#"h.v">;
  defm VLSEG#nf#W_V : VLoad_UnitStride<!add(nf, -1), 0b100,
                                       0b110, "vlseg"#nf#"w.v">;
  defm VLSEG#nf#BU_V : VLoad_UnitStride<!add(nf, -1), 0b000,
                                       0b000, "vlseg"#nf#"bu.v">;
  defm VLSEG#nf#HU_V : VLoad_UnitStride<!add(nf, -1), 0b000,
                                       0b101, "vlseg"#nf#"hu.v">;
  defm VLSEG#nf#WU_V : VLoad_UnitStride<!add(nf, -1), 0b000,
                                       0b110, "vlseg"#nf#"wu.v">;
  defm VLSEG#nf#E_V : VLoad_UnitStride<!add(nf, -1), 0b000,
                                       0b111, "vlseg"#nf#"e.v">;
  defm VSSEG#nf#B_V : VStore_UnitStride<!add(nf, -1), 0b000,
                                       0b000, "vsseg"#nf#"b.v">;
  defm VSSEG#nf#H_V : VStore_UnitStride<!add(nf, -1), 0b000,
                                       0b101, "vsseg"#nf#"h.v">;
  defm VSSEG#nf#W_V : VStore_UnitStride<!add(nf, -1), 0b000,
                                       0b110, "vsseg"#nf#"w.v">;
  defm VSSEG#nf#E_V : VStore_UnitStride<!add(nf, -1), 0b000,
                                       0b111, "vsseg"#nf#"e.v">;

  // Vector Strided Segment Loads and Stores
  defm VLSSEG#nf#B_V : VLoad_Strided<!add(nf, -1), 0b110,
                                       0b000, "vlsseg"#nf#"b.v">;
  defm VLSSEG#nf#H_V : VLoad_Strided<!add(nf, -1), 0b110,
                                       0b101, "vlsseg"#nf#"h.v">;
  defm VLSSEG#nf#W_V : VLoad_Strided<!add(nf, -1), 0b110,
                                       0b110, "vlsseg"#nf#"w.v">;
  defm VLSSEG#nf#BU_V : VLoad_Strided<!add(nf, -1), 0b010,
                                       0b000, "vlsseg"#nf#"bu.v">;
  defm VLSSEG#nf#HU_V : VLoad_Strided<!add(nf, -1), 0b010,
                                       0b101, "vlsseg"#nf#"hu.v">;
  defm VLSSEG#nf#WU_V : VLoad_Strided<!add(nf, -1), 0b010,
                                       0b110, "vlsseg"#nf#"wu.v">;
  defm VLSSEG#nf#E_V : VLoad_Strided<!add(nf, -1), 0b010,
                                       0b111, "vlsseg"#nf#"e.v">;
  defm VSSSEG#nf#B_V : VStore_Strided<!add(nf, -1), 0b010,
                                       0b000, "vssseg"#nf#"b.v">;
  defm VSSSEG#nf#H_V : VStore_Strided<!add(nf, -1), 0b010,
                                       0b101, "vssseg"#nf#"h.v">;
  defm VSSSEG#nf#W_V : VStore_Strided<!add(nf, -1), 0b010,
                                       0b110, "vssseg"#nf#"w.v">;
  defm VSSSEG#nf#E_V : VStore_Strided<!add(nf, -1), 0b010,
                                       0b111, "vssseg"#nf#"e.v">;

  // Vector Indexed Segment Loads and Stores
  defm VLXSEG#nf#B_V : VLoad_Indexed<!add(nf, -1), 0b111,
                                       0b000, "vlxseg"#nf#"b.v">;
  defm VLXSEG#nf#H_V : VLoad_Indexed<!add(nf, -1), 0b111,
                                       0b101, "vlxseg"#nf#"h.v">;
  defm VLXSEG#nf#W_V : VLoad_Indexed<!add(nf, -1), 0b111,
                                       0b110, "vlxseg"#nf#"w.v">;
  defm VLXSEG#nf#BU_V : VLoad_Indexed<!add(nf, -1), 0b011,
                                       0b000, "vlxseg"#nf#"bu.v">;
  defm VLXSEG#nf#HU_V : VLoad_Indexed<!add(nf, -1), 0b011,
                                       0b101, "vlxseg"#nf#"hu.v">;
  defm VLXSEG#nf#WU_V : VLoad_Indexed<!add(nf, -1), 0b011,
                                       0b110, "vlxseg"#nf#"wu.v">;
  defm VLXSEG#nf#E_V : VLoad_Indexed<!add(nf, -1), 0b011,
                                       0b111, "vlxseg"#nf#"e.v">;
  defm VSXSEG#nf#B_V : VStore_Indexed<!add(nf, -1), 0b011,
                                       0b000, "vsxseg"#nf#"b.v">;
  defm VSXSEG#nf#H_V : VStore_Indexed<!add(nf, -1), 0b011,
                                       0b101, "vsxseg"#nf#"h.v">;
  defm VSXSEG#nf#W_V : VStore_Indexed<!add(nf, -1), 0b011,
                                       0b110, "vsxseg"#nf#"w.v">;
  defm VSXSEG#nf#E_V : VStore_Indexed<!add(nf, -1), 0b011,
                                       0b111, "vsxseg"#nf#"e.v">;

  // Vector Unit-Stride Fault-Only-First Segment Loads
  defm VLSEG#nf#BFF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b100,
                                       0b000, "vlseg"#nf#"bff.v">;
  defm VLSEG#nf#HFF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b100,
                                       0b101, "vlseg"#nf#"hff.v">;
  defm VLSEG#nf#WFF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b100,
                                       0b110, "vlseg"#nf#"wff.v">;
  defm VLSEG#nf#BUFF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b000,
                                       0b000, "vlseg"#nf#"buff.v">;
  defm VLSEG#nf#HUFF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b000,
                                       0b101, "vlseg"#nf#"huff.v">;
  defm VLSEG#nf#WUFF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b000,
                                       0b110, "vlseg"#nf#"wuff.v">;
  defm VLSEG#nf#EFF_V : VLoad_UnitStrideFF<!add(nf, -1), 0b000,
                                       0b111, "vlseg"#nf#"eff.v">;
}


// Vector Load/Store Whole Register Instructions
// TODO


// Vector AMO Operations
// TODO


// Vector Single-Width Integer Add and Subtract Instructions

defm VADD_VV : VALU_OPIVV<0b000000, "vadd.vv">;
defm VADD_VX : VALU_OPIVX<0b000000, "vadd.vx">;
defm VADD_VI : VALU_OPIVI_signed<0b000000, "vadd.vi">;

defm VSUB_VV : VALU_OPIVV<0b000010, "vsub.vv">;
defm VSUB_VX : VALU_OPIVX<0b000010, "vsub.vx">;

defm VRSUB_VX : VALU_OPIVX<0b000011, "vrsub.vx">;
defm VRSUB_VI : VALU_OPIVI_signed<0b000011, "vrsub.vi">;


// Vector Widening Integer Add and Subtract Instructions

defm VWADDU_VV : VALU_OPMVV<0b110000, "vwaddu.vv">;
defm VWADDU_VX : VALU_OPMVX<0b110000, "vwaddu.vx">;
defm VWSUBU_VV : VALU_OPMVV<0b110010, "vwsubu.vv">;
defm VWSUBU_VX : VALU_OPMVX<0b110010, "vwsubu.vx">;

defm VWADD_VV : VALU_OPMVV<0b110001, "vwadd.vv">;
defm VWADD_VX : VALU_OPMVX<0b110001, "vwadd.vx">;
defm VWSUB_VV : VALU_OPMVV<0b110011, "vwsub.vv">;
defm VWSUB_VX : VALU_OPMVX<0b110011, "vwsub.vx">;

defm VWADDU_WV : VALU_OPMVV<0b110100, "vwaddu.wv">;
defm VWADDU_WX : VALU_OPMVX<0b110100, "vwaddu.wx">;
defm VWSUBU_WV : VALU_OPMVV<0b110110, "vwsubu.wv">;
defm VWSUBU_WX : VALU_OPMVX<0b110110, "vwsubu.wx">;

defm VWADD_WV : VALU_OPMVV<0b110101, "vwadd.wv">;
defm VWADD_WX : VALU_OPMVX<0b110101, "vwadd.wx">;
defm VWSUB_WV : VALU_OPMVV<0b110111, "vwsub.wv">;
defm VWSUB_WX : VALU_OPMVX<0b110111, "vwsub.wx">;


// Vector Integer Add-with-Carry / Subtract-with-Borrow Instructions

def VADC_VVM : VALU_OPIVV_m<0b010000, "vadc.vvm">;
def VADC_VXM : VALU_OPIVX_m<0b010000, "vadc.vxm">;
def VADC_VIM : VALU_OPIVI_m<0b010000, "vadc.vim">;

def VMADC_VVM : VALU_OPIVV_m<0b010001, "vmadc.vvm">;
def VMADC_VXM : VALU_OPIVX_m<0b010001, "vmadc.vxm">;
def VMADC_VIM : VALU_OPIVI_m<0b010001, "vmadc.vim">;

def VMADC_VV : VALU_OPIVV_um<0b010001, "vmadc.vv">;
def VMADC_VX : VALU_OPIVX_um<0b010001, "vmadc.vx">;
def VMADC_VI : VALU_OPIVI_um<0b010001, "vmadc.vi">;

def VSBC_VVM : VALU_OPIVV_m<0b010010, "vsbc.vvm">;
def VSBC_VXM : VALU_OPIVX_m<0b010010, "vsbc.vxm">;

def VMSBC_VVM : VALU_OPIVV_m<0b010011, "vmsbc.vvm">;
def VMSBC_VXM : VALU_OPIVX_m<0b010011, "vmsbc.vxm">;

def VMSBC_VV : VALU_OPIVV_um<0b010011, "vmsbc.vv">;
def VMSBC_VX : VALU_OPIVX_um<0b010011, "vmsbc.vx">;


// Vector Bitwise Logical Instructions

defm VAND_VV : VALU_OPIVV<0b001001, "vand.vv">;
defm VAND_VX : VALU_OPIVX<0b001001, "vand.vx">;
defm VAND_VI : VALU_OPIVI_signed<0b001001, "vand.vi">;

defm VOR_VV : VALU_OPIVV<0b001010, "vor.vv">;
defm VOR_VX : VALU_OPIVX<0b001010, "vor.vx">;
defm VOR_VI : VALU_OPIVI_signed<0b001010, "vor.vi">;

defm VXOR_VV : VALU_OPIVV<0b001011, "vxor.vv">;
defm VXOR_VX : VALU_OPIVX<0b001011, "vxor.vx">;
defm VXOR_VI : VALU_OPIVI_signed<0b001011, "vxor.vi">;


// Vector Single-Width Bit Shift Instructions

defm VSLL_VV : VALU_OPIVV<0b100101, "vsll.vv">;
defm VSLL_VX : VALU_OPIVX<0b100101, "vsll.vx">;
defm VSLL_VI : VALU_OPIVI_unsigned<0b100101, "vsll.vi">;

defm VSRL_VV : VALU_OPIVV<0b101000, "vsrl.vv">;
defm VSRL_VX : VALU_OPIVX<0b101000, "vsrl.vx">;
defm VSRL_VI : VALU_OPIVI_unsigned<0b101000, "vsrl.vi">;

defm VSRA_VV : VALU_OPIVV<0b101001, "vsra.vv">;
defm VSRA_VX : VALU_OPIVX<0b101001, "vsra.vx">;
defm VSRA_VI : VALU_OPIVI_unsigned<0b101001, "vsra.vi">;


// Vector Narrowing Integer Right Shift Instructions

defm VNSRL_WV : VALU_OPIVV<0b101100, "vnsrl.wv">;
defm VNSRL_WX : VALU_OPIVX<0b101100, "vnsrl.wx">;
defm VNSRL_WI : VALU_OPIVI_unsigned<0b101100, "vnsrl.wi">;

defm VNSRA_WV : VALU_OPIVV<0b101101, "vnsra.wv">;
defm VNSRA_WX : VALU_OPIVX<0b101101, "vnsra.wx">;
defm VNSRA_WI : VALU_OPIVI_unsigned<0b101101, "vnsra.wi">;


// Vector Integer Comparison Instructions

defm VMSEQ_VV : VALU_OPIVV<0b011000, "vmseq.vv">;
defm VMSEQ_VX : VALU_OPIVX<0b011000, "vmseq.vx">;
defm VMSEQ_VI : VALU_OPIVI_signed<0b011000, "vmseq.vi">;

defm VMSNE_VV : VALU_OPIVV<0b011001, "vmsne.vv">;
defm VMSNE_VX : VALU_OPIVX<0b011001, "vmsne.vx">;
defm VMSNE_VI : VALU_OPIVI_signed<0b011001, "vmsne.vi">;

defm VMSLTU_VV : VALU_OPIVV<0b011010, "vmsltu.vv">;
defm VMSLTU_VX : VALU_OPIVX<0b011010, "vmsltu.vx">;

defm VMSLT_VV : VALU_OPIVV<0b011011, "vmslt.vv">;
defm VMSLT_VX : VALU_OPIVX<0b011011, "vmslt.vx">;

defm VMSLEU_VV : VALU_OPIVV<0b011100, "vmsleu.vv">;
defm VMSLEU_VX : VALU_OPIVX<0b011100, "vmsleu.vx">;
defm VMSLEU_VI : VALU_OPIVI_signed<0b011100, "vmsleu.vi">;

defm VMSLE_VV : VALU_OPIVV<0b011101, "vmsle.vv">;
defm VMSLE_VX : VALU_OPIVX<0b011101, "vmsle.vx">;
defm VMSLE_VI : VALU_OPIVI_signed<0b011101, "vmsle.vi">;

defm VMSGTU_VX : VALU_OPIVX<0b011110, "vmsgtu.vx">;
defm VMSGTU_VI : VALU_OPIVI_signed<0b011110, "vmsgtu.vi">;

defm VMSGT_VX : VALU_OPIVX<0b011111, "vmsgt.vx">;
defm VMSGT_VI : VALU_OPIVI_signed<0b011111, "vmsgt.vi">;


// Vector Integer Min/Max Instructions

defm VMINU_VV : VALU_OPIVV<0b000100, "vminu.vv">;
defm VMINU_VX : VALU_OPIVX<0b000100, "vminu.vx">;

defm VMIN_VV : VALU_OPIVV<0b000101, "vmin.vv">;
defm VMIN_VX : VALU_OPIVX<0b000101, "vmin.vx">;

defm VMAXU_VV : VALU_OPIVV<0b000110, "vmaxu.vv">;
defm VMAXU_VX : VALU_OPIVX<0b000110, "vmaxu.vx">;

defm VMAX_VV : VALU_OPIVV<0b000111, "vmax.vv">;
defm VMAX_VX : VALU_OPIVX<0b000111, "vmax.vx">;


// Vector Single-Width Integer Multiply Instructions

defm VMUL_VV : VALU_OPMVV<0b100101, "vmul.vv">;
defm VMUL_VX : VALU_OPMVX<0b100101, "vmul.vx">;

defm VMULH_VV : VALU_OPMVV<0b100111, "vmulh.vv">;
defm VMULH_VX : VALU_OPMVX<0b100111, "vmulh.vx">;

defm VMULHU_VV : VALU_OPMVV<0b100100, "vmulhu.vv">;
defm VMULHU_VX : VALU_OPMVX<0b100100, "vmulhu.vx">;

defm VMULHSU_VV : VALU_OPMVV<0b100110, "vmulhsu.vv">;
defm VMULHSU_VX : VALU_OPMVX<0b100110, "vmulhsu.vx">;


// Vector Integer Divide Instructions

defm VDIVU_VV : VALU_OPMVV<0b100000, "vdivu.vv">;
defm VDIVU_VX : VALU_OPMVX<0b100000, "vdivu.vx">;

defm VDIV_VV : VALU_OPMVV<0b100001, "vdiv.vv">;
defm VDIV_VX : VALU_OPMVX<0b100001, "vdiv.vx">;

defm VREMU_VV : VALU_OPMVV<0b100010, "vremu.vv">;
defm VREMU_VX : VALU_OPMVX<0b100010, "vremu.vx">;

defm VREM_VV : VALU_OPMVV<0b100011, "vrem.vv">;
defm VREM_VX : VALU_OPMVX<0b100011, "vrem.vx">;


// Vector Widening Integer Multiply Instructions

defm VWMUL_VV : VALU_OPMVV<0b111011, "vwmul.vv">;
defm VWMUL_VX : VALU_OPMVX<0b111011, "vwmul.vx">;

defm VWMULU_VV : VALU_OPMVV<0b111000, "vwmulu.vv">;
defm VWMULU_VX : VALU_OPMVX<0b111000, "vwmulu.vx">;

defm VWMULSU_VV : VALU_OPMVV<0b111010, "vwmulsu.vv">;
defm VWMULSU_VX : VALU_OPMVX<0b111010, "vwmulsu.vx">;


// Vector Single-Width Integer Multiply-Add Instructions

defm VMACC_VV : VALU_OPMVV_MulAdd<0b101101, "vmacc.vv">;
defm VMACC_VX : VALU_OPMVX_MulAdd<0b101101, "vmacc.vx">;

defm VNMSAC_VV : VALU_OPMVV_MulAdd<0b101111, "vnmsac.vv">;
defm VNMSAC_VX : VALU_OPMVX_MulAdd<0b101111, "vnmsac.vx">;

defm VMADD_VV : VALU_OPMVV_MulAdd<0b101001, "vmadd.vv">;
defm VMADD_VX : VALU_OPMVX_MulAdd<0b101001, "vmadd.vx">;

defm VNMSUB_VV : VALU_OPMVV_MulAdd<0b101011, "vnmsub.vv">;
defm VNMSUB_VX : VALU_OPMVX_MulAdd<0b101011, "vnmsub.vx">;


// Vector Widening Integer Multiply-Add Instructions

defm VWMACCU_VV : VALU_OPMVV_MulAdd<0b111100, "vwmaccu.vv">;
defm VWMACCU_VX : VALU_OPMVX_MulAdd<0b111100, "vwmaccu.vx">;

defm VWMACC_VV : VALU_OPMVV_MulAdd<0b111101, "vwmacc.vv">;
defm VWMACC_VX : VALU_OPMVX_MulAdd<0b111101, "vwmacc.vx">;

defm VWMACCSU_VV : VALU_OPMVV_MulAdd<0b111110, "vwmaccsu.vv">;
defm VWMACCSU_VX : VALU_OPMVX_MulAdd<0b111110, "vwmaccsu.vx">;

defm VWMACCUS_VX : VALU_OPMVX_MulAdd<0b111111, "vwmaccus.vx">;


// Vector Quad-Widening Integer Multiply-Add Instructions
// TODO


// Vector Integer Merge Instructions

def VMERGE_VVM : VALU_OPIVV_m<0b010111, "vmerge.vvm">;
def VMERGE_VXM : VALU_OPIVX_m<0b010111, "vmerge.vxm">;
def VMERGE_VIM : VALU_OPIVI_m<0b010111, "vmerge.vim">;


// Vector Integer Move Instructions

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VMV_V_V : RVInstVA<0b010111, 0b000, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VLR:$vl),
               "vmv.v.v", "$vd, $vs1"> {
  bits<5> vs1;
  let vs2 = 0b00000;
  let Inst{19-15} = vs1;
}
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VMV_V_X : RVInstVA<0b010111, 0b100, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins GPR:$rs1, VLR:$vl),
               "vmv.v.x", "$vd, $rs1"> {
  bits<5> rs1;
  let vs2 = 0b00000;
  let Inst{19-15} = rs1;
}
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VMV_V_I : RVInstVA<0b010111, 0b011, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins simm5:$simm, VLR:$vl),
               "vmv.v.i", "$vd, $simm"> {
  bits<5> simm;
  let vs2 = 0b00000;
  let Inst{19-15} = simm;
}


// Vector Single-Width Saturating Add and Subtract Instructions

defm VSADDU_VV : VALU_OPIVV<0b100000, "vsaddu.vv">;
defm VSADDU_VX : VALU_OPIVX<0b100000, "vsaddu.vx">;
defm VSADDU_VI : VALU_OPIVI_signed<0b100000, "vsaddu.vi">;

defm VSADD_VV : VALU_OPIVV<0b100001, "vsadd.vv">;
defm VSADD_VX : VALU_OPIVX<0b100001, "vsadd.vx">;
defm VSADD_VI : VALU_OPIVI_signed<0b100001, "vsadd.vi">;

defm VSSUBU_VV : VALU_OPIVV<0b100010, "vssubu.vv">;
defm VSSUBU_VX : VALU_OPIVX<0b100010, "vssubu.vx">;

defm VSSUB_VV : VALU_OPIVV<0b100011, "vssub.vv">;
defm VSSUB_VX : VALU_OPIVX<0b100011, "vssub.vx">;


// Vector Single-Width Averaging Add and Subtract Instructions

defm VAADDU_VV : VALU_OPMVV<0b001000, "vaaddu.vv">;
defm VAADDU_VX : VALU_OPMVX<0b001000, "vaaddu.vx">;

defm VAADD_VV : VALU_OPMVV<0b001001, "vaadd.vv">;
defm VAADD_VX : VALU_OPMVX<0b001001, "vaadd.vx">;

defm VASUBU_VV : VALU_OPMVV<0b001010, "vasubu.vv">;
defm VASUBU_VX : VALU_OPMVX<0b001010, "vasubu.vx">;

defm VASUB_VV : VALU_OPMVV<0b001011, "vasub.vv">;
defm VASUB_VX : VALU_OPMVX<0b001011, "vasub.vx">;


// Vector Single-Width Fractional Multiply Instructions with Rounding and Saturation

defm VSMUL_VV : VALU_OPIVV<0b100111, "vsmul.vv">;
defm VSMUL_VX : VALU_OPIVX<0b100111, "vsmul.vx">;


// Vector Single-Width Scaling Shift Instructions

defm VSSRL_VV : VALU_OPIVV<0b101010, "vssrl.vv">;
defm VSSRL_VX : VALU_OPIVX<0b101010, "vssrl.vx">;
defm VSSRL_VI : VALU_OPIVI_unsigned<0b101010, "vssrl.vi">;

defm VSSRA_VV : VALU_OPIVV<0b101011, "vssra.vv">;
defm VSSRA_VX : VALU_OPIVX<0b101011, "vssra.vx">;
defm VSSRA_VI : VALU_OPIVI_unsigned<0b101011, "vssra.vi">;


// Vector Narrowing Fixed-Point Clip Instructions

defm VNCLIPU_WV : VALU_OPIVV<0b101110, "vnclipu.wv">;
defm VNCLIPU_WX : VALU_OPIVX<0b101110, "vnclipu.wx">;
defm VNCLIPU_WI : VALU_OPIVI_unsigned<0b101110, "vnclipu.wi">;

defm VNCLIP_WV : VALU_OPIVV<0b101111, "vnclip.wv">;
defm VNCLIP_WX : VALU_OPIVX<0b101111, "vnclip.wx">;
defm VNCLIP_WI : VALU_OPIVI_unsigned<0b101111, "vnclip.wi">;


// Vector Single-Width Floating-Point Add/Subtract Instructions

defm VFADD_VV : VALU_OPFVV<0b000000, "vfadd.vv">;
defm VFADD_VF : VALU_OPFVF<0b000000, "vfadd.vf">;

defm VFSUB_VV : VALU_OPFVV<0b000010, "vfsub.vv">;
defm VFSUB_VF : VALU_OPFVF<0b000010, "vfsub.vf">;
defm VFRSUB_VF : VALU_OPFVF<0b100111, "vfrsub.vf">;


// Vector Widening Floating-Point Add/Subtract Instructions

defm VFWADD_VV : VALU_OPFVV<0b110000, "vfwadd.vv">;
defm VFWADD_VF : VALU_OPFVF<0b110000, "vfwadd.vf">;
defm VFWSUB_VV : VALU_OPFVV<0b110010, "vfwsub.vv">;
defm VFWSUB_VF : VALU_OPFVF<0b110010, "vfwsub.vf">;

defm VFWADD_WV : VALU_OPFVV<0b110100, "vfwadd.wv">;
defm VFWADD_WF : VALU_OPFVF<0b110100, "vfwadd.wf">;
defm VFWSUB_WV : VALU_OPFVV<0b110110, "vfwsub.wv">;
defm VFWSUB_WF : VALU_OPFVF<0b110110, "vfwsub.wf">;


// Vector Single-Width Floating-Point Multiply/Divide Instructions

defm VFMUL_VV : VALU_OPFVV<0b100100, "vfmul.vv">;
defm VFMUL_VF : VALU_OPFVF<0b100100, "vfmul.vf">;

defm VFDIV_VV : VALU_OPFVV<0b100000, "vfdiv.vv">;
defm VFDIV_VF : VALU_OPFVF<0b100000, "vfdiv.vf">;
defm VFRDIV_VF : VALU_OPFVF<0b100001, "vfrdiv.vf">;


// Vector Widening Floating-Point Multiply Instructions

defm VFWMUL_VV : VALU_OPFVV<0b111000, "vfwmul.vv">;
defm VFWMUL_VF : VALU_OPFVF<0b111000, "vfwmul.vf">;


// Vector Single-Width Floating-Point Fused Multiply-Add Instructions

defm VFMACC_VV : VALU_OPFVV_MulAdd<0b101100, "vfmacc.vv">;
defm VFMACC_VF : VALU_OPFVF_MulAdd<0b101100, "vfmacc.vf">;

defm VFNMACC_VV : VALU_OPFVV_MulAdd<0b101101, "vfnmacc.vv">;
defm VFNMACC_VF : VALU_OPFVF_MulAdd<0b101101, "vfnmacc.vf">;

defm VFMSAC_VV : VALU_OPFVV_MulAdd<0b101110, "vfmsac.vv">;
defm VFMSAC_VF : VALU_OPFVF_MulAdd<0b101110, "vfmsac.vf">;

defm VFNMSAC_VV : VALU_OPFVV_MulAdd<0b101111, "vfnmsac.vv">;
defm VFNMSAC_VF : VALU_OPFVF_MulAdd<0b101111, "vfnmsac.vf">;

defm VFMADD_VV : VALU_OPFVV_MulAdd<0b101000, "vfmadd.vv">;
defm VFMADD_VF : VALU_OPFVF_MulAdd<0b101000, "vfmadd.vf">;

defm VFNMADD_VV : VALU_OPFVV_MulAdd<0b101001, "vfnmadd.vv">;
defm VFNMADD_VF : VALU_OPFVF_MulAdd<0b101001, "vfnmadd.vf">;

defm VFMSUB_VV : VALU_OPFVV_MulAdd<0b101010, "vfmsub.vv">;
defm VFMSUB_VF : VALU_OPFVF_MulAdd<0b101010, "vfmsub.vf">;

defm VFNMSUB_VV : VALU_OPFVV_MulAdd<0b101011, "vfnmsub.vv">;
defm VFNMSUB_VF : VALU_OPFVF_MulAdd<0b101011, "vfnmsub.vf">;


// Vector Widening Floating-Point Fused Multiply-Add Instructions

defm VFWMACC_VV : VALU_OPFVV_MulAdd<0b111100, "vfwmacc.vv">;
defm VFWMACC_VF : VALU_OPFVF_MulAdd<0b111100, "vfwmacc.vf">;

defm VFWNMACC_VV : VALU_OPFVV_MulAdd<0b111101, "vfwnmacc.vv">;
defm VFWNMACC_VF : VALU_OPFVF_MulAdd<0b111101, "vfwnmacc.vf">;

defm VFWMSAC_VV : VALU_OPFVV_MulAdd<0b111110, "vfwmsac.vv">;
defm VFWMSAC_VF : VALU_OPFVF_MulAdd<0b111110, "vfwmsac.vf">;

defm VFWNMSAC_VV : VALU_OPFVV_MulAdd<0b111111, "vfwnmsac.vv">;
defm VFWNMSAC_VF : VALU_OPFVF_MulAdd<0b111111, "vfwnmsac.vf">;


// Vector Floating-Point Square-Root Instruction

defm VFSQRT_V : VALU_OPFVV_VFUNARY1<0b00000, "vfsqrt.v">;


// Vector Floating-Point MIN/MAX Instructions

defm VFMIN_VV : VALU_OPFVV<0b000100, "vfmin.vv">;
defm VFMIN_VF : VALU_OPFVF<0b000100, "vfmin.vf">;

defm VFMAX_VV : VALU_OPFVV<0b000110, "vfmax.vv">;
defm VFMAX_VF : VALU_OPFVF<0b000110, "vfmax.vf">;


// Vector Floating-Point Sign-Injection Instructions

defm VFSGNJ_VV : VALU_OPFVV<0b001000, "vfsgnj.vv">;
defm VFSGNJ_VF : VALU_OPFVF<0b001000, "vfsgnj.vf">;

defm VFSGNJN_VV : VALU_OPFVV<0b001001, "vfsgnjn.vv">;
defm VFSGNJN_VF : VALU_OPFVF<0b001001, "vfsgnjn.vf">;

defm VFSGNJX_VV : VALU_OPFVV<0b001010, "vfsgnjx.vv">;
defm VFSGNJX_VF : VALU_OPFVF<0b001010, "vfsgnjx.vf">;


// Vector Floating-Point Compare Instructions

defm VMFEQ_VV : VALU_OPFVV<0b011000, "vmfeq.vv">;
defm VMFEQ_VF : VALU_OPFVF<0b011000, "vmfeq.vf">;

defm VMFNE_VV : VALU_OPFVV<0b011100, "vmfne.vv">;
defm VMFNE_VF : VALU_OPFVF<0b011100, "vmfne.vf">;

defm VMFLT_VV : VALU_OPFVV<0b011011, "vmflt.vv">;
defm VMFLT_VF : VALU_OPFVF<0b011011, "vmflt.vf">;

defm VMFLE_VV : VALU_OPFVV<0b011001, "vmfle.vv">;
defm VMFLE_VF : VALU_OPFVF<0b011001, "vmfle.vf">;

defm VMFGT_VF : VALU_OPFVF<0b011101, "vmfgt.vf">;
defm VMFGE_VF : VALU_OPFVF<0b011111, "vmfge.vf">;


// Vector Floating-Point Classify Instruction

defm VFCLASS_V : VALU_OPFVV_VFUNARY1<0b10000, "vfclass.v">;


// Vector Floating-Point Merge Instruction

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VFMERGE_VFM : RVInstVA<0b010111, 0b101, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins FPR32:$rs1, VR:$vs2, VLR:$vl, VRV0:$v0),
               "vfmerge.vfm", "$vd, $vs2, $rs1, $v0"> {
  bits<5> rs1;
  let Inst{19-15} = rs1;
}


// Vector Floating-Point Move Instruction

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VFMV_V_F : RVInstVA<0b010111, 0b101, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins FPR32:$rs1, VLR:$vl),
               "vfmv.v.f", "$vd, $rs1"> {
  bits<5> rs1;
  let vs2 = 0b00000;
  let Inst{19-15} = rs1;
}


// Single-Width Floating-Point/Integer Type-Convert Instructions

defm VFCVT_XU_F_V : VALU_OPFVV_VFUNARY0<0b00000, "vfcvt.xu.f.v">;
defm VFCVT_X_F_V : VALU_OPFVV_VFUNARY0<0b00001, "vfcvt.x.f.v">;
defm VFCVT_F_XU_V : VALU_OPFVV_VFUNARY0<0b00010, "vfcvt.f.xu.v">;
defm VFCVT_F_X_V : VALU_OPFVV_VFUNARY0<0b00011, "vfcvt.f.x.v">;


// Widening Floating-Point/Integer Type-Convert Instructions

defm VFWCVT_XU_F_V : VALU_OPFVV_VFUNARY0<0b01000, "vfwcvt.xu.f.v">;
defm VFWCVT_X_F_V : VALU_OPFVV_VFUNARY0<0b01001, "vfwcvt.x.f.v">;
defm VFWCVT_F_XU_V : VALU_OPFVV_VFUNARY0<0b01010, "vfwcvt.f.xu.v">;
defm VFWCVT_F_X_V : VALU_OPFVV_VFUNARY0<0b01011, "vfwcvt.f.x.v">;
defm VFWCVT_F_F_V : VALU_OPFVV_VFUNARY0<0b01100, "vfwcvt.f.f.v">;


// Narrowing Floating-Point/Integer Type-Convert Instructions

defm VFNCVT_XU_F_W : VALU_OPFVV_VFUNARY0<0b10000, "vfncvt.xu.f.w">;
defm VFNCVT_X_F_W : VALU_OPFVV_VFUNARY0<0b10001, "vfncvt.x.f.w">;
defm VFNCVT_F_XU_W : VALU_OPFVV_VFUNARY0<0b10010, "vfncvt.f.xu.w">;
defm VFNCVT_F_X_W : VALU_OPFVV_VFUNARY0<0b10011, "vfncvt.f.x.w">;
defm VFNCVT_F_F_W : VALU_OPFVV_VFUNARY0<0b10100, "vfncvt.f.f.w">;
defm VFNCVT_ROD_F_F_W : VALU_OPFVV_VFUNARY0<0b10101, "vfncvt.rod.f.f.w">;


// Vector Single-Width Integer Reduction Instructions

defm VREDSUM_VS : VALU_OPMVV<0b000000, "vredsum.vs">;
defm VREDMAXU_VS : VALU_OPMVV<0b000110, "vredmaxu.vs">;
defm VREDMAX_VS : VALU_OPMVV<0b000111, "vredmax.vs">;
defm VREDMINU_VS : VALU_OPMVV<0b000100, "vredminu.vs">;
defm VREDMIN_VS : VALU_OPMVV<0b000101, "vredmin.vs">;
defm VREDAND_VS : VALU_OPMVV<0b000001, "vredand.vs">;
defm VREDOR_VS : VALU_OPMVV<0b000010, "vredor.vs">;
defm VREDXOR_VS : VALU_OPMVV<0b000011, "vredxor.vs">;


// Vector Widening Integer Reduction Instructions

defm VWREDSUMU_VS : VALU_OPIVV<0b110000, "vwredsumu.vs">;
defm VWREDSUM_VS : VALU_OPIVV<0b110001, "vwredsum.vs">;


// Vector Single-Width Floating-Point Reduction Instructions

defm VFREDOSUM_VS : VALU_OPFVV<0b000011, "vfredosum.vs">;
defm VFREDSUM_VS : VALU_OPFVV<0b000001, "vfredsum.vs">;
defm VFREDMAX_VS : VALU_OPFVV<0b000111, "vfredmax.vs">;
defm VFREDMIN_VS : VALU_OPFVV<0b000101, "vfredmin.vs">;


// Vector Widening Floating-Point Reduction Instructions

defm VFWREDOSUM_VS : VALU_OPFVV<0b110011, "vfwredosum.vs">;
defm VFWREDSUM_VS : VALU_OPFVV<0b110001, "vfwredsum.vs">;


// Vector Mask-Register Logical Instructions

def VMAND_MM : VALU_OPMVV_um<0b011001, "vmand.mm">;
def VMNAND_MM : VALU_OPMVV_um<0b011101, "vmnand.mm">;
def VMANDNOT_MM : VALU_OPMVV_um<0b011000, "vmandnot.mm">;
def VMXOR_MM : VALU_OPMVV_um<0b011011, "vmxor.mm">;
def VMOR_MM : VALU_OPMVV_um<0b011010, "vmor.mm">;
def VMNOR_MM : VALU_OPMVV_um<0b011110, "vmnor.mm">;
def VMORNOT_MM : VALU_OPMVV_um<0b011100, "vmornot.mm">;
def VMXNOR_MM : VALU_OPMVV_um<0b011111, "vmxnor.mm">;


// Vector mask population count Instruction

defm VPOPC_M : VALU_OPMVV_VWXUNARY0<0b10000, "vpopc.m">;


// find-first-set mask bit Instruction

defm VFIRST_M : VALU_OPMVV_VWXUNARY0<0b10001, "vfirst.m">;


// set-before-first mask bit Instruction

defm VMSBF_M : VALU_OPMVV_VMUNARY0<0b00001, "vmsbf.m">;


// set-including-first mask bit Instruction

defm VMSIF_M : VALU_OPMVV_VMUNARY0<0b00011, "vmsif.m">;


// set-only-first mask bit Instruction

defm VMSOF_M : VALU_OPMVV_VMUNARY0<0b00010, "vmsof.m">;


// Vector Iota Instruction

defm VIOTA_M : VALU_OPMVV_VMUNARY0<0b10000, "viota.m">;


// Vector Element Index Instruction

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VID_V_m : RVInstVA<0b010100, 0b010, RVV_Masked, OPC_OP_V,
               (outs VR:$vd), (ins VLR:$vl, VMR:$vm), "vid.v", "$vd, $vm"> {
  bits<5> vs1;
  let vs1 = 0b10001;
  let vs2 = 0b00000;
  let Inst{19-15} = vs1;
}
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VID_V_um : RVInstVA<0b010100, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VLR:$vl), "vid.v", "$vd"> {
  bits<5> vs1;
  let vs1 = 0b10001;
  let vs2 = 0b00000;
  let Inst{19-15} = vs1;
}


// Integer Scalar Move Instruction

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VMV_X_S : RVInstVA<0b010000, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs GPR:$rd), (ins VR:$vs2, VLR:$vl),
               "vmv.x.s", "$rd, $vs2"> {
  bits<5> vs1;
  let vs1 = 0b00000;
  let Inst{19-15} = vs1;
}
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VMV_S_X : RVInstVA<0b010000, 0b110, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins GPR:$rs1, VLR:$vl),
               "vmv.s.x", "$vd, $rs1"> {
  bits<5> rs1;
  let vs2 = 0b00000;
  let Inst{19-15} = rs1;
}


// Floating-Point Scalar Move Instructions

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VFMV_F_S : RVInstVA<0b010000, 0b001, RVV_Unmasked, OPC_OP_V,
               (outs FPR32:$rd), (ins VR:$vs2, VLR:$vl),
               "vfmv.f.s", "$rd, $vs2"> {
  bits<5> vs1;
  let vs1 = 0b00000;
  let Inst{19-15} = vs1;
}
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VFMV_S_F : RVInstVA<0b010000, 0b101, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins FPR32:$rs1, VLR:$vl),
               "vfmv.s.f", "$vd, $rs1"> {
  bits<5> rs1;
  let vs2 = 0b00000;
  let Inst{19-15} = rs1;
}


// Vector Slide Instructions

defm VSLIDEUP_VX : VALU_OPIVX<0b001110, "vslideup.vx">;
defm VSLIDEUP_VI : VALU_OPIVI_unsigned<0b001110, "vslideup.vi">;

defm VSLIDEDOWN_VX : VALU_OPIVX<0b001111, "vslidedown.vx">;
defm VSLIDEDOWN_VI : VALU_OPIVI_unsigned<0b001111, "vslidedown.vi">;

defm VSLIDE1UP_VX : VALU_OPMVX<0b001110, "vslide1up.vx">;

defm VSLIDE1DOWN_VX : VALU_OPMVX<0b001111, "vslide1down.vx">;


// Vector Register Gather Instructions

defm VRGATHER_VV : VALU_OPIVV<0b001100, "vrgather.vv">;
defm VRGATHER_VX : VALU_OPIVX<0b001100, "vrgather.vx">;
defm VRGATHER_VI : VALU_OPIVI_unsigned<0b001100, "vrgather.vi">;


// Vector Compress Instruction

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VCOMPRESS_VM : RVInstVA<0b010111, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VLR:$vl),
               "vcompress.vm", "$vd, $vs2, $vs1"> {
  bits<5> vs1;
  let Inst{19-15} = vs1;
}


// Whole Vector Register Move
// TODO


// Vector Integer Dot-Product Instructions

defm VDOTU_VV : VALU_OPIVV<0b111000, "vdotu.vv">;
defm VDOT_VV : VALU_OPIVV<0b111001, "vdot.vv">;


// Vector Floating-Point Dot-Product Instruction

defm VFDOT_VV : VALU_OPFVV<0b111001, "vfdot.vv">;


} // Predicates = [HasStdExtV]

//===----------------------------------------------------------------------===//
// Assembler Pseudo Instructions
//===----------------------------------------------------------------------===//

let EmitPriority = 0 in {


def : InstAlias<"vlb.v $vd, (${rs1})",
                (VLB_V_um  VR:$vd, GPR:$rs1, VL, 0)>;
def : InstAlias<"vlb.v $vd, (${rs1}), $vm",
                (VLB_V_m  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
def : InstAlias<"vlh.v $vd, (${rs1})",
                (VLH_V_um  VR:$vd, GPR:$rs1, VL, 0)>;
def : InstAlias<"vlh.v $vd, (${rs1}), $vm",
                (VLH_V_m  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
def : InstAlias<"vlw.v $vd, (${rs1})",
                (VLW_V_um  VR:$vd, GPR:$rs1, VL, 0)>;
def : InstAlias<"vlw.v $vd, (${rs1}), $vm",
                (VLW_V_m  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
def : InstAlias<"vlbu.v $vd, (${rs1})",
                (VLBU_V_um  VR:$vd, GPR:$rs1, VL, 0)>;
def : InstAlias<"vlbu.v $vd, (${rs1}), $vm",
                (VLBU_V_m  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
def : InstAlias<"vlhu.v $vd, (${rs1})",
                (VLHU_V_um  VR:$vd, GPR:$rs1, VL, 0)>;
def : InstAlias<"vlhu.v $vd, (${rs1}), $vm",
                (VLHU_V_m  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
def : InstAlias<"vlwu.v $vd, (${rs1})",
                (VLWU_V_um  VR:$vd, GPR:$rs1, VL, 0)>;
def : InstAlias<"vlwu.v $vd, (${rs1}), $vm",
                (VLWU_V_m  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
def : InstAlias<"vle.v $vd, (${rs1})",
                (VLE_V_um  VR:$vd, GPR:$rs1, VL, 0)>;
def : InstAlias<"vle.v $vd, (${rs1}), $vm",
                (VLE_V_m  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;

def : InstAlias<"vsb.v $vs3, (${rs1})",
                (VSB_V_um  VR:$vs3, GPR:$rs1, VL, 0)>;
def : InstAlias<"vsb.v $vs3, (${rs1}), $vm",
                (VSB_V_m  VR:$vs3, GPR:$rs1, VL, 0, VMR:$vm)>;
def : InstAlias<"vsh.v $vs3, (${rs1})",
                (VSH_V_um  VR:$vs3, GPR:$rs1, VL, 0)>;
def : InstAlias<"vsh.v $vs3, (${rs1}), $vm",
                (VSH_V_m  VR:$vs3, GPR:$rs1, VL, 0, VMR:$vm)>;
def : InstAlias<"vsw.v $vs3, (${rs1})",
                (VSW_V_um  VR:$vs3, GPR:$rs1, VL, 0)>;
def : InstAlias<"vsw.v $vs3, (${rs1}), $vm",
                (VSW_V_m  VR:$vs3, GPR:$rs1, VL, 0, VMR:$vm)>;
def : InstAlias<"vse.v $vs3, (${rs1})",
                (VSE_V_um  VR:$vs3, GPR:$rs1, VL, 0)>;
def : InstAlias<"vse.v $vs3, (${rs1}), $vm",
                (VSE_V_m  VR:$vs3, GPR:$rs1, VL, 0, VMR:$vm)>;


def : InstAlias<"vlsb.v $vd, (${rs1}), $rs2",
                (VLSB_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0)>;
def : InstAlias<"vlsb.v $vd, (${rs1}), $rs2, $vm",
                (VLSB_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vlsh.v $vd, (${rs1}), $rs2",
                (VLSH_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0)>;
def : InstAlias<"vlsh.v $vd, (${rs1}), $rs2, $vm",
                (VLSH_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vlsw.v $vd, (${rs1}), $rs2",
                (VLSW_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0)>;
def : InstAlias<"vlsw.v $vd, (${rs1}), $rs2, $vm",
                (VLSW_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vlsbu.v $vd, (${rs1}), $rs2",
                (VLSBU_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0)>;
def : InstAlias<"vlsbu.v $vd, (${rs1}), $rs2, $vm",
                (VLSBU_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vlshu.v $vd, (${rs1}), $rs2",
                (VLSHU_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0)>;
def : InstAlias<"vlshu.v $vd, (${rs1}), $rs2, $vm",
                (VLSHU_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vlswu.v $vd, (${rs1}), $rs2",
                (VLSWU_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0)>;
def : InstAlias<"vlswu.v $vd, (${rs1}), $rs2, $vm",
                (VLSWU_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vlse.v $vd, (${rs1}), $rs2",
                (VLSE_V_um  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0)>;
def : InstAlias<"vlse.v $vd, (${rs1}), $rs2, $vm",
                (VLSE_V_m  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;

def : InstAlias<"vssb.v $vs3, (${rs1}), $rs2",
                (VSSB_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0)>;
def : InstAlias<"vssb.v $vs3, (${rs1}), $rs2, $vm",
                (VSSB_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vssh.v $vs3, (${rs1}), $rs2",
                (VSSH_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0)>;
def : InstAlias<"vssh.v $vs3, (${rs1}), $rs2, $vm",
                (VSSH_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vssw.v $vs3, (${rs1}), $rs2",
                (VSSW_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0)>;
def : InstAlias<"vssw.v $vs3, (${rs1}), $rs2, $vm",
                (VSSW_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vsse.v $vs3, (${rs1}), $rs2",
                (VSSE_V_um  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0)>;
def : InstAlias<"vsse.v $vs3, (${rs1}), $rs2, $vm",
                (VSSE_V_m  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;


def : InstAlias<"vlxb.v $vd, (${rs1}), $vs2",
                (VLXB_V_um  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0)>;
def : InstAlias<"vlxb.v $vd, (${rs1}), $vs2, $vm",
                (VLXB_V_m  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vlxh.v $vd, (${rs1}), $vs2",
                (VLXH_V_um  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0)>;
def : InstAlias<"vlxh.v $vd, (${rs1}), $vs2, $vm",
                (VLXH_V_m  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vlxw.v $vd, (${rs1}), $vs2",
                (VLXW_V_um  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0)>;
def : InstAlias<"vlxw.v $vd, (${rs1}), $vs2, $vm",
                (VLXW_V_m  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vlxbu.v $vd, (${rs1}), $vs2",
                (VLXBU_V_um  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0)>;
def : InstAlias<"vlxbu.v $vd, (${rs1}), $vs2, $vm",
                (VLXBU_V_m  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vlxhu.v $vd, (${rs1}), $vs2",
                (VLXHU_V_um  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0)>;
def : InstAlias<"vlxhu.v $vd, (${rs1}), $vs2, $vm",
                (VLXHU_V_m  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vlxwu.v $vd, (${rs1}), $vs2",
                (VLXWU_V_um  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0)>;
def : InstAlias<"vlxwu.v $vd, (${rs1}), $vs2, $vm",
                (VLXWU_V_m  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vlxe.v $vd, (${rs1}), $vs2",
                (VLXE_V_um  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0)>;
def : InstAlias<"vlxe.v $vd, (${rs1}), $vs2, $vm",
                (VLXE_V_m  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;

def : InstAlias<"vsxb.v $vs3, (${rs1}), $vs2",
                (VSXB_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0)>;
def : InstAlias<"vsxb.v $vs3, (${rs1}), $vs2, $vm",
                (VSXB_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vsxh.v $vs3, (${rs1}), $vs2",
                (VSXH_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0)>;
def : InstAlias<"vsxh.v $vs3, (${rs1}), $vs2, $vm",
                (VSXH_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vsxw.v $vs3, (${rs1}), $vs2",
                (VSXW_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0)>;
def : InstAlias<"vsxw.v $vs3, (${rs1}), $vs2, $vm",
                (VSXW_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vsxe.v $vs3, (${rs1}), $vs2",
                (VSXE_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0)>;
def : InstAlias<"vsxe.v $vs3, (${rs1}), $vs2, $vm",
                (VSXE_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vsuxb.v $vs3, (${rs1}), $vs2",
                (VSUXB_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0)>;
def : InstAlias<"vsuxb.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXB_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vsuxh.v $vs3, (${rs1}), $vs2",
                (VSUXH_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0)>;
def : InstAlias<"vsuxh.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXH_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vsuxw.v $vs3, (${rs1}), $vs2",
                (VSUXW_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0)>;
def : InstAlias<"vsuxw.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXW_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
def : InstAlias<"vsuxe.v $vs3, (${rs1}), $vs2",
                (VSUXE_V_um  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0)>;
def : InstAlias<"vsuxe.v $vs3, (${rs1}), $vs2, $vm",
                (VSUXE_V_m  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;


def : InstAlias<"vlbff.v $vd, (${rs1})",
                (VLBFF_V_um  VR:$vd, GPR:$rs1, VL, 0)>;
def : InstAlias<"vlbff.v $vd, (${rs1}), $vm",
                (VLBFF_V_m  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
def : InstAlias<"vlhff.v $vd, (${rs1})",
                (VLHFF_V_um  VR:$vd, GPR:$rs1, VL, 0)>;
def : InstAlias<"vlhff.v $vd, (${rs1}), $vm",
                (VLHFF_V_m  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
def : InstAlias<"vlwff.v $vd, (${rs1})",
                (VLWFF_V_um  VR:$vd, GPR:$rs1, VL, 0)>;
def : InstAlias<"vlwff.v $vd, (${rs1}), $vm",
                (VLWFF_V_m  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
def : InstAlias<"vlbuff.v $vd, (${rs1})",
                (VLBUFF_V_um  VR:$vd, GPR:$rs1, VL, 0)>;
def : InstAlias<"vlbuff.v $vd, (${rs1}), $vm",
                (VLBUFF_V_m  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
def : InstAlias<"vlhuff.v $vd, (${rs1})",
                (VLHUFF_V_um  VR:$vd, GPR:$rs1, VL, 0)>;
def : InstAlias<"vlhuff.v $vd, (${rs1}), $vm",
                (VLHUFF_V_m  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
def : InstAlias<"vlwuff.v $vd, (${rs1})",
                (VLWUFF_V_um  VR:$vd, GPR:$rs1, VL, 0)>;
def : InstAlias<"vlwuff.v $vd, (${rs1}), $vm",
                (VLWUFF_V_m  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
def : InstAlias<"vleff.v $vd, (${rs1})",
                (VLEFF_V_um  VR:$vd, GPR:$rs1, VL, 0)>;
def : InstAlias<"vleff.v $vd, (${rs1}), $vm",
                (VLEFF_V_m  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;


foreach nf = 2-8 in {

  def : InstAlias<"vlseg"#nf#"b.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"B_V_um")
                  VR:$vd, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vlseg"#nf#"b.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"B_V_m")
                  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"h.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"H_V_um")
                  VR:$vd, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vlseg"#nf#"h.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"H_V_m")
                  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"w.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"W_V_um")
                  VR:$vd, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vlseg"#nf#"w.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"W_V_m")
                  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"bu.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"BU_V_um")
                  VR:$vd, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vlseg"#nf#"bu.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"BU_V_m")
                  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"hu.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"HU_V_um")
                  VR:$vd, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vlseg"#nf#"hu.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"HU_V_m")
                  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"wu.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"WU_V_um")
                  VR:$vd, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vlseg"#nf#"wu.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"WU_V_m")
                  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"e.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E_V_um")
                  VR:$vd, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vlseg"#nf#"e.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"E_V_m")
                  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;

  def : InstAlias<"vsseg"#nf#"b.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"B_V_um")
                  VR:$vs3, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vsseg"#nf#"b.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"B_V_m")
                  VR:$vs3, GPR:$rs1, VL, 0, VMR:$vm)>;
  def : InstAlias<"vsseg"#nf#"h.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"H_V_um")
                  VR:$vs3, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vsseg"#nf#"h.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"H_V_m")
                  VR:$vs3, GPR:$rs1, VL, 0, VMR:$vm)>;
  def : InstAlias<"vsseg"#nf#"w.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"W_V_um")
                  VR:$vs3, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vsseg"#nf#"w.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"W_V_m")
                  VR:$vs3, GPR:$rs1, VL, 0, VMR:$vm)>;
  def : InstAlias<"vsseg"#nf#"e.v $vs3, (${rs1})",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E_V_um")
                  VR:$vs3, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vsseg"#nf#"e.v $vs3, (${rs1}), $vm",
                  (!cast<RVInstVStore>("VSSEG"#nf#"E_V_m")
                  VR:$vs3, GPR:$rs1, VL, 0, VMR:$vm)>;


  def : InstAlias<"vlsseg"#nf#"b.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"B_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0)>;
  def : InstAlias<"vlsseg"#nf#"b.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"B_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"h.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"H_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0)>;
  def : InstAlias<"vlsseg"#nf#"h.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"H_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"w.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"W_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0)>;
  def : InstAlias<"vlsseg"#nf#"w.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"W_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"bu.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"BU_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0)>;
  def : InstAlias<"vlsseg"#nf#"bu.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"BU_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"hu.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"HU_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0)>;
  def : InstAlias<"vlsseg"#nf#"hu.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"HU_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"wu.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"WU_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0)>;
  def : InstAlias<"vlsseg"#nf#"wu.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"WU_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlsseg"#nf#"e.v $vd, (${rs1}), $rs2",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E_V_um")
                  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0)>;
  def : InstAlias<"vlsseg"#nf#"e.v $vd, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVLoad>("VLSSEG"#nf#"E_V_m")
                  VR:$vd, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;

  def : InstAlias<"vssseg"#nf#"b.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"B_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0)>;
  def : InstAlias<"vssseg"#nf#"b.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"B_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vssseg"#nf#"h.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"H_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0)>;
  def : InstAlias<"vssseg"#nf#"h.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"H_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vssseg"#nf#"w.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"W_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0)>;
  def : InstAlias<"vssseg"#nf#"w.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"W_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vssseg"#nf#"e.v $vs3, (${rs1}), $rs2",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E_V_um")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0)>;
  def : InstAlias<"vssseg"#nf#"e.v $vs3, (${rs1}), $rs2, $vm",
                  (!cast<RVInstVStore>("VSSSEG"#nf#"E_V_m")
                  VR:$vs3, GPR:$rs1, GPR:$rs2, VL, 0, VMR:$vm)>;


  def : InstAlias<"vlxseg"#nf#"b.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"B_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0)>;
  def : InstAlias<"vlxseg"#nf#"b.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"B_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"h.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"H_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0)>;
  def : InstAlias<"vlxseg"#nf#"h.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"H_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"w.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"W_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0)>;
  def : InstAlias<"vlxseg"#nf#"w.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"W_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"bu.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"BU_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0)>;
  def : InstAlias<"vlxseg"#nf#"bu.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"BU_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"hu.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"HU_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0)>;
  def : InstAlias<"vlxseg"#nf#"hu.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"HU_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"wu.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"WU_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0)>;
  def : InstAlias<"vlxseg"#nf#"wu.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"WU_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlxseg"#nf#"e.v $vd, (${rs1}), $vs2",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"E_V_um")
                  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0)>;
  def : InstAlias<"vlxseg"#nf#"e.v $vd, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVLoad>("VLXSEG"#nf#"E_V_m")
                  VR:$vd, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;

  def : InstAlias<"vsxseg"#nf#"b.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"B_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0)>;
  def : InstAlias<"vsxseg"#nf#"b.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"B_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vsxseg"#nf#"h.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"H_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0)>;
  def : InstAlias<"vsxseg"#nf#"h.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"H_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vsxseg"#nf#"w.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"W_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0)>;
  def : InstAlias<"vsxseg"#nf#"w.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"W_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;
  def : InstAlias<"vsxseg"#nf#"e.v $vs3, (${rs1}), $vs2",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"E_V_um")
                  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0)>;
  def : InstAlias<"vsxseg"#nf#"e.v $vs3, (${rs1}), $vs2, $vm",
                  (!cast<RVInstVStore>("VSXSEG"#nf#"E_V_m")
                  VR:$vs3, GPR:$rs1, VR:$vs2, VL, 0, VMR:$vm)>;


  def : InstAlias<"vlseg"#nf#"bff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"BFF_V_um")
                  VR:$vd, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vlseg"#nf#"bff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"BFF_V_m")
                  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"hff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"HFF_V_um")
                  VR:$vd, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vlseg"#nf#"hff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"HFF_V_m")
                  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"wff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"WFF_V_um")
                  VR:$vd, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vlseg"#nf#"wff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"WFF_V_m")
                  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"buff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"BUFF_V_um")
                  VR:$vd, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vlseg"#nf#"buff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"BUFF_V_m")
                  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"huff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"HUFF_V_um")
                  VR:$vd, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vlseg"#nf#"huff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"HUFF_V_m")
                  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"wuff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"WUFF_V_um")
                  VR:$vd, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vlseg"#nf#"wuff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"WUFF_V_m")
                  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
  def : InstAlias<"vlseg"#nf#"eff.v $vd, (${rs1})",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"EFF_V_um")
                  VR:$vd, GPR:$rs1, VL, 0)>;
  def : InstAlias<"vlseg"#nf#"eff.v $vd, (${rs1}), $vm",
                  (!cast<RVInstVLoad>("VLSEG"#nf#"EFF_V_m")
                  VR:$vd, GPR:$rs1, VL, 0, VMR:$vm)>;
}


def : InstAlias<"vwcvt.x.x.v $vd, $vs2",
                (VWADD_VX_um  VR:$vd, VR:$vs2, X0, VL)>;
def : InstAlias<"vwcvt.x.x.v $vd, $vs2, $vm",
                (VWADD_VX_m  VR:$vd, VR:$vs2, X0, VL, VMR:$vm)>;
def : InstAlias<"vwcvtu.x.x.v $vd, $vs2",
                (VWADDU_VX_um  VR:$vd, VR:$vs2, X0, VL)>;
def : InstAlias<"vwcvtu.x.x.v $vd, $vs2, $vm",
                (VWADDU_VX_m  VR:$vd, VR:$vs2, X0, VL, VMR:$vm)>;


def : InstAlias<"vnot.v $vd, $vs2",
                (VXOR_VI_um  VR:$vd, VR:$vs2, -1, VL)>;
def : InstAlias<"vnot.v $vd, $vs2, $vm",
                (VXOR_VI_m  VR:$vd, VR:$vs2, -1, VL, VMR:$vm)>;


def : InstAlias<"vmsgt.vv $vd, $vs2, $vs1",
                (VMSLT_VV_um  VR:$vd, VR:$vs1, VR:$vs2, VL)>;
def : InstAlias<"vmsgt.vv $vd, $vs2, $vs1, $vm",
                (VMSLT_VV_m  VR:$vd, VR:$vs1, VR:$vs2, VL, VMR:$vm)>;
def : InstAlias<"vmsgtu.vv $vd, $vs2, $vs1",
                (VMSLTU_VV_um  VR:$vd, VR:$vs1, VR:$vs2, VL)>;
def : InstAlias<"vmsgtu.vv $vd, $vs2, $vs1, $vm",
                (VMSLTU_VV_m  VR:$vd, VR:$vs1, VR:$vs2, VL, VMR:$vm)>;
def : InstAlias<"vmsge.vv $vd, $vs2, $vs1",
                (VMSLE_VV_um  VR:$vd, VR:$vs1, VR:$vs2, VL)>;
def : InstAlias<"vmsge.vv $vd, $vs2, $vs1, $vm",
                (VMSLE_VV_m  VR:$vd, VR:$vs1, VR:$vs2, VL, VMR:$vm)>;
def : InstAlias<"vmsgeu.vv $vd, $vs2, $vs1",
                (VMSLEU_VV_um  VR:$vd, VR:$vs1, VR:$vs2, VL)>;
def : InstAlias<"vmsgeu.vv $vd, $vs2, $vs1, $vm",
                (VMSLEU_VV_m  VR:$vd, VR:$vs1, VR:$vs2, VL, VMR:$vm)>;

// TODO ： vmslt{u}.vi, vmsge{u}.vi, vmsge{u}.vx


def : InstAlias<"vmfgt.vv $vd, $vs2, $vs1",
                (VMFLT_VV_um  VR:$vd, VR:$vs1, VR:$vs2, VL)>;
def : InstAlias<"vmfgt.vv $vd, $vs2, $vs1, $vm",
                (VMFLT_VV_m  VR:$vd, VR:$vs1, VR:$vs2, VL, VMR:$vm)>;
def : InstAlias<"vmfge.vv $vd, $vs2, $vs1",
                (VMFLE_VV_um  VR:$vd, VR:$vs1, VR:$vs2, VL)>;
def : InstAlias<"vmfge.vv $vd, $vs2, $vs1, $vm",
                (VMFLE_VV_m  VR:$vd, VR:$vs1, VR:$vs2, VL, VMR:$vm)>;


def : InstAlias<"vmcpy.m $vd, $vs2",
                (VMAND_MM  VR:$vd, VR:$vs2, VR:$vs2, VL)>;
def : InstAlias<"vmclr.m $vd",
                (VMXOR_MM  VR:$vd, VR:$vd, VR:$vd, VL)>;
def : InstAlias<"vmset.m $vd",
                (VMXNOR_MM  VR:$vd, VR:$vd, VR:$vd, VL)>;
def : InstAlias<"vmnot.m $vd, $vs2",
                (VMNAND_MM  VR:$vd, VR:$vs2, VR:$vs2, VL)>;

}

//===----------------------------------------------------------------------===//
// Pseudo-instructions and codegen patterns
//===----------------------------------------------------------------------===//

let Predicates = [HasStdExtV] in {

let hasSideEffects = 1, mayLoad = 0, mayStore = 0,
    isCodeGenOnly = 1, isAsmParserOnly = 0 in {
  def PseudoCSRR_VL : Pseudo<(outs GPR:$rd), (ins VLR:$vl), []>,
                      PseudoInstExpansion<(CSRRS GPR:$rd, 0xCC0, X0)>;
}


class PatVrVr<SDPatternOperator OpNode, RVInst Inst>
    : Pat<(OpNode VR:$rs1, VR:$rs2, VLR:$vl), (Inst VR:$rs1, VR:$rs2, VLR:$vl)>;

class PatVrIm<SDPatternOperator OpNode, RVInst Inst>
    : Pat<(OpNode VR:$rs1, (RISCVBROADCAST simm5:$imm), VLR:$vl), (Inst VR:$rs1, simm5:$imm, VLR:$vl)>; 

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
def : Pat<(int_riscv_vlw GPR:$rs1, VLR:$vl),
          (VLW_V_um GPR:$rs1, VLR:$vl, 0)>;

def : Pat<(int_riscv_vsw VR:$vs3, GPR:$rs1, VLR:$vl),
          (VSW_V_um VR:$vs3, GPR:$rs1, VLR:$vl, 0)>;

def : Pat<(RISCVSETVL GPR:$rs1, GPR:$rs2), (VSETVL GPR:$rs1, GPR:$rs2)>;

} // Predicates = [HasStdExtV]
