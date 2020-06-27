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

  vsetvl	a3, a3, a2              
# CHECK-ASM-AND-OBJ: vsetvl	a3, a3, a2
# CHECK-ASM: [0xd7,0xf6,0xc6,0x80]

	vsetvli	a0, a1, e16,m2,ta,mu      
# CHECK-ASM-AND-OBJ: 	vsetvli	a0, a1, e16,m2,ta,mu    
# CHECK-ASM: [0x57,0xf5,0x55,0x04]

	vsetvli	a0, a1, e1024,mf8,ta,mu 
# CHECK-ASM-AND-OBJ: 	vsetvli	a0, a1, e1024,mf8,ta,mu 
# CHECK-ASM: [0x57,0xf5,0xf5,0x07]

	vsetvli	a0, a1, e8,m1,tu,mu     
# CHECK-ASM-AND-OBJ: 	vsetvli	a0, a1, e8,m1,tu,mu     
# CHECK-ASM: [0x57,0xf5,0x05,0x00]

	vsetvli	a0, a1, e8,m2,tu,mu     
# CHECK-ASM-AND-OBJ: 	vsetvli	a0, a1, e8,m2,tu,mu     
# CHECK-ASM: [0x57,0xf5,0x15,0x00]

	vsetvli	a0, a1, e16,m1,ta,mu    
# CHECK-ASM-AND-OBJ: 	vsetvli	a0, a1, e16,m1,ta,mu    
# CHECK-ASM: [0x57,0xf5,0x45,0x04]

	vle128.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vle128.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x12]

	vle256.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vle256.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x12]

	vle512.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vle512.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x12]

	vle8.v	v0, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vle8.v	v0, 0(a1)               
# CHECK-ASM: [0x07,0x80,0x05,0x02]

	vle16.v	v0, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vle16.v	v0, 0(a1)               
# CHECK-ASM: [0x07,0xd0,0x05,0x02]

	vle32.v	v0, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vle32.v	v0, 0(a1)               
# CHECK-ASM: [0x07,0xe0,0x05,0x02]

	vle64.v	v0, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vle64.v	v0, 0(a1)               
# CHECK-ASM: [0x07,0xf0,0x05,0x02]

	vse8.v	v0, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vse8.v	v0, 0(a1)               
# CHECK-ASM: [0x27,0x80,0x05,0x02]

	vse16.v	v0, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vse16.v	v0, 0(a1)               
# CHECK-ASM: [0x27,0xd0,0x05,0x02]

	vse32.v	v0, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vse32.v	v0, 0(a1)               
# CHECK-ASM: [0x27,0xe0,0x05,0x02]

	vse64.v	v0, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vse64.v	v0, 0(a1)               
# CHECK-ASM: [0x27,0xf0,0x05,0x02]

	vlse128.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlse128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0x80,0xc5,0x1a]

	vlse256.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlse256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0x1a]

	vlse512.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlse512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0x1a]

	vlse8.v	v0, 0(a1), a2           
# CHECK-ASM-AND-OBJ: 	vlse8.v	v0, 0(a1), a2           
# CHECK-ASM: [0x07,0x80,0xc5,0x0a]

	vlse16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlse16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0x0a]

	vlse32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlse32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0x0a]

	vlse64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlse64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xf0,0xc5,0x0a]

	vsse8.v	v0, 0(a1), a2           
# CHECK-ASM-AND-OBJ: 	vsse8.v	v0, 0(a1), a2           
# CHECK-ASM: [0x27,0x80,0xc5,0x0a]

	vsse16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vsse16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0x0a]

	vsse32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vsse32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0x0a]

	vsse64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vsse64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0x0a]

	vlxei128.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxei128.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0x1e]

	vlxei256.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxei256.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0x1e]

	vlxei512.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxei512.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0x1e]

	vlxei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0x0e]

	vlxei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0x0e]

	vlxei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0x0e]

	vlxei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xf0,0x25,0x0e]

	vsxei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0x80,0x25,0x0e]

	vsxei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xd0,0x25,0x0e]

	vsxei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xe0,0x25,0x0e]

	vsxei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xf0,0x25,0x0e]

	vsxei128.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxei128.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0x80,0x25,0x1e]

	vsxei256.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxei256.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xd0,0x25,0x1e]

	vsxei512.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxei512.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xe0,0x25,0x1e]

	vsxei1024.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxei1024.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xf0,0x25,0x1e]

	vle128ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vle128ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x13]

	vle256ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vle256ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x13]

	vle512ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vle512ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x13]

	vle8ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vle8ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x03]

	vle16ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vle16ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x03]

	vle32ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vle32ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x03]

	vle64ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vle64ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xf0,0x05,0x03]

	vlseg2e128.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg2e128.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x32]

	vlseg2e256.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg2e256.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x32]

	vlseg2e512.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg2e512.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x32]

	vlseg2e8.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg2e8.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x22]

	vlseg2e16.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg2e16.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x22]

	vlseg2e32.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg2e32.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x22]

	vlseg2e64.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg2e64.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xf0,0x05,0x22]

	vsseg2e8.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg2e8.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0x80,0x05,0x22]

	vsseg2e16.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg2e16.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xd0,0x05,0x22]

	vsseg2e32.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg2e32.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xe0,0x05,0x22]

	vsseg2e64.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg2e64.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xf0,0x05,0x22]

	vlseg3e128.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg3e128.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x52]

	vlseg3e256.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg3e256.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x52]

	vlseg3e512.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg3e512.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x52]

	vlseg3e8.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg3e8.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x42]

	vlseg3e16.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg3e16.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x42]

	vlseg3e32.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg3e32.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x42]

	vlseg3e64.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg3e64.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xf0,0x05,0x42]

	vsseg3e8.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg3e8.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0x80,0x05,0x42]

	vsseg3e16.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg3e16.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xd0,0x05,0x42]

	vsseg3e32.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg3e32.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xe0,0x05,0x42]

	vsseg3e64.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg3e64.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xf0,0x05,0x42]

	vlseg4e128.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg4e128.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x72]

	vlseg4e256.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg4e256.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x72]

	vlseg4e512.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg4e512.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x72]

	vlseg4e8.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg4e8.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x62]

	vlseg4e16.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg4e16.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x62]

	vlseg4e32.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg4e32.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x62]

	vlseg4e64.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg4e64.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xf0,0x05,0x62]

	vsseg4e8.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg4e8.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0x80,0x05,0x62]

	vsseg4e16.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg4e16.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xd0,0x05,0x62]

	vsseg4e32.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg4e32.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xe0,0x05,0x62]

	vsseg4e64.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg4e64.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xf0,0x05,0x62]

	vlseg5e128.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg5e128.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x92]

	vlseg5e256.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg5e256.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x92]

	vlseg5e512.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg5e512.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x92]

	vlseg5e8.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg5e8.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x82]

	vlseg5e16.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg5e16.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x82]

	vlseg5e32.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg5e32.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x82]

	vlseg5e64.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg5e64.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xf0,0x05,0x82]

	vsseg5e8.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg5e8.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0x80,0x05,0x82]

	vsseg5e16.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg5e16.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xd0,0x05,0x82]

	vsseg5e32.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg5e32.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xe0,0x05,0x82]

	vsseg5e64.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg5e64.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xf0,0x05,0x82]

	vlseg6e128.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg6e128.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0xb2]

	vlseg6e256.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg6e256.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0xb2]

	vlseg6e512.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg6e512.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0xb2]

	vlseg6e8.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg6e8.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0xa2]

	vlseg6e16.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg6e16.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0xa2]

	vlseg6e32.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg6e32.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0xa2]

	vlseg6e64.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg6e64.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xf0,0x05,0xa2]

	vsseg6e8.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg6e8.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0x80,0x05,0xa2]

	vsseg6e16.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg6e16.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xd0,0x05,0xa2]

	vsseg6e32.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg6e32.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xe0,0x05,0xa2]

	vsseg6e64.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg6e64.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xf0,0x05,0xa2]

	vlseg7e128.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg7e128.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0xd2]

	vlseg7e256.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg7e256.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0xd2]

	vlseg7e512.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg7e512.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0xd2]

	vlseg7e8.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg7e8.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0xc2]

	vlseg7e16.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg7e16.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0xc2]

	vlseg7e32.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg7e32.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0xc2]

	vlseg7e64.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg7e64.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xf0,0x05,0xc2]

	vsseg7e8.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg7e8.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0x80,0x05,0xc2]

	vsseg7e16.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg7e16.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xd0,0x05,0xc2]

	vsseg7e32.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg7e32.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xe0,0x05,0xc2]

	vsseg7e64.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg7e64.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xf0,0x05,0xc2]

	vlseg8e128.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg8e128.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0xf2]

	vlseg8e256.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg8e256.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0xf2]

	vlseg8e512.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg8e512.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0xf2]

	vlseg8e8.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg8e8.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0xe2]

	vlseg8e16.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg8e16.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0xe2]

	vlseg8e32.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg8e32.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0xe2]

	vlseg8e64.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg8e64.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xf0,0x05,0xe2]

	vsseg8e8.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg8e8.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0x80,0x05,0xe2]

	vsseg8e16.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg8e16.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xd0,0x05,0xe2]

	vsseg8e32.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg8e32.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xe0,0x05,0xe2]

	vsseg8e64.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vsseg8e64.v	v0, 0(a1)       
