; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x half> @test_vfncvt_rod_f_f_w_f16mf4(<vscale x 1 x float> %src) {
entry:
; CHECK-LABEL: vfncvt_rod_f_f_w_f16mf4
; CHECK: vfncvt.rod.f.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x half> @llvm.riscv.vfncvt.rod.f.f.w.nxv1f16.nxv1f32(<vscale x 1 x float> %src)
  ret <vscale x 1 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x half> @test_vfncvt_rod_f_f_w_f16mf2(<vscale x 2 x float> %src) {
entry:
; CHECK-LABEL: vfncvt_rod_f_f_w_f16mf2
; CHECK: vfncvt.rod.f.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x half> @llvm.riscv.vfncvt.rod.f.f.w.nxv2f16.nxv2f32(<vscale x 2 x float> %src)
  ret <vscale x 2 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x half> @test_vfncvt_rod_f_f_w_f16m1(<vscale x 4 x float> %src) {
entry:
; CHECK-LABEL: vfncvt_rod_f_f_w_f16m1
; CHECK: vfncvt.rod.f.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x half> @llvm.riscv.vfncvt.rod.f.f.w.nxv4f16.nxv4f32(<vscale x 4 x float> %src)
  ret <vscale x 4 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x half> @test_vfncvt_rod_f_f_w_f16m2(<vscale x 8 x float> %src) {
entry:
; CHECK-LABEL: vfncvt_rod_f_f_w_f16m2
; CHECK: vfncvt.rod.f.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x half> @llvm.riscv.vfncvt.rod.f.f.w.nxv8f16.nxv8f32(<vscale x 8 x float> %src)
  ret <vscale x 8 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x half> @test_vfncvt_rod_f_f_w_f16m4(<vscale x 16 x float> %src) {
entry:
; CHECK-LABEL: vfncvt_rod_f_f_w_f16m4
; CHECK: vfncvt.rod.f.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x half> @llvm.riscv.vfncvt.rod.f.f.w.nxv16f16.nxv16f32(<vscale x 16 x float> %src)
  ret <vscale x 16 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x float> @test_vfncvt_rod_f_f_w_f32mf2(<vscale x 1 x double> %src) {
entry:
; CHECK-LABEL: vfncvt_rod_f_f_w_f32mf2
; CHECK: vfncvt.rod.f.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x float> @llvm.riscv.vfncvt.rod.f.f.w.nxv1f32.nxv1f64(<vscale x 1 x double> %src)
  ret <vscale x 1 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x float> @test_vfncvt_rod_f_f_w_f32m1(<vscale x 2 x double> %src) {
entry:
; CHECK-LABEL: vfncvt_rod_f_f_w_f32m1
; CHECK: vfncvt.rod.f.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x float> @llvm.riscv.vfncvt.rod.f.f.w.nxv2f32.nxv2f64(<vscale x 2 x double> %src)
  ret <vscale x 2 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x float> @test_vfncvt_rod_f_f_w_f32m2(<vscale x 4 x double> %src) {
entry:
; CHECK-LABEL: vfncvt_rod_f_f_w_f32m2
; CHECK: vfncvt.rod.f.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x float> @llvm.riscv.vfncvt.rod.f.f.w.nxv4f32.nxv4f64(<vscale x 4 x double> %src)
  ret <vscale x 4 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x float> @test_vfncvt_rod_f_f_w_f32m4(<vscale x 8 x double> %src) {
entry:
; CHECK-LABEL: vfncvt_rod_f_f_w_f32m4
; CHECK: vfncvt.rod.f.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x float> @llvm.riscv.vfncvt.rod.f.f.w.nxv8f32.nxv8f64(<vscale x 8 x double> %src)
  ret <vscale x 8 x float> %call
}

; Function Attrs: nounwind
declare <vscale x 4 x float> @llvm.riscv.vfncvt.rod.f.f.w.nxv4f32.nxv4f64(<vscale x 4 x double>)
; Function Attrs: nounwind
declare <vscale x 1 x half> @llvm.riscv.vfncvt.rod.f.f.w.nxv1f16.nxv1f32(<vscale x 1 x float>)
; Function Attrs: nounwind
declare <vscale x 2 x float> @llvm.riscv.vfncvt.rod.f.f.w.nxv2f32.nxv2f64(<vscale x 2 x double>)
; Function Attrs: nounwind
declare <vscale x 8 x half> @llvm.riscv.vfncvt.rod.f.f.w.nxv8f16.nxv8f32(<vscale x 8 x float>)
; Function Attrs: nounwind
declare <vscale x 16 x half> @llvm.riscv.vfncvt.rod.f.f.w.nxv16f16.nxv16f32(<vscale x 16 x float>)
; Function Attrs: nounwind
declare <vscale x 1 x float> @llvm.riscv.vfncvt.rod.f.f.w.nxv1f32.nxv1f64(<vscale x 1 x double>)
; Function Attrs: nounwind
declare <vscale x 4 x half> @llvm.riscv.vfncvt.rod.f.f.w.nxv4f16.nxv4f32(<vscale x 4 x float>)
; Function Attrs: nounwind
declare <vscale x 8 x float> @llvm.riscv.vfncvt.rod.f.f.w.nxv8f32.nxv8f64(<vscale x 8 x double>)
; Function Attrs: nounwind
declare <vscale x 2 x half> @llvm.riscv.vfncvt.rod.f.f.w.nxv2f16.nxv2f32(<vscale x 2 x float>)
