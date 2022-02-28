# REQUIRES: riscv

# RUN: llvm-mc -filetype=obj -triple=riscv32-unknown-elf -mattr=+zce-lsgp,+relax %s -o %t.rv32relax.o
# RUN: llvm-mc -filetype=obj -triple=riscv32-unknown-elf -mattr=+zce-lsgp %s -o %t.rv32.o

# RUN: echo 'SECTIONS { .text : { *(.text) } .sdata 0x200000 : { gI = .+0x100; gStart = .+0x6500; } }' > %t.lds
# RUN: ld.lld --undefined=__global_pointer$ %t.rv32relax.o %t.lds -o %t.rv32relax -mzce-lsgp
# RUN: ld.lld --undefined=__global_pointer$ %t.rv32.o %t.lds -o %t.rv32 -mzce-lsgp --no-relax

# RUN: llvm-objdump  --triple=riscv32 --mattr=+c,+m,+a,+zce-lsgp -M no-aliases --no-show-raw-insn  %t.rv32 | FileCheck --check-prefix=LSGP %s
# RUN: llvm-objdump  --triple=riscv32 --mattr=+c,+m,+a,+zce-lsgp -d -M no-aliases --no-show-raw-insn  %t.rv32relax | FileCheck --check-prefix=LSGP-RELAX %s

# LSGP:       lui   a0, 512
# LSGP-NEXT:  addi  a1, a0, 256
# LSGP-NEXT:  lui   a0, 512
# LSGP-NEXT:  lw    a0, 256(a0)
# LSGP-NEXT:  lui   a0, 512
# LSGP-NEXT:  sw    a0, 256(a0)

# LSGP:       lui   a0, 518
# LSGP-NEXT:  addi  a1, a0, 1280
# LSGP-NEXT:  lui   a0, 518
# LSGP-NEXT:  lw    a0, 1280(a0)
# LSGP-NEXT:  lui   a0, 518
# LSGP-NEXT:  sw    a0, 1280(a0)

# LSGP-NEXT:  lwgp  a0, -1792(gp)
# LSGP-NEXT:  swgp  a0, -1792(gp)
# LSGP-NEXT:  lwgp  a0, 23808(gp)
# LSGP-NEXT:  swgp  a0, 23808(gp)

# LSGP-RELAX:       addi    a1, gp, -1792
# LSGP-RELAX-NEXT:  lwgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  swgp    a0, -1792(gp)

# LSGP-RELAX-NEXT:  lui     a0, 518
# LSGP-RELAX-NEXT:  addi    a1, a0, 1280
# LSGP-RELAX-NEXT:  lwgp    a0, 23808(gp)
# LSGP-RELAX-NEXT:  swgp    a0, 23808(gp)

# LSGP-RELAX-NEXT:  lwgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  swgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  lwgp    a0, 23808(gp)
# LSGP-RELAX-NEXT:  swgp    a0, 23808(gp)

.global _start
_start:
  lui a0, %hi(gI)
  addi a1, a0, %lo(gI)
  lui a0, %hi(gI)
  lw a0, %lo(gI)(a0)
  lui a0, %hi(gI)
  sw a0, %lo(gI)(a0)
  
  lui a0, %hi(gStart)
  addi a1, a0, %lo(gStart)
  lui a0, %hi(gStart)
  lw a0, %lo(gStart)(a0)
  lui a0, %hi(gStart)
  sw a0, %lo(gStart)(a0)

  lwgp a0, %lo(gI)(gp)
  swgp a0, %lo(gI)(gp)
  lwgp a0, %lo(gStart)(gp)
  swgp a0, %lo(gStart)(gp)
