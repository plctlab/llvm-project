// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8_t test_vcopy_v_i8mf8 (vint8mf8_t src) {
  // CHECK-LABEL: test_vcopy_v_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vcopy.v.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}})
  return vcopy_v_i8mf8(src);
}

vint8mf4_t test_vcopy_v_i8mf4 (vint8mf4_t src) {
  // CHECK-LABEL: test_vcopy_v_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vcopy.v.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}})
  return vcopy_v_i8mf4(src);
}

vint8mf2_t test_vcopy_v_i8mf2 (vint8mf2_t src) {
  // CHECK-LABEL: test_vcopy_v_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vcopy.v.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}})
  return vcopy_v_i8mf2(src);
}

vint8m1_t test_vcopy_v_i8m1 (vint8m1_t src) {
  // CHECK-LABEL: test_vcopy_v_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcopy.v.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vcopy_v_i8m1(src);
}

vint8m2_t test_vcopy_v_i8m2 (vint8m2_t src) {
  // CHECK-LABEL: test_vcopy_v_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcopy.v.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vcopy_v_i8m2(src);
}

vint8m4_t test_vcopy_v_i8m4 (vint8m4_t src) {
  // CHECK-LABEL: test_vcopy_v_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcopy.v.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vcopy_v_i8m4(src);
}

vint8m8_t test_vcopy_v_i8m8 (vint8m8_t src) {
  // CHECK-LABEL: test_vcopy_v_i8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vcopy.v.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}})
  return vcopy_v_i8m8(src);
}

vint16mf4_t test_vcopy_v_i16mf4 (vint16mf4_t src) {
  // CHECK-LABEL: test_vcopy_v_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vcopy.v.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}})
  return vcopy_v_i16mf4(src);
}

vint16mf2_t test_vcopy_v_i16mf2 (vint16mf2_t src) {
  // CHECK-LABEL: test_vcopy_v_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vcopy.v.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}})
  return vcopy_v_i16mf2(src);
}

vint16m1_t test_vcopy_v_i16m1 (vint16m1_t src) {
  // CHECK-LABEL: test_vcopy_v_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vcopy.v.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vcopy_v_i16m1(src);
}

vint16m2_t test_vcopy_v_i16m2 (vint16m2_t src) {
  // CHECK-LABEL: test_vcopy_v_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcopy.v.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vcopy_v_i16m2(src);
}

vint16m4_t test_vcopy_v_i16m4 (vint16m4_t src) {
  // CHECK-LABEL: test_vcopy_v_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcopy.v.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vcopy_v_i16m4(src);
}

vint16m8_t test_vcopy_v_i16m8 (vint16m8_t src) {
  // CHECK-LABEL: test_vcopy_v_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcopy.v.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vcopy_v_i16m8(src);
}

vint32mf2_t test_vcopy_v_i32mf2 (vint32mf2_t src) {
  // CHECK-LABEL: test_vcopy_v_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vcopy.v.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}})
  return vcopy_v_i32mf2(src);
}

vint32m1_t test_vcopy_v_i32m1 (vint32m1_t src) {
  // CHECK-LABEL: test_vcopy_v_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vcopy.v.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}})
  return vcopy_v_i32m1(src);
}

vint32m2_t test_vcopy_v_i32m2 (vint32m2_t src) {
  // CHECK-LABEL: test_vcopy_v_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vcopy.v.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vcopy_v_i32m2(src);
}

vint32m4_t test_vcopy_v_i32m4 (vint32m4_t src) {
  // CHECK-LABEL: test_vcopy_v_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcopy.v.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vcopy_v_i32m4(src);
}

vint32m8_t test_vcopy_v_i32m8 (vint32m8_t src) {
  // CHECK-LABEL: test_vcopy_v_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcopy.v.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vcopy_v_i32m8(src);
}

vint64m1_t test_vcopy_v_i64m1 (vint64m1_t src) {
  // CHECK-LABEL: test_vcopy_v_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vcopy.v.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}})
  return vcopy_v_i64m1(src);
}

vint64m2_t test_vcopy_v_i64m2 (vint64m2_t src) {
  // CHECK-LABEL: test_vcopy_v_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vcopy.v.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}})
  return vcopy_v_i64m2(src);
}

vint64m4_t test_vcopy_v_i64m4 (vint64m4_t src) {
  // CHECK-LABEL: test_vcopy_v_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vcopy.v.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}})
  return vcopy_v_i64m4(src);
}

vint64m8_t test_vcopy_v_i64m8 (vint64m8_t src) {
  // CHECK-LABEL: test_vcopy_v_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcopy.v.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vcopy_v_i64m8(src);
}

vuint8mf8_t test_vcopy_v_u8mf8 (vuint8mf8_t src) {
  // CHECK-LABEL: test_vcopy_v_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vcopy.v.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}})
  return vcopy_v_u8mf8(src);
}

vuint8mf4_t test_vcopy_v_u8mf4 (vuint8mf4_t src) {
  // CHECK-LABEL: test_vcopy_v_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vcopy.v.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}})
  return vcopy_v_u8mf4(src);
}

vuint8mf2_t test_vcopy_v_u8mf2 (vuint8mf2_t src) {
  // CHECK-LABEL: test_vcopy_v_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vcopy.v.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}})
  return vcopy_v_u8mf2(src);
}

vuint8m1_t test_vcopy_v_u8m1 (vuint8m1_t src) {
  // CHECK-LABEL: test_vcopy_v_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcopy.v.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vcopy_v_u8m1(src);
}

vuint8m2_t test_vcopy_v_u8m2 (vuint8m2_t src) {
  // CHECK-LABEL: test_vcopy_v_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcopy.v.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vcopy_v_u8m2(src);
}

vuint8m4_t test_vcopy_v_u8m4 (vuint8m4_t src) {
  // CHECK-LABEL: test_vcopy_v_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcopy.v.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vcopy_v_u8m4(src);
}

vuint8m8_t test_vcopy_v_u8m8 (vuint8m8_t src) {
  // CHECK-LABEL: test_vcopy_v_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vcopy.v.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}})
  return vcopy_v_u8m8(src);
}

vuint16mf4_t test_vcopy_v_u16mf4 (vuint16mf4_t src) {
  // CHECK-LABEL: test_vcopy_v_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vcopy.v.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}})
  return vcopy_v_u16mf4(src);
}

vuint16mf2_t test_vcopy_v_u16mf2 (vuint16mf2_t src) {
  // CHECK-LABEL: test_vcopy_v_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vcopy.v.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}})
  return vcopy_v_u16mf2(src);
}

vuint16m1_t test_vcopy_v_u16m1 (vuint16m1_t src) {
  // CHECK-LABEL: test_vcopy_v_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vcopy.v.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vcopy_v_u16m1(src);
}

vuint16m2_t test_vcopy_v_u16m2 (vuint16m2_t src) {
  // CHECK-LABEL: test_vcopy_v_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcopy.v.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vcopy_v_u16m2(src);
}

vuint16m4_t test_vcopy_v_u16m4 (vuint16m4_t src) {
  // CHECK-LABEL: test_vcopy_v_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcopy.v.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vcopy_v_u16m4(src);
}

vuint16m8_t test_vcopy_v_u16m8 (vuint16m8_t src) {
  // CHECK-LABEL: test_vcopy_v_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcopy.v.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vcopy_v_u16m8(src);
}

vuint32mf2_t test_vcopy_v_u32mf2 (vuint32mf2_t src) {
  // CHECK-LABEL: test_vcopy_v_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vcopy.v.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}})
  return vcopy_v_u32mf2(src);
}

vuint32m1_t test_vcopy_v_u32m1 (vuint32m1_t src) {
  // CHECK-LABEL: test_vcopy_v_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vcopy.v.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}})
  return vcopy_v_u32m1(src);
}

vuint32m2_t test_vcopy_v_u32m2 (vuint32m2_t src) {
  // CHECK-LABEL: test_vcopy_v_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vcopy.v.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vcopy_v_u32m2(src);
}

vuint32m4_t test_vcopy_v_u32m4 (vuint32m4_t src) {
  // CHECK-LABEL: test_vcopy_v_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcopy.v.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vcopy_v_u32m4(src);
}

vuint32m8_t test_vcopy_v_u32m8 (vuint32m8_t src) {
  // CHECK-LABEL: test_vcopy_v_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcopy.v.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vcopy_v_u32m8(src);
}

vuint64m1_t test_vcopy_v_u64m1 (vuint64m1_t src) {
  // CHECK-LABEL: test_vcopy_v_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vcopy.v.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}})
  return vcopy_v_u64m1(src);
}

vuint64m2_t test_vcopy_v_u64m2 (vuint64m2_t src) {
  // CHECK-LABEL: test_vcopy_v_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vcopy.v.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}})
  return vcopy_v_u64m2(src);
}

vuint64m4_t test_vcopy_v_u64m4 (vuint64m4_t src) {
  // CHECK-LABEL: test_vcopy_v_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vcopy.v.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}})
  return vcopy_v_u64m4(src);
}

vuint64m8_t test_vcopy_v_u64m8 (vuint64m8_t src) {
  // CHECK-LABEL: test_vcopy_v_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcopy.v.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vcopy_v_u64m8(src);
}

vint8mf8x2_t test_vcopy_i8mf8x2 (vint8mf8x2_t src) {
  // CHECK-LABEL: test_vcopy_i8mf8x2
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vcopy.nxv1i8x2.{{.*}}(<vscale x 2 x i8> %{{.*}})
  return vcopy_i8mf8x2(src);
}

vint8mf8x3_t test_vcopy_i8mf8x3 (vint8mf8x3_t src) {
  // CHECK-LABEL: test_vcopy_i8mf8x3
  // CHECK: %{{.*}} = call <vscale x 3 x i8> @llvm.riscv.vcopy.nxv1i8x3.{{.*}}(<vscale x 3 x i8> %{{.*}})
  return vcopy_i8mf8x3(src);
}

vint8mf8x4_t test_vcopy_i8mf8x4 (vint8mf8x4_t src) {
  // CHECK-LABEL: test_vcopy_i8mf8x4
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vcopy.nxv1i8x4.{{.*}}(<vscale x 4 x i8> %{{.*}})
  return vcopy_i8mf8x4(src);
}

vint8mf8x5_t test_vcopy_i8mf8x5 (vint8mf8x5_t src) {
  // CHECK-LABEL: test_vcopy_i8mf8x5
  // CHECK: %{{.*}} = call <vscale x 5 x i8> @llvm.riscv.vcopy.nxv1i8x5.{{.*}}(<vscale x 5 x i8> %{{.*}})
  return vcopy_i8mf8x5(src);
}

