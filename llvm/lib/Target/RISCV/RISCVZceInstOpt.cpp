#include "RISCV.h"
#include "RISCVSubtarget.h"
#include "RISCVInstrInfo.h"
#include "llvm/CodeGen/MachineBasicBlock.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"

#include <iostream>

using namespace llvm;

#define DEBUG_TYPE "ZceInstOptPass"
#define DEBUG_ZCE_OPT_NAME "RISCV Zce instruction optimise pass"

namespace {

class RISCVZceInstOpt : public MachineFunctionPass {
public:
    const RISCVSubtarget *STI;
    const RISCVInstrInfo *TII;
    static char ID;
    RISCVZceInstOpt() : MachineFunctionPass(ID){
        initializeRISCVZceInstOptPass(*PassRegistry::getPassRegistry());
    }

    bool runOnMachineFunction(MachineFunction &MF) override;
    bool optimiseZceeInstruction(MachineBasicBlock &MBB,
                                MachineBasicBlock::iterator MBBI, 
                                MachineBasicBlock::iterator &NextMBBI);
};

char RISCVZceInstOpt::ID = 0;

bool RISCVZceInstOpt::runOnMachineFunction(MachineFunction &MF){
    // TODO:
    STI = &static_cast<const RISCVSubtarget &>(MF.getSubtarget());
    TII = static_cast<const RISCVInstrInfo *>(MF.getSubtarget().getInstrInfo());
    bool Modified = false;

    if(!STI->hasStdExtZce())
        return Modified;

    for (auto &MBB : MF){
        MachineBasicBlock::iterator MBBI = MBB.begin(), E = MBB.end();
        while (MBBI != E) {
            MachineBasicBlock::iterator NMBBI = std::next(MBBI);
            // std::cout<<"SEXTB:"<<RISCV::SEXTB<<std::endl;
            // std::cout<<MBBI->getOpcode()<<" is SEXTB:"<<(MBBI->getOpcode() == RISCV::SEXTB)<<std::endl;
            switch (MBBI->getOpcode()){
                default:
                    break;
                case RISCV::ZEXTH_RV32:
                case RISCV::ZEXTH_RV64:
                case RISCV::SEXTB:
                case RISCV::SEXTH:
                case RISCV::MUL:
                case RISCV::ANDI:
                    if(STI->hasStdExtZcee())
                        Modified |= optimiseZceeInstruction(MBB, MBBI, NMBBI);
                    break;
            }
            MBBI = NMBBI;
        }
    }
    return Modified;
}

bool RISCVZceInstOpt::optimiseZceeInstruction(MachineBasicBlock &MBB,
                            MachineBasicBlock::iterator MBBI, 
                            MachineBasicBlock::iterator &NextMBBI){
    bool Modified = false;
    switch (MBBI->getOpcode()){
        default:
            break;
        case RISCV::ZEXTH_RV32:
        case RISCV::ZEXTH_RV64:
            if(STI->hasStdExtZbb()){
                Register DestReg = MBBI->getOperand(0).getReg();
                Register SourceReg = MBBI->getOperand(1).getReg();
                DebugLoc DL = MBBI->getDebugLoc();
                if(SourceReg == DestReg && (DestReg >= RISCV::X8 || DestReg <= RISCV::X15)){
                    BuildMI(MBB, MBBI, DL, TII->get(RISCV::C_ZEXT_H), DestReg).addReg(SourceReg);
                    MBBI->removeFromBundle();
                    Modified = true;
                }
            }
            break;
        case RISCV::SEXTB:
            if(STI->hasStdExtZbb()){
                Register DestReg = MBBI->getOperand(0).getReg();
                Register SourceReg = MBBI->getOperand(1).getReg();
                DebugLoc DL = MBBI->getDebugLoc();
                if(SourceReg == DestReg && (DestReg >= RISCV::X8 || DestReg <= RISCV::X15)){
                    BuildMI(MBB, MBBI, DL, TII->get(RISCV::C_SEXT_B), DestReg).addReg(SourceReg);
                    MBBI->removeFromBundle();
                    Modified = true;
                }
            }
            break;
        case RISCV::SEXTH:
            if(STI->hasStdExtZbb()){
                Register DestReg = MBBI->getOperand(0).getReg();
                Register SourceReg = MBBI->getOperand(1).getReg();
                DebugLoc DL = MBBI->getDebugLoc();
                if(SourceReg == DestReg && (DestReg >= RISCV::X8 || DestReg <= RISCV::X15)){
                    BuildMI(MBB, MBBI, DL, TII->get(RISCV::C_SEXT_H), DestReg).addReg(SourceReg);
                    MBBI->removeFromBundle();
                    Modified = true;
                }
            }
            break;
        case RISCV::MUL:
            {
                Register DestReg = MBBI->getOperand(0).getReg();
                Register SourceReg1 = MBBI->getOperand(1).getReg();
                Register SourceReg2 = MBBI->getOperand(2).getReg();
                DebugLoc DL = MBBI->getDebugLoc();
                if(SourceReg1 == DestReg && (DestReg >= RISCV::X8 || DestReg <= RISCV::X15)){
                    BuildMI(MBB, MBBI, DL, TII->get(RISCV::C_MUL), DestReg).addReg(SourceReg1).addReg(SourceReg2);
                    MBBI->removeFromBundle();
                    Modified = true;
                }
            }
            break;
        case RISCV::ANDI:
            {
                Register DestReg = MBBI->getOperand(0).getReg();
                Register SourceReg1 = MBBI->getOperand(1).getReg();
                Register SourceImm = MBBI->getOperand(2).getImm();
                DebugLoc DL = MBBI->getDebugLoc();
                if(SourceReg1 == DestReg && (DestReg >= RISCV::X8 || DestReg <= RISCV::X15) && SourceImm == 255){
                    BuildMI(MBB, MBBI, DL, TII->get(RISCV::C_ZEXT_B), DestReg).addReg(SourceReg1);
                    MBBI->removeFromBundle();
                    Modified = true;
                }
            }
            break;
    }

    return Modified;
}

} // end of anonymous namespace

INITIALIZE_PASS(RISCVZceInstOpt, "riscv-zce-inst-optimise", DEBUG_ZCE_OPT_NAME, false, false)

namespace llvm
{
    FunctionPass *createRISCVZceInstOptPass() { return new RISCVZceInstOpt(); }
} // namespace llvm


