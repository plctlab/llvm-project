# With K extension:
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-k %s \
# RUN:      | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-k %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-k - \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ASM-AND-OBJ

# With Zkn extension:
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-zkn %s \
# RUN:      | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zkn %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zkn - \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ASM-AND-OBJ

# With Zks extension:
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-zks %s \
# RUN:      | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zks %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zks - \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ASM-AND-OBJ

# With Zkb extension:
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-zkb %s \
# RUN:      | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zkb %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zkb - \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ASM-AND-OBJ


# CHECK-ASM-AND-OBJ: roriw t0, t1, 31
# CHECK-ASM: encoding: [0x9b,0x52,0xf3,0x61]
roriw t0, t1, 31

# CHECK-ASM-AND-OBJ: roriw t0, t1, 0
# CHECK-ASM: encoding: [0x9b,0x52,0x03,0x60]
roriw t0, t1, 0

# CHECK-ASM-AND-OBJ: packw t0, t1, t2
# CHECK-ASM: encoding: [0xbb,0x42,0x73,0x08]
packw t0, t1, t2

# CHECK-ASM-AND-OBJ: packuw t0, t1, t2
# CHECK-ASM: encoding: [0xbb,0x42,0x73,0x48]
packuw t0, t1, t2
