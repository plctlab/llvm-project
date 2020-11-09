// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat16mf4_t test_vmv_v_v_f16mf4 (vfloat16mf4_t src) {
  // CHECK-LABEL: test_vmv_v_v_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vmv.v.v.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}})
  return vmv_v_v_f16mf4(src);
}

vfloat16mf2_t test_vmv_v_v_f16mf2 (vfloat16mf2_t src) {
  // CHECK-LABEL: test_vmv_v_v_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vmv.v.v.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}})
  return vmv_v_v_f16mf2(src);
}

vfloat16m1_t test_vmv_v_v_f16m1 (vfloat16m1_t src) {
  // CHECK-LABEL: test_vmv_v_v_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vmv.v.v.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}})
  return vmv_v_v_f16m1(src);
}

vfloat16m2_t test_vmv_v_v_f16m2 (vfloat16m2_t src) {
  // CHECK-LABEL: test_vmv_v_v_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vmv.v.v.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}})
  return vmv_v_v_f16m2(src);
}

vfloat16m4_t test_vmv_v_v_f16m4 (vfloat16m4_t src) {
  // CHECK-LABEL: test_vmv_v_v_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vmv.v.v.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}})
  return vmv_v_v_f16m4(src);
}

vfloat16m8_t test_vmv_v_v_f16m8 (vfloat16m8_t src) {
  // CHECK-LABEL: test_vmv_v_v_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vmv.v.v.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}})
  return vmv_v_v_f16m8(src);
}

vfloat32mf2_t test_vmv_v_v_f32mf2 (vfloat32mf2_t src) {
  // CHECK-LABEL: test_vmv_v_v_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vmv.v.v.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}})
  return vmv_v_v_f32mf2(src);
}

vfloat32m1_t test_vmv_v_v_f32m1 (vfloat32m1_t src) {
  // CHECK-LABEL: test_vmv_v_v_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vmv.v.v.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}})
  return vmv_v_v_f32m1(src);
}

vfloat32m2_t test_vmv_v_v_f32m2 (vfloat32m2_t src) {
  // CHECK-LABEL: test_vmv_v_v_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vmv.v.v.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}})
  return vmv_v_v_f32m2(src);
}

vfloat32m4_t test_vmv_v_v_f32m4 (vfloat32m4_t src) {
  // CHECK-LABEL: test_vmv_v_v_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vmv.v.v.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}})
  return vmv_v_v_f32m4(src);
}

vfloat32m8_t test_vmv_v_v_f32m8 (vfloat32m8_t src) {
  // CHECK-LABEL: test_vmv_v_v_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vmv.v.v.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}})
  return vmv_v_v_f32m8(src);
}

vfloat64m1_t test_vmv_v_v_f64m1 (vfloat64m1_t src) {
  // CHECK-LABEL: test_vmv_v_v_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vmv.v.v.nxv1f32{{.*}}(<vscale x 1 x double> %{{.*}})
  return vmv_v_v_f64m1(src);
}

vfloat64m2_t test_vmv_v_v_f64m2 (vfloat64m2_t src) {
  // CHECK-LABEL: test_vmv_v_v_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vmv.v.v.nxv2f32{{.*}}(<vscale x 2 x double> %{{.*}})
  return vmv_v_v_f64m2(src);
}

vfloat64m4_t test_vmv_v_v_f64m4 (vfloat64m4_t src) {
  // CHECK-LABEL: test_vmv_v_v_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vmv.v.v.nxv4f32{{.*}}(<vscale x 4 x double> %{{.*}})
  return vmv_v_v_f64m4(src);
}

vfloat64m8_t test_vmv_v_v_f64m8 (vfloat64m8_t src) {
  // CHECK-LABEL: test_vmv_v_v_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vmv.v.v.nxv8f32{{.*}}(<vscale x 8 x double> %{{.*}})
  return vmv_v_v_f64m8(src);
}

vint8mf8_t test_vmv_v_v_i8mf8 (vint8mf8_t src) {
  // CHECK-LABEL: test_vmv_v_v_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vmv.v.v.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}})
  return vmv_v_v_i8mf8(src);
}

vint8mf8_t test_vmv_v_x_i8mf8 (int8_t src) {
  // CHECK-LABEL: test_vmv_v_x_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vmv.v.x.nxv1i8{{.*}}(i8 %{{.*}})
  return vmv_v_x_i8mf8(src);
}

vint8mf4_t test_vmv_v_v_i8mf4 (vint8mf4_t src) {
  // CHECK-LABEL: test_vmv_v_v_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vmv.v.v.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}})
  return vmv_v_v_i8mf4(src);
}

vint8mf4_t test_vmv_v_x_i8mf4 (int8_t src) {
  // CHECK-LABEL: test_vmv_v_x_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vmv.v.x.nxv2i8{{.*}}(i8 %{{.*}})
  return vmv_v_x_i8mf4(src);
}

vint8mf2_t test_vmv_v_v_i8mf2 (vint8mf2_t src) {
  // CHECK-LABEL: test_vmv_v_v_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vmv.v.v.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}})
  return vmv_v_v_i8mf2(src);
}

vint8mf2_t test_vmv_v_x_i8mf2 (int8_t src) {
  // CHECK-LABEL: test_vmv_v_x_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vmv.v.x.nxv4i8{{.*}}(i8 %{{.*}})
  return vmv_v_x_i8mf2(src);
}

vint8m1_t test_vmv_v_v_i8m1 (vint8m1_t src) {
  // CHECK-LABEL: test_vmv_v_v_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vmv.v.v.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vmv_v_v_i8m1(src);
}

