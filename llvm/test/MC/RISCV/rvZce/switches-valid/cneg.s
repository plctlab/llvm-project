# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-cneg -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-cneg -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce  --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: c.neg s0
# CHECK-ASM: encoding: [0x18,0x80]
c.neg s0

# CHECK-ASM-AND-OBJ: c.neg a4
# CHECK-ASM: encoding: [0x18,0x83]
neg x14,x14
