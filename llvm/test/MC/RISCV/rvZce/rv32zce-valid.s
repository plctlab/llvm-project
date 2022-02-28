# RUN: llvm-mc %s -triple=riscv32 -mattr=+m,+experimental-zcmt,+zce-beqi,+zce-bnei,+zce-cdecbnez,+zce-decbnez,+zce-lsgp,+zce-muli \
# RUN:  -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+experimental-zcmt,+zce-beqi,+zce-bnei,+zce-cdecbnez,+zce-decbnez,+zce-lsgp,+zce-muli \
# RUN:  -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=+m,+experimental-zcmt,+zce-beqi,+zce-bnei,+zce-cdecbnez,+zce-decbnez,+zce-lsgp,+zce-muli \
# RUN:  -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-OBJ,CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: muli s0, s1, 2
# CHECK-ASM: encoding: [0x0b,0x94,0x24,0x00]
muli s0, s1, 2

# CHECK-OBJ: beqi s0, 20, 0x2c
# CHECK-ASM: encoding: [0x63,0x24,0x8a,0x02]
beqi s0, 20, 40

# CHECK-OBJ: bnei s0, 20, 0x30
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

# CHECK-OBJ: decbnez s0, 0, 0x18
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


