// RUN: %clang --target=riscv32-unknown-elf -mzce-beqi -c %s -o %t
// RUN: llvm-objdump -d --mattr=+zce-beqi %t | FileCheck %s

beqi s0, 20, 40
// CHECK: beqi s0, 20, 0x28