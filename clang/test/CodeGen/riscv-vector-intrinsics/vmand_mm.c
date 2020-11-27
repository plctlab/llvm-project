// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -fallow-half-arguments-and-returns -fnative-half-type -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vbool1_t test_vmand_mm_b1 (vbool1_t op1, vbool1_t op2) {
  // CHECK-LABEL: test_vmand_mm_b1
  // CHECK: %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmand.mm.{{.*}}nxv64i1{{.*}}(<vscale x 64 x i1> %{{.*}}, <vscale x 64 x i1> %{{.*}})
  return vmand_mm_b1(op1, op2);
}

vbool2_t test_vmand_mm_b2 (vbool2_t op1, vbool2_t op2) {
  // CHECK-LABEL: test_vmand_mm_b2
  // CHECK: %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmand.mm.{{.*}}nxv32i1{{.*}}(<vscale x 32 x i1> %{{.*}}, <vscale x 32 x i1> %{{.*}})
  return vmand_mm_b2(op1, op2);
}

vbool4_t test_vmand_mm_b4 (vbool4_t op1, vbool4_t op2) {
  // CHECK-LABEL: test_vmand_mm_b4
  // CHECK: %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmand.mm.{{.*}}nxv16i1{{.*}}(<vscale x 16 x i1> %{{.*}}, <vscale x 16 x i1> %{{.*}})
  return vmand_mm_b4(op1, op2);
}

vbool8_t test_vmand_mm_b8 (vbool8_t op1, vbool8_t op2) {
  // CHECK-LABEL: test_vmand_mm_b8
  // CHECK: %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmand.mm.{{.*}}nxv8i1{{.*}}(<vscale x 8 x i1> %{{.*}}, <vscale x 8 x i1> %{{.*}})
  return vmand_mm_b8(op1, op2);
}

vbool16_t test_vmand_mm_b16 (vbool16_t op1, vbool16_t op2) {
  // CHECK-LABEL: test_vmand_mm_b16
  // CHECK: %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmand.mm.{{.*}}nxv4i1{{.*}}(<vscale x 4 x i1> %{{.*}}, <vscale x 4 x i1> %{{.*}})
  return vmand_mm_b16(op1, op2);
}

vbool32_t test_vmand_mm_b32 (vbool32_t op1, vbool32_t op2) {
  // CHECK-LABEL: test_vmand_mm_b32
  // CHECK: %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmand.mm.{{.*}}nxv2i1{{.*}}(<vscale x 2 x i1> %{{.*}}, <vscale x 2 x i1> %{{.*}})
  return vmand_mm_b32(op1, op2);
}

vbool64_t test_vmand_mm_b64 (vbool64_t op1, vbool64_t op2) {
  // CHECK-LABEL: test_vmand_mm_b64
  // CHECK: %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmand.mm.{{.*}}nxv1i1{{.*}}(<vscale x 1 x i1> %{{.*}}, <vscale x 1 x i1> %{{.*}})
  return vmand_mm_b64(op1, op2);
}

