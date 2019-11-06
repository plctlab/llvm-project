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
class VLoad_UnitStride<bits<3> nf, bits<3> mop, bits<3> width, string opcodestr>
    : RVInstVLoad<nf, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, VLR:$vl, simm5:$imm5),
                  opcodestr, "$vd, ${imm5}(${rs1})">
{
  let Inst{24-20} = 0b00000;
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
class VLoad_UnitStrideFF<bits<3> nf, bits<3> mop, bits<3> width, string opcodestr>
    : RVInstVLoad<nf, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, VLR:$vl, simm5:$imm5),
                  opcodestr, "$vd, ${imm5}(${rs1})">
{
  let Inst{24-20} = 0b10000;
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
class VStore_UnitStride<bits<3> nf, bits<3> mop, bits<3> width, string opcodestr>
    : RVInstVStore<nf, mop, width, RVV_Unmasked, OPC_STORE_FP,
                   (outs), (ins GPR:$rs1, VR:$vs3, VLR:$vl, simm5:$imm5),
                   opcodestr, "$vs3, ${imm5}(${rs1})">
{
  let Inst{24-20} = 0b00000;
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
class VLoad_Strided<bits<3> nf, bits<3> mop, bits<3> width, string opcodestr>
    : RVInstVLoad<nf, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, GPR:$rs2, VLR:$vl, simm5:$imm5),
                  opcodestr, "$vd, ${imm5}(${rs1}), $rs2">
{
  bits<5> rs2;  

  let Inst{24-20} = rs2;
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
class VStore_Strided<bits<3> nf, bits<3> mop, bits<3> width, string opcodestr>
    : RVInstVStore<nf, mop, width, RVV_Unmasked, OPC_STORE_FP,
                   (outs), (ins GPR:$rs1, GPR:$rs2, VR:$vs3, VLR:$vl, simm5:$imm5),
                   opcodestr, "$vs3, ${imm5}(${rs1}), $rs2">
{
  bits<5> rs2;  

  let Inst{24-20} = rs2;
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
class VLoad_Indexed<bits<3> nf, bits<3> mop, bits<3> width, string opcodestr>
    : RVInstVLoad<nf, mop, width, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, VR:$vs2, VLR:$vl, simm5:$imm5),
                  opcodestr, "$vd, ${imm5}(${rs1}), $vs2">
{
  bits<5> vs2;

  let Inst{24-20} = vs2;
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
class VStore_Indexed<bits<3> nf, bits<3> mop, bits<3> width, string opcodestr>
    : RVInstVStore<nf, mop, width, RVV_Unmasked, OPC_STORE_FP,
                   (outs), (ins GPR:$rs1, VR:$vs2, VR:$vs3, VLR:$vl, simm5:$imm5),
                   opcodestr, "$vs3, ${imm5}(${rs1}), $vs2">
{
  bits<5> vs2;

  let Inst{24-20} = vs2;
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_AMO<bits<5> amoop, bits<1> wd, bits<3> width, string opcodestr>
    : RVInstVAMO<amoop, wd, width, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vs3), (ins GPR:$rs1, VR:$vs2, VLR:$vl),
               opcodestr, "$vs3, $vs1, $vs2">
{
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVV<bits<6> funct6, string opcodestr>
    : RVInstVA<funct6, 0b000, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VLR:$vl),
               opcodestr, "$vd, $vs2, $vs1">
{
  bits<5> vs1;

  let Inst{19-15} = vs1;
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPFVV<bits<6> funct6, string opcodestr>
    : RVInstVA<funct6, 0b001, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VLR:$vl),
               opcodestr, "$vd, $vs2, $vs1">
{
  bits<5> vs1;

  let Inst{19-15} = vs1;
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPMVV<bits<6> funct6, string opcodestr>
    : RVInstVA<funct6, 0b010, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VLR:$vl),
               opcodestr, "$vd, $vs2, $vs1">
{
  bits<5> vs1;

  let Inst{19-15} = vs1;
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVI<bits<6> funct6, string opcodestr>
    : RVInstVA<funct6, 0b011, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, simm5:$imm5, VLR:$vl),
               opcodestr, "$vd, $vs2, $imm5">
{
  bits<5> simm5;

  let Inst{19-15} = simm5;
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVX<bits<6> funct6, string opcodestr>
    : RVInstVA<funct6, 0b100, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VLR:$vl),
               opcodestr, "$vd, $vs2, $rs1">
{
  bits<5> rs1;

  let Inst{19-15} = rs1;
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPFVF<bits<6> funct6, string opcodestr>
    : RVInstVA<funct6, 0b101, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, FPR32:$rs1, VLR:$vl),
               opcodestr, "$vd, $vs2, $rs1">
{
  bits<5> rs1;

  let Inst{19-15} = rs1;
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPMVX<bits<6> funct6, string opcodestr>
    : RVInstVA<funct6, 0b110, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VLR:$vl),
               opcodestr, "$vd, $vs2, $rs1">
{
  bits<5> rs1;

  let Inst{19-15} = rs1;
  //let Uses = [VCFG];
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
                      "vsetvli", "$rd, $rs1, $vtypei">
{
  bits<11> vtypei;

  let Inst{30-20} = vtypei;

  //let Uses = [VCFG];
}
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VSETVL: RVInstVSet<0b1, OPC_OP_V, 
                      (outs VLR:$vl, GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
                      "vsetvl", "$rd, $rs1, $rs2">
{
  bits<5> rs2;

  let Inst{30-25} = 0b000000;
  let Inst{24-20} = rs2;
  
  //let Uses = [VCFG];
}


// Vector Unit-Stride Instructions

def VLB_V : VLoad_UnitStride<0b000, 0b100, 0b000, "vlb.v">;
def VLH_V : VLoad_UnitStride<0b000, 0b100, 0b101, "vlh.v">;
def VLW_V : VLoad_UnitStride<0b000, 0b100, 0b110, "vlw.v">;
def VLBU_V : VLoad_UnitStride<0b000, 0b000, 0b000, "vlbu.v">;
def VLHU_V : VLoad_UnitStride<0b000, 0b000, 0b101, "vlhu.v">;
def VLWU_V : VLoad_UnitStride<0b000, 0b000, 0b110, "vlwu.v">;
def VLE_V : VLoad_UnitStride<0b000, 0b000, 0b111, "vle.v">;

def VSB_V : VStore_UnitStride<0b000, 0b000, 0b000, "vsb.v">;
def VSH_V : VStore_UnitStride<0b000, 0b000, 0b101, "vsh.v">;
def VSW_V : VStore_UnitStride<0b000, 0b000, 0b110, "vsw.v">;
def VSE_V : VStore_UnitStride<0b000, 0b000, 0b111, "vse.v">;


// Vector Strided Instructions

def VLSB_V : VLoad_Strided<0b000, 0b110, 0b000, "vlsb.v">;
def VLSH_V : VLoad_Strided<0b000, 0b110, 0b101, "vlsh.v">;
def VLSW_V : VLoad_Strided<0b000, 0b110, 0b110, "vlsw.v">;
def VLSBU_V : VLoad_Strided<0b000, 0b010, 0b000, "vlsbu.v">;
def VLSHU_V : VLoad_Strided<0b000, 0b010, 0b101, "vlshu.v">;
def VLSWU_V : VLoad_Strided<0b000, 0b010, 0b110, "vlswu.v">;
def VLSE_V : VLoad_Strided<0b000, 0b010, 0b111, "vlse.v">;

def VSSB_V : VStore_Strided<0b000, 0b010, 0b000, "vssb.v">;
def VSSH_V : VStore_Strided<0b000, 0b010, 0b101, "vssh.v">;
def VSSW_V : VStore_Strided<0b000, 0b010, 0b110, "vssw.v">;
def VSSE_V : VStore_Strided<0b000, 0b010, 0b111, "vsse.v">;


// Vector Indexed Instructions

def VLXB_V : VLoad_Indexed<0b000, 0b111, 0b000, "vlxb.v">;
def VLXH_V : VLoad_Indexed<0b000, 0b111, 0b101, "vlxh.v">;
def VLXW_V : VLoad_Indexed<0b000, 0b111, 0b110, "vlxw.v">;
def VLXBU_V : VLoad_Indexed<0b000, 0b011, 0b000, "vlxbu.v">;
def VLXHU_V : VLoad_Indexed<0b000, 0b011, 0b101, "vlxhu.v">;
def VLXWU_V : VLoad_Indexed<0b000, 0b011, 0b110, "vlxwu.v">;
def VLXE_V : VLoad_Indexed<0b000, 0b011, 0b111, "vlxe.v">;

def VSXB_V : VStore_Indexed<0b000, 0b011, 0b000, "vsxb.v">;
def VSXH_V : VStore_Indexed<0b000, 0b011, 0b101, "vsxh.v">;
def VSXW_V : VStore_Indexed<0b000, 0b011, 0b110, "vsxw.v">;
def VSXE_V : VStore_Indexed<0b000, 0b011, 0b111, "vsxe.v">;
def VSUXB_V : VStore_Indexed<0b000, 0b111, 0b000, "vsuxb.v">;
def VSUXH_V : VStore_Indexed<0b000, 0b111, 0b101, "vsuxh.v">;
def VSUXW_V : VStore_Indexed<0b000, 0b111, 0b110, "vsuxw.v">;
def VSUXE_V : VStore_Indexed<0b000, 0b111, 0b111, "vsuxe.v">;


// Unit-stride Fault-Only-First Loads Instructions

def VLBFF_V : VLoad_UnitStrideFF<0b000, 0b100, 0b000, "vlbff.v">;
def VLHFF_V : VLoad_UnitStrideFF<0b000, 0b100, 0b101, "vlhff.v">;
def VLWFF_V : VLoad_UnitStrideFF<0b000, 0b100, 0b110, "vlwff.v">;
def VLBUFF_V : VLoad_UnitStrideFF<0b000, 0b000, 0b000, "vlbuff.v">;
def VLHUFF_V : VLoad_UnitStrideFF<0b000, 0b000, 0b101, "vlhuff.v">;
def VLWUFF_V : VLoad_UnitStrideFF<0b000, 0b000, 0b110, "vlwuff.v">;
def VLEFF_V : VLoad_UnitStrideFF<0b000, 0b000, 0b111, "vleff.v">;


// Vector Load/Store Segment Instructions
// TODO


// Vector Single-Width Integer Add and Subtract Instructions

def VADD_VV : VALU_OPIVV<0b000000, "vadd.vv">;
def VADD_VX : VALU_OPIVX<0b000000, "vadd.vx">;
def VADD_VI : VALU_OPIVI<0b000000, "vadd.vi">;

def VSUB_VV : VALU_OPIVV<0b000010, "vsub.vv">;
def VSUB_VX : VALU_OPIVX<0b000010, "vsub.vx">;

def VRSUB_VX : VALU_OPIVX<0b000011, "vrsub.vx">;
def VRSUB_VI : VALU_OPIVI<0b000011, "vrsub.vi">;


// Vector Widening Integer Add and Subtract Instructions

def VWADDU_VV : VALU_OPMVV<0b110000, "vwaddu.vv">;
def VWADDU_VX : VALU_OPMVX<0b110000, "vwaddu.vx">;
def VWSUBU_VV : VALU_OPMVV<0b110010, "vwsubu.vv">;
def VWSUBU_VX : VALU_OPMVX<0b110010, "vwsubu.vx">;

def VWADD_VV : VALU_OPMVV<0b110001, "vwadd.vv">;
def VWADD_VX : VALU_OPMVX<0b110001, "vwadd.vx">;
def VWSUB_VV : VALU_OPMVV<0b110011, "vwsub.vv">;
def VWSUB_VX : VALU_OPMVX<0b110011, "vwsub.vx">;

def VWADDU_WV : VALU_OPMVV<0b110100, "vwaddu.wv">;
def VWADDU_WX : VALU_OPMVX<0b110100, "vwaddu.wx">;
def VWSUBU_WV : VALU_OPMVV<0b110110, "vwsubu.wv">;
def VWSUBU_WX : VALU_OPMVX<0b110110, "vwsubu.wx">;

def VWADD_WV : VALU_OPMVV<0b110101, "vwadd.wv">;
def VWADD_WX : VALU_OPMVX<0b110101, "vwadd.wx">;
def VWSUB_WV : VALU_OPMVV<0b110111, "vwsub.wv">;
def VWSUB_WX : VALU_OPMVX<0b110111, "vwsub.wx">;


// Vector Integer Add-with-Carry / Subtract-with-Borrow Instructions
// TODO


// Vector Bitwise Logical Instructions

def VAND_VV : VALU_OPIVV<0b001001, "vand.vv">;
def VAND_VX : VALU_OPIVX<0b001001, "vand.vx">;
def VAND_VI : VALU_OPIVI<0b001001, "vand.vi">;

def VOR_VV : VALU_OPIVV<0b001010, "vor.vv">;
def VOR_VX : VALU_OPIVX<0b001010, "vor.vx">;
def VOR_VI : VALU_OPIVI<0b001010, "vor.vi">;

def VXOR_VV : VALU_OPIVV<0b001011, "vxor.vv">;
def VXOR_VX : VALU_OPIVX<0b001011, "vxor.vx">;
def VXOR_VI : VALU_OPIVI<0b001011, "vxor.vi">;


// Vector Single-Width Bit Shift Instructions

def VSLL_VV : VALU_OPIVV<0b100101, "vsll.vv">;
def VSLL_VX : VALU_OPIVX<0b100101, "vsll.vx">;
def VSLL_VI : VALU_OPIVI<0b100101, "vsll.vi">;

def VSRL_VV : VALU_OPIVV<0b101000, "vsrl.vv">;
def VSRL_VX : VALU_OPIVX<0b101000, "vsrl.vx">;
def VSRL_VI : VALU_OPIVI<0b101000, "vsrl.vi">;

def VSRA_VV : VALU_OPIVV<0b101001, "vsra.vv">;
def VSRA_VX : VALU_OPIVX<0b101001, "vsra.vx">;
def VSRA_VI : VALU_OPIVI<0b101001, "vsra.vi">;


// Vector Narrowing Integer Right Shift Instructions

def VNSRL_VV : VALU_OPIVV<0b101100, "vnsrl.vv">;
def VNSRL_VX : VALU_OPIVX<0b101100, "vnsrl.vx">;
def VNSRL_VI : VALU_OPIVI<0b101100, "vnsrl.vi">;

def VNSRA_VV : VALU_OPIVV<0b101101, "vnsra.vv">;
def VNSRA_VX : VALU_OPIVX<0b101101, "vnsra.vx">;
def VNSRA_VI : VALU_OPIVI<0b101101, "vnsra.vi">;


// Vector Integer Comparison Instructions

def VMSEQ_VV : VALU_OPIVV<0b011000, "vmseq.vv">;
def VMSEQ_VX : VALU_OPIVX<0b011000, "vmseq.vx">;
def VMSEQ_VI : VALU_OPIVI<0b011000, "vmseq.vi">;

def VMSNE_VV : VALU_OPIVV<0b011001, "vmsne.vv">;
def VMSNE_VX : VALU_OPIVX<0b011001, "vmsne.vx">;
def VMSNE_VI : VALU_OPIVI<0b011001, "vmsne.vi">;

def VMSLTU_VV : VALU_OPIVV<0b011010, "vmsltu.vv">;
def VMSLTU_VX : VALU_OPIVX<0b011010, "vmsltu.vx">;

def VMSLT_VV : VALU_OPIVV<0b011011, "vmslt.vv">;
def VMSLT_VX : VALU_OPIVX<0b011011, "vmslt.vx">;

def VMSLEU_VV : VALU_OPIVV<0b011100, "vmsleu.vv">;
def VMSLEU_VX : VALU_OPIVX<0b011100, "vmsleu.vx">;
def VMSLEU_VI : VALU_OPIVI<0b011100, "vmsleu.vi">;

def VMSLE_VV : VALU_OPIVV<0b011101, "vmsle.vv">;
def VMSLE_VX : VALU_OPIVX<0b011101, "vmsle.vx">;
def VMSLE_VI : VALU_OPIVI<0b011101, "vmsle.vi">;

def VMSGTU_VX : VALU_OPIVX<0b011110, "vmsgtu.vx">;
def VMSGTU_VI : VALU_OPIVI<0b011110, "vmsgtu.vi">;

def VMSGT_VX : VALU_OPIVX<0b011111, "vmsgt.vx">;
def VMSGT_VI : VALU_OPIVI<0b011111, "vmsgt.vi">;


// Vector Integer Min/Max Instructions

def VMINU_VV : VALU_OPIVV<0b000100, "vminu.vv">;
def VMINU_VX : VALU_OPIVX<0b000100, "vminu.vx">;

def VMIN_VV : VALU_OPIVV<0b000101, "vmin.vv">;
def VMIN_VX : VALU_OPIVX<0b000101, "vmin.vx">;

def VMAXU_VV : VALU_OPIVV<0b000110, "vmaxu.vv">;
def VMAXU_VX : VALU_OPIVX<0b000110, "vmaxu.vx">;

def VMAX_VV : VALU_OPIVV<0b000111, "vmax.vv">;
def VMAX_VX : VALU_OPIVX<0b000111, "vmax.vx">;


// Vector Single-Width Integer Multiply Instructions

def VMUL_VV : VALU_OPMVV<0b100101, "vmul.vv">;
def VMUL_VX : VALU_OPMVX<0b100101, "vmul.vx">;

def VMULH_VV : VALU_OPMVV<0b100111, "vmulh.vv">;
def VMULH_VX : VALU_OPMVX<0b100111, "vmulh.vx">;

def VMULHU_VV : VALU_OPMVV<0b100100, "vmulhu.vv">;
def VMULHU_VX : VALU_OPMVX<0b100100, "vmulhu.vx">;

def VMULHSU_VV : VALU_OPMVV<0b100110, "vmulhsu.vv">;
def VMULHSU_VX : VALU_OPMVX<0b100110, "vmulhsu.vx">;


// Vector Integer Divide Instructions

def VDIVU_VV : VALU_OPMVV<0b100000, "vdivu.vv">;
def VDIVU_VX : VALU_OPMVX<0b100000, "vdivu.vx">;

def VDIV_VV : VALU_OPMVV<0b100001, "vdiv.vv">;
def VDIV_VX : VALU_OPMVX<0b100001, "vdiv.vx">;

def VREMU_VV : VALU_OPMVV<0b100010, "vremu.vv">;
def VREMU_VX : VALU_OPMVX<0b100010, "vremu.vx">;

def VREM_VV : VALU_OPMVV<0b100011, "vrem.vv">;
def VREM_VX : VALU_OPMVX<0b100011, "vrem.vx">;


// Vector Widening Integer Multiply Instructions

def VWMUL_VV : VALU_OPMVV<0b111011, "vwmul.vv">;
def VWMUL_VX : VALU_OPMVX<0b111011, "vwmul.vx">;

def VWMULU_VV : VALU_OPMVV<0b111000, "vwmulu.vv">;
def VWMULU_VX : VALU_OPMVX<0b111000, "vwmulu.vx">;

def VWMULSU_VV : VALU_OPMVV<0b111010, "vwmulsu.vv">;
def VWMULSU_VX : VALU_OPMVX<0b111010, "vwmulsu.vx">;


// Vector Single-Width Integer Multiply-Add Instructions
// TODO


// Vector Widening Integer Multiply-Add Instructions
// TODO


// Vector Integer Merge and Move Instructions
// TODO


// Vector Single-Width Saturating Add and Subtract Instructions

def VSADDU_VV : VALU_OPIVV<0b100000, "vsaddu.vv">;
def VSADDU_VX : VALU_OPIVX<0b100000, "vsaddu.vx">;
def VSADDU_VI : VALU_OPIVI<0b100000, "vsaddu.vi">;

def VSADD_VV : VALU_OPIVV<0b100001, "vsadd.vv">;
def VSADD_VX : VALU_OPIVX<0b100001, "vsadd.vx">;
def VSADD_VI : VALU_OPIVI<0b100001, "vsadd.vi">;

def VSSUBU_VV : VALU_OPIVV<0b100010, "vssubu.vv">;
def VSSUBU_VX : VALU_OPIVX<0b100010, "vssubu.vx">;

def VSSUB_VV : VALU_OPIVV<0b100011, "vssub.vv">;
def VSSUB_VX : VALU_OPIVX<0b100011, "vssub.vx">;


// Vector Single-Width Averaging Add and Subtract Instructions

def VAADD_VV : VALU_OPIVV<0b100100, "vaadd.vv">;
def VAADD_VX : VALU_OPIVX<0b100100, "vaadd.vx">;
def VAADD_VI : VALU_OPIVI<0b100100, "vaadd.vi">;

def VASUB_VV : VALU_OPIVV<0b100110, "vasub.vv">;
def VASUB_VX : VALU_OPIVX<0b100110, "vasub.vx">;


// Vector Single-Width Fractional Multiply Instructions with Rounding and Saturation

def VSMUL_VV : VALU_OPIVV<0b100111, "vsmul.vv">;
def VSMUL_VX : VALU_OPIVX<0b100111, "vsmul.vx">;


// Vector Widening Saturating Scaled Multiply-Add Instructions
// TODO


// Vector Single-Width Scaling Shift Instructions

def VSSRL_VV : VALU_OPIVV<0b101010, "vssrl.vv">;
def VSSRL_VX : VALU_OPIVX<0b101010, "vssrl.vx">;
def VSSRL_VI : VALU_OPIVI<0b101010, "vssrl.vi">;

def VSSRA_VV : VALU_OPIVV<0b101011, "vssra.vv">;
def VSSRA_VX : VALU_OPIVX<0b101011, "vssra.vx">;
def VSSRA_VI : VALU_OPIVI<0b101011, "vssra.vi">;


// Vector Narrowing Fixed-Point Clip Instructions

def VNCLIPU_VV : VALU_OPIVV<0b101110, "vnclipu.vv">;
def VNCLIPU_VX : VALU_OPIVX<0b101110, "vnclipu.vx">;
def VNCLIPU_VI : VALU_OPIVI<0b101110, "vnclipu.vi">;

def VNCLIP_VV : VALU_OPIVV<0b101111, "vnclip.vv">;
def VNCLIP_VX : VALU_OPIVX<0b101111, "vnclip.vx">;
def VNCLIP_VI : VALU_OPIVI<0b101111, "vnclip.vi">;


// Vector Single-Width Floating-Point Add/Subtract Instructions

def VFADD_VV : VALU_OPFVV<0b000000, "vfadd.vv">;
def VFADD_VF : VALU_OPFVF<0b000000, "vfadd.vf">;

def VFSUB_VV : VALU_OPFVV<0b000010, "vfsub.vv">;
def VFSUB_VF : VALU_OPFVF<0b000010, "vfsub.vf">;
def VFRSUB_VF : VALU_OPFVF<0b100111, "vfrsub.vf">;


// Vector Widening Floating-Point Add/Subtract Instructions

def VFWADD_VV : VALU_OPFVV<0b110000, "vfwadd.vv">;
def VFWADD_VF : VALU_OPFVF<0b110000, "vfwadd.vf">;
def VFWSUB_VV : VALU_OPFVV<0b110010, "vfwsub.vv">;
def VFWSUB_VF : VALU_OPFVF<0b110010, "vfwsub.vf">;

def VFWADD_WV : VALU_OPFVV<0b110100, "vfwadd.wv">;
def VFWADD_WF : VALU_OPFVF<0b110100, "vfwadd.wf">;
def VFWSUB_WV : VALU_OPFVV<0b110110, "vfwsub.wv">;
def VFWSUB_WF : VALU_OPFVF<0b110110, "vfwsub.wf">;


// Vector Single-Width Floating-Point Multiply/Divide Instructions

def VFMUL_VV : VALU_OPFVV<0b100100, "vfmul.vv">;
def VFMUL_VF : VALU_OPFVF<0b100100, "vfmul.vf">;

def VFDIV_VV : VALU_OPFVV<0b100000, "vfdiv.vv">;
def VFDIV_VF : VALU_OPFVF<0b100000, "vfdiv.vf">;
def VFRDIV_VF : VALU_OPFVF<0b100001, "vfrdiv.vf">;


// Vector Widening Floating-Point Multiply Instructions

def VFWMUL_VV : VALU_OPFVV<0b111000, "vfwmul.vv">;
def VFWMUL_VF : VALU_OPFVF<0b111000, "vfwmul.vf">;


// Vector Single-Width Floating-Point Fused Multiply-Add Instructions
// TODO


// Vector Widening Floating-Point Fused Multiply-Add Instructions
// TODO


// Vector Floating-Point Square-Root Instruction
// TODO


// Vector Floating-Point MIN/MAX Instructions

def VFMIN_VV : VALU_OPFVV<0b000100, "vfmin.vv">;
def VFMIN_VF : VALU_OPFVF<0b000100, "vfmin.vf">;

def VFMAX_VV : VALU_OPFVV<0b000110, "vfmax.vv">;
def VFMAX_VF : VALU_OPFVF<0b000110, "vfmax.vf">;


// Vector Floating-Point Compare Instructions

def VMFEQ_VV : VALU_OPFVV<0b011000, "vmfeq.vv">;
def VMFEQ_VF : VALU_OPFVF<0b011000, "vmfeq.vf">;

def VMFNE_VV : VALU_OPFVV<0b011100, "vmfne.vv">;
def VMFNE_VF : VALU_OPFVF<0b011100, "vmfne.vf">;

def VMFLT_VV : VALU_OPFVV<0b011011, "vmflt.vv">;
def VMFLT_VF : VALU_OPFVF<0b011011, "vmflt.vf">;

def VMFLE_VV : VALU_OPFVV<0b011001, "vmfle.vv">;
def VMFLE_VF : VALU_OPFVF<0b011001, "vmfle.vf">;

def VMFGT_VF : VALU_OPFVF<0b011101, "vmfgt.vf">;

def VMFGE_VF : VALU_OPFVF<0b011111, "vmfge.vf">;

/*
def VMFORD_VV : VALU_OPFVV<0b011010, "vmford.vv">;
def VMFORD_VF : VALU_OPFVF<0b011010, "vmford.vf">;
*/


// Vector Floating-Point Classify Instruction
// TODO


// Vector Floating-Point Merge and Move Instructions
// TODO


// Widening Floating-Point/Integer Type-Convert Instructions
// TODO


// Narrowing Floating-Point/Integer Type-Convert Instructions
// TODO


// Vector Single-Width Integer Reduction Instructions

def VREDSUM_VS : VALU_OPMVV<0b000000, "vredsum.vs">;
def VREDMAXU_VS : VALU_OPMVV<0b000110, "vredmaxu.vs">;
def VREDMAX_VS : VALU_OPMVV<0b000111, "vredmax.vs">;
def VREDMINU_VS : VALU_OPMVV<0b000100, "vredminu.vs">;
def VREDMIN_VS : VALU_OPMVV<0b000101, "vredmin.vs">;
def VREDAND_VS : VALU_OPMVV<0b000001, "vredand.vs">;
def VREDOR_VS : VALU_OPMVV<0b000010, "vredor.vs">;
def VREDXOR_VS : VALU_OPMVV<0b000011, "vredxor.vs">;


// Vector Widening Integer Reduction Instructions

def VWREDSUMU_VS : VALU_OPIVV<0b110000, "vwredsumu.vs">;
def VWREDSUM_VS : VALU_OPIVV<0b110001, "vwredsum.vs">;


// Vector Single-Width Floating-Point Reduction Instructions

def VFREDOSUM_VS : VALU_OPFVV<0b000011, "vfredosum.vs">;
def VFREDSUM_VS : VALU_OPFVV<0b000001, "vfredsum.vs">;
def VFREDMAX_VS : VALU_OPFVV<0b000111, "vfredmax.vs">;
def VFREDMIN_VS : VALU_OPFVV<0b000101, "vfredmin.vs">;


// Vector Widening Floating-Point Reduction Instructions
// TODO


} // Predicates = [HasStdExtV]

//===----------------------------------------------------------------------===//
// Pseudo-instructions and codegen patterns
//===----------------------------------------------------------------------===//

let Predicates = [HasStdExtV] in {

let hasSideEffects = 1, mayLoad = 0, mayStore = 0,
    isCodeGenOnly = 1, isAsmParserOnly = 0 in {
  def PseudoCSRR_VL : Pseudo<(outs GPR:$rd), (ins VLR:$vl), []>,
                      PseudoInstExpansion<(CSRRS GPR:$rd, 0xCC0, X0)>
  {
    //let Uses = [VCFG];
  }
}


class PatVrVr<SDPatternOperator OpNode, RVInst Inst>
    : Pat<(OpNode VR:$rs1, VR:$rs2, VLR:$vl), (Inst VR:$rs1, VR:$rs2, VLR:$vl)>;

class PatVrIm<SDPatternOperator OpNode, RVInst Inst>
    : Pat<(OpNode VR:$rs1, (RISCVBROADCAST simm5:$imm), VLR:$vl), (Inst VR:$rs1, simm5:$imm, VLR:$vl)>; 

def : PatVrVr<int_riscv_vadd, VADD_VV>;
def : PatVrVr<int_riscv_vsub, VSUB_VV>;
def : PatVrIm<int_riscv_vadd, VADD_VI>;
/*
def : PatVrVr<int_riscv_vmul, VMUL_VV>;
def : PatVrVr<int_riscv_vand, VAND_VV>;
def : PatVrVr<int_riscv_vor, VOR_VV>;
def : PatVrVr<int_riscv_vxor, VXOR_VV>;
*/

// TODO exploit immediate offset
def : Pat<(int_riscv_vlw GPR:$rs1, VLR:$vl),
          (VLW_V GPR:$rs1, VLR:$vl, 0)>;

def : Pat<(int_riscv_vsw GPR:$rs1, VR:$rs2, VLR:$vl),
          (VSW_V GPR:$rs1, VR:$rs2, VLR:$vl, 0)>;

def : Pat<(RISCVSETVL GPR:$rs1, GPR:$rs2), (VSETVL GPR:$rs1, GPR:$rs2)>;

} // Predicates = [HasStdExtV]
