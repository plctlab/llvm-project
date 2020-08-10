// RUN: %clang --target=riscv64-unknown-linux-elf -S -emit-llvm -O0 %s -o - | FileCheck %s

#include "riscv_vector.h"

// vint64m1_t
vint64m1_t generate_vint64m1_t();
void consume_vint64m1_t(vint64m1_t x);

vint64m1_t test_vint64m1_t() {
  // CHECK: define dso_local <vscale x 1 x i64> @test_vint64m1_t() #0 {
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
// CHECK: declare dso_local <vscale x 1 x i64> @generate_vint64m1_t(...) #1
// CHECK: declare dso_local void @consume_vint64m1_t(<vscale x 1 x i64>) #1

// vint64m2_t
vint64m2_t generate_vint64m2_t();
void consume_vint64m2_t(vint64m2_t x);

vint64m2_t test_vint64m2_t() {
  // CHECK: define dso_local <vscale x 2 x i64> @test_vint64m2_t() #2 {
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
// CHECK: declare dso_local <vscale x 2 x i64> @generate_vint64m2_t(...) #1
// CHECK: declare dso_local void @consume_vint64m2_t(<vscale x 2 x i64>) #1

// vint32m1_t
vint32m1_t generate_vint32m1_t();
void consume_vint32m1_t(vint32m1_t x);

vint32m1_t test_vint32m1_t() {
  // CHECK: define dso_local <vscale x 1 x i32> @test_vint32m1_t() #3 {
  // CHECK: %x = alloca <vscale x 1 x i32>, align 4
  // CHECK: %call = call <vscale x 1 x i32> bitcast (<vscale x 1 x i32> (...)* @generate_vint32m1_t to <vscale x 1 x i32> ()*)()
  // CHECK: store <vscale x 1 x i32> %call, <vscale x 1 x i32>* %x, align 4
  // CHECK: %0 = load <vscale x 1 x i32>, <vscale x 1 x i32>* %x, align 4
  // CHECK: call void @consume_vint32m1_t(<vscale x 1 x i32> %0)
  // CHECK: %1 = load <vscale x 1 x i32>, <vscale x 1 x i32>* %x, align 4
  // CHECK: ret <vscale x 1 x i32> %1
  vint32m1_t x = generate_vint32m1_t();
  consume_vint32m1_t(x);
  return x;
}
// CHECK: declare dso_local <vscale x 1 x i32> @generate_vint32m1_t(...) #1
// CHECK: declare dso_local void @consume_vint32m1_t(<vscale x 1 x i32>) #1

// vint16m1_t
vint16m1_t generate_vint16m1_t();
void consume_vint16m1_t(vint16m1_t x);

vint16m1_t test_vint16m1_t() {
  // CHECK: define dso_local <vscale x 1 x i16> @test_vint16m1_t() #4 {
  // CHECK: %x = alloca <vscale x 1 x i16>, align 2
  // CHECK: %call = call <vscale x 1 x i16> bitcast (<vscale x 1 x i16> (...)* @generate_vint16m1_t to <vscale x 1 x i16> ()*)()
  // CHECK: store <vscale x 1 x i16> %call, <vscale x 1 x i16>* %x, align 2
  // CHECK: %0 = load <vscale x 1 x i16>, <vscale x 1 x i16>* %x, align 2
  // CHECK: call void @consume_vint16m1_t(<vscale x 1 x i16> %0)
  // CHECK: %1 = load <vscale x 1 x i16>, <vscale x 1 x i16>* %x, align 2
  // CHECK: ret <vscale x 1 x i16> %1
  vint16m1_t x = generate_vint16m1_t();
  consume_vint16m1_t(x);
  return x;
}
// CHECK: declare dso_local <vscale x 1 x i16> @generate_vint16m1_t(...) #1
// CHECK: declare dso_local void @consume_vint16m1_t(<vscale x 1 x i16>) #1

// vint8m1_t
vint8m1_t generate_vint8m1_t();
void consume_vint8m1_t(vint8m1_t x);

vint8m1_t test_vint8m1_t() {
  // CHECK: define dso_local <vscale x 1 x i8> @test_vint8m1_t() #5 {
  // CHECK: %x = alloca <vscale x 1 x i8>, align 1
  // CHECK: %call = call <vscale x 1 x i8> bitcast (<vscale x 1 x i8> (...)* @generate_vint8m1_t to <vscale x 1 x i8> ()*)()
  // CHECK: store <vscale x 1 x i8> %call, <vscale x 1 x i8>* %x, align 1
  // CHECK: %0 = load <vscale x 1 x i8>, <vscale x 1 x i8>* %x, align 1
  // CHECK: call void @consume_vint8m1_t(<vscale x 1 x i8> %0)
  // CHECK: %1 = load <vscale x 1 x i8>, <vscale x 1 x i8>* %x, align 1
  // CHECK: ret <vscale x 1 x i8> %1
  vint8m1_t x = generate_vint8m1_t();
  consume_vint8m1_t(x);
  return x;
}
// CHECK: declare dso_local <vscale x 1 x i8> @generate_vint8m1_t(...) #1
// CHECK: declare dso_local void @consume_vint8m1_t(<vscale x 1 x i8>) #1

// vuint8m1_t
vuint8m1_t generate_vuint8m1_t();
void consume_vuint8m1_t(vuint8m1_t x);

vuint8m1_t test_vuint8m1_t() {
  // CHECK: define dso_local <vscale x 1 x i8> @test_vuint8m1_t() #5 {
  // CHECK: %x = alloca <vscale x 1 x i8>, align 1
  // CHECK: %call = call <vscale x 1 x i8> bitcast (<vscale x 1 x i8> (...)* @generate_vuint8m1_t to <vscale x 1 x i8> ()*)()
  // CHECK: store <vscale x 1 x i8> %call, <vscale x 1 x i8>* %x, align 1
  // CHECK: %0 = load <vscale x 1 x i8>, <vscale x 1 x i8>* %x, align 1
  // CHECK: call void @consume_vuint8m1_t(<vscale x 1 x i8> %0)
  // CHECK: %1 = load <vscale x 1 x i8>, <vscale x 1 x i8>* %x, align 1
  // CHECK: ret <vscale x 1 x i8> %1
  vuint8m1_t x = generate_vuint8m1_t();
  consume_vuint8m1_t(x);
  return x;
}
// CHECK: declare dso_local <vscale x 1 x i8> @generate_vuint8m1_t(...) #1
// CHECK: declare dso_local void @consume_vuint8m1_t(<vscale x 1 x i8>) #1

// vfloat64m1_t
vfloat64m1_t generate_vfloat64m1_t();
void consume_vfloat64m1_t(vfloat64m1_t x);

vfloat64m1_t test_vfloat64m1_t() {
  // CHECK: define dso_local <vscale x 1 x double> @test_vfloat64m1_t() #0 {
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

// CHECK: declare dso_local <vscale x 1 x double> @generate_vfloat64m1_t(...) #1
// CHECK: declare dso_local void @consume_vfloat64m1_t(<vscale x 1 x double>) #1

// vfloat32m1_t
vfloat32m1_t generate_vfloat32m1_t();
void consume_vfloat32m1_t(vfloat32m1_t x);

vfloat32m1_t test_vfloat32m1_t() {
  // CHECK: define dso_local <vscale x 1 x float> @test_vfloat32m1_t() #3 {
  // CHECK: %x = alloca <vscale x 1 x float>, align 4
  // CHECK: %call = call <vscale x 1 x float> bitcast (<vscale x 1 x float> (...)* @generate_vfloat32m1_t to <vscale x 1 x float> ()*)()
  // CHECK: store <vscale x 1 x float> %call, <vscale x 1 x float>* %x, align 4
  // CHECK: %0 = load <vscale x 1 x float>, <vscale x 1 x float>* %x, align 4
  // CHECK: call void @consume_vfloat32m1_t(<vscale x 1 x float> %0)
  // CHECK: %1 = load <vscale x 1 x float>, <vscale x 1 x float>* %x, align 4
  // CHECK: ret <vscale x 1 x float> %1
  vfloat32m1_t x = generate_vfloat32m1_t();
  consume_vfloat32m1_t(x);
  return x;
}
// CHECK: declare dso_local <vscale x 1 x float> @generate_vfloat32m1_t(...) #1
// CHECK: declare dso_local void @consume_vfloat32m1_t(<vscale x 1 x float>) #1

// vfloat16m1_t
vfloat16m1_t generate_vfloat16m1_t();
void consume_vfloat16m1_t(vfloat16m1_t x);

vfloat16m1_t test_vfloat16m1_t() {
  // CHECK: define dso_local <vscale x 1 x half> @test_vfloat16m1_t() #4 {
  // CHECK: %x = alloca <vscale x 1 x half>, align 2
  // CHECK: %call = call <vscale x 1 x half> bitcast (<vscale x 1 x half> (...)* @generate_vfloat16m1_t to <vscale x 1 x half> ()*)()
  // CHECK: store <vscale x 1 x half> %call, <vscale x 1 x half>* %x, align 2
  // CHECK: %0 = load <vscale x 1 x half>, <vscale x 1 x half>* %x, align 2
  // CHECK: call void @consume_vfloat16m1_t(<vscale x 1 x half> %0)
  // CHECK: %1 = load <vscale x 1 x half>, <vscale x 1 x half>* %x, align 2
  // CHECK: ret <vscale x 1 x half> %1
  vfloat16m1_t x = generate_vfloat16m1_t();
  consume_vfloat16m1_t(x);
  return x;
}
// CHECK: declare dso_local <vscale x 1 x half> @generate_vfloat16m1_t(...) #1
// CHECK: declare dso_local void @consume_vfloat16m1_t(<vscale x 1 x half>) #1

