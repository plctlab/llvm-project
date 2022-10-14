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
// template<int N, class V> struct resize_simd { using type = see below ; };
// template<int N, class V> using resize_simd_t = typename resize_simd<N, V>::type;

#include "../test_utils.h"
#include <cstdint>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

class CheckResizeSimdTrue {
public:
  template <class _Tp, std::size_t _Np, class SimdAbi, class Func>
  void operator()(Func func) {
    using U1 = ex::resize_simd<func(ex::simd_size_v<_Tp, SimdAbi>, _Np), ex::simd_mask<_Tp, SimdAbi>>;
    using V1 = ex::simd_mask<_Tp, SimdAbi>;
    static_assert(U1::type::size() == func(V1::size(), _Np));

    using U2 = ex::resize_simd<func(ex::simd_size_v<_Tp, SimdAbi>, _Np), ex::simd<_Tp, SimdAbi>>;
    using V2 = ex::simd<_Tp, SimdAbi>;
    static_assert(U2::type::size() == func(V2::size(), _Np));

    using U3 = ex::resize_simd_t<func(ex::simd_size_v<_Tp, SimdAbi>, _Np), ex::simd_mask<_Tp, SimdAbi>>;
    using V3 = ex::simd_mask<_Tp, SimdAbi>;
    static_assert(U3::size() == func(V3::size(), _Np));

    using U4 = ex::resize_simd_t<func(ex::simd_size_v<_Tp, SimdAbi>, _Np), ex::simd<_Tp, SimdAbi>>;
    using V4 = ex::simd<_Tp, SimdAbi>;
    static_assert(U4::size() == func(V4::size(), _Np));
  }
};

template <class F, std::size_t _Np, class _Tp>
void test_simd_abi() {
}
template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi() {
  F{}.template operator()<_Tp, _Np, SimdAbi, std::plus<std::size_t>>(std::plus<std::size_t>());
  if constexpr (ex::simd_size_v<_Tp, SimdAbi> >= _Np) {
    F{}.template operator()<_Tp, _Np, SimdAbi, std::divides<std::size_t>>(std::divides<std::size_t>());
  }
  F{}.template operator()<_Tp, _Np, SimdAbi, std::multiplies<std::size_t>>(std::multiplies<std::size_t>());
  if constexpr (ex::simd_size_v<_Tp, SimdAbi> > _Np) {
    F{}.template operator()<_Tp, _Np, SimdAbi, std::minus<std::size_t>>(std::minus<std::size_t>());
  }

  test_simd_abi<F, _Np, _Tp, SimdAbis...>();
}
int main() {
  test_all_simd_abi<CheckResizeSimdTrue>();
}