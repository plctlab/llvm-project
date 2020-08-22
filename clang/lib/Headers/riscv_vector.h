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

#define _MF2 35

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

typedef __attribute__((riscv_vector_type(32, 2, 1))) float vfloat32mf2_t;

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
//add
static __attribute__((always_inline))
size_t vsetvl_e32m8(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E32 | _M8);
}

static __attribute__((always_inline))
size_t vsetvl_e32mf2(size_t avl) {
  return __builtin_riscv_vsetvl(avl, _E32 | _MF2);
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
static __attribute__((always_inline))
vuint8m1_t vadd_vv_u8m1(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vadd_vv_u8m1(value1, value2);
}

static __attribute__((always_inline))
vuint16m1_t vadd_vv_u16m1(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vadd_vv_u16m1(value1, value2);
}

static __attribute__((always_inline))
vuint32m1_t vadd_vv_u32m1(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vadd_vv_u32m1(value1, value2);
}

static __attribute__((always_inline))
vuint64m1_t vadd_vv_u64m1(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vadd_vv_u64m1(value1, value2);
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

static __attribute__((always_inline))
vuint8m1_t vand_vv_u8m1(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vand_vv_u8m1(value1, value2);
}

static __attribute__((always_inline))
vuint16m1_t vand_vv_u16m1(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vand_vv_u16m1(value1, value2);
}

static __attribute__((always_inline))
vuint32m1_t vand_vv_u32m1(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vand_vv_u32m1(value1, value2);
}

static __attribute__((always_inline))
vuint64m1_t vand_vv_u64m1(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vand_vv_u64m1(value1, value2);
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

static __attribute__((always_inline))
vuint8m1_t vsub_vv_u8m1(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vsub_vv_u8m1(value1, value2);
}

static __attribute__((always_inline))
vuint16m1_t vsub_vv_u16m1(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vsub_vv_u16m1(value1, value2);
}

static __attribute__((always_inline))
vuint32m1_t vsub_vv_u32m1(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vsub_vv_u32m1(value1, value2);
}

static __attribute__((always_inline))
vuint64m1_t vsub_vv_u64m1(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vsub_vv_u64m1(value1, value2);
}

//xor
static __attribute__((always_inline))
vuint8m1_t vxor_vv_u8m1(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vxor_vv_u8m1(value1, value2);
}

static __attribute__((always_inline))
vuint16m1_t vxor_vv_u16m1(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vxor_vv_u16m1(value1, value2);
}

static __attribute__((always_inline))
vuint32m1_t vxor_vv_u32m1(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vxor_vv_u32m1(value1, value2);
}

static __attribute__((always_inline))
vuint64m1_t vxor_vv_u64m1(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vxor_vv_u64m1(value1, value2);
}

//or
static __attribute__((always_inline))
vuint8m1_t vor_vv_u8m1(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vor_vv_u8m1(value1, value2);
}

static __attribute__((always_inline))
vuint16m1_t vor_vv_u16m1(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vor_vv_u16m1(value1, value2);
}

static __attribute__((always_inline))
vuint32m1_t vor_vv_u32m1(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vor_vv_u32m1(value1, value2);
}

static __attribute__((always_inline))
vuint64m1_t vor_vv_u64m1(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vor_vv_u64m1(value1, value2);
}

//not
static __attribute__((always_inline))
vuint8m1_t vnot_v_u8m1(vuint8m1_t value1) {
  return  __builtin_riscv_vnot_v_u8m1(value1);
}

static __attribute__((always_inline))
vuint16m1_t vnot_v_u16m1(vuint16m1_t value1) {
  return  __builtin_riscv_vnot_v_u16m1(value1);
}

static __attribute__((always_inline))
vuint32m1_t vnot_v_u32m1(vuint32m1_t value1) {
  return  __builtin_riscv_vnot_v_u32m1(value1);
}

static __attribute__((always_inline))
vuint64m1_t vnot_v_u64m1(vuint64m1_t value1) {
  return  __builtin_riscv_vnot_v_u64m1(value1);
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
//static __attribute__((always_inline))
//vfloat16m1_t vfmin_vv_f16m1(vfloat16m1_t value1, vfloat16m1_t value2) {
//    return __builtin_riscv_vfmin_vv_f16m1(value1, value2);
//}

//static __attribute__((always_inline))
//vfloat32m1_t vfmin_vv_f32m1(vfloat32m1_t value1, vfloat32m1_t value2) {
//    return __builtin_riscv_vfmin_vv_f32m1(value1, value2);
//}

//static __attribute__((always_inline))
//vfloat64m1_t vfmin_vv_f64m1(vfloat64m1_t value1, vfloat64m1_t value2) {
//    return __builtin_riscv_vfmin_vv_f64m1(value1, value2);
//}
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
static __attribute__((always_inline))
vuint8m1_t vmul_vv_u8m1(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vmul_vv_u8m1(value1, value2);
}

static __attribute__((always_inline))
vuint16m1_t vmul_vv_u16m1(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vmul_vv_u16m1(value1, value2);
}

static __attribute__((always_inline))
vuint32m1_t vmul_vv_u32m1(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vmul_vv_u32m1(value1, value2);
}

static __attribute__((always_inline))
vuint64m1_t vmul_vv_u64m1(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vmul_vv_u64m1(value1, value2);
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

static __attribute__((always_inline))
vuint8m1_t vdivu_vv_u8m1(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vdivu_vv_u8m1(value1, value2);
}

static __attribute__((always_inline))
vuint16m1_t vdivu_vv_u16m1(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vdivu_vv_u16m1(value1, value2);
}

static __attribute__((always_inline))
vuint32m1_t vdivu_vv_u32m1(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vdivu_vv_u32m1(value1, value2);
}

static __attribute__((always_inline))
vuint64m1_t vdivu_vv_u64m1(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vdivu_vv_u64m1(value1, value2);
}

//vle32

static __attribute__((always_inline))
vint32m1_t vle32_v_i32m1(const int32_t* src) {
  return __builtin_riscv_vle32_v_i32m1(src);
}

static __attribute__((always_inline))
vfloat32mf2_t vle32_v_f32mf2 (const float *src) {
  return __builtin_riscv_vle32_v_f32mf2(src);
}

static __attribute__((always_inline))
vfloat32m1_t vle32_v_f32m1 (const float *src) {
  return __builtin_riscv_vle32_v_f32m1(src);
}

static __attribute__((always_inline))
vfloat32m8_t vle32_v_f32m8 (const float *src) {
  return __builtin_riscv_vle32_v_f32m8(src);
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
void vse32_v_f32mf2 (float *base, vfloat32mf2_t value) {
 __builtin_riscv_vse32_v_f32mf2(base, value);
}

static __attribute__((always_inline))
void vse32_v_f32m1 (float *base, vfloat32m1_t value) {
 __builtin_riscv_vse32_v_f32m1(base, value);
}

static __attribute__((always_inline))
void vse32_v_f32m8 (float *base, vfloat32m8_t value) {
 __builtin_riscv_vse32_v_f32m8(base, value);
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
vfloat64m1_t vle64_v_f64m1 (const double *src) {
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
void vse64_v_f64m1 (double *base, vfloat64m1_t value) {
 __builtin_riscv_vse64_v_f64m1(base, value);
}

static __attribute__((always_inline))
void vse64_v_u64m1(uint64_t *base, vuint64m1_t value) {
  __builtin_riscv_vse64_v_u64m1(base, value);
}


static __attribute__((always_inline))
vfloat32mf2_t vfmacc_vf_f32mf2(vfloat32mf2_t value1, float op1, vfloat32mf2_t value2) {
    return __builtin_riscv_vfmacc_vf_f32mf2(value1, op1, value2);
}

static __attribute__((always_inline))
vfloat32m8_t vfmacc_vf_f32m8(vfloat32m8_t value1, float op1, vfloat32m8_t value2) {
    return __builtin_riscv_vfmacc_vf_f32m8(value1, op1, value2);
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

//vmfeq
static __attribute__((always_inline))
vbool16_t vmfeq_vv_f16m1_b16(vfloat16m1_t value1, vfloat16m1_t value2) {
    return __builtin_riscv_vmfeq_vv_f16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmfeq_vv_f32m1_b32(vfloat32m1_t value1, vfloat32m1_t value2) {
    return __builtin_riscv_vmfeq_vv_f32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmfeq_vv_f64m1_b64(vfloat64m1_t value1, vfloat64m1_t value2) {
    return __builtin_riscv_vmfeq_vv_f64m1_b64(value1, value2);
}

//vmfne
static __attribute__((always_inline))
vbool16_t vmfne_vv_f16m1_b16(vfloat16m1_t value1, vfloat16m1_t value2) {
    return __builtin_riscv_vmfne_vv_f16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmfne_vv_f32m1_b32(vfloat32m1_t value1, vfloat32m1_t value2) {
    return __builtin_riscv_vmfne_vv_f32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmfne_vv_f64m1_b64(vfloat64m1_t value1, vfloat64m1_t value2) {
    return __builtin_riscv_vmfne_vv_f64m1_b64(value1, value2);
}

//vmflt
static __attribute__((always_inline))
vbool16_t vmflt_vv_f16m1_b16(vfloat16m1_t value1, vfloat16m1_t value2) {
    return __builtin_riscv_vmflt_vv_f16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmflt_vv_f32m1_b32(vfloat32m1_t value1, vfloat32m1_t value2) {
    return __builtin_riscv_vmflt_vv_f32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmflt_vv_f64m1_b64(vfloat64m1_t value1, vfloat64m1_t value2) {
    return __builtin_riscv_vmflt_vv_f64m1_b64(value1, value2);
}

//vmfgt
static __attribute__((always_inline))
vbool16_t vmfgt_vv_f16m1_b16(vfloat16m1_t value1, vfloat16m1_t value2) {
    return __builtin_riscv_vmfgt_vv_f16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmfgt_vv_f32m1_b32(vfloat32m1_t value1, vfloat32m1_t value2) {
    return __builtin_riscv_vmfgt_vv_f32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmfgt_vv_f64m1_b64(vfloat64m1_t value1, vfloat64m1_t value2) {
    return __builtin_riscv_vmfgt_vv_f64m1_b64(value1, value2);
}

//vmfle
static __attribute__((always_inline))
vbool16_t vmfle_vv_f16m1_b16(vfloat16m1_t value1, vfloat16m1_t value2) {
    return __builtin_riscv_vmfle_vv_f16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmfle_vv_f32m1_b32(vfloat32m1_t value1, vfloat32m1_t value2) {
    return __builtin_riscv_vmfle_vv_f32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmfle_vv_f64m1_b64(vfloat64m1_t value1, vfloat64m1_t value2) {
    return __builtin_riscv_vmfle_vv_f64m1_b64(value1, value2);
}
//vmfge
static __attribute__((always_inline))
vbool16_t vmfge_vv_f16m1_b16(vfloat16m1_t value1, vfloat16m1_t value2) {
    return __builtin_riscv_vmfge_vv_f16m1_b16(value1, value2);
}

static __attribute__((always_inline))
vbool32_t vmfge_vv_f32m1_b32(vfloat32m1_t value1, vfloat32m1_t value2) {
    return __builtin_riscv_vmfge_vv_f32m1_b32(value1, value2);
}

static __attribute__((always_inline))
vbool64_t vmfge_vv_f64m1_b64(vfloat64m1_t value1, vfloat64m1_t value2) {
    return __builtin_riscv_vmfge_vv_f64m1_b64(value1, value2);
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

//slide
/*vint8m1_t vslideup_vx_i8m1_m(vbool8_t mask, vint8m1_t dst, vint8m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i8m1_m(mask, dst, src, offset);
}

static __attribute__((always_inline))
vint16m1_t vslideup_vx_i16m1_m(vbool16_t mask, vint16m1_t dst, vint16m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i16m1_m(mask, dst, src, offset);
}

static __attribute__((always_inline))
vint32m1_t vslideup_vx_i32m1_m(vbool32_t mask, vint32m1_t dst, vint32m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i32m1_m(mask, dst, src, offset);
}

static __attribute__((always_inline))
vint64m1_t vslideup_vx_i64m1_m(vbool64_t mask, vint64m1_t dst, vint64m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i64m1_m(mask, dst, src, offset);
}

static __attribute__((always_inline))
vuint8m1_t vslideup_vx_u8m1_m(vbool8_t mask, vuint8m1_t dst, vuint8m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u8m1_m(mask, dst, src, offset);
}

static __attribute__((always_inline))
vuint16m1_t vslideup_vx_u16m1_m(vbool16_t mask, vuint16m1_t dst, vuint16m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u16m1_m(mask, dst, src, offset);
}

static __attribute__((always_inline))
vuint32m1_t vslideup_vx_u32m1_m(vbool32_t mask, vuint32m1_t dst, vuint32m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u32m1_m(mask, dst, src, offset);
}

static __attribute__((always_inline))
vuint64m1_t vslideup_vx_u64m1_m(vbool64_t mask, vuint64m1_t dst, vuint64m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u64m1_m(mask, dst, src, offset);
}

static __attribute__((always_inline))
vfloat32m1_t vslideup_vx_f32m1_m(vbool32_t mask, vfloat32m1_t dst, vfloat32m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f32m1_m(mask, dst, src, offset);
}

static __attribute__((always_inline))
vfloat64m1_t vslideup_vx_f64m1_m(vbool64_t mask, vfloat64m1_t dst, vfloat64m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f64m1_m(mask, dst, src, offset);
}
*/
//vmset
/*static __attribute__((always_inline))
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
*/
//vmv_v_x
static __attribute__((always_inline))
vint8m1_t vmv_v_x_i8m1(int8_t src) {
  return __builtin_riscv_vmv_v_x_i8m1(src);
}

static __attribute__((always_inline)) 
vint16m1_t vmv_v_x_i16m1(int16_t src) {
  return __builtin_riscv_vmv_v_x_i16m1(src);
}

static __attribute__((always_inline))
vint32m1_t vmv_v_x_i32m1(int32_t src) {
  return __builtin_riscv_vmv_v_x_i32m1(src);
}

static __attribute__((always_inline))
vint64m1_t vmv_v_x_i64m1(int64_t src) {
  return __builtin_riscv_vmv_v_x_i64m1(src);
}

static __attribute__((always_inline))
vuint8m1_t vmv_v_x_u8m1(uint8_t src) {
  return __builtin_riscv_vmv_v_x_u8m1(src);
}

static __attribute__((always_inline))
vuint16m1_t vmv_v_x_u16m1(uint16_t src) {
  return __builtin_riscv_vmv_v_x_u16m1(src);
}

static __attribute__((always_inline))
vuint32m1_t vmv_v_x_u32m1(uint32_t src) {
  return __builtin_riscv_vmv_v_x_u32m1(src);
}

static __attribute__((always_inline))
vuint64m1_t vmv_v_x_u64m1(uint64_t src) {
  return __builtin_riscv_vmv_v_x_u64m1(src);
}

static __attribute__((always_inline))
float vfmv_f_s_f32m1_f32(vfloat32m1_t src) {
  return __builtin_riscv_vfmv_f_s_f32m1_f32(src);
}

static __attribute__((always_inline))
double vfmv_f_s_f64m1_f64(vfloat64m1_t src) {
  return __builtin_riscv_vfmv_f_s_f64m1_f64(src);
}

static __attribute__((always_inline))
vfloat32m1_t vfmv_v_f_f32m1(float src) {
  return __builtin_riscv_vfmv_v_f_f32m1(src);
}

static __attribute__((always_inline))
vfloat64m1_t vfmv_v_f_f64m1(double src) {
  return __builtin_riscv_vfmv_v_f_f64m1(src);
}

//vmv_v_s
static __attribute__((always_inline))
int8_t vmv_x_s_i8m1_i8(vint8m1_t src) {
  return __builtin_riscv_vmv_x_s_i8m1_i8(src);
}

static __attribute__((always_inline))
int16_t vmv_x_s_i16m1_i16(vint16m1_t src) {
  return __builtin_riscv_vmv_x_s_i16m1_i16(src);
}

static __attribute__((always_inline))
int32_t vmv_x_s_i32m1_i32(vint32m1_t src) {
  return __builtin_riscv_vmv_x_s_i32m1_i32(src);
}

static __attribute__((always_inline))
int64_t vmv_x_s_i64m1_i64(vint64m1_t src) {
  return __builtin_riscv_vmv_x_s_i64m1_i64(src);
}

static __attribute__((always_inline))
uint8_t vmv_x_s_u8m1_u8(vuint8m1_t src) {
  return __builtin_riscv_vmv_x_s_u8m1_u8(src);
}

static __attribute__((always_inline))
uint16_t vmv_x_s_u16m1_u16(vuint16m1_t src) {
  return __builtin_riscv_vmv_x_s_u16m1_u16(src);
}

static __attribute__((always_inline))
uint32_t vmv_x_s_u32m1_u32(vuint32m1_t src) {
  return __builtin_riscv_vmv_x_s_u32m1_u32(src);
}

static __attribute__((always_inline))
uint64_t vmv_x_s_u64m1_u64(vuint64m1_t src) {
  return __builtin_riscv_vmv_x_s_u64m1_u64(src);
}

//vzero
static __attribute__((always_inline))
vint8m1_t vzero_i8m1() {
  vint8m1_t x;
  return x;
}

static __attribute__((always_inline))
vint16m1_t vzero_i16m1() {
  vint16m1_t x;
  return x;
}

static __attribute__((always_inline))
vint32m1_t vzero_i32m1() {
  vint32m1_t x;
  return x;
}

static __attribute__((always_inline))
vint64m1_t vzero_i64m1() {
  vint64m1_t x;
  return x;
}

static __attribute__((always_inline))
vuint8m1_t vzero_u8m1() {
  vuint8m1_t x;
  return x;
}

static __attribute__((always_inline))
vuint16m1_t vzero_u16m1() {
  vuint16m1_t x;
  return x;
}

static __attribute__((always_inline))
vuint32m1_t vzero_u32m1() {
  vuint32m1_t x;
  return x;
}

static __attribute__((always_inline))
vuint64m1_t vzero_u64m1() {
  vuint64m1_t x;
  return x;
}

static __attribute__((always_inline))
vfloat32m1_t vzero_f32m1() {
  vfloat32m1_t x;
  return x;
}

static __attribute__((always_inline))
vfloat64m1_t vzero_f64m1() {
  vfloat64m1_t x;
  return x;
}
//vsadd
static __attribute__((always_inline))
vint8m1_t vsadd_vv_i8m1(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vsadd_vv_i8m1(value1, value2);
}

static __attribute__((always_inline))
vint16m1_t vsadd_vv_i16m1(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vsadd_vv_i16m1(value1, value2);
}

static __attribute__((always_inline))
vint32m1_t vsadd_vv_i32m1(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vsadd_vv_i32m1(value1, value2);
}

static __attribute__((always_inline))
vint64m1_t vsadd_vv_i64m1(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vsadd_vv_i64m1(value1, value2);
}

static __attribute__((always_inline))
vuint8m1_t vsaddu_vv_u8m1(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vsaddu_vv_u8m1(value1, value2);
}

static __attribute__((always_inline))
vuint16m1_t vsaddu_vv_u16m1(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vsaddu_vv_u16m1(value1, value2);
}

static __attribute__((always_inline))
vuint32m1_t vsaddu_vv_u32m1(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vsaddu_vv_u32m1(value1, value2);
}

static __attribute__((always_inline))
vuint64m1_t vsaddu_vv_u64m1(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vsaddu_vv_u64m1(value1, value2);
}
//vssub
static __attribute__((always_inline))
vint8m1_t vssub_vv_i8m1(vint8m1_t value1, vint8m1_t value2) {
  return  __builtin_riscv_vssub_vv_i8m1(value1, value2);
}

static __attribute__((always_inline))
vint16m1_t vssub_vv_i16m1(vint16m1_t value1, vint16m1_t value2) {
  return  __builtin_riscv_vssub_vv_i16m1(value1, value2);
}

static __attribute__((always_inline))
vint32m1_t vssub_vv_i32m1(vint32m1_t value1, vint32m1_t value2) {
  return  __builtin_riscv_vssub_vv_i32m1(value1, value2);
}

static __attribute__((always_inline))
vint64m1_t vssub_vv_i64m1(vint64m1_t value1, vint64m1_t value2) {
  return  __builtin_riscv_vssub_vv_i64m1(value1, value2);
}

static __attribute__((always_inline))
vuint8m1_t vssubu_vv_u8m1(vuint8m1_t value1, vuint8m1_t value2) {
  return  __builtin_riscv_vssubu_vv_u8m1(value1, value2);
}

static __attribute__((always_inline))
vuint16m1_t vssubu_vv_u16m1(vuint16m1_t value1, vuint16m1_t value2) {
  return  __builtin_riscv_vssubu_vv_u16m1(value1, value2);
}

static __attribute__((always_inline))
vuint32m1_t vssubu_vv_u32m1(vuint32m1_t value1, vuint32m1_t value2) {
  return  __builtin_riscv_vssubu_vv_u32m1(value1, value2);
}

static __attribute__((always_inline))
vuint64m1_t vssubu_vv_u64m1(vuint64m1_t value1, vuint64m1_t value2) {
  return  __builtin_riscv_vssubu_vv_u64m1(value1, value2);
}

// Vector Integer Merge Operations

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


//vfmerge

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



// Vector Slide Operations
static __attribute__((always_inline))
vint8m1_t vslideup_vx_i8m1(vint8m1_t dst, vint8m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i8m1(dst, src, offset);
}

static __attribute__((always_inline))
vint8m1_t vslidedown_vx_i8m1(vint8m1_t dst, vint8m1_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_i8m1(dst, src, offset);
}

static __attribute__((always_inline))
vint8m2_t vslideup_vx_i8m2(vint8m2_t dst, vint8m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i8m2(dst, src, offset);
}

static __attribute__((always_inline))
vint8m2_t vslidedown_vx_i8m2(vint8m2_t dst, vint8m2_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_i8m2(dst, src, offset);
}

static __attribute__((always_inline))
vint8m4_t vslideup_vx_i8m4(vint8m4_t dst, vint8m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i8m4(dst, src, offset);
}

static __attribute__((always_inline))
vint8m4_t vslidedown_vx_i8m4(vint8m4_t dst, vint8m4_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_i8m4(dst, src, offset);
}

static __attribute__((always_inline))
vint16m1_t vslideup_vx_i16m1(vint16m1_t dst, vint16m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i16m1(dst, src, offset);
}

static __attribute__((always_inline))
vint16m1_t vslidedown_vx_i16m1(vint16m1_t dst, vint16m1_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_i16m1(dst, src, offset);
}

static __attribute__((always_inline))
vint16m2_t vslideup_vx_i16m2(vint16m2_t dst, vint16m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i16m2(dst, src, offset);
}

static __attribute__((always_inline))
vint16m2_t vslidedown_vx_i16m2(vint16m2_t dst, vint16m2_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_i16m2(dst, src, offset);
}

static __attribute__((always_inline))
vint16m4_t vslideup_vx_i16m4(vint16m4_t dst, vint16m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i16m4(dst, src, offset);
}

static __attribute__((always_inline))
vint16m4_t vslidedown_vx_i16m4(vint16m4_t dst, vint16m4_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_i16m4(dst, src, offset);
}

static __attribute__((always_inline))
vint32m1_t vslideup_vx_i32m1(vint32m1_t dst, vint32m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i32m1(dst, src, offset);
}

static __attribute__((always_inline))
vint32m1_t vslidedown_vx_i32m1(vint32m1_t dst, vint32m1_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_i32m1(dst, src, offset);
}

static __attribute__((always_inline))
vint32m2_t vslideup_vx_i32m2(vint32m2_t dst, vint32m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i32m2(dst, src, offset);
}

static __attribute__((always_inline))
vint32m2_t vslidedown_vx_i32m2(vint32m2_t dst, vint32m2_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_i32m2(dst, src, offset);
}

static __attribute__((always_inline))
vint32m4_t vslideup_vx_i32m4(vint32m4_t dst, vint32m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i32m4(dst, src, offset);
}

static __attribute__((always_inline))
vint32m4_t vslidedown_vx_i32m4(vint32m4_t dst, vint32m4_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_i32m4(dst, src, offset);
}

static __attribute__((always_inline))
vint64m1_t vslideup_vx_i64m1(vint64m1_t dst, vint64m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i64m1(dst, src, offset);
}

static __attribute__((always_inline))
vint64m1_t vslidedown_vx_i64m1(vint64m1_t dst, vint64m1_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_i64m1(dst, src, offset);
}

static __attribute__((always_inline))
vint64m2_t vslideup_vx_i64m2(vint64m2_t dst, vint64m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i64m2(dst, src, offset);
}

static __attribute__((always_inline))
vint64m2_t vslidedown_vx_i64m2(vint64m2_t dst, vint64m2_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_i64m2(dst, src, offset);
}

static __attribute__((always_inline))
vint64m4_t vslideup_vx_i64m4(vint64m4_t dst, vint64m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_i64m4(dst, src, offset);
}

static __attribute__((always_inline))
vint64m4_t vslidedown_vx_i64m4(vint64m4_t dst, vint64m4_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_i64m4(dst, src, offset);
}

static __attribute__((always_inline))
vuint8m1_t vslideup_vx_u8m1(vuint8m1_t dst, vuint8m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u8m1(dst, src, offset);
}

static __attribute__((always_inline))
vuint8m1_t vslidedown_vx_u8m1(vuint8m1_t dst, vuint8m1_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_u8m1(dst, src, offset);
}

static __attribute__((always_inline))
vuint8m2_t vslideup_vx_u8m2(vuint8m2_t dst, vuint8m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u8m2(dst, src, offset);
}

static __attribute__((always_inline))
vuint8m2_t vslidedown_vx_u8m2(vuint8m2_t dst, vuint8m2_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_u8m2(dst, src, offset);
}

static __attribute__((always_inline))
vuint8m4_t vslideup_vx_u8m4(vuint8m4_t dst, vuint8m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u8m4(dst, src, offset);
}

static __attribute__((always_inline))
vuint8m4_t vslidedown_vx_u8m4(vuint8m4_t dst, vuint8m4_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_u8m4(dst, src, offset);
}

static __attribute__((always_inline))
vuint16m1_t vslideup_vx_u16m1(vuint16m1_t dst, vuint16m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u16m1(dst, src, offset);
}

static __attribute__((always_inline))
vuint16m1_t vslidedown_vx_u16m1(vuint16m1_t dst, vuint16m1_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_u16m1(dst, src, offset);
}

static __attribute__((always_inline))
vuint16m2_t vslideup_vx_u16m2(vuint16m2_t dst, vuint16m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u16m2(dst, src, offset);
}

static __attribute__((always_inline))
vuint16m2_t vslidedown_vx_u16m2(vuint16m2_t dst, vuint16m2_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_u16m2(dst, src, offset);
}

static __attribute__((always_inline))
vuint16m4_t vslideup_vx_u16m4(vuint16m4_t dst, vuint16m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u16m4(dst, src, offset);
}

static __attribute__((always_inline))
vuint16m4_t vslidedown_vx_u16m4(vuint16m4_t dst, vuint16m4_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_u16m4(dst, src, offset);
}

static __attribute__((always_inline))
vuint32m1_t vslideup_vx_u32m1(vuint32m1_t dst, vuint32m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u32m1(dst, src, offset);
}

static __attribute__((always_inline))
vuint32m1_t vslidedown_vx_u32m1(vuint32m1_t dst, vuint32m1_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_u32m1(dst, src, offset);
}

static __attribute__((always_inline))
vuint32m2_t vslideup_vx_u32m2(vuint32m2_t dst, vuint32m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u32m2(dst, src, offset);
}

static __attribute__((always_inline))
vuint32m2_t vslidedown_vx_u32m2(vuint32m2_t dst, vuint32m2_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_u32m2(dst, src, offset);
}

static __attribute__((always_inline))
vuint32m4_t vslideup_vx_u32m4(vuint32m4_t dst, vuint32m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u32m4(dst, src, offset);
}

static __attribute__((always_inline))
vuint32m4_t vslidedown_vx_u32m4(vuint32m4_t dst, vuint32m4_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_u32m4(dst, src, offset);
}

static __attribute__((always_inline))
vuint64m1_t vslideup_vx_u64m1(vuint64m1_t dst, vuint64m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u64m1(dst, src, offset);
}

static __attribute__((always_inline))
vuint64m1_t vslidedown_vx_u64m1(vuint64m1_t dst, vuint64m1_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_u64m1(dst, src, offset);
}

static __attribute__((always_inline))
vuint64m2_t vslideup_vx_u64m2(vuint64m2_t dst, vuint64m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u64m2(dst, src, offset);
}

static __attribute__((always_inline))
vuint64m2_t vslidedown_vx_u64m2(vuint64m2_t dst, vuint64m2_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_u64m2(dst, src, offset);
}

static __attribute__((always_inline))
vuint64m4_t vslideup_vx_u64m4(vuint64m4_t dst, vuint64m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_u64m4(dst, src, offset);
}

static __attribute__((always_inline))
vuint64m4_t vslidedown_vx_u64m4(vuint64m4_t dst, vuint64m4_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_u64m4(dst, src, offset);
}

static __attribute__((always_inline))
vfloat32m1_t vslideup_vx_f32m1(vfloat32m1_t dst, vfloat32m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f32m1(dst, src, offset);
}

static __attribute__((always_inline))
vfloat32m1_t vslidedown_vx_f32m1(vfloat32m1_t dst, vfloat32m1_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_f32m1(dst, src, offset);
}

static __attribute__((always_inline))
vfloat32m2_t vslideup_vx_f32m2(vfloat32m2_t dst, vfloat32m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f32m2(dst, src, offset);
}

static __attribute__((always_inline))
vfloat32m2_t vslidedown_vx_f32m2(vfloat32m2_t dst, vfloat32m2_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_f32m2(dst, src, offset);
}

static __attribute__((always_inline))
vfloat32m4_t vslideup_vx_f32m4(vfloat32m4_t dst, vfloat32m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f32m4(dst, src, offset);
}

static __attribute__((always_inline))
vfloat32m4_t vslidedown_vx_f32m4(vfloat32m4_t dst, vfloat32m4_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_f32m4(dst, src, offset);
}

static __attribute__((always_inline))
vfloat64m1_t vslideup_vx_f64m1(vfloat64m1_t dst, vfloat64m1_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f64m1(dst, src, offset);
}

static __attribute__((always_inline))
vfloat64m1_t vslidedown_vx_f64m1(vfloat64m1_t dst, vfloat64m1_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_f64m1(dst, src, offset);
}

static __attribute__((always_inline))
vfloat64m2_t vslideup_vx_f64m2(vfloat64m2_t dst, vfloat64m2_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f64m2(dst, src, offset);
}

static __attribute__((always_inline))
vfloat64m2_t vslidedown_vx_f64m2(vfloat64m2_t dst, vfloat64m2_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_f64m2(dst, src, offset);
}

static __attribute__((always_inline))
vfloat64m4_t vslideup_vx_f64m4(vfloat64m4_t dst, vfloat64m4_t src, size_t offset) {
  return __builtin_riscv_vslideup_vx_f64m4(dst, src, offset);
}

static __attribute__((always_inline))
vfloat64m4_t vslidedown_vx_f64m4(vfloat64m4_t dst, vfloat64m4_t src, size_t offset) {
  return __builtin_riscv_vslidedown_vx_f64m4(dst, src, offset);
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
vint8m2_t vmacc_vv_i8m2(vint8m2_t acc, vint8m2_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmacc_vv_i8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint8m2_t vmacc_vx_i8m2(vint8m2_t acc, int8_t op1, vint8m2_t op2) {
  return __builtin_riscv_vmacc_vx_i8m2(acc, op1, op2);
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
vint16m1_t vmacc_vv_i16m1(vint16m1_t acc, vint16m1_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmacc_vv_i16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m1_t vmacc_vx_i16m1(vint16m1_t acc, int16_t op1, vint16m1_t op2) {
  return __builtin_riscv_vmacc_vx_i16m1(acc, op1, op2);
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
vint16m4_t vmacc_vv_i16m4(vint16m4_t acc, vint16m4_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmacc_vv_i16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint16m4_t vmacc_vx_i16m4(vint16m4_t acc, int16_t op1, vint16m4_t op2) {
  return __builtin_riscv_vmacc_vx_i16m4(acc, op1, op2);
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
vint32m2_t vmacc_vv_i32m2(vint32m2_t acc, vint32m2_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmacc_vv_i32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vint32m2_t vmacc_vx_i32m2(vint32m2_t acc, int32_t op1, vint32m2_t op2) {
  return __builtin_riscv_vmacc_vx_i32m2(acc, op1, op2);
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
vint64m1_t vmacc_vv_i64m1(vint64m1_t acc, vint64m1_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmacc_vv_i64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m1_t vmacc_vx_i64m1(vint64m1_t acc, int64_t op1, vint64m1_t op2) {
  return __builtin_riscv_vmacc_vx_i64m1(acc, op1, op2);
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
vint64m4_t vmacc_vv_i64m4(vint64m4_t acc, vint64m4_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmacc_vv_i64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vint64m4_t vmacc_vx_i64m4(vint64m4_t acc, int64_t op1, vint64m4_t op2) {
  return __builtin_riscv_vmacc_vx_i64m4(acc, op1, op2);
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
vuint8m2_t vmacc_vv_u8m2(vuint8m2_t acc, vuint8m2_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vmacc_vv_u8m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint8m2_t vmacc_vx_u8m2(vuint8m2_t acc, uint8_t op1, vuint8m2_t op2) {
  return __builtin_riscv_vmacc_vx_u8m2(acc, op1, op2);
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
vuint16m1_t vmacc_vv_u16m1(vuint16m1_t acc, vuint16m1_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vmacc_vv_u16m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m1_t vmacc_vx_u16m1(vuint16m1_t acc, uint16_t op1, vuint16m1_t op2) {
  return __builtin_riscv_vmacc_vx_u16m1(acc, op1, op2);
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
vuint16m4_t vmacc_vv_u16m4(vuint16m4_t acc, vuint16m4_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vmacc_vv_u16m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint16m4_t vmacc_vx_u16m4(vuint16m4_t acc, uint16_t op1, vuint16m4_t op2) {
  return __builtin_riscv_vmacc_vx_u16m4(acc, op1, op2);
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
vuint32m2_t vmacc_vv_u32m2(vuint32m2_t acc, vuint32m2_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vmacc_vv_u32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vuint32m2_t vmacc_vx_u32m2(vuint32m2_t acc, uint32_t op1, vuint32m2_t op2) {
  return __builtin_riscv_vmacc_vx_u32m2(acc, op1, op2);
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
vuint64m1_t vmacc_vv_u64m1(vuint64m1_t acc, vuint64m1_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vmacc_vv_u64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m1_t vmacc_vx_u64m1(vuint64m1_t acc, uint64_t op1, vuint64m1_t op2) {
  return __builtin_riscv_vmacc_vx_u64m1(acc, op1, op2);
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
vuint64m4_t vmacc_vv_u64m4(vuint64m4_t acc, vuint64m4_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vmacc_vv_u64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vuint64m4_t vmacc_vx_u64m4(vuint64m4_t acc, uint64_t op1, vuint64m4_t op2) {
  return __builtin_riscv_vmacc_vx_u64m4(acc, op1, op2);
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
vfloat32m2_t vfmacc_vv_f32m2(vfloat32m2_t acc, vfloat32m2_t op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfmacc_vv_f32m2(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat32m2_t vfmacc_vf_f32m2(vfloat32m2_t acc, float op1, vfloat32m2_t op2) {
  return __builtin_riscv_vfmacc_vf_f32m2(acc, op1, op2);
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
vfloat64m1_t vfmacc_vv_f64m1(vfloat64m1_t acc, vfloat64m1_t op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfmacc_vv_f64m1(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m1_t vfmacc_vf_f64m1(vfloat64m1_t acc, double op1, vfloat64m1_t op2) {
  return __builtin_riscv_vfmacc_vf_f64m1(acc, op1, op2);
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
vfloat64m4_t vfmacc_vv_f64m4(vfloat64m4_t acc, vfloat64m4_t op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfmacc_vv_f64m4(acc, op1, op2);
}

static __attribute__((always_inline))
vfloat64m4_t vfmacc_vf_f64m4(vfloat64m4_t acc, double op1, vfloat64m4_t op2) {
  return __builtin_riscv_vfmacc_vf_f64m4(acc, op1, op2);
}

// Single-Width Floating-Point/Integer Type-Convert Operations
static __attribute__((always_inline))
vint32m1_t vfcvt_rtz_x_f_v_i32m1(vfloat32m1_t src) {
  return __builtin_riscv_vfcvt_rtz_x_f_v_i32m1(src);
}

static __attribute__((always_inline))
vfloat32m1_t vfcvt_f_x_v_f32m1(vint32m1_t src) {
  return __builtin_riscv_vfcvt_f_x_v_f32m1(src);
}

static __attribute__((always_inline))
vint32m2_t vfcvt_rtz_x_f_v_i32m2(vfloat32m2_t src) {
  return __builtin_riscv_vfcvt_rtz_x_f_v_i32m2(src);
}

static __attribute__((always_inline))
vfloat32m2_t vfcvt_f_x_v_f32m2(vint32m2_t src) {
  return __builtin_riscv_vfcvt_f_x_v_f32m2(src);
}

static __attribute__((always_inline))
vint32m4_t vfcvt_rtz_x_f_v_i32m4(vfloat32m4_t src) {
  return __builtin_riscv_vfcvt_rtz_x_f_v_i32m4(src);
}

static __attribute__((always_inline))
vfloat32m4_t vfcvt_f_x_v_f32m4(vint32m4_t src) {
  return __builtin_riscv_vfcvt_f_x_v_f32m4(src);
}

static __attribute__((always_inline))
vint64m1_t vfcvt_rtz_x_f_v_i64m1(vfloat64m1_t src) {
  return __builtin_riscv_vfcvt_rtz_x_f_v_i64m1(src);
}

static __attribute__((always_inline))
vfloat64m1_t vfcvt_f_x_v_f64m1(vint64m1_t src) {
  return __builtin_riscv_vfcvt_f_x_v_f64m1(src);
}

static __attribute__((always_inline))
vint64m2_t vfcvt_rtz_x_f_v_i64m2(vfloat64m2_t src) {
  return __builtin_riscv_vfcvt_rtz_x_f_v_i64m2(src);
}

static __attribute__((always_inline))
vfloat64m2_t vfcvt_f_x_v_f64m2(vint64m2_t src) {
  return __builtin_riscv_vfcvt_f_x_v_f64m2(src);
}

static __attribute__((always_inline))
vint64m4_t vfcvt_rtz_x_f_v_i64m4(vfloat64m4_t src) {
  return __builtin_riscv_vfcvt_rtz_x_f_v_i64m4(src);
}

static __attribute__((always_inline))
vfloat64m4_t vfcvt_f_x_v_f64m4(vint64m4_t src) {
  return __builtin_riscv_vfcvt_f_x_v_f64m4(src);
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


#endif

