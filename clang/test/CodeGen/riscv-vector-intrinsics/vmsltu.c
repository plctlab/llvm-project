// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vbool64_t test_vmsltu_vv_u8mf8_b64 (vuint8mf8_t op1, vuint8mf8_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u8mf8_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vv.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vmsltu_vv_u8mf8_b64(op1, op2);
}

vbool64_t test_vmsltu_vx_u8mf8_b64 (vuint8mf8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u8mf8_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vx.nxv1i8{{.*}}(<vscale x 1 x i8> %{{.*}}, i8 %{{.*}})
  return vmsltu_vx_u8mf8_b64(op1, op2);
}

vbool32_t test_vmsltu_vv_u8mf4_b32 (vuint8mf4_t op1, vuint8mf4_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u8mf4_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vv.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vmsltu_vv_u8mf4_b32(op1, op2);
}

vbool32_t test_vmsltu_vx_u8mf4_b32 (vuint8mf4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u8mf4_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vx.nxv2i8{{.*}}(<vscale x 2 x i8> %{{.*}}, i8 %{{.*}})
  return vmsltu_vx_u8mf4_b32(op1, op2);
}

vbool16_t test_vmsltu_vv_u8mf2_b16 (vuint8mf2_t op1, vuint8mf2_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u8mf2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vv.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vmsltu_vv_u8mf2_b16(op1, op2);
}

vbool16_t test_vmsltu_vx_u8mf2_b16 (vuint8mf2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u8mf2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vx.nxv4i8{{.*}}(<vscale x 4 x i8> %{{.*}}, i8 %{{.*}})
  return vmsltu_vx_u8mf2_b16(op1, op2);
}

vbool8_t test_vmsltu_vv_u8m1_b8 (vuint8m1_t op1, vuint8m1_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u8m1_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vv.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vmsltu_vv_u8m1_b8(op1, op2);
}

