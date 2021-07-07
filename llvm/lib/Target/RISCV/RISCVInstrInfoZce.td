//===-- RISCVInstrInfoZce.td - RISC-V 'Zce' instructions -------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
///
/// This file describes the RISC-V instructions from the 'Zce' Code-size reduction
/// extension, version 0.24.
/// This version is still experimental as the 'Zce' extension hasn't been
/// ratified yet.
///
//===----------------------------------------------------------------------===//

include "RISCVInstrFormatsZce.td"

//===----------------------------------------------------------------------===//
// Operand and SDNode transformation definitions.
//===----------------------------------------------------------------------===//

def uimm4 : Operand<XLenVT>, ImmLeaf<XLenVT, [{return isUInt<4>(Imm);}]> {
  let ParserMatchClass = UImmAsmOperand<4>;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeUImmOperand<4>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return isUInt<4>(Imm);
    return MCOp.isBareSymbolRef();
  }];
}

def uimm5_lsb0 : Operand<XLenVT>,
                 ImmLeaf<XLenVT, [{return isShiftedUInt<4, 1>(Imm);}]> {
  let ParserMatchClass = UImmAsmOperand<5, "Lsb0">;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeUImmOperand<5>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (!MCOp.evaluateAsConstantImm(Imm))
      return false;
    return isShiftedUInt<4, 1>(Imm);
  }];
}

def simm13_lsb0_zce : Operand<XLenVT>,
                      ImmLeaf<XLenVT, [{return isShiftedInt<12, 1>(Imm);}]> {
  let ParserMatchClass = SImmAsmOperand<13, "Lsb0Zce">;
  let PrintMethod = "printBranchOperand";
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeSImmOperand<13>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return isShiftedInt<12, 1>(Imm);
    return MCOp.isBareSymbolRef();
  }];
  let OperandType = "OPERAND_PCREL";
}

class uimm8 : Operand<XLenVT>,
              ImmLeaf<XLenVT, [{return isUInt<8>(Imm);}]> {
  let ParserMatchClass = UImmAsmOperand<8>;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeUImmOperand<8>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (!MCOp.evaluateAsConstantImm(Imm))
      return false;
    return MCOp.isBareSymbolRef();
  }];
}

def tbljalm_uimm8 : uimm8 {
  let ParserMatchClass = UImmAsmOperand<8, "tbljalm">;
  let DecoderMethod = "decodeZceTableJump";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (!MCOp.evaluateAsConstantImm(Imm))
      return false;
    return MCOp.isBareSymbolRef();
  }];
}

def tblj_uimm8 : uimm8 {
  let ParserMatchClass = UImmAsmOperand<8, "tblj">;
  let EncoderMethod = "8+getImmOpValue";
  let DecoderMethod = "decodeZceTableJump";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (!MCOp.evaluateAsConstantImm(Imm))
      return false;
    return MCOp.isBareSymbolRef();
  }];
}

def tbljal_uimm8 : uimm8 {
  let ParserMatchClass = UImmAsmOperand<8, "tbljal">;
  let EncoderMethod = "64+getImmOpValue";
  let DecoderMethod = "decodeZceTableJump";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (!MCOp.evaluateAsConstantImm(Imm))
      return false;
    return MCOp.isBareSymbolRef();
  }];
}

def simm16_lsb00 : Operand<XLenVT>,
                   ImmLeaf<XLenVT, [{return isShiftedInt<14, 2>(Imm);}]> {
  let ParserMatchClass = SImmAsmOperand<16, "Lsb00">;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeSImmOperand<16>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (!MCOp.evaluateAsConstantImm(Imm))
      return false;
    return isShiftedInt<14, 2>(Imm);
  }];
}

def simm17_lsb000 : Operand<XLenVT>,
                    ImmLeaf<XLenVT, [{return isShiftedInt<14, 3>(Imm);}]> {
  let ParserMatchClass = SImmAsmOperand<17, "Lsb000">;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeSImmOperand<17>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (!MCOp.evaluateAsConstantImm(Imm))
      return false;
    return isShiftedInt<14, 3>(Imm);
  }];
}

def ScaleAsmOperand : AsmOperandClass {
  let Name = "Scale";
  let RenderMethod = "addScaleOperands";
  let DiagnosticType = "InvalidScale";
}

// def SpimmAsmOperand : AsmOperandClass {
//   let Name = "Spimm";
//   let RenderMethod = "addScaleOperands";
// }

// def spimm : Operand<XLenVT> {
//   let ParserMatchClass = Spimm;
// }

