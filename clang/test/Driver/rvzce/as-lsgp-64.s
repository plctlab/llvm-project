// RUN: %clang --target=riscv64-unknown-elf -mzce-lsgp -c %s -o %t
// RUN: llvm-objdump -d --mattr=+zce-lsgp %t | FileCheck %s

ldgp s0, 65528(gp)
// CHECK: ldgp s0, 65528(gp)

sdgp s0, 65528(gp)
// CHECK: sdgp s0, 65528(gp)