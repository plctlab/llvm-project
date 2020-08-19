// RUN: %clang --target=riscv64-unknown-linux-elf -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <riscv_vector.h>


vint8m1_t  __attribute__((noinline)) testnot8(vint8m1_t value1) {
  return vnot_v_i8m1(value1);
}

vint16m1_t  __attribute__((noinline)) testnot16(vint16m1_t value1) {
  return vnot_v_i16m1(value1);
}

vint32m1_t  __attribute__((noinline)) testnot32(vint32m1_t value1) {
  return vnot_v_i32m1(value1);
}

vint64m1_t  __attribute__((noinline)) testnot64(vint64m1_t value1) {
  return vnot_v_i64m1(value1);
}
//CHECK: %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vnot.v.nxv8i8(<vscale x 8 x i8> %{{.*}}) #{{.*}}
//CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vnot.v.nxv4i16(<vscale x 4 x i16> %{{.*}}) #{{.*}}
//CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vnot.v.nxv2i32(<vscale x 2 x i32> %{{.*}}) #{{.*}}
//CHECK: %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vnot.v.nxv1i64(<vscale x 1 x i64> %{{.*}}) #{{.*}}

