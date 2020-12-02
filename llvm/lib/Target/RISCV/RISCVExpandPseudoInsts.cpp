//===-- RISCVExpandPseudoInsts.cpp - Expand pseudo instructions -----------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains a pass that expands pseudo instructions into target
// instructions. This pass should be run after register allocation but before
// the post-regalloc scheduling pass.
//
//===----------------------------------------------------------------------===//

#include "RISCV.h"
#include "RISCVInstrInfo.h"
#include "RISCVTargetMachine.h"
#include "llvm/CodeGen/LivePhysRegs.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"

using namespace llvm;

#define RISCV_EXPAND_PSEUDO_NAME "RISCV pseudo instruction expansion pass"

namespace {

class RISCVExpandPseudo : public MachineFunctionPass {
public:
  const RISCVInstrInfo *TII;
  static char ID;

  RISCVExpandPseudo() : MachineFunctionPass(ID) {
    initializeRISCVExpandPseudoPass(*PassRegistry::getPassRegistry());
  }

  bool runOnMachineFunction(MachineFunction &MF) override;

  StringRef getPassName() const override { return RISCV_EXPAND_PSEUDO_NAME; }

private:
  bool expandMBB(MachineBasicBlock &MBB);
  bool expandMI(MachineBasicBlock &MBB, MachineBasicBlock::iterator MBBI,
                MachineBasicBlock::iterator &NextMBBI);
  bool expandAuipcInstPair(MachineBasicBlock &MBB,
                           MachineBasicBlock::iterator MBBI,
                           MachineBasicBlock::iterator &NextMBBI,
                           unsigned FlagsHi, unsigned SecondOpcode);
  bool expandLoadLocalAddress(MachineBasicBlock &MBB,
                              MachineBasicBlock::iterator MBBI,
                              MachineBasicBlock::iterator &NextMBBI);
  bool expandLoadAddress(MachineBasicBlock &MBB,
                         MachineBasicBlock::iterator MBBI,
                         MachineBasicBlock::iterator &NextMBBI);
  bool expandLoadTLSIEAddress(MachineBasicBlock &MBB,
                              MachineBasicBlock::iterator MBBI,
                              MachineBasicBlock::iterator &NextMBBI);
  bool expandLoadTLSGDAddress(MachineBasicBlock &MBB,
                              MachineBasicBlock::iterator MBBI,
                              MachineBasicBlock::iterator &NextMBBI);
  bool expandRISCVVector(MachineBasicBlock &MBB, 
                         MachineBasicBlock::iterator MBBI,
                         MachineBasicBlock::iterator &NextMBBI, unsigned BaseInstr, 
                         int MergeOpIndex, int SEWIndex, int VLMul);
  bool expandReadCSRs(MachineBasicBlock &MBB,
                      MachineBasicBlock::iterator MBBI, int Address);
};

} // end of anonymous namespace

char RISCVExpandPseudo::ID = 0;

bool RISCVExpandPseudo::runOnMachineFunction(MachineFunction &MF) {
  TII = static_cast<const RISCVInstrInfo *>(MF.getSubtarget().getInstrInfo());
  bool Modified = false;

  for (auto &MBB : MF)
    Modified |= expandMBB(MBB);
  return Modified;
}

bool RISCVExpandPseudo::expandMBB(MachineBasicBlock &MBB) {
  bool Modified = false;
  MachineBasicBlock::iterator MBBI = MBB.begin(), E = MBB.end();

  while (MBBI != E) {
    MachineBasicBlock::iterator NMBBI = std::next(MBBI);
    Modified |= expandMI(MBB, MBBI, NMBBI);
    MBBI = NMBBI;
  }
  return Modified;
}

