#ifndef __RISCV_VECTOR_H__
#define __RISCV_VECTOR_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#define _E8 0

#define _E16 4

#define _E32 8

#define _E64 12


#define _M1 0

#define _M2 1

#define _M4 2

#define _M8 3


typedef __attribute__((riscv_vector_type(8, 1, 0))) int vint8m1_t;

typedef __attribute__((riscv_vector_type(8, 2, 0))) int vint8m2_t;

typedef __attribute__((riscv_vector_type(8, 4, 0))) int vint8m4_t;

typedef __attribute__((riscv_vector_type(8, 8, 0))) int vint8m8_t;

typedef __attribute__((riscv_vector_type(16, 1, 0))) int vint16m1_t;

typedef __attribute__((riscv_vector_type(16, 2, 0))) int vint16m2_t;

typedef __attribute__((riscv_vector_type(16, 4, 0))) int vint16m4_t;

typedef __attribute__((riscv_vector_type(16, 8, 0))) int vint16m8_t;

typedef __attribute__((riscv_vector_type(32, 1, 0))) int vint32m1_t;

typedef __attribute__((riscv_vector_type(32, 2, 0))) int vint32m2_t;

typedef __attribute__((riscv_vector_type(32, 4, 0))) int vint32m4_t;

typedef __attribute__((riscv_vector_type(32, 8, 0))) int vint32m8_t;

typedef __attribute__((riscv_vector_type(64, 1, 0))) int vint64m1_t;

typedef __attribute__((riscv_vector_type(64, 2, 0))) int vint64m2_t;

typedef __attribute__((riscv_vector_type(64, 4, 0))) int vint64m4_t;

typedef __attribute__((riscv_vector_type(64, 8, 0))) int vint64m8_t;

typedef __attribute__((riscv_vector_type(8, 1, 0))) unsigned vuint8m1_t;

typedef __attribute__((riscv_vector_type(8, 2, 0))) unsigned vuint8m2_t;

typedef __attribute__((riscv_vector_type(8, 4, 0))) unsigned vuint8m4_t;

typedef __attribute__((riscv_vector_type(8, 8, 0))) unsigned vuint8m8_t;

typedef __attribute__((riscv_vector_type(16, 1, 0))) unsigned vuint16m1_t;

typedef __attribute__((riscv_vector_type(16, 2, 0))) unsigned vuint16m2_t;

typedef __attribute__((riscv_vector_type(16, 4, 0))) unsigned vuint16m4_t;

typedef __attribute__((riscv_vector_type(16, 8, 0))) unsigned vuint16m8_t;

typedef __attribute__((riscv_vector_type(32, 1, 0))) unsigned vuint32m1_t;

typedef __attribute__((riscv_vector_type(32, 2, 0))) unsigned vuint32m2_t;

typedef __attribute__((riscv_vector_type(32, 4, 0))) unsigned vuint32m4_t;

typedef __attribute__((riscv_vector_type(32, 8, 0))) unsigned vuint32m8_t;

typedef __attribute__((riscv_vector_type(64, 1, 0))) unsigned vuint64m1_t;

typedef __attribute__((riscv_vector_type(64, 2, 0))) unsigned vuint64m2_t;

typedef __attribute__((riscv_vector_type(64, 4, 0))) unsigned vuint64m4_t;

typedef __attribute__((riscv_vector_type(64, 8, 0))) unsigned vuint64m8_t;

typedef __attribute__((riscv_vector_type(32, 1, 0))) float vfloat32m1_t;

typedef __attribute__((riscv_vector_type(32, 2, 0))) float vfloat32m2_t;

typedef __attribute__((riscv_vector_type(32, 4, 0))) float vfloat32m4_t;

typedef __attribute__((riscv_vector_type(32, 8, 0))) float vfloat32m8_t;

typedef __attribute__((riscv_vector_type(64, 1, 0))) float vfloat64m1_t;

typedef __attribute__((riscv_vector_type(64, 2, 0))) float vfloat64m2_t;

typedef __attribute__((riscv_vector_type(64, 4, 0))) float vfloat64m4_t;

typedef __attribute__((riscv_vector_type(64, 8, 0))) float vfloat64m8_t;


typedef __attribute__((riscv_mask_type(1))) bool vbool1_t;

typedef __attribute__((riscv_mask_type(2))) bool vbool2_t;

typedef __attribute__((riscv_mask_type(4))) bool vbool4_t;

typedef __attribute__((riscv_mask_type(8))) bool vbool8_t;

typedef __attribute__((riscv_mask_type(16))) bool vbool16_t;

typedef __attribute__((riscv_mask_type(32))) bool vbool32_t;

typedef __attribute__((riscv_mask_type(64))) bool vbool64_t;

typedef float float32_t;
typedef double float64_t;

static __attribute__((always_inline))
size_t vsetvl_e8m1(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E8 | _M1);
}

static __attribute__((always_inline))
size_t vsetvlmax_e8m1() {
  return __builtin_riscv_vsetvlmax(_E8 | _M1);
}

static __attribute__((always_inline))
size_t vsetvl_e8m2(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E8 | _M2);
}

static __attribute__((always_inline))
size_t vsetvlmax_e8m2() {
  return __builtin_riscv_vsetvlmax(_E8 | _M2);
}

static __attribute__((always_inline))
size_t vsetvl_e8m4(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E8 | _M4);
}

static __attribute__((always_inline))
size_t vsetvlmax_e8m4() {
  return __builtin_riscv_vsetvlmax(_E8 | _M4);
}

static __attribute__((always_inline))
size_t vsetvl_e8m8(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E8 | _M8);
}

static __attribute__((always_inline))
size_t vsetvlmax_e8m8() {
  return __builtin_riscv_vsetvlmax(_E8 | _M8);
}

static __attribute__((always_inline))
size_t vsetvl_e16m1(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E16 | _M1);
}

static __attribute__((always_inline))
size_t vsetvlmax_e16m1() {
  return __builtin_riscv_vsetvlmax(_E16 | _M1);
}

static __attribute__((always_inline))
size_t vsetvl_e16m2(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E16 | _M2);
}

static __attribute__((always_inline))
size_t vsetvlmax_e16m2() {
  return __builtin_riscv_vsetvlmax(_E16 | _M2);
}

static __attribute__((always_inline))
size_t vsetvl_e16m4(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E16 | _M4);
}

static __attribute__((always_inline))
size_t vsetvlmax_e16m4() {
  return __builtin_riscv_vsetvlmax(_E16 | _M4);
}

static __attribute__((always_inline))
size_t vsetvl_e16m8(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E16 | _M8);
}

static __attribute__((always_inline))
size_t vsetvlmax_e16m8() {
  return __builtin_riscv_vsetvlmax(_E16 | _M8);
}

static __attribute__((always_inline))
size_t vsetvl_e32m1(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E32 | _M1);
}

static __attribute__((always_inline))
size_t vsetvlmax_e32m1() {
  return __builtin_riscv_vsetvlmax(_E32 | _M1);
}

static __attribute__((always_inline))
size_t vsetvl_e32m2(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E32 | _M2);
}

static __attribute__((always_inline))
size_t vsetvlmax_e32m2() {
  return __builtin_riscv_vsetvlmax(_E32 | _M2);
}

static __attribute__((always_inline))
size_t vsetvl_e32m4(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E32 | _M4);
}

static __attribute__((always_inline))
size_t vsetvlmax_e32m4() {
  return __builtin_riscv_vsetvlmax(_E32 | _M4);
}

static __attribute__((always_inline))
size_t vsetvl_e32m8(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E32 | _M8);
}

static __attribute__((always_inline))
size_t vsetvlmax_e32m8() {
  return __builtin_riscv_vsetvlmax(_E32 | _M8);
}

static __attribute__((always_inline))
size_t vsetvl_e64m1(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E64 | _M1);
}

static __attribute__((always_inline))
size_t vsetvlmax_e64m1() {
  return __builtin_riscv_vsetvlmax(_E64 | _M1);
}

static __attribute__((always_inline))
size_t vsetvl_e64m2(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E64 | _M2);
}

static __attribute__((always_inline))
size_t vsetvlmax_e64m2() {
  return __builtin_riscv_vsetvlmax(_E64 | _M2);
}

static __attribute__((always_inline))
size_t vsetvl_e64m4(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E64 | _M4);
}

static __attribute__((always_inline))
size_t vsetvlmax_e64m4() {
  return __builtin_riscv_vsetvlmax(_E64 | _M4);
}

static __attribute__((always_inline))
size_t vsetvl_e64m8(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E64 | _M8);
}

static __attribute__((always_inline))
size_t vsetvlmax_e64m8() {
  return __builtin_riscv_vsetvlmax(_E64 | _M8);
}

static __attribute__((always_inline))
vint8m1_t vle8_v_i8m1(const int8_t* src) {
  return __builtin_riscv_vle8_v_i8m1(src);
}

static __attribute__((always_inline))
void vse8_v_i8m1(int8_t* base, vint8m1_t value) {
  __builtin_riscv_vse8_v_i8m1(value, base);
}

static __attribute__((always_inline))
vint8m2_t vle8_v_i8m2(const int8_t* src) {
  return __builtin_riscv_vle8_v_i8m2(src);
}

static __attribute__((always_inline))
void vse8_v_i8m2(int8_t* base, vint8m2_t value) {
  __builtin_riscv_vse8_v_i8m2(value, base);
}

static __attribute__((always_inline))
vint8m4_t vle8_v_i8m4(const int8_t* src) {
  return __builtin_riscv_vle8_v_i8m4(src);
}

static __attribute__((always_inline))
void vse8_v_i8m4(int8_t* base, vint8m4_t value) {
  __builtin_riscv_vse8_v_i8m4(value, base);
}

static __attribute__((always_inline))
vint8m8_t vle8_v_i8m8(const int8_t* src) {
  return __builtin_riscv_vle8_v_i8m8(src);
}

static __attribute__((always_inline))
void vse8_v_i8m8(int8_t* base, vint8m8_t value) {
  __builtin_riscv_vse8_v_i8m8(value, base);
}

static __attribute__((always_inline))
vint16m1_t vle16_v_i16m1(const int16_t* src) {
  return __builtin_riscv_vle16_v_i16m1(src);
}

static __attribute__((always_inline))
void vse16_v_i16m1(int16_t* base, vint16m1_t value) {
  __builtin_riscv_vse16_v_i16m1(value, base);
}

static __attribute__((always_inline))
vint16m2_t vle16_v_i16m2(const int16_t* src) {
  return __builtin_riscv_vle16_v_i16m2(src);
}

static __attribute__((always_inline))
void vse16_v_i16m2(int16_t* base, vint16m2_t value) {
  __builtin_riscv_vse16_v_i16m2(value, base);
}

static __attribute__((always_inline))
vint16m4_t vle16_v_i16m4(const int16_t* src) {
  return __builtin_riscv_vle16_v_i16m4(src);
}

static __attribute__((always_inline))
void vse16_v_i16m4(int16_t* base, vint16m4_t value) {
  __builtin_riscv_vse16_v_i16m4(value, base);
}

static __attribute__((always_inline))
vint16m8_t vle16_v_i16m8(const int16_t* src) {
  return __builtin_riscv_vle16_v_i16m8(src);
}

static __attribute__((always_inline))
void vse16_v_i16m8(int16_t* base, vint16m8_t value) {
  __builtin_riscv_vse16_v_i16m8(value, base);
}

static __attribute__((always_inline))
vint32m1_t vle32_v_i32m1(const int32_t* src) {
  return __builtin_riscv_vle32_v_i32m1(src);
}

static __attribute__((always_inline))
void vse32_v_i32m1(int32_t* base, vint32m1_t value) {
  __builtin_riscv_vse32_v_i32m1(value, base);
}

static __attribute__((always_inline))
vint32m2_t vle32_v_i32m2(const int32_t* src) {
  return __builtin_riscv_vle32_v_i32m2(src);
}

static __attribute__((always_inline))
void vse32_v_i32m2(int32_t* base, vint32m2_t value) {
  __builtin_riscv_vse32_v_i32m2(value, base);
}

static __attribute__((always_inline))
vint32m4_t vle32_v_i32m4(const int32_t* src) {
  return __builtin_riscv_vle32_v_i32m4(src);
}

static __attribute__((always_inline))
void vse32_v_i32m4(int32_t* base, vint32m4_t value) {
  __builtin_riscv_vse32_v_i32m4(value, base);
}

static __attribute__((always_inline))
vint32m8_t vle32_v_i32m8(const int32_t* src) {
  return __builtin_riscv_vle32_v_i32m8(src);
}

static __attribute__((always_inline))
void vse32_v_i32m8(int32_t* base, vint32m8_t value) {
  __builtin_riscv_vse32_v_i32m8(value, base);
}

static __attribute__((always_inline))
vint64m1_t vle64_v_i64m1(const int64_t* src) {
  return __builtin_riscv_vle64_v_i64m1(src);
}

static __attribute__((always_inline))
void vse64_v_i64m1(int64_t* base, vint64m1_t value) {
  __builtin_riscv_vse64_v_i64m1(value, base);
}

static __attribute__((always_inline))
vint64m2_t vle64_v_i64m2(const int64_t* src) {
  return __builtin_riscv_vle64_v_i64m2(src);
}

static __attribute__((always_inline))
void vse64_v_i64m2(int64_t* base, vint64m2_t value) {
  __builtin_riscv_vse64_v_i64m2(value, base);
}

static __attribute__((always_inline))
vint64m4_t vle64_v_i64m4(const int64_t* src) {
  return __builtin_riscv_vle64_v_i64m4(src);
}

static __attribute__((always_inline))
void vse64_v_i64m4(int64_t* base, vint64m4_t value) {
  __builtin_riscv_vse64_v_i64m4(value, base);
}

static __attribute__((always_inline))
vint64m8_t vle64_v_i64m8(const int64_t* src) {
  return __builtin_riscv_vle64_v_i64m8(src);
}

static __attribute__((always_inline))
void vse64_v_i64m8(int64_t* base, vint64m8_t value) {
  __builtin_riscv_vse64_v_i64m8(value, base);
}

static __attribute__((always_inline))
vuint8m1_t vle8_v_u8m1(const uint8_t* src) {
  return __builtin_riscv_vle8_v_u8m1(src);
}

static __attribute__((always_inline))
void vse8_v_u8m1(uint8_t* base, vuint8m1_t value) {
  __builtin_riscv_vse8_v_u8m1(value, base);
}

static __attribute__((always_inline))
vuint8m2_t vle8_v_u8m2(const uint8_t* src) {
  return __builtin_riscv_vle8_v_u8m2(src);
}

static __attribute__((always_inline))
void vse8_v_u8m2(uint8_t* base, vuint8m2_t value) {
  __builtin_riscv_vse8_v_u8m2(value, base);
}

static __attribute__((always_inline))
vuint8m4_t vle8_v_u8m4(const uint8_t* src) {
  return __builtin_riscv_vle8_v_u8m4(src);
}

static __attribute__((always_inline))
void vse8_v_u8m4(uint8_t* base, vuint8m4_t value) {
  __builtin_riscv_vse8_v_u8m4(value, base);
}

static __attribute__((always_inline))
vuint8m8_t vle8_v_u8m8(const uint8_t* src) {
  return __builtin_riscv_vle8_v_u8m8(src);
}

static __attribute__((always_inline))
void vse8_v_u8m8(uint8_t* base, vuint8m8_t value) {
  __builtin_riscv_vse8_v_u8m8(value, base);
}

static __attribute__((always_inline))
vuint16m1_t vle16_v_u16m1(const uint16_t* src) {
  return __builtin_riscv_vle16_v_u16m1(src);
}

static __attribute__((always_inline))
void vse16_v_u16m1(uint16_t* base, vuint16m1_t value) {
  __builtin_riscv_vse16_v_u16m1(value, base);
}

static __attribute__((always_inline))
vuint16m2_t vle16_v_u16m2(const uint16_t* src) {
  return __builtin_riscv_vle16_v_u16m2(src);
}

static __attribute__((always_inline))
void vse16_v_u16m2(uint16_t* base, vuint16m2_t value) {
  __builtin_riscv_vse16_v_u16m2(value, base);
}

static __attribute__((always_inline))
vuint16m4_t vle16_v_u16m4(const uint16_t* src) {
  return __builtin_riscv_vle16_v_u16m4(src);
}

static __attribute__((always_inline))
void vse16_v_u16m4(uint16_t* base, vuint16m4_t value) {
  __builtin_riscv_vse16_v_u16m4(value, base);
}

static __attribute__((always_inline))
vuint16m8_t vle16_v_u16m8(const uint16_t* src) {
  return __builtin_riscv_vle16_v_u16m8(src);
}

static __attribute__((always_inline))
void vse16_v_u16m8(uint16_t* base, vuint16m8_t value) {
  __builtin_riscv_vse16_v_u16m8(value, base);
}

static __attribute__((always_inline))
vuint32m1_t vle32_v_u32m1(const uint32_t* src) {
  return __builtin_riscv_vle32_v_u32m1(src);
}

static __attribute__((always_inline))
void vse32_v_u32m1(uint32_t* base, vuint32m1_t value) {
  __builtin_riscv_vse32_v_u32m1(value, base);
}

static __attribute__((always_inline))
vuint32m2_t vle32_v_u32m2(const uint32_t* src) {
  return __builtin_riscv_vle32_v_u32m2(src);
}

static __attribute__((always_inline))
void vse32_v_u32m2(uint32_t* base, vuint32m2_t value) {
  __builtin_riscv_vse32_v_u32m2(value, base);
}

static __attribute__((always_inline))
vuint32m4_t vle32_v_u32m4(const uint32_t* src) {
  return __builtin_riscv_vle32_v_u32m4(src);
}

static __attribute__((always_inline))
void vse32_v_u32m4(uint32_t* base, vuint32m4_t value) {
  __builtin_riscv_vse32_v_u32m4(value, base);
}

static __attribute__((always_inline))
vuint32m8_t vle32_v_u32m8(const uint32_t* src) {
  return __builtin_riscv_vle32_v_u32m8(src);
}

static __attribute__((always_inline))
void vse32_v_u32m8(uint32_t* base, vuint32m8_t value) {
  __builtin_riscv_vse32_v_u32m8(value, base);
}

static __attribute__((always_inline))
vuint64m1_t vle64_v_u64m1(const uint64_t* src) {
  return __builtin_riscv_vle64_v_u64m1(src);
}

static __attribute__((always_inline))
void vse64_v_u64m1(uint64_t* base, vuint64m1_t value) {
  __builtin_riscv_vse64_v_u64m1(value, base);
}

static __attribute__((always_inline))
vuint64m2_t vle64_v_u64m2(const uint64_t* src) {
  return __builtin_riscv_vle64_v_u64m2(src);
}

static __attribute__((always_inline))
void vse64_v_u64m2(uint64_t* base, vuint64m2_t value) {
  __builtin_riscv_vse64_v_u64m2(value, base);
}

static __attribute__((always_inline))
vuint64m4_t vle64_v_u64m4(const uint64_t* src) {
  return __builtin_riscv_vle64_v_u64m4(src);
}

static __attribute__((always_inline))
void vse64_v_u64m4(uint64_t* base, vuint64m4_t value) {
  __builtin_riscv_vse64_v_u64m4(value, base);
}

static __attribute__((always_inline))
vuint64m8_t vle64_v_u64m8(const uint64_t* src) {
  return __builtin_riscv_vle64_v_u64m8(src);
}

static __attribute__((always_inline))
void vse64_v_u64m8(uint64_t* base, vuint64m8_t value) {
  __builtin_riscv_vse64_v_u64m8(value, base);
}

static __attribute__((always_inline))
vfloat32m1_t vle32_v_f32m1(const float* src) {
  return __builtin_riscv_vle32_v_f32m1(src);
}

static __attribute__((always_inline))
void vse32_v_f32m1(float* base, vfloat32m1_t value) {
  __builtin_riscv_vse32_v_f32m1(value, base);
}

static __attribute__((always_inline))
vfloat32m2_t vle32_v_f32m2(const float* src) {
  return __builtin_riscv_vle32_v_f32m2(src);
}

static __attribute__((always_inline))
void vse32_v_f32m2(float* base, vfloat32m2_t value) {
  __builtin_riscv_vse32_v_f32m2(value, base);
}

static __attribute__((always_inline))
vfloat32m4_t vle32_v_f32m4(const float* src) {
  return __builtin_riscv_vle32_v_f32m4(src);
}

static __attribute__((always_inline))
void vse32_v_f32m4(float* base, vfloat32m4_t value) {
  __builtin_riscv_vse32_v_f32m4(value, base);
}

static __attribute__((always_inline))
vfloat32m8_t vle32_v_f32m8(const float* src) {
  return __builtin_riscv_vle32_v_f32m8(src);
}

static __attribute__((always_inline))
void vse32_v_f32m8(float* base, vfloat32m8_t value) {
  __builtin_riscv_vse32_v_f32m8(value, base);
}

static __attribute__((always_inline))
vfloat64m1_t vle64_v_f64m1(const double* src) {
  return __builtin_riscv_vle64_v_f64m1(src);
}

static __attribute__((always_inline))
void vse64_v_f64m1(double* base, vfloat64m1_t value) {
  __builtin_riscv_vse64_v_f64m1(value, base);
}

static __attribute__((always_inline))
vfloat64m2_t vle64_v_f64m2(const double* src) {
  return __builtin_riscv_vle64_v_f64m2(src);
}

static __attribute__((always_inline))
void vse64_v_f64m2(double* base, vfloat64m2_t value) {
  __builtin_riscv_vse64_v_f64m2(value, base);
}

static __attribute__((always_inline))
vfloat64m4_t vle64_v_f64m4(const double* src) {
  return __builtin_riscv_vle64_v_f64m4(src);
}

static __attribute__((always_inline))
void vse64_v_f64m4(double* base, vfloat64m4_t value) {
  __builtin_riscv_vse64_v_f64m4(value, base);
}

static __attribute__((always_inline))
vfloat64m8_t vle64_v_f64m8(const double* src) {
  return __builtin_riscv_vle64_v_f64m8(src);
}

static __attribute__((always_inline))
void vse64_v_f64m8(double* base, vfloat64m8_t value) {
  __builtin_riscv_vse64_v_f64m8(value, base);
}

static __attribute__((always_inline))
int8_t vmv_x_s_i8m1_i8(vint8m1_t src) {
  return __builtin_riscv_vmv_x_s_i8m1_i8(src);
}

static __attribute__((always_inline))
vint8m1_t vmv_s_x_i8m1(vint8m1_t dst, int8_t src) {
  return __builtin_riscv_vmv_s_x_i8m1(dst, src);
}

static __attribute__((always_inline))
int8_t vmv_x_s_i8m2_i8(vint8m2_t src) {
  return __builtin_riscv_vmv_x_s_i8m2_i8(src);
}

static __attribute__((always_inline))
vint8m2_t vmv_s_x_i8m2(vint8m2_t dst, int8_t src) {
  return __builtin_riscv_vmv_s_x_i8m2(dst, src);
}

static __attribute__((always_inline))
int8_t vmv_x_s_i8m4_i8(vint8m4_t src) {
  return __builtin_riscv_vmv_x_s_i8m4_i8(src);
}

static __attribute__((always_inline))
vint8m4_t vmv_s_x_i8m4(vint8m4_t dst, int8_t src) {
  return __builtin_riscv_vmv_s_x_i8m4(dst, src);
}

static __attribute__((always_inline))
int8_t vmv_x_s_i8m8_i8(vint8m8_t src) {
  return __builtin_riscv_vmv_x_s_i8m8_i8(src);
}

static __attribute__((always_inline))
vint8m8_t vmv_s_x_i8m8(vint8m8_t dst, int8_t src) {
  return __builtin_riscv_vmv_s_x_i8m8(dst, src);
}

static __attribute__((always_inline))
int16_t vmv_x_s_i16m1_i16(vint16m1_t src) {
  return __builtin_riscv_vmv_x_s_i16m1_i16(src);
}

static __attribute__((always_inline))
vint16m1_t vmv_s_x_i16m1(vint16m1_t dst, int16_t src) {
  return __builtin_riscv_vmv_s_x_i16m1(dst, src);
}

static __attribute__((always_inline))
int16_t vmv_x_s_i16m2_i16(vint16m2_t src) {
  return __builtin_riscv_vmv_x_s_i16m2_i16(src);
}

static __attribute__((always_inline))
vint16m2_t vmv_s_x_i16m2(vint16m2_t dst, int16_t src) {
  return __builtin_riscv_vmv_s_x_i16m2(dst, src);
}

static __attribute__((always_inline))
int16_t vmv_x_s_i16m4_i16(vint16m4_t src) {
  return __builtin_riscv_vmv_x_s_i16m4_i16(src);
}

static __attribute__((always_inline))
vint16m4_t vmv_s_x_i16m4(vint16m4_t dst, int16_t src) {
  return __builtin_riscv_vmv_s_x_i16m4(dst, src);
}

static __attribute__((always_inline))
int16_t vmv_x_s_i16m8_i16(vint16m8_t src) {
  return __builtin_riscv_vmv_x_s_i16m8_i16(src);
}

static __attribute__((always_inline))
vint16m8_t vmv_s_x_i16m8(vint16m8_t dst, int16_t src) {
  return __builtin_riscv_vmv_s_x_i16m8(dst, src);
}

static __attribute__((always_inline))
int32_t vmv_x_s_i32m1_i32(vint32m1_t src) {
  return __builtin_riscv_vmv_x_s_i32m1_i32(src);
}

static __attribute__((always_inline))
vint32m1_t vmv_s_x_i32m1(vint32m1_t dst, int32_t src) {
  return __builtin_riscv_vmv_s_x_i32m1(dst, src);
}

static __attribute__((always_inline))
int32_t vmv_x_s_i32m2_i32(vint32m2_t src) {
  return __builtin_riscv_vmv_x_s_i32m2_i32(src);
}

static __attribute__((always_inline))
vint32m2_t vmv_s_x_i32m2(vint32m2_t dst, int32_t src) {
  return __builtin_riscv_vmv_s_x_i32m2(dst, src);
}

static __attribute__((always_inline))
int32_t vmv_x_s_i32m4_i32(vint32m4_t src) {
  return __builtin_riscv_vmv_x_s_i32m4_i32(src);
}

static __attribute__((always_inline))
vint32m4_t vmv_s_x_i32m4(vint32m4_t dst, int32_t src) {
  return __builtin_riscv_vmv_s_x_i32m4(dst, src);
}

static __attribute__((always_inline))
int32_t vmv_x_s_i32m8_i32(vint32m8_t src) {
  return __builtin_riscv_vmv_x_s_i32m8_i32(src);
}

static __attribute__((always_inline))
vint32m8_t vmv_s_x_i32m8(vint32m8_t dst, int32_t src) {
  return __builtin_riscv_vmv_s_x_i32m8(dst, src);
}

static __attribute__((always_inline))
int64_t vmv_x_s_i64m1_i64(vint64m1_t src) {
  return __builtin_riscv_vmv_x_s_i64m1_i64(src);
}

static __attribute__((always_inline))
vint64m1_t vmv_s_x_i64m1(vint64m1_t dst, int64_t src) {
  return __builtin_riscv_vmv_s_x_i64m1(dst, src);
}

static __attribute__((always_inline))
int64_t vmv_x_s_i64m2_i64(vint64m2_t src) {
  return __builtin_riscv_vmv_x_s_i64m2_i64(src);
}

static __attribute__((always_inline))
vint64m2_t vmv_s_x_i64m2(vint64m2_t dst, int64_t src) {
  return __builtin_riscv_vmv_s_x_i64m2(dst, src);
}

static __attribute__((always_inline))
int64_t vmv_x_s_i64m4_i64(vint64m4_t src) {
  return __builtin_riscv_vmv_x_s_i64m4_i64(src);
}

static __attribute__((always_inline))
vint64m4_t vmv_s_x_i64m4(vint64m4_t dst, int64_t src) {
  return __builtin_riscv_vmv_s_x_i64m4(dst, src);
}

static __attribute__((always_inline))
int64_t vmv_x_s_i64m8_i64(vint64m8_t src) {
  return __builtin_riscv_vmv_x_s_i64m8_i64(src);
}

static __attribute__((always_inline))
vint64m8_t vmv_s_x_i64m8(vint64m8_t dst, int64_t src) {
  return __builtin_riscv_vmv_s_x_i64m8(dst, src);
}

static __attribute__((always_inline))
uint8_t vmv_x_s_u8m1_u8(vuint8m1_t src) {
  return __builtin_riscv_vmv_x_s_u8m1_u8(src);
}

static __attribute__((always_inline))
vuint8m1_t vmv_s_x_u8m1(vuint8m1_t dst, uint8_t src) {
  return __builtin_riscv_vmv_s_x_u8m1(dst, src);
}

static __attribute__((always_inline))
uint8_t vmv_x_s_u8m2_u8(vuint8m2_t src) {
  return __builtin_riscv_vmv_x_s_u8m2_u8(src);
}

static __attribute__((always_inline))
vuint8m2_t vmv_s_x_u8m2(vuint8m2_t dst, uint8_t src) {
  return __builtin_riscv_vmv_s_x_u8m2(dst, src);
}

static __attribute__((always_inline))
uint8_t vmv_x_s_u8m4_u8(vuint8m4_t src) {
  return __builtin_riscv_vmv_x_s_u8m4_u8(src);
}

