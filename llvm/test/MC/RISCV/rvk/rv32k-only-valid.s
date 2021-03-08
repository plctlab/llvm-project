# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-k %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv32 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-k %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-k - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-k %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# CHECK-INST: sha512sum0r a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x50]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 33 85 c5 50 <unknown>
sha512sum0r a0, a1, a2

# CHECK-INST: sha512sum1r a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x52]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 33 85 c5 52 <unknown>
sha512sum1r a0, a1, a2

# CHECK-INST: sha512sig0l a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x54]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 33 85 c5 54 <unknown>
sha512sig0l a0, a1, a2

# CHECK-INST: sha512sig0h a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x5c]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 33 85 c5 5c <unknown>
sha512sig0h a0, a1, a2

# CHECK-INST: sha512sig1l a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x56]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 33 85 c5 56 <unknown>
sha512sig1l a0, a1, a2

# CHECK-INST: sha512sig1h a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x5e]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 33 85 c5 5e <unknown>
sha512sig1h a0, a1, a2

# CHECK-INST: csrr a0, mnoise 
# CHECK-ENCODING: [0x73,0x25,0x90,0x7a]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 73 25 90 7a csrr a0, mnoise
getnoise a0

# CHECK-INST: csrr a0, mentropy
# CHECK-ENCODING: [0x73,0x25,0x50,0xf1]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 73 25 50 f1 csrr a0, mentropy
pollentropy a0

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

# CHECK-INST: aes32esmi t0, a2, 3
# CHECK-ENCODING: [0x33,0x80,0xc2,0xf6]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 33 80 c2 f6 <unknown>
aes32esmi t0, a2, 3

# CHECK-INST: aes32esi t0, a2, 3
# CHECK-ENCODING: [0x33,0x80,0xc2,0xf2]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 33 80 c2 f2 <unknown>
aes32esi t0, a2, 3

# CHECK-INST: aes32dsmi t0, a2, 3
# CHECK-ENCODING: [0x33,0x80,0xc2,0xfe]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 33 80 c2 fe <unknown>
aes32dsmi t0, a2, 3

# CHECK-INST: aes32dsi t0, a2, 3
# CHECK-ENCODING: [0x33,0x80,0xc2,0xfa]
# CHECK-ERROR: instruction requires the following: 'K' (Scalar Cryptography Instructions)
# CHECK-UNKNOWN: 33 80 c2 fa <unknown>
aes32dsi t0, a2, 3
