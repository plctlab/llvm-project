// RUN: %clang --target=riscv64-unknown-linux-elf -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <riscv_vector.h>


vbool8_t  __attribute__((noinline)) testmsne8(vint8m1_t value1, vint8m1_t value2) {
  return vmsne_vv_i8m1_b8(value1, value2);
}

vbool16_t  __attribute__((noinline)) testmsne16(vint16m1_t value1, vint16m1_t value2) {
  return vmsne_vv_i16m1_b16(value1, value2);
}

vbool32_t  __attribute__((noinline)) testmsne32(vint32m1_t value1, vint32m1_t value2) {
  return vmsne_vv_i32m1_b32(value1, value2);
}

vbool64_t __attribute__((noinline)) testmsne64(vint64m1_t value1, vint64m1_t value2) {
  return vmsne_vv_i64m1_b64(value1, value2);
}

//CHECK:   %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsne.vv.nxv8i1.nxv8i8.nxv8i8(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}) #{{.*}}
//CHECK:   %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmsne.vv.nxv16i1.nxv4i16.nxv4i16(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}) #{{.*}}
//CHECK:   %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmsne.vv.nxv32i1.nxv2i32.nxv2i32(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}) #{{.*}}
//CHECK:   %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmsne.vv.nxv64i1.nxv1i64.nxv1i64(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}) #{{.*}}


vbool8_t  __attribute__((noinline)) testmsne8_u(vuint8m1_t value1, vuint8m1_t value2) {
  return vmsne_vv_u8m1_b8(value1, value2);
}

vbool16_t  __attribute__((noinline)) testmsne16_u(vuint16m1_t value1, vuint16m1_t value2) {
  return vmsne_vv_u16m1_b16(value1, value2);
}

vbool32_t  __attribute__((noinline)) testmsne32_u(vuint32m1_t value1, vuint32m1_t value2) {
  return vmsne_vv_u32m1_b32(value1, value2);
}

vbool64_t __attribute__((noinline)) testmsne64_u(vuint64m1_t value1, vuint64m1_t value2) {
  return vmsne_vv_u64m1_b64(value1, value2);
}

//CHECK:   %{{.*}} = call <vscale x 8 x i1> @llvm.riscv.vmsne.vv.nxv8i1.nxv8i8.nxv8i8(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}}) #{{.*}}
//CHECK:   %{{.*}} = call <vscale x 16 x i1> @llvm.riscv.vmsne.vv.nxv16i1.nxv4i16.nxv4i16(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}}) #{{.*}}
//CHECK:   %{{.*}} = call <vscale x 32 x i1> @llvm.riscv.vmsne.vv.nxv32i1.nxv2i32.nxv2i32(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}}) #{{.*}}
//CHECK:   %{{.*}} = call <vscale x 64 x i1> @llvm.riscv.vmsne.vv.nxv64i1.nxv1i64.nxv1i64(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}}) #{{.*}}

