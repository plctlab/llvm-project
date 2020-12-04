; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 1 x i16> @llvm.riscv.vfncvt.xu.f.w.u16mf4(<vscale x 1 x float>);
define <vscale x 1 x i16> @vfncvt_xu_f_w_u16mf4(<vscale x 1 x float> %0) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u16mf4
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vfncvt.xu.f.w.u16mf4(<vscale x 1 x float> %0)
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vfncvt.xu.f.w.u16mf2(<vscale x 2 x float>);
define <vscale x 2 x i16> @vfncvt_xu_f_w_u16mf2(<vscale x 2 x float> %0) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u16mf2
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vfncvt.xu.f.w.u16mf2(<vscale x 2 x float> %0)
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vfncvt.xu.f.w.u16m1(<vscale x 4 x float>);
define <vscale x 4 x i16> @vfncvt_xu_f_w_u16m1(<vscale x 4 x float> %0) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u16m1
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vfncvt.xu.f.w.u16m1(<vscale x 4 x float> %0)
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vfncvt.xu.f.w.u16m2(<vscale x 8 x float>);
define <vscale x 8 x i16> @vfncvt_xu_f_w_u16m2(<vscale x 8 x float> %0) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u16m2
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vfncvt.xu.f.w.u16m2(<vscale x 8 x float> %0)
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vfncvt.xu.f.w.u16m4(<vscale x 16 x float>);
define <vscale x 16 x i16> @vfncvt_xu_f_w_u16m4(<vscale x 16 x float> %0) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u16m4
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vfncvt.xu.f.w.u16m4(<vscale x 16 x float> %0)
  ret <vscale x 16 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vfncvt.xu.f.w.u32mf2(<vscale x 1 x double>);
define <vscale x 1 x i32> @vfncvt_xu_f_w_u32mf2(<vscale x 1 x double> %0) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u32mf2
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vfncvt.xu.f.w.u32mf2(<vscale x 1 x double> %0)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vfncvt.xu.f.w.u32m1(<vscale x 2 x double>);
define <vscale x 2 x i32> @vfncvt_xu_f_w_u32m1(<vscale x 2 x double> %0) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u32m1
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vfncvt.xu.f.w.u32m1(<vscale x 2 x double> %0)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vfncvt.xu.f.w.u32m2(<vscale x 4 x double>);
define <vscale x 4 x i32> @vfncvt_xu_f_w_u32m2(<vscale x 4 x double> %0) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u32m2
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vfncvt.xu.f.w.u32m2(<vscale x 4 x double> %0)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vfncvt.xu.f.w.u32m4(<vscale x 8 x double>);
define <vscale x 8 x i32> @vfncvt_xu_f_w_u32m4(<vscale x 8 x double> %0) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u32m4
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vfncvt.xu.f.w.u32m4(<vscale x 8 x double> %0)
  ret <vscale x 8 x i32> %a
}

declare <vscale x 1 x i16> @llvm.riscv.vfncvt.xu.f.w.mask.u16mf4(<vscale x 1 x i1>, <vscale x 1 x i16>, <vscale x 1 x float>);
define <vscale x 1 x i16> @vfncvt_xu_f_w_u16mf4_m(<vscale x 1 x i1> %0, <vscale x 1 x i16> %1, <vscale x 1 x float> %2) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u16mf4_m
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i16> @llvm.riscv.vfncvt.xu.f.w.mask.u16mf4(<vscale x 1 x i1> %0, <vscale x 1 x i16> %1, <vscale x 1 x float> %2)
  ret <vscale x 1 x i16> %a
}

declare <vscale x 2 x i16> @llvm.riscv.vfncvt.xu.f.w.mask.u16mf2(<vscale x 2 x i1>, <vscale x 2 x i16>, <vscale x 2 x float>);
define <vscale x 2 x i16> @vfncvt_xu_f_w_u16mf2_m(<vscale x 2 x i1> %0, <vscale x 2 x i16> %1, <vscale x 2 x float> %2) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u16mf2_m
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i16> @llvm.riscv.vfncvt.xu.f.w.mask.u16mf2(<vscale x 2 x i1> %0, <vscale x 2 x i16> %1, <vscale x 2 x float> %2)
  ret <vscale x 2 x i16> %a
}

