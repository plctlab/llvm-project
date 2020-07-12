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


typedef struct {
  vint8m1_t v1;
  vint8m1_t v2;
} vint8m1x2_t;

typedef struct {
  vint8m1_t v1;
  vint8m1_t v2;
  vint8m1_t v3;
} vint8m1x3_t;

typedef struct {
  vint8m1_t v1;
  vint8m1_t v2;
  vint8m1_t v3;
  vint8m1_t v4;
} vint8m1x4_t;

typedef struct {
  vint8m1_t v1;
  vint8m1_t v2;
  vint8m1_t v3;
  vint8m1_t v4;
  vint8m1_t v5;
} vint8m1x5_t;

typedef struct {
  vint8m1_t v1;
  vint8m1_t v2;
  vint8m1_t v3;
  vint8m1_t v4;
  vint8m1_t v5;
  vint8m1_t v6;
} vint8m1x6_t;

typedef struct {
  vint8m1_t v1;
  vint8m1_t v2;
  vint8m1_t v3;
  vint8m1_t v4;
  vint8m1_t v5;
  vint8m1_t v6;
  vint8m1_t v7;
} vint8m1x7_t;

typedef struct {
  vint8m1_t v1;
  vint8m1_t v2;
  vint8m1_t v3;
  vint8m1_t v4;
  vint8m1_t v5;
  vint8m1_t v6;
  vint8m1_t v7;
  vint8m1_t v8;
} vint8m1x8_t;

typedef struct {
  vint8m2_t v1;
  vint8m2_t v2;
} vint8m2x2_t;

typedef struct {
  vint8m2_t v1;
  vint8m2_t v2;
  vint8m2_t v3;
} vint8m2x3_t;

typedef struct {
  vint8m2_t v1;
  vint8m2_t v2;
  vint8m2_t v3;
  vint8m2_t v4;
} vint8m2x4_t;

typedef struct {
  vint8m2_t v1;
  vint8m2_t v2;
  vint8m2_t v3;
  vint8m2_t v4;
  vint8m2_t v5;
} vint8m2x5_t;

typedef struct {
  vint8m2_t v1;
  vint8m2_t v2;
  vint8m2_t v3;
  vint8m2_t v4;
  vint8m2_t v5;
  vint8m2_t v6;
} vint8m2x6_t;

typedef struct {
  vint8m2_t v1;
  vint8m2_t v2;
  vint8m2_t v3;
  vint8m2_t v4;
  vint8m2_t v5;
  vint8m2_t v6;
  vint8m2_t v7;
} vint8m2x7_t;

typedef struct {
  vint8m2_t v1;
  vint8m2_t v2;
  vint8m2_t v3;
  vint8m2_t v4;
  vint8m2_t v5;
  vint8m2_t v6;
  vint8m2_t v7;
  vint8m2_t v8;
} vint8m2x8_t;

typedef struct {
  vint8m4_t v1;
  vint8m4_t v2;
} vint8m4x2_t;

typedef struct {
  vint8m4_t v1;
  vint8m4_t v2;
  vint8m4_t v3;
} vint8m4x3_t;

typedef struct {
  vint8m4_t v1;
  vint8m4_t v2;
  vint8m4_t v3;
  vint8m4_t v4;
} vint8m4x4_t;

typedef struct {
  vint8m4_t v1;
  vint8m4_t v2;
  vint8m4_t v3;
  vint8m4_t v4;
  vint8m4_t v5;
} vint8m4x5_t;

typedef struct {
  vint8m4_t v1;
  vint8m4_t v2;
  vint8m4_t v3;
  vint8m4_t v4;
  vint8m4_t v5;
  vint8m4_t v6;
} vint8m4x6_t;

typedef struct {
  vint8m4_t v1;
  vint8m4_t v2;
  vint8m4_t v3;
  vint8m4_t v4;
  vint8m4_t v5;
  vint8m4_t v6;
  vint8m4_t v7;
} vint8m4x7_t;

typedef struct {
  vint8m4_t v1;
  vint8m4_t v2;
  vint8m4_t v3;
  vint8m4_t v4;
  vint8m4_t v5;
  vint8m4_t v6;
  vint8m4_t v7;
  vint8m4_t v8;
} vint8m4x8_t;

typedef struct {
  vint8m8_t v1;
  vint8m8_t v2;
} vint8m8x2_t;

typedef struct {
  vint8m8_t v1;
  vint8m8_t v2;
  vint8m8_t v3;
} vint8m8x3_t;

typedef struct {
  vint8m8_t v1;
  vint8m8_t v2;
  vint8m8_t v3;
  vint8m8_t v4;
} vint8m8x4_t;

typedef struct {
  vint8m8_t v1;
  vint8m8_t v2;
  vint8m8_t v3;
  vint8m8_t v4;
  vint8m8_t v5;
} vint8m8x5_t;

typedef struct {
  vint8m8_t v1;
  vint8m8_t v2;
  vint8m8_t v3;
  vint8m8_t v4;
  vint8m8_t v5;
  vint8m8_t v6;
} vint8m8x6_t;

typedef struct {
  vint8m8_t v1;
  vint8m8_t v2;
  vint8m8_t v3;
  vint8m8_t v4;
  vint8m8_t v5;
  vint8m8_t v6;
  vint8m8_t v7;
} vint8m8x7_t;

typedef struct {
  vint8m8_t v1;
  vint8m8_t v2;
  vint8m8_t v3;
  vint8m8_t v4;
  vint8m8_t v5;
  vint8m8_t v6;
  vint8m8_t v7;
  vint8m8_t v8;
} vint8m8x8_t;

typedef struct {
  vint16m1_t v1;
  vint16m1_t v2;
} vint16m1x2_t;

typedef struct {
  vint16m1_t v1;
  vint16m1_t v2;
  vint16m1_t v3;
} vint16m1x3_t;

typedef struct {
  vint16m1_t v1;
  vint16m1_t v2;
  vint16m1_t v3;
  vint16m1_t v4;
} vint16m1x4_t;

typedef struct {
  vint16m1_t v1;
  vint16m1_t v2;
  vint16m1_t v3;
  vint16m1_t v4;
  vint16m1_t v5;
} vint16m1x5_t;

typedef struct {
  vint16m1_t v1;
  vint16m1_t v2;
  vint16m1_t v3;
  vint16m1_t v4;
  vint16m1_t v5;
  vint16m1_t v6;
} vint16m1x6_t;

typedef struct {
  vint16m1_t v1;
  vint16m1_t v2;
  vint16m1_t v3;
  vint16m1_t v4;
  vint16m1_t v5;
  vint16m1_t v6;
  vint16m1_t v7;
} vint16m1x7_t;

typedef struct {
  vint16m1_t v1;
  vint16m1_t v2;
  vint16m1_t v3;
  vint16m1_t v4;
  vint16m1_t v5;
  vint16m1_t v6;
  vint16m1_t v7;
  vint16m1_t v8;
} vint16m1x8_t;

typedef struct {
  vint16m2_t v1;
  vint16m2_t v2;
} vint16m2x2_t;

typedef struct {
  vint16m2_t v1;
  vint16m2_t v2;
  vint16m2_t v3;
} vint16m2x3_t;

typedef struct {
  vint16m2_t v1;
  vint16m2_t v2;
  vint16m2_t v3;
  vint16m2_t v4;
} vint16m2x4_t;

typedef struct {
  vint16m2_t v1;
  vint16m2_t v2;
  vint16m2_t v3;
  vint16m2_t v4;
  vint16m2_t v5;
} vint16m2x5_t;

typedef struct {
  vint16m2_t v1;
  vint16m2_t v2;
  vint16m2_t v3;
  vint16m2_t v4;
  vint16m2_t v5;
  vint16m2_t v6;
} vint16m2x6_t;

typedef struct {
  vint16m2_t v1;
  vint16m2_t v2;
  vint16m2_t v3;
  vint16m2_t v4;
  vint16m2_t v5;
  vint16m2_t v6;
  vint16m2_t v7;
} vint16m2x7_t;

typedef struct {
  vint16m2_t v1;
  vint16m2_t v2;
  vint16m2_t v3;
  vint16m2_t v4;
  vint16m2_t v5;
  vint16m2_t v6;
  vint16m2_t v7;
  vint16m2_t v8;
} vint16m2x8_t;

typedef struct {
  vint16m4_t v1;
  vint16m4_t v2;
} vint16m4x2_t;

typedef struct {
  vint16m4_t v1;
  vint16m4_t v2;
  vint16m4_t v3;
} vint16m4x3_t;

typedef struct {
  vint16m4_t v1;
  vint16m4_t v2;
  vint16m4_t v3;
  vint16m4_t v4;
} vint16m4x4_t;

typedef struct {
  vint16m4_t v1;
  vint16m4_t v2;
  vint16m4_t v3;
  vint16m4_t v4;
  vint16m4_t v5;
} vint16m4x5_t;

typedef struct {
  vint16m4_t v1;
  vint16m4_t v2;
  vint16m4_t v3;
  vint16m4_t v4;
  vint16m4_t v5;
  vint16m4_t v6;
} vint16m4x6_t;

