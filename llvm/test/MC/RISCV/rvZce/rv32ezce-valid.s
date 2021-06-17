# RUN: llvm-mc %s -triple=riscv32 -mattr=experimental-zce -mattr=e -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=experimental-zce -mattr=e < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce --mattr=e -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: pop.e {ra, s0-s2}, {}, 16
# CHECK-ASM: encoding: [0x2b,0x50,0x0d,0x00]
pop.e {ra, s0-s2}, {}, 16

# CHECK-ASM-AND-OBJ: popret.e {ra, s0-s2}, {}, 16
# CHECK-ASM: encoding: [0x2b,0x60,0x0d,0x00]
popret.e {ra, s0-s2}, {}, 16

# CHECK-ASM-AND-OBJ: push.e {ra, s0-s2}, {a0-a2}, -16
# CHECK-ASM: encoding: [0x2b,0x40,0x1d,0x00]
push.e {ra, s0-s2}, {a0-a2}, -16

# CHECK-ASM-AND-OBJ: push.e {ra, s0-s4}, {a0-a3}, -528
# CHECK-ASM: encoding: [0xab,0x4f,0x1f,0x00]
push.e {ra, s0-s4}, {a0-a3}, -528

# CHECK-ASM-AND-OBJ: c.popret   {ra}, {}, 16
# CHECK-ASM: encoding: [0x00,0x8c]
c.popret.e {ra}, {}, 16

# CHECK-ASM-AND-OBJ: c.pop  {ra}, {}, 32
# CHECK-ASM: encoding: [0x80,0x8f]
c.pop.e {ra}, {}, 32

# CHECK-ASM-AND-OBJ: c.push  {ra}, {}, -32
# CHECK-ASM: encoding: [0xc0,0x8c]
c.push.e {ra}, {}, -32

# CHECK-ASM-AND-OBJ: c.pop.e {ra, s0-s2}, {}, 32
# CHECK-ASM: encoding: [0xa0,0x8f]
c.pop.e {ra, s0-s2}, {}, 32

# CHECK-ASM-AND-OBJ: c.pop.e {ra, s0-s3}, {}, 48
# CHECK-ASM: encoding: [0xa4,0x8f]
c.pop.e {ra, s0-s3}, {}, 48

# CHECK-ASM-AND-OBJ: c.popret.e {ra, s0-s2}, {}, 16
# CHECK-ASM: encoding: [0x60,0x8c]
c.popret.e {ra, s0-s2}, {}, 16

# CHECK-ASM-AND-OBJ: c.popret.e {ra, s0-s2}, {}, 96
# CHECK-ASM: encoding: [0xe0,0x8e]
c.popret.e {ra, s0-s2}, {}, 96

# CHECK-ASM-AND-OBJ: c.popret.e {ra, s0-s3}, {}, 32
# CHECK-ASM: encoding: [0x64,0x8c]
c.popret.e {ra, s0-s3}, {}, 32

# CHECK-ASM-AND-OBJ: c.popret.e {ra, s0-s3}, {0}, 96
# CHECK-ASM: encoding: [0x74,0x8e]
c.popret.e {ra, s0-s3}, {0}, 96

# CHECK-ASM-AND-OBJ: c.popret.e {ra, s0-s4}, {}, 112
# CHECK-ASM: encoding: [0xe8,0x8e]
c.popret.e {ra, s0-s4}, {}, 112

# CHECK-ASM-AND-OBJ: c.push.e {ra, s0-s2}, {a0-a2}, -16
# CHECK-ASM: encoding: [0x40,0x8f]
c.push.e {ra, s0-s2}, {a0-a2}, -16

# CHECK-ASM-AND-OBJ: c.push.e {ra, s0-s2}, {a0-a2}, -96
# CHECK-ASM: encoding: [0xe0,0x8f]
c.push.e {ra, s0-s2}, {a0-a2}, -96

# CHECK-ASM-AND-OBJ: c.push.e {ra, s0-s3}, {a0-a3}, -32
# CHECK-ASM: encoding: [0x44,0x8f]
c.push.e {ra, s0-s3}, {a0-a3}, -32

# CHECK-ASM-AND-OBJ: c.push.e {ra, s0-s4}, {a0-a3}, -112
# CHECK-ASM: encoding: [0xe8,0x8f]
c.push.e {ra, s0-s4}, {a0-a3}, -112
