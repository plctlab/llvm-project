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

# With Zks extension:
# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-zks %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv32 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zks %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zks - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zks %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# With Zksh extension:
# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-zksh %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv32 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zksh %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zksh - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zksh %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN


# CHECK-INST: sm3p0 a0, a1
# CHECK-ENCODING: [0x13,0x95,0x85,0x10]
# CHECK-ERROR: instruction requires the following: 'Zksh'(SM3 Hash function instructions)
# CHECK-UNKNOWN: 13 95 85 10 <unknown>
sm3p0 a0, a1

# CHECK-INST: sm3p1 a0, a1
# CHECK-ENCODING: [0x13,0x95,0x95,0x10]
# CHECK-ERROR: instruction requires the following: 'Zksh'(SM3 Hash function instructions)
# CHECK-UNKNOWN: 13 95 95 10 <unknown>
sm3p1 a0, a1
