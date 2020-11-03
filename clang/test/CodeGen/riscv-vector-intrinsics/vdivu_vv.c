// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vuint16m1_t test_vdivuvv_u16m1 (vuint16m1_t a, vuint16m1_t b) {
    return vdivu_vv_u16m1 (a, b);
}


vuint16m2_t test_vdivuvv_u16m2 (vuint16m2_t a, vuint16m2_t b) {
    return vdivu_vv_u16m2 (a, b);
}


vuint16m4_t test_vdivuvv_u16m4 (vuint16m4_t a, vuint16m4_t b) {
    return vdivu_vv_u16m4 (a, b);
}


vuint16m8_t test_vdivuvv_u16m8 (vuint16m8_t a, vuint16m8_t b) {
    return vdivu_vv_u16m8 (a, b);
}


vuint32m1_t test_vdivuvv_u32m1 (vuint32m1_t a, vuint32m1_t b) {
    return vdivu_vv_u32m1 (a, b);
}


vuint32m2_t test_vdivuvv_u32m2 (vuint32m2_t a, vuint32m2_t b) {
    return vdivu_vv_u32m2 (a, b);
}


vuint32m4_t test_vdivuvv_u32m4 (vuint32m4_t a, vuint32m4_t b) {
    return vdivu_vv_u32m4 (a, b);
}


vuint32m8_t test_vdivuvv_u32m8 (vuint32m8_t a, vuint32m8_t b) {
    return vdivu_vv_u32m8 (a, b);
}


vuint64m1_t test_vdivuvv_u64m1 (vuint64m1_t a, vuint64m1_t b) {
    return vdivu_vv_u64m1 (a, b);
}


vuint64m2_t test_vdivuvv_u64m2 (vuint64m2_t a, vuint64m2_t b) {
    return vdivu_vv_u64m2 (a, b);
}


vuint64m4_t test_vdivuvv_u64m4 (vuint64m4_t a, vuint64m4_t b) {
    return vdivu_vv_u64m4 (a, b);
}


vuint64m8_t test_vdivuvv_u64m8 (vuint64m8_t a, vuint64m8_t b) {
    return vdivu_vv_u64m8 (a, b);
}


vuint8m1_t test_vdivuvv_u8m1 (vuint8m1_t a, vuint8m1_t b) {
    return vdivu_vv_u8m1 (a, b);
}


vuint8m2_t test_vdivuvv_u8m2 (vuint8m2_t a, vuint8m2_t b) {
    return vdivu_vv_u8m2 (a, b);
}


vuint8m4_t test_vdivuvv_u8m4 (vuint8m4_t a, vuint8m4_t b) {
    return vdivu_vv_u8m4 (a, b);
}


vuint8m8_t test_vdivuvv_u8m8 (vuint8m8_t a, vuint8m8_t b) {
    return vdivu_vv_u8m8 (a, b);
}

//CHECK:   %{{.*}} = call <vscale x 4 x i16> @llvm.riscv.vdivu.vv.nxv4i16(<vscale x 4 x i16> %{{.*}}, <vscale x 4 x i16> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 8 x i16> @llvm.riscv.vdivu.vv.nxv8i16(<vscale x 8 x i16> %{{.*}}, <vscale x 8 x i16> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 16 x i16> @llvm.riscv.vdivu.vv.nxv16i16(<vscale x 16 x i16> %{{.*}}, <vscale x 16 x i16> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 32 x i16> @llvm.riscv.vdivu.vv.nxv32i16(<vscale x 32 x i16> %{{.*}}, <vscale x 32 x i16> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 2 x i32> @llvm.riscv.vdivu.vv.nxv2i32(<vscale x 2 x i32> %{{.*}}, <vscale x 2 x i32> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 4 x i32> @llvm.riscv.vdivu.vv.nxv4i32(<vscale x 4 x i32> %{{.*}}, <vscale x 4 x i32> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 8 x i32> @llvm.riscv.vdivu.vv.nxv8i32(<vscale x 8 x i32> %{{.*}}, <vscale x 8 x i32> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 16 x i32> @llvm.riscv.vdivu.vv.nxv16i32(<vscale x 16 x i32> %{{.*}}, <vscale x 16 x i32> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 1 x i64> @llvm.riscv.vdivu.vv.nxv1i64(<vscale x 1 x i64> %{{.*}}, <vscale x 1 x i64> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 2 x i64> @llvm.riscv.vdivu.vv.nxv2i64(<vscale x 2 x i64> %{{.*}}, <vscale x 2 x i64> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 4 x i64> @llvm.riscv.vdivu.vv.nxv4i64(<vscale x 4 x i64> %{{.*}}, <vscale x 4 x i64> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 8 x i64> @llvm.riscv.vdivu.vv.nxv8i64(<vscale x 8 x i64> %{{.*}}, <vscale x 8 x i64> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 8 x i8> @llvm.riscv.vdivu.vv.nxv8i8(<vscale x 8 x i8> %{{.*}}, <vscale x 8 x i8> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 16 x i8> @llvm.riscv.vdivu.vv.nxv16i8(<vscale x 16 x i8> %{{.*}}, <vscale x 16 x i8> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 32 x i8> @llvm.riscv.vdivu.vv.nxv32i8(<vscale x 32 x i8> %{{.*}}, <vscale x 32 x i8> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 64 x i8> @llvm.riscv.vdivu.vv.nxv64i8(<vscale x 64 x i8> %{{.*}}, <vscale x 64 x i8> %{{.*}})
