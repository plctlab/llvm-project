// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint32mf2_t test_vamoorei32_v_i32mf2 (int32_t *base, vuint32mf2_t bindex, vint32mf2_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vamoorei32.v.nxv1i32{{.*}}(i32 %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vamoorei32_v_i32mf2(*base, bindex, value);
}

vint32m1_t test_vamoorei32_v_i32m1 (int32_t *base, vuint32m1_t bindex, vint32m1_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vamoorei32.v.nxv2i32{{.*}}(i32 %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vamoorei32_v_i32m1(*base, bindex, value);
}

vint32m2_t test_vamoorei32_v_i32m2 (int32_t *base, vuint32m2_t bindex, vint32m2_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vamoorei32.v.nxv4i32{{.*}}(i32 %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vamoorei32_v_i32m2(*base, bindex, value);
}

vint32m4_t test_vamoorei32_v_i32m4 (int32_t *base, vuint32m4_t bindex, vint32m4_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vamoorei32.v.nxv8i32{{.*}}(i32 %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vamoorei32_v_i32m4(*base, bindex, value);
}

vint32m8_t test_vamoorei32_v_i32m8 (int32_t *base, vuint32m8_t bindex, vint32m8_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vamoorei32.v.nxv16i32{{.*}}(i32 %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vamoorei32_v_i32m8(*base, bindex, value);
}

vint64m1_t test_vamoorei32_v_i64m1 (int64_t *base, vuint32mf2_t bindex, vint64m1_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vamoorei32.v.nxv1i64{{.*}}(i64 %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vamoorei32_v_i64m1(*base, bindex, value);
}

vint64m2_t test_vamoorei32_v_i64m2 (int64_t *base, vuint32m1_t bindex, vint64m2_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vamoorei32.v.nxv2i64{{.*}}(i64 %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vamoorei32_v_i64m2(*base, bindex, value);
}

vint64m4_t test_vamoorei32_v_i64m4 (int64_t *base, vuint32m2_t bindex, vint64m4_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vamoorei32.v.nxv4i64{{.*}}(i64 %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vamoorei32_v_i64m4(*base, bindex, value);
}

vint64m8_t test_vamoorei32_v_i64m8 (int64_t *base, vuint32m4_t bindex, vint64m8_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vamoorei32.v.nxv8i64{{.*}}(i64 %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vamoorei32_v_i64m8(*base, bindex, value);
}

vuint32mf2_t test_vamoorei32_v_u32mf2 (uint32_t *base, vuint32mf2_t bindex, vuint32mf2_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vamoorei32.v.nxv1i32{{.*}}(i32 %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vamoorei32_v_u32mf2(*base, bindex, value);
}

vuint32m1_t test_vamoorei32_v_u32m1 (uint32_t *base, vuint32m1_t bindex, vuint32m1_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vamoorei32.v.nxv2i32{{.*}}(i32 %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vamoorei32_v_u32m1(*base, bindex, value);
}

vuint32m2_t test_vamoorei32_v_u32m2 (uint32_t *base, vuint32m2_t bindex, vuint32m2_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vamoorei32.v.nxv4i32{{.*}}(i32 %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vamoorei32_v_u32m2(*base, bindex, value);
}

vuint32m4_t test_vamoorei32_v_u32m4 (uint32_t *base, vuint32m4_t bindex, vuint32m4_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vamoorei32.v.nxv8i32{{.*}}(i32 %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vamoorei32_v_u32m4(*base, bindex, value);
}

vuint32m8_t test_vamoorei32_v_u32m8 (uint32_t *base, vuint32m8_t bindex, vuint32m8_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vamoorei32.v.nxv16i32{{.*}}(i32 %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vamoorei32_v_u32m8(*base, bindex, value);
}

vuint64m1_t test_vamoorei32_v_u64m1 (uint64_t *base, vuint32mf2_t bindex, vuint64m1_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vamoorei32.v.nxv1i64{{.*}}(i64 %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vamoorei32_v_u64m1(*base, bindex, value);
}

vuint64m2_t test_vamoorei32_v_u64m2 (uint64_t *base, vuint32m1_t bindex, vuint64m2_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vamoorei32.v.nxv2i64{{.*}}(i64 %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vamoorei32_v_u64m2(*base, bindex, value);
}

vuint64m4_t test_vamoorei32_v_u64m4 (uint64_t *base, vuint32m2_t bindex, vuint64m4_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vamoorei32.v.nxv4i64{{.*}}(i64 %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vamoorei32_v_u64m4(*base, bindex, value);
}

vuint64m8_t test_vamoorei32_v_u64m8 (uint64_t *base, vuint32m4_t bindex, vuint64m8_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vamoorei32.v.nxv8i64{{.*}}(i64 %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vamoorei32_v_u64m8(*base, bindex, value);
}

vint32mf2_t test_vamoorei32_v_i32mf2_m (vbool64_t mask, int32_t *base, vuint32mf2_t bindex, vint32mf2_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vamoorei32.v.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, i32 %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vamoorei32_v_i32mf2_m(mask, *base, bindex, value);
}

vint32m1_t test_vamoorei32_v_i32m1_m (vbool32_t mask, int32_t *base, vuint32m1_t bindex, vint32m1_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vamoorei32.v.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, i32 %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vamoorei32_v_i32m1_m(mask, *base, bindex, value);
}

vint32m2_t test_vamoorei32_v_i32m2_m (vbool16_t mask, int32_t *base, vuint32m2_t bindex, vint32m2_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vamoorei32.v.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, i32 %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vamoorei32_v_i32m2_m(mask, *base, bindex, value);
}

vint32m4_t test_vamoorei32_v_i32m4_m (vbool8_t mask, int32_t *base, vuint32m4_t bindex, vint32m4_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vamoorei32.v.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, i32 %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vamoorei32_v_i32m4_m(mask, *base, bindex, value);
}

vint32m8_t test_vamoorei32_v_i32m8_m (vbool4_t mask, int32_t *base, vuint32m8_t bindex, vint32m8_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vamoorei32.v.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, i32 %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vamoorei32_v_i32m8_m(mask, *base, bindex, value);
}

vint64m1_t test_vamoorei32_v_i64m1_m (vbool64_t mask, int64_t *base, vuint32mf2_t bindex, vint64m1_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vamoorei32.v.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, i64 %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vamoorei32_v_i64m1_m(mask, *base, bindex, value);
}

vint64m2_t test_vamoorei32_v_i64m2_m (vbool32_t mask, int64_t *base, vuint32m1_t bindex, vint64m2_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vamoorei32.v.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, i64 %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vamoorei32_v_i64m2_m(mask, *base, bindex, value);
}

vint64m4_t test_vamoorei32_v_i64m4_m (vbool16_t mask, int64_t *base, vuint32m2_t bindex, vint64m4_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vamoorei32.v.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, i64 %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vamoorei32_v_i64m4_m(mask, *base, bindex, value);
}

vint64m8_t test_vamoorei32_v_i64m8_m (vbool8_t mask, int64_t *base, vuint32m4_t bindex, vint64m8_t value) {
  // CHECK-LABEL: test_vamoorei32_v_i64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vamoorei32.v.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, i64 %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vamoorei32_v_i64m8_m(mask, *base, bindex, value);
}

vuint32mf2_t test_vamoorei32_v_u32mf2_m (vbool64_t mask, uint32_t *base, vuint32mf2_t bindex, vuint32mf2_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vamoorei32.v.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, i32 %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vamoorei32_v_u32mf2_m(mask, *base, bindex, value);
}

vuint32m1_t test_vamoorei32_v_u32m1_m (vbool32_t mask, uint32_t *base, vuint32m1_t bindex, vuint32m1_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vamoorei32.v.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, i32 %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vamoorei32_v_u32m1_m(mask, *base, bindex, value);
}

vuint32m2_t test_vamoorei32_v_u32m2_m (vbool16_t mask, uint32_t *base, vuint32m2_t bindex, vuint32m2_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vamoorei32.v.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, i32 %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vamoorei32_v_u32m2_m(mask, *base, bindex, value);
}

vuint32m4_t test_vamoorei32_v_u32m4_m (vbool8_t mask, uint32_t *base, vuint32m4_t bindex, vuint32m4_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vamoorei32.v.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, i32 %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vamoorei32_v_u32m4_m(mask, *base, bindex, value);
}

vuint32m8_t test_vamoorei32_v_u32m8_m (vbool4_t mask, uint32_t *base, vuint32m8_t bindex, vuint32m8_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vamoorei32.v.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, i32 %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vamoorei32_v_u32m8_m(mask, *base, bindex, value);
}

vuint64m1_t test_vamoorei32_v_u64m1_m (vbool64_t mask, uint64_t *base, vuint32mf2_t bindex, vuint64m1_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vamoorei32.v.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, i64 %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vamoorei32_v_u64m1_m(mask, *base, bindex, value);
}

vuint64m2_t test_vamoorei32_v_u64m2_m (vbool32_t mask, uint64_t *base, vuint32m1_t bindex, vuint64m2_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vamoorei32.v.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, i64 %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vamoorei32_v_u64m2_m(mask, *base, bindex, value);
}

vuint64m4_t test_vamoorei32_v_u64m4_m (vbool16_t mask, uint64_t *base, vuint32m2_t bindex, vuint64m4_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vamoorei32.v.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, i64 %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vamoorei32_v_u64m4_m(mask, *base, bindex, value);
}

vuint64m8_t test_vamoorei32_v_u64m8_m (vbool8_t mask, uint64_t *base, vuint32m4_t bindex, vuint64m8_t value) {
  // CHECK-LABEL: test_vamoorei32_v_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vamoorei32.v.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, i64 %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vamoorei32_v_u64m8_m(mask, *base, bindex, value);
}

