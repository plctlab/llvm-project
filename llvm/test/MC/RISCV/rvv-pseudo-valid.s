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

vsetvli	a0, a1, e8,m1,tu,mu     
# CHECK-ASM-AND-OBJ: vsetvli	a0, a1, e8,m1,tu,mu     
# CHECK-ASM: encoding:  [0x57,0xf5,0x05,0x00]

vsetvli	a0, a1, 0x7ff
# CHECK-ASM-AND-OBJ: vsetvli a0, a1, e1024,mf8,ta,ma
# CHECK-ASM: encoding:  [0x57,0xf5,0xf5,0x7f]

vle128.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vle128.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x12]

vle256.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vle256.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x12]

vle512.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vle512.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x12]

vle8.v	v0, (a1)               
# CHECK-ASM-AND-OBJ: vle8.v	v0, 0(a1)               
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x02]

vle16.v	v0, (a1)               
# CHECK-ASM-AND-OBJ: vle16.v	v0, 0(a1)               
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x02]

vle32.v	v0, (a1)               
# CHECK-ASM-AND-OBJ: vle32.v	v0, 0(a1)               
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x02]

vle64.v	v0, (a1)               
# CHECK-ASM-AND-OBJ: vle64.v	v0, 0(a1)               
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x02]

vse8.v	v0, (a1)               
# CHECK-ASM-AND-OBJ: vse8.v	v0, 0(a1)               
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x02]

vse16.v	v0, (a1)               
# CHECK-ASM-AND-OBJ: vse16.v	v0, 0(a1)               
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x02]

vse32.v	v0, (a1)               
# CHECK-ASM-AND-OBJ: vse32.v	v0, 0(a1)               
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x02]

vse64.v	v0, (a1)               
# CHECK-ASM-AND-OBJ: vse64.v	v0, 0(a1)               
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x02]

vlse128.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlse128.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x1a]

vlse256.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlse256.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x1a]

vlse512.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlse512.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x1a]

vlse8.v	v0, (a1), a2           
# CHECK-ASM-AND-OBJ: vlse8.v	v0, 0(a1), a2           
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x0a]

vlse16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlse16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x0a]

vlse32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlse32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x0a]

vlse64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlse64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x0a]

vsse8.v	v0, (a1), a2           
# CHECK-ASM-AND-OBJ: vsse8.v	v0, 0(a1), a2           
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x0a]

vsse16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vsse16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x0a]

vsse32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vsse32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x0a]

vsse64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vsse64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x0a]

vlxei128.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxei128.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x1e]

vlxei256.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxei256.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x1e]

vlxei512.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxei512.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x1e]

vlxei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x0e]

vlxei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x0e]

vlxei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x0e]

vlxei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x0e]

vsxei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x0e]

vsxei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x0e]

vsxei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x0e]

vsxei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x0e]

vsxei128.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxei128.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x1e]

vsxei256.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxei256.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x1e]

vsxei512.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxei512.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x1e]

vsxei1024.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxei1024.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x1e]

vle128ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vle128ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x13]

vle256ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vle256ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x13]

vle512ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vle512ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x13]

vle8ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vle8ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x03]

vle16ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vle16ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x03]

vle32ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vle32ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x03]

vle64ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vle64ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x03]

vlseg2e128.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg2e128.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x32]

vlseg2e256.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg2e256.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x32]

vlseg2e512.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg2e512.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x32]

vlseg2e8.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg2e8.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x22]

vlseg2e16.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg2e16.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x22]

vlseg2e32.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg2e32.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x22]

vlseg2e64.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg2e64.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x22]

vsseg2e8.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg2e8.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x22]

vsseg2e16.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg2e16.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x22]

vsseg2e32.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg2e32.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x22]

vsseg2e64.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg2e64.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x22]

vlseg3e128.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg3e128.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x52]

vlseg3e256.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg3e256.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x52]

vlseg3e512.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg3e512.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x52]

vlseg3e8.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg3e8.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x42]

vlseg3e16.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg3e16.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x42]

vlseg3e32.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg3e32.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x42]

vlseg3e64.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg3e64.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x42]

vsseg3e8.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg3e8.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x42]

vsseg3e16.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg3e16.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x42]

vsseg3e32.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg3e32.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x42]

vsseg3e64.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg3e64.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x42]

vlseg4e128.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg4e128.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x72]

vlseg4e256.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg4e256.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x72]

