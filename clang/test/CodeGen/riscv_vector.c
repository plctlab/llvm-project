// RUN: %clang --target=riscv32-unknown-linux-gnu -S -emit-llvm -O0 %s -o - | FileCheck %s

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

// vbool64_t
vbool64_t generate_vbool64_t();
void consume_vbool64_t(vbool64_t x);

vbool64_t test_vbool64_t() {
  // CHECK: define dso_local <vscale x 64 x i1> @test_vbool64_t() #0 {
  // CHECK: %x = alloca <vscale x 64 x i1>, align 64
  // CHECK: %call = call <vscale x 64 x i1> bitcast (<vscale x 64 x i1> (...)* @generate_vbool64_t to <vscale x 64 x i1> ()*)()
  // CHECK: store <vscale x 64 x i1> %call, <vscale x 64 x i1>* %x, align 64
  // CHECK: %0 = load <vscale x 64 x i1>, <vscale x 64 x i1>* %x, align 64
  // CHECK: call void @consume_vbool64_t(<vscale x 64 x i1> %0)
  // CHECK: %1 = load <vscale x 64 x i1>, <vscale x 64 x i1>* %x, align 64
  // CHECK: ret <vscale x 64 x i1> %1
  vbool64_t x = generate_vbool64_t();
  consume_vbool64_t(x);
  return x;
}
// CHECK: declare dso_local <vscale x 64 x i1> @generate_vbool64_t(...) #1
// CHECK: declare dso_local void @consume_vbool64_t(<vscale x 64 x i1>) #1

// vbool2_t
vbool2_t generate_vbool2_t();
void consume_vbool2_t(vbool2_t x);

vbool2_t test_vbool2_t() {
  // CHECK: define dso_local <vscale x 2 x i1> @test_vbool2_t() #6 {
  // CHECK: %x = alloca <vscale x 2 x i1>, align 2
  // CHECK: %call = call <vscale x 2 x i1> bitcast (<vscale x 2 x i1> (...)* @generate_vbool2_t to <vscale x 2 x i1> ()*)()
  // CHECK: store <vscale x 2 x i1> %call, <vscale x 2 x i1>* %x, align 2
  // CHECK: %0 = load <vscale x 2 x i1>, <vscale x 2 x i1>* %x, align 2
  // CHECK: call void @consume_vbool2_t(<vscale x 2 x i1> %0)
  // CHECK: %1 = load <vscale x 2 x i1>, <vscale x 2 x i1>* %x, align 2
  // CHECK: ret <vscale x 2 x i1> %1
  vbool2_t x = generate_vbool2_t();
  consume_vbool2_t(x);
  return x;
}
// CHECK: declare dso_local <vscale x 2 x i1> @generate_vbool2_t(...) #1
// CHECK: declare dso_local void @consume_vbool2_t(<vscale x 2 x i1>) #1

// vbool1_t
vbool1_t generate_vbool1_t();
void consume_vbool1_t(vbool1_t x);

vbool1_t test_vbool1_t() {
  // CHECK: define dso_local <vscale x 1 x i1> @test_vbool1_t() #7 {
  // CHECK: %x = alloca <vscale x 1 x i1>, align 1
  // CHECK: %call = call <vscale x 1 x i1> bitcast (<vscale x 1 x i1> (...)* @generate_vbool1_t to <vscale x 1 x i1> ()*)()
  // CHECK: %0 = load <vscale x 1 x i1>, <vscale x 1 x i1>* %x, align 1
  // CHECK: call void @consume_vbool1_t(<vscale x 1 x i1> %0)
  // CHECK: %1 = load <vscale x 1 x i1>, <vscale x 1 x i1>* %x, align 1
  // CHECK: ret <vscale x 1 x i1> %1
  vbool1_t x = generate_vbool1_t();
  consume_vbool1_t(x);
  return x;
}
// CHECK: declare dso_local <vscale x 1 x i1> @generate_vbool1_t(...) #1
// CHECK: declare dso_local void @consume_vbool1_t(<vscale x 1 x i1>) #1

// vint64m1x8_t
vint64m1x8_t generate_vint64m1x8_t();
void consume_vint64m1x8_t(vint64m1x8_t x);

