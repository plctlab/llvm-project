; ModuleID = '../clang/test/CodeGen/RISCV/rvk-intrinsics/riscv64-zkn.c'
source_filename = "../clang/test/CodeGen/RISCV/rvk-intrinsics/riscv64-zkn.c"
target datalayout = "e-m:e-p:64:64-i64:64-i128:128-n64-S128"
target triple = "riscv64"

; Function Attrs: noinline nounwind optnone
define dso_local i64 @test_rv64_aes64dsm(i64 %rs1, i64 %rs2) #0 {
entry:
  %rs1.addr = alloca i64, align 8
  %rs2.addr = alloca i64, align 8
  store i64 %rs1, i64* %rs1.addr, align 8
  store i64 %rs2, i64* %rs2.addr, align 8
  %0 = load i64, i64* %rs1.addr, align 8
  %1 = load i64, i64* %rs2.addr, align 8
  %call = call i64 @_rv64_aes64dsm(i64 %0, i64 %1)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define internal i64 @_rv64_aes64dsm(i64 %rs1, i64 %rs2) #0 {
entry:
  %rs1.addr = alloca i64, align 8
  %rs2.addr = alloca i64, align 8
  store i64 %rs1, i64* %rs1.addr, align 8
  store i64 %rs2, i64* %rs2.addr, align 8
  %0 = load i64, i64* %rs1.addr, align 8
  %1 = load i64, i64* %rs2.addr, align 8
  %2 = call i64 @llvm.riscv.aes64dsm(i64 %0, i64 %1)
  ret i64 %2
}

; Function Attrs: noinline nounwind optnone
define dso_local i64 @test_rv64_aes64ds(i64 %rs1, i64 %rs2) #0 {
entry:
  %rs1.addr = alloca i64, align 8
  %rs2.addr = alloca i64, align 8
  store i64 %rs1, i64* %rs1.addr, align 8
  store i64 %rs2, i64* %rs2.addr, align 8
  %0 = load i64, i64* %rs1.addr, align 8
  %1 = load i64, i64* %rs2.addr, align 8
  %call = call i64 @_rv64_aes64ds(i64 %0, i64 %1)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define internal i64 @_rv64_aes64ds(i64 %rs1, i64 %rs2) #0 {
entry:
  %rs1.addr = alloca i64, align 8
  %rs2.addr = alloca i64, align 8
  store i64 %rs1, i64* %rs1.addr, align 8
  store i64 %rs2, i64* %rs2.addr, align 8
  %0 = load i64, i64* %rs1.addr, align 8
  %1 = load i64, i64* %rs2.addr, align 8
  %2 = call i64 @llvm.riscv.aes64ds(i64 %0, i64 %1)
  ret i64 %2
}

; Function Attrs: noinline nounwind optnone
define dso_local i64 @test_rv64_aes64es(i64 %rs1, i64 %rs2) #0 {
entry:
  %rs1.addr = alloca i64, align 8
  %rs2.addr = alloca i64, align 8
  store i64 %rs1, i64* %rs1.addr, align 8
  store i64 %rs2, i64* %rs2.addr, align 8
  %0 = load i64, i64* %rs1.addr, align 8
  %1 = load i64, i64* %rs2.addr, align 8
  %call = call i64 @_rv64_aes64es(i64 %0, i64 %1)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define internal i64 @_rv64_aes64es(i64 %rs1, i64 %rs2) #0 {
entry:
  %rs1.addr = alloca i64, align 8
  %rs2.addr = alloca i64, align 8
  store i64 %rs1, i64* %rs1.addr, align 8
  store i64 %rs2, i64* %rs2.addr, align 8
  %0 = load i64, i64* %rs1.addr, align 8
  %1 = load i64, i64* %rs2.addr, align 8
  %2 = call i64 @llvm.riscv.aes64es(i64 %0, i64 %1)
  ret i64 %2
}

