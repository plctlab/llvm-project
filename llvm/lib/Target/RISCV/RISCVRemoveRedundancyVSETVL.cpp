//===- RISCVRemoveRedundantVSETVL.cpp - Remove redundant VSETVL instructions ===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements a function pass that removes the 'vsetvl' instructions
// that are known to have no effect, and thus are redundant.
//
//===----------------------------------------------------------------------===//

#include "RISCVTargetMachine.h"

using namespace llvm;

#define RISCV_VECTOR_REMOVE_REDUNDANCY_VSETVL "RISCV vector remove redundancy vsetvl"

/// Decide if the two vsetvli instruction is the same 
static bool isSameVsetvli(MachineInstr &, MachineInstr &, bool = false);

/// Decode if the Machineinstr is the vsetvli instruction
static bool isVsetvli(MachineInstr &);

namespace {
class RISCVRemoveRedundancyVSETVL : public MachineFunctionPass {
public:
  static char ID;

  // the redundancyVSETVLI record all the redundancy vsetvli
  // instructions, the headVSETVLI record the head meaningful
  // vsetvli instruction, and the tailVSETVLI record the 
  // tail meaningful vsetvli instruction
  std::vector<MachineInstr *> redundancyVSETVLI;
  std::map<MachineBasicBlock *, MachineInstr *> headVSETVLI;
  std::map<MachineBasicBlock *, MachineInstr *> tailVSETVLI;

  RISCVRemoveRedundancyVSETVL() : MachineFunctionPass(ID) {
    initializeRISCVRemoveRedundancyVSETVLPass(*PassRegistry::getPassRegistry());
  }

  bool runOnMachineFunction(MachineFunction &MF) override;

  /// remove the redundancy vsetvli instruction
  /// return true if the number of redundancy instruction 
  /// great than 0, else false
  bool removeRedundancy();

  StringRef getPassName() const override { return RISCV_VECTOR_REMOVE_REDUNDANCY_VSETVL; }

  /// collect the redundancy vsetvli instruction not 
  /// only in just machine basic block, but also 
  /// in between machine basic block, there are some 
  /// redundancy vsetvli
  void collectRedundancyVSETVLIInMF(MachineFunction &MF);

  /// collect the redundancy vsetvli instruction 
  // in every machine basic block and record the 
  // head meaningful vsetvli and tail meaningful vsetvli
  void collectRedundancyVSETVLIInMBB(MachineBasicBlock &MBB); 

  // use a BFS to collect the redundancy vsetvli instruction between MBB,
  // Because of the CFG is not acyclic, so it is not definitly find the 
  // redundancy 
  void collectRedundancyVSETVLIBetweenMBB(MachineFunction &MF);
};
}

char RISCVRemoveRedundancyVSETVL::ID = 0;

bool RISCVRemoveRedundancyVSETVL::runOnMachineFunction(MachineFunction &MF) {
  collectRedundancyVSETVLIInMF(MF);
  return removeRedundancy();
}

bool RISCVRemoveRedundancyVSETVL::removeRedundancy() {
  if (!redundancyVSETVLI.size())
    return false;
  for (MachineInstr * instr : redundancyVSETVLI) {
    instr->eraseFromParent();
  }
  redundancyVSETVLI.clear();
  return true;
}

