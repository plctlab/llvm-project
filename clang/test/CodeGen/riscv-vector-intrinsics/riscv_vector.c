// RUN: %clang_cc1 -triple riscv64-unknown-linux-gnu -target-feature +experimental-v -S -emit-llvm %s -o - | FileCheck %s

#include "riscv_vector.h"

// vint64m1_t
vint64m1_t generate_vint64m1_t();
void consume_vint64m1_t(vint64m1_t x);

vint64m1_t test_vint64m1_t() {
  // CHECK: %x = alloca <vscale x 1 x i64>, align 8
  // CHECK:%call = call <vscale x 1 x i64> bitcast (<vscale x 1 x i64> (...)* @generate_vint64m1_t to <vscale x 1 x i64> ()*)()
  // CHECK:store <vscale x 1 x i64> %call, <vscale x 1 x i64>* %x, align 8
  // CHECK:%0 = load <vscale x 1 x i64>, <vscale x 1 x i64>* %x, align 8
  // CHECK:call void @consume_vint64m1_t(<vscale x 1 x i64> %0)
  // CHECK:%1 = load <vscale x 1 x i64>, <vscale x 1 x i64>* %x, align 8
  // CHECK:ret <vscale x 1 x i64> %1
  vint64m1_t x = generate_vint64m1_t();
  consume_vint64m1_t(x);
  return x;
}

// vint64m2_t
vint64m2_t generate_vint64m2_t();
void consume_vint64m2_t(vint64m2_t x);

vint64m2_t test_vint64m2_t() {
  // CHECK: %x = alloca <vscale x 2 x i64>, align 16
  // CHECK: %call = call <vscale x 2 x i64> bitcast (<vscale x 2 x i64> (...)* @generate_vint64m2_t to <vscale x 2 x i64> ()*)()
  // CHECK: store <vscale x 2 x i64> %call, <vscale x 2 x i64>* %x, align 16
  // CHECK: %0 = load <vscale x 2 x i64>, <vscale x 2 x i64>* %x, align 16
  // CHECK: call void @consume_vint64m2_t(<vscale x 2 x i64> %0)
  // CHECK: %1 = load <vscale x 2 x i64>, <vscale x 2 x i64>* %x, align 16
  // CHECK: ret <vscale x 2 x i64> %1
  vint64m2_t x = generate_vint64m2_t();
  consume_vint64m2_t(x);
  return x;
}

// vint32m1_t
vint32m1_t generate_vint32m1_t();
void consume_vint32m1_t(vint32m1_t x);

vint32m1_t test_vint32m1_t() {
  // CHECK: %x = alloca <vscale x 2 x i32>, align 8
  // CHECK: %call = call <vscale x 2 x i32> bitcast (<vscale x 2 x i32> (...)* @generate_vint32m1_t to <vscale x 2 x i32> ()*)()
  // CHECK: store <vscale x 2 x i32> %call, <vscale x 2 x i32>* %x, align 8
  // CHECK: %0 = load <vscale x 2 x i32>, <vscale x 2 x i32>* %x, align 8
  // CHECK: call void @consume_vint32m1_t(<vscale x 2 x i32> %0)
  // CHECK:%1 = load <vscale x 2 x i32>, <vscale x 2 x i32>* %x, align 8
  // CHECK:ret <vscale x 2 x i32> %1
  vint32m1_t x = generate_vint32m1_t();
  consume_vint32m1_t(x);
  return x;
}

// vint16m1_t
vint16m1_t generate_vint16m1_t();
void consume_vint16m1_t(vint16m1_t x);

vint16m1_t test_vint16m1_t() {
  // CHECK: %x = alloca <vscale x 4 x i16>, align 8
  // CHECK: %call = call <vscale x 4 x i16> bitcast (<vscale x 4 x i16> (...)* @generate_vint16m1_t to <vscale x 4 x i16> ()*)()
  // CHECK: store <vscale x 4 x i16> %call, <vscale x 4 x i16>* %x, align 8
  // CHECK: %0 = load <vscale x 4 x i16>, <vscale x 4 x i16>* %x, align 8
  // CHECK: call void @consume_vint16m1_t(<vscale x 4 x i16> %0)
  // CHECK: %1 = load <vscale x 4 x i16>, <vscale x 4 x i16>* %x, align 8
  // CHECK: ret <vscale x 4 x i16> %1
  vint16m1_t x = generate_vint16m1_t();
  consume_vint16m1_t(x);
  return x;
}

// vint8m1_t
vint8m1_t generate_vint8m1_t();
void consume_vint8m1_t(vint8m1_t x);

