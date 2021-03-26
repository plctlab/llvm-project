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

# With Zknh extension:
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-zknh %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zknh %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zknh - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zknh %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# CHECK-INST: sha512sig0 a0, a1
# CHECK-ENCODING: [0x13,0x95,0x65,0x10]
# CHECK-ERROR: instruction requires the following: 'Zknh'(NIST SHA2 Hash function instructions)
# CHECK-UNKNOWN: 13 95 65 10 <unknown>
sha512sig0 a0, a1

# CHECK-INST: sha512sig1 a0, a1
# CHECK-ENCODING: [0x13,0x95,0x75,0x10]
# CHECK-ERROR: instruction requires the following: 'Zknh'(NIST SHA2 Hash function instructions)
# CHECK-UNKNOWN: 13 95 75 10 <unknown>
sha512sig1 a0, a1

# CHECK-INST: sha512sum0 a0, a1
# CHECK-ENCODING: [0x13,0x95,0x45,0x10]
# CHECK-ERROR: instruction requires the following: 'Zknh'(NIST SHA2 Hash function instructions)
# CHECK-UNKNOWN: 13 95 45 10 <unknown>
sha512sum0 a0, a1

# CHECK-INST: sha512sum1 a0, a1
# CHECK-ENCODING: [0x13,0x95,0x55,0x10]
# CHECK-ERROR: instruction requires the following: 'Zknh'(NIST SHA2 Hash function instructions)
# CHECK-UNKNOWN: 13 95 55 10 <unknown>
sha512sum1 a0, a1
