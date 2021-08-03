; RUN: llc -mtriple=riscv32 -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32I
; RUN: llc -mtriple=riscv32 -mattr=+experimental-b,+experimental-zce -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IB
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbb,+experimental-zce -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IBB
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbp,+experimental-zce -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IBP
; RUN: llc -mtriple=riscv64 -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64I
; RUN: llc -mtriple=riscv64 -mattr=+experimental-b,+experimental-zce -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IB
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbb,+experimental-zce -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IBB
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zbp,+experimental-zce -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IBP

; NOTE: /home/wuxinlong/workspace/llvm-project/build/bin/llc -mtriple=riscv32 -mattr=+experimental-b,+experimental-zce -verify-machineinstrs < /home/wuxinlong/workspace/llvm-project/llvm/test/CodeGen/RISCV/rvZce/rv32zcee.ll  --print-after-all -o test.ll

define i16 @srai_i16(i16 %a) nounwind {
; RV32I-LABEL: srai_i16:
; RV32I:       # %bb.0:
; RV32I-NEXT:    slli a0, a0, 16
; RV32I-NEXT:    srai a0, a0, 25
; RV32I-NEXT:    ret
;
; RV32IB-LABEL: srai_i16:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    c.sext.h a0
; RV32IB-NEXT:    srai a0, a0, 9
; RV32IB-NEXT:    ret
;
; RV32IBB-LABEL: srai_i16:
; RV32IBB:       # %bb.0:
; RV32IBB-NEXT:    c.sext.h a0
; RV32IBB-NEXT:    srai a0, a0, 9
; RV32IBB-NEXT:    ret
;
; RV32IBP-LABEL: srai_i16:
; RV32IBP:       # %bb.0:
; RV32IBP-NEXT:    slli a0, a0, 16
; RV32IBP-NEXT:    srai a0, a0, 25
; RV32IBP-NEXT:    ret
;
; RV64I-LABEL: srai_i16:
; RV64I:       # %bb.0:
; RV64I-NEXT:    slli a0, a0, 48
; RV64I-NEXT:    srai a0, a0, 57
; RV64I-NEXT:    ret
;
; RV64IB-LABEL: srai_i16:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    c.sext.h a0
; RV64IB-NEXT:    srai a0, a0, 9
; RV64IB-NEXT:    ret
;
; RV64IBB-LABEL: srai_i16:
; RV64IBB:       # %bb.0:
; RV64IBB-NEXT:    c.sext.h a0
; RV64IBB-NEXT:    srai a0, a0, 9
; RV64IBB-NEXT:    ret
;
; RV64IBP-LABEL: srai_i16:
; RV64IBP:       # %bb.0:
; RV64IBP-NEXT:    slli a0, a0, 48
; RV64IBP-NEXT:    srai a0, a0, 57
; RV64IBP-NEXT:    ret
  %1 = ashr i16 %a, 9
  ret i16 %1
}

define i32 @sexth_i32(i32 %a) nounwind {
; RV32I-LABEL: sexth_i32:
; RV32I:       # %bb.0:
; RV32I-NEXT:    slli a0, a0, 16
; RV32I-NEXT:    srai a0, a0, 16
; RV32I-NEXT:    ret
;
; RV32IB-LABEL: sexth_i32:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    c.sext.h a0
; RV32IB-NEXT:    ret
;
; RV32IBB-LABEL: sexth_i32:
; RV32IBB:       # %bb.0:
; RV32IBB-NEXT:    c.sext.h a0
; RV32IBB-NEXT:    ret
;
; RV64I-LABEL: sexth_i32:
; RV64I:       # %bb.0:
; RV64I-NEXT:    slli a0, a0, 48
; RV64I-NEXT:    srai a0, a0, 48
; RV64I-NEXT:    ret
;
; RV64IB-LABEL: sexth_i32:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    c.sext.h a0
; RV64IB-NEXT:    ret
;
; RV64IBB-LABEL: sexth_i32:
; RV64IBB:       # %bb.0:
; RV64IBB-NEXT:    c.sext.h a0
; RV64IBB-NEXT:    ret
  %shl = shl i32 %a, 16
  %shr = ashr exact i32 %shl, 16
  ret i32 %shr
}

declare i16 @llvm.sadd.sat.i16(i16, i16)
define i16 @func5(i16 %x, i16 %y, i16 %z) nounwind {
; RV32IZBB-LABEL: func5:
; RV32IZBB:       # %bb.0:
; RV32IZBB-CHECK:    c.sext.h a0
; RV32IZBB-CHECK:    c.sext.h a1
;
; RV64IZBB-LABEL: func5:
; RV64IZBB:       # %bb.0:
; RV64IZBB-CHECK:    c.sext.h a0
; RV64IZBB-CHECK:    c.sext.h a1
  %a = mul i16 %y, %z
  %tmp = call i16 @llvm.sadd.sat.i16(i16 %x, i16 %a)
  ret i16 %tmp
}

declare i16 @llvm.ssub.sat.i16(i16, i16)
define i16 @func6(i16 %x, i16 %y, i16 %z) nounwind {
; RV32IZBB-LABEL: func6:
; RV32IZBB:       # %bb.0:
; RV32IZBB-CHECK:    c.sext.h a0
; RV32IZBB-CHECK:    c.sext.h a1
;
; RV64IZBB-LABEL: func6:
; RV64IZBB:       # %bb.0:
; RV64IZBB-CHECK:    sext.h a0, a0
; RV64IZBB-CHECK:    sext.h a1, a1
  %a = mul i16 %y, %z
  %tmp = call i16 @llvm.ssub.sat.i16(i16 %x, i16 %a)
  ret i16 %tmp
}