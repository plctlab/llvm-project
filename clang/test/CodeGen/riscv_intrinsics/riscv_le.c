// RUN: %clang --target=riscv64-unknown-linux-elf -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <riscv_vector.h>



vint32m1_t  __attribute__((noinline)) testle32(const int32_t* src) {
  return vle32_v_i32m1(src);
}

vfloat32m1_t  __attribute__((noinline)) testle32_f(const float* src) {
  return vle32_v_f32m1(src);
}

vuint32m1_t  __attribute__((noinline)) testle32_u(const uint32_t* src) {
  return vle32_v_u32m1(src);
}

vint8m1_t  __attribute__((noinline)) testle8(const int8_t* src) {
  return vle8_v_i8m1(src);
}

vuint8m1_t  __attribute__((noinline)) testle8_u(const uint8_t* src) {
  return vle8_v_u8m1(src);
}

vint64m1_t  __attribute__((noinline)) testle64(const int64_t* src) {
  return vle64_v_i64m1(src);
}

vfloat64m1_t  __attribute__((noinline)) testle64_f(const float* src) {
  return vle64_v_f64m1(src);
}

vuint64m1_t  __attribute__((noinline)) testle64_u(const uint64_t* src) {
  return vle64_v_u64m1(src);
}


//CHECK:   %3 = call <vscale x 2 x i32> @llvm.riscv.vload.nxv2i32.p0i32(i32* %1) #2
//CHECK:    %3 = call <vscale x 2 x float> @llvm.riscv.vload.nxv2f32.p0f32(float* %1) #2
//CHECK: %3 = call <vscale x 2 x i32> @llvm.riscv.vload.nxv2i32.p0i32(i32* %1) #2
//CHECK:   %3 = call <vscale x 8 x i8> @llvm.riscv.vload.nxv8i8.p0i8(i8* %1) #2
//CHECK:   %3 = call <vscale x 8 x i8> @llvm.riscv.vload.nxv8i8.p0i8(i8* %1) #2
//CHECK:   %3 = call <vscale x 1 x i64> @llvm.riscv.vload.nxv1i64.p0i64(i64* %1) #2
//CHECK:   %5 = call <vscale x 1 x double> @llvm.riscv.vload.nxv1f64.p0f64(double* %2) #2
//CHECK:   %3 = call <vscale x 1 x i64> @llvm.riscv.vload.nxv1i64.p0i64(i64* %1) #2
