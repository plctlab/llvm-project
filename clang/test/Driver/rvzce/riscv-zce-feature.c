// RUN: %clang -target riscv32-unknown-elf -### %s 2>&1 | FileCheck %s -check-prefix=DEFAULT
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-lsgp  2>&1 | FileCheck %s -check-prefix=LSGP
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-muli  2>&1 | FileCheck %s -check-prefix=MULI
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-beqi  2>&1 | FileCheck %s -check-prefix=BEQI
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-bnei  2>&1 | FileCheck %s -check-prefix=BNEI
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-decbnez  2>&1 | FileCheck %s -check-prefix=DECBNEZ

// DEFAULT-NOT: "-target-feature" "+zce-lsgp"
// DEFAULT-NOT: "-target-feature" "+zce-muli"
// DEFAULT-NOT: "-target-feature" "+zce-beqi"
// DEFAULT-NOT: "-target-feature" "+zce-bnei"
// DEFAULT-NOT: "-target-feature" "+zce-decbnez"

// LSGP: "-target-feature" "+zce-lsgp"
// MULI: "-target-feature" "+zce-muli"
// BEQI: "-target-feature" "+zce-beqi"
// BNEI: "-target-feature" "+zce-bnei"
// DECBNEZ: "-target-feature" "+zce-decbnez"