vbool8_t test_vmsltu_vx_u8m1_b8 (vuint8m1_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u8m1_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vx.nxv8i8{{.*}}(<vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vmsltu_vx_u8m1_b8(op1, op2);
}

vbool4_t test_vmsltu_vv_u8m2_b4 (vuint8m2_t op1, vuint8m2_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u8m2_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmsltu.vv.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vmsltu_vv_u8m2_b4(op1, op2);
}

vbool4_t test_vmsltu_vx_u8m2_b4 (vuint8m2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u8m2_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmsltu.vx.nxv16i8{{.*}}(<vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vmsltu_vx_u8m2_b4(op1, op2);
}

vbool2_t test_vmsltu_vv_u8m4_b2 (vuint8m4_t op1, vuint8m4_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u8m4_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmsltu.vv.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vmsltu_vv_u8m4_b2(op1, op2);
}

vbool2_t test_vmsltu_vx_u8m4_b2 (vuint8m4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u8m4_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmsltu.vx.nxv32i8{{.*}}(<vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vmsltu_vx_u8m4_b2(op1, op2);
}

vbool1_t test_vmsltu_vv_u8m8_b1 (vuint8m8_t op1, vuint8m8_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u8m8_b1
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmsltu.vv.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vmsltu_vv_u8m8_b1(op1, op2);
}

vbool1_t test_vmsltu_vx_u8m8_b1 (vuint8m8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u8m8_b1
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmsltu.vx.nxv64i8{{.*}}(<vscale x 64 x i8> %{{.*}}, i8 %{{.*}})
  return vmsltu_vx_u8m8_b1(op1, op2);
}

vbool64_t test_vmsltu_vv_u16mf4_b64 (vuint16mf4_t op1, vuint16mf4_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u16mf4_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vv.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vmsltu_vv_u16mf4_b64(op1, op2);
}

vbool64_t test_vmsltu_vx_u16mf4_b64 (vuint16mf4_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u16mf4_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vx.nxv1i16{{.*}}(<vscale x 1 x i16> %{{.*}}, i16 %{{.*}})
  return vmsltu_vx_u16mf4_b64(op1, op2);
}

vbool32_t test_vmsltu_vv_u16mf2_b32 (vuint16mf2_t op1, vuint16mf2_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u16mf2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vv.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vmsltu_vv_u16mf2_b32(op1, op2);
}

vbool32_t test_vmsltu_vx_u16mf2_b32 (vuint16mf2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u16mf2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vx.nxv2i16{{.*}}(<vscale x 2 x i16> %{{.*}}, i16 %{{.*}})
  return vmsltu_vx_u16mf2_b32(op1, op2);
}

vbool16_t test_vmsltu_vv_u16m1_b16 (vuint16m1_t op1, vuint16m1_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u16m1_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vv.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vmsltu_vv_u16m1_b16(op1, op2);
}

vbool16_t test_vmsltu_vx_u16m1_b16 (vuint16m1_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u16m1_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vx.nxv4i16{{.*}}(<vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vmsltu_vx_u16m1_b16(op1, op2);
}

vbool8_t test_vmsltu_vv_u16m2_b8 (vuint16m2_t op1, vuint16m2_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u16m2_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vv.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vmsltu_vv_u16m2_b8(op1, op2);
}

vbool8_t test_vmsltu_vx_u16m2_b8 (vuint16m2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u16m2_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vx.nxv8i16{{.*}}(<vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vmsltu_vx_u16m2_b8(op1, op2);
}

vbool4_t test_vmsltu_vv_u16m4_b4 (vuint16m4_t op1, vuint16m4_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u16m4_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmsltu.vv.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vmsltu_vv_u16m4_b4(op1, op2);
}

vbool4_t test_vmsltu_vx_u16m4_b4 (vuint16m4_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u16m4_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmsltu.vx.nxv16i16{{.*}}(<vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vmsltu_vx_u16m4_b4(op1, op2);
}

vbool2_t test_vmsltu_vv_u16m8_b2 (vuint16m8_t op1, vuint16m8_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u16m8_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmsltu.vv.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vmsltu_vv_u16m8_b2(op1, op2);
}

vbool2_t test_vmsltu_vx_u16m8_b2 (vuint16m8_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u16m8_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmsltu.vx.nxv32i16{{.*}}(<vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vmsltu_vx_u16m8_b2(op1, op2);
}

vbool64_t test_vmsltu_vv_u32mf2_b64 (vuint32mf2_t op1, vuint32mf2_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u32mf2_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vv.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vmsltu_vv_u32mf2_b64(op1, op2);
}

vbool64_t test_vmsltu_vx_u32mf2_b64 (vuint32mf2_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u32mf2_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vx.nxv1i32{{.*}}(<vscale x 1 x i32> %{{.*}}, i32 %{{.*}})
  return vmsltu_vx_u32mf2_b64(op1, op2);
}

vbool32_t test_vmsltu_vv_u32m1_b32 (vuint32m1_t op1, vuint32m1_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u32m1_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vv.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vmsltu_vv_u32m1_b32(op1, op2);
}

vbool32_t test_vmsltu_vx_u32m1_b32 (vuint32m1_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u32m1_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vx.nxv2i32{{.*}}(<vscale x 2 x i32> %{{.*}}, i32 %{{.*}})
  return vmsltu_vx_u32m1_b32(op1, op2);
}

vbool16_t test_vmsltu_vv_u32m2_b16 (vuint32m2_t op1, vuint32m2_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u32m2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vv.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vmsltu_vv_u32m2_b16(op1, op2);
}

vbool16_t test_vmsltu_vx_u32m2_b16 (vuint32m2_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u32m2_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vx.nxv4i32{{.*}}(<vscale x 4 x i32> %{{.*}}, i32 %{{.*}})
  return vmsltu_vx_u32m2_b16(op1, op2);
}

vbool8_t test_vmsltu_vv_u32m4_b8 (vuint32m4_t op1, vuint32m4_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u32m4_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vv.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vmsltu_vv_u32m4_b8(op1, op2);
}

vbool8_t test_vmsltu_vx_u32m4_b8 (vuint32m4_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u32m4_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vx.nxv8i32{{.*}}(<vscale x 8 x i32> %{{.*}}, i32 %{{.*}})
  return vmsltu_vx_u32m4_b8(op1, op2);
}

vbool4_t test_vmsltu_vv_u32m8_b4 (vuint32m8_t op1, vuint32m8_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u32m8_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmsltu.vv.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vmsltu_vv_u32m8_b4(op1, op2);
}

vbool4_t test_vmsltu_vx_u32m8_b4 (vuint32m8_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u32m8_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmsltu.vx.nxv16i32{{.*}}(<vscale x 16 x i32> %{{.*}}, i32 %{{.*}})
  return vmsltu_vx_u32m8_b4(op1, op2);
}

vbool64_t test_vmsltu_vv_u64m1_b64 (vuint64m1_t op1, vuint64m1_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u64m1_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vv.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vmsltu_vv_u64m1_b64(op1, op2);
}

vbool64_t test_vmsltu_vx_u64m1_b64 (vuint64m1_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u64m1_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vx.nxv1i64{{.*}}(<vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vmsltu_vx_u64m1_b64(op1, op2);
}

vbool32_t test_vmsltu_vv_u64m2_b32 (vuint64m2_t op1, vuint64m2_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u64m2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vv.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vmsltu_vv_u64m2_b32(op1, op2);
}

vbool32_t test_vmsltu_vx_u64m2_b32 (vuint64m2_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u64m2_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vx.nxv2i64{{.*}}(<vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vmsltu_vx_u64m2_b32(op1, op2);
}

vbool16_t test_vmsltu_vv_u64m4_b16 (vuint64m4_t op1, vuint64m4_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u64m4_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vv.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vmsltu_vv_u64m4_b16(op1, op2);
}

vbool16_t test_vmsltu_vx_u64m4_b16 (vuint64m4_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u64m4_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vx.nxv4i64{{.*}}(<vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vmsltu_vx_u64m4_b16(op1, op2);
}

vbool8_t test_vmsltu_vv_u64m8_b8 (vuint64m8_t op1, vuint64m8_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u64m8_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vv.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vmsltu_vv_u64m8_b8(op1, op2);
}

vbool8_t test_vmsltu_vx_u64m8_b8 (vuint64m8_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u64m8_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vx.nxv8i64{{.*}}(<vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vmsltu_vx_u64m8_b8(op1, op2);
}

vbool64_t test_vmsltu_vv_u8mf8_b64_m (vbool64_t mask, vbool64_t maskedoff, vuint8mf8_t op1, vuint8mf8_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u8mf8_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vv.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, <vscale x 1 x i8> %{{.*}})
  return vmsltu_vv_u8mf8_b64_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmsltu_vx_u8mf8_b64_m (vbool64_t mask, vbool64_t maskedoff, vuint8mf8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u8mf8_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vx.mask.nxv1i8{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i8> %{{.*}}, i8 %{{.*}})
  return vmsltu_vx_u8mf8_b64_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmsltu_vv_u8mf4_b32_m (vbool32_t mask, vbool32_t maskedoff, vuint8mf4_t op1, vuint8mf4_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u8mf4_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vv.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, <vscale x 2 x i8> %{{.*}})
  return vmsltu_vv_u8mf4_b32_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmsltu_vx_u8mf4_b32_m (vbool32_t mask, vbool32_t maskedoff, vuint8mf4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u8mf4_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vx.mask.nxv2i8{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i8> %{{.*}}, i8 %{{.*}})
  return vmsltu_vx_u8mf4_b32_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmsltu_vv_u8mf2_b16_m (vbool16_t mask, vbool16_t maskedoff, vuint8mf2_t op1, vuint8mf2_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u8mf2_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vv.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, <vscale x 4 x i8> %{{.*}})
  return vmsltu_vv_u8mf2_b16_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmsltu_vx_u8mf2_b16_m (vbool16_t mask, vbool16_t maskedoff, vuint8mf2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u8mf2_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vx.mask.nxv4i8{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i8> %{{.*}}, i8 %{{.*}})
  return vmsltu_vx_u8mf2_b16_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmsltu_vv_u8m1_b8_m (vbool8_t mask, vbool8_t maskedoff, vuint8m1_t op1, vuint8m1_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u8m1_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vv.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
  return vmsltu_vv_u8m1_b8_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmsltu_vx_u8m1_b8_m (vbool8_t mask, vbool8_t maskedoff, vuint8m1_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u8m1_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vx.mask.nxv8i8{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i8> %{{.*}}, i8 %{{.*}})
  return vmsltu_vx_u8m1_b8_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmsltu_vv_u8m2_b4_m (vbool4_t mask, vbool4_t maskedoff, vuint8m2_t op1, vuint8m2_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u8m2_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmsltu.vv.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
  return vmsltu_vv_u8m2_b4_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmsltu_vx_u8m2_b4_m (vbool4_t mask, vbool4_t maskedoff, vuint8m2_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u8m2_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmsltu.vx.mask.nxv16i8{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x i8> %{{.*}}, i8 %{{.*}})
  return vmsltu_vx_u8m2_b4_m(mask, maskedoff, op1, op2);
}

vbool2_t test_vmsltu_vv_u8m4_b2_m (vbool2_t mask, vbool2_t maskedoff, vuint8m4_t op1, vuint8m4_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u8m4_b2_m
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmsltu.vv.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
  return vmsltu_vv_u8m4_b2_m(mask, maskedoff, op1, op2);
}

vbool2_t test_vmsltu_vx_u8m4_b2_m (vbool2_t mask, vbool2_t maskedoff, vuint8m4_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u8m4_b2_m
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmsltu.vx.mask.nxv32i8{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i1> %{{.*}}, <vscale x 32 x i8> %{{.*}}, i8 %{{.*}})
  return vmsltu_vx_u8m4_b2_m(mask, maskedoff, op1, op2);
}

vbool1_t test_vmsltu_vv_u8m8_b1_m (vbool1_t mask, vbool1_t maskedoff, vuint8m8_t op1, vuint8m8_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u8m8_b1_m
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmsltu.vv.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
  return vmsltu_vv_u8m8_b1_m(mask, maskedoff, op1, op2);
}

vbool1_t test_vmsltu_vx_u8m8_b1_m (vbool1_t mask, vbool1_t maskedoff, vuint8m8_t op1, uint8_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u8m8_b1_m
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmsltu.vx.mask.nxv64i8{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i1> %{{.*}}, <vscale x 64 x i8> %{{.*}}, i8 %{{.*}})
  return vmsltu_vx_u8m8_b1_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmsltu_vv_u16mf4_b64_m (vbool64_t mask, vbool64_t maskedoff, vuint16mf4_t op1, vuint16mf4_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u16mf4_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vv.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, <vscale x 1 x i16> %{{.*}})
  return vmsltu_vv_u16mf4_b64_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmsltu_vx_u16mf4_b64_m (vbool64_t mask, vbool64_t maskedoff, vuint16mf4_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u16mf4_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vx.mask.nxv1i16{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i16> %{{.*}}, i16 %{{.*}})
  return vmsltu_vx_u16mf4_b64_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmsltu_vv_u16mf2_b32_m (vbool32_t mask, vbool32_t maskedoff, vuint16mf2_t op1, vuint16mf2_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u16mf2_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vv.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, <vscale x 2 x i16> %{{.*}})
  return vmsltu_vv_u16mf2_b32_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmsltu_vx_u16mf2_b32_m (vbool32_t mask, vbool32_t maskedoff, vuint16mf2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u16mf2_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vx.mask.nxv2i16{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i16> %{{.*}}, i16 %{{.*}})
  return vmsltu_vx_u16mf2_b32_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmsltu_vv_u16m1_b16_m (vbool16_t mask, vbool16_t maskedoff, vuint16m1_t op1, vuint16m1_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u16m1_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vv.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
  return vmsltu_vv_u16m1_b16_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmsltu_vx_u16m1_b16_m (vbool16_t mask, vbool16_t maskedoff, vuint16m1_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u16m1_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vx.mask.nxv4i16{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i16> %{{.*}}, i16 %{{.*}})
  return vmsltu_vx_u16m1_b16_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmsltu_vv_u16m2_b8_m (vbool8_t mask, vbool8_t maskedoff, vuint16m2_t op1, vuint16m2_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u16m2_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vv.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
  return vmsltu_vv_u16m2_b8_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmsltu_vx_u16m2_b8_m (vbool8_t mask, vbool8_t maskedoff, vuint16m2_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u16m2_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vx.mask.nxv8i16{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i16> %{{.*}}, i16 %{{.*}})
  return vmsltu_vx_u16m2_b8_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmsltu_vv_u16m4_b4_m (vbool4_t mask, vbool4_t maskedoff, vuint16m4_t op1, vuint16m4_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u16m4_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmsltu.vv.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
  return vmsltu_vv_u16m4_b4_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmsltu_vx_u16m4_b4_m (vbool4_t mask, vbool4_t maskedoff, vuint16m4_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u16m4_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmsltu.vx.mask.nxv16i16{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x i16> %{{.*}}, i16 %{{.*}})
  return vmsltu_vx_u16m4_b4_m(mask, maskedoff, op1, op2);
}

vbool2_t test_vmsltu_vv_u16m8_b2_m (vbool2_t mask, vbool2_t maskedoff, vuint16m8_t op1, vuint16m8_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u16m8_b2_m
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmsltu.vv.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
  return vmsltu_vv_u16m8_b2_m(mask, maskedoff, op1, op2);
}

vbool2_t test_vmsltu_vx_u16m8_b2_m (vbool2_t mask, vbool2_t maskedoff, vuint16m8_t op1, uint16_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u16m8_b2_m
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmsltu.vx.mask.nxv32i16{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i1> %{{.*}}, <vscale x 32 x i16> %{{.*}}, i16 %{{.*}})
  return vmsltu_vx_u16m8_b2_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmsltu_vv_u32mf2_b64_m (vbool64_t mask, vbool64_t maskedoff, vuint32mf2_t op1, vuint32mf2_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u32mf2_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vv.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
  return vmsltu_vv_u32mf2_b64_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmsltu_vx_u32mf2_b64_m (vbool64_t mask, vbool64_t maskedoff, vuint32mf2_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u32mf2_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vx.mask.nxv1i32{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i32> %{{.*}}, i32 %{{.*}})
  return vmsltu_vx_u32mf2_b64_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmsltu_vv_u32m1_b32_m (vbool32_t mask, vbool32_t maskedoff, vuint32m1_t op1, vuint32m1_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u32m1_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vv.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
  return vmsltu_vv_u32m1_b32_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmsltu_vx_u32m1_b32_m (vbool32_t mask, vbool32_t maskedoff, vuint32m1_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u32m1_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vx.mask.nxv2i32{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i32> %{{.*}}, i32 %{{.*}})
  return vmsltu_vx_u32m1_b32_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmsltu_vv_u32m2_b16_m (vbool16_t mask, vbool16_t maskedoff, vuint32m2_t op1, vuint32m2_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u32m2_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vv.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
  return vmsltu_vv_u32m2_b16_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmsltu_vx_u32m2_b16_m (vbool16_t mask, vbool16_t maskedoff, vuint32m2_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u32m2_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vx.mask.nxv4i32{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i32> %{{.*}}, i32 %{{.*}})
  return vmsltu_vx_u32m2_b16_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmsltu_vv_u32m4_b8_m (vbool8_t mask, vbool8_t maskedoff, vuint32m4_t op1, vuint32m4_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u32m4_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vv.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
  return vmsltu_vv_u32m4_b8_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmsltu_vx_u32m4_b8_m (vbool8_t mask, vbool8_t maskedoff, vuint32m4_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u32m4_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vx.mask.nxv8i32{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i32> %{{.*}}, i32 %{{.*}})
  return vmsltu_vx_u32m4_b8_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmsltu_vv_u32m8_b4_m (vbool4_t mask, vbool4_t maskedoff, vuint32m8_t op1, vuint32m8_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u32m8_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmsltu.vv.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
  return vmsltu_vv_u32m8_b4_m(mask, maskedoff, op1, op2);
}

vbool4_t test_vmsltu_vx_u32m8_b4_m (vbool4_t mask, vbool4_t maskedoff, vuint32m8_t op1, uint32_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u32m8_b4_m
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmsltu.vx.mask.nxv16i32{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}}, <vscale x 16 x i32> %{{.*}}, i32 %{{.*}})
  return vmsltu_vx_u32m8_b4_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmsltu_vv_u64m1_b64_m (vbool64_t mask, vbool64_t maskedoff, vuint64m1_t op1, vuint64m1_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u64m1_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vv.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
  return vmsltu_vv_u64m1_b64_m(mask, maskedoff, op1, op2);
}

vbool64_t test_vmsltu_vx_u64m1_b64_m (vbool64_t mask, vbool64_t maskedoff, vuint64m1_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u64m1_b64_m
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsltu.vx.mask.nxv1i64{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}}, <vscale x 1 x i64> %{{.*}}, i64 %{{.*}})
  return vmsltu_vx_u64m1_b64_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmsltu_vv_u64m2_b32_m (vbool32_t mask, vbool32_t maskedoff, vuint64m2_t op1, vuint64m2_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u64m2_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vv.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
  return vmsltu_vv_u64m2_b32_m(mask, maskedoff, op1, op2);
}

vbool32_t test_vmsltu_vx_u64m2_b32_m (vbool32_t mask, vbool32_t maskedoff, vuint64m2_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u64m2_b32_m
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsltu.vx.mask.nxv2i64{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}}, <vscale x 2 x i64> %{{.*}}, i64 %{{.*}})
  return vmsltu_vx_u64m2_b32_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmsltu_vv_u64m4_b16_m (vbool16_t mask, vbool16_t maskedoff, vuint64m4_t op1, vuint64m4_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u64m4_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vv.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
  return vmsltu_vv_u64m4_b16_m(mask, maskedoff, op1, op2);
}

vbool16_t test_vmsltu_vx_u64m4_b16_m (vbool16_t mask, vbool16_t maskedoff, vuint64m4_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u64m4_b16_m
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsltu.vx.mask.nxv4i64{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}}, <vscale x 4 x i64> %{{.*}}, i64 %{{.*}})
  return vmsltu_vx_u64m4_b16_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmsltu_vv_u64m8_b8_m (vbool8_t mask, vbool8_t maskedoff, vuint64m8_t op1, vuint64m8_t op2) {
  // CHECK-LABEL: test_vmsltu_vv_u64m8_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vv.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
  return vmsltu_vv_u64m8_b8_m(mask, maskedoff, op1, op2);
}

vbool8_t test_vmsltu_vx_u64m8_b8_m (vbool8_t mask, vbool8_t maskedoff, vuint64m8_t op1, uint64_t op2) {
  // CHECK-LABEL: test_vmsltu_vx_u64m8_b8_m
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsltu.vx.mask.nxv8i64{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}}, <vscale x 8 x i64> %{{.*}}, i64 %{{.*}})
  return vmsltu_vx_u64m8_b8_m(mask, maskedoff, op1, op2);
}

