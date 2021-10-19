// RUN: %clang --target=riscv32-unknown-elf -mzce-clbhu -c %s -o %t
// RUN: llvm-objdump -d --mattr=+experimental-zce %t | FileCheck %s

c.lbu a5, 10(a4)
// CHECK: c.lbu a5, 10(a4)

c.lhu a5, 10(a4)
// CHECK: c.lhu a5, 10(a4)