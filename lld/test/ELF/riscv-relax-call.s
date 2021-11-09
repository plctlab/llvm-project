# REQUIRES: riscv

# RUN: llvm-mc -filetype=obj -triple=riscv32-unknown-elf -mattr=+relax %s -o %t.rv32.o
# RUN: llvm-mc -filetype=obj -triple=riscv64-unknown-elf -mattr=+relax %s -o %t.rv64.o
# RUN: llvm-mc -filetype=obj -triple=riscv32-unknown-elf -mattr=+c,+relax %s -o %t.rv32c.o
# RUN: llvm-mc -filetype=obj -triple=riscv64-unknown-elf -mattr=+c,+relax %s -o %t.rv64c.o

# jal relaxation
# RUN: ld.lld %t.rv32.o --defsym foo=_start+20 -o %t.rv32
# RUN: ld.lld %t.rv64.o --defsym foo=_start+20 -o %t.rv64
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t.rv32 | FileCheck --check-prefix=JAL %s
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t.rv64 | FileCheck --check-prefix=JAL %s
# JAL:      jal     ra, {{.*}} <foo>
# JAL-NEXT: jal     zero, {{.*}} <foo>

# c.j and c.jal (RV32C-only) relaxation
# RUN: ld.lld %t.rv32c.o --defsym foo=_start+20 -o %t.rv32c
# RUN: ld.lld %t.rv64c.o --defsym foo=_start+20 -o %t.rv64c
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t.rv32c | FileCheck --check-prefix=RV32C %s
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t.rv64c | FileCheck --check-prefix=RV64C %s
# RV32C:      c.jal     {{.*}} <foo>
# RV32C-NEXT: c.j       {{.*}} <foo>
# RV64C:      jal       ra, {{.*}} <foo>
# RV64C-NEXT: c.j       {{.*}} <foo>

# Don't relax to c.j/c.jal if out of range
# RUN: ld.lld %t.rv32c.o --defsym foo=_start+0x1004 -o %t.rv32c
# RUN: ld.lld %t.rv64c.o --defsym foo=_start+0x1004 -o %t.rv64c
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t.rv32c | FileCheck --check-prefix=JAL %s
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t.rv64c | FileCheck --check-prefix=JAL %s

# Don't relax if out of range (for the first call)
# RUN: ld.lld %t.rv32c.o --defsym foo=_start+0x100000 -o %t-boundary.rv32
# RUN: ld.lld %t.rv64c.o --defsym foo=_start+0x100000 -o %t-boundary.rv64
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t-boundary.rv32 | FileCheck --check-prefix=BOUNDARY %s
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t-boundary.rv64 | FileCheck --check-prefix=BOUNDARY %s
# BOUNDARY:      auipc  ra, 256
# BOUNDARY-NEXT: jalr   ra, 0(ra)
# BOUNDARY-NEXT: jal    zero, {{.*}} <foo>

# Check relaxation works across output sections
# RUN: echo 'SECTIONS { .text 0x100000 : { *(.text) } .foo : ALIGN(8) { foo = .; } }' > %t-cross-section.lds
# RUN: ld.lld %t.rv32c.o %t-cross-section.lds -o %t-cross-section.rv32
# RUN: ld.lld %t.rv64c.o %t-cross-section.lds -o %t-cross-section.rv64
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t-cross-section.rv32 | FileCheck --check-prefix=RV32C %s
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t-cross-section.rv64 | FileCheck --check-prefix=RV64C %s

# Test for output section alignment checking during relaxation. The .foo section
# cannot be moved closer due to alignment so lld must not relax the call, even
# though it seems it may be in range before relaxation.

# RUN: echo 'SECTIONS { .text 0x100000 : { *(.text); } .foo : ALIGN(0x100000) { foo = .; } }' > %t-cross-section-out-of-range.lds
# RUN: ld.lld %t.rv32c.o %t-cross-section-out-of-range.lds -o %t-cross-section-out-of-range.rv32
# RUN: ld.lld %t.rv64c.o %t-cross-section-out-of-range.lds -o %t-cross-section-out-of-range.rv64
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t-cross-section-out-of-range.rv32 | FileCheck --check-prefix=NORELAX %s
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t-cross-section-out-of-range.rv64 | FileCheck --check-prefix=NORELAX %s
# NORELAX:      auipc  ra, {{.*}}
# NORELAX-NEXT: jalr   ra, {{.*}}(ra)
# NORELAX:      auipc  t1, {{.*}}
# NORELAX-NEXT: jalr   zero, {{.*}}(t1)

# Don't relax to absolute symbols
# RUN: ld.lld %t.rv32c.o -Ttext=0x100000 --defsym foo=0x100000 -o %t-abs.rv32
# RUN: ld.lld %t.rv64c.o -Ttext=0x100000 --defsym foo=0x100000 -o %t-abs.rv64
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t-abs.rv32 | FileCheck --check-prefix=NORELAX %s
# RUN: llvm-objdump -d -M no-aliases --no-show-raw-insn %t-abs.rv64 | FileCheck --check-prefix=NORELAX %s

.global _start
.p2align 3
_start:
  call foo
  tail foo
