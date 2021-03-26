# With K extension:
# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-k %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv32 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-k %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-k - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-k %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# With Zkn extension:
# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-zkn %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv32 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zkn %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zkn - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zkn %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# With Zknh extension:
# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-zknh %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv32 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zknh %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zknh - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zknh %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# CHECK-INST: sha512sig0h a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x5c]
# CHECK-ERROR: instruction requires the following: 'Zknh'(NIST SHA2 Hash function instructions)
# CHECK-UNKNOWN: 33 85 c5 5c <unknown>
sha512sig0h a0, a1, a2

# CHECK-INST: sha512sig1h a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x5e]
# CHECK-ERROR: instruction requires the following: 'Zknh'(NIST SHA2 Hash function instructions)
# CHECK-UNKNOWN: 33 85 c5 5e <unknown>
sha512sig1h a0, a1, a2

# CHECK-INST: sha512sig0l a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x54]
# CHECK-ERROR: instruction requires the following: 'Zknh'(NIST SHA2 Hash function instructions)
# CHECK-UNKNOWN: 33 85 c5 54 <unknown>
sha512sig0l a0, a1, a2

# CHECK-INST: sha512sig1l a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x56]
# CHECK-ERROR: instruction requires the following: 'Zknh'(NIST SHA2 Hash function instructions)
# CHECK-UNKNOWN: 33 85 c5 56 <unknown>
sha512sig1l a0, a1, a2

# CHECK-INST: sha512sum0r a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x50]
# CHECK-ERROR: instruction requires the following: 'Zknh'(NIST SHA2 Hash function instructions)
# CHECK-UNKNOWN: 33 85 c5 50 <unknown>
sha512sum0r a0, a1, a2

# CHECK-INST: sha512sum1r a0, a1, a2
# CHECK-ENCODING: [0x33,0x85,0xc5,0x52]
# CHECK-ERROR: instruction requires the following: 'Zknh'(NIST SHA2 Hash function instructions)
# CHECK-UNKNOWN: 33 85 c5 52 <unknown>
sha512sum1r a0, a1, a2
