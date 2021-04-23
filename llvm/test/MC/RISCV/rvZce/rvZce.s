# RUN: llvm-mc %s -triple=riscv64 -mattr=experimental-zce -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s

# RUN: llvm-mc %s -triple=riscv32 -mattr=experimental-zce -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: c.zext.b s0
# CHECK-ASM: encoding: [0x00,0x84]
c.zext.b s0