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
// [simd.reference]
// template<class U> reference operator=(U&& x) && noexcept;
// template<class U> reference operator+=(U&& x) && noexcept;
// template<class U> reference operator-=(U&& x) && noexcept;
// template<class U> reference operator*=(U&& x) && noexcept;
// template<class U> reference operator/=(U&& x) && noexcept;
// template<class U> reference operator%=(U&& x) && noexcept;
// template<class U> reference operator|=(U&& x) && noexcept;
// template<class U> reference operator&=(U&& x) && noexcept;
// template<class U> reference operator^=(U&& x) && noexcept;
// template<class U> reference operator<<=(U&& x) && noexcept;
// template<class U> reference operator>>=(U&& x) && noexcept;
// reference operator++() && noexcept;
// value_type operator++(int) && noexcept;
// reference operator--() && noexcept;
// value_type operator--(int) && noexcept;

#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;
struct CheckReferenceOperators {
  template <class _Tp, class SimdAbi>
  void operator()() {
    ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i){return static_cast<_Tp>(i+2);});

    {
      assert(origin_simd[0] == static_cast<_Tp>(2));
      using U = _Tp;
      U x = static_cast<U>(3);
      //if  (std::declval<_Tp&>() == std::forward<U>(x)) 
      {
        origin_simd[0]= std::move(x);
      }
      assert(origin_simd[0] == static_cast<_Tp>(3));
    }
    {

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

int main(int, char**) {
  test_all_simd_abi<CheckReferenceOperators>();
}