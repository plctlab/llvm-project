; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: nounwind
declare <vscale x 64 x i8> @llvm.riscv.vmv.s.x.nxv64i8.i8(<vscale x 64 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 8 x i16> @llvm.riscv.vmv.s.x.nxv8i16.i16(<vscale x 8 x i16>, i16)
; Function Attrs: nounwind
declare <vscale x 8 x i32> @llvm.riscv.vmv.s.x.nxv8i32.i32(<vscale x 8 x i32>, i32)
; Function Attrs: nounwind
declare <vscale x 2 x i8> @llvm.riscv.vmv.s.x.nxv2i8.i8(<vscale x 2 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 4 x i16> @llvm.riscv.vmv.s.x.nxv4i16.i16(<vscale x 4 x i16>, i16)
; Function Attrs: nounwind
declare <vscale x 4 x i32> @llvm.riscv.vmv.s.x.nxv4i32.i32(<vscale x 4 x i32>, i32)
; Function Attrs: nounwind
declare <vscale x 1 x i32> @llvm.riscv.vmv.s.x.nxv1i32.i32(<vscale x 1 x i32>, i32)
; Function Attrs: nounwind
declare <vscale x 2 x i32> @llvm.riscv.vmv.s.x.nxv2i32.i32(<vscale x 2 x i32>, i32)
; Function Attrs: nounwind
declare <vscale x 8 x i8> @llvm.riscv.vmv.s.x.nxv8i8.i8(<vscale x 8 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 1 x i64> @llvm.riscv.vmv.s.x.nxv1i64.i64(<vscale x 1 x i64>, i64)
; Function Attrs: nounwind
declare <vscale x 16 x i16> @llvm.riscv.vmv.s.x.nxv16i16.i16(<vscale x 16 x i16>, i16)
; Function Attrs: nounwind
declare <vscale x 1 x i16> @llvm.riscv.vmv.s.x.nxv1i16.i16(<vscale x 1 x i16>, i16)
; Function Attrs: nounwind
declare <vscale x 32 x i8> @llvm.riscv.vmv.s.x.nxv32i8.i8(<vscale x 32 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 1 x i8> @llvm.riscv.vmv.s.x.nxv1i8.i8(<vscale x 1 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 16 x i32> @llvm.riscv.vmv.s.x.nxv16i32.i32(<vscale x 16 x i32>, i32)
; Function Attrs: nounwind
declare <vscale x 16 x i8> @llvm.riscv.vmv.s.x.nxv16i8.i8(<vscale x 16 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 2 x i64> @llvm.riscv.vmv.s.x.nxv2i64.i64(<vscale x 2 x i64>, i64)
; Function Attrs: nounwind
declare <vscale x 8 x i64> @llvm.riscv.vmv.s.x.nxv8i64.i64(<vscale x 8 x i64>, i64)
; Function Attrs: nounwind
declare <vscale x 2 x i16> @llvm.riscv.vmv.s.x.nxv2i16.i16(<vscale x 2 x i16>, i16)
; Function Attrs: nounwind
declare <vscale x 32 x i16> @llvm.riscv.vmv.s.x.nxv32i16.i16(<vscale x 32 x i16>, i16)
; Function Attrs: nounwind
declare <vscale x 4 x i8> @llvm.riscv.vmv.s.x.nxv4i8.i8(<vscale x 4 x i8>, i8)
; Function Attrs: nounwind
declare <vscale x 4 x i64> @llvm.riscv.vmv.s.x.nxv4i64.i64(<vscale x 4 x i64>, i64)
; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_vmv_s_x_i8mf8(<vscale x 1 x i8> %dst, i8 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i8mf8
; CHECK: vsetvli zero, zero, e8,mf8,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 1 x i8>
  %src.addr = alloca i8
  store <vscale x 1 x i8> %dst, <vscale x 1 x i8>* %dst.addr
  store i8 %src, i8* %src.addr
  %0 = load <vscale x 1 x i8>, <vscale x 1 x i8>* %dst.addr
  %1 = load i8, i8* %src.addr
  %2 = call <vscale x 1 x i8> @llvm.riscv.vmv.s.x.nxv1i8.i8(<vscale x 1 x i8> %0, i8 %1)
  ret <vscale x 1 x i8> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_vmv_s_x_i8mf4(<vscale x 2 x i8> %dst, i8 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i8mf4
; CHECK: vsetvli zero, zero, e8,mf4,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 2 x i8>
  %src.addr = alloca i8
  store <vscale x 2 x i8> %dst, <vscale x 2 x i8>* %dst.addr
  store i8 %src, i8* %src.addr
  %0 = load <vscale x 2 x i8>, <vscale x 2 x i8>* %dst.addr
  %1 = load i8, i8* %src.addr
  %2 = call <vscale x 2 x i8> @llvm.riscv.vmv.s.x.nxv2i8.i8(<vscale x 2 x i8> %0, i8 %1)
  ret <vscale x 2 x i8> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_vmv_s_x_i8mf2(<vscale x 4 x i8> %dst, i8 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i8mf2
; CHECK: vsetvli zero, zero, e8,mf2,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 4 x i8>
  %src.addr = alloca i8
  store <vscale x 4 x i8> %dst, <vscale x 4 x i8>* %dst.addr
  store i8 %src, i8* %src.addr
  %0 = load <vscale x 4 x i8>, <vscale x 4 x i8>* %dst.addr
  %1 = load i8, i8* %src.addr
  %2 = call <vscale x 4 x i8> @llvm.riscv.vmv.s.x.nxv4i8.i8(<vscale x 4 x i8> %0, i8 %1)
  ret <vscale x 4 x i8> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_vmv_s_x_i8m1(<vscale x 8 x i8> %dst, i8 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i8m1
; CHECK: vsetvli zero, zero, e8,m1,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 8 x i8>
  %src.addr = alloca i8
  store <vscale x 8 x i8> %dst, <vscale x 8 x i8>* %dst.addr
  store i8 %src, i8* %src.addr
  %0 = load <vscale x 8 x i8>, <vscale x 8 x i8>* %dst.addr
  %1 = load i8, i8* %src.addr
  %2 = call <vscale x 8 x i8> @llvm.riscv.vmv.s.x.nxv8i8.i8(<vscale x 8 x i8> %0, i8 %1)
  ret <vscale x 8 x i8> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_vmv_s_x_i8m2(<vscale x 16 x i8> %dst, i8 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i8m2
; CHECK: vsetvli zero, zero, e8,m2,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 16 x i8>
  %src.addr = alloca i8
  store <vscale x 16 x i8> %dst, <vscale x 16 x i8>* %dst.addr
  store i8 %src, i8* %src.addr
  %0 = load <vscale x 16 x i8>, <vscale x 16 x i8>* %dst.addr
  %1 = load i8, i8* %src.addr
  %2 = call <vscale x 16 x i8> @llvm.riscv.vmv.s.x.nxv16i8.i8(<vscale x 16 x i8> %0, i8 %1)
  ret <vscale x 16 x i8> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_vmv_s_x_i8m4(<vscale x 32 x i8> %dst, i8 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i8m4
; CHECK: vsetvli zero, zero, e8,m4,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 32 x i8>
  %src.addr = alloca i8
  store <vscale x 32 x i8> %dst, <vscale x 32 x i8>* %dst.addr
  store i8 %src, i8* %src.addr
  %0 = load <vscale x 32 x i8>, <vscale x 32 x i8>* %dst.addr
  %1 = load i8, i8* %src.addr
  %2 = call <vscale x 32 x i8> @llvm.riscv.vmv.s.x.nxv32i8.i8(<vscale x 32 x i8> %0, i8 %1)
  ret <vscale x 32 x i8> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i8> @test_vmv_s_x_i8m8(<vscale x 64 x i8> %dst, i8 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i8m8
; CHECK: vsetvli zero, zero, e8,m8,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 64 x i8>
  %src.addr = alloca i8
  store <vscale x 64 x i8> %dst, <vscale x 64 x i8>* %dst.addr
  store i8 %src, i8* %src.addr
  %0 = load <vscale x 64 x i8>, <vscale x 64 x i8>* %dst.addr
  %1 = load i8, i8* %src.addr
  %2 = call <vscale x 64 x i8> @llvm.riscv.vmv.s.x.nxv64i8.i8(<vscale x 64 x i8> %0, i8 %1)
  ret <vscale x 64 x i8> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vmv_s_x_i16mf4(<vscale x 1 x i16> %dst, i16 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i16mf4
; CHECK: vsetvli zero, zero, e16,mf4,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 1 x i16>
  %src.addr = alloca i16
  store <vscale x 1 x i16> %dst, <vscale x 1 x i16>* %dst.addr
  store i16 %src, i16* %src.addr
  %0 = load <vscale x 1 x i16>, <vscale x 1 x i16>* %dst.addr
  %1 = load i16, i16* %src.addr
  %2 = call <vscale x 1 x i16> @llvm.riscv.vmv.s.x.nxv1i16.i16(<vscale x 1 x i16> %0, i16 %1)
  ret <vscale x 1 x i16> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vmv_s_x_i16mf2(<vscale x 2 x i16> %dst, i16 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i16mf2
; CHECK: vsetvli zero, zero, e16,mf2,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 2 x i16>
  %src.addr = alloca i16
  store <vscale x 2 x i16> %dst, <vscale x 2 x i16>* %dst.addr
  store i16 %src, i16* %src.addr
  %0 = load <vscale x 2 x i16>, <vscale x 2 x i16>* %dst.addr
  %1 = load i16, i16* %src.addr
  %2 = call <vscale x 2 x i16> @llvm.riscv.vmv.s.x.nxv2i16.i16(<vscale x 2 x i16> %0, i16 %1)
  ret <vscale x 2 x i16> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vmv_s_x_i16m1(<vscale x 4 x i16> %dst, i16 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i16m1
; CHECK: vsetvli zero, zero, e16,m1,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 4 x i16>
  %src.addr = alloca i16
  store <vscale x 4 x i16> %dst, <vscale x 4 x i16>* %dst.addr
  store i16 %src, i16* %src.addr
  %0 = load <vscale x 4 x i16>, <vscale x 4 x i16>* %dst.addr
  %1 = load i16, i16* %src.addr
  %2 = call <vscale x 4 x i16> @llvm.riscv.vmv.s.x.nxv4i16.i16(<vscale x 4 x i16> %0, i16 %1)
  ret <vscale x 4 x i16> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vmv_s_x_i16m2(<vscale x 8 x i16> %dst, i16 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i16m2
; CHECK: vsetvli zero, zero, e16,m2,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 8 x i16>
  %src.addr = alloca i16
  store <vscale x 8 x i16> %dst, <vscale x 8 x i16>* %dst.addr
  store i16 %src, i16* %src.addr
  %0 = load <vscale x 8 x i16>, <vscale x 8 x i16>* %dst.addr
  %1 = load i16, i16* %src.addr
  %2 = call <vscale x 8 x i16> @llvm.riscv.vmv.s.x.nxv8i16.i16(<vscale x 8 x i16> %0, i16 %1)
  ret <vscale x 8 x i16> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vmv_s_x_i16m4(<vscale x 16 x i16> %dst, i16 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i16m4
; CHECK: vsetvli zero, zero, e16,m4,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 16 x i16>
  %src.addr = alloca i16
  store <vscale x 16 x i16> %dst, <vscale x 16 x i16>* %dst.addr
  store i16 %src, i16* %src.addr
  %0 = load <vscale x 16 x i16>, <vscale x 16 x i16>* %dst.addr
  %1 = load i16, i16* %src.addr
  %2 = call <vscale x 16 x i16> @llvm.riscv.vmv.s.x.nxv16i16.i16(<vscale x 16 x i16> %0, i16 %1)
  ret <vscale x 16 x i16> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vmv_s_x_i16m8(<vscale x 32 x i16> %dst, i16 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i16m8
; CHECK: vsetvli zero, zero, e16,m8,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 32 x i16>
  %src.addr = alloca i16
  store <vscale x 32 x i16> %dst, <vscale x 32 x i16>* %dst.addr
  store i16 %src, i16* %src.addr
  %0 = load <vscale x 32 x i16>, <vscale x 32 x i16>* %dst.addr
  %1 = load i16, i16* %src.addr
  %2 = call <vscale x 32 x i16> @llvm.riscv.vmv.s.x.nxv32i16.i16(<vscale x 32 x i16> %0, i16 %1)
  ret <vscale x 32 x i16> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vmv_s_x_i32mf2(<vscale x 1 x i32> %dst, i32 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i32mf2
; CHECK: vsetvli zero, zero, e32,mf2,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 1 x i32>
  %src.addr = alloca i32
  store <vscale x 1 x i32> %dst, <vscale x 1 x i32>* %dst.addr
  store i32 %src, i32* %src.addr
  %0 = load <vscale x 1 x i32>, <vscale x 1 x i32>* %dst.addr
  %1 = load i32, i32* %src.addr
  %2 = call <vscale x 1 x i32> @llvm.riscv.vmv.s.x.nxv1i32.i32(<vscale x 1 x i32> %0, i32 %1)
  ret <vscale x 1 x i32> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vmv_s_x_i32m1(<vscale x 2 x i32> %dst, i32 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i32m1
; CHECK: vsetvli zero, zero, e32,m1,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 2 x i32>
  %src.addr = alloca i32
  store <vscale x 2 x i32> %dst, <vscale x 2 x i32>* %dst.addr
  store i32 %src, i32* %src.addr
  %0 = load <vscale x 2 x i32>, <vscale x 2 x i32>* %dst.addr
  %1 = load i32, i32* %src.addr
  %2 = call <vscale x 2 x i32> @llvm.riscv.vmv.s.x.nxv2i32.i32(<vscale x 2 x i32> %0, i32 %1)
  ret <vscale x 2 x i32> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vmv_s_x_i32m2(<vscale x 4 x i32> %dst, i32 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i32m2
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 4 x i32>
  %src.addr = alloca i32
  store <vscale x 4 x i32> %dst, <vscale x 4 x i32>* %dst.addr
  store i32 %src, i32* %src.addr
  %0 = load <vscale x 4 x i32>, <vscale x 4 x i32>* %dst.addr
  %1 = load i32, i32* %src.addr
  %2 = call <vscale x 4 x i32> @llvm.riscv.vmv.s.x.nxv4i32.i32(<vscale x 4 x i32> %0, i32 %1)
  ret <vscale x 4 x i32> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vmv_s_x_i32m4(<vscale x 8 x i32> %dst, i32 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i32m4
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 8 x i32>
  %src.addr = alloca i32
  store <vscale x 8 x i32> %dst, <vscale x 8 x i32>* %dst.addr
  store i32 %src, i32* %src.addr
  %0 = load <vscale x 8 x i32>, <vscale x 8 x i32>* %dst.addr
  %1 = load i32, i32* %src.addr
  %2 = call <vscale x 8 x i32> @llvm.riscv.vmv.s.x.nxv8i32.i32(<vscale x 8 x i32> %0, i32 %1)
  ret <vscale x 8 x i32> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vmv_s_x_i32m8(<vscale x 16 x i32> %dst, i32 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i32m8
; CHECK: vsetvli zero, zero, e32,m8,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 16 x i32>
  %src.addr = alloca i32
  store <vscale x 16 x i32> %dst, <vscale x 16 x i32>* %dst.addr
  store i32 %src, i32* %src.addr
  %0 = load <vscale x 16 x i32>, <vscale x 16 x i32>* %dst.addr
  %1 = load i32, i32* %src.addr
  %2 = call <vscale x 16 x i32> @llvm.riscv.vmv.s.x.nxv16i32.i32(<vscale x 16 x i32> %0, i32 %1)
  ret <vscale x 16 x i32> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vmv_s_x_i64m1(<vscale x 1 x i64> %dst, i64 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i64m1
; CHECK: vsetvli zero, zero, e64,m1,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 1 x i64>
  %src.addr = alloca i64
  store <vscale x 1 x i64> %dst, <vscale x 1 x i64>* %dst.addr
  store i64 %src, i64* %src.addr
  %0 = load <vscale x 1 x i64>, <vscale x 1 x i64>* %dst.addr
  %1 = load i64, i64* %src.addr
  %2 = call <vscale x 1 x i64> @llvm.riscv.vmv.s.x.nxv1i64.i64(<vscale x 1 x i64> %0, i64 %1)
  ret <vscale x 1 x i64> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vmv_s_x_i64m2(<vscale x 2 x i64> %dst, i64 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i64m2
; CHECK: vsetvli zero, zero, e64,m2,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 2 x i64>
  %src.addr = alloca i64
  store <vscale x 2 x i64> %dst, <vscale x 2 x i64>* %dst.addr
  store i64 %src, i64* %src.addr
  %0 = load <vscale x 2 x i64>, <vscale x 2 x i64>* %dst.addr
  %1 = load i64, i64* %src.addr
  %2 = call <vscale x 2 x i64> @llvm.riscv.vmv.s.x.nxv2i64.i64(<vscale x 2 x i64> %0, i64 %1)
  ret <vscale x 2 x i64> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vmv_s_x_i64m4(<vscale x 4 x i64> %dst, i64 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i64m4
; CHECK: vsetvli zero, zero, e64,m4,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 4 x i64>
  %src.addr = alloca i64
  store <vscale x 4 x i64> %dst, <vscale x 4 x i64>* %dst.addr
  store i64 %src, i64* %src.addr
  %0 = load <vscale x 4 x i64>, <vscale x 4 x i64>* %dst.addr
  %1 = load i64, i64* %src.addr
  %2 = call <vscale x 4 x i64> @llvm.riscv.vmv.s.x.nxv4i64.i64(<vscale x 4 x i64> %0, i64 %1)
  ret <vscale x 4 x i64> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vmv_s_x_i64m8(<vscale x 8 x i64> %dst, i64 %src) {
entry:
; CHECK-LABEL: vmv_s_x_i64m8
; CHECK: vsetvli zero, zero, e64,m8,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 8 x i64>
  %src.addr = alloca i64
  store <vscale x 8 x i64> %dst, <vscale x 8 x i64>* %dst.addr
  store i64 %src, i64* %src.addr
  %0 = load <vscale x 8 x i64>, <vscale x 8 x i64>* %dst.addr
  %1 = load i64, i64* %src.addr
  %2 = call <vscale x 8 x i64> @llvm.riscv.vmv.s.x.nxv8i64.i64(<vscale x 8 x i64> %0, i64 %1)
  ret <vscale x 8 x i64> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i8> @test_vmv_s_x_u8mf8(<vscale x 1 x i8> %dst, i8 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u8mf8
; CHECK: vsetvli zero, zero, e8,mf8,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 1 x i8>
  %src.addr = alloca i8
  store <vscale x 1 x i8> %dst, <vscale x 1 x i8>* %dst.addr
  store i8 %src, i8* %src.addr
  %0 = load <vscale x 1 x i8>, <vscale x 1 x i8>* %dst.addr
  %1 = load i8, i8* %src.addr
  %2 = call <vscale x 1 x i8> @llvm.riscv.vmv.s.x.nxv1i8.i8(<vscale x 1 x i8> %0, i8 %1)
  ret <vscale x 1 x i8> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i8> @test_vmv_s_x_u8mf4(<vscale x 2 x i8> %dst, i8 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u8mf4
; CHECK: vsetvli zero, zero, e8,mf4,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 2 x i8>
  %src.addr = alloca i8
  store <vscale x 2 x i8> %dst, <vscale x 2 x i8>* %dst.addr
  store i8 %src, i8* %src.addr
  %0 = load <vscale x 2 x i8>, <vscale x 2 x i8>* %dst.addr
  %1 = load i8, i8* %src.addr
  %2 = call <vscale x 2 x i8> @llvm.riscv.vmv.s.x.nxv2i8.i8(<vscale x 2 x i8> %0, i8 %1)
  ret <vscale x 2 x i8> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i8> @test_vmv_s_x_u8mf2(<vscale x 4 x i8> %dst, i8 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u8mf2
; CHECK: vsetvli zero, zero, e8,mf2,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 4 x i8>
  %src.addr = alloca i8
  store <vscale x 4 x i8> %dst, <vscale x 4 x i8>* %dst.addr
  store i8 %src, i8* %src.addr
  %0 = load <vscale x 4 x i8>, <vscale x 4 x i8>* %dst.addr
  %1 = load i8, i8* %src.addr
  %2 = call <vscale x 4 x i8> @llvm.riscv.vmv.s.x.nxv4i8.i8(<vscale x 4 x i8> %0, i8 %1)
  ret <vscale x 4 x i8> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i8> @test_vmv_s_x_u8m1(<vscale x 8 x i8> %dst, i8 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u8m1
; CHECK: vsetvli zero, zero, e8,m1,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 8 x i8>
  %src.addr = alloca i8
  store <vscale x 8 x i8> %dst, <vscale x 8 x i8>* %dst.addr
  store i8 %src, i8* %src.addr
  %0 = load <vscale x 8 x i8>, <vscale x 8 x i8>* %dst.addr
  %1 = load i8, i8* %src.addr
  %2 = call <vscale x 8 x i8> @llvm.riscv.vmv.s.x.nxv8i8.i8(<vscale x 8 x i8> %0, i8 %1)
  ret <vscale x 8 x i8> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i8> @test_vmv_s_x_u8m2(<vscale x 16 x i8> %dst, i8 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u8m2
; CHECK: vsetvli zero, zero, e8,m2,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 16 x i8>
  %src.addr = alloca i8
  store <vscale x 16 x i8> %dst, <vscale x 16 x i8>* %dst.addr
  store i8 %src, i8* %src.addr
  %0 = load <vscale x 16 x i8>, <vscale x 16 x i8>* %dst.addr
  %1 = load i8, i8* %src.addr
  %2 = call <vscale x 16 x i8> @llvm.riscv.vmv.s.x.nxv16i8.i8(<vscale x 16 x i8> %0, i8 %1)
  ret <vscale x 16 x i8> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i8> @test_vmv_s_x_u8m4(<vscale x 32 x i8> %dst, i8 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u8m4
; CHECK: vsetvli zero, zero, e8,m4,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 32 x i8>
  %src.addr = alloca i8
  store <vscale x 32 x i8> %dst, <vscale x 32 x i8>* %dst.addr
  store i8 %src, i8* %src.addr
  %0 = load <vscale x 32 x i8>, <vscale x 32 x i8>* %dst.addr
  %1 = load i8, i8* %src.addr
  %2 = call <vscale x 32 x i8> @llvm.riscv.vmv.s.x.nxv32i8.i8(<vscale x 32 x i8> %0, i8 %1)
  ret <vscale x 32 x i8> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 64 x i8> @test_vmv_s_x_u8m8(<vscale x 64 x i8> %dst, i8 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u8m8
; CHECK: vsetvli zero, zero, e8,m8,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 64 x i8>
  %src.addr = alloca i8
  store <vscale x 64 x i8> %dst, <vscale x 64 x i8>* %dst.addr
  store i8 %src, i8* %src.addr
  %0 = load <vscale x 64 x i8>, <vscale x 64 x i8>* %dst.addr
  %1 = load i8, i8* %src.addr
  %2 = call <vscale x 64 x i8> @llvm.riscv.vmv.s.x.nxv64i8.i8(<vscale x 64 x i8> %0, i8 %1)
  ret <vscale x 64 x i8> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i16> @test_vmv_s_x_u16mf4(<vscale x 1 x i16> %dst, i16 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u16mf4
; CHECK: vsetvli zero, zero, e16,mf4,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 1 x i16>
  %src.addr = alloca i16
  store <vscale x 1 x i16> %dst, <vscale x 1 x i16>* %dst.addr
  store i16 %src, i16* %src.addr
  %0 = load <vscale x 1 x i16>, <vscale x 1 x i16>* %dst.addr
  %1 = load i16, i16* %src.addr
  %2 = call <vscale x 1 x i16> @llvm.riscv.vmv.s.x.nxv1i16.i16(<vscale x 1 x i16> %0, i16 %1)
  ret <vscale x 1 x i16> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i16> @test_vmv_s_x_u16mf2(<vscale x 2 x i16> %dst, i16 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u16mf2
; CHECK: vsetvli zero, zero, e16,mf2,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 2 x i16>
  %src.addr = alloca i16
  store <vscale x 2 x i16> %dst, <vscale x 2 x i16>* %dst.addr
  store i16 %src, i16* %src.addr
  %0 = load <vscale x 2 x i16>, <vscale x 2 x i16>* %dst.addr
  %1 = load i16, i16* %src.addr
  %2 = call <vscale x 2 x i16> @llvm.riscv.vmv.s.x.nxv2i16.i16(<vscale x 2 x i16> %0, i16 %1)
  ret <vscale x 2 x i16> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i16> @test_vmv_s_x_u16m1(<vscale x 4 x i16> %dst, i16 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u16m1
; CHECK: vsetvli zero, zero, e16,m1,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 4 x i16>
  %src.addr = alloca i16
  store <vscale x 4 x i16> %dst, <vscale x 4 x i16>* %dst.addr
  store i16 %src, i16* %src.addr
  %0 = load <vscale x 4 x i16>, <vscale x 4 x i16>* %dst.addr
  %1 = load i16, i16* %src.addr
  %2 = call <vscale x 4 x i16> @llvm.riscv.vmv.s.x.nxv4i16.i16(<vscale x 4 x i16> %0, i16 %1)
  ret <vscale x 4 x i16> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i16> @test_vmv_s_x_u16m2(<vscale x 8 x i16> %dst, i16 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u16m2
; CHECK: vsetvli zero, zero, e16,m2,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 8 x i16>
  %src.addr = alloca i16
  store <vscale x 8 x i16> %dst, <vscale x 8 x i16>* %dst.addr
  store i16 %src, i16* %src.addr
  %0 = load <vscale x 8 x i16>, <vscale x 8 x i16>* %dst.addr
  %1 = load i16, i16* %src.addr
  %2 = call <vscale x 8 x i16> @llvm.riscv.vmv.s.x.nxv8i16.i16(<vscale x 8 x i16> %0, i16 %1)
  ret <vscale x 8 x i16> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i16> @test_vmv_s_x_u16m4(<vscale x 16 x i16> %dst, i16 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u16m4
; CHECK: vsetvli zero, zero, e16,m4,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 16 x i16>
  %src.addr = alloca i16
  store <vscale x 16 x i16> %dst, <vscale x 16 x i16>* %dst.addr
  store i16 %src, i16* %src.addr
  %0 = load <vscale x 16 x i16>, <vscale x 16 x i16>* %dst.addr
  %1 = load i16, i16* %src.addr
  %2 = call <vscale x 16 x i16> @llvm.riscv.vmv.s.x.nxv16i16.i16(<vscale x 16 x i16> %0, i16 %1)
  ret <vscale x 16 x i16> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 32 x i16> @test_vmv_s_x_u16m8(<vscale x 32 x i16> %dst, i16 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u16m8
; CHECK: vsetvli zero, zero, e16,m8,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 32 x i16>
  %src.addr = alloca i16
  store <vscale x 32 x i16> %dst, <vscale x 32 x i16>* %dst.addr
  store i16 %src, i16* %src.addr
  %0 = load <vscale x 32 x i16>, <vscale x 32 x i16>* %dst.addr
  %1 = load i16, i16* %src.addr
  %2 = call <vscale x 32 x i16> @llvm.riscv.vmv.s.x.nxv32i16.i16(<vscale x 32 x i16> %0, i16 %1)
  ret <vscale x 32 x i16> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i32> @test_vmv_s_x_u32mf2(<vscale x 1 x i32> %dst, i32 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u32mf2
; CHECK: vsetvli zero, zero, e32,mf2,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 1 x i32>
  %src.addr = alloca i32
  store <vscale x 1 x i32> %dst, <vscale x 1 x i32>* %dst.addr
  store i32 %src, i32* %src.addr
  %0 = load <vscale x 1 x i32>, <vscale x 1 x i32>* %dst.addr
  %1 = load i32, i32* %src.addr
  %2 = call <vscale x 1 x i32> @llvm.riscv.vmv.s.x.nxv1i32.i32(<vscale x 1 x i32> %0, i32 %1)
  ret <vscale x 1 x i32> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i32> @test_vmv_s_x_u32m1(<vscale x 2 x i32> %dst, i32 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u32m1
; CHECK: vsetvli zero, zero, e32,m1,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 2 x i32>
  %src.addr = alloca i32
  store <vscale x 2 x i32> %dst, <vscale x 2 x i32>* %dst.addr
  store i32 %src, i32* %src.addr
  %0 = load <vscale x 2 x i32>, <vscale x 2 x i32>* %dst.addr
  %1 = load i32, i32* %src.addr
  %2 = call <vscale x 2 x i32> @llvm.riscv.vmv.s.x.nxv2i32.i32(<vscale x 2 x i32> %0, i32 %1)
  ret <vscale x 2 x i32> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i32> @test_vmv_s_x_u32m2(<vscale x 4 x i32> %dst, i32 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u32m2
; CHECK: vsetvli zero, zero, e32,m2,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 4 x i32>
  %src.addr = alloca i32
  store <vscale x 4 x i32> %dst, <vscale x 4 x i32>* %dst.addr
  store i32 %src, i32* %src.addr
  %0 = load <vscale x 4 x i32>, <vscale x 4 x i32>* %dst.addr
  %1 = load i32, i32* %src.addr
  %2 = call <vscale x 4 x i32> @llvm.riscv.vmv.s.x.nxv4i32.i32(<vscale x 4 x i32> %0, i32 %1)
  ret <vscale x 4 x i32> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i32> @test_vmv_s_x_u32m4(<vscale x 8 x i32> %dst, i32 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u32m4
; CHECK: vsetvli zero, zero, e32,m4,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 8 x i32>
  %src.addr = alloca i32
  store <vscale x 8 x i32> %dst, <vscale x 8 x i32>* %dst.addr
  store i32 %src, i32* %src.addr
  %0 = load <vscale x 8 x i32>, <vscale x 8 x i32>* %dst.addr
  %1 = load i32, i32* %src.addr
  %2 = call <vscale x 8 x i32> @llvm.riscv.vmv.s.x.nxv8i32.i32(<vscale x 8 x i32> %0, i32 %1)
  ret <vscale x 8 x i32> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 16 x i32> @test_vmv_s_x_u32m8(<vscale x 16 x i32> %dst, i32 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u32m8
; CHECK: vsetvli zero, zero, e32,m8,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 16 x i32>
  %src.addr = alloca i32
  store <vscale x 16 x i32> %dst, <vscale x 16 x i32>* %dst.addr
  store i32 %src, i32* %src.addr
  %0 = load <vscale x 16 x i32>, <vscale x 16 x i32>* %dst.addr
  %1 = load i32, i32* %src.addr
  %2 = call <vscale x 16 x i32> @llvm.riscv.vmv.s.x.nxv16i32.i32(<vscale x 16 x i32> %0, i32 %1)
  ret <vscale x 16 x i32> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 1 x i64> @test_vmv_s_x_u64m1(<vscale x 1 x i64> %dst, i64 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u64m1
; CHECK: vsetvli zero, zero, e64,m1,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 1 x i64>
  %src.addr = alloca i64
  store <vscale x 1 x i64> %dst, <vscale x 1 x i64>* %dst.addr
  store i64 %src, i64* %src.addr
  %0 = load <vscale x 1 x i64>, <vscale x 1 x i64>* %dst.addr
  %1 = load i64, i64* %src.addr
  %2 = call <vscale x 1 x i64> @llvm.riscv.vmv.s.x.nxv1i64.i64(<vscale x 1 x i64> %0, i64 %1)
  ret <vscale x 1 x i64> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 2 x i64> @test_vmv_s_x_u64m2(<vscale x 2 x i64> %dst, i64 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u64m2
; CHECK: vsetvli zero, zero, e64,m2,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 2 x i64>
  %src.addr = alloca i64
  store <vscale x 2 x i64> %dst, <vscale x 2 x i64>* %dst.addr
  store i64 %src, i64* %src.addr
  %0 = load <vscale x 2 x i64>, <vscale x 2 x i64>* %dst.addr
  %1 = load i64, i64* %src.addr
  %2 = call <vscale x 2 x i64> @llvm.riscv.vmv.s.x.nxv2i64.i64(<vscale x 2 x i64> %0, i64 %1)
  ret <vscale x 2 x i64> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 4 x i64> @test_vmv_s_x_u64m4(<vscale x 4 x i64> %dst, i64 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u64m4
; CHECK: vsetvli zero, zero, e64,m4,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 4 x i64>
  %src.addr = alloca i64
  store <vscale x 4 x i64> %dst, <vscale x 4 x i64>* %dst.addr
  store i64 %src, i64* %src.addr
  %0 = load <vscale x 4 x i64>, <vscale x 4 x i64>* %dst.addr
  %1 = load i64, i64* %src.addr
  %2 = call <vscale x 4 x i64> @llvm.riscv.vmv.s.x.nxv4i64.i64(<vscale x 4 x i64> %0, i64 %1)
  ret <vscale x 4 x i64> %2
}

; Function Attrs: noinline nounwind optnone
define <vscale x 8 x i64> @test_vmv_s_x_u64m8(<vscale x 8 x i64> %dst, i64 %src) {
entry:
; CHECK-LABEL: vmv_s_x_u64m8
; CHECK: vsetvli zero, zero, e64,m8,tu,mu
; CHECK-NEXT: vmv.s.x v{{.*}}, a{{.*}}
  %dst.addr = alloca <vscale x 8 x i64>
  %src.addr = alloca i64
  store <vscale x 8 x i64> %dst, <vscale x 8 x i64>* %dst.addr
  store i64 %src, i64* %src.addr
  %0 = load <vscale x 8 x i64>, <vscale x 8 x i64>* %dst.addr
  %1 = load i64, i64* %src.addr
  %2 = call <vscale x 8 x i64> @llvm.riscv.vmv.s.x.nxv8i64.i64(<vscale x 8 x i64> %0, i64 %1)
  ret <vscale x 8 x i64> %2
}

