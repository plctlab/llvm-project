# RUN: llvm-mc %s -triple=riscv32 -mattr=experimental-zce -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=experimental-zce -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-OBJ,CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: c.zext.b s0
# CHECK-ASM: encoding: [0x61,0x9c]
c.zext.b s0

# CHECK-ASM-AND-OBJ: c.sext.b s0
# CHECK-ASM: encoding: [0x65,0x9c]
c.sext.b s0

# CHECK-ASM-AND-OBJ: c.zext.h s0
# CHECK-ASM: encoding: [0x69,0x9c]
c.zext.h s0

# CHECK-ASM-AND-OBJ: c.sext.h s0
# CHECK-ASM: encoding: [0x6d,0x9c]
c.sext.h s0

# CHECK-ASM-AND-OBJ: c.not s0
# CHECK-ASM: encoding: [0x75,0x9c]
c.not s0

# CHECK-ASM-AND-OBJ: c.mul s0, s1
# CHECK-ASM: encoding: [0x45,0x9c]
c.mul s0, s1

# CHECK-ASM-AND-OBJ: muli s0, s1, 2
# CHECK-ASM: encoding: [0x0b,0x94,0x24,0x00]
muli s0, s1, 2

# CHECK-OBJ: beqi s0, 20, 0x38
# CHECK-ASM: encoding: [0x63,0x24,0x8a,0x02]
beqi s0, 20, 40

# CHECK-OBJ: bnei s0, 20, 0x3c
# CHECK-ASM: encoding: [0x63,0x34,0x8a,0x02]
bnei s0, 20, 40

# CHECK-ASM-AND-OBJ: tbljalm 6
# CHECK-ASM: encoding: [0x18,0x88]
tbljalm 6

# CHECK-ASM-AND-OBJ: tblj 40
# CHECK-ASM: encoding: [0xc0,0x88]
tblj 40

# CHECK-ASM-AND-OBJ: tbljal 190
# CHECK-ASM: encoding: [0xf8,0x8b]
tbljal 190

# CHECK-OBJ: c.decbnez s0, 0, 4
# CHECK-ASM: encoding: [0x22,0xa0]
c.decbnez s0, 1, -4

# CHECK-OBJ: decbnez s0, 0, 0x24
# CHECK-ASM: encoding: [0x07,0x34,0x40,0x80]
decbnez s0, 1, 4

# CHECK-ASM-AND-OBJ: lwgp s0, 32764(gp)
# CHECK-ASM: encoding: [0x07,0xb4,0xf7,0x1f]
lwgp s0, 32764(gp)

# CHECK-ASM: lwgp s0, %lo(foo)(gp)
# CHECK-ASM: encoding: [0x07,0bA0110100,A,0b000AAAAA]
# CHECK-ASM: fixup A - offset: 0, value: %lo(foo), kind: fixup_riscv_zce_lwgp
# CHECK-OBJ: lwgp s0, 0(gp)
# CHECK-OBJ: R_RISCV_GPREL_ZCE_LWGP foo
lwgp s0, %lo(foo)(gp)

# CHECK-ASM-AND-OBJ: swgp s0, 32764(gp)
# CHECK-ASM: encoding: [0xa7,0xbf,0x87,0x1e]
swgp s0, 32764(gp)

# CHECK-ASM: swgp s0, %lo(foo)(gp)
# CHECK-ASM: encoding: [0bA0100111,0x30'A',0x80'A',0b000AAAAA]
# CHECK-ASM: fixup A - offset: 0, value: %lo(foo), kind: fixup_riscv_zce_swgp
# CHECK-OBJ: swgp s0, 0(gp)
# CHECK-OBJ: R_RISCV_GPREL_ZCE_SWGP foo
swgp s0, %lo(foo)(gp)


