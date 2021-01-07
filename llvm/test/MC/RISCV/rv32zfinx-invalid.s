# RUN: not llvm-mc -triple riscv32 -mattr=+experimental-zfinx < %s 2>&1 | FileCheck %s

# Invalid instructions
flw fa4, 12(sp) # CHECK: :[[@LINE]]:1: error: instruction requires the following: 'F' (Single-Precision Floating-Point)
fsw a5, 12(sp) # CHECK: :[[@LINE]]:5: error: invalid operand for instruction
fmv.x.d s0, s1 # CHECK: :[[@LINE]]:13: error: invalid operand for instruction
fadd.d t1, t3, t5 # CHECK: :[[@LINE]]:1: error: instruction requires the following: 'Zfdinx' (Double in Integer)

# Invalid register names
lw f15, 100(a0) # CHECK: :[[@LINE]]:4: error: invalid operand for instruction
lw t1, 100(a10) # CHECK: :[[@LINE]]:12: error: expected register
fadd.s a100, a2, a3 # CHECK: :[[@LINE]]:8: error: invalid operand for instruction
