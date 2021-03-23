# With K extension:
# RUN: not llvm-mc -triple=riscv32 -mattr=+experimental-k < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR

# With Zkn extension:
# RUN: not llvm-mc -triple=riscv32 -mattr=+experimental-zkn < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR

# With Zknd extension:
# RUN: not llvm-mc -triple=riscv32 -mattr=+experimental-zknd < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR

aes32dsmi t0, a2, 8
# CHECK-ERROR: immediate must be an integer in the range [0, 3]

aes32dsi t0, a2, 8
# CHECK-ERROR: immediate must be an integer in the range [0, 3]
