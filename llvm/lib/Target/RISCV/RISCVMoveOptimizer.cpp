//===- RISCVMoveOptimizer.cpp - RISCV move opt. pass -------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains a pass that performs move related peephole
// optimizations. This pass should be run after register allocation.
//
//===----------------------------------------------------------------------===//


#include "RISCVInstrInfo.h"
#include "RISCVMachineFunctionInfo.h"
#include "RISCVSubtarget.h"

using namespace llvm;

#define RISCV_MOVE_OPT_NAME "RISC-V Zce move merging pass"

namespace{
struct RISCVMoveOpt : public MachineFunctionPass{
    static char ID;

    RISCVMoveOpt(): MachineFunctionPass(ID) {
      initializeRISCVMoveOptPass(*PassRegistry::getPassRegistry());
    }

    const RISCVInstrInfo *TII;
    const TargetRegisterInfo *TRI;
    const RISCVSubtarget *Subtarget;

    // Track which register units have been modified and used.
    LiveRegUnits ModifiedRegUnits, UsedRegUnits;

    // Merge the two instructions indicated into a single pair instruction.
    MachineBasicBlock::iterator
    mergePairedInsns(MachineBasicBlock::iterator I,
                     MachineBasicBlock::iterator Paired);

    //Look for C.MV instruction that can be combined with
    //the given instruction into C.MVA01S07. Return the matching instruction if
    //one exists.
    MachineBasicBlock::iterator findMatchingInst(MachineBasicBlock::iterator &MBBI);
    bool MovOpt(MachineBasicBlock &MBB);
    bool runOnMachineFunction(MachineFunction &Fn) override;

    StringRef getPassName() const override { return RISCV_MOVE_OPT_NAME; }
};

char RISCVMoveOpt::ID = 0;

} //end of anonymous namespace

INITIALIZE_PASS(RISCVMoveOpt, "riscv-mov-opt", RISCV_MOVE_OPT_NAME, false,
                false)

// Check if registers meet C.MVA01S07 constraints.
static bool isCandidateToMerge(DestSourcePair &RegPair){
  Register Destination = RegPair.Destination->getReg();
  Register Source = RegPair.Source->getReg();

  // If destination is not a0 or a1.
  if (Destination != RISCV::X10 &&
      Destination != RISCV::X11)
    return false;

  if (Source == RISCV::X8 || Source == RISCV::X9 ||
     (Source >= RISCV::X18 && Source <= RISCV::X23))
     return true;
  else
     return false;
}

MachineBasicBlock::iterator
RISCVMoveOpt::mergePairedInsns(MachineBasicBlock::iterator I,
                               MachineBasicBlock::iterator Paired){
  MachineBasicBlock::iterator E = I->getParent()->end();
  MachineBasicBlock::iterator NextI = next_nodbg(I, E);
  DestSourcePair FirstPair = TII->getCMovReg(*I).getValue();
  DestSourcePair PairedRegs = TII->getCMovReg(*Paired).getValue();

  if (NextI == Paired)
    NextI = next_nodbg(NextI, E);
  DebugLoc DL = I->getDebugLoc();
  MachineInstrBuilder MIB;
  MIB = BuildMI(*I->getParent(), I, DL, TII->get(RISCV::C_MVA01S07))
            .add(*FirstPair.Source)
            .add(*PairedRegs.Source);
  I->eraseFromParent();
  Paired->eraseFromParent();
  return NextI;
}

MachineBasicBlock::iterator
RISCVMoveOpt::findMatchingInst(MachineBasicBlock::iterator &MBBI){
  MachineBasicBlock::iterator E = MBBI->getParent()->end();
  DestSourcePair FirstPair = TII->getCMovReg(*MBBI).getValue();

  // Track which register units have been modified and used between the first
  // insn and the second insn.
  ModifiedRegUnits.clear();
  UsedRegUnits.clear();

  for (MachineBasicBlock::iterator I = next_nodbg(MBBI,E); I != E;
        I = next_nodbg(I, E)){

    MachineInstr &MI = *I;

    if (auto SecondPair = TII->getCMovReg(MI)){
      Register SourceReg = SecondPair->Source->getReg();
      Register DestReg =   SecondPair->Destination->getReg();

      // If register pair is valid and does not contain registers from first instruction.
      if(isCandidateToMerge(*SecondPair) && (FirstPair.Source->getReg() != SourceReg) &&
        (FirstPair.Destination->getReg() != DestReg)){

        //  If paired destination register was modified or used, there is no possibility
        //  of finding matching instruction so exit early.
        if (!ModifiedRegUnits.available(DestReg) ||  !UsedRegUnits.available(DestReg))
          return E;

        if (ModifiedRegUnits.available(SourceReg))
          return I;
      }
    }
    // Update modified / used register units.
    LiveRegUnits::accumulateUsedDefed(MI, ModifiedRegUnits, UsedRegUnits, TRI);
  }
  return E;
}


// Finds instructions, which could be represented as C.MV instructions and merged into C.MVA01S07.
bool RISCVMoveOpt::MovOpt(MachineBasicBlock &MBB){
  bool Modified = false;

  for (MachineBasicBlock::iterator MBBI = MBB.begin(), E = MBB.end();
         MBBI != E;) {
    // Check if the instruction can be compressed to C.MV instruction. If it can, return Dest/Src
    // register pair.
    auto RegPair = TII->getCMovReg(*MBBI);
    if(RegPair.hasValue() && isCandidateToMerge(*RegPair)){
      MachineBasicBlock::iterator Paired= findMatchingInst(MBBI);
      //If matching instruction could be found merge them.
      if(Paired != E){
        MBBI= mergePairedInsns(MBBI, Paired);
        Modified = true;
        continue;
      }
    }
    ++MBBI;
  }
  return Modified;
}


bool RISCVMoveOpt::runOnMachineFunction(MachineFunction &Fn) {
  if (skipFunction(Fn.getFunction()))
    return false;

  Subtarget = &static_cast<const RISCVSubtarget &>(Fn.getSubtarget());
  if(!Subtarget->hasStdExtZce()){
    return false;
  }

  TII = static_cast<const RISCVInstrInfo *>(Subtarget->getInstrInfo());
  TRI = Subtarget->getRegisterInfo();
  // Resize the modified and used register unit trackers.  We do this once
  // per function and then clear the register units each time we optimize a
  // move.
  ModifiedRegUnits.init(*TRI);
  UsedRegUnits.init(*TRI);
  bool Modified = false;
  for (auto &MBB : Fn) {
    Modified |= MovOpt(MBB);
  }
  return Modified;
}

/// createRISCVMoveOptimizationPass - returns an instance of the
/// move optimization pass.
FunctionPass *llvm::createRISCVMoveOptimizationPass() {
  return new RISCVMoveOpt();
}
