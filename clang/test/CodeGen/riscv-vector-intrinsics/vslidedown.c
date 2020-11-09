// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8_t test_vslidedown_vx_i8mf8 (vint8mf8_t dst, vint8mf8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vslidedown.vx.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i8mf8(dst, src, offset);
}

vint8mf4_t test_vslidedown_vx_i8mf4 (vint8mf4_t dst, vint8mf4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vslidedown.vx.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i8mf4(dst, src, offset);
}

vint8mf2_t test_vslidedown_vx_i8mf2 (vint8mf2_t dst, vint8mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vslidedown.vx.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i8mf2(dst, src, offset);
}

vint8m1_t test_vslidedown_vx_i8m1 (vint8m1_t dst, vint8m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vslidedown.vx.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i8m1(dst, src, offset);
}

vint8m2_t test_vslidedown_vx_i8m2 (vint8m2_t dst, vint8m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vslidedown.vx.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i8m2(dst, src, offset);
}

vint8m4_t test_vslidedown_vx_i8m4 (vint8m4_t dst, vint8m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vslidedown.vx.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i8m4(dst, src, offset);
}

vint8m8_t test_vslidedown_vx_i8m8 (vint8m8_t dst, vint8m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vslidedown.vx.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i8m8(dst, src, offset);
}

vint16mf4_t test_vslidedown_vx_i16mf4 (vint16mf4_t dst, vint16mf4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vslidedown.vx.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i16mf4(dst, src, offset);
}

vint16mf2_t test_vslidedown_vx_i16mf2 (vint16mf2_t dst, vint16mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vslidedown.vx.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i16mf2(dst, src, offset);
}

vint16m1_t test_vslidedown_vx_i16m1 (vint16m1_t dst, vint16m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vslidedown.vx.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i16m1(dst, src, offset);
}

vint16m2_t test_vslidedown_vx_i16m2 (vint16m2_t dst, vint16m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vslidedown.vx.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i16m2(dst, src, offset);
}

vint16m4_t test_vslidedown_vx_i16m4 (vint16m4_t dst, vint16m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vslidedown.vx.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i16m4(dst, src, offset);
}

vint16m8_t test_vslidedown_vx_i16m8 (vint16m8_t dst, vint16m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vslidedown.vx.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i16m8(dst, src, offset);
}

vint32mf2_t test_vslidedown_vx_i32mf2 (vint32mf2_t dst, vint32mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vslidedown.vx.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i32mf2(dst, src, offset);
}

vint32m1_t test_vslidedown_vx_i32m1 (vint32m1_t dst, vint32m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vslidedown.vx.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i32m1(dst, src, offset);
}

vint32m2_t test_vslidedown_vx_i32m2 (vint32m2_t dst, vint32m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vslidedown.vx.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i32m2(dst, src, offset);
}

vint32m4_t test_vslidedown_vx_i32m4 (vint32m4_t dst, vint32m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vslidedown.vx.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i32m4(dst, src, offset);
}

vint32m8_t test_vslidedown_vx_i32m8 (vint32m8_t dst, vint32m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vslidedown.vx.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i32m8(dst, src, offset);
}

vint64m1_t test_vslidedown_vx_i64m1 (vint64m1_t dst, vint64m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vslidedown.vx.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i64m1(dst, src, offset);
}

vint64m2_t test_vslidedown_vx_i64m2 (vint64m2_t dst, vint64m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vslidedown.vx.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i64m2(dst, src, offset);
}

vint64m4_t test_vslidedown_vx_i64m4 (vint64m4_t dst, vint64m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vslidedown.vx.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i64m4(dst, src, offset);
}

vint64m8_t test_vslidedown_vx_i64m8 (vint64m8_t dst, vint64m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vslidedown.vx.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i64m8(dst, src, offset);
}

vuint8mf8_t test_vslidedown_vx_u8mf8 (vuint8mf8_t dst, vuint8mf8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vslidedown.vx.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u8mf8(dst, src, offset);
}

