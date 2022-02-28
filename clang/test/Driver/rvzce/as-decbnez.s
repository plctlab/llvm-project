// RUN: %clang --target=riscv32-unknown-elf -mzce-decbnez -c %s -o %t
// RUN: llvm-objdump -d --mattr=+zce-decbnez %t | FileCheck %s

nop
decbnez s0, 1, -4
// CHECK: decbnez s0, 0, 0xfffffffe