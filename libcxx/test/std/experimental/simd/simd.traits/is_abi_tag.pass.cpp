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
// template <class T> struct is_abi_tag;
// template <class T> inline constexpr bool ex::is_abi_tag_v = ex::is_abi_tag<T>::value;

#include "../test_utils.h"
#include <cstdint>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckIsAbiTagTrue {
  template <class _Tp>
  void operator()() {
    static_assert(_Tp::value);
  }
};

struct CheckIsAbiTagFalse {
  template <class _Tp>
  void operator()() {
    static_assert(!_Tp::value);
  }
};

struct CheckIsAbiTagVTrue {
  template <bool _Tp>
  void operator()() {
    static_assert(_Tp);
  }
};

struct CheckIsAbiTagVFalse {
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
  if constexpr (std::is_same<F, CheckIsAbiTagTrue>::value) {
    F{}.template operator()<ex::is_abi_tag<SimdAbi>>();
  } else if constexpr (std::is_same<F, CheckIsAbiTagFalse>::value) {
    F{}.template operator()<ex::is_abi_tag<_Tp>>();
    F{}.template operator()<ex::is_abi_tag<ex::simd<_Tp, SimdAbi>>>();
    F{}.template operator()<ex::is_abi_tag<ex::simd_mask<_Tp, SimdAbi>>>();
  } else if constexpr (std::is_same<F, CheckIsAbiTagVTrue>::value) {
    F{}.template operator()<ex::is_abi_tag_v<SimdAbi>>();
  } else {
    F{}.template operator()<ex::is_abi_tag_v<_Tp>>();
    F{}.template operator()<ex::is_abi_tag_v<ex::simd<_Tp, SimdAbi>>>();
    F{}.template operator()<ex::is_abi_tag_v<ex::simd_mask<_Tp, SimdAbi>>>();
  }

  test_simd_abi<F, _Np, _Tp, SimdAbis...>();
}

int main(int, char**) {
  test_all_simd_abi<CheckIsAbiTagTrue>();
  test_all_simd_abi<CheckIsAbiTagFalse>();
  test_all_simd_abi<CheckIsAbiTagVTrue>();
  test_all_simd_abi<CheckIsAbiTagVFalse>();
}