; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.i8mf8.b64(<vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i1>);
define <vscale x 1 x i1> @vmadc_vvm_i8mf8_b64(<vscale x 1 x i8> %0, <vscale x 1 x i8> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i8mf8_b64
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.i8mf8.b64(<vscale x 1 x i8> %0, <vscale x 1 x i8> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.i8mf4.b32(<vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i1>);
define <vscale x 2 x i1> @vmadc_vvm_i8mf4_b32(<vscale x 2 x i8> %0, <vscale x 2 x i8> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i8mf4_b32
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.i8mf4.b32(<vscale x 2 x i8> %0, <vscale x 2 x i8> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.i8mf2.b16(<vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i1>);
define <vscale x 4 x i1> @vmadc_vvm_i8mf2_b16(<vscale x 4 x i8> %0, <vscale x 4 x i8> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i8mf2_b16
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.i8mf2.b16(<vscale x 4 x i8> %0, <vscale x 4 x i8> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.i8m1.b8(<vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i1>);
define <vscale x 8 x i1> @vmadc_vvm_i8m1_b8(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i8m1_b8
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.i8m1.b8(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.i8m2.b4(<vscale x 16 x i8>, <vscale x 16 x i8>, <vscale x 16 x i1>);
define <vscale x 16 x i1> @vmadc_vvm_i8m2_b4(<vscale x 16 x i8> %0, <vscale x 16 x i8> %1, <vscale x 16 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i8m2_b4
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.i8m2.b4(<vscale x 16 x i8> %0, <vscale x 16 x i8> %1, <vscale x 16 x i1> %2)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 32 x i1> @llvm.riscv.vmadc.vvm.i8m4.b2(<vscale x 32 x i8>, <vscale x 32 x i8>, <vscale x 32 x i1>);
define <vscale x 32 x i1> @vmadc_vvm_i8m4_b2(<vscale x 32 x i8> %0, <vscale x 32 x i8> %1, <vscale x 32 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i8m4_b2
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i1> @llvm.riscv.vmadc.vvm.i8m4.b2(<vscale x 32 x i8> %0, <vscale x 32 x i8> %1, <vscale x 32 x i1> %2)
  ret <vscale x 32 x i1> %a
}

declare <vscale x 64 x i1> @llvm.riscv.vmadc.vvm.i8m8.b1(<vscale x 64 x i8>, <vscale x 64 x i8>, <vscale x 64 x i1>);
define <vscale x 64 x i1> @vmadc_vvm_i8m8_b1(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1, <vscale x 64 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i8m8_b1
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 64 x i1> @llvm.riscv.vmadc.vvm.i8m8.b1(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1, <vscale x 64 x i1> %2)
  ret <vscale x 64 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.i16mf4.b64(<vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i1>);
define <vscale x 1 x i1> @vmadc_vvm_i16mf4_b64(<vscale x 1 x i16> %0, <vscale x 1 x i16> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i16mf4_b64
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.i16mf4.b64(<vscale x 1 x i16> %0, <vscale x 1 x i16> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.i16mf2.b32(<vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i1>);
define <vscale x 2 x i1> @vmadc_vvm_i16mf2_b32(<vscale x 2 x i16> %0, <vscale x 2 x i16> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i16mf2_b32
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.i16mf2.b32(<vscale x 2 x i16> %0, <vscale x 2 x i16> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.i16m1.b16(<vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i1>);
define <vscale x 4 x i1> @vmadc_vvm_i16m1_b16(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i16m1_b16
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.i16m1.b16(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.i16m2.b8(<vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i1>);
define <vscale x 8 x i1> @vmadc_vvm_i16m2_b8(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i16m2_b8
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.i16m2.b8(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.i16m4.b4(<vscale x 16 x i16>, <vscale x 16 x i16>, <vscale x 16 x i1>);
define <vscale x 16 x i1> @vmadc_vvm_i16m4_b4(<vscale x 16 x i16> %0, <vscale x 16 x i16> %1, <vscale x 16 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i16m4_b4
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.i16m4.b4(<vscale x 16 x i16> %0, <vscale x 16 x i16> %1, <vscale x 16 x i1> %2)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 32 x i1> @llvm.riscv.vmadc.vvm.i16m8.b2(<vscale x 32 x i16>, <vscale x 32 x i16>, <vscale x 32 x i1>);
define <vscale x 32 x i1> @vmadc_vvm_i16m8_b2(<vscale x 32 x i16> %0, <vscale x 32 x i16> %1, <vscale x 32 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i16m8_b2
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i1> @llvm.riscv.vmadc.vvm.i16m8.b2(<vscale x 32 x i16> %0, <vscale x 32 x i16> %1, <vscale x 32 x i1> %2)
  ret <vscale x 32 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.i32mf2.b64(<vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i1>);
define <vscale x 1 x i1> @vmadc_vvm_i32mf2_b64(<vscale x 1 x i32> %0, <vscale x 1 x i32> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i32mf2_b64
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.i32mf2.b64(<vscale x 1 x i32> %0, <vscale x 1 x i32> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.i32m1.b32(<vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i1>);
define <vscale x 2 x i1> @vmadc_vvm_i32m1_b32(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i32m1_b32
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.i32m1.b32(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.i32m2.b16(<vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i1>);
define <vscale x 4 x i1> @vmadc_vvm_i32m2_b16(<vscale x 4 x i32> %0, <vscale x 4 x i32> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i32m2_b16
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.i32m2.b16(<vscale x 4 x i32> %0, <vscale x 4 x i32> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.i32m4.b8(<vscale x 8 x i32>, <vscale x 8 x i32>, <vscale x 8 x i1>);
define <vscale x 8 x i1> @vmadc_vvm_i32m4_b8(<vscale x 8 x i32> %0, <vscale x 8 x i32> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i32m4_b8
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.i32m4.b8(<vscale x 8 x i32> %0, <vscale x 8 x i32> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.i32m8.b4(<vscale x 16 x i32>, <vscale x 16 x i32>, <vscale x 16 x i1>);
define <vscale x 16 x i1> @vmadc_vvm_i32m8_b4(<vscale x 16 x i32> %0, <vscale x 16 x i32> %1, <vscale x 16 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i32m8_b4
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.i32m8.b4(<vscale x 16 x i32> %0, <vscale x 16 x i32> %1, <vscale x 16 x i1> %2)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.i64m1.b64(<vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i1>);
define <vscale x 1 x i1> @vmadc_vvm_i64m1_b64(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i64m1_b64
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.i64m1.b64(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.i64m2.b32(<vscale x 2 x i64>, <vscale x 2 x i64>, <vscale x 2 x i1>);
define <vscale x 2 x i1> @vmadc_vvm_i64m2_b32(<vscale x 2 x i64> %0, <vscale x 2 x i64> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i64m2_b32
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.i64m2.b32(<vscale x 2 x i64> %0, <vscale x 2 x i64> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.i64m4.b16(<vscale x 4 x i64>, <vscale x 4 x i64>, <vscale x 4 x i1>);
define <vscale x 4 x i1> @vmadc_vvm_i64m4_b16(<vscale x 4 x i64> %0, <vscale x 4 x i64> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i64m4_b16
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.i64m4.b16(<vscale x 4 x i64> %0, <vscale x 4 x i64> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.i64m8.b8(<vscale x 8 x i64>, <vscale x 8 x i64>, <vscale x 8 x i1>);
define <vscale x 8 x i1> @vmadc_vvm_i64m8_b8(<vscale x 8 x i64> %0, <vscale x 8 x i64> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_i64m8_b8
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.i64m8.b8(<vscale x 8 x i64> %0, <vscale x 8 x i64> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.u8mf8.b64(<vscale x 1 x i8>, <vscale x 1 x i8>, <vscale x 1 x i1>);
define <vscale x 1 x i1> @vmadc_vvm_u8mf8_b64(<vscale x 1 x i8> %0, <vscale x 1 x i8> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u8mf8_b64
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.u8mf8.b64(<vscale x 1 x i8> %0, <vscale x 1 x i8> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.u8mf4.b32(<vscale x 2 x i8>, <vscale x 2 x i8>, <vscale x 2 x i1>);
define <vscale x 2 x i1> @vmadc_vvm_u8mf4_b32(<vscale x 2 x i8> %0, <vscale x 2 x i8> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u8mf4_b32
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.u8mf4.b32(<vscale x 2 x i8> %0, <vscale x 2 x i8> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.u8mf2.b16(<vscale x 4 x i8>, <vscale x 4 x i8>, <vscale x 4 x i1>);
define <vscale x 4 x i1> @vmadc_vvm_u8mf2_b16(<vscale x 4 x i8> %0, <vscale x 4 x i8> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u8mf2_b16
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.u8mf2.b16(<vscale x 4 x i8> %0, <vscale x 4 x i8> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.u8m1.b8(<vscale x 8 x i8>, <vscale x 8 x i8>, <vscale x 8 x i1>);
define <vscale x 8 x i1> @vmadc_vvm_u8m1_b8(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u8m1_b8
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.u8m1.b8(<vscale x 8 x i8> %0, <vscale x 8 x i8> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.u8m2.b4(<vscale x 16 x i8>, <vscale x 16 x i8>, <vscale x 16 x i1>);
define <vscale x 16 x i1> @vmadc_vvm_u8m2_b4(<vscale x 16 x i8> %0, <vscale x 16 x i8> %1, <vscale x 16 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u8m2_b4
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.u8m2.b4(<vscale x 16 x i8> %0, <vscale x 16 x i8> %1, <vscale x 16 x i1> %2)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 32 x i1> @llvm.riscv.vmadc.vvm.u8m4.b2(<vscale x 32 x i8>, <vscale x 32 x i8>, <vscale x 32 x i1>);
define <vscale x 32 x i1> @vmadc_vvm_u8m4_b2(<vscale x 32 x i8> %0, <vscale x 32 x i8> %1, <vscale x 32 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u8m4_b2
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i1> @llvm.riscv.vmadc.vvm.u8m4.b2(<vscale x 32 x i8> %0, <vscale x 32 x i8> %1, <vscale x 32 x i1> %2)
  ret <vscale x 32 x i1> %a
}

declare <vscale x 64 x i1> @llvm.riscv.vmadc.vvm.u8m8.b1(<vscale x 64 x i8>, <vscale x 64 x i8>, <vscale x 64 x i1>);
define <vscale x 64 x i1> @vmadc_vvm_u8m8_b1(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1, <vscale x 64 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u8m8_b1
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 64 x i1> @llvm.riscv.vmadc.vvm.u8m8.b1(<vscale x 64 x i8> %0, <vscale x 64 x i8> %1, <vscale x 64 x i1> %2)
  ret <vscale x 64 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.u16mf4.b64(<vscale x 1 x i16>, <vscale x 1 x i16>, <vscale x 1 x i1>);
define <vscale x 1 x i1> @vmadc_vvm_u16mf4_b64(<vscale x 1 x i16> %0, <vscale x 1 x i16> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u16mf4_b64
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.u16mf4.b64(<vscale x 1 x i16> %0, <vscale x 1 x i16> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.u16mf2.b32(<vscale x 2 x i16>, <vscale x 2 x i16>, <vscale x 2 x i1>);
define <vscale x 2 x i1> @vmadc_vvm_u16mf2_b32(<vscale x 2 x i16> %0, <vscale x 2 x i16> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u16mf2_b32
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.u16mf2.b32(<vscale x 2 x i16> %0, <vscale x 2 x i16> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.u16m1.b16(<vscale x 4 x i16>, <vscale x 4 x i16>, <vscale x 4 x i1>);
define <vscale x 4 x i1> @vmadc_vvm_u16m1_b16(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u16m1_b16
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.u16m1.b16(<vscale x 4 x i16> %0, <vscale x 4 x i16> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.u16m2.b8(<vscale x 8 x i16>, <vscale x 8 x i16>, <vscale x 8 x i1>);
define <vscale x 8 x i1> @vmadc_vvm_u16m2_b8(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u16m2_b8
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.u16m2.b8(<vscale x 8 x i16> %0, <vscale x 8 x i16> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.u16m4.b4(<vscale x 16 x i16>, <vscale x 16 x i16>, <vscale x 16 x i1>);
define <vscale x 16 x i1> @vmadc_vvm_u16m4_b4(<vscale x 16 x i16> %0, <vscale x 16 x i16> %1, <vscale x 16 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u16m4_b4
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.u16m4.b4(<vscale x 16 x i16> %0, <vscale x 16 x i16> %1, <vscale x 16 x i1> %2)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 32 x i1> @llvm.riscv.vmadc.vvm.u16m8.b2(<vscale x 32 x i16>, <vscale x 32 x i16>, <vscale x 32 x i1>);
define <vscale x 32 x i1> @vmadc_vvm_u16m8_b2(<vscale x 32 x i16> %0, <vscale x 32 x i16> %1, <vscale x 32 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u16m8_b2
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i1> @llvm.riscv.vmadc.vvm.u16m8.b2(<vscale x 32 x i16> %0, <vscale x 32 x i16> %1, <vscale x 32 x i1> %2)
  ret <vscale x 32 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.u32mf2.b64(<vscale x 1 x i32>, <vscale x 1 x i32>, <vscale x 1 x i1>);
define <vscale x 1 x i1> @vmadc_vvm_u32mf2_b64(<vscale x 1 x i32> %0, <vscale x 1 x i32> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u32mf2_b64
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.u32mf2.b64(<vscale x 1 x i32> %0, <vscale x 1 x i32> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.u32m1.b32(<vscale x 2 x i32>, <vscale x 2 x i32>, <vscale x 2 x i1>);
define <vscale x 2 x i1> @vmadc_vvm_u32m1_b32(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u32m1_b32
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.u32m1.b32(<vscale x 2 x i32> %0, <vscale x 2 x i32> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.u32m2.b16(<vscale x 4 x i32>, <vscale x 4 x i32>, <vscale x 4 x i1>);
define <vscale x 4 x i1> @vmadc_vvm_u32m2_b16(<vscale x 4 x i32> %0, <vscale x 4 x i32> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u32m2_b16
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.u32m2.b16(<vscale x 4 x i32> %0, <vscale x 4 x i32> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.u32m4.b8(<vscale x 8 x i32>, <vscale x 8 x i32>, <vscale x 8 x i1>);
define <vscale x 8 x i1> @vmadc_vvm_u32m4_b8(<vscale x 8 x i32> %0, <vscale x 8 x i32> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u32m4_b8
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.u32m4.b8(<vscale x 8 x i32> %0, <vscale x 8 x i32> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.u32m8.b4(<vscale x 16 x i32>, <vscale x 16 x i32>, <vscale x 16 x i1>);
define <vscale x 16 x i1> @vmadc_vvm_u32m8_b4(<vscale x 16 x i32> %0, <vscale x 16 x i32> %1, <vscale x 16 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u32m8_b4
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmadc.vvm.u32m8.b4(<vscale x 16 x i32> %0, <vscale x 16 x i32> %1, <vscale x 16 x i1> %2)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.u64m1.b64(<vscale x 1 x i64>, <vscale x 1 x i64>, <vscale x 1 x i1>);
define <vscale x 1 x i1> @vmadc_vvm_u64m1_b64(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1, <vscale x 1 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u64m1_b64
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmadc.vvm.u64m1.b64(<vscale x 1 x i64> %0, <vscale x 1 x i64> %1, <vscale x 1 x i1> %2)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.u64m2.b32(<vscale x 2 x i64>, <vscale x 2 x i64>, <vscale x 2 x i1>);
define <vscale x 2 x i1> @vmadc_vvm_u64m2_b32(<vscale x 2 x i64> %0, <vscale x 2 x i64> %1, <vscale x 2 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u64m2_b32
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmadc.vvm.u64m2.b32(<vscale x 2 x i64> %0, <vscale x 2 x i64> %1, <vscale x 2 x i1> %2)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.u64m4.b16(<vscale x 4 x i64>, <vscale x 4 x i64>, <vscale x 4 x i1>);
define <vscale x 4 x i1> @vmadc_vvm_u64m4_b16(<vscale x 4 x i64> %0, <vscale x 4 x i64> %1, <vscale x 4 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u64m4_b16
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmadc.vvm.u64m4.b16(<vscale x 4 x i64> %0, <vscale x 4 x i64> %1, <vscale x 4 x i1> %2)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.u64m8.b8(<vscale x 8 x i64>, <vscale x 8 x i64>, <vscale x 8 x i1>);
define <vscale x 8 x i1> @vmadc_vvm_u64m8_b8(<vscale x 8 x i64> %0, <vscale x 8 x i64> %1, <vscale x 8 x i1> %2) {
entry:
  ; CHECK-LABEL: vmadc_vvm_u64m8_b8
  ; CHECK: vmadc.vvm v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmadc.vvm.u64m8.b8(<vscale x 8 x i64> %0, <vscale x 8 x i64> %1, <vscale x 8 x i1> %2)
  ret <vscale x 8 x i1> %a
}