# CHECK-ASM: [0x27,0xf0,0x05,0xe2]

	vlsseg2e128.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg2e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0x80,0xc5,0x3a]

	vlsseg2e256.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg2e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0x3a]

	vlsseg2e512.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg2e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0x3a]

	vlsseg2e8.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg2e8.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0x80,0xc5,0x2a]

	vlsseg2e16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg2e16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0x2a]

	vlsseg2e32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg2e32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0x2a]

	vlsseg2e64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg2e64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xf0,0xc5,0x2a]

	vssseg2e8.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg2e8.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0x2a]

	vssseg2e16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg2e16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0x2a]

	vssseg2e32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg2e32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0x2a]

	vssseg2e64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg2e64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0x2a]

	vssseg2e128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ:  vssseg2e128.v	v0, 0(a1), a2
# CHECK-ASM: [0x27,0x80,0xc5,0x3a]

	vssseg2e256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ:  vssseg2e256.v v0, 0(a1), a2
# CHECK-ASM: [0x27,0xd0,0xc5,0x3a]

	vssseg2e512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ:  vssseg2e512.v v0, 0(a1), a2
# CHECK-ASM: [0x27,0xe0,0xc5,0x3a]

	vssseg2e1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ:  vssseg2e1024.v v0, 0(a1), a2
# CHECK-ASM: [0x27,0xf0,0xc5,0x3a]

	vlsseg3e128.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg3e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0x80,0xc5,0x5a]

	vlsseg3e256.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg3e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0x5a]

	vlsseg3e512.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg3e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0x5a]

	vlsseg3e8.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg3e8.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0x80,0xc5,0x4a]

	vlsseg3e16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg3e16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0x4a]

	vlsseg3e32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg3e32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0x4a]

	vlsseg3e64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg3e64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xf0,0xc5,0x4a]

	vssseg3e8.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg3e8.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0x4a]

	vssseg3e16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg3e16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0x4a]

	vssseg3e32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg3e32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0x4a]

	vssseg3e64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg3e64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0x4a]

	vssseg3e128.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg3e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0x5a]

	vssseg3e256.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg3e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0x5a]

	vssseg3e512.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg3e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0x5a]

	vssseg3e1024.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg3e1024.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0x5a]

	vlsseg4e128.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg4e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0x80,0xc5,0x7a]

	vlsseg4e256.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg4e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0x7a]

	vlsseg4e512.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg4e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0x7a]

	vlsseg4e8.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg4e8.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0x80,0xc5,0x6a]

	vlsseg4e16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg4e16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0x6a]

	vlsseg4e32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg4e32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0x6a]

	vlsseg4e64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg4e64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xf0,0xc5,0x6a]

	vssseg4e8.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg4e8.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0x6a]

	vssseg4e16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg4e16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0x6a]

	vssseg4e32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg4e32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0x6a]

	vssseg4e64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg4e64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0x6a]

	vssseg4e128.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg4e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0x7a]

	vssseg4e256.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg4e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0x7a]

	vssseg4e512.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg4e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0x7a]

	vssseg4e1024.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg4e1024.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0x7a]

	vlsseg5e128.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg5e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0x80,0xc5,0x9a]

	vlsseg5e256.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg5e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0x9a]

	vlsseg5e512.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg5e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0x9a]

	vlsseg5e8.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg5e8.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0x80,0xc5,0x8a]

	vlsseg5e16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg5e16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0x8a]

	vlsseg5e32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg5e32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0x8a]

	vlsseg5e64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg5e64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xf0,0xc5,0x8a]

	vssseg5e8.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg5e8.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0x8a]

	vssseg5e16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg5e16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0x8a]

	vssseg5e32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg5e32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0x8a]

	vssseg5e64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg5e64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0x8a]

	vssseg5e128.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg5e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0x9a]

	vssseg5e256.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg5e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0x9a]

	vssseg5e512.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg5e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0x9a]

	vssseg5e1024.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg5e1024.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0x9a]

	vlsseg6e128.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg6e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0x80,0xc5,0xba]

	vlsseg6e256.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg6e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0xba]

	vlsseg6e512.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg6e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0xba]

	vlsseg6e8.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg6e8.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0x80,0xc5,0xaa]

	vlsseg6e16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg6e16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0xaa]

	vlsseg6e32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg6e32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0xaa]

	vlsseg6e64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg6e64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xf0,0xc5,0xaa]

	vssseg6e8.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg6e8.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0xaa]

	vssseg6e16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg6e16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0xaa]

	vssseg6e32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg6e32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0xaa]

	vssseg6e64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg6e64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0xaa]

	vssseg6e128.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg6e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0xba]

	vssseg6e256.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg6e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0xba]

	vssseg6e512.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg6e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0xba]

	vssseg6e1024.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg6e1024.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0xba]

	vlsseg7e128.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg7e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0x80,0xc5,0xda]

	vlsseg7e256.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg7e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0xda]

	vlsseg7e512.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg7e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0xda]

	vlsseg7e8.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg7e8.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0x80,0xc5,0xca]

	vlsseg7e16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg7e16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0xca]

	vlsseg7e32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg7e32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0xca]

	vlsseg7e64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg7e64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xf0,0xc5,0xca]

	vssseg7e8.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg7e8.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0xca]

	vssseg7e16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg7e16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0xca]

	vssseg7e32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg7e32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0xca]

	vssseg7e64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg7e64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0xca]

	vssseg7e128.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg7e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0xda]

	vssseg7e256.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg7e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0xda]

	vssseg7e512.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg7e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0xda]

	vssseg7e1024.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg7e1024.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0xda]

	vlsseg8e128.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg8e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0x80,0xc5,0xfa]

	vlsseg8e256.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg8e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0xfa]

	vlsseg8e512.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg8e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0xfa]

	vlsseg8e8.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg8e8.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0x80,0xc5,0xea]

	vlsseg8e16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg8e16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xd0,0xc5,0xea]

	vlsseg8e32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg8e32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xe0,0xc5,0xea]

	vlsseg8e64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vlsseg8e64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x07,0xf0,0xc5,0xea]

	vssseg8e8.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg8e8.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0xea]

	vssseg8e16.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg8e16.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0xea]

	vssseg8e32.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg8e32.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0xea]

	vssseg8e64.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg8e64.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0xea]

	vssseg8e128.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg8e128.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0x80,0xc5,0xfa]

	vssseg8e256.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg8e256.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xd0,0xc5,0xfa]

	vssseg8e512.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg8e512.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xe0,0xc5,0xfa]

	vssseg8e1024.v	v0, 0(a1), a2   
# CHECK-ASM-AND-OBJ: 	vssseg8e1024.v	v0, 0(a1), a2   
# CHECK-ASM: [0x27,0xf0,0xc5,0xfa]

	vlxseg2ei128.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg2ei128.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0x3e]

	vlxseg2ei256.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg2ei256.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0x3e]

	vlxseg2ei512.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg2ei512.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0x3e]

	vlxseg2ei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg2ei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0x2e]

	vlxseg2ei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg2ei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0x2e]

	vlxseg2ei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg2ei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0x2e]

	vlxseg2ei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg2ei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xf0,0x25,0x2e]

	vsxseg2ei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg2ei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0x80,0x25,0x2e]

	vsxseg2ei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg2ei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xd0,0x25,0x2e]

	vsxseg2ei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg2ei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xe0,0x25,0x2e]

	vsxseg2ei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg2ei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xf0,0x25,0x2e]

	vlxseg3ei128.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg3ei128.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0x5e]

	vlxseg3ei256.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg3ei256.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0x5e]

	vlxseg3ei512.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg3ei512.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0x5e]

	vlxseg3ei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg3ei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0x4e]

	vlxseg3ei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg3ei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0x4e]

	vlxseg3ei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg3ei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0x4e]

	vlxseg3ei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg3ei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xf0,0x25,0x4e]

	vsxseg3ei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg3ei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0x80,0x25,0x4e]

	vsxseg3ei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg3ei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xd0,0x25,0x4e]

	vsxseg3ei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg3ei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xe0,0x25,0x4e]

	vsxseg3ei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg3ei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xf0,0x25,0x4e]

	vlxseg4ei128.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg4ei128.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0x7e]

	vlxseg4ei256.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg4ei256.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0x7e]

	vlxseg4ei512.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg4ei512.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0x7e]

	vlxseg4ei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg4ei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0x6e]

	vlxseg4ei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg4ei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0x6e]

	vlxseg4ei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg4ei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0x6e]

	vlxseg4ei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg4ei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xf0,0x25,0x6e]

	vsxseg4ei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg4ei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0x80,0x25,0x6e]

	vsxseg4ei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg4ei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xd0,0x25,0x6e]

	vsxseg4ei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg4ei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xe0,0x25,0x6e]

	vsxseg4ei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg4ei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xf0,0x25,0x6e]

	vlxseg5ei128.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg5ei128.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0x9e]

	vlxseg5ei256.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg5ei256.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0x9e]

	vlxseg5ei512.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg5ei512.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0x9e]

	vlxseg5ei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg5ei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0x8e]

	vlxseg5ei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg5ei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0x8e]

	vlxseg5ei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg5ei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0x8e]

	vlxseg5ei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg5ei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xf0,0x25,0x8e]

	vsxseg5ei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg5ei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0x80,0x25,0x8e]

	vsxseg5ei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg5ei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xd0,0x25,0x8e]

	vsxseg5ei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg5ei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xe0,0x25,0x8e]

	vsxseg5ei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg5ei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xf0,0x25,0x8e]

	vlxseg6ei128.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg6ei128.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0xbe]

	vlxseg6ei256.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg6ei256.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0xbe]

	vlxseg6ei512.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg6ei512.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0xbe]

	vlxseg6ei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg6ei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0xae]

	vlxseg6ei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg6ei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0xae]

	vlxseg6ei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg6ei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0xae]

	vlxseg6ei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg6ei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xf0,0x25,0xae]

	vsxseg6ei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg6ei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0x80,0x25,0xae]

	vsxseg6ei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg6ei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xd0,0x25,0xae]

	vsxseg6ei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg6ei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xe0,0x25,0xae]

	vsxseg6ei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg6ei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xf0,0x25,0xae]

	vlxseg7ei128.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg7ei128.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0xde]

	vlxseg7ei256.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg7ei256.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0xde]

	vlxseg7ei512.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg7ei512.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0xde]

	vlxseg7ei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg7ei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0xce]

	vlxseg7ei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg7ei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0xce]

	vlxseg7ei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg7ei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0xce]

	vlxseg7ei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg7ei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xf0,0x25,0xce]

	vsxseg7ei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg7ei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0x80,0x25,0xce]

	vsxseg7ei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg7ei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xd0,0x25,0xce]

	vsxseg7ei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg7ei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xe0,0x25,0xce]

	vsxseg7ei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg7ei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xf0,0x25,0xce]

	vlxseg8ei128.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg8ei128.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0xfe]

	vlxseg8ei256.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg8ei256.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0xfe]

	vlxseg8ei512.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg8ei512.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0xfe]

	vlxseg8ei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg8ei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0x80,0x25,0xee]

	vlxseg8ei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg8ei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xd0,0x25,0xee]

	vlxseg8ei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg8ei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xe0,0x25,0xee]

	vlxseg8ei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vlxseg8ei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x07,0xf0,0x25,0xee]

	vsxseg8ei8.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg8ei8.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0x80,0x25,0xee]

	vsxseg8ei16.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg8ei16.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xd0,0x25,0xee]

	vsxseg8ei32.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg8ei32.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xe0,0x25,0xee]

	vsxseg8ei64.v	v0, 0(a1), v2   
