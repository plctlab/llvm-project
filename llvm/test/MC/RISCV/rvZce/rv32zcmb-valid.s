# RUN: llvm-mc %s -triple=riscv32 -mattr=experimental-zcmb -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=experimental-zcmb < %s \
# RUN:     | llvm-objdump --mattr=experimental-zcmb -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: cm.lbu a5, 10(a4)
# CHECK-ASM: encoding: [0x3e,0x27]
cm.lbu a5, 10(a4)

# CHECK-ASM-AND-OBJ: cm.lhu a5, 10(a4)
# CHECK-ASM: encoding: [0x3e,0x37]
cm.lhu a5, 10(a4)

# CHECK-ASM-AND-OBJ: cm.lb a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0x27]
cm.lb a5, 10(a4)

# CHECK-ASM-AND-OBJ: cm.lh a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0x37]
cm.lh a5, 10(a4)

# CHECK-ASM-AND-OBJ: cm.sb a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0xa7]
cm.sb a5, 10(a4)

# CHECK-ASM-AND-OBJ: cm.sh a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0xb7]
cm.sh a5, 10(a4)

# NOTE: c.lb a5, 10(a4)
# NOTE: [0x3e,0x27]
# lb a5, 10(a4)

# NOTE: c.lh a5, 10(a4)
# NOTE: 0x3e,0x37]
# lh a5, 10(a4)

# NOTE: c.lbu a5, 10(a4)
# NOTE: [0x3c,0x27]
#lbu a5, 10(a4)

# NOTE: c.lhu a5, 10(a4)
# NOTE: [0x3c,0x37]
#lhu a5, 10(a4)

# NOTE: c.sb a5, 10(a4)
# NOTE: [0x3c,0xa7]
#sb a5, 10(a4)

# NOTE: c.sh a5, 10(a4)
# NOTE: [0x3c,0xb7]
#sh a5, 10(a4)
