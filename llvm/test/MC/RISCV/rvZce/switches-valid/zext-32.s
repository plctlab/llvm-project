# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-zext -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-zext -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce  --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: c.zext.b s0
# CHECK-ASM: encoding: [0x00,0x80]
c.zext.b s0

# CHECK-ASM-AND-OBJ: c.zext.h s0
# CHECK-ASM: encoding: [0x08,0x80]
c.zext.h s0