vint8m1_t test_vmv_v_x_i8m1 (int8_t src) {
  // CHECK-LABEL: test_vmv_v_x_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vmv.v.x.nxv8i8{{.*}}(i8 %{{.*}})
  return vmv_v_x_i8m1(src);
}

vint8m2_t test_vmv_v_v_i8m2 (vint8m2_t src) {
  // CHECK-LABEL: test_vmv_v_v_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vmv.v.v.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vmv_v_v_i8m2(src);
}

vint8m2_t test_vmv_v_x_i8m2 (int8_t src) {
  // CHECK-LABEL: test_vmv_v_x_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vmv.v.x.nxv16i8{{.*}}(i8 %{{.*}})
  return vmv_v_x_i8m2(src);
}

vint8m4_t test_vmv_v_v_i8m4 (vint8m4_t src) {
  // CHECK-LABEL: test_vmv_v_v_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vmv.v.v.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vmv_v_v_i8m4(src);
}

vint8m4_t test_vmv_v_x_i8m4 (int8_t src) {
  // CHECK-LABEL: test_vmv_v_x_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vmv.v.x.nxv32i8{{.*}}(i8 %{{.*}})
  return vmv_v_x_i8m4(src);
}

vint8m8_t test_vmv_v_v_i8m8 (vint8m8_t src) {
  // CHECK-LABEL: test_vmv_v_v_i8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vmv.v.v.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}})
  return vmv_v_v_i8m8(src);
}

vint8m8_t test_vmv_v_x_i8m8 (int8_t src) {
  // CHECK-LABEL: test_vmv_v_x_i8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vmv.v.x.nxv64i8{{.*}}(i8 %{{.*}})
  return vmv_v_x_i8m8(src);
}

vint16mf4_t test_vmv_v_v_i16mf4 (vint16mf4_t src) {
  // CHECK-LABEL: test_vmv_v_v_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vmv.v.v.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}})
  return vmv_v_v_i16mf4(src);
}

vint16mf4_t test_vmv_v_x_i16mf4 (int16_t src) {
  // CHECK-LABEL: test_vmv_v_x_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vmv.v.x.nxv1i16{{.*}}(i16 %{{.*}})
  return vmv_v_x_i16mf4(src);
}

vint16mf2_t test_vmv_v_v_i16mf2 (vint16mf2_t src) {
  // CHECK-LABEL: test_vmv_v_v_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vmv.v.v.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}})
  return vmv_v_v_i16mf2(src);
}

vint16mf2_t test_vmv_v_x_i16mf2 (int16_t src) {
  // CHECK-LABEL: test_vmv_v_x_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vmv.v.x.nxv2i16{{.*}}(i16 %{{.*}})
  return vmv_v_x_i16mf2(src);
}

vint16m1_t test_vmv_v_v_i16m1 (vint16m1_t src) {
  // CHECK-LABEL: test_vmv_v_v_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vmv.v.v.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vmv_v_v_i16m1(src);
}

vint16m1_t test_vmv_v_x_i16m1 (int16_t src) {
  // CHECK-LABEL: test_vmv_v_x_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vmv.v.x.nxv4i16{{.*}}(i16 %{{.*}})
  return vmv_v_x_i16m1(src);
}

vint16m2_t test_vmv_v_v_i16m2 (vint16m2_t src) {
  // CHECK-LABEL: test_vmv_v_v_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vmv.v.v.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vmv_v_v_i16m2(src);
}

vint16m2_t test_vmv_v_x_i16m2 (int16_t src) {
  // CHECK-LABEL: test_vmv_v_x_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vmv.v.x.nxv8i16{{.*}}(i16 %{{.*}})
  return vmv_v_x_i16m2(src);
}

vint16m4_t test_vmv_v_v_i16m4 (vint16m4_t src) {
  // CHECK-LABEL: test_vmv_v_v_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vmv.v.v.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vmv_v_v_i16m4(src);
}

vint16m4_t test_vmv_v_x_i16m4 (int16_t src) {
  // CHECK-LABEL: test_vmv_v_x_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vmv.v.x.nxv16i16{{.*}}(i16 %{{.*}})
  return vmv_v_x_i16m4(src);
}

vint16m8_t test_vmv_v_v_i16m8 (vint16m8_t src) {
  // CHECK-LABEL: test_vmv_v_v_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vmv.v.v.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vmv_v_v_i16m8(src);
}

vint16m8_t test_vmv_v_x_i16m8 (int16_t src) {
  // CHECK-LABEL: test_vmv_v_x_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vmv.v.x.nxv32i16{{.*}}(i16 %{{.*}})
  return vmv_v_x_i16m8(src);
}

vint32mf2_t test_vmv_v_v_i32mf2 (vint32mf2_t src) {
  // CHECK-LABEL: test_vmv_v_v_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vmv.v.v.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}})
  return vmv_v_v_i32mf2(src);
}

vint32mf2_t test_vmv_v_x_i32mf2 (int32_t src) {
  // CHECK-LABEL: test_vmv_v_x_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vmv.v.x.nxv1i32{{.*}}(i32 %{{.*}})
  return vmv_v_x_i32mf2(src);
}

vint32m1_t test_vmv_v_v_i32m1 (vint32m1_t src) {
  // CHECK-LABEL: test_vmv_v_v_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vmv.v.v.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}})
  return vmv_v_v_i32m1(src);
}

vint32m1_t test_vmv_v_x_i32m1 (int32_t src) {
  // CHECK-LABEL: test_vmv_v_x_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vmv.v.x.nxv2i32{{.*}}(i32 %{{.*}})
  return vmv_v_x_i32m1(src);
}

