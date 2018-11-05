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
// Instruction class templates
//===----------------------------------------------------------------------===//

// mayLoad = 1 because vector ALU ops read the configuration CSRs
// and we model that as memory operand.
let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
class VALU_rr<bits<7> funct7, bits<1> funct1, RVVMaskCond m, string opcodestr>
    : RVInstVR<funct7, funct1, m, OPC_VEC_OP,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VLR:$vl),
               opcodestr, "$vd, $vs1, $vs2">;

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

let Predicates = [HasStdExtV] in {

def VADD : VALU_rr<0b1001000, 0b1, RVV_Unmasked, "vadd">;

} // Predicates = [HasStdExtV]
