# RUN: not llvm-mc -triple=riscv32 -mattr=experimental-zce -mattr=m -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck -check-prefixes=CHECK-ERROR %s

# CHECK-ERROR: error: immediate must be an integer in the range [0, 7]
tbljalm 8

# CHECK-ERROR: error: immediate must be an integer in the range [0, 55]
tblj 56

# CHECK-ERROR: error: immediate must be an integer in the range [0, 191]
tbljal 192

# CHECK-ERROR: error: immediate must be an integer in the range [0, 15]
c.lbu a5, 16(a4)

# CHECK-ERROR: error: immediate must be a multiple of 2 bytes in the range [0, 30]
c.lhu a5, 31(a4)

# CHECK-ERROR: error: immediate must be an integer in the range [0, 15]
c.lb a5, 16(a4)

# CHECK-ERROR: error: immediate must be a multiple of 2 bytes in the range [0, 30]
c.lh a5, 31(a4)

# CHECK-ERROR: error: immediate must be an integer in the range [0, 15]
c.sb a5, 16(a4)

# CHECK-ERROR: error: immediate must be a multiple of 2 bytes in the range [0, 30]
c.sh a5, 31(a4)
