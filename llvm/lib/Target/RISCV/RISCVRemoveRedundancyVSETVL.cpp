#include "RISCVTargetMachine.h"

using namespace llvm;

#define RISCV_VECTOR_REMOVE_REDUNDANCY_VSETVL "RISCV vector remove redundancy vsetvl"

/// Decide if the two vsetvli instruction is the same 
static bool isSameVsetvli(MachineInstr &, MachineInstr &);

/// Decode if the Machineinstr is the vsetvli instruction
static bool isVsetvli(MachineInstr &);

namespace {
class RISCVRemoveRedundancyVSETVL : public MachineFunctionPass {
public:
  static char ID;

  RISCVRemoveRedundancyVSETVL() : MachineFunctionPass(ID) {
    initializeRISCVRemoveRedundancyVSETVLPass(*PassRegistry::getPassRegistry());
  }

  bool runOnMachineFunction(MachineFunction &MF) override;

  StringRef getPassName() const override { return RISCV_VECTOR_REMOVE_REDUNDANCY_VSETVL; }

  void removeVsetvliInMF(MachineFunction &MF);

  /// remove the redundancy vetvli instruction in MachineBasicBlock 
  /// and return the first non-redundancy vsetvli and the last non-redundancy
  /// vsetvli instruction, return nullptr if no vsetvli exist
  std::shared_ptr<std::pair<MachineInstr *, MachineInstr *>> 
    removeVsetvliInMBB(MachineBasicBlock &MBB); 
};
}

char RISCVRemoveRedundancyVSETVL::ID = 0;

bool RISCVRemoveRedundancyVSETVL::runOnMachineFunction(MachineFunction &MF) {
  removeVsetvliInMF(MF);
  return true;
}

void RISCVRemoveRedundancyVSETVL::removeVsetvliInMF(MachineFunction &MF) {
  for (auto &MBB : MF) {
    removeVsetvliInMBB(MBB);
  }
}

std::shared_ptr<std::pair<MachineInstr *, MachineInstr *>> 
RISCVRemoveRedundancyVSETVL::removeVsetvliInMBB(MachineBasicBlock &MBB) {
  MachineInstr * firstEffectiveVsetvli = nullptr;
  MachineInstr * lastEffectiveVsetvli = nullptr;

  // unnecessay vsetvli instruction to be removed after iterate the MBB
  std::vector<MachineInstr *> unnecessaryVsetvli;
  for (llvm::MachineBasicBlock::iterator instr : MBB) {
    if (isVsetvli(*instr)) {
      if (firstEffectiveVsetvli == nullptr)
        firstEffectiveVsetvli = &(*instr);
      else {
        if (lastEffectiveVsetvli == nullptr) {
          if (isSameVsetvli(*instr, *firstEffectiveVsetvli)) {
            unnecessaryVsetvli.push_back(&(*instr));
          } else {
            lastEffectiveVsetvli = &(*instr);
          }
        }
        else if (isSameVsetvli(*instr, *lastEffectiveVsetvli))
          unnecessaryVsetvli.push_back(&(*instr));
        else 
          lastEffectiveVsetvli = &(*instr);
      }
    }
  }

  // remove the unnecessay vsetvli
  for (std::vector<MachineInstr *>::iterator it = unnecessaryVsetvli.begin(); 
          it != unnecessaryVsetvli.end(); it++) {
    (*it)->eraseFromParent();
  }


  if (firstEffectiveVsetvli == nullptr)
    return nullptr;
  else if (lastEffectiveVsetvli == nullptr)
    return std::make_shared<std::pair<MachineInstr *, MachineInstr *>>(firstEffectiveVsetvli, firstEffectiveVsetvli);
  else 
    return std::make_shared<std::pair<MachineInstr *, MachineInstr *>>(firstEffectiveVsetvli, lastEffectiveVsetvli);
  
}

static bool isSameVsetvli(MachineInstr & first, MachineInstr & second) {
  assert((first.getOpcode() == RISCV::VSETVLI && second.getOpcode() == RISCV::VSETVLI) &&
            "Expected the machine instruction is the vsetvli instruction");

  for (unsigned i = 0; i < first.getNumOperands(); i++) {
    const MachineOperand &firstOperand = first.getOperand(i);
    const MachineOperand &secondOperand = second.getOperand(i); 
    assert(((firstOperand.isReg() && secondOperand.isReg()) || 
              (firstOperand.isImm() && secondOperand.isImm())) 
                && "Expected two operands has the same operand type");

    if (firstOperand.isReg() && secondOperand.isReg() && 
          !(firstOperand.getReg() == secondOperand.getReg()))
      return false;
    
    if (firstOperand.isImm() && secondOperand.isImm() &&
          !(firstOperand.getImm() == secondOperand.getImm()))
      return false;
  }
  return true;
}

static bool isVsetvli(MachineInstr & instr) {
  return instr.getOpcode() == RISCV::VSETVLI;
}
 
INITIALIZE_PASS(RISCVRemoveRedundancyVSETVL, "riscv-remove-vsetvl",
                RISCV_VECTOR_REMOVE_REDUNDANCY_VSETVL, false, false)

namespace llvm {
  
FunctionPass *createRISCVRemoveRedundancyVSETVLPass() { return new RISCVRemoveRedundancyVSETVL(); }

}