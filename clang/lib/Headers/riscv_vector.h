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
vfloat32m1_t vmv_v_x_f32m1(float src) {
  return __builtin_riscv_vmv_v_x_f32m1(src);
}

static __attribute__((always_inline))
vfloat32m2_t vmv_v_v_f32m2(vfloat32m2_t src) {
  return __builtin_riscv_vmv_v_v_f32m2(src);
}

static __attribute__((always_inline))
vfloat32m2_t vmv_v_x_f32m2(float src) {
  return __builtin_riscv_vmv_v_x_f32m2(src);
}

static __attribute__((always_inline))
vfloat32m4_t vmv_v_v_f32m4(vfloat32m4_t src) {
  return __builtin_riscv_vmv_v_v_f32m4(src);
}

static __attribute__((always_inline))
vfloat32m4_t vmv_v_x_f32m4(float src) {
  return __builtin_riscv_vmv_v_x_f32m4(src);
}

static __attribute__((always_inline))
vfloat32m8_t vmv_v_v_f32m8(vfloat32m8_t src) {
  return __builtin_riscv_vmv_v_v_f32m8(src);
}

static __attribute__((always_inline))
vfloat32m8_t vmv_v_x_f32m8(float src) {
  return __builtin_riscv_vmv_v_x_f32m8(src);
}

static __attribute__((always_inline))
vfloat64m1_t vmv_v_v_f64m1(vfloat64m1_t src) {
  return __builtin_riscv_vmv_v_v_f64m1(src);
}

static __attribute__((always_inline))
vfloat64m1_t vmv_v_x_f64m1(double src) {
  return __builtin_riscv_vmv_v_x_f64m1(src);
}

static __attribute__((always_inline))
vfloat64m2_t vmv_v_v_f64m2(vfloat64m2_t src) {
  return __builtin_riscv_vmv_v_v_f64m2(src);
}

static __attribute__((always_inline))
vfloat64m2_t vmv_v_x_f64m2(double src) {
  return __builtin_riscv_vmv_v_x_f64m2(src);
}

static __attribute__((always_inline))
vfloat64m4_t vmv_v_v_f64m4(vfloat64m4_t src) {
  return __builtin_riscv_vmv_v_v_f64m4(src);
}

static __attribute__((always_inline))
vfloat64m4_t vmv_v_x_f64m4(double src) {
  return __builtin_riscv_vmv_v_x_f64m4(src);
}

static __attribute__((always_inline))
vfloat64m8_t vmv_v_v_f64m8(vfloat64m8_t src) {
  return __builtin_riscv_vmv_v_v_f64m8(src);
}

static __attribute__((always_inline))
vfloat64m8_t vmv_v_x_f64m8(double src) {
  return __builtin_riscv_vmv_v_x_f64m8(src);
}

static __attribute__((always_inline))
vint8m1_t vreinterpret_i8_u8_i8m1(vuint8m1_t src) {
  return __builtin_riscv_vreinterpret_i8_u8_i8m1(src);
}

