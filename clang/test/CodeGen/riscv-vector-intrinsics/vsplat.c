// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8_t test_vsplat_s_i8mf8 (int8_t src) {
  // CHECK-LABEL: test_vsplat_s_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vsplat.s.nxv1i8{{.*}}(i8 %{{.*}})
  return vsplat_s_i8mf8(src);
}

vint8mf4_t test_vsplat_s_i8mf4 (int8_t src) {
  // CHECK-LABEL: test_vsplat_s_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vsplat.s.nxv2i8{{.*}}(i8 %{{.*}})
  return vsplat_s_i8mf4(src);
}

vint8mf2_t test_vsplat_s_i8mf2 (int8_t src) {
  // CHECK-LABEL: test_vsplat_s_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vsplat.s.nxv4i8{{.*}}(i8 %{{.*}})
  return vsplat_s_i8mf2(src);
}

vint8m1_t test_vsplat_s_i8m1 (int8_t src) {
  // CHECK-LABEL: test_vsplat_s_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vsplat.s.nxv8i8{{.*}}(i8 %{{.*}})
  return vsplat_s_i8m1(src);
}

vint8m2_t test_vsplat_s_i8m2 (int8_t src) {
  // CHECK-LABEL: test_vsplat_s_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vsplat.s.nxv16i8{{.*}}(i8 %{{.*}})
  return vsplat_s_i8m2(src);
}

vint8m4_t test_vsplat_s_i8m4 (int8_t src) {
  // CHECK-LABEL: test_vsplat_s_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vsplat.s.nxv32i8{{.*}}(i8 %{{.*}})
  return vsplat_s_i8m4(src);
}

vint8m8_t test_vsplat_s_i8m8 (int8_t src) {
  // CHECK-LABEL: test_vsplat_s_i8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vsplat.s.nxv64i8{{.*}}(i8 %{{.*}})
  return vsplat_s_i8m8(src);
}

vint16mf4_t test_vsplat_s_i16mf4 (int16_t src) {
  // CHECK-LABEL: test_vsplat_s_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vsplat.s.nxv1i16{{.*}}(i16 %{{.*}})
  return vsplat_s_i16mf4(src);
}

vint16mf2_t test_vsplat_s_i16mf2 (int16_t src) {
  // CHECK-LABEL: test_vsplat_s_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vsplat.s.nxv2i16{{.*}}(i16 %{{.*}})
  return vsplat_s_i16mf2(src);
}

vint16m1_t test_vsplat_s_i16m1 (int16_t src) {
  // CHECK-LABEL: test_vsplat_s_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vsplat.s.nxv4i16{{.*}}(i16 %{{.*}})
  return vsplat_s_i16m1(src);
}

vint16m2_t test_vsplat_s_i16m2 (int16_t src) {
  // CHECK-LABEL: test_vsplat_s_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vsplat.s.nxv8i16{{.*}}(i16 %{{.*}})
  return vsplat_s_i16m2(src);
}

vint16m4_t test_vsplat_s_i16m4 (int16_t src) {
  // CHECK-LABEL: test_vsplat_s_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vsplat.s.nxv16i16{{.*}}(i16 %{{.*}})
  return vsplat_s_i16m4(src);
}

vint16m8_t test_vsplat_s_i16m8 (int16_t src) {
  // CHECK-LABEL: test_vsplat_s_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vsplat.s.nxv32i16{{.*}}(i16 %{{.*}})
  return vsplat_s_i16m8(src);
}

vint32mf2_t test_vsplat_s_i32mf2 (int32_t src) {
  // CHECK-LABEL: test_vsplat_s_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vsplat.s.nxv1i32{{.*}}(i32 %{{.*}})
  return vsplat_s_i32mf2(src);
}

vint32m1_t test_vsplat_s_i32m1 (int32_t src) {
  // CHECK-LABEL: test_vsplat_s_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vsplat.s.nxv2i32{{.*}}(i32 %{{.*}})
  return vsplat_s_i32m1(src);
}

vint32m2_t test_vsplat_s_i32m2 (int32_t src) {
  // CHECK-LABEL: test_vsplat_s_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vsplat.s.nxv4i32{{.*}}(i32 %{{.*}})
  return vsplat_s_i32m2(src);
}

vint32m4_t test_vsplat_s_i32m4 (int32_t src) {
  // CHECK-LABEL: test_vsplat_s_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vsplat.s.nxv8i32{{.*}}(i32 %{{.*}})
  return vsplat_s_i32m4(src);
}

vint32m8_t test_vsplat_s_i32m8 (int32_t src) {
  // CHECK-LABEL: test_vsplat_s_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vsplat.s.nxv16i32{{.*}}(i32 %{{.*}})
  return vsplat_s_i32m8(src);
}

vint64m1_t test_vsplat_s_i64m1 (int64_t src) {
  // CHECK-LABEL: test_vsplat_s_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vsplat.s.nxv1i64{{.*}}(i64 %{{.*}})
  return vsplat_s_i64m1(src);
}

vint64m2_t test_vsplat_s_i64m2 (int64_t src) {
  // CHECK-LABEL: test_vsplat_s_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vsplat.s.nxv2i64{{.*}}(i64 %{{.*}})
  return vsplat_s_i64m2(src);
}

vint64m4_t test_vsplat_s_i64m4 (int64_t src) {
  // CHECK-LABEL: test_vsplat_s_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vsplat.s.nxv4i64{{.*}}(i64 %{{.*}})
  return vsplat_s_i64m4(src);
}

vint64m8_t test_vsplat_s_i64m8 (int64_t src) {
  // CHECK-LABEL: test_vsplat_s_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vsplat.s.nxv8i64{{.*}}(i64 %{{.*}})
  return vsplat_s_i64m8(src);
}