declare <vscale x 4 x i16> @llvm.riscv.vfncvt.xu.f.w.mask.u16m1(<vscale x 4 x i1>, <vscale x 4 x i16>, <vscale x 4 x float>);
define <vscale x 4 x i16> @vfncvt_xu_f_w_u16m1_m(<vscale x 4 x i1> %0, <vscale x 4 x i16> %1, <vscale x 4 x float> %2) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u16m1_m
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i16> @llvm.riscv.vfncvt.xu.f.w.mask.u16m1(<vscale x 4 x i1> %0, <vscale x 4 x i16> %1, <vscale x 4 x float> %2)
  ret <vscale x 4 x i16> %a
}

declare <vscale x 8 x i16> @llvm.riscv.vfncvt.xu.f.w.mask.u16m2(<vscale x 8 x i1>, <vscale x 8 x i16>, <vscale x 8 x float>);
define <vscale x 8 x i16> @vfncvt_xu_f_w_u16m2_m(<vscale x 8 x i1> %0, <vscale x 8 x i16> %1, <vscale x 8 x float> %2) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u16m2_m
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i16> @llvm.riscv.vfncvt.xu.f.w.mask.u16m2(<vscale x 8 x i1> %0, <vscale x 8 x i16> %1, <vscale x 8 x float> %2)
  ret <vscale x 8 x i16> %a
}

declare <vscale x 16 x i16> @llvm.riscv.vfncvt.xu.f.w.mask.u16m4(<vscale x 16 x i1>, <vscale x 16 x i16>, <vscale x 16 x float>);
define <vscale x 16 x i16> @vfncvt_xu_f_w_u16m4_m(<vscale x 16 x i1> %0, <vscale x 16 x i16> %1, <vscale x 16 x float> %2) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u16m4_m
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i16> @llvm.riscv.vfncvt.xu.f.w.mask.u16m4(<vscale x 16 x i1> %0, <vscale x 16 x i16> %1, <vscale x 16 x float> %2)
  ret <vscale x 16 x i16> %a
}

declare <vscale x 1 x i32> @llvm.riscv.vfncvt.xu.f.w.mask.u32mf2(<vscale x 1 x i1>, <vscale x 1 x i32>, <vscale x 1 x double>);
define <vscale x 1 x i32> @vfncvt_xu_f_w_u32mf2_m(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1, <vscale x 1 x double> %2) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u32mf2_m
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i32> @llvm.riscv.vfncvt.xu.f.w.mask.u32mf2(<vscale x 1 x i1> %0, <vscale x 1 x i32> %1, <vscale x 1 x double> %2)
  ret <vscale x 1 x i32> %a
}

declare <vscale x 2 x i32> @llvm.riscv.vfncvt.xu.f.w.mask.u32m1(<vscale x 2 x i1>, <vscale x 2 x i32>, <vscale x 2 x double>);
define <vscale x 2 x i32> @vfncvt_xu_f_w_u32m1_m(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1, <vscale x 2 x double> %2) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u32m1_m
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i32> @llvm.riscv.vfncvt.xu.f.w.mask.u32m1(<vscale x 2 x i1> %0, <vscale x 2 x i32> %1, <vscale x 2 x double> %2)
  ret <vscale x 2 x i32> %a
}

declare <vscale x 4 x i32> @llvm.riscv.vfncvt.xu.f.w.mask.u32m2(<vscale x 4 x i1>, <vscale x 4 x i32>, <vscale x 4 x double>);
define <vscale x 4 x i32> @vfncvt_xu_f_w_u32m2_m(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x double> %2) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u32m2_m
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i32> @llvm.riscv.vfncvt.xu.f.w.mask.u32m2(<vscale x 4 x i1> %0, <vscale x 4 x i32> %1, <vscale x 4 x double> %2)
  ret <vscale x 4 x i32> %a
}

declare <vscale x 8 x i32> @llvm.riscv.vfncvt.xu.f.w.mask.u32m4(<vscale x 8 x i1>, <vscale x 8 x i32>, <vscale x 8 x double>);
define <vscale x 8 x i32> @vfncvt_xu_f_w_u32m4_m(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1, <vscale x 8 x double> %2) {
entry:
  ; CHECK-LABEL: vfncvt_xu_f_w_u32m4_m
  ; CHECK: vfncvt.xu.f.w v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i32> @llvm.riscv.vfncvt.xu.f.w.mask.u32m4(<vscale x 8 x i1> %0, <vscale x 8 x i32> %1, <vscale x 8 x double> %2)
  ret <vscale x 8 x i32> %a
}

