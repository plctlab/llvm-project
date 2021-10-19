// RUN: %clang --target=riscv32-unknown-elf -mzce-cpush-cpop -c %s -o %t
// RUN: llvm-objdump -d --mattr=+experimental-zce -M no-aliases %t | FileCheck %s

c.popret {ra}, {}, 16
// CHECK: c.popret {ra}, {}, 16

c.pop {ra}, {}, 16
// CHECK: c.pop {ra}, {}, 16

c.push {ra}, {}, -16
// CHECK: c.push {ra}, {}, -16