// RUN: %clang_cc1 -triple riscv64 -target-feature +experimental-v -mriscv-vector-bits=128 -S -O1 -emit-llvm -o - %s | FileCheck %s --check-prefix=CHECK-128
#include <riscv_vector.h>

typedef vint8m2_t fixed_vint8m2_t __attribute__((riscv_vector_bits(128)));
struct struct_vint8m2_t {
  fixed_vint8m2_t x, y[3];
};

// CHECK-128-LABEL: @read_int8(
// CHECK-128-NEXT:  entry:
// CHECK-128-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds [[STRUCT_STRUCT_INT64:%.*]], %struct.struct_vint8m2_t* [[S:%.*]], i64 0, i32 1, i64 0
// CHECK-128-NEXT:    [[TMP0:%.*]] = bitcast <16 x i8>* [[ARRAYIDX]] to <vscale x 16 x i8>*
// CHECK-128-NEXT:    [[TMP1:%.*]] = load <vscale x 16 x i8>, <vscale x 16 x i8>* [[TMP0]], align 16, !tbaa !4
// CHECK-128-NEXT:    ret <vscale x 16 x i8> [[TMP1]]
vint8m2_t read_int8(struct struct_vint8m2_t *s) {
  return s->y[0];
}

// CHECK-128-LABEL: @assign_int8(
// CHECK-128-NEXT:  entry:
// CHECK-128-NEXT:    [[X_ADDR:%.*]] = alloca <vscale x 16 x i8>, align 16
// CHECK-128-NEXT:    store <vscale x 16 x i8> [[X:%.*]], <vscale x 16 x i8>* [[X_ADDR]], align 16, !tbaa !4
// CHECK-128-NEXT:    [[TMP0:%.*]] = bitcast <vscale x 16 x i8>* [[X_ADDR]] to <16 x i8>*
// CHECK-128-NEXT:    [[TMP1:%.*]] = load <16 x i8>, <16 x i8>* [[TMP0]], align 16, !tbaa !4
// CHECK-128-NEXT:    [[ARRAYIDX:%.*]] = getelementptr inbounds [[STRUCT_STRUCT_INT64:%.*]], %struct.struct_vint8m2_t* [[S:%.*]], i64 0, i32 1, i64 0
// CHECK-128-NEXT:    store <16 x i8> [[TMP1]], <16 x i8>* [[ARRAYIDX]], align 16, !tbaa !4
// CHECK-128-NEXT:    ret void
void assign_int8(struct struct_vint8m2_t *s, vint8m2_t x) {
  s->y[0] = x;
} 