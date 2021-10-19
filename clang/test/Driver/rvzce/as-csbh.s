// RUN: %clang --target=riscv32-unknown-elf -mzce-csbh -c %s -o %t
// RUN: llvm-objdump -d --mattr=+experimental-zce %t | FileCheck %s

c.sb a5, 10(a4)
// CHECK: c.sb a5, 10(a4)

c.sh a5, 10(a4)
// CHECK: c.sh a5, 10(a4)