vlseg4e512.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg4e512.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x72]

vlseg4e8.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg4e8.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x62]

vlseg4e16.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg4e16.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x62]

vlseg4e32.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg4e32.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x62]

vlseg4e64.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg4e64.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x62]

vsseg4e8.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg4e8.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x62]

vsseg4e16.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg4e16.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x62]

vsseg4e32.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg4e32.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x62]

vsseg4e64.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg4e64.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x62]

vlseg5e128.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg5e128.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x92]

vlseg5e256.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg5e256.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x92]

vlseg5e512.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg5e512.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x92]

vlseg5e8.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg5e8.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x82]

vlseg5e16.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg5e16.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x82]

vlseg5e32.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg5e32.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x82]

vlseg5e64.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg5e64.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x82]

vsseg5e8.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg5e8.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x82]

vsseg5e16.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg5e16.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x82]

vsseg5e32.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg5e32.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x82]

vsseg5e64.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg5e64.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x82]

vlseg6e128.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg6e128.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xb2]

vlseg6e256.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg6e256.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xb2]

vlseg6e512.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg6e512.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xb2]

vlseg6e8.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg6e8.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xa2]

vlseg6e16.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg6e16.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xa2]

vlseg6e32.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg6e32.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xa2]

vlseg6e64.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg6e64.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xa2]

vsseg6e8.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg6e8.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0xa2]

vsseg6e16.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg6e16.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0xa2]

vsseg6e32.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg6e32.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0xa2]

vsseg6e64.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg6e64.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0xa2]

vlseg7e128.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg7e128.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xd2]

vlseg7e256.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg7e256.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xd2]

vlseg7e512.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg7e512.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xd2]

vlseg7e8.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg7e8.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xc2]

vlseg7e16.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg7e16.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xc2]

vlseg7e32.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg7e32.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xc2]

vlseg7e64.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg7e64.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xc2]

vsseg7e8.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg7e8.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0xc2]

vsseg7e16.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg7e16.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0xc2]

vsseg7e32.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg7e32.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0xc2]

vsseg7e64.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg7e64.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0xc2]

vlseg8e128.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg8e128.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xf2]

vlseg8e256.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg8e256.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xf2]

vlseg8e512.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg8e512.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xf2]

vlseg8e8.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg8e8.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xe2]

vlseg8e16.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg8e16.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xe2]

vlseg8e32.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg8e32.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xe2]

vlseg8e64.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg8e64.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xe2]

vsseg8e8.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg8e8.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0xe2]

vsseg8e16.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg8e16.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0xe2]

vsseg8e32.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg8e32.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0xe2]

vsseg8e64.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vsseg8e64.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0xe2]

vlsseg2e128.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg2e128.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x3a]

vlsseg2e256.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg2e256.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x3a]

vlsseg2e512.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg2e512.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x3a]

vlsseg2e8.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg2e8.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x2a]

vlsseg2e16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg2e16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x2a]

vlsseg2e32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg2e32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x2a]

vlsseg2e64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg2e64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x2a]

vssseg2e8.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg2e8.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x2a]

vssseg2e16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg2e16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x2a]

vssseg2e32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg2e32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x2a]

vssseg2e64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg2e64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x2a]

vssseg2e128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ:  vssseg2e128.v	v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x3a]

vssseg2e256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ:  vssseg2e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x3a]

vssseg2e512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ:  vssseg2e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x3a]

vssseg2e1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ:  vssseg2e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x3a]

vlsseg3e128.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg3e128.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x5a]

vlsseg3e256.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg3e256.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x5a]

vlsseg3e512.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg3e512.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x5a]

vlsseg3e8.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg3e8.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x4a]

vlsseg3e16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg3e16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x4a]

vlsseg3e32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg3e32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x4a]

vlsseg3e64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg3e64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x4a]

vssseg3e8.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg3e8.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x4a]

vssseg3e16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg3e16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x4a]

vssseg3e32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg3e32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x4a]

vssseg3e64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg3e64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x4a]

vssseg3e128.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg3e128.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x5a]

vssseg3e256.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg3e256.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x5a]

vssseg3e512.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg3e512.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x5a]

vssseg3e1024.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg3e1024.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x5a]

vlsseg4e128.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg4e128.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x7a]

vlsseg4e256.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg4e256.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x7a]

vlsseg4e512.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg4e512.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x7a]

