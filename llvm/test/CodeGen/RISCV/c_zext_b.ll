; RUN: llc -mtriple=riscv32 -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32I
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zce -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV32IZce
; RUN: llc -mtriple=riscv64 -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64I
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zce -verify-machineinstrs < %s \
; RUN:   | FileCheck %s -check-prefix=RV64IZce

define i8 @sltiu(i8 %a) nounwind {
; RV32I-LABEL: sltiu:
; RV32I:       # %bb.0:
; RV32I-NEXT:    andi a0, a0, 255
; RV32I-NEXT:    sltiu a0, a0, 3
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: sltiu:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.zext.b	a0
; RV32IZce-NEXT:    sltiu a0, a0, 3
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: sltiu:
; RV64I:       # %bb.0:
; RV64I-NEXT:    andi a0, a0, 255
; RV64I-NEXT:    sltiu a0, a0, 3
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: sltiu:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    c.zext.b	a0
; RV64IZce-NEXT:    sltiu a0, a0, 3
; RV64IZce-NEXT:    ret
  %1 = icmp ult i8 %a, 3
  %2 = zext i1 %1 to i8
  ret i8 %2
}

define i8 @sltu(i8 %a, i8 %b) nounwind {
; RV32I-LABEL: sltu:
; RV32I:       # %bb.0:
; RV32I-NEXT:    andi a1, a1, 255
; RV32I-NEXT:    andi a0, a0, 255
; RV32I-NEXT:    sltu a0, a0, a1
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: sltu:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.zext.b	a1
; RV32IZce-NEXT:    c.zext.b	a0
; RV32IZce-NEXT:    sltu a0, a0, a1
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: sltu:
; RV64I:       # %bb.0:
; RV64I-NEXT:    andi a1, a1, 255
; RV64I-NEXT:    andi a0, a0, 255
; RV64I-NEXT:    sltu a0, a0, a1
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: sltu:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    c.zext.b	a1
; RV64IZce-NEXT:    c.zext.b	a0
; RV64IZce-NEXT:    sltu a0, a0, a1
; RV64IZce-NEXT:    ret
  %1 = icmp ult i8 %a, %b
  %2 = zext i1 %1 to i8
  ret i8 %2
}

define i8 @srl(i8 %a, i8 %b) nounwind {
; RV32I-LABEL: srl:
; RV32I:       # %bb.0:
; RV32I-NEXT:    andi a0, a0, 255
; RV32I-NEXT:    srl a0, a0, a1
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: srl:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.zext.b  a0
; RV32IZce-NEXT:    srl a0, a0, a1
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: srl:
; RV64I:       # %bb.0:
; RV64I-NEXT:    andi a0, a0, 255
; RV64I-NEXT:    srl a0, a0, a1
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: srl:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    c.zext.b   a0
; RV64IZce-NEXT:    srl a0, a0, a1
; RV64IZce-NEXT:    ret
  %1 = lshr i8 %a, %b
  ret i8 %1
}

define zeroext i8 @sint8_arg_to_uint8_ret(i8 signext %a) nounwind {
; RV32I-LABEL: sint8_arg_to_uint8_ret:
; RV32I:       # %bb.0:
; RV32I-NEXT:    andi a0, a0, 255
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: sint8_arg_to_uint8_ret:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.zext.b  a0
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: sint8_arg_to_uint8_ret:
; RV64I:       # %bb.0:
; RV64I-NEXT:    andi a0, a0, 255
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: sint8_arg_to_uint8_ret:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    c.zext.b  a0
; RV64IZce-NEXT:    ret
  ret i8 %a
}

