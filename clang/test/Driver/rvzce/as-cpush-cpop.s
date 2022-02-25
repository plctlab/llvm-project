// RUN: %clang --target=riscv32-unknown-elf -mzce-cpush-cpop -c %s -o %t
// RUN: llvm-objdump -d --mattr=zce-cpush-cpop -M no-aliases %t | FileCheck %s

cm.popret {ra}, 16
// CHECK: cm.popret {ra}, 16

cm.pop {ra}, 16
// CHECK: cm.pop {ra}, 16

cm.push {ra}, -16
// CHECK: cm.push {ra}, -16