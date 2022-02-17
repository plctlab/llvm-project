# RUN: llvm-mc %s -triple=riscv64 -mattr=experimental-zce -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=experimental-zce < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefix=CHECK-ASM-AND-OBJ %s
# RUN: not llvm-mc -triple=riscv64 \
# RUN:     -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck --check-prefix=CHECK-NO-EXT %s
# RUN: not llvm-mc -triple=riscv32 -mattr=experimental-zce \
# RUN:     -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck --check-prefix=CHECK-NO-RV64 %s
# RUN: not llvm-mc -triple=riscv32 \
# RUN:     -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck --check-prefix=CHECK-NO-RV64-AND-EXT %s

# CHECK-ASM-AND-OBJ: c.zext.b s0
# CHECK-ASM: encoding: [0x61,0x9c]
# CHECK-NO-EXT: error: instruction requires the following: 'Zext' from 'Zcee' (high performance cores v0.50)
c.zext.b s0

# CHECK-ASM-AND-OBJ: c.sext.b s0
# CHECK-ASM: encoding: [0x65,0x9c]
# CHECK-NO-EXT: error: instruction requires the following: 'Sext' from 'Zcee' (high performance cores v0.50)
c.sext.b s0

# CHECK-ASM-AND-OBJ: c.zext.h s0
# CHECK-ASM: encoding: [0x69,0x9c]
# CHECK-NO-EXT: error: instruction requires the following: 'Zext' from 'Zcee' (high performance cores v0.50)
c.zext.h s0

# CHECK-ASM-AND-OBJ: c.sext.h s0
# CHECK-ASM: encoding: [0x6d,0x9c]
# CHECK-NO-EXT: error: instruction requires the following: 'Sext' from 'Zcee' (high performance cores v0.50)
c.sext.h s0

# CHECK-ASM-AND-OBJ: c.zext.w s0
# CHECK-ASM: encoding: [0x71,0x9c]
# CHECK-NO-EXT: error: instruction requires the following: 'Zext' from 'Zcee' (high performance cores v0.50)
# CHECK-NO-RV64: error: instruction requires the following: RV64I Base Instruction Set
# CHECK-NO-RV64-AND-EXT: error: instruction requires the following: 'Zext' from 'Zcee' (high performance cores v0.50), RV64I Base Instruction Set
c.zext.w s0

# CHECK-ASM-AND-OBJ: c.not s0
# CHECK-ASM: encoding: [0x75,0x9c]
# CHECK-NO-EXT: error: instruction requires the following: 'CNot' from 'Zcea' (all existing standard extensions for small embedded cores v0.50)
c.not s0

# CHECK-ASM-AND-OBJ: c.mul s0, s1
# CHECK-ASM: encoding: [0x45,0x9c]
c.mul s0, s1

# CHECK-ASM-AND-OBJ: lwgp s0, 32764(gp)
# CHECK-ASM: encoding: [0x07,0xb4,0xf7,0x1f]
lwgp s0, 32764(gp)

# CHECK-ASM: lwgp s0, %lo(foo)(gp)
# CHECK-ASM: encoding: [0x07,0bA0110100,A,0b000AAAAA]
# CHECK-ASM-FIXUP:  fixup A - offset: 0, value: %lo(foo), kind: fixup_riscv_zce_lwgp
# CHECK-OBJ: lwgp s0, 0(gp)
# CHECK-OBJ: R_RISCV_GPREL_ZCE_LWGP foo
lwgp s0, %lo(foo)(gp)

# CHECK-ASM-AND-OBJ: swgp s0, 32764(gp)
# CHECK-ASM: encoding: [0xa7,0xbf,0x87,0x1e]
swgp s0, 32764(gp)

# CHECK-ASM: swgp s0, %lo(foo)(gp)
# CHECK-ASM: encoding: [0bA0100111,0x30'A',0x80'A',0b000AAAAA]
# CHECK-ASM-FIXUP:  fixup A - offset: 0, value: %lo(foo), kind: fixup_riscv_zce_swgp
# CHECK-OBJ: swgp s0, 0(gp)
# CHECK-OBJ: R_RISCV_GPREL_ZCE_SWGP foo
swgp s0, %lo(foo)(gp)

# CHECK-ASM-AND-OBJ: ldgp s0, 65528(gp)
# CHECK-ASM: encoding: [0x07,0xb4,0xbf,0x5f]
# CHECK-NO-EXT: error: instruction requires the following: 'Lsgp' from 'Zceb' (all existing standard extensions for small embedded cores v0.50)
# CHECK-NO-RV64: error: instruction requires the following: RV64I Base Instruction Set
# CHECK-NO-RV64-AND-EXT: error: instruction requires the following: 'Lsgp' from 'Zceb' (all existing standard extensions for small embedded cores v0.50), RV64I Base Instruction Set
ldgp s0, 65528(gp)

