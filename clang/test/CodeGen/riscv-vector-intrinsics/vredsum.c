// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8m1_t test_vredsum_vs_i8m1_i8m1 (vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8m1_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8m1_i8m1(dst, vector, scalar);
}

vint16m1_t test_vredsum_vs_i16m1_i16m1 (vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i16m1_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_i16m1_i16m1(dst, vector, scalar);
}

vint32m1_t test_vredsum_vs_i32m1_i32m1 (vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i32m1_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_i32m1_i32m1(dst, vector, scalar);
}

vint64m1_t test_vredsum_vs_i64m1_i64m1 (vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i64m1_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_i64m1_i64m1(dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8m1_u8m1 (vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8m1_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8m1_u8m1(dst, vector, scalar);
}

vuint16m1_t test_vredsum_vs_u16m1_u16m1 (vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u16m1_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_u16m1_u16m1(dst, vector, scalar);
}

vuint32m1_t test_vredsum_vs_u32m1_u32m1 (vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u32m1_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_u32m1_u32m1(dst, vector, scalar);
}

vuint64m1_t test_vredsum_vs_u64m1_u64m1 (vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u64m1_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_u64m1_u64m1(dst, vector, scalar);
}

vint8m1_t test_vredmax_vs_i8m1_i8m1 (vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8m1_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8m1_i8m1(dst, vector, scalar);
}

vint16m1_t test_vredmax_vs_i16m1_i16m1 (vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i16m1_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmax.vs.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmax_vs_i16m1_i16m1(dst, vector, scalar);
}

vint32m1_t test_vredmax_vs_i32m1_i32m1 (vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i32m1_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmax.vs.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmax_vs_i32m1_i32m1(dst, vector, scalar);
}

vint64m1_t test_vredmax_vs_i64m1_i64m1 (vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i64m1_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredmax.vs.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredmax_vs_i64m1_i64m1(dst, vector, scalar);
}

vuint8m1_t test_vredmaxu_vs_u8m1_u8m1 (vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredmaxu_vs_u8m1_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmaxu.vs.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmaxu_vs_u8m1_u8m1(dst, vector, scalar);
}

vuint16m1_t test_vredmaxu_vs_u16m1_u16m1 (vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredmaxu_vs_u16m1_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmaxu.vs.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmaxu_vs_u16m1_u16m1(dst, vector, scalar);
}

vuint32m1_t test_vredmaxu_vs_u32m1_u32m1 (vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredmaxu_vs_u32m1_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmaxu.vs.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmaxu_vs_u32m1_u32m1(dst, vector, scalar);
}

vuint64m1_t test_vredmaxu_vs_u64m1_u64m1 (vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredmaxu_vs_u64m1_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredmaxu.vs.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredmaxu_vs_u64m1_u64m1(dst, vector, scalar);
}

vint8m1_t test_vredmin_vs_i8m1_i8m1 (vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmin_vs_i8m1_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmin.vs.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmin_vs_i8m1_i8m1(dst, vector, scalar);
}

vint16m1_t test_vredmin_vs_i16m1_i16m1 (vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmin_vs_i16m1_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmin.vs.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmin_vs_i16m1_i16m1(dst, vector, scalar);
}

vint32m1_t test_vredmin_vs_i32m1_i32m1 (vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredmin_vs_i32m1_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmin.vs.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmin_vs_i32m1_i32m1(dst, vector, scalar);
}

vint64m1_t test_vredmin_vs_i64m1_i64m1 (vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredmin_vs_i64m1_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredmin.vs.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredmin_vs_i64m1_i64m1(dst, vector, scalar);
}

vuint8m1_t test_vredminu_vs_u8m1_u8m1 (vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredminu_vs_u8m1_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredminu.vs.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredminu_vs_u8m1_u8m1(dst, vector, scalar);
}

vuint16m1_t test_vredminu_vs_u16m1_u16m1 (vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredminu_vs_u16m1_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredminu.vs.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredminu_vs_u16m1_u16m1(dst, vector, scalar);
}

vuint32m1_t test_vredminu_vs_u32m1_u32m1 (vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredminu_vs_u32m1_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredminu.vs.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredminu_vs_u32m1_u32m1(dst, vector, scalar);
}

vuint64m1_t test_vredminu_vs_u64m1_u64m1 (vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredminu_vs_u64m1_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredminu.vs.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredminu_vs_u64m1_u64m1(dst, vector, scalar);
}

vint8m1_t test_vredand_vs_i8m1_i8m1 (vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_i8m1_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredand.vs.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredand_vs_i8m1_i8m1(dst, vector, scalar);
}

vint16m1_t test_vredand_vs_i16m1_i16m1 (vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_i16m1_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredand.vs.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredand_vs_i16m1_i16m1(dst, vector, scalar);
}

vint32m1_t test_vredand_vs_i32m1_i32m1 (vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_i32m1_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredand.vs.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredand_vs_i32m1_i32m1(dst, vector, scalar);
}

vint64m1_t test_vredand_vs_i64m1_i64m1 (vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_i64m1_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredand.vs.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredand_vs_i64m1_i64m1(dst, vector, scalar);
}

vuint8m1_t test_vredand_vs_u8m1_u8m1 (vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_u8m1_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredand.vs.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredand_vs_u8m1_u8m1(dst, vector, scalar);
}

vuint16m1_t test_vredand_vs_u16m1_u16m1 (vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_u16m1_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredand.vs.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredand_vs_u16m1_u16m1(dst, vector, scalar);
}

vuint32m1_t test_vredand_vs_u32m1_u32m1 (vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_u32m1_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredand.vs.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredand_vs_u32m1_u32m1(dst, vector, scalar);
}

vuint64m1_t test_vredand_vs_u64m1_u64m1 (vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_u64m1_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredand.vs.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredand_vs_u64m1_u64m1(dst, vector, scalar);
}

vint8m1_t test_vredor_vs_i8m1_i8m1 (vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_i8m1_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredor.vs.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredor_vs_i8m1_i8m1(dst, vector, scalar);
}

vint16m1_t test_vredor_vs_i16m1_i16m1 (vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_i16m1_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredor.vs.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredor_vs_i16m1_i16m1(dst, vector, scalar);
}

vint32m1_t test_vredor_vs_i32m1_i32m1 (vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_i32m1_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredor.vs.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredor_vs_i32m1_i32m1(dst, vector, scalar);
}

vint64m1_t test_vredor_vs_i64m1_i64m1 (vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_i64m1_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredor.vs.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredor_vs_i64m1_i64m1(dst, vector, scalar);
}

vuint8m1_t test_vredor_vs_u8m1_u8m1 (vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_u8m1_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredor.vs.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredor_vs_u8m1_u8m1(dst, vector, scalar);
}

vuint16m1_t test_vredor_vs_u16m1_u16m1 (vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_u16m1_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredor.vs.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredor_vs_u16m1_u16m1(dst, vector, scalar);
}

vuint32m1_t test_vredor_vs_u32m1_u32m1 (vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_u32m1_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredor.vs.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredor_vs_u32m1_u32m1(dst, vector, scalar);
}

vuint64m1_t test_vredor_vs_u64m1_u64m1 (vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_u64m1_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredor.vs.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredor_vs_u64m1_u64m1(dst, vector, scalar);
}

vint8m1_t test_vredxor_vs_i8m1_i8m1 (vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_i8m1_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredxor.vs.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredxor_vs_i8m1_i8m1(dst, vector, scalar);
}

vint16m1_t test_vredxor_vs_i16m1_i16m1 (vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_i16m1_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredxor.vs.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredxor_vs_i16m1_i16m1(dst, vector, scalar);
}

vint32m1_t test_vredxor_vs_i32m1_i32m1 (vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_i32m1_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredxor.vs.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredxor_vs_i32m1_i32m1(dst, vector, scalar);
}

vint64m1_t test_vredxor_vs_i64m1_i64m1 (vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_i64m1_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredxor.vs.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredxor_vs_i64m1_i64m1(dst, vector, scalar);
}

vuint8m1_t test_vredxor_vs_u8m1_u8m1 (vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_u8m1_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredxor.vs.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredxor_vs_u8m1_u8m1(dst, vector, scalar);
}

vuint16m1_t test_vredxor_vs_u16m1_u16m1 (vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_u16m1_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredxor.vs.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredxor_vs_u16m1_u16m1(dst, vector, scalar);
}

vuint32m1_t test_vredxor_vs_u32m1_u32m1 (vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_u32m1_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredxor.vs.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredxor_vs_u32m1_u32m1(dst, vector, scalar);
}

vuint64m1_t test_vredxor_vs_u64m1_u64m1 (vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_u64m1_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredxor.vs.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredxor_vs_u64m1_u64m1(dst, vector, scalar);
}

vint8m1_t test_vredsum_vs_i8m1_i8m1_m (vbool8_t mask, vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i8m1_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_i8m1_i8m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredsum_vs_i16m1_i16m1_m (vbool16_t mask, vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i16m1_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_i16m1_i16m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredsum_vs_i32m1_i32m1_m (vbool32_t mask, vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i32m1_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_i32m1_i32m1_m(mask, dst, vector, scalar);
}

vint64m1_t test_vredsum_vs_i64m1_i64m1_m (vbool64_t mask, vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_i64m1_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_i64m1_i64m1_m(mask, dst, vector, scalar);
}

vuint8m1_t test_vredsum_vs_u8m1_u8m1_m (vbool8_t mask, vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u8m1_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredsum.vs.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredsum_vs_u8m1_u8m1_m(mask, dst, vector, scalar);
}

vuint16m1_t test_vredsum_vs_u16m1_u16m1_m (vbool16_t mask, vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u16m1_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredsum.vs.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredsum_vs_u16m1_u16m1_m(mask, dst, vector, scalar);
}

vuint32m1_t test_vredsum_vs_u32m1_u32m1_m (vbool32_t mask, vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u32m1_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredsum.vs.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredsum_vs_u32m1_u32m1_m(mask, dst, vector, scalar);
}

vuint64m1_t test_vredsum_vs_u64m1_u64m1_m (vbool64_t mask, vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredsum_vs_u64m1_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredsum.vs.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredsum_vs_u64m1_u64m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredmax_vs_i8m1_i8m1_m (vbool8_t mask, vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i8m1_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmax.vs.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmax_vs_i8m1_i8m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredmax_vs_i16m1_i16m1_m (vbool16_t mask, vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i16m1_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmax.vs.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmax_vs_i16m1_i16m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredmax_vs_i32m1_i32m1_m (vbool32_t mask, vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i32m1_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmax.vs.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmax_vs_i32m1_i32m1_m(mask, dst, vector, scalar);
}

vint64m1_t test_vredmax_vs_i64m1_i64m1_m (vbool64_t mask, vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredmax_vs_i64m1_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredmax.vs.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredmax_vs_i64m1_i64m1_m(mask, dst, vector, scalar);
}

vuint8m1_t test_vredmaxu_vs_u8m1_u8m1_m (vbool8_t mask, vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredmaxu_vs_u8m1_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmaxu.vs.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmaxu_vs_u8m1_u8m1_m(mask, dst, vector, scalar);
}

vuint16m1_t test_vredmaxu_vs_u16m1_u16m1_m (vbool16_t mask, vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredmaxu_vs_u16m1_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmaxu.vs.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmaxu_vs_u16m1_u16m1_m(mask, dst, vector, scalar);
}

vuint32m1_t test_vredmaxu_vs_u32m1_u32m1_m (vbool32_t mask, vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredmaxu_vs_u32m1_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmaxu.vs.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmaxu_vs_u32m1_u32m1_m(mask, dst, vector, scalar);
}

vuint64m1_t test_vredmaxu_vs_u64m1_u64m1_m (vbool64_t mask, vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredmaxu_vs_u64m1_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredmaxu.vs.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredmaxu_vs_u64m1_u64m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredmin_vs_i8m1_i8m1_m (vbool8_t mask, vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredmin_vs_i8m1_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredmin.vs.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredmin_vs_i8m1_i8m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredmin_vs_i16m1_i16m1_m (vbool16_t mask, vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredmin_vs_i16m1_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredmin.vs.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredmin_vs_i16m1_i16m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredmin_vs_i32m1_i32m1_m (vbool32_t mask, vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredmin_vs_i32m1_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredmin.vs.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredmin_vs_i32m1_i32m1_m(mask, dst, vector, scalar);
}

vint64m1_t test_vredmin_vs_i64m1_i64m1_m (vbool64_t mask, vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredmin_vs_i64m1_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredmin.vs.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredmin_vs_i64m1_i64m1_m(mask, dst, vector, scalar);
}

vuint8m1_t test_vredminu_vs_u8m1_u8m1_m (vbool8_t mask, vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredminu_vs_u8m1_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredminu.vs.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredminu_vs_u8m1_u8m1_m(mask, dst, vector, scalar);
}

vuint16m1_t test_vredminu_vs_u16m1_u16m1_m (vbool16_t mask, vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredminu_vs_u16m1_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredminu.vs.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredminu_vs_u16m1_u16m1_m(mask, dst, vector, scalar);
}

vuint32m1_t test_vredminu_vs_u32m1_u32m1_m (vbool32_t mask, vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredminu_vs_u32m1_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredminu.vs.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredminu_vs_u32m1_u32m1_m(mask, dst, vector, scalar);
}

vuint64m1_t test_vredminu_vs_u64m1_u64m1_m (vbool64_t mask, vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredminu_vs_u64m1_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredminu.vs.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredminu_vs_u64m1_u64m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredand_vs_i8m1_i8m1_m (vbool8_t mask, vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_i8m1_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredand.vs.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredand_vs_i8m1_i8m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredand_vs_i16m1_i16m1_m (vbool16_t mask, vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_i16m1_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredand.vs.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredand_vs_i16m1_i16m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredand_vs_i32m1_i32m1_m (vbool32_t mask, vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_i32m1_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredand.vs.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredand_vs_i32m1_i32m1_m(mask, dst, vector, scalar);
}

vint64m1_t test_vredand_vs_i64m1_i64m1_m (vbool64_t mask, vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_i64m1_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredand.vs.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredand_vs_i64m1_i64m1_m(mask, dst, vector, scalar);
}

vuint8m1_t test_vredand_vs_u8m1_u8m1_m (vbool8_t mask, vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_u8m1_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredand.vs.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredand_vs_u8m1_u8m1_m(mask, dst, vector, scalar);
}

vuint16m1_t test_vredand_vs_u16m1_u16m1_m (vbool16_t mask, vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_u16m1_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredand.vs.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredand_vs_u16m1_u16m1_m(mask, dst, vector, scalar);
}

vuint32m1_t test_vredand_vs_u32m1_u32m1_m (vbool32_t mask, vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_u32m1_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredand.vs.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredand_vs_u32m1_u32m1_m(mask, dst, vector, scalar);
}

vuint64m1_t test_vredand_vs_u64m1_u64m1_m (vbool64_t mask, vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredand_vs_u64m1_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredand.vs.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredand_vs_u64m1_u64m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredor_vs_i8m1_i8m1_m (vbool8_t mask, vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_i8m1_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredor.vs.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredor_vs_i8m1_i8m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredor_vs_i16m1_i16m1_m (vbool16_t mask, vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_i16m1_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredor.vs.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredor_vs_i16m1_i16m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredor_vs_i32m1_i32m1_m (vbool32_t mask, vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_i32m1_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredor.vs.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredor_vs_i32m1_i32m1_m(mask, dst, vector, scalar);
}

vint64m1_t test_vredor_vs_i64m1_i64m1_m (vbool64_t mask, vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_i64m1_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredor.vs.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredor_vs_i64m1_i64m1_m(mask, dst, vector, scalar);
}

vuint8m1_t test_vredor_vs_u8m1_u8m1_m (vbool8_t mask, vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_u8m1_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredor.vs.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredor_vs_u8m1_u8m1_m(mask, dst, vector, scalar);
}

vuint16m1_t test_vredor_vs_u16m1_u16m1_m (vbool16_t mask, vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_u16m1_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredor.vs.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredor_vs_u16m1_u16m1_m(mask, dst, vector, scalar);
}

vuint32m1_t test_vredor_vs_u32m1_u32m1_m (vbool32_t mask, vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_u32m1_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredor.vs.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredor_vs_u32m1_u32m1_m(mask, dst, vector, scalar);
}

vuint64m1_t test_vredor_vs_u64m1_u64m1_m (vbool64_t mask, vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredor_vs_u64m1_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredor.vs.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredor_vs_u64m1_u64m1_m(mask, dst, vector, scalar);
}

vint8m1_t test_vredxor_vs_i8m1_i8m1_m (vbool8_t mask, vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_i8m1_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredxor.vs.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredxor_vs_i8m1_i8m1_m(mask, dst, vector, scalar);
}

vint16m1_t test_vredxor_vs_i16m1_i16m1_m (vbool16_t mask, vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_i16m1_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredxor.vs.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredxor_vs_i16m1_i16m1_m(mask, dst, vector, scalar);
}

vint32m1_t test_vredxor_vs_i32m1_i32m1_m (vbool32_t mask, vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_i32m1_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredxor.vs.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredxor_vs_i32m1_i32m1_m(mask, dst, vector, scalar);
}

vint64m1_t test_vredxor_vs_i64m1_i64m1_m (vbool64_t mask, vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_i64m1_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredxor.vs.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredxor_vs_i64m1_i64m1_m(mask, dst, vector, scalar);
}

vuint8m1_t test_vredxor_vs_u8m1_u8m1_m (vbool8_t mask, vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_u8m1_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vredxor.vs.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vredxor_vs_u8m1_u8m1_m(mask, dst, vector, scalar);
}

vuint16m1_t test_vredxor_vs_u16m1_u16m1_m (vbool16_t mask, vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_u16m1_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vredxor.vs.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vredxor_vs_u16m1_u16m1_m(mask, dst, vector, scalar);
}

vuint32m1_t test_vredxor_vs_u32m1_u32m1_m (vbool32_t mask, vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_u32m1_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vredxor.vs.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vredxor_vs_u32m1_u32m1_m(mask, dst, vector, scalar);
}

vuint64m1_t test_vredxor_vs_u64m1_u64m1_m (vbool64_t mask, vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  // CHECK-LABEL: test_vredxor_vs_u64m1_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vredxor.vs.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vredxor_vs_u64m1_u64m1_m(mask, dst, vector, scalar);
}

