# RUN: llvm-mc %s -triple=riscv32 -mattr=experimental-zce -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=experimental-zce -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-OBJ,CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: c.zext.b s0
# CHECK-ASM: encoding: [0x00,0x80]
c.zext.b s0

# CHECK-ASM-AND-OBJ: c.sext.b s0
# CHECK-ASM: encoding: [0x04,0x80]
c.sext.b s0

# CHECK-ASM-AND-OBJ: c.zext.h s0
# CHECK-ASM: encoding: [0x08,0x80]
c.zext.h s0

# CHECK-ASM-AND-OBJ: c.sext.h s0
# CHECK-ASM: encoding: [0x0c,0x80]
c.sext.h s0

# CHECK-ASM-AND-OBJ: c.neg s0
# CHECK-ASM: encoding: [0x18,0x80]
c.neg s0

# CHECK-ASM-AND-OBJ: c.not s0
# CHECK-ASM: encoding: [0x1c,0x80]
c.not s0

# CHECK-ASM-AND-OBJ: c.mul s0, s1
# CHECK-ASM: encoding: [0x45,0x9c]
c.mul s0, s1

# CHECK-ASM-AND-OBJ: c.mva01s07 s0, s1
# CHECK-ASM: encoding: [0x65,0x9c]
c.mva01s07 s0, s1

# CHECK-ASM-AND-OBJ: muli s0, s1, 2
# CHECK-ASM: encoding: [0x0b,0x94,0x24,0x00]
muli s0, s1, 2

# CHECK-OBJ: beqi s0, 20, 0x3c
# CHECK-ASM: encoding: [0x63,0x24,0x8a,0x02]
beqi s0, 20, 40

# CHECK-OBJ: bnei s0, 20, 0x40
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

# CHECK-ASM-AND-OBJ: push {ra, s0-s1}, {a0-a1}, -144
# CHECK-ASM: encoding: [0x2b,0x44,0x12,0x00]
push {ra, s0-s1}, {a0-a1}, -144

# CHECK-ASM-AND-OBJ: push {ra, s0-s1}, {a0-a1}, -128
# CHECK-ASM: encoding: [0xab,0x43,0x12,0x00]
push {ra, s0-s1}, {a0-a1}, -128

# CHECK-ASM-AND-OBJ: pop {ra, s0-s1}, {0}, 128
# CHECK-ASM: encoding: [0xab,0x53,0x12,0x00]
pop {ra, s0-s1}, {0}, 128

# CHECK-ASM: pop.e {ra, s0-s2}, {}, 16
# CHECK-OBJ: pop {ra, s0-s2}, {}, 16
# CHECK-ASM: encoding: [0x2b,0x50,0x0d,0x00]
pop.e {ra, s0-s2}, {}, 16

# CHECK-ASM-AND-OBJ: popret {ra, s0-s1}, {0}, 128
# CHECK-ASM: encoding: [0xab,0x63,0x12,0x00]
popret {ra, s0-s1}, {0}, 128

# CHECK-ASM: popret.e {ra, s0-s2}, {}, 16
# CHECK-OBJ: popret {ra, s0-s2}, {}, 16
# CHECK-ASM: encoding: [0x2b,0x60,0x0d,0x00]
popret.e {ra, s0-s2}, {}, 16

# CHECK-ASM: push.e {ra, s0-s2}, {a0-a2}, -16
# CHECK-OBJ: push {ra, s0-s2}, {a0-a2}, -16
# CHECK-ASM: encoding: [0x2b,0x40,0x1d,0x00]
push.e {ra, s0-s2}, {a0-a2}, -16

# CHECK-ASM: push.e {ra, s0-s4}, {a0-a3}, -528
# CHECK-OBJ: push {ra, s0-s4}, {a0-a3}, -528
# CHECK-ASM: encoding: [0xab,0x4f,0x1f,0x00]
push.e {ra, s0-s4}, {a0-a3}, -528