vint32m2_t test_vmv_v_v_i32m2 (vint32m2_t src) {
  // CHECK-LABEL: test_vmv_v_v_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vmv.v.v.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vmv_v_v_i32m2(src);
}

vint32m2_t test_vmv_v_x_i32m2 (int32_t src) {
  // CHECK-LABEL: test_vmv_v_x_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vmv.v.x.nxv4i32{{.*}}(i32 %{{.*}})
  return vmv_v_x_i32m2(src);
}

vint32m4_t test_vmv_v_v_i32m4 (vint32m4_t src) {
  // CHECK-LABEL: test_vmv_v_v_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vmv.v.v.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vmv_v_v_i32m4(src);
}

vint32m4_t test_vmv_v_x_i32m4 (int32_t src) {
  // CHECK-LABEL: test_vmv_v_x_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vmv.v.x.nxv8i32{{.*}}(i32 %{{.*}})
  return vmv_v_x_i32m4(src);
}

vint32m8_t test_vmv_v_v_i32m8 (vint32m8_t src) {
  // CHECK-LABEL: test_vmv_v_v_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vmv.v.v.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vmv_v_v_i32m8(src);
}

vint32m8_t test_vmv_v_x_i32m8 (int32_t src) {
  // CHECK-LABEL: test_vmv_v_x_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vmv.v.x.nxv16i32{{.*}}(i32 %{{.*}})
  return vmv_v_x_i32m8(src);
}

vint64m1_t test_vmv_v_v_i64m1 (vint64m1_t src) {
  // CHECK-LABEL: test_vmv_v_v_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vmv.v.v.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}})
  return vmv_v_v_i64m1(src);
}

vint64m1_t test_vmv_v_x_i64m1 (int64_t src) {
  // CHECK-LABEL: test_vmv_v_x_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vmv.v.x.nxv1i64{{.*}}(i64 %{{.*}})
  return vmv_v_x_i64m1(src);
}

vint64m2_t test_vmv_v_v_i64m2 (vint64m2_t src) {
  // CHECK-LABEL: test_vmv_v_v_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vmv.v.v.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}})
  return vmv_v_v_i64m2(src);
}

vint64m2_t test_vmv_v_x_i64m2 (int64_t src) {
  // CHECK-LABEL: test_vmv_v_x_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vmv.v.x.nxv2i64{{.*}}(i64 %{{.*}})
  return vmv_v_x_i64m2(src);
}

vint64m4_t test_vmv_v_v_i64m4 (vint64m4_t src) {
  // CHECK-LABEL: test_vmv_v_v_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vmv.v.v.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}})
  return vmv_v_v_i64m4(src);
}

vint64m4_t test_vmv_v_x_i64m4 (int64_t src) {
  // CHECK-LABEL: test_vmv_v_x_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vmv.v.x.nxv4i64{{.*}}(i64 %{{.*}})
  return vmv_v_x_i64m4(src);
}

vint64m8_t test_vmv_v_v_i64m8 (vint64m8_t src) {
  // CHECK-LABEL: test_vmv_v_v_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vmv.v.v.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vmv_v_v_i64m8(src);
}

vint64m8_t test_vmv_v_x_i64m8 (int64_t src) {
  // CHECK-LABEL: test_vmv_v_x_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vmv.v.x.nxv8i64{{.*}}(i64 %{{.*}})
  return vmv_v_x_i64m8(src);
}

vuint8mf8_t test_vmv_v_v_u8mf8 (vuint8mf8_t src) {
  // CHECK-LABEL: test_vmv_v_v_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vmv.v.v.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}})
  return vmv_v_v_u8mf8(src);
}

vuint8mf8_t test_vmv_v_x_u8mf8 (uint8_t src) {
  // CHECK-LABEL: test_vmv_v_x_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vmv.v.x.nxv1i8{{.*}}(i8 %{{.*}})
  return vmv_v_x_u8mf8(src);
}

vuint8mf4_t test_vmv_v_v_u8mf4 (vuint8mf4_t src) {
  // CHECK-LABEL: test_vmv_v_v_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vmv.v.v.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}})
  return vmv_v_v_u8mf4(src);
}

vuint8mf4_t test_vmv_v_x_u8mf4 (uint8_t src) {
  // CHECK-LABEL: test_vmv_v_x_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vmv.v.x.nxv2i8{{.*}}(i8 %{{.*}})
  return vmv_v_x_u8mf4(src);
}

vuint8mf2_t test_vmv_v_v_u8mf2 (vuint8mf2_t src) {
  // CHECK-LABEL: test_vmv_v_v_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vmv.v.v.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}})
  return vmv_v_v_u8mf2(src);
}

vuint8mf2_t test_vmv_v_x_u8mf2 (uint8_t src) {
  // CHECK-LABEL: test_vmv_v_x_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vmv.v.x.nxv4i8{{.*}}(i8 %{{.*}})
  return vmv_v_x_u8mf2(src);
}

vuint8m1_t test_vmv_v_v_u8m1 (vuint8m1_t src) {
  // CHECK-LABEL: test_vmv_v_v_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vmv.v.v.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vmv_v_v_u8m1(src);
}

vuint8m1_t test_vmv_v_x_u8m1 (uint8_t src) {
  // CHECK-LABEL: test_vmv_v_x_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vmv.v.x.nxv8i8{{.*}}(i8 %{{.*}})
  return vmv_v_x_u8m1(src);
}

vuint8m2_t test_vmv_v_v_u8m2 (vuint8m2_t src) {
  // CHECK-LABEL: test_vmv_v_v_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vmv.v.v.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vmv_v_v_u8m2(src);
}

