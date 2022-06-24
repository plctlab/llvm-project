# RUN: not llvm-mc -triple riscv32 -mattr=+experimental-p < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: not llvm-mc -triple riscv32 -mattr=+experimental-zpsfoperand < %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR

# Paired register operand

# CHECK-ERROR: error: expected even register
smal a0, a1, a2

# CHECK-ERROR: error: expected even register
add64 a0, a1, a4

# CHECK-ERROR: error: expected even register
radd64 a0, a2, a3

# CHECK-ERROR: error: expected even register
uradd64 a0, a1, a4

# CHECK-ERROR: error: expected even register
kadd64 a0, a2, a3

# CHECK-ERROR: error: expected even register
ukadd64 a0, a1, a4

# CHECK-ERROR: error: expected even register
sub64 a0, a1, a4

# CHECK-ERROR: error: expected even register
rsub64 a0, a2, a3

# CHECK-ERROR: error: expected even register
ursub64 a0, a1, a4

# CHECK-ERROR: error: expected even register
ksub64 a0, a2, a3

# CHECK-ERROR: error: expected even register
uksub64 a0, a1, a4

# CHECK-ERROR: error: expected even register
smar64 a1, a2, a3

# CHECK-ERROR: error: expected even register
smsr64 a5, a6, a7

# CHECK-ERROR: error: expected even register
umar64 a1, a2, a3

# CHECK-ERROR: error: expected even register
umsr64 a5, a6, a7

# CHECK-ERROR: error: expected even register
kmar64 a1, a2, a3

# CHECK-ERROR: error: expected even register
kmsr64 a5, a6, a7

# CHECK-ERROR: error: expected even register
ukmar64 a1, a2, a3

# CHECK-ERROR: error: expected even register
ukmsr64 a5, a6, a7

# CHECK-ERROR: error: expected even register
smalbb a1, a2, a3

# CHECK-ERROR: error: expected even register
smalbt a5, a6, a7

# CHECK-ERROR: error: expected even register
smaltt s3, s4, s5

# CHECK-ERROR: error: expected even register
smalda a1, a2, a3

# CHECK-ERROR: error: expected even register
smalxda a5, a6, a7

# CHECK-ERROR: error: expected even register
smalds a1, a2, a3

# CHECK-ERROR: error: expected even register
smaldrs a5, a6, a7

# CHECK-ERROR: error: expected even register
smalxds s3, s4, s5

# CHECK-ERROR: error: expected even register
smslda a1, a2, a3

# CHECK-ERROR: error: expected even register
smslxda a5, a6, a7

# CHECK-ERROR: error: expected even register
mulr64 a1, a2, a3

# CHECK-ERROR: error: expected even register
mulsr64 a5, a6, a7

# CHECK-ERROR: error: expected even register
umul8 a1, a2, a3

# CHECK-ERROR: error: expected even register
umulx8 a5, a6, a7

# CHECK-ERROR: error: expected even register
umul16 a1, a2, a3

# CHECK-ERROR: error: expected even register
umulx16 a5, a6, a7

# CHECK-ERROR: error: expected even register
smul8 a1, a2, a3

# CHECK-ERROR: error: expected even register
smulx8 a5, a6, a7

# CHECK-ERROR: error: expected even register
smul16 a1, a2, a3

# CHECK-ERROR: error: expected even register
smulx16 a5, a6, a7

# CHECK-ERROR: error: expected even register
wexti a0, a1, 16

# CHECK-ERROR: immediate must be an integer in the range [0, 31]
wexti a0, a2, 33

# CHECK-ERROR: error: expected even register
wext a0, a1, a2

# CHECK-ERROR: error: expected general purpose register
add64 fa0, a1, a4

# CHECK-ERROR: error: expected general purpose register
radd64 a0, fa1, a3

# CHECK-ERROR: error: expected general purpose register
kadd64 a0, a2, fa2
