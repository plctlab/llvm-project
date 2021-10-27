; RUN: llc -mtriple=riscv32 -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV32I %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zceb -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV32IZce %s
; RUN: llc -mtriple=riscv64 -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV64I %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zceb -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV64IZce %s

define dso_local i32 @lbu(i8 *%a) nounwind {
; RV32I-LABEL: lbu:
; RV32I:       # %bb.0:
; RV32I-NEXT:    lbu a1, 4(a0)
; RV32I-NEXT:    lbu a0, 0(a0)
; RV32I-NEXT:    add a0, a1, a0
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: lbu:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.lbu a1, 4(a0)
; RV32IZce-NEXT:    c.lbu a0, 0(a0)
; RV32IZce-NEXT:    add a0, a1, a0
; RV32IZce-NEXT:    ret
  %1 = getelementptr i8, i8* %a, i32 4
  %2 = load i8, i8* %1
  %3 = zext i8 %2 to i32
  %4 = load volatile i8, i8* %a
  %5 = zext i8 %4 to i32
  %6 = add i32 %3, %5
  ret i32 %6
}

define dso_local i64 @lbu64(i8 *%a) nounwind {
; RV64I-LABEL: lbu64:
; RV64I:       # %bb.0:
; RV64I-NEXT:    lbu a1, 4(a0)
; RV64I-NEXT:    lbu a0, 0(a0)
; RV64I-NEXT:    add a0, a1, a0
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: lbu64:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    c.lbu a1, 4(a0)
; RV64IZce-NEXT:    c.lbu a0, 0(a0)
; RV64IZce-NEXT:    add a0, a1, a0
; RV64IZce-NEXT:    ret
  %1 = getelementptr i8, i8* %a, i32 4
  %2 = load i8, i8* %1
  %3 = zext i8 %2 to i64
  %4 = load volatile i8, i8* %a
  %5 = zext i8 %4 to i64
  %6 = add i64 %3, %5
  ret i64 %6
}

; Check load and store to an i1 location
define dso_local i32 @load_sext_zext_anyext_i1(i1 *%a) nounwind {
; RV32I-LABEL: load_sext_zext_anyext_i1:
; RV32I:       # %bb.0:
; RV32I-NEXT:    lbu a1, 1(a0)
; RV32I-NEXT:    lbu a2, 2(a0)
; RV32I-NEXT:    lb a0, 0(a0)
; RV32I-NEXT:    sub a0, a2, a1
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: load_sext_zext_anyext_i1:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.lbu a1, 1(a0)
; RV32IZce-NEXT:    c.lbu a2, 2(a0)
; RV32IZce-NEXT:    c.lb a0, 0(a0)
; RV32IZce-NEXT:    sub a0, a2, a1
; RV32IZce-NEXT:    ret
  ; sextload i1
  %1 = getelementptr i1, i1* %a, i32 1
  %2 = load i1, i1* %1
  %3 = sext i1 %2 to i32
  ; zextload i1
  %4 = getelementptr i1, i1* %a, i32 2
  %5 = load i1, i1* %4
  %6 = zext i1 %5 to i32
  %7 = add i32 %3, %6
  ; extload i1 (anyext). Produced as the load is unused.
  %8 = load volatile i1, i1* %a
  ret i32 %7
}

; Check load and store to an i1 location
define dso_local i64 @load_sext_zext_anyext_i1_64(i1 *%a) nounwind {
; RV64I-LABEL: load_sext_zext_anyext_i1_64:
; RV64I:       # %bb.0:
; RV64I-NEXT:    lbu a1, 1(a0)
; RV64I-NEXT:    lbu a2, 2(a0)
; RV64I-NEXT:    lb a0, 0(a0)
; RV64I-NEXT:    sub a0, a2, a1
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: load_sext_zext_anyext_i1_64:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    c.lbu a1, 1(a0)
; RV64IZce-NEXT:    c.lbu a2, 2(a0)
; RV64IZce-NEXT:    c.lb a0, 0(a0)
; RV64IZce-NEXT:    sub a0, a2, a1
; RV64IZce-NEXT:    ret
  ; sextload i1
  %1 = getelementptr i1, i1* %a, i32 1
  %2 = load i1, i1* %1
  %3 = sext i1 %2 to i64
  ; zextload i1
  %4 = getelementptr i1, i1* %a, i32 2
  %5 = load i1, i1* %4
  %6 = zext i1 %5 to i64
  %7 = add i64 %3, %6
  ; extload i1 (anyext). Produced as the load is unused.
  %8 = load volatile i1, i1* %a
  ret i64 %7
}

define dso_local i16 @load_sext_zext_anyext_i1_i16(i1 *%a) nounwind {
; RV32I-LABEL: load_sext_zext_anyext_i1_i16:
; RV32I:       # %bb.0:
; RV32I-NEXT:    lbu a1, 1(a0)
; RV32I-NEXT:    lbu a2, 2(a0)
; RV32I-NEXT:    lb a0, 0(a0)
; RV32I-NEXT:    sub a0, a2, a1
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: load_sext_zext_anyext_i1_i16:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.lbu a1, 1(a0)
; RV32IZce-NEXT:    c.lbu a2, 2(a0)
; RV32IZce-NEXT:    c.lb a0, 0(a0)
; RV32IZce-NEXT:    sub a0, a2, a1
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: load_sext_zext_anyext_i1_i16:
; RV64I:       # %bb.0:
; RV64I-NEXT:    lbu a1, 1(a0)
; RV64I-NEXT:    lbu a2, 2(a0)
; RV64I-NEXT:    lb a0, 0(a0)
; RV64I-NEXT:    sub a0, a2, a1
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: load_sext_zext_anyext_i1_i16:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    c.lbu a1, 1(a0)
; RV64IZce-NEXT:    c.lbu a2, 2(a0)
; RV64IZce-NEXT:    c.lb a0, 0(a0)
; RV64IZce-NEXT:    sub a0, a2, a1
; RV64IZce-NEXT:    ret
  ; sextload i1
  %1 = getelementptr i1, i1* %a, i32 1
  %2 = load i1, i1* %1
  %3 = sext i1 %2 to i16
  ; zextload i1
  %4 = getelementptr i1, i1* %a, i32 2
  %5 = load i1, i1* %4
  %6 = zext i1 %5 to i16
  %7 = add i16 %3, %6
  ; extload i1 (anyext). Produced as the load is unused.
  %8 = load volatile i1, i1* %a
  ret i16 %7
}
