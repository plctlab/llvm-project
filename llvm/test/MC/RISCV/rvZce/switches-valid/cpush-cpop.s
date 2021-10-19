# RUN: llvm-mc %s -triple=riscv32 -mattr=+zce-cpush-cpop -mattr=m -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+zce-cpush-cpop -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce  --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: c.popret   {ra}, {}, 16
# CHECK-ASM: encoding: [0x00,0x8c]
c.popret {ra}, {}, 16

# CHECK-ASM-AND-OBJ: c.popret   {ra}, {0}, 32
# CHECK-ASM: encoding: [0xa0,0x8c]
c.popret {ra}, {0}, 32

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0}, {0}, 64
# CHECK-ASM: encoding: [0xa4,0x8d]
c.popret {ra, s0}, {0}, 64

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s1}, {0}, 96
# CHECK-ASM: encoding: [0xa8,0x8e]
c.popret {ra,s0-s1}, {0}, 96

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s2}, {0}, 32
# CHECK-ASM: encoding: [0xac,0x8c]
c.popret {ra, s0-s2}, {0}, 32

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s3}, {0}, 112
# CHECK-ASM: encoding: [0xb0,0x8e]
c.popret {ra, s0-s3}, {0}, 112

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s5}, {0}, 112
# CHECK-ASM: encoding: [0xb4,0x8e]
c.popret {ra, s0-s5}, {0}, 112

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s7}, {0}, 128
# CHECK-ASM: encoding: [0xb8,0x8e]
c.popret {ra, s0-s7}, {0}, 128

# CHECK-ASM-AND-OBJ: c.popret   {ra, s0-s11}, {0}, 144
# CHECK-ASM: encoding: [0xbc,0x8e]
c.popret {ra, s0-s11}, {0}, 144

# CHECK-ASM-AND-OBJ: c.pop  {ra}, {}, 16
# CHECK-ASM: encoding: [0x00,0x8f]
c.pop {ra}, {}, 16

# CHECK-ASM-AND-OBJ: c.pop  {ra}, {}, 32
# CHECK-ASM: encoding: [0x80,0x8f]
c.pop {ra}, {}, 32

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0}, {}, 16
# CHECK-ASM: encoding: [0x04,0x8f]
c.pop {ra, s0}, {}, 16

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0-s1}, {}, 32
# CHECK-ASM: encoding: [0x88,0x8f]
c.pop {ra, s0-s1}, {}, 32

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0-s2}, {}, 32
# CHECK-ASM: encoding: [0x8c,0x8f]
c.pop {ra, s0-s2}, {}, 32

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0-s5}, {}, 32
# CHECK-ASM: encoding: [0x14,0x8f]
c.pop {ra, s0-s5}, {}, 32

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0-s7}, {}, 48
# CHECK-ASM: encoding: [0x18,0x8f]
c.pop {ra, s0-s7}, {}, 48

# CHECK-ASM-AND-OBJ: c.pop  {ra, s0-s11}, {}, 64
# CHECK-ASM: encoding: [0x1c,0x8f]
c.pop {ra, s0-s11}, {}, 64

# CHECK-ASM-AND-OBJ: c.push {ra}, {}, -16
# CHECK-ASM: encoding: [0x40,0x8c]
c.push {ra}, {}, -16

# CHECK-ASM-AND-OBJ: c.push {ra, s0}, {a0}, -32
# CHECK-ASM: encoding: [0xc4,0x8c]
c.push {ra, s0}, {a0}, -32

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s1}, {a0-a1}, -96
# CHECK-ASM: encoding: [0xc8,0x8e]
c.push {ra, s0-s1}, {a0-a1}, -96

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s3}, {a0-a3}, -112
# CHECK-ASM: encoding: [0xd0,0x8e]
c.push {ra, s0-s3}, {a0-a3}, -112

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s7}, {a0-a3}, -80
# CHECK-ASM: encoding: [0x58,0x8d]
c.push {ra, s0-s7}, {a0-a3}, -80

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s7}, {a0-a3}, -128
# CHECK-ASM: encoding: [0xd8,0x8e]
c.push {ra, s0-s7}, {a0-a3}, -128

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s11}, {a0-a3}, -112
# CHECK-ASM: encoding: [0xdc,0x8d]
c.push {ra, s0-s11}, {a0-a3}, -112

# CHECK-ASM-AND-OBJ: c.push {ra, s0-s11}, {a0-a3}, -144
# CHECK-ASM: encoding: [0xdc,0x8e]
c.push {ra, s0-s11}, {a0-a3}, -144