//===-- RISCVInstrInfoK.td - RISC-V 'K' instructions -------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
///
/// This file describes the RISC-K instructions from the standard 'K' 
/// scalar cryptography extension, version 0.8.1. 
///
//===----------------------------------------------------------------------===//


//===----------------------------------------------------------------------===//
// Operand and SDNode transformation definitions.
//===----------------------------------------------------------------------===//
def uimm2 : Operand<XLenVT>, ImmLeaf<XLenVT, [{return isUInt<2>(Imm);}]> {
  let ParserMatchClass = UImmAsmOperand<2>;
  let DecoderMethod = "decodeUImmOperand<2>";
  let OperandType = "OPERAND_UIMM2";
  let OperandNamespace = "RISCVOp";
}

def rcon : Operand<XLenVT>, ImmLeaf<XLenVT, [{return isUInt<4>(Imm);}]> {
  let ParserMatchClass = UImmAsmOperand<4>;
  let EncoderMethod = "getImmOpValue";
  let DecoderMethod = "decodeUImmOperand<4>";
  let OperandType = "OPERAND_UIMM4";
  let OperandNamespace = "RISCVOp";
}

//===----------------------------------------------------------------------===//
// Instruction class templates
//===----------------------------------------------------------------------===//

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in {
    // op rd, rs1
    class RVKUnary<bits<7> funct7, bits<5> funct5, bits<3> funct3, string opcodestr>
        : RVInstR<funct7, funct3, OPC_OP_IMM, (outs GPR:$rd), (ins GPR:$rs1), opcodestr, "$rd, $rs1">{
            let Inst{24-20} = funct5;
        }

    // op rd rs1 rs2
    class RVKBinary<bits<7> funct7, bits<3> funct3, string opcodestr>
        : RVInstR<funct7, funct3, OPC_OP, (outs GPR:$rd), (ins GPR:$rs1, GPR:$rs2),
                opcodestr, "$rd, $rs1, $rs2">;

    // op rt rs2 bs
    class RVKByteSelect<bits<5> funct5, string opcodestr>
        : RVInstS<0b000, OPC_OP, (outs GPR:$rt), (ins GPR:$rs2, uimm2:$bs), 
                opcodestr, "$rt, $rs2, $bs">{
            bits<2> bs;
            bits<5> rt;

            let Inst{31-30}=bs;
            let Inst{29-25}=funct5;
            let Inst{19-15}=rt;
            let Inst{11-7}=0b00000;
        }
    // op rd rs1 rcon
    class RVKUnary_rcon<bits<7> funct7, bits<3> funct3, string opcodestr>
        : RVInstI<funct3, OPC_OP_IMM, (outs GPR:$rd), (ins GPR:$rs1, rcon:$rcon),
                opcodestr, "$rd, $rs1, $rcon"> {
        bits<4> rcon;
        
        let Inst{31-25} = funct7;
        let Inst{24} = 1;
        let Inst{23-20} = rcon;
    }

} // hasSideEffects = 0, mayLoad = 0, mayStore = 0

let Predicates = [HasStdExtK] in {
    // RVKUnary
    def SHA256SUM0 :    RVKUnary<0b0001000, 0b00000, 0b001, "sha256sum0">, 
                        Sched<[]>;
    def SHA256SUM1 :    RVKUnary<0b0001000, 0b00001, 0b001, "sha256sum1">, 
                        Sched<[]>;
    def SHA256SIG0 :    RVKUnary<0b0001000, 0b00010, 0b001, "sha256sig0">, 
                        Sched<[]>;
    def SHA256SIG1 :    RVKUnary<0b0001000, 0b00011, 0b001, "sha256sig1">, 
                        Sched<[]>;
    def SM3P0      :    RVKUnary<0b0001000, 0b01000, 0b001, "sm3p0">, 
                        Sched<[]>;
    def SM3P1      :    RVKUnary<0b0001000, 0b01001, 0b001, "sm3p1">, 
                        Sched<[]>;
    //RVKByteSelect
    def SM4ED      :    RVKByteSelect<0b11000, "sm4ed">,
                        Sched<[]>;
    def SM4KS      :    RVKByteSelect<0b11010, "sm4ks">,
                        Sched<[]>;
    // Pseudo Instructions
    def GETNOISE   :   InstAlias<"getnoise $rd", (CSRRS GPR:$rd, MNOISE.Encoding, X0)>, 
                        Sched<[]>;
    def POLLENTROPY:   InstAlias<"pollentropy $rd", (CSRRS GPR:$rd, MENTROPY.Encoding, X0)>, 
                        Sched<[]>;
} // Predicates = [HasStdExtK]

