// RUN: %clang --target=riscv64-unknown-linux-elf -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <riscv_vector.h>


void  __attribute__((noinline)) testle32(int32_t *base, vint32m1_t value) {
  return vse32_v_i32m1(base, value);
}

void  __attribute__((noinline)) testle32_f(float *base, vfloat32m1_t value) {
  return vse32_v_f32m1(base, value);
}

//CHECK:  call void @llvm.riscv.vstore.p0i32.nxv2i32(i32* %2, <vscale x 2 x i32> %3) #2
//CHECK:  call void @llvm.riscv.vstore.p0f32.nxv2f32(float* %2, <vscale x 2 x float> %3) #2
