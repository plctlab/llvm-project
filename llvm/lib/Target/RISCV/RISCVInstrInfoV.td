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
               (outs VR:$vd), (ins VR:$vs2, GPR:$rs1, VLR:$vl),
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