vuint8mf4_t test_vslidedown_vx_u8mf4 (vuint8mf4_t dst, vuint8mf4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vslidedown.vx.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u8mf4(dst, src, offset);
}

vuint8mf2_t test_vslidedown_vx_u8mf2 (vuint8mf2_t dst, vuint8mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vslidedown.vx.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u8mf2(dst, src, offset);
}

vuint8m1_t test_vslidedown_vx_u8m1 (vuint8m1_t dst, vuint8m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vslidedown.vx.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u8m1(dst, src, offset);
}

vuint8m2_t test_vslidedown_vx_u8m2 (vuint8m2_t dst, vuint8m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vslidedown.vx.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u8m2(dst, src, offset);
}

vuint8m4_t test_vslidedown_vx_u8m4 (vuint8m4_t dst, vuint8m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vslidedown.vx.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u8m4(dst, src, offset);
}

vuint8m8_t test_vslidedown_vx_u8m8 (vuint8m8_t dst, vuint8m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vslidedown.vx.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u8m8(dst, src, offset);
}

vuint16mf4_t test_vslidedown_vx_u16mf4 (vuint16mf4_t dst, vuint16mf4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vslidedown.vx.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u16mf4(dst, src, offset);
}

vuint16mf2_t test_vslidedown_vx_u16mf2 (vuint16mf2_t dst, vuint16mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vslidedown.vx.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u16mf2(dst, src, offset);
}

vuint16m1_t test_vslidedown_vx_u16m1 (vuint16m1_t dst, vuint16m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vslidedown.vx.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u16m1(dst, src, offset);
}

vuint16m2_t test_vslidedown_vx_u16m2 (vuint16m2_t dst, vuint16m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vslidedown.vx.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u16m2(dst, src, offset);
}

vuint16m4_t test_vslidedown_vx_u16m4 (vuint16m4_t dst, vuint16m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vslidedown.vx.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u16m4(dst, src, offset);
}

vuint16m8_t test_vslidedown_vx_u16m8 (vuint16m8_t dst, vuint16m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vslidedown.vx.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u16m8(dst, src, offset);
}

vuint32mf2_t test_vslidedown_vx_u32mf2 (vuint32mf2_t dst, vuint32mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vslidedown.vx.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u32mf2(dst, src, offset);
}

vuint32m1_t test_vslidedown_vx_u32m1 (vuint32m1_t dst, vuint32m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vslidedown.vx.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u32m1(dst, src, offset);
}

vuint32m2_t test_vslidedown_vx_u32m2 (vuint32m2_t dst, vuint32m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vslidedown.vx.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u32m2(dst, src, offset);
}

vuint32m4_t test_vslidedown_vx_u32m4 (vuint32m4_t dst, vuint32m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vslidedown.vx.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u32m4(dst, src, offset);
}

vuint32m8_t test_vslidedown_vx_u32m8 (vuint32m8_t dst, vuint32m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vslidedown.vx.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u32m8(dst, src, offset);
}

vuint64m1_t test_vslidedown_vx_u64m1 (vuint64m1_t dst, vuint64m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vslidedown.vx.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u64m1(dst, src, offset);
}

vuint64m2_t test_vslidedown_vx_u64m2 (vuint64m2_t dst, vuint64m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vslidedown.vx.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u64m2(dst, src, offset);
}

vuint64m4_t test_vslidedown_vx_u64m4 (vuint64m4_t dst, vuint64m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vslidedown.vx.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u64m4(dst, src, offset);
}

vuint64m8_t test_vslidedown_vx_u64m8 (vuint64m8_t dst, vuint64m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vslidedown.vx.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u64m8(dst, src, offset);
}