vuint8m2_t test_vmv_v_x_u8m2 (uint8_t src) {
  // CHECK-LABEL: test_vmv_v_x_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vmv.v.x.nxv16i8{{.*}}(i8 %{{.*}})
  return vmv_v_x_u8m2(src);
}

vuint8m4_t test_vmv_v_v_u8m4 (vuint8m4_t src) {
  // CHECK-LABEL: test_vmv_v_v_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vmv.v.v.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vmv_v_v_u8m4(src);
}

vuint8m4_t test_vmv_v_x_u8m4 (uint8_t src) {
  // CHECK-LABEL: test_vmv_v_x_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vmv.v.x.nxv32i8{{.*}}(i8 %{{.*}})
  return vmv_v_x_u8m4(src);
}

vuint8m8_t test_vmv_v_v_u8m8 (vuint8m8_t src) {
  // CHECK-LABEL: test_vmv_v_v_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vmv.v.v.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}})
  return vmv_v_v_u8m8(src);
}

vuint8m8_t test_vmv_v_x_u8m8 (uint8_t src) {
  // CHECK-LABEL: test_vmv_v_x_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vmv.v.x.nxv64i8{{.*}}(i8 %{{.*}})
  return vmv_v_x_u8m8(src);
}

vuint16mf4_t test_vmv_v_v_u16mf4 (vuint16mf4_t src) {
  // CHECK-LABEL: test_vmv_v_v_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vmv.v.v.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}})
  return vmv_v_v_u16mf4(src);
}

vuint16mf4_t test_vmv_v_x_u16mf4 (uint16_t src) {
  // CHECK-LABEL: test_vmv_v_x_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vmv.v.x.nxv1i16{{.*}}(i16 %{{.*}})
  return vmv_v_x_u16mf4(src);
}

vuint16mf2_t test_vmv_v_v_u16mf2 (vuint16mf2_t src) {
  // CHECK-LABEL: test_vmv_v_v_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vmv.v.v.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}})
  return vmv_v_v_u16mf2(src);
}

vuint16mf2_t test_vmv_v_x_u16mf2 (uint16_t src) {
  // CHECK-LABEL: test_vmv_v_x_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vmv.v.x.nxv2i16{{.*}}(i16 %{{.*}})
  return vmv_v_x_u16mf2(src);
}

vuint16m1_t test_vmv_v_v_u16m1 (vuint16m1_t src) {
  // CHECK-LABEL: test_vmv_v_v_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vmv.v.v.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vmv_v_v_u16m1(src);
}

vuint16m1_t test_vmv_v_x_u16m1 (uint16_t src) {
  // CHECK-LABEL: test_vmv_v_x_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vmv.v.x.nxv4i16{{.*}}(i16 %{{.*}})
  return vmv_v_x_u16m1(src);
}

vuint16m2_t test_vmv_v_v_u16m2 (vuint16m2_t src) {
  // CHECK-LABEL: test_vmv_v_v_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vmv.v.v.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vmv_v_v_u16m2(src);
}

vuint16m2_t test_vmv_v_x_u16m2 (uint16_t src) {
  // CHECK-LABEL: test_vmv_v_x_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vmv.v.x.nxv8i16{{.*}}(i16 %{{.*}})
  return vmv_v_x_u16m2(src);
}

vuint16m4_t test_vmv_v_v_u16m4 (vuint16m4_t src) {
  // CHECK-LABEL: test_vmv_v_v_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vmv.v.v.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vmv_v_v_u16m4(src);
}

vuint16m4_t test_vmv_v_x_u16m4 (uint16_t src) {
  // CHECK-LABEL: test_vmv_v_x_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vmv.v.x.nxv16i16{{.*}}(i16 %{{.*}})
  return vmv_v_x_u16m4(src);
}

vuint16m8_t test_vmv_v_v_u16m8 (vuint16m8_t src) {
  // CHECK-LABEL: test_vmv_v_v_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vmv.v.v.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vmv_v_v_u16m8(src);
}

vuint16m8_t test_vmv_v_x_u16m8 (uint16_t src) {
  // CHECK-LABEL: test_vmv_v_x_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vmv.v.x.nxv32i16{{.*}}(i16 %{{.*}})
  return vmv_v_x_u16m8(src);
}

vuint32mf2_t test_vmv_v_v_u32mf2 (vuint32mf2_t src) {
  // CHECK-LABEL: test_vmv_v_v_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vmv.v.v.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}})
  return vmv_v_v_u32mf2(src);
}

vuint32mf2_t test_vmv_v_x_u32mf2 (uint32_t src) {
  // CHECK-LABEL: test_vmv_v_x_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vmv.v.x.nxv1i32{{.*}}(i32 %{{.*}})
  return vmv_v_x_u32mf2(src);
}

vuint32m1_t test_vmv_v_v_u32m1 (vuint32m1_t src) {
  // CHECK-LABEL: test_vmv_v_v_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vmv.v.v.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}})
  return vmv_v_v_u32m1(src);
}

vuint32m1_t test_vmv_v_x_u32m1 (uint32_t src) {
  // CHECK-LABEL: test_vmv_v_x_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vmv.v.x.nxv2i32{{.*}}(i32 %{{.*}})
  return vmv_v_x_u32m1(src);
}

vuint32m2_t test_vmv_v_v_u32m2 (vuint32m2_t src) {
  // CHECK-LABEL: test_vmv_v_v_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vmv.v.v.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vmv_v_v_u32m2(src);
}