vint8mf8x6_t test_vcopy_i8mf8x6 (vint8mf8x6_t src) {
  // CHECK-LABEL: test_vcopy_i8mf8x6
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vcopy.nxv1i8x6.{{.*}}(<vscale x 6 x i8> %{{.*}})
  return vcopy_i8mf8x6(src);
}

vint8mf8x7_t test_vcopy_i8mf8x7 (vint8mf8x7_t src) {
  // CHECK-LABEL: test_vcopy_i8mf8x7
  // CHECK: %{{.*}} = call <vscale x 7 x i8> @llvm.riscv.vcopy.nxv1i8x7.{{.*}}(<vscale x 7 x i8> %{{.*}})
  return vcopy_i8mf8x7(src);
}

vint8mf8x8_t test_vcopy_i8mf8x8 (vint8mf8x8_t src) {
  // CHECK-LABEL: test_vcopy_i8mf8x8
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcopy.nxv1i8x8.{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vcopy_i8mf8x8(src);
}

vint8mf4x2_t test_vcopy_i8mf4x2 (vint8mf4x2_t src) {
  // CHECK-LABEL: test_vcopy_i8mf4x2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vcopy.nxv2i8x2.{{.*}}(<vscale x 4 x i8> %{{.*}})
  return vcopy_i8mf4x2(src);
}

vint8mf4x3_t test_vcopy_i8mf4x3 (vint8mf4x3_t src) {
  // CHECK-LABEL: test_vcopy_i8mf4x3
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vcopy.nxv2i8x3.{{.*}}(<vscale x 6 x i8> %{{.*}})
  return vcopy_i8mf4x3(src);
}

vint8mf4x4_t test_vcopy_i8mf4x4 (vint8mf4x4_t src) {
  // CHECK-LABEL: test_vcopy_i8mf4x4
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcopy.nxv2i8x4.{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vcopy_i8mf4x4(src);
}

vint8mf4x5_t test_vcopy_i8mf4x5 (vint8mf4x5_t src) {
  // CHECK-LABEL: test_vcopy_i8mf4x5
  // CHECK: %{{.*}} = call <vscale x 10 x i8> @llvm.riscv.vcopy.nxv2i8x5.{{.*}}(<vscale x 10 x i8> %{{.*}})
  return vcopy_i8mf4x5(src);
}

vint8mf4x6_t test_vcopy_i8mf4x6 (vint8mf4x6_t src) {
  // CHECK-LABEL: test_vcopy_i8mf4x6
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vcopy.nxv2i8x6.{{.*}}(<vscale x 12 x i8> %{{.*}})
  return vcopy_i8mf4x6(src);
}

vint8mf4x7_t test_vcopy_i8mf4x7 (vint8mf4x7_t src) {
  // CHECK-LABEL: test_vcopy_i8mf4x7
  // CHECK: %{{.*}} = call <vscale x 14 x i8> @llvm.riscv.vcopy.nxv2i8x7.{{.*}}(<vscale x 14 x i8> %{{.*}})
  return vcopy_i8mf4x7(src);
}

vint8mf4x8_t test_vcopy_i8mf4x8 (vint8mf4x8_t src) {
  // CHECK-LABEL: test_vcopy_i8mf4x8
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcopy.nxv2i8x8.{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vcopy_i8mf4x8(src);
}

vint8mf2x2_t test_vcopy_i8mf2x2 (vint8mf2x2_t src) {
  // CHECK-LABEL: test_vcopy_i8mf2x2
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcopy.nxv4i8x2.{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vcopy_i8mf2x2(src);
}

vint8mf2x3_t test_vcopy_i8mf2x3 (vint8mf2x3_t src) {
  // CHECK-LABEL: test_vcopy_i8mf2x3
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vcopy.nxv4i8x3.{{.*}}(<vscale x 12 x i8> %{{.*}})
  return vcopy_i8mf2x3(src);
}

vint8mf2x4_t test_vcopy_i8mf2x4 (vint8mf2x4_t src) {
  // CHECK-LABEL: test_vcopy_i8mf2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcopy.nxv4i8x4.{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vcopy_i8mf2x4(src);
}

vint8mf2x5_t test_vcopy_i8mf2x5 (vint8mf2x5_t src) {
  // CHECK-LABEL: test_vcopy_i8mf2x5
  // CHECK: %{{.*}} = call <vscale x 20 x i8> @llvm.riscv.vcopy.nxv4i8x5.{{.*}}(<vscale x 20 x i8> %{{.*}})
  return vcopy_i8mf2x5(src);
}

vint8mf2x6_t test_vcopy_i8mf2x6 (vint8mf2x6_t src) {
  // CHECK-LABEL: test_vcopy_i8mf2x6
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vcopy.nxv4i8x6.{{.*}}(<vscale x 24 x i8> %{{.*}})
  return vcopy_i8mf2x6(src);
}

vint8mf2x7_t test_vcopy_i8mf2x7 (vint8mf2x7_t src) {
  // CHECK-LABEL: test_vcopy_i8mf2x7
  // CHECK: %{{.*}} = call <vscale x 28 x i8> @llvm.riscv.vcopy.nxv4i8x7.{{.*}}(<vscale x 28 x i8> %{{.*}})
  return vcopy_i8mf2x7(src);
}

vint8mf2x8_t test_vcopy_i8mf2x8 (vint8mf2x8_t src) {
  // CHECK-LABEL: test_vcopy_i8mf2x8
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcopy.nxv4i8x8.{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vcopy_i8mf2x8(src);
}

vint8m1x2_t test_vcopy_i8m1x2 (vint8m1x2_t src) {
  // CHECK-LABEL: test_vcopy_i8m1x2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcopy.nxv8i8x2.{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vcopy_i8m1x2(src);
}

vint8m1x3_t test_vcopy_i8m1x3 (vint8m1x3_t src) {
  // CHECK-LABEL: test_vcopy_i8m1x3
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vcopy.nxv8i8x3.{{.*}}(<vscale x 24 x i8> %{{.*}})
  return vcopy_i8m1x3(src);
}

vint8m1x4_t test_vcopy_i8m1x4 (vint8m1x4_t src) {
  // CHECK-LABEL: test_vcopy_i8m1x4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcopy.nxv8i8x4.{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vcopy_i8m1x4(src);
}

vint8m1x5_t test_vcopy_i8m1x5 (vint8m1x5_t src) {
  // CHECK-LABEL: test_vcopy_i8m1x5
  // CHECK: %{{.*}} = call <vscale x 40 x i8> @llvm.riscv.vcopy.nxv8i8x5.{{.*}}(<vscale x 40 x i8> %{{.*}})
  return vcopy_i8m1x5(src);
}

vint8m1x6_t test_vcopy_i8m1x6 (vint8m1x6_t src) {
  // CHECK-LABEL: test_vcopy_i8m1x6
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vcopy.nxv8i8x6.{{.*}}(<vscale x 48 x i8> %{{.*}})
  return vcopy_i8m1x6(src);
}

vint8m1x7_t test_vcopy_i8m1x7 (vint8m1x7_t src) {
  // CHECK-LABEL: test_vcopy_i8m1x7
  // CHECK: %{{.*}} = call <vscale x 56 x i8> @llvm.riscv.vcopy.nxv8i8x7.{{.*}}(<vscale x 56 x i8> %{{.*}})
  return vcopy_i8m1x7(src);
}

vint8m1x8_t test_vcopy_i8m1x8 (vint8m1x8_t src) {
  // CHECK-LABEL: test_vcopy_i8m1x8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vcopy.nxv8i8x8.{{.*}}(<vscale x 64 x i8> %{{.*}})
  return vcopy_i8m1x8(src);
}

vint8m2x2_t test_vcopy_i8m2x2 (vint8m2x2_t src) {
  // CHECK-LABEL: test_vcopy_i8m2x2
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcopy.nxv16i8x2.{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vcopy_i8m2x2(src);
}

vint8m2x3_t test_vcopy_i8m2x3 (vint8m2x3_t src) {
  // CHECK-LABEL: test_vcopy_i8m2x3
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vcopy.nxv16i8x3.{{.*}}(<vscale x 48 x i8> %{{.*}})
  return vcopy_i8m2x3(src);
}

vint8m2x4_t test_vcopy_i8m2x4 (vint8m2x4_t src) {
  // CHECK-LABEL: test_vcopy_i8m2x4
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vcopy.nxv16i8x4.{{.*}}(<vscale x 64 x i8> %{{.*}})
  return vcopy_i8m2x4(src);
}

vint8m4x2_t test_vcopy_i8m4x2 (vint8m4x2_t src) {
  // CHECK-LABEL: test_vcopy_i8m4x2
  // CHECK: %{{.*}} = call <vscale x 54 x i8> @llvm.riscv.vcopy.nxv32i8x2.{{.*}}(<vscale x 54 x i8> %{{.*}})
  return vcopy_i8m4x2(src);
}

vint16mf4x2_t test_vcopy_i16mf4x2 (vint16mf4x2_t src) {
  // CHECK-LABEL: test_vcopy_i16mf4x2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vcopy.nxv1i16x2.{{.*}}(<vscale x 2 x i16> %{{.*}})
  return vcopy_i16mf4x2(src);
}

vint16mf4x3_t test_vcopy_i16mf4x3 (vint16mf4x3_t src) {
  // CHECK-LABEL: test_vcopy_i16mf4x3
  // CHECK: %{{.*}} = call <vscale x 3 x i16> @llvm.riscv.vcopy.nxv1i16x3.{{.*}}(<vscale x 3 x i16> %{{.*}})
  return vcopy_i16mf4x3(src);
}

vint16mf4x4_t test_vcopy_i16mf4x4 (vint16mf4x4_t src) {
  // CHECK-LABEL: test_vcopy_i16mf4x4
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vcopy.nxv1i16x4.{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vcopy_i16mf4x4(src);
}

vint16mf4x5_t test_vcopy_i16mf4x5 (vint16mf4x5_t src) {
  // CHECK-LABEL: test_vcopy_i16mf4x5
  // CHECK: %{{.*}} = call <vscale x 5 x i16> @llvm.riscv.vcopy.nxv1i16x5.{{.*}}(<vscale x 5 x i16> %{{.*}})
  return vcopy_i16mf4x5(src);
}

vint16mf4x6_t test_vcopy_i16mf4x6 (vint16mf4x6_t src) {
  // CHECK-LABEL: test_vcopy_i16mf4x6
  // CHECK: %{{.*}} = call <vscale x 6 x i16> @llvm.riscv.vcopy.nxv1i16x6.{{.*}}(<vscale x 6 x i16> %{{.*}})
  return vcopy_i16mf4x6(src);
}

vint16mf4x7_t test_vcopy_i16mf4x7 (vint16mf4x7_t src) {
  // CHECK-LABEL: test_vcopy_i16mf4x7
  // CHECK: %{{.*}} = call <vscale x 7 x i16> @llvm.riscv.vcopy.nxv1i16x7.{{.*}}(<vscale x 7 x i16> %{{.*}})
  return vcopy_i16mf4x7(src);
}

vint16mf4x8_t test_vcopy_i16mf4x8 (vint16mf4x8_t src) {
  // CHECK-LABEL: test_vcopy_i16mf4x8
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcopy.nxv1i16x8.{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vcopy_i16mf4x8(src);
}

vint16mf2x2_t test_vcopy_i16mf2x2 (vint16mf2x2_t src) {
  // CHECK-LABEL: test_vcopy_i16mf2x2
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vcopy.nxv2i16x2.{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vcopy_i16mf2x2(src);
}

vint16mf2x3_t test_vcopy_i16mf2x3 (vint16mf2x3_t src) {
  // CHECK-LABEL: test_vcopy_i16mf2x3
  // CHECK: %{{.*}} = call <vscale x 6 x i16> @llvm.riscv.vcopy.nxv2i16x3.{{.*}}(<vscale x 6 x i16> %{{.*}})
  return vcopy_i16mf2x3(src);
}

vint16mf2x4_t test_vcopy_i16mf2x4 (vint16mf2x4_t src) {
  // CHECK-LABEL: test_vcopy_i16mf2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcopy.nxv2i16x4.{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vcopy_i16mf2x4(src);
}

vint16mf2x5_t test_vcopy_i16mf2x5 (vint16mf2x5_t src) {
  // CHECK-LABEL: test_vcopy_i16mf2x5
  // CHECK: %{{.*}} = call <vscale x 10 x i16> @llvm.riscv.vcopy.nxv2i16x5.{{.*}}(<vscale x 10 x i16> %{{.*}})
  return vcopy_i16mf2x5(src);
}

vint16mf2x6_t test_vcopy_i16mf2x6 (vint16mf2x6_t src) {
  // CHECK-LABEL: test_vcopy_i16mf2x6
  // CHECK: %{{.*}} = call <vscale x 12 x i16> @llvm.riscv.vcopy.nxv2i16x6.{{.*}}(<vscale x 12 x i16> %{{.*}})
  return vcopy_i16mf2x6(src);
}

vint16mf2x7_t test_vcopy_i16mf2x7 (vint16mf2x7_t src) {
  // CHECK-LABEL: test_vcopy_i16mf2x7
  // CHECK: %{{.*}} = call <vscale x 14 x i16> @llvm.riscv.vcopy.nxv2i16x7.{{.*}}(<vscale x 14 x i16> %{{.*}})
  return vcopy_i16mf2x7(src);
}

vint16mf2x8_t test_vcopy_i16mf2x8 (vint16mf2x8_t src) {
  // CHECK-LABEL: test_vcopy_i16mf2x8
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcopy.nxv2i16x8.{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vcopy_i16mf2x8(src);
}

vint16m1x2_t test_vcopy_i16m1x2 (vint16m1x2_t src) {
  // CHECK-LABEL: test_vcopy_i16m1x2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcopy.nxv4i16x2.{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vcopy_i16m1x2(src);
}

vint16m1x3_t test_vcopy_i16m1x3 (vint16m1x3_t src) {
  // CHECK-LABEL: test_vcopy_i16m1x3
  // CHECK: %{{.*}} = call <vscale x 12 x i16> @llvm.riscv.vcopy.nxv4i16x3.{{.*}}(<vscale x 12 x i16> %{{.*}})
  return vcopy_i16m1x3(src);
}

vint16m1x4_t test_vcopy_i16m1x4 (vint16m1x4_t src) {
  // CHECK-LABEL: test_vcopy_i16m1x4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcopy.nxv4i16x4.{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vcopy_i16m1x4(src);
}

vint16m1x5_t test_vcopy_i16m1x5 (vint16m1x5_t src) {
  // CHECK-LABEL: test_vcopy_i16m1x5
  // CHECK: %{{.*}} = call <vscale x 20 x i16> @llvm.riscv.vcopy.nxv4i16x5.{{.*}}(<vscale x 20 x i16> %{{.*}})
  return vcopy_i16m1x5(src);
}

vint16m1x6_t test_vcopy_i16m1x6 (vint16m1x6_t src) {
  // CHECK-LABEL: test_vcopy_i16m1x6
  // CHECK: %{{.*}} = call <vscale x 24 x i16> @llvm.riscv.vcopy.nxv4i16x6.{{.*}}(<vscale x 24 x i16> %{{.*}})
  return vcopy_i16m1x6(src);
}

vint16m1x7_t test_vcopy_i16m1x7 (vint16m1x7_t src) {
  // CHECK-LABEL: test_vcopy_i16m1x7
  // CHECK: %{{.*}} = call <vscale x 28 x i16> @llvm.riscv.vcopy.nxv4i16x7.{{.*}}(<vscale x 28 x i16> %{{.*}})
  return vcopy_i16m1x7(src);
}

vint16m1x8_t test_vcopy_i16m1x8 (vint16m1x8_t src) {
  // CHECK-LABEL: test_vcopy_i16m1x8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcopy.nxv4i16x8.{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vcopy_i16m1x8(src);
}

vint16m2x2_t test_vcopy_i16m2x2 (vint16m2x2_t src) {
  // CHECK-LABEL: test_vcopy_i16m2x2
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcopy.nxv8i16x2.{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vcopy_i16m2x2(src);
}

vint16m2x3_t test_vcopy_i16m2x3 (vint16m2x3_t src) {
  // CHECK-LABEL: test_vcopy_i16m2x3
  // CHECK: %{{.*}} = call <vscale x 24 x i16> @llvm.riscv.vcopy.nxv8i16x3.{{.*}}(<vscale x 24 x i16> %{{.*}})
  return vcopy_i16m2x3(src);
}

vint16m2x4_t test_vcopy_i16m2x4 (vint16m2x4_t src) {
  // CHECK-LABEL: test_vcopy_i16m2x4
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcopy.nxv8i16x4.{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vcopy_i16m2x4(src);
}

vint16m4x2_t test_vcopy_i16m4x2 (vint16m4x2_t src) {
  // CHECK-LABEL: test_vcopy_i16m4x2
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcopy.nxv16i16x2.{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vcopy_i16m4x2(src);
}

vint32mf2x2_t test_vcopy_i32mf2x2 (vint32mf2x2_t src) {
  // CHECK-LABEL: test_vcopy_i32mf2x2
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vcopy.nxv1i32x2.{{.*}}(<vscale x 2 x i32> %{{.*}})
  return vcopy_i32mf2x2(src);
}

vint32mf2x3_t test_vcopy_i32mf2x3 (vint32mf2x3_t src) {
  // CHECK-LABEL: test_vcopy_i32mf2x3
  // CHECK: %{{.*}} = call <vscale x 3 x i32> @llvm.riscv.vcopy.nxv1i32x3.{{.*}}(<vscale x 3 x i32> %{{.*}})
  return vcopy_i32mf2x3(src);
}

vint32mf2x4_t test_vcopy_i32mf2x4 (vint32mf2x4_t src) {
  // CHECK-LABEL: test_vcopy_i32mf2x4
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vcopy.nxv1i32x4.{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vcopy_i32mf2x4(src);
}

vint32mf2x5_t test_vcopy_i32mf2x5 (vint32mf2x5_t src) {
  // CHECK-LABEL: test_vcopy_i32mf2x5
  // CHECK: %{{.*}} = call <vscale x 5 x i32> @llvm.riscv.vcopy.nxv1i32x5.{{.*}}(<vscale x 5 x i32> %{{.*}})
  return vcopy_i32mf2x5(src);
}

vint32mf2x6_t test_vcopy_i32mf2x6 (vint32mf2x6_t src) {
  // CHECK-LABEL: test_vcopy_i32mf2x6
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vcopy.nxv1i32x6.{{.*}}(<vscale x 6 x i32> %{{.*}})
  return vcopy_i32mf2x6(src);
}

vint32mf2x7_t test_vcopy_i32mf2x7 (vint32mf2x7_t src) {
  // CHECK-LABEL: test_vcopy_i32mf2x7
  // CHECK: %{{.*}} = call <vscale x 7 x i32> @llvm.riscv.vcopy.nxv1i32x7.{{.*}}(<vscale x 7 x i32> %{{.*}})
  return vcopy_i32mf2x7(src);
}

vint32mf2x8_t test_vcopy_i32mf2x8 (vint32mf2x8_t src) {
  // CHECK-LABEL: test_vcopy_i32mf2x8
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcopy.nxv1i32x8.{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vcopy_i32mf2x8(src);
}

vint32m1x2_t test_vcopy_i32m1x2 (vint32m1x2_t src) {
  // CHECK-LABEL: test_vcopy_i32m1x2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vcopy.nxv2i32x2.{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vcopy_i32m1x2(src);
}

vint32m1x3_t test_vcopy_i32m1x3 (vint32m1x3_t src) {
  // CHECK-LABEL: test_vcopy_i32m1x3
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vcopy.nxv2i32x3.{{.*}}(<vscale x 6 x i32> %{{.*}})
  return vcopy_i32m1x3(src);
}

vint32m1x4_t test_vcopy_i32m1x4 (vint32m1x4_t src) {
  // CHECK-LABEL: test_vcopy_i32m1x4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcopy.nxv2i32x4.{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vcopy_i32m1x4(src);
}

vint32m1x5_t test_vcopy_i32m1x5 (vint32m1x5_t src) {
  // CHECK-LABEL: test_vcopy_i32m1x5
  // CHECK: %{{.*}} = call <vscale x 10 x i32> @llvm.riscv.vcopy.nxv2i32x5.{{.*}}(<vscale x 10 x i32> %{{.*}})
  return vcopy_i32m1x5(src);
}

vint32m1x6_t test_vcopy_i32m1x6 (vint32m1x6_t src) {
  // CHECK-LABEL: test_vcopy_i32m1x6
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vcopy.nxv2i32x6.{{.*}}(<vscale x 12 x i32> %{{.*}})
  return vcopy_i32m1x6(src);
}

vint32m1x7_t test_vcopy_i32m1x7 (vint32m1x7_t src) {
  // CHECK-LABEL: test_vcopy_i32m1x7
  // CHECK: %{{.*}} = call <vscale x 14 x i32> @llvm.riscv.vcopy.nxv2i32x7.{{.*}}(<vscale x 14 x i32> %{{.*}})
  return vcopy_i32m1x7(src);
}

vint32m1x8_t test_vcopy_i32m1x8 (vint32m1x8_t src) {
  // CHECK-LABEL: test_vcopy_i32m1x8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcopy.nxv2i32x8.{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vcopy_i32m1x8(src);
}

vint32m2x2_t test_vcopy_i32m2x2 (vint32m2x2_t src) {
  // CHECK-LABEL: test_vcopy_i32m2x2
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcopy.nxv4i32x2.{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vcopy_i32m2x2(src);
}

vint32m2x3_t test_vcopy_i32m2x3 (vint32m2x3_t src) {
  // CHECK-LABEL: test_vcopy_i32m2x3
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vcopy.nxv4i32x3.{{.*}}(<vscale x 12 x i32> %{{.*}})
  return vcopy_i32m2x3(src);
}

vint32m2x4_t test_vcopy_i32m2x4 (vint32m2x4_t src) {
  // CHECK-LABEL: test_vcopy_i32m2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcopy.nxv4i32x4.{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vcopy_i32m2x4(src);
}

vint32m4x2_t test_vcopy_i32m4x2 (vint32m4x2_t src) {
  // CHECK-LABEL: test_vcopy_i32m4x2
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcopy.nxv8i32x2.{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vcopy_i32m4x2(src);
}

vint64m1x2_t test_vcopy_i64m1x2 (vint64m1x2_t src) {
  // CHECK-LABEL: test_vcopy_i64m1x2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vcopy.nxv1i64x2.{{.*}}(<vscale x 2 x i64> %{{.*}})
  return vcopy_i64m1x2(src);
}

vint64m1x3_t test_vcopy_i64m1x3 (vint64m1x3_t src) {
  // CHECK-LABEL: test_vcopy_i64m1x3
  // CHECK: %{{.*}} = call <vscale x 3 x i64> @llvm.riscv.vcopy.nxv1i64x3.{{.*}}(<vscale x 3 x i64> %{{.*}})
  return vcopy_i64m1x3(src);
}

vint64m1x4_t test_vcopy_i64m1x4 (vint64m1x4_t src) {
  // CHECK-LABEL: test_vcopy_i64m1x4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vcopy.nxv1i64x4.{{.*}}(<vscale x 4 x i64> %{{.*}})
  return vcopy_i64m1x4(src);
}

vint64m1x5_t test_vcopy_i64m1x5 (vint64m1x5_t src) {
  // CHECK-LABEL: test_vcopy_i64m1x5
  // CHECK: %{{.*}} = call <vscale x 5 x i64> @llvm.riscv.vcopy.nxv1i64x5.{{.*}}(<vscale x 5 x i64> %{{.*}})
  return vcopy_i64m1x5(src);
}

vint64m1x6_t test_vcopy_i64m1x6 (vint64m1x6_t src) {
  // CHECK-LABEL: test_vcopy_i64m1x6
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vcopy.nxv1i64x6.{{.*}}(<vscale x 6 x i64> %{{.*}})
  return vcopy_i64m1x6(src);
}

vint64m1x7_t test_vcopy_i64m1x7 (vint64m1x7_t src) {
  // CHECK-LABEL: test_vcopy_i64m1x7
  // CHECK: %{{.*}} = call <vscale x 7 x i64> @llvm.riscv.vcopy.nxv1i64x7.{{.*}}(<vscale x 7 x i64> %{{.*}})
  return vcopy_i64m1x7(src);
}

vint64m1x8_t test_vcopy_i64m1x8 (vint64m1x8_t src) {
  // CHECK-LABEL: test_vcopy_i64m1x8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcopy.nxv1i64x8.{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vcopy_i64m1x8(src);
}

vint64m2x2_t test_vcopy_i64m2x2 (vint64m2x2_t src) {
  // CHECK-LABEL: test_vcopy_i64m2x2
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vcopy.nxv2i64x2.{{.*}}(<vscale x 4 x i64> %{{.*}})
  return vcopy_i64m2x2(src);
}

vint64m2x3_t test_vcopy_i64m2x3 (vint64m2x3_t src) {
  // CHECK-LABEL: test_vcopy_i64m2x3
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vcopy.nxv2i64x3.{{.*}}(<vscale x 6 x i64> %{{.*}})
  return vcopy_i64m2x3(src);
}

vint64m2x4_t test_vcopy_i64m2x4 (vint64m2x4_t src) {
  // CHECK-LABEL: test_vcopy_i64m2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcopy.nxv2i64x4.{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vcopy_i64m2x4(src);
}

vint64m4x2_t test_vcopy_i64m4x2 (vint64m4x2_t src) {
  // CHECK-LABEL: test_vcopy_i64m4x2
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcopy.nxv4i64x2.{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vcopy_i64m4x2(src);
}

vuint8mf8x2_t test_vcopy_u8mf8x2 (vuint8mf8x2_t src) {
  // CHECK-LABEL: test_vcopy_u8mf8x2
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vcopy.nxv1i8x2.{{.*}}(<vscale x 2 x i8> %{{.*}})
  return vcopy_u8mf8x2(src);
}

vuint8mf8x3_t test_vcopy_u8mf8x3 (vuint8mf8x3_t src) {
  // CHECK-LABEL: test_vcopy_u8mf8x3
  // CHECK: %{{.*}} = call <vscale x 3 x i8> @llvm.riscv.vcopy.nxv1i8x3.{{.*}}(<vscale x 3 x i8> %{{.*}})
  return vcopy_u8mf8x3(src);
}

vuint8mf8x4_t test_vcopy_u8mf8x4 (vuint8mf8x4_t src) {
  // CHECK-LABEL: test_vcopy_u8mf8x4
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vcopy.nxv1i8x4.{{.*}}(<vscale x 4 x i8> %{{.*}})
  return vcopy_u8mf8x4(src);
}

vuint8mf8x5_t test_vcopy_u8mf8x5 (vuint8mf8x5_t src) {
  // CHECK-LABEL: test_vcopy_u8mf8x5
  // CHECK: %{{.*}} = call <vscale x 5 x i8> @llvm.riscv.vcopy.nxv1i8x5.{{.*}}(<vscale x 5 x i8> %{{.*}})
  return vcopy_u8mf8x5(src);
}

vuint8mf8x6_t test_vcopy_u8mf8x6 (vuint8mf8x6_t src) {
  // CHECK-LABEL: test_vcopy_u8mf8x6
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vcopy.nxv1i8x6.{{.*}}(<vscale x 6 x i8> %{{.*}})
  return vcopy_u8mf8x6(src);
}

vuint8mf8x7_t test_vcopy_u8mf8x7 (vuint8mf8x7_t src) {
  // CHECK-LABEL: test_vcopy_u8mf8x7
  // CHECK: %{{.*}} = call <vscale x 7 x i8> @llvm.riscv.vcopy.nxv1i8x7.{{.*}}(<vscale x 7 x i8> %{{.*}})
  return vcopy_u8mf8x7(src);
}

vuint8mf8x8_t test_vcopy_u8mf8x8 (vuint8mf8x8_t src) {
  // CHECK-LABEL: test_vcopy_u8mf8x8
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcopy.nxv1i8x8.{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vcopy_u8mf8x8(src);
}

vuint8mf4x2_t test_vcopy_u8mf4x2 (vuint8mf4x2_t src) {
  // CHECK-LABEL: test_vcopy_u8mf4x2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vcopy.nxv2i8x2.{{.*}}(<vscale x 4 x i8> %{{.*}})
  return vcopy_u8mf4x2(src);
}

vuint8mf4x3_t test_vcopy_u8mf4x3 (vuint8mf4x3_t src) {
  // CHECK-LABEL: test_vcopy_u8mf4x3
  // CHECK: %{{.*}} = call <vscale x 6 x i8> @llvm.riscv.vcopy.nxv2i8x3.{{.*}}(<vscale x 6 x i8> %{{.*}})
  return vcopy_u8mf4x3(src);
}

vuint8mf4x4_t test_vcopy_u8mf4x4 (vuint8mf4x4_t src) {
  // CHECK-LABEL: test_vcopy_u8mf4x4
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcopy.nxv2i8x4.{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vcopy_u8mf4x4(src);
}

vuint8mf4x5_t test_vcopy_u8mf4x5 (vuint8mf4x5_t src) {
  // CHECK-LABEL: test_vcopy_u8mf4x5
  // CHECK: %{{.*}} = call <vscale x 10 x i8> @llvm.riscv.vcopy.nxv2i8x5.{{.*}}(<vscale x 10 x i8> %{{.*}})
  return vcopy_u8mf4x5(src);
}

vuint8mf4x6_t test_vcopy_u8mf4x6 (vuint8mf4x6_t src) {
  // CHECK-LABEL: test_vcopy_u8mf4x6
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vcopy.nxv2i8x6.{{.*}}(<vscale x 12 x i8> %{{.*}})
  return vcopy_u8mf4x6(src);
}

vuint8mf4x7_t test_vcopy_u8mf4x7 (vuint8mf4x7_t src) {
  // CHECK-LABEL: test_vcopy_u8mf4x7
  // CHECK: %{{.*}} = call <vscale x 14 x i8> @llvm.riscv.vcopy.nxv2i8x7.{{.*}}(<vscale x 14 x i8> %{{.*}})
  return vcopy_u8mf4x7(src);
}

vuint8mf4x8_t test_vcopy_u8mf4x8 (vuint8mf4x8_t src) {
  // CHECK-LABEL: test_vcopy_u8mf4x8
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcopy.nxv2i8x8.{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vcopy_u8mf4x8(src);
}

vuint8mf2x2_t test_vcopy_u8mf2x2 (vuint8mf2x2_t src) {
  // CHECK-LABEL: test_vcopy_u8mf2x2
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcopy.nxv4i8x2.{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vcopy_u8mf2x2(src);
}

vuint8mf2x3_t test_vcopy_u8mf2x3 (vuint8mf2x3_t src) {
  // CHECK-LABEL: test_vcopy_u8mf2x3
  // CHECK: %{{.*}} = call <vscale x 12 x i8> @llvm.riscv.vcopy.nxv4i8x3.{{.*}}(<vscale x 12 x i8> %{{.*}})
  return vcopy_u8mf2x3(src);
}

vuint8mf2x4_t test_vcopy_u8mf2x4 (vuint8mf2x4_t src) {
  // CHECK-LABEL: test_vcopy_u8mf2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcopy.nxv4i8x4.{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vcopy_u8mf2x4(src);
}

vuint8mf2x5_t test_vcopy_u8mf2x5 (vuint8mf2x5_t src) {
  // CHECK-LABEL: test_vcopy_u8mf2x5
  // CHECK: %{{.*}} = call <vscale x 20 x i8> @llvm.riscv.vcopy.nxv4i8x5.{{.*}}(<vscale x 20 x i8> %{{.*}})
  return vcopy_u8mf2x5(src);
}

vuint8mf2x6_t test_vcopy_u8mf2x6 (vuint8mf2x6_t src) {
  // CHECK-LABEL: test_vcopy_u8mf2x6
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vcopy.nxv4i8x6.{{.*}}(<vscale x 24 x i8> %{{.*}})
  return vcopy_u8mf2x6(src);
}

vuint8mf2x7_t test_vcopy_u8mf2x7 (vuint8mf2x7_t src) {
  // CHECK-LABEL: test_vcopy_u8mf2x7
  // CHECK: %{{.*}} = call <vscale x 28 x i8> @llvm.riscv.vcopy.nxv4i8x7.{{.*}}(<vscale x 28 x i8> %{{.*}})
  return vcopy_u8mf2x7(src);
}

vuint8mf2x8_t test_vcopy_u8mf2x8 (vuint8mf2x8_t src) {
  // CHECK-LABEL: test_vcopy_u8mf2x8
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcopy.nxv4i8x8.{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vcopy_u8mf2x8(src);
}

vuint8m1x2_t test_vcopy_u8m1x2 (vuint8m1x2_t src) {
  // CHECK-LABEL: test_vcopy_u8m1x2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcopy.nxv8i8x2.{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vcopy_u8m1x2(src);
}

vuint8m1x3_t test_vcopy_u8m1x3 (vuint8m1x3_t src) {
  // CHECK-LABEL: test_vcopy_u8m1x3
  // CHECK: %{{.*}} = call <vscale x 24 x i8> @llvm.riscv.vcopy.nxv8i8x3.{{.*}}(<vscale x 24 x i8> %{{.*}})
  return vcopy_u8m1x3(src);
}

vuint8m1x4_t test_vcopy_u8m1x4 (vuint8m1x4_t src) {
  // CHECK-LABEL: test_vcopy_u8m1x4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcopy.nxv8i8x4.{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vcopy_u8m1x4(src);
}

vuint8m1x5_t test_vcopy_u8m1x5 (vuint8m1x5_t src) {
  // CHECK-LABEL: test_vcopy_u8m1x5
  // CHECK: %{{.*}} = call <vscale x 40 x i8> @llvm.riscv.vcopy.nxv8i8x5.{{.*}}(<vscale x 40 x i8> %{{.*}})
  return vcopy_u8m1x5(src);
}

vuint8m1x6_t test_vcopy_u8m1x6 (vuint8m1x6_t src) {
  // CHECK-LABEL: test_vcopy_u8m1x6
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vcopy.nxv8i8x6.{{.*}}(<vscale x 48 x i8> %{{.*}})
  return vcopy_u8m1x6(src);
}

vuint8m1x7_t test_vcopy_u8m1x7 (vuint8m1x7_t src) {
  // CHECK-LABEL: test_vcopy_u8m1x7
  // CHECK: %{{.*}} = call <vscale x 56 x i8> @llvm.riscv.vcopy.nxv8i8x7.{{.*}}(<vscale x 56 x i8> %{{.*}})
  return vcopy_u8m1x7(src);
}

vuint8m1x8_t test_vcopy_u8m1x8 (vuint8m1x8_t src) {
  // CHECK-LABEL: test_vcopy_u8m1x8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vcopy.nxv8i8x8.{{.*}}(<vscale x 64 x i8> %{{.*}})
  return vcopy_u8m1x8(src);
}

vuint8m2x2_t test_vcopy_u8m2x2 (vuint8m2x2_t src) {
  // CHECK-LABEL: test_vcopy_u8m2x2
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcopy.nxv16i8x2.{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vcopy_u8m2x2(src);
}

vuint8m2x3_t test_vcopy_u8m2x3 (vuint8m2x3_t src) {
  // CHECK-LABEL: test_vcopy_u8m2x3
  // CHECK: %{{.*}} = call <vscale x 48 x i8> @llvm.riscv.vcopy.nxv16i8x3.{{.*}}(<vscale x 48 x i8> %{{.*}})
  return vcopy_u8m2x3(src);
}

vuint8m2x4_t test_vcopy_u8m2x4 (vuint8m2x4_t src) {
  // CHECK-LABEL: test_vcopy_u8m2x4
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vcopy.nxv16i8x4.{{.*}}(<vscale x 64 x i8> %{{.*}})
  return vcopy_u8m2x4(src);
}

vuint8m4x2_t test_vcopy_u8m4x2 (vuint8m4x2_t src) {
  // CHECK-LABEL: test_vcopy_u8m4x2
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vcopy.nxv32i8x2.{{.*}}(<vscale x 64 x i8> %{{.*}})
  return vcopy_u8m4x2(src);
}

vuint16mf4x2_t test_vcopy_u16mf4x2 (vuint16mf4x2_t src) {
  // CHECK-LABEL: test_vcopy_u16mf4x2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vcopy.nxv1i16x2.{{.*}}(<vscale x 2 x i16> %{{.*}})
  return vcopy_u16mf4x2(src);
}

vuint16mf4x3_t test_vcopy_u16mf4x3 (vuint16mf4x3_t src) {
  // CHECK-LABEL: test_vcopy_u16mf4x3
  // CHECK: %{{.*}} = call <vscale x 3 x i16> @llvm.riscv.vcopy.nxv1i16x3.{{.*}}(<vscale x 3 x i16> %{{.*}})
  return vcopy_u16mf4x3(src);
}

vuint16mf4x4_t test_vcopy_u16mf4x4 (vuint16mf4x4_t src) {
  // CHECK-LABEL: test_vcopy_u16mf4x4
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vcopy.nxv1i16x4.{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vcopy_u16mf4x4(src);
}

vuint16mf4x5_t test_vcopy_u16mf4x5 (vuint16mf4x5_t src) {
  // CHECK-LABEL: test_vcopy_u16mf4x5
  // CHECK: %{{.*}} = call <vscale x 5 x i16> @llvm.riscv.vcopy.nxv1i16x5.{{.*}}(<vscale x 5 x i16> %{{.*}})
  return vcopy_u16mf4x5(src);
}

vuint16mf4x6_t test_vcopy_u16mf4x6 (vuint16mf4x6_t src) {
  // CHECK-LABEL: test_vcopy_u16mf4x6
  // CHECK: %{{.*}} = call <vscale x 6 x i16> @llvm.riscv.vcopy.nxv1i16x6.{{.*}}(<vscale x 6 x i16> %{{.*}})
  return vcopy_u16mf4x6(src);
}

vuint16mf4x7_t test_vcopy_u16mf4x7 (vuint16mf4x7_t src) {
  // CHECK-LABEL: test_vcopy_u16mf4x7
  // CHECK: %{{.*}} = call <vscale x 7 x i16> @llvm.riscv.vcopy.nxv1i16x7.{{.*}}(<vscale x 7 x i16> %{{.*}})
  return vcopy_u16mf4x7(src);
}

vuint16mf4x8_t test_vcopy_u16mf4x8 (vuint16mf4x8_t src) {
  // CHECK-LABEL: test_vcopy_u16mf4x8
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcopy.nxv1i16x8.{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vcopy_u16mf4x8(src);
}

vuint16mf2x2_t test_vcopy_u16mf2x2 (vuint16mf2x2_t src) {
  // CHECK-LABEL: test_vcopy_u16mf2x2
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vcopy.nxv2i16x2.{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vcopy_u16mf2x2(src);
}

vuint16mf2x3_t test_vcopy_u16mf2x3 (vuint16mf2x3_t src) {
  // CHECK-LABEL: test_vcopy_u16mf2x3
  // CHECK: %{{.*}} = call <vscale x 6 x i16> @llvm.riscv.vcopy.nxv2i16x3.{{.*}}(<vscale x 6 x i16> %{{.*}})
  return vcopy_u16mf2x3(src);
}

vuint16mf2x4_t test_vcopy_u16mf2x4 (vuint16mf2x4_t src) {
  // CHECK-LABEL: test_vcopy_u16mf2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcopy.nxv2i16x4.{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vcopy_u16mf2x4(src);
}

vuint16mf2x5_t test_vcopy_u16mf2x5 (vuint16mf2x5_t src) {
  // CHECK-LABEL: test_vcopy_u16mf2x5
  // CHECK: %{{.*}} = call <vscale x 10 x i16> @llvm.riscv.vcopy.nxv2i16x5.{{.*}}(<vscale x 10 x i16> %{{.*}})
  return vcopy_u16mf2x5(src);
}

vuint16mf2x6_t test_vcopy_u16mf2x6 (vuint16mf2x6_t src) {
  // CHECK-LABEL: test_vcopy_u16mf2x6
  // CHECK: %{{.*}} = call <vscale x 12 x i16> @llvm.riscv.vcopy.nxv2i16x6.{{.*}}(<vscale x 12 x i16> %{{.*}})
  return vcopy_u16mf2x6(src);
}

vuint16mf2x7_t test_vcopy_u16mf2x7 (vuint16mf2x7_t src) {
  // CHECK-LABEL: test_vcopy_u16mf2x7
  // CHECK: %{{.*}} = call <vscale x 14 x i16> @llvm.riscv.vcopy.nxv2i16x7.{{.*}}(<vscale x 14 x i16> %{{.*}})
  return vcopy_u16mf2x7(src);
}

vuint16mf2x8_t test_vcopy_u16mf2x8 (vuint16mf2x8_t src) {
  // CHECK-LABEL: test_vcopy_u16mf2x8
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcopy.nxv2i16x8.{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vcopy_u16mf2x8(src);
}

vuint16m1x2_t test_vcopy_u16m1x2 (vuint16m1x2_t src) {
  // CHECK-LABEL: test_vcopy_u16m1x2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcopy.nxv4i16x2.{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vcopy_u16m1x2(src);
}

vuint16m1x3_t test_vcopy_u16m1x3 (vuint16m1x3_t src) {
  // CHECK-LABEL: test_vcopy_u16m1x3
  // CHECK: %{{.*}} = call <vscale x 12 x i16> @llvm.riscv.vcopy.nxv4i16x3.{{.*}}(<vscale x 12 x i16> %{{.*}})
  return vcopy_u16m1x3(src);
}

vuint16m1x4_t test_vcopy_u16m1x4 (vuint16m1x4_t src) {
  // CHECK-LABEL: test_vcopy_u16m1x4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcopy.nxv4i16x4.{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vcopy_u16m1x4(src);
}

vuint16m1x5_t test_vcopy_u16m1x5 (vuint16m1x5_t src) {
  // CHECK-LABEL: test_vcopy_u16m1x5
  // CHECK: %{{.*}} = call <vscale x 20 x i16> @llvm.riscv.vcopy.nxv4i16x5.{{.*}}(<vscale x 20 x i16> %{{.*}})
  return vcopy_u16m1x5(src);
}

vuint16m1x6_t test_vcopy_u16m1x6 (vuint16m1x6_t src) {
  // CHECK-LABEL: test_vcopy_u16m1x6
  // CHECK: %{{.*}} = call <vscale x 24 x i16> @llvm.riscv.vcopy.nxv4i16x6.{{.*}}(<vscale x 24 x i16> %{{.*}})
  return vcopy_u16m1x6(src);
}

vuint16m1x7_t test_vcopy_u16m1x7 (vuint16m1x7_t src) {
  // CHECK-LABEL: test_vcopy_u16m1x7
  // CHECK: %{{.*}} = call <vscale x 28 x i16> @llvm.riscv.vcopy.nxv4i16x7.{{.*}}(<vscale x 28 x i16> %{{.*}})
  return vcopy_u16m1x7(src);
}

vuint16m1x8_t test_vcopy_u16m1x8 (vuint16m1x8_t src) {
  // CHECK-LABEL: test_vcopy_u16m1x8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcopy.nxv4i16x8.{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vcopy_u16m1x8(src);
}

vuint16m2x2_t test_vcopy_u16m2x2 (vuint16m2x2_t src) {
  // CHECK-LABEL: test_vcopy_u16m2x2
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcopy.nxv8i16x2.{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vcopy_u16m2x2(src);
}

vuint16m2x3_t test_vcopy_u16m2x3 (vuint16m2x3_t src) {
  // CHECK-LABEL: test_vcopy_u16m2x3
  // CHECK: %{{.*}} = call <vscale x 24 x i16> @llvm.riscv.vcopy.nxv8i16x3.{{.*}}(<vscale x 24 x i16> %{{.*}})
  return vcopy_u16m2x3(src);
}

vuint16m2x4_t test_vcopy_u16m2x4 (vuint16m2x4_t src) {
  // CHECK-LABEL: test_vcopy_u16m2x4
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcopy.nxv8i16x4.{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vcopy_u16m2x4(src);
}

vuint16m4x2_t test_vcopy_u16m4x2 (vuint16m4x2_t src) {
  // CHECK-LABEL: test_vcopy_u16m4x2
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcopy.nxv16i16x2.{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vcopy_u16m4x2(src);
}

vuint32mf2x2_t test_vcopy_u32mf2x2 (vuint32mf2x2_t src) {
  // CHECK-LABEL: test_vcopy_u32mf2x2
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vcopy.nxv1i32x2.{{.*}}(<vscale x 2 x i32> %{{.*}})
  return vcopy_u32mf2x2(src);
}

vuint32mf2x3_t test_vcopy_u32mf2x3 (vuint32mf2x3_t src) {
  // CHECK-LABEL: test_vcopy_u32mf2x3
  // CHECK: %{{.*}} = call <vscale x 3 x i32> @llvm.riscv.vcopy.nxv1i32x3.{{.*}}(<vscale x 3 x i32> %{{.*}})
  return vcopy_u32mf2x3(src);
}

vuint32mf2x4_t test_vcopy_u32mf2x4 (vuint32mf2x4_t src) {
  // CHECK-LABEL: test_vcopy_u32mf2x4
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vcopy.nxv1i32x4.{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vcopy_u32mf2x4(src);
}

vuint32mf2x5_t test_vcopy_u32mf2x5 (vuint32mf2x5_t src) {
  // CHECK-LABEL: test_vcopy_u32mf2x5
  // CHECK: %{{.*}} = call <vscale x 5 x i32> @llvm.riscv.vcopy.nxv1i32x5.{{.*}}(<vscale x 5 x i32> %{{.*}})
  return vcopy_u32mf2x5(src);
}

vuint32mf2x6_t test_vcopy_u32mf2x6 (vuint32mf2x6_t src) {
  // CHECK-LABEL: test_vcopy_u32mf2x6
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vcopy.nxv1i32x6.{{.*}}(<vscale x 6 x i32> %{{.*}})
  return vcopy_u32mf2x6(src);
}

vuint32mf2x7_t test_vcopy_u32mf2x7 (vuint32mf2x7_t src) {
  // CHECK-LABEL: test_vcopy_u32mf2x7
  // CHECK: %{{.*}} = call <vscale x 7 x i32> @llvm.riscv.vcopy.nxv1i32x7.{{.*}}(<vscale x 7 x i32> %{{.*}})
  return vcopy_u32mf2x7(src);
}

vuint32mf2x8_t test_vcopy_u32mf2x8 (vuint32mf2x8_t src) {
  // CHECK-LABEL: test_vcopy_u32mf2x8
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcopy.nxv1i32x8.{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vcopy_u32mf2x8(src);
}

vuint32m1x2_t test_vcopy_u32m1x2 (vuint32m1x2_t src) {
  // CHECK-LABEL: test_vcopy_u32m1x2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vcopy.nxv2i32x2.{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vcopy_u32m1x2(src);
}

vuint32m1x3_t test_vcopy_u32m1x3 (vuint32m1x3_t src) {
  // CHECK-LABEL: test_vcopy_u32m1x3
  // CHECK: %{{.*}} = call <vscale x 6 x i32> @llvm.riscv.vcopy.nxv2i32x3.{{.*}}(<vscale x 6 x i32> %{{.*}})
  return vcopy_u32m1x3(src);
}

vuint32m1x4_t test_vcopy_u32m1x4 (vuint32m1x4_t src) {
  // CHECK-LABEL: test_vcopy_u32m1x4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcopy.nxv2i32x4.{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vcopy_u32m1x4(src);
}

vuint32m1x5_t test_vcopy_u32m1x5 (vuint32m1x5_t src) {
  // CHECK-LABEL: test_vcopy_u32m1x5
  // CHECK: %{{.*}} = call <vscale x 10 x i32> @llvm.riscv.vcopy.nxv2i32x5.{{.*}}(<vscale x 10 x i32> %{{.*}})
  return vcopy_u32m1x5(src);
}

vuint32m1x6_t test_vcopy_u32m1x6 (vuint32m1x6_t src) {
  // CHECK-LABEL: test_vcopy_u32m1x6
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vcopy.nxv2i32x6.{{.*}}(<vscale x 12 x i32> %{{.*}})
  return vcopy_u32m1x6(src);
}

vuint32m1x7_t test_vcopy_u32m1x7 (vuint32m1x7_t src) {
  // CHECK-LABEL: test_vcopy_u32m1x7
  // CHECK: %{{.*}} = call <vscale x 14 x i32> @llvm.riscv.vcopy.nxv2i32x7.{{.*}}(<vscale x 14 x i32> %{{.*}})
  return vcopy_u32m1x7(src);
}

vuint32m1x8_t test_vcopy_u32m1x8 (vuint32m1x8_t src) {
  // CHECK-LABEL: test_vcopy_u32m1x8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcopy.nxv2i32x8.{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vcopy_u32m1x8(src);
}

vuint32m2x2_t test_vcopy_u32m2x2 (vuint32m2x2_t src) {
  // CHECK-LABEL: test_vcopy_u32m2x2
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcopy.nxv4i32x2.{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vcopy_u32m2x2(src);
}

vuint32m2x3_t test_vcopy_u32m2x3 (vuint32m2x3_t src) {
  // CHECK-LABEL: test_vcopy_u32m2x3
  // CHECK: %{{.*}} = call <vscale x 12 x i32> @llvm.riscv.vcopy.nxv4i32x3.{{.*}}(<vscale x 12 x i32> %{{.*}})
  return vcopy_u32m2x3(src);
}

vuint32m2x4_t test_vcopy_u32m2x4 (vuint32m2x4_t src) {
  // CHECK-LABEL: test_vcopy_u32m2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcopy.nxv4i32x4.{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vcopy_u32m2x4(src);
}

vuint32m4x2_t test_vcopy_u32m4x2 (vuint32m4x2_t src) {
  // CHECK-LABEL: test_vcopy_u32m4x2
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcopy.nxv8i32x2.{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vcopy_u32m4x2(src);
}

vuint64m1x2_t test_vcopy_u64m1x2 (vuint64m1x2_t src) {
  // CHECK-LABEL: test_vcopy_u64m1x2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vcopy.nxv1i64x2.{{.*}}(<vscale x 2 x i64> %{{.*}})
  return vcopy_u64m1x2(src);
}

vuint64m1x3_t test_vcopy_u64m1x3 (vuint64m1x3_t src) {
  // CHECK-LABEL: test_vcopy_u64m1x3
  // CHECK: %{{.*}} = call <vscale x 3 x i64> @llvm.riscv.vcopy.nxv1i64x3.{{.*}}(<vscale x 3 x i64> %{{.*}})
  return vcopy_u64m1x3(src);
}

vuint64m1x4_t test_vcopy_u64m1x4 (vuint64m1x4_t src) {
  // CHECK-LABEL: test_vcopy_u64m1x4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vcopy.nxv1i64x4.{{.*}}(<vscale x 4 x i64> %{{.*}})
  return vcopy_u64m1x4(src);
}

vuint64m1x5_t test_vcopy_u64m1x5 (vuint64m1x5_t src) {
  // CHECK-LABEL: test_vcopy_u64m1x5
  // CHECK: %{{.*}} = call <vscale x 5 x i64> @llvm.riscv.vcopy.nxv1i64x5.{{.*}}(<vscale x 5 x i64> %{{.*}})
  return vcopy_u64m1x5(src);
}

vuint64m1x6_t test_vcopy_u64m1x6 (vuint64m1x6_t src) {
  // CHECK-LABEL: test_vcopy_u64m1x6
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vcopy.nxv1i64x6.{{.*}}(<vscale x 6 x i64> %{{.*}})
  return vcopy_u64m1x6(src);
}

vuint64m1x7_t test_vcopy_u64m1x7 (vuint64m1x7_t src) {
  // CHECK-LABEL: test_vcopy_u64m1x7
  // CHECK: %{{.*}} = call <vscale x 7 x i64> @llvm.riscv.vcopy.nxv1i64x7.{{.*}}(<vscale x 7 x i64> %{{.*}})
  return vcopy_u64m1x7(src);
}

vuint64m1x8_t test_vcopy_u64m1x8 (vuint64m1x8_t src) {
  // CHECK-LABEL: test_vcopy_u64m1x8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcopy.nxv1i64x8.{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vcopy_u64m1x8(src);
}

vuint64m2x2_t test_vcopy_u64m2x2 (vuint64m2x2_t src) {
  // CHECK-LABEL: test_vcopy_u64m2x2
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vcopy.nxv2i64x2.{{.*}}(<vscale x 4 x i64> %{{.*}})
  return vcopy_u64m2x2(src);
}

vuint64m2x3_t test_vcopy_u64m2x3 (vuint64m2x3_t src) {
  // CHECK-LABEL: test_vcopy_u64m2x3
  // CHECK: %{{.*}} = call <vscale x 6 x i64> @llvm.riscv.vcopy.nxv2i64x3.{{.*}}(<vscale x 6 x i64> %{{.*}})
  return vcopy_u64m2x3(src);
}

vuint64m2x4_t test_vcopy_u64m2x4 (vuint64m2x4_t src) {
  // CHECK-LABEL: test_vcopy_u64m2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcopy.nxv2i64x4.{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vcopy_u64m2x4(src);
}

vuint64m4x2_t test_vcopy_u64m4x2 (vuint64m4x2_t src) {
  // CHECK-LABEL: test_vcopy_u64m4x2
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcopy.nxv4i64x2.{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vcopy_u64m4x2(src);
}

vfloat16mf4x2_t test_vcopy_f16mf4x2 (vfloat16mf4x2_t src) {
  // CHECK-LABEL: test_vcopy_f16mf4x2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vcopy.nxv1f16x2.{{.*}}(<vscale x 2 x half> %{{.*}})
  return vcopy_f16mf4x2(src);
}

vfloat16mf4x3_t test_vcopy_f16mf4x3 (vfloat16mf4x3_t src) {
  // CHECK-LABEL: test_vcopy_f16mf4x3
  // CHECK: %{{.*}} = call <vscale x 3 x half> @llvm.riscv.vcopy.nxv1f16x3.{{.*}}(<vscale x 3 x half> %{{.*}})
  return vcopy_f16mf4x3(src);
}

vfloat16mf4x4_t test_vcopy_f16mf4x4 (vfloat16mf4x4_t src) {
  // CHECK-LABEL: test_vcopy_f16mf4x4
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vcopy.nxv1f16x4.{{.*}}(<vscale x 4 x half> %{{.*}})
  return vcopy_f16mf4x4(src);
}

vfloat16mf4x5_t test_vcopy_f16mf4x5 (vfloat16mf4x5_t src) {
  // CHECK-LABEL: test_vcopy_f16mf4x5
  // CHECK: %{{.*}} = call <vscale x 5 x half> @llvm.riscv.vcopy.nxv1f16x5.{{.*}}(<vscale x 5 x half> %{{.*}})
  return vcopy_f16mf4x5(src);
}

vfloat16mf4x6_t test_vcopy_f16mf4x6 (vfloat16mf4x6_t src) {
  // CHECK-LABEL: test_vcopy_f16mf4x6
  // CHECK: %{{.*}} = call <vscale x 6 x half> @llvm.riscv.vcopy.nxv1f16x6.{{.*}}(<vscale x 6 x half> %{{.*}})
  return vcopy_f16mf4x6(src);
}

vfloat16mf4x7_t test_vcopy_f16mf4x7 (vfloat16mf4x7_t src) {
  // CHECK-LABEL: test_vcopy_f16mf4x7
  // CHECK: %{{.*}} = call <vscale x 7 x half> @llvm.riscv.vcopy.nxv1f16x7.{{.*}}(<vscale x 7 x half> %{{.*}})
  return vcopy_f16mf4x7(src);
}

vfloat16mf4x8_t test_vcopy_f16mf4x8 (vfloat16mf4x8_t src) {
  // CHECK-LABEL: test_vcopy_f16mf4x8
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vcopy.nxv1f16x8.{{.*}}(<vscale x 8 x half> %{{.*}})
  return vcopy_f16mf4x8(src);
}

vfloat16mf2x2_t test_vcopy_f16mf2x2 (vfloat16mf2x2_t src) {
  // CHECK-LABEL: test_vcopy_f16mf2x2
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vcopy.nxv2f16x2.{{.*}}(<vscale x 4 x half> %{{.*}})
  return vcopy_f16mf2x2(src);
}

vfloat16mf2x3_t test_vcopy_f16mf2x3 (vfloat16mf2x3_t src) {
  // CHECK-LABEL: test_vcopy_f16mf2x3
  // CHECK: %{{.*}} = call <vscale x 6 x half> @llvm.riscv.vcopy.nxv2f16x3.{{.*}}(<vscale x 6 x half> %{{.*}})
  return vcopy_f16mf2x3(src);
}

vfloat16mf2x4_t test_vcopy_f16mf2x4 (vfloat16mf2x4_t src) {
  // CHECK-LABEL: test_vcopy_f16mf2x4
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vcopy.nxv2f16x4.{{.*}}(<vscale x 8 x half> %{{.*}})
  return vcopy_f16mf2x4(src);
}

vfloat16mf2x5_t test_vcopy_f16mf2x5 (vfloat16mf2x5_t src) {
  // CHECK-LABEL: test_vcopy_f16mf2x5
  // CHECK: %{{.*}} = call <vscale x 10 x half> @llvm.riscv.vcopy.nxv2f16x5.{{.*}}(<vscale x 10 x half> %{{.*}})
  return vcopy_f16mf2x5(src);
}

vfloat16mf2x6_t test_vcopy_f16mf2x6 (vfloat16mf2x6_t src) {
  // CHECK-LABEL: test_vcopy_f16mf2x6
  // CHECK: %{{.*}} = call <vscale x 12 x half> @llvm.riscv.vcopy.nxv2f16x6.{{.*}}(<vscale x 12 x half> %{{.*}})
  return vcopy_f16mf2x6(src);
}

vfloat16mf2x7_t test_vcopy_f16mf2x7 (vfloat16mf2x7_t src) {
  // CHECK-LABEL: test_vcopy_f16mf2x7
  // CHECK: %{{.*}} = call <vscale x 14 x half> @llvm.riscv.vcopy.nxv2f16x7.{{.*}}(<vscale x 14 x half> %{{.*}})
  return vcopy_f16mf2x7(src);
}

vfloat16mf2x8_t test_vcopy_f16mf2x8 (vfloat16mf2x8_t src) {
  // CHECK-LABEL: test_vcopy_f16mf2x8
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vcopy.nxv2f16x8.{{.*}}(<vscale x 16 x half> %{{.*}})
  return vcopy_f16mf2x8(src);
}

vfloat16m1x2_t test_vcopy_f16m1x2 (vfloat16m1x2_t src) {
  // CHECK-LABEL: test_vcopy_f16m1x2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vcopy.nxv4f16x2.{{.*}}(<vscale x 8 x half> %{{.*}})
  return vcopy_f16m1x2(src);
}

vfloat16m1x3_t test_vcopy_f16m1x3 (vfloat16m1x3_t src) {
  // CHECK-LABEL: test_vcopy_f16m1x3
  // CHECK: %{{.*}} = call <vscale x 12 x half> @llvm.riscv.vcopy.nxv4f16x3.{{.*}}(<vscale x 12 x half> %{{.*}})
  return vcopy_f16m1x3(src);
}

vfloat16m1x4_t test_vcopy_f16m1x4 (vfloat16m1x4_t src) {
  // CHECK-LABEL: test_vcopy_f16m1x4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vcopy.nxv4f16x4.{{.*}}(<vscale x 16 x half> %{{.*}})
  return vcopy_f16m1x4(src);
}

vfloat16m1x5_t test_vcopy_f16m1x5 (vfloat16m1x5_t src) {
  // CHECK-LABEL: test_vcopy_f16m1x5
  // CHECK: %{{.*}} = call <vscale x 20 x half> @llvm.riscv.vcopy.nxv4f16x5.{{.*}}(<vscale x 20 x half> %{{.*}})
  return vcopy_f16m1x5(src);
}

vfloat16m1x6_t test_vcopy_f16m1x6 (vfloat16m1x6_t src) {
  // CHECK-LABEL: test_vcopy_f16m1x6
  // CHECK: %{{.*}} = call <vscale x 24 x half> @llvm.riscv.vcopy.nxv4f16x6.{{.*}}(<vscale x 24 x half> %{{.*}})
  return vcopy_f16m1x6(src);
}

vfloat16m1x7_t test_vcopy_f16m1x7 (vfloat16m1x7_t src) {
  // CHECK-LABEL: test_vcopy_f16m1x7
  // CHECK: %{{.*}} = call <vscale x 28 x half> @llvm.riscv.vcopy.nxv4f16x7.{{.*}}(<vscale x 28 x half> %{{.*}})
  return vcopy_f16m1x7(src);
}

vfloat16m1x8_t test_vcopy_f16m1x8 (vfloat16m1x8_t src) {
  // CHECK-LABEL: test_vcopy_f16m1x8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vcopy.nxv4f16x8.{{.*}}(<vscale x 32 x half> %{{.*}})
  return vcopy_f16m1x8(src);
}

vfloat16m2x2_t test_vcopy_f16m2x2 (vfloat16m2x2_t src) {
  // CHECK-LABEL: test_vcopy_f16m2x2
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vcopy.nxv8f16x2.{{.*}}(<vscale x 16 x half> %{{.*}})
  return vcopy_f16m2x2(src);
}

vfloat16m2x3_t test_vcopy_f16m2x3 (vfloat16m2x3_t src) {
  // CHECK-LABEL: test_vcopy_f16m2x3
  // CHECK: %{{.*}} = call <vscale x 24 x half> @llvm.riscv.vcopy.nxv8f16x3.{{.*}}(<vscale x 24 x half> %{{.*}})
  return vcopy_f16m2x3(src);
}

vfloat16m2x4_t test_vcopy_f16m2x4 (vfloat16m2x4_t src) {
  // CHECK-LABEL: test_vcopy_f16m2x4
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vcopy.nxv8f16x4.{{.*}}(<vscale x 32 x half> %{{.*}})
  return vcopy_f16m2x4(src);
}

vfloat16m4x2_t test_vcopy_f16m4x2 (vfloat16m4x2_t src) {
  // CHECK-LABEL: test_vcopy_f16m4x2
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vcopy.nxv16f16x2.{{.*}}(<vscale x 32 x half> %{{.*}})
  return vcopy_f16m4x2(src);
}

vfloat32mf2x2_t test_vcopy_f32mf2x2 (vfloat32mf2x2_t src) {
  // CHECK-LABEL: test_vcopy_f32mf2x2
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vcopy.nxv1f32x2.{{.*}}(<vscale x 2 x float> %{{.*}})
  return vcopy_f32mf2x2(src);
}

vfloat32mf2x3_t test_vcopy_f32mf2x3 (vfloat32mf2x3_t src) {
  // CHECK-LABEL: test_vcopy_f32mf2x3
  // CHECK: %{{.*}} = call <vscale x 3 x float> @llvm.riscv.vcopy.nxv1f32x3.{{.*}}(<vscale x 3 x float> %{{.*}})
  return vcopy_f32mf2x3(src);
}

vfloat32mf2x4_t test_vcopy_f32mf2x4 (vfloat32mf2x4_t src) {
  // CHECK-LABEL: test_vcopy_f32mf2x4
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vcopy.nxv1f32x4.{{.*}}(<vscale x 4 x float> %{{.*}})
  return vcopy_f32mf2x4(src);
}

vfloat32mf2x5_t test_vcopy_f32mf2x5 (vfloat32mf2x5_t src) {
  // CHECK-LABEL: test_vcopy_f32mf2x5
  // CHECK: %{{.*}} = call <vscale x 5 x float> @llvm.riscv.vcopy.nxv1f32x5.{{.*}}(<vscale x 5 x float> %{{.*}})
  return vcopy_f32mf2x5(src);
}

vfloat32mf2x6_t test_vcopy_f32mf2x6 (vfloat32mf2x6_t src) {
  // CHECK-LABEL: test_vcopy_f32mf2x6
  // CHECK: %{{.*}} = call <vscale x 6 x float> @llvm.riscv.vcopy.nxv1f32x6.{{.*}}(<vscale x 6 x float> %{{.*}})
  return vcopy_f32mf2x6(src);
}

vfloat32mf2x7_t test_vcopy_f32mf2x7 (vfloat32mf2x7_t src) {
  // CHECK-LABEL: test_vcopy_f32mf2x7
  // CHECK: %{{.*}} = call <vscale x 7 x float> @llvm.riscv.vcopy.nxv1f32x7.{{.*}}(<vscale x 7 x float> %{{.*}})
  return vcopy_f32mf2x7(src);
}

vfloat32mf2x8_t test_vcopy_f32mf2x8 (vfloat32mf2x8_t src) {
  // CHECK-LABEL: test_vcopy_f32mf2x8
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vcopy.nxv1f32x8.{{.*}}(<vscale x 8 x float> %{{.*}})
  return vcopy_f32mf2x8(src);
}

vfloat32m1x2_t test_vcopy_f32m1x2 (vfloat32m1x2_t src) {
  // CHECK-LABEL: test_vcopy_f32m1x2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vcopy.nxv2f32x2.{{.*}}(<vscale x 4 x float> %{{.*}})
  return vcopy_f32m1x2(src);
}

vfloat32m1x3_t test_vcopy_f32m1x3 (vfloat32m1x3_t src) {
  // CHECK-LABEL: test_vcopy_f32m1x3
  // CHECK: %{{.*}} = call <vscale x 6 x float> @llvm.riscv.vcopy.nxv2f32x3.{{.*}}(<vscale x 6 x float> %{{.*}})
  return vcopy_f32m1x3(src);
}

vfloat32m1x4_t test_vcopy_f32m1x4 (vfloat32m1x4_t src) {
  // CHECK-LABEL: test_vcopy_f32m1x4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vcopy.nxv2f32x4.{{.*}}(<vscale x 8 x float> %{{.*}})
  return vcopy_f32m1x4(src);
}

vfloat32m1x5_t test_vcopy_f32m1x5 (vfloat32m1x5_t src) {
  // CHECK-LABEL: test_vcopy_f32m1x5
  // CHECK: %{{.*}} = call <vscale x 10 x float> @llvm.riscv.vcopy.nxv2f32x5.{{.*}}(<vscale x 10 x float> %{{.*}})
  return vcopy_f32m1x5(src);
}

vfloat32m1x6_t test_vcopy_f32m1x6 (vfloat32m1x6_t src) {
  // CHECK-LABEL: test_vcopy_f32m1x6
  // CHECK: %{{.*}} = call <vscale x 12 x float> @llvm.riscv.vcopy.nxv2f32x6.{{.*}}(<vscale x 12 x float> %{{.*}})
  return vcopy_f32m1x6(src);
}

vfloat32m1x7_t test_vcopy_f32m1x7 (vfloat32m1x7_t src) {
  // CHECK-LABEL: test_vcopy_f32m1x7
  // CHECK: %{{.*}} = call <vscale x 14 x float> @llvm.riscv.vcopy.nxv2f32x7.{{.*}}(<vscale x 14 x float> %{{.*}})
  return vcopy_f32m1x7(src);
}

vfloat32m1x8_t test_vcopy_f32m1x8 (vfloat32m1x8_t src) {
  // CHECK-LABEL: test_vcopy_f32m1x8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vcopy.nxv2f32x8.{{.*}}(<vscale x 16 x float> %{{.*}})
  return vcopy_f32m1x8(src);
}

vfloat32m2x2_t test_vcopy_f32m2x2 (vfloat32m2x2_t src) {
  // CHECK-LABEL: test_vcopy_f32m2x2
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vcopy.nxv4f32x2.{{.*}}(<vscale x 8 x float> %{{.*}})
  return vcopy_f32m2x2(src);
}

vfloat32m2x3_t test_vcopy_f32m2x3 (vfloat32m2x3_t src) {
  // CHECK-LABEL: test_vcopy_f32m2x3
  // CHECK: %{{.*}} = call <vscale x 12 x float> @llvm.riscv.vcopy.nxv4f32x3.{{.*}}(<vscale x 12 x float> %{{.*}})
  return vcopy_f32m2x3(src);
}

vfloat32m2x4_t test_vcopy_f32m2x4 (vfloat32m2x4_t src) {
  // CHECK-LABEL: test_vcopy_f32m2x4
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vcopy.nxv4f32x4.{{.*}}(<vscale x 16 x float> %{{.*}})
  return vcopy_f32m2x4(src);
}

vfloat32m4x2_t test_vcopy_f32m4x2 (vfloat32m4x2_t src) {
  // CHECK-LABEL: test_vcopy_f32m4x2
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vcopy.nxv8f32x2.{{.*}}(<vscale x 16 x float> %{{.*}})
  return vcopy_f32m4x2(src);
}

vfloat64m1x2_t test_vcopy_f64m1x2 (vfloat64m1x2_t src) {
  // CHECK-LABEL: test_vcopy_f64m1x2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vcopy.nxv1f32x2.{{.*}}(<vscale x 2 x double> %{{.*}})
  return vcopy_f64m1x2(src);
}

vfloat64m1x3_t test_vcopy_f64m1x3 (vfloat64m1x3_t src) {
  // CHECK-LABEL: test_vcopy_f64m1x3
  // CHECK: %{{.*}} = call <vscale x 3 x double> @llvm.riscv.vcopy.nxv1f32x3.{{.*}}(<vscale x 3 x double> %{{.*}})
  return vcopy_f64m1x3(src);
}

vfloat64m1x4_t test_vcopy_f64m1x4 (vfloat64m1x4_t src) {
  // CHECK-LABEL: test_vcopy_f64m1x4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vcopy.nxv1f32x4.{{.*}}(<vscale x 4 x double> %{{.*}})
  return vcopy_f64m1x4(src);
}

vfloat64m1x5_t test_vcopy_f64m1x5 (vfloat64m1x5_t src) {
  // CHECK-LABEL: test_vcopy_f64m1x5
  // CHECK: %{{.*}} = call <vscale x 5 x double> @llvm.riscv.vcopy.nxv1f32x5.{{.*}}(<vscale x 5 x double> %{{.*}})
  return vcopy_f64m1x5(src);
}

vfloat64m1x6_t test_vcopy_f64m1x6 (vfloat64m1x6_t src) {
  // CHECK-LABEL: test_vcopy_f64m1x6
  // CHECK: %{{.*}} = call <vscale x 6 x double> @llvm.riscv.vcopy.nxv1f32x6.{{.*}}(<vscale x 6 x double> %{{.*}})
  return vcopy_f64m1x6(src);
}

vfloat64m1x7_t test_vcopy_f64m1x7 (vfloat64m1x7_t src) {
  // CHECK-LABEL: test_vcopy_f64m1x7
  // CHECK: %{{.*}} = call <vscale x 7 x double> @llvm.riscv.vcopy.nxv1f32x7.{{.*}}(<vscale x 7 x double> %{{.*}})
  return vcopy_f64m1x7(src);
}

vfloat64m1x8_t test_vcopy_f64m1x8 (vfloat64m1x8_t src) {
  // CHECK-LABEL: test_vcopy_f64m1x8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vcopy.nxv1f32x8.{{.*}}(<vscale x 8 x double> %{{.*}})
  return vcopy_f64m1x8(src);
}

vfloat64m2x2_t test_vcopy_f64m2x2 (vfloat64m2x2_t src) {
  // CHECK-LABEL: test_vcopy_f64m2x2
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vcopy.nxv2f32x2.{{.*}}(<vscale x 4 x double> %{{.*}})
  return vcopy_f64m2x2(src);
}

vfloat64m2x3_t test_vcopy_f64m2x3 (vfloat64m2x3_t src) {
  // CHECK-LABEL: test_vcopy_f64m2x3
  // CHECK: %{{.*}} = call <vscale x 6 x double> @llvm.riscv.vcopy.nxv2f32x3.{{.*}}(<vscale x 6 x double> %{{.*}})
  return vcopy_f64m2x3(src);
}

vfloat64m2x4_t test_vcopy_f64m2x4 (vfloat64m2x4_t src) {
  // CHECK-LABEL: test_vcopy_f64m2x4
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vcopy.nxv2f32x4.{{.*}}(<vscale x 8 x double> %{{.*}})
  return vcopy_f64m2x4(src);
}

vfloat64m4x2_t test_vcopy_f64m4x2 (vfloat64m4x2_t src) {
  // CHECK-LABEL: test_vcopy_f64m4x2
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vcopy.nxv4f32x2.{{.*}}(<vscale x 8 x double> %{{.*}})
  return vcopy_f64m4x2(src);
}

