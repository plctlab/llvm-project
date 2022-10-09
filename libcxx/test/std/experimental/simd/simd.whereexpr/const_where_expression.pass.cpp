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
// // [simd.whereexpr]
// template <class M, class T>
// class const_where_expression {
//   const M& mask; // exposition only
//   T& data; // exposition only
// public:
//   const_where_expression(const const_where_expression&) = delete;
//   const_where_expression& operator=(const const_where_expression&) = delete;
//   T operator-() const && noexcept;
//   T operator+() const && noexcept;
//   T operator~() const && noexcept;
//   template<class U, class Flags> void copy_to(U* mem, Flags f) const &&;
// };

#include <experimental/simd>
#include <cassert>
#include <cstdint>
#include <algorithm>
#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;

void test_operator_minus() {
  {
    const ex::fixed_size_simd<int, 4> a([](int i) { return i; });
    auto b = -ex::where(a < 2, a);
    assert(b[0] == 0);
    assert(b[1] == -1);
    assert(b[2] == 2);
    assert(b[3] == 3);
  }
  //assert((-ex::where(true, 3)) == -3);
  //assert((-ex::where(false, 3)) == 3);
}


void test_operator_positive() {
  {
    const ex::fixed_size_simd<int, 4> a([](int i) { return i; });
    auto b = +ex::where(a < 2, a);
    assert(b[0] == 0);
    assert(b[1] == 1);
    assert(b[2] == 2);
    assert(b[3] == 3);
  }
  //assert((+ex::where(true, 3)) == 3);
  //assert((+ex::where(false, -3)) == -3);
}


void test_copy_to() {
  {
    const ex::fixed_size_simd<int, 4> a([](int i) { return i - 2; });
    int buffer[] = {1, 2, 3, 4};
    ex::where(a < 0, a).copy_to(buffer, ex::element_aligned_tag());
    assert(buffer[0] == -2);
    assert(buffer[1] == -1);
    assert(buffer[2] == 3);
    assert(buffer[3] == 4);
  }
  {
    const ex::fixed_size_simd<int, 4> a([](int i) { return i - 2; });
    int buffer[] = {1, 2, 3, 4};
    ex::where(a >= 0, a).copy_to(buffer, ex::element_aligned_tag());
    assert(buffer[0] == 1);
    assert(buffer[1] == 2);
    assert(buffer[2] == 0);
    assert(buffer[3] == 1);
  }
  {
    ex::fixed_size_simd_mask<int, 4> a;
    {
      bool input[] = {false, true, true, false};
      a.copy_from(input, ex::element_aligned_tag());
    }
    {
      bool buffer[] = {true, true, false, false};
      ex::where(a, a).copy_to(buffer, ex::element_aligned_tag());
      assert(buffer[0]);
      assert(buffer[1]);
      assert(buffer[2]);
      assert(!buffer[3]);
    }
    {
      bool buffer[] = {true, true, false, false};
      ex::where(!a, a).copy_to(buffer, ex::element_aligned_tag());
      assert(!buffer[0]);
      assert(buffer[1]);
      assert(!buffer[2]);
      assert(!buffer[3]);
    }
  }
  {
    int b = 1;
    ex::where(true, 3).copy_to(&b, ex::element_aligned_tag());
    assert(b == 3);
  }
  {
    int b = 1;
    ex::where(false, 3).copy_to(&b, ex::element_aligned_tag());
    assert(b == 1);
  }
}

int main() {
  test_operator_minus();
  test_copy_to();
}