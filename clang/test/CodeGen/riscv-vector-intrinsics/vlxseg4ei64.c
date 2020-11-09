// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8x4_t test_vlxseg4ei64_v_i8mf8x4 (int8_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i8mf8x4
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlxseg4ei64.v.nxv1i8x4.{{.*}}(i8 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_i8mf8x4(*base, bindex);
}

vint8mf4x4_t test_vlxseg4ei64_v_i8mf4x4 (int8_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i8mf4x4
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlxseg4ei64.v.nxv2i8x4.{{.*}}(i8 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_i8mf4x4(*base, bindex);
}

vint8mf2x4_t test_vlxseg4ei64_v_i8mf2x4 (int8_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i8mf2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlxseg4ei64.v.nxv4i8x4.{{.*}}(i8 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_i8mf2x4(*base, bindex);
}

vint8m1x4_t test_vlxseg4ei64_v_i8m1x4 (int8_t *base, vuint64m8_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i8m1x4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlxseg4ei64.v.nxv8i8x4.{{.*}}(i8 %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vlxseg4ei64_v_i8m1x4(*base, bindex);
}

vint16mf4x4_t test_vlxseg4ei64_v_i16mf4x4 (int16_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i16mf4x4
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlxseg4ei64.v.nxv1i16x4.{{.*}}(i16 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_i16mf4x4(*base, bindex);
}

vint16mf2x4_t test_vlxseg4ei64_v_i16mf2x4 (int16_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i16mf2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlxseg4ei64.v.nxv2i16x4.{{.*}}(i16 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_i16mf2x4(*base, bindex);
}

vint16m1x4_t test_vlxseg4ei64_v_i16m1x4 (int16_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i16m1x4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlxseg4ei64.v.nxv4i16x4.{{.*}}(i16 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_i16m1x4(*base, bindex);
}

vint16m2x4_t test_vlxseg4ei64_v_i16m2x4 (int16_t *base, vuint64m8_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i16m2x4
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlxseg4ei64.v.nxv8i16x4.{{.*}}(i16 %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vlxseg4ei64_v_i16m2x4(*base, bindex);
}

vint32mf2x4_t test_vlxseg4ei64_v_i32mf2x4 (int32_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i32mf2x4
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlxseg4ei64.v.nxv1i32x4.{{.*}}(i32 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_i32mf2x4(*base, bindex);
}

vint32m1x4_t test_vlxseg4ei64_v_i32m1x4 (int32_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i32m1x4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlxseg4ei64.v.nxv2i32x4.{{.*}}(i32 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_i32m1x4(*base, bindex);
}

vint32m2x4_t test_vlxseg4ei64_v_i32m2x4 (int32_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i32m2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlxseg4ei64.v.nxv4i32x4.{{.*}}(i32 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_i32m2x4(*base, bindex);
}

vint64m1x4_t test_vlxseg4ei64_v_i64m1x4 (int64_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i64m1x4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlxseg4ei64.v.nxv1i64x4.{{.*}}(i64 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_i64m1x4(*base, bindex);
}

vint64m2x4_t test_vlxseg4ei64_v_i64m2x4 (int64_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i64m2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlxseg4ei64.v.nxv2i64x4.{{.*}}(i64 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_i64m2x4(*base, bindex);
}

vuint8mf8x4_t test_vlxseg4ei64_v_u8mf8x4 (uint8_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u8mf8x4
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlxseg4ei64.v.nxv1i8x4.{{.*}}(i8 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_u8mf8x4(*base, bindex);
}

vuint8mf4x4_t test_vlxseg4ei64_v_u8mf4x4 (uint8_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u8mf4x4
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlxseg4ei64.v.nxv2i8x4.{{.*}}(i8 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_u8mf4x4(*base, bindex);
}

vuint8mf2x4_t test_vlxseg4ei64_v_u8mf2x4 (uint8_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u8mf2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlxseg4ei64.v.nxv4i8x4.{{.*}}(i8 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_u8mf2x4(*base, bindex);
}

vuint8m1x4_t test_vlxseg4ei64_v_u8m1x4 (uint8_t *base, vuint64m8_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u8m1x4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlxseg4ei64.v.nxv8i8x4.{{.*}}(i8 %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vlxseg4ei64_v_u8m1x4(*base, bindex);
}

vuint16mf4x4_t test_vlxseg4ei64_v_u16mf4x4 (uint16_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u16mf4x4
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlxseg4ei64.v.nxv1i16x4.{{.*}}(i16 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_u16mf4x4(*base, bindex);
}

vuint16mf2x4_t test_vlxseg4ei64_v_u16mf2x4 (uint16_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u16mf2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlxseg4ei64.v.nxv2i16x4.{{.*}}(i16 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_u16mf2x4(*base, bindex);
}

vuint16m1x4_t test_vlxseg4ei64_v_u16m1x4 (uint16_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u16m1x4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlxseg4ei64.v.nxv4i16x4.{{.*}}(i16 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_u16m1x4(*base, bindex);
}

vuint16m2x4_t test_vlxseg4ei64_v_u16m2x4 (uint16_t *base, vuint64m8_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u16m2x4
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlxseg4ei64.v.nxv8i16x4.{{.*}}(i16 %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vlxseg4ei64_v_u16m2x4(*base, bindex);
}

vuint32mf2x4_t test_vlxseg4ei64_v_u32mf2x4 (uint32_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u32mf2x4
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlxseg4ei64.v.nxv1i32x4.{{.*}}(i32 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_u32mf2x4(*base, bindex);
}

vuint32m1x4_t test_vlxseg4ei64_v_u32m1x4 (uint32_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u32m1x4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlxseg4ei64.v.nxv2i32x4.{{.*}}(i32 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_u32m1x4(*base, bindex);
}

vuint32m2x4_t test_vlxseg4ei64_v_u32m2x4 (uint32_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u32m2x4
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlxseg4ei64.v.nxv4i32x4.{{.*}}(i32 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_u32m2x4(*base, bindex);
}

vuint64m1x4_t test_vlxseg4ei64_v_u64m1x4 (uint64_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u64m1x4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlxseg4ei64.v.nxv1i64x4.{{.*}}(i64 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_u64m1x4(*base, bindex);
}

vuint64m2x4_t test_vlxseg4ei64_v_u64m2x4 (uint64_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u64m2x4
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlxseg4ei64.v.nxv2i64x4.{{.*}}(i64 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_u64m2x4(*base, bindex);
}

vfloat16mf4x4_t test_vlxseg4ei64_v_f16mf4x4 (float16_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f16mf4x4
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vlxseg4ei64.v.nxv1f16x4.{{.*}}(half %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_f16mf4x4(*base, bindex);
}

vfloat16mf2x4_t test_vlxseg4ei64_v_f16mf2x4 (float16_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f16mf2x4
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vlxseg4ei64.v.nxv2f16x4.{{.*}}(half %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_f16mf2x4(*base, bindex);
}

vfloat16m1x4_t test_vlxseg4ei64_v_f16m1x4 (float16_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f16m1x4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vlxseg4ei64.v.nxv4f16x4.{{.*}}(half %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_f16m1x4(*base, bindex);
}

vfloat16m2x4_t test_vlxseg4ei64_v_f16m2x4 (float16_t *base, vuint64m8_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f16m2x4
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vlxseg4ei64.v.nxv8f16x4.{{.*}}(half %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vlxseg4ei64_v_f16m2x4(*base, bindex);
}

vfloat32mf2x4_t test_vlxseg4ei64_v_f32mf2x4 (float32_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f32mf2x4
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vlxseg4ei64.v.nxv1f32x4.{{.*}}(float %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_f32mf2x4(*base, bindex);
}

vfloat32m1x4_t test_vlxseg4ei64_v_f32m1x4 (float32_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f32m1x4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vlxseg4ei64.v.nxv2f32x4.{{.*}}(float %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_f32m1x4(*base, bindex);
}

vfloat32m2x4_t test_vlxseg4ei64_v_f32m2x4 (float32_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f32m2x4
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vlxseg4ei64.v.nxv4f32x4.{{.*}}(float %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_f32m2x4(*base, bindex);
}

vfloat64m1x4_t test_vlxseg4ei64_v_f64m1x4 (float64_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f64m1x4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vlxseg4ei64.v.nxv1f32x4.{{.*}}(double %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_f64m1x4(*base, bindex);
}

vfloat64m2x4_t test_vlxseg4ei64_v_f64m2x4 (float64_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f64m2x4
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vlxseg4ei64.v.nxv2f32x4.{{.*}}(double %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_f64m2x4(*base, bindex);
}

vint8mf8x4_t test_vlxseg4ei64_v_i8mf8x4_m (vbool64_t mask, vint8mf8x4_t maskedoff, int8_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i8mf8x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlxseg4ei64.v.nxv1i8x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_i8mf8x4_m(mask, maskedoff, *base, bindex);
}

vint8mf4x4_t test_vlxseg4ei64_v_i8mf4x4_m (vbool32_t mask, vint8mf4x4_t maskedoff, int8_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i8mf4x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlxseg4ei64.v.nxv2i8x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_i8mf4x4_m(mask, maskedoff, *base, bindex);
}

vint8mf2x4_t test_vlxseg4ei64_v_i8mf2x4_m (vbool16_t mask, vint8mf2x4_t maskedoff, int8_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i8mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlxseg4ei64.v.nxv4i8x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_i8mf2x4_m(mask, maskedoff, *base, bindex);
}

vint8m1x4_t test_vlxseg4ei64_v_i8m1x4_m (vbool8_t mask, vint8m1x4_t maskedoff, int8_t *base, vuint64m8_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i8m1x4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlxseg4ei64.v.nxv8i8x4.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vlxseg4ei64_v_i8m1x4_m(mask, maskedoff, *base, bindex);
}

vint16mf4x4_t test_vlxseg4ei64_v_i16mf4x4_m (vbool64_t mask, vint16mf4x4_t maskedoff, int16_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i16mf4x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlxseg4ei64.v.nxv1i16x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_i16mf4x4_m(mask, maskedoff, *base, bindex);
}

vint16mf2x4_t test_vlxseg4ei64_v_i16mf2x4_m (vbool32_t mask, vint16mf2x4_t maskedoff, int16_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i16mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlxseg4ei64.v.nxv2i16x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_i16mf2x4_m(mask, maskedoff, *base, bindex);
}

vint16m1x4_t test_vlxseg4ei64_v_i16m1x4_m (vbool16_t mask, vint16m1x4_t maskedoff, int16_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i16m1x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlxseg4ei64.v.nxv4i16x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_i16m1x4_m(mask, maskedoff, *base, bindex);
}

vint16m2x4_t test_vlxseg4ei64_v_i16m2x4_m (vbool8_t mask, vint16m2x4_t maskedoff, int16_t *base, vuint64m8_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i16m2x4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlxseg4ei64.v.nxv8i16x4.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vlxseg4ei64_v_i16m2x4_m(mask, maskedoff, *base, bindex);
}

vint32mf2x4_t test_vlxseg4ei64_v_i32mf2x4_m (vbool64_t mask, vint32mf2x4_t maskedoff, int32_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i32mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlxseg4ei64.v.nxv1i32x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_i32mf2x4_m(mask, maskedoff, *base, bindex);
}

vint32m1x4_t test_vlxseg4ei64_v_i32m1x4_m (vbool32_t mask, vint32m1x4_t maskedoff, int32_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i32m1x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlxseg4ei64.v.nxv2i32x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_i32m1x4_m(mask, maskedoff, *base, bindex);
}

vint32m2x4_t test_vlxseg4ei64_v_i32m2x4_m (vbool16_t mask, vint32m2x4_t maskedoff, int32_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i32m2x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlxseg4ei64.v.nxv4i32x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_i32m2x4_m(mask, maskedoff, *base, bindex);
}

vint64m1x4_t test_vlxseg4ei64_v_i64m1x4_m (vbool64_t mask, vint64m1x4_t maskedoff, int64_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i64m1x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlxseg4ei64.v.nxv1i64x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_i64m1x4_m(mask, maskedoff, *base, bindex);
}

vint64m2x4_t test_vlxseg4ei64_v_i64m2x4_m (vbool32_t mask, vint64m2x4_t maskedoff, int64_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_i64m2x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlxseg4ei64.v.nxv2i64x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_i64m2x4_m(mask, maskedoff, *base, bindex);
}

vuint8mf8x4_t test_vlxseg4ei64_v_u8mf8x4_m (vbool64_t mask, vuint8mf8x4_t maskedoff, uint8_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u8mf8x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlxseg4ei64.v.nxv1i8x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_u8mf8x4_m(mask, maskedoff, *base, bindex);
}

vuint8mf4x4_t test_vlxseg4ei64_v_u8mf4x4_m (vbool32_t mask, vuint8mf4x4_t maskedoff, uint8_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u8mf4x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlxseg4ei64.v.nxv2i8x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_u8mf4x4_m(mask, maskedoff, *base, bindex);
}

vuint8mf2x4_t test_vlxseg4ei64_v_u8mf2x4_m (vbool16_t mask, vuint8mf2x4_t maskedoff, uint8_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u8mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlxseg4ei64.v.nxv4i8x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_u8mf2x4_m(mask, maskedoff, *base, bindex);
}

vuint8m1x4_t test_vlxseg4ei64_v_u8m1x4_m (vbool8_t mask, vuint8m1x4_t maskedoff, uint8_t *base, vuint64m8_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u8m1x4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlxseg4ei64.v.nxv8i8x4.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vlxseg4ei64_v_u8m1x4_m(mask, maskedoff, *base, bindex);
}

vuint16mf4x4_t test_vlxseg4ei64_v_u16mf4x4_m (vbool64_t mask, vuint16mf4x4_t maskedoff, uint16_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u16mf4x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlxseg4ei64.v.nxv1i16x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_u16mf4x4_m(mask, maskedoff, *base, bindex);
}

vuint16mf2x4_t test_vlxseg4ei64_v_u16mf2x4_m (vbool32_t mask, vuint16mf2x4_t maskedoff, uint16_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u16mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlxseg4ei64.v.nxv2i16x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_u16mf2x4_m(mask, maskedoff, *base, bindex);
}

vuint16m1x4_t test_vlxseg4ei64_v_u16m1x4_m (vbool16_t mask, vuint16m1x4_t maskedoff, uint16_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u16m1x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlxseg4ei64.v.nxv4i16x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_u16m1x4_m(mask, maskedoff, *base, bindex);
}

vuint16m2x4_t test_vlxseg4ei64_v_u16m2x4_m (vbool8_t mask, vuint16m2x4_t maskedoff, uint16_t *base, vuint64m8_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u16m2x4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlxseg4ei64.v.nxv8i16x4.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vlxseg4ei64_v_u16m2x4_m(mask, maskedoff, *base, bindex);
}

vuint32mf2x4_t test_vlxseg4ei64_v_u32mf2x4_m (vbool64_t mask, vuint32mf2x4_t maskedoff, uint32_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u32mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlxseg4ei64.v.nxv1i32x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_u32mf2x4_m(mask, maskedoff, *base, bindex);
}

vuint32m1x4_t test_vlxseg4ei64_v_u32m1x4_m (vbool32_t mask, vuint32m1x4_t maskedoff, uint32_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u32m1x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlxseg4ei64.v.nxv2i32x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_u32m1x4_m(mask, maskedoff, *base, bindex);
}

vuint32m2x4_t test_vlxseg4ei64_v_u32m2x4_m (vbool16_t mask, vuint32m2x4_t maskedoff, uint32_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u32m2x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlxseg4ei64.v.nxv4i32x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_u32m2x4_m(mask, maskedoff, *base, bindex);
}

vuint64m1x4_t test_vlxseg4ei64_v_u64m1x4_m (vbool64_t mask, vuint64m1x4_t maskedoff, uint64_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u64m1x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlxseg4ei64.v.nxv1i64x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_u64m1x4_m(mask, maskedoff, *base, bindex);
}

vuint64m2x4_t test_vlxseg4ei64_v_u64m2x4_m (vbool32_t mask, vuint64m2x4_t maskedoff, uint64_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_u64m2x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlxseg4ei64.v.nxv2i64x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_u64m2x4_m(mask, maskedoff, *base, bindex);
}

vfloat16mf4x4_t test_vlxseg4ei64_v_f16mf4x4_m (vbool64_t mask, vfloat16mf4x4_t maskedoff, float16_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f16mf4x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vlxseg4ei64.v.nxv1f16x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_f16mf4x4_m(mask, maskedoff, *base, bindex);
}

vfloat16mf2x4_t test_vlxseg4ei64_v_f16mf2x4_m (vbool32_t mask, vfloat16mf2x4_t maskedoff, float16_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f16mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vlxseg4ei64.v.nxv2f16x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_f16mf2x4_m(mask, maskedoff, *base, bindex);
}

vfloat16m1x4_t test_vlxseg4ei64_v_f16m1x4_m (vbool16_t mask, vfloat16m1x4_t maskedoff, float16_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f16m1x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vlxseg4ei64.v.nxv4f16x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_f16m1x4_m(mask, maskedoff, *base, bindex);
}

vfloat16m2x4_t test_vlxseg4ei64_v_f16m2x4_m (vbool8_t mask, vfloat16m2x4_t maskedoff, float16_t *base, vuint64m8_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f16m2x4_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vlxseg4ei64.v.nxv8f16x4.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vlxseg4ei64_v_f16m2x4_m(mask, maskedoff, *base, bindex);
}

vfloat32mf2x4_t test_vlxseg4ei64_v_f32mf2x4_m (vbool64_t mask, vfloat32mf2x4_t maskedoff, float32_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f32mf2x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vlxseg4ei64.v.nxv1f32x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_f32mf2x4_m(mask, maskedoff, *base, bindex);
}

vfloat32m1x4_t test_vlxseg4ei64_v_f32m1x4_m (vbool32_t mask, vfloat32m1x4_t maskedoff, float32_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f32m1x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vlxseg4ei64.v.nxv2f32x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_f32m1x4_m(mask, maskedoff, *base, bindex);
}

vfloat32m2x4_t test_vlxseg4ei64_v_f32m2x4_m (vbool16_t mask, vfloat32m2x4_t maskedoff, float32_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f32m2x4_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vlxseg4ei64.v.nxv4f32x4.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg4ei64_v_f32m2x4_m(mask, maskedoff, *base, bindex);
}

vfloat64m1x4_t test_vlxseg4ei64_v_f64m1x4_m (vbool64_t mask, vfloat64m1x4_t maskedoff, float64_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f64m1x4_m
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vlxseg4ei64.v.nxv1f32x4.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, double %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg4ei64_v_f64m1x4_m(mask, maskedoff, *base, bindex);
}

vfloat64m2x4_t test_vlxseg4ei64_v_f64m2x4_m (vbool32_t mask, vfloat64m2x4_t maskedoff, float64_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg4ei64_v_f64m2x4_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vlxseg4ei64.v.nxv2f32x4.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, double %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg4ei64_v_f64m2x4_m(mask, maskedoff, *base, bindex);
}

