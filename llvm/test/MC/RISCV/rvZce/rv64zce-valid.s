# RUN: llvm-mc %s -triple=riscv64 -mattr=experimental-zce -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=experimental-zce < %s \
# RUN:     | llvm-objdump --mattr=experimental-zce -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefix=CHECK-ASM-AND-OBJ %s
# RUN: not llvm-mc -triple=riscv64 \
# RUN:     -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck --check-prefix=CHECK-NO-EXT %s
# RUN: not llvm-mc -triple=riscv32 -mattr=experimental-zce \
# RUN:     -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck --check-prefix=CHECK-NO-RV64 %s
# RUN: not llvm-mc -triple=riscv32 \
# RUN:     -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck --check-prefix=CHECK-NO-RV64-AND-EXT %s

# CHECK-ASM-AND-OBJ: c.zext.b s0
# CHECK-ASM: encoding: [0x00,0x84]
# CHECK-NO-EXT: error: instruction requires the following: 'Zcee' (high performance cores v0.41)
c.zext.b s0

# CHECK-ASM-AND-OBJ: c.sext.b s0
# CHECK-ASM: encoding: [0x04,0x84]
# CHECK-NO-EXT: error: instruction requires the following: 'Zcee' (high performance cores v0.41)
c.sext.b s0

# CHECK-ASM-AND-OBJ: c.zext.h s0
# CHECK-ASM: encoding: [0x08,0x84]
# CHECK-NO-EXT: error: instruction requires the following: 'Zcee' (high performance cores v0.41)
c.zext.h s0

# CHECK-ASM-AND-OBJ: c.sext.h s0
# CHECK-ASM: encoding: [0x0c,0x84]
# CHECK-NO-EXT: error: instruction requires the following: 'Zcee' (high performance cores v0.41)
c.sext.h s0

# CHECK-ASM-AND-OBJ: c.zext.w s0
# CHECK-ASM: encoding: [0x10,0x84]
# CHECK-NO-EXT: error: instruction requires the following: 'Zcee' (high performance cores v0.41)
# CHECK-NO-RV64: error: instruction requires the following: RV64I Base Instruction Set
# CHECK-NO-RV64-AND-EXT: error: instruction requires the following: 'Zcee' (high performance cores v0.41), RV64I Base Instruction Set
c.zext.w s0

# CHECK-ASM-AND-OBJ: c.neg s0
# CHECK-ASM: encoding: [0x18,0x84]
# CHECK-NO-EXT: error: instruction requires the following: 'Zcea' (all existing standard extensions for small embedded cores v0.41)
c.neg s0

# CHECK-ASM-AND-OBJ: c.not s0
# CHECK-ASM: encoding: [0x1c,0x84]
# CHECK-NO-EXT: error: instruction requires the following: 'Zcea' (all existing standard extensions for small embedded cores v0.41)
c.not s0

# CHECK-ASM-AND-OBJ: c.mul s0, s1
# CHECK-ASM: encoding: [0x45,0x9c]
c.mul s0, s1

# CHECK-ASM-AND-OBJ: ldgp s0, 65528(gp)
# CHECK-ASM: encoding: [0x07,0xb4,0xbf,0x5f]
# CHECK-NO-EXT: error: instruction requires the following: 'Zceb' (reuses encoding from the D-extension, incompatible with D v0.41)
# CHECK-NO-RV64: error: instruction requires the following: RV64I Base Instruction Set
# CHECK-NO-RV64-AND-EXT: error: instruction requires the following: 'Zceb' (reuses encoding from the D-extension, incompatible with D v0.41), RV64I Base Instruction Set
ldgp s0, 65528(gp)

# CHECK-ASM-AND-OBJ: sdgp s0, 65528(gp)
# CHECK-ASM: encoding: [0xa7,0xbd,0x8f,0x5e]
# CHECK-NO-EXT: error: instruction requires the following: 'Zceb' (reuses encoding from the D-extension, incompatible with D v0.41)
# CHECK-NO-RV64: error: instruction requires the following: RV64I Base Instruction Set
# CHECK-NO-RV64-AND-EXT: error: instruction requires the following: 'Zceb' (reuses encoding from the D-extension, incompatible with D v0.41), RV64I Base Instruction Set
sdgp s0, 65528(gp)

# CHECK-ASM: encoding: [0x2b,0x4c,0x02,0x00]
push <ra, s0-s1>, <a0>, -128
