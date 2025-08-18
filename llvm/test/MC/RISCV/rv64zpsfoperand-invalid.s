# RUN: not llvm-mc -triple riscv64 -mattr=+experimental-p < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: not llvm-mc -triple riscv64 -mattr=+experimental-zpsfoperand < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR

# CHECK-ERROR: immediate must be an integer in the range [0, 31]
wexti a0, a1, 33

# CHECK-ERROR: invalid operand for instruction
add64 a0, a0, a1

# CHECK-ERROR: invalid operand for instruction
sub64 a0, a0, a1