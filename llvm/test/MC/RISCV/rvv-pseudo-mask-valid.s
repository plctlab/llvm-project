# RUN: llvm-mc %s -triple=riscv32 -mattr=+v -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc %s -triple=riscv64 -mattr=+v -riscv-no-aliases -show-encoding \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+v < %s \
# RUN:     | llvm-objdump --mattr=+v -M no-aliases -d -r - \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM-AND-OBJ %s
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=+v < %s \
# RUN:     | llvm-objdump --mattr=+v -M no-aliases -d -r - \
# RUN:     | FileCheck -check-prefixes=CHECK-ASM-AND-OBJ %s

vle128.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vle128.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x10]

vle256.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vle256.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x10]

vle512.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vle512.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x10]

vle8.v	v0, (a1), v0.t         
# CHECK-ASM-AND-OBJ: vle8.v	v0,  0(a1), v0.t         
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x00]

vle16.v	v0, (a1), v0.t         
# CHECK-ASM-AND-OBJ: vle16.v	v0,  0(a1), v0.t         
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x00]

vle32.v	v0, (a1), v0.t         
# CHECK-ASM-AND-OBJ: vle32.v	v0,  0(a1), v0.t         
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x00]

vle64.v	v0, (a1), v0.t         
# CHECK-ASM-AND-OBJ: vle64.v	v0,  0(a1), v0.t         
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x00]

vse8.v	v0, (a1), v0.t         
# CHECK-ASM-AND-OBJ: vse8.v	v0,  0(a1), v0.t         
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x00]

vse16.v	v0, (a1), v0.t         
# CHECK-ASM-AND-OBJ: vse16.v	v0,  0(a1), v0.t         
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x00]

vse32.v	v0, (a1), v0.t         
# CHECK-ASM-AND-OBJ: vse32.v	v0,  0(a1), v0.t         
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x00]

vse64.v	v0, (a1), v0.t         
# CHECK-ASM-AND-OBJ: vse64.v	v0,  0(a1), v0.t         
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x00]

vlse128.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlse128.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x18]

vlse256.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlse256.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x18]

vlse512.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlse512.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x18]

vlse8.v	v0, (a1), a2, v0.t     
# CHECK-ASM-AND-OBJ: vlse8.v	v0,  0(a1), a2, v0.t     
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x08]

vlse16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlse16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x08]

vlse32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlse32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x08]

vlse64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlse64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x08]

vsse8.v	v0, (a1), a2, v0.t     
# CHECK-ASM-AND-OBJ: vsse8.v	v0,  0(a1), a2, v0.t     
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x08]

vsse16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vsse16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x08]

vsse32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vsse32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x08]

vsse64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vsse64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x08]

vlxei128.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxei128.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x1c]

vlxei256.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxei256.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x1c]

vlxei512.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxei512.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x1c]

vlxei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x0c]

vlxei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x0c]

vlxei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x0c]

vlxei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x0c]

vsxei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x0c]

vsxei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x0c]

vsxei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x0c]

vsxei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x0c]

vsxei128.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxei128.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x1c]

vsxei256.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxei256.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x1c]

vsxei512.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxei512.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x1c]

vsxei1024.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxei1024.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x1c]

vle128ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vle128ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x11]

vle256ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vle256ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x11]

vle512ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vle512ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x11]

vle8ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vle8ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x01]

vle16ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vle16ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x01]

vle32ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vle32ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x01]

vle64ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vle64ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x01]

vlseg2e128.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg2e128.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x30]

vlseg2e256.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg2e256.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x30]

vlseg2e512.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg2e512.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x30]

vlseg2e8.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg2e8.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x20]

vlseg2e16.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg2e16.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x20]

vlseg2e32.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg2e32.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x20]

vlseg2e64.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg2e64.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x20]

vsseg2e8.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg2e8.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x20]

vsseg2e16.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg2e16.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x20]

vsseg2e32.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg2e32.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x20]

vsseg2e64.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg2e64.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x20]

vlseg3e128.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg3e128.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x50]

vlseg3e256.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg3e256.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x50]

vlseg3e512.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg3e512.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x50]

vlseg3e8.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg3e8.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x40]

vlseg3e16.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg3e16.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x40]

vlseg3e32.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg3e32.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x40]

vlseg3e64.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg3e64.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x40]

vsseg3e8.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg3e8.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x40]

vsseg3e16.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg3e16.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x40]

vsseg3e32.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg3e32.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x40]

vsseg3e64.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg3e64.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x40]

vlseg4e128.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg4e128.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x70]

vlseg4e256.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg4e256.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x70]

vlseg4e512.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg4e512.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x70]

vlseg4e8.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg4e8.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x60]

vlseg4e16.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg4e16.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x60]

vlseg4e32.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg4e32.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x60]

