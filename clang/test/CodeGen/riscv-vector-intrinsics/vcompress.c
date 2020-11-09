// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint8mf8_t test_vcompress_vm_i8mf8 (vbool64_t mask, vint8mf8_t maskedoff, vint8mf8_t src) {
  // CHECK-LABEL: test_vcompress_vm_i8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vcompress.vm.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcompress_vm_i8mf8(mask, maskedoff, src);
}

vint8mf4_t test_vcompress_vm_i8mf4 (vbool32_t mask, vint8mf4_t maskedoff, vint8mf4_t src) {
  // CHECK-LABEL: test_vcompress_vm_i8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vcompress.vm.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcompress_vm_i8mf4(mask, maskedoff, src);
}

vint8mf2_t test_vcompress_vm_i8mf2 (vbool16_t mask, vint8mf2_t maskedoff, vint8mf2_t src) {
  // CHECK-LABEL: test_vcompress_vm_i8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vcompress.vm.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcompress_vm_i8mf2(mask, maskedoff, src);
}

vint8m1_t test_vcompress_vm_i8m1 (vbool8_t mask, vint8m1_t maskedoff, vint8m1_t src) {
  // CHECK-LABEL: test_vcompress_vm_i8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcompress.vm.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcompress_vm_i8m1(mask, maskedoff, src);
}

vint8m2_t test_vcompress_vm_i8m2 (vbool4_t mask, vint8m2_t maskedoff, vint8m2_t src) {
  // CHECK-LABEL: test_vcompress_vm_i8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcompress.vm.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vcompress_vm_i8m2(mask, maskedoff, src);
}

vint8m4_t test_vcompress_vm_i8m4 (vbool2_t mask, vint8m4_t maskedoff, vint8m4_t src) {
  // CHECK-LABEL: test_vcompress_vm_i8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcompress.vm.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vcompress_vm_i8m4(mask, maskedoff, src);
}

vint8m8_t test_vcompress_vm_i8m8 (vbool1_t mask, vint8m8_t maskedoff, vint8m8_t src) {
  // CHECK-LABEL: test_vcompress_vm_i8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vcompress.vm.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vcompress_vm_i8m8(mask, maskedoff, src);
}

vint16mf4_t test_vcompress_vm_i16mf4 (vbool64_t mask, vint16mf4_t maskedoff, vint16mf4_t src) {
  // CHECK-LABEL: test_vcompress_vm_i16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vcompress.vm.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcompress_vm_i16mf4(mask, maskedoff, src);
}

vint16mf2_t test_vcompress_vm_i16mf2 (vbool32_t mask, vint16mf2_t maskedoff, vint16mf2_t src) {
  // CHECK-LABEL: test_vcompress_vm_i16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vcompress.vm.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcompress_vm_i16mf2(mask, maskedoff, src);
}

vint16m1_t test_vcompress_vm_i16m1 (vbool16_t mask, vint16m1_t maskedoff, vint16m1_t src) {
  // CHECK-LABEL: test_vcompress_vm_i16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vcompress.vm.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcompress_vm_i16m1(mask, maskedoff, src);
}

vint16m2_t test_vcompress_vm_i16m2 (vbool8_t mask, vint16m2_t maskedoff, vint16m2_t src) {
  // CHECK-LABEL: test_vcompress_vm_i16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcompress.vm.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vcompress_vm_i16m2(mask, maskedoff, src);
}

vint16m4_t test_vcompress_vm_i16m4 (vbool4_t mask, vint16m4_t maskedoff, vint16m4_t src) {
  // CHECK-LABEL: test_vcompress_vm_i16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcompress.vm.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vcompress_vm_i16m4(mask, maskedoff, src);
}

vint16m8_t test_vcompress_vm_i16m8 (vbool2_t mask, vint16m8_t maskedoff, vint16m8_t src) {
  // CHECK-LABEL: test_vcompress_vm_i16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcompress.vm.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vcompress_vm_i16m8(mask, maskedoff, src);
}

vint32mf2_t test_vcompress_vm_i32mf2 (vbool64_t mask, vint32mf2_t maskedoff, vint32mf2_t src) {
  // CHECK-LABEL: test_vcompress_vm_i32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vcompress.vm.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcompress_vm_i32mf2(mask, maskedoff, src);
}

