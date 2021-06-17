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

# With Zknd extension:
# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-zknd %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv32 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zknd %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zknd - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zknd %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# CHECK-INST: aes32dsi a0, a1, a2, 3
# CHECK-ENCODING: [0x33,0x85,0xc5,0xfa]
# CHECK-ERROR: instruction requires the following: 'Zknd'(NIST AES Decryption Instructions)
# CHECK-UNKNOWN: 33 85 c5 fa <unknown>
aes32dsi a0, a1, a2, 3

# CHECK-INST: aes32dsmi a0, a1, a2, 3
# CHECK-ENCODING: [0x33,0x85,0xc5,0xfe]
# CHECK-ERROR: instruction requires the following: 'Zknd'(NIST AES Decryption Instructions)
# CHECK-UNKNOWN: 33 85 c5 fe <unknown>
aes32dsmi a0, a1, a2, 3
