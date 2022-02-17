# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-sext,+experimental-zbb -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-sext,+experimental-zbb < %s \
# RUN:     | llvm-objdump --mattr=+zce-sext,+experimental-zbb -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc %s -triple=riscv64 -mattr=+zce-sext,+experimental-zbb -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=+zce-sext,+experimental-zbb < %s \
# RUN:     | llvm-objdump --mattr=+zce-sext,+experimental-zbb -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: sext.b s0, s1
# CHECK-ASM: encoding: [0x13,0x94,0x44,0x60]
sext.b s0, s1

# CHECK-ASM-AND-OBJ: c.sext.b s0
# CHECK-ASM: encoding: [0x65,0x9c]
sext.b s0, s0

# CHECK-ASM-AND-OBJ: sext.h s0, s1
# CHECK-ASM: encoding: [0x13,0x94,0x54,0x60]
sext.h s0, s1

# CHECK-ASM-AND-OBJ: c.sext.h s0
# CHECK-ASM: encoding: [0x6d,0x9c]
sext.h s0, s0