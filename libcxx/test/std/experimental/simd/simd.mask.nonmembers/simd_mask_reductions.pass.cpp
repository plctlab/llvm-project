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
// template <class T, class Abi> bool all_of(const simd_mask<T, Abi>&) noexcept;
// template <class T, class Abi> bool any_of(const simd_mask<T, Abi>&) noexcept;
// template <class T, class Abi> bool none_of(const simd_mask<T, Abi>&) noexcept;
// template <class T, class Abi> bool some_of(const simd_mask<T, Abi>&) noexcept;
// template <class T, class Abi> int popcount(const simd_mask<T, Abi>&) noexcept;
// template <class T, class Abi> int find_first_set(const simd_mask<T, Abi>&);
// template <class T, class Abi> int find_last_set(const simd_mask<T, Abi>&);

#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

struct CheckSimdMaskReduction {
  template <class _Tp, class SimdAbi>
  void operator()() {
    { 
        const ex::simd_mask<_Tp, SimdAbi> mask_all_true(true), mask_all_false(false);
        assert(ex::all_of(mask_all_true) == true);
        assert(ex::all_of(mask_all_false) == false);
    }
    {
        ex::simd<_Tp, SimdAbi> l_simd(static_cast<_Tp>(0));
        ex::simd<_Tp, SimdAbi> r_simd([](_Tp i) { return i; });
        const ex::simd_mask<_Tp, SimdAbi> mask_at_least_one_true(l_simd == r_simd);
        assert(ex::any_of(mask_at_least_one_true) == true);
        const ex::simd_mask<_Tp, SimdAbi> mask_all_false(false);
        assert(ex::any_of(mask_all_false) == false);
    }
    {
        ex::simd<_Tp, SimdAbi> l_simd(static_cast<_Tp>(0));
        ex::simd<_Tp, SimdAbi> r_simd([](_Tp i) { return i; });
        const ex::simd_mask<_Tp, SimdAbi> mask_at_least_one_true(l_simd == r_simd);
        assert(ex::none_of(mask_at_least_one_true) == false);
        const ex::simd_mask<_Tp, SimdAbi> mask_all_false(false);
        assert(ex::none_of(mask_all_false) == true);
    }
    {
        ex::simd<_Tp, SimdAbi> l_simd(static_cast<_Tp>(0));
        ex::simd<_Tp, SimdAbi> r_simd([](_Tp i) { return i; });
        const ex::simd_mask<_Tp, SimdAbi> mask_at_least_one_true(l_simd == r_simd);
        assert(ex::none_of(mask_at_least_one_true) == false);
        const ex::simd_mask<_Tp, SimdAbi> mask_all_false(false);
        assert(ex::none_of(mask_all_false) == true);
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
  test_all_simd_abi<CheckSimdMaskReduction>();
}