vuint8mf8_t test_vsplat_s_u8mf8 (uint8_t src) {
  // CHECK-LABEL: test_vsplat_s_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vsplat.s.nxv1i8{{.*}}(i8 %{{.*}})
  return vsplat_s_u8mf8(src);
}

vuint8mf4_t test_vsplat_s_u8mf4 (uint8_t src) {
  // CHECK-LABEL: test_vsplat_s_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vsplat.s.nxv2i8{{.*}}(i8 %{{.*}})
  return vsplat_s_u8mf4(src);
}

vuint8mf2_t test_vsplat_s_u8mf2 (uint8_t src) {
  // CHECK-LABEL: test_vsplat_s_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vsplat.s.nxv4i8{{.*}}(i8 %{{.*}})
  return vsplat_s_u8mf2(src);
}

vuint8m1_t test_vsplat_s_u8m1 (uint8_t src) {
  // CHECK-LABEL: test_vsplat_s_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vsplat.s.nxv8i8{{.*}}(i8 %{{.*}})
  return vsplat_s_u8m1(src);
}

vuint8m2_t test_vsplat_s_u8m2 (uint8_t src) {
  // CHECK-LABEL: test_vsplat_s_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vsplat.s.nxv16i8{{.*}}(i8 %{{.*}})
  return vsplat_s_u8m2(src);
}

vuint8m4_t test_vsplat_s_u8m4 (uint8_t src) {
  // CHECK-LABEL: test_vsplat_s_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vsplat.s.nxv32i8{{.*}}(i8 %{{.*}})
  return vsplat_s_u8m4(src);
}

vuint8m8_t test_vsplat_s_u8m8 (uint8_t src) {
  // CHECK-LABEL: test_vsplat_s_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vsplat.s.nxv64i8{{.*}}(i8 %{{.*}})
  return vsplat_s_u8m8(src);
}

vuint16mf4_t test_vsplat_s_u16mf4 (uint16_t src) {
  // CHECK-LABEL: test_vsplat_s_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vsplat.s.nxv1i16{{.*}}(i16 %{{.*}})
  return vsplat_s_u16mf4(src);
}

vuint16mf2_t test_vsplat_s_u16mf2 (uint16_t src) {
  // CHECK-LABEL: test_vsplat_s_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vsplat.s.nxv2i16{{.*}}(i16 %{{.*}})
  return vsplat_s_u16mf2(src);
}

vuint16m1_t test_vsplat_s_u16m1 (uint16_t src) {
  // CHECK-LABEL: test_vsplat_s_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vsplat.s.nxv4i16{{.*}}(i16 %{{.*}})
  return vsplat_s_u16m1(src);
}

vuint16m2_t test_vsplat_s_u16m2 (uint16_t src) {
  // CHECK-LABEL: test_vsplat_s_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vsplat.s.nxv8i16{{.*}}(i16 %{{.*}})
  return vsplat_s_u16m2(src);
}

vuint16m4_t test_vsplat_s_u16m4 (uint16_t src) {
  // CHECK-LABEL: test_vsplat_s_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vsplat.s.nxv16i16{{.*}}(i16 %{{.*}})
  return vsplat_s_u16m4(src);
}

vuint16m8_t test_vsplat_s_u16m8 (uint16_t src) {
  // CHECK-LABEL: test_vsplat_s_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vsplat.s.nxv32i16{{.*}}(i16 %{{.*}})
  return vsplat_s_u16m8(src);
}

vuint32mf2_t test_vsplat_s_u32mf2 (uint32_t src) {
  // CHECK-LABEL: test_vsplat_s_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vsplat.s.nxv1i32{{.*}}(i32 %{{.*}})
  return vsplat_s_u32mf2(src);
}

vuint32m1_t test_vsplat_s_u32m1 (uint32_t src) {
  // CHECK-LABEL: test_vsplat_s_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vsplat.s.nxv2i32{{.*}}(i32 %{{.*}})
  return vsplat_s_u32m1(src);
}

vuint32m2_t test_vsplat_s_u32m2 (uint32_t src) {
  // CHECK-LABEL: test_vsplat_s_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vsplat.s.nxv4i32{{.*}}(i32 %{{.*}})
  return vsplat_s_u32m2(src);
}

vuint32m4_t test_vsplat_s_u32m4 (uint32_t src) {
  // CHECK-LABEL: test_vsplat_s_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vsplat.s.nxv8i32{{.*}}(i32 %{{.*}})
  return vsplat_s_u32m4(src);
}

vuint32m8_t test_vsplat_s_u32m8 (uint32_t src) {
  // CHECK-LABEL: test_vsplat_s_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vsplat.s.nxv16i32{{.*}}(i32 %{{.*}})
  return vsplat_s_u32m8(src);
}

vuint64m1_t test_vsplat_s_u64m1 (uint64_t src) {
  // CHECK-LABEL: test_vsplat_s_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vsplat.s.nxv1i64{{.*}}(i64 %{{.*}})
  return vsplat_s_u64m1(src);
}

vuint64m2_t test_vsplat_s_u64m2 (uint64_t src) {
  // CHECK-LABEL: test_vsplat_s_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vsplat.s.nxv2i64{{.*}}(i64 %{{.*}})
  return vsplat_s_u64m2(src);
}

vuint64m4_t test_vsplat_s_u64m4 (uint64_t src) {
  // CHECK-LABEL: test_vsplat_s_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vsplat.s.nxv4i64{{.*}}(i64 %{{.*}})
  return vsplat_s_u64m4(src);
}

vuint64m8_t test_vsplat_s_u64m8 (uint64_t src) {
  // CHECK-LABEL: test_vsplat_s_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vsplat.s.nxv8i64{{.*}}(i64 %{{.*}})
  return vsplat_s_u64m8(src);
}

