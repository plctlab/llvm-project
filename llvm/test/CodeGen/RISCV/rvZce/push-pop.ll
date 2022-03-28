; NOTE: Check cm.push/cm.pop.
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zcmp -verify-machineinstrs < %s \
; RUN: | FileCheck %s -check-prefixes=RV32IZCMP
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zcmp -verify-machineinstrs < %s \
; RUN: | FileCheck %s -check-prefixes=RV64IZCMP
; RUN: llc -mtriple=riscv32 -verify-machineinstrs < %s \
; RUN: | FileCheck -check-prefixes=RV32I %s
; RUN: llc -mtriple=riscv64 -verify-machineinstrs < %s \
; RUN: | FileCheck -check-prefixes=RV64I %s

declare void @test(i8*)

; Function Attrs: optnone
define i32 @foo() {
; RV32IZCMP-LABEL: foo:
; RV32IZCMP:     # %bb.0:
; RV32IZCMP-NEXT:  cm.push	{ra}, -64
; RV32IZCMP-NEXT:  .cfi_def_cfa_offset 528
; RV32IZCMP-NEXT:  addi	sp, sp, -464
; RV32IZCMP-NEXT:  .cfi_offset ra, -4
; RV32IZCMP-NEXT:  addi	a0, sp, 12
; RV32IZCMP-NEXT:  call	test@plt
; RV32IZCMP-NEXT:  addi	sp, sp, 464
; RV32IZCMP-NEXT:  cm.popretz	{ra}, 64
;
; RV64IZCMP-LABEL: foo:
; RV64IZCMP:     # %bb.0:
; RV64IZCMP-NEXT:  cm.push	{ra}, -64
; RV64IZCMP-NEXT:  .cfi_def_cfa_offset 528
; RV64IZCMP-NEXT:  addi	sp, sp, -464
; RV64IZCMP-NEXT:  .cfi_offset ra, -8
; RV64IZCMP-NEXT:  addi	a0, sp, 8
; RV64IZCMP-NEXT:  call	test@plt
; RV64IZCMP-NEXT:  addi	sp, sp, 464
; RV64IZCMP-NEXT:  cm.popretz	{ra}, 64
;
; RV32I-LABEL: foo:
; RV32I:     # %bb.0:
; RV32I-NEXT:  addi	sp, sp, -528
; RV32I-NEXT:  .cfi_def_cfa_offset 528
; RV32I-NEXT:  sw	ra, 524(sp) # 4-byte Folded Spill
; RV32I-NEXT:  .cfi_offset ra, -4
; RV32I-NEXT:  addi	a0, sp, 12
; RV32I-NEXT:  call	test@plt
; RV32I-NEXT:  li	a0, 0
; RV32I-NEXT:  lw	ra, 524(sp) # 4-byte Folded Reload
; RV32I-NEXT:  addi	sp, sp, 528
; RV32I-NEXT:  ret
;
; RV64I-LABEL: foo:
; RV64I:     # %bb.0:
; RV64I-NEXT:  addi	sp, sp, -528
; RV64I-NEXT:  .cfi_def_cfa_offset 528
; RV64I-NEXT:  sd	ra, 520(sp) # 8-byte Folded Spill
; RV64I-NEXT:  .cfi_offset ra, -8
; RV64I-NEXT:  addi	a0, sp, 8
; RV64I-NEXT:  call	test@plt
; RV64I-NEXT:  li	a0, 0
; RV64I-NEXT:  ld	ra, 520(sp) # 8-byte Folded Reload
; RV64I-NEXT:  addi	sp, sp, 528
; RV64I-NEXT:  ret
  %1 = alloca [512 x i8]
  %2 = getelementptr [512 x i8], [512 x i8]* %1, i32 0, i32 0
  call void @test(i8* %2)
  ret i32 0
}