vlseg4e64.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg4e64.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x60]

vsseg4e8.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg4e8.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x60]

vsseg4e16.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg4e16.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x60]

vsseg4e32.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg4e32.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x60]

vsseg4e64.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg4e64.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x60]

vlseg5e128.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg5e128.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x90]

vlseg5e256.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg5e256.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x90]

vlseg5e512.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg5e512.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x90]

vlseg5e8.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg5e8.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x80]

vlseg5e16.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg5e16.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x80]

vlseg5e32.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg5e32.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x80]

vlseg5e64.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg5e64.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x80]

vsseg5e8.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg5e8.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x80]

vsseg5e16.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg5e16.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x80]

vsseg5e32.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg5e32.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x80]

vsseg5e64.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg5e64.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x80]

vlseg6e128.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg6e128.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xb0]

vlseg6e256.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg6e256.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xb0]

vlseg6e512.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg6e512.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xb0]

vlseg6e8.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg6e8.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xa0]

vlseg6e16.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg6e16.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xa0]

vlseg6e32.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg6e32.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xa0]

vlseg6e64.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg6e64.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xa0]

vsseg6e8.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg6e8.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0xa0]

vsseg6e16.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg6e16.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0xa0]

vsseg6e32.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg6e32.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0xa0]

vsseg6e64.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg6e64.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0xa0]

vlseg7e128.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg7e128.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xd0]

vlseg7e256.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg7e256.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xd0]

vlseg7e512.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg7e512.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xd0]

vlseg7e8.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg7e8.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xc0]

vlseg7e16.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg7e16.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xc0]

vlseg7e32.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg7e32.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xc0]

vlseg7e64.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg7e64.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xc0]

vsseg7e8.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg7e8.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0xc0]

vsseg7e16.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg7e16.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0xc0]

vsseg7e32.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg7e32.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0xc0]

vsseg7e64.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg7e64.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0xc0]

vlseg8e128.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg8e128.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xf0]

vlseg8e256.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg8e256.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xf0]

vlseg8e512.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg8e512.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xf0]

vlseg8e8.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg8e8.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xe0]

vlseg8e16.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg8e16.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xe0]

vlseg8e32.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg8e32.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xe0]

vlseg8e64.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg8e64.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xe0]

vsseg8e8.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg8e8.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0xe0]

vsseg8e16.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg8e16.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0xe0]

vsseg8e32.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg8e32.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0xe0]

vsseg8e64.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vsseg8e64.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0xe0]

vlsseg2e128.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg2e128.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x38]

vlsseg2e256.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg2e256.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x38]

vlsseg2e512.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg2e512.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x38]

vlsseg2e8.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg2e8.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x28]

vlsseg2e16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg2e16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x28]

vlsseg2e32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg2e32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x28]

vlsseg2e64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg2e64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x28]

vssseg2e8.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg2e8.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x28]

vssseg2e16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg2e16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x28]

vssseg2e32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg2e32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x28]

vssseg2e64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg2e64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x28]

vssseg2e128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ:  vssseg2e128.v	v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x38]

vssseg2e256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ:  vssseg2e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x38]

vssseg2e512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ:  vssseg2e512.v v0, 0(a1), a2
# CHECK-ASM: [0x27,0xe0,0xc5,0x38]

vssseg2e1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ:  vssseg2e1024.v v0, 0(a1), a2
# CHECK-ASM: [0x27,0xf0,0xc5,0x38]

vlsseg3e128.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg3e128.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x58]

vlsseg3e256.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg3e256.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x58]

vlsseg3e512.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg3e512.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x58]

vlsseg3e8.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg3e8.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x48]

vlsseg3e16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg3e16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x48]

vlsseg3e32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg3e32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x48]

vlsseg3e64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg3e64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x48]

vssseg3e8.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg3e8.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x48]

vssseg3e16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg3e16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x48]

vssseg3e32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg3e32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x48]

vssseg3e64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg3e64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x48]

vssseg3e128.v	v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg3e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0x58]

vssseg3e256.v	v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg3e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0x58]

vssseg3e512.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg3e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0x58]

vssseg3e1024.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg3e1024.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0x58]

vlsseg4e128.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg4e128.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x78]

vlsseg4e256.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg4e256.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x78]

vlsseg4e512.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg4e512.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x78]

vlsseg4e8.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg4e8.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x68]

vlsseg4e16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg4e16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x68]

vlsseg4e32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg4e32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x68]

vlsseg4e64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg4e64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x68]

vssseg4e8.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg4e8.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x68]

vssseg4e16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg4e16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x68]

vssseg4e32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg4e32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x68]

vssseg4e64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg4e64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x68]

vssseg4e128.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg4e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0x78]