def scale : Operand<XLenVT>,
            ImmLeaf<XLenVT, [{ return Imm != 0 && (Imm & (Imm - 1)) == 0;}]> {
  let ParserMatchClass = ScaleAsmOperand;
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return Imm != 0 && (Imm & (Imm - 1)) == 0;
    return MCOp.isBareSymbolRef();
  }];
}

def NEGImm7Lsb0NonZeroAsmOperand : AsmOperandClass {
  let Name = "NEGImm7Lsb0NonZero";
  let RenderMethod = "addNEGImm7Lsb0NonZeroOperands";
  let DiagnosticType = "InvalidNEGImm7Lsb0NonZero";
}

def negimm7_lsb0nonzero : Operand<XLenVT>,
  ImmLeaf<XLenVT, [{return Imm != 0 && isShiftedUInt<6, 1>(-Imm); }]> {
  let ParserMatchClass = NEGImm7Lsb0NonZeroAsmOperand;
  let EncoderMethod = "getNEGImm7Lsb0NonZero";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (MCOp.evaluateAsConstantImm(Imm))
      return Imm != 0 && isShiftedUInt<6, 1>(-Imm);
    return MCOp.isBareSymbolRef();
  }];
}

def AlistAsmOperand : AsmOperandClass {
  let Name = "Alist";
  let ParserMethod = "parseReglist";
  let DiagnosticType = "InvalidAlist";
}

def AlistAsmOperand16 : AsmOperandClass {
  let Name = "Alist16";
  let ParserMethod = "parseReglist16";
  let DiagnosticType = "InvalidAlist";
}

def SlistAsmOperand : AsmOperandClass {
  let Name = "Slist";
  let ParserMethod = "parseReglist";
  let DiagnosticType = "InvalidSlist";
}

def SlistAsmOperand16 : AsmOperandClass {
  let Name = "Slist16";
  let ParserMethod = "parseReglist16";
  let DiagnosticType = "InvalidSlist";
}

def RetvalAsmOperand : AsmOperandClass {
  let Name = "Retval";
  let ParserMethod = "parseRetval";
  let DiagnosticType = "InvalidRetval";
}

def SpimmAsmOperand : AsmOperandClass {
  let Name = "Spimm";
  let ParserMethod = "parseZceSpimm";
  let DiagnosticType = "InvalidSpimm";
}

def alist : Operand<OtherVT> {
  let ParserMatchClass = AlistAsmOperand;
  let PrintMethod = "printAlist";
}

def slist : Operand<OtherVT> {
  let ParserMatchClass = SlistAsmOperand;
  let PrintMethod = "printSlist";
}

def alist16 : Operand<OtherVT> {
  let ParserMatchClass = AlistAsmOperand16;
  let PrintMethod = "printAlist";
}

def rlist3 : Operand<OtherVT> {
  let ParserMatchClass = SlistAsmOperand16;
  let PrintMethod = "printRlist3";
  let DecoderMethod = "decodeZceRlist3";
}

def rlist2 : Operand<OtherVT> {
  let ParserMatchClass = SlistAsmOperand16;
  let PrintMethod = "printRlist2";
  let DecoderMethod = "decodeZceRlist2";
}

def retval : Operand<OtherVT> {
  let ParserMatchClass = RetvalAsmOperand;
  let PrintMethod = "printRetval";
}

def spimm : Operand<OtherVT> {
  let ParserMatchClass = SpimmAsmOperand;
  let PrintMethod = "printSpimm";
  let DecoderMethod = "decodeZceSpimm";
}