# CHECK-ASM: ldgp s0, %lo(foo)(gp)
# CHECK-ASM: encoding: [0x07,0bA0110100,A,0b010AAAAA]
# CHECK-ASM-FIXUP:  fixup A - offset: 0, value: %lo(foo), kind: fixup_riscv_zce_ldgp
# CHECK-OBJ: ldgp s0, 0(gp)
# CHECK-OBJ: R_RISCV_GPREL_ZCE_LDGP foo
# CHECK-NO-EXT: error: instruction requires the following: 'Lsgp' from 'Zceb' (all existing standard extensions for small embedded cores v0.50)
# CHECK-NO-RV64: error: instruction requires the following: RV64I Base Instruction Set
# CHECK-NO-RV64-AND-EXT: error: instruction requires the following: 'Lsgp' from 'Zceb' (all existing standard extensions for small embedded cores v0.50), RV64I Base Instruction Set
ldgp s0, %lo(foo)(gp)

# CHECK-ASM-AND-OBJ: sdgp s0, 65528(gp)
# CHECK-ASM: encoding: [0xa7,0xbd,0x8f,0x5e]
# CHECK-NO-EXT: error: instruction requires the following: 'Lsgp' from 'Zceb' (all existing standard extensions for small embedded cores v0.50)
# CHECK-NO-RV64: error: instruction requires the following: RV64I Base Instruction Set
# CHECK-NO-RV64-AND-EXT: error: instruction requires the following: 'Lsgp' from 'Zceb' (all existing standard extensions for small embedded cores v0.50), RV64I Base Instruction Set
sdgp s0, 65528(gp)

# CHECK-ASM: sdgp s0, %lo(foo)(gp)
# CHECK-ASM: encoding: [0bA0100111,0x30'A',0x80'A',0b010AAAAA]
# CHECK-ASM-FIXUP:  fixup A - offset: 0, value: %lo(foo), kind: fixup_riscv_zce_sdgp
# CHECK-OBJ: sdgp s0, 0(gp)
# CHECK-OBJ: R_RISCV_GPREL_ZCE_SDGP foo
# CHECK-NO-EXT: error: instruction requires the following: 'Lsgp' from 'Zceb' (all existing standard extensions for small embedded cores v0.50)
# CHECK-NO-RV64: error: instruction requires the following: RV64I Base Instruction Set
# CHECK-NO-RV64-AND-EXT: error: instruction requires the following: 'Lsgp' from 'Zceb' (all existing standard extensions for small embedded cores v0.50), RV64I Base Instruction Set
sdgp s0, %lo(foo)(gp)

# CHECK-ASM-AND-OBJ: push {ra, s0-s1}, {a0-a1}, -128
# CHECK-ASM: encoding: [0x2b,0x43,0x12,0x00]
push {ra, s0-s1}, {a0-a1}, -128

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
# CHECK-ASM: encoding: [0x28,0x8e]
c.popret {ra,s0-s1}, {0}, 96

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s2}, {0}, 32
# CHECK-ASM: encoding: [0x2c,0x8c]
c.popret {ra, s0-s2}, {0}, 32

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s3}, {0}, 112
# CHECK-ASM: encoding: [0x30,0x8e]
c.popret {ra, s0-s3}, {0}, 112

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s5}, {0}, 112
# CHECK-ASM: encoding: [0xb4,0x8d]
c.popret {ra, s0-s5}, {0}, 112

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s7}, {0}, 128
# CHECK-ASM: encoding: [0xb8,0x8d]
c.popret {ra, s0-s7}, {0}, 128

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s11}, {0}, 144
# CHECK-ASM: encoding: [0x3c,0x8d]
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
# CHECK-ASM: encoding: [0x08,0x8f]
c.pop {ra, s0-s1}, {}, 32

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0-s2}, {}, 32
# CHECK-ASM: encoding: [0x0c,0x8f]
c.pop {ra, s0-s2}, {}, 32

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0-s5}, {}, 64
# CHECK-ASM: encoding: [0x14,0x8f]
c.pop {ra, s0-s5}, {}, 64

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0-s7}, {}, 80
# CHECK-ASM: encoding: [0x18,0x8f]
c.pop {ra, s0-s7}, {}, 80

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0-s11}, {}, 112
# CHECK-ASM: encoding: [0x1c,0x8f]
c.pop {ra, s0-s11}, {}, 112

# CHECK-ASM-AND-OBJ: c.push {ra}, {}, -16
# CHECK-ASM: encoding: [0x40,0x8c]
c.push {ra}, {}, -16

# CHECK-ASM-AND-OBJ: c.push {ra, s0}, {a0}, -32
# CHECK-ASM: encoding: [0xc4,0x8c]
c.push {ra, s0}, {a0}, -32

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s1}, {a0-a1}, -96
# CHECK-ASM: encoding: [0x48,0x8e]
c.push {ra, s0-s1}, {a0-a1}, -96

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s3}, {a0-a3}, -112
# CHECK-ASM: encoding: [0x50,0x8e]
c.push {ra, s0-s3}, {a0-a3}, -112

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s7}, {a0-a3}, -80
# CHECK-ASM: encoding: [0x58,0x8c]
c.push {ra, s0-s7}, {a0-a3}, -80

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s7}, {a0-a3}, -128
# CHECK-ASM: encoding: [0xd8,0x8d]
c.push {ra, s0-s7}, {a0-a3}, -128

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s11}, {a0-a3}, -112
# CHECK-ASM: encoding: [0x5c,0x8c]
c.push {ra, s0-s11}, {a0-a3}, -112

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s11}, {a0-a3}, -144
# CHECK-ASM: encoding: [0x5c,0x8d]
c.push {ra, s0-s11}, {a0-a3}, -144
