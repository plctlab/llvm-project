// RUN: %clang_cc1 -triple riscv64-unknown-linux-elf -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

//vfloat16m1_t test_vfadd_vv_f16m1(vfloat16m1_t value1, vfloat16m1_t value2) {
//  // cHECK-LABEL: test_vfadd_vv_f16m1
//  // cHECK: %{{.*}} = call <vscale x 4 x half> @llvm.riscv.vfadd.vv.nxv4f16(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}) 
//  return vfadd_vv_f16m1(value1, value2);
//}

vfloat32m1_t test_vfadd_vv_f32m1(vfloat32m1_t value1, vfloat32m1_t value2) {
  // CHECK-LABEL: test_vfadd_vv_f32m1
  // CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfadd.vv.nxv2f32(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}) 
  return vfadd_vv_f32m1(value1, value2);
}

vfloat64m1_t test_vfadd_vv_f64m1(vfloat64m1_t value1, vfloat64m1_t value2) {
  // CHECK-LABEL: test_vfadd_vv_f64m1
  // CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfadd.vv.nxv1f64(<vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}) 
  return vfadd_vv_f64m1(value1, value2);
}

