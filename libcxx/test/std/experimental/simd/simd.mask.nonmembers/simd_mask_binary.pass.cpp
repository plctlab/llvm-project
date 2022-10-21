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
// [simd.mask.nonmembers]
// friend simd_mask operator&&(const simd_mask& lhs, const simd_mask& rhs) noexcept;
// friend simd_mask operator||(const simd_mask& lhs, const simd_mask& rhs) noexcept;
// friend simd_mask operator& (const simd_mask& lhs, const simd_mask& rhs) noexcept;
// friend simd_mask operator| (const simd_mask& lhs, const simd_mask& rhs) noexcept;
// friend simd_mask operator^ (const simd_mask& lhs, const simd_mask& rhs) noexcept;
// 1 Returns: 
// A simd_mask object initialized with the results of applying the indicated operator to lhs and
// rhs as a binary element-wise operation.
#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckSimdMaskBinary {
template<class _Tp, class SimdAbi>
void operator()(){
    ex::simd_mask_lhs<_Tp, SimdAbi>([](bool i) { return i;});
    ex::simd_mask_rhs<_Tp, SimdAbi>([](bool i) { return i;});

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

}