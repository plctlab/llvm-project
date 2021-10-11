// RUN: %clang -target riscv32-unknown-elf -### %s 2>&1 | FileCheck %s -check-prefix=DEFAULT
// RUN: %clang -target riscv32-unknown-elf -### %s -mzce-cdecbnez  2>&1 | FileCheck %s -check-prefix=SAVE-RESTORE
// RUN: %clang -target riscv32-unknown-elf -### %s -mno-zce-cdecbnez  2>&1 | FileCheck %s -check-prefix=NO-SAVE-RESTORE

// SAVE-RESTORE: "-target-feature" "+zce-cdecbnez"
// NO-SAVE-RESTORE: "-target-feature" "-zce-cdecbnez"
// DEFAULT: "-target-feature" "-zce-cdecbnez"
// DEFAULT-NOT: "-target-feature" "+zce-cdecbnez"

