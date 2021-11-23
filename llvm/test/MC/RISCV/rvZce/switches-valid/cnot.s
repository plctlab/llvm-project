# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-cnot -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-cnot -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce  --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: c.not s0
# CHECK-ASM: encoding: [0x1c,0x80]
c.not s0

# CHECK-ASM-AND-OBJ: c.not a5
# CHECK-ASM: encoding: [0x9c,0x83]
not x15,x15
