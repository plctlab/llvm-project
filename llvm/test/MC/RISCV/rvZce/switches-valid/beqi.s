# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-beqi -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-beqi < %s \
# RUN:     | llvm-objdump --mattr=+zce-beqi -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-OBJ %s

# CHECK-OBJ: beqi s0, 20, 0x34
# CHECK-ASM: encoding: [0x63,0x24,0x8a,0x02]
nop
nop
nop
beqi s0, 20, 40
