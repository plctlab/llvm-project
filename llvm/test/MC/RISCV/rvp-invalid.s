# RUN: not llvm-mc -triple riscv32 -mattr=+experimental-p < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-RV32-ERROR
# RUN: not llvm-mc -triple riscv32 -mattr=+experimental-zpn < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-RV32-ERROR
# RUN: not llvm-mc -triple riscv64 -mattr=+experimental-p < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-RV64-ERROR
# RUN: not llvm-mc -triple riscv64 -mattr=+experimental-zpn < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-RV64-ERROR

# 16-bit shift

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 15]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 15]
srai16 a0, a1, 21

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 15]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 15]
srai16.u a0, a1, 21

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 15]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 15]
srli16 a0, a1, 21

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 15]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 15]
srli16.u a0, a1, 21

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 15]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 15]
slli16 a0, a1, 21

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 15]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 15]
kslli16 a0, a1, 21

# 8-bit shift

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 7]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 7]
srai8 a0, a1, 8

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 7]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 7]
srai8.u a0, a1, 9

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 7]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 7]
srli8 a0, a1, 8

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 7]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 7]
srli8.u a0, a1, 9

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 7]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 7]
slli8 a0, a1, 8

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 7]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 7]
kslli8 a0, a1, 9

# Misc

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 7]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 7]
sclip8 a0, a1, 8

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 7]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 7]
uclip8 a0, a1, 8

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 15]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 15]
sclip16 a0, a1, 21

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 15]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 15]
uclip16 a0, a1, 21

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 31]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 31]
sclip32 a0, a1, 37

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 31]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 31]
uclip32 a0, a1, 37

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 31]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 31]
kslliw a0, a1, 37

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 31]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 63]
srai.u a0, a1, 67

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 31]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 63]
bitrevi a0, a1, 67

# CHECK-RV32-ERROR: immediate must be an integer in the range [0, 3]
# CHECK-RV64-ERROR: immediate must be an integer in the range [0, 7]
insb a0, a1, 9
