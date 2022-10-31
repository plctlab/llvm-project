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
// template <class T> struct is_simd_flag_type;
// template <class T> inline constexpr bool ex::is_simd_flag_type_v = ex::is_simd_flag_type<T>::value;

#include "../test_utils.h"
#include <cstdint>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckIsSimdFlagTypeTrue {
  template <class _Tp>
  void operator()() {
    static_assert(_Tp::value);
  }
};

struct CheckIsSimdFlagTypeFalse {
  template <class _Tp>
  void operator()() {
    static_assert(!_Tp::value);
  }
};

struct CheckIsSimdFlagTypeVTrue {
  template <bool _Tp>
  void operator()() {
    static_assert(_Tp);
  }
};

struct CheckIsSimdFlagTypeVFalse {
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
  if constexpr (std::is_same<F, CheckIsSimdFlagTypeTrue>::value) {
    F{}.template operator()<ex::is_simd_flag_type<ex::element_aligned_tag>>();
    F{}.template operator()<ex::is_simd_flag_type<ex::vector_aligned_tag>>();
    F{}.template operator()<ex::is_simd_flag_type<ex::overaligned_tag<_Np>>>();
  } else if constexpr (std::is_same<F, CheckIsSimdFlagTypeFalse>::value) {
    F{}.template operator()<ex::is_simd_flag_type<_Tp>>();
    F{}.template operator()<ex::is_simd_flag_type<ex::simd<_Tp, SimdAbi>>>();
    F{}.template operator()<ex::is_simd_flag_type<ex::simd_mask<_Tp, SimdAbi>>>();
  } else if constexpr (std::is_same<F, CheckIsSimdFlagTypeVTrue>::value) {
    F{}.template operator()<ex::is_simd_flag_type_v<ex::element_aligned_tag>>();
    F{}.template operator()<ex::is_simd_flag_type_v<ex::vector_aligned_tag>>();
    F{}.template operator()<ex::is_simd_flag_type_v<ex::overaligned_tag<_Np>>>();
  } else {
    F{}.template operator()<ex::is_simd_flag_type_v<_Tp>>();
    F{}.template operator()<ex::is_simd_flag_type_v<ex::simd<_Tp, SimdAbi>>>();
    F{}.template operator()<ex::is_simd_flag_type_v<ex::simd_mask<_Tp, SimdAbi>>>();
  }

  test_simd_abi<F, _Np, _Tp, SimdAbis...>();
}

int main(int, char**) {
  test_all_simd_abi<CheckIsSimdFlagTypeTrue>();
  test_all_simd_abi<CheckIsSimdFlagTypeFalse>();
  test_all_simd_abi<CheckIsSimdFlagTypeVTrue>();
  test_all_simd_abi<CheckIsSimdFlagTypeVFalse>();
}