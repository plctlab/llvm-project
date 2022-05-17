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
// template <class T, class Abi> T ex::hmax(const simd<T, Abi>&);
// template <class M, class V> T ex::hmax(const const_where_expression<M, V>&);

#include <experimental/simd>
#include <cassert>
#include <cstdint>

namespace ex = std::experimental::parallelism_v2;

void test_hmax() {
  {
    int a[] = {3,-1,2,-4};
    assert(ex::hmax(ex::fixed_size_simd<int, 4>(a, ex::element_aligned_tag())) == 3);
  }
  {
    int a[] = {-1,2,-4,3};
    assert(ex::hmax(ex::fixed_size_simd<int, 4>(a, ex::element_aligned_tag())) == 3);
  }
  {
    int a[] = {2,-4,3,-1};
    assert(ex::hmax(ex::fixed_size_simd<int, 4>(a, ex::element_aligned_tag())) == 3);
  }
  {
    int a[] = {-4,3,-1,-2};
    assert(ex::hmax(ex::fixed_size_simd<int, 4>(a, ex::element_aligned_tag())) == 3);
  }
}
void test_hmax_mask() {
  assert(ex::hmax(ex::where(ex::native_simd_mask<int>(false), ex::native_simd<int>())) ==
         std::numeric_limits<int>::min());
  {
    int buffer[] = {1, -2, 3, -4};
    ex::fixed_size_simd<int, 4> a(buffer, ex::element_aligned_tag());
    assert(ex::hmax(ex::where(a <= 3, a)) == 3);
    assert(ex::hmax(ex::where(a < 3, a)) == 1);
    assert(ex::hmax(ex::where(a < 1, a)) == -2);
    assert(ex::hmax(ex::where(a < -2, a)) == -4);
    assert(ex::hmax(ex::where(a < -4, a)) == std::numeric_limits<int>::min());
  }
  {
    const ex::fixed_size_simd<float, 1> a(0);
    assert(ex::hmax(ex::where(ex::fixed_size_simd_mask<float, 1>(true), a)) == 0.f);
    assert(ex::hmax(ex::where(ex::fixed_size_simd_mask<float, 1>(false), a)) ==
           std::numeric_limits<float>::lowest());
  }
}

int main() { 
  test_hmax();
  test_hmax_mask();
 }