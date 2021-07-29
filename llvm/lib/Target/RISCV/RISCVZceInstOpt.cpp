#include "RISCV.h"
#include "RISCVInstrInfo.h"

using namespace llvm;

#define DEBUG_TYPE "ZceInstOptPass"
#define DEBUG_ZCE_OPT_NAME "RISCV Zce instruction optimise pass"

namespace {

class RISCVZceInstOpt : public MachineFunctionPass {
public:
    static char ID;
    RISCVZceInstOpt() : MachineFunctionPass(ID){
        initializeRISCVZceInstOptPass(*PassRegistry::getPassRegistry());
    }

    bool runOnMachineFunction(MachineFunction &MF) override;
};

char RISCVZceInstOpt::ID = 0;

bool RISCVZceInstOpt::runOnMachineFunction(MachineFunction &MF){
    // TODO:
    return false;
}

} // end of anonymous namespace

INITIALIZE_PASS(RISCVZceInstOpt, "riscv-zce-inst-optimise", DEBUG_ZCE_OPT_NAME, false, false)

namespace llvm
{
    FunctionPass *createRISCVZceInstOptPass() { return new RISCVZceInstOpt(); }
} // namespace llvm


