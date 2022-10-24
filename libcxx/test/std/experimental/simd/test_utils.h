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

template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi();

template <class F, class _Tp, std::size_t... _Np>
void test_all_simd_abi(std::integer_sequence<std::size_t, _Np...>) {
  using namespace ex;

  (test_simd_abi<F,
                 _Np + 1,
                 _Tp,
                 simd_abi::native<_Tp>,
                 simd_abi::fixed_size<_Np + 1>,
                 simd_abi::scalar,
                 simd_abi::compatible<_Tp>,
                 simd_abi::deduce_t<_Tp, _Np + 1>>(),
   ...);
}

template <class F>
void test_all_simd_abi() {
  test_all_simd_abi<F, long double>(std::make_integer_sequence<std::size_t, 64>());
  test_all_simd_abi<F, double>(std::make_integer_sequence<std::size_t, 64>());
  test_all_simd_abi<F, float>(std::make_integer_sequence<std::size_t, 64>());
  test_all_simd_abi<F, long long>(std::make_integer_sequence<std::size_t, 64>());
  test_all_simd_abi<F, unsigned long long>(std::make_integer_sequence<std::size_t, 64>());
  test_all_simd_abi<F, long>(std::make_integer_sequence<std::size_t, 64>());
  test_all_simd_abi<F, unsigned long>(std::make_integer_sequence<std::size_t, 64>());
  test_all_simd_abi<F, int>(std::make_integer_sequence<std::size_t, 64>());
  test_all_simd_abi<F, unsigned int>(std::make_integer_sequence<std::size_t, 64>());
  test_all_simd_abi<F, short>(std::make_integer_sequence<std::size_t, 64>());
  test_all_simd_abi<F, unsigned short>(std::make_integer_sequence<std::size_t, 64>());
  test_all_simd_abi<F, wchar_t>(std::make_integer_sequence<std::size_t, 64>());
  test_all_simd_abi<F, signed char>(std::make_integer_sequence<std::size_t, 64>());
  test_all_simd_abi<F, unsigned char>(std::make_integer_sequence<std::size_t, 64>());
  test_all_simd_abi<F, char32_t>(std::make_integer_sequence<std::size_t, 64>());
  test_all_simd_abi<F, char16_t>(std::make_integer_sequence<std::size_t, 64>());
}

#endif // TEST_UTIL_H