// RUN: %clang --target=riscv32-unknown-elf -mzce-cmul -c %s -o %t
// RUN: llvm-objdump -d --mattr=+experimental-zce --mattr=m %t | FileCheck %s

c.mul s0, s1
// CHECK: c.mul s0, s1