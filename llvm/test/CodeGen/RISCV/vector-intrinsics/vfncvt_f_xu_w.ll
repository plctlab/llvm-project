; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 1 x half> @llvm.riscv.vfncvt.f.xu.w.f16mf4(<vscale x 1 x i32>);
define <vscale x 1 x half> @vfncvt_f_xu_w_f16mf4(<vscale x 1 x i32> %0) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f16mf4
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x half> @llvm.riscv.vfncvt.f.xu.w.f16mf4(<vscale x 1 x i32> %0)
  ret <vscale x 1 x half> %a
}

declare <vscale x 2 x half> @llvm.riscv.vfncvt.f.xu.w.f16mf2(<vscale x 2 x i32>);
define <vscale x 2 x half> @vfncvt_f_xu_w_f16mf2(<vscale x 2 x i32> %0) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f16mf2
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x half> @llvm.riscv.vfncvt.f.xu.w.f16mf2(<vscale x 2 x i32> %0)
  ret <vscale x 2 x half> %a
}

declare <vscale x 4 x half> @llvm.riscv.vfncvt.f.xu.w.f16m1(<vscale x 4 x i32>);
define <vscale x 4 x half> @vfncvt_f_xu_w_f16m1(<vscale x 4 x i32> %0) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f16m1
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x half> @llvm.riscv.vfncvt.f.xu.w.f16m1(<vscale x 4 x i32> %0)
  ret <vscale x 4 x half> %a
}

declare <vscale x 8 x half> @llvm.riscv.vfncvt.f.xu.w.f16m2(<vscale x 8 x i32>);
define <vscale x 8 x half> @vfncvt_f_xu_w_f16m2(<vscale x 8 x i32> %0) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f16m2
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x half> @llvm.riscv.vfncvt.f.xu.w.f16m2(<vscale x 8 x i32> %0)
  ret <vscale x 8 x half> %a
}

declare <vscale x 16 x half> @llvm.riscv.vfncvt.f.xu.w.f16m4(<vscale x 16 x i32>);
define <vscale x 16 x half> @vfncvt_f_xu_w_f16m4(<vscale x 16 x i32> %0) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f16m4
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x half> @llvm.riscv.vfncvt.f.xu.w.f16m4(<vscale x 16 x i32> %0)
  ret <vscale x 16 x half> %a
}

declare <vscale x 1 x float> @llvm.riscv.vfncvt.f.xu.w.f32mf2(<vscale x 1 x i64>);
define <vscale x 1 x float> @vfncvt_f_xu_w_f32mf2(<vscale x 1 x i64> %0) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f32mf2
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x float> @llvm.riscv.vfncvt.f.xu.w.f32mf2(<vscale x 1 x i64> %0)
  ret <vscale x 1 x float> %a
}

declare <vscale x 2 x float> @llvm.riscv.vfncvt.f.xu.w.f32m1(<vscale x 2 x i64>);
define <vscale x 2 x float> @vfncvt_f_xu_w_f32m1(<vscale x 2 x i64> %0) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f32m1
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x float> @llvm.riscv.vfncvt.f.xu.w.f32m1(<vscale x 2 x i64> %0)
  ret <vscale x 2 x float> %a
}

declare <vscale x 4 x float> @llvm.riscv.vfncvt.f.xu.w.f32m2(<vscale x 4 x i64>);
define <vscale x 4 x float> @vfncvt_f_xu_w_f32m2(<vscale x 4 x i64> %0) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f32m2
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x float> @llvm.riscv.vfncvt.f.xu.w.f32m2(<vscale x 4 x i64> %0)
  ret <vscale x 4 x float> %a
}

declare <vscale x 8 x float> @llvm.riscv.vfncvt.f.xu.w.f32m4(<vscale x 8 x i64>);
define <vscale x 8 x float> @vfncvt_f_xu_w_f32m4(<vscale x 8 x i64> %0) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f32m4
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x float> @llvm.riscv.vfncvt.f.xu.w.f32m4(<vscale x 8 x i64> %0)
  ret <vscale x 8 x float> %a
}

declare <vscale x 1 x half> @llvm.riscv.vfncvt.f.xu.w.mask.f16mf4(<vscale x 1 x i1>, <vscale x 1 x half>, <vscale x 1 x i32>);
define <vscale x 1 x half> @vfncvt_f_xu_w_f16mf4_m(<vscale x 1 x i1> %0, <vscale x 1 x half> %1, <vscale x 1 x i32> %2) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f16mf4_m
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x half> @llvm.riscv.vfncvt.f.xu.w.mask.f16mf4(<vscale x 1 x i1> %0, <vscale x 1 x half> %1, <vscale x 1 x i32> %2)
  ret <vscale x 1 x half> %a
}

declare <vscale x 2 x half> @llvm.riscv.vfncvt.f.xu.w.mask.f16mf2(<vscale x 2 x i1>, <vscale x 2 x half>, <vscale x 2 x i32>);
define <vscale x 2 x half> @vfncvt_f_xu_w_f16mf2_m(<vscale x 2 x i1> %0, <vscale x 2 x half> %1, <vscale x 2 x i32> %2) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f16mf2_m
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x half> @llvm.riscv.vfncvt.f.xu.w.mask.f16mf2(<vscale x 2 x i1> %0, <vscale x 2 x half> %1, <vscale x 2 x i32> %2)
  ret <vscale x 2 x half> %a
}

