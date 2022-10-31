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
// template <class T> struct ex::is_simd_mask;
// template <class T> inline constexpr bool ex::is_simd_mask_v = ex::is_simd_mask<T>::value;

#include "../test_utils.h"
#include <cstdint>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckIsSimdMaskTrue {
  template <class _Tp>
  void operator()() {
    static_assert(_Tp::value);
  }
};

struct CheckIsSimdMaskFalse {
  template <class _Tp>
  void operator()() {
    static_assert(!_Tp::value);
  }
};

struct CheckIsSimdMaskVTrue {
  template <bool _Tp>
  void operator()() {
    static_assert(_Tp);
  }
};

struct CheckIsSimdMaskVFalse {
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
  if constexpr (std::is_same<F, CheckIsSimdMaskTrue>::value) {
    F{}.template operator()<ex::is_simd_mask<ex::simd_mask<_Tp, SimdAbi>>>();
  } else if constexpr (std::is_same<F, CheckIsSimdMaskFalse>::value) {
    F{}.template operator()<ex::is_simd_mask<_Tp>>();
    F{}.template operator()<ex::is_simd_mask<ex::simd<_Tp, SimdAbi>>>();
  } else if constexpr (std::is_same<F, CheckIsSimdMaskVTrue>::value) {
    F{}.template operator()<ex::is_simd_mask_v<ex::simd_mask<_Tp, SimdAbi>>>();
  } else {
    F{}.template operator()<ex::is_simd_mask_v<_Tp>>();
    F{}.template operator()<ex::is_simd_mask_v<ex::simd<_Tp, SimdAbi>>>();
  }

  test_simd_abi<F, _Np, _Tp, SimdAbis...>();
}

int main(int, char**) {
  test_all_simd_abi<CheckIsSimdMaskTrue>();
  test_all_simd_abi<CheckIsSimdMaskFalse>();
  test_all_simd_abi<CheckIsSimdMaskVTrue>();
  test_all_simd_abi<CheckIsSimdMaskVFalse>();
}