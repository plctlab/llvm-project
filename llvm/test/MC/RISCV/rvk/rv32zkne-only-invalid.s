# With K extension:
# RUN: not llvm-mc -triple=riscv32 -mattr=+experimental-k < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR

# With Zkn extension:
# RUN: not llvm-mc -triple=riscv32 -mattr=+experimental-zkn < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR

# With Zkne extension:
# RUN: not llvm-mc -triple=riscv32 -mattr=+experimental-zkne < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR

aes32esmi t0, a2, 8
# CHECK-ERROR: immediate must be an integer in the range [0, 3]

aes32esi t0, a2, 8
# CHECK-ERROR: immediate must be an integer in the range [0, 3]