# CHECK-ASM-AND-OBJ: 	vsxseg8ei64.v	v0, 0(a1), v2   
# CHECK-ASM: [0x27,0xf0,0x25,0xee]

	vlseg2e128ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg2e128ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x33]

	vlseg2e256ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg2e256ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x33]

	vlseg2e512ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg2e512ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x33]

	vlseg2e8ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg2e8ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x23]

	vlseg2e16ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg2e16ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x23]

	vlseg2e32ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg2e32ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x23]

	vlseg2e64ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg2e64ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xf0,0x05,0x23]

	vlseg3e128ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg3e128ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x53]

	vlseg3e256ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg3e256ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x53]

	vlseg3e512ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg3e512ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x53]

	vlseg3e8ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg3e8ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x43]

	vlseg3e16ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg3e16ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x43]

	vlseg3e32ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg3e32ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x43]

	vlseg3e64ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg3e64ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xf0,0x05,0x43]

	vlseg4e128ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg4e128ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x73]

	vlseg4e256ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg4e256ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x73]

	vlseg4e512ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg4e512ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x73]

	vlseg4e8ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg4e8ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x63]

	vlseg4e16ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg4e16ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x63]

	vlseg4e32ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg4e32ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x63]

	vlseg4e64ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg4e64ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xf0,0x05,0x63]

	vlseg5e128ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg5e128ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x93]

	vlseg5e256ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg5e256ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x93]

	vlseg5e512ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg5e512ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x93]

	vlseg5e8ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg5e8ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0x83]

	vlseg5e16ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg5e16ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0x83]

	vlseg5e32ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg5e32ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0x83]

	vlseg5e64ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg5e64ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xf0,0x05,0x83]

	vlseg6e128ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg6e128ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0xb3]

	vlseg6e256ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg6e256ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0xb3]

	vlseg6e512ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg6e512ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0xb3]

	vlseg6e8ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg6e8ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0xa3]

	vlseg6e16ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg6e16ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0xa3]

	vlseg6e32ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg6e32ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0xa3]

	vlseg6e64ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg6e64ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xf0,0x05,0xa3]

	vlseg7e128ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg7e128ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0xd3]

	vlseg7e256ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg7e256ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0xd3]

	vlseg7e512ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg7e512ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0xd3]

	vlseg7e8ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg7e8ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0xc3]

	vlseg7e16ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg7e16ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0xc3]

	vlseg7e32ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg7e32ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0xc3]

	vlseg7e64ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg7e64ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xf0,0x05,0xc3]

	vlseg8e128ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg8e128ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0xf3]

	vlseg8e256ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg8e256ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0xf3]

	vlseg8e512ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg8e512ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0xf3]

	vlseg8e8ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg8e8ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0x80,0x05,0xe3]

	vlseg8e16ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg8e16ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xd0,0x05,0xe3]

	vlseg8e32ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg8e32ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xe0,0x05,0xe3]

	vlseg8e64ff.v	v0, 0(a1)       
# CHECK-ASM-AND-OBJ: 	vlseg8e64ff.v	v0, 0(a1)       
# CHECK-ASM: [0x07,0xf0,0x05,0xe3]

	vl1r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vl1r.v	v3, 0(a1)               
# CHECK-ASM: [0x87,0xf1,0x85,0x02]

	vs1r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vs1r.v	v3, 0(a1)               
# CHECK-ASM: [0xa7,0xf1,0x85,0x02]

	vl2r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vl2r.v	v3, 0(a1)               
# CHECK-ASM: [0x87,0xf1,0x85,0x22]

	vs2r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vs2r.v	v3, 0(a1)               
# CHECK-ASM: [0xa7,0xf1,0x85,0x22]

	vl3r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vl3r.v	v3, 0(a1)               
# CHECK-ASM: [0x87,0xf1,0x85,0x42]

	vs3r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vs3r.v	v3, 0(a1)               
# CHECK-ASM: [0xa7,0xf1,0x85,0x42]

	vl4r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vl4r.v	v3, 0(a1)               
# CHECK-ASM: [0x87,0xf1,0x85,0x62]

	vs4r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vs4r.v	v3, 0(a1)               
# CHECK-ASM: [0xa7,0xf1,0x85,0x62]

	vl5r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vl5r.v	v3, 0(a1)               
# CHECK-ASM: [0x87,0xf1,0x85,0x82]

	vs5r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vs5r.v	v3, 0(a1)               
# CHECK-ASM: [0xa7,0xf1,0x85,0x82]

	vl6r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vl6r.v	v3, 0(a1)               
# CHECK-ASM: [0x87,0xf1,0x85,0xa2]

	vs6r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vs6r.v	v3, 0(a1)               
# CHECK-ASM: [0xa7,0xf1,0x85,0xa2]

	vl7r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vl7r.v	v3, 0(a1)               
# CHECK-ASM: [0x87,0xf1,0x85,0xc2]

	vs7r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vs7r.v	v3, 0(a1)               
# CHECK-ASM: [0xa7,0xf1,0x85,0xc2]

	vl8r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vl8r.v	v3, 0(a1)               
# CHECK-ASM: [0x87,0xf1,0x85,0xe2]

	vs8r.v	v3, 0(a1)               
# CHECK-ASM-AND-OBJ: 	vs8r.v	v3, 0(a1)               
# CHECK-ASM: [0xa7,0xf1,0x85,0xe2]

  vamoswapei8.v v0, 0(a1), v2, v0
# CHECK-ASM: [0x2f,0x80,0x25,0x0e]

	vamoswapei16.v v0, 0(a1), v2, v0
# CHECK-ASM-AND-OBJ: 	vamoswapei16.v v0, 0(a1), v2, v0
# CHECK-ASM: [0x2f,0xd0,0x25,0x0e]

	vamoswapei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoswapei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0x0e]

	vamoswapei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoswapei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0x0a]

	vamoaddei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoaddei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0x06]

	vamoaddei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoaddei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0x02]

	vamoxorei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoxorei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0x26]

	vamoxorei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoxorei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0x22]

	vamoandei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoandei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0x66]

	vamoandei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoandei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0x62]

	vamoorei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoorei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0x46]

	vamoorei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoorei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0x42]

	vamominei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamominei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0x86]

	vamominei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamominei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0x82]

	vamomaxei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamomaxei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0xa6]

	vamomaxei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamomaxei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0xa2]

	vamominuei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamominuei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0xc6]

	vamominuei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamominuei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0xc2]

	vamomaxuei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamomaxuei32.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0xe6]

	vamomaxuei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamomaxuei32.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xe0,0x25,0xe2]

	vamoswapei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoswapei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0x0e]

	vamoswapei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoswapei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0x0a]

	vamoaddei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoaddei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0x06]

	vamoaddei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoaddei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0x02]

	vamoxorei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoxorei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0x26]

	vamoxorei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoxorei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0x22]

	vamoandei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoandei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0x66]

	vamoandei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoandei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0x62]

	vamoorei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoorei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0x46]

	vamoorei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamoorei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0x42]

	vamominei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamominei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0x86]

	vamominei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamominei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0x82]

	vamomaxei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamomaxei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0xa6]

	vamomaxei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamomaxei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0xa2]

	vamominuei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamominuei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0xc6]

	vamominuei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamominuei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0xc2]

	vamomaxuei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamomaxuei64.v	v0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0xe6]

	vamomaxuei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM-AND-OBJ: 	vamomaxuei64.v	x0, 0(a1), v2, v0 
# CHECK-ASM: [0x2f,0xf0,0x25,0xe2]

	vadd.vv	v0, v1, v0              