declare void @receive_uint8(i8)
define void @pass_sint8_as_uint8(i8 signext %a) nounwind {
; RV32I-LABEL: pass_sint8_as_uint8:
; RV32I:       # %bb.0:
; RV32I-NEXT:    addi sp, sp, -16
; RV32I-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32I-NEXT:    andi a0, a0, 255
; RV32I-NEXT:    call receive_uint8@plt
; RV32I-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32I-NEXT:    addi sp, sp, 16
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: pass_sint8_as_uint8:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    addi sp, sp, -16
; RV32IZce-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    c.zext.b  a0
; RV32IZce-NEXT:    call receive_uint8@plt
; RV32IZce-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    addi sp, sp, 16
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: pass_sint8_as_uint8:
; RV64I:       # %bb.0:
; RV64I-NEXT:    addi sp, sp, -16
; RV64I-NEXT:    sd	ra, 8(sp)   # 8-byte Folded Spill
; RV64I-NEXT:    andi a0, a0, 255
; RV64I-NEXT:    call receive_uint8@plt
; RV64I-NEXT:    ld	ra, 8(sp)   # 8-byte Folded Reload
; RV64I-NEXT:    addi sp, sp, 16
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: pass_sint8_as_uint8:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    addi sp, sp, -16
; RV64IZce-NEXT:    sd	ra, 8(sp)   # 8-byte Folded Spill
; RV64IZce-NEXT:    c.zext.b  a0
; RV64IZce-NEXT:    call receive_uint8@plt
; RV64IZce-NEXT:    ld	ra, 8(sp)   # 8-byte Folded Reload
; RV64IZce-NEXT:    addi sp, sp, 16
; RV64IZce-NEXT:    ret
  call void @receive_uint8(i8 zeroext %a)
  ret void
}

declare i8 @return_sint8()
define zeroext i8 @ret_callresult_sint8_as_uint8() nounwind {
; RV32I-LABEL: ret_callresult_sint8_as_uint8:
; RV32I:       # %bb.0:
; RV32I-NEXT:    addi sp, sp, -16
; RV32I-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32I-NEXT:    call return_sint8@plt
; RV32I-NEXT:    andi a0, a0, 255
; RV32I-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32I-NEXT:    addi sp, sp, 16
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: ret_callresult_sint8_as_uint8:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    addi sp, sp, -16
; RV32IZce-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    call return_sint8@plt
; RV32IZce-NEXT:    c.zext.b   a0
; RV32IZce-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    addi sp, sp, 16
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: ret_callresult_sint8_as_uint8:
; RV64I:       # %bb.0:
; RV64I-NEXT:    addi sp, sp, -16
; RV64I-NEXT:    sd	ra, 8(sp)   # 8-byte Folded Spill
; RV64I-NEXT:    call return_sint8@plt
; RV64I-NEXT:    andi a0, a0, 255
; RV64I-NEXT:    ld	ra, 8(sp)   # 8-byte Folded Reload
; RV64I-NEXT:    addi sp, sp, 16
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: ret_callresult_sint8_as_uint8:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    addi sp, sp, -16
; RV64IZce-NEXT:    sd	ra, 8(sp)   # 8-byte Folded Spill
; RV64IZce-NEXT:    call return_sint8@plt
; RV64IZce-NEXT:    c.zext.b   a0
; RV64IZce-NEXT:    ld	ra, 8(sp)   # 8-byte Folded Reload
; RV64IZce-NEXT:    addi sp, sp, 16
; RV64IZce-NEXT:    ret
  %1 = call signext i8 @return_sint8()
  ret i8 %1
}

define zeroext i8 @anyint32_arg_to_uint8_ret(i32 signext %a) nounwind {
; RV32I-LABEL: anyint32_arg_to_uint8_ret:
; RV32I:       # %bb.0:
; RV32I-NEXT:    andi a0, a0, 255
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: anyint32_arg_to_uint8_ret:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.zext.b   a0
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: anyint32_arg_to_uint8_ret:
; RV64I:       # %bb.0:
; RV64I-NEXT:    andi a0, a0, 255
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: anyint32_arg_to_uint8_ret:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    c.zext.b   a0
; RV64IZce-NEXT:    ret
  %1 = trunc i32 %a to i8
  ret i8 %1
}

