// UNSUPPORTED: x86_64-unknown-linux-gnu
// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vbool1_t test_vmnot_m_b1 (vbool1_t op1) {
  // CHECK-LABEL: test_vmnot_m_b1
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmnot.{{.*}}(<vscale x 64 x i1> %{{.*}})
  return vmnot_m_b1(op1);
}

vbool2_t test_vmnot_m_b2 (vbool2_t op1) {
  // CHECK-LABEL: test_vmnot_m_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmnot.{{.*}}(<vscale x 32 x i1> %{{.*}})
  return vmnot_m_b2(op1);
}

vbool4_t test_vmnot_m_b4 (vbool4_t op1) {
  // CHECK-LABEL: test_vmnot_m_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmnot.{{.*}}(<vscale x 16 x i1> %{{.*}})
  return vmnot_m_b4(op1);
}

vbool8_t test_vmnot_m_b8 (vbool8_t op1) {
  // CHECK-LABEL: test_vmnot_m_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmnot.{{.*}}(<vscale x 8 x i1> %{{.*}})
  return vmnot_m_b8(op1);
}

vbool16_t test_vmnot_m_b16 (vbool16_t op1) {
  // CHECK-LABEL: test_vmnot_m_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmnot.{{.*}}(<vscale x 4 x i1> %{{.*}})
  return vmnot_m_b16(op1);
}

vbool32_t test_vmnot_m_b32 (vbool32_t op1) {
  // CHECK-LABEL: test_vmnot_m_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmnot.{{.*}}(<vscale x 2 x i1> %{{.*}})
  return vmnot_m_b32(op1);
}

vbool64_t test_vmnot_m_b64 (vbool64_t op1) {
  // CHECK-LABEL: test_vmnot_m_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmnot.{{.*}}(<vscale x 1 x i1> %{{.*}})
  return vmnot_m_b64(op1);
}