typedef struct {
  vint16m4_t v1;
  vint16m4_t v2;
  vint16m4_t v3;
  vint16m4_t v4;
  vint16m4_t v5;
  vint16m4_t v6;
  vint16m4_t v7;
} vint16m4x7_t;

typedef struct {
  vint16m4_t v1;
  vint16m4_t v2;
  vint16m4_t v3;
  vint16m4_t v4;
  vint16m4_t v5;
  vint16m4_t v6;
  vint16m4_t v7;
  vint16m4_t v8;
} vint16m4x8_t;

typedef struct {
  vint16m8_t v1;
  vint16m8_t v2;
} vint16m8x2_t;

typedef struct {
  vint16m8_t v1;
  vint16m8_t v2;
  vint16m8_t v3;
} vint16m8x3_t;

typedef struct {
  vint16m8_t v1;
  vint16m8_t v2;
  vint16m8_t v3;
  vint16m8_t v4;
} vint16m8x4_t;

typedef struct {
  vint16m8_t v1;
  vint16m8_t v2;
  vint16m8_t v3;
  vint16m8_t v4;
  vint16m8_t v5;
} vint16m8x5_t;

typedef struct {
  vint16m8_t v1;
  vint16m8_t v2;
  vint16m8_t v3;
  vint16m8_t v4;
  vint16m8_t v5;
  vint16m8_t v6;
} vint16m8x6_t;

typedef struct {
  vint16m8_t v1;
  vint16m8_t v2;
  vint16m8_t v3;
  vint16m8_t v4;
  vint16m8_t v5;
  vint16m8_t v6;
  vint16m8_t v7;
} vint16m8x7_t;

typedef struct {
  vint16m8_t v1;
  vint16m8_t v2;
  vint16m8_t v3;
  vint16m8_t v4;
  vint16m8_t v5;
  vint16m8_t v6;
  vint16m8_t v7;
  vint16m8_t v8;
} vint16m8x8_t;

typedef struct {
  vint32m1_t v1;
  vint32m1_t v2;
} vint32m1x2_t;

typedef struct {
  vint32m1_t v1;
  vint32m1_t v2;
  vint32m1_t v3;
} vint32m1x3_t;

typedef struct {
  vint32m1_t v1;
  vint32m1_t v2;
  vint32m1_t v3;
  vint32m1_t v4;
} vint32m1x4_t;

typedef struct {
  vint32m1_t v1;
  vint32m1_t v2;
  vint32m1_t v3;
  vint32m1_t v4;
  vint32m1_t v5;
} vint32m1x5_t;

typedef struct {
  vint32m1_t v1;
  vint32m1_t v2;
  vint32m1_t v3;
  vint32m1_t v4;
  vint32m1_t v5;
  vint32m1_t v6;
} vint32m1x6_t;

typedef struct {
  vint32m1_t v1;
  vint32m1_t v2;
  vint32m1_t v3;
  vint32m1_t v4;
  vint32m1_t v5;
  vint32m1_t v6;
  vint32m1_t v7;
} vint32m1x7_t;

typedef struct {
  vint32m1_t v1;
  vint32m1_t v2;
  vint32m1_t v3;
  vint32m1_t v4;
  vint32m1_t v5;
  vint32m1_t v6;
  vint32m1_t v7;
  vint32m1_t v8;
} vint32m1x8_t;

typedef struct {
  vint32m2_t v1;
  vint32m2_t v2;
} vint32m2x2_t;

typedef struct {
  vint32m2_t v1;
  vint32m2_t v2;
  vint32m2_t v3;
} vint32m2x3_t;

typedef struct {
  vint32m2_t v1;
  vint32m2_t v2;
  vint32m2_t v3;
  vint32m2_t v4;
} vint32m2x4_t;

typedef struct {
  vint32m2_t v1;
  vint32m2_t v2;
  vint32m2_t v3;
  vint32m2_t v4;
  vint32m2_t v5;
} vint32m2x5_t;

typedef struct {
  vint32m2_t v1;
  vint32m2_t v2;
  vint32m2_t v3;
  vint32m2_t v4;
  vint32m2_t v5;
  vint32m2_t v6;
} vint32m2x6_t;

typedef struct {
  vint32m2_t v1;
  vint32m2_t v2;
  vint32m2_t v3;
  vint32m2_t v4;
  vint32m2_t v5;
  vint32m2_t v6;
  vint32m2_t v7;
} vint32m2x7_t;

typedef struct {
  vint32m2_t v1;
  vint32m2_t v2;
  vint32m2_t v3;
  vint32m2_t v4;
  vint32m2_t v5;
  vint32m2_t v6;
  vint32m2_t v7;
  vint32m2_t v8;
} vint32m2x8_t;

typedef struct {
  vint32m4_t v1;
  vint32m4_t v2;
} vint32m4x2_t;

typedef struct {
  vint32m4_t v1;
  vint32m4_t v2;
  vint32m4_t v3;
} vint32m4x3_t;

typedef struct {
  vint32m4_t v1;
  vint32m4_t v2;
  vint32m4_t v3;
  vint32m4_t v4;
} vint32m4x4_t;

typedef struct {
  vint32m4_t v1;
  vint32m4_t v2;
  vint32m4_t v3;
  vint32m4_t v4;
  vint32m4_t v5;
} vint32m4x5_t;

typedef struct {
  vint32m4_t v1;
  vint32m4_t v2;
  vint32m4_t v3;
  vint32m4_t v4;
  vint32m4_t v5;
  vint32m4_t v6;
} vint32m4x6_t;

typedef struct {
  vint32m4_t v1;
  vint32m4_t v2;
  vint32m4_t v3;
  vint32m4_t v4;
  vint32m4_t v5;
  vint32m4_t v6;
  vint32m4_t v7;
} vint32m4x7_t;

typedef struct {
  vint32m4_t v1;
  vint32m4_t v2;
  vint32m4_t v3;
  vint32m4_t v4;
  vint32m4_t v5;
  vint32m4_t v6;
  vint32m4_t v7;
  vint32m4_t v8;
} vint32m4x8_t;

typedef struct {
  vint32m8_t v1;
  vint32m8_t v2;
} vint32m8x2_t;

typedef struct {
  vint32m8_t v1;
  vint32m8_t v2;
  vint32m8_t v3;
} vint32m8x3_t;

typedef struct {
  vint32m8_t v1;
  vint32m8_t v2;
  vint32m8_t v3;
  vint32m8_t v4;
} vint32m8x4_t;

typedef struct {
  vint32m8_t v1;
  vint32m8_t v2;
  vint32m8_t v3;
  vint32m8_t v4;
  vint32m8_t v5;
} vint32m8x5_t;

typedef struct {
  vint32m8_t v1;
  vint32m8_t v2;
  vint32m8_t v3;
  vint32m8_t v4;
  vint32m8_t v5;
  vint32m8_t v6;
} vint32m8x6_t;

typedef struct {
  vint32m8_t v1;
  vint32m8_t v2;
  vint32m8_t v3;
  vint32m8_t v4;
  vint32m8_t v5;
  vint32m8_t v6;
  vint32m8_t v7;
} vint32m8x7_t;

typedef struct {
  vint32m8_t v1;
  vint32m8_t v2;
  vint32m8_t v3;
  vint32m8_t v4;
  vint32m8_t v5;
  vint32m8_t v6;
  vint32m8_t v7;
  vint32m8_t v8;
} vint32m8x8_t;

typedef struct {
  vint64m1_t v1;
  vint64m1_t v2;
} vint64m1x2_t;

typedef struct {
  vint64m1_t v1;
  vint64m1_t v2;
  vint64m1_t v3;
} vint64m1x3_t;

typedef struct {
  vint64m1_t v1;
  vint64m1_t v2;
  vint64m1_t v3;
  vint64m1_t v4;
} vint64m1x4_t;

typedef struct {
  vint64m1_t v1;
  vint64m1_t v2;
  vint64m1_t v3;
  vint64m1_t v4;
  vint64m1_t v5;
} vint64m1x5_t;

typedef struct {
  vint64m1_t v1;
  vint64m1_t v2;
  vint64m1_t v3;
  vint64m1_t v4;
  vint64m1_t v5;
  vint64m1_t v6;
} vint64m1x6_t;

typedef struct {
  vint64m1_t v1;
  vint64m1_t v2;
  vint64m1_t v3;
  vint64m1_t v4;
  vint64m1_t v5;
  vint64m1_t v6;
  vint64m1_t v7;
} vint64m1x7_t;

typedef struct {
  vint64m1_t v1;
  vint64m1_t v2;
  vint64m1_t v3;
  vint64m1_t v4;
  vint64m1_t v5;
  vint64m1_t v6;
  vint64m1_t v7;
  vint64m1_t v8;
} vint64m1x8_t;

typedef struct {
  vint64m2_t v1;
  vint64m2_t v2;
} vint64m2x2_t;

typedef struct {
  vint64m2_t v1;
  vint64m2_t v2;
  vint64m2_t v3;
} vint64m2x3_t;

typedef struct {
  vint64m2_t v1;
  vint64m2_t v2;
  vint64m2_t v3;
  vint64m2_t v4;
} vint64m2x4_t;

typedef struct {
  vint64m2_t v1;
  vint64m2_t v2;
  vint64m2_t v3;
  vint64m2_t v4;
  vint64m2_t v5;
} vint64m2x5_t;

