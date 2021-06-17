# With Zks extension:
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-zks %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zks %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zks - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zks %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

# With Zksed extension:
# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-zksed %s \
# RUN:      | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:      | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zksed %s \
# RUN:      | llvm-objdump -d --mattr=+experimental-zksed - \
# RUN:      | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zksed %s \
# RUN:      | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN


# CHECK-INST: sm4ed a0, a1, a2, 3
# CHECK-ENCODING: [0x33,0x85,0xc5,0xf0]
# CHECK-ERROR: instruction requires the following: 'Zksed'(SM4 Instructions)
# CHECK-UNKNOWN: 33 85 c5 f0 <unknown>
sm4ed a0, a1, a2, 3

# CHECK-INST: sm4ks a0, a1, a2, 3
# CHECK-ENCODING: [0x33,0x85,0xc5,0xf4]
# CHECK-ERROR: instruction requires the following: 'Zksed'(SM4 Instructions)
# CHECK-UNKNOWN: 33 85 c5 f4 <unknown>
sm4ks a0, a1, a2, 3
