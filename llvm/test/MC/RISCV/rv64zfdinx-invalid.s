# RUN: not llvm-mc -triple riscv64 -mattr=+experimental-zfdinx < %s 2>&1 | FileCheck %s

# Invalid Instructions
fmv.x.d t2, a2 # CHECK: :[[@LINE]]:13: error: invalid operand for instruction
fmv.d.x a5, t5 # CHECK: :[[@LINE]]:9:  error: invalid operand for instruction