let Predicates = [HasStdExtK, IsRV32] in {
    // RVKBinary
    def SHA512SUM0R : RVKBinary<0b0101000, 0b000, "sha512sum0r">, 
                        Sched<[]>;
    def SHA512SUM1R : RVKBinary<0b0101001, 0b000, "sha512sum1r">, 
                        Sched<[]>;
    def SHA512SIG0L : RVKBinary<0b0101010, 0b000, "sha512sig0l">, 
                        Sched<[]>;
    def SHA512SIG0H : RVKBinary<0b0101110, 0b000, "sha512sig0h">, 
                        Sched<[]>;
    def SHA512SIG1L : RVKBinary<0b0101011, 0b000, "sha512sig1l">, 
                        Sched<[]>;
    def SHA512SIG1H : RVKBinary<0b0101111, 0b000, "sha512sig1h">, 
                        Sched<[]>;
    // RVKByteSelect
    def AES32ESMI  :    RVKByteSelect<0b11011, "aes32esmi">,
                        Sched<[]>;
    def AES32ESI  :     RVKByteSelect<0b11001, "aes32esi">,
                        Sched<[]>;
    def AES32DSMI  :    RVKByteSelect<0b11111, "aes32dsmi">,
                        Sched<[]>;
    def AES32DSI  :     RVKByteSelect<0b11101, "aes32dsi">,
                        Sched<[]>;
} // Predicates = [HasStdExtK, IsRV32]

let Predicates = [HasStdExtK, IsRV64] in {
    // RVK Unary
    def SHA512SUM0  : RVKUnary<0b0001000, 0b00100, 0b001, "sha512sum0">, 
                        Sched<[]>;
    def SHA512SUM1  : RVKUnary<0b0001000, 0b00101, 0b001, "sha512sum1">, 
                        Sched<[]>;
    def SHA512SIG0  : RVKUnary<0b0001000, 0b00110, 0b001, "sha512sig0">, 
                        Sched<[]>;
    def SHA512SIG1  : RVKUnary<0b0001000, 0b00111, 0b001, "sha512sig1">, 
                        Sched<[]>;
    def AES64IM     : RVKUnary<0b0011000, 0b00000, 0b001, "aes64im">, 
                        Sched<[]>;
    // RVK Binary
    def AES64KS2    : RVKBinary<0b0111111, 0b000, "aes64ks2">, 
                        Sched<[]>;
    def AES64ESM    : RVKBinary<0b0011011, 0b000, "aes64esm">, 
                        Sched<[]>;
    def AES64ES     : RVKBinary<0b0011001, 0b000, "aes64es">, 
                        Sched<[]>;
    def AES64DSM    : RVKBinary<0b0011111, 0b000, "aes64dsm">, 
                        Sched<[]>;
    def AES64DS     : RVKBinary<0b0011101, 0b000, "aes64ds">, 
                        Sched<[]>;
    // RVKUnary_rcon
    def AES64KS1I   : RVKUnary_rcon<0b0011000, 0b001, "aes64ks1i">, 
                        Sched<[]>;
} // Predicates = [HasStdExtK, IsRV64]