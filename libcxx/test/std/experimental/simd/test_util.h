//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef TEST_UTIL_H
#define TEST_UTIL_H

#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

template <class F>
void test_simd() {}

template <class F, class Simd, class... Simds>
void test_simd() {
  F{}.template operator()<Simd>();
  test_simd<F, Simds...>();
}

template <class F>
void test_all_simd() {
  using namespace ex;
  using namespace ex::simd_abi;

  // clang-format off
  test_simd<F,
    // public ABIs
    native_simd<int>,
    fixed_size_simd<int, 4>,
    fixed_size_simd<int, 15>,

    // private ABIs
    simd<int, __scalar>,
    simd<int, __vec_ext<4>>
  >();
  // clang-format on
}

#endif // TEST_UTIL_H
