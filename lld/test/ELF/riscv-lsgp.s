# REQUIRES: riscv

# RUN: llvm-mc -filetype=obj -triple=riscv32-unknown-elf -mattr=+zce-lsgp,+relax %s -o %t.rv32.o
# RUN: llvm-mc -filetype=obj -triple=riscv64-unknown-elf -mattr=+zce-lsgp,+relax %s -o %t.rv64.o

# RUN: echo 'SECTIONS { .text : { *(.text) } .sdata 0x200000 : { gI = .+0x100; gStart = .+0x6500; } }' > %t.lds
# RUN: ld.lld --undefined=__global_pointer$ %t.rv32.o %t.lds -o %t.rv32 -mzce-lsgp
# RUN: ld.lld --undefined=__global_pointer$ %t.rv64.o %t.lds -o %t.rv64 -mzce-lsgp

# RUN: llvm-objdump  --triple=riscv32 --mattr=+c,+m,+a,+experimental-zce -d -M no-aliases --no-show-raw-insn  %t.rv32 | FileCheck --check-prefix=LSGP %s
# RUN: llvm-objdump  --triple=riscv64 --mattr=+c,+m,+a,+experimental-zce -d -M no-aliases --no-show-raw-insn %t.rv64 | FileCheck --check-prefix=LSGP %s

# LSGP:       addi  a0, gp, -1792
# LSGP-NEXT:  lwgp    a0, -1792(gp)
# LSGP-NEXT:  sw      a0, -1792(gp)
# LSGP:       addi    a0, a0, 1280
# LSGP-NEXT:  lwgp    a0, 23808(gp)
# LSGP-NEXT:  sw      a0, 1280(a0)
# LSGP-NEXT:  lwgp    a0, -1792(gp)
# LSGP-NEXT:  lwgp    a0, 23808(gp)
# LSGP-NEXT:  lw a0, 256(a0)

.global _start
_start:
  addi a0, a0, %lo(gI)
  lw a0, %lo(gI)(a0)
  sw a0, %lo(gI)(a0)
  
  addi a0, a0, %lo(gStart)
  lw a0, %lo(gStart)(a0)
  sw a0, %lo(gStart)(a0)

  lwgp a0, %lo(gI)(gp)
  lwgp a0, %lo(gStart)(gp)

  lw a0, 256(a0)