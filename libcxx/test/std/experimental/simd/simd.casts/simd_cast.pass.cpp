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
// template <class T, class U, class Abi> see below ex::simd_cast<(const ex::simd<U, Abi>&);

#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

#define ASSERT_AND_TEST_EQUAL(ORIGIN, EXPECTED)                                                                        \
  static_assert(std::is_same_v<decltype(ORIGIN), decltype(EXPECTED)>, "");                                             \
  assert(ex::all_of(ORIGIN == EXPECTED) == true);

// 3. test for the final case
#define GNERATOR_FULL_TYPE(TYPE)                                                                                       \
  if constexpr (!std::is_same_v<_Tp, TYPE>) {                                                                          \
    auto after_cast = ex::simd_cast<TYPE>(ex::simd<_Tp, SimdAbi>());                                                   \
    auto expected = ex::simd<TYPE, ex::simd_abi::fixed_size<ex::simd<_Tp, SimdAbi>::size()>>{};                        \
    ASSERT_AND_TEST_EQUAL(after_cast, expected);                                                                       \
  }
struct CheckSimdCast {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    GNERATOR_FULL_TYPE(long double)
    GNERATOR_FULL_TYPE(double)
    GNERATOR_FULL_TYPE(float)
    GNERATOR_FULL_TYPE(long long)
    GNERATOR_FULL_TYPE(unsigned long long)
    GNERATOR_FULL_TYPE(long)
    GNERATOR_FULL_TYPE(unsigned long)
    GNERATOR_FULL_TYPE(int)
    GNERATOR_FULL_TYPE(unsigned int)
    GNERATOR_FULL_TYPE(short)
    GNERATOR_FULL_TYPE(unsigned short)
    GNERATOR_FULL_TYPE(wchar_t)
    GNERATOR_FULL_TYPE(signed char)
    GNERATOR_FULL_TYPE(unsigned char)
    GNERATOR_FULL_TYPE(char32_t)
    GNERATOR_FULL_TYPE(char16_t)

    // 2. test for the `std::is_same_v<U, T>`
    {
      auto after_cast = ex::simd_cast<_Tp>(ex::simd<_Tp, SimdAbi>());
      auto expected = ex::simd<_Tp, SimdAbi>{};
      ASSERT_AND_TEST_EQUAL(after_cast, expected);
    }

    constexpr std::size_t origin_full_abi_simd_size = ex::simd<_Tp, SimdAbi>::size();
    static auto InitializeSimd = [](auto& origin_simd) {
      const size_t simd_size = origin_simd.size();
      for (size_t i = 0; i < simd_size; ++i) {
        origin_simd[i++] = static_cast<_Tp>(i + 1);
      }
    };
    // 1. test for the `ex::is_simd_v<T>`
    if constexpr (origin_full_abi_simd_size == ex::native_simd<_Tp>::size()) {
      {
        auto origin = ex::simd<_Tp, SimdAbi>();
        InitializeSimd(origin);
        auto after_cast = ex::simd_cast<ex::native_simd<_Tp>>(origin);
        auto expected = ex::native_simd<_Tp>{};
        InitializeSimd(expected);
        ASSERT_AND_TEST_EQUAL(after_cast, expected);
      }

      {
        auto origin = ex::native_simd<_Tp>();
        InitializeSimd(origin);
        auto after_cast = ex::simd_cast<ex::simd<_Tp, SimdAbi>>(origin);
        auto expected = ex::simd<_Tp, SimdAbi>{};
        InitializeSimd(expected);
        ASSERT_AND_TEST_EQUAL(after_cast, expected);
      }
    }

