
/*===---- riscv_vector.h - rvv intrinsics
 * -------------------------------------===
 *
 */

#ifndef __RISCV_VECTOR_H__
#define __RISCV_VECTOR_H__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define RISCV_VECTOR_NAME(LMUL, SEW, NAME) v##NAME##SEW##m##LMUL##_t

#define RISCV_VECTOR_TYPE(LMUL, SEW, Kind, NAME)                               \
  typedef __attribute((riscv_vector_type(LMUL, SEW)))                          \
      Kind RISCV_VECTOR_NAME(LMUL, SEW, NAME)

#define RISCV_VECTOR_TUPLE_NAME(LMUL, SEW, NAME, NR)                           \
  v##NAME##SEW##m##LMUL##x##NR##_t

#define RISCV_VECTOR_TUPLE_TYPE_1(LMUL, SEW, NAME)                             \
  typedef struct {                                                             \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v1;                                     \
  } RISCV_VECTOR_TUPLE_NAME(LMUL, SEW, NAME, 1)

#define RISCV_VECTOR_TUPLE_TYPE_2(LMUL, SEW, NAME)                             \
  typedef struct {                                                             \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v1;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v2;                                     \
  } RISCV_VECTOR_TUPLE_NAME(LMUL, SEW, NAME, 2)

#define RISCV_VECTOR_TUPLE_TYPE_3(LMUL, SEW, NAME)                             \
  typedef struct {                                                             \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v1;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v2;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v3;                                     \
  } RISCV_VECTOR_TUPLE_NAME(LMUL, SEW, NAME, 3)

#define RISCV_VECTOR_TUPLE_TYPE_4(LMUL, SEW, NAME)                             \
  typedef struct {                                                             \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v1;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v2;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v3;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v4;                                     \
  } RISCV_VECTOR_TUPLE_NAME(LMUL, SEW, NAME, 4)

#define RISCV_VECTOR_TUPLE_TYPE_5(LMUL, SEW, NAME)                             \
  typedef struct {                                                             \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v1;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v2;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v3;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v4;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v5;                                     \
  } RISCV_VECTOR_TUPLE_NAME(LMUL, SEW, NAME, 5)

#define RISCV_VECTOR_TUPLE_TYPE_6(LMUL, SEW, NAME)                             \
  typedef struct {                                                             \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v1;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v2;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v3;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v4;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v5;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v6;                                     \
  } RISCV_VECTOR_TUPLE_NAME(LMUL, SEW, NAME, 6)

#define RISCV_VECTOR_TUPLE_TYPE_7(LMUL, SEW, NAME)                             \
  typedef struct {                                                             \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v1;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v2;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v3;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v4;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v5;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v6;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v7;                                     \
  } RISCV_VECTOR_TUPLE_NAME(LMUL, SEW, NAME, 7)

#define RISCV_VECTOR_TUPLE_TYPE_8(LMUL, SEW, NAME)                             \
  typedef struct {                                                             \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v1;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v2;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v3;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v4;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v5;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v6;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v7;                                     \
    RISCV_VECTOR_NAME(LMUL, SEW, NAME) v8;                                     \
  } RISCV_VECTOR_TUPLE_NAME(LMUL, SEW, NAME, 8)

#define RISCV_MASK_NAME(MLEN) vbool##MLEN##_t

#define RISCV_MASK_TYPE(MLEN)                                                  \
  typedef __attribute((riscv_mask_type(MLEN))) bool RISCV_MASK_NAME(MLEN)

#define RISCV_VECTOR_GROUP(SEW, Kind, NAME)                                    \
  RISCV_VECTOR_TYPE(1, SEW, Kind, NAME);                                       \
  RISCV_VECTOR_TYPE(2, SEW, Kind, NAME);                                       \
  RISCV_VECTOR_TYPE(4, SEW, Kind, NAME);                                       \
  RISCV_VECTOR_TYPE(8, SEW, Kind, NAME);                                       \
                                                                               \
  RISCV_VECTOR_TUPLE_TYPE_1(1, SEW, NAME);                                     \
  RISCV_VECTOR_TUPLE_TYPE_2(1, SEW, NAME);                                     \
  RISCV_VECTOR_TUPLE_TYPE_3(1, SEW, NAME);                                     \
  RISCV_VECTOR_TUPLE_TYPE_4(1, SEW, NAME);                                     \
  RISCV_VECTOR_TUPLE_TYPE_5(1, SEW, NAME);                                     \
  RISCV_VECTOR_TUPLE_TYPE_6(1, SEW, NAME);                                     \
  RISCV_VECTOR_TUPLE_TYPE_7(1, SEW, NAME);                                     \
  RISCV_VECTOR_TUPLE_TYPE_8(1, SEW, NAME);                                     \
                                                                               \
  RISCV_VECTOR_TUPLE_TYPE_1(2, SEW, NAME);                                     \
  RISCV_VECTOR_TUPLE_TYPE_2(2, SEW, NAME);                                     \
  RISCV_VECTOR_TUPLE_TYPE_3(2, SEW, NAME);                                     \
  RISCV_VECTOR_TUPLE_TYPE_4(2, SEW, NAME);                                     \
                                                                               \
  RISCV_VECTOR_TUPLE_TYPE_1(4, SEW, NAME);                                     \
  RISCV_VECTOR_TUPLE_TYPE_2(4, SEW, NAME);                                     \
                                                                               \
  RISCV_VECTOR_TUPLE_TYPE_1(8, SEW, NAME)

