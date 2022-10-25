# With P extension:
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
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-zpn %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zpn %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-p - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zpn %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# RV64P only

# SIMD 32-bit Add/Subtract

# CHECK-INST: add32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x40]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 40 <unknown>
add32 a0, a1, a2

# CHECK-INST: radd32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x00]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 00 <unknown>
radd32 a0, a1, a2

# CHECK-INST: uradd32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x20]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 20 <unknown>
uradd32 a0, a1, a2

# CHECK-INST: add32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x10]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 10 <unknown>
kadd32 a0, a1, a2

# CHECK-INST: add32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x30]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 30 <unknown>
ukadd32 a0, a1, a2

# CHECK-INST: sub32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x42]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 42 <unknown>
sub32 a0, a1, a2

# CHECK-INST: rsub32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x02]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 02 <unknown>
rsub32 a0, a1, a2

# CHECK-INST: ursub32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x22]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 22 <unknown>
ursub32 a0, a1, a2

# CHECK-INST: sub32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x12]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 12 <unknown>
ksub32 a0, a1, a2

# CHECK-INST: sub32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x32]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 32 <unknown>
uksub32 a0, a1, a2

# CHECK-INST: cras32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x44]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 44 <unknown>
cras32 a0, a1, a2

# CHECK-INST: rcras32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x04]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 04 <unknown>
rcras32 a0, a1, a2

# CHECK-INST: urcras32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x24]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 24 <unknown>
urcras32 a0, a1, a2

# CHECK-INST: kcras32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x14]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 14 <unknown>
kcras32 a0, a1, a2

# CHECK-INST: ukcras32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x34]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 34 <unknown>
ukcras32 a0, a1, a2

# CHECK-INST: crsa32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x46]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 46 <unknown>
crsa32 a0, a1, a2

# CHECK-INST: rcrsa32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x06]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 06 <unknown>
rcrsa32 a0, a1, a2

urcrsa32 a0, a1, a2
# CHECK-INST: urcrsa32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x26]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 26 <unknown>

# CHECK-INST: kcrsa32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x16]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 16 <unknown>
kcrsa32 a0, a1, a2

# CHECK-INST: ukcrsa32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x36]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 36 <unknown>
ukcrsa32 a0, a1, a2

# CHECK-INST: stas32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xf0]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 f0 <unknown>
stas32 a0, a1, a2

# CHECK-INST: rstas32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xb0]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 b0 <unknown>
rstas32 a0, a1, a2

# CHECK-INST: urstas32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xd0]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 d0 <unknown>
urstas32 a0, a1, a2

# CHECK-INST: kstas32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xc0]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 c0 <unknown>
kstas32 a0, a1, a2

# CHECK-INST: ukstas32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xe0]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 e0 <unknown>
ukstas32 a0, a1, a2

# CHECK-INST: stsa32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xf2]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 f2 <unknown>
stsa32 a0, a1, a2

# CHECK-INST: rstsa32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xb2]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 b2 <unknown>
rstsa32 a0, a1, a2

# CHECK-INST: urstsa32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xd2]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 d2 <unknown>
urstsa32 a0, a1, a2

# CHECK-INST: kstsa32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xc2]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 c2 <unknown>
kstsa32 a0, a1, a2

# CHECK-INST: ukstsa32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xe2]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 e2 <unknown>
ukstsa32 a0, a1, a2

# SIMD 32-bit Shift

# CHECK-INST: sra32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x50]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 50 <unknown>
sra32 a0, a1, a2

# CHECK-INST: srai32 a0, a1, 19
# CHECK-ENCODING: [0x77,0xa5,0x35,0x71]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 35 71 <unknown>
srai32 a0, a1, 19

# CHECK-INST: sra32.u a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x60]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 60 <unknown>
sra32.u a0, a1, a2

# CHECK-INST: srai32.u a0, a1, 16
# CHECK-ENCODING: [0x77,0xa5,0x05,0x81]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 05 81 <unknown>
srai32.u a0, a1, 16

# CHECK-INST: srl32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x52]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 52 <unknown>
srl32 a0, a1, a2

# CHECK-INST: srli32 a0, a1, 9
# CHECK-ENCODING: [0x77,0xa5,0x95,0x72]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 95 72 <unknown>
srli32 a0, a1, 9

# CHECK-INST: srl32.u a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x62]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 62 <unknown>
srl32.u a0, a1, a2

# CHECK-INST: srli32.u a0, a1, 15
# CHECK-ENCODING: [0x77,0xa5,0xf5,0x82]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 f5 82 <unknown>
srli32.u a0, a1, 15

# CHECK-INST: sll32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x54]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 54 <unknown>
sll32 a0, a1, a2

# CHECK-INST: slli32 a0, a1, 23
# CHECK-ENCODING: [0x77,0xa5,0x75,0x75]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 75 75 <unknown>
slli32 a0, a1, 23