vssseg4e256.v	v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg4e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0x78]

vssseg4e512.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: 	vssseg4e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0x78]

vssseg4e1024.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg4e1024.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0x78]

vlsseg5e128.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg5e128.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x98]

vlsseg5e256.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg5e256.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x98]

vlsseg5e512.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg5e512.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x98]

vlsseg5e8.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg5e8.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x88]

vlsseg5e16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg5e16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x88]

vlsseg5e32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg5e32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x88]

vlsseg5e64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg5e64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x88]

vssseg5e8.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg5e8.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x88]

vssseg5e16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg5e16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x88]

vssseg5e32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg5e32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x88]

vssseg5e64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg5e64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x88]

vssseg5e128.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: 	vssseg5e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0x98]

vssseg5e256.v	v0, (a1), a2, v0.t  
# CHECK-ASM-AND-OBJ: 	vssseg5e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0x98]

vssseg5e512.v	v0, (a1), a2, v0.t  
# CHECK-ASM-AND-OBJ: 	vssseg5e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0x98]

vssseg5e1024.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg5e1024.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0x98]

vlsseg6e128.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg6e128.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xb8]

vlsseg6e256.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg6e256.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xb8]

vlsseg6e512.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg6e512.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xb8]

vlsseg6e8.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg6e8.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xa8]

vlsseg6e16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg6e16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xa8]

vlsseg6e32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg6e32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xa8]

vlsseg6e64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg6e64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0xa8]

vssseg6e8.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg6e8.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xa8]

vssseg6e16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg6e16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xa8]

vssseg6e32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg6e32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xa8]

vssseg6e64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg6e64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xa8]

vssseg6e128.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg6e128.v	v0, 0(a1), a2, v0.t  
# CHECK-ASM: [0x27,0x80,0xc5,0xb8]

vssseg6e256.v	v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg6e256.v	v0, 0(a1), a2, v0.t  
# CHECK-ASM: [0x27,0xd0,0xc5,0xb8]

vssseg6e512.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg6e512.v	v0, 0(a1), a2, v0.t   
# CHECK-ASM: [0x27,0xe0,0xc5,0xb8]

vssseg6e1024.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg6e1024.v	v0, 0(a1), a2, v0.t   
# CHECK-ASM: [0x27,0xf0,0xc5,0xb8]

vlsseg7e128.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg7e128.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xd8]

vlsseg7e256.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg7e256.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xd8]

vlsseg7e512.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg7e512.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xd8]

vlsseg7e8.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg7e8.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xc8]

vlsseg7e16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg7e16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xc8]

vlsseg7e32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg7e32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xc8]

vlsseg7e64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg7e64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0xc8]

vssseg7e8.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg7e8.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xc8]

vssseg7e16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg7e16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xc8]

vssseg7e32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg7e32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xc8]

vssseg7e64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg7e64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xc8]

vssseg7e128.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg7e128.v	v0, 0(a1), a2, v0.t   
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xd8]

vssseg7e256.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg7e256.v	v0, 0(a1), a2, v0.t   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xd8]

vssseg7e512.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg7e512.v	v0, 0(a1), a2, v0.t   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xd8]

vssseg7e1024.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg7e1024.v	v0, 0(a1), a2, v0.t   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xd8]

vlsseg8e128.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg8e128.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xf8]

vlsseg8e256.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg8e256.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xf8]

vlsseg8e512.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg8e512.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xf8]

vlsseg8e8.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg8e8.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xe8]

vlsseg8e16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg8e16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xe8]

vlsseg8e32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg8e32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xe8]

vlsseg8e64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vlsseg8e64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0xe8]

vssseg8e8.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg8e8.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xe8]

vssseg8e16.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg8e16.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xe8]

vssseg8e32.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg8e32.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xe8]

vssseg8e64.v	v0, (a1), a2, v0.t 
# CHECK-ASM-AND-OBJ: vssseg8e64.v	v0,  0(a1), a2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xe8]

vssseg8e128.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg8e128.v	v0, 0(a1), a2, v0.t   
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xf8]

vssseg8e256.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg8e256.v	v0, 0(a1), a2, v0.t   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xf8]

vssseg8e512.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg8e512.v	v0, 0(a1), a2, v0.t   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xf8]

vssseg8e1024.v	v0, (a1), a2, v0.t   
# CHECK-ASM-AND-OBJ: 	vssseg8e1024.v	v0, 0(a1), a2, v0.t   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xf8]

vlxseg2ei128.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg2ei128.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x3c]

vlxseg2ei256.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg2ei256.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x3c]

vlxseg2ei512.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg2ei512.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x3c]

vlxseg2ei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg2ei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x2c]

vlxseg2ei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg2ei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x2c]

