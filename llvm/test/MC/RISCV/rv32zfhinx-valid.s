# RUN: llvm-mc %s -triple=riscv32 -mattr=+experimental-zfhinx -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc %s -triple=riscv64 -mattr=+experimental-zfhinx -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+experimental-zfhinx < %s \
# RUN:     | llvm-objdump --mattr=+experimental-zfhinx -M no-aliases -d -r - \
# RUN:     | FileCheck -check-prefixes=CHECK-OBJ,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=+experimental-zfhinx < %s \
# RUN:     | llvm-objdump --mattr=+experimental-zfhinx -M no-aliases -d -r - \
# RUN:     | FileCheck -check-prefixes=CHECK-OBJ,CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: lh s0, 12(a0)
# CHECK-ASM: encoding: [0x03,0x14,0xc5,0x00]
lh s0, 12(a0)
# CHECK-ASM-AND-OBJ: lh s1, 4(ra)
# CHECK-ASM: encoding: [0x83,0x94,0x40,0x00]
lh s1, +4(ra)
# CHECK-ASM-AND-OBJ: lh s2, -2048(a3)
# CHECK-ASM: encoding: [0x03,0x99,0x06,0x80]
lh s2, -2048(x13)
# CHECK-ASM-AND-OBJ: lh s3, -2048(s1)
# CHECK-ASM: encoding: [0x83,0x99,0x04,0x80]
lh s3, %lo(2048)(s1)
# CHECK-ASM-AND-OBJ: lh s4, 2047(s2)
# CHECK-ASM: encoding: [0x03,0x1a,0xf9,0x7f]
lh s4, 2047(s2)
# CHECK-ASM-AND-OBJ: lh s5, 0(s3)
# CHECK-ASM: encoding: [0x83,0x9a,0x09,0x00]
lh s5, 0(s3)

# CHECK-ASM-AND-OBJ: sh s6, 2047(s4)
# CHECK-ASM: encoding: [0xa3,0x1f,0x6a,0x7f]
sh s6, 2047(s4)
# CHECK-ASM-AND-OBJ: sh s7, -2048(s5)
# CHECK-ASM: encoding: [0x23,0x90,0x7a,0x81]
sh s7, -2048(s5)
# CHECK-ASM-AND-OBJ: sh s0, -2048(s6)
# CHECK-ASM: encoding: [0x23,0x10,0x8b,0x80]
sh x8, %lo(2048)(s6)
# CHECK-ASM-AND-OBJ: sh s1, 999(s7)
# CHECK-ASM: encoding: [0xa3,0x93,0x9b,0x3e]
sh x9, 999(s7)

# CHECK-ASM-AND-OBJ: fmadd.h a0, a1, a2, a3, dyn
# CHECK-ASM: encoding: [0x43,0xf5,0xc5,0x6c]
fmadd.h x10, x11, x12, x13, dyn
# CHECK-ASM-AND-OBJ: fmsub.h a4, a5, a6, a7, dyn
# CHECK-ASM: encoding: [0x47,0xf7,0x07,0x8d]
fmsub.h x14, x15, x16, x17, dyn
# CHECK-ASM-AND-OBJ: fnmsub.h s2, s3, s4, s5, dyn
# CHECK-ASM: encoding: [0x4b,0xf9,0x49,0xad]
fnmsub.h x18, x19, x20, x21, dyn
# CHECK-ASM-AND-OBJ: fnmadd.h s6, s7, s8, s9, dyn
# CHECK-ASM: encoding: [0x4f,0xfb,0x8b,0xcd]
fnmadd.h x22, x23, x24, x25, dyn

