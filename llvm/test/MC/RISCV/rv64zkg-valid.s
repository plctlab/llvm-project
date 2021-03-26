# With K extension:
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-k %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-k %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-k - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST

# With Zkn extension:
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-zkn %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zkn %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zkn - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST

# With Zks extension:
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-zks %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zks %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zks - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST

# With Zkg extension:
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-zkg %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zkg %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zkg - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST

# CHECK-INST: clmul t0, t1, t2
# CHECK-ENCODING: [0xb3,0x12,0x73,0x0a]
clmul t0, t1, t2

# CHECK-INST: clmulh t0, t1, t2
# CHECK-ENCODING: [0xb3,0x32,0x73,0x0a]
clmulh t0, t1, t2
