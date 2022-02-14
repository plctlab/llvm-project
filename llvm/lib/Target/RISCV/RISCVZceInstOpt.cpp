#include "RISCV.h"
#include "RISCVInstrInfo.h"
#include "RISCVSubtarget.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"

#include<map>

using namespace llvm;

#define DEBUG_TYPE "ZceInstOptPass"
#define DEBUG_ZCE_OPT_NAME "RISCV Zce instruction optimise pass"

namespace {

class RISCVZceInstOpt : public MachineFunctionPass {
public:
  const RISCVSubtarget *STI;
  const RISCVInstrInfo *TII;
  static char ID;
  std::map<unsigned,unsigned> optimisItionMap;
  RISCVZceInstOpt() : MachineFunctionPass(ID) {
    initializeRISCVZceInstOptPass(*PassRegistry::getPassRegistry());
    optimisItionMap[RISCV::ZEXTH_RV32] = RISCV::C_ZEXT_H;
    optimisItionMap[RISCV::ZEXTH_RV64] = RISCV::C_ZEXT_H;
    optimisItionMap[RISCV::SEXTB] = RISCV::C_SEXT_B;
    optimisItionMap[RISCV::SEXTH] = RISCV::C_SEXT_H;
    optimisItionMap[RISCV::MUL] = RISCV::C_MUL;
    optimisItionMap[RISCV::ANDI] = RISCV::C_ZEXT_B;
    optimisItionMap[RISCV::ADDUW] = RISCV::C_ZEXT_W;
    // zcea
    optimisItionMap[RISCV::XORI] = RISCV::C_NOT_ZCE;
    optimisItionMap[RISCV::SUB] = RISCV::C_NEG_ZCE;
  }

  bool runOnMachineFunction(MachineFunction &MF) override;
  bool optimiseZceaInstruction(MachineBasicBlock &MBB,
                               MachineBasicBlock::iterator MBBI,
                               MachineBasicBlock::iterator &NextMBBI);
};

char RISCVZceInstOpt::ID = 0;

bool RISCVZceInstOpt::runOnMachineFunction(MachineFunction &MF) {
  // TODO:
  STI = &static_cast<const RISCVSubtarget &>(MF.getSubtarget());
  TII = static_cast<const RISCVInstrInfo *>(MF.getSubtarget().getInstrInfo());
  bool Modified = false;

  if (!(STI->enableZceCMul() || STI->enableZceZext() || STI->enableZceSext() ||
        STI->enableZceCNot() || STI->enableZceMuli() || STI->enableZceCMul() ||
        STI->enableZceCNeg() || STI->enableZceClbhu() ||
        STI->enableZceClbh() || STI->enableZceCsbh() || STI->enableZcePushPop()))
    return Modified;

  for (auto &MBB : MF) {
    MachineBasicBlock::iterator MBBI = MBB.begin(), E = MBB.end();
    while (MBBI != E) {
      MachineBasicBlock::iterator NMBBI = std::next(MBBI);
      switch (MBBI->getOpcode()) {
      default:
        break;
      case RISCV::XORI: // c.not
        if (STI->enableZceCNot())
          Modified |= optimiseZceaInstruction(MBB, MBBI, NMBBI);
        break;
      case RISCV::SUB:  // c.neg
        if (STI->enableZceCNeg())
          Modified |= optimiseZceaInstruction(MBB, MBBI, NMBBI);
        break;
      }
      MBBI = NMBBI;
    }
  }
  return Modified;
}

bool RISCVZceInstOpt::optimiseZceaInstruction(
    MachineBasicBlock &MBB, MachineBasicBlock::iterator MBBI,
    MachineBasicBlock::iterator &NextMBBI) {
  
  bool Modified = false;
  switch (MBBI->getOpcode()) {
  default:
    break;
  case RISCV::XORI:
    if (!STI->isRV32E()) {
      Register DestReg = MBBI->getOperand(0).getReg();
      Register SourceReg = MBBI->getOperand(1).getReg();
      int64_t imm = MBBI->getOperand(2).getImm();
      DebugLoc DL = MBBI->getDebugLoc();
      if(imm == -1 && 
          (DestReg == SourceReg) &&
          (SourceReg >= RISCV::X8 && SourceReg <= RISCV::X15)){
        BuildMI(MBB, MBBI, DL, TII->get(optimisItionMap[MBBI->getOpcode()]), DestReg)
            .addReg(SourceReg);
        MBBI->eraseFromParent();
        Modified = true;
      }
    }
    break;
  case RISCV::SUB:
    if (!STI->isRV32E()) {
      Register DestReg = MBBI->getOperand(0).getReg();
      Register SourceX0 = MBBI->getOperand(1).getReg();
      Register SourceReg = MBBI->getOperand(2).getReg();
      DebugLoc DL = MBBI->getDebugLoc();
      if ((SourceX0 == RISCV::X0) && 
          (DestReg == SourceReg) &&
          (SourceReg >= RISCV::X8 && SourceReg <= RISCV::X15)) {
        BuildMI(MBB, MBBI, DL, TII->get(optimisItionMap[MBBI->getOpcode()]), DestReg)
            .addReg(SourceReg);
        MBBI->eraseFromParent();
        Modified = true;
      }
    }
    break;
  }

  return Modified;
}

} // end of anonymous namespace

INITIALIZE_PASS(RISCVZceInstOpt, "riscv-zce-inst-optimise", DEBUG_ZCE_OPT_NAME,
                false, false)

namespace llvm {
FunctionPass *createRISCVZceInstOptPass() { return new RISCVZceInstOpt(); }
} // namespace llvm
