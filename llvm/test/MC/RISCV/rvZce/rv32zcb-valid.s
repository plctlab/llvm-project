# RUN: llvm-mc %s -triple=riscv32 -mattr=experimental-zcb -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=experimental-zcb -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zcb --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

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