# CHECK-OBJ: c.decbnez s0, 0, 4
# CHECK-ASM: encoding: [0x22,0xa0]
c.decbnez s0, 1, -4

# CHECK-OBJ: decbnez s0, 0, 0x48
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

# CHECK-ASM-AND-OBJ: c.popret   {ra}, {}, 16
# CHECK-ASM: encoding: [0x00,0x8c]
c.popret {ra}, {}, 16

# CHECK-ASM-AND-OBJ: c.popret   {ra}, {0}, 32
# CHECK-ASM: encoding: [0xa0,0x8c]
c.popret {ra}, {0}, 32

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0}, {0}, 64
# CHECK-ASM: encoding: [0xa4,0x8d]
c.popret {ra, s0}, {0}, 64

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s1}, {0}, 96
# CHECK-ASM: encoding: [0xa8,0x8e]
c.popret {ra,s0-s1}, {0}, 96

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s2}, {0}, 32
# CHECK-ASM: encoding: [0xac,0x8c]
c.popret {ra, s0-s2}, {0}, 32

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s3}, {0}, 112
# CHECK-ASM: encoding: [0xb0,0x8e]
c.popret {ra, s0-s3}, {0}, 112

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s5}, {0}, 112
# CHECK-ASM: encoding: [0xb4,0x8e]
c.popret {ra, s0-s5}, {0}, 112

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s7}, {0}, 128
# CHECK-ASM: encoding: [0xb8,0x8e]
c.popret {ra, s0-s7}, {0}, 128

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s11}, {0}, 144
# CHECK-ASM: encoding: [0xbc,0x8e]
c.popret {ra, s0-s11}, {0}, 144

# CHECK-ASM-AND-OBJ: c.pop  {ra}, {}, 16
# CHECK-ASM: encoding: [0x00,0x8f]
c.pop {ra}, {}, 16

# CHECK-ASM-AND-OBJ: c.pop  {ra}, {}, 32
# CHECK-ASM: encoding: [0x80,0x8f]
c.pop {ra}, {}, 32

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0}, {}, 16
# CHECK-ASM: encoding: [0x04,0x8f]
c.pop {ra, s0}, {}, 16

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0-s1}, {}, 32
# CHECK-ASM: encoding: [0x88,0x8f]
c.pop {ra, s0-s1}, {}, 32

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0-s2}, {}, 32
# CHECK-ASM: encoding: [0x8c,0x8f]
c.pop {ra, s0-s2}, {}, 32

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0-s5}, {}, 32
# CHECK-ASM: encoding: [0x14,0x8f]
c.pop {ra, s0-s5}, {}, 32

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0-s7}, {}, 48
# CHECK-ASM: encoding: [0x18,0x8f]
c.pop {ra, s0-s7}, {}, 48

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0-s11}, {}, 64
# CHECK-ASM: encoding: [0x1c,0x8f]
c.pop {ra, s0-s11}, {}, 64

# CHECK-ASM-AND-OBJ: c.push {ra}, {}, -16
# CHECK-ASM: encoding: [0x40,0x8c]
c.push {ra}, {}, -16

# CHECK-ASM-AND-OBJ: c.push {ra, s0}, {a0}, -32
# CHECK-ASM: encoding: [0xc4,0x8c]
c.push {ra, s0}, {a0}, -32

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s1}, {a0-a1}, -96
# CHECK-ASM: encoding: [0xc8,0x8e]
c.push {ra, s0-s1}, {a0-a1}, -96

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s3}, {a0-a3}, -112
# CHECK-ASM: encoding: [0xd0,0x8e]
c.push {ra, s0-s3}, {a0-a3}, -112

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s7}, {a0-a3}, -80
# CHECK-ASM: encoding: [0x58,0x8d]
c.push {ra, s0-s7}, {a0-a3}, -80

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s7}, {a0-a3}, -128
# CHECK-ASM: encoding: [0xd8,0x8e]
c.push {ra, s0-s7}, {a0-a3}, -128

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s11}, {a0-a3}, -112
# CHECK-ASM: encoding: [0xdc,0x8d]
c.push {ra, s0-s11}, {a0-a3}, -112

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s11}, {a0-a3}, -144
# CHECK-ASM: encoding: [0xdc,0x8e]
c.push {ra, s0-s11}, {a0-a3}, -144

