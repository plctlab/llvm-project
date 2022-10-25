//===-- RISCVInstrInfoP.td - RISC-V 'P' instructions -------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
///
/// This file describes the RISC-V instructions from the standard 'P' SIMD
/// extension, version 0.9.6.
/// This version is still experimental as the 'P' extension hasn't been
/// ratified yet.
///
//===----------------------------------------------------------------------===//

//===----------------------------------------------------------------------===//
// Operand and SDNode transformation definitions.
//===----------------------------------------------------------------------===//

def uimm4 : Operand<XLenVT>, ImmLeaf<XLenVT, [{return isUInt<4>(Imm);}]> {
  let ParserMatchClass = UImmAsmOperand<4>;
  let DecoderMethod = "decodeUImmOperand<4>";
  let OperandType = "OPERAND_UIMM4";
  let OperandNamespace = "RISCVOp";
}

def UImmLog2XLenBytesAsmOperand : AsmOperandClass {
  let Name = "UImmLog2XLenBytes";
  let RenderMethod = "addImmOperands";
  let DiagnosticType = "InvalidUImmLog2XLenBytes";
}

def uimmlog2xlenbytes : Operand<XLenVT>, ImmLeaf<XLenVT, [{
  if (Subtarget->is64Bit())
    return isUInt<3>(Imm);
  return isUInt<2>(Imm);
}]> {
  let ParserMatchClass = UImmLog2XLenBytesAsmOperand;
  let DecoderMethod = "decodeUImmOperand<3>";
  let MCOperandPredicate = [{
    int64_t Imm;
    if (!MCOp.evaluateAsConstantImm(Imm))
      return false;
    if (STI.getTargetTriple().isArch64Bit())
      return isUInt<3>(Imm);
    return isUInt<2>(Imm);
  }];
  let OperandType = "OPERAND_UIMMLOG2XLENBYTES";
  let OperandNamespace = "RISCVOp";
}

def GPR32PairOpOperand : AsmOperandClass {
  let Name = "GPR32PairOpOperand";
  let RenderMethod = "addRegOperands";
  let PredicateMethod = "isGPR32Pair";
  let ParserMethod = "parseGPR32PairReg";
}

def GPR32PairOp : RegisterOperand<GPR32Pair> {
  let ParserMatchClass = GPR32PairOpOperand;
}

