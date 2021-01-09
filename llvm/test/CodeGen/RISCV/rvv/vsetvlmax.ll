; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s | FileCheck -check-prefix=CHECK %s

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e8mf8() {
entry:
; CHECK-LABEL: vsetvlmax_e8mf8
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e8,mf8,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 5)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e8mf4() {
entry:
; CHECK-LABEL: vsetvlmax_e8mf4
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e8,mf4,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 6)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e8mf2() {
entry:
; CHECK-LABEL: vsetvlmax_e8mf2
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e8,mf2,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 7)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e8m1() {
entry:
; CHECK-LABEL: vsetvlmax_e8m1
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e8,m1,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 0)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e8m2() {
entry:
; CHECK-LABEL: vsetvlmax_e8m2
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e8,m2,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 1)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e8m4() {
entry:
; CHECK-LABEL: vsetvlmax_e8m4
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e8,m4,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 2)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e8m8() {
entry:
; CHECK-LABEL: vsetvlmax_e8m8
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e8,m8,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 3)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e16mf4() {
entry:
; CHECK-LABEL: vsetvlmax_e16mf4
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e16,mf4,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 14)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e16mf2() {
entry:
; CHECK-LABEL: vsetvlmax_e16mf2
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e16,mf2,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 15)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e16m1() {
entry:
; CHECK-LABEL: vsetvlmax_e16m1
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e16,m1,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 8)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e16m2() {
entry:
; CHECK-LABEL: vsetvlmax_e16m2
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e16,m2,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 9)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e16m4() {
entry:
; CHECK-LABEL: vsetvlmax_e16m4
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e16,m4,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 10)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e16m8() {
entry:
; CHECK-LABEL: vsetvlmax_e16m8
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e16,m8,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 11)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e32mf2() {
entry:
; CHECK-LABEL: vsetvlmax_e32mf2
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e32,mf2,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 23)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e32m1() {
entry:
; CHECK-LABEL: vsetvlmax_e32m1
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e32,m1,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 16)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e32m2() {
entry:
; CHECK-LABEL: vsetvlmax_e32m2
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e32,m2,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 17)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e32m4() {
entry:
; CHECK-LABEL: vsetvlmax_e32m4
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e32,m4,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 18)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e32m8() {
entry:
; CHECK-LABEL: vsetvlmax_e32m8
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e32,m8,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 19)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e64m1() {
entry:
; CHECK-LABEL: vsetvlmax_e64m1
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e64,m1,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 24)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e64m2() {
entry:
; CHECK-LABEL: vsetvlmax_e64m2
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e64,m2,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 25)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e64m4() {
entry:
; CHECK-LABEL: vsetvlmax_e64m4
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e64,m4,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 26)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define i64 @test_vsetvlmax_e64m8() {
entry:
; CHECK-LABEL: vsetvlmax_e64m8
; CHECK: vsetvli {{a[0-9]+}}, {{a[0-9]+}}, e64,m8,tu,mu
  %call = tail call i64 @llvm.riscv.vsetvl(i64 -1, i64 27)
  ret i64 %call
}

; Function Attrs: nounwind
declare i64 @llvm.riscv.vsetvl(i64, i64)
