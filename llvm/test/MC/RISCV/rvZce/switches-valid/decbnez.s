# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-decbnez -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-decbnez < %s \
# RUN:     | llvm-objdump --mattr=+zce-decbnez -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-OBJ %s


# CHECK-OBJ: decbnez s0, 0, 0x8
# CHECK-ASM: encoding: [0x07,0x34,0x40,0x80]
nop
decbnez s0, 1, 4