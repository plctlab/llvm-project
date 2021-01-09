; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x half> @test_vfcvt_f_x_v_f16mf4(<vscale x 1 x i16> %src) {
entry:
; CHECK-LABEL: vfcvt_f_x_v_f16mf4
; CHECK: vsetvli zero, zero, e16,mf4,tu,mu
; CHECK: vfcvt.f.x.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x half> @llvm.riscv.vfcvt.f.x.v.nxv1f16.nxv1i16(<vscale x 1 x i16> %src)
  ret <vscale x 1 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x half> @test_vfcvt_f_x_v_f16mf2(<vscale x 2 x i16> %src) {
entry:
; CHECK-LABEL: vfcvt_f_x_v_f16mf2
; CHECK: vsetvli zero, zero, e16,mf2,tu,mu
; CHECK: vfcvt.f.x.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x half> @llvm.riscv.vfcvt.f.x.v.nxv2f16.nxv2i16(<vscale x 2 x i16> %src)
  ret <vscale x 2 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x half> @test_vfcvt_f_x_v_f16m1(<vscale x 4 x i16> %src) {
entry:
; CHECK-LABEL: vfcvt_f_x_v_f16m1
; CHECK: vsetvli zero, zero, e16,m1,tu,mu
; CHECK: vfcvt.f.x.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x half> @llvm.riscv.vfcvt.f.x.v.nxv4f16.nxv4i16(<vscale x 4 x i16> %src)
  ret <vscale x 4 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x half> @test_vfcvt_f_x_v_f16m2(<vscale x 8 x i16> %src) {
entry:
; CHECK-LABEL: vfcvt_f_x_v_f16m2
; CHECK: vsetvli zero, zero, e16,m2,tu,mu
; CHECK: vfcvt.f.x.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x half> @llvm.riscv.vfcvt.f.x.v.nxv8f16.nxv8i16(<vscale x 8 x i16> %src)
  ret <vscale x 8 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x half> @test_vfcvt_f_x_v_f16m4(<vscale x 16 x i16> %src) {
entry:
; CHECK-LABEL: vfcvt_f_x_v_f16m4
; CHECK: vsetvli zero, zero, e16,m4,tu,mu
; CHECK: vfcvt.f.x.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x half> @llvm.riscv.vfcvt.f.x.v.nxv16f16.nxv16i16(<vscale x 16 x i16> %src)
  ret <vscale x 16 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x half> @test_vfcvt_f_x_v_f16m8(<vscale x 32 x i16> %src) {
entry:
; CHECK-LABEL: vfcvt_f_x_v_f16m8
; CHECK: vsetvli zero, zero, e16,m8,tu,mu
; CHECK: vfcvt.f.x.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x half> @llvm.riscv.vfcvt.f.x.v.nxv32f16.nxv32i16(<vscale x 32 x i16> %src)
  ret <vscale x 32 x half> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x float> @test_vfcvt_f_x_v_f32mf2(<vscale x 1 x i32> %src) {
entry:
; CHECK-LABEL: vfcvt_f_x_v_f32mf2
; CHECK: vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vfcvt.f.x.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x float> @llvm.riscv.vfcvt.f.x.v.nxv1f32.nxv1i32(<vscale x 1 x i32> %src)
  ret <vscale x 1 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x float> @test_vfcvt_f_x_v_f32m1(<vscale x 2 x i32> %src) {
entry:
; CHECK-LABEL: vfcvt_f_x_v_f32m1
; CHECK: vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vfcvt.f.x.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x float> @llvm.riscv.vfcvt.f.x.v.nxv2f32.nxv2i32(<vscale x 2 x i32> %src)
  ret <vscale x 2 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x float> @test_vfcvt_f_x_v_f32m2(<vscale x 4 x i32> %src) {
entry:
; CHECK-LABEL: vfcvt_f_x_v_f32m2
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vfcvt.f.x.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x float> @llvm.riscv.vfcvt.f.x.v.nxv4f32.nxv4i32(<vscale x 4 x i32> %src)
  ret <vscale x 4 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x float> @test_vfcvt_f_x_v_f32m4(<vscale x 8 x i32> %src) {
entry:
; CHECK-LABEL: vfcvt_f_x_v_f32m4
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vfcvt.f.x.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x float> @llvm.riscv.vfcvt.f.x.v.nxv8f32.nxv8i32(<vscale x 8 x i32> %src)
  ret <vscale x 8 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x float> @test_vfcvt_f_x_v_f32m8(<vscale x 16 x i32> %src) {
entry:
; CHECK-LABEL: vfcvt_f_x_v_f32m8
; CHECK: vsetvli zero, zero, e32,m8,tu,mu
; CHECK: vfcvt.f.x.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x float> @llvm.riscv.vfcvt.f.x.v.nxv16f32.nxv16i32(<vscale x 16 x i32> %src)
  ret <vscale x 16 x float> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x double> @test_vfcvt_f_x_v_f64m1(<vscale x 1 x i64> %src) {
entry:
; CHECK-LABEL: vfcvt_f_x_v_f64m1
; CHECK: vsetvli zero, zero, e64,m1,tu,mu
; CHECK: vfcvt.f.x.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x double> @llvm.riscv.vfcvt.f.x.v.nxv1f64.nxv1i64(<vscale x 1 x i64> %src)
  ret <vscale x 1 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x double> @test_vfcvt_f_x_v_f64m2(<vscale x 2 x i64> %src) {
entry:
; CHECK-LABEL: vfcvt_f_x_v_f64m2
; CHECK: vsetvli zero, zero, e64,m2,tu,mu
; CHECK: vfcvt.f.x.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x double> @llvm.riscv.vfcvt.f.x.v.nxv2f64.nxv2i64(<vscale x 2 x i64> %src)
  ret <vscale x 2 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x double> @test_vfcvt_f_x_v_f64m4(<vscale x 4 x i64> %src) {
entry:
; CHECK-LABEL: vfcvt_f_x_v_f64m4
; CHECK: vsetvli zero, zero, e64,m4,tu,mu
; CHECK: vfcvt.f.x.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x double> @llvm.riscv.vfcvt.f.x.v.nxv4f64.nxv4i64(<vscale x 4 x i64> %src)
  ret <vscale x 4 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x double> @test_vfcvt_f_x_v_f64m8(<vscale x 8 x i64> %src) {
entry:
; CHECK-LABEL: vfcvt_f_x_v_f64m8
; CHECK: vsetvli zero, zero, e64,m8,tu,mu
; CHECK: vfcvt.f.x.v {{v[0-9]+}}, {{v[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x double> @llvm.riscv.vfcvt.f.x.v.nxv8f64.nxv8i64(<vscale x 8 x i64> %src)
  ret <vscale x 8 x double> %call
}

; Function Attrs: nounwind
declare <vscale x 4 x float> @llvm.riscv.vfcvt.f.x.v.nxv4f32.nxv4i32(<vscale x 4 x i32>)
; Function Attrs: nounwind
declare <vscale x 1 x double> @llvm.riscv.vfcvt.f.x.v.nxv1f64.nxv1i64(<vscale x 1 x i64>)
; Function Attrs: nounwind
declare <vscale x 1 x float> @llvm.riscv.vfcvt.f.x.v.nxv1f32.nxv1i32(<vscale x 1 x i32>)
; Function Attrs: nounwind
declare <vscale x 8 x half> @llvm.riscv.vfcvt.f.x.v.nxv8f16.nxv8i16(<vscale x 8 x i16>)
; Function Attrs: nounwind
declare <vscale x 32 x half> @llvm.riscv.vfcvt.f.x.v.nxv32f16.nxv32i16(<vscale x 32 x i16>)
; Function Attrs: nounwind
declare <vscale x 8 x double> @llvm.riscv.vfcvt.f.x.v.nxv8f64.nxv8i64(<vscale x 8 x i64>)
; Function Attrs: nounwind
declare <vscale x 1 x half> @llvm.riscv.vfcvt.f.x.v.nxv1f16.nxv1i16(<vscale x 1 x i16>)
; Function Attrs: nounwind
declare <vscale x 16 x half> @llvm.riscv.vfcvt.f.x.v.nxv16f16.nxv16i16(<vscale x 16 x i16>)
; Function Attrs: nounwind
declare <vscale x 2 x float> @llvm.riscv.vfcvt.f.x.v.nxv2f32.nxv2i32(<vscale x 2 x i32>)
; Function Attrs: nounwind
declare <vscale x 4 x double> @llvm.riscv.vfcvt.f.x.v.nxv4f64.nxv4i64(<vscale x 4 x i64>)
; Function Attrs: nounwind
declare <vscale x 2 x double> @llvm.riscv.vfcvt.f.x.v.nxv2f64.nxv2i64(<vscale x 2 x i64>)
; Function Attrs: nounwind
declare <vscale x 16 x float> @llvm.riscv.vfcvt.f.x.v.nxv16f32.nxv16i32(<vscale x 16 x i32>)
; Function Attrs: nounwind
declare <vscale x 2 x half> @llvm.riscv.vfcvt.f.x.v.nxv2f16.nxv2i16(<vscale x 2 x i16>)
; Function Attrs: nounwind
declare <vscale x 4 x half> @llvm.riscv.vfcvt.f.x.v.nxv4f16.nxv4i16(<vscale x 4 x i16>)
; Function Attrs: nounwind
declare <vscale x 8 x float> @llvm.riscv.vfcvt.f.x.v.nxv8f32.nxv8i32(<vscale x 8 x i32>)