static __attribute__((always_inline))
vuint8m4_t vmv_s_x_u8m4(vuint8m4_t dst, uint8_t src) {
  return __builtin_riscv_vmv_s_x_u8m4(dst, src);
}

static __attribute__((always_inline))
uint8_t vmv_x_s_u8m8_u8(vuint8m8_t src) {
  return __builtin_riscv_vmv_x_s_u8m8_u8(src);
}

static __attribute__((always_inline))
vuint8m8_t vmv_s_x_u8m8(vuint8m8_t dst, uint8_t src) {
  return __builtin_riscv_vmv_s_x_u8m8(dst, src);
}

static __attribute__((always_inline))
uint16_t vmv_x_s_u16m1_u16(vuint16m1_t src) {
  return __builtin_riscv_vmv_x_s_u16m1_u16(src);
}

static __attribute__((always_inline))
vuint16m1_t vmv_s_x_u16m1(vuint16m1_t dst, uint16_t src) {
  return __builtin_riscv_vmv_s_x_u16m1(dst, src);
}

static __attribute__((always_inline))
uint16_t vmv_x_s_u16m2_u16(vuint16m2_t src) {
  return __builtin_riscv_vmv_x_s_u16m2_u16(src);
}

static __attribute__((always_inline))
vuint16m2_t vmv_s_x_u16m2(vuint16m2_t dst, uint16_t src) {
  return __builtin_riscv_vmv_s_x_u16m2(dst, src);
}

static __attribute__((always_inline))
uint16_t vmv_x_s_u16m4_u16(vuint16m4_t src) {
  return __builtin_riscv_vmv_x_s_u16m4_u16(src);
}

static __attribute__((always_inline))
vuint16m4_t vmv_s_x_u16m4(vuint16m4_t dst, uint16_t src) {
  return __builtin_riscv_vmv_s_x_u16m4(dst, src);
}

static __attribute__((always_inline))
uint16_t vmv_x_s_u16m8_u16(vuint16m8_t src) {
  return __builtin_riscv_vmv_x_s_u16m8_u16(src);
}

static __attribute__((always_inline))
vuint16m8_t vmv_s_x_u16m8(vuint16m8_t dst, uint16_t src) {
  return __builtin_riscv_vmv_s_x_u16m8(dst, src);
}

static __attribute__((always_inline))
uint32_t vmv_x_s_u32m1_u32(vuint32m1_t src) {
  return __builtin_riscv_vmv_x_s_u32m1_u32(src);
}

static __attribute__((always_inline))
vuint32m1_t vmv_s_x_u32m1(vuint32m1_t dst, uint32_t src) {
  return __builtin_riscv_vmv_s_x_u32m1(dst, src);
}

static __attribute__((always_inline))
uint32_t vmv_x_s_u32m2_u32(vuint32m2_t src) {
  return __builtin_riscv_vmv_x_s_u32m2_u32(src);
}

static __attribute__((always_inline))
vuint32m2_t vmv_s_x_u32m2(vuint32m2_t dst, uint32_t src) {
  return __builtin_riscv_vmv_s_x_u32m2(dst, src);
}

static __attribute__((always_inline))
uint32_t vmv_x_s_u32m4_u32(vuint32m4_t src) {
  return __builtin_riscv_vmv_x_s_u32m4_u32(src);
}

static __attribute__((always_inline))
vuint32m4_t vmv_s_x_u32m4(vuint32m4_t dst, uint32_t src) {
  return __builtin_riscv_vmv_s_x_u32m4(dst, src);
}

static __attribute__((always_inline))
uint32_t vmv_x_s_u32m8_u32(vuint32m8_t src) {
  return __builtin_riscv_vmv_x_s_u32m8_u32(src);
}

static __attribute__((always_inline))
vuint32m8_t vmv_s_x_u32m8(vuint32m8_t dst, uint32_t src) {
  return __builtin_riscv_vmv_s_x_u32m8(dst, src);
}

static __attribute__((always_inline))
uint64_t vmv_x_s_u64m1_u64(vuint64m1_t src) {
  return __builtin_riscv_vmv_x_s_u64m1_u64(src);
}

static __attribute__((always_inline))
vuint64m1_t vmv_s_x_u64m1(vuint64m1_t dst, uint64_t src) {
  return __builtin_riscv_vmv_s_x_u64m1(dst, src);
}

static __attribute__((always_inline))
uint64_t vmv_x_s_u64m2_u64(vuint64m2_t src) {
  return __builtin_riscv_vmv_x_s_u64m2_u64(src);
}

static __attribute__((always_inline))
vuint64m2_t vmv_s_x_u64m2(vuint64m2_t dst, uint64_t src) {
  return __builtin_riscv_vmv_s_x_u64m2(dst, src);
}

static __attribute__((always_inline))
uint64_t vmv_x_s_u64m4_u64(vuint64m4_t src) {
  return __builtin_riscv_vmv_x_s_u64m4_u64(src);
}

static __attribute__((always_inline))
vuint64m4_t vmv_s_x_u64m4(vuint64m4_t dst, uint64_t src) {
  return __builtin_riscv_vmv_s_x_u64m4(dst, src);
}

static __attribute__((always_inline))
uint64_t vmv_x_s_u64m8_u64(vuint64m8_t src) {
  return __builtin_riscv_vmv_x_s_u64m8_u64(src);
}

static __attribute__((always_inline))
vuint64m8_t vmv_s_x_u64m8(vuint64m8_t dst, uint64_t src) {
  return __builtin_riscv_vmv_s_x_u64m8(dst, src);
}

static __attribute__((always_inline))
float vfmv_f_s_f32m1_f32(vfloat32m1_t src) {
  return __builtin_riscv_vfmv_f_s_f32m1_f32(src);
}

static __attribute__((always_inline))
vfloat32m1_t vfmv_s_f_f32m1(vfloat32m1_t dst, float src) {
  return __builtin_riscv_vfmv_s_f_f32m1(dst, src);
}

static __attribute__((always_inline))
float vfmv_f_s_f32m2_f32(vfloat32m2_t src) {
  return __builtin_riscv_vfmv_f_s_f32m2_f32(src);
}

static __attribute__((always_inline))
vfloat32m2_t vfmv_s_f_f32m2(vfloat32m2_t dst, float src) {
  return __builtin_riscv_vfmv_s_f_f32m2(dst, src);
}

static __attribute__((always_inline))
float vfmv_f_s_f32m4_f32(vfloat32m4_t src) {
  return __builtin_riscv_vfmv_f_s_f32m4_f32(src);
}

static __attribute__((always_inline))
vfloat32m4_t vfmv_s_f_f32m4(vfloat32m4_t dst, float src) {
  return __builtin_riscv_vfmv_s_f_f32m4(dst, src);
}

static __attribute__((always_inline))
float vfmv_f_s_f32m8_f32(vfloat32m8_t src) {
  return __builtin_riscv_vfmv_f_s_f32m8_f32(src);
}

static __attribute__((always_inline))
vfloat32m8_t vfmv_s_f_f32m8(vfloat32m8_t dst, float src) {
  return __builtin_riscv_vfmv_s_f_f32m8(dst, src);
}

static __attribute__((always_inline))
double vfmv_f_s_f64m1_f64(vfloat64m1_t src) {
  return __builtin_riscv_vfmv_f_s_f64m1_f64(src);
}

static __attribute__((always_inline))
vfloat64m1_t vfmv_s_f_f64m1(vfloat64m1_t dst, double src) {
  return __builtin_riscv_vfmv_s_f_f64m1(dst, src);
}

static __attribute__((always_inline))
double vfmv_f_s_f64m2_f64(vfloat64m2_t src) {
  return __builtin_riscv_vfmv_f_s_f64m2_f64(src);
}

static __attribute__((always_inline))
vfloat64m2_t vfmv_s_f_f64m2(vfloat64m2_t dst, double src) {
  return __builtin_riscv_vfmv_s_f_f64m2(dst, src);
}

static __attribute__((always_inline))
double vfmv_f_s_f64m4_f64(vfloat64m4_t src) {
  return __builtin_riscv_vfmv_f_s_f64m4_f64(src);
}

static __attribute__((always_inline))
vfloat64m4_t vfmv_s_f_f64m4(vfloat64m4_t dst, double src) {
  return __builtin_riscv_vfmv_s_f_f64m4(dst, src);
}

static __attribute__((always_inline))
double vfmv_f_s_f64m8_f64(vfloat64m8_t src) {
  return __builtin_riscv_vfmv_f_s_f64m8_f64(src);
}

static __attribute__((always_inline))
vfloat64m8_t vfmv_s_f_f64m8(vfloat64m8_t dst, double src) {
  return __builtin_riscv_vfmv_s_f_f64m8(dst, src);
}

static __attribute__((always_inline))
vint8m1_t vzero_i8m1() {
  return __builtin_riscv_vzero_i8m1();
}

static __attribute__((always_inline))
vint8m1_t vundefined_i8m1() {
  return __builtin_riscv_vundefined_i8m1();
}

static __attribute__((always_inline))
vint8m2_t vzero_i8m2() {
  return __builtin_riscv_vzero_i8m2();
}

static __attribute__((always_inline))
vint8m2_t vundefined_i8m2() {
  return __builtin_riscv_vundefined_i8m2();
}

static __attribute__((always_inline))
vint8m4_t vzero_i8m4() {
  return __builtin_riscv_vzero_i8m4();
}

static __attribute__((always_inline))
vint8m4_t vundefined_i8m4() {
  return __builtin_riscv_vundefined_i8m4();
}

static __attribute__((always_inline))
vint8m8_t vzero_i8m8() {
  return __builtin_riscv_vzero_i8m8();
}

static __attribute__((always_inline))
vint8m8_t vundefined_i8m8() {
  return __builtin_riscv_vundefined_i8m8();
}

static __attribute__((always_inline))
vint16m1_t vzero_i16m1() {
  return __builtin_riscv_vzero_i16m1();
}

static __attribute__((always_inline))
vint16m1_t vundefined_i16m1() {
  return __builtin_riscv_vundefined_i16m1();
}

static __attribute__((always_inline))
vint16m2_t vzero_i16m2() {
  return __builtin_riscv_vzero_i16m2();
}

static __attribute__((always_inline))
vint16m2_t vundefined_i16m2() {
  return __builtin_riscv_vundefined_i16m2();
}

static __attribute__((always_inline))
vint16m4_t vzero_i16m4() {
  return __builtin_riscv_vzero_i16m4();
}

static __attribute__((always_inline))
vint16m4_t vundefined_i16m4() {
  return __builtin_riscv_vundefined_i16m4();
}

static __attribute__((always_inline))
vint16m8_t vzero_i16m8() {
  return __builtin_riscv_vzero_i16m8();
}

static __attribute__((always_inline))
vint16m8_t vundefined_i16m8() {
  return __builtin_riscv_vundefined_i16m8();
}

static __attribute__((always_inline))
vint32m1_t vzero_i32m1() {
  return __builtin_riscv_vzero_i32m1();
}

static __attribute__((always_inline))
vint32m1_t vundefined_i32m1() {
  return __builtin_riscv_vundefined_i32m1();
}

static __attribute__((always_inline))
vint32m2_t vzero_i32m2() {
  return __builtin_riscv_vzero_i32m2();
}

static __attribute__((always_inline))
vint32m2_t vundefined_i32m2() {
  return __builtin_riscv_vundefined_i32m2();
}

static __attribute__((always_inline))
vint32m4_t vzero_i32m4() {
  return __builtin_riscv_vzero_i32m4();
}

static __attribute__((always_inline))
vint32m4_t vundefined_i32m4() {
  return __builtin_riscv_vundefined_i32m4();
}

static __attribute__((always_inline))
vint32m8_t vzero_i32m8() {
  return __builtin_riscv_vzero_i32m8();
}

static __attribute__((always_inline))
vint32m8_t vundefined_i32m8() {
  return __builtin_riscv_vundefined_i32m8();
}

static __attribute__((always_inline))
vint64m1_t vzero_i64m1() {
  return __builtin_riscv_vzero_i64m1();
}

static __attribute__((always_inline))
vint64m1_t vundefined_i64m1() {
  return __builtin_riscv_vundefined_i64m1();
}

static __attribute__((always_inline))
vint64m2_t vzero_i64m2() {
  return __builtin_riscv_vzero_i64m2();
}

static __attribute__((always_inline))
vint64m2_t vundefined_i64m2() {
  return __builtin_riscv_vundefined_i64m2();
}

static __attribute__((always_inline))
vint64m4_t vzero_i64m4() {
  return __builtin_riscv_vzero_i64m4();
}

static __attribute__((always_inline))
vint64m4_t vundefined_i64m4() {
  return __builtin_riscv_vundefined_i64m4();
}

static __attribute__((always_inline))
vint64m8_t vzero_i64m8() {
  return __builtin_riscv_vzero_i64m8();
}

static __attribute__((always_inline))
vint64m8_t vundefined_i64m8() {
  return __builtin_riscv_vundefined_i64m8();
}

static __attribute__((always_inline))
vuint8m1_t vzero_u8m1() {
  return __builtin_riscv_vzero_u8m1();
}

static __attribute__((always_inline))
vuint8m1_t vundefined_u8m1() {
  return __builtin_riscv_vundefined_u8m1();
}

static __attribute__((always_inline))
vuint8m2_t vzero_u8m2() {
  return __builtin_riscv_vzero_u8m2();
}

static __attribute__((always_inline))
vuint8m2_t vundefined_u8m2() {
  return __builtin_riscv_vundefined_u8m2();
}

static __attribute__((always_inline))
vuint8m4_t vzero_u8m4() {
  return __builtin_riscv_vzero_u8m4();
}

static __attribute__((always_inline))
vuint8m4_t vundefined_u8m4() {
  return __builtin_riscv_vundefined_u8m4();
}

static __attribute__((always_inline))
vuint8m8_t vzero_u8m8() {
  return __builtin_riscv_vzero_u8m8();
}

static __attribute__((always_inline))
vuint8m8_t vundefined_u8m8() {
  return __builtin_riscv_vundefined_u8m8();
}

static __attribute__((always_inline))
vuint16m1_t vzero_u16m1() {
  return __builtin_riscv_vzero_u16m1();
}

static __attribute__((always_inline))
vuint16m1_t vundefined_u16m1() {
  return __builtin_riscv_vundefined_u16m1();
}

static __attribute__((always_inline))
vuint16m2_t vzero_u16m2() {
  return __builtin_riscv_vzero_u16m2();
}

static __attribute__((always_inline))
vuint16m2_t vundefined_u16m2() {
  return __builtin_riscv_vundefined_u16m2();
}

static __attribute__((always_inline))
vuint16m4_t vzero_u16m4() {
  return __builtin_riscv_vzero_u16m4();
}

static __attribute__((always_inline))
vuint16m4_t vundefined_u16m4() {
  return __builtin_riscv_vundefined_u16m4();
}

static __attribute__((always_inline))
vuint16m8_t vzero_u16m8() {
  return __builtin_riscv_vzero_u16m8();
}

static __attribute__((always_inline))
vuint16m8_t vundefined_u16m8() {
  return __builtin_riscv_vundefined_u16m8();
}

static __attribute__((always_inline))
vuint32m1_t vzero_u32m1() {
  return __builtin_riscv_vzero_u32m1();
}

static __attribute__((always_inline))
vuint32m1_t vundefined_u32m1() {
  return __builtin_riscv_vundefined_u32m1();
}

static __attribute__((always_inline))
vuint32m2_t vzero_u32m2() {
  return __builtin_riscv_vzero_u32m2();
}

static __attribute__((always_inline))
vuint32m2_t vundefined_u32m2() {
  return __builtin_riscv_vundefined_u32m2();
}

static __attribute__((always_inline))
vuint32m4_t vzero_u32m4() {
  return __builtin_riscv_vzero_u32m4();
}

static __attribute__((always_inline))
vuint32m4_t vundefined_u32m4() {
  return __builtin_riscv_vundefined_u32m4();
}

static __attribute__((always_inline))
vuint32m8_t vzero_u32m8() {
  return __builtin_riscv_vzero_u32m8();
}

static __attribute__((always_inline))
vuint32m8_t vundefined_u32m8() {
  return __builtin_riscv_vundefined_u32m8();
}

static __attribute__((always_inline))
vuint64m1_t vzero_u64m1() {
  return __builtin_riscv_vzero_u64m1();
}

static __attribute__((always_inline))
vuint64m1_t vundefined_u64m1() {
  return __builtin_riscv_vundefined_u64m1();
}

static __attribute__((always_inline))
vuint64m2_t vzero_u64m2() {
  return __builtin_riscv_vzero_u64m2();
}

static __attribute__((always_inline))
vuint64m2_t vundefined_u64m2() {
  return __builtin_riscv_vundefined_u64m2();
}

static __attribute__((always_inline))
vuint64m4_t vzero_u64m4() {
  return __builtin_riscv_vzero_u64m4();
}

static __attribute__((always_inline))
vuint64m4_t vundefined_u64m4() {
  return __builtin_riscv_vundefined_u64m4();
}

static __attribute__((always_inline))
vuint64m8_t vzero_u64m8() {
  return __builtin_riscv_vzero_u64m8();
}

static __attribute__((always_inline))
vuint64m8_t vundefined_u64m8() {
  return __builtin_riscv_vundefined_u64m8();
}

static __attribute__((always_inline))
vfloat32m1_t vzero_f32m1() {
  return __builtin_riscv_vzero_f32m1();
}

static __attribute__((always_inline))
vfloat32m1_t vundefined_f32m1() {
  return __builtin_riscv_vundefined_f32m1();
}

static __attribute__((always_inline))
vfloat32m2_t vzero_f32m2() {
  return __builtin_riscv_vzero_f32m2();
}

static __attribute__((always_inline))
vfloat32m2_t vundefined_f32m2() {
  return __builtin_riscv_vundefined_f32m2();
}

static __attribute__((always_inline))
vfloat32m4_t vzero_f32m4() {
  return __builtin_riscv_vzero_f32m4();
}

static __attribute__((always_inline))
vfloat32m4_t vundefined_f32m4() {
  return __builtin_riscv_vundefined_f32m4();
}

static __attribute__((always_inline))
vfloat32m8_t vzero_f32m8() {
  return __builtin_riscv_vzero_f32m8();
}

static __attribute__((always_inline))
vfloat32m8_t vundefined_f32m8() {
  return __builtin_riscv_vundefined_f32m8();
}

static __attribute__((always_inline))
vfloat64m1_t vzero_f64m1() {
  return __builtin_riscv_vzero_f64m1();
}

static __attribute__((always_inline))
vfloat64m1_t vundefined_f64m1() {
  return __builtin_riscv_vundefined_f64m1();
}

static __attribute__((always_inline))
vfloat64m2_t vzero_f64m2() {
  return __builtin_riscv_vzero_f64m2();
}

static __attribute__((always_inline))
vfloat64m2_t vundefined_f64m2() {
  return __builtin_riscv_vundefined_f64m2();
}

static __attribute__((always_inline))
vfloat64m4_t vzero_f64m4() {
  return __builtin_riscv_vzero_f64m4();
}

static __attribute__((always_inline))
vfloat64m4_t vundefined_f64m4() {
  return __builtin_riscv_vundefined_f64m4();
}

static __attribute__((always_inline))
vfloat64m8_t vzero_f64m8() {
  return __builtin_riscv_vzero_f64m8();
}

static __attribute__((always_inline))
vfloat64m8_t vundefined_f64m8() {
  return __builtin_riscv_vundefined_f64m8();
}

static __attribute__((always_inline))
vint8m1_t vmv_v_v_i8m1(vint8m1_t src) {
  return __builtin_riscv_vmv_v_v_i8m1(src);
}

static __attribute__((always_inline))
vint8m1_t vmv_v_x_i8m1(int8_t src) {
  return __builtin_riscv_vmv_v_x_i8m1(src);
}

static __attribute__((always_inline))
vint8m2_t vmv_v_v_i8m2(vint8m2_t src) {
  return __builtin_riscv_vmv_v_v_i8m2(src);
}

static __attribute__((always_inline))
vint8m2_t vmv_v_x_i8m2(int8_t src) {
  return __builtin_riscv_vmv_v_x_i8m2(src);
}

static __attribute__((always_inline))
vint8m4_t vmv_v_v_i8m4(vint8m4_t src) {
  return __builtin_riscv_vmv_v_v_i8m4(src);
}

static __attribute__((always_inline))
vint8m4_t vmv_v_x_i8m4(int8_t src) {
  return __builtin_riscv_vmv_v_x_i8m4(src);
}

static __attribute__((always_inline))
vint8m8_t vmv_v_v_i8m8(vint8m8_t src) {
  return __builtin_riscv_vmv_v_v_i8m8(src);
}

static __attribute__((always_inline))
vint8m8_t vmv_v_x_i8m8(int8_t src) {
  return __builtin_riscv_vmv_v_x_i8m8(src);
}

static __attribute__((always_inline))
vint16m1_t vmv_v_v_i16m1(vint16m1_t src) {
  return __builtin_riscv_vmv_v_v_i16m1(src);
}

static __attribute__((always_inline))
vint16m1_t vmv_v_x_i16m1(int16_t src) {
  return __builtin_riscv_vmv_v_x_i16m1(src);
}

static __attribute__((always_inline))
vint16m2_t vmv_v_v_i16m2(vint16m2_t src) {
  return __builtin_riscv_vmv_v_v_i16m2(src);
}

static __attribute__((always_inline))
vint16m2_t vmv_v_x_i16m2(int16_t src) {
  return __builtin_riscv_vmv_v_x_i16m2(src);
}

static __attribute__((always_inline))
vint16m4_t vmv_v_v_i16m4(vint16m4_t src) {
  return __builtin_riscv_vmv_v_v_i16m4(src);
}

static __attribute__((always_inline))
vint16m4_t vmv_v_x_i16m4(int16_t src) {
  return __builtin_riscv_vmv_v_x_i16m4(src);
}

static __attribute__((always_inline))
vint16m8_t vmv_v_v_i16m8(vint16m8_t src) {
  return __builtin_riscv_vmv_v_v_i16m8(src);
}

static __attribute__((always_inline))
vint16m8_t vmv_v_x_i16m8(int16_t src) {
  return __builtin_riscv_vmv_v_x_i16m8(src);
}

static __attribute__((always_inline))
vint32m1_t vmv_v_v_i32m1(vint32m1_t src) {
  return __builtin_riscv_vmv_v_v_i32m1(src);
}

static __attribute__((always_inline))
vint32m1_t vmv_v_x_i32m1(int32_t src) {
  return __builtin_riscv_vmv_v_x_i32m1(src);
}

static __attribute__((always_inline))
vint32m2_t vmv_v_v_i32m2(vint32m2_t src) {
  return __builtin_riscv_vmv_v_v_i32m2(src);
}

static __attribute__((always_inline))
vint32m2_t vmv_v_x_i32m2(int32_t src) {
  return __builtin_riscv_vmv_v_x_i32m2(src);
}

static __attribute__((always_inline))
vint32m4_t vmv_v_v_i32m4(vint32m4_t src) {
  return __builtin_riscv_vmv_v_v_i32m4(src);
}

static __attribute__((always_inline))
vint32m4_t vmv_v_x_i32m4(int32_t src) {
  return __builtin_riscv_vmv_v_x_i32m4(src);
}

static __attribute__((always_inline))
vint32m8_t vmv_v_v_i32m8(vint32m8_t src) {
  return __builtin_riscv_vmv_v_v_i32m8(src);
}

static __attribute__((always_inline))
vint32m8_t vmv_v_x_i32m8(int32_t src) {
  return __builtin_riscv_vmv_v_x_i32m8(src);
}

static __attribute__((always_inline))
vint64m1_t vmv_v_v_i64m1(vint64m1_t src) {
  return __builtin_riscv_vmv_v_v_i64m1(src);
}

static __attribute__((always_inline))
vint64m1_t vmv_v_x_i64m1(int64_t src) {
  return __builtin_riscv_vmv_v_x_i64m1(src);
}

static __attribute__((always_inline))
vint64m2_t vmv_v_v_i64m2(vint64m2_t src) {
  return __builtin_riscv_vmv_v_v_i64m2(src);
}

static __attribute__((always_inline))
vint64m2_t vmv_v_x_i64m2(int64_t src) {
  return __builtin_riscv_vmv_v_x_i64m2(src);
}

static __attribute__((always_inline))
vint64m4_t vmv_v_v_i64m4(vint64m4_t src) {
  return __builtin_riscv_vmv_v_v_i64m4(src);
}

static __attribute__((always_inline))
vint64m4_t vmv_v_x_i64m4(int64_t src) {
  return __builtin_riscv_vmv_v_x_i64m4(src);
}

static __attribute__((always_inline))
vint64m8_t vmv_v_v_i64m8(vint64m8_t src) {
  return __builtin_riscv_vmv_v_v_i64m8(src);
}

static __attribute__((always_inline))
vint64m8_t vmv_v_x_i64m8(int64_t src) {
  return __builtin_riscv_vmv_v_x_i64m8(src);
}

static __attribute__((always_inline))
vuint8m1_t vmv_v_v_u8m1(vuint8m1_t src) {
  return __builtin_riscv_vmv_v_v_u8m1(src);
}

static __attribute__((always_inline))
vuint8m1_t vmv_v_x_u8m1(uint8_t src) {
  return __builtin_riscv_vmv_v_x_u8m1(src);
}

static __attribute__((always_inline))
vuint8m2_t vmv_v_v_u8m2(vuint8m2_t src) {
  return __builtin_riscv_vmv_v_v_u8m2(src);
}

static __attribute__((always_inline))
vuint8m2_t vmv_v_x_u8m2(uint8_t src) {
  return __builtin_riscv_vmv_v_x_u8m2(src);
}

static __attribute__((always_inline))
vuint8m4_t vmv_v_v_u8m4(vuint8m4_t src) {
  return __builtin_riscv_vmv_v_v_u8m4(src);
}

static __attribute__((always_inline))
vuint8m4_t vmv_v_x_u8m4(uint8_t src) {
  return __builtin_riscv_vmv_v_x_u8m4(src);
}

static __attribute__((always_inline))
vuint8m8_t vmv_v_v_u8m8(vuint8m8_t src) {
  return __builtin_riscv_vmv_v_v_u8m8(src);
}

static __attribute__((always_inline))
vuint8m8_t vmv_v_x_u8m8(uint8_t src) {
  return __builtin_riscv_vmv_v_x_u8m8(src);
}

static __attribute__((always_inline))
vuint16m1_t vmv_v_v_u16m1(vuint16m1_t src) {
  return __builtin_riscv_vmv_v_v_u16m1(src);
}

static __attribute__((always_inline))
vuint16m1_t vmv_v_x_u16m1(uint16_t src) {
  return __builtin_riscv_vmv_v_x_u16m1(src);
}

static __attribute__((always_inline))
vuint16m2_t vmv_v_v_u16m2(vuint16m2_t src) {
  return __builtin_riscv_vmv_v_v_u16m2(src);
}

static __attribute__((always_inline))
vuint16m2_t vmv_v_x_u16m2(uint16_t src) {
  return __builtin_riscv_vmv_v_x_u16m2(src);
}

static __attribute__((always_inline))
vuint16m4_t vmv_v_v_u16m4(vuint16m4_t src) {
  return __builtin_riscv_vmv_v_v_u16m4(src);
}

static __attribute__((always_inline))
vuint16m4_t vmv_v_x_u16m4(uint16_t src) {
  return __builtin_riscv_vmv_v_x_u16m4(src);
}

static __attribute__((always_inline))
vuint16m8_t vmv_v_v_u16m8(vuint16m8_t src) {
  return __builtin_riscv_vmv_v_v_u16m8(src);
}

static __attribute__((always_inline))
vuint16m8_t vmv_v_x_u16m8(uint16_t src) {
  return __builtin_riscv_vmv_v_x_u16m8(src);
}

static __attribute__((always_inline))
vuint32m1_t vmv_v_v_u32m1(vuint32m1_t src) {
  return __builtin_riscv_vmv_v_v_u32m1(src);
}

static __attribute__((always_inline))
vuint32m1_t vmv_v_x_u32m1(uint32_t src) {
  return __builtin_riscv_vmv_v_x_u32m1(src);
}

static __attribute__((always_inline))
vuint32m2_t vmv_v_v_u32m2(vuint32m2_t src) {
  return __builtin_riscv_vmv_v_v_u32m2(src);
}

static __attribute__((always_inline))
vuint32m2_t vmv_v_x_u32m2(uint32_t src) {
  return __builtin_riscv_vmv_v_x_u32m2(src);
}

static __attribute__((always_inline))
vuint32m4_t vmv_v_v_u32m4(vuint32m4_t src) {
  return __builtin_riscv_vmv_v_v_u32m4(src);
}

static __attribute__((always_inline))
vuint32m4_t vmv_v_x_u32m4(uint32_t src) {
  return __builtin_riscv_vmv_v_x_u32m4(src);
}

static __attribute__((always_inline))
vuint32m8_t vmv_v_v_u32m8(vuint32m8_t src) {
  return __builtin_riscv_vmv_v_v_u32m8(src);
}

static __attribute__((always_inline))
vuint32m8_t vmv_v_x_u32m8(uint32_t src) {
  return __builtin_riscv_vmv_v_x_u32m8(src);
}

static __attribute__((always_inline))
vuint64m1_t vmv_v_v_u64m1(vuint64m1_t src) {
  return __builtin_riscv_vmv_v_v_u64m1(src);
}

