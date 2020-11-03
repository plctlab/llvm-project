// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vint16m1_t test_vdivvv_i16m1 (vint16m1_t a, vint16m1_t b) {
    return vdiv_vv_i16m1 (a, b);
}


vint16m2_t test_vdivvv_i16m2 (vint16m2_t a, vint16m2_t b) {
    return vdiv_vv_i16m2 (a, b);
}


vint16m4_t test_vdivvv_i16m4 (vint16m4_t a, vint16m4_t b) {
    return vdiv_vv_i16m4 (a, b);
}


vint16m8_t test_vdivvv_i16m8 (vint16m8_t a, vint16m8_t b) {
    return vdiv_vv_i16m8 (a, b);
}


vint32m1_t test_vdivvv_i32m1 (vint32m1_t a, vint32m1_t b) {
    return vdiv_vv_i32m1 (a, b);
}


vint32m2_t test_vdivvv_i32m2 (vint32m2_t a, vint32m2_t b) {
    return vdiv_vv_i32m2 (a, b);
}


vint32m4_t test_vdivvv_i32m4 (vint32m4_t a, vint32m4_t b) {
    return vdiv_vv_i32m4 (a, b);
}


vint32m8_t test_vdivvv_i32m8 (vint32m8_t a, vint32m8_t b) {
    return vdiv_vv_i32m8 (a, b);
}


vint64m1_t test_vdivvv_i64m1 (vint64m1_t a, vint64m1_t b) {
    return vdiv_vv_i64m1 (a, b);
}


vint64m2_t test_vdivvv_i64m2 (vint64m2_t a, vint64m2_t b) {
    return vdiv_vv_i64m2 (a, b);
}


vint64m4_t test_vdivvv_i64m4 (vint64m4_t a, vint64m4_t b) {
    return vdiv_vv_i64m4 (a, b);
}


vint64m8_t test_vdivvv_i64m8 (vint64m8_t a, vint64m8_t b) {
    return vdiv_vv_i64m8 (a, b);
}


vint8m1_t test_vdivvv_i8m1 (vint8m1_t a, vint8m1_t b) {
    return vdiv_vv_i8m1 (a, b);
}


vint8m2_t test_vdivvv_i8m2 (vint8m2_t a, vint8m2_t b) {
    return vdiv_vv_i8m2 (a, b);
}


vint8m4_t test_vdivvv_i8m4 (vint8m4_t a, vint8m4_t b) {
    return vdiv_vv_i8m4 (a, b);
}


vint8m8_t test_vdivvv_i8m8 (vint8m8_t a, vint8m8_t b) {
    return vdiv_vv_i8m8 (a, b);
}

//CHECK:   %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vdiv.vv.nxv4i16(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vdiv.vv.nxv8i16(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vdiv.vv.nxv16i16(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vdiv.vv.nxv32i16(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vdiv.vv.nxv2i32(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vdiv.vv.nxv4i32(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vdiv.vv.nxv8i32(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vdiv.vv.nxv16i32(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vdiv.vv.nxv1i64(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vdiv.vv.nxv2i64(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vdiv.vv.nxv4i64(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vdiv.vv.nxv8i64(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vdiv.vv.nxv8i8(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vdiv.vv.nxv16i8(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vdiv.vv.nxv32i8(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vdiv.vv.nxv64i8(<vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
