// RUN: %clang --target=riscv32-unknown-elf -mzce-tbljal -c %s -o %t
// RUN: llvm-objdump -d --mattr=+experimental-zce %t | FileCheck %s

tbljalm 6
// CHECK: tbljalm 6

tblj 40
// CHECK: tblj 40

tbljal 190
// CHECK: tbljal 190