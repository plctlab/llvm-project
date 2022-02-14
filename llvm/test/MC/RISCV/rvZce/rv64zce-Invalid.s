# RUN: not llvm-mc -triple=riscv64 -mattr=experimental-zce -mattr=m -riscv-no-aliases -show-encoding < %s 2>&1 \
# RUN:     | FileCheck -check-prefixes=CHECK-ERROR %s

# CHECK-ERROR: error: immediate must be an integer in the range [0, 7]
tbljalm 8

# CHECK-ERROR: error: immediate must be an integer in the range [0, 55]
tblj 56

# CHECK-ERROR: error: immediate must be an integer in the range [0, 191]
tbljal 192

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

# CHECK-ERROR: error: operand must be a symbol with %lo modifier or an multiple of 8 bytes integer in the range [-65536, 65528]
ldgp s0, %hi(foo)(gp)

# CHECK-ERROR: error: operand must be a symbol with %lo modifier or an multiple of 8 bytes integer in the range [-65536, 65528]
ldgp s0, 2043(gp)

# CHECK-ERROR: error: operand must be a symbol with %lo modifier or an multiple of 8 bytes integer in the range [-65536, 65528]
ldgp s0, 65536(gp)

# CHECK-ERROR: error: operand must be a symbol with %lo modifier or an multiple of 8 bytes integer in the range [-65536, 65528]
sdgp s0, %hi(foo)(gp)

# CHECK-ERROR: error: operand must be a symbol with %lo modifier or an multiple of 8 bytes integer in the range [-65536, 65528]
sdgp s0, 2043(gp)

# CHECK-ERROR: error: operand must be a symbol with %lo modifier or an multiple of 8 bytes integer in the range [-65536, 65528]
sdgp s0, 65536(gp)
