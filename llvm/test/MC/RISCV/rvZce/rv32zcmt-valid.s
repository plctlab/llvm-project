# RUN: llvm-mc %s -triple=riscv32 -mattr=+experimental-zcmt\
# RUN:  -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+experimental-zcmt\
# RUN:  -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=+experimental-zcmt\
# RUN:  -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-OBJ,CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: cm.jt 1
# CHECK-ASM: encoding: [0x06,0xa0]
cm.jt 1

# CHECK-ASM: cm.jalt 1
# CHECK-OBJ: cm.jt 1
# CHECK-ASM: encoding: [0x06,0xa0]
cm.jalt 1

# CHECK-ASM-AND-OBJ: cm.jalt 64
# CHECK-ASM: encoding: [0x02,0xa1]
cm.jalt 64