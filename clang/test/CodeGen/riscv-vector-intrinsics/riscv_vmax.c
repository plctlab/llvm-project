// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>

#include <riscv_vector.h>


vint8m1_t  __attribute__((noinline)) testmax8(vint8m1_t value1, vint8m1_t value2) {
  return vmax_vv_i8m1(value1, value2);
}
//CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vmax.vv.nxv8i8(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}) 

vint16m1_t  __attribute__((noinline)) testmax16(vint16m1_t value1, vint16m1_t value2) {
  return vmax_vv_i16m1(value1, value2);
}
//CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vmax.vv.nxv4i16(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}) 

vint32m1_t  __attribute__((noinline)) testmax32(vint32m1_t value1, vint32m1_t value2) {
  return vmax_vv_i32m1(value1, value2);
}
//CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vmax.vv.nxv2i32(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}) 

vint64m1_t  __attribute__((noinline)) testmax64(vint64m1_t value1, vint64m1_t value2) {
  return vmax_vv_i64m1(value1, value2);
}
//CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vmax.vv.nxv1i64(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}) 


vuint8m1_t  __attribute__((noinline)) testumax8(vuint8m1_t value1, vuint8m1_t value2) {
  return vmaxu_vv_u8m1(value1, value2);
}

vuint16m1_t  __attribute__((noinline)) testumax16(vuint16m1_t value1, vuint16m1_t value2) {
  return vmaxu_vv_u16m1(value1, value2);
}

vuint32m1_t  __attribute__((noinline)) testumax32(vuint32m1_t value1, vuint32m1_t value2) {
  return vmaxu_vv_u32m1(value1, value2);
}

vuint64m1_t  __attribute__((noinline)) testumax64(vuint64m1_t value1, vuint64m1_t value2) {
  return vmaxu_vv_u64m1(value1, value2);
}


//CHECK:   %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vmaxu.vv.nxv8i8(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vmaxu.vv.nxv4i16(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vmaxu.vv.nxv2i32(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vmaxu.vv.nxv1i64(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}) 


vfloat32m1_t __attribute__((noinline)) testvfmax_vv_f32m1 (vfloat32m1_t op1, vfloat32m1_t op2) {
  return vfmax_vv_f32m1(op1, op2);
}

//CHECK;  %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfmax.vv.nxv2f32(<vscale x 2 x float> %{{.*}}, <vscale x 2 x float> %{{.*}}) 
