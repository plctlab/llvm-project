# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-clbhu -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-clbhu -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce  --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: c.lbu a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0x27]
c.lbu a5, 10(a4)

# CHECK-ASM-AND-OBJ: c.lhu a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0x37]
c.lhu a5, 10(a4)