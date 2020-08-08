; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define internal void @vse32_v_f32m1(<vscale x 2 x float> %value) #1 {
entry:
;CHECK: addi	sp, sp, -16
;CHECK: .cfi_def_cfa_offset 16
;CHECK: addi	s0, sp, 16
;CHECK: .cfi_def_cfa s0, 0
;CHECK: csrr	a0, vlenb
;CHECK: sub	sp, sp, a0
;CHECK: sd	sp, -8(s0)
;CHECK: addi	a0, s0, -8
;CHECK: vse32.v	v16, (a0)
;CHECK: addi	sp, s0, -16
;CHECK: addi	sp, sp, 16
;CHECK: ret
  %addr = alloca <vscale x 2 x float>, align 8
  store <vscale x 2 x float> %value, <vscale x 2 x float>* %addr, align 8
  ret void
}