vlxseg2ei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg2ei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x2c]

vlxseg2ei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg2ei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x2c]

vsxseg2ei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg2ei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x2c]

vsxseg2ei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg2ei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x2c]

vsxseg2ei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg2ei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x2c]

vsxseg2ei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg2ei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x2c]

vlxseg3ei128.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg3ei128.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x5c]

vlxseg3ei256.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg3ei256.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x5c]

vlxseg3ei512.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg3ei512.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x5c]

vlxseg3ei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg3ei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x4c]

vlxseg3ei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg3ei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x4c]

vlxseg3ei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg3ei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x4c]

vlxseg3ei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg3ei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x4c]

vsxseg3ei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg3ei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x4c]

vsxseg3ei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg3ei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x4c]

vsxseg3ei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg3ei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x4c]

vsxseg3ei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg3ei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x4c]

vlxseg4ei128.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg4ei128.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x7c]

vlxseg4ei256.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg4ei256.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x7c]

vlxseg4ei512.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg4ei512.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x7c]

vlxseg4ei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg4ei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x6c]

vlxseg4ei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg4ei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x6c]

vlxseg4ei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg4ei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x6c]

vlxseg4ei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg4ei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x6c]

vsxseg4ei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg4ei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x6c]

vsxseg4ei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg4ei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x6c]

vsxseg4ei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg4ei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x6c]

vsxseg4ei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg4ei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x6c]

vlxseg5ei128.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg5ei128.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x9c]

vlxseg5ei256.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg5ei256.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x9c]

vlxseg5ei512.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg5ei512.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x9c]

vlxseg5ei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg5ei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x8c]

vlxseg5ei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg5ei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x8c]

vlxseg5ei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg5ei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x8c]

vlxseg5ei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg5ei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x8c]

vsxseg5ei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg5ei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x8c]

vsxseg5ei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg5ei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x8c]

vsxseg5ei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg5ei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x8c]

vsxseg5ei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg5ei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x8c]

vlxseg6ei128.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg6ei128.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xbc]

vlxseg6ei256.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg6ei256.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xbc]

vlxseg6ei512.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg6ei512.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xbc]

vlxseg6ei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg6ei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xac]

vlxseg6ei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg6ei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xac]

vlxseg6ei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg6ei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xac]

vlxseg6ei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg6ei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0xac]

vsxseg6ei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg6ei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0xac]

vsxseg6ei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg6ei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0xac]

vsxseg6ei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg6ei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0xac]

vsxseg6ei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg6ei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0xac]

vlxseg7ei128.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg7ei128.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xdc]

vlxseg7ei256.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg7ei256.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xdc]

vlxseg7ei512.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg7ei512.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xdc]

vlxseg7ei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg7ei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xcc]

vlxseg7ei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg7ei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xcc]

vlxseg7ei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg7ei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xcc]

vlxseg7ei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg7ei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0xcc]

vsxseg7ei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg7ei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0xcc]

vsxseg7ei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg7ei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0xcc]

vsxseg7ei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg7ei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0xcc]

vsxseg7ei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg7ei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0xcc]

vlxseg8ei128.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg8ei128.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xfc]

vlxseg8ei256.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg8ei256.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xfc]

vlxseg8ei512.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg8ei512.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xfc]

vlxseg8ei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg8ei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xec]

vlxseg8ei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg8ei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xec]

vlxseg8ei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg8ei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xec]

vlxseg8ei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vlxseg8ei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0xec]

vsxseg8ei8.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg8ei8.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0xec]

vsxseg8ei16.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg8ei16.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0xec]

vsxseg8ei32.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg8ei32.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0xec]

vsxseg8ei64.v	v0, (a1), v2, v0.t 
# CHECK-ASM-AND-OBJ: vsxseg8ei64.v	v0,  0(a1), v2, v0.t 
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0xec]

vlseg2e128ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg2e128ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x31]

vlseg2e256ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg2e256ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x31]

vlseg2e512ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg2e512ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x31]

vlseg2e8ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg2e8ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x21]

vlseg2e16ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg2e16ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x21]

vlseg2e32ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg2e32ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x21]

vlseg2e64ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg2e64ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x21]

vlseg3e128ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg3e128ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x51]

vlseg3e256ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg3e256ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x51]

vlseg3e512ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg3e512ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x51]

vlseg3e8ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg3e8ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x41]

vlseg3e16ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg3e16ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x41]

vlseg3e32ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg3e32ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x41]

vlseg3e64ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg3e64ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x41]

vlseg4e128ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg4e128ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x71]

vlseg4e256ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg4e256ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x71]

vlseg4e512ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg4e512ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x71]

vlseg4e8ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg4e8ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x61]

vlseg4e16ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg4e16ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x61]

vlseg4e32ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg4e32ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x61]

vlseg4e64ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg4e64ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x61]

