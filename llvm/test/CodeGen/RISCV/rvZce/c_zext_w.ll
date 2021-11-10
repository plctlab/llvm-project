; RUN: llc -mtriple=riscv64 -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64I
; RUN: llc -mtriple=riscv64 -mattr=+zce-zext -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IZCE
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zba -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IZBA
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zba,+zce-zext -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IZBAZCE

define i64 @zextw_i64(i64 %a) nounwind {
; RV64I-LABEL: zextw_i64:
; RV64I:       # %bb.0:
; RV64I-NEXT:    slli a0, a0, 32
; RV64I-NEXT:    srli a0, a0, 32
; RV64I-NEXT:    ret
;
; RV64IZCE-LABEL: zextw_i64:
; RV64IZCE:       # %bb.0:
; RV64IZCE-NEXT:    slli a0, a0, 32
; RV64IZCE-NEXT:    srli a0, a0, 32
; RV64IZCE-NEXT:    ret
;
; RV64IZBA-LABEL: zextw_i64:
; RV64IZBA:       # %bb.0:
; RV64IZBA-NEXT:    zext.w a0, a0
; RV64IZBA-NEXT:    ret
;
; RV64IZBAZCE-LABEL: zextw_i64:
; RV64IZBAZCE:       # %bb.0:
; RV64IZBAZCE-NEXT:    c.zext.w a0
; RV64IZBAZCE-NEXT:    ret
  %and = and i64 %a, 4294967295
  ret i64 %and
}

; This makes sure targetShrinkDemandedConstant changes the and immmediate to
; allow zext.w or slli+srli.
define i64 @zextw_demandedbits_i64(i64 %0) {
; RV64I-LABEL: zextw_demandedbits_i64:
; RV64I:       # %bb.0:
; RV64I-NEXT:    ori a0, a0, 1
; RV64I-NEXT:    slli a0, a0, 32
; RV64I-NEXT:    srli a0, a0, 32
; RV64I-NEXT:    ret
;
; RV64IZCE-LABEL: zextw_demandedbits_i64:
; RV64IZCE:       # %bb.0:
; RV64IZCE-NEXT:    ori a0, a0, 1
; RV64IZCE-NEXT:    slli a0, a0, 32
; RV64IZCE-NEXT:    srli a0, a0, 32
; RV64IZCE-NEXT:    ret
;
; RV64IZBA-LABEL: zextw_demandedbits_i64:
; RV64IZBA:       # %bb.0:
; RV64IZBA-NEXT:    ori a0, a0, 1
; RV64IZBA-NEXT:    zext.w a0, a0
; RV64IZBA-NEXT:    ret
;
; RV64IZBAZCE-LABEL: zextw_demandedbits_i64:
; RV64IZBAZCE:       # %bb.0:
; RV64IZBAZCE-NEXT:    ori a0, a0, 1
; RV64IZBAZCE-NEXT:    c.zext.w a0
; RV64IZBAZCE-NEXT:    ret
  %2 = and i64 %0, 4294967294
  %3 = or i64 %2, 1
  ret i64 %3
}