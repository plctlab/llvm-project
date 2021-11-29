# RUN: llvm-mc -triple riscv32 -riscv-no-aliases -mattr=+zce-lsgp,+relax < %s -show-encoding \
# RUN:     | FileCheck -check-prefix=INSTR -check-prefix=FIXUP %s
# RUN: llvm-mc -filetype=obj -triple riscv32 -mattr=+zce-lsgp,+relax < %s \
# RUN:     | llvm-readobj -r - | FileCheck -check-prefix=RELOC %s

# Check prefixes:
# RELOC - Check the relocation in the object.
# FIXUP - Check the fixup on the instruction.
# INSTR - Check the instruction is handled properly by the ASMPrinter

lw	a0, 0(sp)
# RELOC: R_RISCV_GPREL_ZCE_LWGP
# INSTR: lw	a0, 0(sp)
# FIXUP: fixup A - offset: 0, value: 0, kind: fixup_riscv_zce_lwgp

lw	a0, 12(a1)
# RELOC: R_RISCV_GPREL_ZCE_LWGP
# INSTR: lw	a0, 12(a1)
# FIXUP: fixup A - offset: 0, value: 0, kind: fixup_riscv_zce_lwgp
