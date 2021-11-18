# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-cmul,+m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-cmul,+m < %s \
# RUN:     | llvm-objdump --mattr=+zce-cmul,+m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: c.mul s0, a2
# CHECK-ASM: encoding: [0x51,0x9c]
mul s0, s0, a2

# CHECK-ASM-AND-OBJ: mul s0, a1, a2
# CHECK-ASM: encoding: [0x33,0x84,0xc5,0x02]
mul s0, a1, a2

# CHECK-ASM-AND-OBJ: c.mul s0, a1
# CHECK-ASM: encoding: [0x4d,0x9c]
mul s0, a1, s0