# RUN: llvm-mc %s -triple=riscv64 -mattr=experimental-zcb -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=experimental-zcb -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zcb --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

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

# CHECK-ASM-AND-OBJ: c.zext.w s0
# CHECK-ASM: encoding: [0x71,0x9c]
c.zext.w s0

# CHECK-ASM-AND-OBJ: c.not s0
# CHECK-ASM: encoding: [0x75,0x9c]
c.not s0

# CHECK-ASM-AND-OBJ: c.mul s0, s1
# CHECK-ASM: encoding: [0x45,0x9c]
c.mul s0, s1

# CHECK-ASM-AND-OBJ: c.lbu a5, 2(a4)
# CHECK-ASM: encoding: [0x3c,0x83]
c.lbu a5, 2(a4)

# CHECK-ASM-AND-OBJ: c.lhu a5, 2(a4)
# CHECK-ASM: encoding: [0x3c,0x87]
c.lhu a5, 2(a4)

# CHECK-ASM-AND-OBJ: c.lh a5, 2(a4)
# CHECK-ASM: encoding: [0x7c,0x87]
c.lh a5, 2(a4)

# CHECK-ASM-AND-OBJ: c.sb a5, 2(a4)
# CHECK-ASM: encoding: [0x3c,0x8b]
c.sb a5, 2(a4)

# CHECK-ASM-AND-OBJ: c.sh a5, 2(a4)
# CHECK-ASM: encoding: [0x7c,0x8f]
c.sh a5, 2(a4)

# CHECK-ASM-AND-OBJ: c.lh a5, 2(a4)
# CHECK-ASM: encoding: [0x7c,0x87]
lh a5, 2(a4)

# CHECK-ASM-AND-OBJ: c.lbu a5, 2(a4)
# CHECK-ASM: encoding: [0x3c,0x83]
lbu a5, 2(a4)

# CHECK-ASM-AND-OBJ: c.lhu a5, 2(a4)
# CHECK-ASM: encoding: [0x3c,0x87]
lhu a5, 2(a4)

# CHECK-ASM-AND-OBJ: c.sb a5, 2(a4)
# CHECK-ASM: encoding: [0x3c,0x8b]
sb a5, 2(a4)

# CHECK-ASM-AND-OBJ: c.sh a5, 2(a4)
# CHECK-ASM: encoding: [0x7c,0x8f]
sh a5, 2(a4)

# CHECK-ASM-AND-OBJ: lh a5, 3(a4)
# CHECK-ASM: encoding: [0x83,0x17,0x37,0x00]
lh a5, 3(a4)

# CHECK-ASM-AND-OBJ: lbu a5, 4(a4)
# CHECK-ASM: encoding: [0x83,0x47,0x47,0x00]
lbu a5, 4(a4)

# CHECK-ASM-AND-OBJ: lhu a5, 3(a4)
# CHECK-ASM: encoding: [0x83,0x57,0x37,0x00]
lhu a5, 3(a4)

# CHECK-ASM-AND-OBJ: sb a5, 4(a4)
# CHECK-ASM: encoding: [0x23,0x02,0xf7,0x00]
sb a5, 4(a4)

# CHECK-ASM-AND-OBJ: sh a5, 3(a4)
# CHECK-ASM: encoding: [0xa3,0x11,0xf7,0x00]
sh a5, 3(a4)