vuint32m2_t test_vmv_v_x_u32m2 (uint32_t src) {
  // CHECK-LABEL: test_vmv_v_x_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vmv.v.x.nxv4i32{{.*}}(i32 %{{.*}})
  return vmv_v_x_u32m2(src);
}

vuint32m4_t test_vmv_v_v_u32m4 (vuint32m4_t src) {
  // CHECK-LABEL: test_vmv_v_v_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vmv.v.v.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vmv_v_v_u32m4(src);
}

vuint32m4_t test_vmv_v_x_u32m4 (uint32_t src) {
  // CHECK-LABEL: test_vmv_v_x_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vmv.v.x.nxv8i32{{.*}}(i32 %{{.*}})
  return vmv_v_x_u32m4(src);
}

vuint32m8_t test_vmv_v_v_u32m8 (vuint32m8_t src) {
  // CHECK-LABEL: test_vmv_v_v_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vmv.v.v.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vmv_v_v_u32m8(src);
}

vuint32m8_t test_vmv_v_x_u32m8 (uint32_t src) {
  // CHECK-LABEL: test_vmv_v_x_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vmv.v.x.nxv16i32{{.*}}(i32 %{{.*}})
  return vmv_v_x_u32m8(src);
}

vuint64m1_t test_vmv_v_v_u64m1 (vuint64m1_t src) {
  // CHECK-LABEL: test_vmv_v_v_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vmv.v.v.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}})
  return vmv_v_v_u64m1(src);
}

vuint64m1_t test_vmv_v_x_u64m1 (uint64_t src) {
  // CHECK-LABEL: test_vmv_v_x_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vmv.v.x.nxv1i64{{.*}}(i64 %{{.*}})
  return vmv_v_x_u64m1(src);
}

vuint64m2_t test_vmv_v_v_u64m2 (vuint64m2_t src) {
  // CHECK-LABEL: test_vmv_v_v_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vmv.v.v.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}})
  return vmv_v_v_u64m2(src);
}

vuint64m2_t test_vmv_v_x_u64m2 (uint64_t src) {
  // CHECK-LABEL: test_vmv_v_x_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vmv.v.x.nxv2i64{{.*}}(i64 %{{.*}})
  return vmv_v_x_u64m2(src);
}

vuint64m4_t test_vmv_v_v_u64m4 (vuint64m4_t src) {
  // CHECK-LABEL: test_vmv_v_v_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vmv.v.v.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}})
  return vmv_v_v_u64m4(src);
}

vuint64m4_t test_vmv_v_x_u64m4 (uint64_t src) {
  // CHECK-LABEL: test_vmv_v_x_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vmv.v.x.nxv4i64{{.*}}(i64 %{{.*}})
  return vmv_v_x_u64m4(src);
}

vuint64m8_t test_vmv_v_v_u64m8 (vuint64m8_t src) {
  // CHECK-LABEL: test_vmv_v_v_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vmv.v.v.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vmv_v_v_u64m8(src);
}

vuint64m8_t test_vmv_v_x_u64m8 (uint64_t src) {
  // CHECK-LABEL: test_vmv_v_x_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vmv.v.x.nxv8i64{{.*}}(i64 %{{.*}})
  return vmv_v_x_u64m8(src);
}

int8_t test_vmv_x_s_i8mf8_i8 (vint8mf8_t src) {
  // CHECK-LABEL: test_vmv_x_s_i8mf8_i8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}})
  return vmv_x_s_i8mf8_i8(src);
}

vint8mf8_t test_vmv_s_x_i8mf8 (vint8mf8_t dst, int8_t src) {
  // CHECK-LABEL: test_vmv_s_x_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vmv.s.x.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, i8 %{{.*}})
  return vmv_s_x_i8mf8(dst, src);
}

int8_t test_vmv_x_s_i8mf4_i8 (vint8mf4_t src) {
  // CHECK-LABEL: test_vmv_x_s_i8mf4_i8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}})
  return vmv_x_s_i8mf4_i8(src);
}

vint8mf4_t test_vmv_s_x_i8mf4 (vint8mf4_t dst, int8_t src) {
  // CHECK-LABEL: test_vmv_s_x_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vmv.s.x.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, i8 %{{.*}})
  return vmv_s_x_i8mf4(dst, src);
}

int8_t test_vmv_x_s_i8mf2_i8 (vint8mf2_t src) {
  // CHECK-LABEL: test_vmv_x_s_i8mf2_i8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}})
  return vmv_x_s_i8mf2_i8(src);
}

vint8mf2_t test_vmv_s_x_i8mf2 (vint8mf2_t dst, int8_t src) {
  // CHECK-LABEL: test_vmv_s_x_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vmv.s.x.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, i8 %{{.*}})
  return vmv_s_x_i8mf2(dst, src);
}

int8_t test_vmv_x_s_i8m1_i8 (vint8m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_i8m1_i8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vmv_x_s_i8m1_i8(src);
}

vint8m1_t test_vmv_s_x_i8m1 (vint8m1_t dst, int8_t src) {
  // CHECK-LABEL: test_vmv_s_x_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vmv.s.x.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vmv_s_x_i8m1(dst, src);
}

int8_t test_vmv_x_s_i8m2_i8 (vint8m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_i8m2_i8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vmv_x_s_i8m2_i8(src);
}

vint8m2_t test_vmv_s_x_i8m2 (vint8m2_t dst, int8_t src) {
  // CHECK-LABEL: test_vmv_s_x_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vmv.s.x.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vmv_s_x_i8m2(dst, src);
}