typedef struct {
  vint64m2_t v1;
  vint64m2_t v2;
  vint64m2_t v3;
  vint64m2_t v4;
  vint64m2_t v5;
  vint64m2_t v6;
} vint64m2x6_t;

typedef struct {
  vint64m2_t v1;
  vint64m2_t v2;
  vint64m2_t v3;
  vint64m2_t v4;
  vint64m2_t v5;
  vint64m2_t v6;
  vint64m2_t v7;
} vint64m2x7_t;

typedef struct {
  vint64m2_t v1;
  vint64m2_t v2;
  vint64m2_t v3;
  vint64m2_t v4;
  vint64m2_t v5;
  vint64m2_t v6;
  vint64m2_t v7;
  vint64m2_t v8;
} vint64m2x8_t;

typedef struct {
  vint64m4_t v1;
  vint64m4_t v2;
} vint64m4x2_t;

typedef struct {
  vint64m4_t v1;
  vint64m4_t v2;
  vint64m4_t v3;
} vint64m4x3_t;

typedef struct {
  vint64m4_t v1;
  vint64m4_t v2;
  vint64m4_t v3;
  vint64m4_t v4;
} vint64m4x4_t;

typedef struct {
  vint64m4_t v1;
  vint64m4_t v2;
  vint64m4_t v3;
  vint64m4_t v4;
  vint64m4_t v5;
} vint64m4x5_t;

typedef struct {
  vint64m4_t v1;
  vint64m4_t v2;
  vint64m4_t v3;
  vint64m4_t v4;
  vint64m4_t v5;
  vint64m4_t v6;
} vint64m4x6_t;

typedef struct {
  vint64m4_t v1;
  vint64m4_t v2;
  vint64m4_t v3;
  vint64m4_t v4;
  vint64m4_t v5;
  vint64m4_t v6;
  vint64m4_t v7;
} vint64m4x7_t;

typedef struct {
  vint64m4_t v1;
  vint64m4_t v2;
  vint64m4_t v3;
  vint64m4_t v4;
  vint64m4_t v5;
  vint64m4_t v6;
  vint64m4_t v7;
  vint64m4_t v8;
} vint64m4x8_t;

typedef struct {
  vint64m8_t v1;
  vint64m8_t v2;
} vint64m8x2_t;

typedef struct {
  vint64m8_t v1;
  vint64m8_t v2;
  vint64m8_t v3;
} vint64m8x3_t;

typedef struct {
  vint64m8_t v1;
  vint64m8_t v2;
  vint64m8_t v3;
  vint64m8_t v4;
} vint64m8x4_t;

typedef struct {
  vint64m8_t v1;
  vint64m8_t v2;
  vint64m8_t v3;
  vint64m8_t v4;
  vint64m8_t v5;
} vint64m8x5_t;

typedef struct {
  vint64m8_t v1;
  vint64m8_t v2;
  vint64m8_t v3;
  vint64m8_t v4;
  vint64m8_t v5;
  vint64m8_t v6;
} vint64m8x6_t;

typedef struct {
  vint64m8_t v1;
  vint64m8_t v2;
  vint64m8_t v3;
  vint64m8_t v4;
  vint64m8_t v5;
  vint64m8_t v6;
  vint64m8_t v7;
} vint64m8x7_t;

typedef struct {
  vint64m8_t v1;
  vint64m8_t v2;
  vint64m8_t v3;
  vint64m8_t v4;
  vint64m8_t v5;
  vint64m8_t v6;
  vint64m8_t v7;
  vint64m8_t v8;
} vint64m8x8_t;

typedef struct {
  vuint8m1_t v1;
  vuint8m1_t v2;
} vuint8m1x2_t;

typedef struct {
  vuint8m1_t v1;
  vuint8m1_t v2;
  vuint8m1_t v3;
} vuint8m1x3_t;

typedef struct {
  vuint8m1_t v1;
  vuint8m1_t v2;
  vuint8m1_t v3;
  vuint8m1_t v4;
} vuint8m1x4_t;

typedef struct {
  vuint8m1_t v1;
  vuint8m1_t v2;
  vuint8m1_t v3;
  vuint8m1_t v4;
  vuint8m1_t v5;
} vuint8m1x5_t;

typedef struct {
  vuint8m1_t v1;
  vuint8m1_t v2;
  vuint8m1_t v3;
  vuint8m1_t v4;
  vuint8m1_t v5;
  vuint8m1_t v6;
} vuint8m1x6_t;

typedef struct {
  vuint8m1_t v1;
  vuint8m1_t v2;
  vuint8m1_t v3;
  vuint8m1_t v4;
  vuint8m1_t v5;
  vuint8m1_t v6;
  vuint8m1_t v7;
} vuint8m1x7_t;

typedef struct {
  vuint8m1_t v1;
  vuint8m1_t v2;
  vuint8m1_t v3;
  vuint8m1_t v4;
  vuint8m1_t v5;
  vuint8m1_t v6;
  vuint8m1_t v7;
  vuint8m1_t v8;
} vuint8m1x8_t;

typedef struct {
  vuint8m2_t v1;
  vuint8m2_t v2;
} vuint8m2x2_t;

typedef struct {
  vuint8m2_t v1;
  vuint8m2_t v2;
  vuint8m2_t v3;
} vuint8m2x3_t;

typedef struct {
  vuint8m2_t v1;
  vuint8m2_t v2;
  vuint8m2_t v3;
  vuint8m2_t v4;
} vuint8m2x4_t;

typedef struct {
  vuint8m2_t v1;
  vuint8m2_t v2;
  vuint8m2_t v3;
  vuint8m2_t v4;
  vuint8m2_t v5;
} vuint8m2x5_t;

typedef struct {
  vuint8m2_t v1;
  vuint8m2_t v2;
  vuint8m2_t v3;
  vuint8m2_t v4;
  vuint8m2_t v5;
  vuint8m2_t v6;
} vuint8m2x6_t;

typedef struct {
  vuint8m2_t v1;
  vuint8m2_t v2;
  vuint8m2_t v3;
  vuint8m2_t v4;
  vuint8m2_t v5;
  vuint8m2_t v6;
  vuint8m2_t v7;
} vuint8m2x7_t;

typedef struct {
  vuint8m2_t v1;
  vuint8m2_t v2;
  vuint8m2_t v3;
  vuint8m2_t v4;
  vuint8m2_t v5;
  vuint8m2_t v6;
  vuint8m2_t v7;
  vuint8m2_t v8;
} vuint8m2x8_t;

typedef struct {
  vuint8m4_t v1;
  vuint8m4_t v2;
} vuint8m4x2_t;

typedef struct {
  vuint8m4_t v1;
  vuint8m4_t v2;
  vuint8m4_t v3;
} vuint8m4x3_t;

typedef struct {
  vuint8m4_t v1;
  vuint8m4_t v2;
  vuint8m4_t v3;
  vuint8m4_t v4;
} vuint8m4x4_t;

typedef struct {
  vuint8m4_t v1;
  vuint8m4_t v2;
  vuint8m4_t v3;
  vuint8m4_t v4;
  vuint8m4_t v5;
} vuint8m4x5_t;

typedef struct {
  vuint8m4_t v1;
  vuint8m4_t v2;
  vuint8m4_t v3;
  vuint8m4_t v4;
  vuint8m4_t v5;
  vuint8m4_t v6;
} vuint8m4x6_t;

typedef struct {
  vuint8m4_t v1;
  vuint8m4_t v2;
  vuint8m4_t v3;
  vuint8m4_t v4;
  vuint8m4_t v5;
  vuint8m4_t v6;
  vuint8m4_t v7;
} vuint8m4x7_t;

typedef struct {
  vuint8m4_t v1;
  vuint8m4_t v2;
  vuint8m4_t v3;
  vuint8m4_t v4;
  vuint8m4_t v5;
  vuint8m4_t v6;
  vuint8m4_t v7;
  vuint8m4_t v8;
} vuint8m4x8_t;

typedef struct {
  vuint8m8_t v1;
  vuint8m8_t v2;
} vuint8m8x2_t;

typedef struct {
  vuint8m8_t v1;
  vuint8m8_t v2;
  vuint8m8_t v3;
} vuint8m8x3_t;

typedef struct {
  vuint8m8_t v1;
  vuint8m8_t v2;
  vuint8m8_t v3;
  vuint8m8_t v4;
} vuint8m8x4_t;

typedef struct {
  vuint8m8_t v1;
  vuint8m8_t v2;
  vuint8m8_t v3;
  vuint8m8_t v4;
  vuint8m8_t v5;
} vuint8m8x5_t;

typedef struct {
  vuint8m8_t v1;
  vuint8m8_t v2;
  vuint8m8_t v3;
  vuint8m8_t v4;
  vuint8m8_t v5;
  vuint8m8_t v6;
} vuint8m8x6_t;

typedef struct {
  vuint8m8_t v1;
  vuint8m8_t v2;
  vuint8m8_t v3;
  vuint8m8_t v4;
  vuint8m8_t v5;
  vuint8m8_t v6;
  vuint8m8_t v7;
} vuint8m8x7_t;

