# REQUIRES: riscv

#  llvm-mc -filetype=obj -triple=riscv32 -mattr=+relax,+Zce %s -o %t.rv32.o
# RUN: llvm-mc -filetype=obj -triple=riscv64- -mattr=+relax %s -o %t.rv64.o
#  llvm-mc -filetype=obj -triple=riscv32 -mattr=+c,+relax %s -o %t.rv32c.o
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=+c,+relax %s -o %t.rv64c.o

# tbljal conversion
#  ld.lld %t.rv32.o -zce-tbljal --defsym foo=_start+20 -o %t.rv32
# RUN: ld.lld %t.rv64.o -zce-tbljal --defsym foo=_start+20 -o %t.rv64
#  llvm-objdump -d -M no-aliases --no-show-raw-insn %t.rv32 | FileCheck --check-prefix=TBLJAL %s
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t.rv64 | FileCheck --check-prefix=TBLJAL %s
# TBLJAL:      tbljalm 0
# TBLJAL-NEXT: tbljalm 0

# Check the bounds of what would be out of range (for the first call) for other jump types.
#  ld.lld %t.rv32c.o -zce-tbljal --defsym foo=_start+0x100000 -o %t-boundary.rv32
# RUN: ld.lld %t.rv64c.o -zce-tbljal --defsym foo=_start+0x100000 -o %t-boundary.rv64
#  llvm-objdump -d -M no-aliases --no-show-raw-insn %t-boundary.rv32 | FileCheck --check-prefix=BOUNDARY %s
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t-boundary.rv64 | FileCheck --check-prefix=BOUNDARY %s
# OLDBOUNDARY:      auipc  ra, 256
# OLDBOUNDARY-NEXT: jalr   ra, 0(ra)
# OLDBOUNDARY-NEXT: jal    zero, {{.*}} <foo>
# BOUNDARY:      tbljalm 0
# BOUNDARY-NEXT: tbljalm 0

# Check relaxation works across output sections
# RUN: echo 'SECTIONS { .text 0x100000 : { *(.text) } .foo : ALIGN(8) { foo = .; } }' > %t-cross-section.lds
#  ld.lld %t.rv32c.o %t-cross-section.lds -o %t-cross-section.rv32
# RUN: ld.lld %t.rv64c.o %t-cross-section.lds -o %t-cross-section.rv64

.global _start
.p2align 3
_start:
  call foo
  tail foo