vlseg5e128ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg5e128ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x91]

vlseg5e256ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg5e256ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x91]

vlseg5e512ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg5e512ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x91]

vlseg5e8ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg5e8ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x81]

vlseg5e16ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg5e16ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x81]

vlseg5e32ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg5e32ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x81]

vlseg5e64ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg5e64ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x81]

vlseg6e128ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg6e128ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xb1]

vlseg6e256ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg6e256ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xb1]

vlseg6e512ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg6e512ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xb1]

vlseg6e8ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg6e8ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xa1]

vlseg6e16ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg6e16ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xa1]

vlseg6e32ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg6e32ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xa1]

vlseg6e64ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg6e64ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xa1]

vlseg7e128ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg7e128ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xd1]

vlseg7e256ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg7e256ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xd1]

vlseg7e512ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg7e512ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xd1]

vlseg7e8ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg7e8ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xc1]

vlseg7e16ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg7e16ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xc1]

vlseg7e32ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg7e32ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xc1]

vlseg7e64ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg7e64ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xc1]

vlseg8e128ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg8e128ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xf1]

vlseg8e256ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg8e256ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xf1]

vlseg8e512ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg8e512ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xf1]

vlseg8e8ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg8e8ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xe1]

vlseg8e16ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg8e16ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xe1]

vlseg8e32ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg8e32ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xe1]

vlseg8e64ff.v	v0, (a1), v0.t 
# CHECK-ASM-AND-OBJ: vlseg8e64ff.v	v0,  0(a1), v0.t 
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xe1]

vamoswapei32.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoswapei32.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x0c]

vamoswapei32.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoswapei32.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x08]

vamoaddei32.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoaddei32.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x04]

vamoaddei32.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoaddei32.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x00]

vamoxorei32.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoxorei32.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x24]

vamoxorei32.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoxorei32.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x20]

vamoandei32.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoandei32.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x64]

vamoandei32.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoandei32.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x60]

vamoorei32.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoorei32.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x44]

vamoorei32.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoorei32.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x40]

vamominei32.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamominei32.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x84]

vamominei32.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamominei32.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x80]

vamomaxei32.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamomaxei32.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0xa4]

vamomaxei32.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamomaxei32.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0xa0]

vamominuei32.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamominuei32.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0xc4]

vamominuei32.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamominuei32.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0xc0]

vamomaxuei32.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamomaxuei32.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0xe4]

vamomaxuei32.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamomaxuei32.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0xe0]

vamoswapei64.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoswapei64.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x0c]

vamoswapei64.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoswapei64.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x08]

vamoaddei64.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoaddei64.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x04]

vamoaddei64.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoaddei64.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x00]

vamoxorei64.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoxorei64.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x24]

vamoxorei64.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoxorei64.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x20]

vamoandei64.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoandei64.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x64]

vamoandei64.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoandei64.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x60]

vamoorei64.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoorei64.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x44]

vamoorei64.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamoorei64.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x40]

vamominei64.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamominei64.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x84]

vamominei64.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamominei64.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x80]

vamomaxei64.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamomaxei64.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0xa4]

vamomaxei64.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamomaxei64.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0xa0]

vamominuei64.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamominuei64.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0xc4]

vamominuei64.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamominuei64.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0xc0]

vamomaxuei64.v	v0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamomaxuei64.v	v0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0xe4]

vamomaxuei64.v	x0, (a1), v2, v0, v0.t 
# CHECK-ASM-AND-OBJ: vamomaxuei64.v	x0,  0(a1), v2, v0, v0.t 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0xe0]

vwadd.vx	v0, v1, zero, v0.t 
# CHECK-ASM-AND-OBJ: vwadd.vx	v0, v1, zero, v0.t 
# CHECK-ASM: encoding:  [0x57,0x60,0x10,0xc4]

vwaddu.vx	v0, v1, zero, v0.t 
# CHECK-ASM-AND-OBJ: vwaddu.vx	v0, v1, zero, v0.t 
# CHECK-ASM: encoding:  [0x57,0x60,0x10,0xc0]

vxor.vi	v0, v1, -1, v0.t        
# CHECK-ASM-AND-OBJ: vxor.vi	v0, v1, -1, v0.t        
# CHECK-ASM: encoding:  [0x57,0xb0,0x1f,0x2c]

vmslt.vv	v0, v2, v1, v0.t 
# CHECK-ASM-AND-OBJ: vmslt.vv	v0, v2, v1, v0.t 
# CHECK-ASM: encoding:  [0x57,0x80,0x20,0x6c]

vmsltu.vv	v0, v2, v1, v0.t 
# CHECK-ASM-AND-OBJ: vmsltu.vv	v0, v2, v1, v0.t 
# CHECK-ASM: encoding:  [0x57,0x80,0x20,0x68]

