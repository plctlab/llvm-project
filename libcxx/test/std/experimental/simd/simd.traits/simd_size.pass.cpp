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
// [simd.traits]
//template <class T, class Abi = simd_abi::compatible<T>> struct simd_size;
//template <class T, class Abi = simd_abi::compatible<T>>
//inline constexpr size_t ex::simd_size_v = ex::simd_size<T, Abi>::value;

#include <cstdint>
#include <experimental/simd>
#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;

static_assert(ex::simd_size<int, ex::simd_abi::fixed_size<4>>::value == 4, "");
static_assert(ex::simd_size<float, ex::simd_abi::fixed_size<4>>::value == 4, "");
static_assert(ex::simd_size<double, ex::simd_abi::fixed_size<4>>::value == 4, "");

static_assert(ex::simd_size<int, ex::simd_abi::scalar>::value == 1, "");
static_assert(ex::simd_size<float, ex::simd_abi::scalar>::value == 1, "");
static_assert(ex::simd_size<double, ex::simd_abi::scalar>::value == 1, "");




static_assert(ex::simd_size_v<int, ex::simd_abi::fixed_size<4>> == 4, "");
static_assert(ex::simd_size_v<float, ex::simd_abi::fixed_size<4>> == 4, "");
static_assert(ex::simd_size_v<double, ex::simd_abi::fixed_size<4>> == 4, "");

static_assert(ex::simd_size_v<int, ex::simd_abi::scalar> == 1, "");
static_assert(ex::simd_size_v<float, ex::simd_abi::scalar> == 1, "");
static_assert(ex::simd_size_v<double, ex::simd_abi::scalar> == 1, "");


int main(int, char**) {
    return 0;
}
