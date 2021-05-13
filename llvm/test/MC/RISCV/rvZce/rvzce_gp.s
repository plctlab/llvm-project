# RUN: llvm-mc %s -triple=riscv64 -mattr=+experimental-zce -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=+experimental-zce < %s \
# RUN:     | llvm-objdump --mattr=+experimental-zce -d -r - \
# RUN:     | FileCheck --check-prefix=CHECK-ASM-AND-OBJ %s

# With Bitmanip base extension:
# RUN: llvm-mc %s -triple=riscv64 -mattr=+experimental-zce -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=+experimental-zce < %s \
# RUN:     | llvm-objdump --mattr=+experimental-zce -d -r - \
# RUN:     | FileCheck --check-prefix=CHECK-ASM-AND-OBJ %s

# CHECK-ASM-AND-OBJ: lwgp s0, 65532(gp)
# CHECK-ASM: encoding: [0x07,0xb4,0xff,0x1f]
lwgp s0, 65532(gp)