int8_t test_vmv_x_s_i8m4_i8 (vint8m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_i8m4_i8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vmv_x_s_i8m4_i8(src);
}

vint8m4_t test_vmv_s_x_i8m4 (vint8m4_t dst, int8_t src) {
  // CHECK-LABEL: test_vmv_s_x_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vmv.s.x.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vmv_s_x_i8m4(dst, src);
}

int8_t test_vmv_x_s_i8m8_i8 (vint8m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_i8m8_i8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}})
  return vmv_x_s_i8m8_i8(src);
}

vint8m8_t test_vmv_s_x_i8m8 (vint8m8_t dst, int8_t src) {
  // CHECK-LABEL: test_vmv_s_x_i8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vmv.s.x.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i8 %{{.*}})
  return vmv_s_x_i8m8(dst, src);
}

int16_t test_vmv_x_s_i16mf4_i16 (vint16mf4_t src) {
  // CHECK-LABEL: test_vmv_x_s_i16mf4_i16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}})
  return vmv_x_s_i16mf4_i16(src);
}

vint16mf4_t test_vmv_s_x_i16mf4 (vint16mf4_t dst, int16_t src) {
  // CHECK-LABEL: test_vmv_s_x_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vmv.s.x.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, i16 %{{.*}})
  return vmv_s_x_i16mf4(dst, src);
}

int16_t test_vmv_x_s_i16mf2_i16 (vint16mf2_t src) {
  // CHECK-LABEL: test_vmv_x_s_i16mf2_i16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}})
  return vmv_x_s_i16mf2_i16(src);
}

vint16mf2_t test_vmv_s_x_i16mf2 (vint16mf2_t dst, int16_t src) {
  // CHECK-LABEL: test_vmv_s_x_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vmv.s.x.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, i16 %{{.*}})
  return vmv_s_x_i16mf2(dst, src);
}

int16_t test_vmv_x_s_i16m1_i16 (vint16m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_i16m1_i16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vmv_x_s_i16m1_i16(src);
}

vint16m1_t test_vmv_s_x_i16m1 (vint16m1_t dst, int16_t src) {
  // CHECK-LABEL: test_vmv_s_x_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vmv.s.x.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vmv_s_x_i16m1(dst, src);
}

int16_t test_vmv_x_s_i16m2_i16 (vint16m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_i16m2_i16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vmv_x_s_i16m2_i16(src);
}

vint16m2_t test_vmv_s_x_i16m2 (vint16m2_t dst, int16_t src) {
  // CHECK-LABEL: test_vmv_s_x_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vmv.s.x.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vmv_s_x_i16m2(dst, src);
}

int16_t test_vmv_x_s_i16m4_i16 (vint16m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_i16m4_i16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vmv_x_s_i16m4_i16(src);
}

vint16m4_t test_vmv_s_x_i16m4 (vint16m4_t dst, int16_t src) {
  // CHECK-LABEL: test_vmv_s_x_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vmv.s.x.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vmv_s_x_i16m4(dst, src);
}

int16_t test_vmv_x_s_i16m8_i16 (vint16m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_i16m8_i16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vmv_x_s_i16m8_i16(src);
}

vint16m8_t test_vmv_s_x_i16m8 (vint16m8_t dst, int16_t src) {
  // CHECK-LABEL: test_vmv_s_x_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vmv.s.x.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vmv_s_x_i16m8(dst, src);
}

int32_t test_vmv_x_s_i32mf2_i32 (vint32mf2_t src) {
  // CHECK-LABEL: test_vmv_x_s_i32mf2_i32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}})
  return vmv_x_s_i32mf2_i32(src);
}

vint32mf2_t test_vmv_s_x_i32mf2 (vint32mf2_t dst, int32_t src) {
  // CHECK-LABEL: test_vmv_s_x_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vmv.s.x.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i32 %{{.*}})
  return vmv_s_x_i32mf2(dst, src);
}

int32_t test_vmv_x_s_i32m1_i32 (vint32m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_i32m1_i32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}})
  return vmv_x_s_i32m1_i32(src);
}

vint32m1_t test_vmv_s_x_i32m1 (vint32m1_t dst, int32_t src) {
  // CHECK-LABEL: test_vmv_s_x_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vmv.s.x.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i32 %{{.*}})
  return vmv_s_x_i32m1(dst, src);
}

int32_t test_vmv_x_s_i32m2_i32 (vint32m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_i32m2_i32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vmv_x_s_i32m2_i32(src);
}

vint32m2_t test_vmv_s_x_i32m2 (vint32m2_t dst, int32_t src) {
  // CHECK-LABEL: test_vmv_s_x_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vmv.s.x.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i32 %{{.*}})
  return vmv_s_x_i32m2(dst, src);
}

int32_t test_vmv_x_s_i32m4_i32 (vint32m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_i32m4_i32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vmv_x_s_i32m4_i32(src);
}

vint32m4_t test_vmv_s_x_i32m4 (vint32m4_t dst, int32_t src) {
  // CHECK-LABEL: test_vmv_s_x_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vmv.s.x.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i32 %{{.*}})
  return vmv_s_x_i32m4(dst, src);
}

int32_t test_vmv_x_s_i32m8_i32 (vint32m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_i32m8_i32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vmv_x_s_i32m8_i32(src);
}

vint32m8_t test_vmv_s_x_i32m8 (vint32m8_t dst, int32_t src) {
  // CHECK-LABEL: test_vmv_s_x_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vmv.s.x.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i32 %{{.*}})
  return vmv_s_x_i32m8(dst, src);
}

int64_t test_vmv_x_s_i64m1_i64 (vint64m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_i64m1_i64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}})
  return vmv_x_s_i64m1_i64(src);
}

