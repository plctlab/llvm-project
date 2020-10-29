// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>
#include <riscv_vector.h>

vfloat64m1_t __attribute__((noinline)) testvslidedown_vx_f64m1 (vfloat64m1_t dst, vfloat64m1_t src, size_t offset) {
 return  vslidedown_vx_f64m1(dst, src, offset);                                                                                                                                                                                                                          
}

vfloat64m1_t __attribute__((noinline)) testvslideup_vx_f64m1 (vfloat64m1_t dst, vfloat64m1_t src, size_t offset) {
 return  vslideup_vx_f64m1(dst, src, offset);                                                                                                                                                                                                                          
}


//CHECK:  %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vslidedown.vx.nxv1f64.i64(<vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, i64 %{{.*}}) 
//CHECK:  %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vslideup.vx.nxv1f64.i64(<vscale x 1 x double> %{{.*}}, <vscale x 1 x double> %{{.*}}, i64 %{{.*}}) 

