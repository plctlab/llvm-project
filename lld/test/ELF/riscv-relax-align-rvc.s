# REQUIRES: riscv

# RUN: llvm-mc -filetype=obj -triple=riscv32-unknown-elf -mattr=+c,+relax %s -o %t.rv32.o
# RUN: llvm-mc -filetype=obj -triple=riscv64-unknown-elf -mattr=+c,+relax %s -o %t.rv64.o

# RUN: ld.lld %t.rv32.o -o %t.rv32
# RUN: ld.lld %t.rv64.o -o %t.rv64
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t.rv32 | FileCheck %s
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t.rv64 | FileCheck %s

# CHECK:      c.add   a0, a1
# CHECK-NEXT: addi    zero, zero, 0
# CHECK-NEXT: addi    zero, zero, 0
# CHECK-NEXT: addi    zero, zero, 0
# CHECK-NEXT: c.nop
# CHECK-NEXT: c.add   s0, s1
# CHECK-NEXT: c.add   s2, s3
# CHECK-NEXT: c.add   s4, s5
# CHECK-NEXT: c.nop
# CHECK-NEXT: c.add   t0, t1

.global _start
_start:
.balign 4
  c.add a0, a1
.balign 16
  c.add s0, s1
  c.add s2, s3
  c.add s4, s5
.balign 8
  c.add t0, t1