# CHECK-ASM-AND-OBJ: 	vadd.vv	v0, v1, v0              
# CHECK-ASM: [0x57,0x00,0x10,0x02]

	vadd.vx	v0, v1, a0              
# CHECK-ASM-AND-OBJ: 	vadd.vx	v0, v1, a0              
# CHECK-ASM: [0x57,0x40,0x15,0x02]

	vadd.vi	v0, v1, 0               
# CHECK-ASM-AND-OBJ: 	vadd.vi	v0, v1, 0               
# CHECK-ASM: [0x57,0x30,0x10,0x02]

	vsub.vv	v0, v1, v0              
# CHECK-ASM-AND-OBJ: 	vsub.vv	v0, v1, v0              
# CHECK-ASM: [0x57,0x00,0x10,0x0a]

	vsub.vx	v0, v1, a0              
# CHECK-ASM-AND-OBJ: 	vsub.vx	v0, v1, a0              
# CHECK-ASM: [0x57,0x40,0x15,0x0a]

	vrsub.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vrsub.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x0e]

	vrsub.vi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vrsub.vi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0x0e]

	vwaddu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vwaddu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0xc2]

	vwaddu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vwaddu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0xc2]

	vwsubu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vwsubu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0xca]

	vwsubu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vwsubu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0xca]

	vwadd.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vwadd.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0xc6]

	vwadd.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vwadd.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0xc6]

	vwsub.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vwsub.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0xce]

	vwsub.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vwsub.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0xce]

	vwaddu.wv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vwaddu.wv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0xd2]

	vwaddu.wx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vwaddu.wx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0xd2]

	vwsubu.wv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vwsubu.wv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0xda]

	vwsubu.wx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vwsubu.wx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0xda]

	vwadd.wv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vwadd.wv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0xd6]

	vwadd.wx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vwadd.wx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0xd6]

	vwsub.wv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vwsub.wv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0xde]

	vwsub.wx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vwsub.wx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0xde]

	vadc.vvm	v0, v1, v0, v0  
# CHECK-ASM-AND-OBJ: 	vadc.vvm	v0, v1, v0, v0  
# CHECK-ASM: [0x57,0x00,0x10,0x40]

	vadc.vxm	v0, v1, a0, v0  
# CHECK-ASM-AND-OBJ: 	vadc.vxm	v0, v1, a0, v0  
# CHECK-ASM: [0x57,0x40,0x15,0x40]

	vadc.vim	v0, v1, 0, v0   
# CHECK-ASM-AND-OBJ: 	vadc.vim	v0, v1, 0, v0   
# CHECK-ASM: [0x57,0x30,0x10,0x40]

	vmadc.vvm	v0, v1, v0, v0  
# CHECK-ASM-AND-OBJ: 	vmadc.vvm	v0, v1, v0, v0  
# CHECK-ASM: [0x57,0x00,0x10,0x44]

	vmadc.vxm	v0, v1, a0, v0  
# CHECK-ASM-AND-OBJ: 	vmadc.vxm	v0, v1, a0, v0  
# CHECK-ASM: [0x57,0x40,0x15,0x44]

	vmadc.vim	v0, v1, 0, v0   
# CHECK-ASM-AND-OBJ: 	vmadc.vim	v0, v1, 0, v0   
# CHECK-ASM: [0x57,0x30,0x10,0x44]

	vmadc.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmadc.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x46]

	vmadc.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vmadc.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x46]

	vmadc.vi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vmadc.vi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0x46]

	vsbc.vvm	v0, v1, v0, v0  
# CHECK-ASM-AND-OBJ: 	vsbc.vvm	v0, v1, v0, v0  
# CHECK-ASM: [0x57,0x00,0x10,0x48]

	vsbc.vxm	v0, v1, a0, v0  
# CHECK-ASM-AND-OBJ: 	vsbc.vxm	v0, v1, a0, v0  
# CHECK-ASM: [0x57,0x40,0x15,0x48]

	vmsbc.vvm	v0, v1, v0, v0  
# CHECK-ASM-AND-OBJ: 	vmsbc.vvm	v0, v1, v0, v0  
# CHECK-ASM: [0x57,0x00,0x10,0x4c]

	vmsbc.vxm	v0, v1, a0, v0  
# CHECK-ASM-AND-OBJ: 	vmsbc.vxm	v0, v1, a0, v0  
# CHECK-ASM: [0x57,0x40,0x15,0x4c]

	vmsbc.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmsbc.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x4e]

	vmsbc.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vmsbc.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x4e]

	vand.vv	v0, v1, v0              
# CHECK-ASM-AND-OBJ: 	vand.vv	v0, v1, v0              
# CHECK-ASM: [0x57,0x00,0x10,0x26]

	vand.vx	v0, v1, a0              
# CHECK-ASM-AND-OBJ: 	vand.vx	v0, v1, a0              
# CHECK-ASM: [0x57,0x40,0x15,0x26]

	vand.vi	v0, v1, 0               
# CHECK-ASM-AND-OBJ: 	vand.vi	v0, v1, 0               
# CHECK-ASM: [0x57,0x30,0x10,0x26]

	vor.vv	v0, v1, v0              
# CHECK-ASM-AND-OBJ: 	vor.vv	v0, v1, v0              
# CHECK-ASM: [0x57,0x00,0x10,0x2a]

	vor.vx	v0, v1, a0              
# CHECK-ASM-AND-OBJ: 	vor.vx	v0, v1, a0              
# CHECK-ASM: [0x57,0x40,0x15,0x2a]

	vor.vi	v0, v1, 0               
# CHECK-ASM-AND-OBJ: 	vor.vi	v0, v1, 0               
# CHECK-ASM: [0x57,0x30,0x10,0x2a]

	vxor.vv	v0, v1, v0              
# CHECK-ASM-AND-OBJ: 	vxor.vv	v0, v1, v0              
# CHECK-ASM: [0x57,0x00,0x10,0x2e]

	vxor.vx	v0, v1, a0              
# CHECK-ASM-AND-OBJ: 	vxor.vx	v0, v1, a0              
# CHECK-ASM: [0x57,0x40,0x15,0x2e]

	vxor.vi	v0, v1, 0               
# CHECK-ASM-AND-OBJ: 	vxor.vi	v0, v1, 0               
# CHECK-ASM: [0x57,0x30,0x10,0x2e]

	vsll.vv	v0, v1, v0              
# CHECK-ASM-AND-OBJ: 	vsll.vv	v0, v1, v0              
# CHECK-ASM: [0x57,0x00,0x10,0x96]

	vsll.vx	v0, v1, a0              
# CHECK-ASM-AND-OBJ: 	vsll.vx	v0, v1, a0              
# CHECK-ASM: [0x57,0x40,0x15,0x96]

	vsll.vi	v0, v1, 0               
# CHECK-ASM-AND-OBJ: 	vsll.vi	v0, v1, 0               
# CHECK-ASM: [0x57,0x30,0x10,0x96]

	vsrl.vv	v0, v1, v0              
# CHECK-ASM-AND-OBJ: 	vsrl.vv	v0, v1, v0              
# CHECK-ASM: [0x57,0x00,0x10,0xa2]

	vsrl.vx	v0, v1, a0              
# CHECK-ASM-AND-OBJ: 	vsrl.vx	v0, v1, a0              
# CHECK-ASM: [0x57,0x40,0x15,0xa2]

	vsrl.vi	v0, v1, 0               
# CHECK-ASM-AND-OBJ: 	vsrl.vi	v0, v1, 0               
# CHECK-ASM: [0x57,0x30,0x10,0xa2]

	vsra.vv	v0, v1, v0              
# CHECK-ASM-AND-OBJ: 	vsra.vv	v0, v1, v0              
# CHECK-ASM: [0x57,0x00,0x10,0xa6]

	vsra.vx	v0, v1, a0              
# CHECK-ASM-AND-OBJ: 	vsra.vx	v0, v1, a0              
# CHECK-ASM: [0x57,0x40,0x15,0xa6]

	vsra.vi	v0, v1, 0               
# CHECK-ASM-AND-OBJ: 	vsra.vi	v0, v1, 0               
# CHECK-ASM: [0x57,0x30,0x10,0xa6]

	vnsrl.wv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vnsrl.wv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0xb2]

	vnsrl.wx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vnsrl.wx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0xb2]

	vnsrl.wi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vnsrl.wi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0xb2]

	vnsra.wv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vnsra.wv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0xb6]

	vnsra.wx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vnsra.wx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0xb6]

	vnsra.wi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vnsra.wi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0xb6]

	vmseq.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmseq.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x62]

	vmseq.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vmseq.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x62]

	vmseq.vi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vmseq.vi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0x62]

	vmsne.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmsne.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x66]

	vmsne.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vmsne.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x66]

	vmsne.vi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vmsne.vi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0x66]

	vmsltu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmsltu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x6a]

	vmsltu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vmsltu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x6a]

	vmslt.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmslt.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x6e]

	vmslt.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vmslt.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x6e]

	vmsleu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmsleu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x72]

	vmsleu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vmsleu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x72]

	vmsleu.vi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vmsleu.vi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0x72]

	vmsle.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmsle.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x76]

	vmsle.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vmsle.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x76]

	vmsle.vi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vmsle.vi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0x76]

	vmsgtu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vmsgtu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x7a]

	vmsgtu.vi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vmsgtu.vi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0x7a]

	vmsgt.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vmsgt.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x7e]

	vmsgt.vi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vmsgt.vi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0x7e]

	vminu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vminu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x12]

	vminu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vminu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x12]

	vmin.vv	v0, v1, v0              