define void @pass_anyint32_as_uint8(i32 signext %a) nounwind {
; RV32I-LABEL: pass_anyint32_as_uint8:
; RV32I:       # %bb.0:
; RV32I-NEXT:    addi sp, sp, -16
; RV32I-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32I-NEXT:    andi a0, a0, 255
; RV32I-NEXT:    call receive_uint8@plt
; RV32I-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32I-NEXT:    addi sp, sp, 16
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: pass_anyint32_as_uint8:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    addi sp, sp, -16
; RV32IZce-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    c.zext.b   a0
; RV32IZce-NEXT:    call receive_uint8@plt
; RV32IZce-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    addi sp, sp, 16
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: pass_anyint32_as_uint8:
; RV64I:       # %bb.0:
; RV64I-NEXT:    addi sp, sp, -16
; RV64I-NEXT:    sd	ra, 8(sp)   # 8-byte Folded Spill
; RV64I-NEXT:    andi a0, a0, 255
; RV64I-NEXT:    call receive_uint8@plt
; RV64I-NEXT:    ld	ra, 8(sp)   # 8-byte Folded Reload
; RV64I-NEXT:    addi sp, sp, 16
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: pass_anyint32_as_uint8:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    addi sp, sp, -16
; RV64IZce-NEXT:    sd	ra, 8(sp)   # 8-byte Folded Spill
; RV64IZce-NEXT:    c.zext.b   a0
; RV64IZce-NEXT:    call receive_uint8@plt
; RV64IZce-NEXT:    ld	ra, 8(sp)   # 8-byte Folded Reload
; RV64IZce-NEXT:    addi sp, sp, 16
; RV64IZce-NEXT:    ret
  %1 = trunc i32 %a to i8
  call void @receive_uint8(i8 zeroext %1)
  ret void
}

declare i32 @return_anyint32()
define zeroext i8 @ret_callresult_anyint32_as_uint8() nounwind {
; RV32I-LABEL: ret_callresult_anyint32_as_uint8:
; RV32I:       # %bb.0:
; RV32I-NEXT:    addi sp, sp, -16
; RV32I-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32I-NEXT:    call return_anyint32@plt
; RV32I-NEXT:    andi a0, a0, 255
; RV32I-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32I-NEXT:    addi sp, sp, 16
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: ret_callresult_anyint32_as_uint8:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    addi sp, sp, -16
; RV32IZce-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    call return_anyint32@plt
; RV32IZce-NEXT:    c.zext.b   a0
; RV32IZce-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    addi sp, sp, 16
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: ret_callresult_anyint32_as_uint8:
; RV64I:       # %bb.0:
; RV64I-NEXT:    addi sp, sp, -16
; RV64I-NEXT:    sd	ra, 8(sp)   # 8-byte Folded Spill
; RV64I-NEXT:    call return_anyint32@plt
; RV64I-NEXT:    andi a0, a0, 255
; RV64I-NEXT:    ld	ra, 8(sp)   # 8-byte Folded Reload
; RV64I-NEXT:    addi sp, sp, 16
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: ret_callresult_anyint32_as_uint8:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    addi sp, sp, -16
; RV64IZce-NEXT:    sd	ra, 8(sp)   # 8-byte Folded Spill
; RV64IZce-NEXT:    call return_anyint32@plt
; RV64IZce-NEXT:    c.zext.b   a0
; RV64IZce-NEXT:    ld	ra, 8(sp)   # 8-byte Folded Reload
; RV64IZce-NEXT:    addi sp, sp, 16
; RV64IZce-NEXT:    ret
  %1 = call signext i32 @return_anyint32()
  %2 = trunc i32 %1 to i8
  ret i8 %2
}