vlsseg4e8.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg4e8.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x6a]

vlsseg4e16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg4e16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x6a]

vlsseg4e32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg4e32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x6a]

vlsseg4e64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg4e64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x6a]

vssseg4e8.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg4e8.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x6a]

vssseg4e16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg4e16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x6a]

vssseg4e32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg4e32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x6a]

vssseg4e64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg4e64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x6a]

vssseg4e128.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg4e128.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x7a]

vssseg4e256.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg4e256.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x7a]

vssseg4e512.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg4e512.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x7a]

vssseg4e1024.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg4e1024.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x7a]

vlsseg5e128.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg5e128.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x9a]

vlsseg5e256.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg5e256.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x9a]

vlsseg5e512.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg5e512.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x9a]

vlsseg5e8.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg5e8.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x8a]

vlsseg5e16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg5e16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x8a]

vlsseg5e32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg5e32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x8a]

vlsseg5e64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg5e64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x8a]

vssseg5e8.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg5e8.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x8a]

vssseg5e16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg5e16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x8a]

vssseg5e32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg5e32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x8a]

vssseg5e64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg5e64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x8a]

vssseg5e128.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg5e128.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x9a]

vssseg5e256.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg5e256.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x9a]

vssseg5e512.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg5e512.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x9a]

vssseg5e1024.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg5e1024.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x9a]

vlsseg6e128.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg6e128.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xba]

vlsseg6e256.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg6e256.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xba]

vlsseg6e512.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg6e512.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xba]

vlsseg6e8.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg6e8.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xaa]

vlsseg6e16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg6e16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xaa]

vlsseg6e32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg6e32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xaa]

vlsseg6e64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg6e64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0xaa]

vssseg6e8.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg6e8.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xaa]

vssseg6e16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg6e16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xaa]

vssseg6e32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg6e32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xaa]

vssseg6e64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg6e64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xaa]

vssseg6e128.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg6e128.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xba]

vssseg6e256.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg6e256.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xba]

vssseg6e512.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg6e512.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xba]

vssseg6e1024.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg6e1024.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xba]

vlsseg7e128.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg7e128.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xda]

vlsseg7e256.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg7e256.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xda]

vlsseg7e512.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg7e512.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xda]

vlsseg7e8.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg7e8.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xca]

vlsseg7e16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg7e16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xca]

vlsseg7e32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg7e32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xca]

vlsseg7e64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg7e64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0xca]

vssseg7e8.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg7e8.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xca]

vssseg7e16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg7e16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xca]

vssseg7e32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg7e32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xca]

vssseg7e64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg7e64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xca]

vssseg7e128.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg7e128.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xda]

vssseg7e256.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg7e256.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xda]

vssseg7e512.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg7e512.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xda]

vssseg7e1024.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg7e1024.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xda]

vlsseg8e128.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg8e128.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xfa]

vlsseg8e256.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg8e256.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xfa]

vlsseg8e512.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg8e512.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xfa]

vlsseg8e8.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg8e8.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xea]

vlsseg8e16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg8e16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xea]

vlsseg8e32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg8e32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xea]

vlsseg8e64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vlsseg8e64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0xea]

vssseg8e8.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg8e8.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xea]

vssseg8e16.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg8e16.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xea]

vssseg8e32.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg8e32.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xea]

vssseg8e64.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: vssseg8e64.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xea]

vssseg8e128.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg8e128.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xfa]

vssseg8e256.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg8e256.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xfa]

vssseg8e512.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg8e512.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xfa]

vssseg8e1024.v	v0, (a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg8e1024.v	v0, 0(a1), a2   
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xfa]

vlxseg2ei128.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg2ei128.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x3e]

vlxseg2ei256.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg2ei256.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x3e]

vlxseg2ei512.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg2ei512.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x3e]

vlxseg2ei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg2ei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x2e]

vlxseg2ei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg2ei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x2e]

vlxseg2ei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg2ei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x2e]

vlxseg2ei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg2ei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x2e]

vsxseg2ei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg2ei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x2e]

vsxseg2ei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg2ei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x2e]

vsxseg2ei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg2ei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x2e]

vsxseg2ei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg2ei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x2e]

vlxseg3ei128.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg3ei128.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x5e]

vlxseg3ei256.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg3ei256.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x5e]

vlxseg3ei512.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg3ei512.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x5e]

