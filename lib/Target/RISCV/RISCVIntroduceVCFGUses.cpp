//===- RISCVIntroduceVCFGUses.cpp - Rewrite V instructions to use VCFG ----===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// Introduce uses of VCFG to the Machine IR.
//
// Instruction selection for V emits pseudos that gloss over the fact that most
// instructions read the vector unit configuration CSRs. This pass turns
// those pseudos into instructions that explicitly access VCFG. This is
// required for correctness since later passes introduce instructions that can
// change the configuration.
//
// For various reasons VCFG is modeled as a memory location, so we make the
// uses explicit by crafting an appropriate MachineMemOperand.
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
using namespace llvm;

#define DEBUG_TYPE "riscv-introduce-vcfg-uses"
#define RISCV_INTRODUCE_VCFG_USES_NAME                                         \
  "Introduce uses of RISC-V vector unit configuration"
namespace {

struct RISCVIntroduceVCFGUses : public MachineFunctionPass {
  static char ID;
  const MachineFunction *MF;
  bool runOnMachineFunction(MachineFunction &Fn) override;

  RISCVIntroduceVCFGUses() : MachineFunctionPass(ID) {}

  MachineFunctionProperties getRequiredProperties() const override {
    return MachineFunctionProperties().set(
        MachineFunctionProperties::Property::IsSSA);
  }

  StringRef getPassName() const override {
    return RISCV_INTRODUCE_VCFG_USES_NAME;
  }
};
} // end anonymous namespace

bool RISCVIntroduceVCFGUses::runOnMachineFunction(MachineFunction &Fn) {
  if (skipFunction(Fn.getFunction()))
    return false;
  if (!Fn.getSubtarget<RISCVSubtarget>().hasStdExtV())
    return false;

  LLVM_DEBUG(dbgs() << "*** Inserting vcfg uses into "
                    << Fn.getFunction().getName() << " ***\n");

  auto *MFI = Fn.getInfo<RISCVMachineFunctionInfo>();
  MachineMemOperand *ReadVCFG = MFI->getVCFGReadMMO();

  std::vector<MachineInstr *> InstrsToRemove;
  auto TII = Fn.getSubtarget().getInstrInfo();
  for (MachineBasicBlock &MBB : Fn) {
    for (MachineInstr &ImplicitInstr : MBB) {
      auto Info = RISCVImplicitVCFGTable::getImplicitVCFGInfo(
          ImplicitInstr.getOpcode());
      if (!Info)
        continue;

      // Create a carbon copy of the pseudo, except with different Opcode and
      // with an extra MachineMemOperand
      // FIXME -- surely this must already exist somewhere? would be good to
      //          avoid duplicating that logic, as it's easy to forget something
      // (MachineFunction::Clone* and TII::duplicate can't change the Opcode)
      MachineInstrBuilder Builder =
          BuildMI(MBB, MachineBasicBlock::instr_iterator(ImplicitInstr),
                  ImplicitInstr.getDebugLoc(), TII->get(Info->ExplicitOpcode));

      for (MachineOperand MO : ImplicitInstr.operands()) {
        Builder.add(MO);
      }
      // The instruction may already have mem operands (e.g. it's a vector load)
      Builder.cloneMemRefs(ImplicitInstr);
      // ... but we also need to add another mem operand for the VCFG read
      Builder.addMemOperand(ReadVCFG);
      InstrsToRemove.push_back(&ImplicitInstr);
    }
  }

  for (MachineInstr *MI : InstrsToRemove) {
    MI->eraseFromParent();
  }
  return true;
}

char RISCVIntroduceVCFGUses::ID = 0;
INITIALIZE_PASS(RISCVIntroduceVCFGUses, DEBUG_TYPE,
                RISCV_INTRODUCE_VCFG_USES_NAME, false, false)

/// Returns an instance of the Merge Base Offset Optimization pass.
FunctionPass *llvm::createRISCVIntroduceVCFGUsesPass() {
  return new RISCVIntroduceVCFGUses();
}