typedef struct {
  vuint8m8_t v1;
  vuint8m8_t v2;
  vuint8m8_t v3;
  vuint8m8_t v4;
  vuint8m8_t v5;
  vuint8m8_t v6;
  vuint8m8_t v7;
  vuint8m8_t v8;
} vuint8m8x8_t;

typedef struct {
  vuint16m1_t v1;
  vuint16m1_t v2;
} vuint16m1x2_t;

typedef struct {
  vuint16m1_t v1;
  vuint16m1_t v2;
  vuint16m1_t v3;
} vuint16m1x3_t;

typedef struct {
  vuint16m1_t v1;
  vuint16m1_t v2;
  vuint16m1_t v3;
  vuint16m1_t v4;
} vuint16m1x4_t;

typedef struct {
  vuint16m1_t v1;
  vuint16m1_t v2;
  vuint16m1_t v3;
  vuint16m1_t v4;
  vuint16m1_t v5;
} vuint16m1x5_t;

typedef struct {
  vuint16m1_t v1;
  vuint16m1_t v2;
  vuint16m1_t v3;
  vuint16m1_t v4;
  vuint16m1_t v5;
  vuint16m1_t v6;
} vuint16m1x6_t;

typedef struct {
  vuint16m1_t v1;
  vuint16m1_t v2;
  vuint16m1_t v3;
  vuint16m1_t v4;
  vuint16m1_t v5;
  vuint16m1_t v6;
  vuint16m1_t v7;
} vuint16m1x7_t;

typedef struct {
  vuint16m1_t v1;
  vuint16m1_t v2;
  vuint16m1_t v3;
  vuint16m1_t v4;
  vuint16m1_t v5;
  vuint16m1_t v6;
  vuint16m1_t v7;
  vuint16m1_t v8;
} vuint16m1x8_t;

typedef struct {
  vuint16m2_t v1;
  vuint16m2_t v2;
} vuint16m2x2_t;

typedef struct {
  vuint16m2_t v1;
  vuint16m2_t v2;
  vuint16m2_t v3;
} vuint16m2x3_t;

typedef struct {
  vuint16m2_t v1;
  vuint16m2_t v2;
  vuint16m2_t v3;
  vuint16m2_t v4;
} vuint16m2x4_t;

typedef struct {
  vuint16m2_t v1;
  vuint16m2_t v2;
  vuint16m2_t v3;
  vuint16m2_t v4;
  vuint16m2_t v5;
} vuint16m2x5_t;

typedef struct {
  vuint16m2_t v1;
  vuint16m2_t v2;
  vuint16m2_t v3;
  vuint16m2_t v4;
  vuint16m2_t v5;
  vuint16m2_t v6;
} vuint16m2x6_t;

typedef struct {
  vuint16m2_t v1;
  vuint16m2_t v2;
  vuint16m2_t v3;
  vuint16m2_t v4;
  vuint16m2_t v5;
  vuint16m2_t v6;
  vuint16m2_t v7;
} vuint16m2x7_t;

typedef struct {
  vuint16m2_t v1;
  vuint16m2_t v2;
  vuint16m2_t v3;
  vuint16m2_t v4;
  vuint16m2_t v5;
  vuint16m2_t v6;
  vuint16m2_t v7;
  vuint16m2_t v8;
} vuint16m2x8_t;

typedef struct {
  vuint16m4_t v1;
  vuint16m4_t v2;
} vuint16m4x2_t;

typedef struct {
  vuint16m4_t v1;
  vuint16m4_t v2;
  vuint16m4_t v3;
} vuint16m4x3_t;

typedef struct {
  vuint16m4_t v1;
  vuint16m4_t v2;
  vuint16m4_t v3;
  vuint16m4_t v4;
} vuint16m4x4_t;

typedef struct {
  vuint16m4_t v1;
  vuint16m4_t v2;
  vuint16m4_t v3;
  vuint16m4_t v4;
  vuint16m4_t v5;
} vuint16m4x5_t;

typedef struct {
  vuint16m4_t v1;
  vuint16m4_t v2;
  vuint16m4_t v3;
  vuint16m4_t v4;
  vuint16m4_t v5;
  vuint16m4_t v6;
} vuint16m4x6_t;

typedef struct {
  vuint16m4_t v1;
  vuint16m4_t v2;
  vuint16m4_t v3;
  vuint16m4_t v4;
  vuint16m4_t v5;
  vuint16m4_t v6;
  vuint16m4_t v7;
} vuint16m4x7_t;

typedef struct {
  vuint16m4_t v1;
  vuint16m4_t v2;
  vuint16m4_t v3;
  vuint16m4_t v4;
  vuint16m4_t v5;
  vuint16m4_t v6;
  vuint16m4_t v7;
  vuint16m4_t v8;
} vuint16m4x8_t;

typedef struct {
  vuint16m8_t v1;
  vuint16m8_t v2;
} vuint16m8x2_t;

typedef struct {
  vuint16m8_t v1;
  vuint16m8_t v2;
  vuint16m8_t v3;
} vuint16m8x3_t;

typedef struct {
  vuint16m8_t v1;
  vuint16m8_t v2;
  vuint16m8_t v3;
  vuint16m8_t v4;
} vuint16m8x4_t;

typedef struct {
  vuint16m8_t v1;
  vuint16m8_t v2;
  vuint16m8_t v3;
  vuint16m8_t v4;
  vuint16m8_t v5;
} vuint16m8x5_t;

typedef struct {
  vuint16m8_t v1;
  vuint16m8_t v2;
  vuint16m8_t v3;
  vuint16m8_t v4;
  vuint16m8_t v5;
  vuint16m8_t v6;
} vuint16m8x6_t;

typedef struct {
  vuint16m8_t v1;
  vuint16m8_t v2;
  vuint16m8_t v3;
  vuint16m8_t v4;
  vuint16m8_t v5;
  vuint16m8_t v6;
  vuint16m8_t v7;
} vuint16m8x7_t;

typedef struct {
  vuint16m8_t v1;
  vuint16m8_t v2;
  vuint16m8_t v3;
  vuint16m8_t v4;
  vuint16m8_t v5;
  vuint16m8_t v6;
  vuint16m8_t v7;
  vuint16m8_t v8;
} vuint16m8x8_t;

typedef struct {
  vuint32m1_t v1;
  vuint32m1_t v2;
} vuint32m1x2_t;

typedef struct {
  vuint32m1_t v1;
  vuint32m1_t v2;
  vuint32m1_t v3;
} vuint32m1x3_t;

typedef struct {
  vuint32m1_t v1;
  vuint32m1_t v2;
  vuint32m1_t v3;
  vuint32m1_t v4;
} vuint32m1x4_t;

typedef struct {
  vuint32m1_t v1;
  vuint32m1_t v2;
  vuint32m1_t v3;
  vuint32m1_t v4;
  vuint32m1_t v5;
} vuint32m1x5_t;

typedef struct {
  vuint32m1_t v1;
  vuint32m1_t v2;
  vuint32m1_t v3;
  vuint32m1_t v4;
  vuint32m1_t v5;
  vuint32m1_t v6;
} vuint32m1x6_t;

typedef struct {
  vuint32m1_t v1;
  vuint32m1_t v2;
  vuint32m1_t v3;
  vuint32m1_t v4;
  vuint32m1_t v5;
  vuint32m1_t v6;
  vuint32m1_t v7;
} vuint32m1x7_t;

typedef struct {
  vuint32m1_t v1;
  vuint32m1_t v2;
  vuint32m1_t v3;
  vuint32m1_t v4;
  vuint32m1_t v5;
  vuint32m1_t v6;
  vuint32m1_t v7;
  vuint32m1_t v8;
} vuint32m1x8_t;

typedef struct {
  vuint32m2_t v1;
  vuint32m2_t v2;
} vuint32m2x2_t;

typedef struct {
  vuint32m2_t v1;
  vuint32m2_t v2;
  vuint32m2_t v3;
} vuint32m2x3_t;

typedef struct {
  vuint32m2_t v1;
  vuint32m2_t v2;
  vuint32m2_t v3;
  vuint32m2_t v4;
} vuint32m2x4_t;

typedef struct {
  vuint32m2_t v1;
  vuint32m2_t v2;
  vuint32m2_t v3;
  vuint32m2_t v4;
  vuint32m2_t v5;
} vuint32m2x5_t;

typedef struct {
  vuint32m2_t v1;
  vuint32m2_t v2;
  vuint32m2_t v3;
  vuint32m2_t v4;
  vuint32m2_t v5;
  vuint32m2_t v6;
} vuint32m2x6_t;

typedef struct {
  vuint32m2_t v1;
  vuint32m2_t v2;
  vuint32m2_t v3;
  vuint32m2_t v4;
  vuint32m2_t v5;
  vuint32m2_t v6;
  vuint32m2_t v7;
} vuint32m2x7_t;

typedef struct {
  vuint32m2_t v1;
  vuint32m2_t v2;
  vuint32m2_t v3;
  vuint32m2_t v4;
  vuint32m2_t v5;
  vuint32m2_t v6;
  vuint32m2_t v7;
  vuint32m2_t v8;
} vuint32m2x8_t;

typedef struct {
  vuint32m4_t v1;
  vuint32m4_t v2;
} vuint32m4x2_t;

