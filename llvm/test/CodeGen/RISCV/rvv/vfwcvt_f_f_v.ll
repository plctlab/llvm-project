; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x float> @test_vfwcvt_f_f_v_f32mf2(<vscale x 1 x half> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_f_v_f32mf2
; CHECK: vfwcvt.f.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x float> @llvm.riscv.vfwcvt.f.f.v.nxv1f32.nxv1f16(<vscale x 1 x half> %src)
  ret <vscale x 1 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x float> @test_vfwcvt_f_f_v_f32m1(<vscale x 2 x half> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_f_v_f32m1
; CHECK: vfwcvt.f.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x float> @llvm.riscv.vfwcvt.f.f.v.nxv2f32.nxv2f16(<vscale x 2 x half> %src)
  ret <vscale x 2 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x float> @test_vfwcvt_f_f_v_f32m2(<vscale x 4 x half> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_f_v_f32m2
; CHECK: vfwcvt.f.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x float> @llvm.riscv.vfwcvt.f.f.v.nxv4f32.nxv4f16(<vscale x 4 x half> %src)
  ret <vscale x 4 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x float> @test_vfwcvt_f_f_v_f32m4(<vscale x 8 x half> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_f_v_f32m4
; CHECK: vfwcvt.f.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x float> @llvm.riscv.vfwcvt.f.f.v.nxv8f32.nxv8f16(<vscale x 8 x half> %src)
  ret <vscale x 8 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x float> @test_vfwcvt_f_f_v_f32m8(<vscale x 16 x half> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_f_v_f32m8
; CHECK: vfwcvt.f.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x float> @llvm.riscv.vfwcvt.f.f.v.nxv16f32.nxv16f16(<vscale x 16 x half> %src)
  ret <vscale x 16 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x double> @test_vfwcvt_f_f_v_f64m1(<vscale x 1 x float> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_f_v_f64m1
; CHECK: vfwcvt.f.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x double> @llvm.riscv.vfwcvt.f.f.v.nxv1f64.nxv1f32(<vscale x 1 x float> %src)
  ret <vscale x 1 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x double> @test_vfwcvt_f_f_v_f64m2(<vscale x 2 x float> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_f_v_f64m2
; CHECK: vfwcvt.f.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x double> @llvm.riscv.vfwcvt.f.f.v.nxv2f64.nxv2f32(<vscale x 2 x float> %src)
  ret <vscale x 2 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x double> @test_vfwcvt_f_f_v_f64m4(<vscale x 4 x float> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_f_v_f64m4
; CHECK: vfwcvt.f.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x double> @llvm.riscv.vfwcvt.f.f.v.nxv4f64.nxv4f32(<vscale x 4 x float> %src)
  ret <vscale x 4 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x double> @test_vfwcvt_f_f_v_f64m8(<vscale x 8 x float> %src) {
entry:
; CHECK-LABEL: vfwcvt_f_f_v_f64m8
; CHECK: vfwcvt.f.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x double> @llvm.riscv.vfwcvt.f.f.v.nxv8f64.nxv8f32(<vscale x 8 x float> %src)
  ret <vscale x 8 x double> %call
}

; Function Attrs: nounwind
declare <vscale x 16 x float> @llvm.riscv.vfwcvt.f.f.v.nxv16f32.nxv16f16(<vscale x 16 x half>)
; Function Attrs: nounwind
declare <vscale x 2 x double> @llvm.riscv.vfwcvt.f.f.v.nxv2f64.nxv2f32(<vscale x 2 x float>)
; Function Attrs: nounwind
declare <vscale x 1 x double> @llvm.riscv.vfwcvt.f.f.v.nxv1f64.nxv1f32(<vscale x 1 x float>)
; Function Attrs: nounwind
declare <vscale x 2 x float> @llvm.riscv.vfwcvt.f.f.v.nxv2f32.nxv2f16(<vscale x 2 x half>)
; Function Attrs: nounwind
declare <vscale x 4 x double> @llvm.riscv.vfwcvt.f.f.v.nxv4f64.nxv4f32(<vscale x 4 x float>)
; Function Attrs: nounwind
declare <vscale x 8 x float> @llvm.riscv.vfwcvt.f.f.v.nxv8f32.nxv8f16(<vscale x 8 x half>)
; Function Attrs: nounwind
declare <vscale x 1 x float> @llvm.riscv.vfwcvt.f.f.v.nxv1f32.nxv1f16(<vscale x 1 x half>)
; Function Attrs: nounwind
declare <vscale x 4 x float> @llvm.riscv.vfwcvt.f.f.v.nxv4f32.nxv4f16(<vscale x 4 x half>)
; Function Attrs: nounwind
declare <vscale x 8 x double> @llvm.riscv.vfwcvt.f.f.v.nxv8f64.nxv8f32(<vscale x 8 x float>)