vlxseg3ei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg3ei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x4e]

vlxseg3ei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg3ei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x4e]

vlxseg3ei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg3ei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x4e]

vlxseg3ei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg3ei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x4e]

vsxseg3ei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg3ei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x4e]

vsxseg3ei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg3ei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x4e]

vsxseg3ei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg3ei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x4e]

vsxseg3ei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg3ei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x4e]

vlxseg4ei128.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg4ei128.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x7e]

vlxseg4ei256.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg4ei256.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x7e]

vlxseg4ei512.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg4ei512.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x7e]

vlxseg4ei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg4ei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x6e]

vlxseg4ei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg4ei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x6e]

vlxseg4ei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg4ei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x6e]

vlxseg4ei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg4ei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x6e]

vsxseg4ei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg4ei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x6e]

vsxseg4ei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg4ei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x6e]

vsxseg4ei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg4ei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x6e]

vsxseg4ei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg4ei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x6e]

vlxseg5ei128.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg5ei128.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x9e]

vlxseg5ei256.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg5ei256.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x9e]

vlxseg5ei512.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg5ei512.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x9e]

vlxseg5ei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg5ei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x8e]

vlxseg5ei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg5ei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x8e]

vlxseg5ei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg5ei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x8e]

vlxseg5ei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg5ei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x8e]

vsxseg5ei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg5ei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x8e]

vsxseg5ei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg5ei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x8e]

vsxseg5ei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg5ei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x8e]

vsxseg5ei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg5ei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x8e]

vlxseg6ei128.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg6ei128.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xbe]

vlxseg6ei256.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg6ei256.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xbe]

vlxseg6ei512.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg6ei512.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xbe]

vlxseg6ei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg6ei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xae]

vlxseg6ei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg6ei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xae]

vlxseg6ei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg6ei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xae]

vlxseg6ei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg6ei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0xae]

vsxseg6ei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg6ei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0xae]

vsxseg6ei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg6ei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0xae]

vsxseg6ei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg6ei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0xae]

vsxseg6ei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg6ei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0xae]

vlxseg7ei128.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg7ei128.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xde]

vlxseg7ei256.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg7ei256.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xde]

vlxseg7ei512.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg7ei512.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xde]

vlxseg7ei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg7ei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xce]

vlxseg7ei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg7ei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xce]

vlxseg7ei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg7ei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xce]

vlxseg7ei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg7ei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0xce]

vsxseg7ei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg7ei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0xce]

vsxseg7ei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg7ei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0xce]

vsxseg7ei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg7ei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0xce]

vsxseg7ei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg7ei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0xce]

vlxseg8ei128.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg8ei128.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xfe]

vlxseg8ei256.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg8ei256.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xfe]

vlxseg8ei512.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg8ei512.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xfe]

vlxseg8ei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg8ei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xee]

vlxseg8ei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg8ei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xee]

vlxseg8ei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg8ei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xee]

vlxseg8ei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vlxseg8ei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0xee]

vsxseg8ei8.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg8ei8.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0xee]

vsxseg8ei16.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg8ei16.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0xee]

vsxseg8ei32.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg8ei32.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0xee]

vsxseg8ei64.v	v0, (a1), v2   
# CHECK-ASM-AND-OBJ: vsxseg8ei64.v	v0, 0(a1), v2   
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0xee]

vlseg2e128ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg2e128ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x33]

vlseg2e256ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg2e256ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x33]

vlseg2e512ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg2e512ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x33]

vlseg2e8ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg2e8ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x23]

vlseg2e16ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg2e16ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x23]

vlseg2e32ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg2e32ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x23]

vlseg2e64ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg2e64ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x23]

vlseg3e128ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg3e128ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x53]

vlseg3e256ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg3e256ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x53]

vlseg3e512ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg3e512ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x53]

vlseg3e8ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg3e8ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x43]

vlseg3e16ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg3e16ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x43]

vlseg3e32ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg3e32ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x43]

vlseg3e64ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg3e64ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x43]

vlseg4e128ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg4e128ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x73]

vlseg4e256ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg4e256ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x73]

vlseg4e512ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg4e512ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x73]

vlseg4e8ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg4e8ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x63]

vlseg4e16ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg4e16ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x63]

vlseg4e32ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg4e32ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x63]

vlseg4e64ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg4e64ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x63]

vlseg5e128ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg5e128ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x93]

vlseg5e256ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg5e256ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x93]

vlseg5e512ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg5e512ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x93]

