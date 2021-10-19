# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-csbh -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-csbh -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce  --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: c.sb a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0xa7]
c.sb a5, 10(a4)

# CHECK-ASM-AND-OBJ: c.sh a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0xb7]
c.sh a5, 10(a4)