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
class RVZcecInst16<bits<2> funct2, bits<3> opcode, string opcodestr>
    : RVInst16<(outs GPRC:$rs_wb), (ins GPRC:$rs), opcodestr, "$rs", [], InstFormatCR> {
  bits<3> rs;
  let Constraints = "$rs = $rs_wb";

  let Inst{15-13} = 0b100;
  let Inst{12-10} = 0b001;
  let Inst{9-7} = rs;
  let Inst{6-5} = funct2;
  let Inst{4-2} = opcode;
  let Inst{1-0} = 0b00;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class RVZcecInstC_MUL<bits<2> funct2, string opcodestr>
    : RVInst16<(outs GPRC:$rs1_wb), (ins GPRC:$rs1, GPRC:$rs2), opcodestr, "$rs1, $rs2", [], InstFormatCR> {
  bits<3> rs1;
  bits<3> rs2;
  let Constraints = "$rs1 = $rs_wb";

  let Inst{15-13} = 0b100;
  let Inst{12-10} = 0b001;
  let Inst{9-7} = rs1;
  let Inst{6-5} = funct2;
  let Inst{4-2} = rs2;
  let Inst{1-0} = 0b00;
}
