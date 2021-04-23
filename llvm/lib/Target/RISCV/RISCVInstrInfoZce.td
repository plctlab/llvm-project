//===-- RISCVInstrInfoZce.td - RISC-V 'Zce' instructions -------*- tablegen -*-===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
///
/// This file describes the RISC-V instructions from the 'Zce' Code-size reduction
/// extension, version 0.24.
/// This version is still experimental as the 'Zce' extension hasn't been
/// ratified yet.
///
//===----------------------------------------------------------------------===//

include "RISCVInstrFormatsZce.td"

//===----------------------------------------------------------------------===//
// Operand and SDNode transformation definitions.
//===----------------------------------------------------------------------===//

// echo "c.zext.b s0" | bin/llvm-mc -triple=riscv64 -mattr=+experimental-zce -show-encoding
let Predicates = [HasStdExtZce] in {
def C_ZEXT_B : RVZcecInst16<0b00, 0b000 , "c.zext.b">, Sched<[]>;
def C_ZEXT_H : RVZcecInst16<0b00, 0b001 , "c.zext.h">, Sched<[]>;
def C_ZEXT_W : RVZcecInst16<0b00, 0b010 , "c.zext.w">, Sched<[]>;
def C_SEXT_B : RVZcecInst16<0b00, 0b100 , "c.sext.b">, Sched<[]>;
def C_SEXT_H : RVZcecInst16<0b00, 0b101 , "c.sext.h">, Sched<[]>;
// def C_NOT : RVZcecInst16<0b00, 0b110 , "c.not">, Sched<[]>;
// def C_NEG : RVZcecInst16<0b00, 0b111 , "c.neg">, Sched<[]>;

// def C_MUL : RVZcecInstC_MUL<0b01, "c.mul">, Sched<[]>;

}