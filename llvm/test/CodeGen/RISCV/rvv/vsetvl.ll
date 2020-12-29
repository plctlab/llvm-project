; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: nounwind
declare i64 @llvm.riscv.vsetvl(i64, i64)
; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e8mf8(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e8mf8
; CHECK: vsetvli a{{.*}}, a{{.*}}, e8,mf8,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 5)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e8mf4(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e8mf4
; CHECK: vsetvli a{{.*}}, a{{.*}}, e8,mf4,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 6)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e8mf2(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e8mf2
; CHECK: vsetvli a{{.*}}, a{{.*}}, e8,mf2,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 7)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e8m1(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e8m1
; CHECK: vsetvli a{{.*}}, a{{.*}}, e8,m1,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 0)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e8m2(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e8m2
; CHECK: vsetvli a{{.*}}, a{{.*}}, e8,m2,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 1)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e8m4(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e8m4
; CHECK: vsetvli a{{.*}}, a{{.*}}, e8,m4,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 2)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e8m8(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e8m8
; CHECK: vsetvli a{{.*}}, a{{.*}}, e8,m8,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 3)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e16mf4(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e16mf4
; CHECK: vsetvli a{{.*}}, a{{.*}}, e16,mf4,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 14)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e16mf2(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e16mf2
; CHECK: vsetvli a{{.*}}, a{{.*}}, e16,mf2,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 15)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e16m1(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e16m1
; CHECK: vsetvli a{{.*}}, a{{.*}}, e16,m1,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 8)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e16m2(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e16m2
; CHECK: vsetvli a{{.*}}, a{{.*}}, e16,m2,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 9)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e16m4(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e16m4
; CHECK: vsetvli a{{.*}}, a{{.*}}, e16,m4,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 10)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e16m8(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e16m8
; CHECK: vsetvli a{{.*}}, a{{.*}}, e16,m8,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 11)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e32mf2(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e32mf2
; CHECK: vsetvli a{{.*}}, a{{.*}}, e32,mf2,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 23)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e32m1(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e32m1
; CHECK: vsetvli a{{.*}}, a{{.*}}, e32,m1,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 16)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e32m2(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e32m2
; CHECK: vsetvli a{{.*}}, a{{.*}}, e32,m2,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 17)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e32m4(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e32m4
; CHECK: vsetvli a{{.*}}, a{{.*}}, e32,m4,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 18)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e32m8(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e32m8
; CHECK: vsetvli a{{.*}}, a{{.*}}, e32,m8,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 19)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e64m1(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e64m1
; CHECK: vsetvli a{{.*}}, a{{.*}}, e64,m1,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 24)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e64m2(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e64m2
; CHECK: vsetvli a{{.*}}, a{{.*}}, e64,m2,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 25)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e64m4(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e64m4
; CHECK: vsetvli a{{.*}}, a{{.*}}, e64,m4,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 26)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvl_e64m8(i64 %avl) {
entry:
; CHECK-LABEL: vsetvl_e64m8
; CHECK: vsetvli a{{.*}}, a{{.*}}, e64,m8,tu,mu
  %avl.addr = alloca i64
  store i64 %avl, i64* %avl.addr
  %0 = load i64, i64* %avl.addr
  %1 = call i64 @llvm.riscv.vsetvl(i64 %0, i64 27)
  ret i64 %1
}