# CHECK-ASM-AND-OBJ: 	vmin.vv	v0, v1, v0              
# CHECK-ASM: [0x57,0x00,0x10,0x16]

	vmin.vx	v0, v1, a0              
# CHECK-ASM-AND-OBJ: 	vmin.vx	v0, v1, a0              
# CHECK-ASM: [0x57,0x40,0x15,0x16]

	vmaxu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmaxu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x1a]

	vmaxu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vmaxu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x1a]

	vmax.vv	v0, v1, v0              
# CHECK-ASM-AND-OBJ: 	vmax.vv	v0, v1, v0              
# CHECK-ASM: [0x57,0x00,0x10,0x1e]

	vmax.vx	v0, v1, a0              
# CHECK-ASM-AND-OBJ: 	vmax.vx	v0, v1, a0              
# CHECK-ASM: [0x57,0x40,0x15,0x1e]

	vmul.vv	v0, v1, v0              
# CHECK-ASM-AND-OBJ: 	vmul.vv	v0, v1, v0              
# CHECK-ASM: [0x57,0x20,0x10,0x96]

	vmul.vx	v0, v1, a0              
# CHECK-ASM-AND-OBJ: 	vmul.vx	v0, v1, a0              
# CHECK-ASM: [0x57,0x60,0x15,0x96]

	vmulh.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmulh.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x9e]

	vmulh.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vmulh.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0x9e]

	vmulhu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmulhu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x92]

	vmulhu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vmulhu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0x92]

	vmulhsu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmulhsu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x9a]

	vmulhsu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vmulhsu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0x9a]

	vdivu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vdivu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x82]

	vdivu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vdivu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0x82]

	vdiv.vv	v0, v1, v0              
# CHECK-ASM-AND-OBJ: 	vdiv.vv	v0, v1, v0              
# CHECK-ASM: [0x57,0x20,0x10,0x86]

	vdiv.vx	v0, v1, a0              
# CHECK-ASM-AND-OBJ: 	vdiv.vx	v0, v1, a0              
# CHECK-ASM: [0x57,0x60,0x15,0x86]

	vremu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vremu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x8a]

	vremu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vremu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0x8a]

	vrem.vv	v0, v1, v0              
# CHECK-ASM-AND-OBJ: 	vrem.vv	v0, v1, v0              
# CHECK-ASM: [0x57,0x20,0x10,0x8e]

	vrem.vx	v0, v1, a0              
# CHECK-ASM-AND-OBJ: 	vrem.vx	v0, v1, a0              
# CHECK-ASM: [0x57,0x60,0x15,0x8e]

	vwmul.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vwmul.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0xee]

	vwmul.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vwmul.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0xee]

	vwmulu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vwmulu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0xe2]

	vwmulu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vwmulu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0xe2]

	vwmulsu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vwmulsu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0xea]

	vwmulsu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vwmulsu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0xea]

	vmacc.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vmacc.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x20,0x10,0xb6]

	vmacc.vx	v0, a0, v1      
# CHECK-ASM-AND-OBJ: 	vmacc.vx	v0, a0, v1      
# CHECK-ASM: [0x57,0x60,0x15,0xb6]

	vnmsac.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vnmsac.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x20,0x10,0xbe]

	vnmsac.vx	v0, a0, v1      
# CHECK-ASM-AND-OBJ: 	vnmsac.vx	v0, a0, v1      
# CHECK-ASM: [0x57,0x60,0x15,0xbe]

	vmadd.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vmadd.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x20,0x10,0xa6]

	vmadd.vx	v0, a0, v1      
# CHECK-ASM-AND-OBJ: 	vmadd.vx	v0, a0, v1      
# CHECK-ASM: [0x57,0x60,0x15,0xa6]

	vnmsub.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vnmsub.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x20,0x10,0xae]

	vnmsub.vx	v0, a0, v1      
# CHECK-ASM-AND-OBJ: 	vnmsub.vx	v0, a0, v1      
# CHECK-ASM: [0x57,0x60,0x15,0xae]

	vwmaccu.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vwmaccu.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x20,0x10,0xf2]

	vwmaccu.vx	v0, a0, v1      
# CHECK-ASM-AND-OBJ: 	vwmaccu.vx	v0, a0, v1      
# CHECK-ASM: [0x57,0x60,0x15,0xf2]

	vwmacc.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vwmacc.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x20,0x10,0xf6]

	vwmacc.vx	v0, a0, v1      
# CHECK-ASM-AND-OBJ: 	vwmacc.vx	v0, a0, v1      
# CHECK-ASM: [0x57,0x60,0x15,0xf6]

	vwmaccsu.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vwmaccsu.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x20,0x10,0xfe]

	vwmaccsu.vx	v0, a0, v1      
# CHECK-ASM-AND-OBJ: 	vwmaccsu.vx	v0, a0, v1      
# CHECK-ASM: [0x57,0x60,0x15,0xfe]

	vwmaccus.vx	v0, a0, v1      
# CHECK-ASM-AND-OBJ: 	vwmaccus.vx	v0, a0, v1      
# CHECK-ASM: [0x57,0x60,0x15,0xfa]

	vqmaccu.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vqmaccu.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x00,0x10,0xf2]

	vqmaccu.vx	v0, a0, v1      
# CHECK-ASM-AND-OBJ: 	vqmaccu.vx	v0, a0, v1      
# CHECK-ASM: [0x57,0x40,0x15,0xf2]

	vqmacc.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vqmacc.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x00,0x10,0xf6]

	vqmacc.vx	v0, a0, v1      
# CHECK-ASM-AND-OBJ: 	vqmacc.vx	v0, a0, v1      
# CHECK-ASM: [0x57,0x40,0x15,0xf6]

	vqmaccsu.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vqmaccsu.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x00,0x10,0xfe]

	vqmaccsu.vx	v0, a0, v1      
# CHECK-ASM-AND-OBJ: 	vqmaccsu.vx	v0, a0, v1      
# CHECK-ASM: [0x57,0x40,0x15,0xfe]

	vqmaccus.vx	v0, a0, v1      
# CHECK-ASM-AND-OBJ: 	vqmaccus.vx	v0, a0, v1      
# CHECK-ASM: [0x57,0x40,0x15,0xfa]

	vmerge.vvm	v0, v1, v0, v0  
# CHECK-ASM-AND-OBJ: 	vmerge.vvm	v0, v1, v0, v0  
# CHECK-ASM: [0x57,0x00,0x10,0x5c]

	vmerge.vxm	v0, v1, a0, v0  
# CHECK-ASM-AND-OBJ: 	vmerge.vxm	v0, v1, a0, v0  
# CHECK-ASM: [0x57,0x40,0x15,0x5c]

	vmerge.vim	v0, v1, 0, v0   
# CHECK-ASM-AND-OBJ: 	vmerge.vim	v0, v1, 0, v0   
# CHECK-ASM: [0x57,0x30,0x10,0x5c]

	vmv.v.v	v0, v0                  
# CHECK-ASM-AND-OBJ: 	vmv.v.v	v0, v0                  
# CHECK-ASM: [0x57,0x00,0x00,0x5e]

	vmv.v.x	v0, a0                  
# CHECK-ASM-AND-OBJ: 	vmv.v.x	v0, a0                  
# CHECK-ASM: [0x57,0x40,0x05,0x5e]

	vmv.v.i	v0, 0                   
# CHECK-ASM-AND-OBJ: 	vmv.v.i	v0, 0                   
# CHECK-ASM: [0x57,0x30,0x00,0x5e]

	vsaddu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vsaddu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x82]

	vsaddu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vsaddu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x82]

	vsaddu.vi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vsaddu.vi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0x82]

	vsadd.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vsadd.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x86]

	vsadd.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vsadd.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x86]

	vsadd.vi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vsadd.vi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0x86]

	vssubu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vssubu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x8a]

	vssubu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vssubu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x8a]

	vssub.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vssub.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x8e]

	vssub.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vssub.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x8e]

	vaaddu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vaaddu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x22]

	vaaddu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vaaddu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0x22]

	vaadd.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vaadd.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x26]

	vaadd.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vaadd.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0x26]

	vasubu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vasubu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x2a]

	vasubu.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vasubu.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0x2a]

	vasub.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vasub.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x2e]

	vasub.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vasub.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0x2e]

	vsmul.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vsmul.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x9e]

	vsmul.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vsmul.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x9e]

	vssrl.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vssrl.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0xaa]

	vssrl.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vssrl.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0xaa]

	vssrl.vi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vssrl.vi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0xaa]

	vssra.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vssra.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0xae]

	vssra.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vssra.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0xae]

	vssra.vi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vssra.vi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0xae]

	vnclipu.wv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vnclipu.wv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0xba]

	vnclipu.wx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vnclipu.wx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0xba]

	vnclipu.wi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vnclipu.wi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0xba]

	vnclip.wv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vnclip.wv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0xbe]

	vnclip.wx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vnclip.wx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0xbe]

	vnclip.wi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vnclip.wi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0xbe]

	vfadd.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfadd.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x02]

	vfadd.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfadd.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x02]

	vfsub.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfsub.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x0a]

	vfsub.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfsub.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x0a]

	vfrsub.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfrsub.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x9e]

	vfwadd.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfwadd.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0xc2]

	vfwadd.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfwadd.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0xc2]

	vfwsub.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfwsub.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0xca]

	vfwsub.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfwsub.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0xca]

	vfwadd.wv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfwadd.wv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0xd2]

	vfwadd.wf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfwadd.wf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0xd2]

	vfwsub.wv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfwsub.wv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0xda]

	vfwsub.wf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfwsub.wf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0xda]

	vfmul.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfmul.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x92]

	vfmul.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfmul.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x92]

	vfdiv.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfdiv.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x82]

	vfdiv.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfdiv.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x82]

	vfrdiv.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfrdiv.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x86]

	vfwmul.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfwmul.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0xe2]

	vfwmul.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfwmul.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0xe2]

	vfmacc.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vfmacc.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x10,0x10,0xb2]

	vfmacc.vf	v0, ft0, v1     
