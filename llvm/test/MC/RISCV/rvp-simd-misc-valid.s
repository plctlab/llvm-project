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

# SIMD 16-bit Miscellaneous

# CHECK-INST: smin16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x80]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 80 <unknown>
smin16 a0, a1, a2

# CHECK-INST: umin16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x90]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 90 <unknown>
umin16 a0, a1, a2

# CHECK-INST: smax16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x82]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 82 <unknown>
smax16 a0, a1, a2

# CHECK-INST: umax16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x92]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 92 <unknown>
umax16 a0, a1, a2

# CHECK-INST: sclip16 a0, a1, 7
# CHECK-ENCODING: [0x77,0x85,0x75,0x84]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 75 84 <unknown>
sclip16 a0, a1, 7

# CHECK-INST: uclip16 a0, a1, 8
# CHECK-ENCODING: [0x77,0x85,0x85,0x85]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 85 85 <unknown>
uclip16 a0, a1, 8

# CHECK-INST: kabs16 a0, a1
# CHECK-ENCODING: [0x77,0x85,0x15,0xad]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 15 ad <unknown>
kabs16 a0, a1

# CHECK-INST: clrs16 a0, a1
# CHECK-ENCODING: [0x77,0x85,0x85,0xae]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 85 ae <unknown>
clrs16 a0, a1

# CHECK-INST: clz16 a0, a1
# CHECK-ENCODING: [0x77,0x85,0x95,0xae]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 95 ae <unknown>
clz16 a0, a1

# CHECK-INST: swap16 a0, a1
# CHECK-ENCODING: [0x77,0x95,0xb5,0x1e]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 b5 1e <unknown>
swap16 a0, a1

# SIMD 8-bit Miscellaneous

# CHECK-INST: smin8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x88]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 88 <unknown>
smin8 a0, a1, a2

# CHECK-INST: umin8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x98]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 98 <unknown>
umin8 a0, a1, a2

# CHECK-INST: smax8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x8a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 8a <unknown>
smax8 a0, a1, a2

# CHECK-INST: umax8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x9a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 9a <unknown>
umax8 a0, a1, a2

# CHECK-INST: sclip8 a0, a1, 4
# CHECK-ENCODING: [0x77,0x85,0x45,0x8c]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 45 8c <unknown>
sclip8 a0, a1, 4

# CHECK-INST: uclip8 a0, a1, 5
# CHECK-ENCODING: [0x77,0x85,0x55,0x8d]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 55 8d <unknown>
uclip8 a0, a1, 5

# CHECK-INST: kabs8 a0, a1
# CHECK-ENCODING: [0x77,0x85,0x05,0xad]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 05 ad <unknown>
kabs8 a0, a1

# CHECK-INST: clrs8 a0, a1
# CHECK-ENCODING: [0x77,0x85,0x05,0xae]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 05 ae <unknown>
clrs8 a0, a1

# CHECK-INST: clz8 a0, a1
# CHECK-ENCODING: [0x77,0x85,0x15,0xae]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 15 ae <unknown>
clz8 a0, a1

# CHECK-INST: swap8 a0, a1
# CHECK-ENCODING: [0x77,0x85,0x85,0xad]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 85 ad <unknown>
swap8 a0, a1
