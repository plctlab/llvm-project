# REQUIRES: riscv
# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+relax %s -o %t.32.o
# RUN: ld.lld -pie %t.32.o -o %t.32
# RUN: llvm-readelf -s %t.32 | FileCheck --check-prefix=SYM32 %s
# RUN: llvm-readelf -S %t.32 | FileCheck --check-prefix=SEC32 %s
# RUN: llvm-objdump -d --print-imm-hex %t.32 | FileCheck --check-prefix=DIS32 %s
# RUN: not ld.lld -shared %t.32.o -o /dev/null 2>&1 | FileCheck --check-prefix=ERR %s

# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=+relax %s -o %t.64.o
# RUN: ld.lld -pie %t.64.o -o %t.64
# RUN: llvm-readelf -s %t.64 | FileCheck --check-prefix=SYM64 %s
# RUN: llvm-readelf -S %t.64 | FileCheck --check-prefix=SEC64 %s
# RUN: llvm-objdump -d %t.64 | FileCheck --check-prefix=DIS64 %s
# RUN: not ld.lld -shared %t.64.o -o /dev/null 2>&1 | FileCheck --check-prefix=ERR %s

## __global_pointer$ = .sdata+0x800 = 0x39c0
# SEC32: [ 7] .sdata PROGBITS {{0*}}000031c0
# SYM32: {{0*}}000039c0 0 NOTYPE GLOBAL DEFAULT 7 __global_pointer$

# SEC64: [ 7] .sdata PROGBITS {{0*}}000032e0
# SYM64: {{0*}}00003ae0 0 NOTYPE GLOBAL DEFAULT 7 __global_pointer$

# DIS32:      auipc gp, 3
# DIS32-NEXT: addi gp, gp, -1968

# DIS64:      auipc gp, 3
# DIS64-NEXT: addi gp, gp, -1896

# ERR: error: relocation R_RISCV_PCREL_HI20 cannot be used against symbol __global_pointer$; recompile with -fPIC

.option norelax
lla gp, __global_pointer$

.section .sdata,"aw"
