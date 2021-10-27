; RUN: llc -mtriple=riscv32 -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV32I %s
; RUN: llc -mtriple=riscv32 -mattr=+experimental-zcea -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV32IZce %s
; RUN: llc -mtriple=riscv64 -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV64I %s
; RUN: llc -mtriple=riscv64 -mattr=+experimental-zcea -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV64IZce %s

define i32 @mulhs_negative_constant(i32 %a) nounwind {
; RV32I-LABEL: mulhs_negative_constant:
; RV32I:       # %bb.0:
; RV32I-NEXT:    srai a1, a0, 31
; RV32I-NEXT:    slli a2, a0, 2
; RV32I-NEXT:    add a3, a2, a0
; RV32I-NEXT:    sltu a2, a3, a2
; RV32I-NEXT:    srli a0, a0, 30
; RV32I-NEXT:    slli a4, a1, 2
; RV32I-NEXT:    or a0, a4, a0
; RV32I-NEXT:    add a0, a0, a1
; RV32I-NEXT:    add a0, a0, a2
; RV32I-NEXT:    snez a1, a3
; RV32I-NEXT:    add a0, a0, a1
; RV32I-NEXT:    neg a0, a0
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: mulhs_negative_constant:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:	srai	a1, a0, 31
; RV32IZce-NEXT:	slli	a2, a0, 2
; RV32IZce-NEXT:	add	a3, a2, a0
; RV32IZce-NEXT:	sltu	a2, a3, a2
; RV32IZce-NEXT:	srli	a0, a0, 30
; RV32IZce-NEXT:	slli	a4, a1, 2
; RV32IZce-NEXT:	or	a0, a4, a0
; RV32IZce-NEXT:	add	a0, a0, a1
; RV32IZce-NEXT:	add	a0, a0, a2
; RV32IZce-NEXT:	snez	a1, a3
; RV32IZce-NEXT:	add	a0, a0, a1
; RV32IZce-NEXT:	c.neg	a0
; RV32IZce-NEXT:	ret
;
; RV64I-LABEL: mulhs_negative_constant:
; RV64I:       # %bb.0:
; RV64I-NEXT:    sext.w a0, a0
; RV64I-NEXT:    slli a1, a0, 2
; RV64I-NEXT:    add a0, a1, a0
; RV64I-NEXT:    neg a0, a0
; RV64I-NEXT:    srli a0, a0, 32
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: mulhs_negative_constant:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    sext.w a0, a0
; RV64IZce-NEXT:    slli a1, a0, 2
; RV64IZce-NEXT:    add a0, a1, a0
; RV64IZce-NEXT:    c.neg	a0
; RV64IZce-NEXT:    srli a0, a0, 32
; RV64IZce-NEXT:    ret
  %1 = sext i32 %a to i64
  %2 = mul i64 %1, -5
  %3 = lshr i64 %2, 32
  %4 = trunc i64 %3 to i32
  ret i32 %4
}

define i32 @muli32_m65(i32 %a) nounwind {
; RV32I-LABEL: muli32_m65:
; RV32I:       # %bb.0:
; RV32I-NEXT:    slli a1, a0, 6
; RV32I-NEXT:    add a0, a1, a0
; RV32I-NEXT:    neg a0, a0
; RV32I-NEXT:    ret
;
; RV32IMZce-LABEL: muli32_m65:
; RV32IMZce:       # %bb.0:
; RV32IMZce-NEXT:    slli a1, a0, 6
; RV32IMZce-NEXT:    add a0, a1, a0
; RV32IMZce-NEXT:    c.neg	a0
; RV32IMZce-NEXT:    ret
;
; RV64I-LABEL: muli32_m65:
; RV64I:       # %bb.0:
; RV64I-NEXT:    slli a1, a0, 6
; RV64I-NEXT:    add a0, a1, a0
; RV64I-NEXT:    negw a0, a0
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: muli32_m65:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT:    slli a1, a0, 6
; RV64IZce-NEXT:    add a0, a1, a0
; RV64IZce-NEXT:    negw a0, a0
; RV64IZce-NEXT:    ret
  %1 = mul i32 %a, -65
  ret i32 %1
}

