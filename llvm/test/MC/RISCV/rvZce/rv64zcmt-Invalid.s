# RUN: not llvm-mc -triple=riscv64 -mattr=+experimental-zcmt -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck -check-prefixes=CHECK-ERROR %s

# CHECK-ERROR: error: immediate must be an integer in the range [0, 63]
cm.jt 64
