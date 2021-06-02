# RUN: llvm-mc %s -triple=riscv32 -mattr=experimental-zce -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=experimental-zce -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-OBJ,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc %s -triple=riscv64 -mattr=experimental-zce -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=experimental-zce -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-OBJ,CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: c.zext.b s0
# CHECK-ASM: encoding: [0x00,0x84]
c.zext.b s0

# CHECK-ASM-AND-OBJ: c.sext.b s0
# CHECK-ASM: encoding: [0x04,0x84]
c.sext.b s0

# CHECK-ASM-AND-OBJ: c.zext.h s0
# CHECK-ASM: encoding: [0x08,0x84]
c.zext.h s0

# CHECK-ASM-AND-OBJ: c.sext.h s0
# CHECK-ASM: encoding: [0x0c,0x84]
c.sext.h s0

# CHECK-ASM-AND-OBJ: c.neg s0
# CHECK-ASM: encoding: [0x18,0x84]
c.neg s0

# CHECK-ASM-AND-OBJ: c.not s0
# CHECK-ASM: encoding: [0x1c,0x84]
c.not s0

# CHECK-ASM-AND-OBJ: c.mul s0, s1
# CHECK-ASM: encoding: [0x45,0x9c]
c.mul s0, s1

# CHECK-OBJ: beqi s0, 20, 0x36
# CHECK-ASM: encoding: [0x63,0x24,0x44,0x03]
beqi s0, 20, 40

# CHECK-OBJ: bnei s0, 20, 0x3a
# CHECK-ASM: encoding: [0x63,0x34,0x44,0x03]
bnei s0, 20, 40

# CHECK-ASM-AND-OBJ: muli s0, s1, 2
# CHECK-ASM: encoding: [0x0b,0x94,0x24,0x00]
muli s0, s1, 2

# CHECK-OBJ: c.decbnez s0, 0, 4
# CHECK-ASM: encoding: [0x22,0xa0]
c.decbnez s0, 1, -4

# CHECK-OBJ: decbnez s0, 0, 0x20
# CHECK-ASM: encoding: [0x07,0x34,0x40,0x80]
decbnez s0, 1, 4

# CHECK-ASM-AND-OBJ: tbljalm 6
# CHECK-ASM: encoding: [0x18,0x88]
tbljalm 6

# CHECK-ASM-AND-OBJ: tblj 40
# CHECK-ASM: encoding: [0xc0,0x88]
tblj 40

# CHECK-ASM-AND-OBJ: tbljal 190
# CHECK-ASM: encoding: [0xf8,0x8b]
tbljal 190

# CHECK-ASM-AND-OBJ: lwgp s0, 32764(gp)
# CHECK-ASM: encoding: [0x07,0xb4,0xf7,0x1f]
lwgp s0, 32764(gp)

# CHECK-ASM-AND-OBJ: swgp s0, 32764(gp)
# CHECK-ASM: encoding: [0xa7,0xbf,0x87,0x1e]
swgp s0, 32764(gp)

# CHECK-ASM-AND-OBJ: c.lbu a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0x27]
c.lbu a5, 10(a4)

# CHECK-ASM-AND-OBJ: c.lhu a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0x37]
c.lhu a5, 10(a4)

# CHECK-ASM-AND-OBJ: c.lb a5, 10(a4)
# CHECK-ASM: encoding: [0x3e,0x27]
c.lb a5, 10(a4)

# CHECK-ASM-AND-OBJ: c.lh a5, 10(a4)
# CHECK-ASM: encoding: [0x3e,0x37]
c.lh a5, 10(a4)

# CHECK-ASM-AND-OBJ: c.sb a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0xa7]
c.sb a5, 10(a4)

# CHECK-ASM-AND-OBJ: c.sh a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0xb7]
c.sh a5, 10(a4)

# comments
