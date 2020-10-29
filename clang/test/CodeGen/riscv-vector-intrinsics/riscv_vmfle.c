// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>

#include <riscv_vector.h>

//vbool16_t  __attribute__((noinline)) testfadd16(vfloat16m1_t value1, vfloat16m1_t value2) {
//  return vmfle_vv_f16m1_b16(value1, value2);
//}

vbool32_t  __attribute__((noinline)) testfadd32(vfloat32m1_t value1, vfloat32m1_t value2) {
  return vmfle_vv_f32m1_b32(value1, value2);
}

vbool64_t __attribute__((noinline)) testfadd64(vfloat64m1_t value1, vfloat64m1_t value2) {
  return vmfle_vv_f64m1_b64(value1, value2);
}


//HECK:   %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmfle.vv.nxv16i1.nxv4f16.nxv4f16(<vscale x 4 x half> %{{.*}}, <vscale x 4 x half> %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmfle.vv.nxv2i1.nxv2f32(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmfle.vv.nxv1i1.nxv1f64(<vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}) 

