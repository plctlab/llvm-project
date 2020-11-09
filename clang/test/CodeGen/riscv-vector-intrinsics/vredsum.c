// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8m1_t test_vredsum_vs_i8mf8_i8m1 (vint8m1_t dst, vint8mf8_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8mf8_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv1i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8mf8_i8m1(dst, vector, scalar);
}

vint8m1_t test_vredsum_vs_i8mf4_i8m1 (vint8m1_t dst, vint8mf4_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8mf4_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv2i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8mf4_i8m1(dst, vector, scalar);
}

vint8m1_t test_vredsum_vs_i8mf2_i8m1 (vint8m1_t dst, vint8mf2_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8mf2_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv4i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8mf2_i8m1(dst, vector, scalar);
}

vint8m1_t test_vredsum_vs_i8m1_i8m1 (vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8m1_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8m1_i8m1(dst, vector, scalar);
}

vint8m1_t test_vredsum_vs_i8m2_i8m1 (vint8m1_t dst, vint8m2_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8m2_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv16i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8m2_i8m1(dst, vector, scalar);
}

vint8m1_t test_vredsum_vs_i8m4_i8m1 (vint8m1_t dst, vint8m4_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8m4_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv32i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8m4_i8m1(dst, vector, scalar);
}

vint8m1_t test_vredsum_vs_i8m8_i8m1 (vint8m1_t dst, vint8m8_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8m8_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv64i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8m8_i8m1(dst, vector, scalar);
}

vint16m1_t test_vredsum_vs_i16mf4_i16m1 (vint16m1_t dst, vint16mf4_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i16mf4_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.nxv1i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_i16mf4_i16m1(dst, vector, scalar);
}

vint16m1_t test_vredsum_vs_i16mf2_i16m1 (vint16m1_t dst, vint16mf2_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i16mf2_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.nxv2i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_i16mf2_i16m1(dst, vector, scalar);
}

vint16m1_t test_vredsum_vs_i16m1_i16m1 (vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i16m1_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_i16m1_i16m1(dst, vector, scalar);
}

vint16m1_t test_vredsum_vs_i16m2_i16m1 (vint16m1_t dst, vint16m2_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i16m2_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.nxv8i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_i16m2_i16m1(dst, vector, scalar);
}

vint16m1_t test_vredsum_vs_i16m4_i16m1 (vint16m1_t dst, vint16m4_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i16m4_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.nxv16i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_i16m4_i16m1(dst, vector, scalar);
}

vint16m1_t test_vredsum_vs_i16m8_i16m1 (vint16m1_t dst, vint16m8_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i16m8_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.nxv32i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_i16m8_i16m1(dst, vector, scalar);
}

vint32m1_t test_vredsum_vs_i32mf2_i32m1 (vint32m1_t dst, vint32mf2_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i32mf2_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.nxv1i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_i32mf2_i32m1(dst, vector, scalar);
}

vint32m1_t test_vredsum_vs_i32m1_i32m1 (vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i32m1_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_i32m1_i32m1(dst, vector, scalar);
}

vint32m1_t test_vredsum_vs_i32m2_i32m1 (vint32m1_t dst, vint32m2_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i32m2_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.nxv4i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_i32m2_i32m1(dst, vector, scalar);
}

vint32m1_t test_vredsum_vs_i32m4_i32m1 (vint32m1_t dst, vint32m4_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i32m4_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.nxv8i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_i32m4_i32m1(dst, vector, scalar);
}

vint32m1_t test_vredsum_vs_i32m8_i32m1 (vint32m1_t dst, vint32m8_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i32m8_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.nxv16i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_i32m8_i32m1(dst, vector, scalar);
}

vint64m1_t test_vredsum_vs_i64m1_i64m1 (vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i64m1_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_i64m1_i64m1(dst, vector, scalar);
}

vint64m1_t test_vredsum_vs_i64m2_i64m1 (vint64m1_t dst, vint64m2_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i64m2_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.nxv2i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_i64m2_i64m1(dst, vector, scalar);
}

