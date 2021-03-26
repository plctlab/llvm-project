# With Zks extension:
# RUN: not llvm-mc -triple=riscv32 -mattr=+experimental-zks < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR

# With Zksed extension:
# RUN: not llvm-mc -triple=riscv32 -mattr=+experimental-zksed < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR

sm4ed t0, a2, 8
# CHECK-ERROR: immediate must be an integer in the range [0, 3]

sm4ks t0, a2, 8
# CHECK-ERROR: immediate must be an integer in the range [0, 3]