vmsle.vv	v0, v2, v1, v0.t 
# CHECK-ASM-AND-OBJ: vmsle.vv	v0, v2, v1, v0.t 
# CHECK-ASM: encoding:  [0x57,0x80,0x20,0x74]

vmsleu.vv	v0, v2, v1, v0.t 
# CHECK-ASM-AND-OBJ: vmsleu.vv	v0, v2, v1, v0.t 
# CHECK-ASM: encoding:  [0x57,0x80,0x20,0x70]

vmflt.vv	v0, v2, v1, v0.t 
# CHECK-ASM-AND-OBJ: vmflt.vv	v0, v2, v1, v0.t 
# CHECK-ASM: encoding:  [0x57,0x90,0x20,0x6c]

vmfle.vv	v0, v2, v1, v0.t 
# CHECK-ASM-AND-OBJ: vmfle.vv	v0, v2, v1, v0.t 
# CHECK-ASM: encoding:  [0x57,0x90,0x20,0x64]

vmsle.vi	v0, v1, 3, v0.t 
# CHECK-ASM-AND-OBJ: vmsle.vi	v0, v1, 3, v0.t 
# CHECK-ASM: encoding:  [0x57,0xb0,0x11,0x74]

vmsleu.vi	v0, v1, 3, v0.t 
# CHECK-ASM-AND-OBJ: vmsleu.vi	v0, v1, 3, v0.t 
# CHECK-ASM: encoding:  [0x57,0xb0,0x11,0x70]

vmsgt.vi	v0, v1, 3, v0.t 
# CHECK-ASM-AND-OBJ: vmsgt.vi	v0, v1, 3, v0.t 
# CHECK-ASM: encoding:  [0x57,0xb0,0x11,0x7c]

vmsgtu.vi	v0, v1, 3, v0.t 
# CHECK-ASM-AND-OBJ: vmsgtu.vi	v0, v1, 3, v0.t 
# CHECK-ASM: encoding:  [0x57,0xb0,0x11,0x78]

vmsgt.vi	v0, v1, 3, v0.t 
# CHECK-ASM-AND-OBJ: vmsgt.vi	v0, v1, 3, v0.t 
# CHECK-ASM: encoding:  [0x57,0xb0,0x11,0x7c]

vmsgtu.vi	v0, v1, 3, v0.t 
# CHECK-ASM-AND-OBJ: vmsgtu.vi	v0, v1, 3, v0.t 
# CHECK-ASM: encoding:  [0x57,0xb0,0x11,0x78]

vmslt.vx	v3, v1, a2      
# CHECK-ASM-AND-OBJ: vmslt.vx	v3, v1, a2      
# CHECK-ASM: encoding:  [0xd7,0x41,0x16,0x6e]

vmandnot.mm	v0, v0, v3      
# CHECK-ASM-AND-OBJ: vmandnot.mm	v0, v0, v3      
# CHECK-ASM: encoding:  [0x57,0xa0,0x01,0x62]

vmsltu.vx	v3, v1, a2      
# CHECK-ASM-AND-OBJ: vmsltu.vx	v3, v1, a2      
# CHECK-ASM: encoding:  [0xd7,0x41,0x16,0x6a]

vmandnot.mm	v0, v0, v3      
# CHECK-ASM-AND-OBJ: vmandnot.mm	v0, v0, v3      
# CHECK-ASM: encoding:  [0x57,0xa0,0x01,0x62]

# CHECK-ASM-AND-OBJ: addi   t0, a2, -1
#                    vmsgt.vx v0, v1, t0, v0.t
# CHECK-ASM: encoding: [0x93,0x02,0xf6,0xff]
#            encoding: [0x57,0xb0,0x11,0x7c]
vmsge.vx v0, v1, a2, v0.t

# CHECK-ASM-AND-OBJ: addi   t0, a2, -1
#                    vmsgtu.vx v0, v1, t0, v0.t
# CHECK-ASM: encoding: [0x93,0x02,0xf6,0xff]
#            encoding: [0x57,0xb0,0x11,0x78]
vmsgeu.vx v0, v1, a2, v0.t

# CHECK-ASM-AND-OBJ: vmslt.vx  v3, v1, a2
#                    vmandnot.mm  v0, v0, v3
# CHECK-ASM: encoding: [0xd7,0x41,0x16,0x6e]
#            encoding: [0x57,0xa0,0x01,0x62]
vmsge.vx v0, v1, a2, v0.t, v3

# CHECK-ASM-AND-OBJ: vmsltu.vx  v3, v1, a2
#                    vmandnot.mm  v0, v0, v3
# CHECK-ASM: encoding: [0xd7,0x41,0x16,0x6a]
#            encoding: [0x57,0xa0,0x01,0x62]
vmsgeu.vx v0, v1, a2, v0.t, v3