//===----------------------------------------------------------------------===//
// Instruction class templates
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class RVPUnary<bits<7> funct7, bits<5> funct5, bits<3> funct3, string opcodestr>
    : RVInstR<funct7, funct3, OPC_OP_P, (outs GPR:$rd), (ins GPR:$rs1),
              opcodestr, "$rd, $rs1"> {
  let Inst{24-20} = funct5;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class RVPBinary<bits<7> funct7, bits<3> funct3, string opcodestr,
                DAGOperand rd_kind = GPR, DAGOperand rs1_kind = GPR,
                DAGOperand rs2_kind = GPR>
    : RVInstR<funct7, funct3, OPC_OP_P,
              (outs rd_kind:$rd), (ins rs1_kind:$rs1, rs2_kind:$rs2),
              opcodestr, "$rd, $rs1, $rs2">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class RVPTernary<bits<7> funct7, bits<3> funct3, string opcodestr,
                 DAGOperand rd_kind = GPR>
    : RVInstR<funct7, funct3, OPC_OP_P,
              (outs rd_kind:$rd), (ins rd_kind:$rs3, GPR:$rs1, GPR:$rs2),
              opcodestr, "$rd, $rs1, $rs2"> {
  let Constraints = "$rs3 = $rd";
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class RVPShiftI3<bits<7> funct7, bits<2> funct2,
                 bits<3> funct3, string opcodestr>
    : RVInstI<funct3, OPC_OP_P, (outs GPR:$rd), (ins GPR:$rs1, uimm3:$shamt),
              opcodestr, "$rd, $rs1, $shamt"> {
  bits<3> shamt;

  let Inst{31-25} = funct7;
  let Inst{24-23} = funct2;
  let Inst{22-20} = shamt;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class RVPShiftI4<bits<7> funct7, bits<1> funct1,
                 bits<3> funct3, string opcodestr>
    : RVInstI<funct3, OPC_OP_P, (outs GPR:$rd), (ins GPR:$rs1, uimm4:$shamt),
              opcodestr, "$rd, $rs1, $shamt"> {
  bits<4> shamt;

  let Inst{31-25} = funct7;
  let Inst{24} = funct1;
  let Inst{23-20} = shamt;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class RVPShiftI5<bits<7> funct7, bits<3> funct3, string opcodestr, 
                 DAGOperand rs1_kind = GPR>
    : RVInstI<funct3, OPC_OP_P, (outs GPR:$rd), (ins rs1_kind:$rs1, uimm5:$shamt),
              opcodestr, "$rd, $rs1, $shamt"> {
  bits<5> shamt;

  let Inst{31-25} = funct7;
  let Inst{24-20} = shamt;
}

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class RVPShiftUImmLog2XLen<bits<6> funct6, bits<3> funct3, string opcodestr>
    : RVInstI<funct3, OPC_OP_P, (outs GPR:$rd),
              (ins GPR:$rs1, uimmlog2xlen:$shamt),
              opcodestr, "$rd, $rs1, $shamt"> {
  bits<6> shamt;

  let Inst{31-26} = funct6;
  let Inst{25-20} = shamt;
}

multiclass RVPALU64<bits<7> funct7, bits<3> funct3, string opcodestr> {
  let DecoderNamespace = "RISCV32Only_",
      Predicates = [HasStdExtZpsfoperand, IsRV32] in
  def "_32" : RVPBinary<funct7, funct3, opcodestr, GPR32PairOp,
                        GPR32PairOp, GPR32PairOp>;
  let Predicates = [HasStdExtZpsfoperand, IsRV64] in
  def "_64" : RVPBinary<funct7, funct3, opcodestr>;
}

multiclass RVPSMAL64<bits<7> funct7, bits<3> funct3, string opcodestr> {
  let DecoderNamespace = "RISCV32Only_",
      Predicates = [HasStdExtZpsfoperand, IsRV32] in
  def "_32" : RVPBinary<funct7, funct3, opcodestr, GPR32PairOp, GPR32PairOp>;
  let Predicates = [HasStdExtZpsfoperand, IsRV64] in
  def "_64" : RVPBinary<funct7, funct3, opcodestr>;
}

multiclass RVPMUL64<bits<7> funct7, bits<3> funct3, string opcodestr> {
  let DecoderNamespace = "RISCV32Only_",
      Predicates = [HasStdExtZpsfoperand, IsRV32] in
  def "_32" : RVPBinary<funct7, funct3, opcodestr, GPR32PairOp>;
  let Predicates = [HasStdExtZpsfoperand, IsRV64] in
  def "_64" : RVPBinary<funct7, funct3, opcodestr>;
}

multiclass RVPMA64<bits<7> funct7, bits<3> funct3, string opcodestr> {
  let DecoderNamespace = "RISCV32Only_",
      Predicates = [HasStdExtZpsfoperand, IsRV32] in
  def "_32" : RVPTernary<funct7, funct3, opcodestr, GPR32PairOp>;
  let Predicates = [HasStdExtZpsfoperand, IsRV64] in
  def "_64" : RVPTernary<funct7, funct3, opcodestr>;
}

multiclass RVPWEXT<bits<7> funct7, bits<3> funct3, string opcodestr> {
  let DecoderNamespace = "RISCV32Only_",
      Predicates = [HasStdExtZpsfoperand, IsRV32] in
  def "_32" : RVPBinary<funct7, funct3, opcodestr, GPR, GPR32PairOp>;
  let Predicates = [HasStdExtZpsfoperand, IsRV64] in
  def "_64" : RVPBinary<funct7, funct3, opcodestr>;
}

multiclass RVPWEXTI<bits<7> funct7, bits<3> funct3, string opcodestr> {
  let DecoderNamespace = "RISCV32Only_",
      Predicates = [HasStdExtZpsfoperand, IsRV32] in
  def "_32" : RVPShiftI5<funct7, funct3, opcodestr, GPR32PairOp>;
  let Predicates = [HasStdExtZpsfoperand, IsRV64] in
  def "_64" : RVPShiftI5<funct7, funct3, opcodestr>;
}

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

// TODO: Add scheduling information for these instructions.

// Unary Instructions

let Predicates = [HasStdExtZpn] in {
def CLRS8     : RVPUnary<0b1010111, 0b00000, 0b000, "clrs8">,
                Sched<[]>;
def CLRS16    : RVPUnary<0b1010111, 0b01000, 0b000, "clrs16">,
                Sched<[]>;
def CLRS32    : RVPUnary<0b1010111, 0b11000, 0b000, "clrs32">,
                Sched<[]>;
def CLZ8      : RVPUnary<0b1010111, 0b00001, 0b000, "clz8">,
                Sched<[]>;
def CLZ16     : RVPUnary<0b1010111, 0b01001, 0b000, "clz16">,
                Sched<[]>;
def CLZ32     : RVPUnary<0b1010111, 0b11001, 0b000, "clz32">,
                Sched<[]>;
def KABS8     : RVPUnary<0b1010110, 0b10000, 0b000, "kabs8">,
                Sched<[]>;
def KABS16    : RVPUnary<0b1010110, 0b10001, 0b000, "kabs16">,
                Sched<[]>;
def KABSW     : RVPUnary<0b1010110, 0b10100, 0b000, "kabsw">,
                Sched<[]>;
def SUNPKD810 : RVPUnary<0b1010110, 0b01000, 0b000, "sunpkd810">,
                Sched<[]>;
def SUNPKD820 : RVPUnary<0b1010110, 0b01001, 0b000, "sunpkd820">,
                Sched<[]>;
def SUNPKD830 : RVPUnary<0b1010110, 0b01010, 0b000, "sunpkd830">,
                Sched<[]>;
def SUNPKD831 : RVPUnary<0b1010110, 0b01011, 0b000, "sunpkd831">,
                Sched<[]>;
def SUNPKD832 : RVPUnary<0b1010110, 0b10011, 0b000, "sunpkd832">,
                Sched<[]>;
def SWAP8     : RVPUnary<0b1010110, 0b11000, 0b000, "swap8">,
                Sched<[]>;
def ZUNPKD810 : RVPUnary<0b1010110, 0b01100, 0b000, "zunpkd810">,
                Sched<[]>;
def ZUNPKD820 : RVPUnary<0b1010110, 0b01101, 0b000, "zunpkd820">,
                Sched<[]>;
def ZUNPKD830 : RVPUnary<0b1010110, 0b01110, 0b000, "zunpkd830">,
                Sched<[]>;
def ZUNPKD831 : RVPUnary<0b1010110, 0b01111, 0b000, "zunpkd831">,
                Sched<[]>;
def ZUNPKD832 : RVPUnary<0b1010110, 0b10111, 0b000, "zunpkd832">,
                Sched<[]>;
} // Predicates = [HasStdExtZpn]

let Predicates = [HasStdExtZpn, IsRV64] in
def KABS32 : RVPUnary<0b1010110, 0b10010, 0b000, "kabs32">,
             Sched<[]>;

// Binary Instructions

let Predicates = [HasStdExtZpn] in {
def ADD8     : RVPBinary<0b0100100, 0b000, "add8">,
               Sched<[]>;
def ADD16    : RVPBinary<0b0100000, 0b000, "add16">,
               Sched<[]>;
def AVE      : RVPBinary<0b1110000, 0b000, "ave">,
               Sched<[]>;
def BITREV   : RVPBinary<0b1110011, 0b000, "bitrev">,
               Sched<[]>;
def CMPEQ8   : RVPBinary<0b0100111, 0b000, "cmpeq8">,
               Sched<[]>;
def CMPEQ16  : RVPBinary<0b0100110, 0b000, "cmpeq16">,
               Sched<[]>;
def CRAS16   : RVPBinary<0b0100010, 0b000, "cras16">,
               Sched<[]>;
def CRSA16   : RVPBinary<0b0100011, 0b000, "crsa16">,
               Sched<[]>;
def KADD8    : RVPBinary<0b0001100, 0b000, "kadd8">,
               Sched<[]>;
def KADD16   : RVPBinary<0b0001000, 0b000, "kadd16">,
               Sched<[]>;
def KADDH    : RVPBinary<0b0000010, 0b001, "kaddh">,
               Sched<[]>;
def KADDW    : RVPBinary<0b0000000, 0b001, "kaddw">,
               Sched<[]>;
def KCRAS16  : RVPBinary<0b0001010, 0b000, "kcras16">,
               Sched<[]>;
def KCRSA16  : RVPBinary<0b0001011, 0b000, "kcrsa16">,
               Sched<[]>;
def KDMBB    : RVPBinary<0b0000101, 0b001, "kdmbb">,
               Sched<[]>;
def KDMBT    : RVPBinary<0b0001101, 0b001, "kdmbt">,
               Sched<[]>;
def KDMTT    : RVPBinary<0b0010101, 0b001, "kdmtt">,
               Sched<[]>;
def KHM8     : RVPBinary<0b1000111, 0b000, "khm8">,
               Sched<[]>;
def KHMX8    : RVPBinary<0b1001111, 0b000, "khmx8">,
               Sched<[]>;
def KHM16    : RVPBinary<0b1000011, 0b000, "khm16">,
               Sched<[]>;
def KHMX16   : RVPBinary<0b1001011, 0b000, "khmx16">,
               Sched<[]>;
def KHMBB    : RVPBinary<0b0000110, 0b001, "khmbb">,
               Sched<[]>;
def KHMBT    : RVPBinary<0b0001110, 0b001, "khmbt">,
               Sched<[]>;
def KHMTT    : RVPBinary<0b0010110, 0b001, "khmtt">,
               Sched<[]>;
def KMDA     : RVPBinary<0b0011100, 0b001, "kmda">,
               Sched<[]>;
def KMXDA    : RVPBinary<0b0011101, 0b001, "kmxda">,
               Sched<[]>;
def KMMWB2   : RVPBinary<0b1000111, 0b001, "kmmwb2">,
               Sched<[]>;
def KMMWB2U  : RVPBinary<0b1001111, 0b001, "kmmwb2.u">,
               Sched<[]>;
def KMMWT2   : RVPBinary<0b1010111, 0b001, "kmmwt2">,
               Sched<[]>;
def KMMWT2U  : RVPBinary<0b1011111, 0b001, "kmmwt2.u">,
               Sched<[]>;
def KSLLW    : RVPBinary<0b0010011, 0b001, "ksllw">,
               Sched<[]>;
def KSLL8    : RVPBinary<0b0110110, 0b000, "ksll8">,
               Sched<[]>;
def KSLL16   : RVPBinary<0b0110010, 0b000, "ksll16">,
               Sched<[]>;
def KSLRA8   : RVPBinary<0b0101111, 0b000, "kslra8">,
               Sched<[]>;
def KSLRA8U  : RVPBinary<0b0110111, 0b000, "kslra8.u">,
               Sched<[]>;
def KSLRA16  : RVPBinary<0b0101011, 0b000, "kslra16">,
               Sched<[]>;
def KSLRA16U : RVPBinary<0b0110011, 0b000, "kslra16.u">,
               Sched<[]>;
def KSLRAW   : RVPBinary<0b0110111, 0b001, "kslraw">,
               Sched<[]>;
def KSLRAWU  : RVPBinary<0b0111111, 0b001, "kslraw.u">,
               Sched<[]>;
def KSTAS16  : RVPBinary<0b1100010, 0b010, "kstas16">,
               Sched<[]>;
def KSTSA16  : RVPBinary<0b1100011, 0b010, "kstsa16">,
               Sched<[]>;
def KSUB8    : RVPBinary<0b0001101, 0b000, "ksub8">,
               Sched<[]>;
def KSUB16   : RVPBinary<0b0001001, 0b000, "ksub16">,
               Sched<[]>;
def KSUBH    : RVPBinary<0b0000011, 0b001, "ksubh">,
               Sched<[]>;
def KSUBW    : RVPBinary<0b0000001, 0b001, "ksubw">,
               Sched<[]>;
def KWMMUL   : RVPBinary<0b0110001, 0b001, "kwmmul">,
               Sched<[]>;
def KWMMULU  : RVPBinary<0b0111001, 0b001, "kwmmul.u">,
               Sched<[]>;
def MAXW     : RVPBinary<0b1111001, 0b000, "maxw">,
               Sched<[]>;
def MINW     : RVPBinary<0b1111000, 0b000, "minw">,
               Sched<[]>;
def PBSAD    : RVPBinary<0b1111110, 0b000, "pbsad">,
               Sched<[]>;
def PKBB16   : RVPBinary<0b0000111, 0b001, "pkbb16">,
               Sched<[]>;
def PKBT16   : RVPBinary<0b0001111, 0b001, "pkbt16">,
               Sched<[]>;
def PKTT16   : RVPBinary<0b0010111, 0b001, "pktt16">,
               Sched<[]>;
def PKTB16   : RVPBinary<0b0011111, 0b001, "pktb16">,
               Sched<[]>;
def RADD8    : RVPBinary<0b0000100, 0b000, "radd8">,
               Sched<[]>;
def RADD16   : RVPBinary<0b0000000, 0b000, "radd16">,
               Sched<[]>;
def RADDW    : RVPBinary<0b0010000, 0b001, "raddw">,
               Sched<[]>;
def RCRAS16  : RVPBinary<0b0000010, 0b000, "rcras16">,
               Sched<[]>;
def RCRSA16  : RVPBinary<0b0000011, 0b000, "rcrsa16">,
               Sched<[]>;
def RSTAS16  : RVPBinary<0b1011010, 0b010, "rstas16">,
               Sched<[]>;
def RSTSA16  : RVPBinary<0b1011011, 0b010, "rstsa16">,
               Sched<[]>;
def RSUB8    : RVPBinary<0b0000101, 0b000, "rsub8">,
               Sched<[]>;
def RSUB16   : RVPBinary<0b0000001, 0b000, "rsub16">,
               Sched<[]>;
def RSUBW    : RVPBinary<0b0010001, 0b001, "rsubw">,
               Sched<[]>;
def SCMPLE8  : RVPBinary<0b0001111, 0b000, "scmple8">,
               Sched<[]>;
def SCMPLE16 : RVPBinary<0b0001110, 0b000, "scmple16">,
               Sched<[]>;
def SCMPLT8  : RVPBinary<0b0000111, 0b000, "scmplt8">,
               Sched<[]>;
def SCMPLT16 : RVPBinary<0b0000110, 0b000, "scmplt16">,
               Sched<[]>;
def SLL8     : RVPBinary<0b0101110, 0b000, "sll8">,
               Sched<[]>;
def SLL16    : RVPBinary<0b0101010, 0b000, "sll16">,
               Sched<[]>;
def SMAX8    : RVPBinary<0b1000101, 0b000, "smax8">,
               Sched<[]>;
def SMAX16   : RVPBinary<0b1000001, 0b000, "smax16">,
               Sched<[]>;
def SMBB16   : RVPBinary<0b0000100, 0b001, "smbb16">,
               Sched<[]>;
def SMBT16   : RVPBinary<0b0001100, 0b001, "smbt16">,
               Sched<[]>;
def SMTT16   : RVPBinary<0b0010100, 0b001, "smtt16">,
               Sched<[]>;
def SMDS     : RVPBinary<0b0101100, 0b001, "smds">,
               Sched<[]>;
def SMDRS    : RVPBinary<0b0110100, 0b001, "smdrs">,
               Sched<[]>;
def SMXDS    : RVPBinary<0b0111100, 0b001, "smxds">,
               Sched<[]>;
def SMIN8    : RVPBinary<0b1000100, 0b000, "smin8">,
               Sched<[]>;
def SMIN16   : RVPBinary<0b1000000, 0b000, "smin16">,
               Sched<[]>;
def SMMUL    : RVPBinary<0b0100000, 0b001, "smmul">,
               Sched<[]>;
def SMMULU   : RVPBinary<0b0101000, 0b001, "smmul.u">,
               Sched<[]>;
def SMMWB    : RVPBinary<0b0100010, 0b001, "smmwb">,
               Sched<[]>;
def SMMWBU   : RVPBinary<0b0101010, 0b001, "smmwb.u">,
               Sched<[]>;
def SMMWT    : RVPBinary<0b0110010, 0b001, "smmwt">,
               Sched<[]>;
def SMMWTU   : RVPBinary<0b0111010, 0b001, "smmwt.u">,
               Sched<[]>;
def SRAU     : RVPBinary<0b0010010, 0b001, "sra.u">,
               Sched<[]>;
def SRA8     : RVPBinary<0b0101100, 0b000, "sra8">,
               Sched<[]>;
def SRA8U    : RVPBinary<0b0110100, 0b000, "sra8.u">,
               Sched<[]>;
def SRA16    : RVPBinary<0b0101000, 0b000, "sra16">,
               Sched<[]>;
def SRA16U   : RVPBinary<0b0110000, 0b000, "sra16.u">,
               Sched<[]>;
def SRL8     : RVPBinary<0b0101101, 0b000, "srl8">,
               Sched<[]>;
def SRL8U    : RVPBinary<0b0110101, 0b000, "srl8.u">,
               Sched<[]>;
def SRL16    : RVPBinary<0b0101001, 0b000, "srl16">,
               Sched<[]>;
def SRL16U   : RVPBinary<0b0110001, 0b000, "srl16.u">,
               Sched<[]>;
def STAS16   : RVPBinary<0b1111010, 0b010, "stas16">,
               Sched<[]>;
def STSA16   : RVPBinary<0b1111011, 0b010, "stsa16">,
               Sched<[]>;
def SUB8     : RVPBinary<0b0100101, 0b000, "sub8">,
               Sched<[]>;
def SUB16    : RVPBinary<0b0100001, 0b000, "sub16">,
               Sched<[]>;
def UCMPLE8  : RVPBinary<0b0011111, 0b000, "ucmple8">,
               Sched<[]>;
def UCMPLE16 : RVPBinary<0b0011110, 0b000, "ucmple16">,
               Sched<[]>;
def UCMPLT8  : RVPBinary<0b0010111, 0b000, "ucmplt8">,
               Sched<[]>;
def UCMPLT16 : RVPBinary<0b0010110, 0b000, "ucmplt16">,
               Sched<[]>;
def UKADD8   : RVPBinary<0b0011100, 0b000, "ukadd8">,
               Sched<[]>;
def UKADD16  : RVPBinary<0b0011000, 0b000, "ukadd16">,
               Sched<[]>;
def UKADDH   : RVPBinary<0b0001010, 0b001, "ukaddh">,
               Sched<[]>;
def UKADDW   : RVPBinary<0b0001000, 0b001, "ukaddw">,
               Sched<[]>;
def UKCRAS16 : RVPBinary<0b0011010, 0b000, "ukcras16">,
               Sched<[]>;
def UKCRSA16 : RVPBinary<0b0011011, 0b000, "ukcrsa16">,
               Sched<[]>;
def UKSTAS16 : RVPBinary<0b1110010, 0b010, "ukstas16">,
               Sched<[]>;
def UKSTSA16 : RVPBinary<0b1110011, 0b010, "ukstsa16">,
               Sched<[]>;
def UKSUB8   : RVPBinary<0b0011101, 0b000, "uksub8">,
               Sched<[]>;
def UKSUB16  : RVPBinary<0b0011001, 0b000, "uksub16">,
               Sched<[]>;
def UKSUBH   : RVPBinary<0b0001011, 0b001, "uksubh">,
               Sched<[]>;
def UKSUBW   : RVPBinary<0b0001001, 0b001, "uksubw">,
               Sched<[]>;
def UMAX8    : RVPBinary<0b1001101, 0b000, "umax8">,
               Sched<[]>;
def UMAX16   : RVPBinary<0b1001001, 0b000, "umax16">,
               Sched<[]>;
def UMIN8    : RVPBinary<0b1001100, 0b000, "umin8">,
               Sched<[]>;
def UMIN16   : RVPBinary<0b1001000, 0b000, "umin16">,
               Sched<[]>;
def URADD8   : RVPBinary<0b0010100, 0b000, "uradd8">,
               Sched<[]>;
def URADD16  : RVPBinary<0b0010000, 0b000, "uradd16">,
               Sched<[]>;
def URADDW   : RVPBinary<0b0011000, 0b001, "uraddw">,
               Sched<[]>;
def URCRAS16 : RVPBinary<0b0010010, 0b000, "urcras16">,
               Sched<[]>;
def URCRSA16 : RVPBinary<0b0010011, 0b000, "urcrsa16">,
               Sched<[]>;
def URSTAS16 : RVPBinary<0b1101010, 0b010, "urstas16">,
               Sched<[]>;
def URSTSA16 : RVPBinary<0b1101011, 0b010, "urstsa16">,
               Sched<[]>;
def URSUB8   : RVPBinary<0b0010101, 0b000, "ursub8">,
               Sched<[]>;
def URSUB16  : RVPBinary<0b0010001, 0b000, "ursub16">,
               Sched<[]>;
def URSUBW   : RVPBinary<0b0011001, 0b001, "ursubw">,
               Sched<[]>;
} // Predicates = [HasStdExtZpn]

let Predicates = [HasStdExtZpn, IsRV64] in {
def ADD32    : RVPBinary<0b0100000, 0b010, "add32">,
               Sched<[]>;
def CRAS32   : RVPBinary<0b0100010, 0b010, "cras32">,
               Sched<[]>;
def CRSA32   : RVPBinary<0b0100011, 0b010, "crsa32">,
               Sched<[]>;
def KADD32   : RVPBinary<0b0001000, 0b010, "kadd32">,
               Sched<[]>;
def KCRAS32  : RVPBinary<0b0001010, 0b010, "kcras32">,
               Sched<[]>;
def KCRSA32  : RVPBinary<0b0001011, 0b010, "kcrsa32">,
               Sched<[]>;
def KDMBB16  : RVPBinary<0b1101101, 0b001, "kdmbb16">,
               Sched<[]>;
def KDMBT16  : RVPBinary<0b1110101, 0b001, "kdmbt16">,
               Sched<[]>;
def KDMTT16  : RVPBinary<0b1111101, 0b001, "kdmtt16">,
               Sched<[]>;
def KHMBB16  : RVPBinary<0b1101110, 0b001, "khmbb16">,
               Sched<[]>;
def KHMBT16  : RVPBinary<0b1110110, 0b001, "khmbt16">,
               Sched<[]>;
def KHMTT16  : RVPBinary<0b1111110, 0b001, "khmtt16">,
               Sched<[]>;
def KMDA32   : RVPBinary<0b0011100, 0b010, "kmda32">,
               Sched<[]>;
def KMXDA32  : RVPBinary<0b0011101, 0b010, "kmxda32">,
               Sched<[]>;
def KSLL32   : RVPBinary<0b0110010, 0b010, "ksll32">,
               Sched<[]>;
def KSLRA32  : RVPBinary<0b0101011, 0b010, "kslra32">,
               Sched<[]>;
def KSLRA32U : RVPBinary<0b0110011, 0b010, "kslra32.u">,
               Sched<[]>;
def KSTAS32  : RVPBinary<0b1100000, 0b010, "kstas32">,
               Sched<[]>;
def KSTSA32  : RVPBinary<0b1100001, 0b010, "kstsa32">,
               Sched<[]>;
def KSUB32   : RVPBinary<0b0001001, 0b010, "ksub32">,
               Sched<[]>;
def PKBB32   : RVPBinary<0b0000111, 0b010, "pkbb32">,
               Sched<[]>;
def PKBT32   : RVPBinary<0b0001111, 0b010, "pkbt32">,
               Sched<[]>;
def PKTT32   : RVPBinary<0b0010111, 0b010, "pktt32">,
               Sched<[]>;
def PKTB32   : RVPBinary<0b0011111, 0b010, "pktb32">,
               Sched<[]>;
def RADD32   : RVPBinary<0b0000000, 0b010, "radd32">,
               Sched<[]>;
def RCRAS32  : RVPBinary<0b0000010, 0b010, "rcras32">,
               Sched<[]>;
def RCRSA32  : RVPBinary<0b0000011, 0b010, "rcrsa32">,
               Sched<[]>;
def RSTAS32  : RVPBinary<0b1011000, 0b010, "rstas32">,
               Sched<[]>;
def RSTSA32  : RVPBinary<0b1011001, 0b010, "rstsa32">,
               Sched<[]>;
def RSUB32   : RVPBinary<0b0000001, 0b010, "rsub32">,
               Sched<[]>;
def SLL32    : RVPBinary<0b0101010, 0b010, "sll32">,
               Sched<[]>;
def SMAX32   : RVPBinary<0b1001001, 0b010, "smax32">,
               Sched<[]>;
def SMBT32   : RVPBinary<0b0001100, 0b010, "smbt32">,
               Sched<[]>;
def SMTT32   : RVPBinary<0b0010100, 0b010, "smtt32">,
               Sched<[]>;
def SMDS32   : RVPBinary<0b0101100, 0b010, "smds32">,
               Sched<[]>;
def SMDRS32  : RVPBinary<0b0110100, 0b010, "smdrs32">,
               Sched<[]>;
def SMXDS32  : RVPBinary<0b0111100, 0b010, "smxds32">,
               Sched<[]>;
def SMIN32   : RVPBinary<0b1001000, 0b010, "smin32">,
               Sched<[]>;
def SRA32    : RVPBinary<0b0101000, 0b010, "sra32">,
               Sched<[]>;
def SRA32U   : RVPBinary<0b0110000, 0b010, "sra32.u">,
               Sched<[]>;
def SRL32    : RVPBinary<0b0101001, 0b010, "srl32">,
               Sched<[]>;
def SRL32U   : RVPBinary<0b0110001, 0b010, "srl32.u">,
               Sched<[]>;
def STAS32   : RVPBinary<0b1111000, 0b010, "stas32">,
               Sched<[]>;
def STSA32   : RVPBinary<0b1111001, 0b010, "stsa32">,
               Sched<[]>;
def SUB32    : RVPBinary<0b0100001, 0b010, "sub32">,
               Sched<[]>;
def UKADD32  : RVPBinary<0b0011000, 0b010, "ukadd32">,
               Sched<[]>;
def UKCRAS32 : RVPBinary<0b0011010, 0b010, "ukcras32">,
               Sched<[]>;
def UKCRSA32 : RVPBinary<0b0011011, 0b010, "ukcrsa32">,
               Sched<[]>;
def UKSTAS32 : RVPBinary<0b1110000, 0b010, "ukstas32">,
               Sched<[]>;
def UKSTSA32 : RVPBinary<0b1110001, 0b010, "ukstsa32">,
               Sched<[]>;
def UKSUB32  : RVPBinary<0b0011001, 0b010, "uksub32">,
               Sched<[]>;
def UMAX32   : RVPBinary<0b1010001, 0b010, "umax32">,
               Sched<[]>;
def UMIN32   : RVPBinary<0b1010000, 0b010, "umin32">,
               Sched<[]>;
def URADD32  : RVPBinary<0b0010000, 0b010, "uradd32">,
               Sched<[]>;
def URCRAS32 : RVPBinary<0b0010010, 0b010, "urcras32">,
               Sched<[]>;
def URCRSA32 : RVPBinary<0b0010011, 0b010, "urcrsa32">,
               Sched<[]>;
def URSTAS32 : RVPBinary<0b1101000, 0b010, "urstas32">,
               Sched<[]>;
def URSTSA32 : RVPBinary<0b1101001, 0b010, "urstsa32">,
               Sched<[]>;
def URSUB32  : RVPBinary<0b0010001, 0b010, "ursub32">,
               Sched<[]>;
} // Predicates = [HasStdExtZpn, IsRV64]

// Ternary Instructions

let Predicates = [HasStdExtZpn] in {
def KDMABB   : RVPTernary<0b1101001, 0b001, "kdmabb">,
               Sched<[]>;
def KDMABT   : RVPTernary<0b1110001, 0b001, "kdmabt">,
               Sched<[]>;
def KDMATT   : RVPTernary<0b1111001, 0b001, "kdmatt">,
               Sched<[]>;
def KMABB    : RVPTernary<0b0101101, 0b001, "kmabb">,
               Sched<[]>;
def KMABT    : RVPTernary<0b0110101, 0b001, "kmabt">,
               Sched<[]>;
def KMATT    : RVPTernary<0b0111101, 0b001, "kmatt">,
               Sched<[]>;
def KMADA    : RVPTernary<0b0100100, 0b001, "kmada">,
               Sched<[]>;
def KMAXDA   : RVPTernary<0b0100101, 0b001, "kmaxda">,
               Sched<[]>;
def KMADS    : RVPTernary<0b0101110, 0b001, "kmads">,
               Sched<[]>;
def KMADRS   : RVPTernary<0b0110110, 0b001, "kmadrs">,
               Sched<[]>;
def KMAXDS   : RVPTernary<0b0111110, 0b001, "kmaxds">,
               Sched<[]>;
def KMMAC    : RVPTernary<0b0110000, 0b001, "kmmac">,
               Sched<[]>;
def KMMACU   : RVPTernary<0b0111000, 0b001, "kmmac.u">,
               Sched<[]>;
def KMMAWB   : RVPTernary<0b0100011, 0b001, "kmmawb">,
               Sched<[]>;
def KMMAWBU  : RVPTernary<0b0101011, 0b001, "kmmawb.u">,
               Sched<[]>;
def KMMAWB2  : RVPTernary<0b1100111, 0b001, "kmmawb2">,
               Sched<[]>;
def KMMAWB2U : RVPTernary<0b1101111, 0b001, "kmmawb2.u">,
               Sched<[]>;
def KMMAWT   : RVPTernary<0b0110011, 0b001, "kmmawt">,
               Sched<[]>;
def KMMAWTU  : RVPTernary<0b0111011, 0b001, "kmmawt.u">,
               Sched<[]>;
def KMMAWT2  : RVPTernary<0b1110111, 0b001, "kmmawt2">,
               Sched<[]>;
def KMMAWT2U : RVPTernary<0b1111111, 0b001, "kmmawt2.u">,
               Sched<[]>;
def KMMSB    : RVPTernary<0b0100001, 0b001, "kmmsb">,
               Sched<[]>;
def KMMSBU   : RVPTernary<0b0101001, 0b001, "kmmsb.u">,
               Sched<[]>;
def KMSDA    : RVPTernary<0b0100110, 0b001, "kmsda">,
               Sched<[]>;
def KMSXDA   : RVPTernary<0b0100111, 0b001, "kmsxda">,
               Sched<[]>;
def MADDR32  : RVPTernary<0b1100010, 0b001, "maddr32">,
               Sched<[]>;
def MSUBR32  : RVPTernary<0b1100011, 0b001, "msubr32">,
               Sched<[]>;
def PBSADA   : RVPTernary<0b1111111, 0b000, "pbsada">,
               Sched<[]>;
def SMAQA    : RVPTernary<0b1100100, 0b000, "smaqa">,
               Sched<[]>;
def SMAQASU  : RVPTernary<0b1100101, 0b000, "smaqa.su">,
               Sched<[]>;
def UMAQA    : RVPTernary<0b1100110, 0b000, "umaqa">,
               Sched<[]>;
} // Predicates = [HasStdExtZpn]

let Predicates = [HasStdExtZpn, IsRV64] in {
def KDMABB16 : RVPTernary<0b1101100, 0b001, "kdmabb16">,
               Sched<[]>;
def KDMABT16 : RVPTernary<0b1110100, 0b001, "kdmabt16">,
               Sched<[]>;
def KDMATT16 : RVPTernary<0b1111100, 0b001, "kdmatt16">,
               Sched<[]>;
def KMABB32  : RVPTernary<0b0101101, 0b010, "kmabb32">,
               Sched<[]>;
def KMABT32  : RVPTernary<0b0110101, 0b010, "kmabt32">,
               Sched<[]>;
def KMATT32  : RVPTernary<0b0111101, 0b010, "kmatt32">,
               Sched<[]>;
def KMAXDA32 : RVPTernary<0b0100101, 0b010, "kmaxda32">,
               Sched<[]>;
def KMADS32  : RVPTernary<0b0101110, 0b010, "kmads32">,
               Sched<[]>;
def KMADRS32 : RVPTernary<0b0110110, 0b010, "kmadrs32">,
               Sched<[]>;
def KMAXDS32 : RVPTernary<0b0111110, 0b010, "kmaxds32">,
               Sched<[]>;
def KMSDA32  : RVPTernary<0b0100110, 0b010, "kmsda32">,
               Sched<[]>;
def KMSXDA32 : RVPTernary<0b0100111, 0b010, "kmsxda32">,
               Sched<[]>;
} // Predicates = [HasStdExtZpn, IsRV64]

// Shift Instructions

let Predicates = [HasStdExtZpn] in {
def KSLLI8 : RVPShiftI3<0b0111110, 0b01, 0b000, "kslli8">,
             Sched<[]>;
def SCLIP8 : RVPShiftI3<0b1000110, 0b00, 0b000, "sclip8">,
             Sched<[]>;
def SLLI8  : RVPShiftI3<0b0111110, 0b00, 0b000, "slli8">,
             Sched<[]>;
def SRAI8  : RVPShiftI3<0b0111100, 0b00, 0b000, "srai8">,
             Sched<[]>;
def SRAI8U : RVPShiftI3<0b0111100, 0b01, 0b000, "srai8.u">,
             Sched<[]>;
def SRLI8  : RVPShiftI3<0b0111101, 0b00, 0b000, "srli8">,
             Sched<[]>;
def SRLI8U : RVPShiftI3<0b0111101, 0b01, 0b000, "srli8.u">,
             Sched<[]>;
def UCLIP8 : RVPShiftI3<0b1000110, 0b10, 0b000, "uclip8">,
             Sched<[]>;
} // Predicates = [HasStdExtZpn]

let Predicates = [HasStdExtZpn] in {
def KSLLI16 : RVPShiftI4<0b0111010, 0b1, 0b000, "kslli16">,
              Sched<[]>;
def SCLIP16 : RVPShiftI4<0b1000010, 0b0, 0b000, "sclip16">,
              Sched<[]>;
def SLLI16  : RVPShiftI4<0b0111010, 0b0, 0b000, "slli16">,
              Sched<[]>;
def SRAI16  : RVPShiftI4<0b0111000, 0b0, 0b000, "srai16">,
              Sched<[]>;
def SRAI16U : RVPShiftI4<0b0111000, 0b1, 0b000, "srai16.u">,
              Sched<[]>;
def SRLI16  : RVPShiftI4<0b0111001, 0b0, 0b000, "srli16">,
              Sched<[]>;
def SRLI16U : RVPShiftI4<0b0111001, 0b1, 0b000, "srli16.u">,
              Sched<[]>;
def UCLIP16 : RVPShiftI4<0b1000010, 0b1, 0b000, "uclip16">,
              Sched<[]>;
} // Predicates = [HasStdExtZpn]

let Predicates = [HasStdExtZpn] in {
def KSLLIW  : RVPShiftI5<0b0011011, 0b001, "kslliw">,
              Sched<[]>;
def SCLIP32 : RVPShiftI5<0b1110010, 0b000, "sclip32">,
              Sched<[]>;
def UCLIP32 : RVPShiftI5<0b1111010, 0b000, "uclip32">,
              Sched<[]>;
} // Predicates = [HasStdExtZpn]

let Predicates = [HasStdExtZpn, IsRV64] in {
def KSLLI32 : RVPShiftI5<0b1000010, 0b010, "kslli32">,
              Sched<[]>;
def SLLI32  : RVPShiftI5<0b0111010, 0b010, "slli32">,
              Sched<[]>;
def SRAI32  : RVPShiftI5<0b0111000, 0b010, "srai32">,
              Sched<[]>;
def SRAI32U : RVPShiftI5<0b1000000, 0b010, "srai32.u">,
              Sched<[]>;
def SRAIWU  : RVPShiftI5<0b0011010, 0b001, "sraiw.u">,
              Sched<[]>;
def SRLI32  : RVPShiftI5<0b0111001, 0b010, "srli32">,
              Sched<[]>;
def SRLI32U : RVPShiftI5<0b1000001, 0b010, "srli32.u">,
              Sched<[]>;
} // Predicates = [HasStdExtZpn, IsRV64]

let Predicates = [HasStdExtZpn] in {
def SRAIU : RVPShiftUImmLog2XLen<0b110101, 0b001, "srai.u">,
            Sched<[]>;
def BITREVI : RVPShiftUImmLog2XLen<0b111010, 0b000, "bitrevi">,
              Sched<[]>;
} // Predicates = [HasStdExtZpn]

let hasSideEffects = 0, mayLoad = 0, mayStore = 0,
    Predicates = [HasStdExtZpn] in
def BPICK : RVInstR4<0b00, 0b011, OPC_OP_P, (outs GPR:$rd),
                     (ins GPR:$rs1, GPR:$rs2, GPR:$rs3),
                     "bpick", "$rd, $rs1, $rs2, $rs3">,
            Sched<[]>;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0,
    Predicates = [HasStdExtZpn] in
def INSB : RVInstI<0b000, OPC_OP_P, (outs GPR:$rd_wb),
                   (ins GPR:$rd, GPR:$rs1, uimmlog2xlenbytes:$shamt),
                   "insb", "$rd, $rs1, $shamt">,
           Sched<[]> {
  bits<3> shamt;

  let Constraints = "$rd = $rd_wb";
  let Inst{31-25} = 0b1010110;
  let Inst{24-23} = 0b00;
  let Inst{22-20} = shamt;
}

// Zpsfoperand extension (64-bit Instructions)

defm ADD64   : RVPALU64<0b1100000, 0b001, "add64">,
               Sched<[]>;
defm KADD64  : RVPALU64<0b1001000, 0b001, "kadd64">,
               Sched<[]>;
defm KSUB64  : RVPALU64<0b1001001, 0b001, "ksub64">,
               Sched<[]>;
defm RADD64  : RVPALU64<0b1000000, 0b001, "radd64">,
               Sched<[]>;
defm RSUB64  : RVPALU64<0b1000001, 0b001, "rsub64">,
               Sched<[]>;
defm SUB64   : RVPALU64<0b1100001, 0b001, "sub64">,
               Sched<[]>;
defm UKADD64 : RVPALU64<0b1011000, 0b001, "ukadd64">,
               Sched<[]>;
defm UKSUB64 : RVPALU64<0b1011001, 0b001, "uksub64">,
               Sched<[]>;
defm URADD64 : RVPALU64<0b1010000, 0b001, "uradd64">,
               Sched<[]>;
defm URSUB64 : RVPALU64<0b1010001, 0b001, "ursub64">,
               Sched<[]>;

defm SMAL : RVPSMAL64<0b0101111, 0b001, "smal">,
            Sched<[]>;

defm MULR64  : RVPMUL64<0b1111000, 0b001, "mulr64">,
               Sched<[]>;
defm MULSR64 : RVPMUL64<0b1110000, 0b001, "mulsr64">,
               Sched<[]>;
defm SMUL8   : RVPMUL64<0b1010100, 0b000, "smul8">,
               Sched<[]>;
defm SMULX8  : RVPMUL64<0b1010101, 0b000, "smulx8">,
               Sched<[]>;
defm SMUL16  : RVPMUL64<0b1010000, 0b000, "smul16">,
               Sched<[]>;
defm SMULX16 : RVPMUL64<0b1010001, 0b000, "smulx16">,
               Sched<[]>;
defm UMUL8   : RVPMUL64<0b1011100, 0b000, "umul8">,
               Sched<[]>;
defm UMULX8  : RVPMUL64<0b1011101, 0b000, "umulx8">,
               Sched<[]>;
defm UMUL16  : RVPMUL64<0b1011000, 0b000, "umul16">,
               Sched<[]>;
defm UMULX16 : RVPMUL64<0b1011001, 0b000, "umulx16">,
               Sched<[]>;

defm KMAR64  : RVPMA64<0b1001010, 0b001, "kmar64">,
               Sched<[]>;
defm KMSR64  : RVPMA64<0b1001011, 0b001, "kmsr64">,
               Sched<[]>;
defm SMALBB  : RVPMA64<0b1000100, 0b001, "smalbb">,
               Sched<[]>;
defm SMALBT  : RVPMA64<0b1001100, 0b001, "smalbt">,
               Sched<[]>;
defm SMALTT  : RVPMA64<0b1010100, 0b001, "smaltt">,
               Sched<[]>;
defm SMALDA  : RVPMA64<0b1000110, 0b001, "smalda">,
               Sched<[]>;
defm SMALXDA : RVPMA64<0b1001110, 0b001, "smalxda">,
               Sched<[]>;
defm SMALDS  : RVPMA64<0b1000101, 0b001, "smalds">,
               Sched<[]>;
defm SMALDRS : RVPMA64<0b1001101, 0b001, "smaldrs">,
               Sched<[]>;
defm SMALXDS : RVPMA64<0b1010101, 0b001, "smalxds">,
               Sched<[]>;
defm SMAR64  : RVPMA64<0b1000010, 0b001, "smar64">,
               Sched<[]>;
defm SMSLDA  : RVPMA64<0b1010110, 0b001, "smslda">,
               Sched<[]>;
defm SMSLXDA : RVPMA64<0b1011110, 0b001, "smslxda">,
               Sched<[]>;
defm SMSR64  : RVPMA64<0b1000011, 0b001, "smsr64">,
               Sched<[]>;
defm UKMAR64 : RVPMA64<0b1011010, 0b001, "ukmar64">,
               Sched<[]>;
defm UKMSR64 : RVPMA64<0b1011011, 0b001, "ukmsr64">,
               Sched<[]>;
defm UMAR64  : RVPMA64<0b1010010, 0b001, "umar64">,
               Sched<[]>;
defm UMSR64  : RVPMA64<0b1010011, 0b001, "umsr64">,
               Sched<[]>;

defm WEXT : RVPWEXT<0b1100111, 0b000, "wext">,
            Sched<[]>;

defm WEXTI : RVPWEXTI<0b1101111, 0b000, "wexti">,
             Sched<[]>;

//===----------------------------------------------------------------------===//
// Assembler Pseudo Instructions
//===----------------------------------------------------------------------===//

let Predicates = [HasStdExtZpn] in {
def : InstAlias<"rdov $rd", (CSRRS  GPR:$rd, SysRegVXSAT.Encoding, X0)>;
def : InstAlias<"clrov",    (CSRRCI      X0, SysRegVXSAT.Encoding,  1)>;

def : InstAlias<"swap16 $rd, $rs1", (PKBT16 GPR:$rd, GPR:$rs1, GPR:$rs1)>;
}

//===----------------------------------------------------------------------===//
// Intrinsics codegen patterns
//===----------------------------------------------------------------------===//

class RVPBitconvertPat<ValueType DstVT, ValueType SrcVT,
                       RegisterClass DstRC, RegisterClass SrcRC>
    : Pat<(DstVT (bitconvert (SrcVT SrcRC:$src))),
          (COPY_TO_REGCLASS SrcRC:$src, DstRC)>;

let Predicates = [HasStdExtZpn] in {
def : RVPBitconvertPat<XLenVT,   XVEI8VT,  GPR, GPR>;
def : RVPBitconvertPat<XLenVT,   XVEI16VT, GPR, GPR>;
def : RVPBitconvertPat<XLenVT,   XVEI32VT, GPR, GPR>;
def : RVPBitconvertPat<XVEI8VT,  XLenVT,   GPR, GPR>;
def : RVPBitconvertPat<XVEI16VT, XLenVT,   GPR, GPR>;
def : RVPBitconvertPat<XVEI32VT, XLenVT,   GPR, GPR>;

def : RVPBitconvertPat<XVEI8VT,  XVEI16VT, GPR, GPR>;
def : RVPBitconvertPat<XVEI8VT,  XVEI32VT, GPR, GPR>;
def : RVPBitconvertPat<XVEI16VT, XVEI8VT,  GPR, GPR>;
def : RVPBitconvertPat<XVEI16VT, XVEI32VT, GPR, GPR>;
def : RVPBitconvertPat<XVEI32VT, XVEI8VT,  GPR, GPR>;
def : RVPBitconvertPat<XVEI32VT, XVEI16VT, GPR, GPR>;
} // Predicates = [HasStdExtZpn]

// Unary operation
class RVPUnaryIntPat<RVInst Inst, string IntID>
    : Pat<(XLenVT (!cast<Intrinsic>("int_riscv_" # IntID) XLenVT:$rs1)),
          (Inst GPR:$rs1)>;

let Predicates = [HasStdExtZpn] in {
def : RVPUnaryIntPat<CLRS8,     "clrs8">;
def : RVPUnaryIntPat<CLRS16,    "clrs16">;
def : RVPUnaryIntPat<CLRS32,    "clrs32">;
def : RVPUnaryIntPat<CLZ8,      "clz8">;
def : RVPUnaryIntPat<CLZ16,     "clz16">;
def : RVPUnaryIntPat<CLZ32,     "clz32">;
def : RVPUnaryIntPat<KABS8,     "kabs8">;
def : RVPUnaryIntPat<KABS16,    "kabs16">;
def : RVPUnaryIntPat<KABSW,     "kabsw">;
def : RVPUnaryIntPat<SWAP8,     "swap8">;
def : Pat<(XLenVT (!cast<Intrinsic>("int_riscv_swap16") XLenVT:$rs1)),
          (PKBT16 GPR:$rs1, GPR:$rs1)>;
def : RVPUnaryIntPat<SUNPKD810, "sunpkd810">;
def : RVPUnaryIntPat<SUNPKD820, "sunpkd820">;
def : RVPUnaryIntPat<SUNPKD830, "sunpkd830">;
def : RVPUnaryIntPat<SUNPKD831, "sunpkd831">;
def : RVPUnaryIntPat<SUNPKD832, "sunpkd832">;
def : RVPUnaryIntPat<ZUNPKD810, "zunpkd810">;
def : RVPUnaryIntPat<ZUNPKD820, "zunpkd820">;
def : RVPUnaryIntPat<ZUNPKD830, "zunpkd830">;
def : RVPUnaryIntPat<ZUNPKD831, "zunpkd831">;
def : RVPUnaryIntPat<ZUNPKD832, "zunpkd832">;
} // Predicates = [HasStdExtZpn]

// Binary operation
class RVPBinaryIntPat<RVInst Inst, string IntID>
    : Pat<(XLenVT (!cast<Intrinsic>("int_riscv_" # IntID)
                   XLenVT:$rs1, XLenVT:$rs2)),
          (Inst GPR:$rs1, GPR:$rs2)>;

let Predicates = [HasStdExtZpn] in {
def : RVPBinaryIntPat<ADD8,     "add8">;
def : RVPBinaryIntPat<ADD16,    "add16">;
def : RVPBinaryIntPat<AVE,      "ave">;
def : RVPBinaryIntPat<BITREV,   "bitrev">;
def : RVPBinaryIntPat<CMPEQ8,   "cmpeq8">;
def : RVPBinaryIntPat<CMPEQ16,  "cmpeq16">;
def : RVPBinaryIntPat<CRAS16,   "cras16">;
def : RVPBinaryIntPat<CRSA16,   "crsa16">;
def : RVPBinaryIntPat<KADD8,    "kadd8">;
def : RVPBinaryIntPat<KADD16,   "kadd16">;
def : RVPBinaryIntPat<KADDH,    "kaddh">;
def : RVPBinaryIntPat<KADDW,    "kaddw">;
def : RVPBinaryIntPat<KCRAS16,  "kcras16">;
def : RVPBinaryIntPat<KCRSA16,  "kcrsa16">;
def : RVPBinaryIntPat<KDMBB,    "kdmbb">;
def : RVPBinaryIntPat<KDMBT,    "kdmbt">;
def : RVPBinaryIntPat<KDMTT,    "kdmtt">;
def : RVPBinaryIntPat<KHM8,     "khm8">;
def : RVPBinaryIntPat<KHMX8,    "khmx8">;
def : RVPBinaryIntPat<KHM16,    "khm16">;
def : RVPBinaryIntPat<KHMX16,   "khmx16">;
def : RVPBinaryIntPat<KHMBB,    "khmbb">;
def : RVPBinaryIntPat<KHMBT,    "khmbt">;
def : RVPBinaryIntPat<KHMTT,    "khmtt">;
def : RVPBinaryIntPat<KMDA,     "kmda">;
def : RVPBinaryIntPat<KMXDA,    "kmxda">;
def : RVPBinaryIntPat<KMMWB2,   "kmmwb2">;
def : RVPBinaryIntPat<KMMWB2U,  "kmmwb2_u">;
def : RVPBinaryIntPat<KMMWT2,   "kmmwt2">;
def : RVPBinaryIntPat<KMMWT2U,  "kmmwt2_u">;
def : RVPBinaryIntPat<KSLLW,    "ksllw">;
def : RVPBinaryIntPat<KSLL8,    "ksll8">;
def : RVPBinaryIntPat<KSLL16,   "ksll16">;
def : RVPBinaryIntPat<KSLRA8,   "kslra8">;
def : RVPBinaryIntPat<KSLRA8U,  "kslra8_u">;
def : RVPBinaryIntPat<KSLRA16,  "kslra16">;
def : RVPBinaryIntPat<KSLRA16U, "kslra16_u">;
def : RVPBinaryIntPat<KSLRAW,   "kslraw">;
def : RVPBinaryIntPat<KSLRAWU,  "kslraw_u">;
def : RVPBinaryIntPat<KSTAS16,  "kstas16">;
def : RVPBinaryIntPat<KSTSA16,  "kstsa16">;
def : RVPBinaryIntPat<KSUB8,    "ksub8">;
def : RVPBinaryIntPat<KSUB16,   "ksub16">;
def : RVPBinaryIntPat<KSUBH,    "ksubh">;
def : RVPBinaryIntPat<KSUBW,    "ksubw">;
def : RVPBinaryIntPat<KWMMUL,   "kwmmul">;
def : RVPBinaryIntPat<KWMMULU,  "kwmmul_u">;
def : RVPBinaryIntPat<MAXW,     "maxw">;
def : RVPBinaryIntPat<MINW,     "minw">;
def : RVPBinaryIntPat<PBSAD,    "pbsad">;
def : RVPBinaryIntPat<PKBB16,   "pkbb16">;
def : RVPBinaryIntPat<PKBT16,   "pkbt16">;
def : RVPBinaryIntPat<PKTT16,   "pktt16">;
def : RVPBinaryIntPat<PKTB16,   "pktb16">;
def : RVPBinaryIntPat<RADD8,    "radd8">;
def : RVPBinaryIntPat<RADD16,   "radd16">;
def : RVPBinaryIntPat<RADDW,    "raddw">;
def : RVPBinaryIntPat<RCRAS16,  "rcras16">;
def : RVPBinaryIntPat<RCRSA16,  "rcrsa16">;
def : RVPBinaryIntPat<RSTAS16,  "rstas16">;
def : RVPBinaryIntPat<RSTSA16,  "rstsa16">;
def : RVPBinaryIntPat<RSUB8,    "rsub8">;
def : RVPBinaryIntPat<RSUB16,   "rsub16">;
def : RVPBinaryIntPat<RSUBW,    "rsubw">;
def : RVPBinaryIntPat<SCMPLE8,  "scmple8">;
def : RVPBinaryIntPat<SCMPLE16, "scmple16">;
def : RVPBinaryIntPat<SCMPLT8,  "scmplt8">;
def : RVPBinaryIntPat<SCMPLT16, "scmplt16">;
def : RVPBinaryIntPat<SLL8,     "sll8">;
def : RVPBinaryIntPat<SLL16,    "sll16">;
def : RVPBinaryIntPat<SMAX8,    "smax8">;
def : RVPBinaryIntPat<SMAX16,   "smax16">;
def : RVPBinaryIntPat<SMBB16,   "smbb16">;
def : RVPBinaryIntPat<SMBT16,   "smbt16">;
def : RVPBinaryIntPat<SMTT16,   "smtt16">;
def : RVPBinaryIntPat<SMDS,     "smds">;
def : RVPBinaryIntPat<SMDRS,    "smdrs">;
def : RVPBinaryIntPat<SMXDS,    "smxds">;
def : RVPBinaryIntPat<SMIN8,    "smin8">;
def : RVPBinaryIntPat<SMIN16,   "smin16">;
def : RVPBinaryIntPat<SMMUL,    "smmul">;
def : RVPBinaryIntPat<SMMULU,   "smmul_u">;
def : RVPBinaryIntPat<SMMWB,    "smmwb">;
def : RVPBinaryIntPat<SMMWBU,   "smmwb_u">;
def : RVPBinaryIntPat<SMMWT,    "smmwt">;
def : RVPBinaryIntPat<SMMWTU,   "smmwt_u">;
def : RVPBinaryIntPat<SRAU,     "sra_u">;
def : RVPBinaryIntPat<SRA8,     "sra8">;
def : RVPBinaryIntPat<SRA8U,    "sra8_u">;
def : RVPBinaryIntPat<SRA16,    "sra16">;
def : RVPBinaryIntPat<SRA16U,   "sra16_u">;
def : RVPBinaryIntPat<SRL8,     "srl8">;
def : RVPBinaryIntPat<SRL8U,    "srl8_u">;
def : RVPBinaryIntPat<SRL16,    "srl16">;
def : RVPBinaryIntPat<SRL16U,   "srl16_u">;
def : RVPBinaryIntPat<STAS16,   "stas16">;
def : RVPBinaryIntPat<STSA16,   "stsa16">;
def : RVPBinaryIntPat<SUB8,     "sub8">;
def : RVPBinaryIntPat<SUB16,    "sub16">;
def : RVPBinaryIntPat<UCMPLE8,  "ucmple8">;
def : RVPBinaryIntPat<UCMPLE16, "ucmple16">;
def : RVPBinaryIntPat<UCMPLT8,  "ucmplt8">;
def : RVPBinaryIntPat<UCMPLT16, "ucmplt16">;
def : RVPBinaryIntPat<UKADD8,   "ukadd8">;
def : RVPBinaryIntPat<UKADD16,  "ukadd16">;
def : RVPBinaryIntPat<UKADDH,   "ukaddh">;
def : RVPBinaryIntPat<UKADDW,   "ukaddw">;
def : RVPBinaryIntPat<UKCRAS16, "ukcras16">;
def : RVPBinaryIntPat<UKCRSA16, "ukcrsa16">;
def : RVPBinaryIntPat<UKSTAS16, "ukstas16">;
def : RVPBinaryIntPat<UKSTSA16, "ukstsa16">;
def : RVPBinaryIntPat<UKSUB8,   "uksub8">;
def : RVPBinaryIntPat<UKSUB16,  "uksub16">;
def : RVPBinaryIntPat<UKSUBH,   "uksubh">;
def : RVPBinaryIntPat<UKSUBW,   "uksubw">;
def : RVPBinaryIntPat<UMAX8,    "umax8">;
def : RVPBinaryIntPat<UMAX16,   "umax16">;
def : RVPBinaryIntPat<UMIN8,    "umin8">;
def : RVPBinaryIntPat<UMIN16,   "umin16">;
def : RVPBinaryIntPat<URADD8,   "uradd8">;
def : RVPBinaryIntPat<URADD16,  "uradd16">;
def : RVPBinaryIntPat<URADDW,   "uraddw">;
def : RVPBinaryIntPat<URCRAS16, "urcras16">;
def : RVPBinaryIntPat<URCRSA16, "urcrsa16">;
def : RVPBinaryIntPat<URSTAS16, "urstas16">;
def : RVPBinaryIntPat<URSTSA16, "urstsa16">;
def : RVPBinaryIntPat<URSUB8,   "ursub8">;
def : RVPBinaryIntPat<URSUB16,  "ursub16">;
def : RVPBinaryIntPat<URSUBW,   "ursubw">;
} // Predicates = [HasStdExtZpn]

class RVPBinaryI3IntPat<RVInst Inst, string IntID>
    : Pat<(XLenVT (!cast<Intrinsic>("int_riscv_" # IntID)
                   XLenVT:$rs1, uimm3:$rs2)),
          (Inst GPR:$rs1, uimm3:$rs2)>;

let Predicates = [HasStdExtZpn] in {
def : RVPBinaryI3IntPat<SCLIP8, "sclip8">;
def : RVPBinaryI3IntPat<UCLIP8, "uclip8">;
def : RVPBinaryI3IntPat<KSLLI8, "ksll8">;
} // Predicates = [HasStdExtZpn]

class RVPBinaryI4IntPat<RVInst Inst, string IntID>
    : Pat<(XLenVT (!cast<Intrinsic>("int_riscv_" # IntID)
                   XLenVT:$rs1, uimm4:$rs2)),
          (Inst GPR:$rs1, uimm4:$rs2)>;

let Predicates = [HasStdExtZpn] in {
def : RVPBinaryI4IntPat<SCLIP16, "sclip16">;
def : RVPBinaryI4IntPat<UCLIP16, "uclip16">;
def : RVPBinaryI4IntPat<KSLLI16, "ksll16">;
} // Predicates = [HasStdExtZpn]

class RVPBinaryI5IntPat<RVInst Inst, string IntID>
    : Pat<(XLenVT (!cast<Intrinsic>("int_riscv_" # IntID)
                   XLenVT:$rs1, uimm5:$rs2)),
          (Inst GPR:$rs1, uimm5:$rs2)>;

let Predicates = [HasStdExtZpn] in {
def : RVPBinaryI5IntPat<SCLIP32, "sclip32">;
def : RVPBinaryI5IntPat<UCLIP32, "uclip32">;
def : RVPBinaryI5IntPat<KSLLIW,  "ksllw">;
} // Predicates = [HasStdExtZpn]

// Ternary operation
class RVPTernaryIntPat<RVInst Inst, string IntID>
    : Pat<(XLenVT (!cast<Intrinsic>("int_riscv_" # IntID)
                   XLenVT:$rs1, XLenVT:$rs2, XLenVT:$rs3)),
          (Inst GPR:$rs1, GPR:$rs2, GPR:$rs3)>;

let Predicates = [HasStdExtZpn] in {
def : RVPTernaryIntPat<BPICK,    "bpick">;
def : RVPTernaryIntPat<KDMABB,   "kdmabb">;
def : RVPTernaryIntPat<KDMABT,   "kdmabt">;
def : RVPTernaryIntPat<KDMATT,   "kdmatt">;
def : RVPTernaryIntPat<KMABB,    "kmabb">;
def : RVPTernaryIntPat<KMABT,    "kmabt">;
def : RVPTernaryIntPat<KMATT,    "kmatt">;
def : RVPTernaryIntPat<KMADA,    "kmada">;
def : RVPTernaryIntPat<KMAXDA,   "kmaxda">;
def : RVPTernaryIntPat<KMADS,    "kmads">;
def : RVPTernaryIntPat<KMADRS,   "kmadrs">;
def : RVPTernaryIntPat<KMAXDS,   "kmaxds">;
def : RVPTernaryIntPat<KMMAC,    "kmmac">;
def : RVPTernaryIntPat<KMMACU,   "kmmac_u">;
def : RVPTernaryIntPat<KMMAWB,   "kmmawb">;
def : RVPTernaryIntPat<KMMAWBU,  "kmmawb_u">;
def : RVPTernaryIntPat<KMMAWB2,  "kmmawb2">;
def : RVPTernaryIntPat<KMMAWB2U, "kmmawb2_u">;
def : RVPTernaryIntPat<KMMAWT,   "kmmawt">;
def : RVPTernaryIntPat<KMMAWTU,  "kmmawt_u">;
def : RVPTernaryIntPat<KMMAWT2,  "kmmawt2">;
def : RVPTernaryIntPat<KMMAWT2U, "kmmawt2_u">;
def : RVPTernaryIntPat<KMMSB,    "kmmsb">;
def : RVPTernaryIntPat<KMMSBU,   "kmmsb_u">;
def : RVPTernaryIntPat<KMSDA,    "kmsda">;
def : RVPTernaryIntPat<KMSXDA,   "kmsxda">;
def : RVPTernaryIntPat<PBSADA,   "pbsada">;
def : RVPTernaryIntPat<SMAQA,    "smaqa">;
def : RVPTernaryIntPat<SMAQASU,  "smaqa_su">;
def : RVPTernaryIntPat<UMAQA,    "umaqa">;
} // Predicates = [HasStdExtZpn]

class RVPTernaryINSBIntPat<RVInst Inst, string IntID>
    : Pat<(XLenVT (!cast<Intrinsic>("int_riscv_" # IntID)
                   XLenVT:$rs1, XLenVT:$rs2, uimmlog2xlenbytes:$rs3)),
          (Inst GPR:$rs1, GPR:$rs2, uimmlog2xlenbytes:$rs3)>;

let Predicates = [HasStdExtZpn] in
def : RVPTernaryINSBIntPat<INSB, "insb">;
