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
// [simd.mask.class]
// explicit simd_mask(value_type) noexcept;
// template<class U> simd_mask(const simd_mask<U, simd_abi::fixed_size<size()>>&) noexcept;
// template<class Flags> simd_mask(const value_type* mem, Flags);

#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckSimdMaskCtor {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    {
        const ex::simd_mask<_Tp, SimdAbi> lhs(true);
        assert(ex::all_of(lhs) == true);
    }
    {
        if constexpr (std::is_same_v<SimdAbi, ex::simd_abi::fixed_size<_Np>>) {
            ex::simd<_Tp, SimdAbi> lhs(static_cast<_Tp>(4));
            ex::simd<_Tp, SimdAbi> rhs([](_Tp i){return i;});

            const ex::simd_mask<_Tp, SimdAbi> mask_(lhs == rhs);
            ex::simd_mask<_Tp, SimdAbi> result(mask_);

            assert(ex::all_of(result == mask_) == true);
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
  test_all_simd_abi<CheckSimdMaskCtor>();
}