vlseg5e8ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg5e8ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x83]

vlseg5e16ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg5e16ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x83]

vlseg5e32ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg5e32ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x83]

vlseg5e64ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg5e64ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x83]

vlseg6e128ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg6e128ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xb3]

vlseg6e256ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg6e256ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xb3]

vlseg6e512ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg6e512ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xb3]

vlseg6e8ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg6e8ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xa3]

vlseg6e16ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg6e16ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xa3]

vlseg6e32ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg6e32ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xa3]

vlseg6e64ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg6e64ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xa3]

vlseg7e128ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg7e128ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xd3]

vlseg7e256ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg7e256ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xd3]

vlseg7e512ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg7e512ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xd3]

vlseg7e8ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg7e8ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xc3]

vlseg7e16ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg7e16ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xc3]

vlseg7e32ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg7e32ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xc3]

vlseg7e64ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg7e64ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xc3]

vlseg8e128ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg8e128ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xf3]

vlseg8e256ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg8e256ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xf3]

vlseg8e512ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg8e512ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xf3]

vlseg8e8ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg8e8ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xe3]

vlseg8e16ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg8e16ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xe3]

vlseg8e32ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg8e32ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xe3]

vlseg8e64ff.v	v0, (a1)       
# CHECK-ASM-AND-OBJ: vlseg8e64ff.v	v0, 0(a1)       
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xe3]

vl1r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vl1r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0x87,0x81,0x85,0x02]

vs1r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vs1r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0xa7,0x81,0x85,0x02]

vl2r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vl2r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0x87,0x81,0x85,0x22]

vs2r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vs2r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0xa7,0x81,0x85,0x22]

vl3r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vl3r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0x87,0x81,0x85,0x42]

vs3r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vs3r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0xa7,0x81,0x85,0x42]

vl4r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vl4r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0x87,0x81,0x85,0x62]

vs4r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vs4r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0xa7,0x81,0x85,0x62]

vl5r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vl5r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0x87,0x81,0x85,0x82]

vs5r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vs5r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0xa7,0x81,0x85,0x82]

vl6r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vl6r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0x87,0x81,0x85,0xa2]

vs6r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vs6r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0xa7,0x81,0x85,0xa2]

vl7r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vl7r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0x87,0x81,0x85,0xc2]

vs7r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vs7r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0xa7,0x81,0x85,0xc2]

vl8r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vl8r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0x87,0x81,0x85,0xe2]

vs8r.v	v3, (a1)               
# CHECK-ASM-AND-OBJ: vs8r.v	v3, 0(a1)               
# CHECK-ASM: encoding:  [0xa7,0x81,0x85,0xe2]

vamoswapei32.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoswapei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x0e]

vamoswapei32.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoswapei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x0a]

vamoaddei32.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoaddei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x06]

vamoaddei32.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoaddei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x02]

vamoxorei32.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoxorei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x26]

vamoxorei32.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoxorei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x22]

vamoandei32.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoandei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x66]

vamoandei32.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoandei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x62]

vamoorei32.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoorei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x46]

vamoorei32.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoorei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x42]

vamominei32.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamominei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x86]

vamominei32.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamominei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0x82]

vamomaxei32.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamomaxei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0xa6]

vamomaxei32.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamomaxei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0xa2]

vamominuei32.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamominuei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0xc6]

vamominuei32.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamominuei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0xc2]

vamomaxuei32.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamomaxuei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0xe6]

vamomaxuei32.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamomaxuei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xe0,0x25,0xe2]

vamoswapei64.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoswapei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x0e]

vamoswapei64.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoswapei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x0a]

vamoaddei64.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoaddei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x06]

vamoaddei64.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoaddei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x02]

vamoxorei64.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoxorei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x26]

vamoxorei64.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoxorei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x22]

vamoandei64.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoandei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x66]

vamoandei64.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoandei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x62]

vamoorei64.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoorei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x46]

vamoorei64.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamoorei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x42]

vamominei64.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamominei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x86]

vamominei64.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamominei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0x82]

vamomaxei64.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamomaxei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0xa6]

vamomaxei64.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamomaxei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0xa2]

vamominuei64.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamominuei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0xc6]

vamominuei64.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamominuei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0xc2]

vamomaxuei64.v	v0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamomaxuei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0xe6]

vamomaxuei64.v	x0, (a1), v2, v0 
# CHECK-ASM-AND-OBJ: vamomaxuei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: encoding:  [0x2f,0xf0,0x25,0xe2]

