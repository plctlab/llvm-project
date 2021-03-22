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

# With Zknd extension:
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-zknd %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zknd %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zknd - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zknd %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# CHECK-INST: aes64ds a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x3a]
# CHECK-ERROR: instruction requires the following: 'Zknd'(NIST AES Decryption Instructions)
# CHECK-UNKNOWN: 33 85 c5 3a <unknown>
aes64ds a0, a1, a2

# CHECK-INST: aes64dsm a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x3e]
# CHECK-ERROR: instruction requires the following: 'Zknd'(NIST AES Decryption Instructions)
# CHECK-UNKNOWN: 33 85 c5 3e <unknown>
aes64dsm a0, a1, a2

# CHECK-INST: aes64im a0, a1
# CHECK-ENCODING: [0x13,0x95,0x05,0x30]
# CHECK-ERROR: instruction requires the following: 'Zknd'(NIST AES Decryption Instructions)
# CHECK-UNKNOWN: 13 95 05 30 <unknown>
aes64im a0, a1