vint32m1_t test_vcompress_vm_i32m1 (vbool32_t mask, vint32m1_t maskedoff, vint32m1_t src) {
  // CHECK-LABEL: test_vcompress_vm_i32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vcompress.vm.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcompress_vm_i32m1(mask, maskedoff, src);
}

vint32m2_t test_vcompress_vm_i32m2 (vbool16_t mask, vint32m2_t maskedoff, vint32m2_t src) {
  // CHECK-LABEL: test_vcompress_vm_i32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vcompress.vm.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vcompress_vm_i32m2(mask, maskedoff, src);
}

vint32m4_t test_vcompress_vm_i32m4 (vbool8_t mask, vint32m4_t maskedoff, vint32m4_t src) {
  // CHECK-LABEL: test_vcompress_vm_i32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcompress.vm.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vcompress_vm_i32m4(mask, maskedoff, src);
}

vint32m8_t test_vcompress_vm_i32m8 (vbool4_t mask, vint32m8_t maskedoff, vint32m8_t src) {
  // CHECK-LABEL: test_vcompress_vm_i32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcompress.vm.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vcompress_vm_i32m8(mask, maskedoff, src);
}

vint64m1_t test_vcompress_vm_i64m1 (vbool64_t mask, vint64m1_t maskedoff, vint64m1_t src) {
  // CHECK-LABEL: test_vcompress_vm_i64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vcompress.vm.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcompress_vm_i64m1(mask, maskedoff, src);
}

vint64m2_t test_vcompress_vm_i64m2 (vbool32_t mask, vint64m2_t maskedoff, vint64m2_t src) {
  // CHECK-LABEL: test_vcompress_vm_i64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vcompress.vm.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vcompress_vm_i64m2(mask, maskedoff, src);
}

vint64m4_t test_vcompress_vm_i64m4 (vbool16_t mask, vint64m4_t maskedoff, vint64m4_t src) {
  // CHECK-LABEL: test_vcompress_vm_i64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vcompress.vm.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vcompress_vm_i64m4(mask, maskedoff, src);
}

vint64m8_t test_vcompress_vm_i64m8 (vbool8_t mask, vint64m8_t maskedoff, vint64m8_t src) {
  // CHECK-LABEL: test_vcompress_vm_i64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcompress.vm.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vcompress_vm_i64m8(mask, maskedoff, src);
}

vuint8mf8_t test_vcompress_vm_u8mf8 (vbool64_t mask, vuint8mf8_t maskedoff, vuint8mf8_t src) {
  // CHECK-LABEL: test_vcompress_vm_u8mf8
  // CHECK: %{{.*}} = call <vscale x 1 x i8> @llvm.riscv.vcompress.vm.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vcompress_vm_u8mf8(mask, maskedoff, src);
}

vuint8mf4_t test_vcompress_vm_u8mf4 (vbool32_t mask, vuint8mf4_t maskedoff, vuint8mf4_t src) {
  // CHECK-LABEL: test_vcompress_vm_u8mf4
  // CHECK: %{{.*}} = call <vscale x 2 x i8> @llvm.riscv.vcompress.vm.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vcompress_vm_u8mf4(mask, maskedoff, src);
}

vuint8mf2_t test_vcompress_vm_u8mf2 (vbool16_t mask, vuint8mf2_t maskedoff, vuint8mf2_t src) {
  // CHECK-LABEL: test_vcompress_vm_u8mf2
  // CHECK: %{{.*}} = call <vscale x 4 x i8> @llvm.riscv.vcompress.vm.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vcompress_vm_u8mf2(mask, maskedoff, src);
}

vuint8m1_t test_vcompress_vm_u8m1 (vbool8_t mask, vuint8m1_t maskedoff, vuint8m1_t src) {
  // CHECK-LABEL: test_vcompress_vm_u8m1
  // CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vcompress.vm.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vcompress_vm_u8m1(mask, maskedoff, src);
}

vuint8m2_t test_vcompress_vm_u8m2 (vbool4_t mask, vuint8m2_t maskedoff, vuint8m2_t src) {
  // CHECK-LABEL: test_vcompress_vm_u8m2
  // CHECK: %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vcompress.vm.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vcompress_vm_u8m2(mask, maskedoff, src);
}

