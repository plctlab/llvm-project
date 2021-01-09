; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vfwcvt_rtz_xu_f_v_u32mf2(<vscale x 1 x half> %src) {
entry:
; CHECK-LABEL: vfwcvt_rtz_xu_f_v_u32mf2
; vsetvli zero, zero, e16,mf4,tu,mu
; CHECK: vfwcvt.rtz.xu.f.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv1i32.nxv1f16(<vscale x 1 x half> %src)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vfwcvt_rtz_xu_f_v_u32m1(<vscale x 2 x half> %src) {
entry:
; CHECK-LABEL: vfwcvt_rtz_xu_f_v_u32m1
; vsetvli zero, zero, e16,mf2,tu,mu
; CHECK: vfwcvt.rtz.xu.f.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv2i32.nxv2f16(<vscale x 2 x half> %src)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vfwcvt_rtz_xu_f_v_u32m2(<vscale x 4 x half> %src) {
entry:
; CHECK-LABEL: vfwcvt_rtz_xu_f_v_u32m2
; vsetvli zero, zero, e16,m1,tu,mu
; CHECK: vfwcvt.rtz.xu.f.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv4i32.nxv4f16(<vscale x 4 x half> %src)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vfwcvt_rtz_xu_f_v_u32m4(<vscale x 8 x half> %src) {
entry:
; CHECK-LABEL: vfwcvt_rtz_xu_f_v_u32m4
; vsetvli zero, zero, e16,m2,tu,mu
; CHECK: vfwcvt.rtz.xu.f.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv8i32.nxv8f16(<vscale x 8 x half> %src)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vfwcvt_rtz_xu_f_v_u32m8(<vscale x 16 x half> %src) {
entry:
; CHECK-LABEL: vfwcvt_rtz_xu_f_v_u32m8
; vsetvli zero, zero, e16,m4,tu,mu
; CHECK: vfwcvt.rtz.xu.f.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv16i32.nxv16f16(<vscale x 16 x half> %src)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vfwcvt_rtz_xu_f_v_u64m1(<vscale x 1 x float> %src) {
entry:
; CHECK-LABEL: vfwcvt_rtz_xu_f_v_u64m1
; vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vfwcvt.rtz.xu.f.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv1i64.nxv1f32(<vscale x 1 x float> %src)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vfwcvt_rtz_xu_f_v_u64m2(<vscale x 2 x float> %src) {
entry:
; CHECK-LABEL: vfwcvt_rtz_xu_f_v_u64m2
; vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vfwcvt.rtz.xu.f.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv2i64.nxv2f32(<vscale x 2 x float> %src)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vfwcvt_rtz_xu_f_v_u64m4(<vscale x 4 x float> %src) {
entry:
; CHECK-LABEL: vfwcvt_rtz_xu_f_v_u64m4
; vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vfwcvt.rtz.xu.f.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv4i64.nxv4f32(<vscale x 4 x float> %src)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vfwcvt_rtz_xu_f_v_u64m8(<vscale x 8 x float> %src) {
entry:
; CHECK-LABEL: vfwcvt_rtz_xu_f_v_u64m8
; vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vfwcvt.rtz.xu.f.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv8i64.nxv8f32(<vscale x 8 x float> %src)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: nounwind
declare <vscale x 16 x i32> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv16i32.nxv16f16(<vscale x 16 x half>)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv8i32.nxv8f16(<vscale x 8 x half>)
; Function Attrs: nounwind
declare <vscale x 8 x i64> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv8i64.nxv8f32(<vscale x 8 x float>)
; Function Attrs: nounwind
declare <vscale x 1 x i64> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv1i64.nxv1f32(<vscale x 1 x float>)
; Function Attrs: nounwind
declare <vscale x 2 x i64> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv2i64.nxv2f32(<vscale x 2 x float>)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv4i32.nxv4f16(<vscale x 4 x half>)
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv2i32.nxv2f16(<vscale x 2 x half>)
; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv1i32.nxv1f16(<vscale x 1 x half>)
; Function Attrs: nounwind
declare <vscale x 4 x i64> @llvm.riscv.vfwcvt.rtz.xu.f.v.nxv4i64.nxv4f32(<vscale x 4 x float>)
