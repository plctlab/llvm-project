// RUN: %clang --target=riscv32-unknown-elf -mzce-muli  -c %s -o %t
// RUN: llvm-objdump -d --mattr=+zce-muli --mattr=m %t | FileCheck %s

muli s0, s1, 2
// CHECK: muli s0, s1, 2