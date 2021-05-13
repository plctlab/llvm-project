# RUN: llvm-mc %s -triple=riscv32 -mattr=experimental-zce -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=experimental-zce < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc %s -triple=riscv64 -mattr=experimental-zce -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=experimental-zce < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefix=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: c.zext.b s0
# CHECK-ASM: encoding: [0x00,0x84]
c.zext.b s0

# CHECK-ASM-AND-OBJ: c.zext.h s0
# CHECK-ASM: encoding: [0x04,0x84]
c.zext.h s0

# CHECK-ASM-AND-OBJ: c.sext.b s0
# CHECK-ASM: encoding: [0x10,0x84]
c.sext.b s0

# CHECK-ASM-AND-OBJ: c.sext.h s0
# CHECK-ASM: encoding: [0x14,0x84]
c.sext.h s0


# CHECK-ASM-AND-OBJ: c.lbu a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0x27]
c.lbu a5, 10(a4)

# CHECK-ASM-AND-OBJ: c.lhu a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0x37]
c.lhu a5, 10(a4)

# CHECK-ASM-AND-OBJ: c.lb a5, 10(a4)
# CHECK-ASM: encoding: [0x3e,0xa7]
c.lb a5, 10(a4)

# CHECK-ASM-AND-OBJ: c.lh a5, 10(a4)
# CHECK-ASM: encoding: [0x3e,0xb7]
c.lh a5, 10(a4)

# CHECK-ASM-AND-OBJ: c.sb a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0xa7]
c.sb a5, 10(a4)

# CHECK-ASM-AND-OBJ: c.sh a5, 10(a4)
# CHECK-ASM: encoding: [0x3c,0xb7]
c.sh a5, 10(a4)

# comments
