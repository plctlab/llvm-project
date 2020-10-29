// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>

#include <riscv_vector.h>


vbool8_t  __attribute__((noinline)) testmseq8(vint8m1_t value1, vint8m1_t value2) {
  return vmsle_vv_i8m1_b8(value1, value2);
}

vbool16_t  __attribute__((noinline)) testmseq16(vint16m1_t value1, vint16m1_t value2) {
  return vmsle_vv_i16m1_b16(value1, value2);
}

vbool32_t  __attribute__((noinline)) testmseq32(vint32m1_t value1, vint32m1_t value2) {
  return vmsle_vv_i32m1_b32(value1, value2);
}

vbool64_t __attribute__((noinline)) testmseq64(vint64m1_t value1, vint64m1_t value2) {
  return vmsle_vv_i64m1_b64(value1, value2);
}

vbool8_t  __attribute__((noinline)) testmseq8_u(vuint8m1_t value1, vuint8m1_t value2) {
  return vmsleu_vv_u8m1_b8(value1, value2);
}

vbool16_t  __attribute__((noinline)) testmseq16_u(vuint16m1_t value1, vuint16m1_t value2) {
  return vmsleu_vv_u16m1_b16(value1, value2);
}

vbool32_t  __attribute__((noinline)) testmseq32_u(vuint32m1_t value1, vuint32m1_t value2) {
  return vmsleu_vv_u32m1_b32(value1, value2);
}

vbool64_t __attribute__((noinline)) testmseq64_u(vuint64m1_t value1, vuint64m1_t value2) {
  return vmsleu_vv_u64m1_b64(value1, value2);
}

//CHECK:   %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsle.vv.nxv8i1.nxv8i8(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsle.vv.nxv4i1.nxv4i16(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsle.vv.nxv2i1.nxv2i32(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsle.vv.nxv1i1.nxv1i64(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsleu.vv.nxv8i1.nxv8i8(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 4 x i1> @llvm.riscv.vmsleu.vv.nxv4i1.nxv4i16(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 2 x i1> @llvm.riscv.vmsleu.vv.nxv2i1.nxv2i32(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}) 
//CHECK:   %{{.*}} = call <vscale x 1 x i1> @llvm.riscv.vmsleu.vv.nxv1i1.nxv1i64(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}) 

