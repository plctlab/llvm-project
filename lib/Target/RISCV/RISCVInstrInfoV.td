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
// Operand and SDNode transformation definitions.
//===----------------------------------------------------------------------===//

def simm3 : Operand<XLenVT>, ImmLeaf<XLenVT, [{return isInt<3>(Imm);}]> {
  let ParserMatchClass = SImmAsmOperand<3>;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeSImmOperand<3>";
}

//===----------------------------------------------------------------------===//
// Instruction class templates
//===----------------------------------------------------------------------===//

// mayLoad = 1 because vector ALU ops read the configuration CSRs
// and we model that as memory operand.
let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
class VALU_rr<bits<7> funct7, bits<1> funct1, string opcodestr>
    : RVInstVR<funct7, funct1, RVV_Unmasked, OPC_VEC_OP,
               (outs VR:$vd), (ins VR:$vs1, VR:$vs2, VLR:$vl),
               opcodestr, "$vd, $vs1, $vs2">;

let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
class VLoad_UnitStride<bits<2> funct2, bits<3> funct3, string opcodestr>
    : RVInstVLoad<funct2, funct3, RVV_Unmasked, OPC_LOAD_FP,
                  (outs VR:$vd), (ins GPR:$rs1, VLR:$vl, simm3:$imm3),
                  opcodestr, "$vd, ${imm3}(${rs1})">;

// mayLoad = 1 because stores read the configuration CSRs
// and we model that as memory operand.
let hasSideEffects = 0, mayLoad = 1, mayStore = 1 in
class VStore_UnitStride<bits<3> funct3, bits<2> funct2, string opcodestr>
    : RVInstVStore<funct3, funct2, RVV_Unmasked, OPC_STORE_FP,
                   (outs), (ins GPR:$rs1, VR:$vs3, VLR:$vl, simm3:$imm3),
                   opcodestr, "$vs3, ${imm3}(${rs1})">;


class ImplicitVCFGPseudo<RVInst ExplicitInst>
    : Pseudo<ExplicitInst.OutOperandList, ExplicitInst.InOperandList, []> {
  let isCodeGenOnly = 1;
  let isAsmParserOnly = 0;
  // These fields are stored solely for the benefit of the VCFG access table.
  // Note that we need the ISD enumerator that MachineInstr::getOpcode returns,
  // not the 7-bit "Opcode" field of the RISC-V instruction encoding.
  Instruction ImplicitOpcode = !cast<Instruction>(NAME);
  Instruction ExplicitOpcode = ExplicitInst;
}

//===----------------------------------------------------------------------===//
// VCFG access table.
//
// Generate a table mapping the pseudos with implicit VCFG access to the
// corresponding real instruction.
// This information is used in the RISCVIntroduceVCFGUses pass.
//===----------------------------------------------------------------------===//

def ImplicitVCFGTable : GenericTable {
  let FilterClass = "ImplicitVCFGPseudo";
  let CppTypeName = "ImplicitVCFGInfo";
  let Fields = [ "ImplicitOpcode", "ExplicitOpcode" ];
  let PrimaryKey = [ "ImplicitOpcode" ];
  let PrimaryKeyName = "getImplicitVCFGInfo";
}

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

let Predicates = [HasStdExtV] in {

def VADD : VALU_rr<0b1001000, 0b1, "vadd">;

// This *_ic pseudo is just an example (and makes the build work), these
// pseudos only become important once instruction selection work starts.
let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def VADD_ic : ImplicitVCFGPseudo<ADD>;

def VLW : VLoad_UnitStride<0b00, 0b110, "vlw">;

def VSW : VStore_UnitStride<0b110, 0b00, "vsw">;

// mayLoad = 1 because vsetvl reads the configuration CSRs
// and we model that as memory operand.
let hasSideEffects = 0, mayLoad = 1, mayStore = 0 in
def VSETVL: RVInst<(outs VLR:$vl, GPR:$rd), (ins GPR:$rs1),
                   "vsetvl", "$rd, $rs1", [], InstFormatOther>
{
  bits<5> rs1;
  bits<5> rd;

  let Inst{31-28} = 0b1111;
  let Inst{27-25} = 0b000;
  let Inst{24-20} = 0b00000;
  let Inst{19-15} = rs1;
  let Inst{14} = 0b1;
  let Inst{13-12} = 0b00;
  let Inst{11-7} = rd;
  let Opcode = OPC_VEC_OP.Value;
}

// mayStore = 1 because vconfig writes the configuration CSRs
// and we model that as memory operand.
let hasSideEffects = 0, mayLoad = 0, mayStore = 1 in
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
  let Opcode = OPC_VEC_OP.Value;
}

} // Predicates = [HasStdExtV]
