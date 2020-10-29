// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>

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


vint16m1_t  __attribute__((noinline)) testle16(const int16_t* src) {
  return vle16_v_i16m1(src);
}

vuint16m1_t  __attribute__((noinline)) testle16_u(const uint16_t* src) {
  return vle16_v_u16m1(src);
}

//CHECK:   %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vload.nxv2i32.p0i32(i32* %{{.*}}) 
//CHECK:    %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vload.nxv2f32.p0f32(float* %{{.*}}) 
//CHECK: %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vload.nxv2i32.p0i32(i32* %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vload.nxv8i8.p0i8(i8* %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vload.nxv8i8.p0i8(i8* %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vload.nxv1i64.p0i64(i64* %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vload.nxv1f64.p0f64(double* %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vload.nxv1i64.p0i64(i64* %{{.*}}) 
//CHECK:  %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vload.nxv4i16.p0i16(i16* %{{.*}}) 
//CHECK:  %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vload.nxv4i16.p0i16(i16* %{{.*}}) 

vint16m1_t  __attribute__((noinline)) testloadstride(const int16_t* src, ptrdiff_t bstride) {
  return vlse16_v_i16m1(src, bstride);
}

//CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vload.strided.nxv4i16.p0i16(i16* %0, i64 %1)

vint16m1_t  __attribute__((noinline)) testloadindexed(const int16_t* src, ptrdiff_t bstride) {
  return vlse16_v_i16m1(src, bstride);
}

//CHECK: %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vload.strided.nxv4i16.p0i16(i16* %0, i64 %1)

void  __attribute__((noinline)) teststoreindexed(int16_t *base, ptrdiff_t bstride, vint16m1_t value) {
  return vsse16_v_i16m1(base, bstride, value);
}

//CHECK: call void @llvm.riscv.vstore.strided.p0i16.nxv4i16(i16* %0, i64 %1, <vscale x 4 x i16> %2)
