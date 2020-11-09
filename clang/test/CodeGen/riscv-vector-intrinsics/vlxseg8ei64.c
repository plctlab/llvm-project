// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8x8_t test_vlxseg8ei64_v_i8mf8x8 (int8_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i8mf8x8
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlxseg8ei64.v.nxv1i8x8.{{.*}}(i8 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_i8mf8x8(*base, bindex);
}

vint8mf4x8_t test_vlxseg8ei64_v_i8mf4x8 (int8_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i8mf4x8
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlxseg8ei64.v.nxv2i8x8.{{.*}}(i8 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_i8mf4x8(*base, bindex);
}

vint8mf2x8_t test_vlxseg8ei64_v_i8mf2x8 (int8_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i8mf2x8
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlxseg8ei64.v.nxv4i8x8.{{.*}}(i8 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg8ei64_v_i8mf2x8(*base, bindex);
}

vint8m1x8_t test_vlxseg8ei64_v_i8m1x8 (int8_t *base, vuint64m8_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i8m1x8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlxseg8ei64.v.nxv8i8x8.{{.*}}(i8 %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vlxseg8ei64_v_i8m1x8(*base, bindex);
}

vint16mf4x8_t test_vlxseg8ei64_v_i16mf4x8 (int16_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i16mf4x8
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlxseg8ei64.v.nxv1i16x8.{{.*}}(i16 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_i16mf4x8(*base, bindex);
}

vint16mf2x8_t test_vlxseg8ei64_v_i16mf2x8 (int16_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i16mf2x8
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlxseg8ei64.v.nxv2i16x8.{{.*}}(i16 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_i16mf2x8(*base, bindex);
}

vint16m1x8_t test_vlxseg8ei64_v_i16m1x8 (int16_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i16m1x8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlxseg8ei64.v.nxv4i16x8.{{.*}}(i16 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg8ei64_v_i16m1x8(*base, bindex);
}

vint32mf2x8_t test_vlxseg8ei64_v_i32mf2x8 (int32_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i32mf2x8
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlxseg8ei64.v.nxv1i32x8.{{.*}}(i32 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_i32mf2x8(*base, bindex);
}

vint32m1x8_t test_vlxseg8ei64_v_i32m1x8 (int32_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i32m1x8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlxseg8ei64.v.nxv2i32x8.{{.*}}(i32 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_i32m1x8(*base, bindex);
}

vint64m1x8_t test_vlxseg8ei64_v_i64m1x8 (int64_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i64m1x8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlxseg8ei64.v.nxv1i64x8.{{.*}}(i64 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_i64m1x8(*base, bindex);
}

vuint8mf8x8_t test_vlxseg8ei64_v_u8mf8x8 (uint8_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u8mf8x8
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlxseg8ei64.v.nxv1i8x8.{{.*}}(i8 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_u8mf8x8(*base, bindex);
}

vuint8mf4x8_t test_vlxseg8ei64_v_u8mf4x8 (uint8_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u8mf4x8
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlxseg8ei64.v.nxv2i8x8.{{.*}}(i8 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_u8mf4x8(*base, bindex);
}

vuint8mf2x8_t test_vlxseg8ei64_v_u8mf2x8 (uint8_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u8mf2x8
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlxseg8ei64.v.nxv4i8x8.{{.*}}(i8 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg8ei64_v_u8mf2x8(*base, bindex);
}

vuint8m1x8_t test_vlxseg8ei64_v_u8m1x8 (uint8_t *base, vuint64m8_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u8m1x8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlxseg8ei64.v.nxv8i8x8.{{.*}}(i8 %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vlxseg8ei64_v_u8m1x8(*base, bindex);
}

vuint16mf4x8_t test_vlxseg8ei64_v_u16mf4x8 (uint16_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u16mf4x8
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlxseg8ei64.v.nxv1i16x8.{{.*}}(i16 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_u16mf4x8(*base, bindex);
}

vuint16mf2x8_t test_vlxseg8ei64_v_u16mf2x8 (uint16_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u16mf2x8
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlxseg8ei64.v.nxv2i16x8.{{.*}}(i16 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_u16mf2x8(*base, bindex);
}

vuint16m1x8_t test_vlxseg8ei64_v_u16m1x8 (uint16_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u16m1x8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlxseg8ei64.v.nxv4i16x8.{{.*}}(i16 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg8ei64_v_u16m1x8(*base, bindex);
}

vuint32mf2x8_t test_vlxseg8ei64_v_u32mf2x8 (uint32_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u32mf2x8
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlxseg8ei64.v.nxv1i32x8.{{.*}}(i32 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_u32mf2x8(*base, bindex);
}

vuint32m1x8_t test_vlxseg8ei64_v_u32m1x8 (uint32_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u32m1x8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlxseg8ei64.v.nxv2i32x8.{{.*}}(i32 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_u32m1x8(*base, bindex);
}

vuint64m1x8_t test_vlxseg8ei64_v_u64m1x8 (uint64_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u64m1x8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlxseg8ei64.v.nxv1i64x8.{{.*}}(i64 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_u64m1x8(*base, bindex);
}

vfloat16mf4x8_t test_vlxseg8ei64_v_f16mf4x8 (float16_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_f16mf4x8
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vlxseg8ei64.v.nxv1f16x8.{{.*}}(half %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_f16mf4x8(*base, bindex);
}

vfloat16mf2x8_t test_vlxseg8ei64_v_f16mf2x8 (float16_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_f16mf2x8
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vlxseg8ei64.v.nxv2f16x8.{{.*}}(half %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_f16mf2x8(*base, bindex);
}

vfloat16m1x8_t test_vlxseg8ei64_v_f16m1x8 (float16_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_f16m1x8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vlxseg8ei64.v.nxv4f16x8.{{.*}}(half %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg8ei64_v_f16m1x8(*base, bindex);
}

vfloat32mf2x8_t test_vlxseg8ei64_v_f32mf2x8 (float32_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_f32mf2x8
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vlxseg8ei64.v.nxv1f32x8.{{.*}}(float %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_f32mf2x8(*base, bindex);
}

vfloat32m1x8_t test_vlxseg8ei64_v_f32m1x8 (float32_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_f32m1x8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vlxseg8ei64.v.nxv2f32x8.{{.*}}(float %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_f32m1x8(*base, bindex);
}

vfloat64m1x8_t test_vlxseg8ei64_v_f64m1x8 (float64_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_f64m1x8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vlxseg8ei64.v.nxv1f32x8.{{.*}}(double %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_f64m1x8(*base, bindex);
}

vint8mf8x8_t test_vlxseg8ei64_v_i8mf8x8_m (vbool64_t mask, vint8mf8x8_t maskedoff, int8_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i8mf8x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlxseg8ei64.v.nxv1i8x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_i8mf8x8_m(mask, maskedoff, *base, bindex);
}

vint8mf4x8_t test_vlxseg8ei64_v_i8mf4x8_m (vbool32_t mask, vint8mf4x8_t maskedoff, int8_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i8mf4x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlxseg8ei64.v.nxv2i8x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_i8mf4x8_m(mask, maskedoff, *base, bindex);
}

vint8mf2x8_t test_vlxseg8ei64_v_i8mf2x8_m (vbool16_t mask, vint8mf2x8_t maskedoff, int8_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i8mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlxseg8ei64.v.nxv4i8x8.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg8ei64_v_i8mf2x8_m(mask, maskedoff, *base, bindex);
}

vint8m1x8_t test_vlxseg8ei64_v_i8m1x8_m (vbool8_t mask, vint8m1x8_t maskedoff, int8_t *base, vuint64m8_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i8m1x8_m
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlxseg8ei64.v.nxv8i8x8.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vlxseg8ei64_v_i8m1x8_m(mask, maskedoff, *base, bindex);
}

vint16mf4x8_t test_vlxseg8ei64_v_i16mf4x8_m (vbool64_t mask, vint16mf4x8_t maskedoff, int16_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i16mf4x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlxseg8ei64.v.nxv1i16x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_i16mf4x8_m(mask, maskedoff, *base, bindex);
}

vint16mf2x8_t test_vlxseg8ei64_v_i16mf2x8_m (vbool32_t mask, vint16mf2x8_t maskedoff, int16_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i16mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlxseg8ei64.v.nxv2i16x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_i16mf2x8_m(mask, maskedoff, *base, bindex);
}

vint16m1x8_t test_vlxseg8ei64_v_i16m1x8_m (vbool16_t mask, vint16m1x8_t maskedoff, int16_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i16m1x8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlxseg8ei64.v.nxv4i16x8.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg8ei64_v_i16m1x8_m(mask, maskedoff, *base, bindex);
}

vint32mf2x8_t test_vlxseg8ei64_v_i32mf2x8_m (vbool64_t mask, vint32mf2x8_t maskedoff, int32_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i32mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlxseg8ei64.v.nxv1i32x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_i32mf2x8_m(mask, maskedoff, *base, bindex);
}

vint32m1x8_t test_vlxseg8ei64_v_i32m1x8_m (vbool32_t mask, vint32m1x8_t maskedoff, int32_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i32m1x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlxseg8ei64.v.nxv2i32x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_i32m1x8_m(mask, maskedoff, *base, bindex);
}

vint64m1x8_t test_vlxseg8ei64_v_i64m1x8_m (vbool64_t mask, vint64m1x8_t maskedoff, int64_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_i64m1x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlxseg8ei64.v.nxv1i64x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_i64m1x8_m(mask, maskedoff, *base, bindex);
}

vuint8mf8x8_t test_vlxseg8ei64_v_u8mf8x8_m (vbool64_t mask, vuint8mf8x8_t maskedoff, uint8_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u8mf8x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlxseg8ei64.v.nxv1i8x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_u8mf8x8_m(mask, maskedoff, *base, bindex);
}

vuint8mf4x8_t test_vlxseg8ei64_v_u8mf4x8_m (vbool32_t mask, vuint8mf4x8_t maskedoff, uint8_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u8mf4x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlxseg8ei64.v.nxv2i8x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_u8mf4x8_m(mask, maskedoff, *base, bindex);
}

vuint8mf2x8_t test_vlxseg8ei64_v_u8mf2x8_m (vbool16_t mask, vuint8mf2x8_t maskedoff, uint8_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u8mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlxseg8ei64.v.nxv4i8x8.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg8ei64_v_u8mf2x8_m(mask, maskedoff, *base, bindex);
}

vuint8m1x8_t test_vlxseg8ei64_v_u8m1x8_m (vbool8_t mask, vuint8m1x8_t maskedoff, uint8_t *base, vuint64m8_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u8m1x8_m
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vlxseg8ei64.v.nxv8i8x8.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vlxseg8ei64_v_u8m1x8_m(mask, maskedoff, *base, bindex);
}

vuint16mf4x8_t test_vlxseg8ei64_v_u16mf4x8_m (vbool64_t mask, vuint16mf4x8_t maskedoff, uint16_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u16mf4x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlxseg8ei64.v.nxv1i16x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_u16mf4x8_m(mask, maskedoff, *base, bindex);
}

vuint16mf2x8_t test_vlxseg8ei64_v_u16mf2x8_m (vbool32_t mask, vuint16mf2x8_t maskedoff, uint16_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u16mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlxseg8ei64.v.nxv2i16x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_u16mf2x8_m(mask, maskedoff, *base, bindex);
}

vuint16m1x8_t test_vlxseg8ei64_v_u16m1x8_m (vbool16_t mask, vuint16m1x8_t maskedoff, uint16_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u16m1x8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlxseg8ei64.v.nxv4i16x8.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg8ei64_v_u16m1x8_m(mask, maskedoff, *base, bindex);
}

vuint32mf2x8_t test_vlxseg8ei64_v_u32mf2x8_m (vbool64_t mask, vuint32mf2x8_t maskedoff, uint32_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u32mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlxseg8ei64.v.nxv1i32x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_u32mf2x8_m(mask, maskedoff, *base, bindex);
}

vuint32m1x8_t test_vlxseg8ei64_v_u32m1x8_m (vbool32_t mask, vuint32m1x8_t maskedoff, uint32_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u32m1x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlxseg8ei64.v.nxv2i32x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_u32m1x8_m(mask, maskedoff, *base, bindex);
}

vuint64m1x8_t test_vlxseg8ei64_v_u64m1x8_m (vbool64_t mask, vuint64m1x8_t maskedoff, uint64_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_u64m1x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlxseg8ei64.v.nxv1i64x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_u64m1x8_m(mask, maskedoff, *base, bindex);
}

vfloat16mf4x8_t test_vlxseg8ei64_v_f16mf4x8_m (vbool64_t mask, vfloat16mf4x8_t maskedoff, float16_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_f16mf4x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vlxseg8ei64.v.nxv1f16x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_f16mf4x8_m(mask, maskedoff, *base, bindex);
}

vfloat16mf2x8_t test_vlxseg8ei64_v_f16mf2x8_m (vbool32_t mask, vfloat16mf2x8_t maskedoff, float16_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_f16mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vlxseg8ei64.v.nxv2f16x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_f16mf2x8_m(mask, maskedoff, *base, bindex);
}

vfloat16m1x8_t test_vlxseg8ei64_v_f16m1x8_m (vbool16_t mask, vfloat16m1x8_t maskedoff, float16_t *base, vuint64m4_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_f16m1x8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vlxseg8ei64.v.nxv4f16x8.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vlxseg8ei64_v_f16m1x8_m(mask, maskedoff, *base, bindex);
}

vfloat32mf2x8_t test_vlxseg8ei64_v_f32mf2x8_m (vbool64_t mask, vfloat32mf2x8_t maskedoff, float32_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_f32mf2x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vlxseg8ei64.v.nxv1f32x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_f32mf2x8_m(mask, maskedoff, *base, bindex);
}

vfloat32m1x8_t test_vlxseg8ei64_v_f32m1x8_m (vbool32_t mask, vfloat32m1x8_t maskedoff, float32_t *base, vuint64m2_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_f32m1x8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vlxseg8ei64.v.nxv2f32x8.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vlxseg8ei64_v_f32m1x8_m(mask, maskedoff, *base, bindex);
}

vfloat64m1x8_t test_vlxseg8ei64_v_f64m1x8_m (vbool64_t mask, vfloat64m1x8_t maskedoff, float64_t *base, vuint64m1_t bindex) {
  // CHECK-LABEL: test_vlxseg8ei64_v_f64m1x8_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vlxseg8ei64.v.nxv1f32x8.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, double %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vlxseg8ei64_v_f64m1x8_m(mask, maskedoff, *base, bindex);
}