typedef struct {
  vuint32m4_t v1;
  vuint32m4_t v2;
  vuint32m4_t v3;
} vuint32m4x3_t;

typedef struct {
  vuint32m4_t v1;
  vuint32m4_t v2;
  vuint32m4_t v3;
  vuint32m4_t v4;
} vuint32m4x4_t;

typedef struct {
  vuint32m4_t v1;
  vuint32m4_t v2;
  vuint32m4_t v3;
  vuint32m4_t v4;
  vuint32m4_t v5;
} vuint32m4x5_t;

typedef struct {
  vuint32m4_t v1;
  vuint32m4_t v2;
  vuint32m4_t v3;
  vuint32m4_t v4;
  vuint32m4_t v5;
  vuint32m4_t v6;
} vuint32m4x6_t;

typedef struct {
  vuint32m4_t v1;
  vuint32m4_t v2;
  vuint32m4_t v3;
  vuint32m4_t v4;
  vuint32m4_t v5;
  vuint32m4_t v6;
  vuint32m4_t v7;
} vuint32m4x7_t;

typedef struct {
  vuint32m4_t v1;
  vuint32m4_t v2;
  vuint32m4_t v3;
  vuint32m4_t v4;
  vuint32m4_t v5;
  vuint32m4_t v6;
  vuint32m4_t v7;
  vuint32m4_t v8;
} vuint32m4x8_t;

typedef struct {
  vuint32m8_t v1;
  vuint32m8_t v2;
} vuint32m8x2_t;

typedef struct {
  vuint32m8_t v1;
  vuint32m8_t v2;
  vuint32m8_t v3;
} vuint32m8x3_t;

typedef struct {
  vuint32m8_t v1;
  vuint32m8_t v2;
  vuint32m8_t v3;
  vuint32m8_t v4;
} vuint32m8x4_t;

typedef struct {
  vuint32m8_t v1;
  vuint32m8_t v2;
  vuint32m8_t v3;
  vuint32m8_t v4;
  vuint32m8_t v5;
} vuint32m8x5_t;

typedef struct {
  vuint32m8_t v1;
  vuint32m8_t v2;
  vuint32m8_t v3;
  vuint32m8_t v4;
  vuint32m8_t v5;
  vuint32m8_t v6;
} vuint32m8x6_t;

typedef struct {
  vuint32m8_t v1;
  vuint32m8_t v2;
  vuint32m8_t v3;
  vuint32m8_t v4;
  vuint32m8_t v5;
  vuint32m8_t v6;
  vuint32m8_t v7;
} vuint32m8x7_t;

typedef struct {
  vuint32m8_t v1;
  vuint32m8_t v2;
  vuint32m8_t v3;
  vuint32m8_t v4;
  vuint32m8_t v5;
  vuint32m8_t v6;
  vuint32m8_t v7;
  vuint32m8_t v8;
} vuint32m8x8_t;

typedef struct {
  vuint64m1_t v1;
  vuint64m1_t v2;
} vuint64m1x2_t;

typedef struct {
  vuint64m1_t v1;
  vuint64m1_t v2;
  vuint64m1_t v3;
} vuint64m1x3_t;

typedef struct {
  vuint64m1_t v1;
  vuint64m1_t v2;
  vuint64m1_t v3;
  vuint64m1_t v4;
} vuint64m1x4_t;

typedef struct {
  vuint64m1_t v1;
  vuint64m1_t v2;
  vuint64m1_t v3;
  vuint64m1_t v4;
  vuint64m1_t v5;
} vuint64m1x5_t;

typedef struct {
  vuint64m1_t v1;
  vuint64m1_t v2;
  vuint64m1_t v3;
  vuint64m1_t v4;
  vuint64m1_t v5;
  vuint64m1_t v6;
} vuint64m1x6_t;

typedef struct {
  vuint64m1_t v1;
  vuint64m1_t v2;
  vuint64m1_t v3;
  vuint64m1_t v4;
  vuint64m1_t v5;
  vuint64m1_t v6;
  vuint64m1_t v7;
} vuint64m1x7_t;

typedef struct {
  vuint64m1_t v1;
  vuint64m1_t v2;
  vuint64m1_t v3;
  vuint64m1_t v4;
  vuint64m1_t v5;
  vuint64m1_t v6;
  vuint64m1_t v7;
  vuint64m1_t v8;
} vuint64m1x8_t;

typedef struct {
  vuint64m2_t v1;
  vuint64m2_t v2;
} vuint64m2x2_t;

typedef struct {
  vuint64m2_t v1;
  vuint64m2_t v2;
  vuint64m2_t v3;
} vuint64m2x3_t;

typedef struct {
  vuint64m2_t v1;
  vuint64m2_t v2;
  vuint64m2_t v3;
  vuint64m2_t v4;
} vuint64m2x4_t;

typedef struct {
  vuint64m2_t v1;
  vuint64m2_t v2;
  vuint64m2_t v3;
  vuint64m2_t v4;
  vuint64m2_t v5;
} vuint64m2x5_t;

typedef struct {
  vuint64m2_t v1;
  vuint64m2_t v2;
  vuint64m2_t v3;
  vuint64m2_t v4;
  vuint64m2_t v5;
  vuint64m2_t v6;
} vuint64m2x6_t;

typedef struct {
  vuint64m2_t v1;
  vuint64m2_t v2;
  vuint64m2_t v3;
  vuint64m2_t v4;
  vuint64m2_t v5;
  vuint64m2_t v6;
  vuint64m2_t v7;
} vuint64m2x7_t;

typedef struct {
  vuint64m2_t v1;
  vuint64m2_t v2;
  vuint64m2_t v3;
  vuint64m2_t v4;
  vuint64m2_t v5;
  vuint64m2_t v6;
  vuint64m2_t v7;
  vuint64m2_t v8;
} vuint64m2x8_t;

typedef struct {
  vuint64m4_t v1;
  vuint64m4_t v2;
} vuint64m4x2_t;

typedef struct {
  vuint64m4_t v1;
  vuint64m4_t v2;
  vuint64m4_t v3;
} vuint64m4x3_t;

typedef struct {
  vuint64m4_t v1;
  vuint64m4_t v2;
  vuint64m4_t v3;
  vuint64m4_t v4;
} vuint64m4x4_t;

typedef struct {
  vuint64m4_t v1;
  vuint64m4_t v2;
  vuint64m4_t v3;
  vuint64m4_t v4;
  vuint64m4_t v5;
} vuint64m4x5_t;

typedef struct {
  vuint64m4_t v1;
  vuint64m4_t v2;
  vuint64m4_t v3;
  vuint64m4_t v4;
  vuint64m4_t v5;
  vuint64m4_t v6;
} vuint64m4x6_t;

typedef struct {
  vuint64m4_t v1;
  vuint64m4_t v2;
  vuint64m4_t v3;
  vuint64m4_t v4;
  vuint64m4_t v5;
  vuint64m4_t v6;
  vuint64m4_t v7;
} vuint64m4x7_t;

typedef struct {
  vuint64m4_t v1;
  vuint64m4_t v2;
  vuint64m4_t v3;
  vuint64m4_t v4;
  vuint64m4_t v5;
  vuint64m4_t v6;
  vuint64m4_t v7;
  vuint64m4_t v8;
} vuint64m4x8_t;

typedef struct {
  vuint64m8_t v1;
  vuint64m8_t v2;
} vuint64m8x2_t;

typedef struct {
  vuint64m8_t v1;
  vuint64m8_t v2;
  vuint64m8_t v3;
} vuint64m8x3_t;

typedef struct {
  vuint64m8_t v1;
  vuint64m8_t v2;
  vuint64m8_t v3;
  vuint64m8_t v4;
} vuint64m8x4_t;

typedef struct {
  vuint64m8_t v1;
  vuint64m8_t v2;
  vuint64m8_t v3;
  vuint64m8_t v4;
  vuint64m8_t v5;
} vuint64m8x5_t;

typedef struct {
  vuint64m8_t v1;
  vuint64m8_t v2;
  vuint64m8_t v3;
  vuint64m8_t v4;
  vuint64m8_t v5;
  vuint64m8_t v6;
} vuint64m8x6_t;

typedef struct {
  vuint64m8_t v1;
  vuint64m8_t v2;
  vuint64m8_t v3;
  vuint64m8_t v4;
  vuint64m8_t v5;
  vuint64m8_t v6;
  vuint64m8_t v7;
} vuint64m8x7_t;

typedef struct {
  vuint64m8_t v1;
  vuint64m8_t v2;
  vuint64m8_t v3;
  vuint64m8_t v4;
  vuint64m8_t v5;
  vuint64m8_t v6;
  vuint64m8_t v7;
  vuint64m8_t v8;
} vuint64m8x8_t;

typedef struct {
  vfloat16m1_t v1;
  vfloat16m1_t v2;
} vfloat16m1x2_t;

typedef struct {
  vfloat16m1_t v1;
  vfloat16m1_t v2;
  vfloat16m1_t v3;
} vfloat16m1x3_t;

typedef struct {
  vfloat16m1_t v1;
  vfloat16m1_t v2;
  vfloat16m1_t v3;
  vfloat16m1_t v4;
} vfloat16m1x4_t;

