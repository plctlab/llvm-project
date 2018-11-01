#include "RISCVBaseInfo.h"
#include "llvm/ADT/ArrayRef.h"

namespace llvm {
namespace RISCVSysReg {
#define GET_SysRegsList_IMPL
#include "RISCVGenSearchableTables.inc"
} // namespace RISCVSysReg

namespace RISCVImplicitVCFGTable {
using namespace RISCV;
#define GET_ImplicitVCFGTable_IMPL
#include "RISCVGenSearchableTables.inc"
} // namespace RISCVImplicitVCFGTable
} // namespace llvm