vfloat16mf4_t test_vslidedown_vx_f16mf4 (vfloat16mf4_t dst, vfloat16mf4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vslidedown.vx.nxv1f16{{.*}}(<vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f16mf4(dst, src, offset);
}

vfloat16mf2_t test_vslidedown_vx_f16mf2 (vfloat16mf2_t dst, vfloat16mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vslidedown.vx.nxv2f16{{.*}}(<vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f16mf2(dst, src, offset);
}

vfloat16m1_t test_vslidedown_vx_f16m1 (vfloat16m1_t dst, vfloat16m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vslidedown.vx.nxv4f16{{.*}}(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f16m1(dst, src, offset);
}

vfloat16m2_t test_vslidedown_vx_f16m2 (vfloat16m2_t dst, vfloat16m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vslidedown.vx.nxv8f16{{.*}}(<vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f16m2(dst, src, offset);
}

vfloat16m4_t test_vslidedown_vx_f16m4 (vfloat16m4_t dst, vfloat16m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vslidedown.vx.nxv16f16{{.*}}(<vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f16m4(dst, src, offset);
}

vfloat16m8_t test_vslidedown_vx_f16m8 (vfloat16m8_t dst, vfloat16m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vslidedown.vx.nxv32f16{{.*}}(<vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f16m8(dst, src, offset);
}

vfloat32mf2_t test_vslidedown_vx_f32mf2 (vfloat32mf2_t dst, vfloat32mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vslidedown.vx.nxv1f32{{.*}}(<vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f32mf2(dst, src, offset);
}

vfloat32m1_t test_vslidedown_vx_f32m1 (vfloat32m1_t dst, vfloat32m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vslidedown.vx.nxv2f32{{.*}}(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f32m1(dst, src, offset);
}

vfloat32m2_t test_vslidedown_vx_f32m2 (vfloat32m2_t dst, vfloat32m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vslidedown.vx.nxv4f32{{.*}}(<vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f32m2(dst, src, offset);
}

vfloat32m4_t test_vslidedown_vx_f32m4 (vfloat32m4_t dst, vfloat32m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vslidedown.vx.nxv8f32{{.*}}(<vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f32m4(dst, src, offset);
}

vfloat32m8_t test_vslidedown_vx_f32m8 (vfloat32m8_t dst, vfloat32m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vslidedown.vx.nxv16f32{{.*}}(<vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f32m8(dst, src, offset);
}

vfloat64m1_t test_vslidedown_vx_f64m1 (vfloat64m1_t dst, vfloat64m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vslidedown.vx.nxv1f32{{.*}}(<vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f64m1(dst, src, offset);
}

vfloat64m2_t test_vslidedown_vx_f64m2 (vfloat64m2_t dst, vfloat64m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vslidedown.vx.nxv2f32{{.*}}(<vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f64m2(dst, src, offset);
}

vfloat64m4_t test_vslidedown_vx_f64m4 (vfloat64m4_t dst, vfloat64m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vslidedown.vx.nxv4f32{{.*}}(<vscale x 4 x double> %{{.*}}, <vscale x 4 x double> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f64m4(dst, src, offset);
}

vfloat64m8_t test_vslidedown_vx_f64m8 (vfloat64m8_t dst, vfloat64m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vslidedown.vx.nxv8f32{{.*}}(<vscale x 8 x double> %{{.*}}, <vscale x 8 x double> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f64m8(dst, src, offset);
}

vint8mf8_t test_vslidedown_vx_i8mf8_m (vbool64_t mask, vint8mf8_t dst, vint8mf8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i8mf8_m
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vslidedown.vx.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i8mf8_m(mask, dst, src, offset);
}

vint8mf4_t test_vslidedown_vx_i8mf4_m (vbool32_t mask, vint8mf4_t dst, vint8mf4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i8mf4_m
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vslidedown.vx.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i8mf4_m(mask, dst, src, offset);
}

vint8mf2_t test_vslidedown_vx_i8mf2_m (vbool16_t mask, vint8mf2_t dst, vint8mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i8mf2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vslidedown.vx.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i8mf2_m(mask, dst, src, offset);
}

vint8m1_t test_vslidedown_vx_i8m1_m (vbool8_t mask, vint8m1_t dst, vint8m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vslidedown.vx.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i8m1_m(mask, dst, src, offset);
}

vint8m2_t test_vslidedown_vx_i8m2_m (vbool4_t mask, vint8m2_t dst, vint8m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i8m2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vslidedown.vx.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i8m2_m(mask, dst, src, offset);
}

vint8m4_t test_vslidedown_vx_i8m4_m (vbool2_t mask, vint8m4_t dst, vint8m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i8m4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vslidedown.vx.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i8m4_m(mask, dst, src, offset);
}

vint8m8_t test_vslidedown_vx_i8m8_m (vbool1_t mask, vint8m8_t dst, vint8m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i8m8_m
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vslidedown.vx.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i8m8_m(mask, dst, src, offset);
}

vint16mf4_t test_vslidedown_vx_i16mf4_m (vbool64_t mask, vint16mf4_t dst, vint16mf4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vslidedown.vx.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i16mf4_m(mask, dst, src, offset);
}

vint16mf2_t test_vslidedown_vx_i16mf2_m (vbool32_t mask, vint16mf2_t dst, vint16mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vslidedown.vx.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i16mf2_m(mask, dst, src, offset);
}

vint16m1_t test_vslidedown_vx_i16m1_m (vbool16_t mask, vint16m1_t dst, vint16m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vslidedown.vx.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i16m1_m(mask, dst, src, offset);
}

vint16m2_t test_vslidedown_vx_i16m2_m (vbool8_t mask, vint16m2_t dst, vint16m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vslidedown.vx.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i16m2_m(mask, dst, src, offset);
}

vint16m4_t test_vslidedown_vx_i16m4_m (vbool4_t mask, vint16m4_t dst, vint16m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vslidedown.vx.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i16m4_m(mask, dst, src, offset);
}

vint16m8_t test_vslidedown_vx_i16m8_m (vbool2_t mask, vint16m8_t dst, vint16m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vslidedown.vx.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i16m8_m(mask, dst, src, offset);
}

vint32mf2_t test_vslidedown_vx_i32mf2_m (vbool64_t mask, vint32mf2_t dst, vint32mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vslidedown.vx.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i32mf2_m(mask, dst, src, offset);
}

vint32m1_t test_vslidedown_vx_i32m1_m (vbool32_t mask, vint32m1_t dst, vint32m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vslidedown.vx.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i32m1_m(mask, dst, src, offset);
}

vint32m2_t test_vslidedown_vx_i32m2_m (vbool16_t mask, vint32m2_t dst, vint32m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vslidedown.vx.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i32m2_m(mask, dst, src, offset);
}

vint32m4_t test_vslidedown_vx_i32m4_m (vbool8_t mask, vint32m4_t dst, vint32m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vslidedown.vx.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i32m4_m(mask, dst, src, offset);
}

vint32m8_t test_vslidedown_vx_i32m8_m (vbool4_t mask, vint32m8_t dst, vint32m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vslidedown.vx.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i32m8_m(mask, dst, src, offset);
}

vint64m1_t test_vslidedown_vx_i64m1_m (vbool64_t mask, vint64m1_t dst, vint64m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vslidedown.vx.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i64m1_m(mask, dst, src, offset);
}

vint64m2_t test_vslidedown_vx_i64m2_m (vbool32_t mask, vint64m2_t dst, vint64m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vslidedown.vx.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i64m2_m(mask, dst, src, offset);
}

vint64m4_t test_vslidedown_vx_i64m4_m (vbool16_t mask, vint64m4_t dst, vint64m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vslidedown.vx.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i64m4_m(mask, dst, src, offset);
}

vint64m8_t test_vslidedown_vx_i64m8_m (vbool8_t mask, vint64m8_t dst, vint64m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_i64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vslidedown.vx.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_i64m8_m(mask, dst, src, offset);
}

vuint8mf8_t test_vslidedown_vx_u8mf8_m (vbool64_t mask, vuint8mf8_t dst, vuint8mf8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u8mf8_m
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vslidedown.vx.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u8mf8_m(mask, dst, src, offset);
}

vuint8mf4_t test_vslidedown_vx_u8mf4_m (vbool32_t mask, vuint8mf4_t dst, vuint8mf4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u8mf4_m
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vslidedown.vx.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u8mf4_m(mask, dst, src, offset);
}

vuint8mf2_t test_vslidedown_vx_u8mf2_m (vbool16_t mask, vuint8mf2_t dst, vuint8mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u8mf2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vslidedown.vx.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u8mf2_m(mask, dst, src, offset);
}

vuint8m1_t test_vslidedown_vx_u8m1_m (vbool8_t mask, vuint8m1_t dst, vuint8m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vslidedown.vx.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u8m1_m(mask, dst, src, offset);
}

vuint8m2_t test_vslidedown_vx_u8m2_m (vbool4_t mask, vuint8m2_t dst, vuint8m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u8m2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vslidedown.vx.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u8m2_m(mask, dst, src, offset);
}

vuint8m4_t test_vslidedown_vx_u8m4_m (vbool2_t mask, vuint8m4_t dst, vuint8m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u8m4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vslidedown.vx.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u8m4_m(mask, dst, src, offset);
}

vuint8m8_t test_vslidedown_vx_u8m8_m (vbool1_t mask, vuint8m8_t dst, vuint8m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u8m8_m
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vslidedown.vx.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u8m8_m(mask, dst, src, offset);
}

vuint16mf4_t test_vslidedown_vx_u16mf4_m (vbool64_t mask, vuint16mf4_t dst, vuint16mf4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vslidedown.vx.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u16mf4_m(mask, dst, src, offset);
}

vuint16mf2_t test_vslidedown_vx_u16mf2_m (vbool32_t mask, vuint16mf2_t dst, vuint16mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vslidedown.vx.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u16mf2_m(mask, dst, src, offset);
}

vuint16m1_t test_vslidedown_vx_u16m1_m (vbool16_t mask, vuint16m1_t dst, vuint16m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vslidedown.vx.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u16m1_m(mask, dst, src, offset);
}

vuint16m2_t test_vslidedown_vx_u16m2_m (vbool8_t mask, vuint16m2_t dst, vuint16m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vslidedown.vx.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u16m2_m(mask, dst, src, offset);
}

vuint16m4_t test_vslidedown_vx_u16m4_m (vbool4_t mask, vuint16m4_t dst, vuint16m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vslidedown.vx.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u16m4_m(mask, dst, src, offset);
}

vuint16m8_t test_vslidedown_vx_u16m8_m (vbool2_t mask, vuint16m8_t dst, vuint16m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vslidedown.vx.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u16m8_m(mask, dst, src, offset);
}

vuint32mf2_t test_vslidedown_vx_u32mf2_m (vbool64_t mask, vuint32mf2_t dst, vuint32mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vslidedown.vx.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u32mf2_m(mask, dst, src, offset);
}

vuint32m1_t test_vslidedown_vx_u32m1_m (vbool32_t mask, vuint32m1_t dst, vuint32m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vslidedown.vx.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u32m1_m(mask, dst, src, offset);
}

vuint32m2_t test_vslidedown_vx_u32m2_m (vbool16_t mask, vuint32m2_t dst, vuint32m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vslidedown.vx.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u32m2_m(mask, dst, src, offset);
}

vuint32m4_t test_vslidedown_vx_u32m4_m (vbool8_t mask, vuint32m4_t dst, vuint32m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vslidedown.vx.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u32m4_m(mask, dst, src, offset);
}

vuint32m8_t test_vslidedown_vx_u32m8_m (vbool4_t mask, vuint32m8_t dst, vuint32m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vslidedown.vx.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u32m8_m(mask, dst, src, offset);
}

vuint64m1_t test_vslidedown_vx_u64m1_m (vbool64_t mask, vuint64m1_t dst, vuint64m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vslidedown.vx.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u64m1_m(mask, dst, src, offset);
}

vuint64m2_t test_vslidedown_vx_u64m2_m (vbool32_t mask, vuint64m2_t dst, vuint64m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vslidedown.vx.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u64m2_m(mask, dst, src, offset);
}

vuint64m4_t test_vslidedown_vx_u64m4_m (vbool16_t mask, vuint64m4_t dst, vuint64m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vslidedown.vx.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u64m4_m(mask, dst, src, offset);
}

vuint64m8_t test_vslidedown_vx_u64m8_m (vbool8_t mask, vuint64m8_t dst, vuint64m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vslidedown.vx.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_u64m8_m(mask, dst, src, offset);
}

vfloat16mf4_t test_vslidedown_vx_f16mf4_m (vbool64_t mask, vfloat16mf4_t dst, vfloat16mf4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vslidedown.vx.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f16mf4_m(mask, dst, src, offset);
}

vfloat16mf2_t test_vslidedown_vx_f16mf2_m (vbool32_t mask, vfloat16mf2_t dst, vfloat16mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vslidedown.vx.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f16mf2_m(mask, dst, src, offset);
}

vfloat16m1_t test_vslidedown_vx_f16m1_m (vbool16_t mask, vfloat16m1_t dst, vfloat16m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vslidedown.vx.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f16m1_m(mask, dst, src, offset);
}

vfloat16m2_t test_vslidedown_vx_f16m2_m (vbool8_t mask, vfloat16m2_t dst, vfloat16m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vslidedown.vx.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f16m2_m(mask, dst, src, offset);
}

vfloat16m4_t test_vslidedown_vx_f16m4_m (vbool4_t mask, vfloat16m4_t dst, vfloat16m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vslidedown.vx.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f16m4_m(mask, dst, src, offset);
}

vfloat16m8_t test_vslidedown_vx_f16m8_m (vbool2_t mask, vfloat16m8_t dst, vfloat16m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vslidedown.vx.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f16m8_m(mask, dst, src, offset);
}

vfloat32mf2_t test_vslidedown_vx_f32mf2_m (vbool64_t mask, vfloat32mf2_t dst, vfloat32mf2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vslidedown.vx.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f32mf2_m(mask, dst, src, offset);
}

vfloat32m1_t test_vslidedown_vx_f32m1_m (vbool32_t mask, vfloat32m1_t dst, vfloat32m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vslidedown.vx.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f32m1_m(mask, dst, src, offset);
}

vfloat32m2_t test_vslidedown_vx_f32m2_m (vbool16_t mask, vfloat32m2_t dst, vfloat32m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vslidedown.vx.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f32m2_m(mask, dst, src, offset);
}

vfloat32m4_t test_vslidedown_vx_f32m4_m (vbool8_t mask, vfloat32m4_t dst, vfloat32m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vslidedown.vx.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f32m4_m(mask, dst, src, offset);
}

vfloat32m8_t test_vslidedown_vx_f32m8_m (vbool4_t mask, vfloat32m8_t dst, vfloat32m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vslidedown.vx.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f32m8_m(mask, dst, src, offset);
}

vfloat64m1_t test_vslidedown_vx_f64m1_m (vbool64_t mask, vfloat64m1_t dst, vfloat64m1_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vslidedown.vx.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f64m1_m(mask, dst, src, offset);
}

vfloat64m2_t test_vslidedown_vx_f64m2_m (vbool32_t mask, vfloat64m2_t dst, vfloat64m2_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vslidedown.vx.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f64m2_m(mask, dst, src, offset);
}

vfloat64m4_t test_vslidedown_vx_f64m4_m (vbool16_t mask, vfloat64m4_t dst, vfloat64m4_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vslidedown.vx.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, <vscale x 4 x double> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f64m4_m(mask, dst, src, offset);
}

vfloat64m8_t test_vslidedown_vx_f64m8_m (vbool8_t mask, vfloat64m8_t dst, vfloat64m8_t src, size_t offset) {
  // CHECK-LABEL: test_vslidedown_vx_f64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vslidedown.vx.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, <vscale x 8 x double> %{{.*}}, i64 %{{.*}})
  return vslidedown_vx_f64m8_m(mask, dst, src, offset);
}

