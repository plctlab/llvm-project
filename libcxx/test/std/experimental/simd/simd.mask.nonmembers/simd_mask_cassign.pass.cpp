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
// friend simd_mask& operator&=(simd_mask& lhs, const simd_mask& rhs) noexcept;
// friend simd_mask& operator|=(simd_mask& lhs, const simd_mask& rhs) noexcept;
// friend simd_mask& operator^=(simd_mask& lhs, const simd_mask& rhs) noexcept;

#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckSimdMaskCassign {
  template <class _Tp, class SimdAbi>
  void operator()() {
    ex::simd<_Tp, SimdAbi> l_simd(static_cast<_Tp>(5));
    ex::simd<_Tp, SimdAbi> r_simd([](_Tp i) { return i; });

    ex::simd_mask<_Tp, SimdAbi> lhs(l_simd == r_simd);
    const ex::simd_mask<_Tp, SimdAbi> rhs(l_simd > r_simd);

    {
      auto origin_lhs = lhs;
      ex::simd_mask<_Tp, SimdAbi> and_equal_mask(lhs &= rhs);
      assert(ex::all_of(and_equal_mask == lhs) == true);
      for (size_t i = 0; i < and_equal_mask.size(); ++i) {
        assert(and_equal_mask[i] == (origin_lhs[i] && rhs[i]));
      }
      lhs = origin_lhs;
    }
    {
      auto origin_lhs = lhs;
      ex::simd_mask<_Tp, SimdAbi> or_equal_mask(lhs |= rhs);
      assert(ex::all_of(or_equal_mask == lhs) == true);
      for (size_t i = 0; i < or_equal_mask.size(); ++i) {
        assert(or_equal_mask[i] == (origin_lhs[i] || rhs[i]));
      }
      lhs = origin_lhs;
    }
    {
      auto origin_lhs = lhs;
      ex::simd_mask<_Tp, SimdAbi> xor_equal_mask(lhs ^= rhs);
      assert(ex::all_of(xor_equal_mask == lhs) == true);
      for (size_t i = 0; i < xor_equal_mask.size(); ++i) {
        assert(xor_equal_mask[i] == (origin_lhs[i] ^ rhs[i]));
      }
      lhs = origin_lhs;
    }
  }
};

template <class F, std::size_t _Np, class _Tp>
void test_simd_abi() {
}
template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi() {
  F{}.template operator()<_Tp, SimdAbi>();
  test_simd_abi<F, _Np, _Tp, SimdAbis...>();
}

int main() {
  test_all_simd_abi<CheckSimdMaskCassign>();
}
