// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8_t test_vlxei16_v_i8mf8 (int8_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vlxei16.v.nxv1i8{{.*}}(i8 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_i8mf8(*base, bindex);
}

vint8mf4_t test_vlxei16_v_i8mf4 (int8_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vlxei16.v.nxv2i8{{.*}}(i8 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_i8mf4(*base, bindex);
}

vint8mf2_t test_vlxei16_v_i8mf2 (int8_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlxei16.v.nxv4i8{{.*}}(i8 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_i8mf2(*base, bindex);
}

vint8m1_t test_vlxei16_v_i8m1 (int8_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlxei16.v.nxv8i8{{.*}}(i8 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_i8m1(*base, bindex);
}

vint8m2_t test_vlxei16_v_i8m2 (int8_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlxei16.v.nxv16i8{{.*}}(i8 %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_i8m2(*base, bindex);
}

vint8m4_t test_vlxei16_v_i8m4 (int8_t *base, vuint16m8_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlxei16.v.nxv32i8{{.*}}(i8 %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vlxei16_v_i8m4(*base, bindex);
}

vint16mf4_t test_vlxei16_v_i16mf4 (int16_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vlxei16.v.nxv1i16{{.*}}(i16 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_i16mf4(*base, bindex);
}

vint16mf2_t test_vlxei16_v_i16mf2 (int16_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vlxei16.v.nxv2i16{{.*}}(i16 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_i16mf2(*base, bindex);
}

vint16m1_t test_vlxei16_v_i16m1 (int16_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlxei16.v.nxv4i16{{.*}}(i16 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_i16m1(*base, bindex);
}

vint16m2_t test_vlxei16_v_i16m2 (int16_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlxei16.v.nxv8i16{{.*}}(i16 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_i16m2(*base, bindex);
}

vint16m4_t test_vlxei16_v_i16m4 (int16_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlxei16.v.nxv16i16{{.*}}(i16 %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_i16m4(*base, bindex);
}

vint16m8_t test_vlxei16_v_i16m8 (int16_t *base, vuint16m8_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlxei16.v.nxv32i16{{.*}}(i16 %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vlxei16_v_i16m8(*base, bindex);
}

vint32mf2_t test_vlxei16_v_i32mf2 (int32_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vlxei16.v.nxv1i32{{.*}}(i32 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_i32mf2(*base, bindex);
}

vint32m1_t test_vlxei16_v_i32m1 (int32_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vlxei16.v.nxv2i32{{.*}}(i32 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_i32m1(*base, bindex);
}

vint32m2_t test_vlxei16_v_i32m2 (int32_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlxei16.v.nxv4i32{{.*}}(i32 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_i32m2(*base, bindex);
}

vint32m4_t test_vlxei16_v_i32m4 (int32_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlxei16.v.nxv8i32{{.*}}(i32 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_i32m4(*base, bindex);
}

vint32m8_t test_vlxei16_v_i32m8 (int32_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlxei16.v.nxv16i32{{.*}}(i32 %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_i32m8(*base, bindex);
}

vint64m1_t test_vlxei16_v_i64m1 (int64_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vlxei16.v.nxv1i64{{.*}}(i64 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_i64m1(*base, bindex);
}

vint64m2_t test_vlxei16_v_i64m2 (int64_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vlxei16.v.nxv2i64{{.*}}(i64 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_i64m2(*base, bindex);
}

vint64m4_t test_vlxei16_v_i64m4 (int64_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlxei16.v.nxv4i64{{.*}}(i64 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_i64m4(*base, bindex);
}

vint64m8_t test_vlxei16_v_i64m8 (int64_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlxei16.v.nxv8i64{{.*}}(i64 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_i64m8(*base, bindex);
}

vuint8mf8_t test_vlxei16_v_u8mf8 (uint8_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vlxei16.v.nxv1i8{{.*}}(i8 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_u8mf8(*base, bindex);
}

vuint8mf4_t test_vlxei16_v_u8mf4 (uint8_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vlxei16.v.nxv2i8{{.*}}(i8 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_u8mf4(*base, bindex);
}

vuint8mf2_t test_vlxei16_v_u8mf2 (uint8_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlxei16.v.nxv4i8{{.*}}(i8 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_u8mf2(*base, bindex);
}

vuint8m1_t test_vlxei16_v_u8m1 (uint8_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlxei16.v.nxv8i8{{.*}}(i8 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_u8m1(*base, bindex);
}

vuint8m2_t test_vlxei16_v_u8m2 (uint8_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlxei16.v.nxv16i8{{.*}}(i8 %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_u8m2(*base, bindex);
}

vuint8m4_t test_vlxei16_v_u8m4 (uint8_t *base, vuint16m8_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlxei16.v.nxv32i8{{.*}}(i8 %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vlxei16_v_u8m4(*base, bindex);
}

vuint16mf4_t test_vlxei16_v_u16mf4 (uint16_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vlxei16.v.nxv1i16{{.*}}(i16 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_u16mf4(*base, bindex);
}

vuint16mf2_t test_vlxei16_v_u16mf2 (uint16_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vlxei16.v.nxv2i16{{.*}}(i16 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_u16mf2(*base, bindex);
}

vuint16m1_t test_vlxei16_v_u16m1 (uint16_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlxei16.v.nxv4i16{{.*}}(i16 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_u16m1(*base, bindex);
}

vuint16m2_t test_vlxei16_v_u16m2 (uint16_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlxei16.v.nxv8i16{{.*}}(i16 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_u16m2(*base, bindex);
}

vuint16m4_t test_vlxei16_v_u16m4 (uint16_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlxei16.v.nxv16i16{{.*}}(i16 %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_u16m4(*base, bindex);
}

vuint16m8_t test_vlxei16_v_u16m8 (uint16_t *base, vuint16m8_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlxei16.v.nxv32i16{{.*}}(i16 %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vlxei16_v_u16m8(*base, bindex);
}

vuint32mf2_t test_vlxei16_v_u32mf2 (uint32_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vlxei16.v.nxv1i32{{.*}}(i32 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_u32mf2(*base, bindex);
}

vuint32m1_t test_vlxei16_v_u32m1 (uint32_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vlxei16.v.nxv2i32{{.*}}(i32 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_u32m1(*base, bindex);
}

vuint32m2_t test_vlxei16_v_u32m2 (uint32_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlxei16.v.nxv4i32{{.*}}(i32 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_u32m2(*base, bindex);
}

vuint32m4_t test_vlxei16_v_u32m4 (uint32_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlxei16.v.nxv8i32{{.*}}(i32 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_u32m4(*base, bindex);
}

vuint32m8_t test_vlxei16_v_u32m8 (uint32_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlxei16.v.nxv16i32{{.*}}(i32 %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_u32m8(*base, bindex);
}

vuint64m1_t test_vlxei16_v_u64m1 (uint64_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vlxei16.v.nxv1i64{{.*}}(i64 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_u64m1(*base, bindex);
}

vuint64m2_t test_vlxei16_v_u64m2 (uint64_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vlxei16.v.nxv2i64{{.*}}(i64 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_u64m2(*base, bindex);
}

vuint64m4_t test_vlxei16_v_u64m4 (uint64_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlxei16.v.nxv4i64{{.*}}(i64 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_u64m4(*base, bindex);
}

vuint64m8_t test_vlxei16_v_u64m8 (uint64_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlxei16.v.nxv8i64{{.*}}(i64 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_u64m8(*base, bindex);
}

vfloat16mf4_t test_vlxei16_v_f16mf4 (float16_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vlxei16.v.nxv1f16{{.*}}(half %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_f16mf4(*base, bindex);
}

vfloat16mf2_t test_vlxei16_v_f16mf2 (float16_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vlxei16.v.nxv2f16{{.*}}(half %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_f16mf2(*base, bindex);
}

vfloat16m1_t test_vlxei16_v_f16m1 (float16_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vlxei16.v.nxv4f16{{.*}}(half %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_f16m1(*base, bindex);
}

vfloat16m2_t test_vlxei16_v_f16m2 (float16_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vlxei16.v.nxv8f16{{.*}}(half %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_f16m2(*base, bindex);
}

vfloat16m4_t test_vlxei16_v_f16m4 (float16_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vlxei16.v.nxv16f16{{.*}}(half %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_f16m4(*base, bindex);
}

vfloat16m8_t test_vlxei16_v_f16m8 (float16_t *base, vuint16m8_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vlxei16.v.nxv32f16{{.*}}(half %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vlxei16_v_f16m8(*base, bindex);
}

vfloat32mf2_t test_vlxei16_v_f32mf2 (float32_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vlxei16.v.nxv1f32{{.*}}(float %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_f32mf2(*base, bindex);
}

vfloat32m1_t test_vlxei16_v_f32m1 (float32_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vlxei16.v.nxv2f32{{.*}}(float %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_f32m1(*base, bindex);
}

vfloat32m2_t test_vlxei16_v_f32m2 (float32_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vlxei16.v.nxv4f32{{.*}}(float %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_f32m2(*base, bindex);
}

vfloat32m4_t test_vlxei16_v_f32m4 (float32_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vlxei16.v.nxv8f32{{.*}}(float %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_f32m4(*base, bindex);
}

vfloat32m8_t test_vlxei16_v_f32m8 (float32_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vlxei16.v.nxv16f32{{.*}}(float %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_f32m8(*base, bindex);
}

vfloat64m1_t test_vlxei16_v_f64m1 (float64_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vlxei16.v.nxv1f32{{.*}}(double %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_f64m1(*base, bindex);
}

vfloat64m2_t test_vlxei16_v_f64m2 (float64_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vlxei16.v.nxv2f32{{.*}}(double %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_f64m2(*base, bindex);
}

vfloat64m4_t test_vlxei16_v_f64m4 (float64_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vlxei16.v.nxv4f32{{.*}}(double %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_f64m4(*base, bindex);
}

vfloat64m8_t test_vlxei16_v_f64m8 (float64_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vlxei16.v.nxv8f32{{.*}}(double %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_f64m8(*base, bindex);
}

vint8mf8_t test_vlxei16_v_i8mf8_m (vbool64_t mask, vint8mf8_t maskedoff, int8_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i8mf8_m
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vlxei16.v.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_i8mf8_m(mask, maskedoff, *base, bindex);
}

vint8mf4_t test_vlxei16_v_i8mf4_m (vbool32_t mask, vint8mf4_t maskedoff, int8_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i8mf4_m
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vlxei16.v.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_i8mf4_m(mask, maskedoff, *base, bindex);
}

vint8mf2_t test_vlxei16_v_i8mf2_m (vbool16_t mask, vint8mf2_t maskedoff, int8_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i8mf2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlxei16.v.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_i8mf2_m(mask, maskedoff, *base, bindex);
}

vint8m1_t test_vlxei16_v_i8m1_m (vbool8_t mask, vint8m1_t maskedoff, int8_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlxei16.v.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_i8m1_m(mask, maskedoff, *base, bindex);
}

vint8m2_t test_vlxei16_v_i8m2_m (vbool4_t mask, vint8m2_t maskedoff, int8_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i8m2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlxei16.v.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_i8m2_m(mask, maskedoff, *base, bindex);
}

vint8m4_t test_vlxei16_v_i8m4_m (vbool2_t mask, vint8m4_t maskedoff, int8_t *base, vuint16m8_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i8m4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlxei16.v.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vlxei16_v_i8m4_m(mask, maskedoff, *base, bindex);
}

vint16mf4_t test_vlxei16_v_i16mf4_m (vbool64_t mask, vint16mf4_t maskedoff, int16_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vlxei16.v.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_i16mf4_m(mask, maskedoff, *base, bindex);
}

vint16mf2_t test_vlxei16_v_i16mf2_m (vbool32_t mask, vint16mf2_t maskedoff, int16_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vlxei16.v.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_i16mf2_m(mask, maskedoff, *base, bindex);
}

vint16m1_t test_vlxei16_v_i16m1_m (vbool16_t mask, vint16m1_t maskedoff, int16_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlxei16.v.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_i16m1_m(mask, maskedoff, *base, bindex);
}

vint16m2_t test_vlxei16_v_i16m2_m (vbool8_t mask, vint16m2_t maskedoff, int16_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlxei16.v.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_i16m2_m(mask, maskedoff, *base, bindex);
}

vint16m4_t test_vlxei16_v_i16m4_m (vbool4_t mask, vint16m4_t maskedoff, int16_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlxei16.v.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_i16m4_m(mask, maskedoff, *base, bindex);
}

vint16m8_t test_vlxei16_v_i16m8_m (vbool2_t mask, vint16m8_t maskedoff, int16_t *base, vuint16m8_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlxei16.v.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vlxei16_v_i16m8_m(mask, maskedoff, *base, bindex);
}

vint32mf2_t test_vlxei16_v_i32mf2_m (vbool64_t mask, vint32mf2_t maskedoff, int32_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vlxei16.v.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_i32mf2_m(mask, maskedoff, *base, bindex);
}

vint32m1_t test_vlxei16_v_i32m1_m (vbool32_t mask, vint32m1_t maskedoff, int32_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vlxei16.v.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_i32m1_m(mask, maskedoff, *base, bindex);
}

vint32m2_t test_vlxei16_v_i32m2_m (vbool16_t mask, vint32m2_t maskedoff, int32_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlxei16.v.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_i32m2_m(mask, maskedoff, *base, bindex);
}

vint32m4_t test_vlxei16_v_i32m4_m (vbool8_t mask, vint32m4_t maskedoff, int32_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlxei16.v.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_i32m4_m(mask, maskedoff, *base, bindex);
}

vint32m8_t test_vlxei16_v_i32m8_m (vbool4_t mask, vint32m8_t maskedoff, int32_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlxei16.v.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_i32m8_m(mask, maskedoff, *base, bindex);
}

vint64m1_t test_vlxei16_v_i64m1_m (vbool64_t mask, vint64m1_t maskedoff, int64_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vlxei16.v.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_i64m1_m(mask, maskedoff, *base, bindex);
}

vint64m2_t test_vlxei16_v_i64m2_m (vbool32_t mask, vint64m2_t maskedoff, int64_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vlxei16.v.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_i64m2_m(mask, maskedoff, *base, bindex);
}

vint64m4_t test_vlxei16_v_i64m4_m (vbool16_t mask, vint64m4_t maskedoff, int64_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlxei16.v.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_i64m4_m(mask, maskedoff, *base, bindex);
}

vint64m8_t test_vlxei16_v_i64m8_m (vbool8_t mask, vint64m8_t maskedoff, int64_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_i64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlxei16.v.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_i64m8_m(mask, maskedoff, *base, bindex);
}

vuint8mf8_t test_vlxei16_v_u8mf8_m (vbool64_t mask, vuint8mf8_t maskedoff, uint8_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u8mf8_m
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vlxei16.v.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_u8mf8_m(mask, maskedoff, *base, bindex);
}

vuint8mf4_t test_vlxei16_v_u8mf4_m (vbool32_t mask, vuint8mf4_t maskedoff, uint8_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u8mf4_m
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vlxei16.v.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_u8mf4_m(mask, maskedoff, *base, bindex);
}

vuint8mf2_t test_vlxei16_v_u8mf2_m (vbool16_t mask, vuint8mf2_t maskedoff, uint8_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u8mf2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vlxei16.v.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_u8mf2_m(mask, maskedoff, *base, bindex);
}

vuint8m1_t test_vlxei16_v_u8m1_m (vbool8_t mask, vuint8m1_t maskedoff, uint8_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vlxei16.v.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_u8m1_m(mask, maskedoff, *base, bindex);
}

vuint8m2_t test_vlxei16_v_u8m2_m (vbool4_t mask, vuint8m2_t maskedoff, uint8_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u8m2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vlxei16.v.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_u8m2_m(mask, maskedoff, *base, bindex);
}

vuint8m4_t test_vlxei16_v_u8m4_m (vbool2_t mask, vuint8m4_t maskedoff, uint8_t *base, vuint16m8_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u8m4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vlxei16.v.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vlxei16_v_u8m4_m(mask, maskedoff, *base, bindex);
}

vuint16mf4_t test_vlxei16_v_u16mf4_m (vbool64_t mask, vuint16mf4_t maskedoff, uint16_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vlxei16.v.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_u16mf4_m(mask, maskedoff, *base, bindex);
}

vuint16mf2_t test_vlxei16_v_u16mf2_m (vbool32_t mask, vuint16mf2_t maskedoff, uint16_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vlxei16.v.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_u16mf2_m(mask, maskedoff, *base, bindex);
}

vuint16m1_t test_vlxei16_v_u16m1_m (vbool16_t mask, vuint16m1_t maskedoff, uint16_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vlxei16.v.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_u16m1_m(mask, maskedoff, *base, bindex);
}

vuint16m2_t test_vlxei16_v_u16m2_m (vbool8_t mask, vuint16m2_t maskedoff, uint16_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vlxei16.v.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_u16m2_m(mask, maskedoff, *base, bindex);
}

vuint16m4_t test_vlxei16_v_u16m4_m (vbool4_t mask, vuint16m4_t maskedoff, uint16_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vlxei16.v.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_u16m4_m(mask, maskedoff, *base, bindex);
}

vuint16m8_t test_vlxei16_v_u16m8_m (vbool2_t mask, vuint16m8_t maskedoff, uint16_t *base, vuint16m8_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vlxei16.v.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vlxei16_v_u16m8_m(mask, maskedoff, *base, bindex);
}

vuint32mf2_t test_vlxei16_v_u32mf2_m (vbool64_t mask, vuint32mf2_t maskedoff, uint32_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vlxei16.v.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_u32mf2_m(mask, maskedoff, *base, bindex);
}

vuint32m1_t test_vlxei16_v_u32m1_m (vbool32_t mask, vuint32m1_t maskedoff, uint32_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vlxei16.v.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_u32m1_m(mask, maskedoff, *base, bindex);
}

vuint32m2_t test_vlxei16_v_u32m2_m (vbool16_t mask, vuint32m2_t maskedoff, uint32_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vlxei16.v.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_u32m2_m(mask, maskedoff, *base, bindex);
}

vuint32m4_t test_vlxei16_v_u32m4_m (vbool8_t mask, vuint32m4_t maskedoff, uint32_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vlxei16.v.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_u32m4_m(mask, maskedoff, *base, bindex);
}

vuint32m8_t test_vlxei16_v_u32m8_m (vbool4_t mask, vuint32m8_t maskedoff, uint32_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vlxei16.v.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_u32m8_m(mask, maskedoff, *base, bindex);
}

vuint64m1_t test_vlxei16_v_u64m1_m (vbool64_t mask, vuint64m1_t maskedoff, uint64_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vlxei16.v.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_u64m1_m(mask, maskedoff, *base, bindex);
}

vuint64m2_t test_vlxei16_v_u64m2_m (vbool32_t mask, vuint64m2_t maskedoff, uint64_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vlxei16.v.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_u64m2_m(mask, maskedoff, *base, bindex);
}

vuint64m4_t test_vlxei16_v_u64m4_m (vbool16_t mask, vuint64m4_t maskedoff, uint64_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vlxei16.v.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_u64m4_m(mask, maskedoff, *base, bindex);
}

vuint64m8_t test_vlxei16_v_u64m8_m (vbool8_t mask, vuint64m8_t maskedoff, uint64_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vlxei16.v.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_u64m8_m(mask, maskedoff, *base, bindex);
}

vfloat16mf4_t test_vlxei16_v_f16mf4_m (vbool64_t mask, vfloat16mf4_t maskedoff, float16_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vlxei16.v.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, half %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_f16mf4_m(mask, maskedoff, *base, bindex);
}

vfloat16mf2_t test_vlxei16_v_f16mf2_m (vbool32_t mask, vfloat16mf2_t maskedoff, float16_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vlxei16.v.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, half %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_f16mf2_m(mask, maskedoff, *base, bindex);
}

vfloat16m1_t test_vlxei16_v_f16m1_m (vbool16_t mask, vfloat16m1_t maskedoff, float16_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vlxei16.v.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, half %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_f16m1_m(mask, maskedoff, *base, bindex);
}

vfloat16m2_t test_vlxei16_v_f16m2_m (vbool8_t mask, vfloat16m2_t maskedoff, float16_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vlxei16.v.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, half %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_f16m2_m(mask, maskedoff, *base, bindex);
}

vfloat16m4_t test_vlxei16_v_f16m4_m (vbool4_t mask, vfloat16m4_t maskedoff, float16_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vlxei16.v.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, half %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_f16m4_m(mask, maskedoff, *base, bindex);
}

vfloat16m8_t test_vlxei16_v_f16m8_m (vbool2_t mask, vfloat16m8_t maskedoff, float16_t *base, vuint16m8_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vlxei16.v.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, half %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vlxei16_v_f16m8_m(mask, maskedoff, *base, bindex);
}

vfloat32mf2_t test_vlxei16_v_f32mf2_m (vbool64_t mask, vfloat32mf2_t maskedoff, float32_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vlxei16.v.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, float %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_f32mf2_m(mask, maskedoff, *base, bindex);
}

vfloat32m1_t test_vlxei16_v_f32m1_m (vbool32_t mask, vfloat32m1_t maskedoff, float32_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vlxei16.v.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_f32m1_m(mask, maskedoff, *base, bindex);
}

vfloat32m2_t test_vlxei16_v_f32m2_m (vbool16_t mask, vfloat32m2_t maskedoff, float32_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vlxei16.v.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_f32m2_m(mask, maskedoff, *base, bindex);
}

vfloat32m4_t test_vlxei16_v_f32m4_m (vbool8_t mask, vfloat32m4_t maskedoff, float32_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vlxei16.v.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_f32m4_m(mask, maskedoff, *base, bindex);
}

vfloat32m8_t test_vlxei16_v_f32m8_m (vbool4_t mask, vfloat32m8_t maskedoff, float32_t *base, vuint16m4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vlxei16.v.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vlxei16_v_f32m8_m(mask, maskedoff, *base, bindex);
}

vfloat64m1_t test_vlxei16_v_f64m1_m (vbool64_t mask, vfloat64m1_t maskedoff, float64_t *base, vuint16mf4_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vlxei16.v.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, double %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vlxei16_v_f64m1_m(mask, maskedoff, *base, bindex);
}

vfloat64m2_t test_vlxei16_v_f64m2_m (vbool32_t mask, vfloat64m2_t maskedoff, float64_t *base, vuint16mf2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vlxei16.v.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, double %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vlxei16_v_f64m2_m(mask, maskedoff, *base, bindex);
}

vfloat64m4_t test_vlxei16_v_f64m4_m (vbool16_t mask, vfloat64m4_t maskedoff, float64_t *base, vuint16m1_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vlxei16.v.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, double %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vlxei16_v_f64m4_m(mask, maskedoff, *base, bindex);
}

vfloat64m8_t test_vlxei16_v_f64m8_m (vbool8_t mask, vfloat64m8_t maskedoff, float64_t *base, vuint16m2_t bindex) {
  // CHECK-LABEL: test_vlxei16_v_f64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vlxei16.v.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, double %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vlxei16_v_f64m8_m(mask, maskedoff, *base, bindex);
}

