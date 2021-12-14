; RUN: llc -mtriple=riscv32 -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV32I %s
; RUN: llc -mtriple=riscv32 -mattr=+zce-clbh,+zce-csbh -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV32IZce %s
; RUN: llc -mtriple=riscv64 -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV64I %s
; RUN: llc -mtriple=riscv64 -mattr=+zce-clbh,+zce-csbh -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV64IZce %s

define dso_local i32 @lh(i16 *%a) nounwind {
; RV32I-LABEL: lh:
; RV32I:       # %bb.0:
; RV32I-NEXT:    lh a1, 4(a0)
; RV32I-NEXT:    lh a0, 0(a0)
; RV32I-NEXT:    mv a0, a1
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: lh:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.lh a1, 4(a0)
; RV32IZce-NEXT:    c.lh a0, 0(a0)
; RV32IZce-NEXT:    mv a0, a1
; RV32IZce-NEXT:    ret
  %1 = getelementptr i16, i16* %a, i32 2
  %2 = load i16, i16* %1
  %3 = sext i16 %2 to i32
  ; the unused load will produce an anyext for selection
  %4 = load volatile i16, i16* %a
  ret i32 %3
}

define void @test_load_store(half* %p, half* %q) nounwind {
; RV32I-LABEL: test_load_store:
; RV32I:       # %bb.0:
; RV32I-NEXT:    lh a0, 0(a0)
; RV32I-NEXT:    sh a0, 0(a1)
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: test_load_store:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.lh a0, 0(a0)
; RV32IZce-NEXT:    c.sh a0, 0(a1)
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: test_load_store:
; RV64I:       # %bb.0:
; RV64I-NEXT:    lh a0, 0(a0)
; RV64I-NEXT:    sh a0, 0(a1)
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: test_load_store:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    c.lh a0, 0(a0)
; RV64IZce-NEXT:    c.sh a0, 0(a1)
; RV64IZce-NEXT:    ret
  %a = load half, half* %p
  store half %a, half* %q
  ret void
}
