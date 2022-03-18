
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
// [simd.casts]
// template <class T, size_t N> simd_mask<T> to_compatible(const fixed_size_simd_mask<T, N>&) noexcept;

#include <experimental/simd>
#include <cstdint>

#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;

static_assert(
    std::is_same_v<decltype(ex::to_compatible<int,4>(ex::fixed_size_simd_mask<int,4>())),
                 ex::simd_mask<int>>,
    "");

static_assert(
    !(std::is_same_v<decltype(ex::to_compatible<int,8>(ex::fixed_size_simd_mask<int,8>())),
                 ex::simd_mask<int>>),
    "");

static_assert(
    !(std::is_same_v<decltype(ex::to_compatible<int,15>(ex::fixed_size_simd_mask<int,15>())),
                 ex::simd_mask<int>>),
    "");


int main(int, char**) {
    return 0;
}