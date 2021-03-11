# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-k %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-k %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-k - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-k %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# CHECK-INST: sha256sig0 a0, a1
# CHECK-ENCODING: [0x13,0x95,0x25,0x10]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 13 95 25 10 <unknown>
sha256sig0 a0, a1

# CHECK-INST: sha256sig1 a0, a1
# CHECK-ENCODING: [0x13,0x95,0x35,0x10]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 13 95 35 10 <unknown>
sha256sig1 a0, a1

# CHECK-INST: sha256sum0 a0, a1
# CHECK-ENCODING: [0x13,0x95,0x05,0x10]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 13 95 05 10 <unknown>
sha256sum0 a0, a1

# CHECK-INST: sha256sum1 a0, a1
# CHECK-ENCODING: [0x13,0x95,0x15,0x10]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 13 95 15 10 <unknown>
sha256sum1 a0, a1

# CHECK-INST: sm3p0 a0, a1
# CHECK-ENCODING: [0x13,0x95,0x85,0x10]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 13 95 85 10 <unknown>
sm3p0 a0, a1

# CHECK-INST: sm3p1 a0, a1
# CHECK-ENCODING: [0x13,0x95,0x95,0x10]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 13 95 95 10 <unknown>
sm3p1 a0, a1

# CHECK-INST: sm4ed t0, a2, 3
# CHECK-ENCODING: [0x33,0x80,0xc2,0xf0]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 33 80 c2 f0 <unknown>
sm4ed t0, a2, 3

# CHECK-INST: sm4ks t0, a2, 3
# CHECK-ENCODING: [0x33,0x80,0xc2,0xf4]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 33 80 c2 f4 <unknown>
sm4ks t0, a2, 3
# CHECK-INST: csrr a0, mnoise 
# CHECK-ENCODING: [0x73,0x25,0x90,0x7a]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 73 25 90 7a
getnoise a0

# CHECK-INST: csrr a0, mentropy
# CHECK-ENCODING: [0x73,0x25,0x50,0xf1]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 73 25 50 f1
pollentropy a0
