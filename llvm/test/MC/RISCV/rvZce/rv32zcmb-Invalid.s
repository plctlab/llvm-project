# RUN: not llvm-mc -triple=riscv32 -mattr=experimental-zcmb -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck -check-prefixes=CHECK-ERROR %s

# CHECK-ERROR: error: immediate must be an integer in the range [0, 15]
cm.lbu a5, 17(a4)

# CHECK-ERROR: error: immediate must be a multiple of 2 bytes in the range [0, 30]
cm.lhu a5, 17(a4)

# CHECK-ERROR: error: immediate must be an integer in the range [0, 15]
cm.lb a5, 17(a4)

# CHECK-ERROR: error: immediate must be a multiple of 2 bytes in the range [0, 30]
cm.lh a5, 17(a4)

# CHECK-ERROR: error: immediate must be an integer in the range [0, 15]
cm.sb a5, 17(a4)

# CHECK-ERROR: error: immediate must be a multiple of 2 bytes in the range [0, 30]
cm.sh a5, 17(a4)
