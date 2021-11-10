; RUN: llc -mtriple=riscv32 -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV32I %s
; RUN: llc -mtriple=riscv32 -mattr=+zce-csbh -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV32IZce %s
; RUN: llc -mtriple=riscv64 -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV64I %s
; RUN: llc -mtriple=riscv64 -mattr=+zce-csbh -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV64IZce %s

define dso_local void @sb(i8 *%a, i8 %b) nounwind {
; RV32I-LABEL: sb:
; RV32I:       # %bb.0:
; RV32I-NEXT:    sb a1, 0(a0)
; RV32I-NEXT:    sb a1, 6(a0)
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: sb:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.sb a1, 0(a0)
; RV32IZce-NEXT:    c.sb a1, 6(a0)
; RV32IZce-NEXT:    ret
  store i8 %b, i8* %a
  %1 = getelementptr i8, i8* %a, i32 6
  store i8 %b, i8* %1
  ret void
}

define dso_local void @sb64(i8 *%a, i8 %b) nounwind {
; RV64I-LABEL: sb64:
; RV64I:       # %bb.0:
; RV64I-NEXT:    sb a1, 0(a0)
; RV64I-NEXT:    sb a1, 7(a0)
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: sb64:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    c.sb a1, 0(a0)
; RV64IZce-NEXT:    c.sb a1, 7(a0)
; RV64IZce-NEXT:    ret
  store i8 %b, i8* %a
  %1 = getelementptr i8, i8* %a, i32 7
  store i8 %b, i8* %1
  ret void
}