; Function Attrs: noinline nounwind optnone
define dso_local i64 @test_rv64_aes64esm(i64 %rs1, i64 %rs2) #0 {
entry:
  %rs1.addr = alloca i64, align 8
  %rs2.addr = alloca i64, align 8
  store i64 %rs1, i64* %rs1.addr, align 8
  store i64 %rs2, i64* %rs2.addr, align 8
  %0 = load i64, i64* %rs1.addr, align 8
  %1 = load i64, i64* %rs2.addr, align 8
  %call = call i64 @_rv64_aes64esm(i64 %0, i64 %1)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define internal i64 @_rv64_aes64esm(i64 %rs1, i64 %rs2) #0 {
entry:
  %rs1.addr = alloca i64, align 8
  %rs2.addr = alloca i64, align 8
  store i64 %rs1, i64* %rs1.addr, align 8
  store i64 %rs2, i64* %rs2.addr, align 8
  %0 = load i64, i64* %rs1.addr, align 8
  %1 = load i64, i64* %rs2.addr, align 8
  %2 = call i64 @llvm.riscv.aes64esm(i64 %0, i64 %1)
  ret i64 %2
}

; Function Attrs: noinline nounwind optnone
define dso_local i64 @test_rv64_aes64im(i64 %rs1) #0 {
entry:
  %rs1.addr = alloca i64, align 8
  store i64 %rs1, i64* %rs1.addr, align 8
  %0 = load i64, i64* %rs1.addr, align 8
  %call = call i64 @_rv64_aes64im(i64 %0)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define internal i64 @_rv64_aes64im(i64 %rs1) #0 {
entry:
  %rs1.addr = alloca i64, align 8
  store i64 %rs1, i64* %rs1.addr, align 8
  %0 = load i64, i64* %rs1.addr, align 8
  %1 = call i64 @llvm.riscv.aes64im(i64 %0)
  ret i64 %1
}

; Function Attrs: noinline nounwind optnone
define dso_local i64 @test_rv64_aes64ks2(i64 %rs1, i64 %rs2) #0 {
entry:
  %rs1.addr = alloca i64, align 8
  %rs2.addr = alloca i64, align 8
  store i64 %rs1, i64* %rs1.addr, align 8
  store i64 %rs2, i64* %rs2.addr, align 8
  %0 = load i64, i64* %rs1.addr, align 8
  %1 = load i64, i64* %rs2.addr, align 8
  %call = call i64 @_rv64_aes64ks2(i64 %0, i64 %1)
  ret i64 %call
}

; Function Attrs: noinline nounwind optnone
define internal i64 @_rv64_aes64ks2(i64 %rs1, i64 %rs2) #0 {
entry:
  %rs1.addr = alloca i64, align 8
  %rs2.addr = alloca i64, align 8
  store i64 %rs1, i64* %rs1.addr, align 8
  store i64 %rs2, i64* %rs2.addr, align 8
  %0 = load i64, i64* %rs1.addr, align 8
  %1 = load i64, i64* %rs2.addr, align 8
  %2 = call i64 @llvm.riscv.aes64ks2(i64 %0, i64 %1)
  ret i64 %2
}

; Function Attrs: nounwind readnone speculatable
declare i64 @llvm.riscv.aes64dsm(i64, i64) #1

; Function Attrs: nounwind readnone speculatable
declare i64 @llvm.riscv.aes64ds(i64, i64) #1

; Function Attrs: nounwind readnone speculatable
declare i64 @llvm.riscv.aes64es(i64, i64) #1

; Function Attrs: nounwind readnone speculatable
declare i64 @llvm.riscv.aes64esm(i64, i64) #1

; Function Attrs: nounwind readnone speculatable
declare i64 @llvm.riscv.aes64im(i64) #1

; Function Attrs: nounwind readnone speculatable
declare i64 @llvm.riscv.aes64ks2(i64, i64) #1

attributes #0 = { noinline nounwind optnone "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-features"="+64bit,+experimental-k" }
attributes #1 = { nounwind readnone speculatable }

!llvm.module.flags = !{!0, !1, !2}
!llvm.ident = !{!3}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 1, !"target-abi", !""}
!2 = !{i32 1, !"SmallDataLimit", i32 0}
!3 = !{!"clang version 13.0.0 (git@yt.droid.ac.cn:wuxinlong/llvm-project.git c3801e8754f22ddac04d1d5ce77fc9c0dbd4cef9)"}