    if constexpr (origin_full_abi_simd_size == ex::fixed_size_simd<_Tp, _Np>::size()) {
      {
        auto origin = ex::simd<_Tp, SimdAbi>();
        InitializeSimd(origin);
        auto after_cast = ex::simd_cast<ex::fixed_size_simd<_Tp, _Np>>(origin);
        auto expected = ex::fixed_size_simd<_Tp, _Np>{};
        InitializeSimd(expected);
        ASSERT_AND_TEST_EQUAL(after_cast, expected);
      }

      {
        auto origin = ex::fixed_size_simd<_Tp, _Np>();
        InitializeSimd(origin);
        auto after_cast = ex::simd_cast<ex::simd<_Tp, SimdAbi>>(origin);
        auto expected = ex::simd<_Tp, SimdAbi>{};
        InitializeSimd(expected);
        ASSERT_AND_TEST_EQUAL(after_cast, expected);
      }
    }

    if constexpr (origin_full_abi_simd_size == ex::simd<_Tp, ex::simd_abi::scalar>::size()) {
      {
        auto origin = ex::simd<_Tp, SimdAbi>();
        InitializeSimd(origin);
        auto after_cast = ex::simd_cast<ex::simd<_Tp, ex::simd_abi::scalar>>(origin);
        auto expected = ex::simd<_Tp, ex::simd_abi::scalar>{};
        InitializeSimd(expected);
        ASSERT_AND_TEST_EQUAL(after_cast, expected);
      }

      {
        auto origin = ex::simd<_Tp, ex::simd_abi::scalar>();
        InitializeSimd(origin);
        auto after_cast = ex::simd_cast<ex::simd<_Tp, SimdAbi>>(origin);
        auto expected = ex::simd<_Tp, SimdAbi>{};
        InitializeSimd(expected);
        ASSERT_AND_TEST_EQUAL(after_cast, expected);
      }
    }

    if constexpr (origin_full_abi_simd_size == ex::simd<_Tp, ex::simd_abi::deduce_t<_Tp, _Np + 1>>::size()) {
      {
        auto origin = ex::simd<_Tp, SimdAbi>();
        InitializeSimd(origin);
        auto after_cast = ex::simd_cast<ex::simd<_Tp, ex::simd_abi::deduce_t<_Tp, _Np + 1>>>(origin);
        auto expected = ex::simd<_Tp, ex::simd_abi::deduce_t<_Tp, _Np + 1>>{};
        InitializeSimd(expected);
        ASSERT_AND_TEST_EQUAL(after_cast, expected);
      }

      {
        auto origin = ex::simd<_Tp, ex::simd_abi::deduce_t<_Tp, _Np + 1>>();
        InitializeSimd(origin);
        auto after_cast = ex::simd_cast<ex::simd<_Tp, SimdAbi>>(origin);
        auto expected = ex::simd<_Tp, SimdAbi>{};
        InitializeSimd(expected);
        ASSERT_AND_TEST_EQUAL(after_cast, expected);
      }
    }

    if constexpr (origin_full_abi_simd_size == ex::simd<_Tp, ex::simd_abi::compatible<_Tp>>::size()) {
      {
        auto origin = ex::simd<_Tp, SimdAbi>();
        InitializeSimd(origin);
        auto after_cast = ex::simd_cast<ex::simd<_Tp, ex::simd_abi::compatible<_Tp>>>(origin);
        auto expected = ex::simd<_Tp, ex::simd_abi::compatible<_Tp>>{};
        InitializeSimd(expected);
        ASSERT_AND_TEST_EQUAL(after_cast, expected);
      }

      {
        auto origin = ex::simd<_Tp, ex::simd_abi::compatible<_Tp>>();
        InitializeSimd(origin);
        auto after_cast = ex::simd_cast<ex::simd<_Tp, SimdAbi>>(origin);
        auto expected = ex::simd<_Tp, SimdAbi>{};
        InitializeSimd(expected);
        ASSERT_AND_TEST_EQUAL(after_cast, expected);
      }
    }
  }
};

template <class F, std::size_t _Np, class _Tp>
void test_simd_abi() {
}
template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi() {
  F{}.template operator()<_Tp, SimdAbi, _Np>();
  test_simd_abi<F, _Np, _Tp, SimdAbis...>();
}

int main(int, char**) {
  test_all_simd_abi<CheckSimdCast>();
}