vint64m1_t test_vmv_s_x_i64m1 (vint64m1_t dst, int64_t src) {
  // CHECK-LABEL: test_vmv_s_x_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vmv.s.x.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vmv_s_x_i64m1(dst, src);
}

int64_t test_vmv_x_s_i64m2_i64 (vint64m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_i64m2_i64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}})
  return vmv_x_s_i64m2_i64(src);
}

vint64m2_t test_vmv_s_x_i64m2 (vint64m2_t dst, int64_t src) {
  // CHECK-LABEL: test_vmv_s_x_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vmv.s.x.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vmv_s_x_i64m2(dst, src);
}

int64_t test_vmv_x_s_i64m4_i64 (vint64m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_i64m4_i64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}})
  return vmv_x_s_i64m4_i64(src);
}

vint64m4_t test_vmv_s_x_i64m4 (vint64m4_t dst, int64_t src) {
  // CHECK-LABEL: test_vmv_s_x_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vmv.s.x.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vmv_s_x_i64m4(dst, src);
}

int64_t test_vmv_x_s_i64m8_i64 (vint64m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_i64m8_i64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vmv_x_s_i64m8_i64(src);
}

vint64m8_t test_vmv_s_x_i64m8 (vint64m8_t dst, int64_t src) {
  // CHECK-LABEL: test_vmv_s_x_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vmv.s.x.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vmv_s_x_i64m8(dst, src);
}

uint8_t test_vmv_x_s_u8mf8_u8 (vuint8mf8_t src) {
  // CHECK-LABEL: test_vmv_x_s_u8mf8_u8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}})
  return vmv_x_s_u8mf8_u8(src);
}

vuint8mf8_t test_vmv_s_x_u8mf8 (vuint8mf8_t dst, uint8_t src) {
  // CHECK-LABEL: test_vmv_s_x_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vmv.s.x.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, i8 %{{.*}})
  return vmv_s_x_u8mf8(dst, src);
}

uint8_t test_vmv_x_s_u8mf4_u8 (vuint8mf4_t src) {
  // CHECK-LABEL: test_vmv_x_s_u8mf4_u8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}})
  return vmv_x_s_u8mf4_u8(src);
}

vuint8mf4_t test_vmv_s_x_u8mf4 (vuint8mf4_t dst, uint8_t src) {
  // CHECK-LABEL: test_vmv_s_x_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vmv.s.x.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, i8 %{{.*}})
  return vmv_s_x_u8mf4(dst, src);
}

uint8_t test_vmv_x_s_u8mf2_u8 (vuint8mf2_t src) {
  // CHECK-LABEL: test_vmv_x_s_u8mf2_u8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}})
  return vmv_x_s_u8mf2_u8(src);
}

vuint8mf2_t test_vmv_s_x_u8mf2 (vuint8mf2_t dst, uint8_t src) {
  // CHECK-LABEL: test_vmv_s_x_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vmv.s.x.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, i8 %{{.*}})
  return vmv_s_x_u8mf2(dst, src);
}

uint8_t test_vmv_x_s_u8m1_u8 (vuint8m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_u8m1_u8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vmv_x_s_u8m1_u8(src);
}

vuint8m1_t test_vmv_s_x_u8m1 (vuint8m1_t dst, uint8_t src) {
  // CHECK-LABEL: test_vmv_s_x_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vmv.s.x.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vmv_s_x_u8m1(dst, src);
}

uint8_t test_vmv_x_s_u8m2_u8 (vuint8m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_u8m2_u8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vmv_x_s_u8m2_u8(src);
}

vuint8m2_t test_vmv_s_x_u8m2 (vuint8m2_t dst, uint8_t src) {
  // CHECK-LABEL: test_vmv_s_x_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vmv.s.x.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vmv_s_x_u8m2(dst, src);
}

uint8_t test_vmv_x_s_u8m4_u8 (vuint8m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_u8m4_u8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vmv_x_s_u8m4_u8(src);
}

vuint8m4_t test_vmv_s_x_u8m4 (vuint8m4_t dst, uint8_t src) {
  // CHECK-LABEL: test_vmv_s_x_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vmv.s.x.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vmv_s_x_u8m4(dst, src);
}

uint8_t test_vmv_x_s_u8m8_u8 (vuint8m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_u8m8_u8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}})
  return vmv_x_s_u8m8_u8(src);
}

vuint8m8_t test_vmv_s_x_u8m8 (vuint8m8_t dst, uint8_t src) {
  // CHECK-LABEL: test_vmv_s_x_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vmv.s.x.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i8 %{{.*}})
  return vmv_s_x_u8m8(dst, src);
}

uint16_t test_vmv_x_s_u16mf4_u16 (vuint16mf4_t src) {
  // CHECK-LABEL: test_vmv_x_s_u16mf4_u16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}})
  return vmv_x_s_u16mf4_u16(src);
}

vuint16mf4_t test_vmv_s_x_u16mf4 (vuint16mf4_t dst, uint16_t src) {
  // CHECK-LABEL: test_vmv_s_x_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vmv.s.x.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, i16 %{{.*}})
  return vmv_s_x_u16mf4(dst, src);
}

uint16_t test_vmv_x_s_u16mf2_u16 (vuint16mf2_t src) {
  // CHECK-LABEL: test_vmv_x_s_u16mf2_u16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}})
  return vmv_x_s_u16mf2_u16(src);
}

