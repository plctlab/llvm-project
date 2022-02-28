// RUN: %clang --target=riscv32-unknown-elf -mzce-lsgp -c %s -o %t
// RUN: llvm-objdump -d --mattr=+zce-lsgp %t | FileCheck %s

lwgp s0, 32764(gp)
// CHECK: lwgp s0, 32764(gp)

swgp s0, 32764(gp)
// CHECK: swgp s0, 32764(gp)