//===----------------------------------------------------------------------===//
// Instruction Class Templates
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class Branch_rii<bits<3> funct3, string opcodestr>
    : RVInstB<funct3, OPC_BRANCH, (outs),
              (ins GPR:$rs1, uimm5:$uimm, simm13_lsb0:$imm12),
              opcodestr, "$rs1, $uimm, $imm12">,
      Sched<[]> {
  bits<12> imm12;
  bits<5> uimm;
  bits<5> rs1;
  let isBranch = 1;
  let isTerminator = 1;

  let Inst{24-20} = uimm;
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
class ZceGPLoad<bits<3> funct3_2, bits<3> funct3, string opcodestr, DAGOperand opnd>
    : RVInstZceI<funct3_2, funct3, 0b0000111, (outs GPR:$rd), (ins GP:$rs1, opnd:$imm),
              opcodestr, "$rd, ${imm}(${rs1})">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
class ZceGPStore<bits<3> funct3_2, bits<3> funct3, string opcodestr, DAGOperand opnd>
    : RVInstZceS<funct3_2, funct3, 0b0100111, (outs), (ins GPR:$rs2, GP:$rs1, opnd:$imm),
              opcodestr, "$rs2, ${imm}(${rs1})">;

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
class ZceLoad_ri<bits<3> funct3, bits<2> opcode, string opcodestr,
                 RegisterClass cls, DAGOperand opnd>
    : RVInst16CL<funct3, opcode, (outs cls:$rd), (ins GPRC:$rs1, opnd:$imm),
                 opcodestr, "$rd, ${imm}(${rs1})">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
class ZceStore_ri<bits<3> funct3, bits<2> opcode, string opcodestr,
                 RegisterClass cls, DAGOperand opnd>
    : RVInst16CS<funct3, opcode, (outs), (ins cls:$rs2, GPRC:$rs1, opnd:$imm),
                 opcodestr, "$rs2, ${imm}(${rs1})">;

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

// 6. Zcea

// 6.1
// echo "c.zext.b s0" | bin/llvm-mc -triple=riscv64 -mattr=+experimental-zce -show-encoding
let Predicates = [HasStdExtZcee] in {
def C_ZEXT_B  : RVZceArith_r<0b00, 0b000 , "c.zext.b">, Sched<[]>;
def C_SEXT_B  : RVZceArith_r<0b00, 0b001 , "c.sext.b">, Sched<[]>;
def C_ZEXT_H  : RVZceArith_r<0b00, 0b010 , "c.zext.h">, Sched<[]>;
def C_SEXT_H  : RVZceArith_r<0b00, 0b011 , "c.sext.h">, Sched<[]>;
}

let Predicates = [HasStdExtZcee, IsRV64] in {
def C_ZEXT_W : RVZceArith_r<0b00, 0b100 , "c.zext.w">, Sched<[]>;
}

let Predicates = [HasStdExtC, HasStdExtZcee, IsRV64] in{
def : InstAlias<"c.sext.w $rd", (C_ADDIW GPRC:$rd, 0)>;
}

let Predicates = [HasStdExtZcea] in {
def C_NEG_ZCE : RVZceArith_r<0b00, 0b110 , "c.neg">, Sched<[]>;
def C_NOT_ZCE : RVZceArith_r<0b00, 0b111 , "c.not">, Sched<[]>;
def C_MUL     : RVZceArith_rr<0b100111, 0b10, 0b01, "c.mul">, Sched<[]>;
}

// 6.3 C.MVA01S07
let Predicates = [HasStdExtZcea],
    hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def C_MVA01S07 : RVInst16CA<0b100111, 0b11, 0b01, (outs SR07:$rs1, SR07:$rs2),
                            (ins), "c.mva01s07", "$rs1, $rs2">,
                Sched<[]>;

// 6.4 MULI
// TODO: requires M or *Zmmul*, waiting for Zmmul ext
let Predicates = [HasStdExtZcea, HasStdExtM],
    hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def MULI : RVInstI<0b001, RISCVOpcode<0b0001011>, (outs GPR:$rd),
                  (ins GPR:$rs1, simm12:$imm12), "muli", "$rd, $rs1, $imm12">,
           Sched<[]>;

// 6.5 BEQI, BNEI
let Predicates = [HasStdExtZcea] in {
def BEQI : Branch_rii<0b010, "beqi">;
def BNEI : Branch_rii<0b011, "bnei">;
}

let Predicates = [HasStdExtZcea] in {
def TBLJALM : RVInstZceTableJump_i<0b010, "tbljalm", tbljalm_uimm8>, Sched<[]>;
def TBLJ    : RVInstZceTableJump_i<0b010, "tblj", tblj_uimm8>, Sched<[]>;
def TBLJAL  : RVInstZceTableJump_i<0b010, "tbljal", tbljal_uimm8>, Sched<[]>;
}

// 6.9 push, pop
let Predicates = [HasStdExtZcea] in {
let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
def PUSH : RVInstZcePPP<0b100, (outs), (ins slist:$sreg, alist:$areg, spimm:$imm),
           "push", "$sreg, $areg, $imm">, Sched<[]> {
  bits<1> areg;
  bits<4> sreg;
  bits<16> imm;
  let Inst{20} = areg;
  let Inst{11-7} = imm{8-4};
  let Inst{19-16} = sreg;
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
def POP : RVInstZcePPP<0b101, (outs), (ins slist:$sreg, retval:$retval, spimm:$imm),
          "pop", "$sreg, $retval, $imm">, Sched<[]> {
  bits<2> retval;
  bits<4> sreg;
  bits<16> imm;
  let Inst{21-20} = retval;
  let Inst{11-7} = imm{8-4};
  let Inst{19-16} = sreg;
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
def POPRET : RVInstZcePPP<0b110, (outs), (ins slist:$sreg, retval:$retval, spimm:$imm),
          "popret", "$sreg, $retval, $imm">, Sched<[]> {
  bits<2> retval;
  bits<4> sreg;
  bits<16> imm;
  let Inst{21-20} = retval;
  let Inst{11-7} = imm{8-4};
  let Inst{19-16} = sreg;
}

// let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
// def PUSH_E : RVInstZcePPP<0b100, (outs), (ins slist_e:$sreg, alist:$areg,
//              simm9:$imm), "push.e", "$sreg, $areg, $imm">, Sched<[]> {
//   bits<1> areg;
//   bits<4> sreg;
//   bits<12> imm;
//   let Inst{20} = areg;
//   let Inst{11-7} = imm{8-4};
//   let Inst{19-16} = sreg;
// }

// let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
// def POP_E : RVInstZcePPP<0b101, (outs), (ins slist_e:$sreg, retval:$retval,
//             simm9:$imm), "pop.e", "$sreg, $retval, $imm">, Sched<[]> {
//   bits<2> retval;
//   bits<4> sreg;
//   let Inst{21-20} = retval;
//   let Inst{11-7} = imm{8-4};
//   let Inst{19-16} = sreg;
// }

// let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
// def POPRET_E : RVInstZcePPP<0b110, (outs), (ins slist_e:$sreg, retval:$retval,
//             simm9:$imm), "popret.e", "$sreg, $retval, $imm">, Sched<[]> {
//   bits<2> retval;
//   bits<4> sreg;
//   let Inst{21-20} = retval;
//   let Inst{11-7} = imm{8-4};
//   let Inst{19-16} = sreg;
// }

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in 
def C_PUSH : RVInstZceCPPP<(outs), (ins rlist3:$slist, alist16:$areg, spimm:$spimm), 
    "c.push", "{$slist}, {$areg}, $spimm">, Sched<[]> {
  bits<3> slist;
  bits<1> areg;
  bits<16> spimm;

  let DecoderNamespace  = "ZceC_PUSH";
  let Inst{9-7} = spimm{6-4};
  let Inst{6-5} = 0b10;
  let Inst{4-2} = slist;
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in 
def C_POPRET : RVInstZceCPPP<(outs), (ins rlist3:$rlist3, retval:$ret0, spimm:$spimm), 
    "c.popret", "{$rlist3}, {$ret0}, $spimm">, Sched<[]> {
  bits<3> rlist3;
  bits<1> ret0;
  bits<16> spimm;

  let DecoderNamespace  = "ZcePOPRET";
  let Inst{9-7} = spimm{6-4};
  let Inst{6} = 0b0;
  let Inst{5} = ret0;
  let Inst{4-2} = rlist3;
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in 
def C_POP : RVInstZceCPPP<(outs), (ins rlist3:$rlist3, retval:$ret0, spimm:$spimm), 
    "c.pop", "{$rlist3}, {$ret0}, $spimm">, Sched<[]> {
  bits<3> rlist3;
  bits<16> spimm;

  let Inst{9-8} = 0b11;
  let Inst{7} = spimm{4};
  let Inst{6-5} = 0b00;
  let Inst{4-2} = rlist3;
}
}

let Predicates = [HasStdExtZcea, IsRV32] in {
let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in 
def C_POP_E : RVInstZceCPPP<(outs), (ins rlist2:$rlist2, retval:$ret0, spimm:$spimm), 
    "c.pop.e", "{$rlist2}, {$ret0}, $spimm">, Sched<[]> {
  bits<2> rlist2;
  bits<16> spimm;

  let Inst{9-8} = 0b11;
  let Inst{7} = spimm{4};
  let Inst{6-4} = 0b010;
  let Inst{3-2} = rlist2;
}

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in 
def C_POPRET_E : RVInstZceCPPP<(outs), (ins rlist2:$rlist2, retval:$ret0, spimm:$spimm), 
    "c.popret.e", "{$rlist2}, {$ret0}, $spimm">, Sched<[]> {
  bits<2> rlist2;
  bits<16> spimm;
  bits<1> ret0;

  let DecoderNamespace  = "ZcePOPRET";

  let Inst{9-7} = spimm{6-4};
  let Inst{6-5} = 0b11;
  let Inst{4} = ret0;
  let Inst{3-2} = rlist2;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in 
def C_PUSH_E : RVInstZceCPPP<(outs), (ins rlist2:$rlist2, alist16:$areg, spimm:$spimm), 
    "c.push.e", "{$rlist2}, {$areg}, $spimm">, Sched<[]> {
  bits<2> rlist2;
  bits<16> spimm;
  let DecoderNamespace  = "ZceC_PUSH_E";
  let Inst{9-8} = 0b11;
  let Inst{7} = spimm{4};
  let Inst{6} = 0b1;
  let Inst{5-4} = spimm{6-5};
  let Inst{3-2} = rlist2;
}
}

// 7. Zceb

// 7.1 C.DECBNEZ, DECBNEZ
let Predicates = [HasStdExtZceb],
    DecoderNamespace = "RVZceb_",
    hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def C_DECBNEZ : RVInst16CIW<0b101, 0b10, (outs GPRC:$rd),
                            (ins scale:$scale, negimm7_lsb0nonzero:$imm),
                            "c.decbnez", "$rd, $scale, $imm">,
                Sched<[]> {
  bits<3> rd;
  bits<2> scale;
  let Inst{12-10} = imm{6-4};
  let Inst{9-7} = rd;
  let Inst{6-4} = imm{3-1};
  let Inst{3-2} = scale;
}

let Predicates = [HasStdExtZceb],
    hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def DECBNEZ : RVInstZceB<0b100, 0b011, 0b0000111, (outs GPR:$rd),
                         (ins scale:$scale, simm13_lsb0_zce:$imm),
                         "decbnez", "$rd, $scale, $imm">,
              Sched<[]> {
  bits<2> scale;

  let Inst{28-20} = imm{8-2, 10-9};
  let Inst{19-18} = scale;
  let Inst{17-15} = imm{1, 12-11};
}

// 7.2. LWGP, SWGP, LDGP, SDGP
let Predicates = [HasStdExtZceb] in
def LWGP : ZceGPLoad<0b000, 0b011, "lwgp", simm16_lsb00>, Sched<[]>;

let Predicates = [HasStdExtZceb] in
def SWGP : ZceGPStore<0b000, 0b011, "swgp", simm16_lsb00>, Sched<[]>;

let Predicates = [HasStdExtZceb, IsRV64] in
def LDGP : ZceGPLoad<0b010, 0b011, "ldgp", simm17_lsb000>, Sched<[]> {
  bits<17> imm;
  let Inst{22} = imm{16};
}

let Predicates = [HasStdExtZceb, IsRV64] in
def SDGP : ZceGPStore<0b010, 0b011, "sdgp", simm17_lsb000>, Sched<[]> {
  bits<17> imm;
  let Inst{9} = imm{16};
}

// 7.3. C.LBU, C.LHU, C.LB, C.LH, C.SB, C.SH
let Predicates = [HasStdExtZceb] in {

def C_LBU : ZceLoad_ri<0b001, 0b00, "c.lbu", GPRC, uimm4>,
           Sched<[]> {
  bits<4> imm;
  let Inst{12} = 0;
  let Inst{11-10} = imm{0, 3};
  let Inst{6-5} = imm{2-1};
}

def C_LHU : ZceLoad_ri<0b001, 0b00, "c.lhu", GPRC, uimm5_lsb0>,
           Sched<[]> {
  bits<5> imm;
  let Inst{12} = 1;
  let Inst{11-10} = imm{4-3};
  let Inst{6-5} = imm{2-1};
}

def C_LB : ZceLoad_ri<0b001, 0b10, "c.lb", GPRC, uimm4>,
          Sched<[]> {
  bits<4> imm;
  let Inst{12} = 0;
  let Inst{11-10} = imm{0, 3};
  let Inst{6-5} = imm{2-1};
}

def C_LH : ZceLoad_ri<0b001, 0b10, "c.lh", GPRC, uimm5_lsb0>,
          Sched<[]> {
  bits<5> imm;
  let Inst{12} = 1;
  let Inst{11-10} = imm{4-3};
  let Inst{6-5} = imm{2-1};
}

def C_SB : ZceStore_ri<0b101, 0b00, "c.sb", GPRC, uimm4>,
          Sched<[]> {
  bits<4> imm;
  let Inst{12} = 0;
  let Inst{11-10} = imm{0, 3};
  let Inst{6-5} = imm{2-1};
}

def C_SH : ZceStore_ri<0b101, 0b00, "c.sh", GPRC, uimm5_lsb0>,
          Sched<[]> {
  bits<5> imm;
  let Inst{12} = 1;
  let Inst{11-10} = imm{4-3};
  let Inst{6-5} = imm{2-1};
}

}