static __attribute__((always_inline))
vuint8m1_t vreinterpret_u8_i8_u8m1(vint8m1_t src) {
  return __builtin_riscv_vreinterpret_u8_i8_u8m1(src);
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
vint16m1_t vreinterpret_i16_u16_i16m1(vuint16m1_t src) {
  return __builtin_riscv_vreinterpret_i16_u16_i16m1(src);
}

static __attribute__((always_inline))
vuint16m1_t vreinterpret_u16_i16_u16m1(vint16m1_t src) {
  return __builtin_riscv_vreinterpret_u16_i16_u16m1(src);
}

static __attribute__((always_inline))
vint16m2_t vreinterpret_i16_u16_i16m2(vuint16m2_t src) {
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
vuint32m1_t vreinterpret_u32_f32_u32m1(vfloat32m1_t src) {
  return __builtin_riscv_vreinterpret_u32_f32_u32m1(src);
}

static __attribute__((always_inline))
vfloat32m1_t vreinterpret_f32_u32_f32m1(vuint32m1_t src) {
  return __builtin_riscv_vreinterpret_f32_u32_f32m1(src);
}

static __attribute__((always_inline))
vint32m1_t vreinterpret_i32_f32_i32m1(vfloat32m1_t src) {
  return __builtin_riscv_vreinterpret_i32_f32_i32m1(src);
}

static __attribute__((always_inline))
vfloat32m1_t vreinterpret_f32_i32_f32m1(vint32m1_t src) {
  return __builtin_riscv_vreinterpret_f32_i32_f32m1(src);
}

static __attribute__((always_inline))
vint32m1_t vreinterpret_i32_u32_i32m1(vuint32m1_t src) {
  return __builtin_riscv_vreinterpret_i32_u32_i32m1(src);
}

static __attribute__((always_inline))
vuint32m1_t vreinterpret_u32_i32_u32m1(vint32m1_t src) {
  return __builtin_riscv_vreinterpret_u32_i32_u32m1(src);
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
  return __builtin_riscv_vreinterpret_u64_f64_u64m1(src);
}

static __attribute__((always_inline))
vfloat64m1_t vreinterpret_f64_u64_f64m1(vuint64m1_t src) {
  return __builtin_riscv_vreinterpret_f64_u64_f64m1(src);
}

static __attribute__((always_inline))
vint64m1_t vreinterpret_i64_f64_i64m1(vfloat64m1_t src) {
  return __builtin_riscv_vreinterpret_i64_f64_i64m1(src);
}

static __attribute__((always_inline))
vfloat64m1_t vreinterpret_f64_i64_f64m1(vint64m1_t src) {
  return __builtin_riscv_vreinterpret_f64_i64_f64m1(src);
}

static __attribute__((always_inline))
vint64m1_t vreinterpret_i64_u64_i64m1(vuint64m1_t src) {
  return __builtin_riscv_vreinterpret_i64_u64_i64m1(src);
}

static __attribute__((always_inline))
vuint64m1_t vreinterpret_u64_i64_u64m1(vint64m1_t src) {
  return __builtin_riscv_vreinterpret_u64_i64_u64m1(src);
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
vint32m1_t vreinterpret_i32_i64_i32m1(vint64m1_t src) {
  return __builtin_riscv_vreinterpret_i32_i64_i32m1(src);
}

static __attribute__((always_inline))
vint64m1_t vreinterpret_i64_i32_i64m1(vint32m1_t src) {
  return __builtin_riscv_vreinterpret_i64_i32_i64m1(src);
}

static __attribute__((always_inline))
vint16m1_t vreinterpret_i16_i64_i16m1(vint64m1_t src) {
  return __builtin_riscv_vreinterpret_i16_i64_i16m1(src);
}

static __attribute__((always_inline))
vint64m1_t vreinterpret_i64_i16_i64m1(vint16m1_t src) {
  return __builtin_riscv_vreinterpret_i64_i16_i64m1(src);
}

static __attribute__((always_inline))
vint8m1_t vreinterpret_i8_i64_i8m1(vint64m1_t src) {
  return __builtin_riscv_vreinterpret_i8_i64_i8m1(src);
}

static __attribute__((always_inline))
vint64m1_t vreinterpret_i64_i8_i64m1(vint8m1_t src) {
  return __builtin_riscv_vreinterpret_i64_i8_i64m1(src);
}

static __attribute__((always_inline))
vint16m1_t vreinterpret_i16_i32_i16m1(vint32m1_t src) {
  return __builtin_riscv_vreinterpret_i16_i32_i16m1(src);
}

static __attribute__((always_inline))
vint32m1_t vreinterpret_i32_i16_i32m1(vint16m1_t src) {
  return __builtin_riscv_vreinterpret_i32_i16_i32m1(src);
}

static __attribute__((always_inline))
vint8m1_t vreinterpret_i8_i32_i8m1(vint32m1_t src) {
  return __builtin_riscv_vreinterpret_i8_i32_i8m1(src);
}

static __attribute__((always_inline))
vint32m1_t vreinterpret_i32_i8_i32m1(vint8m1_t src) {
  return __builtin_riscv_vreinterpret_i32_i8_i32m1(src);
}

static __attribute__((always_inline))
vint8m1_t vreinterpret_i8_i16_i8m1(vint16m1_t src) {
  return __builtin_riscv_vreinterpret_i8_i16_i8m1(src);
}

static __attribute__((always_inline))
vint16m1_t vreinterpret_i16_i8_i16m1(vint8m1_t src) {
  return __builtin_riscv_vreinterpret_i16_i8_i16m1(src);
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
vuint32m1_t vreinterpret_u32_u64_u32m1(vuint64m1_t src) {
  return __builtin_riscv_vreinterpret_u32_u64_u32m1(src);
}

static __attribute__((always_inline))
vuint64m1_t vreinterpret_u64_u32_u64m1(vuint32m1_t src) {
  return __builtin_riscv_vreinterpret_u64_u32_u64m1(src);
}

static __attribute__((always_inline))
vuint16m1_t vreinterpret_u16_u64_u16m1(vuint64m1_t src) {
  return __builtin_riscv_vreinterpret_u16_u64_u16m1(src);
}

static __attribute__((always_inline))
vuint64m1_t vreinterpret_u64_u16_u64m1(vuint16m1_t src) {
  return __builtin_riscv_vreinterpret_u64_u16_u64m1(src);
}

static __attribute__((always_inline))
vuint8m1_t vreinterpret_u8_u64_u8m1(vuint64m1_t src) {
  return __builtin_riscv_vreinterpret_u8_u64_u8m1(src);
}

static __attribute__((always_inline))
vuint64m1_t vreinterpret_u64_u8_u64m1(vuint8m1_t src) {
  return __builtin_riscv_vreinterpret_u64_u8_u64m1(src);
}

static __attribute__((always_inline))
vuint16m1_t vreinterpret_u16_u32_u16m1(vuint32m1_t src) {
  return __builtin_riscv_vreinterpret_u16_u32_u16m1(src);
}

static __attribute__((always_inline))
vuint32m1_t vreinterpret_u32_u16_u32m1(vuint16m1_t src) {
  return __builtin_riscv_vreinterpret_u32_u16_u32m1(src);
}

static __attribute__((always_inline))
vuint8m1_t vreinterpret_u8_u32_u8m1(vuint32m1_t src) {
  return __builtin_riscv_vreinterpret_u8_u32_u8m1(src);
}

static __attribute__((always_inline))
vuint32m1_t vreinterpret_u32_u8_u32m1(vuint8m1_t src) {
  return __builtin_riscv_vreinterpret_u32_u8_u32m1(src);
}

static __attribute__((always_inline))
vuint8m1_t vreinterpret_u8_u16_u8m1(vuint16m1_t src) {
  return __builtin_riscv_vreinterpret_u8_u16_u8m1(src);
}

static __attribute__((always_inline))
vuint16m1_t vreinterpret_u16_u8_u16m1(vuint8m1_t src) {
  return __builtin_riscv_vreinterpret_u16_u8_u16m1(src);
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

static __attribute__((always_inline))
vbool1_t vmset_m_b1() {
  return __builtin_riscv_vmset_m_b1();
}

static __attribute__((always_inline))
vbool2_t vmset_m_b2() {
  return __builtin_riscv_vmset_m_b2();
}

static __attribute__((always_inline))
vbool4_t vmset_m_b4() {
  return __builtin_riscv_vmset_m_b4();
}

static __attribute__((always_inline))
vbool8_t vmset_m_b8() {
  return __builtin_riscv_vmset_m_b8();
}

static __attribute__((always_inline))
vbool16_t vmset_m_b16() {
  return __builtin_riscv_vmset_m_b16();
}

static __attribute__((always_inline))
vbool32_t vmset_m_b32() {
  return __builtin_riscv_vmset_m_b32();
}

static __attribute__((always_inline))
vbool64_t vmset_m_b64() {
  return __builtin_riscv_vmset_m_b64();
}

#endif