vint64m1_t test_vredsum_vs_i64m4_i64m1 (vint64m1_t dst, vint64m4_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i64m4_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.nxv4i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_i64m4_i64m1(dst, vector, scalar);
}

vint64m1_t test_vredsum_vs_i64m8_i64m1 (vint64m1_t dst, vint64m8_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i64m8_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.nxv8i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_i64m8_i64m1(dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8mf8_u8m1 (vuint8m1_t dst, vuint8mf8_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8mf8_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv1i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8mf8_u8m1(dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8mf4_u8m1 (vuint8m1_t dst, vuint8mf4_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8mf4_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv2i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8mf4_u8m1(dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8mf2_u8m1 (vuint8m1_t dst, vuint8mf2_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8mf2_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv4i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8mf2_u8m1(dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8m1_u8m1 (vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8m1_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8m1_u8m1(dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8m2_u8m1 (vuint8m1_t dst, vuint8m2_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8m2_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv16i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8m2_u8m1(dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8m4_u8m1 (vuint8m1_t dst, vuint8m4_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8m4_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv32i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8m4_u8m1(dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8m8_u8m1 (vuint8m1_t dst, vuint8m8_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8m8_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv64i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8m8_u8m1(dst, vector, scalar);
}

vuint16m1_t test_vredsum_vs_u16mf4_u16m1 (vuint16m1_t dst, vuint16mf4_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u16mf4_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.nxv1i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_u16mf4_u16m1(dst, vector, scalar);
}

vuint16m1_t test_vredsum_vs_u16mf2_u16m1 (vuint16m1_t dst, vuint16mf2_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u16mf2_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.nxv2i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_u16mf2_u16m1(dst, vector, scalar);
}

vuint16m1_t test_vredsum_vs_u16m1_u16m1 (vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u16m1_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_u16m1_u16m1(dst, vector, scalar);
}

vuint16m1_t test_vredsum_vs_u16m2_u16m1 (vuint16m1_t dst, vuint16m2_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u16m2_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.nxv8i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_u16m2_u16m1(dst, vector, scalar);
}

vuint16m1_t test_vredsum_vs_u16m4_u16m1 (vuint16m1_t dst, vuint16m4_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u16m4_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.nxv16i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_u16m4_u16m1(dst, vector, scalar);
}

vuint16m1_t test_vredsum_vs_u16m8_u16m1 (vuint16m1_t dst, vuint16m8_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u16m8_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.nxv32i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_u16m8_u16m1(dst, vector, scalar);
}

vuint32m1_t test_vredsum_vs_u32mf2_u32m1 (vuint32m1_t dst, vuint32mf2_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u32mf2_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.nxv1i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_u32mf2_u32m1(dst, vector, scalar);
}

vuint32m1_t test_vredsum_vs_u32m1_u32m1 (vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u32m1_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_u32m1_u32m1(dst, vector, scalar);
}

vuint32m1_t test_vredsum_vs_u32m2_u32m1 (vuint32m1_t dst, vuint32m2_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u32m2_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.nxv4i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_u32m2_u32m1(dst, vector, scalar);
}

vuint32m1_t test_vredsum_vs_u32m4_u32m1 (vuint32m1_t dst, vuint32m4_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u32m4_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.nxv8i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_u32m4_u32m1(dst, vector, scalar);
}

vuint32m1_t test_vredsum_vs_u32m8_u32m1 (vuint32m1_t dst, vuint32m8_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u32m8_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.nxv16i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_u32m8_u32m1(dst, vector, scalar);
}

vuint64m1_t test_vredsum_vs_u64m1_u64m1 (vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u64m1_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_u64m1_u64m1(dst, vector, scalar);
}

vuint64m1_t test_vredsum_vs_u64m2_u64m1 (vuint64m1_t dst, vuint64m2_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u64m2_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.nxv2i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_u64m2_u64m1(dst, vector, scalar);
}

vuint64m1_t test_vredsum_vs_u64m4_u64m1 (vuint64m1_t dst, vuint64m4_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u64m4_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.nxv4i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_u64m4_u64m1(dst, vector, scalar);
}

vuint64m1_t test_vredsum_vs_u64m8_u64m1 (vuint64m1_t dst, vuint64m8_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u64m8_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.nxv8i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_u64m8_u64m1(dst, vector, scalar);
}

vint8m1_t test_vredsum_vs_i8mf8_i8m1_m (vbool64_t mask, vint8m1_t dst, vint8mf8_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8mf8_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8mf8_i8m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredsum_vs_i8mf4_i8m1_m (vbool32_t mask, vint8m1_t dst, vint8mf4_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8mf4_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8mf4_i8m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredsum_vs_i8mf2_i8m1_m (vbool16_t mask, vint8m1_t dst, vint8mf2_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8mf2_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8mf2_i8m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredsum_vs_i8m1_i8m1_m (vbool8_t mask, vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8m1_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8m1_i8m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredsum_vs_i8m2_i8m1_m (vbool4_t mask, vint8m1_t dst, vint8m2_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8m2_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8m2_i8m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredsum_vs_i8m4_i8m1_m (vbool2_t mask, vint8m1_t dst, vint8m4_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8m4_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8m4_i8m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredsum_vs_i8m8_i8m1_m (vbool1_t mask, vint8m1_t dst, vint8m8_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8m8_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8m8_i8m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredsum_vs_i16mf4_i16m1_m (vbool64_t mask, vint16m1_t dst, vint16mf4_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i16mf4_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_i16mf4_i16m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredsum_vs_i16mf2_i16m1_m (vbool32_t mask, vint16m1_t dst, vint16mf2_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i16mf2_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_i16mf2_i16m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredsum_vs_i16m1_i16m1_m (vbool16_t mask, vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i16m1_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_i16m1_i16m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredsum_vs_i16m2_i16m1_m (vbool8_t mask, vint16m1_t dst, vint16m2_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i16m2_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_i16m2_i16m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredsum_vs_i16m4_i16m1_m (vbool4_t mask, vint16m1_t dst, vint16m4_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i16m4_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_i16m4_i16m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredsum_vs_i16m8_i16m1_m (vbool2_t mask, vint16m1_t dst, vint16m8_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i16m8_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_i16m8_i16m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredsum_vs_i32mf2_i32m1_m (vbool64_t mask, vint32m1_t dst, vint32mf2_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i32mf2_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_i32mf2_i32m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredsum_vs_i32m1_i32m1_m (vbool32_t mask, vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i32m1_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_i32m1_i32m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredsum_vs_i32m2_i32m1_m (vbool16_t mask, vint32m1_t dst, vint32m2_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i32m2_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_i32m2_i32m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredsum_vs_i32m4_i32m1_m (vbool8_t mask, vint32m1_t dst, vint32m4_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i32m4_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_i32m4_i32m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredsum_vs_i32m8_i32m1_m (vbool4_t mask, vint32m1_t dst, vint32m8_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i32m8_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_i32m8_i32m1_m(mask, dst, vector, scalar);
}

vint64m1_t test_vredsum_vs_i64m1_i64m1_m (vbool64_t mask, vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i64m1_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_i64m1_i64m1_m(mask, dst, vector, scalar);
}

vint64m1_t test_vredsum_vs_i64m2_i64m1_m (vbool32_t mask, vint64m1_t dst, vint64m2_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i64m2_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_i64m2_i64m1_m(mask, dst, vector, scalar);
}

vint64m1_t test_vredsum_vs_i64m4_i64m1_m (vbool16_t mask, vint64m1_t dst, vint64m4_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i64m4_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_i64m4_i64m1_m(mask, dst, vector, scalar);
}

vint64m1_t test_vredsum_vs_i64m8_i64m1_m (vbool8_t mask, vint64m1_t dst, vint64m8_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i64m8_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_i64m8_i64m1_m(mask, dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8mf8_u8m1_m (vbool64_t mask, vuint8m1_t dst, vuint8mf8_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8mf8_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8mf8_u8m1_m(mask, dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8mf4_u8m1_m (vbool32_t mask, vuint8m1_t dst, vuint8mf4_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8mf4_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8mf4_u8m1_m(mask, dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8mf2_u8m1_m (vbool16_t mask, vuint8m1_t dst, vuint8mf2_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8mf2_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8mf2_u8m1_m(mask, dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8m1_u8m1_m (vbool8_t mask, vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8m1_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8m1_u8m1_m(mask, dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8m2_u8m1_m (vbool4_t mask, vuint8m1_t dst, vuint8m2_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8m2_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8m2_u8m1_m(mask, dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8m4_u8m1_m (vbool2_t mask, vuint8m1_t dst, vuint8m4_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8m4_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8m4_u8m1_m(mask, dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8m8_u8m1_m (vbool1_t mask, vuint8m1_t dst, vuint8m8_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8m8_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8m8_u8m1_m(mask, dst, vector, scalar);
}

vuint16m1_t test_vredsum_vs_u16mf4_u16m1_m (vbool64_t mask, vuint16m1_t dst, vuint16mf4_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u16mf4_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_u16mf4_u16m1_m(mask, dst, vector, scalar);
}

vuint16m1_t test_vredsum_vs_u16mf2_u16m1_m (vbool32_t mask, vuint16m1_t dst, vuint16mf2_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u16mf2_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_u16mf2_u16m1_m(mask, dst, vector, scalar);
}

vuint16m1_t test_vredsum_vs_u16m1_u16m1_m (vbool16_t mask, vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u16m1_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_u16m1_u16m1_m(mask, dst, vector, scalar);
}

vuint16m1_t test_vredsum_vs_u16m2_u16m1_m (vbool8_t mask, vuint16m1_t dst, vuint16m2_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u16m2_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_u16m2_u16m1_m(mask, dst, vector, scalar);
}

vuint16m1_t test_vredsum_vs_u16m4_u16m1_m (vbool4_t mask, vuint16m1_t dst, vuint16m4_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u16m4_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_u16m4_u16m1_m(mask, dst, vector, scalar);
}

vuint16m1_t test_vredsum_vs_u16m8_u16m1_m (vbool2_t mask, vuint16m1_t dst, vuint16m8_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u16m8_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_u16m8_u16m1_m(mask, dst, vector, scalar);
}

vuint32m1_t test_vredsum_vs_u32mf2_u32m1_m (vbool64_t mask, vuint32m1_t dst, vuint32mf2_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u32mf2_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_u32mf2_u32m1_m(mask, dst, vector, scalar);
}

vuint32m1_t test_vredsum_vs_u32m1_u32m1_m (vbool32_t mask, vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u32m1_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_u32m1_u32m1_m(mask, dst, vector, scalar);
}

vuint32m1_t test_vredsum_vs_u32m2_u32m1_m (vbool16_t mask, vuint32m1_t dst, vuint32m2_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u32m2_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_u32m2_u32m1_m(mask, dst, vector, scalar);
}

vuint32m1_t test_vredsum_vs_u32m4_u32m1_m (vbool8_t mask, vuint32m1_t dst, vuint32m4_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u32m4_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_u32m4_u32m1_m(mask, dst, vector, scalar);
}

vuint32m1_t test_vredsum_vs_u32m8_u32m1_m (vbool4_t mask, vuint32m1_t dst, vuint32m8_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u32m8_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_u32m8_u32m1_m(mask, dst, vector, scalar);
}

vuint64m1_t test_vredsum_vs_u64m1_u64m1_m (vbool64_t mask, vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u64m1_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_u64m1_u64m1_m(mask, dst, vector, scalar);
}

vuint64m1_t test_vredsum_vs_u64m2_u64m1_m (vbool32_t mask, vuint64m1_t dst, vuint64m2_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u64m2_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_u64m2_u64m1_m(mask, dst, vector, scalar);
}

vuint64m1_t test_vredsum_vs_u64m4_u64m1_m (vbool16_t mask, vuint64m1_t dst, vuint64m4_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u64m4_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_u64m4_u64m1_m(mask, dst, vector, scalar);
}

vuint64m1_t test_vredsum_vs_u64m8_u64m1_m (vbool8_t mask, vuint64m1_t dst, vuint64m8_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u64m8_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_u64m8_u64m1_m(mask, dst, vector, scalar);
}

