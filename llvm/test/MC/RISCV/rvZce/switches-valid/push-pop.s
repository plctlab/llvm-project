# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-push-pop -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-push-pop -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce  --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: push {ra, s0-s1}, {a0-a1}, -144
# CHECK-ASM: encoding: [0x2b,0x44,0x12,0x00]
push {ra, s0-s1}, {a0-a1}, -144

# CHECK-ASM-AND-OBJ: push {ra, s0-s1}, {a0-a1}, -128
# CHECK-ASM: encoding: [0xab,0x43,0x12,0x00]
push {ra, s0-s1}, {a0-a1}, -128

# CHECK-ASM-AND-OBJ: pop {ra, s0-s1}, {0}, 128
# CHECK-ASM: encoding: [0xab,0x53,0x12,0x00]
pop {ra, s0-s1}, {0}, 128

# CHECK-ASM-AND-OBJ: popret {ra, s0-s1}, {0}, 128
# CHECK-ASM: encoding: [0xab,0x63,0x12,0x00]
popret {ra, s0-s1}, {0}, 128