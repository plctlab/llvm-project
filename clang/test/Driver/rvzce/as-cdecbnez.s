// RUN: %clang --target=riscv32-unknown-elf -mzce-cdecbnez -c %s -o %t
// RUN: llvm-objdump -d --mattr=+zce-cdecbnez %t | FileCheck %s

c.decbnez s0, 1, -4
// CHECK: c.decbnez s0, 0, 4