vint8m1_t test_vint8m1_t() {
  // CHECK: %x = alloca <vscale x 8 x i8>, align 8
  // CHECK: %call = call <vscale x 8 x i8> bitcast (<vscale x 8 x i8> (...)* @generate_vint8m1_t to <vscale x 8 x i8> ()*)()
  // CHECK: store <vscale x 8 x i8> %call, <vscale x 8 x i8>* %x, align 8
  // CHECK: %0 = load <vscale x 8 x i8>, <vscale x 8 x i8>* %x, align 8
  // CHECK: call void @consume_vint8m1_t(<vscale x 8 x i8> %0)
  // CHECK: %1 = load <vscale x 8 x i8>, <vscale x 8 x i8>* %x, align 8
  // CHECK: ret <vscale x 8 x i8> %1
  vint8m1_t x = generate_vint8m1_t();
  consume_vint8m1_t(x);
  return x;
}

// vuint8m1_t
vuint8m1_t generate_vuint8m1_t();
void consume_vuint8m1_t(vuint8m1_t x);

vuint8m1_t test_vuint8m1_t() {
  // CHECK: %x = alloca <vscale x 8 x i8>, align 8
  // CHECK: %call = call <vscale x 8 x i8> bitcast (<vscale x 8 x i8> (...)* @generate_vuint8m1_t to <vscale x 8 x i8> ()*)()
  // CHECK: store <vscale x 8 x i8> %call, <vscale x 8 x i8>* %x, align 8
  // CHECK: %0 = load <vscale x 8 x i8>, <vscale x 8 x i8>* %x, align 8
  // CHECK: call void @consume_vuint8m1_t(<vscale x 8 x i8> %0)
  // CHECK: %1 = load <vscale x 8 x i8>, <vscale x 8 x i8>* %x, align 8
  // CHECK: ret <vscale x 8 x i8> %1
  vuint8m1_t x = generate_vuint8m1_t();
  consume_vuint8m1_t(x);
  return x;
}

// vfloat64m1_t
vfloat64m1_t generate_vfloat64m1_t();
void consume_vfloat64m1_t(vfloat64m1_t x);

vfloat64m1_t test_vfloat64m1_t() {
  // CHECK: %x = alloca <vscale x 1 x double>, align 8
  // CHECK: %call = call <vscale x 1 x double> bitcast (<vscale x 1 x double> (...)* @generate_vfloat64m1_t to <vscale x 1 x double> ()*)()
  // CHECK: store <vscale x 1 x double> %call, <vscale x 1 x double>* %x, align 8
  // CHECK: %0 = load <vscale x 1 x double>, <vscale x 1 x double>* %x, align 8
  // CHECK: call void @consume_vfloat64m1_t(<vscale x 1 x double> %0)
  // CHECK: %1 = load <vscale x 1 x double>, <vscale x 1 x double>* %x, align 8
  // CHECK: ret <vscale x 1 x double> %1
  vfloat64m1_t x = generate_vfloat64m1_t();
  consume_vfloat64m1_t(x);
  return x;
}


// vfloat32m1_t
vfloat32m1_t generate_vfloat32m1_t();
void consume_vfloat32m1_t(vfloat32m1_t x);

vfloat32m1_t test_vfloat32m1_t() {
  // CHECK: %x = alloca <vscale x 2 x float>, align 8
  // CHECK: %call = call <vscale x 2 x float> bitcast (<vscale x 2 x float> (...)* @generate_vfloat32m1_t to <vscale x 2 x float> ()*)()
  // CHECK: store <vscale x 2 x float> %call, <vscale x 2 x float>* %x, align 8
  // CHECK: %0 = load <vscale x 2 x float>, <vscale x 2 x float>* %x, align 8
  // CHECK: call void @consume_vfloat32m1_t(<vscale x 2 x float> %0)
  // CHECK: %1 = load <vscale x 2 x float>, <vscale x 2 x float>* %x, align 8
  // CHECK: ret <vscale x 2 x float> %1
  vfloat32m1_t x = generate_vfloat32m1_t();
  consume_vfloat32m1_t(x);
  return x;
}

// vfloat16m1_t
vfloat16m1_t generate_vfloat16m1_t();
void consume_vfloat16m1_t(vfloat16m1_t x);