vwadd.vx	v0, v1, zero    
# CHECK-ASM-AND-OBJ: vwadd.vx	v0, v1, zero    
# CHECK-ASM: encoding:  [0x57,0x60,0x10,0xc6]

vwaddu.vx	v0, v1, zero    
# CHECK-ASM-AND-OBJ: vwaddu.vx	v0, v1, zero    
# CHECK-ASM: encoding:  [0x57,0x60,0x10,0xc2]

vxor.vi	v0, v1, -1              
# CHECK-ASM-AND-OBJ: vxor.vi	v0, v1, -1              
# CHECK-ASM: encoding:  [0x57,0xb0,0x1f,0x2e]

vmslt.vv	v0, v2, v1      
# CHECK-ASM-AND-OBJ: vmslt.vv	v0, v2, v1      
# CHECK-ASM: encoding:  [0x57,0x80,0x20,0x6e]

vmsltu.vv	v0, v2, v1      
# CHECK-ASM-AND-OBJ: vmsltu.vv	v0, v2, v1      
# CHECK-ASM: encoding:  [0x57,0x80,0x20,0x6a]

vmsle.vv	v0, v2, v1      
# CHECK-ASM-AND-OBJ: vmsle.vv	v0, v2, v1      
# CHECK-ASM: encoding:  [0x57,0x80,0x20,0x76]

vmsleu.vv	v0, v2, v1      
# CHECK-ASM-AND-OBJ: vmsleu.vv	v0, v2, v1      
# CHECK-ASM: encoding:  [0x57,0x80,0x20,0x72]

vmflt.vv	v0, v2, v1      
# CHECK-ASM-AND-OBJ: vmflt.vv	v0, v2, v1      
# CHECK-ASM: encoding:  [0x57,0x90,0x20,0x6e]

vmfle.vv	v0, v2, v1      
# CHECK-ASM-AND-OBJ: vmfle.vv	v0, v2, v1      
# CHECK-ASM: encoding:  [0x57,0x90,0x20,0x66]

vmand.mm	v0, v1, v1      
# CHECK-ASM-AND-OBJ: vmand.mm	v0, v1, v1      
# CHECK-ASM: encoding:  [0x57,0xa0,0x10,0x66]

vmxor.mm	v0, v0, v0      
# CHECK-ASM-AND-OBJ: vmxor.mm	v0, v0, v0      
# CHECK-ASM: encoding:  [0x57,0x20,0x00,0x6e]

vmxnor.mm	v0, v0, v0      
# CHECK-ASM-AND-OBJ: vmxnor.mm	v0, v0, v0      
# CHECK-ASM: encoding:  [0x57,0x20,0x00,0x7e]

vmnand.mm	v0, v1, v1      
# CHECK-ASM-AND-OBJ: vmnand.mm	v0, v1, v1      
# CHECK-ASM: encoding:  [0x57,0xa0,0x10,0x76]

vmsle.vi	v0, v1, 3       
# CHECK-ASM-AND-OBJ: vmsle.vi	v0, v1, 3       
# CHECK-ASM: encoding:  [0x57,0xb0,0x11,0x76]

vmsleu.vi	v0, v1, 3       
# CHECK-ASM-AND-OBJ: vmsleu.vi	v0, v1, 3       
# CHECK-ASM: encoding:  [0x57,0xb0,0x11,0x72]

vmsgt.vi	v0, v1, 3       
# CHECK-ASM-AND-OBJ: vmsgt.vi	v0, v1, 3       
# CHECK-ASM: encoding:  [0x57,0xb0,0x11,0x7e]

vmsgtu.vi	v0, v1, 3       
# CHECK-ASM-AND-OBJ: vmsgtu.vi	v0, v1, 3       
# CHECK-ASM: encoding:  [0x57,0xb0,0x11,0x7a]

# CHECK-ASM-AND-OBJ: addi   t0, a2, -1
#                    vmsgt.vx v0, v1, t0
# CHECK-ASM: encoding: [0x93,0x02,0xf6,0xff]
#            encoding: [0x57,0xb0,0x11,0x7e]
vmsge.vx v0, v1, a2

# CHECK-ASM-AND-OBJ: addi   t0, a2, -1
#                    vmsgtu.vx v0, v1, t0
# CHECK-ASM: encoding: [0x93,0x02,0xf6,0xff]
#            encoding: [0x57,0xb0,0x11,0x7a]
vmsgeu.vx v0, v1, a2

