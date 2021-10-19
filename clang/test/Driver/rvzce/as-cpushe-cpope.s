// RUN: %clang --target=riscv32-unknown-elf -mzce-cpushe-cpope -c %s -o %t
// RUN: llvm-objdump -d --mattr=+experimental-zce %t | FileCheck %s

c.pop.e {ra, s0-s3}, {}, 48
// CHECK: c.pop.e {ra, s0-s3}, {}, 48

c.popret.e {ra, s0-s3}, {}, 32
// CHECK: c.popret.e {ra, s0-s3}, {}, 32

c.push.e {ra, s0-s2}, {a0-a2}, -96
// CHECK: c.push.e {ra, s0-s2}, {a0-a2}, -96