static __attribute__((always_inline))
vuint64m1_t vmv_v_x_u64m1(uint64_t src) {
  return __builtin_riscv_vmv_v_x_u64m1(src);
}

static __attribute__((always_inline))
vuint64m2_t vmv_v_v_u64m2(vuint64m2_t src) {
  return __builtin_riscv_vmv_v_v_u64m2(src);
}

static __attribute__((always_inline))
vuint64m2_t vmv_v_x_u64m2(uint64_t src) {
  return __builtin_riscv_vmv_v_x_u64m2(src);
}

static __attribute__((always_inline))
vuint64m4_t vmv_v_v_u64m4(vuint64m4_t src) {
  return __builtin_riscv_vmv_v_v_u64m4(src);
}

static __attribute__((always_inline))
vuint64m4_t vmv_v_x_u64m4(uint64_t src) {
  return __builtin_riscv_vmv_v_x_u64m4(src);
}

static __attribute__((always_inline))
vuint64m8_t vmv_v_v_u64m8(vuint64m8_t src) {
  return __builtin_riscv_vmv_v_v_u64m8(src);
}

static __attribute__((always_inline))
vuint64m8_t vmv_v_x_u64m8(uint64_t src) {
  return __builtin_riscv_vmv_v_x_u64m8(src);
}

static __attribute__((always_inline))
vfloat32m1_t vmv_v_v_f32m1(vfloat32m1_t src) {
  return __builtin_riscv_vmv_v_v_f32m1(src);
}

static __attribute__((always_inline))
vfloat32m1_t vfmv_v_f_f32m1(float src) {
  return __builtin_riscv_vfmv_v_f_f32m1(src);
}

static __attribute__((always_inline))
vfloat32m2_t vmv_v_v_f32m2(vfloat32m2_t src) {
  return __builtin_riscv_vmv_v_v_f32m2(src);
}

static __attribute__((always_inline))
vfloat32m2_t vfmv_v_f_f32m2(float src) {
  return __builtin_riscv_vfmv_v_f_f32m2(src);
}

static __attribute__((always_inline))
vfloat32m4_t vmv_v_v_f32m4(vfloat32m4_t src) {
  return __builtin_riscv_vmv_v_v_f32m4(src);
}

static __attribute__((always_inline))
vfloat32m4_t vfmv_v_f_f32m4(float src) {
  return __builtin_riscv_vfmv_v_f_f32m4(src);
}

static __attribute__((always_inline))
vfloat32m8_t vmv_v_v_f32m8(vfloat32m8_t src) {
  return __builtin_riscv_vmv_v_v_f32m8(src);
}

static __attribute__((always_inline))
vfloat32m8_t vfmv_v_f_f32m8(float src) {
  return __builtin_riscv_vfmv_v_f_f32m8(src);
}

static __attribute__((always_inline))
vfloat64m1_t vmv_v_v_f64m1(vfloat64m1_t src) {
  return __builtin_riscv_vmv_v_v_f64m1(src);
}

static __attribute__((always_inline))
vfloat64m1_t vfmv_v_f_f64m1(double src) {
  return __builtin_riscv_vfmv_v_f_f64m1(src);
}

static __attribute__((always_inline))
vfloat64m2_t vmv_v_v_f64m2(vfloat64m2_t src) {
  return __builtin_riscv_vmv_v_v_f64m2(src);
}

static __attribute__((always_inline))
vfloat64m2_t vfmv_v_f_f64m2(double src) {
  return __builtin_riscv_vfmv_v_f_f64m2(src);
}

static __attribute__((always_inline))
vfloat64m4_t vmv_v_v_f64m4(vfloat64m4_t src) {
  return __builtin_riscv_vmv_v_v_f64m4(src);
}

static __attribute__((always_inline))
vfloat64m4_t vfmv_v_f_f64m4(double src) {
  return __builtin_riscv_vfmv_v_f_f64m4(src);
}

static __attribute__((always_inline))
vfloat64m8_t vmv_v_v_f64m8(vfloat64m8_t src) {
  return __builtin_riscv_vmv_v_v_f64m8(src);
}

static __attribute__((always_inline))
vfloat64m8_t vfmv_v_f_f64m8(double src) {
  return __builtin_riscv_vfmv_v_f_f64m8(src);
}

static __attribute__((always_inline))
vint8m1_t vreinterpret_v_u8m1_i8m1(vuint8m1_t src) {
  uint8_t* base;
  vse8_v_u8m1(base, src);
  return vle8_v_i8m1((int8_t*)base);
}

static __attribute__((always_inline))
vuint8m1_t vreinterpret_v_i8m1_u8m1(vint8m1_t src) {
  int8_t* base;
  vse8_v_i8m1(base, src);
  return vle8_v_u8m1((uint8_t*)base);
}

static __attribute__((always_inline))
vint8m2_t vreinterpret_i8_u8_i8m2(vuint8m2_t src) {
  return __builtin_riscv_vreinterpret_i8_u8_i8m2(src);
}

static __attribute__((always_inline))
vuint8m2_t vreinterpret_u8_i8_u8m2(vint8m2_t src) {
  return __builtin_riscv_vreinterpret_u8_i8_u8m2(src);
}

static __attribute__((always_inline))
vint8m4_t vreinterpret_i8_u8_i8m4(vuint8m4_t src) {
  return __builtin_riscv_vreinterpret_i8_u8_i8m4(src);
}

static __attribute__((always_inline))
vuint8m4_t vreinterpret_u8_i8_u8m4(vint8m4_t src) {
  return __builtin_riscv_vreinterpret_u8_i8_u8m4(src);
}

static __attribute__((always_inline))
vint8m8_t vreinterpret_i8_u8_i8m8(vuint8m8_t src) {
  return __builtin_riscv_vreinterpret_i8_u8_i8m8(src);
}

static __attribute__((always_inline))
vuint8m8_t vreinterpret_u8_i8_u8m8(vint8m8_t src) {
  return __builtin_riscv_vreinterpret_u8_i8_u8m8(src);
}

static __attribute__((always_inline))
vint16m1_t vreinterpret_v_u16m1_i16m1(vuint16m1_t src) {
  uint16_t* base;
  vse16_v_u16m1(base, src);
  return vle16_v_i16m1((int16_t*)base);
}

static __attribute__((always_inline))
vuint16m1_t vreinterpret_v_i16m1_u16m1(vint16m1_t src) {
  int16_t* base;
  vse16_v_i16m1(base, src);
  return vle16_v_u16m1((uint16_t*)base);
}

static __attribute__((always_inline))
vint16m2_t vreinterpret_v_u16m1_i16m2(vuint16m2_t src) {
  return __builtin_riscv_vreinterpret_i16_u16_i16m2(src);
}

static __attribute__((always_inline))
vuint16m2_t vreinterpret_u16_i16_u16m2(vint16m2_t src) {
  return __builtin_riscv_vreinterpret_u16_i16_u16m2(src);
}

static __attribute__((always_inline))
vint16m4_t vreinterpret_i16_u16_i16m4(vuint16m4_t src) {
  return __builtin_riscv_vreinterpret_i16_u16_i16m4(src);
}

static __attribute__((always_inline))
vuint16m4_t vreinterpret_u16_i16_u16m4(vint16m4_t src) {
  return __builtin_riscv_vreinterpret_u16_i16_u16m4(src);
}

static __attribute__((always_inline))
vint16m8_t vreinterpret_i16_u16_i16m8(vuint16m8_t src) {
  return __builtin_riscv_vreinterpret_i16_u16_i16m8(src);
}

static __attribute__((always_inline))
vuint16m8_t vreinterpret_u16_i16_u16m8(vint16m8_t src) {
  return __builtin_riscv_vreinterpret_u16_i16_u16m8(src);
}

static __attribute__((always_inline))
vuint32m1_t vreinterpret_v_f32m1_u32m1(vfloat32m1_t src) {
  float* base;
  vse32_v_f32m1(base, src);
  return vle32_v_u32m1((uint32_t*)base);
}

static __attribute__((always_inline))
vfloat32m1_t vreinterpret_v_u32m1_f32m1(vuint32m1_t src) {
  uint32_t* base;
  vse32_v_u32m1(base, src);
  return vle32_v_f32m1((float*)base);
}

static __attribute__((always_inline))
vint32m1_t vreinterpret_v_f32m1_i32m1(vfloat32m1_t src) {
  float* base;
  vse32_v_f32m1(base, src);
  return vle32_v_i32m1((int32_t*)base);
}

static __attribute__((always_inline))
vfloat32m1_t vreinterpret_v_i32m1_f32m1(vint32m1_t src) {
  int32_t* base;
  vse32_v_i32m1(base, src);
  return vle32_v_f32m1((float*)base);
}

static __attribute__((always_inline))
vint32m1_t vreinterpret_v_u32m1_i32m1(vuint32m1_t src) {
  uint32_t* base;
  vse32_v_u32m1(base, src);
  return vle32_v_i32m1((int32_t*)base);
}

static __attribute__((always_inline))
vuint32m1_t vreinterpret_v_i32m1_u32m1(vint32m1_t src) {
  int32_t* base;
  vse32_v_i32m1(base, src);
  return vle32_v_u32m1((uint32_t*)base);
}

static __attribute__((always_inline))
vuint32m2_t vreinterpret_u32_f32_u32m2(vfloat32m2_t src) {
  return __builtin_riscv_vreinterpret_u32_f32_u32m2(src);
}

static __attribute__((always_inline))
vfloat32m2_t vreinterpret_f32_u32_f32m2(vuint32m2_t src) {
  return __builtin_riscv_vreinterpret_f32_u32_f32m2(src);
}

static __attribute__((always_inline))
vint32m2_t vreinterpret_i32_f32_i32m2(vfloat32m2_t src) {
  return __builtin_riscv_vreinterpret_i32_f32_i32m2(src);
}

static __attribute__((always_inline))
vfloat32m2_t vreinterpret_f32_i32_f32m2(vint32m2_t src) {
  return __builtin_riscv_vreinterpret_f32_i32_f32m2(src);
}

static __attribute__((always_inline))
vint32m2_t vreinterpret_i32_u32_i32m2(vuint32m2_t src) {
  return __builtin_riscv_vreinterpret_i32_u32_i32m2(src);
}

static __attribute__((always_inline))
vuint32m2_t vreinterpret_u32_i32_u32m2(vint32m2_t src) {
  return __builtin_riscv_vreinterpret_u32_i32_u32m2(src);
}

static __attribute__((always_inline))
vuint32m4_t vreinterpret_u32_f32_u32m4(vfloat32m4_t src) {
  return __builtin_riscv_vreinterpret_u32_f32_u32m4(src);
}

static __attribute__((always_inline))
vfloat32m4_t vreinterpret_f32_u32_f32m4(vuint32m4_t src) {
  return __builtin_riscv_vreinterpret_f32_u32_f32m4(src);
}

static __attribute__((always_inline))
vint32m4_t vreinterpret_i32_f32_i32m4(vfloat32m4_t src) {
  return __builtin_riscv_vreinterpret_i32_f32_i32m4(src);
}

static __attribute__((always_inline))
vfloat32m4_t vreinterpret_f32_i32_f32m4(vint32m4_t src) {
  return __builtin_riscv_vreinterpret_f32_i32_f32m4(src);
}

static __attribute__((always_inline))
vint32m4_t vreinterpret_i32_u32_i32m4(vuint32m4_t src) {
  return __builtin_riscv_vreinterpret_i32_u32_i32m4(src);
}

static __attribute__((always_inline))
vuint32m4_t vreinterpret_u32_i32_u32m4(vint32m4_t src) {
  return __builtin_riscv_vreinterpret_u32_i32_u32m4(src);
}

static __attribute__((always_inline))
vuint32m8_t vreinterpret_u32_f32_u32m8(vfloat32m8_t src) {
  return __builtin_riscv_vreinterpret_u32_f32_u32m8(src);
}

static __attribute__((always_inline))
vfloat32m8_t vreinterpret_f32_u32_f32m8(vuint32m8_t src) {
  return __builtin_riscv_vreinterpret_f32_u32_f32m8(src);
}

static __attribute__((always_inline))
vint32m8_t vreinterpret_i32_f32_i32m8(vfloat32m8_t src) {
  return __builtin_riscv_vreinterpret_i32_f32_i32m8(src);
}

static __attribute__((always_inline))
vfloat32m8_t vreinterpret_f32_i32_f32m8(vint32m8_t src) {
  return __builtin_riscv_vreinterpret_f32_i32_f32m8(src);
}

static __attribute__((always_inline))
vint32m8_t vreinterpret_i32_u32_i32m8(vuint32m8_t src) {
  return __builtin_riscv_vreinterpret_i32_u32_i32m8(src);
}

static __attribute__((always_inline))
vuint32m8_t vreinterpret_u32_i32_u32m8(vint32m8_t src) {
  return __builtin_riscv_vreinterpret_u32_i32_u32m8(src);
}

static __attribute__((always_inline))
vuint64m1_t vreinterpret_u64_f64_u64m1(vfloat64m1_t src) {
  double* base;
  vse64_v_f64m1(base, src);
  return vle64_v_u64m1((uint64_t*)base);
}

static __attribute__((always_inline))
vfloat64m1_t vreinterpret_f64_u64_f64m1(vuint64m1_t src) {
  uint64_t* base;
  vse64_v_u64m1(base, src);
  return vle64_v_f64m1((double*)base);
}

static __attribute__((always_inline))
vint64m1_t vreinterpret_i64_f64_i64m1(vfloat64m1_t src) {
  double* base;
  vse64_v_f64m1(base, src);
  return vle64_v_i64m1((int64_t*)base);
}

static __attribute__((always_inline))
vfloat64m1_t vreinterpret_f64_i64_f64m1(vint64m1_t src) {
  int64_t* base;
  vse64_v_i64m1(base, src);
  return vle64_v_f64m1((double*)base);
}

static __attribute__((always_inline))
vint64m1_t vreinterpret_v_u64m1_i64m1(vuint64m1_t src) {
  uint64_t* base;
  vse64_v_u64m1(base, src);
  return vle64_v_i64m1((int64_t*)base);
}

static __attribute__((always_inline))
vuint64m1_t vreinterpret_v_i64m1_u64m1(vint64m1_t src) {
  int64_t* base;
  vse64_v_i64m1(base, src);
  return vle64_v_u64m1((uint64_t*)base);
}

static __attribute__((always_inline))
vuint64m2_t vreinterpret_u64_f64_u64m2(vfloat64m2_t src) {
  return __builtin_riscv_vreinterpret_u64_f64_u64m2(src);
}

static __attribute__((always_inline))
vfloat64m2_t vreinterpret_f64_u64_f64m2(vuint64m2_t src) {
  return __builtin_riscv_vreinterpret_f64_u64_f64m2(src);
}

static __attribute__((always_inline))
vint64m2_t vreinterpret_i64_f64_i64m2(vfloat64m2_t src) {
  return __builtin_riscv_vreinterpret_i64_f64_i64m2(src);
}

static __attribute__((always_inline))
vfloat64m2_t vreinterpret_f64_i64_f64m2(vint64m2_t src) {
  return __builtin_riscv_vreinterpret_f64_i64_f64m2(src);
}

static __attribute__((always_inline))
vint64m2_t vreinterpret_i64_u64_i64m2(vuint64m2_t src) {
  return __builtin_riscv_vreinterpret_i64_u64_i64m2(src);
}

static __attribute__((always_inline))
vuint64m2_t vreinterpret_u64_i64_u64m2(vint64m2_t src) {
  return __builtin_riscv_vreinterpret_u64_i64_u64m2(src);
}

static __attribute__((always_inline))
vuint64m4_t vreinterpret_u64_f64_u64m4(vfloat64m4_t src) {
  return __builtin_riscv_vreinterpret_u64_f64_u64m4(src);
}

static __attribute__((always_inline))
vfloat64m4_t vreinterpret_f64_u64_f64m4(vuint64m4_t src) {
  return __builtin_riscv_vreinterpret_f64_u64_f64m4(src);
}

static __attribute__((always_inline))
vint64m4_t vreinterpret_i64_f64_i64m4(vfloat64m4_t src) {
  return __builtin_riscv_vreinterpret_i64_f64_i64m4(src);
}

static __attribute__((always_inline))
vfloat64m4_t vreinterpret_f64_i64_f64m4(vint64m4_t src) {
  return __builtin_riscv_vreinterpret_f64_i64_f64m4(src);
}

static __attribute__((always_inline))
vint64m4_t vreinterpret_i64_u64_i64m4(vuint64m4_t src) {
  return __builtin_riscv_vreinterpret_i64_u64_i64m4(src);
}

static __attribute__((always_inline))
vuint64m4_t vreinterpret_u64_i64_u64m4(vint64m4_t src) {
  return __builtin_riscv_vreinterpret_u64_i64_u64m4(src);
}

static __attribute__((always_inline))
vuint64m8_t vreinterpret_u64_f64_u64m8(vfloat64m8_t src) {
  return __builtin_riscv_vreinterpret_u64_f64_u64m8(src);
}

static __attribute__((always_inline))
vfloat64m8_t vreinterpret_f64_u64_f64m8(vuint64m8_t src) {
  return __builtin_riscv_vreinterpret_f64_u64_f64m8(src);
}

static __attribute__((always_inline))
vint64m8_t vreinterpret_i64_f64_i64m8(vfloat64m8_t src) {
  return __builtin_riscv_vreinterpret_i64_f64_i64m8(src);
}

static __attribute__((always_inline))
vfloat64m8_t vreinterpret_f64_i64_f64m8(vint64m8_t src) {
  return __builtin_riscv_vreinterpret_f64_i64_f64m8(src);
}

static __attribute__((always_inline))
vint64m8_t vreinterpret_i64_u64_i64m8(vuint64m8_t src) {
  return __builtin_riscv_vreinterpret_i64_u64_i64m8(src);
}

static __attribute__((always_inline))
vuint64m8_t vreinterpret_u64_i64_u64m8(vint64m8_t src) {
  return __builtin_riscv_vreinterpret_u64_i64_u64m8(src);
}

static __attribute__((always_inline))
vint32m1_t vreinterpret_v_i64m1_i32m1(vint64m1_t src) {
  int64_t* base;
  vse64_v_i64m1(base, src);
  return vle32_v_i32m1((int32_t*)base);
}

static __attribute__((always_inline))
vint64m1_t vreinterpret_v_i32m1_i64m1(vint32m1_t src) {
  int32_t* base;
  vse32_v_i32m1(base, src);
  return vle64_v_i64m1((int64_t*)base);
}

static __attribute__((always_inline))
vint16m1_t vreinterpret_v_i64m1_i16m1(vint64m1_t src) {
  int64_t* base;
  vse64_v_i64m1(base, src);
  return vle16_v_i16m1((int16_t*)base);
}

static __attribute__((always_inline))
vint64m1_t vreinterpret_v_i16m1_i64m1(vint16m1_t src) {
  int16_t* base;
  vse16_v_i16m1(base, src);
  return vle64_v_i64m1((int64_t*)base);
}

static __attribute__((always_inline))
vint8m1_t vreinterpret_v_i64m1_i8m1(vint64m1_t src) {
  int64_t* base;
  vse64_v_i64m1(base, src);
  return vle8_v_i8m1((int8_t*)base);
}

static __attribute__((always_inline))
vint64m1_t vreinterpret_v_i8m1_i64m1(vint8m1_t src) {
  int8_t* base;
  vse8_v_i8m1(base, src);
  return vle64_v_i64m1((int64_t*)base);
}

static __attribute__((always_inline))
vint16m1_t vreinterpret_v_i32m1_i16m1(vint32m1_t src) {
  int32_t* base;
  vse32_v_i32m1(base, src);
  return vle16_v_i16m1((int16_t*)base);
}

static __attribute__((always_inline))
vint32m1_t vreinterpret_v_i16m1_i32m1(vint16m1_t src) {
  int16_t* base;
  vse16_v_i16m1(base, src);
  return vle32_v_i32m1((int32_t*)base);
}

static __attribute__((always_inline))
vint8m1_t vreinterpret_v_i32m1_i8m1(vint32m1_t src) {
  int32_t* base;
  vse32_v_i32m1(base, src);
  return vle8_v_i8m1((int8_t*)base);
}

static __attribute__((always_inline))
vint32m1_t vreinterpret_v_i8m1_i32m1(vint8m1_t src) {
  int8_t* base;
  vse8_v_i8m1(base, src);
  return vle32_v_i32m1((int32_t*)base);
}

static __attribute__((always_inline))
vint8m1_t vreinterpret_v_i16m1_i8m1(vint16m1_t src) {
  int16_t* base;
  vse16_v_i16m1(base, src);
  return vle8_v_i8m1((int8_t*)base);
}

static __attribute__((always_inline))
vint16m1_t vreinterpret_v_i8m1_i16m1(vint8m1_t src) {
  int8_t* base;
  vse8_v_i8m1(base, src);
  return vle16_v_i16m1((int16_t*)base);
}

static __attribute__((always_inline))
vint32m2_t vreinterpret_i32_i64_i32m2(vint64m2_t src) {
  return __builtin_riscv_vreinterpret_i32_i64_i32m2(src);
}

static __attribute__((always_inline))
vint64m2_t vreinterpret_i64_i32_i64m2(vint32m2_t src) {
  return __builtin_riscv_vreinterpret_i64_i32_i64m2(src);
}

static __attribute__((always_inline))
vint16m2_t vreinterpret_i16_i64_i16m2(vint64m2_t src) {
  return __builtin_riscv_vreinterpret_i16_i64_i16m2(src);
}

static __attribute__((always_inline))
vint64m2_t vreinterpret_i64_i16_i64m2(vint16m2_t src) {
  return __builtin_riscv_vreinterpret_i64_i16_i64m2(src);
}

static __attribute__((always_inline))
vint8m2_t vreinterpret_i8_i64_i8m2(vint64m2_t src) {
  return __builtin_riscv_vreinterpret_i8_i64_i8m2(src);
}

static __attribute__((always_inline))
vint64m2_t vreinterpret_i64_i8_i64m2(vint8m2_t src) {
  return __builtin_riscv_vreinterpret_i64_i8_i64m2(src);
}

static __attribute__((always_inline))
vint16m2_t vreinterpret_i16_i32_i16m2(vint32m2_t src) {
  return __builtin_riscv_vreinterpret_i16_i32_i16m2(src);
}

static __attribute__((always_inline))
vint32m2_t vreinterpret_i32_i16_i32m2(vint16m2_t src) {
  return __builtin_riscv_vreinterpret_i32_i16_i32m2(src);
}

static __attribute__((always_inline))
vint8m2_t vreinterpret_i8_i32_i8m2(vint32m2_t src) {
  return __builtin_riscv_vreinterpret_i8_i32_i8m2(src);
}

static __attribute__((always_inline))
vint32m2_t vreinterpret_i32_i8_i32m2(vint8m2_t src) {
  return __builtin_riscv_vreinterpret_i32_i8_i32m2(src);
}

static __attribute__((always_inline))
vint8m2_t vreinterpret_i8_i16_i8m2(vint16m2_t src) {
  return __builtin_riscv_vreinterpret_i8_i16_i8m2(src);
}

static __attribute__((always_inline))
vint16m2_t vreinterpret_i16_i8_i16m2(vint8m2_t src) {
  return __builtin_riscv_vreinterpret_i16_i8_i16m2(src);
}

static __attribute__((always_inline))
vint32m4_t vreinterpret_i32_i64_i32m4(vint64m4_t src) {
  return __builtin_riscv_vreinterpret_i32_i64_i32m4(src);
}

static __attribute__((always_inline))
vint64m4_t vreinterpret_i64_i32_i64m4(vint32m4_t src) {
  return __builtin_riscv_vreinterpret_i64_i32_i64m4(src);
}

static __attribute__((always_inline))
vint16m4_t vreinterpret_i16_i64_i16m4(vint64m4_t src) {
  return __builtin_riscv_vreinterpret_i16_i64_i16m4(src);
}

static __attribute__((always_inline))
vint64m4_t vreinterpret_i64_i16_i64m4(vint16m4_t src) {
  return __builtin_riscv_vreinterpret_i64_i16_i64m4(src);
}

static __attribute__((always_inline))
vint8m4_t vreinterpret_i8_i64_i8m4(vint64m4_t src) {
  return __builtin_riscv_vreinterpret_i8_i64_i8m4(src);
}

static __attribute__((always_inline))
vint64m4_t vreinterpret_i64_i8_i64m4(vint8m4_t src) {
  return __builtin_riscv_vreinterpret_i64_i8_i64m4(src);
}

static __attribute__((always_inline))
vint16m4_t vreinterpret_i16_i32_i16m4(vint32m4_t src) {
  return __builtin_riscv_vreinterpret_i16_i32_i16m4(src);
}

static __attribute__((always_inline))
vint32m4_t vreinterpret_i32_i16_i32m4(vint16m4_t src) {
  return __builtin_riscv_vreinterpret_i32_i16_i32m4(src);
}

static __attribute__((always_inline))
vint8m4_t vreinterpret_i8_i32_i8m4(vint32m4_t src) {
  return __builtin_riscv_vreinterpret_i8_i32_i8m4(src);
}

static __attribute__((always_inline))
vint32m4_t vreinterpret_i32_i8_i32m4(vint8m4_t src) {
  return __builtin_riscv_vreinterpret_i32_i8_i32m4(src);
}

static __attribute__((always_inline))
vint8m4_t vreinterpret_i8_i16_i8m4(vint16m4_t src) {
  return __builtin_riscv_vreinterpret_i8_i16_i8m4(src);
}

static __attribute__((always_inline))
vint16m4_t vreinterpret_i16_i8_i16m4(vint8m4_t src) {
  return __builtin_riscv_vreinterpret_i16_i8_i16m4(src);
}

static __attribute__((always_inline))
vint32m8_t vreinterpret_i32_i64_i32m8(vint64m8_t src) {
  return __builtin_riscv_vreinterpret_i32_i64_i32m8(src);
}

static __attribute__((always_inline))
vint64m8_t vreinterpret_i64_i32_i64m8(vint32m8_t src) {
  return __builtin_riscv_vreinterpret_i64_i32_i64m8(src);
}

static __attribute__((always_inline))
vint16m8_t vreinterpret_i16_i64_i16m8(vint64m8_t src) {
  return __builtin_riscv_vreinterpret_i16_i64_i16m8(src);
}

static __attribute__((always_inline))
vint64m8_t vreinterpret_i64_i16_i64m8(vint16m8_t src) {
  return __builtin_riscv_vreinterpret_i64_i16_i64m8(src);
}

static __attribute__((always_inline))
vint8m8_t vreinterpret_i8_i64_i8m8(vint64m8_t src) {
  return __builtin_riscv_vreinterpret_i8_i64_i8m8(src);
}

static __attribute__((always_inline))
vint64m8_t vreinterpret_i64_i8_i64m8(vint8m8_t src) {
  return __builtin_riscv_vreinterpret_i64_i8_i64m8(src);
}

static __attribute__((always_inline))
vint16m8_t vreinterpret_i16_i32_i16m8(vint32m8_t src) {
  return __builtin_riscv_vreinterpret_i16_i32_i16m8(src);
}

static __attribute__((always_inline))
vint32m8_t vreinterpret_i32_i16_i32m8(vint16m8_t src) {
  return __builtin_riscv_vreinterpret_i32_i16_i32m8(src);
}

static __attribute__((always_inline))
vint8m8_t vreinterpret_i8_i32_i8m8(vint32m8_t src) {
  return __builtin_riscv_vreinterpret_i8_i32_i8m8(src);
}

static __attribute__((always_inline))
vint32m8_t vreinterpret_i32_i8_i32m8(vint8m8_t src) {
  return __builtin_riscv_vreinterpret_i32_i8_i32m8(src);
}

static __attribute__((always_inline))
vint8m8_t vreinterpret_i8_i16_i8m8(vint16m8_t src) {
  return __builtin_riscv_vreinterpret_i8_i16_i8m8(src);
}

static __attribute__((always_inline))
vint16m8_t vreinterpret_i16_i8_i16m8(vint8m8_t src) {
  return __builtin_riscv_vreinterpret_i16_i8_i16m8(src);
}

static __attribute__((always_inline))
vuint32m1_t vreinterpret_v_u64m1_u32m1(vuint64m1_t src) {
  uint64_t* base;
  vse64_v_u64m1(base, src);
  return vle32_v_u32m1((uint32_t*)base);
}

static __attribute__((always_inline))
vuint64m1_t vreinterpret_v_u32m1_u64m1(vuint32m1_t src) {
  uint32_t* base;
  vse32_v_u32m1(base, src);
  return vle64_v_u64m1((uint64_t*)base);
}

static __attribute__((always_inline))
vuint16m1_t vreinterpret_v_u64m1_u16m1(vuint64m1_t src) {
  uint64_t* base;
  vse64_v_u64m1(base, src);
  return vle16_v_u16m1((uint16_t*)base);
}

static __attribute__((always_inline))
vuint64m1_t vreinterpret_v_u16m1_u64m1(vuint16m1_t src) {
  uint16_t* base;
  vse16_v_u16m1(base, src);
  return vle64_v_u64m1((uint64_t*)base);
}

static __attribute__((always_inline))
vuint8m1_t vreinterpret_v_u64m1_u8m1(vuint64m1_t src) {
  uint64_t* base;
  vse64_v_u64m1(base, src);
  return vle8_v_u8m1((uint8_t*)base);
}