# CHECK-ASM-AND-OBJ: 	vfmacc.vf	v0, ft0, v1     
# CHECK-ASM: [0x57,0x50,0x10,0xb2]

	vfnmacc.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vfnmacc.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x10,0x10,0xb6]

	vfnmacc.vf	v0, ft0, v1     
# CHECK-ASM-AND-OBJ: 	vfnmacc.vf	v0, ft0, v1     
# CHECK-ASM: [0x57,0x50,0x10,0xb6]

	vfmsac.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vfmsac.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x10,0x10,0xba]

	vfmsac.vf	v0, ft0, v1     
# CHECK-ASM-AND-OBJ: 	vfmsac.vf	v0, ft0, v1     
# CHECK-ASM: [0x57,0x50,0x10,0xba]

	vfnmsac.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vfnmsac.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x10,0x10,0xbe]

	vfnmsac.vf	v0, ft0, v1     
# CHECK-ASM-AND-OBJ: 	vfnmsac.vf	v0, ft0, v1     
# CHECK-ASM: [0x57,0x50,0x10,0xbe]

	vfmadd.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vfmadd.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x10,0x10,0xa2]

	vfmadd.vf	v0, ft0, v1     
# CHECK-ASM-AND-OBJ: 	vfmadd.vf	v0, ft0, v1     
# CHECK-ASM: [0x57,0x50,0x10,0xa2]

	vfnmadd.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vfnmadd.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x10,0x10,0xa6]

	vfnmadd.vf	v0, ft0, v1     
# CHECK-ASM-AND-OBJ: 	vfnmadd.vf	v0, ft0, v1     
# CHECK-ASM: [0x57,0x50,0x10,0xa6]

	vfmsub.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vfmsub.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x10,0x10,0xaa]

	vfmsub.vf	v0, ft0, v1     
# CHECK-ASM-AND-OBJ: 	vfmsub.vf	v0, ft0, v1     
# CHECK-ASM: [0x57,0x50,0x10,0xaa]

	vfnmsub.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vfnmsub.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x10,0x10,0xae]

	vfnmsub.vf	v0, ft0, v1     
# CHECK-ASM-AND-OBJ: 	vfnmsub.vf	v0, ft0, v1     
# CHECK-ASM: [0x57,0x50,0x10,0xae]

	vfwmacc.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vfwmacc.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x10,0x10,0xf2]

	vfwmacc.vf	v0, ft0, v1     
# CHECK-ASM-AND-OBJ: 	vfwmacc.vf	v0, ft0, v1     
# CHECK-ASM: [0x57,0x50,0x10,0xf2]

	vfwnmacc.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vfwnmacc.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x10,0x10,0xf6]

	vfwnmacc.vf	v0, ft0, v1     
# CHECK-ASM-AND-OBJ: 	vfwnmacc.vf	v0, ft0, v1     
# CHECK-ASM: [0x57,0x50,0x10,0xf6]

	vfwmsac.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vfwmsac.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x10,0x10,0xfa]

	vfwmsac.vf	v0, ft0, v1     
# CHECK-ASM-AND-OBJ: 	vfwmsac.vf	v0, ft0, v1     
# CHECK-ASM: [0x57,0x50,0x10,0xfa]

	vfwnmsac.vv	v0, v0, v1      
# CHECK-ASM-AND-OBJ: 	vfwnmsac.vv	v0, v0, v1      
# CHECK-ASM: [0x57,0x10,0x10,0xfe]

	vfwnmsac.vf	v0, ft0, v1     
# CHECK-ASM-AND-OBJ: 	vfwnmsac.vf	v0, ft0, v1     
# CHECK-ASM: [0x57,0x50,0x10,0xfe]

	vfsqrt.v	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfsqrt.v	v0, v1          
# CHECK-ASM: [0x57,0x10,0x10,0x8e]

	vfmin.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfmin.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x12]

	vfmin.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfmin.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x12]

	vfmax.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfmax.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x1a]

	vfmax.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfmax.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x1a]

	vfsgnj.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfsgnj.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x22]

	vfsgnj.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfsgnj.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x22]

	vfsgnjn.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfsgnjn.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x26]

	vfsgnjn.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfsgnjn.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x26]

	vfsgnjx.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfsgnjx.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x2a]

	vfsgnjx.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vfsgnjx.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x2a]

	vmfeq.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmfeq.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x62]

	vmfeq.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vmfeq.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x62]

	vmfne.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmfne.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x72]

	vmfne.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vmfne.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x72]

	vmflt.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmflt.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x6e]

	vmflt.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vmflt.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x6e]

	vmfle.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmfle.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x66]

	vmfle.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vmfle.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x66]

	vmfgt.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vmfgt.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x76]

	vmfge.vf	v0, v1, ft0     
# CHECK-ASM-AND-OBJ: 	vmfge.vf	v0, v1, ft0     
# CHECK-ASM: [0x57,0x50,0x10,0x7e]

	vfclass.v	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfclass.v	v0, v1          
# CHECK-ASM: [0x57,0x10,0x18,0x8e]

	vfmerge.vfm	v0, v1, ft0, v0 
# CHECK-ASM-AND-OBJ: 	vfmerge.vfm	v0, v1, ft0, v0 
# CHECK-ASM: [0x57,0x50,0x10,0x5c]

	vfmv.v.f	v0, ft0         
# CHECK-ASM-AND-OBJ: 	vfmv.v.f	v0, ft0         
# CHECK-ASM: [0x57,0x50,0x00,0x5e]

	vfcvt.xu.f.v	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfcvt.xu.f.v	v0, v1          
# CHECK-ASM: [0x57,0x10,0x10,0x8a]

	vfcvt.x.f.v	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfcvt.x.f.v	v0, v1          
# CHECK-ASM: [0x57,0x90,0x10,0x8a]

	vfcvt.f.xu.v	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfcvt.f.xu.v	v0, v1          
# CHECK-ASM: [0x57,0x10,0x11,0x8a]

	vfcvt.f.x.v	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfcvt.f.x.v	v0, v1          
# CHECK-ASM: [0x57,0x90,0x11,0x8a]

	vfcvt.rtz.xu.f.v	v0, v1
# CHECK-ASM-AND-OBJ: vfcvt.rtz.xu.f.v	v0, v1
# encoding: [0x57,0x10,0x13,0x8a]

	vfcvt.rtz.x.f.v	v0, v1     
# CHECK-ASM-AND-OBJ: vfcvt.rtz.x.f.v	v0, v1     
# encoding: [0x57,0x90,0x13,0x8a]

	vfwcvt.xu.f.v	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfwcvt.xu.f.v	v0, v1          
# CHECK-ASM: [0x57,0x10,0x14,0x8a]

	vfwcvt.x.f.v	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfwcvt.x.f.v	v0, v1          
# CHECK-ASM: [0x57,0x90,0x14,0x8a]

	vfwcvt.f.xu.v	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfwcvt.f.xu.v	v0, v1          
# CHECK-ASM: [0x57,0x10,0x15,0x8a]

	vfwcvt.f.x.v	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfwcvt.f.x.v	v0, v1          
# CHECK-ASM: [0x57,0x90,0x15,0x8a]

	vfwcvt.f.f.v	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfwcvt.f.f.v	v0, v1          
# CHECK-ASM: [0x57,0x10,0x16,0x8a]

  vfwcvt.rtz.xu.f.v v0, v1
# CHECK-ASM-AND-OBJ: vfwcvt.rtz.xu.f.v v0, v1
# CHECK-ASM: [0x57,0x10,0x17,0x8a]

	vfwcvt.rtz.x.f.v v0, v1
# CHECK-ASM-AND-OBJ: vfwcvt.rtz.x.f.v v0, v1
# CHECK-ASM: [0x57,0x90,0x17,0x8a]

	vfncvt.xu.f.w	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfncvt.xu.f.w	v0, v1          
# CHECK-ASM: [0x57,0x10,0x18,0x8a]

	vfncvt.x.f.w	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfncvt.x.f.w	v0, v1          
# CHECK-ASM: [0x57,0x90,0x18,0x8a]

	vfncvt.f.xu.w	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfncvt.f.xu.w	v0, v1          
# CHECK-ASM: [0x57,0x10,0x19,0x8a]

	vfncvt.f.x.w	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfncvt.f.x.w	v0, v1          
# CHECK-ASM: [0x57,0x90,0x19,0x8a]

	vfncvt.f.f.w	v0, v1          
# CHECK-ASM-AND-OBJ: 	vfncvt.f.f.w	v0, v1          
# CHECK-ASM: [0x57,0x10,0x1a,0x8a]

	vfncvt.rod.f.f.w	v0, v1  
