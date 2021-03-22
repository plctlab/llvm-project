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

# With k base extension:
# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-zkr %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv32 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zkr %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zkr - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zkr %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# CHECK-INST: csrr a0, mnoise 
# CHECK-ENCODING: [0x73,0x25,0x90,0x7a]
# CHECK-ERROR: instruction requires the following: 'Zkr'(Entropy source for seeding random number generators)
# CHECK-UNKNOWN: 73 25 90 7a
getnoise a0

# CHECK-INST: csrr a0, mentropy
# CHECK-ENCODING: [0x73,0x25,0x50,0xf1]
# CHECK-ERROR: instruction requires the following: 'Zkr'(Entropy source for seeding random number generators)
# CHECK-UNKNOWN: 73 25 50 f1
pollentropy a0