; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vfncvt_x_f_w_i16mf4(<vscale x 1 x float> %src) {
entry:
; CHECK-LABEL: vfncvt_x_f_w_i16mf4
; CHECK: vfncvt.x.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vfncvt.x.f.w.nxv1i16.nxv1f32(<vscale x 1 x float> %src)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vfncvt_x_f_w_i16mf2(<vscale x 2 x float> %src) {
entry:
; CHECK-LABEL: vfncvt_x_f_w_i16mf2
; CHECK: vfncvt.x.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vfncvt.x.f.w.nxv2i16.nxv2f32(<vscale x 2 x float> %src)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vfncvt_x_f_w_i16m1(<vscale x 4 x float> %src) {
entry:
; CHECK-LABEL: vfncvt_x_f_w_i16m1
; CHECK: vfncvt.x.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vfncvt.x.f.w.nxv4i16.nxv4f32(<vscale x 4 x float> %src)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vfncvt_x_f_w_i16m2(<vscale x 8 x float> %src) {
entry:
; CHECK-LABEL: vfncvt_x_f_w_i16m2
; CHECK: vfncvt.x.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vfncvt.x.f.w.nxv8i16.nxv8f32(<vscale x 8 x float> %src)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vfncvt_x_f_w_i16m4(<vscale x 16 x float> %src) {
entry:
; CHECK-LABEL: vfncvt_x_f_w_i16m4
; CHECK: vfncvt.x.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vfncvt.x.f.w.nxv16i16.nxv16f32(<vscale x 16 x float> %src)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vfncvt_x_f_w_i32mf2(<vscale x 1 x double> %src) {
entry:
; CHECK-LABEL: vfncvt_x_f_w_i32mf2
; CHECK: vfncvt.x.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vfncvt.x.f.w.nxv1i32.nxv1f64(<vscale x 1 x double> %src)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vfncvt_x_f_w_i32m1(<vscale x 2 x double> %src) {
entry:
; CHECK-LABEL: vfncvt_x_f_w_i32m1
; CHECK: vfncvt.x.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vfncvt.x.f.w.nxv2i32.nxv2f64(<vscale x 2 x double> %src)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vfncvt_x_f_w_i32m2(<vscale x 4 x double> %src) {
entry:
; CHECK-LABEL: vfncvt_x_f_w_i32m2
; CHECK: vfncvt.x.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vfncvt.x.f.w.nxv4i32.nxv4f64(<vscale x 4 x double> %src)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vfncvt_x_f_w_i32m4(<vscale x 8 x double> %src) {
entry:
; CHECK-LABEL: vfncvt_x_f_w_i32m4
; CHECK: vfncvt.x.f.w {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vfncvt.x.f.w.nxv8i32.nxv8f64(<vscale x 8 x double> %src)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vfncvt.x.f.w.nxv1i32.nxv1f64(<vscale x 1 x double>)
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vfncvt.x.f.w.nxv2i32.nxv2f64(<vscale x 2 x double>)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vfncvt.x.f.w.nxv8i32.nxv8f64(<vscale x 8 x double>)
; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.vfncvt.x.f.w.nxv8i16.nxv8f32(<vscale x 8 x float>)
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.vfncvt.x.f.w.nxv4i16.nxv4f32(<vscale x 4 x float>)
; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.vfncvt.x.f.w.nxv1i16.nxv1f32(<vscale x 1 x float>)
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.vfncvt.x.f.w.nxv2i16.nxv2f32(<vscale x 2 x float>)
; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.vfncvt.x.f.w.nxv16i16.nxv16f32(<vscale x 16 x float>)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vfncvt.x.f.w.nxv4i32.nxv4f64(<vscale x 4 x double>)
