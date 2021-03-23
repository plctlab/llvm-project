# With K extension:
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-k %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-k %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-k - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-k %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# With Zkn extension:
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-zkn %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zkn %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zkn - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zkn %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# With Zkne extension:
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-zkne %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zkne %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zkne - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zkne %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# CHECK-INST: aes64esm a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x36]
# CHECK-ERROR: instruction requires the following: 'Zkne'(NIST AES Encryption Instructions)
# CHECK-UNKNOWN: 33 85 c5 36 <unknown>
aes64esm a0, a1, a2

# CHECK-INST: aes64es a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x32]
# CHECK-ERROR: instruction requires the following: 'Zkne'(NIST AES Encryption Instructions)
# CHECK-UNKNOWN: 33 85 c5 32 <unknown>
aes64es a0, a1, a2

# CHECK-INST: aes64ks1i a0, a1, 5
# CHECK-ENCODING: [0x13,0x95,0x55,0x31]
# CHECK-ERROR: instruction requires the following: 'Zkne'(NIST AES Encryption Instructions)
# CHECK-UNKNOWN: 13 95 55 31 <unknown>
aes64ks1i a0, a1, 5

# CHECK-INST: aes64ks2 a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x7e]
# CHECK-ERROR: instruction requires the following: 'Zkne'(NIST AES Encryption Instructions)
# CHECK-UNKNOWN: 33 85 c5 7e <unknown>
aes64ks2 a0, a1, a2
