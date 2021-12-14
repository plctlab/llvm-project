# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-zext,+experimental-zbb -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-zext,+experimental-zbb < %s \
# RUN:     | llvm-objdump --mattr=+zce-zext,+experimental-zbb -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: zext.h s0, s1
# CHECK-ASM: encoding: [0x33,0xc4,0x04,0x08]
zext.h s0, s1

# CHECK-ASM-AND-OBJ: c.zext.h s0
# CHECK-ASM: encoding: [0x08,0x80]
zext.h s0, s0

# CHECK-ASM-AND-OBJ: andi s0, s1, 255
# CHECK-ASM: encoding: [0x13,0xf4,0xf4,0x0f]
andi s0, s1, 255

# CHECK-ASM-AND-OBJ: c.zext.b s0
# CHECK-ASM: encoding: [0x00,0x80]
andi s0, s0, 255
