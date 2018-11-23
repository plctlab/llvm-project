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
#include "RISCVMachineFunctionInfo.h"
#include "RISCVTargetMachine.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/CodeGen/MachineMemOperand.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/Support/Debug.h"
#include "llvm/Support/Printable.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Target/TargetOptions.h"
#include <vector>
#include <unordered_map>
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
          for (auto& CopyRegsUsed : Instr.uses()) {
            const MachineInstr* MI = MRI.getVRegDef(CopyRegsUsed.getReg());

            if (MI->getOpcode() == RISCV::VSETVL_ic) {
                LLVM_DEBUG(dbgs() << "*** Found COPY instruction from result" <<
                                     "of VSETVL to GPR" << " ***\n");
                LLVM_DEBUG(Instr.dump());

              for (const auto& VSETVLRegsDef : MI->defs()) {
                if (VSETVLRegsDef.getReg() != CopyRegsUsed.getReg()) {
                  LLVM_DEBUG(dbgs() << "*** Replacing VR machine register "
                                    << " ***\n");
                  LLVM_DEBUG(CopyRegsUsed.dump());
                  LLVM_DEBUG(dbgs() << "*** With GPR machine register "
                                    <<  " ***\n");
                  LLVM_DEBUG(VSETVLRegsDef.dump());
                  CopyRegsUsed.setReg(VSETVLRegsDef.getReg());
                }
              }
            }
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