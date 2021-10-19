# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-pushe-pope -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-pushe-pope -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce  --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-OBJ %s

# CHECK-ASM: push.e {ra, s0-s2}, {a0-a2}, -16
# CHECK-OBJ: push {ra, s0-s2}, {a0-a2}, -16
# CHECK-ASM: encoding: [0x2b,0x40,0x1d,0x00]
push.e {ra, s0-s2}, {a0-a2}, -16

# CHECK-ASM: push.e {ra, s0-s4}, {a0-a3}, -528
# CHECK-OBJ: push {ra, s0-s4}, {a0-a3}, -528
# CHECK-ASM: encoding: [0xab,0x4f,0x1f,0x00]
push.e {ra, s0-s4}, {a0-a3}, -528

# CHECK-ASM: pop.e {ra, s0-s2}, {}, 16
# CHECK-OBJ: pop {ra, s0-s2}, {}, 16
# CHECK-ASM: encoding: [0x2b,0x50,0x0d,0x00]
pop.e {ra, s0-s2}, {}, 16

# CHECK-ASM: popret.e {ra, s0-s2}, {}, 16
# CHECK-OBJ: popret {ra, s0-s2}, {}, 16
# CHECK-ASM: encoding: [0x2b,0x60,0x0d,0x00]
popret.e {ra, s0-s2}, {}, 16