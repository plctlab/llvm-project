# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-cmva01s07 -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-cmva01s07 -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce  --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: c.mva01s07 s0, s1
# CHECK-ASM: encoding: [0x65,0x9c]
c.mva01s07 s0, s1