# CHECK-ASM-AND-OBJ: c.pop {ra}, {}, 32
# CHECK-ASM: encoding: [0x80,0x8f]
c.pop.e {ra}, {}, 32

# CHECK-ASM-AND-OBJ: c.pop.e {ra, s0-s2}, {}, 32
# CHECK-ASM: encoding: [0xa0,0x8f]
c.pop.e {ra, s0-s2}, {}, 32

# CHECK-ASM-AND-OBJ: c.pop.e {ra, s0-s3}, {}, 48
# CHECK-ASM: encoding: [0xa4,0x8f]
c.pop.e {ra, s0-s3}, {}, 48

# CHECK-ASM-AND-OBJ: c.popret {ra}, {}, 16
# CHECK-ASM: encoding: [0x00,0x8c]
c.popret.e {ra}, {}, 16

# CHECK-ASM-AND-OBJ: c.popret.e {ra, s0-s2}, {}, 16
# CHECK-ASM: encoding: [0x60,0x8c]
c.popret.e {ra, s0-s2}, {}, 16

# CHECK-ASM-AND-OBJ: c.popret.e {ra, s0-s2}, {}, 96
# CHECK-ASM: encoding: [0xe0,0x8e]
c.popret.e {ra, s0-s2}, {}, 96

# CHECK-ASM-AND-OBJ: c.popret.e {ra, s0-s3}, {}, 32
# CHECK-ASM: encoding: [0x64,0x8c]
c.popret.e {ra, s0-s3}, {}, 32

# CHECK-ASM-AND-OBJ: c.popret.e {ra, s0-s3}, {0}, 96
# CHECK-ASM: encoding: [0x74,0x8e]
c.popret.e {ra, s0-s3}, {0}, 96

# CHECK-ASM-AND-OBJ: c.popret.e {ra, s0-s4}, {}, 112
# CHECK-ASM: encoding: [0xe8,0x8e]
c.popret.e {ra, s0-s4}, {}, 112

# CHECK-ASM-AND-OBJ: c.push {ra}, {}, -16
# CHECK-ASM: encoding: [0x40,0x8c]
c.push.e {ra}, {}, -16

# CHECK-ASM-AND-OBJ: c.push.e {ra, s0-s2}, {a0-a2}, -16
# CHECK-ASM: encoding: [0x40,0x8f]
c.push.e {ra, s0-s2}, {a0-a2}, -16

# CHECK-ASM-AND-OBJ: c.push.e {ra, s0-s2}, {a0-a2}, -96
# CHECK-ASM: encoding: [0xe0,0x8f]
c.push.e {ra, s0-s2}, {a0-a2}, -96

# CHECK-ASM-AND-OBJ: c.push.e {ra, s0-s3}, {a0-a3}, -32
# CHECK-ASM: encoding: [0x44,0x8f]
c.push.e {ra, s0-s3}, {a0-a3}, -32

# CHECK-ASM-AND-OBJ: c.push.e {ra, s0-s4}, {a0-a3}, -112
# CHECK-ASM: encoding: [0xe8,0x8f]
c.push.e {ra, s0-s4}, {a0-a3}, -112

# CHECK-ASM-AND-OBJ: push {ra, s0-s1}, {}, -112
# CHECK-ASM: encoding: [0x2b,0x43,0x02,0x00]
push {ra, s0-s1}, {}, -112

# CHECK-ASM: push.e {ra, s0-s2}, {}, -16
# CHECK-OBJ: push {ra, s0-s2}, {}, -16
# CHECK-ASM: encoding: [0x2b,0x40,0x0d,0x00]
push.e {ra, s0-s2}, {}, -16

