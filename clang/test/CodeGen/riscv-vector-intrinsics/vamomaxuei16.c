// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vuint32mf2_t test_vamomaxuei16_v_u32mf2 (uint32_t *base, vuint16mf4_t bindex, vuint32mf2_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vamomaxuei16.v.nxv1i32{{.*}}(i32 %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vamomaxuei16_v_u32mf2(*base, bindex, value);
}

vuint32m1_t test_vamomaxuei16_v_u32m1 (uint32_t *base, vuint16mf2_t bindex, vuint32m1_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vamomaxuei16.v.nxv2i32{{.*}}(i32 %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vamomaxuei16_v_u32m1(*base, bindex, value);
}

vuint32m2_t test_vamomaxuei16_v_u32m2 (uint32_t *base, vuint16m1_t bindex, vuint32m2_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vamomaxuei16.v.nxv4i32{{.*}}(i32 %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vamomaxuei16_v_u32m2(*base, bindex, value);
}

vuint32m4_t test_vamomaxuei16_v_u32m4 (uint32_t *base, vuint16m2_t bindex, vuint32m4_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vamomaxuei16.v.nxv8i32{{.*}}(i32 %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vamomaxuei16_v_u32m4(*base, bindex, value);
}

vuint32m8_t test_vamomaxuei16_v_u32m8 (uint32_t *base, vuint16m4_t bindex, vuint32m8_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vamomaxuei16.v.nxv16i32{{.*}}(i32 %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vamomaxuei16_v_u32m8(*base, bindex, value);
}

vuint64m1_t test_vamomaxuei16_v_u64m1 (uint64_t *base, vuint16mf4_t bindex, vuint64m1_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vamomaxuei16.v.nxv1i64{{.*}}(i64 %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vamomaxuei16_v_u64m1(*base, bindex, value);
}

vuint64m2_t test_vamomaxuei16_v_u64m2 (uint64_t *base, vuint16mf2_t bindex, vuint64m2_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vamomaxuei16.v.nxv2i64{{.*}}(i64 %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vamomaxuei16_v_u64m2(*base, bindex, value);
}

vuint64m4_t test_vamomaxuei16_v_u64m4 (uint64_t *base, vuint16m1_t bindex, vuint64m4_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vamomaxuei16.v.nxv4i64{{.*}}(i64 %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vamomaxuei16_v_u64m4(*base, bindex, value);
}

vuint64m8_t test_vamomaxuei16_v_u64m8 (uint64_t *base, vuint16m2_t bindex, vuint64m8_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vamomaxuei16.v.nxv8i64{{.*}}(i64 %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vamomaxuei16_v_u64m8(*base, bindex, value);
}

vuint32mf2_t test_vamomaxuei16_v_u32mf2_m (vbool64_t mask, uint32_t *base, vuint16mf4_t bindex, vuint32mf2_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vamomaxuei16.v.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, i32 %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vamomaxuei16_v_u32mf2_m(mask, *base, bindex, value);
}

vuint32m1_t test_vamomaxuei16_v_u32m1_m (vbool32_t mask, uint32_t *base, vuint16mf2_t bindex, vuint32m1_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vamomaxuei16.v.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, i32 %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vamomaxuei16_v_u32m1_m(mask, *base, bindex, value);
}

vuint32m2_t test_vamomaxuei16_v_u32m2_m (vbool16_t mask, uint32_t *base, vuint16m1_t bindex, vuint32m2_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vamomaxuei16.v.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, i32 %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vamomaxuei16_v_u32m2_m(mask, *base, bindex, value);
}

vuint32m4_t test_vamomaxuei16_v_u32m4_m (vbool8_t mask, uint32_t *base, vuint16m2_t bindex, vuint32m4_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vamomaxuei16.v.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, i32 %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vamomaxuei16_v_u32m4_m(mask, *base, bindex, value);
}

vuint32m8_t test_vamomaxuei16_v_u32m8_m (vbool4_t mask, uint32_t *base, vuint16m4_t bindex, vuint32m8_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vamomaxuei16.v.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, i32 %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vamomaxuei16_v_u32m8_m(mask, *base, bindex, value);
}

vuint64m1_t test_vamomaxuei16_v_u64m1_m (vbool64_t mask, uint64_t *base, vuint16mf4_t bindex, vuint64m1_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vamomaxuei16.v.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, i64 %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vamomaxuei16_v_u64m1_m(mask, *base, bindex, value);
}

vuint64m2_t test_vamomaxuei16_v_u64m2_m (vbool32_t mask, uint64_t *base, vuint16mf2_t bindex, vuint64m2_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vamomaxuei16.v.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, i64 %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vamomaxuei16_v_u64m2_m(mask, *base, bindex, value);
}

vuint64m4_t test_vamomaxuei16_v_u64m4_m (vbool16_t mask, uint64_t *base, vuint16m1_t bindex, vuint64m4_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vamomaxuei16.v.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, i64 %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vamomaxuei16_v_u64m4_m(mask, *base, bindex, value);
}

vuint64m8_t test_vamomaxuei16_v_u64m8_m (vbool8_t mask, uint64_t *base, vuint16m2_t bindex, vuint64m8_t value) {
  // CHECK-LABEL: test_vamomaxuei16_v_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vamomaxuei16.v.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, i64 %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vamomaxuei16_v_u64m8_m(mask, *base, bindex, value);
}

