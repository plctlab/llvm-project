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
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
class VStore_UnitStride<bits<3> nf, bits<3> mop, bits<3> width, string opcodestr>
    : RVInstVStore<nf, mop, width, RVV_Unmasked, OPC_STORE_FP,
                   (outs), (ins GPR:$rs1, VR:$vs3, VLR:$vl, simm5:$imm5),
                   opcodestr, "$vs3, ${imm5}(${rs1})">
{
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
  //let Uses = [VCFG];
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class VALU_OPIVI<bits<6> funct6, string opcodestr>
    : RVInstVA<funct6, 0b011, RVV_Unmasked, OPC_OP_V,
               (outs VR:$vd), (ins VR:$vs2, simm5:$imm5, VLR:$vl),
               opcodestr, "$vd, $vs2, $imm5">
{
  //let Uses = [VCFG];
}


//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

//VSETVL{I}
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




let Predicates = [HasStdExtV] in {

def VADD_VV : VALU_OPIVV<0b000000, "vadd.vv">;

def VSUB_VV : VALU_OPIVV<0b000010, "vsub.vv">;

def VADD_VI : VALU_OPIVI<0b000000, "vadd.vi">;

//Instruction encoding table: https://github.com/riscv/riscv-v-spec/blob/master/inst-table.adoc
/*
def VMUL : VALU_Ari<0b100010, 0b010, "vmul">;

def VAND : VALU_Ari<0b100111, 0b100, "vand">;

def VOR : VALU_Ari<0b100110, 0b100, "vor">;

def VXOR : VALU_Ari<0b110000, 0b100, "vxor">;
*/

def VLW_V : VLoad_UnitStride<0b000, 0b100, 0b110, "vlw.v">;

def VSW_V : VStore_UnitStride<0b000, 0b000, 0b110, "vsw.v">;

/*
def VMPOPC : VALU_Ari<0b101011, 0b100, "vmpop">;
def VMFIRST : VALU_Ari<0b101011, 0b101, "vmfirst">;



let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VCONFIG : RVInst<(outs), (ins uimm8:$imm8),
                     "vconfig", "$imm8", [], InstFormatOther>
{
  bits<8> imm8;

  let Inst{31-28} = 0b1111;
  let Inst{27-20} = imm8;
  let Inst{19-15} = 0b00000;
  let Inst{14} = 0b1;
  let Inst{13-12} = 0b01;
  let Inst{11-7} = 0b00000;
  let Opcode = OPC_OP_V.Value;

  let Defs = [VCFG];
}
*/


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
/*
class PatVr<SDPatternOperator OpNode, RVInst Inst>
    : Pat<(OpNode VR:$rs1, VLR:$vl), (Inst VR:$rs1, VLR:$vl)>;
*/

def : PatVrVr<int_riscv_vadd, VADD_VV>;
def : PatVrVr<int_riscv_vsub, VSUB_VV>;
def : PatVrIm<int_riscv_vadd, VADD_VI>;

/*
def : PatVrVr<int_riscv_vmul, VMUL>;
def : PatVrVr<int_riscv_vand, VAND>;
def : PatVrVr<int_riscv_vor, VOR>;
def : PatVrVr<int_riscv_vxor, VXOR>;
def : PatVr<int_riscv_vmpopcnt, VMPOPC>;
def : PatVr<int_riscv_vmfirst, VMFIRST>;
*/


// TODO exploit immediate offset
def : Pat<(int_riscv_vlw GPR:$rs1, VLR:$vl),
          (VLW_V GPR:$rs1, VLR:$vl, 0)>;

def : Pat<(int_riscv_vsw GPR:$rs1, VR:$rs2, VLR:$vl),
          (VSW_V GPR:$rs1, VR:$rs2, VLR:$vl, 0)>;

def : Pat<(RISCVSETVL GPR:$rs1, GPR:$rs2), (VSETVL GPR:$rs1, GPR:$rs2)>;

} // Predicates = [HasStdExtV]
