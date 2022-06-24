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

# SIMD 16-bit Add/Subtract

# CHECK-INST: add16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x40]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 40 <unknown>
add16 a0, a1, a2

# CHECK-INST: radd16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x00]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 00 <unknown>
radd16 a0, a1, a2

# CHECK-INST: uradd16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x20]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 20 <unknown>
uradd16 a0, a1, a2

# CHECK-INST: kadd16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x10]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 10 <unknown>
kadd16 a0, a1, a2

# CHECK-INST: ukadd16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x30]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 30 <unknown>
ukadd16 a0, a1, a2

# CHECK-INST: sub16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x42]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 42 <unknown>
sub16 a0, a1, a2

# CHECK-INST: rsub16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x02]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 02 <unknown>
rsub16 a0, a1, a2

# CHECK-INST: ursub16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x22]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 22 <unknown>
ursub16 a0, a1, a2

# CHECK-INST: ksub16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x12]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 12 <unknown>
ksub16 a0, a1, a2

# CHECK-INST: uksub16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x32]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 32 <unknown>
uksub16 a0, a1, a2

# CHECK-INST: cras16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x44]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 44 <unknown>
cras16 a0, a1, a2

# CHECK-INST: rcras16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x04]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 04 <unknown>
rcras16 a0, a1, a2

# CHECK-INST: urcras16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x24]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 24 <unknown>
urcras16 a0, a1, a2

# CHECK-INST: kcras16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x14]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 14 <unknown>
kcras16 a0, a1, a2

# CHECK-INST: ukcras16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x34]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 34 <unknown>
ukcras16 a0, a1, a2

# CHECK-INST: crsa16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x46]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 46 <unknown>
crsa16 a0, a1, a2

# CHECK-INST: rcrsa16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x06]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 06 <unknown>
rcrsa16 a0, a1, a2

# CHECK-INST: urcrsa16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x26]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 26 <unknown>
urcrsa16 a0, a1, a2

# CHECK-INST: kcrsa16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x16]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 16 <unknown>
kcrsa16 a0, a1, a2

# CHECK-INST: ukcrsa16 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x36]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 36 <unknown>
ukcrsa16 a0, a1, a2

# CHECK-INST: stas16 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xf4]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 f4 <unknown>
stas16 a0, a1, a2

# CHECK-INST: rstas16 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xb4]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 b4 <unknown>
rstas16 a0, a1, a2

# CHECK-INST: urstas16 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xd4]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 d4 <unknown>
urstas16 a0, a1, a2

# CHECK-INST: kstas16 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xc4]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 c4 <unknown>
kstas16 a0, a1, a2

# CHECK-INST: ukstas16 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xe4]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 e4 <unknown>
ukstas16 a0, a1, a2

# CHECK-INST: stsa16 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xf6]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 f6 <unknown>
stsa16 a0, a1, a2

# CHECK-INST: rstsa16 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xb6]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 b6 <unknown>
rstsa16 a0, a1, a2

# CHECK-INST: urstsa16 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xd6]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 d6 <unknown>
urstsa16 a0, a1, a2

# CHECK-INST: kstsa16 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xc6]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 c6 <unknown>
kstsa16 a0, a1, a2

# CHECK-INST: ukstsa16 a0, a1, a2
# CHECK-ENCODING: [0x77,0xa5,0xc5,0xe6]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 a5 c5 e6 <unknown>
ukstsa16 a0, a1, a2

# SIMD 8-bit Add/Subtract

# CHECK-INST: add8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x48]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 48 <unknown>
add8 a0, a1, a2

# CHECK-INST: radd8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x08]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 08 <unknown>
radd8 a0, a1, a2

# CHECK-INST: uradd8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x28]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 28 <unknown>
uradd8 a0, a1, a2

# CHECK-INST: kadd8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x18]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 18 <unknown>
kadd8 a0, a1, a2

# CHECK-INST: ukadd8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x38]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 38 <unknown>
ukadd8 a0, a1, a2

# CHECK-INST: sub8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x4a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 4a <unknown>
sub8 a0, a1, a2

# CHECK-INST: rsub8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x0a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 0a <unknown>
rsub8 a0, a1, a2

# CHECK-INST: ursub8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x2a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 2a <unknown>
ursub8 a0, a1, a2

# CHECK-INST: ksub8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x1a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 1a <unknown>
ksub8 a0, a1, a2

# CHECK-INST: uksub8 a0, a1, a2
# CHECK-ENCODING: [0x77,0x85,0xc5,0x3a]
# CHECK-ERROR: instruction requires the following: 'Zpn' (Normal 'P' Instructions)
# CHECK-UNKNOWN: 77 85 c5 3a <unknown>
uksub8 a0, a1, a2