static __attribute__((always_inline))
vuint64m1_t vreinterpret_v_u8m1_u64m1(vuint8m1_t src) {
  uint8_t* base;
  vse8_v_u8m1(base, src);
  return vle64_v_u64m1((uint64_t*)base);
}

static __attribute__((always_inline))
vuint16m1_t vreinterpret_v_u32m1_u16m1(vuint32m1_t src) {
  uint32_t* base;
  vse32_v_u32m1(base, src);
  return vle16_v_u16m1((uint16_t*)base);
}

static __attribute__((always_inline))
vuint32m1_t vreinterpret_v_u16m1_u32m1(vuint16m1_t src) {
  uint16_t* base;
  vse16_v_u16m1(base, src);
  return vle32_v_u32m1((uint32_t*)base);
}

static __attribute__((always_inline))
vuint8m1_t vreinterpret_v_u32m1_u8m1(vuint32m1_t src) {
  uint32_t* base;
  vse32_v_u32m1(base, src);
  return vle8_v_u8m1((uint8_t*)base);
}

static __attribute__((always_inline))
vuint32m1_t vreinterpret_v_u8m1_u32m1(vuint8m1_t src) {
  uint8_t* base;
  vse8_v_u8m1(base, src);
  return vle32_v_u32m1((uint32_t*)base);
}

static __attribute__((always_inline))
vuint8m1_t vreinterpret_v_u16m1_u8m1(vuint16m1_t src) {
  uint16_t* base;
  vse16_v_u16m1(base, src);
  return vle8_v_u8m1((uint8_t*)base);
}

static __attribute__((always_inline))
vuint16m1_t vreinterpret_v_u8m1_u16m1(vuint8m1_t src) {
  uint8_t* base;
  vse8_v_u8m1(base, src);
  return vle16_v_u16m1((uint16_t*)base);
}

static __attribute__((always_inline))
vuint32m2_t vreinterpret_u32_u64_u32m2(vuint64m2_t src) {
  return __builtin_riscv_vreinterpret_u32_u64_u32m2(src);
}

static __attribute__((always_inline))
vuint64m2_t vreinterpret_u64_u32_u64m2(vuint32m2_t src) {
  return __builtin_riscv_vreinterpret_u64_u32_u64m2(src);
}

static __attribute__((always_inline))
vuint16m2_t vreinterpret_u16_u64_u16m2(vuint64m2_t src) {
  return __builtin_riscv_vreinterpret_u16_u64_u16m2(src);
}

static __attribute__((always_inline))
vuint64m2_t vreinterpret_u64_u16_u64m2(vuint16m2_t src) {
  return __builtin_riscv_vreinterpret_u64_u16_u64m2(src);
}

static __attribute__((always_inline))
vuint8m2_t vreinterpret_u8_u64_u8m2(vuint64m2_t src) {
  return __builtin_riscv_vreinterpret_u8_u64_u8m2(src);
}

static __attribute__((always_inline))
vuint64m2_t vreinterpret_u64_u8_u64m2(vuint8m2_t src) {
  return __builtin_riscv_vreinterpret_u64_u8_u64m2(src);
}

static __attribute__((always_inline))
vuint16m2_t vreinterpret_u16_u32_u16m2(vuint32m2_t src) {
  return __builtin_riscv_vreinterpret_u16_u32_u16m2(src);
}

static __attribute__((always_inline))
vuint32m2_t vreinterpret_u32_u16_u32m2(vuint16m2_t src) {
  return __builtin_riscv_vreinterpret_u32_u16_u32m2(src);
}

static __attribute__((always_inline))
vuint8m2_t vreinterpret_u8_u32_u8m2(vuint32m2_t src) {
  return __builtin_riscv_vreinterpret_u8_u32_u8m2(src);
}

static __attribute__((always_inline))
vuint32m2_t vreinterpret_u32_u8_u32m2(vuint8m2_t src) {
  return __builtin_riscv_vreinterpret_u32_u8_u32m2(src);
}

static __attribute__((always_inline))
vuint8m2_t vreinterpret_u8_u16_u8m2(vuint16m2_t src) {
  return __builtin_riscv_vreinterpret_u8_u16_u8m2(src);
}

static __attribute__((always_inline))
vuint16m2_t vreinterpret_u16_u8_u16m2(vuint8m2_t src) {
  return __builtin_riscv_vreinterpret_u16_u8_u16m2(src);
}

static __attribute__((always_inline))
vuint32m4_t vreinterpret_u32_u64_u32m4(vuint64m4_t src) {
  return __builtin_riscv_vreinterpret_u32_u64_u32m4(src);
}

static __attribute__((always_inline))
vuint64m4_t vreinterpret_u64_u32_u64m4(vuint32m4_t src) {
  return __builtin_riscv_vreinterpret_u64_u32_u64m4(src);
}

static __attribute__((always_inline))
vuint16m4_t vreinterpret_u16_u64_u16m4(vuint64m4_t src) {
  return __builtin_riscv_vreinterpret_u16_u64_u16m4(src);
}

static __attribute__((always_inline))
vuint64m4_t vreinterpret_u64_u16_u64m4(vuint16m4_t src) {
  return __builtin_riscv_vreinterpret_u64_u16_u64m4(src);
}

static __attribute__((always_inline))
vuint8m4_t vreinterpret_u8_u64_u8m4(vuint64m4_t src) {
  return __builtin_riscv_vreinterpret_u8_u64_u8m4(src);
}

static __attribute__((always_inline))
vuint64m4_t vreinterpret_u64_u8_u64m4(vuint8m4_t src) {
  return __builtin_riscv_vreinterpret_u64_u8_u64m4(src);
}

static __attribute__((always_inline))
vuint16m4_t vreinterpret_u16_u32_u16m4(vuint32m4_t src) {
  return __builtin_riscv_vreinterpret_u16_u32_u16m4(src);
}

static __attribute__((always_inline))
vuint32m4_t vreinterpret_u32_u16_u32m4(vuint16m4_t src) {
  return __builtin_riscv_vreinterpret_u32_u16_u32m4(src);
}

static __attribute__((always_inline))
vuint8m4_t vreinterpret_u8_u32_u8m4(vuint32m4_t src) {
  return __builtin_riscv_vreinterpret_u8_u32_u8m4(src);
}

static __attribute__((always_inline))
vuint32m4_t vreinterpret_u32_u8_u32m4(vuint8m4_t src) {
  return __builtin_riscv_vreinterpret_u32_u8_u32m4(src);
}

static __attribute__((always_inline))
vuint8m4_t vreinterpret_u8_u16_u8m4(vuint16m4_t src) {
  return __builtin_riscv_vreinterpret_u8_u16_u8m4(src);
}

static __attribute__((always_inline))
vuint16m4_t vreinterpret_u16_u8_u16m4(vuint8m4_t src) {
  return __builtin_riscv_vreinterpret_u16_u8_u16m4(src);
}

static __attribute__((always_inline))
vuint32m8_t vreinterpret_u32_u64_u32m8(vuint64m8_t src) {
  return __builtin_riscv_vreinterpret_u32_u64_u32m8(src);
}

static __attribute__((always_inline))
vuint64m8_t vreinterpret_u64_u32_u64m8(vuint32m8_t src) {
  return __builtin_riscv_vreinterpret_u64_u32_u64m8(src);
}

static __attribute__((always_inline))
vuint16m8_t vreinterpret_u16_u64_u16m8(vuint64m8_t src) {
  return __builtin_riscv_vreinterpret_u16_u64_u16m8(src);
}

static __attribute__((always_inline))
vuint64m8_t vreinterpret_u64_u16_u64m8(vuint16m8_t src) {
  return __builtin_riscv_vreinterpret_u64_u16_u64m8(src);
}

static __attribute__((always_inline))
vuint8m8_t vreinterpret_u8_u64_u8m8(vuint64m8_t src) {
  return __builtin_riscv_vreinterpret_u8_u64_u8m8(src);
}

static __attribute__((always_inline))
vuint64m8_t vreinterpret_u64_u8_u64m8(vuint8m8_t src) {
  return __builtin_riscv_vreinterpret_u64_u8_u64m8(src);
}

static __attribute__((always_inline))
vuint16m8_t vreinterpret_u16_u32_u16m8(vuint32m8_t src) {
  return __builtin_riscv_vreinterpret_u16_u32_u16m8(src);
}

static __attribute__((always_inline))
vuint32m8_t vreinterpret_u32_u16_u32m8(vuint16m8_t src) {
  return __builtin_riscv_vreinterpret_u32_u16_u32m8(src);
}

static __attribute__((always_inline))
vuint8m8_t vreinterpret_u8_u32_u8m8(vuint32m8_t src) {
  return __builtin_riscv_vreinterpret_u8_u32_u8m8(src);
}

static __attribute__((always_inline))
vuint32m8_t vreinterpret_u32_u8_u32m8(vuint8m8_t src) {
  return __builtin_riscv_vreinterpret_u32_u8_u32m8(src);
}

static __attribute__((always_inline))
vuint8m8_t vreinterpret_u8_u16_u8m8(vuint16m8_t src) {
  return __builtin_riscv_vreinterpret_u8_u16_u8m8(src);
}

static __attribute__((always_inline))
vuint16m8_t vreinterpret_u16_u8_u16m8(vuint8m8_t src) {
  return __builtin_riscv_vreinterpret_u16_u8_u16m8(src);
}

static __attribute__((always_inline))
vint8m1_t vslideup_vx_i8m1(vint8m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i8m1(src, offset);
}

static __attribute__((always_inline))
vint8m2_t vslideup_vx_i8m2(vint8m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i8m2(src, offset);
}

static __attribute__((always_inline))
vint8m4_t vslideup_vx_i8m4(vint8m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i8m4(src, offset);
}

static __attribute__((always_inline))
vint8m8_t vslideup_vx_i8m8(vint8m8_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i8m8(src, offset);
}

static __attribute__((always_inline))
vint16m1_t vslideup_vx_i16m1(vint16m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i16m1(src, offset);
}

static __attribute__((always_inline))
vint16m2_t vslideup_vx_i16m2(vint16m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i16m2(src, offset);
}

static __attribute__((always_inline))
vint16m4_t vslideup_vx_i16m4(vint16m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i16m4(src, offset);
}

static __attribute__((always_inline))
vint16m8_t vslideup_vx_i16m8(vint16m8_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i16m8(src, offset);
}

static __attribute__((always_inline))
vint32m1_t vslideup_vx_i32m1(vint32m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i32m1(src, offset);
}

static __attribute__((always_inline))
vint32m2_t vslideup_vx_i32m2(vint32m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i32m2(src, offset);
}

static __attribute__((always_inline))
vint32m4_t vslideup_vx_i32m4(vint32m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i32m4(src, offset);
}

static __attribute__((always_inline))
vint32m8_t vslideup_vx_i32m8(vint32m8_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i32m8(src, offset);
}

static __attribute__((always_inline))
vint64m1_t vslideup_vx_i64m1(vint64m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i64m1(src, offset);
}

static __attribute__((always_inline))
vint64m2_t vslideup_vx_i64m2(vint64m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i64m2(src, offset);
}

static __attribute__((always_inline))
vint64m4_t vslideup_vx_i64m4(vint64m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i64m4(src, offset);
}

static __attribute__((always_inline))
vint64m8_t vslideup_vx_i64m8(vint64m8_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i64m8(src, offset);
}

static __attribute__((always_inline))
vuint8m1_t vslideup_vx_u8m1(vuint8m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u8m1(src, offset);
}

static __attribute__((always_inline))
vuint8m2_t vslideup_vx_u8m2(vuint8m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u8m2(src, offset);
}

static __attribute__((always_inline))
vuint8m4_t vslideup_vx_u8m4(vuint8m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u8m4(src, offset);
}

static __attribute__((always_inline))
vuint8m8_t vslideup_vx_u8m8(vuint8m8_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u8m8(src, offset);
}

static __attribute__((always_inline))
vuint16m1_t vslideup_vx_u16m1(vuint16m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u16m1(src, offset);
}

static __attribute__((always_inline))
vuint16m2_t vslideup_vx_u16m2(vuint16m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u16m2(src, offset);
}

static __attribute__((always_inline))
vuint16m4_t vslideup_vx_u16m4(vuint16m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u16m4(src, offset);
}

static __attribute__((always_inline))
vuint16m8_t vslideup_vx_u16m8(vuint16m8_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u16m8(src, offset);
}

static __attribute__((always_inline))
vuint32m1_t vslideup_vx_u32m1(vuint32m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u32m1(src, offset);
}

static __attribute__((always_inline))
vuint32m2_t vslideup_vx_u32m2(vuint32m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u32m2(src, offset);
}

static __attribute__((always_inline))
vuint32m4_t vslideup_vx_u32m4(vuint32m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u32m4(src, offset);
}

static __attribute__((always_inline))
vuint32m8_t vslideup_vx_u32m8(vuint32m8_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u32m8(src, offset);
}

static __attribute__((always_inline))
vuint64m1_t vslideup_vx_u64m1(vuint64m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u64m1(src, offset);
}

static __attribute__((always_inline))
vuint64m2_t vslideup_vx_u64m2(vuint64m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u64m2(src, offset);
}

static __attribute__((always_inline))
vuint64m4_t vslideup_vx_u64m4(vuint64m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u64m4(src, offset);
}

static __attribute__((always_inline))
vuint64m8_t vslideup_vx_u64m8(vuint64m8_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u64m8(src, offset);
}

static __attribute__((always_inline))
vfloat32m1_t vslideup_vx_f32m1(vfloat32m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f32m1(src, offset);
}

static __attribute__((always_inline))
vfloat32m2_t vslideup_vx_f32m2(vfloat32m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f32m2(src, offset);
}

static __attribute__((always_inline))
vfloat32m4_t vslideup_vx_f32m4(vfloat32m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f32m4(src, offset);
}

static __attribute__((always_inline))
vfloat32m8_t vslideup_vx_f32m8(vfloat32m8_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f32m8(src, offset);
}

static __attribute__((always_inline))
vfloat64m1_t vslideup_vx_f64m1(vfloat64m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f64m1(src, offset);
}

static __attribute__((always_inline))
vfloat64m2_t vslideup_vx_f64m2(vfloat64m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f64m2(src, offset);
}

static __attribute__((always_inline))
vfloat64m4_t vslideup_vx_f64m4(vfloat64m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f64m4(src, offset);
}

static __attribute__((always_inline))
vfloat64m8_t vslideup_vx_f64m8(vfloat64m8_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f64m8(src, offset);
}

// Vector Integer Arithmetic Operations

// Vector Single-Width Integer Add and Subtract Functions
static __attribute__((always_inline))
vint8m1_t vadd_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vadd_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vadd_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vadd_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vsub_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vsub_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vsub_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vsub_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vrsub_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vrsub_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vadd_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vadd_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vadd_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vadd_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vsub_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vsub_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vsub_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vsub_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vrsub_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vrsub_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vadd_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vadd_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vadd_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vadd_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vsub_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vsub_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vsub_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vsub_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vrsub_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vrsub_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vadd_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vadd_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vadd_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vadd_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vsub_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vsub_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vsub_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vsub_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vrsub_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vrsub_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vadd_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vadd_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vadd_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vadd_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vsub_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vsub_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vsub_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vsub_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vrsub_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vrsub_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vadd_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vadd_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vadd_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vadd_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vsub_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vsub_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vsub_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vsub_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vrsub_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vrsub_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vadd_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vadd_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vadd_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vadd_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vsub_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vsub_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vsub_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vsub_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vrsub_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vrsub_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vadd_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vadd_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vadd_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vadd_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vsub_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vsub_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vsub_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vsub_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vrsub_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vrsub_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vadd_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vadd_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vadd_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vadd_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vsub_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vsub_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vsub_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vsub_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vrsub_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vrsub_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vadd_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vadd_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vadd_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vadd_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vsub_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vsub_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vsub_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vsub_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vrsub_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vrsub_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vadd_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vadd_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vadd_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vadd_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vsub_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vsub_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vsub_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vsub_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vrsub_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vrsub_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vadd_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vadd_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vadd_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vadd_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vsub_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vsub_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vsub_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vsub_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vrsub_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vrsub_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vadd_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vadd_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vadd_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vadd_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vsub_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vsub_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vsub_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vsub_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vrsub_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vrsub_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vadd_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vadd_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vadd_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vadd_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vsub_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vsub_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vsub_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vsub_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vrsub_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vrsub_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vadd_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vadd_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vadd_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vadd_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vsub_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vsub_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vsub_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vsub_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vrsub_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vrsub_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vadd_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vadd_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vadd_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vadd_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vsub_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vsub_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vsub_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vsub_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vrsub_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vrsub_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vadd_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vadd_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vadd_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vadd_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vsub_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vsub_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vsub_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vsub_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vrsub_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vrsub_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vadd_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vadd_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vadd_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vadd_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vsub_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vsub_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vsub_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vsub_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vrsub_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vrsub_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vadd_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vadd_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vadd_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vadd_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vsub_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vsub_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vsub_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vsub_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vrsub_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vrsub_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vadd_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vadd_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vadd_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vadd_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vsub_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vsub_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vsub_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vsub_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vrsub_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vrsub_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vadd_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vadd_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vadd_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vadd_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vsub_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vsub_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vsub_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vsub_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vrsub_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vrsub_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vadd_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vadd_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vadd_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vadd_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vsub_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vsub_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vsub_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vsub_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vrsub_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vrsub_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vadd_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vadd_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vadd_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vadd_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vsub_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vsub_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vsub_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vsub_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vrsub_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vrsub_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vadd_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vadd_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vadd_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vadd_vx_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vsub_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vsub_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vsub_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vsub_vx_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vrsub_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vrsub_vx_u64m4(op1, op2);
}


// Vector Bitwise Logical Operations
static __attribute__((always_inline))
vint8m1_t vand_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vand_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vand_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vand_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vor_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vor_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vor_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vor_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vxor_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vxor_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vxor_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vxor_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vnot_v_i8m1(vint8m1_t op1) {
  return __builtin_riscv_vnot_v_i8m1(op1);
}

static __attribute__((always_inline))
vint8m2_t vand_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vand_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vand_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vand_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vor_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vor_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vor_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vor_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vxor_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vxor_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vxor_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vxor_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vnot_v_i8m2(vint8m2_t op1) {
  return __builtin_riscv_vnot_v_i8m2(op1);
}

static __attribute__((always_inline))
vint8m4_t vand_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vand_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vand_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vand_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vor_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vor_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vor_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vor_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vxor_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vxor_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vxor_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vxor_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vnot_v_i8m4(vint8m4_t op1) {
  return __builtin_riscv_vnot_v_i8m4(op1);
}

static __attribute__((always_inline))
vint16m1_t vand_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vand_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vand_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vand_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vor_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vor_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vor_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vor_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vxor_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vxor_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vxor_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vxor_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vnot_v_i16m1(vint16m1_t op1) {
  return __builtin_riscv_vnot_v_i16m1(op1);
}

static __attribute__((always_inline))
vint16m2_t vand_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vand_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vand_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vand_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vor_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vor_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vor_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vor_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vxor_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vxor_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vxor_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vxor_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vnot_v_i16m2(vint16m2_t op1) {
  return __builtin_riscv_vnot_v_i16m2(op1);
}

static __attribute__((always_inline))
vint16m4_t vand_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vand_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vand_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vand_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vor_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vor_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vor_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vor_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vxor_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vxor_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vxor_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vxor_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vnot_v_i16m4(vint16m4_t op1) {
  return __builtin_riscv_vnot_v_i16m4(op1);
}

static __attribute__((always_inline))
vint32m1_t vand_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vand_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vand_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vand_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vor_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vor_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vor_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vor_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vxor_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vxor_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vxor_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vxor_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vnot_v_i32m1(vint32m1_t op1) {
  return __builtin_riscv_vnot_v_i32m1(op1);
}

static __attribute__((always_inline))
vint32m2_t vand_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vand_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vand_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vand_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vor_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vor_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vor_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vor_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vxor_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vxor_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vxor_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vxor_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vnot_v_i32m2(vint32m2_t op1) {
  return __builtin_riscv_vnot_v_i32m2(op1);
}

static __attribute__((always_inline))
vint32m4_t vand_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vand_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vand_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vand_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vor_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vor_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vor_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vor_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vxor_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vxor_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vxor_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vxor_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vnot_v_i32m4(vint32m4_t op1) {
  return __builtin_riscv_vnot_v_i32m4(op1);
}

static __attribute__((always_inline))
vint64m1_t vand_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vand_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vand_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vand_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vor_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vor_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vor_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vor_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vxor_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vxor_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vxor_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vxor_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vnot_v_i64m1(vint64m1_t op1) {
  return __builtin_riscv_vnot_v_i64m1(op1);
}

static __attribute__((always_inline))
vint64m2_t vand_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vand_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vand_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vand_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vor_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vor_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vor_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vor_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vxor_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vxor_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vxor_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vxor_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vnot_v_i64m2(vint64m2_t op1) {
  return __builtin_riscv_vnot_v_i64m2(op1);
}

static __attribute__((always_inline))
vint64m4_t vand_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vand_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vand_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vand_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vor_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vor_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vor_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vor_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vxor_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vxor_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vxor_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vxor_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vnot_v_i64m4(vint64m4_t op1) {
  return __builtin_riscv_vnot_v_i64m4(op1);
}

static __attribute__((always_inline))
vuint8m1_t vand_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vand_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vand_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vand_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vor_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vor_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vor_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vor_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vxor_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vxor_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vxor_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vxor_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vnot_v_u8m1(vuint8m1_t op1) {
  return __builtin_riscv_vnot_v_u8m1(op1);
}

static __attribute__((always_inline))
vuint8m2_t vand_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vand_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vand_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vand_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vor_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vor_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vor_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vor_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vxor_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vxor_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vxor_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vxor_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vnot_v_u8m2(vuint8m2_t op1) {
  return __builtin_riscv_vnot_v_u8m2(op1);
}

static __attribute__((always_inline))
vuint8m4_t vand_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vand_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vand_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vand_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vor_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vor_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vor_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vor_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vxor_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vxor_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vxor_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vxor_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vnot_v_u8m4(vuint8m4_t op1) {
  return __builtin_riscv_vnot_v_u8m4(op1);
}

static __attribute__((always_inline))
vuint16m1_t vand_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vand_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vand_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vand_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vor_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vor_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vor_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vor_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vxor_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vxor_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vxor_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vxor_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vnot_v_u16m1(vuint16m1_t op1) {
  return __builtin_riscv_vnot_v_u16m1(op1);
}

static __attribute__((always_inline))
vuint16m2_t vand_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vand_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vand_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vand_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vor_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vor_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vor_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vor_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vxor_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vxor_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vxor_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vxor_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vnot_v_u16m2(vuint16m2_t op1) {
  return __builtin_riscv_vnot_v_u16m2(op1);
}

static __attribute__((always_inline))
vuint16m4_t vand_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vand_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vand_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vand_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vor_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vor_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vor_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vor_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vxor_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vxor_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vxor_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vxor_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vnot_v_u16m4(vuint16m4_t op1) {
  return __builtin_riscv_vnot_v_u16m4(op1);
}

static __attribute__((always_inline))
vuint32m1_t vand_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vand_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vand_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vand_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vor_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vor_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vor_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vor_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vxor_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vxor_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vxor_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vxor_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vnot_v_u32m1(vuint32m1_t op1) {
  return __builtin_riscv_vnot_v_u32m1(op1);
}

static __attribute__((always_inline))
vuint32m2_t vand_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vand_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vand_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vand_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vor_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vor_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vor_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vor_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vxor_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vxor_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vxor_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vxor_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vnot_v_u32m2(vuint32m2_t op1) {
  return __builtin_riscv_vnot_v_u32m2(op1);
}

static __attribute__((always_inline))
vuint32m4_t vand_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vand_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vand_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vand_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vor_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vor_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vor_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vor_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vxor_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vxor_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vxor_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vxor_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vnot_v_u32m4(vuint32m4_t op1) {
  return __builtin_riscv_vnot_v_u32m4(op1);
}

static __attribute__((always_inline))
vuint64m1_t vand_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vand_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vand_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vand_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vor_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vor_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vor_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vor_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vxor_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vxor_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vxor_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vxor_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vnot_v_u64m1(vuint64m1_t op1) {
  return __builtin_riscv_vnot_v_u64m1(op1);
}

static __attribute__((always_inline))
vuint64m2_t vand_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vand_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vand_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vand_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vor_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vor_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vor_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vor_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vxor_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vxor_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vxor_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vxor_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vnot_v_u64m2(vuint64m2_t op1) {
  return __builtin_riscv_vnot_v_u64m2(op1);
}

static __attribute__((always_inline))
vuint64m4_t vand_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vand_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vand_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vand_vx_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vor_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vor_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vor_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vor_vx_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vxor_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vxor_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vxor_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vxor_vx_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vnot_v_u64m4(vuint64m4_t op1) {
  return __builtin_riscv_vnot_v_u64m4(op1);
}


// Vector Single-Width Bit Shift Operations
static __attribute__((always_inline))
vint8m1_t vsll_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vsll_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vsll_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vsll_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vsrl_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vsrl_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vsrl_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vsrl_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vsra_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vsra_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vsra_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vsra_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vsll_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vsll_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vsll_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vsll_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vsrl_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vsrl_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vsrl_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vsrl_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vsra_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vsra_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vsra_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vsra_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vsll_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vsll_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vsll_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vsll_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vsrl_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vsrl_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vsrl_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vsrl_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vsra_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vsra_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vsra_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vsra_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vsll_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vsll_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vsll_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vsll_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vsrl_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vsrl_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vsrl_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vsrl_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vsra_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vsra_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vsra_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vsra_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vsll_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vsll_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vsll_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vsll_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vsrl_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vsrl_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vsrl_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vsrl_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vsra_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vsra_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vsra_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vsra_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vsll_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vsll_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vsll_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vsll_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vsrl_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vsrl_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vsrl_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vsrl_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vsra_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vsra_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vsra_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vsra_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vsll_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vsll_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vsll_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vsll_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vsrl_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vsrl_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vsrl_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vsrl_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vsra_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vsra_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vsra_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vsra_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vsll_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vsll_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vsll_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vsll_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vsrl_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vsrl_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vsrl_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vsrl_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vsra_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vsra_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vsra_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vsra_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vsll_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vsll_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vsll_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vsll_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vsrl_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vsrl_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vsrl_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vsrl_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vsra_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vsra_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vsra_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vsra_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vsll_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vsll_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vsll_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vsll_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vsrl_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vsrl_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vsrl_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vsrl_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vsra_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vsra_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vsra_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vsra_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vsll_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vsll_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vsll_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vsll_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vsrl_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vsrl_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vsrl_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vsrl_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vsra_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vsra_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vsra_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vsra_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vsll_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vsll_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vsll_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vsll_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vsrl_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vsrl_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vsrl_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vsrl_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vsra_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vsra_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vsra_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vsra_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vsll_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vsll_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vsll_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vsll_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vsrl_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vsrl_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vsrl_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vsrl_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vsra_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vsra_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vsra_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vsra_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vsll_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vsll_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vsll_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vsll_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vsrl_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vsrl_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vsrl_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vsrl_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vsra_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vsra_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vsra_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vsra_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vsll_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vsll_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vsll_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vsll_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vsrl_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vsrl_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vsrl_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vsrl_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vsra_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vsra_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vsra_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vsra_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vsll_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vsll_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vsll_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vsll_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vsrl_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vsrl_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vsrl_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vsrl_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vsra_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vsra_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vsra_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vsra_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vsll_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vsll_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vsll_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vsll_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vsrl_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vsrl_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vsrl_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vsrl_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vsra_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vsra_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vsra_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vsra_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vsll_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vsll_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vsll_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vsll_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vsrl_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vsrl_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vsrl_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vsrl_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vsra_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vsra_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vsra_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vsra_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vsll_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vsll_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vsll_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vsll_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vsrl_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vsrl_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vsrl_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vsrl_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vsra_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vsra_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vsra_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vsra_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vsll_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vsll_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vsll_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vsll_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vsrl_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vsrl_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vsrl_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vsrl_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vsra_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vsra_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vsra_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vsra_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vsll_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vsll_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vsll_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vsll_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vsrl_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vsrl_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vsrl_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vsrl_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vsra_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vsra_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vsra_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vsra_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vsll_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vsll_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vsll_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vsll_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vsrl_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vsrl_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vsrl_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vsrl_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vsra_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vsra_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vsra_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vsra_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vsll_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vsll_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vsll_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vsll_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vsrl_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vsrl_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vsrl_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vsrl_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vsra_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vsra_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vsra_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vsra_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vsll_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vsll_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vsll_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vsll_vx_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vsrl_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vsrl_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vsrl_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vsrl_vx_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vsra_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vsra_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vsra_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vsra_vx_u64m4(op1, op2);
}