void RISCVRemoveRedundancyVSETVL::
  collectRedundancyVSETVLIBetweenMBB(MachineFunction &MF) {

  MachineBasicBlock &MBB = *(MF.begin());

  std::map<MachineBasicBlock *, MachineInstr *> lastVSETVLIOfMBB;
  std::vector<std::vector<MachineBasicBlock *>> toIterate{{&(*(MF.begin()))}};

  while (toIterate.back().size() != 0) {
    toIterate.push_back(std::vector<MachineBasicBlock *>());
    for (auto MBB : toIterate[toIterate.size() - 2]) {
      for (MachineBasicBlock::succ_iterator begin = MBB->succ_begin();
              begin != MBB->succ_end(); begin++) {
        if (lastVSETVLIOfMBB.count(*begin) == 0)
          toIterate.back().push_back((*begin));
      }

      MachineInstr * predBlockVSETVLI = nullptr;
      for (MachineBasicBlock::pred_iterator begin = MBB->pred_begin();
            begin != MBB->pred_end(); begin++) {
        MachineInstr * predIterate = lastVSETVLIOfMBB.count(*begin) == 0 ? 
          tailVSETVLI[*begin] : lastVSETVLIOfMBB[*begin];
        
        if (predBlockVSETVLI == nullptr) {
          predBlockVSETVLI = predIterate;
          continue;
        }
        if (predIterate == nullptr || 
          (predIterate != nullptr && 
          !isSameVsetvli(*predBlockVSETVLI, *predIterate)))
          break;
      }

      if (predBlockVSETVLI != nullptr) {
        if (headVSETVLI[MBB] != nullptr) {
          if (isSameVsetvli(*predBlockVSETVLI, *headVSETVLI[MBB], true))
            redundancyVSETVLI.push_back(headVSETVLI[MBB]);
          lastVSETVLIOfMBB[MBB] = tailVSETVLI[MBB];
        } else {
          lastVSETVLIOfMBB[MBB] = predBlockVSETVLI;
        }
      } else {
        lastVSETVLIOfMBB[MBB] = tailVSETVLI[MBB];
      }
    }
  }
}

void RISCVRemoveRedundancyVSETVL::
  collectRedundancyVSETVLIInMF(MachineFunction &MF) {
  for (auto &MBB : MF) {
    collectRedundancyVSETVLIInMBB(MBB);
  }
  collectRedundancyVSETVLIBetweenMBB(MF);
}

void RISCVRemoveRedundancyVSETVL::
  collectRedundancyVSETVLIInMBB(MachineBasicBlock &MBB) {
  MachineInstr * firstEffectiveVSETVLI = nullptr;
  MachineInstr * lastEffectiveVSETVLI = nullptr;

  for (llvm::MachineBasicBlock::iterator instr : MBB) {
    if (isVsetvli(*instr)) {
      if (firstEffectiveVSETVLI == nullptr)
        firstEffectiveVSETVLI = &(*instr);
      else if ((lastEffectiveVSETVLI == nullptr && 
                !isSameVsetvli(*firstEffectiveVSETVLI, *instr, true)) ||
                (lastEffectiveVSETVLI && !isSameVsetvli(*instr,
                  *lastEffectiveVSETVLI)))
        lastEffectiveVSETVLI = &(*instr);
      else
        redundancyVSETVLI.push_back(&(*instr));
    }
  }

  lastEffectiveVSETVLI = lastEffectiveVSETVLI == nullptr ? 
      firstEffectiveVSETVLI : lastEffectiveVSETVLI;

  headVSETVLI.emplace(&MBB, firstEffectiveVSETVLI);
  tailVSETVLI.emplace(&MBB, lastEffectiveVSETVLI);
}

static bool isSameVsetvli(MachineInstr & front, MachineInstr & back, bool order) {
  assert((front.getOpcode() == RISCV::VSETVLI && front.getOpcode() == RISCV::VSETVLI) &&
            "Expected the machine instruction is the vsetvli instruction");

  for (unsigned i = 0; i < front.getNumOperands(); i++) {
    const MachineOperand &frontOperand = front.getOperand(i);
    const MachineOperand &backOperand = back.getOperand(i); 
    assert(((frontOperand.isReg() && backOperand.isReg()) || 
              (frontOperand.isImm() && backOperand.isImm())) 
                && "Expected two operands has the same operand type");
    if (order) {
      if (frontOperand.isReg() && backOperand.isReg() && 
          backOperand.getReg() != RISCV::X0 &&
            frontOperand.getReg() != backOperand.getReg())
        return false;
    } else {
      if (frontOperand.isReg() && backOperand.isReg() && 
          frontOperand.getReg() != backOperand.getReg())
        return false;
    }
    
    if (frontOperand.isImm() && backOperand.isImm() &&
          !(frontOperand.getImm() == backOperand.getImm()))
      return false;
  }
  return true;
}

static bool isVsetvli(MachineInstr & instr) {
  return instr.getOpcode() == RISCV::VSETVLI;
}
 
INITIALIZE_PASS(RISCVRemoveRedundancyVSETVL, "riscv-remove-vsetvl",
                RISCV_VECTOR_REMOVE_REDUNDANCY_VSETVL, false, false)

namespace llvm {
  
FunctionPass *createRISCVRemoveRedundancyVSETVLPass() { return new RISCVRemoveRedundancyVSETVL(); }

}