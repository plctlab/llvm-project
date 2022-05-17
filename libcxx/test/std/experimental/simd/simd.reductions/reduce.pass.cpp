//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11, c++14

// template<class T, class Abi, class BinaryOperation = plus<>>
// T reduce(const simd<T, Abi>&,BinaryOperation = {});
// template<class M, class V, class BinaryOperation>
// typename V::value_type reduce(const const_where_expression<M, V>& x,
// typename V::value_type identity_element,BinaryOperation binary_op);
// template<class M, class V>
// typename V::value_type reduce(const const_where_expression<M, V>& x,
// plus<> binary_op = {}) noexcept;
// template<class M, class V>
// typename V::value_type reduce(const const_where_expression<M, V>& x,
// multiplies<> binary_op) noexcept;
// template<class M, class V>
// typename V::value_type reduce(const const_where_expression<M, V>& x,
// bit_and<> binary_op) noexcept;
// template<class M, class V>
// typename V::value_type reduce(const const_where_expression<M, V>& x,
// bit_or<> binary_op) noexcept;
// template<class M, class V>
// typename V::value_type reduce(const const_where_expression<M, V>& x,
// bit_xor<> binary_op) noexcept;

#include <cassert>
#include <cstdint>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

inline int factorial(int n) { return n == 1 ? 1 : n * factorial(n - 1); }

void test_reduce() {
  int n = (int)ex::native_simd<int>::size();
  assert(ex::reduce(ex::native_simd<int>([](int i) { return i; })) == n * (n - 1) / 2);
  assert(ex::reduce(ex::native_simd<int>([](int i) { return i; }), std::plus<int>()) ==
         n * (n - 1) / 2);
  assert(ex::reduce(ex::native_simd<int>([](int i) { return i + 1; }),
                std::multiplies<int>()) == factorial(n));
}

void test_reduce_mask() {
  {
    ex::fixed_size_simd<int, 4> a([](int i) { return i; });
    assert(ex::reduce(ex::where(a < 2, a), 0, std::plus<int>()) == 0 + 1);
    assert(ex::reduce(ex::where(a >= 2, a), 1, std::multiplies<int>()) == 2 * 3);
    assert(ex::reduce(ex::where(a >= 2, a)) == 2 + 3);
    assert(ex::reduce(ex::where(a >= 2, a), std::plus<int>()) == 2 + 3);
    assert(ex::reduce(ex::where(a >= 2, a), std::multiplies<int>()) == 2 * 3);
    assert(ex::reduce(ex::where(a >= 2, a), std::bit_and<int>()) == (2 & 3));
    assert(ex::reduce(ex::where(a >= 2, a), std::bit_or<int>()) == (2 | 3));
    assert(ex::reduce(ex::where(a >= 2, a), std::bit_xor<int>()) == (2 ^ 3));
  }
  {
    ex::fixed_size_simd_mask<int, 4> a;
    a[0] = false;
    a[1] = true;
    a[2] = true;
    a[3] = false;
    assert(ex::reduce(ex::where(ex::fixed_size_simd_mask<int, 4>(true), a)) == true);
    assert(ex::reduce(ex::where(ex::fixed_size_simd_mask<int, 4>(true), a),
                  std::plus<bool>()) == true);
    assert(ex::reduce(ex::where(ex::fixed_size_simd_mask<int, 4>(true), a),
                  std::multiplies<bool>()) == false);
    assert(ex::reduce(ex::where(ex::fixed_size_simd_mask<int, 4>(true), a),
                  std::bit_and<bool>()) == false);
    assert(ex::reduce(ex::where(ex::fixed_size_simd_mask<int, 4>(true), a),
                  std::bit_or<bool>()) == true);
    assert(ex::reduce(ex::where(ex::fixed_size_simd_mask<int, 4>(true), a),
                  std::bit_xor<bool>()) == false);
  }
}
int main() {
       test_reduce();
       test_reduce_mask();
}