typedef struct {
  vfloat16m1_t v1;
  vfloat16m1_t v2;
  vfloat16m1_t v3;
  vfloat16m1_t v4;
  vfloat16m1_t v5;
} vfloat16m1x5_t;

typedef struct {
  vfloat16m1_t v1;
  vfloat16m1_t v2;
  vfloat16m1_t v3;
  vfloat16m1_t v4;
  vfloat16m1_t v5;
  vfloat16m1_t v6;
} vfloat16m1x6_t;

typedef struct {
  vfloat16m1_t v1;
  vfloat16m1_t v2;
  vfloat16m1_t v3;
  vfloat16m1_t v4;
  vfloat16m1_t v5;
  vfloat16m1_t v6;
  vfloat16m1_t v7;
} vfloat16m1x7_t;

typedef struct {
  vfloat16m1_t v1;
  vfloat16m1_t v2;
  vfloat16m1_t v3;
  vfloat16m1_t v4;
  vfloat16m1_t v5;
  vfloat16m1_t v6;
  vfloat16m1_t v7;
  vfloat16m1_t v8;
} vfloat16m1x8_t;

typedef struct {
  vfloat16m2_t v1;
  vfloat16m2_t v2;
} vfloat16m2x2_t;

typedef struct {
  vfloat16m2_t v1;
  vfloat16m2_t v2;
  vfloat16m2_t v3;
} vfloat16m2x3_t;

typedef struct {
  vfloat16m2_t v1;
  vfloat16m2_t v2;
  vfloat16m2_t v3;
  vfloat16m2_t v4;
} vfloat16m2x4_t;

typedef struct {
  vfloat16m2_t v1;
  vfloat16m2_t v2;
  vfloat16m2_t v3;
  vfloat16m2_t v4;
  vfloat16m2_t v5;
} vfloat16m2x5_t;

typedef struct {
  vfloat16m2_t v1;
  vfloat16m2_t v2;
  vfloat16m2_t v3;
  vfloat16m2_t v4;
  vfloat16m2_t v5;
  vfloat16m2_t v6;
} vfloat16m2x6_t;

typedef struct {
  vfloat16m2_t v1;
  vfloat16m2_t v2;
  vfloat16m2_t v3;
  vfloat16m2_t v4;
  vfloat16m2_t v5;
  vfloat16m2_t v6;
  vfloat16m2_t v7;
} vfloat16m2x7_t;

typedef struct {
  vfloat16m2_t v1;
  vfloat16m2_t v2;
  vfloat16m2_t v3;
  vfloat16m2_t v4;
  vfloat16m2_t v5;
  vfloat16m2_t v6;
  vfloat16m2_t v7;
  vfloat16m2_t v8;
} vfloat16m2x8_t;

typedef struct {
  vfloat16m4_t v1;
  vfloat16m4_t v2;
} vfloat16m4x2_t;

typedef struct {
  vfloat16m4_t v1;
  vfloat16m4_t v2;
  vfloat16m4_t v3;
} vfloat16m4x3_t;

typedef struct {
  vfloat16m4_t v1;
  vfloat16m4_t v2;
  vfloat16m4_t v3;
  vfloat16m4_t v4;
} vfloat16m4x4_t;

typedef struct {
  vfloat16m4_t v1;
  vfloat16m4_t v2;
  vfloat16m4_t v3;
  vfloat16m4_t v4;
  vfloat16m4_t v5;
} vfloat16m4x5_t;

typedef struct {
  vfloat16m4_t v1;
  vfloat16m4_t v2;
  vfloat16m4_t v3;
  vfloat16m4_t v4;
  vfloat16m4_t v5;
  vfloat16m4_t v6;
} vfloat16m4x6_t;

typedef struct {
  vfloat16m4_t v1;
  vfloat16m4_t v2;
  vfloat16m4_t v3;
  vfloat16m4_t v4;
  vfloat16m4_t v5;
  vfloat16m4_t v6;
  vfloat16m4_t v7;
} vfloat16m4x7_t;

typedef struct {
  vfloat16m4_t v1;
  vfloat16m4_t v2;
  vfloat16m4_t v3;
  vfloat16m4_t v4;
  vfloat16m4_t v5;
  vfloat16m4_t v6;
  vfloat16m4_t v7;
  vfloat16m4_t v8;
} vfloat16m4x8_t;

typedef struct {
  vfloat16m8_t v1;
  vfloat16m8_t v2;
} vfloat16m8x2_t;

typedef struct {
  vfloat16m8_t v1;
  vfloat16m8_t v2;
  vfloat16m8_t v3;
} vfloat16m8x3_t;

typedef struct {
  vfloat16m8_t v1;
  vfloat16m8_t v2;
  vfloat16m8_t v3;
  vfloat16m8_t v4;
} vfloat16m8x4_t;

typedef struct {
  vfloat16m8_t v1;
  vfloat16m8_t v2;
  vfloat16m8_t v3;
  vfloat16m8_t v4;
  vfloat16m8_t v5;
} vfloat16m8x5_t;

typedef struct {
  vfloat16m8_t v1;
  vfloat16m8_t v2;
  vfloat16m8_t v3;
  vfloat16m8_t v4;
  vfloat16m8_t v5;
  vfloat16m8_t v6;
} vfloat16m8x6_t;

typedef struct {
  vfloat16m8_t v1;
  vfloat16m8_t v2;
  vfloat16m8_t v3;
  vfloat16m8_t v4;
  vfloat16m8_t v5;
  vfloat16m8_t v6;
  vfloat16m8_t v7;
} vfloat16m8x7_t;

typedef struct {
  vfloat16m8_t v1;
  vfloat16m8_t v2;
  vfloat16m8_t v3;
  vfloat16m8_t v4;
  vfloat16m8_t v5;
  vfloat16m8_t v6;
  vfloat16m8_t v7;
  vfloat16m8_t v8;
} vfloat16m8x8_t;

typedef struct {
  vfloat32m1_t v1;
  vfloat32m1_t v2;
} vfloat32m1x2_t;

typedef struct {
  vfloat32m1_t v1;
  vfloat32m1_t v2;
  vfloat32m1_t v3;
} vfloat32m1x3_t;

typedef struct {
  vfloat32m1_t v1;
  vfloat32m1_t v2;
  vfloat32m1_t v3;
  vfloat32m1_t v4;
} vfloat32m1x4_t;

typedef struct {
  vfloat32m1_t v1;
  vfloat32m1_t v2;
  vfloat32m1_t v3;
  vfloat32m1_t v4;
  vfloat32m1_t v5;
} vfloat32m1x5_t;

typedef struct {
  vfloat32m1_t v1;
  vfloat32m1_t v2;
  vfloat32m1_t v3;
  vfloat32m1_t v4;
  vfloat32m1_t v5;
  vfloat32m1_t v6;
} vfloat32m1x6_t;

typedef struct {
  vfloat32m1_t v1;
  vfloat32m1_t v2;
  vfloat32m1_t v3;
  vfloat32m1_t v4;
  vfloat32m1_t v5;
  vfloat32m1_t v6;
  vfloat32m1_t v7;
} vfloat32m1x7_t;

typedef struct {
  vfloat32m1_t v1;
  vfloat32m1_t v2;
  vfloat32m1_t v3;
  vfloat32m1_t v4;
  vfloat32m1_t v5;
  vfloat32m1_t v6;
  vfloat32m1_t v7;
  vfloat32m1_t v8;
} vfloat32m1x8_t;

typedef struct {
  vfloat32m2_t v1;
  vfloat32m2_t v2;
} vfloat32m2x2_t;

typedef struct {
  vfloat32m2_t v1;
  vfloat32m2_t v2;
  vfloat32m2_t v3;
} vfloat32m2x3_t;

typedef struct {
  vfloat32m2_t v1;
  vfloat32m2_t v2;
  vfloat32m2_t v3;
  vfloat32m2_t v4;
} vfloat32m2x4_t;

typedef struct {
  vfloat32m2_t v1;
  vfloat32m2_t v2;
  vfloat32m2_t v3;
  vfloat32m2_t v4;
  vfloat32m2_t v5;
} vfloat32m2x5_t;

typedef struct {
  vfloat32m2_t v1;
  vfloat32m2_t v2;
  vfloat32m2_t v3;
  vfloat32m2_t v4;
  vfloat32m2_t v5;
  vfloat32m2_t v6;
} vfloat32m2x6_t;

typedef struct {
  vfloat32m2_t v1;
  vfloat32m2_t v2;
  vfloat32m2_t v3;
  vfloat32m2_t v4;
  vfloat32m2_t v5;
  vfloat32m2_t v6;
  vfloat32m2_t v7;
} vfloat32m2x7_t;

typedef struct {
  vfloat32m2_t v1;
  vfloat32m2_t v2;
  vfloat32m2_t v3;
  vfloat32m2_t v4;
  vfloat32m2_t v5;
  vfloat32m2_t v6;
  vfloat32m2_t v7;
  vfloat32m2_t v8;
} vfloat32m2x8_t;

typedef struct {
  vfloat32m4_t v1;
  vfloat32m4_t v2;
} vfloat32m4x2_t;

typedef struct {
  vfloat32m4_t v1;
  vfloat32m4_t v2;
  vfloat32m4_t v3;
} vfloat32m4x3_t;

