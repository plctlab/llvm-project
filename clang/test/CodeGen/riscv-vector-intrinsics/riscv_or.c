// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>

#include <riscv_vector.h>


vint8m1_t  __attribute__((noinline)) testor8(vint8m1_t value1, vint8m1_t value2) {
  return vor_vv_i8m1(value1, value2);
}
//CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vor.vv.nxv8i8(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}) 

vint16m1_t  __attribute__((noinline)) testor16(vint16m1_t value1, vint16m1_t value2) {
  return vor_vv_i16m1(value1, value2);
}
//CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vor.vv.nxv4i16(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}) 

vint32m1_t  __attribute__((noinline)) testor32(vint32m1_t value1, vint32m1_t value2) {
  return vor_vv_i32m1(value1, value2);
}
//CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vor.vv.nxv2i32(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}) 

vint64m1_t  __attribute__((noinline)) testor64(vint64m1_t value1, vint64m1_t value2) {
  return vor_vv_i64m1(value1, value2);
}
//CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vor.vv.nxv1i64(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}) 


