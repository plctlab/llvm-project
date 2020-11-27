// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

int8_t test_vmv_x_s_i8mf8_i8 (vint8mf8_t src) {
  // CHECK-LABEL: test_vmv_x_s_i8mf8_i8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.{{.*}}nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}})
  return vmv_x_s_i8mf8_i8(src);
}

int8_t test_vmv_x_s_i8mf4_i8 (vint8mf4_t src) {
  // CHECK-LABEL: test_vmv_x_s_i8mf4_i8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.{{.*}}nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}})
  return vmv_x_s_i8mf4_i8(src);
}

int8_t test_vmv_x_s_i8mf2_i8 (vint8mf2_t src) {
  // CHECK-LABEL: test_vmv_x_s_i8mf2_i8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.{{.*}}nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}})
  return vmv_x_s_i8mf2_i8(src);
}

int8_t test_vmv_x_s_i8m1_i8 (vint8m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_i8m1_i8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.{{.*}}nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vmv_x_s_i8m1_i8(src);
}

int8_t test_vmv_x_s_i8m2_i8 (vint8m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_i8m2_i8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.{{.*}}nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vmv_x_s_i8m2_i8(src);
}

int8_t test_vmv_x_s_i8m4_i8 (vint8m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_i8m4_i8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.{{.*}}nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vmv_x_s_i8m4_i8(src);
}

int8_t test_vmv_x_s_i8m8_i8 (vint8m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_i8m8_i8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.{{.*}}nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}})
  return vmv_x_s_i8m8_i8(src);
}

int16_t test_vmv_x_s_i16mf4_i16 (vint16mf4_t src) {
  // CHECK-LABEL: test_vmv_x_s_i16mf4_i16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.{{.*}}nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}})
  return vmv_x_s_i16mf4_i16(src);
}

int16_t test_vmv_x_s_i16mf2_i16 (vint16mf2_t src) {
  // CHECK-LABEL: test_vmv_x_s_i16mf2_i16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.{{.*}}nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}})
  return vmv_x_s_i16mf2_i16(src);
}

int16_t test_vmv_x_s_i16m1_i16 (vint16m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_i16m1_i16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.{{.*}}nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vmv_x_s_i16m1_i16(src);
}

int16_t test_vmv_x_s_i16m2_i16 (vint16m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_i16m2_i16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.{{.*}}nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vmv_x_s_i16m2_i16(src);
}

int16_t test_vmv_x_s_i16m4_i16 (vint16m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_i16m4_i16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.{{.*}}nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vmv_x_s_i16m4_i16(src);
}

int16_t test_vmv_x_s_i16m8_i16 (vint16m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_i16m8_i16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.{{.*}}nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vmv_x_s_i16m8_i16(src);
}

int32_t test_vmv_x_s_i32mf2_i32 (vint32mf2_t src) {
  // CHECK-LABEL: test_vmv_x_s_i32mf2_i32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.{{.*}}nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}})
  return vmv_x_s_i32mf2_i32(src);
}

int32_t test_vmv_x_s_i32m1_i32 (vint32m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_i32m1_i32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.{{.*}}nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}})
  return vmv_x_s_i32m1_i32(src);
}

int32_t test_vmv_x_s_i32m2_i32 (vint32m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_i32m2_i32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.{{.*}}nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vmv_x_s_i32m2_i32(src);
}

int32_t test_vmv_x_s_i32m4_i32 (vint32m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_i32m4_i32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.{{.*}}nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vmv_x_s_i32m4_i32(src);
}

int32_t test_vmv_x_s_i32m8_i32 (vint32m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_i32m8_i32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.{{.*}}nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vmv_x_s_i32m8_i32(src);
}

int64_t test_vmv_x_s_i64m1_i64 (vint64m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_i64m1_i64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.{{.*}}nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}})
  return vmv_x_s_i64m1_i64(src);
}

int64_t test_vmv_x_s_i64m2_i64 (vint64m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_i64m2_i64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.{{.*}}nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}})
  return vmv_x_s_i64m2_i64(src);
}

int64_t test_vmv_x_s_i64m4_i64 (vint64m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_i64m4_i64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.{{.*}}nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}})
  return vmv_x_s_i64m4_i64(src);
}

int64_t test_vmv_x_s_i64m8_i64 (vint64m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_i64m8_i64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.{{.*}}nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vmv_x_s_i64m8_i64(src);
}

uint8_t test_vmv_x_s_u8mf8_u8 (vuint8mf8_t src) {
  // CHECK-LABEL: test_vmv_x_s_u8mf8_u8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.{{.*}}nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}})
  return vmv_x_s_u8mf8_u8(src);
}

uint8_t test_vmv_x_s_u8mf4_u8 (vuint8mf4_t src) {
  // CHECK-LABEL: test_vmv_x_s_u8mf4_u8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.{{.*}}nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}})
  return vmv_x_s_u8mf4_u8(src);
}

