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

typedef __attribute__((riscv_vector_type(64, 8, 1))) int vint64m8x1_t;

typedef __attribute__((riscv_vector_type(64, 1, 4))) int vint64m1x8_t;

typedef __attribute__((riscv_vector_type(64, 2, 4))) int vint64m2x4_t;

typedef __attribute__((riscv_vector_type(64, 4, 4))) int vint64m4x4_t;

typedef __attribute__((riscv_vector_type(64, 8, 4))) int vint64m8x4_t;

typedef __attribute__((riscv_vector_type(64, 1, 8))) int vint64m1x8_t;

typedef __attribute__((riscv_vector_type(64, 2, 8))) int vint64m2x8_t;

typedef __attribute__((riscv_vector_type(64, 4, 8))) int vint64m4x8_t;

typedef __attribute__((riscv_vector_type(64, 8, 8))) int vint64m8x8_t;

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

typedef __attribute__((riscv_vector_type(16, 1, 0))) float vfloat16m1_t;

typedef __attribute__((riscv_vector_type(16, 2, 0))) float vfloat16m2_t;

typedef __attribute__((riscv_vector_type(16, 4, 0))) float vfloat16m4_t;

typedef __attribute__((riscv_vector_type(16, 8, 0))) float vfloat16m8_t;

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
size_t vsetvl_e32m1(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E32 | _M1);
}

static __attribute__((always_inline))
vint8m1_t vadd_vv_i8m1(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vadd_vv_i8m1(value1, value2);
}

static __attribute__((always_inline))
vint16m1_t vadd_vv_i16m1(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vadd_vv_i16m1(value1, value2);
}

static __attribute__((always_inline))
vint32m1_t vadd_vv_i32m1(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vadd_vv_i32m1(value1, value2);
}

static __attribute__((always_inline))
vint64m1_t vadd_vv_i64m1(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vadd_vv_i64m1(value1, value2);
}

static __attribute__((always_inline))
vfloat16m1_t vfadd_vv_f16m1(vfloat16m1_t value1, vfloat16m1_t value2) {
    return __builtin_riscv_vfadd_vv_f16m1(value1, value2);
}

static __attribute__((always_inline))
vfloat32m1_t vfadd_vv_f32m1(vfloat32m1_t value1, vfloat32m1_t value2) {
    return __builtin_riscv_vfadd_vv_f32m1(value1, value2);
}

static __attribute__((always_inline))
vfloat64m1_t vfadd_vv_f64m1(vfloat64m1_t value1, vfloat64m1_t value2) {
    return __builtin_riscv_vfadd_vv_f64m1(value1, value2);
}
//and
static __attribute__((always_inline))
vint8m1_t vand_vv_i8m1(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vand_vv_i8m1(value1, value2);
}

static __attribute__((always_inline))
vint16m1_t vand_vv_i16m1(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vand_vv_i16m1(value1, value2);
}

static __attribute__((always_inline))
vint32m1_t vand_vv_i32m1(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vand_vv_i32m1(value1, value2);
}

static __attribute__((always_inline))
vint64m1_t vand_vv_i64m1(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vand_vv_i64m1(value1, value2);
}

//sub
static __attribute__((always_inline))
vint8m1_t vsub_vv_i8m1(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vsub_vv_i8m1(value1, value2);
}

static __attribute__((always_inline))
vint16m1_t vsub_vv_i16m1(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vsub_vv_i16m1(value1, value2);
}

static __attribute__((always_inline))
vint32m1_t vsub_vv_i32m1(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vsub_vv_i32m1(value1, value2);
}

static __attribute__((always_inline))
vint64m1_t vsub_vv_i64m1(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vsub_vv_i64m1(value1, value2);
}

static __attribute__((always_inline))
vfloat16m1_t vfsub_vv_f16m1(vfloat16m1_t value1, vfloat16m1_t value2) {
    return __builtin_riscv_vfsub_vv_f16m1(value1, value2);
}

static __attribute__((always_inline))
vfloat32m1_t vfsub_vv_f32m1(vfloat32m1_t value1, vfloat32m1_t value2) {
    return __builtin_riscv_vfsub_vv_f32m1(value1, value2);
}

