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
#include <cassert>
#include <cstdint>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckSplitBySimd { //waiting implementation
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {}
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
  //   test_all_simd_abi<CheckSplitBySimd>();
  //   test_all_simd_abi<CheckSplitBySimdMask>();
}