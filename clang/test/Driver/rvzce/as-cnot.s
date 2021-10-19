// RUN: %clang --target=riscv32-unknown-elf -mzce-cnot -c %s -o %t
// RUN: llvm-objdump -d --mattr=+experimental-zce %t | FileCheck %s

c.not s0
// CHECK: c.not s0