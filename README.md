# RISC-V Vector Extension in LLVM

This is the RISC-V Vector Extension in LLVM implemented by PLCT Group, ISRC, Institute of software, Chinese Academy of Sciences.

The assembly instructions of RVV current stable release, v0.9, are now supported.

## How to Build LLVM for RISC-V Target

	$ git clone https://github.com/isrc-cas/rvv-llvm.git
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

	$ llvm-mc test.s -triple=riscv32 --mattr=+v -riscv-no-aliases -show-encoding --filetype=obj -o test.o  
	
Note: "test.s" here means an assembly file containing riscv vector extension instructions, you can use inline assembly in c++ code to add a riscv vector instruction and then use clang to compile and generate test.s assembly file. 

    $ clang --target=riscv64-unknown-elf -S  test.c -march=rv64gcv -mabi=lp64 --sysroot=/home/u/tools/riscv64/install/riscv64-unknown-elf  --gcc-toolchain=/home/u/tools/riscv64/install  -o test.s `

```  
#include<stdio.h> 

int main(){
    
  size_t a,b,c;
  a = 1;
  b = 2;
  asm volatile
  (
    "vsetvl  %[z], %[x], %[y]\n\t"
    : [z] "=r" (c)
    : [x] "r" (a), [y] "r" (b)
  );
  if ( c == 0 ){
     return -1;
  }
  return 0;
}  
```  

## How to Disassemble RVV Object code

You can use **llvm-objdump** to disassemble RVV object code file and generate assembly file:

	$ llvm-objdump test.o --mattr=+v 

## How to compile rvv instrinsic functions

To use the rvv instrinsic function, you need include the header file for rvv intrinsic:

	$ #include <riscv_vector.h>

then use the clang to compile the code and link to a executable file

	$ ./clang --target=riscv64-unknown-elf -march=rv64gv hello.c --sysroot=/opt/riscv64/riscv64-unknown-elf  --gcc-toolchain=/opt/riscv64 -o hello

Note that the --sysroot and --gcc-toolchain path are depend on how you install the
gcc toolchain