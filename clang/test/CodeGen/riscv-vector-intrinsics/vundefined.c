// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8_t test_vundefined_i8mf8 () {
  // CHECK-LABEL: test_vundefined_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vundefined.nxv1i8{{.*}}()
  return vundefined_i8mf8(();
}

vint8mf4_t test_vundefined_i8mf4 () {
  // CHECK-LABEL: test_vundefined_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vundefined.nxv2i8{{.*}}()
  return vundefined_i8mf4(();
}

vint8mf2_t test_vundefined_i8mf2 () {
  // CHECK-LABEL: test_vundefined_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vundefined.nxv4i8{{.*}}()
  return vundefined_i8mf2(();
}

vint8m1_t test_vundefined_i8m1 () {
  // CHECK-LABEL: test_vundefined_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vundefined.nxv8i8{{.*}}()
  return vundefined_i8m1(();
}

vint8m2_t test_vundefined_i8m2 () {
  // CHECK-LABEL: test_vundefined_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vundefined.nxv16i8{{.*}}()
  return vundefined_i8m2(();
}

vint8m4_t test_vundefined_i8m4 () {
  // CHECK-LABEL: test_vundefined_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vundefined.nxv32i8{{.*}}()
  return vundefined_i8m4(();
}

vint8m8_t test_vundefined_i8m8 () {
  // CHECK-LABEL: test_vundefined_i8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vundefined.nxv64i8{{.*}}()
  return vundefined_i8m8(();
}

vint16mf4_t test_vundefined_i16mf4 () {
  // CHECK-LABEL: test_vundefined_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vundefined.nxv1i16{{.*}}()
  return vundefined_i16mf4(();
}

vint16mf2_t test_vundefined_i16mf2 () {
  // CHECK-LABEL: test_vundefined_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vundefined.nxv2i16{{.*}}()
  return vundefined_i16mf2(();
}

vint16m1_t test_vundefined_i16m1 () {
  // CHECK-LABEL: test_vundefined_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vundefined.nxv4i16{{.*}}()
  return vundefined_i16m1(();
}

vint16m2_t test_vundefined_i16m2 () {
  // CHECK-LABEL: test_vundefined_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vundefined.nxv8i16{{.*}}()
  return vundefined_i16m2(();
}

vint16m4_t test_vundefined_i16m4 () {
  // CHECK-LABEL: test_vundefined_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vundefined.nxv16i16{{.*}}()
  return vundefined_i16m4(();
}

vint16m8_t test_vundefined_i16m8 () {
  // CHECK-LABEL: test_vundefined_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vundefined.nxv32i16{{.*}}()
  return vundefined_i16m8(();
}

vint32mf2_t test_vundefined_i32mf2 () {
  // CHECK-LABEL: test_vundefined_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vundefined.nxv1i32{{.*}}()
  return vundefined_i32mf2(();
}

vint32m1_t test_vundefined_i32m1 () {
  // CHECK-LABEL: test_vundefined_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vundefined.nxv2i32{{.*}}()
  return vundefined_i32m1(();
}

vint32m2_t test_vundefined_i32m2 () {
  // CHECK-LABEL: test_vundefined_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vundefined.nxv4i32{{.*}}()
  return vundefined_i32m2(();
}

vint32m4_t test_vundefined_i32m4 () {
  // CHECK-LABEL: test_vundefined_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vundefined.nxv8i32{{.*}}()
  return vundefined_i32m4(();
}

vint32m8_t test_vundefined_i32m8 () {
  // CHECK-LABEL: test_vundefined_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vundefined.nxv16i32{{.*}}()
  return vundefined_i32m8(();
}

vint64m1_t test_vundefined_i64m1 () {
  // CHECK-LABEL: test_vundefined_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vundefined.nxv1i64{{.*}}()
  return vundefined_i64m1(();
}

vint64m2_t test_vundefined_i64m2 () {
  // CHECK-LABEL: test_vundefined_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vundefined.nxv2i64{{.*}}()
  return vundefined_i64m2(();
}

vint64m4_t test_vundefined_i64m4 () {
  // CHECK-LABEL: test_vundefined_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vundefined.nxv4i64{{.*}}()
  return vundefined_i64m4(();
}

vint64m8_t test_vundefined_i64m8 () {
  // CHECK-LABEL: test_vundefined_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vundefined.nxv8i64{{.*}}()
  return vundefined_i64m8(();
}

vuint8mf8_t test_vundefined_u8mf8 () {
  // CHECK-LABEL: test_vundefined_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vundefined.nxv1i8{{.*}}()
  return vundefined_u8mf8(();
}

vuint8mf4_t test_vundefined_u8mf4 () {
  // CHECK-LABEL: test_vundefined_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vundefined.nxv2i8{{.*}}()
  return vundefined_u8mf4(();
}

vuint8mf2_t test_vundefined_u8mf2 () {
  // CHECK-LABEL: test_vundefined_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vundefined.nxv4i8{{.*}}()
  return vundefined_u8mf2(();
}

vuint8m1_t test_vundefined_u8m1 () {
  // CHECK-LABEL: test_vundefined_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vundefined.nxv8i8{{.*}}()
  return vundefined_u8m1(();
}

vuint8m2_t test_vundefined_u8m2 () {
  // CHECK-LABEL: test_vundefined_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vundefined.nxv16i8{{.*}}()
  return vundefined_u8m2(();
}

vuint8m4_t test_vundefined_u8m4 () {
  // CHECK-LABEL: test_vundefined_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vundefined.nxv32i8{{.*}}()
  return vundefined_u8m4(();
}

vuint8m8_t test_vundefined_u8m8 () {
  // CHECK-LABEL: test_vundefined_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vundefined.nxv64i8{{.*}}()
  return vundefined_u8m8(();
}

vuint16mf4_t test_vundefined_u16mf4 () {
  // CHECK-LABEL: test_vundefined_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vundefined.nxv1i16{{.*}}()
  return vundefined_u16mf4(();
}

vuint16mf2_t test_vundefined_u16mf2 () {
  // CHECK-LABEL: test_vundefined_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vundefined.nxv2i16{{.*}}()
  return vundefined_u16mf2(();
}

vuint16m1_t test_vundefined_u16m1 () {
  // CHECK-LABEL: test_vundefined_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vundefined.nxv4i16{{.*}}()
  return vundefined_u16m1(();
}

vuint16m2_t test_vundefined_u16m2 () {
  // CHECK-LABEL: test_vundefined_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vundefined.nxv8i16{{.*}}()
  return vundefined_u16m2(();
}

vuint16m4_t test_vundefined_u16m4 () {
  // CHECK-LABEL: test_vundefined_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vundefined.nxv16i16{{.*}}()
  return vundefined_u16m4(();
}

vuint16m8_t test_vundefined_u16m8 () {
  // CHECK-LABEL: test_vundefined_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vundefined.nxv32i16{{.*}}()
  return vundefined_u16m8(();
}

vuint32mf2_t test_vundefined_u32mf2 () {
  // CHECK-LABEL: test_vundefined_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vundefined.nxv1i32{{.*}}()
  return vundefined_u32mf2(();
}

vuint32m1_t test_vundefined_u32m1 () {
  // CHECK-LABEL: test_vundefined_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vundefined.nxv2i32{{.*}}()
  return vundefined_u32m1(();
}

vuint32m2_t test_vundefined_u32m2 () {
  // CHECK-LABEL: test_vundefined_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vundefined.nxv4i32{{.*}}()
  return vundefined_u32m2(();
}

vuint32m4_t test_vundefined_u32m4 () {
  // CHECK-LABEL: test_vundefined_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vundefined.nxv8i32{{.*}}()
  return vundefined_u32m4(();
}

vuint32m8_t test_vundefined_u32m8 () {
  // CHECK-LABEL: test_vundefined_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vundefined.nxv16i32{{.*}}()
  return vundefined_u32m8(();
}

vuint64m1_t test_vundefined_u64m1 () {
  // CHECK-LABEL: test_vundefined_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vundefined.nxv1i64{{.*}}()
  return vundefined_u64m1(();
}

vuint64m2_t test_vundefined_u64m2 () {
  // CHECK-LABEL: test_vundefined_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vundefined.nxv2i64{{.*}}()
  return vundefined_u64m2(();
}

vuint64m4_t test_vundefined_u64m4 () {
  // CHECK-LABEL: test_vundefined_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vundefined.nxv4i64{{.*}}()
  return vundefined_u64m4(();
}

vuint64m8_t test_vundefined_u64m8 () {
  // CHECK-LABEL: test_vundefined_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vundefined.nxv8i64{{.*}}()
  return vundefined_u64m8(();
}

vfloat16mf4_t test_vundefined_f16mf4 () {
  // CHECK-LABEL: test_vundefined_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vundefined.nxv1f16{{.*}}()
  return vundefined_f16mf4(();
}

vfloat16mf2_t test_vundefined_f16mf2 () {
  // CHECK-LABEL: test_vundefined_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vundefined.nxv2f16{{.*}}()
  return vundefined_f16mf2(();
}

vfloat16m1_t test_vundefined_f16m1 () {
  // CHECK-LABEL: test_vundefined_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vundefined.nxv4f16{{.*}}()
  return vundefined_f16m1(();
}

vfloat16m2_t test_vundefined_f16m2 () {
  // CHECK-LABEL: test_vundefined_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vundefined.nxv8f16{{.*}}()
  return vundefined_f16m2(();
}

vfloat16m4_t test_vundefined_f16m4 () {
  // CHECK-LABEL: test_vundefined_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vundefined.nxv16f16{{.*}}()
  return vundefined_f16m4(();
}

vfloat16m8_t test_vundefined_f16m8 () {
  // CHECK-LABEL: test_vundefined_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vundefined.nxv32f16{{.*}}()
  return vundefined_f16m8(();
}

vfloat32mf2_t test_vundefined_f32mf2 () {
  // CHECK-LABEL: test_vundefined_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vundefined.nxv1f32{{.*}}()
  return vundefined_f32mf2(();
}

vfloat32m1_t test_vundefined_f32m1 () {
  // CHECK-LABEL: test_vundefined_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vundefined.nxv2f32{{.*}}()
  return vundefined_f32m1(();
}

vfloat32m2_t test_vundefined_f32m2 () {
  // CHECK-LABEL: test_vundefined_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vundefined.nxv4f32{{.*}}()
  return vundefined_f32m2(();
}

vfloat32m4_t test_vundefined_f32m4 () {
  // CHECK-LABEL: test_vundefined_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vundefined.nxv8f32{{.*}}()
  return vundefined_f32m4(();
}

vfloat32m8_t test_vundefined_f32m8 () {
  // CHECK-LABEL: test_vundefined_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vundefined.nxv16f32{{.*}}()
  return vundefined_f32m8(();
}

vfloat64m1_t test_vundefined_f64m1 () {
  // CHECK-LABEL: test_vundefined_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vundefined.nxv1f32{{.*}}()
  return vundefined_f64m1(();
}

vfloat64m2_t test_vundefined_f64m2 () {
  // CHECK-LABEL: test_vundefined_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vundefined.nxv2f32{{.*}}()
  return vundefined_f64m2(();
}

vfloat64m4_t test_vundefined_f64m4 () {
  // CHECK-LABEL: test_vundefined_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vundefined.nxv4f32{{.*}}()
  return vundefined_f64m4(();
}

vfloat64m8_t test_vundefined_f64m8 () {
  // CHECK-LABEL: test_vundefined_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vundefined.nxv8f32{{.*}}()
  return vundefined_f64m8(();
}

