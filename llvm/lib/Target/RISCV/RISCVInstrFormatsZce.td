//===-- RISCVInstrFormatsZce.td - RISCV Zce Instruction Formats --*- tablegen -*-=//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
//  This file describes the RISC-V Zce extension instruction formats.
//
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class RVZceArith_r<bits<2> funct2, bits<3> opcode, string opcodestr>
    : RVInst16<(outs GPRC:$rs_wb), (ins GPRC:$rs), opcodestr, "$rs", [], InstFormatCB> {
  bits<3> rs;
  let Constraints = "$rs = $rs_wb";

  let Inst{15-13} = 0b100;
  let Inst{12-10} = 0b111;
  let Inst{9-7} = rs;
  let Inst{6-5} = funct2;
  let Inst{4-2} = opcode;
  let Inst{1-0} = 0b01;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class RVZceArith_rr<bits<6> funct6,bits<2> funct2, bits<2> opcode, string opcodestr>
    : RVInst16<(outs GPRC:$rs1_wb), (ins GPRC:$rs1, GPRC:$rs2), opcodestr, "$rs1, $rs2", [], InstFormatCB> {
  bits<3> rs1;
  bits<3> rs2;
  let Constraints = "$rs1 = $rs1_wb";

  let Inst{15-10} = funct6;
  let Inst{9-7} = rs1;
  let Inst{6-5} = funct2;
  let Inst{4-2} = rs2;
  let Inst{1-0} = opcode;
}

class RVInstZceB<bits<3> funct3a, bits<3> funct3, bits<7> opcode, dag outs, dag ins,
                 string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatB> {
  bits<13> imm;
  bits<5> rd;

  let Inst{31-29} = funct3a;
  let Inst{14-12} = funct3;
  let Inst{11-7} = rd;
  let Inst{6-0} = opcode;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class RVInstZceTableJump_i<bits<3> funct3, string opcodestr, DAGOperand opnd>
    : RVInst16CJ<0b100, 0b00, (outs),(ins opnd:$imm8), opcodestr, "$imm8"> {
  bits<8> imm8;
  let DecoderNamespace  = "Zce"#NAME;

  let Inst{12-10} = funct3;
  let Inst{9-2} = imm8;
}

class RVInstZceCPPP<dag outs, dag ins, string opcodestr, string argstr>
    : RVInst16<outs, ins, opcodestr, argstr, [], InstFormatOther> {

      let Inst{1-0} = 0b10;
      let Inst{15-13} = 0b101;
}