vle128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vle128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x12]

  vle256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vle256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x12]

  vle512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vle512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x12]

  vle1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vle1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x12]

  vlseg2e128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg2e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x32]

  vlseg2e256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg2e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x32]

  vlseg2e512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg2e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x32]

  vlseg2e1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg2e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x32]

  vlseg3e128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg3e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x52]

  vlseg3e256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg3e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x52]

  vlseg3e512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg3e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x52]

  vlseg3e1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg3e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x52]

  vlseg4e128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg4e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x72]

  vlseg4e256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg4e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x72]

  vlseg4e512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg4e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x72]

  vlseg4e1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg4e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x72]

  vlseg5e128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg5e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x92]

  vlseg5e256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg5e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x92]

  vlseg5e512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg5e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x92]

  vlseg5e1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg5e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x92]

  vlseg6e128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg6e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xb2]

  vlseg6e256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg6e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xb2]

  vlseg6e512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg6e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xb2]

  vlseg6e1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg6e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xb2]

  vlseg7e128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg7e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xd2]

  vlseg7e256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg7e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xd2]

  vlseg7e512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg7e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xd2]

  vlseg7e1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg7e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xd2]

  vlseg8e128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg8e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xf2]

  vlseg8e256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg8e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xf2]

  vlseg8e512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg8e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xf2]

  vlseg8e1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vlseg8e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xf2]

  vlxei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x1e]

  vlxei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x1e]

  vlxei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x1e]

  vlxei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x1e]

  vlxseg2ei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg2ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x3e]

  vlxseg2ei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg2ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x3e]

  vlxseg2ei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg2ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x3e]

  vlxseg2ei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg2ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x3e]

  vlxseg3ei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg3ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x5e]

  vlxseg3ei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg3ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x5e]

  vlxseg3ei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg3ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x5e]

  vlxseg3ei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg3ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x5e]

  vlxseg4ei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg4ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x7e]

  vlxseg4ei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg4ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x7e]

  vlxseg4ei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg4ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x7e]

  vlxseg4ei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg4ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x7e]

  vlxseg5ei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg5ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x9e]

  vlxseg5ei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg5ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x9e]

  vlxseg5ei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg5ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x9e]

  vlxseg5ei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg5ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x9e]

  vlxseg6ei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg6ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xbe]

  vlxseg6ei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg6ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xbe]

  vlxseg6ei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg6ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xbe]

  vlxseg6ei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg6ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0xbe]

  vlxseg7ei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg7ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xde]

  vlxseg7ei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg7ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xde]

  vlxseg7ei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg7ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xde]

  vlxseg7ei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg7ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0xde]

  vlxseg8ei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg8ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xfe]

  vlxseg8ei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg8ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xfe]

  vlxseg8ei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg8ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xfe]

  vlxseg8ei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg8ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0xfe]

  vlse128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlse128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x1a]

  vlse256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlse256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x1a]

  vlse512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlse512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x1a]

  vlse1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlse1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x1a]

  vlsseg2e128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg2e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x3a]

  vlsseg2e256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg2e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x3a]

  vlsseg2e512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg2e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x3a]

  vlsseg2e1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg2e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x3a]

  vlsseg3e128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg3e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x5a]

  vlsseg3e256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg3e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x5a]

  vlsseg3e512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg3e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x5a]

  vlsseg3e1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg3e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x5a]

  vlsseg4e128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg4e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x7a]

  vlsseg4e256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg4e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x7a]

  vlsseg4e512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg4e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x7a]

  vlsseg4e1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg4e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x7a]

  vlsseg5e128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg5e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x9a]

  vlsseg5e256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg5e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x9a]

  vlsseg5e512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg5e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x9a]

  vlsseg5e1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg5e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x9a]

  vlsseg6e128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg6e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xba]

  vlsseg6e256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg6e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xba]

  vlsseg6e512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg6e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xba]

  vlsseg6e1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg6e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0xba]

  vlsseg7e128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg7e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xda]

  vlsseg7e256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg7e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xda]

  vlsseg7e512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg7e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xda]

  vlsseg7e1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg7e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0xda]

  vlsseg8e128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg8e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xfa]

  vlsseg8e256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg8e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xfa]

  vlsseg8e512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg8e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xfa]

  vlsseg8e1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg8e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0xfa]

  vse128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vse128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x12]

  vse256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vse256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x12]

  vse512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vse512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x12]

  vse1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vse1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x12]

  vsseg2e128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg2e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x32]

  vsseg2e256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg2e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x32]

  vsseg2e512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg2e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x32]

  vsseg2e1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg2e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x32]

  vsseg3e128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg3e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x52]

  vsseg3e256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg3e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x52]

  vsseg3e512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg3e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x52]

  vsseg3e1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg3e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x52]

  vsseg4e128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg4e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x72]

  vsseg4e256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg4e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x72]

  vsseg4e512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg4e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x72]

  vsseg4e1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg4e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x72]

  vsseg5e128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg5e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x92]

  vsseg5e256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg5e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x92]

  vsseg5e512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg5e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x92]

  vsseg5e1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg5e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x92]

  vsseg6e128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg6e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0xb2]

  vsseg6e256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg6e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0xb2]

  vsseg6e512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg6e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0xb2]

  vsseg6e1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg6e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0xb2]

  vsseg7e128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg7e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0xd2]

  vsseg7e256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg7e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0xd2]

  vsseg7e512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg7e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0xd2]

  vsseg7e1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg7e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0xd2]

  vsseg8e128.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg8e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0xf2]

  vsseg8e256.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg8e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0xf2]

  vsseg8e512.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg8e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0xf2]

  vsseg8e1024.v v0, (a1)