// Vector Integer Comparison Operations
static __attribute__((always_inline))
vbool8_t vmseq_vv_i8m1_b8(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vmseq_vv_i8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmseq_vx_i8m1_b8(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vmseq_vx_i8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsne_vv_i8m1_b8(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vmsne_vv_i8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsne_vx_i8m1_b8(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vmsne_vx_i8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmslt_vv_i8m1_b8(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vmslt_vv_i8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmslt_vx_i8m1_b8(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vmslt_vx_i8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsle_vv_i8m1_b8(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vmsle_vv_i8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsle_vx_i8m1_b8(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vmsle_vx_i8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsgt_vv_i8m1_b8(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vmsgt_vv_i8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsgt_vx_i8m1_b8(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vmsgt_vx_i8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsge_vv_i8m1_b8(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vmsge_vv_i8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsge_vx__i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vmsge_vx__i8m1(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmseq_vv_i8m2_b4(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmseq_vv_i8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmseq_vx_i8m2_b4(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vmseq_vx_i8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsne_vv_i8m2_b4(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmsne_vv_i8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsne_vx_i8m2_b4(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vmsne_vx_i8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmslt_vv_i8m2_b4(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmslt_vv_i8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmslt_vx_i8m2_b4(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vmslt_vx_i8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsle_vv_i8m2_b4(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmsle_vv_i8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsle_vx_i8m2_b4(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vmsle_vx_i8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsgt_vv_i8m2_b4(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmsgt_vv_i8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsgt_vx_i8m2_b4(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vmsgt_vx_i8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsge_vv_i8m2_b4(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmsge_vv_i8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsge_vx__i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vmsge_vx__i8m2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmseq_vv_i8m4_b2(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vmseq_vv_i8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmseq_vx_i8m4_b2(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vmseq_vx_i8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsne_vv_i8m4_b2(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vmsne_vv_i8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsne_vx_i8m4_b2(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vmsne_vx_i8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmslt_vv_i8m4_b2(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vmslt_vv_i8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmslt_vx_i8m4_b2(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vmslt_vx_i8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsle_vv_i8m4_b2(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vmsle_vv_i8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsle_vx_i8m4_b2(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vmsle_vx_i8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsgt_vv_i8m4_b2(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vmsgt_vv_i8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsgt_vx_i8m4_b2(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vmsgt_vx_i8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsge_vv_i8m4_b2(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vmsge_vv_i8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsge_vx__i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vmsge_vx__i8m4(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmseq_vv_i16m1_b16(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmseq_vv_i16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmseq_vx_i16m1_b16(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vmseq_vx_i16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsne_vv_i16m1_b16(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmsne_vv_i16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsne_vx_i16m1_b16(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vmsne_vx_i16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmslt_vv_i16m1_b16(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmslt_vv_i16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmslt_vx_i16m1_b16(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vmslt_vx_i16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsle_vv_i16m1_b16(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmsle_vv_i16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsle_vx_i16m1_b16(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vmsle_vx_i16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsgt_vv_i16m1_b16(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmsgt_vv_i16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsgt_vx_i16m1_b16(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vmsgt_vx_i16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsge_vv_i16m1_b16(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmsge_vv_i16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsge_vx__i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vmsge_vx__i16m1(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmseq_vv_i16m2_b8(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vmseq_vv_i16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmseq_vx_i16m2_b8(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vmseq_vx_i16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsne_vv_i16m2_b8(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vmsne_vv_i16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsne_vx_i16m2_b8(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vmsne_vx_i16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmslt_vv_i16m2_b8(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vmslt_vv_i16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmslt_vx_i16m2_b8(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vmslt_vx_i16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsle_vv_i16m2_b8(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vmsle_vv_i16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsle_vx_i16m2_b8(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vmsle_vx_i16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsgt_vv_i16m2_b8(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vmsgt_vv_i16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsgt_vx_i16m2_b8(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vmsgt_vx_i16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsge_vv_i16m2_b8(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vmsge_vv_i16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsge_vx__i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vmsge_vx__i16m2(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmseq_vv_i16m4_b4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmseq_vv_i16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmseq_vx_i16m4_b4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vmseq_vx_i16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsne_vv_i16m4_b4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmsne_vv_i16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsne_vx_i16m4_b4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vmsne_vx_i16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmslt_vv_i16m4_b4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmslt_vv_i16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmslt_vx_i16m4_b4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vmslt_vx_i16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsle_vv_i16m4_b4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmsle_vv_i16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsle_vx_i16m4_b4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vmsle_vx_i16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsgt_vv_i16m4_b4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmsgt_vv_i16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsgt_vx_i16m4_b4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vmsgt_vx_i16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsge_vv_i16m4_b4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmsge_vv_i16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsge_vx__i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vmsge_vx__i16m4(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmseq_vv_i32m1_b32(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vmseq_vv_i32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmseq_vx_i32m1_b32(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vmseq_vx_i32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsne_vv_i32m1_b32(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vmsne_vv_i32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsne_vx_i32m1_b32(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vmsne_vx_i32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmslt_vv_i32m1_b32(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vmslt_vv_i32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmslt_vx_i32m1_b32(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vmslt_vx_i32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsle_vv_i32m1_b32(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vmsle_vv_i32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsle_vx_i32m1_b32(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vmsle_vx_i32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsgt_vv_i32m1_b32(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vmsgt_vv_i32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsgt_vx_i32m1_b32(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vmsgt_vx_i32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsge_vv_i32m1_b32(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vmsge_vv_i32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsge_vx__i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vmsge_vx__i32m1(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmseq_vv_i32m2_b16(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmseq_vv_i32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmseq_vx_i32m2_b16(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vmseq_vx_i32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsne_vv_i32m2_b16(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmsne_vv_i32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsne_vx_i32m2_b16(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vmsne_vx_i32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmslt_vv_i32m2_b16(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmslt_vv_i32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmslt_vx_i32m2_b16(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vmslt_vx_i32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsle_vv_i32m2_b16(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmsle_vv_i32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsle_vx_i32m2_b16(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vmsle_vx_i32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsgt_vv_i32m2_b16(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmsgt_vv_i32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsgt_vx_i32m2_b16(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vmsgt_vx_i32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsge_vv_i32m2_b16(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmsge_vv_i32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsge_vx__i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vmsge_vx__i32m2(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmseq_vv_i32m4_b8(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vmseq_vv_i32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmseq_vx_i32m4_b8(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vmseq_vx_i32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsne_vv_i32m4_b8(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vmsne_vv_i32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsne_vx_i32m4_b8(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vmsne_vx_i32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmslt_vv_i32m4_b8(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vmslt_vv_i32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmslt_vx_i32m4_b8(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vmslt_vx_i32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsle_vv_i32m4_b8(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vmsle_vv_i32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsle_vx_i32m4_b8(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vmsle_vx_i32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsgt_vv_i32m4_b8(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vmsgt_vv_i32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsgt_vx_i32m4_b8(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vmsgt_vx_i32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsge_vv_i32m4_b8(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vmsge_vv_i32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsge_vx__i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vmsge_vx__i32m4(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmseq_vv_i64m1_b64(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmseq_vv_i64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmseq_vx_i64m1_b64(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vmseq_vx_i64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsne_vv_i64m1_b64(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmsne_vv_i64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsne_vx_i64m1_b64(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vmsne_vx_i64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmslt_vv_i64m1_b64(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmslt_vv_i64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmslt_vx_i64m1_b64(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vmslt_vx_i64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsle_vv_i64m1_b64(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmsle_vv_i64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsle_vx_i64m1_b64(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vmsle_vx_i64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsgt_vv_i64m1_b64(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmsgt_vv_i64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsgt_vx_i64m1_b64(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vmsgt_vx_i64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsge_vv_i64m1_b64(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmsge_vv_i64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsge_vx__i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vmsge_vx__i64m1(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmseq_vv_i64m2_b32(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vmseq_vv_i64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmseq_vx_i64m2_b32(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vmseq_vx_i64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsne_vv_i64m2_b32(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vmsne_vv_i64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsne_vx_i64m2_b32(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vmsne_vx_i64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmslt_vv_i64m2_b32(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vmslt_vv_i64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmslt_vx_i64m2_b32(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vmslt_vx_i64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsle_vv_i64m2_b32(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vmsle_vv_i64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsle_vx_i64m2_b32(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vmsle_vx_i64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsgt_vv_i64m2_b32(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vmsgt_vv_i64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsgt_vx_i64m2_b32(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vmsgt_vx_i64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsge_vv_i64m2_b32(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vmsge_vv_i64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsge_vx__i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vmsge_vx__i64m2(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmseq_vv_i64m4_b16(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmseq_vv_i64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmseq_vx_i64m4_b16(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vmseq_vx_i64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsne_vv_i64m4_b16(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmsne_vv_i64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsne_vx_i64m4_b16(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vmsne_vx_i64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmslt_vv_i64m4_b16(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmslt_vv_i64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmslt_vx_i64m4_b16(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vmslt_vx_i64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsle_vv_i64m4_b16(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmsle_vv_i64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsle_vx_i64m4_b16(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vmsle_vx_i64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsgt_vv_i64m4_b16(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmsgt_vv_i64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsgt_vx_i64m4_b16(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vmsgt_vx_i64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsge_vv_i64m4_b16(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmsge_vv_i64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsge_vx__i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vmsge_vx__i64m4(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmseq_vv_u8m1_b8(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vmseq_vv_u8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmseq_vx_u8m1_b8(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vmseq_vx_u8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsne_vv_u8m1_b8(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vmsne_vv_u8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsne_vx_u8m1_b8(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vmsne_vx_u8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsltu_vv_u8m1_b8(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vmsltu_vv_u8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsltu_vx_u8m1_b8(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vmsltu_vx_u8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsleu_vv_u8m1_b8(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vmsleu_vv_u8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsleu_vx_u8m1_b8(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vmsleu_vx_u8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsgtu_vv_u8m1_b8(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vmsgtu_vv_u8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsgtu_vx_u8m1_b8(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vmsgtu_vx_u8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsgeu_vv_u8m1_b8(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vmsgeu_vv_u8m1_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsge_vx_u_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vmsge_vx_u_u8m1(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmseq_vv_u8m2_b4(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vmseq_vv_u8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmseq_vx_u8m2_b4(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vmseq_vx_u8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsne_vv_u8m2_b4(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vmsne_vv_u8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsne_vx_u8m2_b4(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vmsne_vx_u8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsltu_vv_u8m2_b4(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vmsltu_vv_u8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsltu_vx_u8m2_b4(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vmsltu_vx_u8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsleu_vv_u8m2_b4(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vmsleu_vv_u8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsleu_vx_u8m2_b4(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vmsleu_vx_u8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsgtu_vv_u8m2_b4(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vmsgtu_vv_u8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsgtu_vx_u8m2_b4(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vmsgtu_vx_u8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsgeu_vv_u8m2_b4(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vmsgeu_vv_u8m2_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsge_vx_u_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vmsge_vx_u_u8m2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmseq_vv_u8m4_b2(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vmseq_vv_u8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmseq_vx_u8m4_b2(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vmseq_vx_u8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsne_vv_u8m4_b2(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vmsne_vv_u8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsne_vx_u8m4_b2(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vmsne_vx_u8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsltu_vv_u8m4_b2(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vmsltu_vv_u8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsltu_vx_u8m4_b2(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vmsltu_vx_u8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsleu_vv_u8m4_b2(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vmsleu_vv_u8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsleu_vx_u8m4_b2(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vmsleu_vx_u8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsgtu_vv_u8m4_b2(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vmsgtu_vv_u8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsgtu_vx_u8m4_b2(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vmsgtu_vx_u8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsgeu_vv_u8m4_b2(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vmsgeu_vv_u8m4_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmsge_vx_u_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vmsge_vx_u_u8m4(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmseq_vv_u16m1_b16(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vmseq_vv_u16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmseq_vx_u16m1_b16(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vmseq_vx_u16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsne_vv_u16m1_b16(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vmsne_vv_u16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsne_vx_u16m1_b16(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vmsne_vx_u16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsltu_vv_u16m1_b16(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vmsltu_vv_u16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsltu_vx_u16m1_b16(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vmsltu_vx_u16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsleu_vv_u16m1_b16(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vmsleu_vv_u16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsleu_vx_u16m1_b16(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vmsleu_vx_u16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsgtu_vv_u16m1_b16(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vmsgtu_vv_u16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsgtu_vx_u16m1_b16(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vmsgtu_vx_u16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsgeu_vv_u16m1_b16(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vmsgeu_vv_u16m1_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsge_vx_u_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vmsge_vx_u_u16m1(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmseq_vv_u16m2_b8(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vmseq_vv_u16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmseq_vx_u16m2_b8(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vmseq_vx_u16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsne_vv_u16m2_b8(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vmsne_vv_u16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsne_vx_u16m2_b8(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vmsne_vx_u16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsltu_vv_u16m2_b8(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vmsltu_vv_u16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsltu_vx_u16m2_b8(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vmsltu_vx_u16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsleu_vv_u16m2_b8(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vmsleu_vv_u16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsleu_vx_u16m2_b8(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vmsleu_vx_u16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsgtu_vv_u16m2_b8(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vmsgtu_vv_u16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsgtu_vx_u16m2_b8(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vmsgtu_vx_u16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsgeu_vv_u16m2_b8(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vmsgeu_vv_u16m2_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsge_vx_u_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vmsge_vx_u_u16m2(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmseq_vv_u16m4_b4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vmseq_vv_u16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmseq_vx_u16m4_b4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vmseq_vx_u16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsne_vv_u16m4_b4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vmsne_vv_u16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsne_vx_u16m4_b4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vmsne_vx_u16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsltu_vv_u16m4_b4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vmsltu_vv_u16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsltu_vx_u16m4_b4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vmsltu_vx_u16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsleu_vv_u16m4_b4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vmsleu_vv_u16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsleu_vx_u16m4_b4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vmsleu_vx_u16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsgtu_vv_u16m4_b4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vmsgtu_vv_u16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsgtu_vx_u16m4_b4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vmsgtu_vx_u16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsgeu_vv_u16m4_b4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vmsgeu_vv_u16m4_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmsge_vx_u_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vmsge_vx_u_u16m4(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmseq_vv_u32m1_b32(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vmseq_vv_u32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmseq_vx_u32m1_b32(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vmseq_vx_u32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsne_vv_u32m1_b32(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vmsne_vv_u32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsne_vx_u32m1_b32(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vmsne_vx_u32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsltu_vv_u32m1_b32(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vmsltu_vv_u32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsltu_vx_u32m1_b32(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vmsltu_vx_u32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsleu_vv_u32m1_b32(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vmsleu_vv_u32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsleu_vx_u32m1_b32(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vmsleu_vx_u32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsgtu_vv_u32m1_b32(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vmsgtu_vv_u32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsgtu_vx_u32m1_b32(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vmsgtu_vx_u32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsgeu_vv_u32m1_b32(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vmsgeu_vv_u32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsge_vx_u_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vmsge_vx_u_u32m1(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmseq_vv_u32m2_b16(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vmseq_vv_u32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmseq_vx_u32m2_b16(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vmseq_vx_u32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsne_vv_u32m2_b16(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vmsne_vv_u32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsne_vx_u32m2_b16(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vmsne_vx_u32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsltu_vv_u32m2_b16(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vmsltu_vv_u32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsltu_vx_u32m2_b16(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vmsltu_vx_u32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsleu_vv_u32m2_b16(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vmsleu_vv_u32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsleu_vx_u32m2_b16(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vmsleu_vx_u32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsgtu_vv_u32m2_b16(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vmsgtu_vv_u32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsgtu_vx_u32m2_b16(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vmsgtu_vx_u32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsgeu_vv_u32m2_b16(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vmsgeu_vv_u32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsge_vx_u_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vmsge_vx_u_u32m2(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmseq_vv_u32m4_b8(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vmseq_vv_u32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmseq_vx_u32m4_b8(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vmseq_vx_u32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsne_vv_u32m4_b8(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vmsne_vv_u32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsne_vx_u32m4_b8(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vmsne_vx_u32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsltu_vv_u32m4_b8(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vmsltu_vv_u32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsltu_vx_u32m4_b8(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vmsltu_vx_u32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsleu_vv_u32m4_b8(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vmsleu_vv_u32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsleu_vx_u32m4_b8(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vmsleu_vx_u32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsgtu_vv_u32m4_b8(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vmsgtu_vv_u32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsgtu_vx_u32m4_b8(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vmsgtu_vx_u32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsgeu_vv_u32m4_b8(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vmsgeu_vv_u32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmsge_vx_u_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vmsge_vx_u_u32m4(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmseq_vv_u64m1_b64(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vmseq_vv_u64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmseq_vx_u64m1_b64(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vmseq_vx_u64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsne_vv_u64m1_b64(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vmsne_vv_u64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsne_vx_u64m1_b64(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vmsne_vx_u64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsltu_vv_u64m1_b64(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vmsltu_vv_u64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsltu_vx_u64m1_b64(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vmsltu_vx_u64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsleu_vv_u64m1_b64(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vmsleu_vv_u64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsleu_vx_u64m1_b64(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vmsleu_vx_u64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsgtu_vv_u64m1_b64(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vmsgtu_vv_u64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsgtu_vx_u64m1_b64(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vmsgtu_vx_u64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsgeu_vv_u64m1_b64(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vmsgeu_vv_u64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmsge_vx_u_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vmsge_vx_u_u64m1(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmseq_vv_u64m2_b32(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vmseq_vv_u64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmseq_vx_u64m2_b32(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vmseq_vx_u64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsne_vv_u64m2_b32(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vmsne_vv_u64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsne_vx_u64m2_b32(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vmsne_vx_u64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsltu_vv_u64m2_b32(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vmsltu_vv_u64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsltu_vx_u64m2_b32(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vmsltu_vx_u64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsleu_vv_u64m2_b32(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vmsleu_vv_u64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsleu_vx_u64m2_b32(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vmsleu_vx_u64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsgtu_vv_u64m2_b32(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vmsgtu_vv_u64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsgtu_vx_u64m2_b32(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vmsgtu_vx_u64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsgeu_vv_u64m2_b32(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vmsgeu_vv_u64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmsge_vx_u_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vmsge_vx_u_u64m2(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmseq_vv_u64m4_b16(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vmseq_vv_u64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmseq_vx_u64m4_b16(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vmseq_vx_u64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsne_vv_u64m4_b16(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vmsne_vv_u64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsne_vx_u64m4_b16(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vmsne_vx_u64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsltu_vv_u64m4_b16(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vmsltu_vv_u64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsltu_vx_u64m4_b16(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vmsltu_vx_u64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsleu_vv_u64m4_b16(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vmsleu_vv_u64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsleu_vx_u64m4_b16(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vmsleu_vx_u64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsgtu_vv_u64m4_b16(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vmsgtu_vv_u64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsgtu_vx_u64m4_b16(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vmsgtu_vx_u64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsgeu_vv_u64m4_b16(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vmsgeu_vv_u64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmsge_vx_u_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vmsge_vx_u_u64m4(op1, op2);
}


// Vector Integer Min/Max Operations
static __attribute__((always_inline))
vint8m1_t vmin_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vmin_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vmin_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vmin_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vmax_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vmax_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vmax_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vmax_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vmin_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmin_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vmin_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vmin_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vmax_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmax_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vmax_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vmax_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vmin_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vmin_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vmin_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vmin_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vmax_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vmax_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vmax_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vmax_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vmin_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmin_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vmin_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vmin_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vmax_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmax_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vmax_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vmax_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vmin_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vmin_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vmin_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vmin_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vmax_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vmax_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vmax_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vmax_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vmin_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmin_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vmin_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vmin_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vmax_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmax_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vmax_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vmax_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vmin_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vmin_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vmin_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vmin_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vmax_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vmax_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vmax_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vmax_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vmin_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmin_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vmin_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vmin_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vmax_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmax_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vmax_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vmax_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vmin_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vmin_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vmin_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vmin_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vmax_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vmax_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vmax_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vmax_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vmin_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmin_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vmin_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vmin_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vmax_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmax_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vmax_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vmax_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vmin_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vmin_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vmin_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vmin_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vmax_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vmax_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vmax_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vmax_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vmin_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmin_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vmin_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vmin_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vmax_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmax_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vmax_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vmax_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vminu_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vminu_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vminu_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vminu_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vmaxu_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vmaxu_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vmaxu_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vmaxu_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vminu_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vminu_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vminu_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vminu_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vmaxu_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vmaxu_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vmaxu_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vmaxu_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vminu_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vminu_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vminu_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vminu_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vmaxu_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vmaxu_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vmaxu_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vmaxu_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vminu_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vminu_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vminu_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vminu_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vmaxu_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vmaxu_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vmaxu_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vmaxu_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vminu_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vminu_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vminu_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vminu_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vmaxu_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vmaxu_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vmaxu_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vmaxu_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vminu_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vminu_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vminu_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vminu_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vmaxu_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vmaxu_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vmaxu_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vmaxu_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vminu_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vminu_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vminu_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vminu_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vmaxu_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vmaxu_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vmaxu_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vmaxu_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vminu_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vminu_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vminu_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vminu_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vmaxu_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vmaxu_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vmaxu_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vmaxu_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vminu_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vminu_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vminu_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vminu_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vmaxu_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vmaxu_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vmaxu_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vmaxu_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vminu_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vminu_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vminu_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vminu_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vmaxu_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vmaxu_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vmaxu_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vmaxu_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vminu_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vminu_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vminu_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vminu_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vmaxu_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vmaxu_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vmaxu_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vmaxu_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vminu_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vminu_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vminu_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vminu_vx_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vmaxu_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vmaxu_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vmaxu_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vmaxu_vx_u64m4(op1, op2);
}


// Vector Single-Width Integer Multiply Operations
static __attribute__((always_inline))
vint8m1_t vmul_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vmul_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vmul_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vmul_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vmul_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmul_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vmul_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vmul_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vmul_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vmul_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vmul_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vmul_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vmul_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmul_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vmul_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vmul_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vmul_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vmul_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vmul_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vmul_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vmul_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmul_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vmul_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vmul_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vmul_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vmul_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vmul_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vmul_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vmul_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmul_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vmul_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vmul_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vmul_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vmul_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vmul_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vmul_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vmul_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmul_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vmul_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vmul_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vmul_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vmul_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vmul_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vmul_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vmul_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmul_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vmul_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vmul_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vmul_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vmul_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vmul_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vmul_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vmul_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vmul_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vmul_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vmul_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vmul_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vmul_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vmul_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vmul_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vmul_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vmul_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vmul_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vmul_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vmul_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vmul_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vmul_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vmul_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vmul_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vmul_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vmul_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vmul_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vmul_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vmul_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vmul_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vmul_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vmul_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vmul_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vmul_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vmul_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vmul_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vmul_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vmul_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vmul_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vmul_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vmul_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vmul_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vmul_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vmul_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vmul_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vmul_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vmul_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vmul_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vmul_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vmul_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vmul_vx_u64m4(op1, op2);
}


// Vector Integer Divide Operations
static __attribute__((always_inline))
vint8m1_t vdiv_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vdiv_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vdiv_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vdiv_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vdivu_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vdivu_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vdivu_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vdivu_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vdiv_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vdiv_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vdiv_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vdiv_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vdivu_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vdivu_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vdivu_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vdivu_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vdiv_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vdiv_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vdiv_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vdiv_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vdivu_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vdivu_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vdivu_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vdivu_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vdiv_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vdiv_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vdiv_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vdiv_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vdivu_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vdivu_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vdivu_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vdivu_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vdiv_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vdiv_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vdiv_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vdiv_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vdivu_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vdivu_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vdivu_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vdivu_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vdiv_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vdiv_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vdiv_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vdiv_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vdivu_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vdivu_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vdivu_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vdivu_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vdiv_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vdiv_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vdiv_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vdiv_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vdivu_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vdivu_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vdivu_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vdivu_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vdiv_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vdiv_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vdiv_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vdiv_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vdivu_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vdivu_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vdivu_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vdivu_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vdiv_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vdiv_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vdiv_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vdiv_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vdivu_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vdivu_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vdivu_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vdivu_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vdiv_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vdiv_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vdiv_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vdiv_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vdivu_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vdivu_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vdivu_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vdivu_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vdiv_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vdiv_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vdiv_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vdiv_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vdivu_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vdivu_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vdivu_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vdivu_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vdiv_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vdiv_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vdiv_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vdiv_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vdivu_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vdivu_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vdivu_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vdivu_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vdiv_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vdiv_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vdiv_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vdiv_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vdivu_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vdivu_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vdivu_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vdivu_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vdiv_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vdiv_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vdiv_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vdiv_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vdivu_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vdivu_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vdivu_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vdivu_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vdiv_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vdiv_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vdiv_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vdiv_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vdivu_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vdivu_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vdivu_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vdivu_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vdiv_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vdiv_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vdiv_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vdiv_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vdivu_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vdivu_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vdivu_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vdivu_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vdiv_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vdiv_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vdiv_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vdiv_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vdivu_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vdivu_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vdivu_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vdivu_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vdiv_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vdiv_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vdiv_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vdiv_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vdivu_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vdivu_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vdivu_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vdivu_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vdiv_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vdiv_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vdiv_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vdiv_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vdivu_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vdivu_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vdivu_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vdivu_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vdiv_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vdiv_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vdiv_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vdiv_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vdivu_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vdivu_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vdivu_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vdivu_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vdiv_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vdiv_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vdiv_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vdiv_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vdivu_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vdivu_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vdivu_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vdivu_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vdiv_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vdiv_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vdiv_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vdiv_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vdivu_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vdivu_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vdivu_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vdivu_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vdiv_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vdiv_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vdiv_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vdiv_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vdivu_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vdivu_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vdivu_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vdivu_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vdiv_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vdiv_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vdiv_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vdiv_vx_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vdivu_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vdivu_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vdivu_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vdivu_vx_u64m4(op1, op2);
}


// Vector Single-Width Integer Multiply-Add Operations
static __attribute__((always_inline))
vint8m1_t vmacc_vv_i8m1(vint8m1_t acc, vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vmacc_vv_i8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vmacc_vx_i8m1(vint8m1_t acc, int8_t op1, vint8m1_t op2) {
  return __builtin_riscv_vmacc_vx_i8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vnmsac_vv_i8m1(vint8m1_t acc, vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vnmsac_vv_i8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vnmsac_vx_i8m1(vint8m1_t acc, int8_t op1, vint8m1_t op2) {
  return __builtin_riscv_vnmsac_vx_i8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vmadd_vv_i8m1(vint8m1_t acc, vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vmadd_vv_i8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vmadd_vf_i8m1(vint8m1_t acc, int8_t op1, vint8m1_t op2) {
  return __builtin_riscv_vmadd_vf_i8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vnmsub_vv_i8m1(vint8m1_t acc, vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vnmsub_vv_i8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vnmsub_vf_i8m1(vint8m1_t acc, int8_t op1, vint8m1_t op2) {
  return __builtin_riscv_vnmsub_vf_i8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vmacc_vv_i8m2(vint8m2_t acc, vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmacc_vv_i8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vmacc_vx_i8m2(vint8m2_t acc, int8_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmacc_vx_i8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vnmsac_vv_i8m2(vint8m2_t acc, vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vnmsac_vv_i8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vnmsac_vx_i8m2(vint8m2_t acc, int8_t op1, vint8m2_t op2) {
  return __builtin_riscv_vnmsac_vx_i8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vmadd_vv_i8m2(vint8m2_t acc, vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmadd_vv_i8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vmadd_vf_i8m2(vint8m2_t acc, int8_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmadd_vf_i8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vnmsub_vv_i8m2(vint8m2_t acc, vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vnmsub_vv_i8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vnmsub_vf_i8m2(vint8m2_t acc, int8_t op1, vint8m2_t op2) {
  return __builtin_riscv_vnmsub_vf_i8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vmacc_vv_i8m4(vint8m4_t acc, vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vmacc_vv_i8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vmacc_vx_i8m4(vint8m4_t acc, int8_t op1, vint8m4_t op2) {
  return __builtin_riscv_vmacc_vx_i8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vnmsac_vv_i8m4(vint8m4_t acc, vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vnmsac_vv_i8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vnmsac_vx_i8m4(vint8m4_t acc, int8_t op1, vint8m4_t op2) {
  return __builtin_riscv_vnmsac_vx_i8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vmadd_vv_i8m4(vint8m4_t acc, vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vmadd_vv_i8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vmadd_vf_i8m4(vint8m4_t acc, int8_t op1, vint8m4_t op2) {
  return __builtin_riscv_vmadd_vf_i8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vnmsub_vv_i8m4(vint8m4_t acc, vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vnmsub_vv_i8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vnmsub_vf_i8m4(vint8m4_t acc, int8_t op1, vint8m4_t op2) {
  return __builtin_riscv_vnmsub_vf_i8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vmacc_vv_i16m1(vint16m1_t acc, vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmacc_vv_i16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vmacc_vx_i16m1(vint16m1_t acc, int16_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmacc_vx_i16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vnmsac_vv_i16m1(vint16m1_t acc, vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vnmsac_vv_i16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vnmsac_vx_i16m1(vint16m1_t acc, int16_t op1, vint16m1_t op2) {
  return __builtin_riscv_vnmsac_vx_i16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vmadd_vv_i16m1(vint16m1_t acc, vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmadd_vv_i16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vmadd_vf_i16m1(vint16m1_t acc, int16_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmadd_vf_i16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vnmsub_vv_i16m1(vint16m1_t acc, vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vnmsub_vv_i16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vnmsub_vf_i16m1(vint16m1_t acc, int16_t op1, vint16m1_t op2) {
  return __builtin_riscv_vnmsub_vf_i16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vmacc_vv_i16m2(vint16m2_t acc, vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vmacc_vv_i16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vmacc_vx_i16m2(vint16m2_t acc, int16_t op1, vint16m2_t op2) {
  return __builtin_riscv_vmacc_vx_i16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vnmsac_vv_i16m2(vint16m2_t acc, vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vnmsac_vv_i16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vnmsac_vx_i16m2(vint16m2_t acc, int16_t op1, vint16m2_t op2) {
  return __builtin_riscv_vnmsac_vx_i16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vmadd_vv_i16m2(vint16m2_t acc, vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vmadd_vv_i16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vmadd_vf_i16m2(vint16m2_t acc, int16_t op1, vint16m2_t op2) {
  return __builtin_riscv_vmadd_vf_i16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vnmsub_vv_i16m2(vint16m2_t acc, vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vnmsub_vv_i16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vnmsub_vf_i16m2(vint16m2_t acc, int16_t op1, vint16m2_t op2) {
  return __builtin_riscv_vnmsub_vf_i16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vmacc_vv_i16m4(vint16m4_t acc, vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmacc_vv_i16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vmacc_vx_i16m4(vint16m4_t acc, int16_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmacc_vx_i16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vnmsac_vv_i16m4(vint16m4_t acc, vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vnmsac_vv_i16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vnmsac_vx_i16m4(vint16m4_t acc, int16_t op1, vint16m4_t op2) {
  return __builtin_riscv_vnmsac_vx_i16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vmadd_vv_i16m4(vint16m4_t acc, vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmadd_vv_i16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vmadd_vf_i16m4(vint16m4_t acc, int16_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmadd_vf_i16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vnmsub_vv_i16m4(vint16m4_t acc, vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vnmsub_vv_i16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vnmsub_vf_i16m4(vint16m4_t acc, int16_t op1, vint16m4_t op2) {
  return __builtin_riscv_vnmsub_vf_i16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vmacc_vv_i32m1(vint32m1_t acc, vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vmacc_vv_i32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vmacc_vx_i32m1(vint32m1_t acc, int32_t op1, vint32m1_t op2) {
  return __builtin_riscv_vmacc_vx_i32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vnmsac_vv_i32m1(vint32m1_t acc, vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vnmsac_vv_i32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vnmsac_vx_i32m1(vint32m1_t acc, int32_t op1, vint32m1_t op2) {
  return __builtin_riscv_vnmsac_vx_i32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vmadd_vv_i32m1(vint32m1_t acc, vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vmadd_vv_i32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vmadd_vf_i32m1(vint32m1_t acc, int32_t op1, vint32m1_t op2) {
  return __builtin_riscv_vmadd_vf_i32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vnmsub_vv_i32m1(vint32m1_t acc, vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vnmsub_vv_i32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vnmsub_vf_i32m1(vint32m1_t acc, int32_t op1, vint32m1_t op2) {
  return __builtin_riscv_vnmsub_vf_i32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vmacc_vv_i32m2(vint32m2_t acc, vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmacc_vv_i32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vmacc_vx_i32m2(vint32m2_t acc, int32_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmacc_vx_i32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vnmsac_vv_i32m2(vint32m2_t acc, vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vnmsac_vv_i32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vnmsac_vx_i32m2(vint32m2_t acc, int32_t op1, vint32m2_t op2) {
  return __builtin_riscv_vnmsac_vx_i32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vmadd_vv_i32m2(vint32m2_t acc, vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmadd_vv_i32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vmadd_vf_i32m2(vint32m2_t acc, int32_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmadd_vf_i32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vnmsub_vv_i32m2(vint32m2_t acc, vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vnmsub_vv_i32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vnmsub_vf_i32m2(vint32m2_t acc, int32_t op1, vint32m2_t op2) {
  return __builtin_riscv_vnmsub_vf_i32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vmacc_vv_i32m4(vint32m4_t acc, vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vmacc_vv_i32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vmacc_vx_i32m4(vint32m4_t acc, int32_t op1, vint32m4_t op2) {
  return __builtin_riscv_vmacc_vx_i32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vnmsac_vv_i32m4(vint32m4_t acc, vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vnmsac_vv_i32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vnmsac_vx_i32m4(vint32m4_t acc, int32_t op1, vint32m4_t op2) {
  return __builtin_riscv_vnmsac_vx_i32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vmadd_vv_i32m4(vint32m4_t acc, vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vmadd_vv_i32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vmadd_vf_i32m4(vint32m4_t acc, int32_t op1, vint32m4_t op2) {
  return __builtin_riscv_vmadd_vf_i32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vnmsub_vv_i32m4(vint32m4_t acc, vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vnmsub_vv_i32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vnmsub_vf_i32m4(vint32m4_t acc, int32_t op1, vint32m4_t op2) {
  return __builtin_riscv_vnmsub_vf_i32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vmacc_vv_i64m1(vint64m1_t acc, vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmacc_vv_i64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vmacc_vx_i64m1(vint64m1_t acc, int64_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmacc_vx_i64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vnmsac_vv_i64m1(vint64m1_t acc, vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vnmsac_vv_i64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vnmsac_vx_i64m1(vint64m1_t acc, int64_t op1, vint64m1_t op2) {
  return __builtin_riscv_vnmsac_vx_i64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vmadd_vv_i64m1(vint64m1_t acc, vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmadd_vv_i64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vmadd_vf_i64m1(vint64m1_t acc, int64_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmadd_vf_i64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vnmsub_vv_i64m1(vint64m1_t acc, vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vnmsub_vv_i64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vnmsub_vf_i64m1(vint64m1_t acc, int64_t op1, vint64m1_t op2) {
  return __builtin_riscv_vnmsub_vf_i64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vmacc_vv_i64m2(vint64m2_t acc, vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vmacc_vv_i64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vmacc_vx_i64m2(vint64m2_t acc, int64_t op1, vint64m2_t op2) {
  return __builtin_riscv_vmacc_vx_i64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vnmsac_vv_i64m2(vint64m2_t acc, vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vnmsac_vv_i64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vnmsac_vx_i64m2(vint64m2_t acc, int64_t op1, vint64m2_t op2) {
  return __builtin_riscv_vnmsac_vx_i64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vmadd_vv_i64m2(vint64m2_t acc, vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vmadd_vv_i64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vmadd_vf_i64m2(vint64m2_t acc, int64_t op1, vint64m2_t op2) {
  return __builtin_riscv_vmadd_vf_i64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vnmsub_vv_i64m2(vint64m2_t acc, vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vnmsub_vv_i64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vnmsub_vf_i64m2(vint64m2_t acc, int64_t op1, vint64m2_t op2) {
  return __builtin_riscv_vnmsub_vf_i64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vmacc_vv_i64m4(vint64m4_t acc, vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmacc_vv_i64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vmacc_vx_i64m4(vint64m4_t acc, int64_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmacc_vx_i64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vnmsac_vv_i64m4(vint64m4_t acc, vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vnmsac_vv_i64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vnmsac_vx_i64m4(vint64m4_t acc, int64_t op1, vint64m4_t op2) {
  return __builtin_riscv_vnmsac_vx_i64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vmadd_vv_i64m4(vint64m4_t acc, vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmadd_vv_i64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vmadd_vf_i64m4(vint64m4_t acc, int64_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmadd_vf_i64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vnmsub_vv_i64m4(vint64m4_t acc, vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vnmsub_vv_i64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vnmsub_vf_i64m4(vint64m4_t acc, int64_t op1, vint64m4_t op2) {
  return __builtin_riscv_vnmsub_vf_i64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vmacc_vv_u8m1(vuint8m1_t acc, vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vmacc_vv_u8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vmacc_vx_u8m1(vuint8m1_t acc, uint8_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vmacc_vx_u8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vnmsac_vv_u8m1(vuint8m1_t acc, vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vnmsac_vv_u8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vnmsac_vx_u8m1(vuint8m1_t acc, uint8_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vnmsac_vx_u8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vmadd_vv_u8m1(vuint8m1_t acc, vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vmadd_vv_u8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vmadd_vf_u8m1(vuint8m1_t acc, uint8_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vmadd_vf_u8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vnmsub_vv_u8m1(vuint8m1_t acc, vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vnmsub_vv_u8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vnmsub_vf_u8m1(vuint8m1_t acc, uint8_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vnmsub_vf_u8m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vmacc_vv_u8m2(vuint8m2_t acc, vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vmacc_vv_u8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vmacc_vx_u8m2(vuint8m2_t acc, uint8_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vmacc_vx_u8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vnmsac_vv_u8m2(vuint8m2_t acc, vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vnmsac_vv_u8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vnmsac_vx_u8m2(vuint8m2_t acc, uint8_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vnmsac_vx_u8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vmadd_vv_u8m2(vuint8m2_t acc, vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vmadd_vv_u8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vmadd_vf_u8m2(vuint8m2_t acc, uint8_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vmadd_vf_u8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vnmsub_vv_u8m2(vuint8m2_t acc, vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vnmsub_vv_u8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vnmsub_vf_u8m2(vuint8m2_t acc, uint8_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vnmsub_vf_u8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vmacc_vv_u8m4(vuint8m4_t acc, vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vmacc_vv_u8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vmacc_vx_u8m4(vuint8m4_t acc, uint8_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vmacc_vx_u8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vnmsac_vv_u8m4(vuint8m4_t acc, vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vnmsac_vv_u8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vnmsac_vx_u8m4(vuint8m4_t acc, uint8_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vnmsac_vx_u8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vmadd_vv_u8m4(vuint8m4_t acc, vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vmadd_vv_u8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vmadd_vf_u8m4(vuint8m4_t acc, uint8_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vmadd_vf_u8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vnmsub_vv_u8m4(vuint8m4_t acc, vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vnmsub_vv_u8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vnmsub_vf_u8m4(vuint8m4_t acc, uint8_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vnmsub_vf_u8m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vmacc_vv_u16m1(vuint16m1_t acc, vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vmacc_vv_u16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vmacc_vx_u16m1(vuint16m1_t acc, uint16_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vmacc_vx_u16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vnmsac_vv_u16m1(vuint16m1_t acc, vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vnmsac_vv_u16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vnmsac_vx_u16m1(vuint16m1_t acc, uint16_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vnmsac_vx_u16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vmadd_vv_u16m1(vuint16m1_t acc, vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vmadd_vv_u16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vmadd_vf_u16m1(vuint16m1_t acc, uint16_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vmadd_vf_u16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vnmsub_vv_u16m1(vuint16m1_t acc, vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vnmsub_vv_u16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vnmsub_vf_u16m1(vuint16m1_t acc, uint16_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vnmsub_vf_u16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vmacc_vv_u16m2(vuint16m2_t acc, vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vmacc_vv_u16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vmacc_vx_u16m2(vuint16m2_t acc, uint16_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vmacc_vx_u16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vnmsac_vv_u16m2(vuint16m2_t acc, vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vnmsac_vv_u16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vnmsac_vx_u16m2(vuint16m2_t acc, uint16_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vnmsac_vx_u16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vmadd_vv_u16m2(vuint16m2_t acc, vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vmadd_vv_u16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vmadd_vf_u16m2(vuint16m2_t acc, uint16_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vmadd_vf_u16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vnmsub_vv_u16m2(vuint16m2_t acc, vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vnmsub_vv_u16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vnmsub_vf_u16m2(vuint16m2_t acc, uint16_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vnmsub_vf_u16m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vmacc_vv_u16m4(vuint16m4_t acc, vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vmacc_vv_u16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vmacc_vx_u16m4(vuint16m4_t acc, uint16_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vmacc_vx_u16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vnmsac_vv_u16m4(vuint16m4_t acc, vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vnmsac_vv_u16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vnmsac_vx_u16m4(vuint16m4_t acc, uint16_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vnmsac_vx_u16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vmadd_vv_u16m4(vuint16m4_t acc, vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vmadd_vv_u16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vmadd_vf_u16m4(vuint16m4_t acc, uint16_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vmadd_vf_u16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vnmsub_vv_u16m4(vuint16m4_t acc, vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vnmsub_vv_u16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vnmsub_vf_u16m4(vuint16m4_t acc, uint16_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vnmsub_vf_u16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vmacc_vv_u32m1(vuint32m1_t acc, vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vmacc_vv_u32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vmacc_vx_u32m1(vuint32m1_t acc, uint32_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vmacc_vx_u32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vnmsac_vv_u32m1(vuint32m1_t acc, vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vnmsac_vv_u32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vnmsac_vx_u32m1(vuint32m1_t acc, uint32_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vnmsac_vx_u32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vmadd_vv_u32m1(vuint32m1_t acc, vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vmadd_vv_u32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vmadd_vf_u32m1(vuint32m1_t acc, uint32_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vmadd_vf_u32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vnmsub_vv_u32m1(vuint32m1_t acc, vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vnmsub_vv_u32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vnmsub_vf_u32m1(vuint32m1_t acc, uint32_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vnmsub_vf_u32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vmacc_vv_u32m2(vuint32m2_t acc, vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vmacc_vv_u32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vmacc_vx_u32m2(vuint32m2_t acc, uint32_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vmacc_vx_u32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vnmsac_vv_u32m2(vuint32m2_t acc, vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vnmsac_vv_u32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vnmsac_vx_u32m2(vuint32m2_t acc, uint32_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vnmsac_vx_u32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vmadd_vv_u32m2(vuint32m2_t acc, vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vmadd_vv_u32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vmadd_vf_u32m2(vuint32m2_t acc, uint32_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vmadd_vf_u32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vnmsub_vv_u32m2(vuint32m2_t acc, vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vnmsub_vv_u32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vnmsub_vf_u32m2(vuint32m2_t acc, uint32_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vnmsub_vf_u32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vmacc_vv_u32m4(vuint32m4_t acc, vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vmacc_vv_u32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vmacc_vx_u32m4(vuint32m4_t acc, uint32_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vmacc_vx_u32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vnmsac_vv_u32m4(vuint32m4_t acc, vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vnmsac_vv_u32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vnmsac_vx_u32m4(vuint32m4_t acc, uint32_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vnmsac_vx_u32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vmadd_vv_u32m4(vuint32m4_t acc, vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vmadd_vv_u32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vmadd_vf_u32m4(vuint32m4_t acc, uint32_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vmadd_vf_u32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vnmsub_vv_u32m4(vuint32m4_t acc, vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vnmsub_vv_u32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vnmsub_vf_u32m4(vuint32m4_t acc, uint32_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vnmsub_vf_u32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vmacc_vv_u64m1(vuint64m1_t acc, vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vmacc_vv_u64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vmacc_vx_u64m1(vuint64m1_t acc, uint64_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vmacc_vx_u64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vnmsac_vv_u64m1(vuint64m1_t acc, vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vnmsac_vv_u64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vnmsac_vx_u64m1(vuint64m1_t acc, uint64_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vnmsac_vx_u64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vmadd_vv_u64m1(vuint64m1_t acc, vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vmadd_vv_u64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vmadd_vf_u64m1(vuint64m1_t acc, uint64_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vmadd_vf_u64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vnmsub_vv_u64m1(vuint64m1_t acc, vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vnmsub_vv_u64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vnmsub_vf_u64m1(vuint64m1_t acc, uint64_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vnmsub_vf_u64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vmacc_vv_u64m2(vuint64m2_t acc, vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vmacc_vv_u64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vmacc_vx_u64m2(vuint64m2_t acc, uint64_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vmacc_vx_u64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vnmsac_vv_u64m2(vuint64m2_t acc, vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vnmsac_vv_u64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vnmsac_vx_u64m2(vuint64m2_t acc, uint64_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vnmsac_vx_u64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vmadd_vv_u64m2(vuint64m2_t acc, vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vmadd_vv_u64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vmadd_vf_u64m2(vuint64m2_t acc, uint64_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vmadd_vf_u64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vnmsub_vv_u64m2(vuint64m2_t acc, vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vnmsub_vv_u64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vnmsub_vf_u64m2(vuint64m2_t acc, uint64_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vnmsub_vf_u64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vmacc_vv_u64m4(vuint64m4_t acc, vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vmacc_vv_u64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vmacc_vx_u64m4(vuint64m4_t acc, uint64_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vmacc_vx_u64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vnmsac_vv_u64m4(vuint64m4_t acc, vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vnmsac_vv_u64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vnmsac_vx_u64m4(vuint64m4_t acc, uint64_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vnmsac_vx_u64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vmadd_vv_u64m4(vuint64m4_t acc, vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vmadd_vv_u64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vmadd_vf_u64m4(vuint64m4_t acc, uint64_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vmadd_vf_u64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vnmsub_vv_u64m4(vuint64m4_t acc, vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vnmsub_vv_u64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vnmsub_vf_u64m4(vuint64m4_t acc, uint64_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vnmsub_vf_u64m4(acc, op1, op2);
}


// Vector Integer Merge Operations
static __attribute__((always_inline))
vint8m1_t vmerge_vvm_i8m1(vbool8_t mask, vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vmerge_vvm_i8m1(mask, op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vmerge_vxm_i8m1(vbool8_t mask, vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vmerge_vxm_i8m1(mask, op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vmerge_vvm_i8m2(vbool4_t mask, vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmerge_vvm_i8m2(mask, op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vmerge_vxm_i8m2(vbool4_t mask, vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vmerge_vxm_i8m2(mask, op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vmerge_vvm_i8m4(vbool2_t mask, vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vmerge_vvm_i8m4(mask, op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vmerge_vxm_i8m4(vbool2_t mask, vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vmerge_vxm_i8m4(mask, op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vmerge_vvm_i16m1(vbool16_t mask, vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmerge_vvm_i16m1(mask, op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vmerge_vxm_i16m1(vbool16_t mask, vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vmerge_vxm_i16m1(mask, op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vmerge_vvm_i16m2(vbool8_t mask, vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vmerge_vvm_i16m2(mask, op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vmerge_vxm_i16m2(vbool8_t mask, vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vmerge_vxm_i16m2(mask, op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vmerge_vvm_i16m4(vbool4_t mask, vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmerge_vvm_i16m4(mask, op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vmerge_vxm_i16m4(vbool4_t mask, vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vmerge_vxm_i16m4(mask, op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vmerge_vvm_i32m1(vbool32_t mask, vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vmerge_vvm_i32m1(mask, op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vmerge_vxm_i32m1(vbool32_t mask, vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vmerge_vxm_i32m1(mask, op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vmerge_vvm_i32m2(vbool16_t mask, vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmerge_vvm_i32m2(mask, op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vmerge_vxm_i32m2(vbool16_t mask, vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vmerge_vxm_i32m2(mask, op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vmerge_vvm_i32m4(vbool8_t mask, vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vmerge_vvm_i32m4(mask, op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vmerge_vxm_i32m4(vbool8_t mask, vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vmerge_vxm_i32m4(mask, op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vmerge_vvm_i64m1(vbool64_t mask, vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmerge_vvm_i64m1(mask, op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vmerge_vxm_i64m1(vbool64_t mask, vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vmerge_vxm_i64m1(mask, op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vmerge_vvm_i64m2(vbool32_t mask, vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vmerge_vvm_i64m2(mask, op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vmerge_vxm_i64m2(vbool32_t mask, vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vmerge_vxm_i64m2(mask, op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vmerge_vvm_i64m4(vbool16_t mask, vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmerge_vvm_i64m4(mask, op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vmerge_vxm_i64m4(vbool16_t mask, vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vmerge_vxm_i64m4(mask, op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vmerge_vvm_u8m1(vbool8_t mask, vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vmerge_vvm_u8m1(mask, op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vmerge_vxm_u8m1(vbool8_t mask, vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vmerge_vxm_u8m1(mask, op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vmerge_vvm_u8m2(vbool4_t mask, vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vmerge_vvm_u8m2(mask, op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vmerge_vxm_u8m2(vbool4_t mask, vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vmerge_vxm_u8m2(mask, op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vmerge_vvm_u8m4(vbool2_t mask, vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vmerge_vvm_u8m4(mask, op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vmerge_vxm_u8m4(vbool2_t mask, vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vmerge_vxm_u8m4(mask, op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vmerge_vvm_u16m1(vbool16_t mask, vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vmerge_vvm_u16m1(mask, op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vmerge_vxm_u16m1(vbool16_t mask, vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vmerge_vxm_u16m1(mask, op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vmerge_vvm_u16m2(vbool8_t mask, vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vmerge_vvm_u16m2(mask, op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vmerge_vxm_u16m2(vbool8_t mask, vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vmerge_vxm_u16m2(mask, op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vmerge_vvm_u16m4(vbool4_t mask, vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vmerge_vvm_u16m4(mask, op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vmerge_vxm_u16m4(vbool4_t mask, vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vmerge_vxm_u16m4(mask, op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vmerge_vvm_u32m1(vbool32_t mask, vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vmerge_vvm_u32m1(mask, op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vmerge_vxm_u32m1(vbool32_t mask, vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vmerge_vxm_u32m1(mask, op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vmerge_vvm_u32m2(vbool16_t mask, vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vmerge_vvm_u32m2(mask, op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vmerge_vxm_u32m2(vbool16_t mask, vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vmerge_vxm_u32m2(mask, op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vmerge_vvm_u32m4(vbool8_t mask, vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vmerge_vvm_u32m4(mask, op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vmerge_vxm_u32m4(vbool8_t mask, vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vmerge_vxm_u32m4(mask, op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vmerge_vvm_u64m1(vbool64_t mask, vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vmerge_vvm_u64m1(mask, op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vmerge_vxm_u64m1(vbool64_t mask, vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vmerge_vxm_u64m1(mask, op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vmerge_vvm_u64m2(vbool32_t mask, vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vmerge_vvm_u64m2(mask, op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vmerge_vxm_u64m2(vbool32_t mask, vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vmerge_vxm_u64m2(mask, op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vmerge_vvm_u64m4(vbool16_t mask, vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vmerge_vvm_u64m4(mask, op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vmerge_vxm_u64m4(vbool16_t mask, vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vmerge_vxm_u64m4(mask, op1, op2);
}


// Vector Fixed-Point Arithmetic Operations

// Vector Single-Width Saturating Add and Subtract Functions
static __attribute__((always_inline))
vint8m1_t vsadd_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vsadd_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vsadd_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vsadd_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vsaddu_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vsaddu_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vsaddu_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vsaddu_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vssub_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vssub_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vssub_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vssub_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vssubu_vv_i8m1(vint8m1_t op1, vint8m1_t op2) {
  return __builtin_riscv_vssubu_vv_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m1_t vssubu_vx_i8m1(vint8m1_t op1, int8_t op2) {
  return __builtin_riscv_vssubu_vx_i8m1(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vsadd_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vsadd_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vsadd_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vsadd_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vsaddu_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vsaddu_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vsaddu_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vsaddu_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vssub_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vssub_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vssub_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vssub_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vssubu_vv_i8m2(vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vssubu_vv_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vssubu_vx_i8m2(vint8m2_t op1, int8_t op2) {
  return __builtin_riscv_vssubu_vx_i8m2(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vsadd_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vsadd_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vsadd_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vsadd_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vsaddu_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vsaddu_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vsaddu_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vsaddu_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vssub_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vssub_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vssub_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vssub_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vssubu_vv_i8m4(vint8m4_t op1, vint8m4_t op2) {
  return __builtin_riscv_vssubu_vv_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint8m4_t vssubu_vx_i8m4(vint8m4_t op1, int8_t op2) {
  return __builtin_riscv_vssubu_vx_i8m4(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vsadd_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vsadd_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vsadd_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vsadd_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vsaddu_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vsaddu_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vsaddu_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vsaddu_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vssub_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vssub_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vssub_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vssub_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vssubu_vv_i16m1(vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vssubu_vv_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vssubu_vx_i16m1(vint16m1_t op1, int16_t op2) {
  return __builtin_riscv_vssubu_vx_i16m1(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vsadd_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vsadd_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vsadd_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vsadd_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vsaddu_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vsaddu_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vsaddu_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vsaddu_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vssub_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vssub_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vssub_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vssub_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vssubu_vv_i16m2(vint16m2_t op1, vint16m2_t op2) {
  return __builtin_riscv_vssubu_vv_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m2_t vssubu_vx_i16m2(vint16m2_t op1, int16_t op2) {
  return __builtin_riscv_vssubu_vx_i16m2(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vsadd_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vsadd_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vsadd_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vsadd_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vsaddu_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vsaddu_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vsaddu_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vsaddu_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vssub_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vssub_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vssub_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vssub_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vssubu_vv_i16m4(vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vssubu_vv_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vssubu_vx_i16m4(vint16m4_t op1, int16_t op2) {
  return __builtin_riscv_vssubu_vx_i16m4(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vsadd_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vsadd_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vsadd_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vsadd_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vsaddu_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vsaddu_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vsaddu_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vsaddu_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vssub_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vssub_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vssub_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vssub_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vssubu_vv_i32m1(vint32m1_t op1, vint32m1_t op2) {
  return __builtin_riscv_vssubu_vv_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m1_t vssubu_vx_i32m1(vint32m1_t op1, int32_t op2) {
  return __builtin_riscv_vssubu_vx_i32m1(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vsadd_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vsadd_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vsadd_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vsadd_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vsaddu_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vsaddu_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vsaddu_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vsaddu_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vssub_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vssub_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vssub_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vssub_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vssubu_vv_i32m2(vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vssubu_vv_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vssubu_vx_i32m2(vint32m2_t op1, int32_t op2) {
  return __builtin_riscv_vssubu_vx_i32m2(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vsadd_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vsadd_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vsadd_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vsadd_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vsaddu_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vsaddu_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vsaddu_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vsaddu_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vssub_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vssub_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vssub_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vssub_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vssubu_vv_i32m4(vint32m4_t op1, vint32m4_t op2) {
  return __builtin_riscv_vssubu_vv_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint32m4_t vssubu_vx_i32m4(vint32m4_t op1, int32_t op2) {
  return __builtin_riscv_vssubu_vx_i32m4(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vsadd_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vsadd_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vsadd_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vsadd_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vsaddu_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vsaddu_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vsaddu_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vsaddu_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vssub_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vssub_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vssub_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vssub_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vssubu_vv_i64m1(vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vssubu_vv_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vssubu_vx_i64m1(vint64m1_t op1, int64_t op2) {
  return __builtin_riscv_vssubu_vx_i64m1(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vsadd_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vsadd_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vsadd_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vsadd_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vsaddu_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vsaddu_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vsaddu_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vsaddu_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vssub_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vssub_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vssub_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vssub_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vssubu_vv_i64m2(vint64m2_t op1, vint64m2_t op2) {
  return __builtin_riscv_vssubu_vv_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m2_t vssubu_vx_i64m2(vint64m2_t op1, int64_t op2) {
  return __builtin_riscv_vssubu_vx_i64m2(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vsadd_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vsadd_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vsadd_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vsadd_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vsaddu_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vsaddu_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vsaddu_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vsaddu_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vssub_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vssub_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vssub_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vssub_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vssubu_vv_i64m4(vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vssubu_vv_i64m4(op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vssubu_vx_i64m4(vint64m4_t op1, int64_t op2) {
  return __builtin_riscv_vssubu_vx_i64m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vsadd_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vsadd_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vsadd_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vsadd_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vsaddu_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vsaddu_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vsaddu_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vsaddu_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vssub_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vssub_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vssub_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vssub_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vssubu_vv_u8m1(vuint8m1_t op1, vuint8m1_t op2) {
  return __builtin_riscv_vssubu_vv_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m1_t vssubu_vx_u8m1(vuint8m1_t op1, uint8_t op2) {
  return __builtin_riscv_vssubu_vx_u8m1(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vsadd_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vsadd_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vsadd_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vsadd_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vsaddu_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vsaddu_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vsaddu_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vsaddu_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vssub_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vssub_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vssub_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vssub_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vssubu_vv_u8m2(vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vssubu_vv_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vssubu_vx_u8m2(vuint8m2_t op1, uint8_t op2) {
  return __builtin_riscv_vssubu_vx_u8m2(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vsadd_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vsadd_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vsadd_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vsadd_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vsaddu_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vsaddu_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vsaddu_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vsaddu_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vssub_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vssub_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vssub_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vssub_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vssubu_vv_u8m4(vuint8m4_t op1, vuint8m4_t op2) {
  return __builtin_riscv_vssubu_vv_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint8m4_t vssubu_vx_u8m4(vuint8m4_t op1, uint8_t op2) {
  return __builtin_riscv_vssubu_vx_u8m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vsadd_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vsadd_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vsadd_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vsadd_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vsaddu_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vsaddu_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vsaddu_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vsaddu_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vssub_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vssub_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vssub_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vssub_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vssubu_vv_u16m1(vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vssubu_vv_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vssubu_vx_u16m1(vuint16m1_t op1, uint16_t op2) {
  return __builtin_riscv_vssubu_vx_u16m1(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vsadd_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vsadd_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vsadd_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vsadd_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vsaddu_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vsaddu_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vsaddu_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vsaddu_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vssub_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vssub_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vssub_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vssub_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vssubu_vv_u16m2(vuint16m2_t op1, vuint16m2_t op2) {
  return __builtin_riscv_vssubu_vv_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m2_t vssubu_vx_u16m2(vuint16m2_t op1, uint16_t op2) {
  return __builtin_riscv_vssubu_vx_u16m2(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vsadd_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vsadd_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vsadd_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vsadd_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vsaddu_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vsaddu_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vsaddu_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vsaddu_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vssub_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vssub_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vssub_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vssub_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vssubu_vv_u16m4(vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vssubu_vv_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vssubu_vx_u16m4(vuint16m4_t op1, uint16_t op2) {
  return __builtin_riscv_vssubu_vx_u16m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vsadd_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vsadd_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vsadd_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vsadd_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vsaddu_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vsaddu_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vsaddu_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vsaddu_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vssub_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vssub_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vssub_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vssub_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vssubu_vv_u32m1(vuint32m1_t op1, vuint32m1_t op2) {
  return __builtin_riscv_vssubu_vv_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m1_t vssubu_vx_u32m1(vuint32m1_t op1, uint32_t op2) {
  return __builtin_riscv_vssubu_vx_u32m1(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vsadd_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vsadd_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vsadd_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vsadd_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vsaddu_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vsaddu_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vsaddu_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vsaddu_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vssub_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vssub_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vssub_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vssub_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vssubu_vv_u32m2(vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vssubu_vv_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vssubu_vx_u32m2(vuint32m2_t op1, uint32_t op2) {
  return __builtin_riscv_vssubu_vx_u32m2(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vsadd_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vsadd_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vsadd_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vsadd_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vsaddu_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vsaddu_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vsaddu_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vsaddu_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vssub_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vssub_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vssub_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vssub_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vssubu_vv_u32m4(vuint32m4_t op1, vuint32m4_t op2) {
  return __builtin_riscv_vssubu_vv_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint32m4_t vssubu_vx_u32m4(vuint32m4_t op1, uint32_t op2) {
  return __builtin_riscv_vssubu_vx_u32m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vsadd_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vsadd_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vsadd_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vsadd_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vsaddu_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vsaddu_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vsaddu_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vsaddu_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vssub_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vssub_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vssub_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vssub_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vssubu_vv_u64m1(vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vssubu_vv_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vssubu_vx_u64m1(vuint64m1_t op1, uint64_t op2) {
  return __builtin_riscv_vssubu_vx_u64m1(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vsadd_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vsadd_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vsadd_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vsadd_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vsaddu_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vsaddu_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vsaddu_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vsaddu_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vssub_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vssub_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vssub_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vssub_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vssubu_vv_u64m2(vuint64m2_t op1, vuint64m2_t op2) {
  return __builtin_riscv_vssubu_vv_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m2_t vssubu_vx_u64m2(vuint64m2_t op1, uint64_t op2) {
  return __builtin_riscv_vssubu_vx_u64m2(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vsadd_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vsadd_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vsadd_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vsadd_vx_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vsaddu_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vsaddu_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vsaddu_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vsaddu_vx_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vssub_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vssub_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vssub_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vssub_vx_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vssubu_vv_u64m4(vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vssubu_vv_u64m4(op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vssubu_vx_u64m4(vuint64m4_t op1, uint64_t op2) {
  return __builtin_riscv_vssubu_vx_u64m4(op1, op2);
}


// Vector Floating-Point Operations

// Vector Single-Width Floating-Point Add/Subtract Operations
static __attribute__((always_inline))
vfloat32m1_t vfadd_vv_f32m1(vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfadd_vv_f32m1(op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfadd_vf_f32m1(vfloat32m1_t op1, float op2) {
  return __builtin_riscv_vfadd_vf_f32m1(op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfsub_vv_f32m1(vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfsub_vv_f32m1(op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfsub_vf_f32m1(vfloat32m1_t op1, float op2) {
  return __builtin_riscv_vfsub_vf_f32m1(op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfadd_vv_f32m2(vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfadd_vv_f32m2(op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfadd_vf_f32m2(vfloat32m2_t op1, float op2) {
  return __builtin_riscv_vfadd_vf_f32m2(op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfsub_vv_f32m2(vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfsub_vv_f32m2(op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfsub_vf_f32m2(vfloat32m2_t op1, float op2) {
  return __builtin_riscv_vfsub_vf_f32m2(op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfadd_vv_f32m4(vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfadd_vv_f32m4(op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfadd_vf_f32m4(vfloat32m4_t op1, float op2) {
  return __builtin_riscv_vfadd_vf_f32m4(op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfsub_vv_f32m4(vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfsub_vv_f32m4(op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfsub_vf_f32m4(vfloat32m4_t op1, float op2) {
  return __builtin_riscv_vfsub_vf_f32m4(op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfadd_vv_f64m1(vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfadd_vv_f64m1(op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfadd_vf_f64m1(vfloat64m1_t op1, double op2) {
  return __builtin_riscv_vfadd_vf_f64m1(op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfsub_vv_f64m1(vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfsub_vv_f64m1(op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfsub_vf_f64m1(vfloat64m1_t op1, double op2) {
  return __builtin_riscv_vfsub_vf_f64m1(op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfadd_vv_f64m2(vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfadd_vv_f64m2(op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfadd_vf_f64m2(vfloat64m2_t op1, double op2) {
  return __builtin_riscv_vfadd_vf_f64m2(op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfsub_vv_f64m2(vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfsub_vv_f64m2(op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfsub_vf_f64m2(vfloat64m2_t op1, double op2) {
  return __builtin_riscv_vfsub_vf_f64m2(op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfadd_vv_f64m4(vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfadd_vv_f64m4(op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfadd_vf_f64m4(vfloat64m4_t op1, double op2) {
  return __builtin_riscv_vfadd_vf_f64m4(op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfsub_vv_f64m4(vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfsub_vv_f64m4(op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfsub_vf_f64m4(vfloat64m4_t op1, double op2) {
  return __builtin_riscv_vfsub_vf_f64m4(op1, op2);
}


// Vector Single-Width Floating-Point Multiply/Divide Operations
static __attribute__((always_inline))
vfloat32m1_t vfmul_vv_f32m1(vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfmul_vv_f32m1(op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfmul_vf_f32m1(vfloat32m1_t op1, float op2) {
  return __builtin_riscv_vfmul_vf_f32m1(op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfdiv_vv_f32m1(vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfdiv_vv_f32m1(op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfdiv_vf_f32m1(vfloat32m1_t op1, float op2) {
  return __builtin_riscv_vfdiv_vf_f32m1(op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmul_vv_f32m2(vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfmul_vv_f32m2(op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmul_vf_f32m2(vfloat32m2_t op1, float op2) {
  return __builtin_riscv_vfmul_vf_f32m2(op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfdiv_vv_f32m2(vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfdiv_vv_f32m2(op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfdiv_vf_f32m2(vfloat32m2_t op1, float op2) {
  return __builtin_riscv_vfdiv_vf_f32m2(op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfmul_vv_f32m4(vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfmul_vv_f32m4(op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfmul_vf_f32m4(vfloat32m4_t op1, float op2) {
  return __builtin_riscv_vfmul_vf_f32m4(op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfdiv_vv_f32m4(vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfdiv_vv_f32m4(op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfdiv_vf_f32m4(vfloat32m4_t op1, float op2) {
  return __builtin_riscv_vfdiv_vf_f32m4(op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmul_vv_f64m1(vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfmul_vv_f64m1(op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmul_vf_f64m1(vfloat64m1_t op1, double op2) {
  return __builtin_riscv_vfmul_vf_f64m1(op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfdiv_vv_f64m1(vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfdiv_vv_f64m1(op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfdiv_vf_f64m1(vfloat64m1_t op1, double op2) {
  return __builtin_riscv_vfdiv_vf_f64m1(op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfmul_vv_f64m2(vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfmul_vv_f64m2(op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfmul_vf_f64m2(vfloat64m2_t op1, double op2) {
  return __builtin_riscv_vfmul_vf_f64m2(op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfdiv_vv_f64m2(vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfdiv_vv_f64m2(op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfdiv_vf_f64m2(vfloat64m2_t op1, double op2) {
  return __builtin_riscv_vfdiv_vf_f64m2(op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmul_vv_f64m4(vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfmul_vv_f64m4(op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmul_vf_f64m4(vfloat64m4_t op1, double op2) {
  return __builtin_riscv_vfmul_vf_f64m4(op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfdiv_vv_f64m4(vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfdiv_vv_f64m4(op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfdiv_vf_f64m4(vfloat64m4_t op1, double op2) {
  return __builtin_riscv_vfdiv_vf_f64m4(op1, op2);
}


// Vector Single-Width Floating-Point Fused Multiply-Add Operations
static __attribute__((always_inline))
vfloat32m1_t vfmacc_vv_f32m1(vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfmacc_vv_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfmacc_vf_f32m1(vfloat32m1_t acc, float op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfmacc_vf_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfnmacc_vv_f32m1(vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfnmacc_vv_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfnmacc_vf_f32m1(vfloat32m1_t acc, float op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfnmacc_vf_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfmsac_vv_f32m1(vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfmsac_vv_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfmsac_vf_f32m1(vfloat32m1_t acc, float op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfmsac_vf_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfnmsac_vv_f32m1(vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfnmsac_vv_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfnmsac_vf_f32m1(vfloat32m1_t acc, float op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfnmsac_vf_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfmadd_vv_f32m1(vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfmadd_vv_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfmadd_vf_f32m1(vfloat32m1_t acc, float op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfmadd_vf_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfnmadd_vv_f32m1(vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfnmadd_vv_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfnmadd_vf_f32m1(vfloat32m1_t acc, float op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfnmadd_vf_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfmsub_vv_f32m1(vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfmsub_vv_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfmsub_vf_f32m1(vfloat32m1_t acc, float op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfmsub_vf_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfnmsub_vv_f32m1(vfloat32m1_t acc, vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfnmsub_vv_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfnmsub_vf_f32m1(vfloat32m1_t acc, float op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfnmsub_vf_f32m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmacc_vv_f32m2(vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfmacc_vv_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmacc_vf_f32m2(vfloat32m2_t acc, float op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfmacc_vf_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfnmacc_vv_f32m2(vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfnmacc_vv_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfnmacc_vf_f32m2(vfloat32m2_t acc, float op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfnmacc_vf_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmsac_vv_f32m2(vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfmsac_vv_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmsac_vf_f32m2(vfloat32m2_t acc, float op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfmsac_vf_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfnmsac_vv_f32m2(vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfnmsac_vv_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfnmsac_vf_f32m2(vfloat32m2_t acc, float op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfnmsac_vf_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmadd_vv_f32m2(vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfmadd_vv_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmadd_vf_f32m2(vfloat32m2_t acc, float op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfmadd_vf_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfnmadd_vv_f32m2(vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfnmadd_vv_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfnmadd_vf_f32m2(vfloat32m2_t acc, float op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfnmadd_vf_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmsub_vv_f32m2(vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfmsub_vv_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmsub_vf_f32m2(vfloat32m2_t acc, float op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfmsub_vf_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfnmsub_vv_f32m2(vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfnmsub_vv_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfnmsub_vf_f32m2(vfloat32m2_t acc, float op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfnmsub_vf_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfmacc_vv_f32m4(vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfmacc_vv_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfmacc_vf_f32m4(vfloat32m4_t acc, float op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfmacc_vf_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfnmacc_vv_f32m4(vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfnmacc_vv_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfnmacc_vf_f32m4(vfloat32m4_t acc, float op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfnmacc_vf_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfmsac_vv_f32m4(vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfmsac_vv_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfmsac_vf_f32m4(vfloat32m4_t acc, float op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfmsac_vf_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfnmsac_vv_f32m4(vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfnmsac_vv_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfnmsac_vf_f32m4(vfloat32m4_t acc, float op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfnmsac_vf_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfmadd_vv_f32m4(vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfmadd_vv_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfmadd_vf_f32m4(vfloat32m4_t acc, float op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfmadd_vf_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfnmadd_vv_f32m4(vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfnmadd_vv_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfnmadd_vf_f32m4(vfloat32m4_t acc, float op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfnmadd_vf_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfmsub_vv_f32m4(vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfmsub_vv_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfmsub_vf_f32m4(vfloat32m4_t acc, float op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfmsub_vf_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfnmsub_vv_f32m4(vfloat32m4_t acc, vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfnmsub_vv_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfnmsub_vf_f32m4(vfloat32m4_t acc, float op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfnmsub_vf_f32m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmacc_vv_f64m1(vfloat64m1_t acc, vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfmacc_vv_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmacc_vf_f64m1(vfloat64m1_t acc, double op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfmacc_vf_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfnmacc_vv_f64m1(vfloat64m1_t acc, vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfnmacc_vv_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfnmacc_vf_f64m1(vfloat64m1_t acc, double op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfnmacc_vf_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmsac_vv_f64m1(vfloat64m1_t acc, vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfmsac_vv_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmsac_vf_f64m1(vfloat64m1_t acc, double op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfmsac_vf_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfnmsac_vv_f64m1(vfloat64m1_t acc, vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfnmsac_vv_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfnmsac_vf_f64m1(vfloat64m1_t acc, double op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfnmsac_vf_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmadd_vv_f64m1(vfloat64m1_t acc, vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfmadd_vv_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmadd_vf_f64m1(vfloat64m1_t acc, double op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfmadd_vf_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfnmadd_vv_f64m1(vfloat64m1_t acc, vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfnmadd_vv_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfnmadd_vf_f64m1(vfloat64m1_t acc, double op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfnmadd_vf_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmsub_vv_f64m1(vfloat64m1_t acc, vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfmsub_vv_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmsub_vf_f64m1(vfloat64m1_t acc, double op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfmsub_vf_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfnmsub_vv_f64m1(vfloat64m1_t acc, vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfnmsub_vv_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfnmsub_vf_f64m1(vfloat64m1_t acc, double op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfnmsub_vf_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfmacc_vv_f64m2(vfloat64m2_t acc, vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfmacc_vv_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfmacc_vf_f64m2(vfloat64m2_t acc, double op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfmacc_vf_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfnmacc_vv_f64m2(vfloat64m2_t acc, vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfnmacc_vv_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfnmacc_vf_f64m2(vfloat64m2_t acc, double op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfnmacc_vf_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfmsac_vv_f64m2(vfloat64m2_t acc, vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfmsac_vv_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfmsac_vf_f64m2(vfloat64m2_t acc, double op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfmsac_vf_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfnmsac_vv_f64m2(vfloat64m2_t acc, vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfnmsac_vv_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfnmsac_vf_f64m2(vfloat64m2_t acc, double op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfnmsac_vf_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfmadd_vv_f64m2(vfloat64m2_t acc, vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfmadd_vv_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfmadd_vf_f64m2(vfloat64m2_t acc, double op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfmadd_vf_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfnmadd_vv_f64m2(vfloat64m2_t acc, vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfnmadd_vv_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfnmadd_vf_f64m2(vfloat64m2_t acc, double op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfnmadd_vf_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfmsub_vv_f64m2(vfloat64m2_t acc, vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfmsub_vv_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfmsub_vf_f64m2(vfloat64m2_t acc, double op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfmsub_vf_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfnmsub_vv_f64m2(vfloat64m2_t acc, vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfnmsub_vv_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfnmsub_vf_f64m2(vfloat64m2_t acc, double op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfnmsub_vf_f64m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmacc_vv_f64m4(vfloat64m4_t acc, vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfmacc_vv_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmacc_vf_f64m4(vfloat64m4_t acc, double op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfmacc_vf_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfnmacc_vv_f64m4(vfloat64m4_t acc, vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfnmacc_vv_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfnmacc_vf_f64m4(vfloat64m4_t acc, double op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfnmacc_vf_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmsac_vv_f64m4(vfloat64m4_t acc, vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfmsac_vv_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmsac_vf_f64m4(vfloat64m4_t acc, double op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfmsac_vf_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfnmsac_vv_f64m4(vfloat64m4_t acc, vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfnmsac_vv_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfnmsac_vf_f64m4(vfloat64m4_t acc, double op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfnmsac_vf_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmadd_vv_f64m4(vfloat64m4_t acc, vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfmadd_vv_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmadd_vf_f64m4(vfloat64m4_t acc, double op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfmadd_vf_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfnmadd_vv_f64m4(vfloat64m4_t acc, vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfnmadd_vv_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfnmadd_vf_f64m4(vfloat64m4_t acc, double op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfnmadd_vf_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmsub_vv_f64m4(vfloat64m4_t acc, vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfmsub_vv_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmsub_vf_f64m4(vfloat64m4_t acc, double op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfmsub_vf_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfnmsub_vv_f64m4(vfloat64m4_t acc, vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfnmsub_vv_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfnmsub_vf_f64m4(vfloat64m4_t acc, double op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfnmsub_vf_f64m4(acc, op1, op2);
}


// Vector Floating-Point Square-Root Operations
static __attribute__((always_inline))
vfloat32m1_t vfsqrt_v_f32m1(vfloat32m1_t op1) {
  return __builtin_riscv_vfsqrt_v_f32m1(op1);
}

static __attribute__((always_inline))
vfloat32m2_t vfsqrt_v_f32m2(vfloat32m2_t op1) {
  return __builtin_riscv_vfsqrt_v_f32m2(op1);
}

static __attribute__((always_inline))
vfloat32m4_t vfsqrt_v_f32m4(vfloat32m4_t op1) {
  return __builtin_riscv_vfsqrt_v_f32m4(op1);
}

static __attribute__((always_inline))
vfloat64m1_t vfsqrt_v_f64m1(vfloat64m1_t op1) {
  return __builtin_riscv_vfsqrt_v_f64m1(op1);
}

static __attribute__((always_inline))
vfloat64m2_t vfsqrt_v_f64m2(vfloat64m2_t op1) {
  return __builtin_riscv_vfsqrt_v_f64m2(op1);
}

static __attribute__((always_inline))
vfloat64m4_t vfsqrt_v_f64m4(vfloat64m4_t op1) {
  return __builtin_riscv_vfsqrt_v_f64m4(op1);
}


// Vector Floating-Point MIN/MAX Operations
static __attribute__((always_inline))
vfloat32m1_t vfmin_vv_f32m1(vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfmin_vv_f32m1(op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfmin_vx_f32m1(vfloat32m1_t op1, float op2) {
  return __builtin_riscv_vfmin_vx_f32m1(op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfmax_vv_f32m1(vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vfmax_vv_f32m1(op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfmax_vx_f32m1(vfloat32m1_t op1, float op2) {
  return __builtin_riscv_vfmax_vx_f32m1(op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmin_vv_f32m2(vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfmin_vv_f32m2(op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmin_vx_f32m2(vfloat32m2_t op1, float op2) {
  return __builtin_riscv_vfmin_vx_f32m2(op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmax_vv_f32m2(vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfmax_vv_f32m2(op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmax_vx_f32m2(vfloat32m2_t op1, float op2) {
  return __builtin_riscv_vfmax_vx_f32m2(op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfmin_vv_f32m4(vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfmin_vv_f32m4(op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfmin_vx_f32m4(vfloat32m4_t op1, float op2) {
  return __builtin_riscv_vfmin_vx_f32m4(op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfmax_vv_f32m4(vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vfmax_vv_f32m4(op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfmax_vx_f32m4(vfloat32m4_t op1, float op2) {
  return __builtin_riscv_vfmax_vx_f32m4(op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmin_vv_f64m1(vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfmin_vv_f64m1(op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmin_vx_f64m1(vfloat64m1_t op1, double op2) {
  return __builtin_riscv_vfmin_vx_f64m1(op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmax_vv_f64m1(vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfmax_vv_f64m1(op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmax_vx_f64m1(vfloat64m1_t op1, double op2) {
  return __builtin_riscv_vfmax_vx_f64m1(op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfmin_vv_f64m2(vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfmin_vv_f64m2(op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfmin_vx_f64m2(vfloat64m2_t op1, double op2) {
  return __builtin_riscv_vfmin_vx_f64m2(op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfmax_vv_f64m2(vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vfmax_vv_f64m2(op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfmax_vx_f64m2(vfloat64m2_t op1, double op2) {
  return __builtin_riscv_vfmax_vx_f64m2(op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmin_vv_f64m4(vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfmin_vv_f64m4(op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmin_vx_f64m4(vfloat64m4_t op1, double op2) {
  return __builtin_riscv_vfmin_vx_f64m4(op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmax_vv_f64m4(vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfmax_vv_f64m4(op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmax_vx_f64m4(vfloat64m4_t op1, double op2) {
  return __builtin_riscv_vfmax_vx_f64m4(op1, op2);
}


// Vector Floating-Point Compare Operations
static __attribute__((always_inline))
vbool32_t vmfeq_vv_f32m1_b32(vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vmfeq_vv_f32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfeq_vx_f32m1_b32(vfloat32m1_t op1, float op2) {
  return __builtin_riscv_vmfeq_vx_f32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfne_vv_f32m1_b32(vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vmfne_vv_f32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfne_vx_f32m1_b32(vfloat32m1_t op1, float op2) {
  return __builtin_riscv_vmfne_vx_f32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmflt_vv_f32m1_b32(vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vmflt_vv_f32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmflt_vx_f32m1_b32(vfloat32m1_t op1, float op2) {
  return __builtin_riscv_vmflt_vx_f32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfle_vv_f32m1_b32(vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vmfle_vv_f32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfle_vx_f32m1_b32(vfloat32m1_t op1, float op2) {
  return __builtin_riscv_vmfle_vx_f32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfgt_vv_f32m1_b32(vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vmfgt_vv_f32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfgt_vx_f32m1_b32(vfloat32m1_t op1, float op2) {
  return __builtin_riscv_vmfgt_vx_f32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfge_vv_f32m1_b32(vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vmfge_vv_f32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfge_vx_f32m1_b32(vfloat32m1_t op1, float op2) {
  return __builtin_riscv_vmfge_vx_f32m1_b32(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfeq_vv_f32m2_b16(vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vmfeq_vv_f32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfeq_vx_f32m2_b16(vfloat32m2_t op1, float op2) {
  return __builtin_riscv_vmfeq_vx_f32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfne_vv_f32m2_b16(vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vmfne_vv_f32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfne_vx_f32m2_b16(vfloat32m2_t op1, float op2) {
  return __builtin_riscv_vmfne_vx_f32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmflt_vv_f32m2_b16(vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vmflt_vv_f32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmflt_vx_f32m2_b16(vfloat32m2_t op1, float op2) {
  return __builtin_riscv_vmflt_vx_f32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfle_vv_f32m2_b16(vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vmfle_vv_f32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfle_vx_f32m2_b16(vfloat32m2_t op1, float op2) {
  return __builtin_riscv_vmfle_vx_f32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfgt_vv_f32m2_b16(vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vmfgt_vv_f32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfgt_vx_f32m2_b16(vfloat32m2_t op1, float op2) {
  return __builtin_riscv_vmfgt_vx_f32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfge_vv_f32m2_b16(vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vmfge_vv_f32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfge_vx_f32m2_b16(vfloat32m2_t op1, float op2) {
  return __builtin_riscv_vmfge_vx_f32m2_b16(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmfeq_vv_f32m4_b8(vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vmfeq_vv_f32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmfeq_vx_f32m4_b8(vfloat32m4_t op1, float op2) {
  return __builtin_riscv_vmfeq_vx_f32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmfne_vv_f32m4_b8(vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vmfne_vv_f32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmfne_vx_f32m4_b8(vfloat32m4_t op1, float op2) {
  return __builtin_riscv_vmfne_vx_f32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmflt_vv_f32m4_b8(vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vmflt_vv_f32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmflt_vx_f32m4_b8(vfloat32m4_t op1, float op2) {
  return __builtin_riscv_vmflt_vx_f32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmfle_vv_f32m4_b8(vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vmfle_vv_f32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmfle_vx_f32m4_b8(vfloat32m4_t op1, float op2) {
  return __builtin_riscv_vmfle_vx_f32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmfgt_vv_f32m4_b8(vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vmfgt_vv_f32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmfgt_vx_f32m4_b8(vfloat32m4_t op1, float op2) {
  return __builtin_riscv_vmfgt_vx_f32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmfge_vv_f32m4_b8(vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vmfge_vv_f32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmfge_vx_f32m4_b8(vfloat32m4_t op1, float op2) {
  return __builtin_riscv_vmfge_vx_f32m4_b8(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmfeq_vv_f64m1_b64(vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vmfeq_vv_f64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmfeq_vx_f64m1_b64(vfloat64m1_t op1, double op2) {
  return __builtin_riscv_vmfeq_vx_f64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmfne_vv_f64m1_b64(vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vmfne_vv_f64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmfne_vx_f64m1_b64(vfloat64m1_t op1, double op2) {
  return __builtin_riscv_vmfne_vx_f64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmflt_vv_f64m1_b64(vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vmflt_vv_f64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmflt_vx_f64m1_b64(vfloat64m1_t op1, double op2) {
  return __builtin_riscv_vmflt_vx_f64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmfle_vv_f64m1_b64(vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vmfle_vv_f64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmfle_vx_f64m1_b64(vfloat64m1_t op1, double op2) {
  return __builtin_riscv_vmfle_vx_f64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmfgt_vv_f64m1_b64(vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vmfgt_vv_f64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmfgt_vx_f64m1_b64(vfloat64m1_t op1, double op2) {
  return __builtin_riscv_vmfgt_vx_f64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmfge_vv_f64m1_b64(vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vmfge_vv_f64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmfge_vx_f64m1_b64(vfloat64m1_t op1, double op2) {
  return __builtin_riscv_vmfge_vx_f64m1_b64(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfeq_vv_f64m2_b32(vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vmfeq_vv_f64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfeq_vx_f64m2_b32(vfloat64m2_t op1, double op2) {
  return __builtin_riscv_vmfeq_vx_f64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfne_vv_f64m2_b32(vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vmfne_vv_f64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfne_vx_f64m2_b32(vfloat64m2_t op1, double op2) {
  return __builtin_riscv_vmfne_vx_f64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmflt_vv_f64m2_b32(vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vmflt_vv_f64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmflt_vx_f64m2_b32(vfloat64m2_t op1, double op2) {
  return __builtin_riscv_vmflt_vx_f64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfle_vv_f64m2_b32(vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vmfle_vv_f64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfle_vx_f64m2_b32(vfloat64m2_t op1, double op2) {
  return __builtin_riscv_vmfle_vx_f64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfgt_vv_f64m2_b32(vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vmfgt_vv_f64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfgt_vx_f64m2_b32(vfloat64m2_t op1, double op2) {
  return __builtin_riscv_vmfgt_vx_f64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfge_vv_f64m2_b32(vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vmfge_vv_f64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmfge_vx_f64m2_b32(vfloat64m2_t op1, double op2) {
  return __builtin_riscv_vmfge_vx_f64m2_b32(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfeq_vv_f64m4_b16(vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vmfeq_vv_f64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfeq_vx_f64m4_b16(vfloat64m4_t op1, double op2) {
  return __builtin_riscv_vmfeq_vx_f64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfne_vv_f64m4_b16(vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vmfne_vv_f64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfne_vx_f64m4_b16(vfloat64m4_t op1, double op2) {
  return __builtin_riscv_vmfne_vx_f64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmflt_vv_f64m4_b16(vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vmflt_vv_f64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmflt_vx_f64m4_b16(vfloat64m4_t op1, double op2) {
  return __builtin_riscv_vmflt_vx_f64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfle_vv_f64m4_b16(vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vmfle_vv_f64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfle_vx_f64m4_b16(vfloat64m4_t op1, double op2) {
  return __builtin_riscv_vmfle_vx_f64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfgt_vv_f64m4_b16(vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vmfgt_vv_f64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfgt_vx_f64m4_b16(vfloat64m4_t op1, double op2) {
  return __builtin_riscv_vmfgt_vx_f64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfge_vv_f64m4_b16(vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vmfge_vv_f64m4_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmfge_vx_f64m4_b16(vfloat64m4_t op1, double op2) {
  return __builtin_riscv_vmfge_vx_f64m4_b16(op1, op2);
}


// Vector Floating-Point Merge Operations
static __attribute__((always_inline))
vfloat32m1_t vmerge_vvm_f32m1(vbool32_t mask, vfloat32m1_t op1, vfloat32m1_t op2) {
  return __builtin_riscv_vmerge_vvm_f32m1(mask, op1, op2);
}

static __attribute__((always_inline))
vfloat32m1_t vfmerge_vfm_f32m1(vbool32_t mask, vfloat32m1_t op1, float op2) {
  return __builtin_riscv_vfmerge_vfm_f32m1(mask, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vmerge_vvm_f32m2(vbool16_t mask, vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vmerge_vvm_f32m2(mask, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmerge_vfm_f32m2(vbool16_t mask, vfloat32m2_t op1, float op2) {
  return __builtin_riscv_vfmerge_vfm_f32m2(mask, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vmerge_vvm_f32m4(vbool8_t mask, vfloat32m4_t op1, vfloat32m4_t op2) {
  return __builtin_riscv_vmerge_vvm_f32m4(mask, op1, op2);
}

static __attribute__((always_inline))
vfloat32m4_t vfmerge_vfm_f32m4(vbool8_t mask, vfloat32m4_t op1, float op2) {
  return __builtin_riscv_vfmerge_vfm_f32m4(mask, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vmerge_vvm_f64m1(vbool64_t mask, vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vmerge_vvm_f64m1(mask, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmerge_vfm_f64m1(vbool64_t mask, vfloat64m1_t op1, double op2) {
  return __builtin_riscv_vfmerge_vfm_f64m1(mask, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vmerge_vvm_f64m2(vbool32_t mask, vfloat64m2_t op1, vfloat64m2_t op2) {
  return __builtin_riscv_vmerge_vvm_f64m2(mask, op1, op2);
}

static __attribute__((always_inline))
vfloat64m2_t vfmerge_vfm_f64m2(vbool32_t mask, vfloat64m2_t op1, double op2) {
  return __builtin_riscv_vfmerge_vfm_f64m2(mask, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vmerge_vvm_f64m4(vbool16_t mask, vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vmerge_vvm_f64m4(mask, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmerge_vfm_f64m4(vbool16_t mask, vfloat64m4_t op1, double op2) {
  return __builtin_riscv_vfmerge_vfm_f64m4(mask, op1, op2);
}


// Single-Width Floating-Point/Integer Type-Convert Operations
static __attribute__((always_inline))
vint32m1_t vfcvt_rtz_x_f_v_i32m1(vfloat32m1_t src) {
  return __builtin_riscv_vfcvt_rtz_x_f_v_i32m1(src);
}

static __attribute__((always_inline))
vint32m2_t vfcvt_rtz_x_f_v_i32m2(vfloat32m2_t src) {
  return __builtin_riscv_vfcvt_rtz_x_f_v_i32m2(src);
}

static __attribute__((always_inline))
vint32m4_t vfcvt_rtz_x_f_v_i32m4(vfloat32m4_t src) {
  return __builtin_riscv_vfcvt_rtz_x_f_v_i32m4(src);
}

static __attribute__((always_inline))
vint64m1_t vfcvt_rtz_x_f_v_i64m1(vfloat64m1_t src) {
  return __builtin_riscv_vfcvt_rtz_x_f_v_i64m1(src);
}

static __attribute__((always_inline))
vint64m2_t vfcvt_rtz_x_f_v_i64m2(vfloat64m2_t src) {
  return __builtin_riscv_vfcvt_rtz_x_f_v_i64m2(src);
}

static __attribute__((always_inline))
vint64m4_t vfcvt_rtz_x_f_v_i64m4(vfloat64m4_t src) {
  return __builtin_riscv_vfcvt_rtz_x_f_v_i64m4(src);
}


// Vector Single-Width Integer Reduction Operations
static __attribute__((always_inline))
vint8m1_t vredsum_vs_i8m1_i8m1(vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  return __builtin_riscv_vredsum_vs_i8m1_i8m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vint8m1_t vredmax_vs_i8m1_i8m1(vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  return __builtin_riscv_vredmax_vs_i8m1_i8m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vint8m1_t vredmin_vs_i8m1_i8m1(vint8m1_t dst, vint8m1_t vector, vint8m1_t scalar) {
  return __builtin_riscv_vredmin_vs_i8m1_i8m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vint8m2_t vredsum_vs_i8m2_i8m2(vint8m2_t dst, vint8m2_t vector, vint8m2_t scalar) {
  return __builtin_riscv_vredsum_vs_i8m2_i8m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vint8m2_t vredmax_vs_i8m2_i8m2(vint8m2_t dst, vint8m2_t vector, vint8m2_t scalar) {
  return __builtin_riscv_vredmax_vs_i8m2_i8m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vint8m2_t vredmin_vs_i8m2_i8m2(vint8m2_t dst, vint8m2_t vector, vint8m2_t scalar) {
  return __builtin_riscv_vredmin_vs_i8m2_i8m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vint8m4_t vredsum_vs_i8m4_i8m4(vint8m4_t dst, vint8m4_t vector, vint8m4_t scalar) {
  return __builtin_riscv_vredsum_vs_i8m4_i8m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vint8m4_t vredmax_vs_i8m4_i8m4(vint8m4_t dst, vint8m4_t vector, vint8m4_t scalar) {
  return __builtin_riscv_vredmax_vs_i8m4_i8m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vint8m4_t vredmin_vs_i8m4_i8m4(vint8m4_t dst, vint8m4_t vector, vint8m4_t scalar) {
  return __builtin_riscv_vredmin_vs_i8m4_i8m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vint16m1_t vredsum_vs_i16m1_i16m1(vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  return __builtin_riscv_vredsum_vs_i16m1_i16m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vint16m1_t vredmax_vs_i16m1_i16m1(vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  return __builtin_riscv_vredmax_vs_i16m1_i16m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vint16m1_t vredmin_vs_i16m1_i16m1(vint16m1_t dst, vint16m1_t vector, vint16m1_t scalar) {
  return __builtin_riscv_vredmin_vs_i16m1_i16m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vint16m2_t vredsum_vs_i16m2_i16m2(vint16m2_t dst, vint16m2_t vector, vint16m2_t scalar) {
  return __builtin_riscv_vredsum_vs_i16m2_i16m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vint16m2_t vredmax_vs_i16m2_i16m2(vint16m2_t dst, vint16m2_t vector, vint16m2_t scalar) {
  return __builtin_riscv_vredmax_vs_i16m2_i16m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vint16m2_t vredmin_vs_i16m2_i16m2(vint16m2_t dst, vint16m2_t vector, vint16m2_t scalar) {
  return __builtin_riscv_vredmin_vs_i16m2_i16m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vint16m4_t vredsum_vs_i16m4_i16m4(vint16m4_t dst, vint16m4_t vector, vint16m4_t scalar) {
  return __builtin_riscv_vredsum_vs_i16m4_i16m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vint16m4_t vredmax_vs_i16m4_i16m4(vint16m4_t dst, vint16m4_t vector, vint16m4_t scalar) {
  return __builtin_riscv_vredmax_vs_i16m4_i16m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vint16m4_t vredmin_vs_i16m4_i16m4(vint16m4_t dst, vint16m4_t vector, vint16m4_t scalar) {
  return __builtin_riscv_vredmin_vs_i16m4_i16m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vint32m1_t vredsum_vs_i32m1_i32m1(vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  return __builtin_riscv_vredsum_vs_i32m1_i32m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vint32m1_t vredmax_vs_i32m1_i32m1(vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  return __builtin_riscv_vredmax_vs_i32m1_i32m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vint32m1_t vredmin_vs_i32m1_i32m1(vint32m1_t dst, vint32m1_t vector, vint32m1_t scalar) {
  return __builtin_riscv_vredmin_vs_i32m1_i32m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vint32m2_t vredsum_vs_i32m2_i32m2(vint32m2_t dst, vint32m2_t vector, vint32m2_t scalar) {
  return __builtin_riscv_vredsum_vs_i32m2_i32m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vint32m2_t vredmax_vs_i32m2_i32m2(vint32m2_t dst, vint32m2_t vector, vint32m2_t scalar) {
  return __builtin_riscv_vredmax_vs_i32m2_i32m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vint32m2_t vredmin_vs_i32m2_i32m2(vint32m2_t dst, vint32m2_t vector, vint32m2_t scalar) {
  return __builtin_riscv_vredmin_vs_i32m2_i32m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vint32m4_t vredsum_vs_i32m4_i32m4(vint32m4_t dst, vint32m4_t vector, vint32m4_t scalar) {
  return __builtin_riscv_vredsum_vs_i32m4_i32m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vint32m4_t vredmax_vs_i32m4_i32m4(vint32m4_t dst, vint32m4_t vector, vint32m4_t scalar) {
  return __builtin_riscv_vredmax_vs_i32m4_i32m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vint32m4_t vredmin_vs_i32m4_i32m4(vint32m4_t dst, vint32m4_t vector, vint32m4_t scalar) {
  return __builtin_riscv_vredmin_vs_i32m4_i32m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vint64m1_t vredsum_vs_i64m1_i64m1(vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  return __builtin_riscv_vredsum_vs_i64m1_i64m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vint64m1_t vredmax_vs_i64m1_i64m1(vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  return __builtin_riscv_vredmax_vs_i64m1_i64m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vint64m1_t vredmin_vs_i64m1_i64m1(vint64m1_t dst, vint64m1_t vector, vint64m1_t scalar) {
  return __builtin_riscv_vredmin_vs_i64m1_i64m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vint64m2_t vredsum_vs_i64m2_i64m2(vint64m2_t dst, vint64m2_t vector, vint64m2_t scalar) {
  return __builtin_riscv_vredsum_vs_i64m2_i64m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vint64m2_t vredmax_vs_i64m2_i64m2(vint64m2_t dst, vint64m2_t vector, vint64m2_t scalar) {
  return __builtin_riscv_vredmax_vs_i64m2_i64m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vint64m2_t vredmin_vs_i64m2_i64m2(vint64m2_t dst, vint64m2_t vector, vint64m2_t scalar) {
  return __builtin_riscv_vredmin_vs_i64m2_i64m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vint64m4_t vredsum_vs_i64m4_i64m4(vint64m4_t dst, vint64m4_t vector, vint64m4_t scalar) {
  return __builtin_riscv_vredsum_vs_i64m4_i64m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vint64m4_t vredmax_vs_i64m4_i64m4(vint64m4_t dst, vint64m4_t vector, vint64m4_t scalar) {
  return __builtin_riscv_vredmax_vs_i64m4_i64m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vint64m4_t vredmin_vs_i64m4_i64m4(vint64m4_t dst, vint64m4_t vector, vint64m4_t scalar) {
  return __builtin_riscv_vredmin_vs_i64m4_i64m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint8m1_t vredsum_vs_u8m1_u8m1(vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  return __builtin_riscv_vredsum_vs_u8m1_u8m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint8m1_t vredmaxu_vs_u8m1_u8m1(vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  return __builtin_riscv_vredmaxu_vs_u8m1_u8m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint8m1_t vredminu_vs_u8m1_u8m1(vuint8m1_t dst, vuint8m1_t vector, vuint8m1_t scalar) {
  return __builtin_riscv_vredminu_vs_u8m1_u8m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint8m2_t vredsum_vs_u8m2_u8m2(vuint8m2_t dst, vuint8m2_t vector, vuint8m2_t scalar) {
  return __builtin_riscv_vredsum_vs_u8m2_u8m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint8m2_t vredmaxu_vs_u8m2_u8m2(vuint8m2_t dst, vuint8m2_t vector, vuint8m2_t scalar) {
  return __builtin_riscv_vredmaxu_vs_u8m2_u8m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint8m2_t vredminu_vs_u8m2_u8m2(vuint8m2_t dst, vuint8m2_t vector, vuint8m2_t scalar) {
  return __builtin_riscv_vredminu_vs_u8m2_u8m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint8m4_t vredsum_vs_u8m4_u8m4(vuint8m4_t dst, vuint8m4_t vector, vuint8m4_t scalar) {
  return __builtin_riscv_vredsum_vs_u8m4_u8m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint8m4_t vredmaxu_vs_u8m4_u8m4(vuint8m4_t dst, vuint8m4_t vector, vuint8m4_t scalar) {
  return __builtin_riscv_vredmaxu_vs_u8m4_u8m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint8m4_t vredminu_vs_u8m4_u8m4(vuint8m4_t dst, vuint8m4_t vector, vuint8m4_t scalar) {
  return __builtin_riscv_vredminu_vs_u8m4_u8m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint16m1_t vredsum_vs_u16m1_u16m1(vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  return __builtin_riscv_vredsum_vs_u16m1_u16m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint16m1_t vredmaxu_vs_u16m1_u16m1(vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  return __builtin_riscv_vredmaxu_vs_u16m1_u16m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint16m1_t vredminu_vs_u16m1_u16m1(vuint16m1_t dst, vuint16m1_t vector, vuint16m1_t scalar) {
  return __builtin_riscv_vredminu_vs_u16m1_u16m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint16m2_t vredsum_vs_u16m2_u16m2(vuint16m2_t dst, vuint16m2_t vector, vuint16m2_t scalar) {
  return __builtin_riscv_vredsum_vs_u16m2_u16m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint16m2_t vredmaxu_vs_u16m2_u16m2(vuint16m2_t dst, vuint16m2_t vector, vuint16m2_t scalar) {
  return __builtin_riscv_vredmaxu_vs_u16m2_u16m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint16m2_t vredminu_vs_u16m2_u16m2(vuint16m2_t dst, vuint16m2_t vector, vuint16m2_t scalar) {
  return __builtin_riscv_vredminu_vs_u16m2_u16m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint16m4_t vredsum_vs_u16m4_u16m4(vuint16m4_t dst, vuint16m4_t vector, vuint16m4_t scalar) {
  return __builtin_riscv_vredsum_vs_u16m4_u16m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint16m4_t vredmaxu_vs_u16m4_u16m4(vuint16m4_t dst, vuint16m4_t vector, vuint16m4_t scalar) {
  return __builtin_riscv_vredmaxu_vs_u16m4_u16m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint16m4_t vredminu_vs_u16m4_u16m4(vuint16m4_t dst, vuint16m4_t vector, vuint16m4_t scalar) {
  return __builtin_riscv_vredminu_vs_u16m4_u16m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint32m1_t vredsum_vs_u32m1_u32m1(vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  return __builtin_riscv_vredsum_vs_u32m1_u32m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint32m1_t vredmaxu_vs_u32m1_u32m1(vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  return __builtin_riscv_vredmaxu_vs_u32m1_u32m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint32m1_t vredminu_vs_u32m1_u32m1(vuint32m1_t dst, vuint32m1_t vector, vuint32m1_t scalar) {
  return __builtin_riscv_vredminu_vs_u32m1_u32m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint32m2_t vredsum_vs_u32m2_u32m2(vuint32m2_t dst, vuint32m2_t vector, vuint32m2_t scalar) {
  return __builtin_riscv_vredsum_vs_u32m2_u32m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint32m2_t vredmaxu_vs_u32m2_u32m2(vuint32m2_t dst, vuint32m2_t vector, vuint32m2_t scalar) {
  return __builtin_riscv_vredmaxu_vs_u32m2_u32m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint32m2_t vredminu_vs_u32m2_u32m2(vuint32m2_t dst, vuint32m2_t vector, vuint32m2_t scalar) {
  return __builtin_riscv_vredminu_vs_u32m2_u32m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint32m4_t vredsum_vs_u32m4_u32m4(vuint32m4_t dst, vuint32m4_t vector, vuint32m4_t scalar) {
  return __builtin_riscv_vredsum_vs_u32m4_u32m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint32m4_t vredmaxu_vs_u32m4_u32m4(vuint32m4_t dst, vuint32m4_t vector, vuint32m4_t scalar) {
  return __builtin_riscv_vredmaxu_vs_u32m4_u32m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint32m4_t vredminu_vs_u32m4_u32m4(vuint32m4_t dst, vuint32m4_t vector, vuint32m4_t scalar) {
  return __builtin_riscv_vredminu_vs_u32m4_u32m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint64m1_t vredsum_vs_u64m1_u64m1(vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  return __builtin_riscv_vredsum_vs_u64m1_u64m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint64m1_t vredmaxu_vs_u64m1_u64m1(vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  return __builtin_riscv_vredmaxu_vs_u64m1_u64m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint64m1_t vredminu_vs_u64m1_u64m1(vuint64m1_t dst, vuint64m1_t vector, vuint64m1_t scalar) {
  return __builtin_riscv_vredminu_vs_u64m1_u64m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint64m2_t vredsum_vs_u64m2_u64m2(vuint64m2_t dst, vuint64m2_t vector, vuint64m2_t scalar) {
  return __builtin_riscv_vredsum_vs_u64m2_u64m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint64m2_t vredmaxu_vs_u64m2_u64m2(vuint64m2_t dst, vuint64m2_t vector, vuint64m2_t scalar) {
  return __builtin_riscv_vredmaxu_vs_u64m2_u64m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint64m2_t vredminu_vs_u64m2_u64m2(vuint64m2_t dst, vuint64m2_t vector, vuint64m2_t scalar) {
  return __builtin_riscv_vredminu_vs_u64m2_u64m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint64m4_t vredsum_vs_u64m4_u64m4(vuint64m4_t dst, vuint64m4_t vector, vuint64m4_t scalar) {
  return __builtin_riscv_vredsum_vs_u64m4_u64m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint64m4_t vredmaxu_vs_u64m4_u64m4(vuint64m4_t dst, vuint64m4_t vector, vuint64m4_t scalar) {
  return __builtin_riscv_vredmaxu_vs_u64m4_u64m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vuint64m4_t vredminu_vs_u64m4_u64m4(vuint64m4_t dst, vuint64m4_t vector, vuint64m4_t scalar) {
  return __builtin_riscv_vredminu_vs_u64m4_u64m4(dst, vector, scalar);
}


// Vector Single-Width Floating-Point Reduction Operations
static __attribute__((always_inline))
vfloat32m1_t vfredsum_vs_f32m1_f32m1(vfloat32m1_t dst, vfloat32m1_t vector, vfloat32m1_t scalar) {
  return __builtin_riscv_vfredsum_vs_f32m1_f32m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat32m1_t vfredmax_vs_f32m1_f32m1(vfloat32m1_t dst, vfloat32m1_t vector, vfloat32m1_t scalar) {
  return __builtin_riscv_vfredmax_vs_f32m1_f32m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat32m1_t vfredmin_vs_f32m1_f32m1(vfloat32m1_t dst, vfloat32m1_t vector, vfloat32m1_t scalar) {
  return __builtin_riscv_vfredmin_vs_f32m1_f32m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat32m2_t vfredsum_vs_f32m2_f32m2(vfloat32m2_t dst, vfloat32m2_t vector, vfloat32m2_t scalar) {
  return __builtin_riscv_vfredsum_vs_f32m2_f32m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat32m2_t vfredmax_vs_f32m2_f32m2(vfloat32m2_t dst, vfloat32m2_t vector, vfloat32m2_t scalar) {
  return __builtin_riscv_vfredmax_vs_f32m2_f32m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat32m2_t vfredmin_vs_f32m2_f32m2(vfloat32m2_t dst, vfloat32m2_t vector, vfloat32m2_t scalar) {
  return __builtin_riscv_vfredmin_vs_f32m2_f32m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat32m4_t vfredsum_vs_f32m4_f32m4(vfloat32m4_t dst, vfloat32m4_t vector, vfloat32m4_t scalar) {
  return __builtin_riscv_vfredsum_vs_f32m4_f32m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat32m4_t vfredmax_vs_f32m4_f32m4(vfloat32m4_t dst, vfloat32m4_t vector, vfloat32m4_t scalar) {
  return __builtin_riscv_vfredmax_vs_f32m4_f32m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat32m4_t vfredmin_vs_f32m4_f32m4(vfloat32m4_t dst, vfloat32m4_t vector, vfloat32m4_t scalar) {
  return __builtin_riscv_vfredmin_vs_f32m4_f32m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat64m1_t vfredsum_vs_f64m1_f64m1(vfloat64m1_t dst, vfloat64m1_t vector, vfloat64m1_t scalar) {
  return __builtin_riscv_vfredsum_vs_f64m1_f64m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat64m1_t vfredmax_vs_f64m1_f64m1(vfloat64m1_t dst, vfloat64m1_t vector, vfloat64m1_t scalar) {
  return __builtin_riscv_vfredmax_vs_f64m1_f64m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat64m1_t vfredmin_vs_f64m1_f64m1(vfloat64m1_t dst, vfloat64m1_t vector, vfloat64m1_t scalar) {
  return __builtin_riscv_vfredmin_vs_f64m1_f64m1(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat64m2_t vfredsum_vs_f64m2_f64m2(vfloat64m2_t dst, vfloat64m2_t vector, vfloat64m2_t scalar) {
  return __builtin_riscv_vfredsum_vs_f64m2_f64m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat64m2_t vfredmax_vs_f64m2_f64m2(vfloat64m2_t dst, vfloat64m2_t vector, vfloat64m2_t scalar) {
  return __builtin_riscv_vfredmax_vs_f64m2_f64m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat64m2_t vfredmin_vs_f64m2_f64m2(vfloat64m2_t dst, vfloat64m2_t vector, vfloat64m2_t scalar) {
  return __builtin_riscv_vfredmin_vs_f64m2_f64m2(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat64m4_t vfredsum_vs_f64m4_f64m4(vfloat64m4_t dst, vfloat64m4_t vector, vfloat64m4_t scalar) {
  return __builtin_riscv_vfredsum_vs_f64m4_f64m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat64m4_t vfredmax_vs_f64m4_f64m4(vfloat64m4_t dst, vfloat64m4_t vector, vfloat64m4_t scalar) {
  return __builtin_riscv_vfredmax_vs_f64m4_f64m4(dst, vector, scalar);
}

static __attribute__((always_inline))
vfloat64m4_t vfredmin_vs_f64m4_f64m4(vfloat64m4_t dst, vfloat64m4_t vector, vfloat64m4_t scalar) {
  return __builtin_riscv_vfredmin_vs_f64m4_f64m4(dst, vector, scalar);
}


// Vector Mask-Register Logical Operations
static __attribute__((always_inline))
vbool2_t vmand_mm_b2(vbool2_t op1, vbool2_t op2) {
  return __builtin_riscv_vmand_mm_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmnand_mm_b2(vbool2_t op1, vbool2_t op2) {
  return __builtin_riscv_vmnand_mm_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmandnot_mm_b2(vbool2_t op1, vbool2_t op2) {
  return __builtin_riscv_vmandnot_mm_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmxor_mm_b2(vbool2_t op1, vbool2_t op2) {
  return __builtin_riscv_vmxor_mm_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmor_mm_b2(vbool2_t op1, vbool2_t op2) {
  return __builtin_riscv_vmor_mm_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmnor_mm_b2(vbool2_t op1, vbool2_t op2) {
  return __builtin_riscv_vmnor_mm_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmornot_mm_b2(vbool2_t op1, vbool2_t op2) {
  return __builtin_riscv_vmornot_mm_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmxnor_mm_b2(vbool2_t op1, vbool2_t op2) {
  return __builtin_riscv_vmxnor_mm_b2(op1, op2);
}

static __attribute__((always_inline))
vbool2_t vmmv_m_b2(vbool2_t op1) {
  return __builtin_riscv_vmmv_m_b2(op1);
}

static __attribute__((always_inline))
vbool2_t vmclr_m_b2() {
  return __builtin_riscv_vmclr_m_b2();
}

static __attribute__((always_inline))
vbool2_t vmset_m_b2() {
  return __builtin_riscv_vmset_m_b2();
}

static __attribute__((always_inline))
vbool2_t vmnot_m_b2(vbool2_t op1) {
  return __builtin_riscv_vmnot_m_b2(op1);
}

static __attribute__((always_inline))
vbool4_t vmand_mm_b4(vbool4_t op1, vbool4_t op2) {
  return __builtin_riscv_vmand_mm_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmnand_mm_b4(vbool4_t op1, vbool4_t op2) {
  return __builtin_riscv_vmnand_mm_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmandnot_mm_b4(vbool4_t op1, vbool4_t op2) {
  return __builtin_riscv_vmandnot_mm_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmxor_mm_b4(vbool4_t op1, vbool4_t op2) {
  return __builtin_riscv_vmxor_mm_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmor_mm_b4(vbool4_t op1, vbool4_t op2) {
  return __builtin_riscv_vmor_mm_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmnor_mm_b4(vbool4_t op1, vbool4_t op2) {
  return __builtin_riscv_vmnor_mm_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmornot_mm_b4(vbool4_t op1, vbool4_t op2) {
  return __builtin_riscv_vmornot_mm_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmxnor_mm_b4(vbool4_t op1, vbool4_t op2) {
  return __builtin_riscv_vmxnor_mm_b4(op1, op2);
}

static __attribute__((always_inline))
vbool4_t vmmv_m_b4(vbool4_t op1) {
  return __builtin_riscv_vmmv_m_b4(op1);
}

static __attribute__((always_inline))
vbool4_t vmclr_m_b4() {
  return __builtin_riscv_vmclr_m_b4();
}

static __attribute__((always_inline))
vbool4_t vmset_m_b4() {
  return __builtin_riscv_vmset_m_b4();
}

static __attribute__((always_inline))
vbool4_t vmnot_m_b4(vbool4_t op1) {
  return __builtin_riscv_vmnot_m_b4(op1);
}

static __attribute__((always_inline))
vbool8_t vmand_mm_b8(vbool8_t op1, vbool8_t op2) {
  return __builtin_riscv_vmand_mm_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmnand_mm_b8(vbool8_t op1, vbool8_t op2) {
  return __builtin_riscv_vmnand_mm_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmandnot_mm_b8(vbool8_t op1, vbool8_t op2) {
  return __builtin_riscv_vmandnot_mm_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmxor_mm_b8(vbool8_t op1, vbool8_t op2) {
  return __builtin_riscv_vmxor_mm_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmor_mm_b8(vbool8_t op1, vbool8_t op2) {
  return __builtin_riscv_vmor_mm_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmnor_mm_b8(vbool8_t op1, vbool8_t op2) {
  return __builtin_riscv_vmnor_mm_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmornot_mm_b8(vbool8_t op1, vbool8_t op2) {
  return __builtin_riscv_vmornot_mm_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmxnor_mm_b8(vbool8_t op1, vbool8_t op2) {
  return __builtin_riscv_vmxnor_mm_b8(op1, op2);
}

static __attribute__((always_inline))
vbool8_t vmmv_m_b8(vbool8_t op1) {
  return __builtin_riscv_vmmv_m_b8(op1);
}

static __attribute__((always_inline))
vbool8_t vmclr_m_b8() {
  return __builtin_riscv_vmclr_m_b8();
}

static __attribute__((always_inline))
vbool8_t vmset_m_b8() {
  return __builtin_riscv_vmset_m_b8();
}

static __attribute__((always_inline))
vbool8_t vmnot_m_b8(vbool8_t op1) {
  return __builtin_riscv_vmnot_m_b8(op1);
}

static __attribute__((always_inline))
vbool16_t vmand_mm_b16(vbool16_t op1, vbool16_t op2) {
  return __builtin_riscv_vmand_mm_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmnand_mm_b16(vbool16_t op1, vbool16_t op2) {
  return __builtin_riscv_vmnand_mm_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmandnot_mm_b16(vbool16_t op1, vbool16_t op2) {
  return __builtin_riscv_vmandnot_mm_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmxor_mm_b16(vbool16_t op1, vbool16_t op2) {
  return __builtin_riscv_vmxor_mm_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmor_mm_b16(vbool16_t op1, vbool16_t op2) {
  return __builtin_riscv_vmor_mm_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmnor_mm_b16(vbool16_t op1, vbool16_t op2) {
  return __builtin_riscv_vmnor_mm_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmornot_mm_b16(vbool16_t op1, vbool16_t op2) {
  return __builtin_riscv_vmornot_mm_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmxnor_mm_b16(vbool16_t op1, vbool16_t op2) {
  return __builtin_riscv_vmxnor_mm_b16(op1, op2);
}

static __attribute__((always_inline))
vbool16_t vmmv_m_b16(vbool16_t op1) {
  return __builtin_riscv_vmmv_m_b16(op1);
}

static __attribute__((always_inline))
vbool16_t vmclr_m_b16() {
  return __builtin_riscv_vmclr_m_b16();
}

static __attribute__((always_inline))
vbool16_t vmset_m_b16() {
  return __builtin_riscv_vmset_m_b16();
}

static __attribute__((always_inline))
vbool16_t vmnot_m_b16(vbool16_t op1) {
  return __builtin_riscv_vmnot_m_b16(op1);
}

static __attribute__((always_inline))
vbool32_t vmand_mm_b32(vbool32_t op1, vbool32_t op2) {
  return __builtin_riscv_vmand_mm_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmnand_mm_b32(vbool32_t op1, vbool32_t op2) {
  return __builtin_riscv_vmnand_mm_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmandnot_mm_b32(vbool32_t op1, vbool32_t op2) {
  return __builtin_riscv_vmandnot_mm_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmxor_mm_b32(vbool32_t op1, vbool32_t op2) {
  return __builtin_riscv_vmxor_mm_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmor_mm_b32(vbool32_t op1, vbool32_t op2) {
  return __builtin_riscv_vmor_mm_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmnor_mm_b32(vbool32_t op1, vbool32_t op2) {
  return __builtin_riscv_vmnor_mm_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmornot_mm_b32(vbool32_t op1, vbool32_t op2) {
  return __builtin_riscv_vmornot_mm_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmxnor_mm_b32(vbool32_t op1, vbool32_t op2) {
  return __builtin_riscv_vmxnor_mm_b32(op1, op2);
}

static __attribute__((always_inline))
vbool32_t vmmv_m_b32(vbool32_t op1) {
  return __builtin_riscv_vmmv_m_b32(op1);
}

static __attribute__((always_inline))
vbool32_t vmclr_m_b32() {
  return __builtin_riscv_vmclr_m_b32();
}

static __attribute__((always_inline))
vbool32_t vmset_m_b32() {
  return __builtin_riscv_vmset_m_b32();
}

static __attribute__((always_inline))
vbool32_t vmnot_m_b32(vbool32_t op1) {
  return __builtin_riscv_vmnot_m_b32(op1);
}

static __attribute__((always_inline))
vbool64_t vmand_mm_b64(vbool64_t op1, vbool64_t op2) {
  return __builtin_riscv_vmand_mm_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmnand_mm_b64(vbool64_t op1, vbool64_t op2) {
  return __builtin_riscv_vmnand_mm_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmandnot_mm_b64(vbool64_t op1, vbool64_t op2) {
  return __builtin_riscv_vmandnot_mm_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmxor_mm_b64(vbool64_t op1, vbool64_t op2) {
  return __builtin_riscv_vmxor_mm_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmor_mm_b64(vbool64_t op1, vbool64_t op2) {
  return __builtin_riscv_vmor_mm_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmnor_mm_b64(vbool64_t op1, vbool64_t op2) {
  return __builtin_riscv_vmnor_mm_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmornot_mm_b64(vbool64_t op1, vbool64_t op2) {
  return __builtin_riscv_vmornot_mm_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmxnor_mm_b64(vbool64_t op1, vbool64_t op2) {
  return __builtin_riscv_vmxnor_mm_b64(op1, op2);
}

static __attribute__((always_inline))
vbool64_t vmmv_m_b64(vbool64_t op1) {
  return __builtin_riscv_vmmv_m_b64(op1);
}

static __attribute__((always_inline))
vbool64_t vmclr_m_b64() {
  return __builtin_riscv_vmclr_m_b64();
}

static __attribute__((always_inline))
vbool64_t vmset_m_b64() {
  return __builtin_riscv_vmset_m_b64();
}

static __attribute__((always_inline))
vbool64_t vmnot_m_b64(vbool64_t op1) {
  return __builtin_riscv_vmnot_m_b64(op1);
}


#endif
