// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8m1_t test_vredmax_vs_i8mf8_i8m1 (vint8m1_t dst, vint8mf8_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8mf8_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.nxv1i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8mf8_i8m1(dst, vector, scalar);
}

vint8m1_t test_vredmax_vs_i8mf4_i8m1 (vint8m1_t dst, vint8mf4_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8mf4_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.nxv2i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8mf4_i8m1(dst, vector, scalar);
}

vint8m1_t test_vredmax_vs_i8mf2_i8m1 (vint8m1_t dst, vint8mf2_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8mf2_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.nxv4i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8mf2_i8m1(dst, vector, scalar);
}

vint8m1_t test_vredmax_vs_i8m1_i8m1 (vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8m1_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8m1_i8m1(dst, vector, scalar);
}

vint8m1_t test_vredmax_vs_i8m2_i8m1 (vint8m1_t dst, vint8m2_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8m2_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.nxv16i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8m2_i8m1(dst, vector, scalar);
}

vint8m1_t test_vredmax_vs_i8m4_i8m1 (vint8m1_t dst, vint8m4_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8m4_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.nxv32i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8m4_i8m1(dst, vector, scalar);
}

vint8m1_t test_vredmax_vs_i8m8_i8m1 (vint8m1_t dst, vint8m8_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8m8_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.nxv64i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8m8_i8m1(dst, vector, scalar);
}

vint16m1_t test_vredmax_vs_i16mf4_i16m1 (vint16m1_t dst, vint16mf4_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i16mf4_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmax.vs.nxv1i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmax_vs_i16mf4_i16m1(dst, vector, scalar);
}

vint16m1_t test_vredmax_vs_i16mf2_i16m1 (vint16m1_t dst, vint16mf2_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i16mf2_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmax.vs.nxv2i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmax_vs_i16mf2_i16m1(dst, vector, scalar);
}

vint16m1_t test_vredmax_vs_i16m1_i16m1 (vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i16m1_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmax.vs.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmax_vs_i16m1_i16m1(dst, vector, scalar);
}

vint16m1_t test_vredmax_vs_i16m2_i16m1 (vint16m1_t dst, vint16m2_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i16m2_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmax.vs.nxv8i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmax_vs_i16m2_i16m1(dst, vector, scalar);
}

vint16m1_t test_vredmax_vs_i16m4_i16m1 (vint16m1_t dst, vint16m4_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i16m4_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmax.vs.nxv16i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmax_vs_i16m4_i16m1(dst, vector, scalar);
}

vint16m1_t test_vredmax_vs_i16m8_i16m1 (vint16m1_t dst, vint16m8_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i16m8_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmax.vs.nxv32i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmax_vs_i16m8_i16m1(dst, vector, scalar);
}

vint32m1_t test_vredmax_vs_i32mf2_i32m1 (vint32m1_t dst, vint32mf2_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i32mf2_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmax.vs.nxv1i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmax_vs_i32mf2_i32m1(dst, vector, scalar);
}

vint32m1_t test_vredmax_vs_i32m1_i32m1 (vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i32m1_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmax.vs.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmax_vs_i32m1_i32m1(dst, vector, scalar);
}

vint32m1_t test_vredmax_vs_i32m2_i32m1 (vint32m1_t dst, vint32m2_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i32m2_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmax.vs.nxv4i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmax_vs_i32m2_i32m1(dst, vector, scalar);
}

vint32m1_t test_vredmax_vs_i32m4_i32m1 (vint32m1_t dst, vint32m4_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i32m4_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmax.vs.nxv8i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmax_vs_i32m4_i32m1(dst, vector, scalar);
}

vint32m1_t test_vredmax_vs_i32m8_i32m1 (vint32m1_t dst, vint32m8_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i32m8_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmax.vs.nxv16i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmax_vs_i32m8_i32m1(dst, vector, scalar);
}

vint64m1_t test_vredmax_vs_i64m1_i64m1 (vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i64m1_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredmax.vs.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredmax_vs_i64m1_i64m1(dst, vector, scalar);
}

vint64m1_t test_vredmax_vs_i64m2_i64m1 (vint64m1_t dst, vint64m2_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i64m2_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredmax.vs.nxv2i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredmax_vs_i64m2_i64m1(dst, vector, scalar);
}

vint64m1_t test_vredmax_vs_i64m4_i64m1 (vint64m1_t dst, vint64m4_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i64m4_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredmax.vs.nxv4i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredmax_vs_i64m4_i64m1(dst, vector, scalar);
}