declare <vscale x 4 x half> @llvm.riscv.vfncvt.f.xu.w.mask.f16m1(<vscale x 4 x i1>, <vscale x 4 x half>, <vscale x 4 x i32>);
define <vscale x 4 x half> @vfncvt_f_xu_w_f16m1_m(<vscale x 4 x i1> %0, <vscale x 4 x half> %1, <vscale x 4 x i32> %2) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f16m1_m
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x half> @llvm.riscv.vfncvt.f.xu.w.mask.f16m1(<vscale x 4 x i1> %0, <vscale x 4 x half> %1, <vscale x 4 x i32> %2)
  ret <vscale x 4 x half> %a
}

declare <vscale x 8 x half> @llvm.riscv.vfncvt.f.xu.w.mask.f16m2(<vscale x 8 x i1>, <vscale x 8 x half>, <vscale x 8 x i32>);
define <vscale x 8 x half> @vfncvt_f_xu_w_f16m2_m(<vscale x 8 x i1> %0, <vscale x 8 x half> %1, <vscale x 8 x i32> %2) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f16m2_m
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x half> @llvm.riscv.vfncvt.f.xu.w.mask.f16m2(<vscale x 8 x i1> %0, <vscale x 8 x half> %1, <vscale x 8 x i32> %2)
  ret <vscale x 8 x half> %a
}

declare <vscale x 16 x half> @llvm.riscv.vfncvt.f.xu.w.mask.f16m4(<vscale x 16 x i1>, <vscale x 16 x half>, <vscale x 16 x i32>);
define <vscale x 16 x half> @vfncvt_f_xu_w_f16m4_m(<vscale x 16 x i1> %0, <vscale x 16 x half> %1, <vscale x 16 x i32> %2) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f16m4_m
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x half> @llvm.riscv.vfncvt.f.xu.w.mask.f16m4(<vscale x 16 x i1> %0, <vscale x 16 x half> %1, <vscale x 16 x i32> %2)
  ret <vscale x 16 x half> %a
}

declare <vscale x 1 x float> @llvm.riscv.vfncvt.f.xu.w.mask.f32mf2(<vscale x 1 x i1>, <vscale x 1 x float>, <vscale x 1 x i64>);
define <vscale x 1 x float> @vfncvt_f_xu_w_f32mf2_m(<vscale x 1 x i1> %0, <vscale x 1 x float> %1, <vscale x 1 x i64> %2) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f32mf2_m
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x float> @llvm.riscv.vfncvt.f.xu.w.mask.f32mf2(<vscale x 1 x i1> %0, <vscale x 1 x float> %1, <vscale x 1 x i64> %2)
  ret <vscale x 1 x float> %a
}

declare <vscale x 2 x float> @llvm.riscv.vfncvt.f.xu.w.mask.f32m1(<vscale x 2 x i1>, <vscale x 2 x float>, <vscale x 2 x i64>);
define <vscale x 2 x float> @vfncvt_f_xu_w_f32m1_m(<vscale x 2 x i1> %0, <vscale x 2 x float> %1, <vscale x 2 x i64> %2) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f32m1_m
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x float> @llvm.riscv.vfncvt.f.xu.w.mask.f32m1(<vscale x 2 x i1> %0, <vscale x 2 x float> %1, <vscale x 2 x i64> %2)
  ret <vscale x 2 x float> %a
}

declare <vscale x 4 x float> @llvm.riscv.vfncvt.f.xu.w.mask.f32m2(<vscale x 4 x i1>, <vscale x 4 x float>, <vscale x 4 x i64>);
define <vscale x 4 x float> @vfncvt_f_xu_w_f32m2_m(<vscale x 4 x i1> %0, <vscale x 4 x float> %1, <vscale x 4 x i64> %2) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f32m2_m
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x float> @llvm.riscv.vfncvt.f.xu.w.mask.f32m2(<vscale x 4 x i1> %0, <vscale x 4 x float> %1, <vscale x 4 x i64> %2)
  ret <vscale x 4 x float> %a
}

declare <vscale x 8 x float> @llvm.riscv.vfncvt.f.xu.w.mask.f32m4(<vscale x 8 x i1>, <vscale x 8 x float>, <vscale x 8 x i64>);
define <vscale x 8 x float> @vfncvt_f_xu_w_f32m4_m(<vscale x 8 x i1> %0, <vscale x 8 x float> %1, <vscale x 8 x i64> %2) {
entry:
  ; CHECK-LABEL: vfncvt_f_xu_w_f32m4_m
  ; CHECK: vfncvt.f.xu.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x float> @llvm.riscv.vfncvt.f.xu.w.mask.f32m4(<vscale x 8 x i1> %0, <vscale x 8 x float> %1, <vscale x 8 x i64> %2)
  ret <vscale x 8 x float> %a
}

