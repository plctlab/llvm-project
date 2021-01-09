; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x float> @test_vfwcvt_f_xu_v_f32mf2(<vscale x 1 x i16> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_xu_v_f32mf2
; vsetvli zero, zero, e16,mf4,tu,mu
; CHECK: vfwcvt.f.xu.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 1 x float> @llvm.riscv.vfwcvt.f.xu.v.nxv1f32.nxv1i16(<vscale x 1 x i16> %src)
  ret <vscale x 1 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x float> @test_vfwcvt_f_xu_v_f32m1(<vscale x 2 x i16> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_xu_v_f32m1
; vsetvli zero, zero, e16,mf2,tu,mu
; CHECK: vfwcvt.f.xu.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 2 x float> @llvm.riscv.vfwcvt.f.xu.v.nxv2f32.nxv2i16(<vscale x 2 x i16> %src)
  ret <vscale x 2 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x float> @test_vfwcvt_f_xu_v_f32m2(<vscale x 4 x i16> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_xu_v_f32m2
; vsetvli zero, zero, e16,m1,tu,mu
; CHECK: vfwcvt.f.xu.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 4 x float> @llvm.riscv.vfwcvt.f.xu.v.nxv4f32.nxv4i16(<vscale x 4 x i16> %src)
  ret <vscale x 4 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x float> @test_vfwcvt_f_xu_v_f32m4(<vscale x 8 x i16> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_xu_v_f32m4
; vsetvli zero, zero, e16,m2,tu,mu
; CHECK: vfwcvt.f.xu.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 8 x float> @llvm.riscv.vfwcvt.f.xu.v.nxv8f32.nxv8i16(<vscale x 8 x i16> %src)
  ret <vscale x 8 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x float> @test_vfwcvt_f_xu_v_f32m8(<vscale x 16 x i16> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_xu_v_f32m8
; vsetvli zero, zero, e16,m4,tu,mu
; CHECK: vfwcvt.f.xu.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 16 x float> @llvm.riscv.vfwcvt.f.xu.v.nxv16f32.nxv16i16(<vscale x 16 x i16> %src)
  ret <vscale x 16 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x double> @test_vfwcvt_f_xu_v_f64m1(<vscale x 1 x i32> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_xu_v_f64m1
; vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vfwcvt.f.xu.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 1 x double> @llvm.riscv.vfwcvt.f.xu.v.nxv1f64.nxv1i32(<vscale x 1 x i32> %src)
  ret <vscale x 1 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x double> @test_vfwcvt_f_xu_v_f64m2(<vscale x 2 x i32> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_xu_v_f64m2
; vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vfwcvt.f.xu.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 2 x double> @llvm.riscv.vfwcvt.f.xu.v.nxv2f64.nxv2i32(<vscale x 2 x i32> %src)
  ret <vscale x 2 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x double> @test_vfwcvt_f_xu_v_f64m4(<vscale x 4 x i32> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_xu_v_f64m4
; vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vfwcvt.f.xu.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 4 x double> @llvm.riscv.vfwcvt.f.xu.v.nxv4f64.nxv4i32(<vscale x 4 x i32> %src)
  ret <vscale x 4 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x double> @test_vfwcvt_f_xu_v_f64m8(<vscale x 8 x i32> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_xu_v_f64m8
; vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vfwcvt.f.xu.v {{v[0-9]+}}, {{v[0-9]+}}
  %call = tail call <vscale x 8 x double> @llvm.riscv.vfwcvt.f.xu.v.nxv8f64.nxv8i32(<vscale x 8 x i32> %src)
  ret <vscale x 8 x double> %call
}

; Function Attrs: nounwind
declare <vscale x 4 x float> @llvm.riscv.vfwcvt.f.xu.v.nxv4f32.nxv4i16(<vscale x 4 x i16>)
; Function Attrs: nounwind
declare <vscale x 2 x float> @llvm.riscv.vfwcvt.f.xu.v.nxv2f32.nxv2i16(<vscale x 2 x i16>)
; Function Attrs: nounwind
declare <vscale x 1 x double> @llvm.riscv.vfwcvt.f.xu.v.nxv1f64.nxv1i32(<vscale x 1 x i32>)
; Function Attrs: nounwind
declare <vscale x 8 x double> @llvm.riscv.vfwcvt.f.xu.v.nxv8f64.nxv8i32(<vscale x 8 x i32>)
; Function Attrs: nounwind
declare <vscale x 2 x double> @llvm.riscv.vfwcvt.f.xu.v.nxv2f64.nxv2i32(<vscale x 2 x i32>)
; Function Attrs: nounwind
declare <vscale x 1 x float> @llvm.riscv.vfwcvt.f.xu.v.nxv1f32.nxv1i16(<vscale x 1 x i16>)
; Function Attrs: nounwind
declare <vscale x 4 x double> @llvm.riscv.vfwcvt.f.xu.v.nxv4f64.nxv4i32(<vscale x 4 x i32>)
; Function Attrs: nounwind
declare <vscale x 16 x float> @llvm.riscv.vfwcvt.f.xu.v.nxv16f32.nxv16i16(<vscale x 16 x i16>)
; Function Attrs: nounwind
declare <vscale x 8 x float> @llvm.riscv.vfwcvt.f.xu.v.nxv8f32.nxv8i16(<vscale x 8 x i16>)
