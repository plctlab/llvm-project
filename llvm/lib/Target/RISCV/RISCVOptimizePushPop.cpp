//===- RISCVOptimizePushPop.cpp - RISCV Push/Pop opt. pass -------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains a pass that modifies PUSH/POP instructions from zcea 
// standard to use their non prolog/epilog related functionalities 
// and generates POPRET instruction.
//
//===----------------------------------------------------------------------===//


#include "RISCVInstrInfo.h"
#include "RISCVMachineFunctionInfo.h"

using namespace llvm;

#define RISCV_PUSH_POP_OPT_NAME "RISC-V Zce Push/Pop optimization pass"



namespace{
  struct RISCVPushPopOpt: public MachineFunctionPass{
      static char ID;

      RISCVPushPopOpt(): MachineFunctionPass(ID) {
        initializeRISCVPushPopOptPass(*PassRegistry::getPassRegistry());
      }

      const RISCVInstrInfo *TII;
      const TargetRegisterInfo *TRI;
      const RISCVSubtarget *Subtarget;

      // Track which register units have been modified and used.
      LiveRegUnits ModifiedRegUnits, UsedRegUnits;
      
      bool usePopRet(MachineBasicBlock::iterator &MBBI);
      bool adjustRetVal(MachineBasicBlock::iterator &MBBI);
      bool runOnMachineFunction(MachineFunction &Fn) override;

      std::map<MachineInstr *, int> retValMap;

      StringRef getPassName() const override { return RISCV_PUSH_POP_OPT_NAME; }
  };

  char RISCVPushPopOpt::ID = 0;

} //end of anonymous namespace

INITIALIZE_PASS(RISCVPushPopOpt, "riscv-push-pop-opt", RISCV_PUSH_POP_OPT_NAME, false,
                false)

// Check if POP instruction was inserted into the MBB and return iterator to it.
static MachineBasicBlock::iterator containsPop (MachineBasicBlock &MBB){
  for (MachineBasicBlock::iterator MBBI = MBB.begin(); MBBI != MBB.end(); 
      MBBI = next_nodbg(MBBI,MBB.end()))
    if (MBBI->getOpcode() == RISCV::CM_POP)
      return MBBI;

  return MBB.end();
}

bool RISCVPushPopOpt::usePopRet(MachineBasicBlock::iterator &MBBI){
  MachineBasicBlock::iterator E = MBBI->getParent()->end();
  MachineBasicBlock::iterator NextI = next_nodbg(MBBI, E);
  // Since Pseudo instruction lowering happen later in the pipeline,
  // this will detect all ret instruction.
  if(NextI->getOpcode() == RISCV::PseudoRET){
    DebugLoc DL = NextI->getDebugLoc();
    auto retValInfo = retValMap.find(&(*MBBI));
    if (retValInfo == retValMap.end())
      BuildMI(*NextI->getParent(), NextI, DL, TII->get(RISCV::CM_POPRET))
          .add(MBBI->getOperand(0))
          .add(MBBI->getOperand(1));
    else if (retValInfo->second == 0)
      BuildMI(*NextI->getParent(), NextI, DL, TII->get(RISCV::CM_POPRETZ))
          .add(MBBI->getOperand(0))
          .add(MBBI->getOperand(1));
    // If the return value is not 0 then POPRETZ is not used.
    else
      return false;
    MBBI->eraseFromParent();
    NextI->eraseFromParent();
    return true;
  }
  return false;
}

// Search for last assignment to a0 and if possible use ret_val slot of POP to store return value.
bool RISCVPushPopOpt::adjustRetVal(MachineBasicBlock::iterator &MBBI){
  MachineBasicBlock::reverse_iterator RE = MBBI->getParent()->rend();
  // Track which register units have been modified and used between the POP
  // insn and the last assignment to register a0.
  ModifiedRegUnits.clear();
  UsedRegUnits.clear();
  Register A0(RISCV::X10);
  // Since POP instruction is in Epilogue no normal instructions will follow after it.
  // Therefore search only previous ones to find the return value.
  for (MachineBasicBlock::reverse_iterator I = next_nodbg(MBBI.getReverse(), RE); I != RE; 
      I = next_nodbg(I, RE)){
    MachineInstr &MI = *I;
    if (auto OperandPair = TII->isLoadImmImpl(MI)){
      Register DestReg =   OperandPair->Destination->getReg();
      int64_t RetVal = OperandPair->Source->getImm();
      if (DestReg == RISCV::X10) {
        switch (RetVal)
        {
        default:
          return false;
        case 0:
          retValMap[&(*MBBI)] = 0;
        }
        MI.removeFromParent();
        return true;
      }
    }
    // Update modified / used register units.
    LiveRegUnits::accumulateUsedDefed(MI, ModifiedRegUnits, UsedRegUnits, TRI);
    // If a0 was modified or used, there is no possibility
    // of using ret_val slot of POP instruction.
    if (!ModifiedRegUnits.available(A0) ||  !UsedRegUnits.available(A0))
      return false;
  }
  return false;
}

bool RISCVPushPopOpt::runOnMachineFunction(MachineFunction &Fn) {
  if (skipFunction(Fn.getFunction()))
    return false;

  // If Zcea extension is not supported abort.
  Subtarget = &static_cast<const RISCVSubtarget &>(Fn.getSubtarget());
  if (!Subtarget->hasStdExtZcea()) {
    if (!Subtarget->enableZceCPushCPop())
      return false;
  }
  TII = static_cast<const RISCVInstrInfo *>(Subtarget->getInstrInfo());
  TRI = Subtarget->getRegisterInfo();
  // Resize the modified and used register unit trackers.  We do this once
  // per function and then clear the register units each time we determine 
  // correct return value for the POP.
  ModifiedRegUnits.init(*TRI);
  UsedRegUnits.init(*TRI);
  bool Modified = false;
  for (auto &MBB : Fn) {
    auto MBBI = containsPop(MBB);
    if (MBBI != MBB.end()){
      Modified |= adjustRetVal(MBBI);
      if (MBB.isReturnBlock())
        Modified |= usePopRet(MBBI);
    }
  }
  return Modified;

}

/// createRISCVPushPopOptimizationPass - returns an instance of the
/// Push/Pop optimization pass.
FunctionPass *llvm::createRISCVPushPopOptimizationPass() {
  return new RISCVPushPopOpt();
}