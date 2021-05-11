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

// echo "c.zext.b s0" | bin/llvm-mc -triple=riscv64 -mattr=+experimental-zce -show-encoding
let Predicates = [HasStdExtZce] in
def C_ZEXT_B : RVZcecInst16<0b00, 0b000 , "c.zext.b">, Sched<[]>;

let Predicates = [HasStdExtZce] in
def C_SEXT_B : RVZcecInst16<0b00, 0b100 , "c.sext.b">, Sched<[]>;

let Predicates = [HasStdExtZce] in
def C_ZEXT_H : RVZcecInst16<0b00, 0b001 , "c.zext.h">, Sched<[]>;

let Predicates = [HasStdExtZce] in
def C_SEXT_H : RVZcecInst16<0b00, 0b101 , "c.sext.h">, Sched<[]>;

let Predicates = [HasStdExtZce, IsRV64] in
def C_ZEXT_W : RVZcecInst16<0b00, 0b010 , "c.zext.w">, Sched<[]>;

// def C_NOT : RVZcecInst16<0b00, 0b110 , "c.not">, Sched<[]>;
// def C_NEG : RVZcecInst16<0b00, 0b111 , "c.neg">, Sched<[]>;

// def C_MUL : RVZcecInstC_MUL<0b01, "c.mul">, Sched<[]>;

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

let Predicates = [HasStdExtZce] in {

def C_LBU: ZceLoad_ri<0b001, 0b00, "c.lbu", GPRC, uimm4>,
           Sched<[]> {
  bits<4> imm;
  let Inst{12} = 0;
  let Inst{11-10} = imm{0, 3};
  let Inst{6-5} = imm{2-1};
}

def C_LHU: ZceLoad_ri<0b001, 0b00, "c.lhu", GPRC, uimm5_lsb0>,
           Sched<[]> {
  bits<5> imm;
  let Inst{12} = 1;
  let Inst{11-10} = imm{4-3};
  let Inst{6-5} = imm{2-1};
}

def C_LB: ZceLoad_ri<0b101, 0b10, "c.lb", GPRC, uimm4>,
          Sched<[]> {
  bits<4> imm;
  let Inst{12} = 0;
  let Inst{11-10} = imm{0, 3};
  let Inst{6-5} = imm{2-1};
}

def C_LH: ZceLoad_ri<0b101, 0b10, "c.lh", GPRC, uimm5_lsb0>,
          Sched<[]> {
  bits<5> imm;
  let Inst{12} = 1;
  let Inst{11-10} = imm{4-3};
  let Inst{6-5} = imm{2-1};
}

def C_SB: ZceStore_ri<0b101, 0b00, "c.sb", GPRC, uimm4>,
          Sched<[]> {
  bits<4> imm;
  let Inst{12} = 0;
  let Inst{11-10} = imm{0, 3};
  let Inst{6-5} = imm{2-1};
}

def C_SH: ZceStore_ri<0b101, 0b00, "c.sh", GPRC, uimm5_lsb0>,
          Sched<[]> {
  bits<5> imm;
  let Inst{12} = 1;
  let Inst{11-10} = imm{4-3};
  let Inst{6-5} = imm{2-1};
}

}
