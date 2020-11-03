// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm  %s -o - |  FileCheck %s

#include <riscv_vector.h>

vfloat32m1_t test_vfnmaddvf_f32m1 (vfloat32m1_t a, float b, vfloat32m1_t c) {
    return vfnmadd_vf_f32m1 (a, b, c);
}


vfloat32m2_t test_vfnmaddvf_f32m2 (vfloat32m2_t a, float b, vfloat32m2_t c) {
    return vfnmadd_vf_f32m2 (a, b, c);
}


vfloat32m4_t test_vfnmaddvf_f32m4 (vfloat32m4_t a, float b, vfloat32m4_t c) {
    return vfnmadd_vf_f32m4 (a, b, c);
}


vfloat32m8_t test_vfnmaddvf_f32m8 (vfloat32m8_t a, float b, vfloat32m8_t c) {
    return vfnmadd_vf_f32m8 (a, b, c);
}


vfloat64m1_t test_vfnmaddvf_f64m1 (vfloat64m1_t a, double b, vfloat64m1_t c) {
    return vfnmadd_vf_f64m1 (a, b, c);
}


vfloat64m2_t test_vfnmaddvf_f64m2 (vfloat64m2_t a, double b, vfloat64m2_t c) {
    return vfnmadd_vf_f64m2 (a, b, c);
}


vfloat64m4_t test_vfnmaddvf_f64m4 (vfloat64m4_t a, double b, vfloat64m4_t c) {
    return vfnmadd_vf_f64m4 (a, b, c);
}


vfloat64m8_t test_vfnmaddvf_f64m8 (vfloat64m8_t a, double b, vfloat64m8_t c) {
    return vfnmadd_vf_f64m8 (a, b, c);
}

//CHECK:   %{{.*}} = call <vscale x 2 x float> @llvm.riscv.vfnmadd.vf.nxv2f32.f32(<vscale x 2 x float> %{{.*}}, float %{{.*}}, <vscale x 2 x float> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 4 x float> @llvm.riscv.vfnmadd.vf.nxv4f32.f32(<vscale x 4 x float> %{{.*}}, float %{{.*}}, <vscale x 4 x float> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 8 x float> @llvm.riscv.vfnmadd.vf.nxv8f32.f32(<vscale x 8 x float> %{{.*}}, float %{{.*}}, <vscale x 8 x float> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 16 x float> @llvm.riscv.vfnmadd.vf.nxv16f32.f32(<vscale x 16 x float> %{{.*}}, float %{{.*}}, <vscale x 16 x float> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 1 x double> @llvm.riscv.vfnmadd.vf.nxv1f64.f64(<vscale x 1 x double> %{{.*}}, double %{{.*}}, <vscale x 1 x double> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 2 x double> @llvm.riscv.vfnmadd.vf.nxv2f64.f64(<vscale x 2 x double> %{{.*}}, double %{{.*}}, <vscale x 2 x double> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 4 x double> @llvm.riscv.vfnmadd.vf.nxv4f64.f64(<vscale x 4 x double> %{{.*}}, double %{{.*}}, <vscale x 4 x double> %{{.*}})
//CHECK:   %{{.*}} = call <vscale x 8 x double> @llvm.riscv.vfnmadd.vf.nxv8f64.f64(<vscale x 8 x double> %{{.*}}, double %{{.*}}, <vscale x 8 x double> %{{.*}})