uint8_t test_vmv_x_s_u8mf2_u8 (vuint8mf2_t src) {
  // CHECK-LABEL: test_vmv_x_s_u8mf2_u8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.{{.*}}nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}})
  return vmv_x_s_u8mf2_u8(src);
}

uint8_t test_vmv_x_s_u8m1_u8 (vuint8m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_u8m1_u8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.{{.*}}nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}})
  return vmv_x_s_u8m1_u8(src);
}

uint8_t test_vmv_x_s_u8m2_u8 (vuint8m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_u8m2_u8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.{{.*}}nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}})
  return vmv_x_s_u8m2_u8(src);
}

uint8_t test_vmv_x_s_u8m4_u8 (vuint8m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_u8m4_u8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.{{.*}}nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}})
  return vmv_x_s_u8m4_u8(src);
}

uint8_t test_vmv_x_s_u8m8_u8 (vuint8m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_u8m8_u8
  // CHECK: %{{.*}} = call i8 @llvm.riscv.vmv.x.s.{{.*}}nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}})
  return vmv_x_s_u8m8_u8(src);
}

uint16_t test_vmv_x_s_u16mf4_u16 (vuint16mf4_t src) {
  // CHECK-LABEL: test_vmv_x_s_u16mf4_u16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.{{.*}}nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}})
  return vmv_x_s_u16mf4_u16(src);
}

uint16_t test_vmv_x_s_u16mf2_u16 (vuint16mf2_t src) {
  // CHECK-LABEL: test_vmv_x_s_u16mf2_u16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.{{.*}}nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}})
  return vmv_x_s_u16mf2_u16(src);
}

uint16_t test_vmv_x_s_u16m1_u16 (vuint16m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_u16m1_u16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.{{.*}}nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}})
  return vmv_x_s_u16m1_u16(src);
}

uint16_t test_vmv_x_s_u16m2_u16 (vuint16m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_u16m2_u16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.{{.*}}nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}})
  return vmv_x_s_u16m2_u16(src);
}

uint16_t test_vmv_x_s_u16m4_u16 (vuint16m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_u16m4_u16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.{{.*}}nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}})
  return vmv_x_s_u16m4_u16(src);
}

uint16_t test_vmv_x_s_u16m8_u16 (vuint16m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_u16m8_u16
  // CHECK: %{{.*}} = call i16 @llvm.riscv.vmv.x.s.{{.*}}nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}})
  return vmv_x_s_u16m8_u16(src);
}

uint32_t test_vmv_x_s_u32mf2_u32 (vuint32mf2_t src) {
  // CHECK-LABEL: test_vmv_x_s_u32mf2_u32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.{{.*}}nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}})
  return vmv_x_s_u32mf2_u32(src);
}

uint32_t test_vmv_x_s_u32m1_u32 (vuint32m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_u32m1_u32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.{{.*}}nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}})
  return vmv_x_s_u32m1_u32(src);
}

uint32_t test_vmv_x_s_u32m2_u32 (vuint32m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_u32m2_u32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.{{.*}}nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}})
  return vmv_x_s_u32m2_u32(src);
}

uint32_t test_vmv_x_s_u32m4_u32 (vuint32m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_u32m4_u32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.{{.*}}nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}})
  return vmv_x_s_u32m4_u32(src);
}

uint32_t test_vmv_x_s_u32m8_u32 (vuint32m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_u32m8_u32
  // CHECK: %{{.*}} = call i32 @llvm.riscv.vmv.x.s.{{.*}}nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}})
  return vmv_x_s_u32m8_u32(src);
}

uint64_t test_vmv_x_s_u64m1_u64 (vuint64m1_t src) {
  // CHECK-LABEL: test_vmv_x_s_u64m1_u64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.{{.*}}nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}})
  return vmv_x_s_u64m1_u64(src);
}

uint64_t test_vmv_x_s_u64m2_u64 (vuint64m2_t src) {
  // CHECK-LABEL: test_vmv_x_s_u64m2_u64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.{{.*}}nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}})
  return vmv_x_s_u64m2_u64(src);
}

uint64_t test_vmv_x_s_u64m4_u64 (vuint64m4_t src) {
  // CHECK-LABEL: test_vmv_x_s_u64m4_u64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.{{.*}}nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}})
  return vmv_x_s_u64m4_u64(src);
}

uint64_t test_vmv_x_s_u64m8_u64 (vuint64m8_t src) {
  // CHECK-LABEL: test_vmv_x_s_u64m8_u64
  // CHECK: %{{.*}} = call i64 @llvm.riscv.vmv.x.s.{{.*}}nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}})
  return vmv_x_s_u64m8_u64(src);
}

