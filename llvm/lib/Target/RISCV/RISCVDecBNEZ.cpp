/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: instruction sequence analysis
 * Notes: RISCVInstSequence.cpp - accumulate statistics on instruction sequences
*/

//===----------------------------------------------------------------------===//
//
// use "decrement branch not equal zero" decbnez to replace two instructions namely 
//ADDI and BNE
//   Replace:
//   addi  reg1, -1 or -2 or -4 or -8
//   bne reg1, X0, %label
//
//   With:
//   decbnez reg1, scale,  %label
//
// The transformation is carried out under certain conditions:
// 1) comparison is  against zero. 
// 2) decrement is -1 or scaled by 2, 4 or 8.
// 3) the branch is backwards
//
//===----------------------------------------------------------------------===//

#include "RISCV.h"
#include "RISCVTargetMachine.h"
#include "llvm/CodeGen/Passes.h"
#include "llvm/MC/TargetRegistry.h"
#include "llvm/Target/TargetOptions.h"
#include "stdio.h"
#include <fstream>
#include "RISCVInstrInfo.h"
#include "RISCVSubtarget.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"
#include "llvm/Support/Debug.h"

using namespace llvm;

#define DEBUG_TYPE "riscv-decbnez"
#define RISCV_DECBNEZ_NAME "RISCVDecbnez"
namespace {

class  RISCVDecbnez : public MachineFunctionPass {
public:
  static char ID;
  std::ofstream myfile;
  const RISCVSubtarget *STI;
  const RISCVInstrInfo *TII;
  // pass identifier used by LLVM
  RISCVDecbnez() : MachineFunctionPass(ID) // Initialize our member variables 
  {
    std::string name = (std::string(RISCV_DECBNEZ_NAME) + std::string(".txt"));
  }
  // the entry point that will be invoked on MF 
  bool runOnMachineFunction(MachineFunction &MF) override;
  // return pass name
  StringRef getPassName() const override { 
    return RISCV_DECBNEZ_NAME; 
  }
  
private:
  MachineRegisterInfo *MRI;

}; // end of class

} // end anonymous namespace

bool RISCVDecbnez::runOnMachineFunction(MachineFunction &MF) {
  STI = &static_cast<const RISCVSubtarget &>(MF.getSubtarget());
  TII = static_cast<const RISCVInstrInfo *>(MF.getSubtarget().getInstrInfo());
  MRI = &MF.getRegInfo();
  bool Modified = false;

  if (!(STI->enableZceDecbnez())) {
    return Modified;
  }
  
  for (auto &MBB : MF) 
  {
    MachineBasicBlock::iterator MBBI = MBB.begin(), E = MBB.end();
    while (MBBI != E) 
    {
      MachineBasicBlock::iterator NMBBI = std::next(MBBI);
      //dbgs() << "current op is "<< TII->getName(MBBI->getOpcode()) <<"\n";

      switch (MBBI->getOpcode()) {

      case RISCV::BNE:

        //gather the operands of BNE
        //the index variable
        Register SrcReg = MBBI->getOperand(0).getReg();
        //What value to compare with
        Register X0Reg = MBBI->getOperand(1).getReg();
        MachineBasicBlock *   BrLabel = MBBI->getOperand(2).getMBB();
        //place-holder for scale parameter
        int64_t SourceImm = 0;
        DebugLoc DL = MBBI->getDebugLoc();
        //////////////get regdef, Maybe this should be a function////////////
        //traverse back to the regdef
        MachineBasicBlock::iterator RevMBBI = std::prev(MBBI);
        //initialize r1 to X0
        Register r1 = RISCV::X0; 
        bool Defreg_Flag = false;
        //traverse till the start of basicblock
        while (RevMBBI != MBB.begin()) 
        {
          for (unsigned int i = 0; i < RevMBBI->getNumExplicitOperands(); i++) 
          {
            // check that operand is register
            if (RevMBBI->getOperand(i).isReg()){
              // check that operand is destination register
              if (RevMBBI->getOperand(i).isDef()){
                Register r1 = RevMBBI->getOperand(i).getReg();
                //dbgs() << "\nr1 is:   " << r1;
                //dbgs() << "src reg is:  " << SrcReg;
                if(r1 == SrcReg)
                {
                  //found the latest definition
                  //dbgs() << "\nfound index var def";
                  Defreg_Flag = true;
                  //break the for loop
                  break;
                }
              }
            }
          }
          if(Defreg_Flag)
          {
            if(RevMBBI->getOpcode() == RISCV::ADDI){
              SourceImm = RevMBBI->getOperand(2).getImm();
            }
            //break the while loop
            break;
          }
          else
          {
            RevMBBI = std::prev(RevMBBI);
          }        
        }
        ///////////////// end of get reg def /////////////////////////

        //check conditions for decbnez i.e. comparison with 0, valid decrement and backwards jump
        if( X0Reg == RISCV::X0 && \
        (SourceImm == -1 || SourceImm == -2 || SourceImm == -4 || SourceImm == -8 ) && \
        (BrLabel->getNumber() <= MBB.getNumber() ) ) 
        {
          unsigned int scale=0;
          switch(SourceImm)
          {
            case -1:
              scale=0;
            break;
            case -2:
              scale=1;
            break;
            case -4:
              scale=2;
            break;
            case -8:
              scale=3;
            break;
            default:
              dbgs() << "\n invalid immediate value = " <<SourceImm;
            break;
          }
          BuildMI(MBB, MBBI, DL, TII->get(RISCV::DECBNEZ))
          .addReg(SrcReg)
          .addImm(scale)
          .addMBB(BrLabel);
          //remove the bne
          MBBI->removeFromBundle();
          //remove the addi
          RevMBBI->removeFromBundle(); 
          Modified = true;
        }
        break;
      }
      MBBI = NMBBI;
    }
  }
  
  return Modified; 
}

//unsigned int RISCVDecbnez::mfnum = 0;
char RISCVDecbnez::ID = 0;
char &RISCVDecbnezID = RISCVDecbnez::ID ;
INITIALIZE_PASS(RISCVDecbnez, "riscv-dec-bnez",
                RISCV_DECBNEZ_NAME, false, false)

namespace llvm {
FunctionPass *createRISCVDecbnezPass() { return new RISCVDecbnez(); }
}

