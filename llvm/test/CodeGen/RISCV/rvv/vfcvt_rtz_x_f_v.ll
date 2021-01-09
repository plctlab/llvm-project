; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vfcvt_rtz_x_f_v_i16mf4(<vscale x 1 x half> %src) {
entry:
; CHECK-LABEL: vfcvt_rtz_x_f_v_i16mf4
; CHECK: vfcvt.rtz.x.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.nxv1i16.nxv1f16(<vscale x 1 x half> %src)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vfcvt_rtz_x_f_v_i16mf2(<vscale x 2 x half> %src) {
entry:
; CHECK-LABEL: vfcvt_rtz_x_f_v_i16mf2
; CHECK: vfcvt.rtz.x.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.nxv2i16.nxv2f16(<vscale x 2 x half> %src)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vfcvt_rtz_x_f_v_i16m1(<vscale x 4 x half> %src) {
entry:
; CHECK-LABEL: vfcvt_rtz_x_f_v_i16m1
; CHECK: vfcvt.rtz.x.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.nxv4i16.nxv4f16(<vscale x 4 x half> %src)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vfcvt_rtz_x_f_v_i16m2(<vscale x 8 x half> %src) {
entry:
; CHECK-LABEL: vfcvt_rtz_x_f_v_i16m2
; CHECK: vfcvt.rtz.x.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.nxv8i16.nxv8f16(<vscale x 8 x half> %src)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vfcvt_rtz_x_f_v_i16m4(<vscale x 16 x half> %src) {
entry:
; CHECK-LABEL: vfcvt_rtz_x_f_v_i16m4
; CHECK: vfcvt.rtz.x.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.nxv16i16.nxv16f16(<vscale x 16 x half> %src)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vfcvt_rtz_x_f_v_i16m8(<vscale x 32 x half> %src) {
entry:
; CHECK-LABEL: vfcvt_rtz_x_f_v_i16m8
; CHECK: vfcvt.rtz.x.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.nxv32i16.nxv32f16(<vscale x 32 x half> %src)
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vfcvt_rtz_x_f_v_i32mf2(<vscale x 1 x float> %src) {
entry:
; CHECK-LABEL: vfcvt_rtz_x_f_v_i32mf2
; CHECK: vfcvt.rtz.x.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.nxv1i32.nxv1f32(<vscale x 1 x float> %src)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vfcvt_rtz_x_f_v_i32m1(<vscale x 2 x float> %src) {
entry:
; CHECK-LABEL: vfcvt_rtz_x_f_v_i32m1
; CHECK: vfcvt.rtz.x.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.nxv2i32.nxv2f32(<vscale x 2 x float> %src)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vfcvt_rtz_x_f_v_i32m2(<vscale x 4 x float> %src) {
entry:
; CHECK-LABEL: vfcvt_rtz_x_f_v_i32m2
; CHECK: vfcvt.rtz.x.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.nxv4i32.nxv4f32(<vscale x 4 x float> %src)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vfcvt_rtz_x_f_v_i32m4(<vscale x 8 x float> %src) {
entry:
; CHECK-LABEL: vfcvt_rtz_x_f_v_i32m4
; CHECK: vfcvt.rtz.x.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.nxv8i32.nxv8f32(<vscale x 8 x float> %src)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vfcvt_rtz_x_f_v_i32m8(<vscale x 16 x float> %src) {
entry:
; CHECK-LABEL: vfcvt_rtz_x_f_v_i32m8
; CHECK: vfcvt.rtz.x.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.nxv16i32.nxv16f32(<vscale x 16 x float> %src)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vfcvt_rtz_x_f_v_i64m1(<vscale x 1 x double> %src) {
entry:
; CHECK-LABEL: vfcvt_rtz_x_f_v_i64m1
; CHECK: vfcvt.rtz.x.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.nxv1i64.nxv1f64(<vscale x 1 x double> %src)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vfcvt_rtz_x_f_v_i64m2(<vscale x 2 x double> %src) {
entry:
; CHECK-LABEL: vfcvt_rtz_x_f_v_i64m2
; CHECK: vfcvt.rtz.x.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.nxv2i64.nxv2f64(<vscale x 2 x double> %src)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vfcvt_rtz_x_f_v_i64m4(<vscale x 4 x double> %src) {
entry:
; CHECK-LABEL: vfcvt_rtz_x_f_v_i64m4
; CHECK: vfcvt.rtz.x.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.nxv4i64.nxv4f64(<vscale x 4 x double> %src)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vfcvt_rtz_x_f_v_i64m8(<vscale x 8 x double> %src) {
entry:
; CHECK-LABEL: vfcvt_rtz_x_f_v_i64m8
; CHECK: vfcvt.rtz.x.f.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.nxv8i64.nxv8f64(<vscale x 8 x double> %src)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: nounwind
declare <vscale x 4 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.nxv4i64.nxv4f64(<vscale x 4 x double>)
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.nxv2i16.nxv2f16(<vscale x 2 x half>)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.nxv8i32.nxv8f32(<vscale x 8 x float>)
; Function Attrs: nounwind
declare <vscale x 1 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.nxv1i64.nxv1f64(<vscale x 1 x double>)
; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.nxv1i16.nxv1f16(<vscale x 1 x half>)
; Function Attrs: nounwind
declare <vscale x 32 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.nxv32i16.nxv32f16(<vscale x 32 x half>)
; Function Attrs: nounwind
declare <vscale x 8 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.nxv8i64.nxv8f64(<vscale x 8 x double>)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.nxv4i32.nxv4f32(<vscale x 4 x float>)
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.nxv4i16.nxv4f16(<vscale x 4 x half>)
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.nxv2i32.nxv2f32(<vscale x 2 x float>)
; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.nxv1i32.nxv1f32(<vscale x 1 x float>)
; Function Attrs: nounwind
declare <vscale x 16 x i32> @llvm.riscv.vfcvt.rtz.x.f.v.nxv16i32.nxv16f32(<vscale x 16 x float>)
; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.nxv8i16.nxv8f16(<vscale x 8 x half>)
; Function Attrs: nounwind
declare <vscale x 2 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.nxv2i64.nxv2f64(<vscale x 2 x double>)
; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.vfcvt.rtz.x.f.v.nxv16i16.nxv16f16(<vscale x 16 x half>)