# CHECK-ASM-AND-OBJ: fadd.h s10, s11, t3, dyn
# CHECK-ASM: encoding: [0x53,0xfd,0xcd,0x05]
fadd.h x26, x27, x28, dyn
# CHECK-ASM-AND-OBJ: fsub.h t4, t5, t6, dyn
# CHECK-ASM: encoding: [0xd3,0x7e,0xff,0x0d]
fsub.h x29, x30, x31, dyn
# CHECK-ASM-AND-OBJ: fmul.h s0, s1, s2, dyn
# CHECK-ASM: encoding: [0x53,0xf4,0x24,0x15]
fmul.h s0, s1, s2, dyn
# CHECK-ASM-AND-OBJ: fdiv.h s3, s4, s5, dyn
# CHECK-ASM: encoding: [0xd3,0x79,0x5a,0x1d]
fdiv.h s3, s4, s5, dyn
# CHECK-ASM-AND-OBJ: fsqrt.h s6, s7, dyn
# CHECK-ASM: encoding: [0x53,0xfb,0x0b,0x5c]
fsqrt.h s6, s7, dyn
# CHECK-ASM-AND-OBJ: fsgnj.h s1, a0, a1
# CHECK-ASM: encoding: [0xd3,0x04,0xb5,0x24]
fsgnj.h x9, x10, x11
# CHECK-ASM-AND-OBJ: fsgnjn.h a1, a3, a4
# CHECK-ASM: encoding: [0xd3,0x95,0xe6,0x24]
fsgnjn.h x11, x13, x14
# CHECK-ASM-AND-OBJ: fsgnjx.h a4, a3, a2
# CHECK-ASM: encoding: [0x53,0xa7,0xc6,0x24]
fsgnjx.h x14, x13, x12
# CHECK-ASM-AND-OBJ: fmin.h a5, a6, a7
# CHECK-ASM: encoding: [0xd3,0x07,0x18,0x2d]
fmin.h x15, x16, x17
# CHECK-ASM-AND-OBJ: fmax.h s2, s3, s4
# CHECK-ASM: encoding: [0x53,0x99,0x49,0x2d]
fmax.h x18, x19, x20
# CHECK-ASM-AND-OBJ: fcvt.w.h a0, s5, dyn
# CHECK-ASM: encoding: [0x53,0xf5,0x0a,0xc4]
fcvt.w.h x10, x21, dyn
# CHECK-ASM-AND-OBJ: fcvt.wu.h a1, s6, dyn
# CHECK-ASM: encoding: [0xd3,0x75,0x1b,0xc4]
fcvt.wu.h x11, x22, dyn
# CHECK-ASM-AND-OBJ: feq.h a1, s8, s9
# CHECK-ASM: encoding: [0xd3,0x25,0x9c,0xa5]
feq.h x11, x24, x25
# CHECK-ASM-AND-OBJ: flt.h a2, s10, s11
# CHECK-ASM: encoding: [0x53,0x16,0xbd,0xa5]
flt.h x12, x26, x27
# CHECK-ASM-AND-OBJ: fle.h a3, t3, t4
# CHECK-ASM: encoding: [0xd3,0x06,0xde,0xa5]
fle.h x13, x28, x29
# CHECK-ASM-AND-OBJ: fclass.h a3, t5
# CHECK-ASM: encoding: [0xd3,0x16,0x0f,0xe4]
fclass.h x13, x30
# CHECK-ASM-AND-OBJ: fcvt.h.w t6, a4, dyn
# CHECK-ASM: encoding: [0xd3,0x7f,0x07,0xd4]
fcvt.h.w x31, x14, dyn
# CHECK-ASM-AND-OBJ: fcvt.h.wu s0, a5, dyn
# CHECK-ASM: encoding: [0x53,0xf4,0x17,0xd4]
fcvt.h.wu s0, x15, dyn

# Rounding modes

# CHECK-ASM-AND-OBJ: fmadd.h a0, a1, a2, a3, rne
# CHECK-ASM: encoding: [0x43,0x85,0xc5,0x6c]
fmadd.h x10, x11, x12, x13, rne
# CHECK-ASM-AND-OBJ: fmsub.h a4, a5, a6, a7, rtz
# CHECK-ASM: encoding: [0x47,0x97,0x07,0x8d]
fmsub.h x14, x15, x16, x17, rtz
# CHECK-ASM-AND-OBJ: fnmsub.h s2, s3, s4, s5, rdn
# CHECK-ASM: encoding: [0x4b,0xa9,0x49,0xad]
fnmsub.h x18, x19, x20, x21, rdn
# CHECK-ASM-AND-OBJ: fnmadd.h s6, s7, s8, s9, rup
# CHECK-ASM: encoding: [0x4f,0xbb,0x8b,0xcd]
fnmadd.h x22, x23, x24, x25, rup
# CHECK-ASM-AND-OBJ: fmadd.h a0, a1, a2, a3, rmm
# CHECK-ASM: encoding: [0x43,0xc5,0xc5,0x6c]
fmadd.h x10, x11, x12, x13, rmm
# CHECK-ASM-AND-OBJ: fmsub.h a4, a5, a6, a7
# CHECK-ASM: encoding: [0x47,0xf7,0x07,0x8d]
fmsub.h x14, x15, x16, x17, dyn

# CHECK-ASM-AND-OBJ: fadd.h s10, s11, t3, rne
# CHECK-ASM: encoding: [0x53,0x8d,0xcd,0x05]
fadd.h x26, x27, x28, rne
# CHECK-ASM-AND-OBJ: fsub.h t4, t5, t6, rtz
# CHECK-ASM: encoding: [0xd3,0x1e,0xff,0x0d]
fsub.h x29, x30, x31, rtz
# CHECK-ASM-AND-OBJ: fmul.h s0, s1, s2, rdn
# CHECK-ASM: encoding: [0x53,0xa4,0x24,0x15]
fmul.h s0, s1, s2, rdn
# CHECK-ASM-AND-OBJ: fdiv.h s3, s4, s5, rup
# CHECK-ASM: encoding: [0xd3,0x39,0x5a,0x1d]
fdiv.h s3, s4, s5, rup

# CHECK-ASM-AND-OBJ: fsqrt.h s6, s7, rmm
# CHECK-ASM: encoding: [0x53,0xcb,0x0b,0x5c]
fsqrt.h s6, s7, rmm
# CHECK-ASM-AND-OBJ: fcvt.w.h a0, s5, rup
# CHECK-ASM: encoding: [0x53,0xb5,0x0a,0xc4]
fcvt.w.h x10, x21, rup
# CHECK-ASM-AND-OBJ: fcvt.wu.h a1, s6, rdn
# CHECK-ASM: encoding: [0xd3,0x25,0x1b,0xc4]
fcvt.wu.h x11, x22, rdn
# CHECK-ASM-AND-OBJ: fcvt.h.w t6, a4, rtz
# CHECK-ASM: encoding: [0xd3,0x1f,0x07,0xd4]
fcvt.h.w x31, x14, rtz
# CHECK-ASM-AND-OBJ: fcvt.h.wu s0, a5, rne
# CHECK-ASM: encoding: [0x53,0x84,0x17,0xd4]
fcvt.h.wu s0, a5, rne
