# RUN: not llvm-mc -triple riscv64 -mattr=+experimental-p < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: not llvm-mc -triple riscv64 -mattr=+experimental-zpn < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR

# RV64 only

# CHECK-ERROR: immediate must be an integer in the range [0, 31]
srai32 a0, a1, 37

# CHECK-ERROR: immediate must be an integer in the range [0, 31]
srai32.u a0, a1, 37

# CHECK-ERROR: immediate must be an integer in the range [0, 31]
srli32 a0, a1, 37

# CHECK-ERROR: immediate must be an integer in the range [0, 31]
srli32.u a0, a1, 37

# CHECK-ERROR: immediate must be an integer in the range [0, 31]
slli32 a0, a1, 37

# CHECK-ERROR: immediate must be an integer in the range [0, 31]
kslli32 a0, a1, 37
