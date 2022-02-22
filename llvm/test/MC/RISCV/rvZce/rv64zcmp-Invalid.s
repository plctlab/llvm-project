# RUN: not llvm-mc -triple=riscv64 -mattr=experimental-zcmp -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck -check-prefixes=CHECK-ERROR %s

# CHECK-ERROR: error: invalid operand for instruction
cm.mvsa01 a1, a2

# CHECK-ERROR: error: invalid operand for instruction
cm.mva01s a1, a2
