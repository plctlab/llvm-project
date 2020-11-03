// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8_t test_vadd_vv_i8mf8(vint8mf8_t value1, vint8mf8_t value2) {
  // CHECK-LABEL: test_vadd_vv_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vadd.vv.nxv1i8(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vadd_vv_i8mf8(value1, value2);
}

vint8mf4_t test_vadd_vv_i8mf4(vint8mf4_t value1, vint8mf4_t value2) {
  // CHECK-LABEL: test_vadd_vv_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vadd.vv.nxv2i8(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vadd_vv_i8mf4(value1, value2);
}

vint8mf2_t test_vadd_vv_i8mf2(vint8mf2_t value1, vint8mf2_t value2) {
  // CHECK-LABEL: test_vadd_vv_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vadd.vv.nxv4i8(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vadd_vv_i8mf2(value1, value2);
}

vint8m1_t test_vadd_vv_i8m1(vint8m1_t value1, vint8m1_t value2) {
  // CHECK-LABEL: test_vadd_vv_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vadd.vv.nxv8i8(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vadd_vv_i8m1(value1, value2);
}

vint8m2_t test_vadd_vv_i8m2(vint8m2_t value1, vint8m2_t value2) {
  // CHECK-LABEL: test_vadd_vv_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vadd.vv.nxv16i8(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vadd_vv_i8m2(value1, value2);
}

vint8m4_t test_vadd_vv_i8m4(vint8m4_t value1, vint8m4_t value2) {
  // CHECK-LABEL: test_vadd_vv_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vadd.vv.nxv32i8(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vadd_vv_i8m4(value1, value2);
}

vint8m8_t test_vadd_vv_i8m8(vint8m8_t value1, vint8m8_t value2) {
  // CHECK-LABEL: test_vadd_vv_i8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vadd.vv.nxv64i8(<vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vadd_vv_i8m8(value1, value2);
}

vint16mf4_t test_vadd_vv_i16mf4(vint16mf4_t value1, vint16mf4_t value2) {
  // CHECK-LABEL: test_vadd_vv_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vadd.vv.nxv1i16(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vadd_vv_i16mf4(value1, value2);
}

vint16mf2_t test_vadd_vv_i16mf2(vint16mf2_t value1, vint16mf2_t value2) {
  // CHECK-LABEL: test_vadd_vv_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vadd.vv.nxv2i16(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vadd_vv_i16mf2(value1, value2);
}

vint16m1_t test_vadd_vv_i16m1(vint16m1_t value1, vint16m1_t value2) {
  // CHECK-LABEL: test_vadd_vv_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vadd.vv.nxv4i16(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vadd_vv_i16m1(value1, value2);
}

vint16m2_t test_vadd_vv_i16m2(vint16m2_t value1, vint16m2_t value2) {
  // CHECK-LABEL: test_vadd_vv_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vadd.vv.nxv8i16(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vadd_vv_i16m2(value1, value2);
}

vint16m4_t test_vadd_vv_i16m4(vint16m4_t value1, vint16m4_t value2) {
  // CHECK-LABEL: test_vadd_vv_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vadd.vv.nxv16i16(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vadd_vv_i16m4(value1, value2);
}

vint16m8_t test_vadd_vv_i16m8(vint16m8_t value1, vint16m8_t value2) {
  // CHECK-LABEL: test_vadd_vv_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vadd.vv.nxv32i16(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vadd_vv_i16m8(value1, value2);
}

vint32mf2_t test_vadd_vv_i32mf2(vint32mf2_t value1, vint32mf2_t value2) {
  // CHECK-LABEL: test_vadd_vv_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vadd.vv.nxv1i32(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vadd_vv_i32mf2(value1, value2);
}

vint32m1_t test_vadd_vv_i32m1(vint32m1_t value1, vint32m1_t value2) {
  // CHECK-LABEL: test_vadd_vv_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vadd.vv.nxv2i32(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vadd_vv_i32m1(value1, value2);
}

vint32m2_t test_vadd_vv_i32m2(vint32m2_t value1, vint32m2_t value2) {
  // CHECK-LABEL: test_vadd_vv_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vadd.vv.nxv4i32(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vadd_vv_i32m2(value1, value2);
}

vint32m4_t test_vadd_vv_i32m4(vint32m4_t value1, vint32m4_t value2) {
  // CHECK-LABEL: test_vadd_vv_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vadd.vv.nxv8i32(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vadd_vv_i32m4(value1, value2);
}

vint32m8_t test_vadd_vv_i32m8(vint32m8_t value1, vint32m8_t value2) {
  // CHECK-LABEL: test_vadd_vv_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vadd.vv.nxv16i32(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vadd_vv_i32m8(value1, value2);
}

vint64m1_t test_vadd_vv_i64m1(vint64m1_t value1, vint64m1_t value2) {
  // CHECK-LABEL: test_vadd_vv_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vadd.vv.nxv1i64(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vadd_vv_i64m1(value1, value2);
}

vint64m2_t test_vadd_vv_i64m2(vint64m2_t value1, vint64m2_t value2) {
  // CHECK-LABEL: test_vadd_vv_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vadd.vv.nxv2i64(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vadd_vv_i64m2(value1, value2);
}

vint64m4_t test_vadd_vv_i64m4(vint64m4_t value1, vint64m4_t value2) {
  // CHECK-LABEL: test_vadd_vv_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vadd.vv.nxv4i64(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vadd_vv_i64m4(value1, value2);
}

vint64m8_t test_vadd_vv_i64m8(vint64m8_t value1, vint64m8_t value2) {
  // CHECK-LABEL: test_vadd_vv_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vadd.vv.nxv8i64(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vadd_vv_i64m8(value1, value2);
}

