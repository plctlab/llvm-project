; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 1 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.i32mf2(<vscale x 1 x half>);
define <vscale x 1 x i32> @vfwcvt_rtz_x_f_v_i32mf2(<vscale x 1 x half> %0) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i32mf2
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.i32mf2(<vscale x 1 x half> %0)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.i32m1(<vscale x 2 x half>);
define <vscale x 2 x i32> @vfwcvt_rtz_x_f_v_i32m1(<vscale x 2 x half> %0) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i32m1
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.i32m1(<vscale x 2 x half> %0)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.i32m2(<vscale x 4 x half>);
define <vscale x 4 x i32> @vfwcvt_rtz_x_f_v_i32m2(<vscale x 4 x half> %0) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i32m2
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.i32m2(<vscale x 4 x half> %0)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.i32m4(<vscale x 8 x half>);
define <vscale x 8 x i32> @vfwcvt_rtz_x_f_v_i32m4(<vscale x 8 x half> %0) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i32m4
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.i32m4(<vscale x 8 x half> %0)
  ret <vscale x 8 x i32> %a
}

declare <vscale x 16 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.i32m8(<vscale x 16 x half>);
define <vscale x 16 x i32> @vfwcvt_rtz_x_f_v_i32m8(<vscale x 16 x half> %0) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i32m8
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.i32m8(<vscale x 16 x half> %0)
  ret <vscale x 16 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.i64m1(<vscale x 1 x float>);
define <vscale x 1 x i64> @vfwcvt_rtz_x_f_v_i64m1(<vscale x 1 x float> %0) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i64m1
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.i64m1(<vscale x 1 x float> %0)
  ret <vscale x 1 x i64> %a
}

declare <vscale x 2 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.i64m2(<vscale x 2 x float>);
define <vscale x 2 x i64> @vfwcvt_rtz_x_f_v_i64m2(<vscale x 2 x float> %0) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i64m2
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.i64m2(<vscale x 2 x float> %0)
  ret <vscale x 2 x i64> %a
}

declare <vscale x 4 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.i64m4(<vscale x 4 x float>);
define <vscale x 4 x i64> @vfwcvt_rtz_x_f_v_i64m4(<vscale x 4 x float> %0) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i64m4
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.i64m4(<vscale x 4 x float> %0)
  ret <vscale x 4 x i64> %a
}

declare <vscale x 8 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.i64m8(<vscale x 8 x float>);
define <vscale x 8 x i64> @vfwcvt_rtz_x_f_v_i64m8(<vscale x 8 x float> %0) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i64m8
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.i64m8(<vscale x 8 x float> %0)
  ret <vscale x 8 x i64> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i32mf2(<vscale x 1 x i1>, <vscale x 1 x i32>, <vscale x 1 x half>);
define <vscale x 1 x i32> @vfwcvt_rtz_x_f_v_i32mf2_m(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1, <vscale x 1 x half> %2) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i32mf2_m
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i32mf2(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1, <vscale x 1 x half> %2)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i32m1(<vscale x 2 x i1>, <vscale x 2 x i32>, <vscale x 2 x half>);
define <vscale x 2 x i32> @vfwcvt_rtz_x_f_v_i32m1_m(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1, <vscale x 2 x half> %2) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i32m1_m
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i32m1(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1, <vscale x 2 x half> %2)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i32m2(<vscale x 4 x i1>, <vscale x 4 x i32>, <vscale x 4 x half>);
define <vscale x 4 x i32> @vfwcvt_rtz_x_f_v_i32m2_m(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x half> %2) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i32m2_m
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i32m2(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x half> %2)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i32m4(<vscale x 8 x i1>, <vscale x 8 x i32>, <vscale x 8 x half>);
define <vscale x 8 x i32> @vfwcvt_rtz_x_f_v_i32m4_m(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1, <vscale x 8 x half> %2) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i32m4_m
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i32m4(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1, <vscale x 8 x half> %2)
  ret <vscale x 8 x i32> %a
}

declare <vscale x 16 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i32m8(<vscale x 16 x i1>, <vscale x 16 x i32>, <vscale x 16 x half>);
define <vscale x 16 x i32> @vfwcvt_rtz_x_f_v_i32m8_m(<vscale x 16 x i1> %0, <vscale x 16 x i32> %1, <vscale x 16 x half> %2) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i32m8_m
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i32> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i32m8(<vscale x 16 x i1> %0, <vscale x 16 x i32> %1, <vscale x 16 x half> %2)
  ret <vscale x 16 x i32> %a
}

declare <vscale x 1 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i64m1(<vscale x 1 x i1>, <vscale x 1 x i64>, <vscale x 1 x float>);
define <vscale x 1 x i64> @vfwcvt_rtz_x_f_v_i64m1_m(<vscale x 1 x i1> %0, <vscale x 1 x i64> %1, <vscale x 1 x float> %2) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i64m1_m
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i64m1(<vscale x 1 x i1> %0, <vscale x 1 x i64> %1, <vscale x 1 x float> %2)
  ret <vscale x 1 x i64> %a
}

declare <vscale x 2 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i64m2(<vscale x 2 x i1>, <vscale x 2 x i64>, <vscale x 2 x float>);
define <vscale x 2 x i64> @vfwcvt_rtz_x_f_v_i64m2_m(<vscale x 2 x i1> %0, <vscale x 2 x i64> %1, <vscale x 2 x float> %2) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i64m2_m
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i64m2(<vscale x 2 x i1> %0, <vscale x 2 x i64> %1, <vscale x 2 x float> %2)
  ret <vscale x 2 x i64> %a
}

declare <vscale x 4 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i64m4(<vscale x 4 x i1>, <vscale x 4 x i64>, <vscale x 4 x float>);
define <vscale x 4 x i64> @vfwcvt_rtz_x_f_v_i64m4_m(<vscale x 4 x i1> %0, <vscale x 4 x i64> %1, <vscale x 4 x float> %2) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i64m4_m
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i64m4(<vscale x 4 x i1> %0, <vscale x 4 x i64> %1, <vscale x 4 x float> %2)
  ret <vscale x 4 x i64> %a
}

declare <vscale x 8 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i64m8(<vscale x 8 x i1>, <vscale x 8 x i64>, <vscale x 8 x float>);
define <vscale x 8 x i64> @vfwcvt_rtz_x_f_v_i64m8_m(<vscale x 8 x i1> %0, <vscale x 8 x i64> %1, <vscale x 8 x float> %2) {
entry:
  ; CHECK-LABEL: vfwcvt_rtz_x_f_v_i64m8_m
  ; CHECK: vfwcvt.rtz.x.f.v v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i64> @llvm.riscv.vfwcvt.rtz.x.f.v.mask.i64m8(<vscale x 8 x i1> %0, <vscale x 8 x i64> %1, <vscale x 8 x float> %2)
  ret <vscale x 8 x i64> %a
}

