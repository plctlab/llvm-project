; RUN: llc -mtriple=riscv32 -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32I
; RUN: llc -mtriple=riscv32 -mattr=+experimental-b,+experimental-zce -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IB
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbb,+experimental-zce -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IBB
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zbp,+experimental-zce -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IBP

; NOTE: /home/wuxinlong/workspace/llvm-project/build/bin/llc -mtriple=riscv32 -mattr=+experimental-b,+experimental-zce -verify-machineinstrs < /home/wuxinlong/workspace/llvm-project/llvm/test/CodeGen/RISCV/rvZce/rv32zcee.ll  --print-after-all -o test.ll

define i16 @srli_i16(i16 %a) nounwind {
; RV32I-LABEL: srli_i16:
; RV32I:       # %bb.0:
; RV32I-NEXT:    slli a0, a0, 16
; RV32I-NEXT:    srli a0, a0, 22
; RV32I-NEXT:    ret
;
; RV32IB-LABEL: srli_i16:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    c.zext.h a0
; RV32IB-NEXT:    srli a0, a0, 6
; RV32IB-NEXT:    ret
;
; RV32IBB-LABEL: srli_i16:
; RV32IBB:       # %bb.0:
; RV32IBB-NEXT:    c.zext.h a0
; RV32IBB-NEXT:    srli a0, a0, 6
; RV32IBB-NEXT:    ret
;
; RV32IBP-LABEL: srli_i16:
; RV32IBP:       # %bb.0:
; RV32IBP-NEXT:    zext.h a0, a0
; RV32IBP-NEXT:    srli a0, a0, 6
; RV32IBP-NEXT:    ret
;
; RV64I-LABEL: srli_i16:
; RV64I:       # %bb.0:
; RV64I-NEXT:    slli a0, a0, 48
; RV64I-NEXT:    srli a0, a0, 54
; RV64I-NEXT:    ret
;
; RV64IB-LABEL: srli_i16:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    c.zext.h a0
; RV64IB-NEXT:    srli a0, a0, 6
; RV64IB-NEXT:    ret
;
; RV64IBB-LABEL: srli_i16:
; RV64IBB:       # %bb.0:
; RV64IBB-NEXT:    c.zext.h a0
; RV64IBB-NEXT:    srli a0, a0, 6
; RV64IBB-NEXT:    ret
;
; RV64IBP-LABEL: srli_i16:
; RV64IBP:       # %bb.0:
; RV64IBP-NEXT:    zext.h a0, a0
; RV64IBP-NEXT:    srli a0, a0, 6
; RV64IBP-NEXT:    ret
  %1 = lshr i16 %a, 6
  ret i16 %1
}

define i32 @zexth_i32(i32 %a) nounwind {
; RV32I-LABEL: zexth_i32:
; RV32I:       # %bb.0:
; RV32I-NEXT:    lui a1, 16
; RV32I-NEXT:    addi a1, a1, -1
; RV32I-NEXT:    and a0, a0, a1
; RV32I-NEXT:    ret
;
; RV32IB-LABEL: zexth_i32:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    c.zext.h a0
; RV32IB-NEXT:    ret
;
; RV32IBB-LABEL: zexth_i32:
; RV32IBB:       # %bb.0:
; RV32IBB-NEXT:    c.zext.h a0
; RV32IBB-NEXT:    ret
;
; RV64I-LABEL: zexth_i32:
; RV64I:       # %bb.0:
; RV64I-NEXT:    lui a1, 16
; RV64I-NEXT:    addiw a1, a1, -1
; RV64I-NEXT:    and a0, a0, a1
; RV64I-NEXT:    ret
;
; RV64IB-LABEL: zexth_i32:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    c.zext.h a0
; RV64IB-NEXT:    ret
;
; RV64IBB-LABEL: zexth_i32:
; RV64IBB:       # %bb.0:
; RV64IBB-NEXT:    c.zext.h a0
; RV64IBB-NEXT:    ret
  %and = and i32 %a, 65535
  ret i32 %and
}

define i64 @zexth_i64(i64 %a) nounwind {
; RV32I-LABEL: zexth_i64:
; RV32I:       # %bb.0:
; RV32I-NEXT:    lui a1, 16
; RV32I-NEXT:    addi a1, a1, -1
; RV32I-NEXT:    and a0, a0, a1
; RV32I-NEXT:    mv a1, zero
; RV32I-NEXT:    ret
;
; RV32IB-LABEL: zexth_i64:
; RV32IB:       # %bb.0:
; RV32IB-NEXT:    c.zext.h a0
; RV32IB-NEXT:    mv a1, zero
; RV32IB-NEXT:    ret
;
; RV32IBB-LABEL: zexth_i64:
; RV32IBB:       # %bb.0:
; RV32IBB-NEXT:    c.zext.h a0
; RV32IBB-NEXT:    mv a1, zero
; RV32IBB-NEXT:    ret
;
; RV64I-LABEL: zexth_i64:
; RV64I:       # %bb.0:
; RV64I-NEXT:    lui a1, 16
; RV64I-NEXT:    addiw a1, a1, -1
; RV64I-NEXT:    and a0, a0, a1
; RV64I-NEXT:    ret
;
; RV64IB-LABEL: zexth_i64:
; RV64IB:       # %bb.0:
; RV64IB-NEXT:    c.zext.h a0
; RV64IB-NEXT:    ret
;
; RV64IBB-LABEL: zexth_i64:
; RV64IBB:       # %bb.0:
; RV64IBB-NEXT:    c.zext.h a0
; RV64IBB-NEXT:    ret
  %and = and i64 %a, 65535
  ret i64 %and
}

declare i16 @llvm.uadd.sat.i16(i16, i16)
define i16 @func1(i16 %x, i16 %y, i16 %z) nounwind {
; RV32IBB-LABEL: func1:
; RV32IBB:       # %bb.0:
; RV32IBB-CHECK:    zext.h s0, a0
; RV32IBB-CHECK:    c.zext.h a1
;
; RV64IBB-LABEL: func1:
; RV64IBB:       # %bb.0:
; RV64IBB-CHECK:    zext.h s0, a0
; RV64IBB-CHECK:    c.zext.h a1
  %a = mul i16 %y, %z
  %tmp = call i16 @llvm.uadd.sat.i16(i16 %x, i16 %a)
  ret i16 %tmp
}

declare i16 @llvm.usub.sat.i16(i16, i16)
define i16 @func2(i16 %x, i16 %y, i16 %z) nounwind {
; RV32IBB-LABEL: func2:
; RV32IBB:       # %bb.0:
; RV32IBB-CHECK:    zext.h s0, a0
; RV32IBB-CHECK:    c.zext.h a1
;
; RV64IBB-LABEL: func2:
; RV64IBB:       # %bb.0:
; RV64IBB-CHECK:    zext.h s0, a0
; RV64IBB-CHECK:    c.zext.h a1
  %a = mul i16 %y, %z
  %tmp = call i16 @llvm.usub.sat.i16(i16 %x, i16 %a)
  ret i16 %tmp
}