vfloat16m1_t test_vfloat16m1_t() {
  // CHECK: %x = alloca <vscale x 4 x half>, align 8
  // CHECK: %call = call <vscale x 4 x half> bitcast (<vscale x 4 x half> (...)* @generate_vfloat16m1_t to <vscale x 4 x half> ()*)()
  // CHECK: store <vscale x 4 x half> %call, <vscale x 4 x half>* %x, align 8
  // CHECK: %0 = load <vscale x 4 x half>, <vscale x 4 x half>* %x, align 8
  // CHECK: call void @consume_vfloat16m1_t(<vscale x 4 x half> %0)
  // CHECK: %1 = load <vscale x 4 x half>, <vscale x 4 x half>* %x, align 8
  // CHECK: ret <vscale x 4 x half> %1
  vfloat16m1_t x = generate_vfloat16m1_t();
  consume_vfloat16m1_t(x);
  return x;
}



vbool8_t generate_vbool8_t();
void consume_vbool8_t(vbool8_t x);
vbool8_t test_vbool8_t() {
  vbool8_t x = generate_vbool8_t();
  consume_vbool8_t(x);
  return x;
}

vbool16_t generate_vbool16_t();
void consume_vbool16_t(vbool16_t x);
vbool16_t test_vbool16_t() {
  vbool16_t x = generate_vbool16_t();
  consume_vbool16_t(x);
  return x;
}


vbool32_t generate_vbool32_t();
void consume_vbool32_t(vbool32_t x);
vbool32_t test_vbool32_t() {
  vbool32_t x = generate_vbool32_t();
  consume_vbool32_t(x);
  return x;
}


vbool64_t generate_vbool64_t();
void consume_vbool64_t(vbool64_t x);
vbool64_t test_vbool64_t() {
  vbool64_t x = generate_vbool64_t();
  consume_vbool64_t(x);
  return x;
}
//CHECK: %call = call <vscale x 8 x i1> bitcast (<vscale x 8 x i1> (...)* @generate_vbool8_t to <vscale x 8 x i1> ()*)()
//CHECK: %call = call <vscale x 4 x i1> bitcast (<vscale x 4 x i1> (...)* @generate_vbool16_t to <vscale x 4 x i1> ()*)()
//CHECK: %call = call <vscale x 2 x i1> bitcast (<vscale x 2 x i1> (...)* @generate_vbool32_t to <vscale x 2 x i1> ()*)()
//CHECK: %call = call <vscale x 1 x i1> bitcast (<vscale x 1 x i1> (...)* @generate_vbool64_t to <vscale x 1 x i1> ()*)()

vint8mf8x2_t generate_vint8mf8x2_t();
void consume_vint8mf8x2_t(vint8mf8x2_t x);

vint8mf8x2_t test_vuint8mf8x2_t() {
  //CHECK: %x = alloca <vscale x 2 x i8>, align 2
  //CHECK: %call = call <vscale x 2 x i8> bitcast (<vscale x 2 x i8> (...)* @generate_vint8mf8x2_t to <vscale x 2 x i8> ()*)()
  //CHECK: store <vscale x 2 x i8> %call, <vscale x 2 x i8>* %x, align 2
  //CHECK: %0 = load <vscale x 2 x i8>, <vscale x 2 x i8>* %x, align 2
  //CHECK: call void @consume_vint8mf8x2_t(<vscale x 2 x i8> %0)
  //CHECK: %1 = load <vscale x 2 x i8>, <vscale x 2 x i8>* %x, align 2
  //CHECK: ret <vscale x 2 x i8> %1
  vint8mf8x2_t x = generate_vint8mf8x2_t();
  consume_vint8mf8x2_t(x);
  return x;
}

vint8m1x7_t generate_vuint8m1x7_t();
void consume_vuint8m1x7_t(vint8m1x7_t x);

vint8m1x7_t test_vuint8m1x7_t() {
  //CHECK: %x = alloca <vscale x 56 x i8>, align 64
  //CHECK: %call = call <vscale x 56 x i8> bitcast (<vscale x 56 x i8> (...)* @generate_vuint8m1x7_t to <vscale x 56 x i8> ()*)()
  //CHECK: store <vscale x 56 x i8> %call, <vscale x 56 x i8>* %x, align 64
  //CHECK: %0 = load <vscale x 56 x i8>, <vscale x 56 x i8>* %x, align 64
  //CHECK: call void @consume_vuint8m1x7_t(<vscale x 56 x i8> %0)
  //CHECK: %1 = load <vscale x 56 x i8>, <vscale x 56 x i8>* %x, align 64
  //CHECK: ret <vscale x 56 x i8> %1
  vint8m1x7_t x = generate_vuint8m1x7_t();
  consume_vuint8m1x7_t(x);
  return x;
}


