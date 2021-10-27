; RUN: llc -mtriple=riscv32 -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32I
; RUN: llc -mtriple=riscv32 -mattr=+experimental-b,+experimental-zce -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IB
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbb,+experimental-zce -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IBB
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbp,+experimental-zce -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IBP

; NOTE: /home/wuxinlong/workspace/llvm-project/build/bin/llc -mtriple=riscv32 -mattr=+experimental-b,+experimental-zce -verify-machineinstrs < /home/wuxinlong/workspace/llvm-project/llvm/test/CodeGen/RISCV/rvZce/rv32zcee.ll  --print-after-all -o test.ll

define i8 @srai_i8(i8 %a) nounwind {
; RV32I-LABEL: srai_i8:
; RV32I:       # %bb.0:
; RV32I-NEXT:    slli a0, a0, 24
; RV32I-NEXT:    srai a0, a0, 29
; RV32I-NEXT:    ret
;
; RV32IB-LABEL: srai_i8:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    c.sext.b a0
; RV32IB-NEXT:    srai a0, a0, 5
; RV32IB-NEXT:    ret
;
; RV32IBB-LABEL: srai_i8:
; RV32IBB:       # %bb.0:
; RV32IBB-NEXT:    c.sext.b a0
; RV32IBB-NEXT:    srai a0, a0, 5
; RV32IBB-NEXT:    ret
;
; RV32IBP-LABEL: srai_i8:
; RV32IBP:       # %bb.0:
; RV32IBP-NEXT:    slli a0, a0, 24
; RV32IBP-NEXT:    srai a0, a0, 29
; RV32IBP-NEXT:    ret
;
; RV64I-LABEL: srai_i8:
; RV64I:       # %bb.0:
; RV64I-NEXT:    slli a0, a0, 56
; RV64I-NEXT:    srai a0, a0, 61
; RV64I-NEXT:    ret
;
; RV64IB-LABEL: srai_i8:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    c.sext.b a0
; RV64IB-NEXT:    srai a0, a0, 5
; RV64IB-NEXT:    ret
;
; RV64IBB-LABEL: srai_i8:
; RV64IBB:       # %bb.0:
; RV64IBB-NEXT:    c.sext.b a0
; RV64IBB-NEXT:    srai a0, a0, 5
; RV64IBB-NEXT:    ret
;
; RV64IBP-LABEL: srai_i8:
; RV64IBP:       # %bb.0:
; RV64IBP-NEXT:    slli a0, a0, 56
; RV64IBP-NEXT:    srai a0, a0, 61
; RV64IBP-NEXT:    ret
  %1 = ashr i8 %a, 5
  ret i8 %1
}

define i32 @sextb_i32(i32 %a) nounwind {
; RV32I-LABEL: sextb_i32:
; RV32I:       # %bb.0:
; RV32I-NEXT:    slli a0, a0, 24
; RV32I-NEXT:    srai a0, a0, 24
; RV32I-NEXT:    ret
;
; RV32IB-LABEL: sextb_i32:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    c.sext.b a0
; RV32IB-NEXT:    ret
;
; RV32IBB-LABEL: sextb_i32:
; RV32IBB:       # %bb.0:
; RV32IBB-NEXT:    c.sext.b a0
; RV32IBB-NEXT:    ret
;
; RV64I-LABEL: sextb_i32:
; RV64I:       # %bb.0:
; RV64I-NEXT:    slli a0, a0, 56
; RV64I-NEXT:    srai a0, a0, 56
; RV64I-NEXT:    ret
;
; RV64IB-LABEL: sextb_i32:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    c.sext.b a0
; RV64IB-NEXT:    ret
;
; RV64IBB-LABEL: sextb_i32:
; RV64IBB:       # %bb.0:
; RV64IBB-NEXT:    c.sext.b a0
; RV64IBB-NEXT:    ret
  %shl = shl i32 %a, 24
  %shr = ashr exact i32 %shl, 24
  ret i32 %shr
}

define i64 @sextb_i64(i64 %a) nounwind {
; RV32I-LABEL: sextb_i64:
; RV32I:       # %bb.0:
; RV32I-NEXT:    slli a1, a0, 24
; RV32I-NEXT:    srai a0, a1, 24
; RV32I-NEXT:    srai a1, a1, 31
; RV32I-NEXT:    ret
;
; RV32IB-LABEL: sextb_i64:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    c.sext.b a0
; RV32IB-NEXT:    srai a1, a0, 31
; RV32IB-NEXT:    ret
;
; RV32IBB-LABEL: sextb_i64:
; RV32IBB:       # %bb.0:
; RV32IBB-NEXT:    c.sext.b a0
; RV32IBB-NEXT:    srai a1, a0, 31
; RV32IBB-NEXT:    ret
;
; RV64I-LABEL: sextb_i64:
; RV64I:       # %bb.0:
; RV64I-NEXT:    slli a0, a0, 56
; RV64I-NEXT:    srai a0, a0, 56
; RV64I-NEXT:    ret
;
; RV64IB-LABEL: sextb_i64:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    c.sext.b a0
; RV64IB-NEXT:    ret
;
; RV64IBB-LABEL: sextb_i64:
; RV64IBB:       # %bb.0:
; RV64IBB-NEXT:    c.sext.b a0
; RV64IBB-NEXT:    ret
  %shl = shl i64 %a, 56
  %shr = ashr exact i64 %shl, 56
  ret i64 %shr
}

declare i8 @llvm.sadd.sat.i8(i8, i8)
define i8 @func3(i8 %x, i8 %y, i8 %z) nounwind {
; RV32IZbb-LABEL: func3:
; RV32IZbb:       # %bb.0:
; RV32IZbb-CHECK:    c.sext.b a0
; RV32IZbb-CHECK:    c.sext.b a1
;
; RV64IZBB-LABEL: func3:
; RV64IZBB:       # %bb.0:
; RV64IZBB-CHECK:    c.sext.b a0
; RV64IZBB-CHECK:    c.sext.b a1
  %a = mul i8 %y, %z
  %tmp = call i8 @llvm.sadd.sat.i8(i8 %x, i8 %a)
  ret i8 %tmp
}

declare i8 @llvm.ssub.sat.i8(i8, i8)
define i8 @func4(i8 %x, i8 %y, i8 %z) nounwind {
; RV32IZBB-LABEL: func4:
; RV32IZBB:       # %bb.0:
; RV32IZBB-CHECK:    c.sext.b a0
; RV32IZBB-CHECK:    c.sext.b a1
;
; RV64IZBB-LABEL: func4:
; RV64IZBB:       # %bb.0:
; RV64IZBB-CHECK:    c.sext.b a0
; RV64IZBB-CHECK:    c.sext.b a1
  %a = mul i8 %y, %z
  %tmp = call i8 @llvm.ssub.sat.i8(i8 %x, i8 %a)
  ret i8 %tmp
}
