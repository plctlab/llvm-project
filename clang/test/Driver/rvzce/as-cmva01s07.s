// RUN: %clang --target=riscv32-unknown-elf -mzce-cmva01s07 -c %s -o %t
// RUN: llvm-objdump -d --mattr=+experimental-zce %t | FileCheck %s

c.mva01s07 s0, s1
// CHECK: c.mva01s07 s0, s1