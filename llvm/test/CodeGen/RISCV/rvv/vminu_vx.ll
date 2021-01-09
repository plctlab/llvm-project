; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_vminu_vx_u8mf8(<vscale x 1 x i8> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u8mf8
; CHECK: vsetvli zero, zero, e8,mf8,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i8> @llvm.riscv.vminu.vx.nxv1i8.i8(<vscale x 1 x i8> %op1, i8 %op2)
  ret <vscale x 1 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_vminu_vx_u8mf4(<vscale x 2 x i8> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u8mf4
; CHECK: vsetvli zero, zero, e8,mf4,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i8> @llvm.riscv.vminu.vx.nxv2i8.i8(<vscale x 2 x i8> %op1, i8 %op2)
  ret <vscale x 2 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_vminu_vx_u8mf2(<vscale x 4 x i8> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u8mf2
; CHECK: vsetvli zero, zero, e8,mf2,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i8> @llvm.riscv.vminu.vx.nxv4i8.i8(<vscale x 4 x i8> %op1, i8 %op2)
  ret <vscale x 4 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_vminu_vx_u8m1(<vscale x 8 x i8> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u8m1
; CHECK: vsetvli zero, zero, e8,m1,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i8> @llvm.riscv.vminu.vx.nxv8i8.i8(<vscale x 8 x i8> %op1, i8 %op2)
  ret <vscale x 8 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_vminu_vx_u8m2(<vscale x 16 x i8> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u8m2
; CHECK: vsetvli zero, zero, e8,m2,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i8> @llvm.riscv.vminu.vx.nxv16i8.i8(<vscale x 16 x i8> %op1, i8 %op2)
  ret <vscale x 16 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_vminu_vx_u8m4(<vscale x 32 x i8> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u8m4
; CHECK: vsetvli zero, zero, e8,m4,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i8> @llvm.riscv.vminu.vx.nxv32i8.i8(<vscale x 32 x i8> %op1, i8 %op2)
  ret <vscale x 32 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i8> @test_vminu_vx_u8m8(<vscale x 64 x i8> %op1, i8 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u8m8
; CHECK: vsetvli zero, zero, e8,m8,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 64 x i8> @llvm.riscv.vminu.vx.nxv64i8.i8(<vscale x 64 x i8> %op1, i8 %op2)
  ret <vscale x 64 x i8> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vminu_vx_u16mf4(<vscale x 1 x i16> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u16mf4
; CHECK: vsetvli zero, zero, e16,mf4,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i16> @llvm.riscv.vminu.vx.nxv1i16.i16(<vscale x 1 x i16> %op1, i16 %op2)
  ret <vscale x 1 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vminu_vx_u16mf2(<vscale x 2 x i16> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u16mf2
; CHECK: vsetvli zero, zero, e16,mf2,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i16> @llvm.riscv.vminu.vx.nxv2i16.i16(<vscale x 2 x i16> %op1, i16 %op2)
  ret <vscale x 2 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vminu_vx_u16m1(<vscale x 4 x i16> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u16m1
; CHECK: vsetvli zero, zero, e16,m1,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i16> @llvm.riscv.vminu.vx.nxv4i16.i16(<vscale x 4 x i16> %op1, i16 %op2)
  ret <vscale x 4 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vminu_vx_u16m2(<vscale x 8 x i16> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u16m2
; CHECK: vsetvli zero, zero, e16,m2,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i16> @llvm.riscv.vminu.vx.nxv8i16.i16(<vscale x 8 x i16> %op1, i16 %op2)
  ret <vscale x 8 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vminu_vx_u16m4(<vscale x 16 x i16> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u16m4
; CHECK: vsetvli zero, zero, e16,m4,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i16> @llvm.riscv.vminu.vx.nxv16i16.i16(<vscale x 16 x i16> %op1, i16 %op2)
  ret <vscale x 16 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vminu_vx_u16m8(<vscale x 32 x i16> %op1, i16 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u16m8
; CHECK: vsetvli zero, zero, e16,m8,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 32 x i16> @llvm.riscv.vminu.vx.nxv32i16.i16(<vscale x 32 x i16> %op1, i16 %op2)
  ret <vscale x 32 x i16> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vminu_vx_u32mf2(<vscale x 1 x i32> %op1, i32 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u32mf2
; CHECK: vsetvli zero, zero, e32,mf2,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i32> @llvm.riscv.vminu.vx.nxv1i32.i32(<vscale x 1 x i32> %op1, i32 %op2)
  ret <vscale x 1 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vminu_vx_u32m1(<vscale x 2 x i32> %op1, i32 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u32m1
; CHECK: vsetvli zero, zero, e32,m1,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i32> @llvm.riscv.vminu.vx.nxv2i32.i32(<vscale x 2 x i32> %op1, i32 %op2)
  ret <vscale x 2 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vminu_vx_u32m2(<vscale x 4 x i32> %op1, i32 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u32m2
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i32> @llvm.riscv.vminu.vx.nxv4i32.i32(<vscale x 4 x i32> %op1, i32 %op2)
  ret <vscale x 4 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vminu_vx_u32m4(<vscale x 8 x i32> %op1, i32 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u32m4
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i32> @llvm.riscv.vminu.vx.nxv8i32.i32(<vscale x 8 x i32> %op1, i32 %op2)
  ret <vscale x 8 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vminu_vx_u32m8(<vscale x 16 x i32> %op1, i32 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u32m8
; CHECK: vsetvli zero, zero, e32,m8,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 16 x i32> @llvm.riscv.vminu.vx.nxv16i32.i32(<vscale x 16 x i32> %op1, i32 %op2)
  ret <vscale x 16 x i32> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vminu_vx_u64m1(<vscale x 1 x i64> %op1, i64 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u64m1
; CHECK: vsetvli zero, zero, e64,m1,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 1 x i64> @llvm.riscv.vminu.vx.nxv1i64.i64(<vscale x 1 x i64> %op1, i64 %op2)
  ret <vscale x 1 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vminu_vx_u64m2(<vscale x 2 x i64> %op1, i64 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u64m2
; CHECK: vsetvli zero, zero, e64,m2,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 2 x i64> @llvm.riscv.vminu.vx.nxv2i64.i64(<vscale x 2 x i64> %op1, i64 %op2)
  ret <vscale x 2 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vminu_vx_u64m4(<vscale x 4 x i64> %op1, i64 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u64m4
; CHECK: vsetvli zero, zero, e64,m4,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 4 x i64> @llvm.riscv.vminu.vx.nxv4i64.i64(<vscale x 4 x i64> %op1, i64 %op2)
  ret <vscale x 4 x i64> %call
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vminu_vx_u64m8(<vscale x 8 x i64> %op1, i64 %op2) {
entry:
; CHECK-LABEL: vminu_vx_u64m8
; CHECK: vsetvli zero, zero, e64,m8,tu,mu
; CHECK: vminu.vx {{v[0-9]+}}, {{v[0-9]+}}, {{a[0-9]+}}
; CHECK: ret
  %call = tail call <vscale x 8 x i64> @llvm.riscv.vminu.vx.nxv8i64.i64(<vscale x 8 x i64> %op1, i64 %op2)
  ret <vscale x 8 x i64> %call
}

; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vminu.vx.nxv1i32.i32(<vscale x 1 x i32>, i32)
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vminu.vx.nxv2i32.i32(<vscale x 2 x i32>, i32)
; Function Attrs: nounwind
declare <vscale x 4 x i64> @llvm.riscv.vminu.vx.nxv4i64.i64(<vscale x 4 x i64>, i64)
; Function Attrs: nounwind
declare <vscale x 4 x i8> @llvm.riscv.vminu.vx.nxv4i8.i8(<vscale x 4 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.vminu.vx.nxv4i16.i16(<vscale x 4 x i16>, i16)
; Function Attrs: nounwind
declare <vscale x 8 x i64> @llvm.riscv.vminu.vx.nxv8i64.i64(<vscale x 8 x i64>, i64)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vminu.vx.nxv8i32.i32(<vscale x 8 x i32>, i32)
; Function Attrs: nounwind
declare <vscale x 32 x i8> @llvm.riscv.vminu.vx.nxv32i8.i8(<vscale x 32 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vminu.vx.nxv4i32.i32(<vscale x 4 x i32>, i32)
; Function Attrs: nounwind
declare <vscale x 64 x i8> @llvm.riscv.vminu.vx.nxv64i8.i8(<vscale x 64 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 2 x i64> @llvm.riscv.vminu.vx.nxv2i64.i64(<vscale x 2 x i64>, i64)
; Function Attrs: nounwind
declare <vscale x 2 x i8> @llvm.riscv.vminu.vx.nxv2i8.i8(<vscale x 2 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.vminu.vx.nxv1i16.i16(<vscale x 1 x i16>, i16)
; Function Attrs: nounwind
declare <vscale x 16 x i8> @llvm.riscv.vminu.vx.nxv16i8.i8(<vscale x 16 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 8 x i8> @llvm.riscv.vminu.vx.nxv8i8.i8(<vscale x 8 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 1 x i64> @llvm.riscv.vminu.vx.nxv1i64.i64(<vscale x 1 x i64>, i64)
; Function Attrs: nounwind
declare <vscale x 32 x i16> @llvm.riscv.vminu.vx.nxv32i16.i16(<vscale x 32 x i16>, i16)
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.vminu.vx.nxv2i16.i16(<vscale x 2 x i16>, i16)
; Function Attrs: nounwind
declare <vscale x 16 x i32> @llvm.riscv.vminu.vx.nxv16i32.i32(<vscale x 16 x i32>, i32)
; Function Attrs: nounwind
declare <vscale x 1 x i8> @llvm.riscv.vminu.vx.nxv1i8.i8(<vscale x 1 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.vminu.vx.nxv8i16.i16(<vscale x 8 x i16>, i16)
; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.vminu.vx.nxv16i16.i16(<vscale x 16 x i16>, i16)