vuint8m4_t test_vcompress_vm_u8m4 (vbool2_t mask, vuint8m4_t maskedoff, vuint8m4_t src) {
  // CHECK-LABEL: test_vcompress_vm_u8m4
  // CHECK: %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vcompress.vm.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vcompress_vm_u8m4(mask, maskedoff, src);
}

vuint8m8_t test_vcompress_vm_u8m8 (vbool1_t mask, vuint8m8_t maskedoff, vuint8m8_t src) {
  // CHECK-LABEL: test_vcompress_vm_u8m8
  // CHECK: %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vcompress.vm.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vcompress_vm_u8m8(mask, maskedoff, src);
}

vuint16mf4_t test_vcompress_vm_u16mf4 (vbool64_t mask, vuint16mf4_t maskedoff, vuint16mf4_t src) {
  // CHECK-LABEL: test_vcompress_vm_u16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x i16> @llvm.riscv.vcompress.vm.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vcompress_vm_u16mf4(mask, maskedoff, src);
}

vuint16mf2_t test_vcompress_vm_u16mf2 (vbool32_t mask, vuint16mf2_t maskedoff, vuint16mf2_t src) {
  // CHECK-LABEL: test_vcompress_vm_u16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x i16> @llvm.riscv.vcompress.vm.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vcompress_vm_u16mf2(mask, maskedoff, src);
}

vuint16m1_t test_vcompress_vm_u16m1 (vbool16_t mask, vuint16m1_t maskedoff, vuint16m1_t src) {
  // CHECK-LABEL: test_vcompress_vm_u16m1
  // CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vcompress.vm.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vcompress_vm_u16m1(mask, maskedoff, src);
}

vuint16m2_t test_vcompress_vm_u16m2 (vbool8_t mask, vuint16m2_t maskedoff, vuint16m2_t src) {
  // CHECK-LABEL: test_vcompress_vm_u16m2
  // CHECK: %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vcompress.vm.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vcompress_vm_u16m2(mask, maskedoff, src);
}

vuint16m4_t test_vcompress_vm_u16m4 (vbool4_t mask, vuint16m4_t maskedoff, vuint16m4_t src) {
  // CHECK-LABEL: test_vcompress_vm_u16m4
  // CHECK: %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vcompress.vm.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vcompress_vm_u16m4(mask, maskedoff, src);
}

vuint16m8_t test_vcompress_vm_u16m8 (vbool2_t mask, vuint16m8_t maskedoff, vuint16m8_t src) {
  // CHECK-LABEL: test_vcompress_vm_u16m8
  // CHECK: %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vcompress.vm.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vcompress_vm_u16m8(mask, maskedoff, src);
}

vuint32mf2_t test_vcompress_vm_u32mf2 (vbool64_t mask, vuint32mf2_t maskedoff, vuint32mf2_t src) {
  // CHECK-LABEL: test_vcompress_vm_u32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x i32> @llvm.riscv.vcompress.vm.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vcompress_vm_u32mf2(mask, maskedoff, src);
}

vuint32m1_t test_vcompress_vm_u32m1 (vbool32_t mask, vuint32m1_t maskedoff, vuint32m1_t src) {
  // CHECK-LABEL: test_vcompress_vm_u32m1
  // CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vcompress.vm.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vcompress_vm_u32m1(mask, maskedoff, src);
}

vuint32m2_t test_vcompress_vm_u32m2 (vbool16_t mask, vuint32m2_t maskedoff, vuint32m2_t src) {
  // CHECK-LABEL: test_vcompress_vm_u32m2
  // CHECK: %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vcompress.vm.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vcompress_vm_u32m2(mask, maskedoff, src);
}

vuint32m4_t test_vcompress_vm_u32m4 (vbool8_t mask, vuint32m4_t maskedoff, vuint32m4_t src) {
  // CHECK-LABEL: test_vcompress_vm_u32m4
  // CHECK: %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vcompress.vm.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vcompress_vm_u32m4(mask, maskedoff, src);
}

