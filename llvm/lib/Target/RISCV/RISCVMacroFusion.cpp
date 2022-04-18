//===- RISCVMacroFusion.cpp - RISCV Macro Fusion ----------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
/// \file This file contains the RISCV implementation of the DAG scheduling
///  mutation to pair instructions back to back.
//
//===----------------------------------------------------------------------===//

#include "RISCVMacroFusion.h"
#include "RISCVSubtarget.h"
#include "llvm/CodeGen/MacroFusion.h"
#include "llvm/CodeGen/TargetInstrInfo.h"

namespace llvm {

static inline bool withSameDest(const MachineInstr *FirstMI,
                                const MachineInstr &SecondMI) {
  auto reg = FirstMI->getOperand(0).getReg();
  if (reg != SecondMI.getOperand(0).getReg() ||
      SecondMI.getOperand(0).getReg() != SecondMI.getOperand(1).getReg())
    return false;
  return true;
}

// These functions could be replaced with a
// series of macros.
static bool isFuseAdduwOrZexthPair(const MachineInstr *FirstMI,
                                   const MachineInstr &SecondMI) {
  if (FirstMI->getOpcode() == RISCV::SLLI ||
      FirstMI->getOpcode() == RISCV::SLLIW) {
    if (SecondMI.getOpcode() != RISCV::SRLI &&
        SecondMI.getOpcode() != RISCV::SRLIW)
      return false;
    if (!withSameDest(FirstMI, SecondMI))
      return false;
    auto firstImm = FirstMI->getOperand(2).getImm();
    auto secondImm = SecondMI.getOperand(2).getImm();
    if (firstImm == 32 && secondImm == 32)
      return true;
    if (firstImm == 48 && secondImm == 48)
      return true;
    if (firstImm == 16 && secondImm == 16 &&
        FirstMI->getOpcode() == RISCV::SLLIW &&
        SecondMI.getOpcode() != RISCV::SRLIW)
      return true;
  }
  return false;
}

static bool is16bitSignExtendPair(const MachineInstr *FirstMI,
                                  const MachineInstr &SecondMI) {
  if (FirstMI->getOpcode() != RISCV::SLLIW)
    return false;
  if (SecondMI.getOpcode() != RISCV::SRAIW)
    return false;
  if (!withSameDest(FirstMI, SecondMI))
    return false;
  auto firstImm = FirstMI->getOperand(2).getImm();
  auto secondImm = SecondMI.getOperand(2).getImm();
  if (firstImm == 16 && secondImm == 16)
    return true;
  return false;
}

static bool isShiftLeftAndAddPair(const MachineInstr *FirstMI,
                                  const MachineInstr &SecondMI) {
  if (FirstMI->getOpcode() != RISCV::SLLI)
    return false;
  if (SecondMI.getOpcode() != RISCV::ADD)
    return false;
  if (!withSameDest(FirstMI, SecondMI))
    return false;
  auto Imm = FirstMI->getOperand(2).getImm();
  if (Imm >= 1 && Imm <= 4)
    return true;
  return false;
}

static bool isZeroExtendedShiftPair(const MachineInstr *FirstMI,
                                    const MachineInstr &SecondMI) {
  if (FirstMI->getOpcode() != RISCV::SLLI)
    return false;
  if (SecondMI.getOpcode() != RISCV::SRLI)
    return false;
  if (FirstMI->getOperand(0).getReg() != SecondMI.getOperand(0).getReg())
    return false;
  auto Imm1 = FirstMI->getOperand(2).getImm();
  auto Imm2 = SecondMI.getOperand(2).getImm();
  if (Imm1 != 32)
    return false;
  if (Imm2 >= 29 && Imm2 <= 31)
    return false;
  return true;
}

static bool isGetSecondBytePair(const MachineInstr *FirstMI,
                                const MachineInstr &SecondMI) {
  if (FirstMI->getOpcode() != RISCV::SRLI)
    return false;
  if (SecondMI.getOpcode() != RISCV::ANDI)
    return false;
  if (!withSameDest(FirstMI, SecondMI))
    return false;
  auto Imm1 = FirstMI->getOperand(2).getImm();
  auto Imm2 = SecondMI.getOperand(2).getImm();
  if (Imm1 != 8)
    return false;
  if (Imm2 != 255)
    return false;
  return true;
}

static bool isShiftRightAndAddPair(const MachineInstr *FirstMI,
                                   const MachineInstr &SecondMI) {
  if (FirstMI->getOpcode() != RISCV::SRLI)
    return false;
  if (SecondMI.getOpcode() != RISCV::ADD)
    return false;
  if (!withSameDest(FirstMI, SecondMI))
    return false;
  auto Imm = FirstMI->getOperand(2).getImm();
  if (Imm >= 29 && Imm <= 32)
    return true;
  return false;
}

static bool isAddOneIfOddPair(const MachineInstr *FirstMI,
                              const MachineInstr &SecondMI) {
  if (FirstMI->getOpcode() != RISCV::ANDI)
    return false;
  auto SecondOp = SecondMI.getOpcode();
  if (SecondOp != RISCV::ADD && SecondOp != RISCV::ADDW)
    return false;
  if (!withSameDest(FirstMI, SecondMI))
    return false;
  auto Imm = FirstMI->getOperand(2).getImm();
  if (Imm == 1)
    return true;
  return false;
}

static bool isAddwAndExtractLowerPair(const MachineInstr *FirstMI,
                                      const MachineInstr &SecondMI) {
  if (FirstMI->getOpcode() != RISCV::ADDIW &&
      FirstMI->getOpcode() != RISCV::ADDW)
    return false;
  auto SecondOp = SecondMI.getOpcode();
  if (SecondOp != RISCV::ANDI)
    return false;
  if (!withSameDest(FirstMI, SecondMI))
    return false;
  auto Imm = SecondMI.getOperand(2).getImm();
  if (Imm == 0x1 || Imm == 0xFF)
    return true;
  return false;
}

static bool isAddwAndExtendPair(const MachineInstr *FirstMI,
                                const MachineInstr &SecondMI) {
  if (FirstMI->getOpcode() != RISCV::ADDW)
    return false;
  auto SecondOp = SecondMI.getOpcode();
  if (SecondOp != RISCV::ZEXT_H_RV32 && SecondOp != RISCV::ZEXT_H_RV64 &&
      SecondOp != RISCV::SEXT_H)
    return false;
  if (!withSameDest(FirstMI, SecondMI))
    return false;
  return true;
}

static bool isLogicInstruction(const MachineInstr *MI) {
  auto Opcode = MI->getOpcode();
  switch (Opcode) {
  case RISCV::AND:
  case RISCV::OR:
  case RISCV::XOR:
  case RISCV::ANDI:
  case RISCV::ORI:
  case RISCV::XORI:
  case RISCV::SLL:
  case RISCV::SRL:
  case RISCV::SRA:
  case RISCV::SLLI:
  case RISCV::SRLI:
  case RISCV::SRAI:
    return true;
  default:
    return false;
  }
}

static bool isLogicAndExtractPair(const MachineInstr *FirstMI,
                                  const MachineInstr &SecondMI) {
  if (!isLogicInstruction(FirstMI))
    return false;
  auto SecondOp = SecondMI.getOpcode();
  if (SecondOp == RISCV::ANDI) {
    auto Imm = SecondMI.getOperand(2).getImm();
    if (Imm == 0x1)
      return true;
  } else if (SecondOp != RISCV::ZEXT_H_RV32 && SecondOp != RISCV::ZEXT_H_RV64) {
    return false;
  }
  if (!withSameDest(FirstMI, SecondMI))
    return false;

  return false;
}

static bool isORWithLower8bit0Pair(const MachineInstr *FirstMI,
                                   const MachineInstr &SecondMI) {
  if (FirstMI->getOpcode() != RISCV::SLLI)
    return false;
  auto Imm = FirstMI->getOperand(2).getImm();
  if (Imm != 0x8)
    return false;
  auto SecondOp = SecondMI.getOpcode();
  if (SecondOp != RISCV::ORI)
    return false;
  if (!withSameDest(FirstMI, SecondMI))
    return false;
  return true;
}

static bool is7And32BitMulPair(const MachineInstr *FirstMI,
                               const MachineInstr &SecondMI) {
  if (FirstMI->getOpcode() != RISCV::ANDI)
    return false;
  auto Imm = FirstMI->getOperand(2).getImm();
  if (Imm != 0x7F)
    return false;
  auto SecondOp = SecondMI.getOpcode();
  if (SecondOp != RISCV::MULW)
    return false;
  if (!withSameDest(FirstMI, SecondMI))
    return false;
  return true;
}

/// Check if the instr pair, FirstMI and SecondMI, should be fused
/// together. Given SecondMI, when FirstMI is unspecified, then check if
/// SecondMI may be part of a fused pair at all.
static bool shouldScheduleAdjacent(const TargetInstrInfo &TII,
                                   const TargetSubtargetInfo &TSI,
                                   const MachineInstr *FirstMI,
                                   const MachineInstr &SecondMI) {
  //const RISCVSubtarget &ST = static_cast<const RISCVSubtarget &>(TSI);
  if (!FirstMI)
    return false;
  if (isFuseAdduwOrZexthPair(FirstMI, SecondMI))
    return true;
  if (is16bitSignExtendPair(FirstMI, SecondMI))
    return true;
  if (isShiftLeftAndAddPair(FirstMI, SecondMI))
    return true;
  if (isZeroExtendedShiftPair(FirstMI, SecondMI))
    return true;
  if (isGetSecondBytePair(FirstMI, SecondMI))
    return true;
  if (isShiftRightAndAddPair(FirstMI, SecondMI))
    return true;
  if (isAddOneIfOddPair(FirstMI, SecondMI))
    return true;
  if (isAddwAndExtendPair(FirstMI, SecondMI))
    return true;
  if (isAddwAndExtractLowerPair(FirstMI, SecondMI))
    return true;
  if (isORWithLower8bit0Pair(FirstMI,SecondMI))
    return true;
  if (isLogicAndExtractPair(FirstMI, SecondMI))
    return true;
  if (is7And32BitMulPair(FirstMI, SecondMI))
    return true;
  return false;
}

std::unique_ptr<ScheduleDAGMutation> createRISCVMacroFusionDAGMutation() {
  return createMacroFusionDAGMutation(shouldScheduleAdjacent);
}

} // end namespace llvm