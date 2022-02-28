# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-bnei -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-bnei < %s \
# RUN:     | llvm-objdump --mattr=+zce-bnei -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-OBJ %s

# CHECK-OBJ: bnei s0, 20, 0x30
# CHECK-ASM: encoding: [0x63,0x34,0x8a,0x02]
nop
nop
bnei s0, 20, 40