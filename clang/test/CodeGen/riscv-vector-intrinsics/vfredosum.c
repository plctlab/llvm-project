// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat16m1_t test_vfredosum_vs_f16m1_f16m1 (vfloat16m1_t dst, vfloat16m1_t vector, vfloat16m1_t scalar) {
  // CHECK-LABEL: test_vfredosum_vs_f16m1_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfredosum.vs.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfredosum_vs_f16m1_f16m1(dst, vector, scalar);
}

vfloat32m1_t test_vfredosum_vs_f32m1_f32m1 (vfloat32m1_t dst, vfloat32m1_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfredosum_vs_f32m1_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfredosum.vs.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfredosum_vs_f32m1_f32m1(dst, vector, scalar);
}

vfloat16m1_t test_vfredsum_vs_f16m1_f16m1 (vfloat16m1_t dst, vfloat16m1_t vector, vfloat16m1_t scalar) {
  // CHECK-LABEL: test_vfredsum_vs_f16m1_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfredsum.vs.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfredsum_vs_f16m1_f16m1(dst, vector, scalar);
}

vfloat32m1_t test_vfredsum_vs_f32m1_f32m1 (vfloat32m1_t dst, vfloat32m1_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfredsum_vs_f32m1_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfredsum.vs.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfredsum_vs_f32m1_f32m1(dst, vector, scalar);
}

vfloat16m1_t test_vfredmax_vs_f16m1_f16m1 (vfloat16m1_t dst, vfloat16m1_t vector, vfloat16m1_t scalar) {
  // CHECK-LABEL: test_vfredmax_vs_f16m1_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfredmax.vs.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfredmax_vs_f16m1_f16m1(dst, vector, scalar);
}

vfloat32m1_t test_vfredmax_vs_f32m1_f32m1 (vfloat32m1_t dst, vfloat32m1_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfredmax_vs_f32m1_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfredmax.vs.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfredmax_vs_f32m1_f32m1(dst, vector, scalar);
}

vfloat16m1_t test_vfredmin_vs_f16m1_f16m1 (vfloat16m1_t dst, vfloat16m1_t vector, vfloat16m1_t scalar) {
  // CHECK-LABEL: test_vfredmin_vs_f16m1_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfredmin.vs.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfredmin_vs_f16m1_f16m1(dst, vector, scalar);
}

vfloat32m1_t test_vfredmin_vs_f32m1_f32m1 (vfloat32m1_t dst, vfloat32m1_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfredmin_vs_f32m1_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfredmin.vs.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfredmin_vs_f32m1_f32m1(dst, vector, scalar);
}

vfloat16m1_t test_vfredosum_vs_f16m1_f16m1_m (vbool16_t mask, vfloat16m1_t dst, vfloat16m1_t vector, vfloat16m1_t scalar) {
  // CHECK-LABEL: test_vfredosum_vs_f16m1_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfredosum.vs.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfredosum_vs_f16m1_f16m1_m(mask, dst, vector, scalar);
}

vfloat32m1_t test_vfredosum_vs_f32m1_f32m1_m (vbool32_t mask, vfloat32m1_t dst, vfloat32m1_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfredosum_vs_f32m1_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfredosum.vs.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfredosum_vs_f32m1_f32m1_m(mask, dst, vector, scalar);
}

vfloat16m1_t test_vfredsum_vs_f16m1_f16m1_m (vbool16_t mask, vfloat16m1_t dst, vfloat16m1_t vector, vfloat16m1_t scalar) {
  // CHECK-LABEL: test_vfredsum_vs_f16m1_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfredsum.vs.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfredsum_vs_f16m1_f16m1_m(mask, dst, vector, scalar);
}

vfloat32m1_t test_vfredsum_vs_f32m1_f32m1_m (vbool32_t mask, vfloat32m1_t dst, vfloat32m1_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfredsum_vs_f32m1_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfredsum.vs.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfredsum_vs_f32m1_f32m1_m(mask, dst, vector, scalar);
}

vfloat16m1_t test_vfredmax_vs_f16m1_f16m1_m (vbool16_t mask, vfloat16m1_t dst, vfloat16m1_t vector, vfloat16m1_t scalar) {
  // CHECK-LABEL: test_vfredmax_vs_f16m1_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfredmax.vs.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfredmax_vs_f16m1_f16m1_m(mask, dst, vector, scalar);
}

vfloat32m1_t test_vfredmax_vs_f32m1_f32m1_m (vbool32_t mask, vfloat32m1_t dst, vfloat32m1_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfredmax_vs_f32m1_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfredmax.vs.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfredmax_vs_f32m1_f32m1_m(mask, dst, vector, scalar);
}

vfloat16m1_t test_vfredmin_vs_f16m1_f16m1_m (vbool16_t mask, vfloat16m1_t dst, vfloat16m1_t vector, vfloat16m1_t scalar) {
  // CHECK-LABEL: test_vfredmin_vs_f16m1_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfredmin.vs.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vfredmin_vs_f16m1_f16m1_m(mask, dst, vector, scalar);
}

vfloat32m1_t test_vfredmin_vs_f32m1_f32m1_m (vbool32_t mask, vfloat32m1_t dst, vfloat32m1_t vector, vfloat32m1_t scalar) {
  // CHECK-LABEL: test_vfredmin_vs_f32m1_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfredmin.vs.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vfredmin_vs_f32m1_f32m1_m(mask, dst, vector, scalar);
}