bool RISCVExpandPseudo::expandMI(MachineBasicBlock &MBB,
                                 MachineBasicBlock::iterator MBBI,
                                 MachineBasicBlock::iterator &NextMBBI) {
  // RISCVInstrInfo::getInstSizeInBytes hard-codes the number of expanded
  // instructions for each pseudo, and must be updated when adding new pseudos
  // or changing existing ones.
  if (const RISCVVectorPseudosTable::RISCVVectorPseudoInfo* pseudo = 
      RISCVVectorPseudosTable::getRISCVVectorPseudoInfo(MBBI->getOpcode())) {
    return expandRISCVVector(MBB, MBBI, NextMBBI, pseudo->BaseInstr, 
                             pseudo->getMergeOpIndex(), pseudo->getSEWIndex(),
                             pseudo->VLMul);
  }
  switch (MBBI->getOpcode()) {
  case RISCV::PseudoLLA:
    return expandLoadLocalAddress(MBB, MBBI, NextMBBI);
  case RISCV::PseudoLA:
    return expandLoadAddress(MBB, MBBI, NextMBBI);
  case RISCV::PseudoLA_TLS_IE:
    return expandLoadTLSIEAddress(MBB, MBBI, NextMBBI);
  case RISCV::PseudoLA_TLS_GD:
    return expandLoadTLSGDAddress(MBB, MBBI, NextMBBI);
  case RISCV::PseudoReadVTYPE:
    return expandReadCSRs(MBB, MBBI, 0xC21 /* VTYPE reg address */);
  case RISCV::PseudoReadVL:
    return expandReadCSRs(MBB, MBBI, 0xC20 /* VL reg address */);
  }
  return false;
}

bool RISCVExpandPseudo::expandAuipcInstPair(
    MachineBasicBlock &MBB, MachineBasicBlock::iterator MBBI,
    MachineBasicBlock::iterator &NextMBBI, unsigned FlagsHi,
    unsigned SecondOpcode) {
  MachineFunction *MF = MBB.getParent();
  MachineInstr &MI = *MBBI;
  DebugLoc DL = MI.getDebugLoc();

  Register DestReg = MI.getOperand(0).getReg();
  const MachineOperand &Symbol = MI.getOperand(1);

  MachineBasicBlock *NewMBB = MF->CreateMachineBasicBlock(MBB.getBasicBlock());

  // Tell AsmPrinter that we unconditionally want the symbol of this label to be
  // emitted.
  NewMBB->setLabelMustBeEmitted();

  MF->insert(++MBB.getIterator(), NewMBB);

  BuildMI(NewMBB, DL, TII->get(RISCV::AUIPC), DestReg)
      .addDisp(Symbol, 0, FlagsHi);
  BuildMI(NewMBB, DL, TII->get(SecondOpcode), DestReg)
      .addReg(DestReg)
      .addMBB(NewMBB, RISCVII::MO_PCREL_LO);

  // Move all the rest of the instructions to NewMBB.
  NewMBB->splice(NewMBB->end(), &MBB, std::next(MBBI), MBB.end());
  // Update machine-CFG edges.
  NewMBB->transferSuccessorsAndUpdatePHIs(&MBB);
  // Make the original basic block fall-through to the new.
  MBB.addSuccessor(NewMBB);

  // Make sure live-ins are correctly attached to this new basic block.
  LivePhysRegs LiveRegs;
  computeAndAddLiveIns(LiveRegs, *NewMBB);

  NextMBBI = MBB.end();
  MI.eraseFromParent();
  return true;
}

bool RISCVExpandPseudo::expandLoadLocalAddress(
    MachineBasicBlock &MBB, MachineBasicBlock::iterator MBBI,
    MachineBasicBlock::iterator &NextMBBI) {
  return expandAuipcInstPair(MBB, MBBI, NextMBBI, RISCVII::MO_PCREL_HI,
                             RISCV::ADDI);
}

bool RISCVExpandPseudo::expandLoadAddress(
    MachineBasicBlock &MBB, MachineBasicBlock::iterator MBBI,
    MachineBasicBlock::iterator &NextMBBI) {
  MachineFunction *MF = MBB.getParent();

  unsigned SecondOpcode;
  unsigned FlagsHi;
  if (MF->getTarget().isPositionIndependent()) {
    const auto &STI = MF->getSubtarget<RISCVSubtarget>();
    SecondOpcode = STI.is64Bit() ? RISCV::LD : RISCV::LW;
    FlagsHi = RISCVII::MO_GOT_HI;
  } else {
    SecondOpcode = RISCV::ADDI;
    FlagsHi = RISCVII::MO_PCREL_HI;
  }
  return expandAuipcInstPair(MBB, MBBI, NextMBBI, FlagsHi, SecondOpcode);
}

