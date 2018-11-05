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

class RVVMaskCond<bits<2> m> {
  bits<2> Value = m;
}

def RVV_Unmasked : RVVMaskCond<0b01>;

class RVInstVR<bits<7> funct7, bits<1> funct1, RVVMaskCond m, RISCVOpcode opcode, dag outs,
               dag ins, string opcodestr, string argstr>
    : RVInst<outs, ins, opcodestr, argstr, [], InstFormatR> {
  bits<5> vs2;
  bits<5> vs1;
  bits<5> vd;

  let Inst{31-25} = funct7;
  let Inst{24-20} = vs2;
  let Inst{19-15} = vs1;
  let Inst{14}    = funct1;
  let Inst{13-12} = m.Value;
  let Inst{11-7}  = vd;
  let Opcode = opcode.Value;
}