typedef struct {
  vfloat32m4_t v1;
  vfloat32m4_t v2;
  vfloat32m4_t v3;
  vfloat32m4_t v4;
} vfloat32m4x4_t;

typedef struct {
  vfloat32m4_t v1;
  vfloat32m4_t v2;
  vfloat32m4_t v3;
  vfloat32m4_t v4;
  vfloat32m4_t v5;
} vfloat32m4x5_t;

typedef struct {
  vfloat32m4_t v1;
  vfloat32m4_t v2;
  vfloat32m4_t v3;
  vfloat32m4_t v4;
  vfloat32m4_t v5;
  vfloat32m4_t v6;
} vfloat32m4x6_t;

typedef struct {
  vfloat32m4_t v1;
  vfloat32m4_t v2;
  vfloat32m4_t v3;
  vfloat32m4_t v4;
  vfloat32m4_t v5;
  vfloat32m4_t v6;
  vfloat32m4_t v7;
} vfloat32m4x7_t;

typedef struct {
  vfloat32m4_t v1;
  vfloat32m4_t v2;
  vfloat32m4_t v3;
  vfloat32m4_t v4;
  vfloat32m4_t v5;
  vfloat32m4_t v6;
  vfloat32m4_t v7;
  vfloat32m4_t v8;
} vfloat32m4x8_t;

typedef struct {
  vfloat32m8_t v1;
  vfloat32m8_t v2;
} vfloat32m8x2_t;

typedef struct {
  vfloat32m8_t v1;
  vfloat32m8_t v2;
  vfloat32m8_t v3;
} vfloat32m8x3_t;

typedef struct {
  vfloat32m8_t v1;
  vfloat32m8_t v2;
  vfloat32m8_t v3;
  vfloat32m8_t v4;
} vfloat32m8x4_t;

typedef struct {
  vfloat32m8_t v1;
  vfloat32m8_t v2;
  vfloat32m8_t v3;
  vfloat32m8_t v4;
  vfloat32m8_t v5;
} vfloat32m8x5_t;

typedef struct {
  vfloat32m8_t v1;
  vfloat32m8_t v2;
  vfloat32m8_t v3;
  vfloat32m8_t v4;
  vfloat32m8_t v5;
  vfloat32m8_t v6;
} vfloat32m8x6_t;

typedef struct {
  vfloat32m8_t v1;
  vfloat32m8_t v2;
  vfloat32m8_t v3;
  vfloat32m8_t v4;
  vfloat32m8_t v5;
  vfloat32m8_t v6;
  vfloat32m8_t v7;
} vfloat32m8x7_t;

typedef struct {
  vfloat32m8_t v1;
  vfloat32m8_t v2;
  vfloat32m8_t v3;
  vfloat32m8_t v4;
  vfloat32m8_t v5;
  vfloat32m8_t v6;
  vfloat32m8_t v7;
  vfloat32m8_t v8;
} vfloat32m8x8_t;

typedef struct {
  vfloat64m1_t v1;
  vfloat64m1_t v2;
} vfloat64m1x2_t;

typedef struct {
  vfloat64m1_t v1;
  vfloat64m1_t v2;
  vfloat64m1_t v3;
} vfloat64m1x3_t;

typedef struct {
  vfloat64m1_t v1;
  vfloat64m1_t v2;
  vfloat64m1_t v3;
  vfloat64m1_t v4;
} vfloat64m1x4_t;

typedef struct {
  vfloat64m1_t v1;
  vfloat64m1_t v2;
  vfloat64m1_t v3;
  vfloat64m1_t v4;
  vfloat64m1_t v5;
} vfloat64m1x5_t;

typedef struct {
  vfloat64m1_t v1;
  vfloat64m1_t v2;
  vfloat64m1_t v3;
  vfloat64m1_t v4;
  vfloat64m1_t v5;
  vfloat64m1_t v6;
} vfloat64m1x6_t;

typedef struct {
  vfloat64m1_t v1;
  vfloat64m1_t v2;
  vfloat64m1_t v3;
  vfloat64m1_t v4;
  vfloat64m1_t v5;
  vfloat64m1_t v6;
  vfloat64m1_t v7;
} vfloat64m1x7_t;

typedef struct {
  vfloat64m1_t v1;
  vfloat64m1_t v2;
  vfloat64m1_t v3;
  vfloat64m1_t v4;
  vfloat64m1_t v5;
  vfloat64m1_t v6;
  vfloat64m1_t v7;
  vfloat64m1_t v8;
} vfloat64m1x8_t;

typedef struct {
  vfloat64m2_t v1;
  vfloat64m2_t v2;
} vfloat64m2x2_t;

typedef struct {
  vfloat64m2_t v1;
  vfloat64m2_t v2;
  vfloat64m2_t v3;
} vfloat64m2x3_t;

typedef struct {
  vfloat64m2_t v1;
  vfloat64m2_t v2;
  vfloat64m2_t v3;
  vfloat64m2_t v4;
} vfloat64m2x4_t;

typedef struct {
  vfloat64m2_t v1;
  vfloat64m2_t v2;
  vfloat64m2_t v3;
  vfloat64m2_t v4;
  vfloat64m2_t v5;
} vfloat64m2x5_t;

typedef struct {
  vfloat64m2_t v1;
  vfloat64m2_t v2;
  vfloat64m2_t v3;
  vfloat64m2_t v4;
  vfloat64m2_t v5;
  vfloat64m2_t v6;
} vfloat64m2x6_t;

typedef struct {
  vfloat64m2_t v1;
  vfloat64m2_t v2;
  vfloat64m2_t v3;
  vfloat64m2_t v4;
  vfloat64m2_t v5;
  vfloat64m2_t v6;
  vfloat64m2_t v7;
} vfloat64m2x7_t;

typedef struct {
  vfloat64m2_t v1;
  vfloat64m2_t v2;
  vfloat64m2_t v3;
  vfloat64m2_t v4;
  vfloat64m2_t v5;
  vfloat64m2_t v6;
  vfloat64m2_t v7;
  vfloat64m2_t v8;
} vfloat64m2x8_t;

typedef struct {
  vfloat64m4_t v1;
  vfloat64m4_t v2;
} vfloat64m4x2_t;

typedef struct {
  vfloat64m4_t v1;
  vfloat64m4_t v2;
  vfloat64m4_t v3;
} vfloat64m4x3_t;

typedef struct {
  vfloat64m4_t v1;
  vfloat64m4_t v2;
  vfloat64m4_t v3;
  vfloat64m4_t v4;
} vfloat64m4x4_t;

typedef struct {
  vfloat64m4_t v1;
  vfloat64m4_t v2;
  vfloat64m4_t v3;
  vfloat64m4_t v4;
  vfloat64m4_t v5;
} vfloat64m4x5_t;

typedef struct {
  vfloat64m4_t v1;
  vfloat64m4_t v2;
  vfloat64m4_t v3;
  vfloat64m4_t v4;
  vfloat64m4_t v5;
  vfloat64m4_t v6;
} vfloat64m4x6_t;

typedef struct {
  vfloat64m4_t v1;
  vfloat64m4_t v2;
  vfloat64m4_t v3;
  vfloat64m4_t v4;
  vfloat64m4_t v5;
  vfloat64m4_t v6;
  vfloat64m4_t v7;
} vfloat64m4x7_t;

typedef struct {
  vfloat64m4_t v1;
  vfloat64m4_t v2;
  vfloat64m4_t v3;
  vfloat64m4_t v4;
  vfloat64m4_t v5;
  vfloat64m4_t v6;
  vfloat64m4_t v7;
  vfloat64m4_t v8;
} vfloat64m4x8_t;

typedef struct {
  vfloat64m8_t v1;
  vfloat64m8_t v2;
} vfloat64m8x2_t;

typedef struct {
  vfloat64m8_t v1;
  vfloat64m8_t v2;
  vfloat64m8_t v3;
} vfloat64m8x3_t;

typedef struct {
  vfloat64m8_t v1;
  vfloat64m8_t v2;
  vfloat64m8_t v3;
  vfloat64m8_t v4;
} vfloat64m8x4_t;

typedef struct {
  vfloat64m8_t v1;
  vfloat64m8_t v2;
  vfloat64m8_t v3;
  vfloat64m8_t v4;
  vfloat64m8_t v5;
} vfloat64m8x5_t;

typedef struct {
  vfloat64m8_t v1;
  vfloat64m8_t v2;
  vfloat64m8_t v3;
  vfloat64m8_t v4;
  vfloat64m8_t v5;
  vfloat64m8_t v6;
} vfloat64m8x6_t;

typedef struct {
  vfloat64m8_t v1;
  vfloat64m8_t v2;
  vfloat64m8_t v3;
  vfloat64m8_t v4;
  vfloat64m8_t v5;
  vfloat64m8_t v6;
  vfloat64m8_t v7;
} vfloat64m8x7_t;

typedef struct {
  vfloat64m8_t v1;
  vfloat64m8_t v2;
  vfloat64m8_t v3;
  vfloat64m8_t v4;
  vfloat64m8_t v5;
  vfloat64m8_t v6;
  vfloat64m8_t v7;
  vfloat64m8_t v8;
} vfloat64m8x8_t;

typedef __attribute__((riscv_mask_type(1))) bool vbool1_t;

