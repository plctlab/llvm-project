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
    
    bool isCandidateToMergeMVA01S(DestSourcePair &RegPair);
    bool isCandidateToMergeMVSA01(DestSourcePair &RegPair);
    // Merge the two instructions indicated into a single pair instruction.
    MachineBasicBlock::iterator
    mergePairedInsns(MachineBasicBlock::iterator I,
                     MachineBasicBlock::iterator Paired,
                     unsigned Opcode);

    //Look for C.MV instruction that can be combined with
    //the given instruction into CM.MVA01S or CM.MVSA01. Return the matching instruction if
    //one exists.
    MachineBasicBlock::iterator findMatchingInst(MachineBasicBlock::iterator &MBBI, unsigned InstOpcode);
    bool MovOpt(MachineBasicBlock &MBB);
    bool runOnMachineFunction(MachineFunction &Fn) override;

    StringRef getPassName() const override { return RISCV_MOVE_OPT_NAME; }
};

char RISCVMoveOpt::ID = 0;

} //end of anonymous namespace

INITIALIZE_PASS(RISCVMoveOpt, "riscv-mov-opt", RISCV_MOVE_OPT_NAME, false,
                false)

// Check if registers meet CM.MVA01S constraints. 
bool RISCVMoveOpt::isCandidateToMergeMVA01S(DestSourcePair &RegPair){
  Register Destination = RegPair.Destination->getReg();
  Register Source = RegPair.Source->getReg();
  const TargetRegisterClass *SourceRC = TRI->getMinimalPhysRegClass(Source);
  // If destination is not a0 or a1.
  if (Destination == RISCV::X10 || Destination == RISCV::X11)
    if (RISCV::SR07RegClass.hasSubClassEq(SourceRC))
      return true;
  return false;
}

// Check if registers meet CM.MVSA01 constraints. 
bool RISCVMoveOpt::isCandidateToMergeMVSA01(DestSourcePair &RegPair){
  Register Destination = RegPair.Destination->getReg();
  Register Source = RegPair.Source->getReg();
  const TargetRegisterClass *DestinationRC = TRI->getMinimalPhysRegClass(Destination);
  // If Source is s0 - s7.
  if (RISCV::SR07RegClass.hasSubClassEq(DestinationRC))
    if (Source == RISCV::X10 || Source == RISCV::X11)
      return true;
  return false;
}

MachineBasicBlock::iterator
RISCVMoveOpt::mergePairedInsns(MachineBasicBlock::iterator I,
                               MachineBasicBlock::iterator Paired,
                               unsigned Opcode){
  MachineBasicBlock::iterator E = I->getParent()->end();
  MachineBasicBlock::iterator NextI = next_nodbg(I, E);
  DestSourcePair FirstPair = TII->isCopyInstrImpl(*I).getValue();
  DestSourcePair PairedRegs = TII->isCopyInstrImpl(*Paired).getValue();

  if(Opcode != RISCV::CM_MVA01S && Opcode !=RISCV::CM_MVSA01)
    return I;

  if (NextI == Paired)
    NextI = next_nodbg(NextI, E);
  DebugLoc DL = I->getDebugLoc();

  if(Opcode == RISCV::CM_MVA01S){
    BuildMI(*I->getParent(), I, DL, TII->get(Opcode))
      .add(*FirstPair.Source)
      .add(*PairedRegs.Source);
  }
  else if(Opcode == RISCV::CM_MVSA01){
    BuildMI(*I->getParent(), I, DL, TII->get(Opcode))
        .add(*FirstPair.Destination)
        .add(*PairedRegs.Destination);
  }

  I->eraseFromParent();
  Paired->eraseFromParent();
  return NextI;
}

MachineBasicBlock::iterator
RISCVMoveOpt::findMatchingInst(MachineBasicBlock::iterator &MBBI, unsigned InstOpcode){
  MachineBasicBlock::iterator E = MBBI->getParent()->end();
  DestSourcePair FirstPair = TII->isCopyInstrImpl(*MBBI).getValue();

  // Track which register units have been modified and used between the first
  // insn and the second insn.
  ModifiedRegUnits.clear();
  UsedRegUnits.clear();

  for (MachineBasicBlock::iterator I = next_nodbg(MBBI,E); I != E;
        I = next_nodbg(I, E)){

    MachineInstr &MI = *I;

    if (auto SecondPair = TII->isCopyInstrImpl(MI)){
      Register SourceReg = SecondPair->Source->getReg();
      Register DestReg = SecondPair->Destination->getReg();

      if((InstOpcode == RISCV::CM_MVA01S && isCandidateToMergeMVA01S(*SecondPair)) ||
         (InstOpcode == RISCV::CM_MVSA01 && isCandidateToMergeMVSA01(*SecondPair))){
        // If register pair is valid and does not contain registers from first instruction.
        if ((FirstPair.Source->getReg() == SourceReg) ||
          (FirstPair.Destination->getReg() == DestReg))
          return E;
        
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

// Finds instructions, which could be represented as C.MV instructions and merged into CM.MVA01S or CM.MVSA01.
bool RISCVMoveOpt::MovOpt(MachineBasicBlock &MBB){
  bool Modified = false;

  for (MachineBasicBlock::iterator MBBI = MBB.begin(), E = MBB.end();
         MBBI != E;) {
    // Check if the instruction can be compressed to C.MV instruction. If it can, return Dest/Src
    // register pair.
    auto RegPair = TII->isCopyInstrImpl(*MBBI);
    if(RegPair.hasValue()){
      unsigned Opcode;
      
      if(isCandidateToMergeMVA01S(*RegPair))
        Opcode = RISCV::CM_MVA01S;
      else if (isCandidateToMergeMVSA01(*RegPair))
        Opcode = RISCV::CM_MVSA01;

      MachineBasicBlock::iterator Paired = findMatchingInst(MBBI, Opcode);
      //If matching instruction could be found merge them.
      if(Paired != E){
        MBBI = mergePairedInsns(MBBI, Paired, Opcode);
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
  if (!Subtarget->hasStdExtZcmp()) {
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
