# RUN: llvm-mc %s -triple=riscv64 -mattr=experimental-zcmp -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=experimental-zcmp < %s \
# RUN:     | llvm-objdump --mattr=experimental-zcmp -M no-aliases -d -r - \
# RUN:     | FileCheck --check-prefixes=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: cm.mvsa01 s1, s0
# CHECK-ASM: encoding: [0xa2,0xac]
cm.mvsa01 s1, s0

# CHECK-ASM-AND-OBJ: cm.mva01s s1, s0
# CHECK-ASM: encoding: [0xe2,0xac]
cm.mva01s s1, s0
