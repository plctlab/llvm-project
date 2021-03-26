# With K extension:
# RUN: llvm-mc %s -triple=riscv32 -mattr=+experimental-k -riscv-no-aliases \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ-NOALIAS %s
# RUN: llvm-mc %s -triple=riscv32 -mattr=+experimental-k \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ %s
# RUN: llvm-mc -filetype=obj -triple riscv32 -mattr=+experimental-k < %s \
# RUN:     | llvm-objdump -d -r --riscv-no-aliases --mattr=+experimental-k - \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ-NOALIAS %s
# RUN: llvm-mc -filetype=obj -triple riscv32 -mattr=+experimental-k < %s \
# RUN:     | llvm-objdump -d -r --mattr=+experimental-k - \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ %s

# With Zkn extension:
# RUN: llvm-mc %s -triple=riscv32 -mattr=+experimental-zkn -riscv-no-aliases \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ-NOALIAS %s
# RUN: llvm-mc %s -triple=riscv32 -mattr=+experimental-zkn \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ %s
# RUN: llvm-mc -filetype=obj -triple riscv32 -mattr=+experimental-zkn < %s \
# RUN:     | llvm-objdump -d -r --riscv-no-aliases --mattr=+experimental-zkn - \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ-NOALIAS %s
# RUN: llvm-mc -filetype=obj -triple riscv32 -mattr=+experimental-zkn < %s \
# RUN:     | llvm-objdump -d -r --mattr=+experimental-zkn - \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ %s

# With Zks extension:
# RUN: llvm-mc %s -triple=riscv32 -mattr=+experimental-zks -riscv-no-aliases \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ-NOALIAS %s
# RUN: llvm-mc %s -triple=riscv32 -mattr=+experimental-zks \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ %s
# RUN: llvm-mc -filetype=obj -triple riscv32 -mattr=+experimental-zks < %s \
# RUN:     | llvm-objdump -d -r --riscv-no-aliases --mattr=+experimental-zks - \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ-NOALIAS %s
# RUN: llvm-mc -filetype=obj -triple riscv32 -mattr=+experimental-zks < %s \
# RUN:     | llvm-objdump -d -r --mattr=+experimental-zks - \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ %s

# With Zkb extension:
# RUN: llvm-mc %s -triple=riscv32 -mattr=+experimental-zkb -riscv-no-aliases \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ-NOALIAS %s
# RUN: llvm-mc %s -triple=riscv32 -mattr=+experimental-zkb \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ %s
# RUN: llvm-mc -filetype=obj -triple riscv32 -mattr=+experimental-zkb < %s \
# RUN:     | llvm-objdump -d -r --riscv-no-aliases --mattr=+experimental-zkb - \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ-NOALIAS %s
# RUN: llvm-mc -filetype=obj -triple riscv32 -mattr=+experimental-zkb < %s \
# RUN:     | llvm-objdump -d -r --mattr=+experimental-zkb - \
# RUN:     | FileCheck -check-prefixes=CHECK-S-OBJ %s


# CHECK-S-OBJ-NOALIAS: grevi t0, t1, 7
# CHECK-S-OBJ: rev.b t0, t1
rev.b x5, x6

# CHECK-S-OBJ-NOALIAS: shfli t0, t1, 15
# CHECK-S-OBJ: zip t0, t1
zip x5, x6

# CHECK-S-OBJ-NOALIAS: unshfli t0, t1, 15
# CHECK-S-OBJ: unzip t0, t1
unzip x5, x6
