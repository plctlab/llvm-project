# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-lsgp -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-lsgp -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce  --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: lwgp s0, 32764(gp)
# CHECK-ASM: encoding: [0x07,0xb4,0xf7,0x1f]
lwgp s0, 32764(gp)

# CHECK-ASM-AND-OBJ: swgp s0, 32764(gp)
# CHECK-ASM: encoding: [0xa7,0xbf,0x87,0x1e]
swgp s0, 32764(gp)