vuint16mf2_t test_vmv_s_x_u16mf2 (vuint16mf2_t dst, uint16_t src) {
  // CHECK-LABEL: test_vmv_s_x_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vmv.s.x.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, i16 %{{.*}})
  return vmv_s_x_u16mf2(dst, src);
}

uint16_t test_vmv_x_s_u16m1_u16 (vuint16m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_u16m1_u16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vmv_x_s_u16m1_u16(src);
}

vuint16m1_t test_vmv_s_x_u16m1 (vuint16m1_t dst, uint16_t src) {
  // CHECK-LABEL: test_vmv_s_x_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vmv.s.x.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vmv_s_x_u16m1(dst, src);
}

uint16_t test_vmv_x_s_u16m2_u16 (vuint16m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_u16m2_u16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vmv_x_s_u16m2_u16(src);
}

vuint16m2_t test_vmv_s_x_u16m2 (vuint16m2_t dst, uint16_t src) {
  // CHECK-LABEL: test_vmv_s_x_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vmv.s.x.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vmv_s_x_u16m2(dst, src);
}

uint16_t test_vmv_x_s_u16m4_u16 (vuint16m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_u16m4_u16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vmv_x_s_u16m4_u16(src);
}

vuint16m4_t test_vmv_s_x_u16m4 (vuint16m4_t dst, uint16_t src) {
  // CHECK-LABEL: test_vmv_s_x_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vmv.s.x.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vmv_s_x_u16m4(dst, src);
}

uint16_t test_vmv_x_s_u16m8_u16 (vuint16m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_u16m8_u16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vmv_x_s_u16m8_u16(src);
}

vuint16m8_t test_vmv_s_x_u16m8 (vuint16m8_t dst, uint16_t src) {
  // CHECK-LABEL: test_vmv_s_x_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vmv.s.x.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vmv_s_x_u16m8(dst, src);
}

uint32_t test_vmv_x_s_u32mf2_u32 (vuint32mf2_t src) {
  // CHECK-LABEL: test_vmv_x_s_u32mf2_u32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}})
  return vmv_x_s_u32mf2_u32(src);
}

vuint32mf2_t test_vmv_s_x_u32mf2 (vuint32mf2_t dst, uint32_t src) {
  // CHECK-LABEL: test_vmv_s_x_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vmv.s.x.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i32 %{{.*}})
  return vmv_s_x_u32mf2(dst, src);
}

uint32_t test_vmv_x_s_u32m1_u32 (vuint32m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_u32m1_u32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}})
  return vmv_x_s_u32m1_u32(src);
}

vuint32m1_t test_vmv_s_x_u32m1 (vuint32m1_t dst, uint32_t src) {
  // CHECK-LABEL: test_vmv_s_x_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vmv.s.x.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i32 %{{.*}})
  return vmv_s_x_u32m1(dst, src);
}

uint32_t test_vmv_x_s_u32m2_u32 (vuint32m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_u32m2_u32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vmv_x_s_u32m2_u32(src);
}

vuint32m2_t test_vmv_s_x_u32m2 (vuint32m2_t dst, uint32_t src) {
  // CHECK-LABEL: test_vmv_s_x_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vmv.s.x.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i32 %{{.*}})
  return vmv_s_x_u32m2(dst, src);
}

uint32_t test_vmv_x_s_u32m4_u32 (vuint32m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_u32m4_u32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vmv_x_s_u32m4_u32(src);
}

vuint32m4_t test_vmv_s_x_u32m4 (vuint32m4_t dst, uint32_t src) {
  // CHECK-LABEL: test_vmv_s_x_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vmv.s.x.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i32 %{{.*}})
  return vmv_s_x_u32m4(dst, src);
}

uint32_t test_vmv_x_s_u32m8_u32 (vuint32m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_u32m8_u32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vmv_x_s_u32m8_u32(src);
}

vuint32m8_t test_vmv_s_x_u32m8 (vuint32m8_t dst, uint32_t src) {
  // CHECK-LABEL: test_vmv_s_x_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vmv.s.x.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i32 %{{.*}})
  return vmv_s_x_u32m8(dst, src);
}

uint64_t test_vmv_x_s_u64m1_u64 (vuint64m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_u64m1_u64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}})
  return vmv_x_s_u64m1_u64(src);
}

vuint64m1_t test_vmv_s_x_u64m1 (vuint64m1_t dst, uint64_t src) {
  // CHECK-LABEL: test_vmv_s_x_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vmv.s.x.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vmv_s_x_u64m1(dst, src);
}

uint64_t test_vmv_x_s_u64m2_u64 (vuint64m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_u64m2_u64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}})
  return vmv_x_s_u64m2_u64(src);
}

vuint64m2_t test_vmv_s_x_u64m2 (vuint64m2_t dst, uint64_t src) {
  // CHECK-LABEL: test_vmv_s_x_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vmv.s.x.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vmv_s_x_u64m2(dst, src);
}

uint64_t test_vmv_x_s_u64m4_u64 (vuint64m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_u64m4_u64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}})
  return vmv_x_s_u64m4_u64(src);
}

vuint64m4_t test_vmv_s_x_u64m4 (vuint64m4_t dst, uint64_t src) {
  // CHECK-LABEL: test_vmv_s_x_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vmv.s.x.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vmv_s_x_u64m4(dst, src);
}

uint64_t test_vmv_x_s_u64m8_u64 (vuint64m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_u64m8_u64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vmv_x_s_u64m8_u64(src);
}

vuint64m8_t test_vmv_s_x_u64m8 (vuint64m8_t dst, uint64_t src) {
  // CHECK-LABEL: test_vmv_s_x_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vmv.s.x.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vmv_s_x_u64m8(dst, src);
}

