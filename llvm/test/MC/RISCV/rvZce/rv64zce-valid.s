# RUN: llvm-mc %s -triple=riscv64 -mattr=+m,+experimental-zcmt,+zce-beqi,+zce-bnei,+zce-decbnez,+zce-lsgp \
# RUN:  -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=+experimental-zcmt,+zce-beqi,+zce-bnei,+zce-decbnez,+zce-lsgp \
# RUN:  -mattr=m < %s \
# RUN:     | llvm-objdump --mattr=+m,+experimental-zcmt,+zce-beqi,+zce-bnei,+zce-decbnez,+zce-lsgp \
# RUN:   --mattr=m -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefix=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: lwgp s0, 32764(gp)
# CHECK-ASM: encoding: [0x07,0xb4,0xf7,0x1f]
lwgp s0, 32764(gp)

# CHECK-ASM: lwgp s0, %lo(foo)(gp)
# CHECK-ASM: encoding: [0x07,0bA0110100,A,0b000AAAAA]
# CHECK-OBJ: lwgp s0, 0(gp)
# CHECK-OBJ: R_RISCV_GPREL_ZCE_LWGP foo
lwgp s0, %lo(foo)(gp)

# CHECK-ASM-AND-OBJ: swgp s0, 32764(gp)
# CHECK-ASM: encoding: [0xa7,0xbf,0x87,0x1e]
swgp s0, 32764(gp)

# CHECK-ASM: swgp s0, %lo(foo)(gp)
# CHECK-ASM: encoding: [0bA0100111,0x30'A',0x80'A',0b000AAAAA]
# CHECK-OBJ: swgp s0, 0(gp)
# CHECK-OBJ: R_RISCV_GPREL_ZCE_SWGP foo
swgp s0, %lo(foo)(gp)

# CHECK-ASM-AND-OBJ: ldgp s0, 65528(gp)
# CHECK-ASM: encoding: [0x07,0xb4,0xbf,0x5f]
ldgp s0, 65528(gp)

# CHECK-ASM: ldgp s0, %lo(foo)(gp)
# CHECK-ASM: encoding: [0x07,0bA0110100,A,0b010AAAAA]
# CHECK-ASM-FIXUP:  fixup A - offset: 0, value: %lo(foo), kind: fixup_riscv_zce_ldgp
# CHECK-OBJ: ldgp s0, 0(gp)
# CHECK-OBJ: R_RISCV_GPREL_ZCE_LDGP foo
ldgp s0, %lo(foo)(gp)

# CHECK-ASM-AND-OBJ: sdgp s0, 65528(gp)
# CHECK-ASM: encoding: [0xa7,0xbd,0x8f,0x5e]
sdgp s0, 65528(gp)

# CHECK-ASM: sdgp s0, %lo(foo)(gp)
# CHECK-ASM: encoding: [0bA0100111,0x30'A',0x80'A',0b010AAAAA]
# CHECK-ASM-FIXUP:  fixup A - offset: 0, value: %lo(foo), kind: fixup_riscv_zce_sdgp
# CHECK-OBJ: sdgp s0, 0(gp)
# CHECK-OBJ: R_RISCV_GPREL_ZCE_SDGP foo
sdgp s0, %lo(foo)(gp)