static __attribute__((always_inline))
vfloat64m1_t vfsub_vv_f64m1(vfloat64m1_t value1, vfloat64m1_t value2) {
    return __builtin_riscv_vfsub_vv_f64m1(value1, value2);
}

//xor
static __attribute__((always_inline))
vint8m1_t vxor_vv_i8m1(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vxor_vv_i8m1(value1, value2);
}

static __attribute__((always_inline))
vint16m1_t vxor_vv_i16m1(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vxor_vv_i16m1(value1, value2);
}

static __attribute__((always_inline))
vint32m1_t vxor_vv_i32m1(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vxor_vv_i32m1(value1, value2);
}

static __attribute__((always_inline))
vint64m1_t vxor_vv_i64m1(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vxor_vv_i64m1(value1, value2);
}

//or
static __attribute__((always_inline))
vint8m1_t vor_vv_i8m1(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vor_vv_i8m1(value1, value2);
}

static __attribute__((always_inline))
vint16m1_t vor_vv_i16m1(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vor_vv_i16m1(value1, value2);
}

static __attribute__((always_inline))
vint32m1_t vor_vv_i32m1(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vor_vv_i32m1(value1, value2);
}

static __attribute__((always_inline))
vint64m1_t vor_vv_i64m1(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vor_vv_i64m1(value1, value2);
}

//not
static __attribute__((always_inline))
vint8m1_t vnot_v_i8m1(vint8m1_t value1) {
  return  __builtin_riscv_vnot_v_i8m1(value1);
}

static __attribute__((always_inline))
vint16m1_t vnot_v_i16m1(vint16m1_t value1) {
  return  __builtin_riscv_vnot_v_i16m1(value1);
}

static __attribute__((always_inline))
vint32m1_t vnot_v_i32m1(vint32m1_t value1) {
  return  __builtin_riscv_vnot_v_i32m1(value1);
}

static __attribute__((always_inline))
vint64m1_t vnot_v_i64m1(vint64m1_t value1) {
  return  __builtin_riscv_vnot_v_i64m1(value1);
}

//maxu
static __attribute__((always_inline))
vuint8m1_t vmaxu_vv_u8m1(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vmaxu_vv_u8m1(value1, value2);
}

static __attribute__((always_inline))
vuint16m1_t vmaxu_vv_u16m1(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vmaxu_vv_u16m1(value1, value2);
}

static __attribute__((always_inline))
vuint32m1_t vmaxu_vv_u32m1(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vmaxu_vv_u32m1(value1, value2);
}

static __attribute__((always_inline))
vuint64m1_t vmaxu_vv_u64m1(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vmaxu_vv_u64m1(value1, value2);
}

//max
static __attribute__((always_inline))
vint8m1_t vmax_vv_i8m1(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vmax_vv_i8m1(value1, value2);
}

static __attribute__((always_inline))
vint16m1_t vmax_vv_i16m1(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vmax_vv_i16m1(value1, value2);
}

static __attribute__((always_inline))
vint32m1_t vmax_vv_i32m1(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vmax_vv_i32m1(value1, value2);
}

static __attribute__((always_inline))
vint64m1_t vmax_vv_i64m1(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vmax_vv_i64m1(value1, value2);
}

//minu
static __attribute__((always_inline))
vuint8m1_t vminu_vv_u8m1(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vminu_vv_u8m1(value1, value2);
}

static __attribute__((always_inline))
vuint16m1_t vminu_vv_u16m1(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vminu_vv_u16m1(value1, value2);
}

static __attribute__((always_inline))
vuint32m1_t vminu_vv_u32m1(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vminu_vv_u32m1(value1, value2);
}

static __attribute__((always_inline))
vuint64m1_t vminu_vv_u64m1(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vminu_vv_u64m1(value1, value2);
}

//min
static __attribute__((always_inline))
vint8m1_t vmin_vv_i8m1(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vmin_vv_i8m1(value1, value2);
}