vint64m1x8_t test_vint64m1x8_t() {
  // CHECK: define dso_local void @test_vint64m1x8_t(%struct.vint64m1x8_t* noalias sret align 8 %agg.result) #8 {
  // CHECK: %result.ptr = alloca i8*, align 4
  // CHECK: %byval-temp = alloca %struct.vint64m1x8_t, align 8
  // CHECK: %0 = bitcast %struct.vint64m1x8_t* %agg.result to i8*
  // CHECK: store i8* %0, i8** %result.ptr, align 4
  // CHECK: call void bitcast (void (%struct.vint64m1x8_t*, ...)* @generate_vint64m1x8_t to void (%struct.vint64m1x8_t*)*)(%struct.vint64m1x8_t* sret align 8 %agg.result)
  // CHECK: %1 = bitcast %struct.vint64m1x8_t* %byval-temp to i8*
  // CHECK: %2 = bitcast %struct.vint64m1x8_t* %agg.result to i8*
  // CHECK: call void @llvm.memcpy.p0i8.p0i8.i32(i8* align 8 %1, i8* align 8 %2, i32 64, i1 false)
  // CHECK: call void @consume_vint64m1x8_t(%struct.vint64m1x8_t* %byval-temp)
  // CHECK: ret void
  vint64m1x8_t x = generate_vint64m1x8_t();
  consume_vint64m1x8_t(x);
  return x;
}
// CHECK: declare dso_local void @generate_vint64m1x8_t(%struct.vint64m1x8_t* sret align 8, ...) #1
// CHECK: declare dso_local void @consume_vint64m1x8_t(%struct.vint64m1x8_t*) #1


// vint64m2x4_t
vint64m2x4_t generate_vint64m2x4_t();
void consume_vint64m2x4_t(vint64m2x4_t x);

vint64m2x4_t test_vint64m2x4_t() {
  // CHECK: define dso_local void @test_vint64m2x4_t(%struct.vint64m2x4_t* noalias sret align 16 %agg.result) #8 {
  // CHECK: %result.ptr = alloca i8*, align 4
  // CHECK: %byval-temp = alloca %struct.vint64m2x4_t, align 16
  // CHECK: %0 = bitcast %struct.vint64m2x4_t* %agg.result to i8*
  // CHECK: store i8* %0, i8** %result.ptr, align 4
  // CHECK: call void bitcast (void (%struct.vint64m2x4_t*, ...)* @generate_vint64m2x4_t to void (%struct.vint64m2x4_t*)*)(%struct.vint64m2x4_t* sret align 16 %agg.result)
  // CHECK: %1 = bitcast %struct.vint64m2x4_t* %byval-temp to i8*
  // CHECK: %2 = bitcast %struct.vint64m2x4_t* %agg.result to i8*
  // CHECK: call void @llvm.memcpy.p0i8.p0i8.i32(i8* align 16 %1, i8* align 16 %2, i32 64, i1 false)
  // CHECK: call void @consume_vint64m2x4_t(%struct.vint64m2x4_t* %byval-temp)
  // CHECK: ret void
  vint64m2x4_t x = generate_vint64m2x4_t();
  consume_vint64m2x4_t(x);
  return x;
}
// CHECK: declare dso_local void @generate_vint64m2x4_t(%struct.vint64m2x4_t* sret align 16, ...) #1
// CHECK: declare dso_local void @consume_vint64m2x4_t(%struct.vint64m2x4_t*) #1


// vint64m8x1_t
vint64m8x1_t generate_vint64m8x1_t();
void consume_vint64m8x1_t(vint64m8x1_t x);

vint64m8x1_t test_vint64m8x1_t() {
  // CHECK: define dso_local void @test_vint64m8x1_t(%struct.vint64m8x1_t* noalias sret align 64 %agg.result) #8 {
  // CHECK: %result.ptr = alloca i8*, align 4
  // CHECK: %byval-temp = alloca %struct.vint64m8x1_t, align 64
  // CHECK: %0 = bitcast %struct.vint64m8x1_t* %agg.result to i8*
  // CHECK: store i8* %0, i8** %result.ptr, align 4
  // CHECK: call void bitcast (void (%struct.vint64m8x1_t*, ...)* @generate_vint64m8x1_t to void (%struct.vint64m8x1_t*)*)(%struct.vint64m8x1_t* sret align 64 %agg.result)
  // CHECK: %1 = bitcast %struct.vint64m8x1_t* %byval-temp to i8*
  // CHECK: %2 = bitcast %struct.vint64m8x1_t* %agg.result to i8*
  // CHECK: call void @llvm.memcpy.p0i8.p0i8.i32(i8* align 64 %1, i8* align 64 %2, i32 64, i1 false)
  // CHECK: call void @consume_vint64m8x1_t(%struct.vint64m8x1_t* %byval-temp)
  // CHECK: ret void
  vint64m8x1_t x = generate_vint64m8x1_t();
  consume_vint64m8x1_t(x);
  return x;
}
// CHECK: declare dso_local void @generate_vint64m8x1_t(%struct.vint64m8x1_t* sret align 64, ...) #1
// CHECK: declare dso_local void @consume_vint64m8x1_t(%struct.vint64m8x1_t*) #1
