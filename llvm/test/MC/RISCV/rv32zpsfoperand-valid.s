# With P extension:
# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-p %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv32 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-p %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-zpsfoperand - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-p %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# With Zpsfoperand extension:
# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-zpsfoperand %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv32 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zpsfoperand %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-zpsfoperand - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zpsfoperand %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# Signed 16-bit Multiply with 64-bit Add/Subtract

# CHECK-INST: smal a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0x5e]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 5e <unknown>
smal a0, a2, a4

# SIMD 64-bit Add/Subtract

# CHECK-INST: add64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xc0]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 c0 <unknown>
add64 a0, a2, a4

# CHECK-INST: kadd64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0x90]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 90 <unknown>
kadd64 a0, a2, a4

# CHECK-INST: ksub64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0x92]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 92 <unknown>
ksub64 a0, a2, a4

# CHECK-INST: radd64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0x80]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 80 <unknown>
radd64 a0, a2, a4

# CHECK-INST: rsub64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0x82]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 82 <unknown>
rsub64 a0, a2, a4

# CHECK-INST: sub64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xc2]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 c2 <unknown>
sub64 a0, a2, a4

# CHECK-INST: ukadd64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xb0]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 b0 <unknown>
ukadd64 a0, a2, a4

# CHECK-INST: uksub64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xb2]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 b2 <unknown>
uksub64 a0, a2, a4

# CHECK-INST: uradd64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xa0]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 a0 <unknown>
uradd64 a0, a2, a4

# CHECK-INST: ursub64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xa2]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 a2 <unknown>
ursub64 a0, a2, a4

# 32-bit Multiply 64-bit Add/Subtract

# CHECK-INST: smar64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0x84]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 84 <unknown>
smar64 a0, a2, a4

# CHECK-INST: smsr64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0x86]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 86 <unknown>
smsr64 a0, a2, a4

# CHECK-INST: umar64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xa4]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 a4 <unknown>
umar64 a0, a2, a4

# CHECK-INST: umsr64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xa6]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 a6 <unknown>
umsr64 a0, a2, a4

# CHECK-INST: kmar64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0x94]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 94 <unknown>
kmar64 a0, a2, a4

# CHECK-INST: kmsr64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0x96]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 96 <unknown>
kmsr64 a0, a2, a4

# CHECK-INST: ukmar64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xb4]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 b4 <unknown>
ukmar64 a0, a2, a4

# CHECK-INST: ukmsr64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xb6]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 b6 <unknown>
ukmsr64 a0, a2, a4

# Signed 16-bit Multiply 64-bit Add/Subtract

# CHECK-INST: smalbb a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0x88]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 88 <unknown>
smalbb a0, a2, a4

# CHECK-INST: smalbt a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0x98]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 98 <unknown>
smalbt a0, a2, a4

# CHECK-INST: smaltt a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xa8]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 a8 <unknown>
smaltt a0, a2, a4

# CHECK-INST: smalda a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0x8c]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 8c <unknown>
smalda a0, a2, a4

# CHECK-INST: smalxda a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0x9c]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 9c <unknown>
smalxda a0, a2, a4

# CHECK-INST: smalds a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0x8a]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 8a <unknown>
smalds a0, a2, a4

# CHECK-INST: smaldrs a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0x9a]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 9a <unknown>
smaldrs a0, a2, a4

# CHECK-INST: smalxds a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xaa]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 aa <unknown>
smalxds a0, a2, a4

# CHECK-INST: smslda a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xac]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 ac <unknown>
smslda a0, a2, a4

# CHECK-INST: smslxda a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xbc]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 bc <unknown>
smslxda a0, a2, a4

# 32-bit Computation

# CHECK-INST: mulr64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xf0]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 f0 <unknown>
mulr64 a0, a2, a4

# CHECK-INST: mulsr64 a0, a2, a4
# CHECK-ENCODING: [0x77,0x15,0xe6,0xe0]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 e6 e0 <unknown>
mulsr64 a0, a2, a4

# SIMD 16-bit Multiply

# CHECK-INST: smul16 a0, a2, a4
# CHECK-ENCODING: [0x77,0x05,0xe6,0xa0]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 05 e6 a0 <unknown>
smul16 a0, a2, a4

# CHECK-INST: smulx16 a0, a2, a4
# CHECK-ENCODING: [0x77,0x05,0xe6,0xa2]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 05 e6 a2 <unknown>
smulx16 a0, a2, a4

# CHECK-INST: umul16 a0, a2, a4
# CHECK-ENCODING: [0x77,0x05,0xe6,0xb0]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 05 e6 b0 <unknown>
umul16 a0, a2, a4

# CHECK-INST: umulx16 a0, a2, a4
# CHECK-ENCODING: [0x77,0x05,0xe6,0xb2]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 05 e6 b2 <unknown>
umulx16 a0, a2, a4

# SIMD 8-bit Multiply

# CHECK-INST: smul8 a0, a2, a4
# CHECK-ENCODING: [0x77,0x05,0xe6,0xa8]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 05 e6 a8 <unknown>
smul8 a0, a2, a4

# CHECK-INST: smulx8 a0, a2, a4
# CHECK-ENCODING: [0x77,0x05,0xe6,0xaa]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 05 e6 aa <unknown>
smulx8 a0, a2, a4

# CHECK-INST: umul8 a0, a2, a4
# CHECK-ENCODING: [0x77,0x05,0xe6,0xb8]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 05 e6 b8 <unknown>
umul8 a0, a2, a4

# CHECK-INST: umulx8 a0, a2, a4
# CHECK-ENCODING: [0x77,0x05,0xe6,0xba]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 05 e6 ba <unknown>
umulx8 a0, a2, a4

# Miscellaneous

# CHECK-INST: wext a0, a2, a4
# CHECK-ENCODING: [0x77,0x05,0xe6,0xce]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 05 e6 ce <unknown>
wext a0, a2, a4

# CHECK-INST: wexti a0, a2, 7
# CHECK-ENCODING: [0x77,0x05,0x76,0xde]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 05 76 de <unknown>
wexti a0, a2, 7

# Test with zero operand

# CHECK-INST: add64 zero, a0, a2
# CHECK-ENCODING: [0x77,0x10,0xc5,0xc0]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 10 c5 c0 <unknown>
add64 zero, a0, a2

# CHECK-INST: add64 a0, zero, a2
# CHECK-ENCODING: [0x77,0x15,0xc0,0xc0]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 c0 c0 <unknown>
add64 a0, zero, a2

# CHECK-INST: add64 a0, a2, zero
# CHECK-ENCODING: [0x77,0x15,0x06,0xc0]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 15 06 c0 <unknown>
add64 a0, a2, zero

# CHECK-INST: add64 zero, zero, zero
# CHECK-ENCODING: [0x77,0x10,0x00,0xc0]
# CHECK-ERROR: instruction requires the following: 'Zpsfoperand' (64-bit operand 'P' Instructions)
# CHECK-UNKNOWN: 77 10 00 c0 <unknown>
add64 zero, zero, zero