static __attribute__((always_inline))
vint16m1_t vmin_vv_i16m1(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vmin_vv_i16m1(value1, value2);
}

static __attribute__((always_inline))
vint32m1_t vmin_vv_i32m1(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vmin_vv_i32m1(value1, value2);
}

static __attribute__((always_inline))
vint64m1_t vmin_vv_i64m1(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vmin_vv_i64m1(value1, value2);
}
static __attribute__((always_inline))
vfloat16m1_t vfmin_vv_f16m1(vfloat16m1_t value1, vfloat16m1_t value2) {
    return __builtin_riscv_vfmin_vv_f16m1(value1, value2);
}

static __attribute__((always_inline))
vfloat32m1_t vfmin_vv_f32m1(vfloat32m1_t value1, vfloat32m1_t value2) {
    return __builtin_riscv_vfmin_vv_f32m1(value1, value2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmin_vv_f64m1(vfloat64m1_t value1, vfloat64m1_t value2) {
    return __builtin_riscv_vfmin_vv_f64m1(value1, value2);
}
//mul
static __attribute__((always_inline))
vint8m1_t vmul_vv_i8m1(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vmul_vv_i8m1(value1, value2);
}

static __attribute__((always_inline))
vint16m1_t vmul_vv_i16m1(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vmul_vv_i16m1(value1, value2);
}

static __attribute__((always_inline))
vint32m1_t vmul_vv_i32m1(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vmul_vv_i32m1(value1, value2);
}

static __attribute__((always_inline))
vint64m1_t vmul_vv_i64m1(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vmul_vv_i64m1(value1, value2);
}
static __attribute__((always_inline))
vfloat16m1_t vfmul_vv_f16m1(vfloat16m1_t value1, vfloat16m1_t value2) {
    return __builtin_riscv_vfmul_vv_f16m1(value1, value2);
}

static __attribute__((always_inline))
vfloat32m1_t vfmul_vv_f32m1(vfloat32m1_t value1, vfloat32m1_t value2) {
    return __builtin_riscv_vfmul_vv_f32m1(value1, value2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmul_vv_f64m1(vfloat64m1_t value1, vfloat64m1_t value2) {
    return __builtin_riscv_vfmul_vv_f64m1(value1, value2);
}
//div
static __attribute__((always_inline))
vint8m1_t vdiv_vv_i8m1(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vdiv_vv_i8m1(value1, value2);
}

static __attribute__((always_inline))
vint16m1_t vdiv_vv_i16m1(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vdiv_vv_i16m1(value1, value2);
}

static __attribute__((always_inline))
vint32m1_t vdiv_vv_i32m1(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vdiv_vv_i32m1(value1, value2);
}

static __attribute__((always_inline))
vint64m1_t vdiv_vv_i64m1(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vdiv_vv_i64m1(value1, value2);
}
static __attribute__((always_inline))
vfloat16m1_t vfdiv_vv_f16m1(vfloat16m1_t value1, vfloat16m1_t value2) {
    return __builtin_riscv_vfdiv_vv_f16m1(value1, value2);
}

static __attribute__((always_inline))
vfloat32m1_t vfdiv_vv_f32m1(vfloat32m1_t value1, vfloat32m1_t value2) {
    return __builtin_riscv_vfdiv_vv_f32m1(value1, value2);
}

static __attribute__((always_inline))
vfloat64m1_t vfdiv_vv_f64m1(vfloat64m1_t value1, vfloat64m1_t value2) {
    return __builtin_riscv_vfdiv_vv_f64m1(value1, value2);
}

//vle32
static __attribute__((always_inline))
vint32m1_t vle32_v_i32m1(const int32_t* src) {
  return __builtin_riscv_vle32_v_i32m1(src);
}

static __attribute__((always_inline))
vfloat32m1_t vle32_v_f32m1 (const float *src) {
  return __builtin_riscv_vle32_v_f32m1(src);
}

static __attribute__((always_inline))
vuint32m1_t vle32_v_u32m1(const uint32_t* src) {
  return __builtin_riscv_vle32_v_u32m1(src);
}

//vse32
static __attribute__((always_inline))
void vse32_v_i32m1(int32_t *base, vint32m1_t value) {
  __builtin_riscv_vse32_v_i32m1(base, value);
}

static __attribute__((always_inline))
void vse32_v_f32m1 (float *base, vfloat32m1_t value) {
 __builtin_riscv_vse32_v_f32m1(base, value);
}

static __attribute__((always_inline))
void vse32_v_u32m1(uint32_t *base, vuint32m1_t value) {
  __builtin_riscv_vse32_v_u32m1(base, value);
}

//vle8
static __attribute__((always_inline))
vint8m1_t vle8_v_i8m1(const int8_t* src) {
  return __builtin_riscv_vle8_v_i8m1(src);
}

static __attribute__((always_inline))
vuint8m1_t vle8_v_u8m1(const uint8_t* src) {
  return __builtin_riscv_vle8_v_u8m1(src);
}

//vse8
static __attribute__((always_inline))
void vse8_v_i8m1(int8_t *base, vint8m1_t value) {
  __builtin_riscv_vse8_v_i8m1(base, value);
}

static __attribute__((always_inline))
void vse8_v_u8m1(uint8_t *base, vuint8m1_t value) {
  __builtin_riscv_vse8_v_u8m1(base, value);
}

//vle16
static __attribute__((always_inline))
vint16m1_t vle16_v_i16m1(const int16_t* src) {
  return __builtin_riscv_vle16_v_i16m1(src);
}

//static __attribute__((always_inline))
//vfloat16m1_t vle16_v_f16m1 (const float *src) {
//  return __builtin_riscv_vle16_v_f16m1(src);
//}

static __attribute__((always_inline))
vuint16m1_t vle16_v_u16m1(const uint16_t* src) {
  return __builtin_riscv_vle16_v_u16m1(src);
}

//vse16
static __attribute__((always_inline))
void vse16_v_i16m1(int16_t *base, vint16m1_t value) {
  __builtin_riscv_vse16_v_i16m1(base, value);
}

//static __attribute__((always_inline))
//void vse16_v_f16m1 (float *base, vfloat16m1_t value) {
// __builtin_riscv_vse16_v_f16m1(base, value);
//}

static __attribute__((always_inline))
void vse16_v_u16m1(uint16_t *base, vuint16m1_t value) {
  __builtin_riscv_vse16_v_u16m1(base, value);
}

//vle64
static __attribute__((always_inline))
vint64m1_t vle64_v_i64m1(const int64_t* src) {
  return __builtin_riscv_vle64_v_i64m1(src);
}

static __attribute__((always_inline))
vfloat64m1_t vle64_v_f64m1 (const float *src) {
  return __builtin_riscv_vle64_v_f64m1(src);
}

static __attribute__((always_inline))
vuint64m1_t vle64_v_u64m1(const uint64_t* src) {
  return __builtin_riscv_vle64_v_u64m1(src);
}

//vse64
static __attribute__((always_inline))
void vse64_v_i64m1(int64_t *base, vint64m1_t value) {
  __builtin_riscv_vse64_v_i64m1(base, value);
}

static __attribute__((always_inline))
void vse64_v_f64m1 (float *base, vfloat64m1_t value) {
 __builtin_riscv_vse64_v_f64m1(base, value);
}

static __attribute__((always_inline))
void vse64_v_u64m1(uint64_t *base, vuint64m1_t value) {
  __builtin_riscv_vse64_v_u64m1(base, value);
}
//vfmac
//static __attribute__((always_inline))
//vfloat16m1_t vfmacc_vf_f16m1(vfloat16m1_t value1, float16_t op1, vfloat16m1_t value2) {
//    return __builtin_riscv_vfmacc_vf_f16m1(value1, op1, value2);
//}

static __attribute__((always_inline))
vfloat32m1_t vfmacc_vf_f32m1(vfloat32m1_t value1, float op1, vfloat32m1_t value2) {
    return __builtin_riscv_vfmacc_vf_f32m1(value1, op1, value2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmacc_vf_f64m1(vfloat64m1_t value1, double op1, vfloat64m1_t value2) {
    return __builtin_riscv_vfmacc_vf_f64m1(value1, op1, value2);
}

//vsra
static __attribute__((always_inline))
vint8m1_t vsra_vx_i8m1(vint8m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsra_vx_i8m1(value1, value2);
}

static __attribute__((always_inline))
vint16m1_t vsra_vx_i16m1(vint16m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsra_vx_i16m1(value1, value2);
}

static __attribute__((always_inline))
vint32m1_t vsra_vx_i32m1(vint32m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsra_vx_i32m1(value1, value2);
}

static __attribute__((always_inline))
vint64m1_t vsra_vx_i64m1(vint64m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsra_vx_i64m1(value1, value2);
}

//vsrl
static __attribute__((always_inline))
vuint8m1_t vsrl_vx_u8m1(vuint8m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsrl_vx_u8m1(value1, value2);
}

static __attribute__((always_inline))
vuint16m1_t vsrl_vx_u16m1(vuint16m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsrl_vx_u16m1(value1, value2);
}

static __attribute__((always_inline))
vuint32m1_t vsrl_vx_u32m1(vuint32m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsrl_vx_u32m1(value1, value2);
}

static __attribute__((always_inline))
vuint64m1_t vsrl_vx_u64m1(vuint64m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsrl_vx_u64m1(value1, value2);
}

//vsll
static __attribute__((always_inline))
vint8m1_t vsll_vx_i8m1(vint8m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsll_vx_i8m1(value1, value2);
}

static __attribute__((always_inline))
vint16m1_t vsll_vx_i16m1(vint16m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsll_vx_i16m1(value1, value2);
}

static __attribute__((always_inline))
vint32m1_t vsll_vx_i32m1(vint32m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsll_vx_i32m1(value1, value2);
}

static __attribute__((always_inline))
vint64m1_t vsll_vx_i64m1(vint64m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsll_vx_i64m1(value1, value2);
}

static __attribute__((always_inline))
vuint8m1_t vsll_vx_u8m1(vuint8m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsll_vx_u8m1(value1, value2);
}

static __attribute__((always_inline))
vuint16m1_t vsll_vx_u16m1(vuint16m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsll_vx_u16m1(value1, value2);
}

static __attribute__((always_inline))
vuint32m1_t vsll_vx_u32m1(vuint32m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsll_vx_u32m1(value1, value2);
}

static __attribute__((always_inline))
vuint64m1_t vsll_vx_u64m1(vuint64m1_t value1, uint8_t value2) {
  return  __builtin_riscv_vsll_vx_u64m1(value1, value2);
}

//vmseq
static __attribute__((always_inline))
vbool8_t vmseq_vv_i8m1_b8(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vmseq_vv_i8m1_b8(value1, value2);
}

static __attribute__((always_inline))
vbool16_t vmseq_vv_i16m1_b16(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vmseq_vv_i16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmseq_vv_i32m1_b32(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vmseq_vv_i32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmseq_vv_i64m1_b64(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vmseq_vv_i64m1_b64(value1, value2);
}

static __attribute__((always_inline))
vbool8_t vmseq_vv_u8m1_b8(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vmseq_vv_u8m1_b8(value1, value2);
}

static __attribute__((always_inline))
vbool16_t vmseq_vv_u16m1_b16(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vmseq_vv_u16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmseq_vv_u32m1_b32(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vmseq_vv_u32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmseq_vv_u64m1_b64(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vmseq_vv_u64m1_b64(value1, value2);
}


//vmsne
static __attribute__((always_inline))
vbool8_t vmsne_vv_i8m1_b8(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vmsne_vv_i8m1_b8(value1, value2);
}

static __attribute__((always_inline))
vbool16_t vmsne_vv_i16m1_b16(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vmsne_vv_i16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmsne_vv_i32m1_b32(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vmsne_vv_i32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmsne_vv_i64m1_b64(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vmsne_vv_i64m1_b64(value1, value2);
}

static __attribute__((always_inline))
vbool8_t vmsne_vv_u8m1_b8(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vmsne_vv_u8m1_b8(value1, value2);
}

static __attribute__((always_inline))
vbool16_t vmsne_vv_u16m1_b16(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vmsne_vv_u16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmsne_vv_u32m1_b32(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vmsne_vv_u32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmsne_vv_u64m1_b64(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vmsne_vv_u64m1_b64(value1, value2);
}

//vmslt
static __attribute__((always_inline))
vbool8_t vmslt_vv_i8m1_b8(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vmslt_vv_i8m1_b8(value1, value2);
}

static __attribute__((always_inline))
vbool16_t vmslt_vv_i16m1_b16(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vmslt_vv_i16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmslt_vv_i32m1_b32(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vmslt_vv_i32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmslt_vv_i64m1_b64(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vmslt_vv_i64m1_b64(value1, value2);
}

static __attribute__((always_inline))
vbool8_t vmsltu_vv_u8m1_b8(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vmsltu_vv_u8m1_b8(value1, value2);
}

static __attribute__((always_inline))
vbool16_t vmsltu_vv_u16m1_b16(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vmsltu_vv_u16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmsltu_vv_u32m1_b32(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vmsltu_vv_u32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmsltu_vv_u64m1_b64(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vmsltu_vv_u64m1_b64(value1, value2);
}
//sgt
static __attribute__((always_inline))
vbool8_t vmsgt_vv_i8m1_b8(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vmsgt_vv_i8m1_b8(value1, value2);
}

static __attribute__((always_inline))
vbool16_t vmsgt_vv_i16m1_b16(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vmsgt_vv_i16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmsgt_vv_i32m1_b32(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vmsgt_vv_i32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmsgt_vv_i64m1_b64(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vmsgt_vv_i64m1_b64(value1, value2);
}

static __attribute__((always_inline))
vbool8_t vmsgtu_vv_u8m1_b8(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vmsgtu_vv_u8m1_b8(value1, value2);
}

static __attribute__((always_inline))
vbool16_t vmsgtu_vv_u16m1_b16(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vmsgtu_vv_u16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmsgtu_vv_u32m1_b32(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vmsgtu_vv_u32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmsgtu_vv_u64m1_b64(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vmsgtu_vv_u64m1_b64(value1, value2);
}
//vmsle
static __attribute__((always_inline))
vbool8_t vmsle_vv_i8m1_b8(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vmsle_vv_i8m1_b8(value1, value2);
}

static __attribute__((always_inline))
vbool16_t vmsle_vv_i16m1_b16(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vmsle_vv_i16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmsle_vv_i32m1_b32(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vmsle_vv_i32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmsle_vv_i64m1_b64(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vmsle_vv_i64m1_b64(value1, value2);
}

static __attribute__((always_inline))
vbool8_t vmsleu_vv_u8m1_b8(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vmsleu_vv_u8m1_b8(value1, value2);
}

static __attribute__((always_inline))
vbool16_t vmsleu_vv_u16m1_b16(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vmsleu_vv_u16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmsleu_vv_u32m1_b32(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vmsleu_vv_u32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmsleu_vv_u64m1_b64(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vmsleu_vv_u64m1_b64(value1, value2);
}
//vmsge
static __attribute__((always_inline))
vbool8_t vmsge_vv_i8m1_b8(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vmsge_vv_i8m1_b8(value1, value2);
}

static __attribute__((always_inline))
vbool16_t vmsge_vv_i16m1_b16(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vmsge_vv_i16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmsge_vv_i32m1_b32(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vmsge_vv_i32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmsge_vv_i64m1_b64(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vmsge_vv_i64m1_b64(value1, value2);
}

static __attribute__((always_inline))
vbool8_t vmsgeu_vv_u8m1_b8(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vmsgeu_vv_u8m1_b8(value1, value2);
}

static __attribute__((always_inline))
vbool16_t vmsgeu_vv_u16m1_b16(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vmsgeu_vv_u16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmsgeu_vv_u32m1_b32(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vmsgeu_vv_u32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmsgeu_vv_u64m1_b64(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vmsgeu_vv_u64m1_b64(value1, value2);
}

#endif 