vle128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vle128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x10]

  vle256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vle256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x10]

  vle512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vle512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x10]

  vle1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vle1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x10]

  vlseg2e128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg2e128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x30]

  vlseg2e256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg2e256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x30]

  vlseg2e512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg2e512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x30]

  vlseg2e1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg2e1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x30]

  vlseg3e128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg3e128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x50]

  vlseg3e256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg3e256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x50]

  vlseg3e512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg3e512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x50]

  vlseg3e1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg3e1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x50]

  vlseg4e128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg4e128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x70]

  vlseg4e256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg4e256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x70]

  vlseg4e512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg4e512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x70]

  vlseg4e1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg4e1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x70]

  vlseg5e128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg5e128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x90]

  vlseg5e256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg5e256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x90]

  vlseg5e512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg5e512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x90]

  vlseg5e1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg5e1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x90]

  vlseg6e128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg6e128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xb0]

  vlseg6e256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg6e256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xb0]

  vlseg6e512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg6e512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xb0]

  vlseg6e1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg6e1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xb0]

  vlseg7e128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg7e128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xd0]

  vlseg7e256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg7e256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xd0]

  vlseg7e512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg7e512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xd0]

  vlseg7e1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg7e1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xd0]

  vlseg8e128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg8e128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xf0]

  vlseg8e256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg8e256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xf0]

  vlseg8e512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg8e512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xf0]

  vlseg8e1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vlseg8e1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xf0]

  vlxei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x1c]

  vlxei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x1c]

  vlxei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x1c]

  vlxei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x1c]

  vlxseg2ei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg2ei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x3c]

  vlxseg2ei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg2ei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x3c]

  vlxseg2ei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg2ei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x3c]

  vlxseg2ei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg2ei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x3c]

  vlxseg3ei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg3ei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x5c]

  vlxseg3ei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg3ei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x5c]

  vlxseg3ei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg3ei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x5c]

  vlxseg3ei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg3ei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x5c]

  vlxseg4ei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg4ei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x7c]

  vlxseg4ei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg4ei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x7c]

  vlxseg4ei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg4ei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x7c]

  vlxseg4ei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg4ei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x7c]

  vlxseg5ei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg5ei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x9c]

  vlxseg5ei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg5ei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x9c]

  vlxseg5ei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg5ei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x9c]

  vlxseg5ei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg5ei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x9c]

  vlxseg6ei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg6ei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xbc]

  vlxseg6ei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg6ei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xbc]

  vlxseg6ei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg6ei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xbc]

  vlxseg6ei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg6ei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0xbc]

  vlxseg7ei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg7ei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xdc]

  vlxseg7ei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg7ei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xdc]

  vlxseg7ei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg7ei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xdc]

  vlxseg7ei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg7ei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0xdc]

  vlxseg8ei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg8ei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xfc]

  vlxseg8ei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg8ei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xfc]

  vlxseg8ei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg8ei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xfc]

  vlxseg8ei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vlxseg8ei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0xfc]

  vlse128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlse128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x18]

  vlse256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlse256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x18]

  vlse512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlse512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x18]

  vlse1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlse1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x18]

  vlsseg2e128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg2e128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x38]

  vlsseg2e256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg2e256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x38]

  vlsseg2e512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg2e512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x38]

  vlsseg2e1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg2e1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x38]

  vlsseg3e128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg3e128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x58]

  vlsseg3e256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg3e256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x58]

  vlsseg3e512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg3e512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x58]

  vlsseg3e1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg3e1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x58]

  vlsseg4e128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg4e128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x78]

  vlsseg4e256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg4e256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x78]

  vlsseg4e512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg4e512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x78]

  vlsseg4e1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg4e1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x78]

  vlsseg5e128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg5e128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x98]

  vlsseg5e256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg5e256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x98]

  vlsseg5e512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg5e512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x98]

  vlsseg5e1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg5e1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x98]

  vlsseg6e128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg6e128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xb8]

  vlsseg6e256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg6e256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xb8]

  vlsseg6e512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg6e512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xb8]

  vlsseg6e1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg6e1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0xb8]

  vlsseg7e128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg7e128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xd8]

  vlsseg7e256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg7e256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xd8]

  vlsseg7e512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg7e512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xd8]

  vlsseg7e1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg7e1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0xd8]

  vlsseg8e128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg8e128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xf8]

  vlsseg8e256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg8e256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xf8]

  vlsseg8e512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg8e512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xf8]

  vlsseg8e1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vlsseg8e1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0xf8]

  vse128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vse128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x10]

  vse256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vse256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x10]

  vse512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vse512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x10]

  vse1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vse1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x10]

  vsseg2e128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg2e128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x30]

  vsseg2e256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg2e256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x30]

  vsseg2e512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg2e512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x30]

  vsseg2e1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg2e1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x30]

  vsseg3e128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg3e128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x50]

  vsseg3e256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg3e256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x50]

  vsseg3e512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg3e512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x50]

  vsseg3e1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg3e1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x50]

  vsseg4e128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg4e128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x70]

  vsseg4e256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg4e256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x70]

  vsseg4e512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg4e512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x70]

  vsseg4e1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg4e1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x70]

  vsseg5e128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg5e128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x90]

  vsseg5e256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg5e256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x90]

  vsseg5e512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg5e512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x90]

  vsseg5e1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg5e1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x90]

  vsseg6e128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg6e128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0xb0]

  vsseg6e256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg6e256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0xb0]

  vsseg6e512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg6e512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0xb0]

  vsseg6e1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg6e1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0xb0]

  vsseg7e128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg7e128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0xd0]

  vsseg7e256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg7e256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0xd0]

  vsseg7e512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg7e512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0xd0]

  vsseg7e1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg7e1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0xd0]

  vsseg8e128.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg8e128.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0xf0]

  vsseg8e256.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg8e256.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0xf0]

  vsseg8e512.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg8e512.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0xf0]

  vsseg8e1024.v v0, (a1), v0.t
