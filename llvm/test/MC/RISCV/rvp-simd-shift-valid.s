# With P extension:
# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-p %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv32 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-p %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-p - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-p %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-p %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-p %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-p - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-p %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# With Zpn extension:
# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-zpn %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv32 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zpn %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-zpn - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zpn %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-zpn %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zpn %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-zpn - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zpn %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# SIMD 16-bit Shift

# CHECK-INST: sra16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x50]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 50 <unknown>
sra16 a0, a1, a2

# CHECK-INST: srai16 a0, a1, 3
# CHECK-ENCODING: [0x77,0x85,0x35,0x70]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 35 70 <unknown>
srai16 a0, a1, 3

# CHECK-INST: sra16.u a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x60]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 60 <unknown>
sra16.u a0, a1, a2

# CHECK-INST: srai16.u a0, a1, 4
# CHECK-ENCODING: [0x77,0x85,0x45,0x71]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 45 71 <unknown>
srai16.u a0, a1, 4

# CHECK-INST: srl16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x52]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 52 <unknown>
srl16 a0, a1, a2

# CHECK-INST: srli16 a0, a1, 9
# CHECK-ENCODING: [0x77,0x85,0x95,0x72]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 95 72 <unknown>
srli16 a0, a1, 9

# CHECK-INST: srl16.u a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x62]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 62 <unknown>
srl16.u a0, a1, a2

# CHECK-INST: srli16.u a0, a1, 10
# CHECK-ENCODING: [0x77,0x85,0xa5,0x73]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 a5 73 <unknown>
srli16.u a0, a1, 10

# CHECK-INST: sll16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x54]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 54 <unknown>
sll16 a0, a1, a2

# CHECK-INST: slli16 a0, a1, 8
# CHECK-ENCODING: [0x77,0x85,0x85,0x74]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 85 74 <unknown>
slli16 a0, a1, 8

# CHECK-INST: ksll16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x64]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 64 <unknown>
ksll16 a0, a1, a2

# CHECK-INST: kslli16 a0, a1, 5
# CHECK-ENCODING: [0x77,0x85,0x55,0x75]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 55 75 <unknown>
kslli16 a0, a1, 5

# CHECK-INST: kslra16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x56]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 56 <unknown>
kslra16 a0, a1, a2

# CHECK-INST: kslra16.u a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x66]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 66 <unknown>
kslra16.u a0, a1, a2

# SIMD 8-bit Shift

# CHECK-INST: sra8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x58]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 58 <unknown>
sra8 a0, a1, a2

# CHECK-INST: srai8 a0, a1, 1
# CHECK-ENCODING: [0x77,0x85,0x15,0x78]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 15 78 <unknown>
srai8 a0, a1, 1

# CHECK-INST: sra8.u a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x68]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 68 <unknown>
sra8.u a0, a1, a2

# CHECK-INST: srai8.u a0, a1, 2
# CHECK-ENCODING: [0x77,0x85,0xa5,0x78]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 a5 78 <unknown>
srai8.u a0, a1, 2

# CHECK-INST: srl8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x5a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 5a <unknown>
srl8 a0, a1, a2

# CHECK-INST: srli8 a0, a1, 3
# CHECK-ENCODING: [0x77,0x85,0x35,0x7a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 35 7a <unknown>
srli8 a0, a1, 3

# CHECK-INST: srl8.u a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x6a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 6a <unknown>
srl8.u a0, a1, a2

# CHECK-INST: srli8.u a0, a1, 4
# CHECK-ENCODING: [0x77,0x85,0xc5,0x7a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 7a <unknown>
srli8.u a0, a1, 4

# CHECK-INST: sll8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x5c]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 5c <unknown>
sll8 a0, a1, a2

# CHECK-INST: slli8 a0, a1, 1
# CHECK-ENCODING: [0x77,0x85,0x15,0x7c]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 15 7c <unknown>
slli8 a0, a1, 1

# CHECK-INST: ksll8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x6c]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 6c <unknown>
ksll8 a0, a1, a2

# CHECK-INST: kslli8 a0, a1, 6
# CHECK-ENCODING: [0x77,0x85,0xe5,0x7c]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 e5 7c <unknown>
kslli8 a0, a1, 6

# CHECK-INST: kslra8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x5e]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 5e <unknown>
kslra8 a0, a1, a2

# CHECK-INST: kslra8.u a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x6e]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 6e <unknown>
kslra8.u a0, a1, a2