// 8B integer
RISCV_VECTOR_GROUP(64, signed, int);
RISCV_VECTOR_GROUP(64, unsigned, uint);

// 4B integer
RISCV_VECTOR_GROUP(32, signed, int);
RISCV_VECTOR_GROUP(32, unsigned, uint);

// 2B integer
RISCV_VECTOR_GROUP(16, signed, int);
RISCV_VECTOR_GROUP(16, unsigned, uint);

// 1B integer
RISCV_VECTOR_GROUP(8, signed, int);
RISCV_VECTOR_GROUP(8, unsigned, uint);

// 8B float
RISCV_VECTOR_GROUP(64, float, float);

// 4B float
RISCV_VECTOR_GROUP(32, float, float);

// 2B float
RISCV_VECTOR_GROUP(16, float, float);

// mask
RISCV_MASK_TYPE(1);

RISCV_MASK_TYPE(2);

RISCV_MASK_TYPE(4);

RISCV_MASK_TYPE(8);

RISCV_MASK_TYPE(16);

RISCV_MASK_TYPE(32);

RISCV_MASK_TYPE(64);

#undef RISCV_VECTOR_NAME
#undef RISCV_VECTOR_TYPE
#undef RISCV_VECTOR_TUPLE_NAME
#undef RISCV_VECTOR_TUPLE_TYPE_1
#undef RISCV_VECTOR_TUPLE_TYPE_2
#undef RISCV_VECTOR_TUPLE_TYPE_3
#undef RISCV_VECTOR_TUPLE_TYPE_4
#undef RISCV_VECTOR_TUPLE_TYPE_5
#undef RISCV_VECTOR_TUPLE_TYPE_6
#undef RISCV_VECTOR_TUPLE_TYPE_7
#undef RISCV_VECTOR_TUPLE_TYPE_8
#undef RISCV_MASK_NAME
#undef RISCV_MASK_TYPE
#undef RISCV_VECTOR_GROUP

#define _E8 (0x0 << 2)
#define _E32 (0x2 << 2)

#define _M1 (0x0)
#define _M8 (0x3)

#define __DEFAULT_FN_ATTRS __attribute__((always_inline, nothrow))

static __DEFAULT_FN_ATTRS size_t vsetvl(size_t avl, size_t e, size_t m) {
  size_t vtype = e | m;
  return  __builtin_riscv_vsetvl(avl, vtype);
}

static __DEFAULT_FN_ATTRS size_t vsetvl_e8m1(size_t avl) {
  return vsetvl(avl, _E8, _M1);
}

static __DEFAULT_FN_ATTRS size_t vsetvl_e32m1(size_t avl) {
  return vsetvl(avl, _E32, _M1);
}

static __DEFAULT_FN_ATTRS size_t vsetvl_e32m8(size_t avl) {
  return vsetvl(avl, _E32, _M8);
}

typedef float float32_t;

static __DEFAULT_FN_ATTRS vfloat32m1_t vle32_v_f32m1(const float32_t *base) {
  return __builtin_riscv_vle32_v_f32m1(base);
}

static __DEFAULT_FN_ATTRS vfloat32m8_t vle32_v_f32m8(const float32_t *base) {
  return __builtin_riscv_vle32_v_f32m8(base);
}

static __DEFAULT_FN_ATTRS void vse32_v_f32m1(float32_t *base, vfloat32m1_t value) {
  __builtin_riscv_vse32_v_f32m1(value, base);
}

static __DEFAULT_FN_ATTRS void vse32_v_f32m8(float32_t *base, vfloat32m8_t value) {
  __builtin_riscv_vse32_v_f32m8(value, base);
}

static __DEFAULT_FN_ATTRS vfloat32m1_t vfmacc_vf_f32m1(vfloat32m1_t acc, float32_t op1,
                                           vfloat32m1_t op2) {
  return __builtin_riscv_vfmacc_vf_f32m1(acc, op1, op2);
}

static __DEFAULT_FN_ATTRS vfloat32m8_t vfmacc_vf_f32m8(vfloat32m8_t acc, float32_t op1,
                                           vfloat32m8_t op2) {
  return __builtin_riscv_vfmacc_vf_f32m8(acc, op1, op2);
}

static __DEFAULT_FN_ATTRS float32_t vfmv_f_s_f32m1_f32 (vfloat32m1_t src) {
  return __builtin_riscv_vfmv_f_s_f32m1_f32(src);
}

#endif
