// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>

#include <riscv_vector.h>


vint64m8_t  __attribute__((noinline)) testvwmul_vv_i64m8(vint32m4_t op1, vint32m4_t op2) {
  return vwmul_vv_i64m8(op1, op2);
}

vint32m4_t __attribute__((noinline)) testvwmul_vx_i32m4 (vint16m2_t op1, int16_t op2) {
  return vwmul_vx_i32m4 (op1, op2);
}

//CHECK:  %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vwmul.vv.nxv8i64.nxv8i32(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
//CHECK:  %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vwmul.vx.nxv8i32.nxv8i16.i16(<vscale x 8 x i16> %{{.*}}, i16 %{{.*}})


vuint64m1_t __attribute__((noinline)) testvwmulu_vv_u64m1 (vuint32mf2_t op1, vuint32mf2_t op2) {
  return  vwmulu_vv_u64m1  (op1, op2);
}

vint64m2_t __attribute__((noinline)) testvwmulsu_vx_i64m2 (vint32m1_t op1, uint32_t op2) {
  return vwmulsu_vx_i64m2  (op1, op2);
}


//CHECK:  %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vwmulu.vv.nxv1i64.nxv1i32(<vscale x 1 x i32> %{{.*}}, <vscale x 1 x i32> %{{.*}})
//CHECK:  %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vwmulsu.vx.nxv2i64.nxv2i32.i32(<vscale x 2 x i32> %{{.*}}, i32 %{{.*}})

