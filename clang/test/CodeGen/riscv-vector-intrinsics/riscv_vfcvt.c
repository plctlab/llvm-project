// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>
#include <riscv_vector.h>


vint64m1_t __attribute__((noinline)) testvfcvt_rtz_x_f_v_i64m1(vfloat64m1_t src) {
  return vfcvt_rtz_x_f_v_i64m1(src);
}

//CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vfcvt.rtz.x.f.v.nxv1i64.nxv1f64(<vscale x 1 x double> %{{.*}})
