# REQUIRES: riscv

# RUN: llvm-mc -filetype=obj -triple=riscv64-unknown-elf -mattr=+zce-lsgp,+relax %s -o %t.rv64relax.o
# RUN: llvm-mc -filetype=obj -triple=riscv64-unknown-elf -mattr=+zce-lsgp %s -o %t.rv64.o

# RUN: echo 'SECTIONS { .text : { *(.text) } .sdata 0x200000 : { gI = .+0x100; gStart = .+0x6500; } }' > %t.lds
# RUN: ld.lld --undefined=__global_pointer$ %t.rv64relax.o %t.lds -o %t.rv64relax -mzce-lsgp
# RUN: ld.lld --undefined=__global_pointer$ %t.rv64.o %t.lds -o %t.rv64 -mzce-lsgp --no-relax

# RUN: llvm-objdump  --triple=riscv64 --mattr=+c,+m,+a,+experimental-zce -d -M no-aliases --no-show-raw-insn %t.rv64relax | FileCheck --check-prefix=LSGP-RELAX %s
# RUN: llvm-objdump  --triple=riscv64 --mattr=+c,+m,+a,+experimental-zce -d -M no-aliases --no-show-raw-insn %t.rv64 | FileCheck --check-prefix=LSGP %s


# LSGP-RELAX:       addi  a0, gp, -1792
# LSGP-RELAX-NEXT:  lwgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  swgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  ldgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  sdgp    a0, -1792(gp)

# LSGP-RELAX:       addi    a0, a0, 1280
# LSGP-RELAX-NEXT:  lwgp    a0, 23808(gp)
# LSGP-RELAX-NEXT:  swgp    a0, 23808(gp)
# LSGP-RELAX-NEXT:  ldgp    a0, 23808(gp)
# LSGP-RELAX-NEXT:  sdgp    a0, 23808(gp)

# LSGP-RELAX-NEXT:  lwgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  lwgp    a0, 23808(gp)
# LSGP-RELAX-NEXT:  swgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  swgp    a0, 23808(gp)

# LSGP-RELAX-NEXT:  ldgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  ldgp    a0, 23808(gp)
# LSGP-RELAX-NEXT:  sdgp    a0, -1792(gp)
# LSGP-RELAX-NEXT:  sdgp    a0, 23808(gp)

# LSGP-RELAX-NEXT:  lw a0, 256(a0)

# LSGP:       addi  a0, a0, 256
# LSGP-NEXT:  lw    a0, 256(a0)
# LSGP-NEXT:  sw    a0, 256(a0)
# LSGP-NEXT:  ld    a0, 256(a0)
# LSGP-NEXT:  sd    a0, 256(a0)

# LSGP:       addi  a0, a0, 1280
# LSGP-NEXT:  lw    a0, 1280(a0)
# LSGP-NEXT:  sw    a0, 1280(a0)
# LSGP-NEXT:  ld    a0, 1280(a0)
# LSGP-NEXT:  sd    a0, 1280(a0)

# LSGP-NEXT:  lwgp  a0, -1792(gp)
# LSGP-NEXT:  lwgp  a0, 23808(gp)
# LSGP-NEXT:  swgp  a0, -1792(gp)
# LSGP-NEXT:  swgp  a0, 23808(gp)

# LSGP-NEXT:  ldgp  a0, -1792(gp)
# LSGP-NEXT:  ldgp  a0, 23808(gp)
# LSGP-NEXT:  sdgp  a0, -1792(gp)
# LSGP-NEXT:  sdgp  a0, 23808(gp)

# LSGP-NEXT:  lw a0, 256(a0)

.global _start
_start:
  addi a0, a0, %lo(gI)
  lw a0, %lo(gI)(a0)
  sw a0, %lo(gI)(a0)
  ld a0, %lo(gI)(a0)
  sd a0, %lo(gI)(a0)
  
  addi a0, a0, %lo(gStart)
  lw a0, %lo(gStart)(a0)
  sw a0, %lo(gStart)(a0)
  ld a0, %lo(gStart)(a0)
  sd a0, %lo(gStart)(a0)

  lwgp a0, %lo(gI)(gp)
  lwgp a0, %lo(gStart)(gp)
  swgp a0, %lo(gI)(gp)
  swgp a0, %lo(gStart)(gp)

  ldgp a0, %lo(gI)(gp)
  ldgp a0, %lo(gStart)(gp)
  sdgp a0, %lo(gI)(gp)
  sdgp a0, %lo(gStart)(gp)

  lw a0, 256(a0)
  sw a0, 256(a0)