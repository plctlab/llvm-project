# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-beqi -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-beqi -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce  --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-OBJ %s

# CHECK-OBJ: beqi s0, 20, 0x34
# CHECK-ASM: encoding: [0x63,0x24,0x44,0x03]
nop
nop
nop
beqi s0, 20, 40