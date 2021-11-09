# REQUIRES: riscv

# RUN: llvm-mc -filetype=obj -triple=riscv32-unknown-elf -mattr=+relax %s -o %t.rv32.o
# RUN: llvm-mc -filetype=obj -triple=riscv64-unknown-elf -mattr=+relax %s -o %t.rv64.o

# RUN: ld.lld %t.rv32.o -o %t.rv32
# RUN: ld.lld %t.rv64.o -o %t.rv64
# RUN: llvm-objdump -d --no-show-raw-insn %t.rv32 | FileCheck %s
# RUN: llvm-objdump -d --no-show-raw-insn %t.rv64 | FileCheck %s

# Check that alignment is always handled regardless of --relax option
# RUN: ld.lld --no-relax %t.rv32.o -o %t-no-relax.rv32
# RUN: ld.lld --no-relax %t.rv64.o -o %t-no-relax.rv64
# RUN: llvm-objdump -d --no-show-raw-insn %t-no-relax.rv32 | FileCheck %s
# RUN: llvm-objdump -d --no-show-raw-insn %t-no-relax.rv64 | FileCheck %s

# CHECK:      add     a0, a1, a2
# CHECK-NEXT: add     a3, a4, a5
# CHECK-NEXT: nop
# CHECK-NEXT: nop
# CHECK-NEXT: add     s0, s1, s2
# CHECK-NEXT: add     t0, t1, t2

.global _start
_start:
.balign 4
  add a0, a1, a2
  add a3, a4, a5
.balign 16
  add s0, s1, s2
.balign 4
.balign 4
  add t0, t1, t2
