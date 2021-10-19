// RUN: %clang --target=riscv32-unknown-elf -mzce-clbh -c %s -o %t
// RUN: llvm-objdump -d --mattr=+experimental-zce %t | FileCheck %s

c.lb a5, 10(a4)
// CHECK: c.lb a5, 10(a4)

c.lh a5, 10(a4)
// CHECK: c.lh a5, 10(a4)