//===-- RISCVInstrInfoK.td - RISC-V 'K' instructions -------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
///
/// This file describes the RISC-V instructions from the standard 'K'
/// scalar cryptography extension, version 0.9.2.
///
/// This version is still experimental as the 'K' extension hasn't been
/// ratified yet.
///
//===----------------------------------------------------------------------===//

def RnumArg : AsmOperandClass {
  let Name = "RnumArg";
  let RenderMethod = "addImmOperands";
  let DiagnosticType = "InvalidRnumArg";
}

def rnum : Operand<i32>, TImmLeaf<i32, [{return isInt<4>(Imm);}]> {
  let ParserMatchClass = RnumArg;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeUImmOperand<4>";
  let OperandType = "OPERAND_UIMM4";
  let OperandNamespace = "RISCVOp";
}

def byteselect : Operand<i8>, TImmLeaf<i8, [{return isUInt<2>(Imm);}]> {
  let ParserMatchClass = UImmAsmOperand<2>;
  let DecoderMethod = "decodeUImmOperand<2>";
  let OperandType = "OPERAND_UIMM2";
  let OperandNamespace = "RISCVOp";
}

//===----------------------------------------------------------------------===//
// Instruction class templates
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class RVKUnary<bits<7> funct7, bits<5> funct5, bits<3> funct3, string opcodestr>
    : RVInstR<funct7, funct3, OPC_OP_IMM, (outs GPR:$rd), (ins GPR:$rs1), opcodestr, "$rd, $rs1"> {
        let Inst{24-20} = funct5;
    }

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class RVKBinary<bits<7> funct7, bits<3> funct3, string opcodestr>
    : RVInstR<funct7, funct3, OPC_OP, (outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
            opcodestr, "$rd, $rs1, $rs2">;

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class RVKByteSelect<bits<5> funct5, string opcodestr>
    : RVInstR<{0b00, funct5}, 0b000, OPC_OP, (outs GPR:$rd),
              (ins GPR:$rs1, GPR:$rs2, byteselect:$bs), opcodestr,
              "$rd, $rs1, $rs2, $bs"> {
        bits<2> bs;
        let Inst{31-30}=bs;
    }

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
class RVKUnary_rnum<bits<7> funct7, bits<3> funct3, string opcodestr>
    : RVInstI<funct3, OPC_OP_IMM, (outs GPR:$rd), (ins GPR:$rs1, rnum:$rnum),
            opcodestr, "$rd, $rs1, $rnum"> {
    bits<4> rnum;

    let Inst{31-25} = funct7;
    let Inst{24} = 1;
    let Inst{23-20} = rnum;
}

//===----------------------------------------------------------------------===//
// Instructions
//===----------------------------------------------------------------------===//

let Predicates = [HasStdExtZkr] in {
// Assembler Pseudo Instructions
def : InstAlias<"getnoise $rd", (CSRRS GPR:$rd, MNOISE.Encoding, X0)>;
def : InstAlias<"pollentropy $rd", (CSRRS GPR:$rd, MENTROPY.Encoding, X0)>;
}// Predicates = [HasStdExtZkr]

let Predicates = [HasStdExtZkne, IsRV32] in {
def AES32ESI : RVKByteSelect<0b10001, "aes32esi">;
def AES32ESMI : RVKByteSelect<0b10011, "aes32esmi">;
} // Predicates = [HasStdExtZkne, IsRV32]

let Predicates = [HasStdExtZkne, IsRV64] in {
def AES64ES : RVKBinary<0b0011001, 0b000, "aes64es">;
def AES64ESM : RVKBinary<0b0011011, 0b000, "aes64esm">;
def AES64KS2 : RVKBinary<0b0111111, 0b000, "aes64ks2">;
def AES64KS1I : RVKUnary_rnum<0b0011000, 0b001, "aes64ks1i">;
} // Predicates = [HasStdExtZkne, IsRV64]

let Predicates = [HasStdExtZknd, IsRV32] in {
def AES32DSI : RVKByteSelect<0b10101, "aes32dsi">;
def AES32DSMI : RVKByteSelect<0b10111, "aes32dsmi">;
} // Predicates = [HasStdExtZknd, IsRV32]

let Predicates = [HasStdExtZknd, IsRV64] in {
def AES64DS : RVKBinary<0b0011101, 0b000, "aes64ds">;
def AES64IM : RVKUnary<0b0011000, 0b00000, 0b001, "aes64im">;

def AES64DSM : RVKBinary<0b0011111, 0b000, "aes64dsm">;
} // Predicates = [HasStdExtZknd, IsRV64]

let Predicates = [HasStdExtZknh] in {
def SHA256SUM0 : RVKUnary<0b0001000, 0b00000, 0b001, "sha256sum0">;
def SHA256SUM1 : RVKUnary<0b0001000, 0b00001, 0b001, "sha256sum1">;
def SHA256SIG0 : RVKUnary<0b0001000, 0b00010, 0b001, "sha256sig0">;
def SHA256SIG1 : RVKUnary<0b0001000, 0b00011, 0b001, "sha256sig1">;
} // Predicates = [HasStdExtZknh]

let Predicates = [HasStdExtZknh, IsRV32] in {
def SHA512SUM0R : RVKBinary<0b0101000, 0b000, "sha512sum0r">;
def SHA512SUM1R : RVKBinary<0b0101001, 0b000, "sha512sum1r">;
def SHA512SIG0L : RVKBinary<0b0101010, 0b000, "sha512sig0l">;
def SHA512SIG0H : RVKBinary<0b0101110, 0b000, "sha512sig0h">;
def SHA512SIG1L : RVKBinary<0b0101011, 0b000, "sha512sig1l">;
def SHA512SIG1H : RVKBinary<0b0101111, 0b000, "sha512sig1h">;
} // Predicates = [HasStdExtZknh, IsRV32]

let Predicates = [HasStdExtZknh, IsRV64] in {
def SHA512SUM0 : RVKUnary<0b0001000, 0b00100, 0b001, "sha512sum0">;
def SHA512SUM1 : RVKUnary<0b0001000, 0b00101, 0b001, "sha512sum1">;
def SHA512SIG0 : RVKUnary<0b0001000, 0b00110, 0b001, "sha512sig0">;
def SHA512SIG1 : RVKUnary<0b0001000, 0b00111, 0b001, "sha512sig1">;
} // Predicates = [HasStdExtZknh, IsRV64]

let Predicates = [HasStdExtZksed] in {
def SM4ED : RVKByteSelect<0b11000, "sm4ed">;
def SM4KS : RVKByteSelect<0b11010, "sm4ks">;
} // Predicates = [HasStdExtZksed]

let Predicates = [HasStdExtZksh] in {
def SM3P0 : RVKUnary<0b0001000, 0b01000, 0b001, "sm3p0">;
def SM3P1 : RVKUnary<0b0001000, 0b01001, 0b001, "sm3p1">;
} // Predicates = [HasStdExtZksh]

//===----------------------------------------------------------------------===//
// Intrinsics
//===----------------------------------------------------------------------===//

class PatGprGprByteSelect<SDPatternOperator OpNode, RVInst Inst>
    : Pat<(OpNode GPR:$rs1, GPR:$rs2, i8:$imm),
          (Inst GPR:$rs1, GPR:$rs2, byteselect:$imm)>;

let Predicates = [HasStdExtZkn, IsRV32] in {
def : PatGprGprByteSelect<int_riscv_aes32dsi, AES32DSI>;
def : PatGprGprByteSelect<int_riscv_aes32dsmi, AES32DSMI>;
def : PatGprGprByteSelect<int_riscv_aes32esi, AES32ESI>;
def : PatGprGprByteSelect<int_riscv_aes32esmi, AES32ESMI>;
}

let Predicates = [HasStdExtZknh, IsRV32] in {
def : PatGprGpr<int_riscv_sha512sig0l, SHA512SIG0L>;
def : PatGprGpr<int_riscv_sha512sig0h, SHA512SIG0H>;
def : PatGprGpr<int_riscv_sha512sig1l, SHA512SIG1L>;
def : PatGprGpr<int_riscv_sha512sig1h, SHA512SIG1H>;
def : PatGprGpr<int_riscv_sha512sum0r, SHA512SUM0R>;
def : PatGprGpr<int_riscv_sha512sum1r, SHA512SUM1R>;
}

let Predicates = [HasStdExtZknh, IsRV64] in {
def : PatGpr<int_riscv_sha512sig0, SHA512SIG0>;
def : PatGpr<int_riscv_sha512sig1, SHA512SIG1>;
def : PatGpr<int_riscv_sha512sum0, SHA512SUM0>;
def : PatGpr<int_riscv_sha512sum1, SHA512SUM1>;
}

let Predicates = [HasStdExtZknd, IsRV64] in {
def : PatGprGpr<int_riscv_aes64ds, AES64DS>;
def : PatGprGpr<int_riscv_aes64dsm, AES64DSM>;
def : PatGpr<int_riscv_aes64im, AES64IM>;
}

let Predicates = [HasStdExtZkne, IsRV64] in {
def : PatGprGpr<int_riscv_aes64es, AES64ES>;
def : PatGprGpr<int_riscv_aes64esm, AES64ESM>;
def : Pat<(int_riscv_aes64ks1i GPR:$rs1, i32:$rnum),
          (AES64KS1I GPR:$rs1, rnum:$rnum)>;
def : PatGprGpr<int_riscv_aes64ks2, AES64KS2>;
}

let Predicates = [HasStdExtZknh] in {
def : PatGpr<int_riscv_sha256sig0, SHA256SIG0>;
def : PatGpr<int_riscv_sha256sig1, SHA256SIG1>;
def : PatGpr<int_riscv_sha256sum0, SHA256SUM0>;
def : PatGpr<int_riscv_sha256sum1, SHA256SUM1>;
}

let Predicates = [HasStdExtZksh] in {
def : PatGpr<int_riscv_sm3p0, SM3P0>;
def : PatGpr<int_riscv_sm3p1, SM3P1>;
}

let Predicates = [HasStdExtZksed, IsRV32] in {
def : PatGprGprByteSelect<int_riscv_sm4ks, SM4KS>;
def : PatGprGprByteSelect<int_riscv_sm4ed, SM4ED>;
}

let Predicates = [HasStdExtZksed, IsRV64] in {
def : PatGprGprByteSelect<int_riscv_sm4ks, SM4KS>;
def : PatGprGprByteSelect<int_riscv_sm4ed, SM4ED>;
}

let Predicates = [HasStdExtZkr] in {
class PatEntropy<SDPatternOperator OpNode, string name>
    : Pat<(OpNode), (Pseudo<(outs GPR:$rd), (ins), [], name, "$rd">)>;

def : PatEntropy<int_riscv_getnoise, "getnoise">;
def : PatEntropy<int_riscv_pollentropy, "pollentropy">;
}