bool RISCVExpandPseudo::expandLoadTLSIEAddress(
    MachineBasicBlock &MBB, MachineBasicBlock::iterator MBBI,
    MachineBasicBlock::iterator &NextMBBI) {
  MachineFunction *MF = MBB.getParent();

  const auto &STI = MF->getSubtarget<RISCVSubtarget>();
  unsigned SecondOpcode = STI.is64Bit() ? RISCV::LD : RISCV::LW;
  return expandAuipcInstPair(MBB, MBBI, NextMBBI, RISCVII::MO_TLS_GOT_HI,
                             SecondOpcode);
}

bool RISCVExpandPseudo::expandLoadTLSGDAddress(
    MachineBasicBlock &MBB, MachineBasicBlock::iterator MBBI,
    MachineBasicBlock::iterator &NextMBBI) {
  return expandAuipcInstPair(MBB, MBBI, NextMBBI, RISCVII::MO_TLS_GD_HI,
                             RISCV::ADDI);
}

bool RISCVExpandPseudo::expandRISCVVector(MachineBasicBlock &MBB, 
                                          MachineBasicBlock::iterator MBBI,
                                          MachineBasicBlock::iterator &NextMBBI,
                                          unsigned BaseInstr, int MergeOpIndex,
                                          int SEWIndex, int VLMul) {
  MachineInstr &MI = *MBBI;
  DebugLoc DL = MI.getDebugLoc();
  MachineFunction *MF = MBB.getParent();
  auto &STI = MF->getSubtarget();
  auto *RISCVRegInfo = STI.getRegisterInfo(); 

  MachineInstrBuilder MIB = BuildMI(MBB, MI, DL, TII->get(BaseInstr));

    // Remove implicit operands
  // for (MachineInstr::const_mop_iterator Op = NewMI->operands_end();
  //      Op != NewMI->operands_begin(); Op--) {
  //   MachineInstr::const_mop_iterator Base = Op - 1;
  //   if (Base->isImplicit()) {
  //     assert(Base->isReg());
  //     NewMI->RemoveOperand(NewMI->getOperandNo(Base));
  //   }
  // }

  for (MachineInstr::const_mop_iterator Op = MI.operands_begin();
       Op != MI.operands_end(); Op++) {
    int Op_num = (int)MI.getOperandNo(Op);
    if (Op_num == MergeOpIndex || Op_num == SEWIndex)
      continue;

    if (!Op->isReg() || Op->getReg() == RISCV::NoRegister) {
      MIB.add(*Op);
      continue;
    }

    Register Reg = Op->getReg();
    if ((&RISCV::VRM2RegClass)->contains(Reg) ||
        (&RISCV::VRM4RegClass)->contains(Reg) ||
        (&RISCV::VRM8RegClass)->contains(Reg)) {
      Reg = RISCVRegInfo->getSubReg(Reg, RISCV::sub_vrm2);
    }

    unsigned int Flags = 0;
    if (Op->isImplicit())
      Flags |= RegState::Implicit;

    if (Op->isDef())
      Flags |= RegState::Define;

    if (Op->isUndef())
      Flags |= RegState::Undef;

    MIB.addReg(Reg, Flags);
  }

  MI.eraseFromParent(); // The pseudo instruction is gone now.
  return true;
}

// The parameter 'Address' is the address of the CSR register.
bool RISCVExpandPseudo::expandReadCSRs(MachineBasicBlock &MBB,
                                       MachineBasicBlock::iterator MBBI,
                                       int Address) {
  BuildMI(MBB, MBBI, MBBI->getDebugLoc(), TII->get(RISCV::CSRRS),
          MBBI->getOperand(0).getReg())
    .addImm(Address)
    .addReg(RISCV::X0);
  MBBI->eraseFromParent();
  return true;
}

INITIALIZE_PASS(RISCVExpandPseudo, "riscv-expand-pseudo",
                RISCV_EXPAND_PSEUDO_NAME, false, false)

namespace llvm {

FunctionPass *createRISCVExpandPseudoPass() { return new RISCVExpandPseudo(); }

} // end of namespace llvm
