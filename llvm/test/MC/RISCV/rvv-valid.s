# RUN: llvm-mc %s -triple=riscv32 --mattr=+v -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s


# CHECK-ASM-AND-OBJ: vsetvl a3, a3, a2
# CHECK-ASM: encoding: [0xd7,0xf6,0xc6,0x80]
vsetvl a3, a3, a2

# CHECK-ASM-AND-OBJ: vsetvli a0, a1, 0
# CHECK-ASM: encoding: [0x57,0xf5,0x05,0x00]
vsetvli a0, a1, 0

# CHECK-ASM-AND-OBJ: vlw.v v0, 0(a1)
# CHECK-ASM: encoding: [0x07,0xe0,0x05,0x12]
vlw.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vsw.v v0, 0(a1)
# CHECK-ASM: encoding: [0x27,0xe0,0x05,0x02]
vsw.v v0, 0(a1)

# CHECK-ASM-AND-OBJ: vadd.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x02]
vadd.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vsub.vv v0, v1, v0
# CHECK-ASM: encoding: [0x57,0x00,0x10,0x0a]
vsub.vv v0, v1, v0

# CHECK-ASM-AND-OBJ: vadd.vi v0, v1, 0
# CHECK-ASM: encoding: [0x57,0x30,0x10,0x02]
vadd.vi v0, v1, 0
