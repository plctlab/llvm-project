# RUN: llvm-mc %s -triple=riscv64 -mattr=+experimental-zfdinx -riscv-no-aliases \
# RUN:     | FileCheck -check-prefix=CHECK-INST %s
# RUN: llvm-mc %s -triple=riscv64 -mattr=+experimental-zfdinx \
# RUN:     | FileCheck -check-prefix=CHECK-ALIAS %s
# RUN: llvm-mc -filetype=obj -triple riscv64 -mattr=+experimental-zfdinx < %s \
# RUN:     | llvm-objdump -d --mattr=+experimental-zfdinx -M no-aliases - \
# RUN:     | FileCheck -check-prefix=CHECK-INST %s
# RUN: llvm-mc -filetype=obj -triple riscv64 -mattr=+experimental-zfdinx < %s \
# RUN:     | llvm-objdump -d --mattr=+experimental-zfdinx - \
# RUN:     | FileCheck -check-prefix=CHECK-ALIAS %s

##===----------------------------------------------------------------------===##
## Aliases which omit the rounding mode.
##===----------------------------------------------------------------------===##

# CHECK-INST: fcvt.l.d a0, t0, dyn
# CHECK-ALIAS: fcvt.l.d a0, t0{{[[:space:]]}}
fcvt.l.d a0, t0
# CHECK-INST: fcvt.lu.d a1, t1, dyn
# CHECK-ALIAS: fcvt.lu.d a1, t1{{[[:space:]]}}
fcvt.lu.d a1, t1
# CHECK-INST: fcvt.d.l t3, a3, dyn
# CHECK-ALIAS: fcvt.d.l t3, a3{{[[:space:]]}}
fcvt.d.l t3, a3
# CHECK-INST: fcvt.d.lu t4, a4, dyn
# CHECK-ALIAS: fcvt.d.lu t4, a4{{[[:space:]]}}
fcvt.d.lu t4, a4
