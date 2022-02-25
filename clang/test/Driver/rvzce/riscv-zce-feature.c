// RUN: %clang -target riscv32-unknown-elf -### %s 2>&1 | FileCheck %s -check-prefix=DEFAULT
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-cpush-cpop  2>&1 | FileCheck %s -check-prefix=CPUSHCPOP
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-tbljal  2>&1 | FileCheck %s -check-prefix=TBLJAL
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-clbhu  2>&1 | FileCheck %s -check-prefix=CLBHU
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-clbh  2>&1 | FileCheck %s -check-prefix=CLBH
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-csbh  2>&1 | FileCheck %s -check-prefix=CSBH
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-lsgp  2>&1 | FileCheck %s -check-prefix=LSGP
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-muli  2>&1 | FileCheck %s -check-prefix=MULI
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-cmul  2>&1 | FileCheck %s -check-prefix=CMUL
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-sext  2>&1 | FileCheck %s -check-prefix=SEXT
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-zext  2>&1 | FileCheck %s -check-prefix=ZEXT
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-beqi  2>&1 | FileCheck %s -check-prefix=BEQI
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-bnei  2>&1 | FileCheck %s -check-prefix=BNEI
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-cnot  2>&1 | FileCheck %s -check-prefix=CNOT
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-cneg  2>&1 | FileCheck %s -check-prefix=CNEG
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-cmva01s07  2>&1 | FileCheck %s -check-prefix=CMVA01S07
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-cdecbnez  2>&1 | FileCheck %s -check-prefix=CDECBNEZ
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-decbnez  2>&1 | FileCheck %s -check-prefix=DECBNEZ

// DEFAULT-NOT: "-target-feature" "+zce-cpush-cpop"
// DEFAULT-NOT: "-target-feature" "+zce-tbljal"
// DEFAULT-NOT: "-target-feature" "+zce-clbhu"
// DEFAULT-NOT: "-target-feature" "+zce-clbh"
// DEFAULT-NOT: "-target-feature" "+zce-csbh"
// DEFAULT-NOT: "-target-feature" "+zce-lsgp"
// DEFAULT-NOT: "-target-feature" "+zce-muli"
// DEFAULT-NOT: "-target-feature" "+zce-cmul"
// DEFAULT-NOT: "-target-feature" "+zce-sext"
// DEFAULT-NOT: "-target-feature" "+zce-zext"
// DEFAULT-NOT: "-target-feature" "+zce-beqi"
// DEFAULT-NOT: "-target-feature" "+zce-bnei"
// DEFAULT-NOT: "-target-feature" "+zce-cnot"
// DEFAULT-NOT: "-target-feature" "+zce-cneg"
// DEFAULT-NOT: "-target-feature" "+zce-cmva01s07"
// DEFAULT-NOT: "-target-feature" "+zce-cdecbnez"
// DEFAULT-NOT: "-target-feature" "+zce-decbnez"

// CPUSHCPOP: "-target-feature" "+zce-cpush-cpop"
// TBLJAL: "-target-feature" "+zce-tbljal"
// CLBHU: "-target-feature" "+zce-clbhu"
// CLBH: "-target-feature" "+zce-clbh"
// CSBH: "-target-feature" "+zce-csbh"
// LSGP: "-target-feature" "+zce-lsgp"
// MULI: "-target-feature" "+zce-muli"
// CMUL: "-target-feature" "+zce-cmul"
// SEXT: "-target-feature" "+zce-sext"
// ZEXT: "-target-feature" "+zce-zext"
// BEQI: "-target-feature" "+zce-beqi"
// BNEI: "-target-feature" "+zce-bnei"
// CNOT: "-target-feature" "+zce-cnot"
// CNEG: "-target-feature" "+zce-cneg"
// CMVA01S07: "-target-feature" "+zce-cmva01s07"
// CDECBNEZ: "-target-feature" "+zce-cdecbnez"
// DECBNEZ: "-target-feature" "+zce-decbnez"
