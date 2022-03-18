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
//template <class T, size_t N> native_simd<T> to_native(const fixed_size_simd<T, N>&) noexcept;

#include <experimental/simd>
#include <cstdint>

#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;

static_assert(
    std::is_same_v<decltype(ex::to_native<int,4>(ex::fixed_size_simd<int,4>())),
                 ex::native_simd<int>>,
    "");

static_assert(
    !(std::is_same_v<decltype(ex::to_native<int,8>(ex::fixed_size_simd<int,8>())),
                 ex::native_simd<int>>),
    "");

static_assert(
    !(std::is_same_v<decltype(ex::to_native<int,15>(ex::fixed_size_simd<int,15>())),
                 ex::native_simd<int>>),
    "");


int main(int, char**) {
    return 0;
}

