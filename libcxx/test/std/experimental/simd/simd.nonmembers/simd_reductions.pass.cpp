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
// [simd.nonmembers]
// template <class T, class Abi, class BinaryOperation = plus<>>
//   T reduce(const simd<T, Abi>&,
//            BinaryOperation = {});

// template <class M, class V, class BinaryOperation>
//   typename V::value_type reduce(const const_where_expression<M, V>& x,
//                                 typename V::value_type neutral_element,
//                                 BinaryOperation binary_op);

// template <class M, class V>
//   typename V::value_type reduce(const const_where_expression<M, V>& x,
//                                 plus<> binary_op = {}) noexcept;
// template <class M, class V>
//   typename V::value_type reduce(const const_where_expression<M, V>& x,
//                                 multiplies<> binary_op) noexcept;
// template <class M, class V>
//   typename V::value_type reduce(const const_where_expression<M, V>& x,
//                                 bit_and<> binary_op) noexcept;
// template <class M, class V>
//   typename V::value_type reduce(const const_where_expression<M, V>& x,
//                                 bit_or<> binary_op) noexcept;
// template <class M, class V>
//   typename V::value_type reduce(const const_where_expression<M, V>& x,
//                                 bit_xor<> binary_op) noexcept;

// template <class T, class Abi>
//   T hmin(const simd<T, Abi>&) noexcept;
// template <class M, class V>
//   typename V::value_type hmin(const const_where_expression<M, V>&) noexcept;
// template <class T, class Abi>
//   T hmax(const simd<T, Abi>&) noexcept;
// template <class M, class V>
//   typename V::value_type hmax(const const_where_expression<M, V>&) noexcept;

#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>
#include <numeric>

namespace ex = std::experimental::parallelism_v2;

struct CheckSimdReduction {
  template <class _Tp, class SimdAbi>
  void operator()() {
    const ex::simd<_Tp, SimdAbi> lhs(static_cast<_Tp>(5));
    const ex::simd<_Tp, SimdAbi> rhs([](_Tp i) { return i; });

    {
      _Tp result = ex::reduce(rhs, std::plus<>);
      _Tp expected = std::reduce(rhs.data, rhs.data + rhs.size(), static_cast<_Tp>(0), std::plus<>());
      assert(result == expected);
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
  test_all_simd_abi<CheckSimdReduction>();
}