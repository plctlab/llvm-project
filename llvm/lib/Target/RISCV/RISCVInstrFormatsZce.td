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

class RVInstZceI<bits<3> funct3a, bits<3> funct3, bits<7> opcode, dag outs, dag ins,
                 string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatI> {
  bits<17> imm;
  bits<5> rd;
  bits<5> rs1;

  let Inst{31-29} = funct3a;
  let Inst{28-22} = imm{8-2};
  let Inst{21-20} = imm{10-9};
  let Inst{19-15} = imm{15-11};
  let Inst{14-12} = funct3;
  let Inst{11-7} = rd;
  let Inst{6-0} = opcode;
}

class RVInstZceS<bits<3> funct3a, bits<3> funct3, bits<7> opcode, dag outs, dag ins,
                 string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatS> {
  bits<17> imm;
  bits<5> rs1;
  bits<5> rs2;

  let Inst{31-29} = funct3a;
  let Inst{28-25} = imm{8-5};
  let Inst{24-20} = rs2;
  let Inst{19-15} = imm{15-11};
  let Inst{14-12} = funct3;
  let Inst{11-9} = imm{4-2};
  let Inst{8-7} = imm{10-9};
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

class RVInstZcePPP<bits<3> funct3, dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatOther> {
  bits<5> spimm;
  bits<4> rlist;

  let Inst{31-22} = 0b0000000000;
  let Inst{19-16} = rlist;
  let Inst{15} = 0b0;
  let Inst{14-12} = funct3;
  let Inst{11-7} = spimm;
  let Inst{6-0} = 0b0101011;
}

class RVInstZceCPPP<dag outs, dag ins, string opcodestr, string argstr>
    : RVInst16<outs, ins, opcodestr, argstr, [], InstFormatOther> {

      let Inst{1-0} = 0b00;
      let Inst{15-10} = 0b100011;
}
