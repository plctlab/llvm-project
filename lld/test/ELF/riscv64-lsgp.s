# REQUIRES: riscv

# RUN: llvm-mc -filetype=obj -triple=riscv64-unknown-elf -mattr=+zce-lsgp,+relax %s -o %t.rv64relax.o
# RUN: llvm-mc -filetype=obj -triple=riscv64-unknown-elf -mattr=+zce-lsgp %s -o %t.rv64.o

# RUN: echo 'SECTIONS { .text : { *(.text) } .sdata 0x200000 : { gI = .+0x100; gStart = .+0x6500; } }' > %t.lds
# RUN: ld.lld --undefined=__global_pointer$ %t.rv64relax.o %t.lds -o %t.rv64relax -mzce-lsgp
# RUN: ld.lld --undefined=__global_pointer$ %t.rv64.o %t.lds -o %t.rv64 -mzce-lsgp --no-relax

# RUN: llvm-objdump  --triple=riscv64 -d  --mattr=+c,+m,+a,+zce-lsgp -M no-aliases --no-show-raw-insn %t.rv64 | FileCheck --check-prefix=LSGP %s
# RUN: llvm-objdump  --triple=riscv64 -d --mattr=+c,+m,+a,+zce-lsgp -M no-aliases --no-show-raw-insn %t.rv64relax | FileCheck --check-prefix=LSGP-RELAX %s


# LSGP:       lui   a0, 512
# LSGP-NEXT:  addi  a1, a0, 256
# LSGP-NEXT:  lui   a0, 512
# LSGP-NEXT:  lw    a0, 256(a0)
# LSGP-NEXT:  lui   a0, 512
# LSGP-NEXT:  sw    a0, 256(a0)
# LSGP-NEXT:  lui   a0, 512
# LSGP-NEXT:  ld    a0, 256(a0)
# LSGP-NEXT:  lui   a0, 512
# LSGP-NEXT:  sd    a0, 256(a0)

# LSGP:       lui   a0, 518
# LSGP-NEXT:  addi  a1, a0, 1280
# LSGP-NEXT:  lui   a0, 518
# LSGP-NEXT:  lw    a0, 1280(a0)
# LSGP-NEXT:  lui   a0, 518
# LSGP-NEXT:  sw    a0, 1280(a0)
# LSGP-NEXT:  lui   a0, 518
# LSGP-NEXT:  ld    a0, 1280(a0)
# LSGP-NEXT:  lui   a0, 518
# LSGP-NEXT:  sd    a0, 1280(a0)

# LSGP-NEXT:  lwgp  a0, -1792(gp)
# LSGP-NEXT:  swgp  a0, -1792(gp)
# LSGP-NEXT:  lwgp  a0, 23808(gp)
# LSGP-NEXT:  swgp  a0, 23808(gp)

# LSGP-NEXT:  ldgp  a0, -1792(gp)
# LSGP-NEXT:  sdgp  a0, -1792(gp)
# LSGP-NEXT:  ldgp  a0, 23808(gp)
# LSGP-NEXT:  sdgp  a0, 23808(gp)

# LSGP-RELAX:       addi    a1, gp, -1792
# LSGP-RELAX-NEXT:  lwgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  swgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  ldgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  sdgp    a0, -1792(gp)

# LSGP-RELAX-NEXT:  lui     a0, 518
# LSGP-RELAX-NEXT:  addi    a1, a0, 1280
# LSGP-RELAX-NEXT:  lwgp    a0, 23808(gp)
# LSGP-RELAX-NEXT:  swgp    a0, 23808(gp)
# LSGP-RELAX-NEXT:  ldgp    a0, 23808(gp)
# LSGP-RELAX-NEXT:  sdgp    a0, 23808(gp)

# LSGP-RELAX-NEXT:  lwgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  swgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  lwgp    a0, 23808(gp)
# LSGP-RELAX-NEXT:  swgp    a0, 23808(gp)

# LSGP-RELAX-NEXT:  ldgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  sdgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  ldgp    a0, 23808(gp)
# LSGP-RELAX-NEXT:  sdgp    a0, 23808(gp)


.global _start
_start:
  lui a0, %hi(gI)
  addi a1, a0, %lo(gI)
  lui a0, %hi(gI)
  lw a0, %lo(gI)(a0)
  lui a0, %hi(gI)
  sw a0, %lo(gI)(a0)
  lui a0, %hi(gI)
  ld a0, %lo(gI)(a0)
  lui a0, %hi(gI)
  sd a0, %lo(gI)(a0)
  
  lui a0, %hi(gStart)
  addi a1, a0, %lo(gStart)
  lui a0, %hi(gStart)
  lw a0, %lo(gStart)(a0)
  lui a0, %hi(gStart)
  sw a0, %lo(gStart)(a0)
  lui a0, %hi(gStart)
  ld a0, %lo(gStart)(a0)
  lui a0, %hi(gStart)
  sd a0, %lo(gStart)(a0)

  lwgp a0, %lo(gI)(gp)
  swgp a0, %lo(gI)(gp)
  lwgp a0, %lo(gStart)(gp)
  swgp a0, %lo(gStart)(gp)

  ldgp a0, %lo(gI)(gp)
  sdgp a0, %lo(gI)(gp)
  ldgp a0, %lo(gStart)(gp)
  sdgp a0, %lo(gStart)(gp)