# CHECK-ASM-AND-OBJ: 	vfncvt.rod.f.f.w	v0, v1  
# CHECK-ASM: [0x57,0x90,0x1a,0x8a]

	vfncvt.rtz.xu.f.w	v0, v1
# CHECK-ASM-AND-OBJ: vfncvt.rtz.xu.f.w	v0, v1
# CHECK-ASM: [0x57,0x10,0x1b,0x8a]

	vfncvt.rtz.x.f.w	v0, v1
# CHECK-ASM-AND-OBJ: vfncvt.rtz.x.f.w	v0, v1
# CHECK-ASM: [0x57,0x90,0x1b,0x8a]

	vredsum.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vredsum.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x02]

	vredmaxu.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vredmaxu.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x1a]

	vredmax.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vredmax.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x1e]

	vredminu.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vredminu.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x12]

	vredmin.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vredmin.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x16]

	vredand.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vredand.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x06]

	vredor.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vredor.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x0a]

	vredxor.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vredxor.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x0e]

	vwredsumu.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vwredsumu.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0xc2]

	vwredsum.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vwredsum.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0xc6]

	vfredosum.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfredosum.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x0e]

	vfredsum.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfredsum.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x06]

	vfredmax.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfredmax.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x1e]

	vfredmin.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfredmin.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0x16]

	vfwredosum.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfwredosum.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0xce]

	vfwredsum.vs	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfwredsum.vs	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0xc6]

	vzext.vf2 v0, v1
# CHECK-ASM-AND-OBJ: 	vzext.vf2 v0, v1 	
# CHECK-ASM: [0x57,0x00,0x13,0x4a]

	vsext.vf2 v0, v1
# CHECK-ASM-AND-OBJ: 	vsext.vf2 v0, v1 	
# CHECK-ASM: [0x57,0x80,0x13,0x4a]

	vzext.vf4 v0, v1
# CHECK-ASM-AND-OBJ: 	vzext.vf4 v0, v1 	
# CHECK-ASM: [0x57,0x00,0x12,0x4a]

	vsext.vf4 v0, v1
# CHECK-ASM-AND-OBJ: 	vsext.vf4 v0, v1 	
# CHECK-ASM: [0x57,0x80,0x12,0x4a]

	vzext.vf8 v0, v1
# CHECK-ASM-AND-OBJ: 	vzext.vf8 v0, v1 	
# CHECK-ASM: [0x57,0x00,0x11,0x4a]

	vsext.vf8 v0, v1
# CHECK-ASM-AND-OBJ: 	vsext.vf8 v0, v1 	
# CHECK-ASM: [0x57,0x80,0x11,0x4a]

	vmand.mm	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmand.mm	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x66]

	vmnand.mm	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmnand.mm	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x76]

	vmandnot.mm	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmandnot.mm	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x62]

	vmxor.mm	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmxor.mm	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x6e]

	vmor.mm	v0, v1, v0              
# CHECK-ASM-AND-OBJ: 	vmor.mm	v0, v1, v0              
# CHECK-ASM: [0x57,0x20,0x10,0x6a]

	vmnor.mm	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmnor.mm	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x7a]

	vmornot.mm	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmornot.mm	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x72]

	vmxnor.mm	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vmxnor.mm	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x7e]

	vpopc.m	a0, v1                  
# CHECK-ASM-AND-OBJ: 	vpopc.m	a0, v1                  
# CHECK-ASM: [0x57,0x25,0x18,0x42]

	vfirst.m	a0, v1          
# CHECK-ASM-AND-OBJ: 	vfirst.m	a0, v1          
# CHECK-ASM: [0x57,0xa5,0x18,0x42]

	vmsbf.m	v0, v1                  
# CHECK-ASM-AND-OBJ: 	vmsbf.m	v0, v1                  
# CHECK-ASM: [0x57,0xa0,0x10,0x52]

	vmsif.m	v0, v1                  
# CHECK-ASM-AND-OBJ: 	vmsif.m	v0, v1                  
# CHECK-ASM: [0x57,0xa0,0x11,0x52]

	vmsof.m	v0, v1                  
# CHECK-ASM-AND-OBJ: 	vmsof.m	v0, v1                  
# CHECK-ASM: [0x57,0x20,0x11,0x52]

	viota.m	v0, v1                  
# CHECK-ASM-AND-OBJ: 	viota.m	v0, v1                  
# CHECK-ASM: [0x57,0x20,0x18,0x52]

	vid.v	v0                      
# CHECK-ASM-AND-OBJ: 	vid.v	v0                      
# CHECK-ASM: [0x57,0xa0,0x08,0x52]

	vmv.x.s	a0, v1                  
# CHECK-ASM-AND-OBJ: 	vmv.x.s	a0, v1                  
# CHECK-ASM: [0x57,0x25,0x10,0x42]

	vmv.s.x	v0, a1                  
# CHECK-ASM-AND-OBJ: 	vmv.s.x	v0, a1                  
# CHECK-ASM: [0x57,0xe0,0x05,0x42]

	vfmv.f.s	ft0, v1         
# CHECK-ASM-AND-OBJ: 	vfmv.f.s	ft0, v1         
# CHECK-ASM: [0x57,0x10,0x10,0x42]

	vfmv.s.f	v0, ft1         
# CHECK-ASM-AND-OBJ: 	vfmv.s.f	v0, ft1         
# CHECK-ASM: [0x57,0xd0,0x00,0x42]

	vslideup.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vslideup.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x3a]

	vslideup.vi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vslideup.vi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0x3a]

	vslidedown.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vslidedown.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x3e]

	vslidedown.vi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vslidedown.vi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0x3e]

	vslide1up.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vslide1up.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0x3a]

	vslide1down.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vslide1down.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x60,0x15,0x3e]

  vfslide1up.vf v0, v1, ft0
# CHECK-ASM-AND-OBJ:  vfslide1up.vf v0, v1, ft0
# CHECK-ASM: [0x57,0x50,0x10,0x3a]
 
  vfslide1down.vf v0, v1, ft0
# CHECK-ASM-AND-OBJ:  vfslide1down.vf v0, v1, ft0
# CHECK-ASM: [0x57,0x50,0x10,0x3e]

	vrgather.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vrgather.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0x32]

	vrgather.vx	v0, v1, a0      
# CHECK-ASM-AND-OBJ: 	vrgather.vx	v0, v1, a0      
# CHECK-ASM: [0x57,0x40,0x15,0x32]

	vrgather.vi	v0, v1, 0       
# CHECK-ASM-AND-OBJ: 	vrgather.vi	v0, v1, 0       
# CHECK-ASM: [0x57,0x30,0x10,0x32]

	vcompress.vm	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vcompress.vm	v0, v1, v0      
# CHECK-ASM: [0x57,0x20,0x10,0x5e]

	vmv1r.v	v0, v8                  
# CHECK-ASM-AND-OBJ: 	vmv1r.v	v0, v8                  
# CHECK-ASM: [0x57,0x30,0x80,0x9e]

	vmv2r.v	v0, v8                  
# CHECK-ASM-AND-OBJ: 	vmv2r.v	v0, v8                  
# CHECK-ASM: [0x57,0xb0,0x80,0x9e]

	vmv3r.v	v0, v8                  
# CHECK-ASM-AND-OBJ: 	vmv3r.v	v0, v8                  
# CHECK-ASM: [0x57,0x30,0x81,0x9e]

	vmv4r.v	v0, v8                  
# CHECK-ASM-AND-OBJ: 	vmv4r.v	v0, v8                  
# CHECK-ASM: [0x57,0xb0,0x81,0x9e]

	vmv5r.v	v0, v8                  
# CHECK-ASM-AND-OBJ: 	vmv5r.v	v0, v8                  
# CHECK-ASM: [0x57,0x30,0x82,0x9e]

	vmv6r.v	v0, v8                  
# CHECK-ASM-AND-OBJ: 	vmv6r.v	v0, v8                  
# CHECK-ASM: [0x57,0xb0,0x82,0x9e]

	vmv7r.v	v0, v8                  
# CHECK-ASM-AND-OBJ: 	vmv7r.v	v0, v8                  
# CHECK-ASM: [0x57,0x30,0x83,0x9e]

	vmv8r.v	v0, v8                  
# CHECK-ASM-AND-OBJ: 	vmv8r.v	v0, v8                  
# CHECK-ASM: [0x57,0xb0,0x83,0x9e]

	vdotu.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vdotu.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x00,0x10,0xe2]

	vdot.vv	v0, v1, v0              
# CHECK-ASM-AND-OBJ: 	vdot.vv	v0, v1, v0              
# CHECK-ASM: [0x57,0x00,0x10,0xe6]

	vfdot.vv	v0, v1, v0      
# CHECK-ASM-AND-OBJ: 	vfdot.vv	v0, v1, v0      
# CHECK-ASM: [0x57,0x10,0x10,0xe6]

	vmcpy.m v0, v1
# CHECK-ASM-AND-OBJ:  vmand.mm	v0, v1, v1
# CHECK-ASM: [0x57,0xa0,0x10,0x66]

	vmmv.m v0, v1
