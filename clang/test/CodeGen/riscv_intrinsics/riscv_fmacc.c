// RUN: %clang --target=riscv64-unknown-linux-elf -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <riscv_vector.h>

//vfloat16m1_t  __attribute__((noinline)) testfdiv16(vfloat16m1_t value1,  half op1, vfloat16m1_t value2) {
//  return vfmacc_vf_f16m1(value1, op1, value2);
//}

vfloat32m1_t  __attribute__((noinline)) testfdiv32(vfloat32m1_t value1, float op1, vfloat32m1_t value2) {
  return vfmacc_vf_f32m1(value1, op1, value2);
}

vfloat64m1_t  __attribute__((noinline)) testfdiv64(vfloat64m1_t value1, double op1,  vfloat64m1_t value2) {
  return vfmacc_vf_f64m1(value1, op1, value2);
}

//CHECK: %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmacc.vf.nxv2f32.nxv2f32.f32.nxv2f32(<vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}}) #{{.*}}
//CHECK: %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfmacc.vf.nxv1f64.nxv1f64.f64.nxv1f64(<vscale x 1 x double> %{{.*}}, double %{{.*}}, <vscale x 1 x double> %{{.*}}) #{{.*}}