vint64m1_t test_vredmax_vs_i64m8_i64m1 (vint64m1_t dst, vint64m8_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i64m8_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredmax.vs.nxv8i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredmax_vs_i64m8_i64m1(dst, vector, scalar);
}

vint8m1_t test_vredmax_vs_i8mf8_i8m1_m (vbool64_t mask, vint8m1_t dst, vint8mf8_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8mf8_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8mf8_i8m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredmax_vs_i8mf4_i8m1_m (vbool32_t mask, vint8m1_t dst, vint8mf4_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8mf4_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8mf4_i8m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredmax_vs_i8mf2_i8m1_m (vbool16_t mask, vint8m1_t dst, vint8mf2_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8mf2_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8mf2_i8m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredmax_vs_i8m1_i8m1_m (vbool8_t mask, vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8m1_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8m1_i8m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredmax_vs_i8m2_i8m1_m (vbool4_t mask, vint8m1_t dst, vint8m2_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8m2_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8m2_i8m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredmax_vs_i8m4_i8m1_m (vbool2_t mask, vint8m1_t dst, vint8m4_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8m4_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8m4_i8m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredmax_vs_i8m8_i8m1_m (vbool1_t mask, vint8m1_t dst, vint8m8_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8m8_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8m8_i8m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredmax_vs_i16mf4_i16m1_m (vbool64_t mask, vint16m1_t dst, vint16mf4_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i16mf4_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmax.vs.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmax_vs_i16mf4_i16m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredmax_vs_i16mf2_i16m1_m (vbool32_t mask, vint16m1_t dst, vint16mf2_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i16mf2_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmax.vs.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmax_vs_i16mf2_i16m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredmax_vs_i16m1_i16m1_m (vbool16_t mask, vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i16m1_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmax.vs.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmax_vs_i16m1_i16m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredmax_vs_i16m2_i16m1_m (vbool8_t mask, vint16m1_t dst, vint16m2_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i16m2_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmax.vs.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmax_vs_i16m2_i16m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredmax_vs_i16m4_i16m1_m (vbool4_t mask, vint16m1_t dst, vint16m4_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i16m4_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmax.vs.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmax_vs_i16m4_i16m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredmax_vs_i16m8_i16m1_m (vbool2_t mask, vint16m1_t dst, vint16m8_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i16m8_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmax.vs.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmax_vs_i16m8_i16m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredmax_vs_i32mf2_i32m1_m (vbool64_t mask, vint32m1_t dst, vint32mf2_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i32mf2_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmax.vs.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmax_vs_i32mf2_i32m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredmax_vs_i32m1_i32m1_m (vbool32_t mask, vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i32m1_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmax.vs.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmax_vs_i32m1_i32m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredmax_vs_i32m2_i32m1_m (vbool16_t mask, vint32m1_t dst, vint32m2_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i32m2_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmax.vs.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmax_vs_i32m2_i32m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredmax_vs_i32m4_i32m1_m (vbool8_t mask, vint32m1_t dst, vint32m4_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i32m4_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmax.vs.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmax_vs_i32m4_i32m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredmax_vs_i32m8_i32m1_m (vbool4_t mask, vint32m1_t dst, vint32m8_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i32m8_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmax.vs.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmax_vs_i32m8_i32m1_m(mask, dst, vector, scalar);
}

vint64m1_t test_vredmax_vs_i64m1_i64m1_m (vbool64_t mask, vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i64m1_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredmax.vs.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredmax_vs_i64m1_i64m1_m(mask, dst, vector, scalar);
}

vint64m1_t test_vredmax_vs_i64m2_i64m1_m (vbool32_t mask, vint64m1_t dst, vint64m2_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i64m2_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredmax.vs.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredmax_vs_i64m2_i64m1_m(mask, dst, vector, scalar);
}

vint64m1_t test_vredmax_vs_i64m4_i64m1_m (vbool16_t mask, vint64m1_t dst, vint64m4_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i64m4_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredmax.vs.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredmax_vs_i64m4_i64m1_m(mask, dst, vector, scalar);
}

vint64m1_t test_vredmax_vs_i64m8_i64m1_m (vbool8_t mask, vint64m1_t dst, vint64m8_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i64m8_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredmax.vs.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredmax_vs_i64m8_i64m1_m(mask, dst, vector, scalar);
}

