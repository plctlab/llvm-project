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
//template <class T, class Abi>
//fixed_size_simd<T, simd_size_v<T, Abi>> to_fixed_size(const simd<T, Abi>&) noexcept;

#include <experimental/simd>
#include <cstdint>

#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;

static_assert(
    std::is_same_v<decltype(ex::to_fixed_size<int,ex::simd_abi::native<int>>(ex::simd<int,ex::simd_abi::native<int>>())),
                 ex::fixed_size_simd<int,ex::simd_size_v<int,ex::simd_abi::native<int>>>>,
    "");

static_assert(
    std::is_same_v<decltype(ex::to_fixed_size<int,ex::simd_abi::fixed_size<4>>(ex::simd<int,ex::simd_abi::fixed_size<4>>())),
                 ex::fixed_size_simd<int,ex::simd_size_v<int,ex::simd_abi::fixed_size<4>>>>,
    "");

static_assert(
    std::is_same_v<decltype(ex::to_fixed_size<int,ex::simd_abi::scalar>(ex::simd<int,ex::simd_abi::scalar>())),
                 ex::fixed_size_simd<int,ex::simd_size_v<int,ex::simd_abi::scalar>>>,
    "");

int main(int, char**) {
    return 0;
}