define i8 @udiv8(i8 %a, i8 %b) nounwind {
; RV32I-LABEL: udiv8:
; RV32I:       # %bb.0:
; RV32I-NEXT:    addi sp, sp, -16
; RV32I-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32I-NEXT:    andi a0, a0, 255
; RV32I-NEXT:    andi a1, a1, 255
; RV32I-NEXT:    call __udivsi3@plt
; RV32I-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32I-NEXT:    addi sp, sp, 16
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: udiv8:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    addi sp, sp, -16
; RV32IZce-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    c.zext.b   a0
; RV32IZce-NEXT:    c.zext.b   a1
; RV32IZce-NEXT:    call __udivsi3@plt
; RV32IZce-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    addi sp, sp, 16
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: udiv8:
; RV64I:       # %bb.0:
; RV64I-NEXT:    addi sp, sp, -16
; RV64I-NEXT:    sd ra, 8(sp) # 8-byte Folded Spill
; RV64I-NEXT:    andi a0, a0, 255
; RV64I-NEXT:    andi a1, a1, 255
; RV64I-NEXT:    call __udivdi3@plt
; RV64I-NEXT:    ld ra, 8(sp) # 8-byte Folded Reload
; RV64I-NEXT:    addi sp, sp, 16
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: udiv8:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    addi sp, sp, -16
; RV64IZce-NEXT:    sd ra, 8(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    c.zext.b   a0
; RV64IZce-NEXT:    c.zext.b   a1
; RV64IZce-NEXT:    call __udivdi3@plt
; RV64IZce-NEXT:    ld ra, 8(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    addi sp, sp, 16
; RV64IZce-NEXT:    ret
  %1 = udiv i8 %a, %b
  ret i8 %1
}

define i8 @udiv8_constant(i8 %a) nounwind {
; RV32I-LABEL: udiv8_constant:
; RV32I:       # %bb.0:
; RV32I-NEXT:    addi sp, sp, -16
; RV32I-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32I-NEXT:    andi a0, a0, 255
; RV32I-NEXT:    addi a1, zero, 5
; RV32I-NEXT:    call __udivsi3@plt
; RV32I-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32I-NEXT:    addi sp, sp, 16
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: udiv8_constant:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    addi sp, sp, -16
; RV32IZce-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    c.zext.b   a0
; RV32IZce-NEXT:    addi a1, zero, 5
; RV32IZce-NEXT:    call __udivsi3@plt
; RV32IZce-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    addi sp, sp, 16
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: udiv8_constant:
; RV64I:       # %bb.0:
; RV64I-NEXT:    addi sp, sp, -16
; RV64I-NEXT:    sd ra, 8(sp) # 8-byte Folded Spill
; RV64I-NEXT:    andi a0, a0, 255
; RV64I-NEXT:    addi a1, zero, 5
; RV64I-NEXT:    call __udivdi3@plt
; RV64I-NEXT:    ld ra, 8(sp) # 8-byte Folded Reload
; RV64I-NEXT:    addi sp, sp, 16
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: udiv8_constant:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    addi sp, sp, -16
; RV64IZce-NEXT:    sd ra, 8(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    c.zext.b   a0
; RV64IZce-NEXT:    addi a1, zero, 5
; RV64IZce-NEXT:    call __udivdi3@plt
; RV64IZce-NEXT:    ld ra, 8(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    addi sp, sp, 16
; RV64IZce-NEXT:    ret
  %1 = udiv i8 %a, 5
  ret i8 %1
}

define i8 @udiv8_pow2(i8 %a) nounwind {
; RV32I-LABEL: udiv8_pow2:
; RV32I:       # %bb.0:
; RV32I-NEXT:    andi a0, a0, 248
; RV32I-NEXT:    srli a0, a0, 3
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: udiv8_pow2:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    andi a0, a0, 248
; RV32IZce-NEXT:    srli a0, a0, 3
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: udiv8_pow2:
; RV64I:       # %bb.0:
; RV64I-NEXT:    andi a0, a0, 248
; RV64I-NEXT:    srli a0, a0, 3
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: udiv8_pow2:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    andi a0, a0, 248
; RV64IZce-NEXT:    srli a0, a0, 3
; RV64IZce-NEXT:    ret
  %1 = udiv i8 %a, 8
  ret i8 %1
}

define i8 @urem8(i8 %a, i8 %b) nounwind {
; RV32I-LABEL: urem8:
; RV32I:       # %bb.0:
; RV32I-NEXT:    addi sp, sp, -16
; RV32I-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32I-NEXT:    andi a0, a0, 255
; RV32I-NEXT:    andi a1, a1, 255
; RV32I-NEXT:    call __umodsi3@plt
; RV32I-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32I-NEXT:    addi sp, sp, 16
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: urem8:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    addi sp, sp, -16
; RV32IZce-NEXT:    sw ra, 12(sp) # 4-byte Folded Spill
; RV32IZce-NEXT:    c.zext.b   a0
; RV32IZce-NEXT:    c.zext.b   a1
; RV32IZce-NEXT:    call __umodsi3@plt
; RV32IZce-NEXT:    lw ra, 12(sp) # 4-byte Folded Reload
; RV32IZce-NEXT:    addi sp, sp, 16
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: urem8:
; RV64I:       # %bb.0:
; RV64I-NEXT:    addi sp, sp, -16
; RV64I-NEXT:    sd ra, 8(sp) # 8-byte Folded Spill
; RV64I-NEXT:    andi a0, a0, 255
; RV64I-NEXT:    andi a1, a1, 255
; RV64I-NEXT:    call __umoddi3@plt
; RV64I-NEXT:    ld ra, 8(sp) # 8-byte Folded Reload
; RV64I-NEXT:    addi sp, sp, 16
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: urem8:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    addi sp, sp, -16
; RV64IZce-NEXT:    sd ra, 8(sp) # 8-byte Folded Spill
; RV64IZce-NEXT:    c.zext.b   a0
; RV64IZce-NEXT:    c.zext.b   a1
; RV64IZce-NEXT:    call __umoddi3@plt
; RV64IZce-NEXT:    ld ra, 8(sp) # 8-byte Folded Reload
; RV64IZce-NEXT:    addi sp, sp, 16
; RV64IZce-NEXT:    ret
  %1 = urem i8 %a, %b
  ret i8 %1
}

define i16 @zext_i8_to_i16(i8 %a) nounwind {
; RV32I-LABEL: zext_i8_to_i16:
; RV32I:       # %bb.0:
; RV32I-NEXT:    andi a0, a0, 255
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: zext_i8_to_i16:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.zext.b   a0
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: zext_i8_to_i16:
; RV64I:       # %bb.0:
; RV64I-NEXT:    andi a0, a0, 255
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: zext_i8_to_i16:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    c.zext.b   a0
; RV64IZce-NEXT:    ret
  %1 = zext i8 %a to i16
  ret i16 %1
}

define i32 @zext_i8_to_i32(i8 %a) nounwind {
; RV32I-LABEL: zext_i8_to_i32:
; RV32I:       # %bb.0:
; RV32I-NEXT:    andi a0, a0, 255
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: zext_i8_to_i32:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.zext.b   a0
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: zext_i8_to_i32:
; RV64I:       # %bb.0:
; RV64I-NEXT:    andi a0, a0, 255
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: zext_i8_to_i32:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    c.zext.b   a0
; RV64IZce-NEXT:    ret
  %1 = zext i8 %a to i32
  ret i32 %1
}

define i64 @zext_i8_to_i64(i8 %a) nounwind {
; RV32I-LABEL: zext_i8_to_i64:
; RV32I:       # %bb.0:
; RV32I-NEXT:    andi a0, a0, 255
; RV32I-NEXT:    mv a1, zero
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: zext_i8_to_i64:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    c.zext.b   a0
; RV32IZce-NEXT:    mv a1, zero
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: zext_i8_to_i64:
; RV64I:       # %bb.0:
; RV64I-NEXT:    andi a0, a0, 255
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: zext_i8_to_i64:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    c.zext.b   a0
; RV64IZce-NEXT:    ret
  %1 = zext i8 %a to i64
  ret i64 %1
}

declare i8 @llvm.uadd.sat.i8(i8, i8)
define i8 @func1(i8 %x, i8 %y, i8 %z) nounwind {
; RV32I-LABEL: func1:
; RV32I:       # %bb.0:
; RV32I:	addi	sp, sp, -16
; RV32I:	sw	ra, 12(sp)                      # 4-byte Folded Spill
; RV32I:	sw	s0, 8(sp)                       # 4-byte Folded Spill
; RV32I:	andi	s0, a0, 255
; RV32I:	mv	a0, a1
; RV32I:	mv	a1, a2
; RV32I:	call	__mulsi3@plt
; RV32I:	andi	a0, a0, 255
; RV32I:	add	a0, s0, a0
; RV32I:	addi	a1, zero, 255
; RV32I:	bltu	a0, a1, .LBB16_2
; RV32I:# %bb.1:
; RV32I:	addi	a0, zero, 255
; RV32I:.LBB16_2:
; RV32I:	lw	s0, 8(sp)                       # 4-byte Folded Reload
; RV32I:	lw	ra, 12(sp)                      # 4-byte Folded Reload
; RV32I:	addi	sp, sp, 16
; RV32I:	ret
;
; RV32IZce-LABEL: func1:
; RV32IZce-NEXT:       # %bb.0:
; RV32IZce-NEXT:	addi	sp, sp, -16
; RV32IZce-NEXT:	sw	ra, 12(sp)                      # 4-byte Folded Spill
; RV32IZce-NEXT:	sw	s0, 8(sp)                       # 4-byte Folded Spill
; RV32IZce-NEXT:	andi	s0, a0, 255
; RV32IZce-NEXT:	mv	a0, a1
; RV32IZce-NEXT:	mv	a1, a2
; RV32IZce-NEXT:	call	__mulsi3@plt
; RV32IZce-NEXT:	c.zext.b   a0
; RV32IZce-NEXT:	add	a0, s0, a0
; RV32IZce-NEXT:	addi	a1, zero, 255
; RV32IZce-NEXT:	bltu	a0, a1, .LBB16_2
; RV32IZce-NEXT:# %bb.1:
; RV32IZce-NEXT:	addi	a0, zero, 255
; RV32IZce-NEXT:.LBB16_2:
; RV32IZce-NEXT:	lw	s0, 8(sp)                       # 4-byte Folded Reload
; RV32IZce-NEXT:	lw	ra, 12(sp)                      # 4-byte Folded Reload
; RV32IZce-NEXT:	addi	sp, sp, 16
; RV32IZce-NEXT:	ret
;
; RV64I-LABEL: func1:
; RV64I:       # %bb.0:
; RV64I-NEXT:	addi	sp, sp, -16
; RV64I-NEXT:	sd	ra, 8(sp)                       # 8-byte Folded Spill
; RV64I-NEXT:	sd	s0, 0(sp)                       # 8-byte Folded Spill
; RV64I-NEXT:	andi	s0, a0, 255
; RV64I-NEXT:	mv	a0, a1
; RV64I-NEXT:	mv	a1, a2
; RV64I-NEXT:	call	__muldi3@plt
; RV64I-NEXT:	andi	a0, a0, 255
; RV64I-NEXT:	add	a0, s0, a0
; RV64I-NEXT:	addi	a1, zero, 255
; RV64I-NEXT:	bltu	a0, a1, .LBB16_2
; RV64I-NEXT:# %bb.1:
; RV64I-NEXT:	addi	a0, zero, 255
; RV64I-NEXT:.LBB16_2:
; RV64I-NEXT:	ld	s0, 0(sp)                       # 8-byte Folded Reload
; RV64I-NEXT:	ld	ra, 8(sp)                       # 8-byte Folded Reload
; RV64I-NEXT:	addi	sp, sp, 16
; RV64I-NEXT:	ret
;
; RV64IZce-LABEL: func1:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:	addi	sp, sp, -16
; RV64IZce-NEXT:	sd	ra, 8(sp)                       # 8-byte Folded Spill
; RV64IZce-NEXT:	sd	s0, 0(sp)                       # 8-byte Folded Spill
; RV64IZce-NEXT:	andi	s0, a0, 255
; RV64IZce-NEXT:	mv	a0, a1
; RV64IZce-NEXT:	mv	a1, a2
; RV64IZce-NEXT:	call	__muldi3@plt
; RV64IZce-NEXT:	c.zext.b   a0
; RV64IZce-NEXT:	add	a0, s0, a0
; RV64IZce-NEXT:	addi	a1, zero, 255
; RV64IZce-NEXT:	bltu	a0, a1, .LBB16_2
; RV64IZce-NEXT:# %bb.1:
; RV64IZce-NEXT:	addi	a0, zero, 255
; RV64IZce-NEXT:.LBB16_2:
; RV64IZce-NEXT:	ld	s0, 0(sp)                       # 8-byte Folded Reload
; RV64IZce-NEXT:	ld	ra, 8(sp)                       # 8-byte Folded Reload
; RV64IZce-NEXT:	addi	sp, sp, 16
; RV64IZce-NEXT:	ret
  %a = mul i8 %y, %z
  %tmp = call i8 @llvm.uadd.sat.i8(i8 %x, i8 %a)
  ret i8 %tmp
}

declare i8 @llvm.usub.sat.i8(i8, i8)
define i8 @func2(i8 %x, i8 %y, i8 %z) nounwind {
; RV32I-LABEL: func2:
; RV32I:       # %bb.0:
; RV32I-NEXT:    addi	sp, sp, -16
; RV32I-NEXT:    sw	ra, 12(sp)                      # 4-byte Folded Spill
; RV32I-NEXT:    sw	s0, 8(sp)                       # 4-byte Folded Spill
; RV32I-NEXT:    andi	s0, a0, 255
; RV32I-NEXT:    mv	a0, a1
; RV32I-NEXT:    mv	a1, a2
; RV32I-NEXT:    call	__mulsi3@plt
; RV32I-NEXT:    andi	a0, a0, 255
; RV32I-NEXT:    sub	a1, s0, a0
; RV32I-NEXT:    mv	a0, zero
; RV32I-NEXT:    bltu	s0, a1, .LBB17_2
; RV32I-NEXT:    # %bb.1:
; RV32I-NEXT:    mv	a0, a1
; RV32I-NEXT:    .LBB17_2:
; RV32I-NEXT:    lw	s0, 8(sp)                       # 4-byte Folded Reload
; RV32I-NEXT:    lw	ra, 12(sp)                      # 4-byte Folded Reload
; RV32I-NEXT:    addi	sp, sp, 16
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: func2:
; RV32IZce:# %bb.0:
; RV32IZce-NEXT:   addi	sp, sp, -16
; RV32IZce-NEXT:	sw	ra, 12(sp)                      # 4-byte Folded Spill
; RV32IZce-NEXT:	sw	s0, 8(sp)                       # 4-byte Folded Spill
; RV32IZce-NEXT:	andi	s0, a0, 255
; RV32IZce-NEXT:	mv	a0, a1
; RV32IZce-NEXT:	mv	a1, a2
; RV32IZce-NEXT:	call	__mulsi3@plt
; RV32IZce-NEXT:	c.zext.b	a0
; RV32IZce-NEXT:	sub	a1, s0, a0
; RV32IZce-NEXT:	mv	a0, zero
; RV32IZce-NEXT:	bltu	s0, a1, .LBB17_2
; RV32IZce-NEXT:# %bb.1:
; RV32IZce-NEXT:	mv	a0, a1
; RV32IZce-NEXT:.LBB17_2:
; RV32IZce-NEXT:	lw	s0, 8(sp)                       # 4-byte Folded Reload
; RV32IZce-NEXT:	lw	ra, 12(sp)                      # 4-byte Folded Reload
; RV32IZce-NEXT:	addi	sp, sp, 16
; RV32IZce-NEXT:	ret
;
; RV64I-LABEL: func2:
; RV64I:       # %bb.0:
; RV64I-NEXT:	addi	sp, sp, -16
; RV64I-NEXT:	sd	ra, 8(sp)                       # 8-byte Folded Spill
; RV64I-NEXT:	sd	s0, 0(sp)                       # 8-byte Folded Spill
; RV64I-NEXT:	andi	s0, a0, 255
; RV64I-NEXT:	mv	a0, a1
; RV64I-NEXT:	mv	a1, a2
; RV64I-NEXT:	call	__muldi3@plt
; RV64I-NEXT:	andi	a0, a0, 255
; RV64I-NEXT:	sub	a1, s0, a0
; RV64I-NEXT:	mv	a0, zero
; RV64I-NEXT:	bltu	s0, a1, .LBB17_2
; RV64I-NEXT:# %bb.1:
; RV64I-NEXT:	mv	a0, a1
; RV64I-NEXT:.LBB17_2:
; RV64I-NEXT:	ld	s0, 0(sp)                       # 8-byte Folded Reload
; RV64I-NEXT:	ld	ra, 8(sp)                       # 8-byte Folded Reload
; RV64I-NEXT:	addi	sp, sp, 16
; RV64I-NEXT:	ret
;
; RV64IZce-LABEL: func2:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:	addi	sp, sp, -16
; RV64IZce-NEXT:	sd	ra, 8(sp)                       # 8-byte Folded Spill
; RV64IZce-NEXT:	sd	s0, 0(sp)                       # 8-byte Folded Spill
; RV64IZce-NEXT:	andi	s0, a0, 255
; RV64IZce-NEXT:	mv	a0, a1
; RV64IZce-NEXT:	mv	a1, a2
; RV64IZce-NEXT:	call	__muldi3@plt
; RV64IZce-NEXT:	c.zext.b	a0
; RV64IZce-NEXT:	sub	a1, s0, a0
; RV64IZce-NEXT:	mv	a0, zero
; RV64IZce-NEXT:	bltu	s0, a1, .LBB17_2
; RV64IZce-NEXT:# %bb.1:
; RV64IZce-NEXT:	mv	a0, a1
; RV64IZce-NEXT:.LBB17_2:
; RV64IZce-NEXT:	ld	s0, 0(sp)                       # 8-byte Folded Reload
; RV64IZce-NEXT:	ld	ra, 8(sp)                       # 8-byte Folded Reload
; RV64IZce-NEXT:	addi	sp, sp, 16
; RV64IZce-NEXT:	ret
  %a = mul i8 %y, %z
  %tmp = call i8 @llvm.usub.sat.i8(i8 %x, i8 %a)
  ret i8 %tmp
}