vuint32m8_t test_vcompress_vm_u32m8 (vbool4_t mask, vuint32m8_t maskedoff, vuint32m8_t src) {
  // CHECK-LABEL: test_vcompress_vm_u32m8
  // CHECK: %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vcompress.vm.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vcompress_vm_u32m8(mask, maskedoff, src);
}

vuint64m1_t test_vcompress_vm_u64m1 (vbool64_t mask, vuint64m1_t maskedoff, vuint64m1_t src) {
  // CHECK-LABEL: test_vcompress_vm_u64m1
  // CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vcompress.vm.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vcompress_vm_u64m1(mask, maskedoff, src);
}

vuint64m2_t test_vcompress_vm_u64m2 (vbool32_t mask, vuint64m2_t maskedoff, vuint64m2_t src) {
  // CHECK-LABEL: test_vcompress_vm_u64m2
  // CHECK: %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vcompress.vm.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vcompress_vm_u64m2(mask, maskedoff, src);
}

vuint64m4_t test_vcompress_vm_u64m4 (vbool16_t mask, vuint64m4_t maskedoff, vuint64m4_t src) {
  // CHECK-LABEL: test_vcompress_vm_u64m4
  // CHECK: %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vcompress.vm.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vcompress_vm_u64m4(mask, maskedoff, src);
}

vuint64m8_t test_vcompress_vm_u64m8 (vbool8_t mask, vuint64m8_t maskedoff, vuint64m8_t src) {
  // CHECK-LABEL: test_vcompress_vm_u64m8
  // CHECK: %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vcompress.vm.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vcompress_vm_u64m8(mask, maskedoff, src);
}

vfloat16mf4_t test_vcompress_vm_f16mf4 (vbool64_t mask, vfloat16mf4_t maskedoff, vfloat16mf4_t src) {
  // CHECK-LABEL: test_vcompress_vm_f16mf4
  // CHECK: %{{.*}} = call <vscale x 1 x half> @llvm.riscv.vcompress.vm.mask.nxv1f16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x half> %{{.*}}, <vscale x 1 x half> %{{.*}})
  return vcompress_vm_f16mf4(mask, maskedoff, src);
}

vfloat16mf2_t test_vcompress_vm_f16mf2 (vbool32_t mask, vfloat16mf2_t maskedoff, vfloat16mf2_t src) {
  // CHECK-LABEL: test_vcompress_vm_f16mf2
  // CHECK: %{{.*}} = call <vscale x 2 x half> @llvm.riscv.vcompress.vm.mask.nxv2f16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x half> %{{.*}}, <vscale x 2 x half> %{{.*}})
  return vcompress_vm_f16mf2(mask, maskedoff, src);
}

vfloat16m1_t test_vcompress_vm_f16m1 (vbool16_t mask, vfloat16m1_t maskedoff, vfloat16m1_t src) {
  // CHECK-LABEL: test_vcompress_vm_f16m1
  // CHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vcompress.vm.mask.nxv4f16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}})
  return vcompress_vm_f16m1(mask, maskedoff, src);
}

vfloat16m2_t test_vcompress_vm_f16m2 (vbool8_t mask, vfloat16m2_t maskedoff, vfloat16m2_t src) {
  // CHECK-LABEL: test_vcompress_vm_f16m2
  // CHECK: %{{.*}} = call <vscale x 8 x half> @llvm.riscv.vcompress.vm.mask.nxv8f16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x half> %{{.*}}, <vscale x 8 x half> %{{.*}})
  return vcompress_vm_f16m2(mask, maskedoff, src);
}

vfloat16m4_t test_vcompress_vm_f16m4 (vbool4_t mask, vfloat16m4_t maskedoff, vfloat16m4_t src) {
  // CHECK-LABEL: test_vcompress_vm_f16m4
  // CHECK: %{{.*}} = call <vscale x 16 x half> @llvm.riscv.vcompress.vm.mask.nxv16f16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x half> %{{.*}}, <vscale x 16 x half> %{{.*}})
  return vcompress_vm_f16m4(mask, maskedoff, src);
}

