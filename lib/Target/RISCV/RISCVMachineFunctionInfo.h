//=- RISCVMachineFunctionInfo.h - RISCV machine function info -----*- C++ -*-=//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares RISCV-specific per-machine-function information.
//
//===----------------------------------------------------------------------===//

#ifndef LLVM_LIB_TARGET_RISCV_RISCVMACHINEFUNCTIONINFO_H
#define LLVM_LIB_TARGET_RISCV_RISCVMACHINEFUNCTIONINFO_H

#include "llvm/CodeGen/MachineFrameInfo.h"
#include "llvm/CodeGen/MachineFunction.h"
#include "llvm/CodeGen/TargetSubtargetInfo.h"
#include <memory>

namespace llvm {
// RISCV-specific PseudoSourceValue, represents the vector unit configuration.
// Used to help alias analysis distinguish instructions that only access said
// configuration from real memory accesses.
class RISCVVectorConfigPseudoSourceValue : public PseudoSourceValue {
public:
  explicit RISCVVectorConfigPseudoSourceValue(const TargetInstrInfo &TII)
      : PseudoSourceValue(PseudoSourceValue::TargetCustom, TII) {}

  bool isConstant(const MachineFrameInfo *) const override { return false; }

  bool isAliased(const MachineFrameInfo *) const override {
    // The CSRs are not in addressable memory, so IR can't point at them.
    return false;
  }

  bool mayAlias(const MachineFrameInfo *) const override {
    // The CSRs are not in addressable memory, so IR can't point at them.
    return false;
  }
};

/// RISCVMachineFunctionInfo - This class is derived from MachineFunctionInfo
/// and contains private RISCV-specific information for each MachineFunction.
class RISCVMachineFunctionInfo : public MachineFunctionInfo {
private:
  MachineFunction &MF;
  /// FrameIndex for start of varargs area
  int VarArgsFrameIndex = 0;
  /// Size of the save area used for varargs
  int VarArgsSaveSize = 0;
  /// FrameIndex used for transferring values between 64-bit FPRs and a pair
  /// of 32-bit GPRs via the stack.
  int MoveF64FrameIndex = -1;

  std::unique_ptr<RISCVVectorConfigPseudoSourceValue> VCFGPSV;
  std::unique_ptr<MachineMemOperand> MMOReadVCFG;
  std::unique_ptr<MachineMemOperand> MMOWriteVCFG;

public:
  RISCVMachineFunctionInfo() = delete;

  RISCVMachineFunctionInfo(MachineFunction &MF) : MF(MF) {
    auto &TII = *MF.getSubtarget().getInstrInfo();
    VCFGPSV = make_unique<RISCVVectorConfigPseudoSourceValue>(TII);
    MachinePointerInfo PtrInfo(VCFGPSV.get());
    MMOReadVCFG = make_unique<MachineMemOperand>(
        PtrInfo, MachineMemOperand::MOLoad, 1, 1);
    MMOReadVCFG = make_unique<MachineMemOperand>(
        PtrInfo, MachineMemOperand::MOStore, 1, 1);
  }

  int getVarArgsFrameIndex() const { return VarArgsFrameIndex; }
  void setVarArgsFrameIndex(int Index) { VarArgsFrameIndex = Index; }

  unsigned getVarArgsSaveSize() const { return VarArgsSaveSize; }
  void setVarArgsSaveSize(int Size) { VarArgsSaveSize = Size; }

  int getMoveF64FrameIndex() {
    if (MoveF64FrameIndex == -1)
      MoveF64FrameIndex = MF.getFrameInfo().CreateStackObject(8, 8, false);
    return MoveF64FrameIndex;
  }

  MachineMemOperand *getVCFGReadMMO() const { return MMOReadVCFG.get(); }
  MachineMemOperand *getVCFGWriteMMO() const { return MMOWriteVCFG.get(); }
};

} // end namespace llvm

#endif // LLVM_LIB_TARGET_RISCV_RISCVMACHINEFUNCTIONINFO_H
