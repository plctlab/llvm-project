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
// template <size_t N, class T, class A>
// array<resize_simd<simd_size_v<T, A> / N, simd<T, A>>, N> split_by(const simd<T, A>& x) noexcept;
// template <size_t N, class T, class A>
// array<resize_simd<simd_size_v<T, A> / N, simd_mask<T, A>>, N> split_by(const simd_mask<T, A>& x) noexcept;

#include "../test_utils.h"
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckSplitBySimd {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    if constexpr (_Np % ex::simd_size_v<_Tp, SimdAbi> == 0) {
      const ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return i; });
      auto arr = ex::split_by<_Np>(origin_simd);

      for (size_t i = 0; i < _Np; ++i) {
        for (size_t j = 0; j < arr[i].size(); ++j) {
          assert(arr[i][j] == origin_simd[i * (ex::simd_size_v<_Tp, SimdAbi> / _Np) + j]);
        }
      }
    }
  }
};

struct CheckSplitBySimdMask {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    if constexpr (_Np % ex::simd_size_v<_Tp, SimdAbi> == 0) {
      const ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return i; });
      auto arr = ex::split_by<_Np>(origin_simd);

      for (size_t i = 0; i < _Np; ++i) {
        for (size_t j = 0; j < arr[i].size(); ++j) {
          assert(arr[i][j] == origin_simd[i * (ex::simd_size_v<_Tp, SimdAbi> / _Np) + j]);
        }
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
int main() {
  test_all_simd_abi<CheckSplitBySimd>();
  test_all_simd_abi<CheckSplitBySimdMask>();
}