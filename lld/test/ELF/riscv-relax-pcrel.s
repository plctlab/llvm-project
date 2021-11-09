# REQUIRES: riscv

# RUN: llvm-mc -filetype=obj -triple=riscv32-unknown-elf -mattr=+relax %s -o %t.rv32.o
# RUN: llvm-mc -filetype=obj -triple=riscv64-unknown-elf -mattr=+relax %s -o %t.rv64.o

# RUN: echo 'SECTIONS { .text 0x100000 : { *(.text) } .sdata 0x200000 : { foo = .; } }' > %t.lds
# RUN: ld.lld --undefined=__global_pointer$ %t.rv32.o %t.lds -o %t.rv32
# RUN: ld.lld --undefined=__global_pointer$ %t.rv64.o %t.lds -o %t.rv64
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t.rv32 | FileCheck --check-prefix=GP %s
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t.rv64 | FileCheck --check-prefix=GP %s
# GP-NOT:  auipc
# GP:      addi    a0, gp, -2048
# GP-NEXT: sw      a0, -2048(gp)

# RUN: echo 'SECTIONS { .text 0x100000 : { *(.text) } .sdata 0x200000 : { foo = . + 4096; } }' > %t-norelax.lds
# RUN: ld.lld --undefined=__global_pointer$ %t.rv32.o %t-norelax.lds -o %t-norelax.rv32
# RUN: ld.lld --undefined=__global_pointer$ %t.rv64.o %t-norelax.lds -o %t-norelax.rv64
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t-norelax.rv32 | FileCheck --check-prefix=NORELAX %s
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t-norelax.rv64 | FileCheck --check-prefix=NORELAX %s
# NORELAX:      auipc   a0, 257
# NORELAX-NEXT: addi    a0, a0, 0
# NORELAX-NEXT: sw      a0, 0(a0)

.global _start
_start:
  auipc a0, %pcrel_hi(foo)
  addi a0, a0, %pcrel_lo(_start)
  sw a0, %pcrel_lo(_start)(a0)
