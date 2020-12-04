; RUN: llc -mtriple=riscv64 -mattr=+experimental-v < %s \
; RUN:   | FileCheck -check-prefix=CHECK %s

declare <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.f16mf4.b64(<vscale x 1 x half>, <vscale x 1 x half>);
define <vscale x 1 x i1> @vmfeq_vv_f16mf4_b64(<vscale x 1 x half> %0, <vscale x 1 x half> %1) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f16mf4_b64
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.f16mf4.b64(<vscale x 1 x half> %0, <vscale x 1 x half> %1)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.f16mf2.b32(<vscale x 2 x half>, <vscale x 2 x half>);
define <vscale x 2 x i1> @vmfeq_vv_f16mf2_b32(<vscale x 2 x half> %0, <vscale x 2 x half> %1) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f16mf2_b32
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.f16mf2.b32(<vscale x 2 x half> %0, <vscale x 2 x half> %1)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.f16m1.b16(<vscale x 4 x half>, <vscale x 4 x half>);
define <vscale x 4 x i1> @vmfeq_vv_f16m1_b16(<vscale x 4 x half> %0, <vscale x 4 x half> %1) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f16m1_b16
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.f16m1.b16(<vscale x 4 x half> %0, <vscale x 4 x half> %1)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.f16m2.b8(<vscale x 8 x half>, <vscale x 8 x half>);
define <vscale x 8 x i1> @vmfeq_vv_f16m2_b8(<vscale x 8 x half> %0, <vscale x 8 x half> %1) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f16m2_b8
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.f16m2.b8(<vscale x 8 x half> %0, <vscale x 8 x half> %1)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmfeq.vv.f16m4.b4(<vscale x 16 x half>, <vscale x 16 x half>);
define <vscale x 16 x i1> @vmfeq_vv_f16m4_b4(<vscale x 16 x half> %0, <vscale x 16 x half> %1) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f16m4_b4
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmfeq.vv.f16m4.b4(<vscale x 16 x half> %0, <vscale x 16 x half> %1)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 32 x i1> @llvm.riscv.vmfeq.vv.f16m8.b2(<vscale x 32 x half>, <vscale x 32 x half>);
define <vscale x 32 x i1> @vmfeq_vv_f16m8_b2(<vscale x 32 x half> %0, <vscale x 32 x half> %1) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f16m8_b2
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 32 x i1> @llvm.riscv.vmfeq.vv.f16m8.b2(<vscale x 32 x half> %0, <vscale x 32 x half> %1)
  ret <vscale x 32 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.f32mf2.b64(<vscale x 1 x float>, <vscale x 1 x float>);
