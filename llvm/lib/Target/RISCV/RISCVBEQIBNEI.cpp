#include "RISCV.h"
#include "RISCVInstrInfo.h"
#include "RISCVSubtarget.h"
#include "RISCVTargetMachine.h"
#include "stdio.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/Support/Debug.h"
#include "llvm/Target/TargetOptions.h"
#include <fstream>

using namespace llvm;

#define DEBUG_TYPE "riscv-beqi-bnei"
#define RISCV_BEQI_BNEI_NAME "RISCVBeqiBnei"
namespace {

class RISCVBeqiBnei : public MachineFunctionPass {
public:
  static char ID;
  std::ofstream Myfile;
  const RISCVSubtarget *STI;
  const RISCVInstrInfo *TII;
  RISCVBeqiBnei() : MachineFunctionPass(ID) {
    std::string Name = std::string(RISCV_BEQI_BNEI_NAME) + std::string(".txt");
  }

  bool runOnMachineFunction(MachineFunction &MF) override;
  StringRef getPassName() const override { return RISCV_BEQI_BNEI_NAME; }

private:
  MachineRegisterInfo *MRI;
};

} // namespace

bool RISCVBeqiBnei::runOnMachineFunction(MachineFunction &MF) {
  STI = &static_cast<const RISCVSubtarget &>(MF.getSubtarget());
  TII = static_cast<const RISCVInstrInfo *>(MF.getSubtarget().getInstrInfo());
  MRI = &MF.getRegInfo();
  bool Modified = false;

  if (!(STI->enableZceBnei() || STI->enableZceBeqi())) {
    return Modified;
  }

  for (auto &MBB : MF) {
    MachineBasicBlock::iterator MBBI = MBB.begin(), E = MBB.end();
    while (MBBI != E) {
      MachineBasicBlock::iterator NMBBI = std::next(MBBI);
      switch (MBBI->getOpcode()) {
      default:
        break;
      case RISCV::BNE:
      case RISCV::BEQ:
        Register SrcReg1 = MBBI->getOperand(0).getReg();
        Register SrcReg2 = MBBI->getOperand(1).getReg();
        if (SrcReg2 == RISCV::X0) {
          break;
        }
        MachineBasicBlock *BrLabel = MBBI->getOperand(2).getMBB();
        Register SourceImm = 0;
        MachineBasicBlock::iterator PreMBBI;
        DebugLoc DL = MBBI->getDebugLoc();
        if (MBBI != MBB.begin()) {
          PreMBBI = std::prev(MBBI);
        } else
          break;
        bool DefregFlag = false;

        while (1) {
          for (unsigned int I = 0; I < PreMBBI->getNumExplicitOperands(); I++) {
            if (PreMBBI->getOperand(I).isReg() &&
                PreMBBI->getOperand(I).isDef()) {
              Register R1 = PreMBBI->getOperand(I).getReg();
              if (R1 == SrcReg2) {
                DefregFlag = true;
                break;
              }
            }
          }
          if (DefregFlag) {
            if (PreMBBI->getOpcode() == RISCV::ADDI) {
              SourceImm = PreMBBI->getOperand(2).getImm();
            }
            break;
          }
          if (PreMBBI == MBB.begin())
            break;
          PreMBBI = std::prev(PreMBBI);
        }
        if (DefregFlag == true && SourceImm >= 1 && SourceImm <= 31) {
          if (MBBI->getOpcode() == RISCV::BEQ)
            BuildMI(MBB, MBBI, DL, TII->get(RISCV::BEQI))
                .addReg(SrcReg1)
                .addImm(SourceImm)
                .addMBB(BrLabel);
          else
            BuildMI(MBB, MBBI, DL, TII->get(RISCV::BNEI))
                .addReg(SrcReg1)
                .addImm(SourceImm)
                .addMBB(BrLabel);

          MBBI->removeFromBundle();
          PreMBBI->removeFromBundle();
          Modified = true;
        }
        break;
      }
      MBBI = NMBBI;
    }
  }

  return Modified;
}
char RISCVBeqiBnei::ID = 0;
char &RISCVBeqiBneiID = RISCVBeqiBnei::ID;
INITIALIZE_PASS(RISCVBeqiBnei, "riscv-beqibnei", RISCV_BEQI_BNEI_NAME, false,
                false)

namespace llvm {
FunctionPass *createRISCVBeqiBneiPass() { return new RISCVBeqiBnei(); }
} // namespace llvm
