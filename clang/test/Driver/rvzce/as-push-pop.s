// RUN: %clang --target=riscv32-unknown-elf -mzce-push-pop -c %s -o %t
// RUN: llvm-objdump -d --mattr=+experimental-zce %t | FileCheck %s

push {ra, s0-s1}, {a0-a1}, -128
// CHECK: push {ra, s0-s1}, {a0-a1}, -128

pop {ra, s0-s1}, {0}, 128
// CHECK: pop {ra, s0-s1}, {0}, 128

popret {ra, s0-s1}, {0}, 128
// CHECK: popret {ra, s0-s1}, {0}, 128