define void @getSetCCResultType(<4 x i32>* %p, <4 x i32>* %q) nounwind {
; RV32I-LABEL: getSetCCResultType:
; RV32I:       # %bb.0:
; RV32I-NEXT:    lw a1, 12(a0)
; RV32I-NEXT:    lw a2, 8(a0)
; RV32I-NEXT:    lw a3, 4(a0)
; RV32I-NEXT:    lw a4, 0(a0)
; RV32I-NEXT:    seqz a1, a1
; RV32I-NEXT:    seqz a2, a2
; RV32I-NEXT:    seqz a3, a3
; RV32I-NEXT:    seqz a4, a4
; RV32I-NEXT:    neg a4, a4
; RV32I-NEXT:    neg a3, a3
; RV32I-NEXT:    neg a2, a2
; RV32I-NEXT:    neg a1, a1
; RV32I-NEXT:    sw a1, 12(a0)
; RV32I-NEXT:    sw a2, 8(a0)
; RV32I-NEXT:    sw a3, 4(a0)
; RV32I-NEXT:    sw a4, 0(a0)
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: getSetCCResultType:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    lw a1, 12(a0)
; RV32IZce-NEXT:    lw a2, 8(a0)
; RV32IZce-NEXT:    lw a3, 4(a0)
; RV32IZce-NEXT:    lw a4, 0(a0)
; RV32IZce-NEXT:    seqz a1, a1
; RV32IZce-NEXT:    seqz a2, a2
; RV32IZce-NEXT:    seqz a3, a3
; RV32IZce-NEXT:    seqz a4, a4
; RV32IZce-NEXT:    c.neg a4
; RV32IZce-NEXT:    c.neg a3
; RV32IZce-NEXT:    c.neg a2
; RV32IZce-NEXT:    c.neg a1
; RV32IZce-NEXT:    sw a1, 12(a0)
; RV32IZce-NEXT:    sw a2, 8(a0)
; RV32IZce-NEXT:    sw a3, 4(a0)
; RV32IZce-NEXT:    sw a4, 0(a0)
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: getSetCCResultType:
; RV64I:       # %bb.0: # %entry
; RV64I-NEXT:    lw a1, 12(a0)
; RV64I-NEXT:    lw a2, 8(a0)
; RV64I-NEXT:    lw a3, 4(a0)
; RV64I-NEXT:    lw a4, 0(a0)
; RV64I-NEXT:    seqz a1, a1
; RV64I-NEXT:    seqz a2, a2
; RV64I-NEXT:    seqz a3, a3
; RV64I-NEXT:    seqz a4, a4
; RV64I-NEXT:    neg a4, a4
; RV64I-NEXT:    neg a3, a3
; RV64I-NEXT:    neg a2, a2
; RV64I-NEXT:    neg a1, a1
; RV64I-NEXT:    sw a1, 12(a0)
; RV64I-NEXT:    sw a2, 8(a0)
; RV64I-NEXT:    sw a3, 4(a0)
; RV64I-NEXT:    sw a4, 0(a0)
; RV64I-NEXT:    ret
;
; RV64IZce-LABEL: getSetCCResultType:
; RV64IZce:       # %bb.0: # %entry
; RV64IZce-NEXT:    lw a1, 12(a0)
; RV64IZce-NEXT:    lw a2, 8(a0)
; RV64IZce-NEXT:    lw a3, 4(a0)
; RV64IZce-NEXT:    lw a4, 0(a0)
; RV64IZce-NEXT:    seqz a1, a1
; RV64IZce-NEXT:    seqz a2, a2
; RV64IZce-NEXT:    seqz a3, a3
; RV64IZce-NEXT:    seqz a4, a4
; RV64IZce-NEXT:    c.neg a4
; RV64IZce-NEXT:    c.neg a3
; RV64IZce-NEXT:    c.neg a2
; RV64IZce-NEXT:    c.neg a1
; RV64IZce-NEXT:    sw a1, 12(a0)
; RV64IZce-NEXT:    sw a2, 8(a0)
; RV64IZce-NEXT:    sw a3, 4(a0)
; RV64IZce-NEXT:    sw a4, 0(a0)
; RV64IZce-NEXT:    ret
entry:
  %0 = load <4 x i32>, <4 x i32>* %p, align 16
  %cmp = icmp eq <4 x i32> %0, zeroinitializer
  %sext = sext <4 x i1> %cmp to <4 x i32>
  store <4 x i32> %sext, <4 x i32>* %p, align 16
  ret void
}

declare i32 @llvm.fshl.i32(i32, i32, i32)

define i32 @rol_i32(i32 %a, i32 %b) nounwind {
; RV32I-LABEL: rol_i32:
; RV32I:       # %bb.0:
; RV32I-NEXT:    sll a2, a0, a1
; RV32I-NEXT:    neg a1, a1
; RV32I-NEXT:    srl a0, a0, a1
; RV32I-NEXT:    or a0, a2, a0
; RV32I-NEXT:    ret
;
; RV32IZce-LABEL: rol_i32:
; RV32IZce:       # %bb.0:
; RV32IZce-NEXT:    sll a2, a0, a1
; RV32IZce-NEXT:    c.neg
; RV32IZce-NEXT:    srl a0, a0, a1
; RV32IZce-NEXT:    or a0, a2, a0
; RV32IZce-NEXT:    ret
;
; RV64I-LABEL: rol_i32:
; RV64I:       # %bb.0:
; RV64I-NEXT: 	sllw	a2, a0, a1
; RV64I-NEXT:	neg	a1, a1
; RV64I-NEXT:	srlw	a0, a0, a1
; RV64I-NEXT:	or	a0, a2, a0
; RV64I-NEXT:	ret
;
; RV64IZce-LABEL: rol_i32:
; RV64IZce:       # %bb.0:
; RV64IZce-NEXT: 	sllw	a2, a0, a1
; RV64IZce-NEXT:	c.neg	a1
; RV64IZce-NEXT:	srlw	a0, a0, a1
; RV64IZce-NEXT:	or	a0, a2, a0
; RV64IZce-NEXT:	ret
;
  %or = tail call i32 @llvm.fshl.i32(i32 %a, i32 %a, i32 %b)
  ret i32 %or
}

