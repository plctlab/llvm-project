//===-- RISCVInstrFormatsV.td - RISCV V Instruction Formats --*- tablegen -*-=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
//  This file describes the RISC-V V extension instruction formats.
//
//  NOTE: these formats are not frozen and not even officially named yet
//
//===----------------------------------------------------------------------===//

class RVVMaskCond<bits<1> m> {
  bits<1> Value = m;
}

def RVV_Unmasked : RVVMaskCond<0b1>;
def RVV_Masked : RVVMaskCond<0b0>;


// Format for Vector Load Instructions under LOAD-FP major opcode
class RVInstVLoad<bits<3> nf, bits<3> mop, bits<3> width, RVVMaskCond m,
                  RISCVOpcode opcode, dag outs, dag ins,
                  string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatOther /* TODO */> {
  bits<5> rs1;
  bits<5> vd;

  let Inst{31-29} = nf;
  let Inst{28-26} = mop;
  let Inst{25}    = m.Value;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Inst{11-7}  = vd;
  let Opcode = opcode.Value;
}

// Format for Vector Store Instructions under STORE-FP major opcode
class RVInstVStore<bits<3> nf, bits<3> mop, bits<3> width, RVVMaskCond m,
                   RISCVOpcode opcode, dag outs, dag ins,
                   string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatOther /* TODO */> {
  bits<5> rs1;
  bits<5> vs3;

  let Inst{31-29} = nf;
  let Inst{28-26} = mop;
  let Inst{25}    = m.Value;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Inst{11-7}  = vs3;
  let Opcode = opcode.Value;
}



// Format for Vector AMO Instructions under AMO major opcode
class RVInstVAMO<bits<5> amoop, bits<1> wd, bits<3> width, RVVMaskCond m,
                   RISCVOpcode opcode, dag outs, dag ins,
                   string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatOther /* TODO */> {
  bits<5> rs1;
  bits<5> vs2;

  let Inst{31-27} = amoop;
  let Inst{26}    = wd;
  let Inst{25}    = m.Value;
  let Inst{24-20} = vs2;
  let Inst{19-15} = rs1;
  let Inst{14-12} = width;
  let Opcode = opcode.Value;
}


// Formats for Vector Arithmetic Instructions under OP-V major opcode
class RVInstVA<bits<6> funct6, bits<3> funct3, RVVMaskCond m, RISCVOpcode opcode,
               dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatOther> {
  bits<5> vs2;
  bits<5> vd;

  let Inst{31-26} = funct6;
  let Inst{25}    = m.Value;
  let Inst{24-20} = vs2;
  let Inst{14-12} = funct3;
  let Inst{11-7}  = vd;
  let Opcode = opcode.Value;
}

// Formats for Vector Configuration Instructions under OP-V major opcode
class RVInstVSet<bits<1> funct1, RISCVOpcode opcode,
               dag outs, dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatOther> {
  bits<5> rs1;
  bits<5> rd;

  let Inst{31}    = funct1;
  let Inst{19-15} = rs1;
  let Inst{14-12} = 0b111;
  let Inst{11-7}  = rd;
  let Opcode = opcode.Value;
}