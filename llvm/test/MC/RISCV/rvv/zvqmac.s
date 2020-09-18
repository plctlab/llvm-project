# RUN: llvm-mc -triple=riscv64 -show-encoding --mattr=+experimental-zvqmac %s \
# RUN:        | FileCheck %s --check-prefixes=CHECK-ENCODING,CHECK-INST
# RUN: not llvm-mc -triple=riscv64 -show-encoding %s 2>&1 \
# RUN:        | FileCheck %s --check-prefix=CHECK-ERROR
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zvqmac %s \
# RUN:        | llvm-objdump -d --mattr=+experimental-zvqmac - \
# RUN:        | FileCheck %s --check-prefix=CHECK-INST
# RUN: llvm-mc -triple=riscv64 -filetype=obj --mattr=+experimental-zvqmac %s \
# RUN:        | llvm-objdump -d - | FileCheck %s --check-prefix=CHECK-UNKNOWN

vqmaccu.vv v8, v20, v4, v0.t
# CHECK-INST: vqmaccu.vv v8, v20, v4, v0.t
# CHECK-ENCODING: [0x57,0x04,0x4a,0xf0]
# CHECK-ERROR: 'Zvqmac' (Vector Quad-Widening Integer Multiply-Add Instructions)
# CHECK-UNKNOWN: 57 04 4a f0 <unknown>

vqmaccu.vv v8, v20, v4
# CHECK-INST: vqmaccu.vv v8, v20, v4
# CHECK-ENCODING: [0x57,0x04,0x4a,0xf2]
# CHECK-ERROR: 'Zvqmac' (Vector Quad-Widening Integer Multiply-Add Instructions)
# CHECK-UNKNOWN: 57 04 4a f2 <unknown>

vqmaccu.vx v8, a0, v4, v0.t
# CHECK-INST: vqmaccu.vx v8, a0, v4, v0.t
# CHECK-ENCODING: [0x57,0x44,0x45,0xf0]
# CHECK-ERROR: 'Zvqmac' (Vector Quad-Widening Integer Multiply-Add Instructions)
# CHECK-UNKNOWN: 57 44 45 f0 <unknown>

vqmaccu.vx v8, a0, v4
# CHECK-INST: vqmaccu.vx v8, a0, v4
# CHECK-ENCODING: [0x57,0x44,0x45,0xf2]
# CHECK-ERROR: 'Zvqmac' (Vector Quad-Widening Integer Multiply-Add Instructions)
# CHECK-UNKNOWN: 57 44 45 f2 <unknown>

vqmacc.vv v8, v20, v4, v0.t
# CHECK-INST: vqmacc.vv v8, v20, v4, v0.t
# CHECK-ENCODING: [0x57,0x04,0x4a,0xf4]
# CHECK-ERROR: 'Zvqmac' (Vector Quad-Widening Integer Multiply-Add Instructions)
# CHECK-UNKNOWN: 57 04 4a f4 <unknown>

vqmacc.vv v8, v20, v4
# CHECK-INST: vqmacc.vv v8, v20, v4
# CHECK-ENCODING: [0x57,0x04,0x4a,0xf6]
# CHECK-ERROR: 'Zvqmac' (Vector Quad-Widening Integer Multiply-Add Instructions)
# CHECK-UNKNOWN: 57 04 4a f6 <unknown>

vqmacc.vx v8, a0, v4, v0.t
# CHECK-INST: vqmacc.vx v8, a0, v4, v0.t
# CHECK-ENCODING: [0x57,0x44,0x45,0xf4]
# CHECK-ERROR: 'Zvqmac' (Vector Quad-Widening Integer Multiply-Add Instructions)
# CHECK-UNKNOWN: 57 44 45 f4 <unknown>

vqmacc.vx v8, a0, v4
# CHECK-INST: vqmacc.vx v8, a0, v4
# CHECK-ENCODING: [0x57,0x44,0x45,0xf6]
# CHECK-ERROR: 'Zvqmac' (Vector Quad-Widening Integer Multiply-Add Instructions)
# CHECK-UNKNOWN: 57 44 45 f6 <unknown>

vqmaccsu.vv v8, v20, v4, v0.t
# CHECK-INST: vqmaccsu.vv v8, v20, v4, v0.t
# CHECK-ENCODING: [0x57,0x04,0x4a,0xfc]
# CHECK-ERROR: 'Zvqmac' (Vector Quad-Widening Integer Multiply-Add Instructions)
# CHECK-UNKNOWN: 57 04 4a fc <unknown>

vqmaccsu.vv v8, v20, v4
# CHECK-INST: vqmaccsu.vv v8, v20, v4
# CHECK-ENCODING: [0x57,0x04,0x4a,0xfe]
# CHECK-ERROR: 'Zvqmac' (Vector Quad-Widening Integer Multiply-Add Instructions)
# CHECK-UNKNOWN: 57 04 4a fe <unknown>

vqmaccsu.vx v8, a0, v4, v0.t
# CHECK-INST: vqmaccsu.vx v8, a0, v4, v0.t
# CHECK-ENCODING: [0x57,0x44,0x45,0xfc]
# CHECK-ERROR: 'Zvqmac' (Vector Quad-Widening Integer Multiply-Add Instructions)
# CHECK-UNKNOWN: 57 44 45 fc <unknown>

vqmaccsu.vx v8, a0, v4
# CHECK-INST: vqmaccsu.vx v8, a0, v4
# CHECK-ENCODING: [0x57,0x44,0x45,0xfe]
# CHECK-ERROR: 'Zvqmac' (Vector Quad-Widening Integer Multiply-Add Instructions)
# CHECK-UNKNOWN: 57 44 45 fe <unknown>

vqmaccus.vx v8, a0, v4, v0.t
# CHECK-INST: vqmaccus.vx v8, a0, v4, v0.t
# CHECK-ENCODING: [0x57,0x44,0x45,0xf8]
# CHECK-ERROR: 'Zvqmac' (Vector Quad-Widening Integer Multiply-Add Instructions)
# CHECK-UNKNOWN: 57 44 45 f8 <unknown>

vqmaccus.vx v8, a0, v4
# CHECK-INST: vqmaccus.vx v8, a0, v4
# CHECK-ENCODING: [0x57,0x44,0x45,0xfa]
# CHECK-ERROR: 'Zvqmac' (Vector Quad-Widening Integer Multiply-Add Instructions)
# CHECK-UNKNOWN: 57 44 45 fa <unknown>