typedef __attribute__((riscv_mask_type(2))) bool vbool2_t;

typedef __attribute__((riscv_mask_type(4))) bool vbool4_t;

typedef __attribute__((riscv_mask_type(8))) bool vbool8_t;

typedef __attribute__((riscv_mask_type(16))) bool vbool16_t;

typedef __attribute__((riscv_mask_type(32))) bool vbool32_t;

typedef __attribute__((riscv_mask_type(64))) bool vbool64_t; 


// Intrinsic vsetvl

static __attribute__((nothrow, always_inline))
size_t vsetvl(size_t arg1, size_t arg2) {
  return __builtin_riscv_vsetvl(arg1, arg2);
}

// Intrinsic vle%s_v_%b%sm%l

static __attribute__((nothrow, always_inline))
vint8m1_t vle8_v_i8m1(const int8_t* arg1) {
  return __builtin_riscv_vle8_v_i8m1(arg1);
}

static __attribute__((nothrow, always_inline))
vint8m2_t vle8_v_i8m2(const int8_t* arg1) {
  return __builtin_riscv_vle8_v_i8m2(arg1);
}

static __attribute__((nothrow, always_inline))
vint8m4_t vle8_v_i8m4(const int8_t* arg1) {
  return __builtin_riscv_vle8_v_i8m4(arg1);
}

static __attribute__((nothrow, always_inline))
vint8m8_t vle8_v_i8m8(const int8_t* arg1) {
  return __builtin_riscv_vle8_v_i8m8(arg1);
}

static __attribute__((nothrow, always_inline))
vint16m1_t vle16_v_i16m1(const int16_t* arg1) {
  return __builtin_riscv_vle16_v_i16m1(arg1);
}

static __attribute__((nothrow, always_inline))
vint16m2_t vle16_v_i16m2(const int16_t* arg1) {
  return __builtin_riscv_vle16_v_i16m2(arg1);
}

static __attribute__((nothrow, always_inline))
vint16m4_t vle16_v_i16m4(const int16_t* arg1) {
  return __builtin_riscv_vle16_v_i16m4(arg1);
}

static __attribute__((nothrow, always_inline))
vint16m8_t vle16_v_i16m8(const int16_t* arg1) {
  return __builtin_riscv_vle16_v_i16m8(arg1);
}

static __attribute__((nothrow, always_inline))
vint32m1_t vle32_v_i32m1(const int32_t* arg1) {
  return __builtin_riscv_vle32_v_i32m1(arg1);
}

static __attribute__((nothrow, always_inline))
vint32m2_t vle32_v_i32m2(const int32_t* arg1) {
  return __builtin_riscv_vle32_v_i32m2(arg1);
}

static __attribute__((nothrow, always_inline))
vint32m4_t vle32_v_i32m4(const int32_t* arg1) {
  return __builtin_riscv_vle32_v_i32m4(arg1);
}

static __attribute__((nothrow, always_inline))
vint32m8_t vle32_v_i32m8(const int32_t* arg1) {
  return __builtin_riscv_vle32_v_i32m8(arg1);
}

static __attribute__((nothrow, always_inline))
vint64m1_t vle64_v_i64m1(const int64_t* arg1) {
  return __builtin_riscv_vle64_v_i64m1(arg1);
}

static __attribute__((nothrow, always_inline))
vint64m2_t vle64_v_i64m2(const int64_t* arg1) {
  return __builtin_riscv_vle64_v_i64m2(arg1);
}

static __attribute__((nothrow, always_inline))
vint64m4_t vle64_v_i64m4(const int64_t* arg1) {
  return __builtin_riscv_vle64_v_i64m4(arg1);
}

static __attribute__((nothrow, always_inline))
vint64m8_t vle64_v_i64m8(const int64_t* arg1) {
  return __builtin_riscv_vle64_v_i64m8(arg1);
}

static __attribute__((nothrow, always_inline))
vuint8m1_t vle8_v_u8m1(const uint8_t* arg1) {
  return __builtin_riscv_vle8_v_u8m1(arg1);
}

static __attribute__((nothrow, always_inline))
vuint8m2_t vle8_v_u8m2(const uint8_t* arg1) {
  return __builtin_riscv_vle8_v_u8m2(arg1);
}

static __attribute__((nothrow, always_inline))
vuint8m4_t vle8_v_u8m4(const uint8_t* arg1) {
  return __builtin_riscv_vle8_v_u8m4(arg1);
}

static __attribute__((nothrow, always_inline))
vuint8m8_t vle8_v_u8m8(const uint8_t* arg1) {
  return __builtin_riscv_vle8_v_u8m8(arg1);
}

static __attribute__((nothrow, always_inline))
vuint16m1_t vle16_v_u16m1(const uint16_t* arg1) {
  return __builtin_riscv_vle16_v_u16m1(arg1);
}

static __attribute__((nothrow, always_inline))
vuint16m2_t vle16_v_u16m2(const uint16_t* arg1) {
  return __builtin_riscv_vle16_v_u16m2(arg1);
}

static __attribute__((nothrow, always_inline))
vuint16m4_t vle16_v_u16m4(const uint16_t* arg1) {
  return __builtin_riscv_vle16_v_u16m4(arg1);
}

static __attribute__((nothrow, always_inline))
vuint16m8_t vle16_v_u16m8(const uint16_t* arg1) {
  return __builtin_riscv_vle16_v_u16m8(arg1);
}

static __attribute__((nothrow, always_inline))
vuint32m1_t vle32_v_u32m1(const uint32_t* arg1) {
  return __builtin_riscv_vle32_v_u32m1(arg1);
}

static __attribute__((nothrow, always_inline))
vuint32m2_t vle32_v_u32m2(const uint32_t* arg1) {
  return __builtin_riscv_vle32_v_u32m2(arg1);
}

static __attribute__((nothrow, always_inline))
vuint32m4_t vle32_v_u32m4(const uint32_t* arg1) {
  return __builtin_riscv_vle32_v_u32m4(arg1);
}

static __attribute__((nothrow, always_inline))
vuint32m8_t vle32_v_u32m8(const uint32_t* arg1) {
  return __builtin_riscv_vle32_v_u32m8(arg1);
}

static __attribute__((nothrow, always_inline))
vuint64m1_t vle64_v_u64m1(const uint64_t* arg1) {
  return __builtin_riscv_vle64_v_u64m1(arg1);
}

static __attribute__((nothrow, always_inline))
vuint64m2_t vle64_v_u64m2(const uint64_t* arg1) {
  return __builtin_riscv_vle64_v_u64m2(arg1);
}

static __attribute__((nothrow, always_inline))
vuint64m4_t vle64_v_u64m4(const uint64_t* arg1) {
  return __builtin_riscv_vle64_v_u64m4(arg1);
}

static __attribute__((nothrow, always_inline))
vuint64m8_t vle64_v_u64m8(const uint64_t* arg1) {
  return __builtin_riscv_vle64_v_u64m8(arg1);
}

static __attribute__((nothrow, always_inline))
vfloat16m1_t vle16_v_f16m1(const _Float16* arg1) {
  return __builtin_riscv_vle16_v_f16m1(arg1);
}

static __attribute__((nothrow, always_inline))
vfloat16m2_t vle16_v_f16m2(const _Float16* arg1) {
  return __builtin_riscv_vle16_v_f16m2(arg1);
}

static __attribute__((nothrow, always_inline))
vfloat16m4_t vle16_v_f16m4(const _Float16* arg1) {
  return __builtin_riscv_vle16_v_f16m4(arg1);
}

static __attribute__((nothrow, always_inline))
vfloat16m8_t vle16_v_f16m8(const _Float16* arg1) {
  return __builtin_riscv_vle16_v_f16m8(arg1);
}

static __attribute__((nothrow, always_inline))
vfloat32m1_t vle32_v_f32m1(const float* arg1) {
  return __builtin_riscv_vle32_v_f32m1(arg1);
}

static __attribute__((nothrow, always_inline))
vfloat32m2_t vle32_v_f32m2(const float* arg1) {
  return __builtin_riscv_vle32_v_f32m2(arg1);
}

static __attribute__((nothrow, always_inline))
vfloat32m4_t vle32_v_f32m4(const float* arg1) {
  return __builtin_riscv_vle32_v_f32m4(arg1);
}

static __attribute__((nothrow, always_inline))
vfloat32m8_t vle32_v_f32m8(const float* arg1) {
  return __builtin_riscv_vle32_v_f32m8(arg1);
}

static __attribute__((nothrow, always_inline))
vfloat64m1_t vle64_v_f64m1(const double* arg1) {
  return __builtin_riscv_vle64_v_f64m1(arg1);
}

static __attribute__((nothrow, always_inline))
vfloat64m2_t vle64_v_f64m2(const double* arg1) {
  return __builtin_riscv_vle64_v_f64m2(arg1);
}

static __attribute__((nothrow, always_inline))
vfloat64m4_t vle64_v_f64m4(const double* arg1) {
  return __builtin_riscv_vle64_v_f64m4(arg1);
}

static __attribute__((nothrow, always_inline))
vfloat64m8_t vle64_v_f64m8(const double* arg1) {
  return __builtin_riscv_vle64_v_f64m8(arg1);
}

#endif
