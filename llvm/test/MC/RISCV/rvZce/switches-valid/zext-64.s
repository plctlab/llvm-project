# RUN: llvm-mc %s -triple=riscv64 -mattr=+zce-zext,+experimental-zbb,+experimental-zba -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=+zce-zext,+experimental-zbb,+experimental-zba < %s \
# RUN:     | llvm-objdump --mattr=+zce-zext,+experimental-zbb,+experimental-zba -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: zext.h s0, s1
# CHECK-ASM: encoding: [0x3b,0xc4,0x04,0x08]
zext.h s0, s1

# CHECK-ASM-AND-OBJ: c.zext.h s0
# CHECK-ASM: encoding: [0x69,0x9c]
zext.h s0, s0

# CHECK-ASM-AND-OBJ: andi s0, s1, 255
# CHECK-ASM: encoding: [0x13,0xf4,0xf4,0x0f]
andi s0, s1, 255

# CHECK-ASM-AND-OBJ: c.zext.b s0
# CHECK-ASM: encoding: [0x61,0x9c]
andi s0, s0, 255

# CHECK-ASM-AND-OBJ: add.uw s0, s1, zero
# CHECK-ASM: encoding: [0x3b,0x84,0x04,0x08]
zext.w s0, s1

# CHECK-ASM-AND-OBJ: c.zext.w s0
# CHECK-ASM: encoding: [0x71,0x9c]
zext.w s0, s0

# CHECK-ASM-AND-OBJ: c.zext.w s0
# CHECK-ASM: encoding: [0x71,0x9c]
add.uw s0, s0, zero