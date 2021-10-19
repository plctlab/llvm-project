# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-tbljal -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-tbljal -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce  --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: tbljalm 6
# CHECK-ASM: encoding: [0x18,0x88]
tbljalm 6

# CHECK-ASM-AND-OBJ: tblj 40
# CHECK-ASM: encoding: [0xc0,0x88]
tblj 40

# CHECK-ASM-AND-OBJ: tbljal 190
# CHECK-ASM: encoding: [0xf8,0x8b]
tbljal 190