# CHECK-ASM-AND-OBJ: 	vsseg8e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0xf2]

  vsxei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x1e]

  vsxei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x1e]

  vsxei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x1e]

  vsxei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x1e]

  vsxseg2ei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg2ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x3e]

  vsxseg2ei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg2ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x3e]

  vsxseg2ei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg2ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x3e]

  vsxseg2ei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg2ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x3e]

  vsxseg3ei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg3ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x5e]

  vsxseg3ei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg3ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x5e]

  vsxseg3ei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg3ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x5e]

  vsxseg3ei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg3ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x5e]

  vsxseg4ei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg4ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x7e]

  vsxseg4ei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg4ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x7e]

  vsxseg4ei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg4ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x7e]

  vsxseg4ei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg4ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x7e]

  vsxseg5ei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg5ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x9e]

  vsxseg5ei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg5ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x9e]

  vsxseg5ei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg5ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x9e]

  vsxseg5ei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg5ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x9e]

  vsxseg6ei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg6ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0xbe]

  vsxseg6ei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg6ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0xbe]

  vsxseg6ei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg6ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0xbe]

  vsxseg6ei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg6ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0xbe]

  vsxseg7ei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg7ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0xde]

  vsxseg7ei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg7ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0xde]

  vsxseg7ei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg7ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0xde]

  vsxseg7ei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg7ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0xde]

  vsxseg8ei128.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg8ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0xfe]

  vsxseg8ei256.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg8ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0xfe]

  vsxseg8ei512.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg8ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0xfe]

  vsxseg8ei1024.v v0, (a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg8ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0xfe]

  vsse128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vsse128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x1a]

  vsse256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vsse256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x1a]

  vsse512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vsse512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x1a]

  vsse1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vsse1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x1a]

  vssseg2e128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg2e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x3a]

  vssseg2e256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg2e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x3a]

  vssseg2e512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg2e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x3a]

  vssseg2e1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg2e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x3a]

  vssseg3e128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg3e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x5a]

  vssseg3e256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg3e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x5a]

  vssseg3e512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg3e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x5a]

  vssseg3e1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg3e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x5a]

  vssseg4e128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg4e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x7a]

  vssseg4e256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg4e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x7a]

  vssseg4e512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg4e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x7a]

  vssseg4e1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg4e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x7a]

  vssseg5e128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg5e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x9a]

  vssseg5e256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg5e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x9a]

  vssseg5e512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg5e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x9a]

  vssseg5e1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg5e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x9a]

  vssseg6e128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg6e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xba]

  vssseg6e256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg6e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xba]

  vssseg6e512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg6e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xba]

  vssseg6e1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg6e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xba]

  vssseg7e128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg7e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xda]

  vssseg7e256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg7e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xda]

  vssseg7e512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg7e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xda]

  vssseg7e1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg7e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xda]

  vssseg8e128.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg8e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xfa]

  vssseg8e256.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg8e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xfa]

  vssseg8e512.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg8e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xfa]

  vssseg8e1024.v v0, (a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg8e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xfa]




