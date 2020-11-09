// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8_t test_vget_i8mf8x2_i8mf8 (vint8mf8x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf8x2_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vget.nxv1i8x2.nxv1i8{{.*}}(<vscale x 2 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf8x2_i8mf8(tuple, index);
}

vint8mf8_t test_vget_i8mf8x3_i8mf8 (vint8mf8x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf8x3_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vget.nxv1i8x3.nxv1i8{{.*}}(<vscale x 3 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf8x3_i8mf8(tuple, index);
}

vint8mf8_t test_vget_i8mf8x4_i8mf8 (vint8mf8x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf8x4_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vget.nxv1i8x4.nxv1i8{{.*}}(<vscale x 4 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf8x4_i8mf8(tuple, index);
}

vint8mf8_t test_vget_i8mf8x5_i8mf8 (vint8mf8x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf8x5_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vget.nxv1i8x5.nxv1i8{{.*}}(<vscale x 5 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf8x5_i8mf8(tuple, index);
}

vint8mf8_t test_vget_i8mf8x6_i8mf8 (vint8mf8x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf8x6_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vget.nxv1i8x6.nxv1i8{{.*}}(<vscale x 6 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf8x6_i8mf8(tuple, index);
}

vint8mf8_t test_vget_i8mf8x7_i8mf8 (vint8mf8x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf8x7_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vget.nxv1i8x7.nxv1i8{{.*}}(<vscale x 7 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf8x7_i8mf8(tuple, index);
}

vint8mf8_t test_vget_i8mf8x8_i8mf8 (vint8mf8x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf8x8_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vget.nxv1i8x8.nxv1i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf8x8_i8mf8(tuple, index);
}

vint8mf4_t test_vget_i8mf4x2_i8mf4 (vint8mf4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf4x2_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vget.nxv2i8x2.nxv2i8{{.*}}(<vscale x 4 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf4x2_i8mf4(tuple, index);
}

vint8mf4_t test_vget_i8mf4x3_i8mf4 (vint8mf4x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf4x3_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vget.nxv2i8x3.nxv2i8{{.*}}(<vscale x 6 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf4x3_i8mf4(tuple, index);
}

vint8mf4_t test_vget_i8mf4x4_i8mf4 (vint8mf4x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf4x4_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vget.nxv2i8x4.nxv2i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf4x4_i8mf4(tuple, index);
}

vint8mf4_t test_vget_i8mf4x5_i8mf4 (vint8mf4x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf4x5_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vget.nxv2i8x5.nxv2i8{{.*}}(<vscale x 10 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf4x5_i8mf4(tuple, index);
}

vint8mf4_t test_vget_i8mf4x6_i8mf4 (vint8mf4x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf4x6_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vget.nxv2i8x6.nxv2i8{{.*}}(<vscale x 12 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf4x6_i8mf4(tuple, index);
}

vint8mf4_t test_vget_i8mf4x7_i8mf4 (vint8mf4x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf4x7_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vget.nxv2i8x7.nxv2i8{{.*}}(<vscale x 14 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf4x7_i8mf4(tuple, index);
}

vint8mf4_t test_vget_i8mf4x8_i8mf4 (vint8mf4x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf4x8_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vget.nxv2i8x8.nxv2i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf4x8_i8mf4(tuple, index);
}

vint8mf2_t test_vget_i8mf2x2_i8mf2 (vint8mf2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf2x2_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vget.nxv4i8x2.nxv4i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf2x2_i8mf2(tuple, index);
}

vint8mf2_t test_vget_i8mf2x3_i8mf2 (vint8mf2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf2x3_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vget.nxv4i8x3.nxv4i8{{.*}}(<vscale x 12 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf2x3_i8mf2(tuple, index);
}

vint8mf2_t test_vget_i8mf2x4_i8mf2 (vint8mf2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf2x4_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vget.nxv4i8x4.nxv4i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf2x4_i8mf2(tuple, index);
}

vint8mf2_t test_vget_i8mf2x5_i8mf2 (vint8mf2x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf2x5_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vget.nxv4i8x5.nxv4i8{{.*}}(<vscale x 20 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf2x5_i8mf2(tuple, index);
}

vint8mf2_t test_vget_i8mf2x6_i8mf2 (vint8mf2x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf2x6_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vget.nxv4i8x6.nxv4i8{{.*}}(<vscale x 24 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf2x6_i8mf2(tuple, index);
}

vint8mf2_t test_vget_i8mf2x7_i8mf2 (vint8mf2x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf2x7_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vget.nxv4i8x7.nxv4i8{{.*}}(<vscale x 28 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf2x7_i8mf2(tuple, index);
}

vint8mf2_t test_vget_i8mf2x8_i8mf2 (vint8mf2x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8mf2x8_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vget.nxv4i8x8.nxv4i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8mf2x8_i8mf2(tuple, index);
}

vint8m1_t test_vget_i8m1x2_i8m1 (vint8m1x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8m1x2_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vget.nxv8i8x2.nxv8i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8m1x2_i8m1(tuple, index);
}

vint8m1_t test_vget_i8m1x3_i8m1 (vint8m1x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8m1x3_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vget.nxv8i8x3.nxv8i8{{.*}}(<vscale x 24 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8m1x3_i8m1(tuple, index);
}

vint8m1_t test_vget_i8m1x4_i8m1 (vint8m1x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8m1x4_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vget.nxv8i8x4.nxv8i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8m1x4_i8m1(tuple, index);
}

vint8m1_t test_vget_i8m1x5_i8m1 (vint8m1x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8m1x5_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vget.nxv8i8x5.nxv8i8{{.*}}(<vscale x 40 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8m1x5_i8m1(tuple, index);
}

vint8m1_t test_vget_i8m1x6_i8m1 (vint8m1x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8m1x6_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vget.nxv8i8x6.nxv8i8{{.*}}(<vscale x 48 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8m1x6_i8m1(tuple, index);
}

vint8m1_t test_vget_i8m1x7_i8m1 (vint8m1x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8m1x7_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vget.nxv8i8x7.nxv8i8{{.*}}(<vscale x 56 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8m1x7_i8m1(tuple, index);
}

vint8m1_t test_vget_i8m1x8_i8m1 (vint8m1x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8m1x8_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vget.nxv8i8x8.nxv8i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8m1x8_i8m1(tuple, index);
}

vint8m2_t test_vget_i8m2x2_i8m2 (vint8m2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8m2x2_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vget.nxv16i8x2.nxv16i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8m2x2_i8m2(tuple, index);
}

vint8m2_t test_vget_i8m2x3_i8m2 (vint8m2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8m2x3_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vget.nxv16i8x3.nxv16i8{{.*}}(<vscale x 48 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8m2x3_i8m2(tuple, index);
}

vint8m2_t test_vget_i8m2x4_i8m2 (vint8m2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8m2x4_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vget.nxv16i8x4.nxv16i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8m2x4_i8m2(tuple, index);
}

vint8m4_t test_vget_i8m4x2_i8m4 (vint8m4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i8m4x2_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vget.nxv32i8x2.nxv32i8{{.*}}(<vscale x 54 x i8> %{{.*}}, i64 %{{.*}})
  return vget_i8m4x2_i8m4(tuple, index);
}

vint16mf4_t test_vget_i16mf4x2_i16mf4 (vint16mf4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16mf4x2_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vget.nxv1i16x2.nxv1i16{{.*}}(<vscale x 2 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16mf4x2_i16mf4(tuple, index);
}

vint16mf4_t test_vget_i16mf4x3_i16mf4 (vint16mf4x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16mf4x3_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vget.nxv1i16x3.nxv1i16{{.*}}(<vscale x 3 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16mf4x3_i16mf4(tuple, index);
}

vint16mf4_t test_vget_i16mf4x4_i16mf4 (vint16mf4x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16mf4x4_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vget.nxv1i16x4.nxv1i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16mf4x4_i16mf4(tuple, index);
}

vint16mf4_t test_vget_i16mf4x5_i16mf4 (vint16mf4x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16mf4x5_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vget.nxv1i16x5.nxv1i16{{.*}}(<vscale x 5 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16mf4x5_i16mf4(tuple, index);
}

vint16mf4_t test_vget_i16mf4x6_i16mf4 (vint16mf4x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16mf4x6_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vget.nxv1i16x6.nxv1i16{{.*}}(<vscale x 6 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16mf4x6_i16mf4(tuple, index);
}

vint16mf4_t test_vget_i16mf4x7_i16mf4 (vint16mf4x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16mf4x7_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vget.nxv1i16x7.nxv1i16{{.*}}(<vscale x 7 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16mf4x7_i16mf4(tuple, index);
}

vint16mf4_t test_vget_i16mf4x8_i16mf4 (vint16mf4x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16mf4x8_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vget.nxv1i16x8.nxv1i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16mf4x8_i16mf4(tuple, index);
}

vint16mf2_t test_vget_i16mf2x2_i16mf2 (vint16mf2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16mf2x2_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vget.nxv2i16x2.nxv2i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16mf2x2_i16mf2(tuple, index);
}

vint16mf2_t test_vget_i16mf2x3_i16mf2 (vint16mf2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16mf2x3_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vget.nxv2i16x3.nxv2i16{{.*}}(<vscale x 6 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16mf2x3_i16mf2(tuple, index);
}

vint16mf2_t test_vget_i16mf2x4_i16mf2 (vint16mf2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16mf2x4_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vget.nxv2i16x4.nxv2i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16mf2x4_i16mf2(tuple, index);
}

vint16mf2_t test_vget_i16mf2x5_i16mf2 (vint16mf2x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16mf2x5_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vget.nxv2i16x5.nxv2i16{{.*}}(<vscale x 10 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16mf2x5_i16mf2(tuple, index);
}

vint16mf2_t test_vget_i16mf2x6_i16mf2 (vint16mf2x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16mf2x6_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vget.nxv2i16x6.nxv2i16{{.*}}(<vscale x 12 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16mf2x6_i16mf2(tuple, index);
}

vint16mf2_t test_vget_i16mf2x7_i16mf2 (vint16mf2x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16mf2x7_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vget.nxv2i16x7.nxv2i16{{.*}}(<vscale x 14 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16mf2x7_i16mf2(tuple, index);
}

vint16mf2_t test_vget_i16mf2x8_i16mf2 (vint16mf2x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16mf2x8_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vget.nxv2i16x8.nxv2i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16mf2x8_i16mf2(tuple, index);
}

vint16m1_t test_vget_i16m1x2_i16m1 (vint16m1x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16m1x2_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vget.nxv4i16x2.nxv4i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16m1x2_i16m1(tuple, index);
}

vint16m1_t test_vget_i16m1x3_i16m1 (vint16m1x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16m1x3_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vget.nxv4i16x3.nxv4i16{{.*}}(<vscale x 12 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16m1x3_i16m1(tuple, index);
}

vint16m1_t test_vget_i16m1x4_i16m1 (vint16m1x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16m1x4_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vget.nxv4i16x4.nxv4i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16m1x4_i16m1(tuple, index);
}

vint16m1_t test_vget_i16m1x5_i16m1 (vint16m1x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16m1x5_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vget.nxv4i16x5.nxv4i16{{.*}}(<vscale x 20 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16m1x5_i16m1(tuple, index);
}

vint16m1_t test_vget_i16m1x6_i16m1 (vint16m1x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16m1x6_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vget.nxv4i16x6.nxv4i16{{.*}}(<vscale x 24 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16m1x6_i16m1(tuple, index);
}

vint16m1_t test_vget_i16m1x7_i16m1 (vint16m1x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16m1x7_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vget.nxv4i16x7.nxv4i16{{.*}}(<vscale x 28 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16m1x7_i16m1(tuple, index);
}

vint16m1_t test_vget_i16m1x8_i16m1 (vint16m1x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16m1x8_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vget.nxv4i16x8.nxv4i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16m1x8_i16m1(tuple, index);
}

vint16m2_t test_vget_i16m2x2_i16m2 (vint16m2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16m2x2_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vget.nxv8i16x2.nxv8i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16m2x2_i16m2(tuple, index);
}

vint16m2_t test_vget_i16m2x3_i16m2 (vint16m2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16m2x3_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vget.nxv8i16x3.nxv8i16{{.*}}(<vscale x 24 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16m2x3_i16m2(tuple, index);
}

vint16m2_t test_vget_i16m2x4_i16m2 (vint16m2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16m2x4_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vget.nxv8i16x4.nxv8i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16m2x4_i16m2(tuple, index);
}

vint16m4_t test_vget_i16m4x2_i16m4 (vint16m4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i16m4x2_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vget.nxv16i16x2.nxv16i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i64 %{{.*}})
  return vget_i16m4x2_i16m4(tuple, index);
}

vint32mf2_t test_vget_i32mf2x2_i32mf2 (vint32mf2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32mf2x2_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vget.nxv1i32x2.nxv1i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32mf2x2_i32mf2(tuple, index);
}

vint32mf2_t test_vget_i32mf2x3_i32mf2 (vint32mf2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32mf2x3_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vget.nxv1i32x3.nxv1i32{{.*}}(<vscale x 3 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32mf2x3_i32mf2(tuple, index);
}

vint32mf2_t test_vget_i32mf2x4_i32mf2 (vint32mf2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32mf2x4_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vget.nxv1i32x4.nxv1i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32mf2x4_i32mf2(tuple, index);
}

vint32mf2_t test_vget_i32mf2x5_i32mf2 (vint32mf2x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32mf2x5_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vget.nxv1i32x5.nxv1i32{{.*}}(<vscale x 5 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32mf2x5_i32mf2(tuple, index);
}

vint32mf2_t test_vget_i32mf2x6_i32mf2 (vint32mf2x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32mf2x6_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vget.nxv1i32x6.nxv1i32{{.*}}(<vscale x 6 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32mf2x6_i32mf2(tuple, index);
}

vint32mf2_t test_vget_i32mf2x7_i32mf2 (vint32mf2x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32mf2x7_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vget.nxv1i32x7.nxv1i32{{.*}}(<vscale x 7 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32mf2x7_i32mf2(tuple, index);
}

vint32mf2_t test_vget_i32mf2x8_i32mf2 (vint32mf2x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32mf2x8_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vget.nxv1i32x8.nxv1i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32mf2x8_i32mf2(tuple, index);
}

vint32m1_t test_vget_i32m1x2_i32m1 (vint32m1x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32m1x2_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vget.nxv2i32x2.nxv2i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32m1x2_i32m1(tuple, index);
}

vint32m1_t test_vget_i32m1x3_i32m1 (vint32m1x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32m1x3_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vget.nxv2i32x3.nxv2i32{{.*}}(<vscale x 6 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32m1x3_i32m1(tuple, index);
}

vint32m1_t test_vget_i32m1x4_i32m1 (vint32m1x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32m1x4_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vget.nxv2i32x4.nxv2i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32m1x4_i32m1(tuple, index);
}

vint32m1_t test_vget_i32m1x5_i32m1 (vint32m1x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32m1x5_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vget.nxv2i32x5.nxv2i32{{.*}}(<vscale x 10 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32m1x5_i32m1(tuple, index);
}

vint32m1_t test_vget_i32m1x6_i32m1 (vint32m1x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32m1x6_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vget.nxv2i32x6.nxv2i32{{.*}}(<vscale x 12 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32m1x6_i32m1(tuple, index);
}

vint32m1_t test_vget_i32m1x7_i32m1 (vint32m1x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32m1x7_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vget.nxv2i32x7.nxv2i32{{.*}}(<vscale x 14 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32m1x7_i32m1(tuple, index);
}

vint32m1_t test_vget_i32m1x8_i32m1 (vint32m1x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32m1x8_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vget.nxv2i32x8.nxv2i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32m1x8_i32m1(tuple, index);
}

vint32m2_t test_vget_i32m2x2_i32m2 (vint32m2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32m2x2_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vget.nxv4i32x2.nxv4i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32m2x2_i32m2(tuple, index);
}

vint32m2_t test_vget_i32m2x3_i32m2 (vint32m2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32m2x3_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vget.nxv4i32x3.nxv4i32{{.*}}(<vscale x 12 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32m2x3_i32m2(tuple, index);
}

vint32m2_t test_vget_i32m2x4_i32m2 (vint32m2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32m2x4_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vget.nxv4i32x4.nxv4i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32m2x4_i32m2(tuple, index);
}

vint32m4_t test_vget_i32m4x2_i32m4 (vint32m4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i32m4x2_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vget.nxv8i32x2.nxv8i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i64 %{{.*}})
  return vget_i32m4x2_i32m4(tuple, index);
}

vint64m1_t test_vget_i64m1x2_i64m1 (vint64m1x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i64m1x2_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vget.nxv1i64x2.nxv1i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vget_i64m1x2_i64m1(tuple, index);
}

vint64m1_t test_vget_i64m1x3_i64m1 (vint64m1x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i64m1x3_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vget.nxv1i64x3.nxv1i64{{.*}}(<vscale x 3 x i64> %{{.*}}, i64 %{{.*}})
  return vget_i64m1x3_i64m1(tuple, index);
}

vint64m1_t test_vget_i64m1x4_i64m1 (vint64m1x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i64m1x4_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vget.nxv1i64x4.nxv1i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vget_i64m1x4_i64m1(tuple, index);
}

vint64m1_t test_vget_i64m1x5_i64m1 (vint64m1x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i64m1x5_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vget.nxv1i64x5.nxv1i64{{.*}}(<vscale x 5 x i64> %{{.*}}, i64 %{{.*}})
  return vget_i64m1x5_i64m1(tuple, index);
}

vint64m1_t test_vget_i64m1x6_i64m1 (vint64m1x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i64m1x6_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vget.nxv1i64x6.nxv1i64{{.*}}(<vscale x 6 x i64> %{{.*}}, i64 %{{.*}})
  return vget_i64m1x6_i64m1(tuple, index);
}

vint64m1_t test_vget_i64m1x7_i64m1 (vint64m1x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i64m1x7_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vget.nxv1i64x7.nxv1i64{{.*}}(<vscale x 7 x i64> %{{.*}}, i64 %{{.*}})
  return vget_i64m1x7_i64m1(tuple, index);
}

vint64m1_t test_vget_i64m1x8_i64m1 (vint64m1x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i64m1x8_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vget.nxv1i64x8.nxv1i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vget_i64m1x8_i64m1(tuple, index);
}

vint64m2_t test_vget_i64m2x2_i64m2 (vint64m2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i64m2x2_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vget.nxv2i64x2.nxv2i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vget_i64m2x2_i64m2(tuple, index);
}

vint64m2_t test_vget_i64m2x3_i64m2 (vint64m2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i64m2x3_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vget.nxv2i64x3.nxv2i64{{.*}}(<vscale x 6 x i64> %{{.*}}, i64 %{{.*}})
  return vget_i64m2x3_i64m2(tuple, index);
}

vint64m2_t test_vget_i64m2x4_i64m2 (vint64m2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i64m2x4_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vget.nxv2i64x4.nxv2i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vget_i64m2x4_i64m2(tuple, index);
}

vint64m4_t test_vget_i64m4x2_i64m4 (vint64m4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_i64m4x2_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vget.nxv4i64x2.nxv4i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vget_i64m4x2_i64m4(tuple, index);
}

vuint8mf8_t test_vget_u8mf8x2_u8mf8 (vuint8mf8x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf8x2_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vget.nxv1i8x2.nxv1i8{{.*}}(<vscale x 2 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf8x2_u8mf8(tuple, index);
}

vuint8mf8_t test_vget_u8mf8x3_u8mf8 (vuint8mf8x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf8x3_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vget.nxv1i8x3.nxv1i8{{.*}}(<vscale x 3 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf8x3_u8mf8(tuple, index);
}

vuint8mf8_t test_vget_u8mf8x4_u8mf8 (vuint8mf8x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf8x4_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vget.nxv1i8x4.nxv1i8{{.*}}(<vscale x 4 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf8x4_u8mf8(tuple, index);
}

vuint8mf8_t test_vget_u8mf8x5_u8mf8 (vuint8mf8x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf8x5_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vget.nxv1i8x5.nxv1i8{{.*}}(<vscale x 5 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf8x5_u8mf8(tuple, index);
}

vuint8mf8_t test_vget_u8mf8x6_u8mf8 (vuint8mf8x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf8x6_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vget.nxv1i8x6.nxv1i8{{.*}}(<vscale x 6 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf8x6_u8mf8(tuple, index);
}

vuint8mf8_t test_vget_u8mf8x7_u8mf8 (vuint8mf8x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf8x7_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vget.nxv1i8x7.nxv1i8{{.*}}(<vscale x 7 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf8x7_u8mf8(tuple, index);
}

vuint8mf8_t test_vget_u8mf8x8_u8mf8 (vuint8mf8x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf8x8_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vget.nxv1i8x8.nxv1i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf8x8_u8mf8(tuple, index);
}

vuint8mf4_t test_vget_u8mf4x2_u8mf4 (vuint8mf4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf4x2_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vget.nxv2i8x2.nxv2i8{{.*}}(<vscale x 4 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf4x2_u8mf4(tuple, index);
}

vuint8mf4_t test_vget_u8mf4x3_u8mf4 (vuint8mf4x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf4x3_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vget.nxv2i8x3.nxv2i8{{.*}}(<vscale x 6 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf4x3_u8mf4(tuple, index);
}

vuint8mf4_t test_vget_u8mf4x4_u8mf4 (vuint8mf4x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf4x4_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vget.nxv2i8x4.nxv2i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf4x4_u8mf4(tuple, index);
}

vuint8mf4_t test_vget_u8mf4x5_u8mf4 (vuint8mf4x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf4x5_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vget.nxv2i8x5.nxv2i8{{.*}}(<vscale x 10 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf4x5_u8mf4(tuple, index);
}

vuint8mf4_t test_vget_u8mf4x6_u8mf4 (vuint8mf4x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf4x6_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vget.nxv2i8x6.nxv2i8{{.*}}(<vscale x 12 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf4x6_u8mf4(tuple, index);
}

vuint8mf4_t test_vget_u8mf4x7_u8mf4 (vuint8mf4x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf4x7_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vget.nxv2i8x7.nxv2i8{{.*}}(<vscale x 14 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf4x7_u8mf4(tuple, index);
}

vuint8mf4_t test_vget_u8mf4x8_u8mf4 (vuint8mf4x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf4x8_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vget.nxv2i8x8.nxv2i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf4x8_u8mf4(tuple, index);
}

vuint8mf2_t test_vget_u8mf2x2_u8mf2 (vuint8mf2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf2x2_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vget.nxv4i8x2.nxv4i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf2x2_u8mf2(tuple, index);
}

vuint8mf2_t test_vget_u8mf2x3_u8mf2 (vuint8mf2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf2x3_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vget.nxv4i8x3.nxv4i8{{.*}}(<vscale x 12 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf2x3_u8mf2(tuple, index);
}

vuint8mf2_t test_vget_u8mf2x4_u8mf2 (vuint8mf2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf2x4_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vget.nxv4i8x4.nxv4i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf2x4_u8mf2(tuple, index);
}

vuint8mf2_t test_vget_u8mf2x5_u8mf2 (vuint8mf2x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf2x5_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vget.nxv4i8x5.nxv4i8{{.*}}(<vscale x 20 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf2x5_u8mf2(tuple, index);
}

vuint8mf2_t test_vget_u8mf2x6_u8mf2 (vuint8mf2x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf2x6_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vget.nxv4i8x6.nxv4i8{{.*}}(<vscale x 24 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf2x6_u8mf2(tuple, index);
}

vuint8mf2_t test_vget_u8mf2x7_u8mf2 (vuint8mf2x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf2x7_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vget.nxv4i8x7.nxv4i8{{.*}}(<vscale x 28 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf2x7_u8mf2(tuple, index);
}

vuint8mf2_t test_vget_u8mf2x8_u8mf2 (vuint8mf2x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8mf2x8_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vget.nxv4i8x8.nxv4i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8mf2x8_u8mf2(tuple, index);
}

vuint8m1_t test_vget_u8m1x2_u8m1 (vuint8m1x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8m1x2_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vget.nxv8i8x2.nxv8i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8m1x2_u8m1(tuple, index);
}

vuint8m1_t test_vget_u8m1x3_u8m1 (vuint8m1x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8m1x3_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vget.nxv8i8x3.nxv8i8{{.*}}(<vscale x 24 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8m1x3_u8m1(tuple, index);
}

vuint8m1_t test_vget_u8m1x4_u8m1 (vuint8m1x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8m1x4_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vget.nxv8i8x4.nxv8i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8m1x4_u8m1(tuple, index);
}

vuint8m1_t test_vget_u8m1x5_u8m1 (vuint8m1x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8m1x5_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vget.nxv8i8x5.nxv8i8{{.*}}(<vscale x 40 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8m1x5_u8m1(tuple, index);
}

vuint8m1_t test_vget_u8m1x6_u8m1 (vuint8m1x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8m1x6_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vget.nxv8i8x6.nxv8i8{{.*}}(<vscale x 48 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8m1x6_u8m1(tuple, index);
}

vuint8m1_t test_vget_u8m1x7_u8m1 (vuint8m1x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8m1x7_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vget.nxv8i8x7.nxv8i8{{.*}}(<vscale x 56 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8m1x7_u8m1(tuple, index);
}

vuint8m1_t test_vget_u8m1x8_u8m1 (vuint8m1x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8m1x8_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vget.nxv8i8x8.nxv8i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8m1x8_u8m1(tuple, index);
}

vuint8m2_t test_vget_u8m2x2_u8m2 (vuint8m2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8m2x2_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vget.nxv16i8x2.nxv16i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8m2x2_u8m2(tuple, index);
}

vuint8m2_t test_vget_u8m2x3_u8m2 (vuint8m2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8m2x3_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vget.nxv16i8x3.nxv16i8{{.*}}(<vscale x 48 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8m2x3_u8m2(tuple, index);
}

vuint8m2_t test_vget_u8m2x4_u8m2 (vuint8m2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8m2x4_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vget.nxv16i8x4.nxv16i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8m2x4_u8m2(tuple, index);
}

vuint8m4_t test_vget_u8m4x2_u8m4 (vuint8m4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u8m4x2_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vget.nxv32i8x2.nxv32i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i64 %{{.*}})
  return vget_u8m4x2_u8m4(tuple, index);
}

vuint16mf4_t test_vget_u16mf4x2_u16mf4 (vuint16mf4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16mf4x2_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vget.nxv1i16x2.nxv1i16{{.*}}(<vscale x 2 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16mf4x2_u16mf4(tuple, index);
}

vuint16mf4_t test_vget_u16mf4x3_u16mf4 (vuint16mf4x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16mf4x3_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vget.nxv1i16x3.nxv1i16{{.*}}(<vscale x 3 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16mf4x3_u16mf4(tuple, index);
}

vuint16mf4_t test_vget_u16mf4x4_u16mf4 (vuint16mf4x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16mf4x4_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vget.nxv1i16x4.nxv1i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16mf4x4_u16mf4(tuple, index);
}

vuint16mf4_t test_vget_u16mf4x5_u16mf4 (vuint16mf4x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16mf4x5_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vget.nxv1i16x5.nxv1i16{{.*}}(<vscale x 5 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16mf4x5_u16mf4(tuple, index);
}

vuint16mf4_t test_vget_u16mf4x6_u16mf4 (vuint16mf4x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16mf4x6_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vget.nxv1i16x6.nxv1i16{{.*}}(<vscale x 6 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16mf4x6_u16mf4(tuple, index);
}

vuint16mf4_t test_vget_u16mf4x7_u16mf4 (vuint16mf4x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16mf4x7_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vget.nxv1i16x7.nxv1i16{{.*}}(<vscale x 7 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16mf4x7_u16mf4(tuple, index);
}

vuint16mf4_t test_vget_u16mf4x8_u16mf4 (vuint16mf4x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16mf4x8_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vget.nxv1i16x8.nxv1i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16mf4x8_u16mf4(tuple, index);
}

vuint16mf2_t test_vget_u16mf2x2_u16mf2 (vuint16mf2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16mf2x2_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vget.nxv2i16x2.nxv2i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16mf2x2_u16mf2(tuple, index);
}

vuint16mf2_t test_vget_u16mf2x3_u16mf2 (vuint16mf2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16mf2x3_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vget.nxv2i16x3.nxv2i16{{.*}}(<vscale x 6 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16mf2x3_u16mf2(tuple, index);
}

vuint16mf2_t test_vget_u16mf2x4_u16mf2 (vuint16mf2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16mf2x4_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vget.nxv2i16x4.nxv2i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16mf2x4_u16mf2(tuple, index);
}

vuint16mf2_t test_vget_u16mf2x5_u16mf2 (vuint16mf2x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16mf2x5_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vget.nxv2i16x5.nxv2i16{{.*}}(<vscale x 10 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16mf2x5_u16mf2(tuple, index);
}

vuint16mf2_t test_vget_u16mf2x6_u16mf2 (vuint16mf2x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16mf2x6_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vget.nxv2i16x6.nxv2i16{{.*}}(<vscale x 12 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16mf2x6_u16mf2(tuple, index);
}

vuint16mf2_t test_vget_u16mf2x7_u16mf2 (vuint16mf2x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16mf2x7_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vget.nxv2i16x7.nxv2i16{{.*}}(<vscale x 14 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16mf2x7_u16mf2(tuple, index);
}

vuint16mf2_t test_vget_u16mf2x8_u16mf2 (vuint16mf2x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16mf2x8_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vget.nxv2i16x8.nxv2i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16mf2x8_u16mf2(tuple, index);
}

vuint16m1_t test_vget_u16m1x2_u16m1 (vuint16m1x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16m1x2_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vget.nxv4i16x2.nxv4i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16m1x2_u16m1(tuple, index);
}

vuint16m1_t test_vget_u16m1x3_u16m1 (vuint16m1x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16m1x3_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vget.nxv4i16x3.nxv4i16{{.*}}(<vscale x 12 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16m1x3_u16m1(tuple, index);
}

vuint16m1_t test_vget_u16m1x4_u16m1 (vuint16m1x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16m1x4_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vget.nxv4i16x4.nxv4i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16m1x4_u16m1(tuple, index);
}

vuint16m1_t test_vget_u16m1x5_u16m1 (vuint16m1x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16m1x5_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vget.nxv4i16x5.nxv4i16{{.*}}(<vscale x 20 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16m1x5_u16m1(tuple, index);
}

vuint16m1_t test_vget_u16m1x6_u16m1 (vuint16m1x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16m1x6_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vget.nxv4i16x6.nxv4i16{{.*}}(<vscale x 24 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16m1x6_u16m1(tuple, index);
}

vuint16m1_t test_vget_u16m1x7_u16m1 (vuint16m1x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16m1x7_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vget.nxv4i16x7.nxv4i16{{.*}}(<vscale x 28 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16m1x7_u16m1(tuple, index);
}

vuint16m1_t test_vget_u16m1x8_u16m1 (vuint16m1x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16m1x8_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vget.nxv4i16x8.nxv4i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16m1x8_u16m1(tuple, index);
}

vuint16m2_t test_vget_u16m2x2_u16m2 (vuint16m2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16m2x2_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vget.nxv8i16x2.nxv8i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16m2x2_u16m2(tuple, index);
}

vuint16m2_t test_vget_u16m2x3_u16m2 (vuint16m2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16m2x3_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vget.nxv8i16x3.nxv8i16{{.*}}(<vscale x 24 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16m2x3_u16m2(tuple, index);
}

vuint16m2_t test_vget_u16m2x4_u16m2 (vuint16m2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16m2x4_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vget.nxv8i16x4.nxv8i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16m2x4_u16m2(tuple, index);
}

vuint16m4_t test_vget_u16m4x2_u16m4 (vuint16m4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u16m4x2_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vget.nxv16i16x2.nxv16i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i64 %{{.*}})
  return vget_u16m4x2_u16m4(tuple, index);
}

vuint32mf2_t test_vget_u32mf2x2_u32mf2 (vuint32mf2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32mf2x2_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vget.nxv1i32x2.nxv1i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32mf2x2_u32mf2(tuple, index);
}

vuint32mf2_t test_vget_u32mf2x3_u32mf2 (vuint32mf2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32mf2x3_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vget.nxv1i32x3.nxv1i32{{.*}}(<vscale x 3 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32mf2x3_u32mf2(tuple, index);
}

vuint32mf2_t test_vget_u32mf2x4_u32mf2 (vuint32mf2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32mf2x4_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vget.nxv1i32x4.nxv1i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32mf2x4_u32mf2(tuple, index);
}

vuint32mf2_t test_vget_u32mf2x5_u32mf2 (vuint32mf2x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32mf2x5_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vget.nxv1i32x5.nxv1i32{{.*}}(<vscale x 5 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32mf2x5_u32mf2(tuple, index);
}

vuint32mf2_t test_vget_u32mf2x6_u32mf2 (vuint32mf2x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32mf2x6_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vget.nxv1i32x6.nxv1i32{{.*}}(<vscale x 6 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32mf2x6_u32mf2(tuple, index);
}

vuint32mf2_t test_vget_u32mf2x7_u32mf2 (vuint32mf2x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32mf2x7_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vget.nxv1i32x7.nxv1i32{{.*}}(<vscale x 7 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32mf2x7_u32mf2(tuple, index);
}

vuint32mf2_t test_vget_u32mf2x8_u32mf2 (vuint32mf2x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32mf2x8_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vget.nxv1i32x8.nxv1i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32mf2x8_u32mf2(tuple, index);
}

vuint32m1_t test_vget_u32m1x2_u32m1 (vuint32m1x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32m1x2_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vget.nxv2i32x2.nxv2i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32m1x2_u32m1(tuple, index);
}

vuint32m1_t test_vget_u32m1x3_u32m1 (vuint32m1x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32m1x3_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vget.nxv2i32x3.nxv2i32{{.*}}(<vscale x 6 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32m1x3_u32m1(tuple, index);
}

vuint32m1_t test_vget_u32m1x4_u32m1 (vuint32m1x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32m1x4_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vget.nxv2i32x4.nxv2i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32m1x4_u32m1(tuple, index);
}

vuint32m1_t test_vget_u32m1x5_u32m1 (vuint32m1x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32m1x5_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vget.nxv2i32x5.nxv2i32{{.*}}(<vscale x 10 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32m1x5_u32m1(tuple, index);
}

vuint32m1_t test_vget_u32m1x6_u32m1 (vuint32m1x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32m1x6_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vget.nxv2i32x6.nxv2i32{{.*}}(<vscale x 12 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32m1x6_u32m1(tuple, index);
}

vuint32m1_t test_vget_u32m1x7_u32m1 (vuint32m1x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32m1x7_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vget.nxv2i32x7.nxv2i32{{.*}}(<vscale x 14 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32m1x7_u32m1(tuple, index);
}

vuint32m1_t test_vget_u32m1x8_u32m1 (vuint32m1x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32m1x8_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vget.nxv2i32x8.nxv2i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32m1x8_u32m1(tuple, index);
}

vuint32m2_t test_vget_u32m2x2_u32m2 (vuint32m2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32m2x2_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vget.nxv4i32x2.nxv4i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32m2x2_u32m2(tuple, index);
}

vuint32m2_t test_vget_u32m2x3_u32m2 (vuint32m2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32m2x3_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vget.nxv4i32x3.nxv4i32{{.*}}(<vscale x 12 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32m2x3_u32m2(tuple, index);
}

vuint32m2_t test_vget_u32m2x4_u32m2 (vuint32m2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32m2x4_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vget.nxv4i32x4.nxv4i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32m2x4_u32m2(tuple, index);
}

vuint32m4_t test_vget_u32m4x2_u32m4 (vuint32m4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u32m4x2_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vget.nxv8i32x2.nxv8i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i64 %{{.*}})
  return vget_u32m4x2_u32m4(tuple, index);
}

vuint64m1_t test_vget_u64m1x2_u64m1 (vuint64m1x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u64m1x2_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vget.nxv1i64x2.nxv1i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vget_u64m1x2_u64m1(tuple, index);
}

vuint64m1_t test_vget_u64m1x3_u64m1 (vuint64m1x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u64m1x3_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vget.nxv1i64x3.nxv1i64{{.*}}(<vscale x 3 x i64> %{{.*}}, i64 %{{.*}})
  return vget_u64m1x3_u64m1(tuple, index);
}

vuint64m1_t test_vget_u64m1x4_u64m1 (vuint64m1x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u64m1x4_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vget.nxv1i64x4.nxv1i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vget_u64m1x4_u64m1(tuple, index);
}

vuint64m1_t test_vget_u64m1x5_u64m1 (vuint64m1x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u64m1x5_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vget.nxv1i64x5.nxv1i64{{.*}}(<vscale x 5 x i64> %{{.*}}, i64 %{{.*}})
  return vget_u64m1x5_u64m1(tuple, index);
}

vuint64m1_t test_vget_u64m1x6_u64m1 (vuint64m1x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u64m1x6_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vget.nxv1i64x6.nxv1i64{{.*}}(<vscale x 6 x i64> %{{.*}}, i64 %{{.*}})
  return vget_u64m1x6_u64m1(tuple, index);
}

vuint64m1_t test_vget_u64m1x7_u64m1 (vuint64m1x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u64m1x7_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vget.nxv1i64x7.nxv1i64{{.*}}(<vscale x 7 x i64> %{{.*}}, i64 %{{.*}})
  return vget_u64m1x7_u64m1(tuple, index);
}

vuint64m1_t test_vget_u64m1x8_u64m1 (vuint64m1x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u64m1x8_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vget.nxv1i64x8.nxv1i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vget_u64m1x8_u64m1(tuple, index);
}

vuint64m2_t test_vget_u64m2x2_u64m2 (vuint64m2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u64m2x2_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vget.nxv2i64x2.nxv2i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vget_u64m2x2_u64m2(tuple, index);
}

vuint64m2_t test_vget_u64m2x3_u64m2 (vuint64m2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u64m2x3_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vget.nxv2i64x3.nxv2i64{{.*}}(<vscale x 6 x i64> %{{.*}}, i64 %{{.*}})
  return vget_u64m2x3_u64m2(tuple, index);
}

vuint64m2_t test_vget_u64m2x4_u64m2 (vuint64m2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u64m2x4_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vget.nxv2i64x4.nxv2i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vget_u64m2x4_u64m2(tuple, index);
}

vuint64m4_t test_vget_u64m4x2_u64m4 (vuint64m4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_u64m4x2_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vget.nxv4i64x2.nxv4i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vget_u64m4x2_u64m4(tuple, index);
}

vfloat16mf4_t test_vget_f16mf4x2_f16mf4 (vfloat16mf4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16mf4x2_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vget.nxv1f16x2.nxv1f16{{.*}}(<vscale x 2 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16mf4x2_f16mf4(tuple, index);
}

vfloat16mf4_t test_vget_f16mf4x3_f16mf4 (vfloat16mf4x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16mf4x3_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vget.nxv1f16x3.nxv1f16{{.*}}(<vscale x 3 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16mf4x3_f16mf4(tuple, index);
}

vfloat16mf4_t test_vget_f16mf4x4_f16mf4 (vfloat16mf4x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16mf4x4_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vget.nxv1f16x4.nxv1f16{{.*}}(<vscale x 4 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16mf4x4_f16mf4(tuple, index);
}

vfloat16mf4_t test_vget_f16mf4x5_f16mf4 (vfloat16mf4x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16mf4x5_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vget.nxv1f16x5.nxv1f16{{.*}}(<vscale x 5 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16mf4x5_f16mf4(tuple, index);
}

vfloat16mf4_t test_vget_f16mf4x6_f16mf4 (vfloat16mf4x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16mf4x6_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vget.nxv1f16x6.nxv1f16{{.*}}(<vscale x 6 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16mf4x6_f16mf4(tuple, index);
}

vfloat16mf4_t test_vget_f16mf4x7_f16mf4 (vfloat16mf4x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16mf4x7_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vget.nxv1f16x7.nxv1f16{{.*}}(<vscale x 7 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16mf4x7_f16mf4(tuple, index);
}

vfloat16mf4_t test_vget_f16mf4x8_f16mf4 (vfloat16mf4x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16mf4x8_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vget.nxv1f16x8.nxv1f16{{.*}}(<vscale x 8 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16mf4x8_f16mf4(tuple, index);
}

vfloat16mf2_t test_vget_f16mf2x2_f16mf2 (vfloat16mf2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16mf2x2_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vget.nxv2f16x2.nxv2f16{{.*}}(<vscale x 4 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16mf2x2_f16mf2(tuple, index);
}

vfloat16mf2_t test_vget_f16mf2x3_f16mf2 (vfloat16mf2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16mf2x3_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vget.nxv2f16x3.nxv2f16{{.*}}(<vscale x 6 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16mf2x3_f16mf2(tuple, index);
}

vfloat16mf2_t test_vget_f16mf2x4_f16mf2 (vfloat16mf2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16mf2x4_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vget.nxv2f16x4.nxv2f16{{.*}}(<vscale x 8 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16mf2x4_f16mf2(tuple, index);
}

vfloat16mf2_t test_vget_f16mf2x5_f16mf2 (vfloat16mf2x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16mf2x5_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vget.nxv2f16x5.nxv2f16{{.*}}(<vscale x 10 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16mf2x5_f16mf2(tuple, index);
}

vfloat16mf2_t test_vget_f16mf2x6_f16mf2 (vfloat16mf2x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16mf2x6_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vget.nxv2f16x6.nxv2f16{{.*}}(<vscale x 12 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16mf2x6_f16mf2(tuple, index);
}

vfloat16mf2_t test_vget_f16mf2x7_f16mf2 (vfloat16mf2x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16mf2x7_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vget.nxv2f16x7.nxv2f16{{.*}}(<vscale x 14 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16mf2x7_f16mf2(tuple, index);
}

vfloat16mf2_t test_vget_f16mf2x8_f16mf2 (vfloat16mf2x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16mf2x8_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vget.nxv2f16x8.nxv2f16{{.*}}(<vscale x 16 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16mf2x8_f16mf2(tuple, index);
}

vfloat16m1_t test_vget_f16m1x2_f16m1 (vfloat16m1x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16m1x2_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vget.nxv4f16x2.nxv4f16{{.*}}(<vscale x 8 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16m1x2_f16m1(tuple, index);
}

vfloat16m1_t test_vget_f16m1x3_f16m1 (vfloat16m1x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16m1x3_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vget.nxv4f16x3.nxv4f16{{.*}}(<vscale x 12 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16m1x3_f16m1(tuple, index);
}

vfloat16m1_t test_vget_f16m1x4_f16m1 (vfloat16m1x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16m1x4_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vget.nxv4f16x4.nxv4f16{{.*}}(<vscale x 16 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16m1x4_f16m1(tuple, index);
}

vfloat16m1_t test_vget_f16m1x5_f16m1 (vfloat16m1x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16m1x5_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vget.nxv4f16x5.nxv4f16{{.*}}(<vscale x 20 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16m1x5_f16m1(tuple, index);
}

vfloat16m1_t test_vget_f16m1x6_f16m1 (vfloat16m1x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16m1x6_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vget.nxv4f16x6.nxv4f16{{.*}}(<vscale x 24 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16m1x6_f16m1(tuple, index);
}

vfloat16m1_t test_vget_f16m1x7_f16m1 (vfloat16m1x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16m1x7_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vget.nxv4f16x7.nxv4f16{{.*}}(<vscale x 28 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16m1x7_f16m1(tuple, index);
}

vfloat16m1_t test_vget_f16m1x8_f16m1 (vfloat16m1x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16m1x8_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vget.nxv4f16x8.nxv4f16{{.*}}(<vscale x 32 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16m1x8_f16m1(tuple, index);
}

vfloat16m2_t test_vget_f16m2x2_f16m2 (vfloat16m2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16m2x2_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vget.nxv8f16x2.nxv8f16{{.*}}(<vscale x 16 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16m2x2_f16m2(tuple, index);
}

vfloat16m2_t test_vget_f16m2x3_f16m2 (vfloat16m2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16m2x3_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vget.nxv8f16x3.nxv8f16{{.*}}(<vscale x 24 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16m2x3_f16m2(tuple, index);
}

vfloat16m2_t test_vget_f16m2x4_f16m2 (vfloat16m2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16m2x4_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vget.nxv8f16x4.nxv8f16{{.*}}(<vscale x 32 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16m2x4_f16m2(tuple, index);
}

vfloat16m4_t test_vget_f16m4x2_f16m4 (vfloat16m4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f16m4x2_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vget.nxv16f16x2.nxv16f16{{.*}}(<vscale x 32 x half> %{{.*}}, i64 %{{.*}})
  return vget_f16m4x2_f16m4(tuple, index);
}

vfloat32mf2_t test_vget_f32mf2x2_f32mf2 (vfloat32mf2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32mf2x2_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vget.nxv1f32x2.nxv1f32{{.*}}(<vscale x 2 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32mf2x2_f32mf2(tuple, index);
}

vfloat32mf2_t test_vget_f32mf2x3_f32mf2 (vfloat32mf2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32mf2x3_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vget.nxv1f32x3.nxv1f32{{.*}}(<vscale x 3 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32mf2x3_f32mf2(tuple, index);
}

vfloat32mf2_t test_vget_f32mf2x4_f32mf2 (vfloat32mf2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32mf2x4_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vget.nxv1f32x4.nxv1f32{{.*}}(<vscale x 4 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32mf2x4_f32mf2(tuple, index);
}

vfloat32mf2_t test_vget_f32mf2x5_f32mf2 (vfloat32mf2x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32mf2x5_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vget.nxv1f32x5.nxv1f32{{.*}}(<vscale x 5 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32mf2x5_f32mf2(tuple, index);
}

vfloat32mf2_t test_vget_f32mf2x6_f32mf2 (vfloat32mf2x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32mf2x6_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vget.nxv1f32x6.nxv1f32{{.*}}(<vscale x 6 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32mf2x6_f32mf2(tuple, index);
}

vfloat32mf2_t test_vget_f32mf2x7_f32mf2 (vfloat32mf2x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32mf2x7_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vget.nxv1f32x7.nxv1f32{{.*}}(<vscale x 7 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32mf2x7_f32mf2(tuple, index);
}

vfloat32mf2_t test_vget_f32mf2x8_f32mf2 (vfloat32mf2x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32mf2x8_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vget.nxv1f32x8.nxv1f32{{.*}}(<vscale x 8 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32mf2x8_f32mf2(tuple, index);
}

vfloat32m1_t test_vget_f32m1x2_f32m1 (vfloat32m1x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32m1x2_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vget.nxv2f32x2.nxv2f32{{.*}}(<vscale x 4 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32m1x2_f32m1(tuple, index);
}

vfloat32m1_t test_vget_f32m1x3_f32m1 (vfloat32m1x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32m1x3_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vget.nxv2f32x3.nxv2f32{{.*}}(<vscale x 6 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32m1x3_f32m1(tuple, index);
}

vfloat32m1_t test_vget_f32m1x4_f32m1 (vfloat32m1x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32m1x4_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vget.nxv2f32x4.nxv2f32{{.*}}(<vscale x 8 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32m1x4_f32m1(tuple, index);
}

vfloat32m1_t test_vget_f32m1x5_f32m1 (vfloat32m1x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32m1x5_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vget.nxv2f32x5.nxv2f32{{.*}}(<vscale x 10 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32m1x5_f32m1(tuple, index);
}

vfloat32m1_t test_vget_f32m1x6_f32m1 (vfloat32m1x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32m1x6_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vget.nxv2f32x6.nxv2f32{{.*}}(<vscale x 12 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32m1x6_f32m1(tuple, index);
}

vfloat32m1_t test_vget_f32m1x7_f32m1 (vfloat32m1x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32m1x7_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vget.nxv2f32x7.nxv2f32{{.*}}(<vscale x 14 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32m1x7_f32m1(tuple, index);
}

vfloat32m1_t test_vget_f32m1x8_f32m1 (vfloat32m1x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32m1x8_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vget.nxv2f32x8.nxv2f32{{.*}}(<vscale x 16 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32m1x8_f32m1(tuple, index);
}

vfloat32m2_t test_vget_f32m2x2_f32m2 (vfloat32m2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32m2x2_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vget.nxv4f32x2.nxv4f32{{.*}}(<vscale x 8 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32m2x2_f32m2(tuple, index);
}

vfloat32m2_t test_vget_f32m2x3_f32m2 (vfloat32m2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32m2x3_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vget.nxv4f32x3.nxv4f32{{.*}}(<vscale x 12 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32m2x3_f32m2(tuple, index);
}

vfloat32m2_t test_vget_f32m2x4_f32m2 (vfloat32m2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32m2x4_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vget.nxv4f32x4.nxv4f32{{.*}}(<vscale x 16 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32m2x4_f32m2(tuple, index);
}

vfloat32m4_t test_vget_f32m4x2_f32m4 (vfloat32m4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f32m4x2_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vget.nxv8f32x2.nxv8f32{{.*}}(<vscale x 16 x float> %{{.*}}, i64 %{{.*}})
  return vget_f32m4x2_f32m4(tuple, index);
}

vfloat64m1_t test_vget_f64m1x2_f64m1 (vfloat64m1x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f64m1x2_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vget.nxv1f32x2.nxv1f32{{.*}}(<vscale x 2 x double> %{{.*}}, i64 %{{.*}})
  return vget_f64m1x2_f64m1(tuple, index);
}

vfloat64m1_t test_vget_f64m1x3_f64m1 (vfloat64m1x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f64m1x3_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vget.nxv1f32x3.nxv1f32{{.*}}(<vscale x 3 x double> %{{.*}}, i64 %{{.*}})
  return vget_f64m1x3_f64m1(tuple, index);
}

vfloat64m1_t test_vget_f64m1x4_f64m1 (vfloat64m1x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f64m1x4_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vget.nxv1f32x4.nxv1f32{{.*}}(<vscale x 4 x double> %{{.*}}, i64 %{{.*}})
  return vget_f64m1x4_f64m1(tuple, index);
}

vfloat64m1_t test_vget_f64m1x5_f64m1 (vfloat64m1x5_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f64m1x5_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vget.nxv1f32x5.nxv1f32{{.*}}(<vscale x 5 x double> %{{.*}}, i64 %{{.*}})
  return vget_f64m1x5_f64m1(tuple, index);
}

vfloat64m1_t test_vget_f64m1x6_f64m1 (vfloat64m1x6_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f64m1x6_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vget.nxv1f32x6.nxv1f32{{.*}}(<vscale x 6 x double> %{{.*}}, i64 %{{.*}})
  return vget_f64m1x6_f64m1(tuple, index);
}

vfloat64m1_t test_vget_f64m1x7_f64m1 (vfloat64m1x7_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f64m1x7_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vget.nxv1f32x7.nxv1f32{{.*}}(<vscale x 7 x double> %{{.*}}, i64 %{{.*}})
  return vget_f64m1x7_f64m1(tuple, index);
}

vfloat64m1_t test_vget_f64m1x8_f64m1 (vfloat64m1x8_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f64m1x8_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vget.nxv1f32x8.nxv1f32{{.*}}(<vscale x 8 x double> %{{.*}}, i64 %{{.*}})
  return vget_f64m1x8_f64m1(tuple, index);
}

vfloat64m2_t test_vget_f64m2x2_f64m2 (vfloat64m2x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f64m2x2_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vget.nxv2f32x2.nxv2f32{{.*}}(<vscale x 4 x double> %{{.*}}, i64 %{{.*}})
  return vget_f64m2x2_f64m2(tuple, index);
}

vfloat64m2_t test_vget_f64m2x3_f64m2 (vfloat64m2x3_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f64m2x3_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vget.nxv2f32x3.nxv2f32{{.*}}(<vscale x 6 x double> %{{.*}}, i64 %{{.*}})
  return vget_f64m2x3_f64m2(tuple, index);
}

vfloat64m2_t test_vget_f64m2x4_f64m2 (vfloat64m2x4_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f64m2x4_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vget.nxv2f32x4.nxv2f32{{.*}}(<vscale x 8 x double> %{{.*}}, i64 %{{.*}})
  return vget_f64m2x4_f64m2(tuple, index);
}

vfloat64m4_t test_vget_f64m4x2_f64m4 (vfloat64m4x2_t tuple, size_t index) {
  // CHECK-LABEL: test_vget_f64m4x2_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vget.nxv4f32x2.nxv4f32{{.*}}(<vscale x 8 x double> %{{.*}}, i64 %{{.*}})
  return vget_f64m4x2_f64m4(tuple, index);
}

