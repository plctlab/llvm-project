# RUN: not llvm-mc -triple=riscv32 -mattr=+experimental-zcmt,+zce-lsgp -mattr=m -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck -check-prefixes=CHECK-ERROR %s

# CHECK-ERROR: error: operand must be a symbol with %lo modifier or an multiple of 4 bytes integer in the range [-32768, 32764]
lwgp s0, %hi(foo)(gp)

# CHECK-ERROR: error: operand must be a symbol with %lo modifier or an multiple of 4 bytes integer in the range [-32768, 32764]
lwgp s0, 2043(gp)

# CHECK-ERROR: error: operand must be a symbol with %lo modifier or an multiple of 4 bytes integer in the range [-32768, 32764]
lwgp s0, 32768(gp)

# CHECK-ERROR: error: operand must be a symbol with %lo modifier or an multiple of 4 bytes integer in the range [-32768, 32764]
swgp s0, %hi(foo)(gp)

# CHECK-ERROR: error: operand must be a symbol with %lo modifier or an multiple of 4 bytes integer in the range [-32768, 32764]
swgp s0, 2043(gp)

# CHECK-ERROR: error: operand must be a symbol with %lo modifier or an multiple of 4 bytes integer in the range [-32768, 32764]
swgp s0, 32768(gp)
