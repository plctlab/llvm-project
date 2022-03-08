# RUN: not llvm-mc -triple=riscv64 -mattr=experimental-zcmp -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck -check-prefixes=CHECK-ERROR %s

# CHECK-ERROR: error: invalid operand for instruction
cm.mvsa01 a1, a2

# CHECK-ERROR: error: invalid operand for instruction
cm.mva01s a1, a2

# CHECK-ERROR: error: invalid register list, {ra, s0-s10} is not supported.
cm.popretz {ra, s0-s10}, 112

# CHECK-ERROR: error: This stack adjustment is invalid for this instruction and register list, Please refer to Zce spec for a detailed range of stack adjustment.
cm.popretz {ra, s0-s1}, 112