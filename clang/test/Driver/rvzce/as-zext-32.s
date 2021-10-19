// RUN: %clang --target=riscv32-unknown-elf -mzce-zext -c %s -o %t
// RUN: llvm-objdump -d --mattr=+experimental-zce %t | FileCheck %s

c.zext.b s0
// CHECK: c.zext.b s0

c.zext.h s0
// CHECK: c.zext.h s0