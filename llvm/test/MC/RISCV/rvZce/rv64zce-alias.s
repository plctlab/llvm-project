# RUN: llvm-mc %s -triple=riscv64 -mattr=+c,+experimental-zce -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=+c,+experimental-zce < %s \
# RUN:     | llvm-objdump --mattr=+c,+experimental-zce -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefix=CHECK-ASM-AND-OBJ %s
# RUN: not llvm-mc -triple=riscv64 \
# RUN:     -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck --check-prefix=CHECK-NO-EXT %s
# RUN: not llvm-mc -triple=riscv32 -mattr=+c,+experimental-zce \
# RUN:     -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck --check-prefix=CHECK-NO-RV64 %s
# RUN: not llvm-mc -triple=riscv32 \
# RUN:     -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck --check-prefix=CHECK-NO-RV64-AND-EXT %s

# CHECK-ASM-AND-OBJ: c.addiw s0, 0
# CHECK-ASM: encoding: [0x01,0x24]
# CHECK-NO-EXT: error: instruction requires the following: 'C' (Compressed Instructions), 'Zcee' (high performance cores v0.50)
# CHECK-NO-RV64: error: instruction requires the following: RV64I Base Instruction Set
# CHECK-NO-RV64-AND-EXT: error: instruction requires the following: 'C' (Compressed Instructions), 'Zcee' (high performance cores v0.50), RV64I Base Instruction Set
c.sext.w s0