# CHECK-ASM-AND-OBJ:  vmand.mm	v0, v1, v1
# CHECK-ASM: [0x57,0xa0,0x10,0x66]

  vle128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vle128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x12]

  vle256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vle256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x12]

  vle512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vle512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x12]

  vle1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vle1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x12]

  vlseg2e128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg2e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x32]

  vlseg2e256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg2e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x32]

  vlseg2e512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg2e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x32]

  vlseg2e1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg2e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x32]

  vlseg3e128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg3e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x52]

  vlseg3e256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg3e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x52]

  vlseg3e512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg3e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x52]

  vlseg3e1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg3e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x52]

  vlseg4e128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg4e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x72]

  vlseg4e256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg4e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x72]

  vlseg4e512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg4e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x72]

  vlseg4e1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg4e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x72]

  vlseg5e128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg5e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0x92]

  vlseg5e256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg5e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0x92]

  vlseg5e512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg5e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0x92]

  vlseg5e1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg5e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0x92]

  vlseg6e128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg6e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xb2]

  vlseg6e256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg6e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xb2]

  vlseg6e512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg6e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xb2]

  vlseg6e1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg6e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xb2]

  vlseg7e128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg7e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xd2]

  vlseg7e256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg7e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xd2]

  vlseg7e512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg7e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xd2]

  vlseg7e1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg7e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xd2]

  vlseg8e128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg8e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0x80,0x05,0xf2]

  vlseg8e256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg8e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xd0,0x05,0xf2]

  vlseg8e512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg8e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xe0,0x05,0xf2]

  vlseg8e1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vlseg8e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x07,0xf0,0x05,0xf2]

  vlxei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x1e]

  vlxei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x1e]

  vlxei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x1e]

  vlxei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x1e]

  vlxseg2ei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg2ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x3e]

  vlxseg2ei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg2ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x3e]

  vlxseg2ei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg2ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x3e]

  vlxseg2ei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg2ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x3e]

  vlxseg3ei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg3ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x5e]

  vlxseg3ei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg3ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x5e]

  vlxseg3ei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg3ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x5e]

  vlxseg3ei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg3ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x5e]

  vlxseg4ei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg4ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x7e]

  vlxseg4ei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg4ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x7e]

  vlxseg4ei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg4ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x7e]

  vlxseg4ei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg4ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x7e]

  vlxseg5ei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg5ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0x9e]

  vlxseg5ei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg5ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0x9e]

  vlxseg5ei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg5ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0x9e]

  vlxseg5ei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg5ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0x9e]

  vlxseg6ei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg6ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xbe]

  vlxseg6ei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg6ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xbe]

  vlxseg6ei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg6ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xbe]

  vlxseg6ei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg6ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0xbe]

  vlxseg7ei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg7ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xde]

  vlxseg7ei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg7ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xde]

  vlxseg7ei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg7ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xde]

  vlxseg7ei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg7ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0xde]

  vlxseg8ei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg8ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0x80,0x25,0xfe]

  vlxseg8ei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg8ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xd0,0x25,0xfe]

  vlxseg8ei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg8ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xe0,0x25,0xfe]

  vlxseg8ei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vlxseg8ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x07,0xf0,0x25,0xfe]

  vlse128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlse128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x1a]

  vlse256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlse256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x1a]

  vlse512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlse512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x1a]

  vlse1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlse1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x1a]

  vlsseg2e128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg2e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x3a]

  vlsseg2e256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg2e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x3a]

  vlsseg2e512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg2e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x3a]

  vlsseg2e1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg2e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x3a]

  vlsseg3e128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg3e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x5a]

  vlsseg3e256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg3e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x5a]

  vlsseg3e512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg3e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x5a]

  vlsseg3e1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg3e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x5a]

  vlsseg4e128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg4e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x7a]

  vlsseg4e256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg4e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x7a]

  vlsseg4e512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg4e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x7a]

  vlsseg4e1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg4e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x7a]

  vlsseg5e128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg5e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0x9a]

  vlsseg5e256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg5e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0x9a]

  vlsseg5e512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg5e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0x9a]

  vlsseg5e1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg5e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0x9a]

  vlsseg6e128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg6e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xba]

  vlsseg6e256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg6e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xba]

  vlsseg6e512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg6e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xba]

  vlsseg6e1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg6e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0xba]

  vlsseg7e128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg7e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xda]

  vlsseg7e256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg7e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xda]

  vlsseg7e512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg7e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xda]

  vlsseg7e1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg7e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0xda]

  vlsseg8e128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg8e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0x80,0xc5,0xfa]

  vlsseg8e256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg8e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xd0,0xc5,0xfa]

  vlsseg8e512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg8e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xe0,0xc5,0xfa]

  vlsseg8e1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vlsseg8e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x07,0xf0,0xc5,0xfa]

  vse128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vse128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x12]

  vse256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vse256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x12]

  vse512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vse512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x12]

  vse1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vse1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x12]

  vsseg2e128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg2e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x32]

  vsseg2e256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg2e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x32]

  vsseg2e512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg2e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x32]

  vsseg2e1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg2e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x32]

  vsseg3e128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg3e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x52]

  vsseg3e256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg3e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x52]

  vsseg3e512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg3e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x52]

  vsseg3e1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg3e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x52]

  vsseg4e128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg4e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x72]

  vsseg4e256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg4e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x72]

  vsseg4e512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg4e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x72]

  vsseg4e1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg4e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x72]

  vsseg5e128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg5e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0x92]

  vsseg5e256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg5e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0x92]

  vsseg5e512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg5e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0x92]

  vsseg5e1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg5e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0x92]

  vsseg6e128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg6e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0xb2]

  vsseg6e256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg6e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0xb2]

  vsseg6e512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg6e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0xb2]

  vsseg6e1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg6e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0xb2]

  vsseg7e128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg7e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0xd2]

  vsseg7e256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg7e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0xd2]

  vsseg7e512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg7e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0xd2]

  vsseg7e1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg7e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0xd2]

  vsseg8e128.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg8e128.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0x80,0x05,0xf2]

  vsseg8e256.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg8e256.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xd0,0x05,0xf2]

  vsseg8e512.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg8e512.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xe0,0x05,0xf2]

  vsseg8e1024.v v0, 0(a1)
# CHECK-ASM-AND-OBJ: 	vsseg8e1024.v v0, 0(a1)
# CHECK-ASM: encoding:  [0x27,0xf0,0x05,0xf2]

  vsxei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x1e]

  vsxei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x1e]

  vsxei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x1e]

  vsxei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x1e]

  vsxseg2ei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg2ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x3e]

  vsxseg2ei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg2ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x3e]

  vsxseg2ei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg2ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x3e]

  vsxseg2ei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg2ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x3e]

  vsxseg3ei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg3ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x5e]

  vsxseg3ei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg3ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x5e]

  vsxseg3ei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg3ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x5e]

  vsxseg3ei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg3ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x5e]

  vsxseg4ei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg4ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x7e]

  vsxseg4ei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg4ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x7e]

  vsxseg4ei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg4ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x7e]

  vsxseg4ei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg4ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x7e]

  vsxseg5ei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg5ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0x9e]

  vsxseg5ei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg5ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0x9e]

  vsxseg5ei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg5ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0x9e]

  vsxseg5ei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg5ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0x9e]

  vsxseg6ei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg6ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0xbe]

  vsxseg6ei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg6ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0xbe]

  vsxseg6ei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg6ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0xbe]

  vsxseg6ei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg6ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0xbe]

  vsxseg7ei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg7ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0xde]

  vsxseg7ei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg7ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0xde]

  vsxseg7ei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg7ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0xde]

  vsxseg7ei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg7ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0xde]

  vsxseg8ei128.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg8ei128.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0x80,0x25,0xfe]

  vsxseg8ei256.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg8ei256.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xd0,0x25,0xfe]

  vsxseg8ei512.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg8ei512.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xe0,0x25,0xfe]

  vsxseg8ei1024.v v0, 0(a1), v2
# CHECK-ASM-AND-OBJ: 	vsxseg8ei1024.v v0, 0(a1), v2
# CHECK-ASM: encoding:  [0x27,0xf0,0x25,0xfe]

  vsse128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vsse128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x1a]

  vsse256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vsse256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x1a]

  vsse512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vsse512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x1a]

  vsse1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vsse1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x1a]

  vssseg2e128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg2e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x3a]

  vssseg2e256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg2e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x3a]

  vssseg2e512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg2e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x3a]

  vssseg2e1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg2e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x3a]

  vssseg3e128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg3e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x5a]

  vssseg3e256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg3e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x5a]

  vssseg3e512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg3e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x5a]

  vssseg3e1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg3e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x5a]

  vssseg4e128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg4e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x7a]

  vssseg4e256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg4e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x7a]

  vssseg4e512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg4e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x7a]

  vssseg4e1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg4e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x7a]

  vssseg5e128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg5e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0x9a]

  vssseg5e256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg5e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0x9a]

  vssseg5e512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg5e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0x9a]

  vssseg5e1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg5e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0x9a]

  vssseg6e128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg6e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xba]

  vssseg6e256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg6e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xba]

  vssseg6e512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg6e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xba]

  vssseg6e1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg6e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xba]

  vssseg7e128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg7e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xda]

  vssseg7e256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg7e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xda]

  vssseg7e512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg7e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xda]

  vssseg7e1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg7e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xda]

  vssseg8e128.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg8e128.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0x80,0xc5,0xfa]

  vssseg8e256.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg8e256.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xd0,0xc5,0xfa]

  vssseg8e512.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg8e512.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xe0,0xc5,0xfa]

  vssseg8e1024.v v0, 0(a1), a2
# CHECK-ASM-AND-OBJ: 	vssseg8e1024.v v0, 0(a1), a2
# CHECK-ASM: encoding:  [0x27,0xf0,0xc5,0xfa]

