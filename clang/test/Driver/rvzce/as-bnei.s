// RUN: %clang --target=riscv32-unknown-elf -mzce-bnei -c %s -o %t
// RUN: llvm-objdump -d --mattr=+zce-bnei %t | FileCheck %s

bnei s0, 20, 40
// CHECK: bnei s0, 20, 0x28