vfloat16m8_t test_vcompress_vm_f16m8 (vbool2_t mask, vfloat16m8_t maskedoff, vfloat16m8_t src) {
  // CHECK-LABEL: test_vcompress_vm_f16m8
  // CHECK: %{{.*}} = call <vscale x 32 x half> @llvm.riscv.vcompress.vm.mask.nxv32f16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x half> %{{.*}}, <vscale x 32 x half> %{{.*}})
  return vcompress_vm_f16m8(mask, maskedoff, src);
}

vfloat32mf2_t test_vcompress_vm_f32mf2 (vbool64_t mask, vfloat32mf2_t maskedoff, vfloat32mf2_t src) {
  // CHECK-LABEL: test_vcompress_vm_f32mf2
  // CHECK: %{{.*}} = call <vscale x 1 x float> @llvm.riscv.vcompress.vm.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x float> %{{.*}}, <vscale x 1 x float> %{{.*}})
  return vcompress_vm_f32mf2(mask, maskedoff, src);
}

vfloat32m1_t test_vcompress_vm_f32m1 (vbool32_t mask, vfloat32m1_t maskedoff, vfloat32m1_t src) {
  // CHECK-LABEL: test_vcompress_vm_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vcompress.vm.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}})
  return vcompress_vm_f32m1(mask, maskedoff, src);
}

vfloat32m2_t test_vcompress_vm_f32m2 (vbool16_t mask, vfloat32m2_t maskedoff, vfloat32m2_t src) {
  // CHECK-LABEL: test_vcompress_vm_f32m2
  // CHECK: %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vcompress.vm.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x float> %{{.*}}, <vscale x 4 x float> %{{.*}})
  return vcompress_vm_f32m2(mask, maskedoff, src);
}

vfloat32m4_t test_vcompress_vm_f32m4 (vbool8_t mask, vfloat32m4_t maskedoff, vfloat32m4_t src) {
  // CHECK-LABEL: test_vcompress_vm_f32m4
  // CHECK: %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vcompress.vm.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x float> %{{.*}}, <vscale x 8 x float> %{{.*}})
  return vcompress_vm_f32m4(mask, maskedoff, src);
}

vfloat32m8_t test_vcompress_vm_f32m8 (vbool4_t mask, vfloat32m8_t maskedoff, vfloat32m8_t src) {
  // CHECK-LABEL: test_vcompress_vm_f32m8
  // CHECK: %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vcompress.vm.mask.nxv16f32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x float> %{{.*}}, <vscale x 16 x float> %{{.*}})
  return vcompress_vm_f32m8(mask, maskedoff, src);
}

vfloat64m1_t test_vcompress_vm_f64m1 (vbool64_t mask, vfloat64m1_t maskedoff, vfloat64m1_t src) {
  // CHECK-LABEL: test_vcompress_vm_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vcompress.vm.mask.nxv1f32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}})
  return vcompress_vm_f64m1(mask, maskedoff, src);
}

vfloat64m2_t test_vcompress_vm_f64m2 (vbool32_t mask, vfloat64m2_t maskedoff, vfloat64m2_t src) {
  // CHECK-LABEL: test_vcompress_vm_f64m2
  // CHECK: %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vcompress.vm.mask.nxv2f32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x double> %{{.*}}, <vscale x 2 x double> %{{.*}})
  return vcompress_vm_f64m2(mask, maskedoff, src);
}

vfloat64m4_t test_vcompress_vm_f64m4 (vbool16_t mask, vfloat64m4_t maskedoff, vfloat64m4_t src) {
  // CHECK-LABEL: test_vcompress_vm_f64m4
  // CHECK: %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vcompress.vm.mask.nxv4f32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x double> %{{.*}}, <vscale x 4 x double> %{{.*}})
  return vcompress_vm_f64m4(mask, maskedoff, src);
}

vfloat64m8_t test_vcompress_vm_f64m8 (vbool8_t mask, vfloat64m8_t maskedoff, vfloat64m8_t src) {
  // CHECK-LABEL: test_vcompress_vm_f64m8
  // CHECK: %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vcompress.vm.mask.nxv8f32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x double> %{{.*}}, <vscale x 8 x double> %{{.*}})
  return vcompress_vm_f64m8(mask, maskedoff, src);
}

