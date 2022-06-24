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

# Non-SIMD Q15 saturation ALU

# CHECK-INST: kaddh a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x04]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 04 <unknown>
kaddh a0, a1, a2

# CHECK-INST: ksubh a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x06]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 06 <unknown>
ksubh a0, a1, a2

# CHECK-INST: khmbb a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x0c]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 0c <unknown>
khmbb a0, a1, a2

# CHECK-INST: khmbt a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x1c]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 1c <unknown>
khmbt a0, a1, a2

# CHECK-INST: khmtt a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x2c]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 2c <unknown>
khmtt a0, a1, a2

# CHECK-INST: ukaddh a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x14]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 14 <unknown>
ukaddh a0, a1, a2

# CHECK-INST: uksubh a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x16]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 16 <unknown>
uksubh a0, a1, a2

# Non-SIMD Q31 saturation ALU

# CHECK-INST: kaddw a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x00]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 00 <unknown>
kaddw a0, a1, a2

# CHECK-INST: ukaddw a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x10]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 10 <unknown>
ukaddw a0, a1, a2

# CHECK-INST: ksubw a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x02]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 02 <unknown>
ksubw a0, a1, a2

# CHECK-INST: uksubw a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x12]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 12 <unknown>
uksubw a0, a1, a2

# CHECK-INST: kdmbb a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x0a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 0a <unknown>
kdmbb a0, a1, a2

# CHECK-INST: kdmbt a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x1a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 1a <unknown>
kdmbt a0, a1, a2

# CHECK-INST: kdmtt a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x2a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 2a <unknown>
kdmtt a0, a1, a2

# CHECK-INST: kslraw a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x6e]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 6e <unknown>
kslraw a0, a1, a2

# CHECK-INST: kslraw.u a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x7e]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 7e <unknown>
kslraw.u a0, a1, a2

# CHECK-INST: ksllw a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x26]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 26 <unknown>
ksllw a0, a1, a2

# CHECK-INST: kslliw a0, a1, 31
# CHECK-ENCODING: [0x77,0x95,0xf5,0x37]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 f5 37 <unknown>
kslliw a0, a1, 31

# CHECK-INST: kdmabb a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0xd2]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 d2 <unknown>
kdmabb a0, a1, a2

# CHECK-INST: kdmabt a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0xe2]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 e2 <unknown>
kdmabt a0, a1, a2

# CHECK-INST: kdmatt a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0xf2]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 f2 <unknown>
kdmatt a0, a1, a2

# CHECK-INST: kabsw a0, a1
# CHECK-ENCODING: [0x77,0x85,0x45,0xad]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 45 ad <unknown>
kabsw a0, a1

# 32-bit Computation

# CHECK-INST: raddw a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x20]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 20 <unknown>
raddw a0, a1, a2

# CHECK-INST: uraddw a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x30]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 30 <unknown>
uraddw a0, a1, a2

# CHECK-INST: rsubw a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x22]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 22 <unknown>
rsubw a0, a1, a2

# CHECK-INST: ursubw a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x32]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 32 <unknown>
ursubw a0, a1, a2

# CHECK-INST: maxw a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0xf2]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 f2 <unknown>
maxw a0, a1, a2

# CHECK-INST: minw a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0xf0]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 f0 <unknown>
minw a0, a1, a2

# Overflow/Saturation status manipulation

# CHECK-INST: csrr a5, vxsat
# CHECK-ENCODING: [0xf3,0x27,0x90,0x00]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: f3 27 90 00 csrr a5, vxsat
rdov a5

# CHECK-INST: csrci vxsat, 1
# CHECK-ENCODING: [0x73,0xf0,0x90,0x00]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 73 f0 90 00 csrci vxsat, 1
clrov

# Miscellaneous

# CHECK-INST: ave a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0xe0]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 e0 <unknown>
ave a0, a1, a2

# CHECK-INST: sra.u a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0x24]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 24 <unknown>
sra.u a0, a1, a2

# CHECK-INST: srai.u a0, a1, 9
# CHECK-ENCODING: [0x77,0x95,0x95,0xd4]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 95 d4 <unknown>
srai.u a0, a1, 9

# CHECK-INST: bitrev a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0xe6]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 e6 <unknown>
bitrev a0, a1, a2

# CHECK-INST: bitrevi a0, a1, 7
# CHECK-ENCODING: [0x77,0x85,0x75,0xe8]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 75 e8 <unknown>
bitrevi a0, a1, 7

# CHECK-INST: bpick a0, a1, a2, a3
# CHECK-ENCODING: [0x77,0xb5,0xc5,0x68]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 b5 c5 68 <unknown>
bpick a0, a1, a2, a3

# CHECK-INST: insb a0, a1, 3
# CHECK-ENCODING: [0x77,0x85,0x35,0xac]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 35 ac <unknown>
insb a0, a1, 3

# CHECK-INST: maddr32 a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0xc4]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 c4 <unknown>
maddr32 a0, a1, a2

# CHECK-INST: msubr32 a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0xc6]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 c6 <unknown>
msubr32 a0, a1, a2
