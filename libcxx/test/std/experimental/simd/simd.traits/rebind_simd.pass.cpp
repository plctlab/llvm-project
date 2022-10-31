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
// template<class T, class V> struct rebind_simd { using type = see below ; };
// template<class T, class V> using rebind_simd_t = typename rebind_simd<T, V>::type;

#include "../test_utils.h"
#include <cstdint>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckRebindSimdTrue {
  template <class _Tp, class _Up, class SimdAbi>
  void operator()() {
    static_assert(
        std::is_same<typename ex::rebind_simd<_Tp, ex::simd<_Up, SimdAbi>>::type,
                     ex::simd<_Tp, ex::simd_abi::deduce_t<_Tp, ex::simd_size_v<_Up, SimdAbi>, SimdAbi>>>::value);
    static_assert(
        std::is_same<typename ex::rebind_simd<_Tp, ex::simd_mask<_Up, SimdAbi>>::type,
                     ex::simd_mask<_Tp, ex::simd_abi::deduce_t<_Tp, ex::simd_size_v<_Up, SimdAbi>, SimdAbi>>>::value);
    static_assert(
        std::is_same<ex::rebind_simd_t<_Tp, ex::simd<_Up, SimdAbi>>,
                     ex::simd<_Tp, ex::simd_abi::deduce_t<_Tp, ex::simd_size_v<_Up, SimdAbi>, SimdAbi>>>::value);
    static_assert(
        std::is_same<ex::rebind_simd_t<_Tp, ex::simd_mask<_Up, SimdAbi>>,
                     ex::simd_mask<_Tp, ex::simd_abi::deduce_t<_Tp, ex::simd_size_v<_Up, SimdAbi>, SimdAbi>>>::value);
  }
};

template <class F, std::size_t _Np, class _Tp>
void test_simd_abi() {
}
template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi() {
  F{}.template operator()<long double, _Tp, SimdAbi>();
  F{}.template operator()<double, _Tp, SimdAbi>();
  F{}.template operator()<float, _Tp, SimdAbi>();
  F{}.template operator()<long long, _Tp, SimdAbi>();
  F{}.template operator()<unsigned long long, _Tp, SimdAbi>();
  F{}.template operator()<long, _Tp, SimdAbi>();
  F{}.template operator()<unsigned long, _Tp, SimdAbi>();
  F{}.template operator()<int, _Tp, SimdAbi>();
  F{}.template operator()<unsigned int, _Tp, SimdAbi>();
  F{}.template operator()<short, _Tp, SimdAbi>();
  F{}.template operator()<unsigned short, _Tp, SimdAbi>();
  F{}.template operator()<wchar_t, _Tp, SimdAbi>();
  F{}.template operator()<signed char, _Tp, SimdAbi>();
  F{}.template operator()<unsigned char, _Tp, SimdAbi>();
  F{}.template operator()<char32_t, _Tp, SimdAbi>();
  F{}.template operator()<char16_t, _Tp, SimdAbi>();

  test_simd_abi<F, _Np, _Tp, SimdAbis...>();
}

int main() {
  test_all_simd_abi<CheckRebindSimdTrue>();
}
