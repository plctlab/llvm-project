; RUN: llc -mtriple=riscv32 -mattr=+experimental-zcmp -verify-machineinstrs < %s \
; RUN: | FileCheck %s -check-prefixes=VALID,VALID32
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zcmp -verify-machineinstrs < %s \
; RUN: | FileCheck %s -check-prefixes=VALID


; Function Attrs: nounwind
define dso_local i32 @cmva(i32 %num, i32 %f, i32 %d, i32 %dx) local_unnamed_addr #0 {
;  VALID-LABEL: cmva:
;  VALID: cm.mva01s {{s[0-7]}}, {{s[0-7]}}
;  VALID-NOT: cm.mva01s {{a.}}, {{a.}}
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

declare i64 @llvm.cttz.i64(i64, i1 immarg)

define i64 @cmvs32(i64 %a) nounwind {
;  VALID32-LABEL: cmvs32:
;  VALID32: cm.mvsa01 {{s[0-7]}}, {{s[0-7]}}
;  VALID32-NOT: cm.mvsa01 {{a.}}, {{a.}}
  %tmp = call i64 @llvm.cttz.i64(i64 %a, i1 false)
  ret i64 %tmp
}

declare void @hoge()
define void @cmvs64(i32 signext %arg, i32 signext %arg1) nounwind {
;  VALID64-LABEL: cmvs:
;  VALID64: cm.mvsa01 {{s[0-7]}}, {{s[0-7]}}
;  VALID64-NOT: cm.mvsa01 {{a.}}, {{a.}}
bb:
  %tmp = icmp eq i32 %arg, %arg1
  br i1 %tmp, label %bb6, label %bb2

bb2:                                              ; preds = %bb2, %bb
  %tmp3 = phi i32 [ %tmp4, %bb2 ], [ %arg, %bb ]
  tail call void @hoge()
  %tmp4 = add nsw i32 %tmp3, 1
  %tmp5 = icmp eq i32 %tmp4, %arg1
  br i1 %tmp5, label %bb6, label %bb2

bb6:                                              ; preds = %bb2, %bb
  ret void
}
