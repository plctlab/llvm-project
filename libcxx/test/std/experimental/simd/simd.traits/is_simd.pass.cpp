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
// template <class T> struct ex::is_simd;
// template <class T> inline constexpr bool ex::is_simd_v =
// ex::is_simd<T>::value;

#include "../test_utils.h"
#include <cstdint>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckIsSimdTrue {
  template <class _Tp>
  void operator()() {
    static_assert(_Tp::value);
  }
};

struct CheckIsSimdFalse {
  template <class _Tp>
  void operator()() {
    static_assert(!_Tp::value);
  }
};

struct CheckIsSimdVTrue {
  template <bool _Tp>
  void operator()() {
    static_assert(_Tp);
  }
};

struct CheckIsSimdVFalse {
  template <bool _Tp>
  void operator()() {
    static_assert(!_Tp);
  }
};

template <class F, std::size_t _Np, class _Tp>
void test_simd_abi() {
}
template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi() {
  if constexpr (std::is_same<F, CheckIsSimdTrue>::value) {
    F{}.template operator()<ex::is_simd<ex::simd<_Tp, SimdAbi>>>();
  } else if constexpr (std::is_same<F, CheckIsSimdFalse>::value) {
    F{}.template operator()<ex::is_simd<_Tp>>();
    F{}.template operator()<ex::is_simd<ex::simd_mask<_Tp, SimdAbi>>>();
  } else if constexpr (std::is_same<F, CheckIsSimdVTrue>::value) {
    F{}.template operator()<ex::is_simd_v<ex::simd<_Tp, SimdAbi>>>();
  } else {
    F{}.template operator()<ex::is_simd_v<_Tp>>();
    F{}.template operator()<ex::is_simd_v<ex::simd_mask<_Tp, SimdAbi>>>();
  }

  test_simd_abi<F, _Np, _Tp, SimdAbis...>();
}

int main(int, char**) {
  test_all_simd_abi<CheckIsSimdTrue>();
  test_all_simd_abi<CheckIsSimdFalse>();
  test_all_simd_abi<CheckIsSimdVTrue>();
  test_all_simd_abi<CheckIsSimdVFalse>();
}