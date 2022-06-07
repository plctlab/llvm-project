# REQUIRES: riscv

# RUN: llvm-mc -filetype=obj -triple=riscv32 -mattr=+relax -mattr=+experimental-zcmt %s -o %t.rv32.o
# RUN: llvm-mc -filetype=obj -triple=riscv64 -mattr=+relax -mattr=+experimental-zcmt %s -o %t.rv64.o

# tbljal conversion
# RUN: ld.lld %t.rv32.o -zce-tbljal --defsym foo=_start+20 -o %t.rv32
# RUN: ld.lld %t.rv64.o -zce-tbljal --defsym foo=_start+20 -o %t.rv64
# RUN: llvm-objdump -d -M no-aliases --mattr=+experimental-zcmt --no-show-raw-insn %t.rv32 | FileCheck --check-prefix=TBLJAL %s
# RUN: llvm-objdump -d -M no-aliases --mattr=+experimental-zcmt --no-show-raw-insn %t.rv64 | FileCheck --check-prefix=TBLJAL %s
# TBLJAL:      cm.jalt 64
# TBLJAL-NEXT: cm.jt 0

# Check the bounds of what would be out of range (for the first call) for other jump types.
# RUN: ld.lld %t.rv32.o -zce-tbljal --defsym foo=_start+0x100000 -o %t-boundary.rv32
# RUN: ld.lld %t.rv64.o -zce-tbljal --defsym foo=_start+0x100000 -o %t-boundary.rv64
# RUN: llvm-objdump -d -M no-aliases --mattr=+experimental-zcmt --no-show-raw-insn %t-boundary.rv32 | FileCheck --check-prefix=BOUNDARY %s
# RUN: llvm-objdump -d -M no-aliases --mattr=+experimental-zcmt --no-show-raw-insn %t-boundary.rv64 | FileCheck --check-prefix=BOUNDARY %s
# OLDBOUNDARY:      auipc  ra, 256
# OLDBOUNDARY-NEXT: jalr   ra, 0(ra)
# OLDBOUNDARY-NEXT: jal    zero, {{.*}} <foo>
# BOUNDARY:     cm.jalt 64
# BOUNDARY-NEXT: cm.jt   0

# Check relaxation works across output sections
#  echo 'SECTIONS { .text 0x100000 : { *(.text) } .foo : ALIGN(8) { foo = .; } }' > %t-cross-section.lds
#  ld.lld %t.rv32c.o %t-cross-section.lds -o %t-cross-section.rv32
#  ld.lld %t.rv64c.o %t-cross-section.lds -o %t-cross-section.rv64

.global _start
.p2align 3
_start:
  call foo
  tail foo
