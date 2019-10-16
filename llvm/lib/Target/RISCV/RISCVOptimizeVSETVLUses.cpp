//===- RISCVOptimizeVSETVLUses.cpp - Replace uses of VR from VSETVL ----===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// Optimization pass to avoid copying between VLR and GPR after using vsetvl
//===----------------------------------------------------------------------===//

#include "RISCV.h"
#include "RISCVInstrInfo.h"
#include "RISCVTargetMachine.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Target/TargetOptions.h"
using namespace llvm;

#define DEBUG_TYPE "riscv-optimize-vsetvl-uses"
#define RISCV_OPTIMIZE_VSETVL_USES_NAME                       \
  "Optimization pass to avoid copies to GPR when using VSETVL"
namespace {

struct RISCVOptimizeVSETVLUses : public MachineFunctionPass {
  static char ID;
  const MachineFunction *MF;
  bool runOnMachineFunction(MachineFunction &Fn) override;

  RISCVOptimizeVSETVLUses() : MachineFunctionPass(ID) {}

  MachineFunctionProperties getRequiredProperties() const override {
    return MachineFunctionProperties().set(
        MachineFunctionProperties::Property::IsSSA);
  }

  StringRef getPassName() const override {
    return RISCV_OPTIMIZE_VSETVL_USES_NAME;
  }
};
} // end anonymous namespace


bool isSameRegisterClass(unsigned Reg1, unsigned Reg2) {
  return RISCV::GPRRegClass.contains(Reg1, Reg2) ||
         RISCV::VLRRegClass.contains(Reg1, Reg2);
}

bool RISCVOptimizeVSETVLUses::runOnMachineFunction(MachineFunction &Fn) {
  if (skipFunction(Fn.getFunction()))
    return false;
  if (!Fn.getSubtarget<RISCVSubtarget>().hasStdExtV())
    return false;

  const MachineRegisterInfo &MRI = Fn.getRegInfo();

  LLVM_DEBUG(dbgs() << "*** Optimizing VSETVL in "
                    << Fn.getFunction().getName() << " ***\n");

   for (MachineBasicBlock &MBB : Fn) {
    for (MachineInstr &Instr : MBB) {
      if (Instr.isCopy()) {
          const auto& CopyDest = Instr.getOperand(0);
          auto& CopySource = Instr.getOperand(1);
	 
          const MachineInstr* MI = MRI.getVRegDef(CopySource.getReg());
          if (!MI) {
              // No definition (e.g., a live-in physical register), can't optimize
              continue;
          }

          if (MI->getOpcode() == RISCV::VSETVL &&
                !isSameRegisterClass(CopyDest.getReg(), CopySource.getReg())) {
              LLVM_DEBUG(dbgs() << "*** Found COPY instruction from VSETVL" <<
                                   "across register class" << " ***\n");
              LLVM_DEBUG(Instr.dump());

              const auto& VSETVLDefGPR = MI->getOperand(0);
              const auto& VSETVLDefVLR = MI->getOperand(1);

              //Handle both GPR->VLR and VLR->GPR
              const auto& Replacement = 
                  VSETVLDefGPR.getReg() != CopySource.getReg() ?
                            VSETVLDefGPR : VSETVLDefVLR;

              //Clear flags on CopySource reg
              CopySource.setIsKill(false);

              CopySource.setReg(Replacement.getReg());
              //Remove kill flag on all that use Replacement reg
              MRI.clearKillFlags(Replacement.getReg());
          }
      }
    }
  }

  return true;
}

char RISCVOptimizeVSETVLUses::ID = 0;
INITIALIZE_PASS(RISCVOptimizeVSETVLUses, DEBUG_TYPE,
                RISCV_OPTIMIZE_VSETVL_USES_NAME, false, false)

FunctionPass *llvm::createRISCVOptimizeVSETVLUsesPass() {
  return new RISCVOptimizeVSETVLUses();
}