define <vscale x 1 x i1> @vmfeq_vv_f32mf2_b64(<vscale x 1 x float> %0, <vscale x 1 x float> %1) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f32mf2_b64
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.f32mf2.b64(<vscale x 1 x float> %0, <vscale x 1 x float> %1)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.f32m1.b32(<vscale x 2 x float>, <vscale x 2 x float>);
define <vscale x 2 x i1> @vmfeq_vv_f32m1_b32(<vscale x 2 x float> %0, <vscale x 2 x float> %1) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f32m1_b32
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.f32m1.b32(<vscale x 2 x float> %0, <vscale x 2 x float> %1)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.f32m2.b16(<vscale x 4 x float>, <vscale x 4 x float>);
define <vscale x 4 x i1> @vmfeq_vv_f32m2_b16(<vscale x 4 x float> %0, <vscale x 4 x float> %1) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f32m2_b16
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.f32m2.b16(<vscale x 4 x float> %0, <vscale x 4 x float> %1)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.f32m4.b8(<vscale x 8 x float>, <vscale x 8 x float>);
define <vscale x 8 x i1> @vmfeq_vv_f32m4_b8(<vscale x 8 x float> %0, <vscale x 8 x float> %1) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f32m4_b8
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.f32m4.b8(<vscale x 8 x float> %0, <vscale x 8 x float> %1)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmfeq.vv.f32m8.b4(<vscale x 16 x float>, <vscale x 16 x float>);
define <vscale x 16 x i1> @vmfeq_vv_f32m8_b4(<vscale x 16 x float> %0, <vscale x 16 x float> %1) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f32m8_b4
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmfeq.vv.f32m8.b4(<vscale x 16 x float> %0, <vscale x 16 x float> %1)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.f64m1.b64(<vscale x 1 x double>, <vscale x 1 x double>);
define <vscale x 1 x i1> @vmfeq_vv_f64m1_b64(<vscale x 1 x double> %0, <vscale x 1 x double> %1) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f64m1_b64
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.f64m1.b64(<vscale x 1 x double> %0, <vscale x 1 x double> %1)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.f64m2.b32(<vscale x 2 x double>, <vscale x 2 x double>);
define <vscale x 2 x i1> @vmfeq_vv_f64m2_b32(<vscale x 2 x double> %0, <vscale x 2 x double> %1) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f64m2_b32
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.f64m2.b32(<vscale x 2 x double> %0, <vscale x 2 x double> %1)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.f64m4.b16(<vscale x 4 x double>, <vscale x 4 x double>);
define <vscale x 4 x i1> @vmfeq_vv_f64m4_b16(<vscale x 4 x double> %0, <vscale x 4 x double> %1) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f64m4_b16
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.f64m4.b16(<vscale x 4 x double> %0, <vscale x 4 x double> %1)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.f64m8.b8(<vscale x 8 x double>, <vscale x 8 x double>);
define <vscale x 8 x i1> @vmfeq_vv_f64m8_b8(<vscale x 8 x double> %0, <vscale x 8 x double> %1) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f64m8_b8
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.f64m8.b8(<vscale x 8 x double> %0, <vscale x 8 x double> %1)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.mask.f16mf4.b64(<vscale x 1 x i1>, <vscale x 1 x i1>, <vscale x 1 x half>, <vscale x 1 x half>);
define <vscale x 1 x i1> @vmfeq_vv_f16mf4_b64_m(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x half> %2, <vscale x 1 x half> %3) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f16mf4_b64_m
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.mask.f16mf4.b64(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x half> %2, <vscale x 1 x half> %3)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.mask.f16mf2.b32(<vscale x 2 x i1>, <vscale x 2 x i1>, <vscale x 2 x half>, <vscale x 2 x half>);
define <vscale x 2 x i1> @vmfeq_vv_f16mf2_b32_m(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x half> %2, <vscale x 2 x half> %3) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f16mf2_b32_m
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.mask.f16mf2.b32(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x half> %2, <vscale x 2 x half> %3)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.mask.f16m1.b16(<vscale x 4 x i1>, <vscale x 4 x i1>, <vscale x 4 x half>, <vscale x 4 x half>);
define <vscale x 4 x i1> @vmfeq_vv_f16m1_b16_m(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x half> %2, <vscale x 4 x half> %3) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f16m1_b16_m
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.mask.f16m1.b16(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x half> %2, <vscale x 4 x half> %3)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.mask.f16m2.b8(<vscale x 8 x i1>, <vscale x 8 x i1>, <vscale x 8 x half>, <vscale x 8 x half>);
define <vscale x 8 x i1> @vmfeq_vv_f16m2_b8_m(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x half> %2, <vscale x 8 x half> %3) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f16m2_b8_m
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.mask.f16m2.b8(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x half> %2, <vscale x 8 x half> %3)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmfeq.vv.mask.f16m4.b4(<vscale x 16 x i1>, <vscale x 16 x i1>, <vscale x 16 x half>, <vscale x 16 x half>);
define <vscale x 16 x i1> @vmfeq_vv_f16m4_b4_m(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x half> %2, <vscale x 16 x half> %3) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f16m4_b4_m
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmfeq.vv.mask.f16m4.b4(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x half> %2, <vscale x 16 x half> %3)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 32 x i1> @llvm.riscv.vmfeq.vv.mask.f16m8.b2(<vscale x 32 x i1>, <vscale x 32 x i1>, <vscale x 32 x half>, <vscale x 32 x half>);
define <vscale x 32 x i1> @vmfeq_vv_f16m8_b2_m(<vscale x 32 x i1> %0, <vscale x 32 x i1> %1, <vscale x 32 x half> %2, <vscale x 32 x half> %3) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f16m8_b2_m
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 32 x i1> @llvm.riscv.vmfeq.vv.mask.f16m8.b2(<vscale x 32 x i1> %0, <vscale x 32 x i1> %1, <vscale x 32 x half> %2, <vscale x 32 x half> %3)
  ret <vscale x 32 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.mask.f32mf2.b64(<vscale x 1 x i1>, <vscale x 1 x i1>, <vscale x 1 x float>, <vscale x 1 x float>);
