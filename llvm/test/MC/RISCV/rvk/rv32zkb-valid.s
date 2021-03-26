# With K extension:
# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-k %s \
# RUN:      | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-k %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-k - \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ASM-AND-OBJ

# With Zkn extension:
# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-zkn %s \
# RUN:      | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zkn %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zkn - \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ASM-AND-OBJ

# With Zks extension:
# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-zks %s \
# RUN:      | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zks %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zks - \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ASM-AND-OBJ

# With Zkb extension:
# RUN: llvm-mc -triple=riscv32 -show-encoding --mattr=+experimental-zkb %s \
# RUN:      | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -triple=riscv32 -filetype=obj --mattr=+experimental-zkb %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zkb - \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ASM-AND-OBJ


# CHECK-ASM-AND-OBJ: xperm.n t0, t1, t2
# CHECK-ASM: encoding: [0xb3,0x22,0x73,0x28]
xperm.n t0, t1, t2

# CHECK-ASM-AND-OBJ: xperm.b t0, t1, t2
# CHECK-ASM: encoding: [0xb3,0x42,0x73,0x28]
xperm.b t0, t1, t2

# CHECK-ASM-AND-OBJ: ror t0, t1, t2
# CHECK-ASM: encoding: [0xb3,0x52,0x73,0x60]
ror t0, t1, t2

# CHECK-ASM-AND-OBJ: rol t0, t1, t2
# CHECK-ASM: encoding: [0xb3,0x12,0x73,0x60]
rol t0, t1, t2

# CHECK-ASM-AND-OBJ: rori t0, t1, 31
# CHECK-ASM: encoding: [0x93,0x52,0xf3,0x61]
rori t0, t1, 31

# CHECK-ASM-AND-OBJ: rori t0, t1, 0
# CHECK-ASM: encoding: [0x93,0x52,0x03,0x60]
rori t0, t1, 0

# CHECK-ASM-AND-OBJ: andn t0, t1, t2
# CHECK-ASM: encoding: [0xb3,0x72,0x73,0x40]
andn t0, t1, t2

# CHECK-ASM-AND-OBJ: orn t0, t1, t2
# CHECK-ASM: encoding: [0xb3,0x62,0x73,0x40]
orn t0, t1, t2

# CHECK-ASM-AND-OBJ: xnor t0, t1, t2
# CHECK-ASM: encoding: [0xb3,0x42,0x73,0x40]
xnor t0, t1, t2

# CHECK-ASM-AND-OBJ: pack t0, t1, t2
# CHECK-ASM: encoding: [0xb3,0x42,0x73,0x08]
pack t0, t1, t2

# CHECK-ASM-AND-OBJ: packu t0, t1, t2
# CHECK-ASM: encoding: [0xb3,0x42,0x73,0x48]
packu t0, t1, t2

# CHECK-ASM-AND-OBJ: packh t0, t1, t2
# CHECK-ASM: encoding: [0xb3,0x72,0x73,0x08]
packh t0, t1, t2

# CHECK-ASM-AND-OBJ: rev8 t0, t1
# CHECK-ASM: encoding: [0x93,0x52,0x83,0x69]
rev8 t0, t1

# CHECK-ASM-AND-OBJ: grevi t0, t1, 0
# CHECK-ASM: encoding: [0x93,0x52,0x03,0x68]
grevi t0, t1, 0

# CHECK-ASM-AND-OBJ: shfli t0, t1, 0
# CHECK-ASM: encoding: [0x93,0x12,0x03,0x08]
shfli t0, t1, 0

# CHECK-ASM-AND-OBJ: unshfli t0, t1, 0
# CHECK-ASM: encoding: [0x93,0x52,0x03,0x08]
unshfli t0, t1, 0