vuint8mf8_t test_vadd_vv_u8mf8(vuint8mf8_t value1, vuint8mf8_t value2) {
  // CHECK-LABEL: test_vadd_vv_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vadd.vv.nxv1i8(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vadd_vv_u8mf8(value1, value2);
}

vuint8mf4_t test_vadd_vv_u8mf4(vuint8mf4_t value1, vuint8mf4_t value2) {
  // CHECK-LABEL: test_vadd_vv_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vadd.vv.nxv2i8(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vadd_vv_u8mf4(value1, value2);
}

vuint8mf2_t test_vadd_vv_u8mf2(vuint8mf2_t value1, vuint8mf2_t value2) {
  // CHECK-LABEL: test_vadd_vv_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vadd.vv.nxv4i8(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vadd_vv_u8mf2(value1, value2);
}

vuint8m1_t test_vadd_vv_u8m1(vuint8m1_t value1, vuint8m1_t value2) {
  // CHECK-LABEL: test_vadd_vv_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vadd.vv.nxv8i8(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vadd_vv_u8m1(value1, value2);
}

vuint8m2_t test_vadd_vv_u8m2(vuint8m2_t value1, vuint8m2_t value2) {
  // CHECK-LABEL: test_vadd_vv_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vadd.vv.nxv16i8(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vadd_vv_u8m2(value1, value2);
}

vuint8m4_t test_vadd_vv_u8m4(vuint8m4_t value1, vuint8m4_t value2) {
  // CHECK-LABEL: test_vadd_vv_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vadd.vv.nxv32i8(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vadd_vv_u8m4(value1, value2);
}

vuint8m8_t test_vadd_vv_u8m8(vuint8m8_t value1, vuint8m8_t value2) {
  // CHECK-LABEL: test_vadd_vv_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vadd.vv.nxv64i8(<vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vadd_vv_u8m8(value1, value2);
}

vuint16mf4_t test_vadd_vv_u16mf4(vuint16mf4_t value1, vuint16mf4_t value2) {
  // CHECK-LABEL: test_vadd_vv_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vadd.vv.nxv1i16(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vadd_vv_u16mf4(value1, value2);
}

vuint16mf2_t test_vadd_vv_u16mf2(vuint16mf2_t value1, vuint16mf2_t value2) {
  // CHECK-LABEL: test_vadd_vv_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vadd.vv.nxv2i16(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vadd_vv_u16mf2(value1, value2);
}

vuint16m1_t test_vadd_vv_u16m1(vuint16m1_t value1, vuint16m1_t value2) {
  // CHECK-LABEL: test_vadd_vv_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vadd.vv.nxv4i16(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vadd_vv_u16m1(value1, value2);
}

vuint16m2_t test_vadd_vv_u16m2(vuint16m2_t value1, vuint16m2_t value2) {
  // CHECK-LABEL: test_vadd_vv_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vadd.vv.nxv8i16(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vadd_vv_u16m2(value1, value2);
}

vuint16m4_t test_vadd_vv_u16m4(vuint16m4_t value1, vuint16m4_t value2) {
  // CHECK-LABEL: test_vadd_vv_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vadd.vv.nxv16i16(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vadd_vv_u16m4(value1, value2);
}

vuint16m8_t test_vadd_vv_u16m8(vuint16m8_t value1, vuint16m8_t value2) {
  // CHECK-LABEL: test_vadd_vv_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vadd.vv.nxv32i16(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vadd_vv_u16m8(value1, value2);
}

vuint32mf2_t test_vadd_vv_u32mf2(vuint32mf2_t value1, vuint32mf2_t value2) {
  // CHECK-LABEL: test_vadd_vv_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vadd.vv.nxv1i32(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vadd_vv_u32mf2(value1, value2);
}

vuint32m1_t test_vadd_vv_u32m1(vuint32m1_t value1, vuint32m1_t value2) {
  // CHECK-LABEL: test_vadd_vv_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vadd.vv.nxv2i32(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vadd_vv_u32m1(value1, value2);
}

vuint32m2_t test_vadd_vv_u32m2(vuint32m2_t value1, vuint32m2_t value2) {
  // CHECK-LABEL: test_vadd_vv_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vadd.vv.nxv4i32(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vadd_vv_u32m2(value1, value2);
}

vuint32m4_t test_vadd_vv_u32m4(vuint32m4_t value1, vuint32m4_t value2) {
  // CHECK-LABEL: test_vadd_vv_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vadd.vv.nxv8i32(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vadd_vv_u32m4(value1, value2);
}

vuint32m8_t test_vadd_vv_u32m8(vuint32m8_t value1, vuint32m8_t value2) {
  // CHECK-LABEL: test_vadd_vv_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vadd.vv.nxv16i32(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vadd_vv_u32m8(value1, value2);
}

vuint64m1_t test_vadd_vv_u64m1(vuint64m1_t value1, vuint64m1_t value2) {
  // CHECK-LABEL: test_vadd_vv_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vadd.vv.nxv1i64(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vadd_vv_u64m1(value1, value2);
}

vuint64m2_t test_vadd_vv_u64m2(vuint64m2_t value1, vuint64m2_t value2) {
  // CHECK-LABEL: test_vadd_vv_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vadd.vv.nxv2i64(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vadd_vv_u64m2(value1, value2);
}

vuint64m4_t test_vadd_vv_u64m4(vuint64m4_t value1, vuint64m4_t value2) {
  // CHECK-LABEL: test_vadd_vv_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vadd.vv.nxv4i64(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vadd_vv_u64m4(value1, value2);
}

vuint64m8_t test_vadd_vv_u64m8(vuint64m8_t value1, vuint64m8_t value2) {
  // CHECK-LABEL: test_vadd_vv_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vadd.vv.nxv8i64(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vadd_vv_u64m8(value1, value2);
}
