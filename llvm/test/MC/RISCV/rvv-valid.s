# RUN: llvm-mc %s -triple=riscv32 -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s


# CHECK-ASM-AND-OBJ: vsetvl	a3, a3, a2
# CHECK-ASM: encoding: [0xd7,0xf6,0xc6,0x80]
vsetvl	a3, a3, a2