define <vscale x 1 x i1> @vmfeq_vv_f32mf2_b64_m(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x float> %2, <vscale x 1 x float> %3) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f32mf2_b64_m
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.mask.f32mf2.b64(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x float> %2, <vscale x 1 x float> %3)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.mask.f32m1.b32(<vscale x 2 x i1>, <vscale x 2 x i1>, <vscale x 2 x float>, <vscale x 2 x float>);
define <vscale x 2 x i1> @vmfeq_vv_f32m1_b32_m(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x float> %2, <vscale x 2 x float> %3) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f32m1_b32_m
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.mask.f32m1.b32(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x float> %2, <vscale x 2 x float> %3)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.mask.f32m2.b16(<vscale x 4 x i1>, <vscale x 4 x i1>, <vscale x 4 x float>, <vscale x 4 x float>);
define <vscale x 4 x i1> @vmfeq_vv_f32m2_b16_m(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x float> %2, <vscale x 4 x float> %3) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f32m2_b16_m
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.mask.f32m2.b16(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x float> %2, <vscale x 4 x float> %3)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.mask.f32m4.b8(<vscale x 8 x i1>, <vscale x 8 x i1>, <vscale x 8 x float>, <vscale x 8 x float>);
define <vscale x 8 x i1> @vmfeq_vv_f32m4_b8_m(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x float> %2, <vscale x 8 x float> %3) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f32m4_b8_m
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.mask.f32m4.b8(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x float> %2, <vscale x 8 x float> %3)
  ret <vscale x 8 x i1> %a
}

declare <vscale x 16 x i1> @llvm.riscv.vmfeq.vv.mask.f32m8.b4(<vscale x 16 x i1>, <vscale x 16 x i1>, <vscale x 16 x float>, <vscale x 16 x float>);
define <vscale x 16 x i1> @vmfeq_vv_f32m8_b4_m(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x float> %2, <vscale x 16 x float> %3) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f32m8_b4_m
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 16 x i1> @llvm.riscv.vmfeq.vv.mask.f32m8.b4(<vscale x 16 x i1> %0, <vscale x 16 x i1> %1, <vscale x 16 x float> %2, <vscale x 16 x float> %3)
  ret <vscale x 16 x i1> %a
}

declare <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.mask.f64m1.b64(<vscale x 1 x i1>, <vscale x 1 x i1>, <vscale x 1 x double>, <vscale x 1 x double>);
define <vscale x 1 x i1> @vmfeq_vv_f64m1_b64_m(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x double> %2, <vscale x 1 x double> %3) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f64m1_b64_m
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 1 x i1> @llvm.riscv.vmfeq.vv.mask.f64m1.b64(<vscale x 1 x i1> %0, <vscale x 1 x i1> %1, <vscale x 1 x double> %2, <vscale x 1 x double> %3)
  ret <vscale x 1 x i1> %a
}

declare <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.mask.f64m2.b32(<vscale x 2 x i1>, <vscale x 2 x i1>, <vscale x 2 x double>, <vscale x 2 x double>);
define <vscale x 2 x i1> @vmfeq_vv_f64m2_b32_m(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x double> %2, <vscale x 2 x double> %3) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f64m2_b32_m
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 2 x i1> @llvm.riscv.vmfeq.vv.mask.f64m2.b32(<vscale x 2 x i1> %0, <vscale x 2 x i1> %1, <vscale x 2 x double> %2, <vscale x 2 x double> %3)
  ret <vscale x 2 x i1> %a
}

declare <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.mask.f64m4.b16(<vscale x 4 x i1>, <vscale x 4 x i1>, <vscale x 4 x double>, <vscale x 4 x double>);
define <vscale x 4 x i1> @vmfeq_vv_f64m4_b16_m(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x double> %2, <vscale x 4 x double> %3) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f64m4_b16_m
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 4 x i1> @llvm.riscv.vmfeq.vv.mask.f64m4.b16(<vscale x 4 x i1> %0, <vscale x 4 x i1> %1, <vscale x 4 x double> %2, <vscale x 4 x double> %3)
  ret <vscale x 4 x i1> %a
}

declare <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.mask.f64m8.b8(<vscale x 8 x i1>, <vscale x 8 x i1>, <vscale x 8 x double>, <vscale x 8 x double>);
define <vscale x 8 x i1> @vmfeq_vv_f64m8_b8_m(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x double> %2, <vscale x 8 x double> %3) {
entry:
  ; CHECK-LABEL: vmfeq_vv_f64m8_b8_m
  ; CHECK: vmfeq.vv v{{.*}}, v{{.*}}, v{{.*}}, v0.t
  ; CHECK: ret
  %a = tail call <vscale x 8 x i1> @llvm.riscv.vmfeq.vv.mask.f64m8.b8(<vscale x 8 x i1> %0, <vscale x 8 x i1> %1, <vscale x 8 x double> %2, <vscale x 8 x double> %3)
  ret <vscale x 8 x i1> %a
}

