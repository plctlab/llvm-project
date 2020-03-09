# RISC-V Vector Extension in LLVM

This is the RISC-V Vector Extension in LLVM implemented by PLCT Group, ISRC, Institute of software, Chinese Academy of Sciences.

The assembly instructions of RVV current stable release, v0.8, are now supported.

## How to Build LLVM for RISC-V Target

	$ git clone git@github.com:isrc-cas/rvv-llvm.git
	$ cd rvv-llvm
	$ mkdir build
	$ cd build
	$ cmake -DLLVM_TARGETS_TO_BUILD="X86;RISCV" -DLLVM_ENABLE_PROJECTS=clang  -G "Unix Makefiles" ../llvm
	$ make

## How to Run the RVV tests

We added 4 test files for RVV instructions:

	rvv-llvm/llvm/test/MC/RISCV/rvv-valid.s
	.........................../rvv-mask-valid.s
	.........................../rvv-pseudo-valid.s
	.........................../rvv-pseudo-mask-valid.s

You can use **llvm-lit** to run the tests:

	$ llvm-lit rvv-llvm/llvm/test/MC/RISCV/rvv*

You can also use **FileCheck** to run each test seperately:

	$ llvm-mc %s -triple=riscv32 --mattr=+v -riscv-no-aliases -show-encoding \
	$  | FileCheck -check-prefixes=CHECK-ASM,CHECK-ASM-AND-OBJ %s

## How to Assemble RVV Assembly Files

You can use **llvm-mc** to assemble RVV assembly file and generate an object file:

	$ llvm-mc test.s -triple=riscv32 --mattr=+v -riscv-no-aliases -show-encoding --filetype=obj -o=test.o

