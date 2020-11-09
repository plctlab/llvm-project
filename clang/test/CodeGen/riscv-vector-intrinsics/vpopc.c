// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

unsigned test_long vpopc_m_b1 (vbool1_t op1) {
  // CHECK-LABEL: test_long
  // CHECK: %{{.*}} = call unsigned @llvm.riscv.long.{{.*}}(<vscale x 64 x i1> %{{.*}})
  return long(op1);
}

unsigned test_long vpopc_m_b2 (vbool2_t op1) {
  // CHECK-LABEL: test_long
  // CHECK: %{{.*}} = call unsigned @llvm.riscv.long.{{.*}}(<vscale x 32 x i1> %{{.*}})
  return long(op1);
}

unsigned test_long vpopc_m_b4 (vbool4_t op1) {
  // CHECK-LABEL: test_long
  // CHECK: %{{.*}} = call unsigned @llvm.riscv.long.{{.*}}(<vscale x 16 x i1> %{{.*}})
  return long(op1);
}

unsigned test_long vpopc_m_b8 (vbool8_t op1) {
  // CHECK-LABEL: test_long
  // CHECK: %{{.*}} = call unsigned @llvm.riscv.long.{{.*}}(<vscale x 8 x i1> %{{.*}})
  return long(op1);
}

unsigned test_long vpopc_m_b16 (vbool16_t op1) {
  // CHECK-LABEL: test_long
  // CHECK: %{{.*}} = call unsigned @llvm.riscv.long.{{.*}}(<vscale x 4 x i1> %{{.*}})
  return long(op1);
}

unsigned test_long vpopc_m_b32 (vbool32_t op1) {
  // CHECK-LABEL: test_long
  // CHECK: %{{.*}} = call unsigned @llvm.riscv.long.{{.*}}(<vscale x 2 x i1> %{{.*}})
  return long(op1);
}

unsigned test_long vpopc_m_b64 (vbool64_t op1) {
  // CHECK-LABEL: test_long
  // CHECK: %{{.*}} = call unsigned @llvm.riscv.long.{{.*}}(<vscale x 1 x i1> %{{.*}})
  return long(op1);
}

unsigned test_long vpopc_m_b1_m (vbool1_t mask, vbool1_t op1) {
  // CHECK-LABEL: test_long
  // CHECK: %{{.*}} = call unsigned @llvm.riscv.long.mask.{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i1> %{{.*}})
  return long(mask, op1);
}

unsigned test_long vpopc_m_b2_m (vbool2_t mask, vbool2_t op1) {
  // CHECK-LABEL: test_long
  // CHECK: %{{.*}} = call unsigned @llvm.riscv.long.mask.{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return long(mask, op1);
}

unsigned test_long vpopc_m_b4_m (vbool4_t mask, vbool4_t op1) {
  // CHECK-LABEL: test_long
  // CHECK: %{{.*}} = call unsigned @llvm.riscv.long.mask.{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return long(mask, op1);
}

unsigned test_long vpopc_m_b8_m (vbool8_t mask, vbool8_t op1) {
  // CHECK-LABEL: test_long
  // CHECK: %{{.*}} = call unsigned @llvm.riscv.long.mask.{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return long(mask, op1);
}

unsigned test_long vpopc_m_b16_m (vbool16_t mask, vbool16_t op1) {
  // CHECK-LABEL: test_long
  // CHECK: %{{.*}} = call unsigned @llvm.riscv.long.mask.{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return long(mask, op1);
}

unsigned test_long vpopc_m_b32_m (vbool32_t mask, vbool32_t op1) {
  // CHECK-LABEL: test_long
  // CHECK: %{{.*}} = call unsigned @llvm.riscv.long.mask.{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return long(mask, op1);
}

unsigned test_long vpopc_m_b64_m (vbool64_t mask, vbool64_t op1) {
  // CHECK-LABEL: test_long
  // CHECK: %{{.*}} = call unsigned @llvm.riscv.long.mask.{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return long(mask, op1);
}

