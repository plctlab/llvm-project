// RUN: %clang --target=riscv64-unknown-linux-elf -S -emit-llvm  %s -o - |  FileCheck %s
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <riscv_vector.h>



vint32m1_t  __attribute__((noinline)) testle32(const int32_t* src) {
  return vle32_v_i32m1(src);
}



//vfloat32m1_t  __attribute__((noinline)) testle32_f(const float* src) {
//  return vle32_v_f32m1(src);
//}
