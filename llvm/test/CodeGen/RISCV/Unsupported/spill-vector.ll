; RUN: llc -mtriple=riscv64 -mattr=+v -verify-machineinstrs < %s \
; RUN:   | FileCheck -check-prefix=RV64I %s

; Function Attrs: nounwind
define dso_local void @test(float* %input) local_unnamed_addr #0 {
;RV64I: .Ltest$local:
;RV64I: # %bb.0:                                # %entry
;RV64I: addi	sp, sp, -32
;RV64I: sd	ra, 24(sp)
;RV64I: sd	s0, 16(sp)
;RV64I: addi	s0, sp, 32
;RV64I: csrr	a1, vlenb
;RV64I: sub	sp, sp, a1
;RV64I: sd	sp, -24(s0)
;RV64I: sub	sp, sp, a1
;RV64I: sd	sp, -32(s0)
;RV64I: addi	a1, zero, 8
;RV64I: addi	a2, zero, 1
;RV64I: vsetvl	a1, a2, a1
;RV64I: vle32.v	v0, 0(a0)
;RV64I: vfadd.vv	v1, v0, v0
;RV64I: ld	a1, -24(s0)
;RV64I: vs1r.v	v1, 0(a1)
;RV64I: vfadd.vv	v1, v1, v1
;RV64I: ld	a1, -32(s0)
;RV64I: vs1r.v	v1, 0(a1)
;RV64I: vfadd.vv	v3, v1, v1
;RV64I: vfadd.vv	v4, v3, v3
;RV64I: vfadd.vv	v5, v4, v4
;RV64I: vfadd.vv	v6, v5, v5
;RV64I: vfadd.vv	v7, v6, v6
;RV64I: vfadd.vv	v8, v7, v7
;RV64I: vfadd.vv	v9, v8, v8
;RV64I: vfadd.vv	v10, v9, v9
;RV64I: vfadd.vv	v11, v10, v10
;RV64I: vfadd.vv	v12, v11, v11
;RV64I: vfadd.vv	v13, v12, v12
;RV64I: vfadd.vv	v14, v13, v13
;RV64I: vfadd.vv	v15, v14, v14
;RV64I: vfadd.vv	v16, v15, v15
;RV64I: vfadd.vv	v17, v16, v16
;RV64I: vfadd.vv	v18, v17, v17
;RV64I: vfadd.vv	v19, v18, v18
;RV64I: vfadd.vv	v20, v19, v19
;RV64I: vfadd.vv	v21, v20, v20
;RV64I: vfadd.vv	v22, v21, v21
;RV64I: vfadd.vv	v23, v22, v22
;RV64I: vfadd.vv	v24, v23, v23
;RV64I: vfadd.vv	v25, v24, v24
;RV64I: vfadd.vv	v26, v25, v25
;RV64I: vfadd.vv	v27, v26, v26
;RV64I: vfadd.vv	v28, v27, v27
;RV64I: vfadd.vv	v29, v28, v28
;RV64I: vfadd.vv	v30, v29, v29
;RV64I: vfadd.vv	v31, v30, v30
;RV64I: vfadd.vv	v1, v31, v31
;RV64I: vfadd.vv	v0, v1, v0
;RV64I: ld	a1, -24(s0)
;RV64I: vl1r.v	v2, 0(a1)
;RV64I: vfadd.vv	v0, v0, v2
;RV64I: ld	a1, -32(s0)
;RV64I: vl1r.v	v2, 0(a1)
;RV64I: vfadd.vv	v0, v0, v2
;RV64I: vfadd.vv	v0, v0, v3
;RV64I: vfadd.vv	v0, v0, v4
;RV64I: vfadd.vv	v0, v0, v5
;RV64I: vfadd.vv	v0, v0, v6
;RV64I: vfadd.vv	v0, v0, v7
;RV64I: vfadd.vv	v0, v0, v8
;RV64I: vfadd.vv	v0, v0, v9
;RV64I: vfadd.vv	v0, v0, v10
;RV64I: vfadd.vv	v0, v0, v11
;RV64I: vfadd.vv	v0, v0, v12
;RV64I: vfadd.vv	v0, v0, v13
;RV64I: vfadd.vv	v0, v0, v14
;RV64I: vfadd.vv	v0, v0, v15
;RV64I: vfadd.vv	v0, v0, v16
;RV64I: vfadd.vv	v0, v0, v17
;RV64I: vfadd.vv	v0, v0, v18
;RV64I: vfadd.vv	v0, v0, v19
;RV64I: vfadd.vv	v0, v0, v20
;RV64I: vfadd.vv	v0, v0, v21
;RV64I: vfadd.vv	v0, v0, v22
;RV64I: vfadd.vv	v0, v0, v23
;RV64I: vfadd.vv	v0, v0, v24
;RV64I: vfadd.vv	v0, v0, v25
;RV64I: vfadd.vv	v0, v0, v26
;RV64I: vfadd.vv	v0, v0, v27
;RV64I: vfadd.vv	v0, v0, v28
;RV64I: vfadd.vv	v0, v0, v29
;RV64I: vfadd.vv	v0, v0, v30
;RV64I: vfadd.vv	v0, v0, v31
;RV64I: vfadd.vv	v0, v0, v1
;RV64I: vse32.v	v0, 0(a0)
;RV64I: addi	sp, s0, -32
;RV64I: ld	s0, 16(sp)
;RV64I: ld	ra, 24(sp)
;RV64I: addi	sp, sp, 32
;RV64I: ret
entry:
  %0 = tail call i64 @llvm.riscv.vsetvl.i64.i64.i64(i64 1, i64 8) #3
  %1 = tail call <vscale x 1 x float> @llvm.riscv.vle32.v.f32m1(float* %input) #3
  %2 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %1, <vscale x 1 x float> %1) #3
  %3 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %2, <vscale x 1 x float> %2) #3
  %4 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %3, <vscale x 1 x float> %3) #3
  %5 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %4, <vscale x 1 x float> %4) #3
  %6 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %5, <vscale x 1 x float> %5) #3
  %7 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %6, <vscale x 1 x float> %6) #3
  %8 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %7, <vscale x 1 x float> %7) #3
  %9 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %8, <vscale x 1 x float> %8) #3
  %10 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %9, <vscale x 1 x float> %9) #3
  %11 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %10, <vscale x 1 x float> %10) #3
  %12 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %11, <vscale x 1 x float> %11) #3
  %13 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %12, <vscale x 1 x float> %12) #3
  %14 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %13, <vscale x 1 x float> %13) #3
  %15 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %14, <vscale x 1 x float> %14) #3
  %16 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %15, <vscale x 1 x float> %15) #3
  %17 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %16, <vscale x 1 x float> %16) #3
  %18 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %17, <vscale x 1 x float> %17) #3
  %19 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %18, <vscale x 1 x float> %18) #3
  %20 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %19, <vscale x 1 x float> %19) #3
  %21 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %20, <vscale x 1 x float> %20) #3
  %22 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %21, <vscale x 1 x float> %21) #3
  %23 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %22, <vscale x 1 x float> %22) #3
  %24 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %23, <vscale x 1 x float> %23) #3
  %25 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %24, <vscale x 1 x float> %24) #3
  %26 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %25, <vscale x 1 x float> %25) #3
  %27 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %26, <vscale x 1 x float> %26) #3
  %28 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %27, <vscale x 1 x float> %27) #3
  %29 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %28, <vscale x 1 x float> %28) #3
  %30 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %29, <vscale x 1 x float> %29) #3
  %31 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %30, <vscale x 1 x float> %30) #3
  %32 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %31, <vscale x 1 x float> %31) #3
  %33 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %32, <vscale x 1 x float> %32) #3
  %34 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %33, <vscale x 1 x float> %1) #3
  %35 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %34, <vscale x 1 x float> %2) #3
  %36 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %35, <vscale x 1 x float> %3) #3
  %37 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %36, <vscale x 1 x float> %4) #3
  %38 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %37, <vscale x 1 x float> %5) #3
  %39 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %38, <vscale x 1 x float> %6) #3
  %40 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %39, <vscale x 1 x float> %7) #3
  %41 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %40, <vscale x 1 x float> %8) #3
  %42 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %41, <vscale x 1 x float> %9) #3
  %43 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %42, <vscale x 1 x float> %10) #3
  %44 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %43, <vscale x 1 x float> %11) #3
  %45 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %44, <vscale x 1 x float> %12) #3
  %46 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %45, <vscale x 1 x float> %13) #3
  %47 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %46, <vscale x 1 x float> %14) #3
  %48 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %47, <vscale x 1 x float> %15) #3
  %49 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %48, <vscale x 1 x float> %16) #3
  %50 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %49, <vscale x 1 x float> %17) #3
  %51 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %50, <vscale x 1 x float> %18) #3
  %52 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %51, <vscale x 1 x float> %19) #3
  %53 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %52, <vscale x 1 x float> %20) #3
  %54 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %53, <vscale x 1 x float> %21) #3
  %55 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %54, <vscale x 1 x float> %22) #3
  %56 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %55, <vscale x 1 x float> %23) #3
  %57 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %56, <vscale x 1 x float> %24) #3
  %58 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %57, <vscale x 1 x float> %25) #3
  %59 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %58, <vscale x 1 x float> %26) #3
  %60 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %59, <vscale x 1 x float> %27) #3
  %61 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %60, <vscale x 1 x float> %28) #3
  %62 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %61, <vscale x 1 x float> %29) #3
  %63 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %62, <vscale x 1 x float> %30) #3
  %64 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %63, <vscale x 1 x float> %31) #3
  %65 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %64, <vscale x 1 x float> %32) #3
  %66 = tail call <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float> %65, <vscale x 1 x float> %33) #3
  tail call void @llvm.riscv.vse32.v.f32m1(<vscale x 1 x float> %66, float* %input) #3
  ret void
}


; Function Attrs: nounwind
declare i64 @llvm.riscv.vsetvl.i64.i64.i64(i64, i64) #3

; Function Attrs: nounwind readonly
declare <vscale x 1 x float> @llvm.riscv.vle32.v.f32m1(float*) #4

; Function Attrs: nounwind readnone
declare <vscale x 1 x float> @llvm.riscv.vfadd.vv.f32m1(<vscale x 1 x float>, <vscale x 1 x float>) #5

; Function Attrs: nounwind writeonly
declare void @llvm.riscv.vse32.v.f32m1(<vscale x 1 x float>, float*) #6