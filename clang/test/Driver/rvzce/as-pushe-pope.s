// RUN: %clang --target=riscv32-unknown-elf -mzce-pushe-pope -c %s -o %t
// RUN: llvm-objdump -d --mattr=+experimental-zce -M no-aliases -r %t | FileCheck %s

push.e {ra, s0-s4}, {a0-a3}, -528
// CHECK: push {ra, s0-s4}, {a0-a3}, -528

pop.e {ra, s0-s2}, {}, 16
// CHECK: pop {ra, s0-s2}, {}, 16

popret.e {ra, s0-s2}, {}, 16
// CHECK: popret {ra, s0-s2}, {}, 16