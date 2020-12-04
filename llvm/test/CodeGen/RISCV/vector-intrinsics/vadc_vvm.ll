; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 1 x i8> @llvm.riscv.vadc.vvm.i8mf8(<vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i1>);
define <vscale x 1 x i8> @vadc_vvm_i8mf8(<vscale x 1 x i8> %0, <vscale x 1 x i8> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i8mf8
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i8> @llvm.riscv.vadc.vvm.i8mf8(<vscale x 1 x i8> %0, <vscale x 1 x i8> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i8> %a
}

declare <vscale x 2 x i8> @llvm.riscv.vadc.vvm.i8mf4(<vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i1>);
define <vscale x 2 x i8> @vadc_vvm_i8mf4(<vscale x 2 x i8> %0, <vscale x 2 x i8> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i8mf4
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i8> @llvm.riscv.vadc.vvm.i8mf4(<vscale x 2 x i8> %0, <vscale x 2 x i8> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i8> %a
}

declare <vscale x 4 x i8> @llvm.riscv.vadc.vvm.i8mf2(<vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i1>);
define <vscale x 4 x i8> @vadc_vvm_i8mf2(<vscale x 4 x i8> %0, <vscale x 4 x i8> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i8mf2
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i8> @llvm.riscv.vadc.vvm.i8mf2(<vscale x 4 x i8> %0, <vscale x 4 x i8> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i8> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vadc.vvm.i8m1(<vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i1>);
define <vscale x 8 x i8> @vadc_vvm_i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i8m1
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i8> @llvm.riscv.vadc.vvm.i8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i8> %a
}

declare <vscale x 16 x i8> @llvm.riscv.vadc.vvm.i8m2(<vscale x 16 x i8>, <vscale x 16 x i8>, <vscale x 16 x i1>);
define <vscale x 16 x i8> @vadc_vvm_i8m2(<vscale x 16 x i8> %0, <vscale x 16 x i8> %1, <vscale x 16 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i8m2
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i8> @llvm.riscv.vadc.vvm.i8m2(<vscale x 16 x i8> %0, <vscale x 16 x i8> %1, <vscale x 16 x i1> %2)
  ret <vscale x 16 x i8> %a
}

declare <vscale x 32 x i8> @llvm.riscv.vadc.vvm.i8m4(<vscale x 32 x i8>, <vscale x 32 x i8>, <vscale x 32 x i1>);
define <vscale x 32 x i8> @vadc_vvm_i8m4(<vscale x 32 x i8> %0, <vscale x 32 x i8> %1, <vscale x 32 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i8m4
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i8> @llvm.riscv.vadc.vvm.i8m4(<vscale x 32 x i8> %0, <vscale x 32 x i8> %1, <vscale x 32 x i1> %2)
  ret <vscale x 32 x i8> %a
}

declare <vscale x 64 x i8> @llvm.riscv.vadc.vvm.i8m8(<vscale x 64 x i8>, <vscale x 64 x i8>, <vscale x 64 x i1>);
define <vscale x 64 x i8> @vadc_vvm_i8m8(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1, <vscale x 64 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i8m8
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 64 x i8> @llvm.riscv.vadc.vvm.i8m8(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1, <vscale x 64 x i1> %2)
  ret <vscale x 64 x i8> %a
}

declare <vscale x 1 x i16> @llvm.riscv.vadc.vvm.i16mf4(<vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i1>);
define <vscale x 1 x i16> @vadc_vvm_i16mf4(<vscale x 1 x i16> %0, <vscale x 1 x i16> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i16mf4
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vadc.vvm.i16mf4(<vscale x 1 x i16> %0, <vscale x 1 x i16> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vadc.vvm.i16mf2(<vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i1>);
define <vscale x 2 x i16> @vadc_vvm_i16mf2(<vscale x 2 x i16> %0, <vscale x 2 x i16> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i16mf2
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vadc.vvm.i16mf2(<vscale x 2 x i16> %0, <vscale x 2 x i16> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vadc.vvm.i16m1(<vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i1>);
define <vscale x 4 x i16> @vadc_vvm_i16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i16m1
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vadc.vvm.i16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vadc.vvm.i16m2(<vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i1>);
define <vscale x 8 x i16> @vadc_vvm_i16m2(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i16m2
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vadc.vvm.i16m2(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vadc.vvm.i16m4(<vscale x 16 x i16>, <vscale x 16 x i16>, <vscale x 16 x i1>);
define <vscale x 16 x i16> @vadc_vvm_i16m4(<vscale x 16 x i16> %0, <vscale x 16 x i16> %1, <vscale x 16 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i16m4
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vadc.vvm.i16m4(<vscale x 16 x i16> %0, <vscale x 16 x i16> %1, <vscale x 16 x i1> %2)
  ret <vscale x 16 x i16> %a
}

declare <vscale x 32 x i16> @llvm.riscv.vadc.vvm.i16m8(<vscale x 32 x i16>, <vscale x 32 x i16>, <vscale x 32 x i1>);
define <vscale x 32 x i16> @vadc_vvm_i16m8(<vscale x 32 x i16> %0, <vscale x 32 x i16> %1, <vscale x 32 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i16m8
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i16> @llvm.riscv.vadc.vvm.i16m8(<vscale x 32 x i16> %0, <vscale x 32 x i16> %1, <vscale x 32 x i1> %2)
  ret <vscale x 32 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vadc.vvm.i32mf2(<vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i1>);
define <vscale x 1 x i32> @vadc_vvm_i32mf2(<vscale x 1 x i32> %0, <vscale x 1 x i32> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i32mf2
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vadc.vvm.i32mf2(<vscale x 1 x i32> %0, <vscale x 1 x i32> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vadc.vvm.i32m1(<vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i1>);
define <vscale x 2 x i32> @vadc_vvm_i32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i32m1
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vadc.vvm.i32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vadc.vvm.i32m2(<vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i1>);
define <vscale x 4 x i32> @vadc_vvm_i32m2(<vscale x 4 x i32> %0, <vscale x 4 x i32> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i32m2
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vadc.vvm.i32m2(<vscale x 4 x i32> %0, <vscale x 4 x i32> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vadc.vvm.i32m4(<vscale x 8 x i32>, <vscale x 8 x i32>, <vscale x 8 x i1>);
define <vscale x 8 x i32> @vadc_vvm_i32m4(<vscale x 8 x i32> %0, <vscale x 8 x i32> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i32m4
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vadc.vvm.i32m4(<vscale x 8 x i32> %0, <vscale x 8 x i32> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i32> %a
}

declare <vscale x 16 x i32> @llvm.riscv.vadc.vvm.i32m8(<vscale x 16 x i32>, <vscale x 16 x i32>, <vscale x 16 x i1>);
define <vscale x 16 x i32> @vadc_vvm_i32m8(<vscale x 16 x i32> %0, <vscale x 16 x i32> %1, <vscale x 16 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i32m8
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i32> @llvm.riscv.vadc.vvm.i32m8(<vscale x 16 x i32> %0, <vscale x 16 x i32> %1, <vscale x 16 x i1> %2)
  ret <vscale x 16 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vadc.vvm.i64m1(<vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i1>);
define <vscale x 1 x i64> @vadc_vvm_i64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i64m1
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i64> @llvm.riscv.vadc.vvm.i64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i64> %a
}

declare <vscale x 2 x i64> @llvm.riscv.vadc.vvm.i64m2(<vscale x 2 x i64>, <vscale x 2 x i64>, <vscale x 2 x i1>);
define <vscale x 2 x i64> @vadc_vvm_i64m2(<vscale x 2 x i64> %0, <vscale x 2 x i64> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i64m2
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i64> @llvm.riscv.vadc.vvm.i64m2(<vscale x 2 x i64> %0, <vscale x 2 x i64> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i64> %a
}

declare <vscale x 4 x i64> @llvm.riscv.vadc.vvm.i64m4(<vscale x 4 x i64>, <vscale x 4 x i64>, <vscale x 4 x i1>);
define <vscale x 4 x i64> @vadc_vvm_i64m4(<vscale x 4 x i64> %0, <vscale x 4 x i64> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i64m4
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i64> @llvm.riscv.vadc.vvm.i64m4(<vscale x 4 x i64> %0, <vscale x 4 x i64> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i64> %a
}

declare <vscale x 8 x i64> @llvm.riscv.vadc.vvm.i64m8(<vscale x 8 x i64>, <vscale x 8 x i64>, <vscale x 8 x i1>);
define <vscale x 8 x i64> @vadc_vvm_i64m8(<vscale x 8 x i64> %0, <vscale x 8 x i64> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_i64m8
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i64> @llvm.riscv.vadc.vvm.i64m8(<vscale x 8 x i64> %0, <vscale x 8 x i64> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i64> %a
}

declare <vscale x 1 x i8> @llvm.riscv.vadc.vvm.u8mf8(<vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i1>);
define <vscale x 1 x i8> @vadc_vvm_u8mf8(<vscale x 1 x i8> %0, <vscale x 1 x i8> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u8mf8
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i8> @llvm.riscv.vadc.vvm.u8mf8(<vscale x 1 x i8> %0, <vscale x 1 x i8> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i8> %a
}

declare <vscale x 2 x i8> @llvm.riscv.vadc.vvm.u8mf4(<vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i1>);
define <vscale x 2 x i8> @vadc_vvm_u8mf4(<vscale x 2 x i8> %0, <vscale x 2 x i8> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u8mf4
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i8> @llvm.riscv.vadc.vvm.u8mf4(<vscale x 2 x i8> %0, <vscale x 2 x i8> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i8> %a
}

declare <vscale x 4 x i8> @llvm.riscv.vadc.vvm.u8mf2(<vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i1>);
define <vscale x 4 x i8> @vadc_vvm_u8mf2(<vscale x 4 x i8> %0, <vscale x 4 x i8> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u8mf2
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i8> @llvm.riscv.vadc.vvm.u8mf2(<vscale x 4 x i8> %0, <vscale x 4 x i8> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i8> %a
}

declare <vscale x 8 x i8> @llvm.riscv.vadc.vvm.u8m1(<vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i1>);
define <vscale x 8 x i8> @vadc_vvm_u8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u8m1
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i8> @llvm.riscv.vadc.vvm.u8m1(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i8> %a
}

declare <vscale x 16 x i8> @llvm.riscv.vadc.vvm.u8m2(<vscale x 16 x i8>, <vscale x 16 x i8>, <vscale x 16 x i1>);
define <vscale x 16 x i8> @vadc_vvm_u8m2(<vscale x 16 x i8> %0, <vscale x 16 x i8> %1, <vscale x 16 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u8m2
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i8> @llvm.riscv.vadc.vvm.u8m2(<vscale x 16 x i8> %0, <vscale x 16 x i8> %1, <vscale x 16 x i1> %2)
  ret <vscale x 16 x i8> %a
}

declare <vscale x 32 x i8> @llvm.riscv.vadc.vvm.u8m4(<vscale x 32 x i8>, <vscale x 32 x i8>, <vscale x 32 x i1>);
define <vscale x 32 x i8> @vadc_vvm_u8m4(<vscale x 32 x i8> %0, <vscale x 32 x i8> %1, <vscale x 32 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u8m4
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i8> @llvm.riscv.vadc.vvm.u8m4(<vscale x 32 x i8> %0, <vscale x 32 x i8> %1, <vscale x 32 x i1> %2)
  ret <vscale x 32 x i8> %a
}

declare <vscale x 64 x i8> @llvm.riscv.vadc.vvm.u8m8(<vscale x 64 x i8>, <vscale x 64 x i8>, <vscale x 64 x i1>);
define <vscale x 64 x i8> @vadc_vvm_u8m8(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1, <vscale x 64 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u8m8
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 64 x i8> @llvm.riscv.vadc.vvm.u8m8(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1, <vscale x 64 x i1> %2)
  ret <vscale x 64 x i8> %a
}

declare <vscale x 1 x i16> @llvm.riscv.vadc.vvm.u16mf4(<vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i1>);
define <vscale x 1 x i16> @vadc_vvm_u16mf4(<vscale x 1 x i16> %0, <vscale x 1 x i16> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u16mf4
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vadc.vvm.u16mf4(<vscale x 1 x i16> %0, <vscale x 1 x i16> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vadc.vvm.u16mf2(<vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i1>);
define <vscale x 2 x i16> @vadc_vvm_u16mf2(<vscale x 2 x i16> %0, <vscale x 2 x i16> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u16mf2
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vadc.vvm.u16mf2(<vscale x 2 x i16> %0, <vscale x 2 x i16> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vadc.vvm.u16m1(<vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i1>);
define <vscale x 4 x i16> @vadc_vvm_u16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u16m1
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vadc.vvm.u16m1(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vadc.vvm.u16m2(<vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i1>);
define <vscale x 8 x i16> @vadc_vvm_u16m2(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u16m2
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vadc.vvm.u16m2(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vadc.vvm.u16m4(<vscale x 16 x i16>, <vscale x 16 x i16>, <vscale x 16 x i1>);
define <vscale x 16 x i16> @vadc_vvm_u16m4(<vscale x 16 x i16> %0, <vscale x 16 x i16> %1, <vscale x 16 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u16m4
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vadc.vvm.u16m4(<vscale x 16 x i16> %0, <vscale x 16 x i16> %1, <vscale x 16 x i1> %2)
  ret <vscale x 16 x i16> %a
}

declare <vscale x 32 x i16> @llvm.riscv.vadc.vvm.u16m8(<vscale x 32 x i16>, <vscale x 32 x i16>, <vscale x 32 x i1>);
define <vscale x 32 x i16> @vadc_vvm_u16m8(<vscale x 32 x i16> %0, <vscale x 32 x i16> %1, <vscale x 32 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u16m8
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i16> @llvm.riscv.vadc.vvm.u16m8(<vscale x 32 x i16> %0, <vscale x 32 x i16> %1, <vscale x 32 x i1> %2)
  ret <vscale x 32 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vadc.vvm.u32mf2(<vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i1>);
define <vscale x 1 x i32> @vadc_vvm_u32mf2(<vscale x 1 x i32> %0, <vscale x 1 x i32> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u32mf2
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vadc.vvm.u32mf2(<vscale x 1 x i32> %0, <vscale x 1 x i32> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vadc.vvm.u32m1(<vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i1>);
define <vscale x 2 x i32> @vadc_vvm_u32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u32m1
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vadc.vvm.u32m1(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vadc.vvm.u32m2(<vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i1>);
define <vscale x 4 x i32> @vadc_vvm_u32m2(<vscale x 4 x i32> %0, <vscale x 4 x i32> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u32m2
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vadc.vvm.u32m2(<vscale x 4 x i32> %0, <vscale x 4 x i32> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vadc.vvm.u32m4(<vscale x 8 x i32>, <vscale x 8 x i32>, <vscale x 8 x i1>);
define <vscale x 8 x i32> @vadc_vvm_u32m4(<vscale x 8 x i32> %0, <vscale x 8 x i32> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u32m4
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vadc.vvm.u32m4(<vscale x 8 x i32> %0, <vscale x 8 x i32> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i32> %a
}

declare <vscale x 16 x i32> @llvm.riscv.vadc.vvm.u32m8(<vscale x 16 x i32>, <vscale x 16 x i32>, <vscale x 16 x i1>);
define <vscale x 16 x i32> @vadc_vvm_u32m8(<vscale x 16 x i32> %0, <vscale x 16 x i32> %1, <vscale x 16 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u32m8
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i32> @llvm.riscv.vadc.vvm.u32m8(<vscale x 16 x i32> %0, <vscale x 16 x i32> %1, <vscale x 16 x i1> %2)
  ret <vscale x 16 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vadc.vvm.u64m1(<vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i1>);
define <vscale x 1 x i64> @vadc_vvm_u64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u64m1
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i64> @llvm.riscv.vadc.vvm.u64m1(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i64> %a
}

declare <vscale x 2 x i64> @llvm.riscv.vadc.vvm.u64m2(<vscale x 2 x i64>, <vscale x 2 x i64>, <vscale x 2 x i1>);
define <vscale x 2 x i64> @vadc_vvm_u64m2(<vscale x 2 x i64> %0, <vscale x 2 x i64> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u64m2
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i64> @llvm.riscv.vadc.vvm.u64m2(<vscale x 2 x i64> %0, <vscale x 2 x i64> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i64> %a
}

declare <vscale x 4 x i64> @llvm.riscv.vadc.vvm.u64m4(<vscale x 4 x i64>, <vscale x 4 x i64>, <vscale x 4 x i1>);
define <vscale x 4 x i64> @vadc_vvm_u64m4(<vscale x 4 x i64> %0, <vscale x 4 x i64> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u64m4
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i64> @llvm.riscv.vadc.vvm.u64m4(<vscale x 4 x i64> %0, <vscale x 4 x i64> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i64> %a
}

declare <vscale x 8 x i64> @llvm.riscv.vadc.vvm.u64m8(<vscale x 8 x i64>, <vscale x 8 x i64>, <vscale x 8 x i1>);
define <vscale x 8 x i64> @vadc_vvm_u64m8(<vscale x 8 x i64> %0, <vscale x 8 x i64> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vadc_vvm_u64m8
  ; CHECK: vadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i64> @llvm.riscv.vadc.vvm.u64m8(<vscale x 8 x i64> %0, <vscale x 8 x i64> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i64> %a
}

