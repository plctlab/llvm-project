# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-clbh -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-clbh -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce  --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: c.lb a5, 10(a4)
# CHECK-ASM: encoding: [0x3e,0x27]
c.lb a5, 10(a4)

# CHECK-ASM-AND-OBJ: c.lh a5, 10(a4)
# CHECK-ASM: encoding: [0x3e,0x37]
c.lh a5, 10(a4)

# CHECK-ASM-AND-OBJ: c.lb a5, 10(a4)
# CHECK-ASM: encoding: [0x3e,0x27]
lb a5, 10(a4)

# CHECK-ASM-AND-OBJ: c.lh a5, 10(a4)
# CHECK-ASM: encoding: [0x3e,0x37]
lh a5, 10(a4)