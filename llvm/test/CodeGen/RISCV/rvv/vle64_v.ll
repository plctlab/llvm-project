; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vle64_v_i64m1(i64* %base) {
entry:
; CHECK-LABEL: vle64_v_i64m1
; CHECK: vsetvli zero, zero, e64,m1,tu,mu
; CHECK: vle64.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vload.nxv1i64.p0i64(i64* %base)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vle64_v_i64m2(i64* %base) {
entry:
; CHECK-LABEL: vle64_v_i64m2
; CHECK: vsetvli zero, zero, e64,m2,tu,mu
; CHECK: vle64.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vload.nxv2i64.p0i64(i64* %base)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vle64_v_i64m4(i64* %base) {
entry:
; CHECK-LABEL: vle64_v_i64m4
; CHECK: vsetvli zero, zero, e64,m4,tu,mu
; CHECK: vle64.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vload.nxv4i64.p0i64(i64* %base)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vle64_v_i64m8(i64* %base) {
entry:
; CHECK-LABEL: vle64_v_i64m8
; CHECK: vsetvli zero, zero, e64,m8,tu,mu
; CHECK: vle64.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vload.nxv8i64.p0i64(i64* %base)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vle64_v_u64m1(i64* %base) {
entry:
; CHECK-LABEL: vle64_v_u64m1
; CHECK: vsetvli zero, zero, e64,m1,tu,mu
; CHECK: vle64.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vload.nxv1i64.p0i64(i64* %base)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vle64_v_u64m2(i64* %base) {
entry:
; CHECK-LABEL: vle64_v_u64m2
; CHECK: vsetvli zero, zero, e64,m2,tu,mu
; CHECK: vle64.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vload.nxv2i64.p0i64(i64* %base)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vle64_v_u64m4(i64* %base) {
entry:
; CHECK-LABEL: vle64_v_u64m4
; CHECK: vsetvli zero, zero, e64,m4,tu,mu
; CHECK: vle64.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vload.nxv4i64.p0i64(i64* %base)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vle64_v_u64m8(i64* %base) {
entry:
; CHECK-LABEL: vle64_v_u64m8
; CHECK: vsetvli zero, zero, e64,m8,tu,mu
; CHECK: vle64.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vload.nxv8i64.p0i64(i64* %base)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x double> @test_vle64_v_f64m1(double* %base) {
entry:
; CHECK-LABEL: vle64_v_f64m1
; CHECK: vsetvli zero, zero, e64,m1,tu,mu
; CHECK: vle64.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 1 x double> @llvm.riscv.vload.nxv1f64.p0f64(double* %base)
  ret <vscale x 1 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x double> @test_vle64_v_f64m2(double* %base) {
entry:
; CHECK-LABEL: vle64_v_f64m2
; CHECK: vsetvli zero, zero, e64,m2,tu,mu
; CHECK: vle64.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 2 x double> @llvm.riscv.vload.nxv2f64.p0f64(double* %base)
  ret <vscale x 2 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x double> @test_vle64_v_f64m4(double* %base) {
entry:
; CHECK-LABEL: vle64_v_f64m4
; CHECK: vsetvli zero, zero, e64,m4,tu,mu
; CHECK: vle64.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 4 x double> @llvm.riscv.vload.nxv4f64.p0f64(double* %base)
  ret <vscale x 4 x double> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x double> @test_vle64_v_f64m8(double* %base) {
entry:
; CHECK-LABEL: vle64_v_f64m8
; CHECK: vsetvli zero, zero, e64,m8,tu,mu
; CHECK: vle64.v {{v[0-9]+}}, ({{a[0-9]+}})
  %call = tail call <vscale x 8 x double> @llvm.riscv.vload.nxv8f64.p0f64(double* %base)
  ret <vscale x 8 x double> %call
}

; Function Attrs: nounwind
declare <vscale x 4 x i64> @llvm.riscv.vload.nxv4i64.p0i64(i64*)
; Function Attrs: nounwind
declare <vscale x 2 x double> @llvm.riscv.vload.nxv2f64.p0f64(double*)
; Function Attrs: nounwind
declare <vscale x 2 x i64> @llvm.riscv.vload.nxv2i64.p0i64(i64*)
; Function Attrs: nounwind
declare <vscale x 8 x i64> @llvm.riscv.vload.nxv8i64.p0i64(i64*)
; Function Attrs: nounwind
declare <vscale x 4 x double> @llvm.riscv.vload.nxv4f64.p0f64(double*)
; Function Attrs: nounwind
declare <vscale x 1 x double> @llvm.riscv.vload.nxv1f64.p0f64(double*)
; Function Attrs: nounwind
declare <vscale x 1 x i64> @llvm.riscv.vload.nxv1i64.p0i64(i64*)
; Function Attrs: nounwind
declare <vscale x 8 x double> @llvm.riscv.vload.nxv8f64.p0f64(double*)