# CHECK-INST: ksll32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x64]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 64 <unknown>
ksll32 a0, a1, a2

# CHECK-INST: kslli32 a0, a1, 29
# CHECK-ENCODING: [0x77,0xa5,0xd5,0x85]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 d5 85 <unknown>
kslli32 a0, a1, 29

# CHECK-INST: kslra32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x56]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 56 <unknown>
kslra32 a0, a1, a2

# CHECK-INST: kslra32.u a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x66]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 66 <unknown>
kslra32.u a0, a1, a2

# SIMD 32-bit Miscellaneous

# CHECK-INST: smin32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x90]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 90 <unknown>
smin32 a0, a1, a2

# CHECK-INST: umin32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xa0]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 a0 <unknown>
umin32 a0, a1, a2

# CHECK-INST: smax32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x92]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 92 <unknown>
smax32 a0, a1, a2

# CHECK-INST: umax32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xa2]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 a2 <unknown>
umax32 a0, a1, a2

# CHECK-INST: kabs32 a0, a1
# CHECK-ENCODING: [0x77,0x85,0x25,0xad]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 25 ad <unknown>
kabs32 a0, a1

# SIMD Q15 saturating Multiply

# CHECK-INST: khmbb16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0xdc]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 dc <unknown>
khmbb16 a0, a1, a2

# CHECK-INST: khmbt16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0xec]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 ec <unknown>
khmbt16 a0, a1, a2

# CHECK-INST: khmtt16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0xfc]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 fc <unknown>
khmtt16 a0, a1, a2

# CHECK-INST: kdmbb16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0xda]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 da <unknown>
kdmbb16 a0, a1, a2

# CHECK-INST: kdmbt16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0xea]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 ea <unknown>
kdmbt16 a0, a1, a2

# CHECK-INST: kdmtt16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0xfa]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 fa <unknown>
kdmtt16 a0, a1, a2

# CHECK-INST: kdmabb16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0xd8]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 d8 <unknown>
kdmabb16 a0, a1, a2

# CHECK-INST: kdmabt16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0xe8]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 e8 <unknown>
kdmabt16 a0, a1, a2

# CHECK-INST: kdmatt16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x95,0xc5,0xf8]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 c5 f8 <unknown>
kdmatt16 a0, a1, a2

# 32-bit Multiply

# CHECK-INST: smbt32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x18]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 18 <unknown>
smbt32 a0, a1, a2

# CHECK-INST: smtt32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x28]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 28 <unknown>
smtt32 a0, a1, a2

# 32-bit Multiply & Add

# CHECK-INST: kmabb32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x5a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 5a <unknown>
kmabb32 a0, a1, a2

# CHECK-INST: kmabt32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x6a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 6a <unknown>
kmabt32 a0, a1, a2

# CHECK-INST: kmatt32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x7a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 7a <unknown>
kmatt32 a0, a1, a2

# CHECK-INST: kmda32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x38]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 38 <unknown>
kmda32 a0, a1, a2

# CHECK-INST: kmxda32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x3a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 3a <unknown>
kmxda32 a0, a1, a2

# CHECK-INST: kmaxda32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x4a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 4a <unknown>
kmaxda32 a0, a1, a2

# CHECK-INST: kmads32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x5c]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 5c <unknown>
kmads32 a0, a1, a2

# CHECK-INST: kmadrs32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x6c]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 6c <unknown>
kmadrs32 a0, a1, a2

# CHECK-INST: kmaxds32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x7c]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 7c <unknown>
kmaxds32 a0, a1, a2

# CHECK-INST: kmsda32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x4c]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 4c <unknown>
kmsda32 a0, a1, a2

# CHECK-INST: kmsxda32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x4e]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 4e <unknown>
kmsxda32 a0, a1, a2

# CHECK-INST: smds32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x58]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 58 <unknown>
smds32 a0, a1, a2

# CHECK-INST: smdrs32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x68]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 68 <unknown>
smdrs32 a0, a1, a2

# CHECK-INST: smxds32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x78]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 78 <unknown>
smxds32 a0, a1, a2

# Non-SIMD 32-bit Shift

# CHECK-INST: sraiw.u a0, a1, 17
# CHECK-ENCODING: [0x77,0x95,0x15,0x35]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 95 15 35 <unknown>
sraiw.u a0, a1, 17

# 32-bit Packing

# CHECK-INST: pkbb32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x0e]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 0e <unknown>
pkbb32 a0, a1, a2

# CHECK-INST: pkbt32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x1e]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 1e <unknown>
pkbt32 a0, a1, a2

# CHECK-INST: pktb32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x3e]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 3e <unknown>
pktb32 a0, a1, a2

# CHECK-INST: pktt32 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0x2e]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 2e <unknown>
pktt32 a0, a1, a2
