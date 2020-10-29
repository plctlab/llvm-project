// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>

#include <riscv_vector.h>


vint8m1_t  __attribute__((noinline)) testmin8(vint8m1_t value1, uint8_t value2) {
  return vsll_vx_i8m1(value1, value2);
}

vint16m1_t  __attribute__((noinline)) testmin16(vint16m1_t value1, uint8_t value2) {
  return vsll_vx_i16m1(value1, value2);
}

vint32m1_t  __attribute__((noinline)) testmin32(vint32m1_t value1, uint8_t value2) {
  return vsll_vx_i32m1(value1, value2);
}

vint64m1_t  __attribute__((noinline)) testmin64(vint64m1_t value1, uint8_t value2) {
  return vsll_vx_i64m1(value1, value2);
}

//CHECK:   %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vsll.vx.nxv8i8.i8(<vscale x 8 x i8> %{{.*}}, i8 %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vsll.vx.nxv4i16.i8(<vscale x 4 x i16> %{{.*}}, i8 %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vsll.vx.nxv2i32.i8(<vscale x 2 x i32> %{{.*}}, i8 %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vsll.vx.nxv1i64.i8(<vscale x 1 x i64> %{{.*}}, i8 %{{.*}}) 


vuint8m1_t  __attribute__((noinline)) testsllu8(vuint8m1_t value1, uint8_t value2) {
  return vsll_vx_u8m1(value1, value2);
}

vuint16m1_t  __attribute__((noinline)) testsllu16(vuint16m1_t value1, uint8_t value2) {
  return vsll_vx_u16m1(value1, value2);
}

vuint32m1_t  __attribute__((noinline)) testsllu32(vuint32m1_t value1, uint8_t value2) {
  return vsll_vx_u32m1(value1, value2);
}

vuint64m1_t  __attribute__((noinline)) testsllu64(vuint64m1_t value1, uint8_t value2) {
  return vsll_vx_u64m1(value1, value2);
}


//CHECK:   %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vsll.vx.nxv8i8.i8(<vscale x 8 x i8> %{{.*}}, i8 %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vsll.vx.nxv4i16.i8(<vscale x 4 x i16> %{{.*}}, i8 %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vsll.vx.nxv2i32.i8(<vscale x 2 x i32> %{{.*}}, i8 %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vsll.vx.nxv1i64.i8(<vscale x 1 x i64> %{{.*}}, i8 %{{.*}}) 

