// RUN: %clang --target=riscv32-unknown-elf -mzce-sext -c %s -o %t
// RUN: llvm-objdump -d --mattr=+experimental-zce %t | FileCheck %s

c.sext.b s0
// CHECK: c.sext.b s0

c.sext.h s0
// CHECK: c.sext.h s0