; RUN: llc -mtriple=riscv32 -mattr=+zce-cmva01s07 -verify-machineinstrs < %s \
; RUN: | FileCheck %s -check-prefix=VALID
; RUN: llc -mtriple=riscv64 -mattr=+zce-cmva01s07 -verify-machineinstrs < %s \
; RUN: | FileCheck %s -check-prefix=VALID


; Function Attrs: nounwind
define dso_local i32 @cmva(i32 %num, i32 %f, i32 %d, i32 %dx) local_unnamed_addr #0 {
 ;  VALID-LABEL: cmva:
 ;  VALID: c.mva01s07 {{s[0-7]}}, {{s[0-7]}}
 ;  VALID-NOT: c.mva01s07 {{a.}}, {{a.}}
entry:
  %mul = mul nsw i32 %dx, %d
  %sub = sub nsw i32 %mul, %dx
  %add = add nsw i32 %mul, %d
  %mul2 = mul nsw i32 %sub, %dx
  %add3 = add nsw i32 %add, %mul2
  %mul4 = mul nsw i32 %add3, %d
  %add6 = add nsw i32 %add3, %num
  %add5 = add i32 %sub, %f
  %add7 = add i32 %add5, %mul4
  ret i32 %add7
}