# CHECK-ASM-AND-OBJ: 	vsseg8e1024.v v0, 0(a1), v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0xf0]

  vsxei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x1c]

  vsxei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x1c]

  vsxei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x1c]

  vsxei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x1c]

  vsxseg2ei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg2ei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x3c]

  vsxseg2ei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg2ei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x3c]

  vsxseg2ei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg2ei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x3c]

  vsxseg2ei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg2ei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x3c]

  vsxseg3ei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg3ei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x5c]

  vsxseg3ei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg3ei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x5c]

  vsxseg3ei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg3ei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x5c]

  vsxseg3ei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg3ei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x5c]

  vsxseg4ei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg4ei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x7c]

  vsxseg4ei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg4ei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x7c]

  vsxseg4ei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg4ei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x7c]

  vsxseg4ei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg4ei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x7c]

  vsxseg5ei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg5ei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x9c]

  vsxseg5ei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg5ei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x9c]

  vsxseg5ei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg5ei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x9c]

  vsxseg5ei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg5ei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x9c]

  vsxseg6ei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg6ei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0xbc]

  vsxseg6ei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg6ei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0xbc]

  vsxseg6ei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg6ei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0xbc]

  vsxseg6ei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg6ei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0xbc]

  vsxseg7ei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg7ei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0xdc]

  vsxseg7ei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg7ei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0xdc]

  vsxseg7ei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg7ei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0xdc]

  vsxseg7ei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg7ei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0xdc]

  vsxseg8ei128.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg8ei128.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0xfc]

  vsxseg8ei256.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg8ei256.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0xfc]

  vsxseg8ei512.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg8ei512.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0xfc]

  vsxseg8ei1024.v v0, (a1), v2, v0.t
# CHECK-ASM-AND-OBJ: 	vsxseg8ei1024.v v0, 0(a1), v2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0xfc]

  vsse128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vsse128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x18]

  vsse256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vsse256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x18]

  vsse512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vsse512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x18]

  vsse1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vsse1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x18]

  vssseg2e128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg2e128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x38]

  vssseg2e256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg2e256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x38]

  vssseg2e512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg2e512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x38]

  vssseg2e1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg2e1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x38]

  vssseg3e128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg3e128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x58]

  vssseg3e256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg3e256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x58]

  vssseg3e512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg3e512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x58]

  vssseg3e1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg3e1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x58]

  vssseg4e128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg4e128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x78]

  vssseg4e256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg4e256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x78]

  vssseg4e512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg4e512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x78]

  vssseg4e1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg4e1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x78]

  vssseg5e128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg5e128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x98]

  vssseg5e256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg5e256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x98]

  vssseg5e512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg5e512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x98]

  vssseg5e1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg5e1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x98]

  vssseg6e128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg6e128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xb8]

  vssseg6e256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg6e256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xb8]

  vssseg6e512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg6e512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xb8]

  vssseg6e1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg6e1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xb8]

  vssseg7e128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg7e128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xd8]

  vssseg7e256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg7e256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xd8]

  vssseg7e512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg7e512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xd8]

  vssseg7e1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg7e1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xd8]

  vssseg8e128.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg8e128.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xf8]

  vssseg8e256.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg8e256.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xf8]

  vssseg8e512.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg8e512.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xf8]

  vssseg8e1024.v v0, (a1), a2, v0.t
# CHECK-ASM-AND-OBJ: 	vssseg8e1024.v v0, 0(a1), a2, v0.t
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xf8]


