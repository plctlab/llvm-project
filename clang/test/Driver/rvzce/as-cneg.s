// RUN: %clang --target=riscv32-unknown-elf -mzce-cneg -c %s -o %t
// RUN: llvm-objdump -d --mattr=+experimental-zce %t | FileCheck %s

c.neg s0
// CHECK: c.neg s0