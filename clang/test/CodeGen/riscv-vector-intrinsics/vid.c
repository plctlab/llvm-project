// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vuint8mf8_t test_vid_v_u8mf8 () {
  // CHECK-LABEL: test_vid_v_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vid.v.nxv1i8{{.*}}()
  return vid_v_u8mf8(();
}

vuint8mf4_t test_vid_v_u8mf4 () {
  // CHECK-LABEL: test_vid_v_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vid.v.nxv2i8{{.*}}()
  return vid_v_u8mf4(();
}

vuint8mf2_t test_vid_v_u8mf2 () {
  // CHECK-LABEL: test_vid_v_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vid.v.nxv4i8{{.*}}()
  return vid_v_u8mf2(();
}

vuint8m1_t test_vid_v_u8m1 () {
  // CHECK-LABEL: test_vid_v_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vid.v.nxv8i8{{.*}}()
  return vid_v_u8m1(();
}

vuint8m2_t test_vid_v_u8m2 () {
  // CHECK-LABEL: test_vid_v_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vid.v.nxv16i8{{.*}}()
  return vid_v_u8m2(();
}

vuint8m4_t test_vid_v_u8m4 () {
  // CHECK-LABEL: test_vid_v_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vid.v.nxv32i8{{.*}}()
  return vid_v_u8m4(();
}

vuint8m8_t test_vid_v_u8m8 () {
  // CHECK-LABEL: test_vid_v_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vid.v.nxv64i8{{.*}}()
  return vid_v_u8m8(();
}

vuint16mf4_t test_vid_v_u16mf4 () {
  // CHECK-LABEL: test_vid_v_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vid.v.nxv1i16{{.*}}()
  return vid_v_u16mf4(();
}

vuint16mf2_t test_vid_v_u16mf2 () {
  // CHECK-LABEL: test_vid_v_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vid.v.nxv2i16{{.*}}()
  return vid_v_u16mf2(();
}

vuint16m1_t test_vid_v_u16m1 () {
  // CHECK-LABEL: test_vid_v_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vid.v.nxv4i16{{.*}}()
  return vid_v_u16m1(();
}

vuint16m2_t test_vid_v_u16m2 () {
  // CHECK-LABEL: test_vid_v_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vid.v.nxv8i16{{.*}}()
  return vid_v_u16m2(();
}

vuint16m4_t test_vid_v_u16m4 () {
  // CHECK-LABEL: test_vid_v_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vid.v.nxv16i16{{.*}}()
  return vid_v_u16m4(();
}

vuint16m8_t test_vid_v_u16m8 () {
  // CHECK-LABEL: test_vid_v_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vid.v.nxv32i16{{.*}}()
  return vid_v_u16m8(();
}

vuint32mf2_t test_vid_v_u32mf2 () {
  // CHECK-LABEL: test_vid_v_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vid.v.nxv1i32{{.*}}()
  return vid_v_u32mf2(();
}

vuint32m1_t test_vid_v_u32m1 () {
  // CHECK-LABEL: test_vid_v_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vid.v.nxv2i32{{.*}}()
  return vid_v_u32m1(();
}

vuint32m2_t test_vid_v_u32m2 () {
  // CHECK-LABEL: test_vid_v_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vid.v.nxv4i32{{.*}}()
  return vid_v_u32m2(();
}

vuint32m4_t test_vid_v_u32m4 () {
  // CHECK-LABEL: test_vid_v_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vid.v.nxv8i32{{.*}}()
  return vid_v_u32m4(();
}

vuint32m8_t test_vid_v_u32m8 () {
  // CHECK-LABEL: test_vid_v_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vid.v.nxv16i32{{.*}}()
  return vid_v_u32m8(();
}

vuint64m1_t test_vid_v_u64m1 () {
  // CHECK-LABEL: test_vid_v_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vid.v.nxv1i64{{.*}}()
  return vid_v_u64m1(();
}

vuint64m2_t test_vid_v_u64m2 () {
  // CHECK-LABEL: test_vid_v_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vid.v.nxv2i64{{.*}}()
  return vid_v_u64m2(();
}

vuint64m4_t test_vid_v_u64m4 () {
  // CHECK-LABEL: test_vid_v_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vid.v.nxv4i64{{.*}}()
  return vid_v_u64m4(();
}

vuint64m8_t test_vid_v_u64m8 () {
  // CHECK-LABEL: test_vid_v_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vid.v.nxv8i64{{.*}}()
  return vid_v_u64m8(();
}

vuint8mf8_t test_vid_v_u8mf8_m (vbool64_t mask, vuint8mf8_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u8mf8_m
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vid.v.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vid_v_u8mf8_m(mask, maskedoff);
}

vuint8mf4_t test_vid_v_u8mf4_m (vbool32_t mask, vuint8mf4_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u8mf4_m
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vid.v.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vid_v_u8mf4_m(mask, maskedoff);
}

vuint8mf2_t test_vid_v_u8mf2_m (vbool16_t mask, vuint8mf2_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u8mf2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vid.v.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vid_v_u8mf2_m(mask, maskedoff);
}

vuint8m1_t test_vid_v_u8m1_m (vbool8_t mask, vuint8m1_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u8m1_m
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vid.v.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vid_v_u8m1_m(mask, maskedoff);
}

vuint8m2_t test_vid_v_u8m2_m (vbool4_t mask, vuint8m2_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u8m2_m
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vid.v.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vid_v_u8m2_m(mask, maskedoff);
}

vuint8m4_t test_vid_v_u8m4_m (vbool2_t mask, vuint8m4_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u8m4_m
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vid.v.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vid_v_u8m4_m(mask, maskedoff);
}

vuint8m8_t test_vid_v_u8m8_m (vbool1_t mask, vuint8m8_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u8m8_m
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vid.v.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vid_v_u8m8_m(mask, maskedoff);
}

vuint16mf4_t test_vid_v_u16mf4_m (vbool64_t mask, vuint16mf4_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u16mf4_m
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vid.v.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vid_v_u16mf4_m(mask, maskedoff);
}

vuint16mf2_t test_vid_v_u16mf2_m (vbool32_t mask, vuint16mf2_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u16mf2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vid.v.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vid_v_u16mf2_m(mask, maskedoff);
}

vuint16m1_t test_vid_v_u16m1_m (vbool16_t mask, vuint16m1_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u16m1_m
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vid.v.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vid_v_u16m1_m(mask, maskedoff);
}

vuint16m2_t test_vid_v_u16m2_m (vbool8_t mask, vuint16m2_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u16m2_m
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vid.v.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vid_v_u16m2_m(mask, maskedoff);
}

vuint16m4_t test_vid_v_u16m4_m (vbool4_t mask, vuint16m4_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u16m4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vid.v.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vid_v_u16m4_m(mask, maskedoff);
}

vuint16m8_t test_vid_v_u16m8_m (vbool2_t mask, vuint16m8_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u16m8_m
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vid.v.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vid_v_u16m8_m(mask, maskedoff);
}

vuint32mf2_t test_vid_v_u32mf2_m (vbool64_t mask, vuint32mf2_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u32mf2_m
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vid.v.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vid_v_u32mf2_m(mask, maskedoff);
}

vuint32m1_t test_vid_v_u32m1_m (vbool32_t mask, vuint32m1_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u32m1_m
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vid.v.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vid_v_u32m1_m(mask, maskedoff);
}

vuint32m2_t test_vid_v_u32m2_m (vbool16_t mask, vuint32m2_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u32m2_m
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vid.v.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vid_v_u32m2_m(mask, maskedoff);
}

vuint32m4_t test_vid_v_u32m4_m (vbool8_t mask, vuint32m4_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u32m4_m
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vid.v.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vid_v_u32m4_m(mask, maskedoff);
}

vuint32m8_t test_vid_v_u32m8_m (vbool4_t mask, vuint32m8_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u32m8_m
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vid.v.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vid_v_u32m8_m(mask, maskedoff);
}

vuint64m1_t test_vid_v_u64m1_m (vbool64_t mask, vuint64m1_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u64m1_m
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vid.v.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vid_v_u64m1_m(mask, maskedoff);
}

vuint64m2_t test_vid_v_u64m2_m (vbool32_t mask, vuint64m2_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u64m2_m
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vid.v.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vid_v_u64m2_m(mask, maskedoff);
}

vuint64m4_t test_vid_v_u64m4_m (vbool16_t mask, vuint64m4_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u64m4_m
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vid.v.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vid_v_u64m4_m(mask, maskedoff);
}

vuint64m8_t test_vid_v_u64m8_m (vbool8_t mask, vuint64m8_t maskedoff) {
  // CHECK-LABEL: test_vid_v_u64m8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vid.v.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vid_v_u64m8_m(mask, maskedoff);
}

