//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11, c++14

// <experimental/simd>
//
// [simd.mask.class]
// simd_mask() = default;

#include <cstdint>
#include <experimental/simd>

#include "test_macros.h"


namespace ex = std::experimental::parallelism_v2;

int main() { 
  (void)ex::native_simd_mask<int32_t>();
  static_assert(ex::native_simd_mask<int8_t>().size() > 0, "");
  static_assert(ex::native_simd_mask<int16_t>().size() > 0, "");
  static_assert(ex::native_simd_mask<int32_t>().size() > 0, "");
  static_assert(ex::native_simd_mask<int64_t>().size() > 0, "");
  static_assert(ex::native_simd_mask<uint8_t>().size() > 0, "");
  static_assert(ex::native_simd_mask<uint16_t>().size() > 0, "");
  static_assert(ex::native_simd_mask<uint32_t>().size() > 0, "");
  static_assert(ex::native_simd_mask<uint64_t>().size() > 0, "");
  static_assert(ex::native_simd_mask<char>().size() > 0, "");
  static_assert(ex::native_simd_mask<float>().size() > 0, "");
  static_assert(ex::native_simd_mask<double>().size() > 0, "");

  static_assert(ex::simd_mask<int8_t>().size() > 0, "");
  static_assert(ex::simd_mask<int16_t>().size() > 0, "");
  static_assert(ex::simd_mask<int32_t>().size() > 0, "");
  static_assert(ex::simd_mask<int64_t>().size() > 0, "");
  static_assert(ex::simd_mask<uint8_t>().size() > 0, "");
  static_assert(ex::simd_mask<uint16_t>().size() > 0, "");
  static_assert(ex::simd_mask<uint32_t>().size() > 0, "");
  static_assert(ex::simd_mask<uint64_t>().size() > 0, "");
  static_assert(ex::simd_mask<char>().size() > 0, "");
  static_assert(ex::simd_mask<float>().size() > 0, "");
  static_assert(ex::simd_mask<double>().size() > 0, "");

  static_assert(ex::fixed_size_simd_mask<int8_t, 4>().size() == 4, "");
  static_assert(ex::fixed_size_simd_mask<int16_t, 4>().size() == 4, "");
  static_assert(ex::fixed_size_simd_mask<int32_t, 4>().size() == 4, "");
  static_assert(ex::fixed_size_simd_mask<int64_t, 4>().size() == 4, "");
  static_assert(ex::fixed_size_simd_mask<uint8_t, 4>().size() == 4, "");
  static_assert(ex::fixed_size_simd_mask<uint16_t, 4>().size() == 4, "");
  static_assert(ex::fixed_size_simd_mask<uint32_t, 4>().size() == 4, "");
  static_assert(ex::fixed_size_simd_mask<uint64_t, 4>().size() == 4, "");
  static_assert(ex::fixed_size_simd_mask<int32_t, 5>().size() == 5, "");
  static_assert(ex::fixed_size_simd_mask<int32_t, 1>().size() == 1, "");
  static_assert(ex::fixed_size_simd_mask<char, 32>().size() == 32, "");
  static_assert(ex::fixed_size_simd_mask<float, 4>().size() == 4, "");
  static_assert(ex::fixed_size_simd_mask<double, 4>().size() == 4, "");
  static_assert(ex::fixed_size_simd_mask<int32_t, 4>().size() == 4, "");
 }