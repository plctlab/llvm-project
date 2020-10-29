// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>

#include <riscv_vector.h>


void  __attribute__((noinline)) testle32(int32_t *base, vint32m1_t value) {
  return vse32_v_i32m1(base, value);
}

void  __attribute__((noinline)) testle32_f(float *base, vfloat32m1_t value) {
  return vse32_v_f32m1(base, value);
}

void  __attribute__((noinline)) testle32_u(uint32_t *base, vuint32m1_t value) {
  return vse32_v_u32m1(base, value);
}

void  __attribute__((noinline)) testle8(int8_t *base, vint8m1_t value) {
  return vse8_v_i8m1(base, value);
}

void  __attribute__((noinline)) testle8_u(uint8_t *base, vuint8m1_t value) {
  return vse8_v_u8m1(base, value);
}

void  __attribute__((noinline)) testle64(int64_t *base, vint64m1_t value) {
  return vse64_v_i64m1(base, value);
}

void  __attribute__((noinline)) testle64_f(float *base, vfloat64m1_t value) {
  return vse64_v_f64m1(base, value);
}

void  __attribute__((noinline)) testle64_u(uint64_t *base, vuint64m1_t value) {
  return vse64_v_u64m1(base, value);
}

void  __attribute__((noinline)) testle16(int16_t *base, vint16m1_t value) {
  return vse16_v_i16m1(base, value);
}

void  __attribute__((noinline)) testle16_u(uint16_t *base, vuint16m1_t value) {
  return vse16_v_u16m1(base, value);
}


//CHECK:  call void @llvm.riscv.vstore.p0i32.nxv2i32(i32* %{{.*}}, <vscale x 2 x i32> %{{.*}}) 
//CHECK:  call void @llvm.riscv.vstore.p0f32.nxv2f32(float* %{{.*}}, <vscale x 2 x float> %{{.*}}) 
//CHECK:  call void @llvm.riscv.vstore.p0i32.nxv2i32(i32* %{{.*}}, <vscale x 2 x i32> %{{.*}}) 
//CHECK:   call void @llvm.riscv.vstore.p0i8.nxv8i8(i8* %{{.*}}, <vscale x 8 x i8> %{{.*}}) 
//CHECK:   call void @llvm.riscv.vstore.p0i8.nxv8i8(i8* %{{.*}}, <vscale x 8 x i8> %{{.*}}) 
//CHECK:   call void @llvm.riscv.vstore.p0i64.nxv1i64(i64* %{{.*}}, <vscale x 1 x i64> %{{.*}}) 
//CHECK:   call void @llvm.riscv.vstore.p0f64.nxv1f64(double* %{{.*}}, <vscale x 1 x double> %{{.*}}) 
//CHECK:   call void @llvm.riscv.vstore.p0i64.nxv1i64(i64* %{{.*}}, <vscale x 1 x i64> %{{.*}}) 
//CHECK:  call void @llvm.riscv.vstore.p0i16.nxv4i16(i16* %{{.*}}, <vscale x 4 x i16> %{{.*}}) 
//CHECK:  call void @llvm.riscv.vstore.p0i16.nxv4i16(i16* %{{.*}}, <vscale x 4 x i16> %{{.*}}) 
