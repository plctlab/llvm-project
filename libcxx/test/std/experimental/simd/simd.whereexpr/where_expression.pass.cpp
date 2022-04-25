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
// class where_expression : public const_where_expression<M, T> {
// public:
//   where_expression(const where_expression&) = delete;
//   where_expression& operator=(const where_expression&) = delete;
//   template <class U> void operator=(U&& x);
//   template <class U> void operator+=(U&& x);
//   template <class U> void operator-=(U&& x);
//   template <class U> void operator*=(U&& x);
//   template <class U> void operator/=(U&& x);
//   template <class U> void operator%=(U&& x);
//   template <class U> void operator&=(U&& x);
//   template <class U> void operator|=(U&& x);
//   template <class U> void operator^=(U&& x);
//   template <class U> void operator<<=(U&& x);
//   template <class U> void operator>>=(U&& x);
//   void operator++();
//   void operator++(int);
//   void operator--();
//   void operator--(int);
//   template <class U, class Flags> void copy_from(const U* mem, Flags);
// };

#include <experimental/simd>
#include <cassert>
#include <cstdint>
#include <algorithm>

namespace ex = std::experimental::parallelism_v2;

void test_operators_simd() {
  {
    ex::fixed_size_simd<int, 4> a([](int i) { return i; });
    ex::where(a < 2, a) = -1;
    assert(a[0] == -1);
    assert(a[1] == -1);
    assert(a[2] == 2);
    assert(a[3] == 3);
  }
  {
    ex::fixed_size_simd<int, 4> a([](int i) { return i; });
    ex::where(a < 2, a) += -1;
    assert(a[0] == -1);
    assert(a[1] == 0);
    assert(a[2] == 2);
    assert(a[3] == 3);
  }
  {
    ex::fixed_size_simd<int, 4> a([](int i) { return i; });
    ex::where(a < 2, a) -= -1;
    assert(a[0] == 1);
    assert(a[1] == 2);
    assert(a[2] == 2);
    assert(a[3] == 3);
  }
  {
    ex::fixed_size_simd<int, 4> a([](int i) { return i; });
    ex::where(a < 2, a) *= -1;
    assert(a[0] == 0);
    assert(a[1] == -1);
    assert(a[2] == 2);
    assert(a[3] == 3);
  }
  {
    ex::fixed_size_simd<int, 4> a([](int i) { return 3 * i; });
    ex::where(a >= 6, a) /= 2;
    assert(a[0] == 0);
    assert(a[1] == 3);
    assert(a[2] == 3);
    assert(a[3] == 4);
  }
  {
    ex::fixed_size_simd<int, 4> a([](int i) { return 3 * i; });
    ex::where(a >= 6, a) %= 2;
    assert(a[0] == 0);
    assert(a[1] == 3);
    assert(a[2] == 0);
    assert(a[3] == 1);
  }
  {
    ex::fixed_size_simd<int, 4> a([](int i) { return i; });
    ex::where(a > -2, a) &= 1;
    assert(a[0] == 0);
    assert(a[1] == 1);
    assert(a[2] == 0);
    assert(a[3] == 1);
  }
  {
    ex::fixed_size_simd<int, 4> a([](int i) { return i; });
    ex::where(a < 2, a) |= 2;
    assert(a[0] == 2);
    assert(a[1] == 3);
    assert(a[2] == 2);
    assert(a[3] == 3);
  }
  {
    ex::fixed_size_simd<int, 4> a([](int i) { return i; });
    ex::where(a < 2, a) ^= 1;
    assert(a[0] == 1);
    assert(a[1] == 0);
    assert(a[2] == 2);
    assert(a[3] == 3);
  }
  {
    ex::fixed_size_simd<int, 4> a([](int i) { return i; });
    ex::where(a < 2, a) <<= 1;
    assert(a[0] == 0);
    assert(a[1] == 2);
    assert(a[2] == 2);
    assert(a[3] == 3);
  }
  /* {
    ex::fixed_size_simd<int, 4> a([](int i) { return i; });
    ex::where(a < 2, a) <<= ex::fixed_size_simd<int, 4>(1);
    assert(a[0] == 0);
    assert(a[1] == 2);
    assert(a[2] == 2);
    assert(a[3] == 3);
  } */
  {
    ex::fixed_size_simd<int, 4> a([](int i) { return 2 * i; });
    ex::where(a < 4, a) >>= 1;
    assert(a[0] == 0);
    assert(a[1] == 1);
    assert(a[2] == 4);
    assert(a[3] == 6);
  }
}

void test_operators_mask() {
  {
    ex::fixed_size_simd_mask<int, 4> a;
    a[0] = false;
    a[1] = true;
    a[2] = true;
    a[3] = false;
    ex::where(a, a) = false;
    assert(!a[0]);
    assert(!a[1]);
    assert(!a[2]);
    assert(!a[3]);
  }
  {
    ex::fixed_size_simd_mask<int, 4> a;
    a[0] = false;
    a[1] = true;
    a[2] = true;
    a[3] = false;
    ex::where(a, a) &= false;
    assert(!a[0]);
    assert(!a[1]);
    assert(!a[2]);
    assert(!a[3]);
  }
  {
    ex::fixed_size_simd_mask<int, 4> a;
    a[0] = false;
    a[1] = true;
    a[2] = true;
    a[3] = false;
    ex::where(!a, a) |= true;
    assert(a[0]);
    assert(a[1]);
    assert(a[2]);
    assert(a[3]);
  }
  {
    ex::fixed_size_simd_mask<int, 4> a;
    a[0] = false;
    a[1] = true;
    a[2] = true;
    a[3] = false;
    ex::where(a, a) ^= true;
    assert(!a[0]);
    assert(!a[1]);
    assert(!a[2]);
    assert(!a[3]);
  }
  {
    ex::fixed_size_simd_mask<int, 4> a;
    a[0] = false;
    a[1] = true;
    a[2] = true;
    a[3] = false;
    ex::where(!a, a) ^= true;
    assert(a[0]);
    assert(!a[1]);
    assert(!a[2]);
    assert(a[3]);
  }
}

void test_copy_from() {
  {
    const int buffer[] = {-1, -2, -3, -4};
    ex::fixed_size_simd<int, 4> a([](int i) { return i; });
    ex::where(a < 2, a).copy_from(buffer, ex::element_aligned_tag());
    assert(a[0] == -1);
    assert(a[1] == -2);
    assert(a[2] == 2);
    assert(a[3] == 3);
  }
  {
    const int buffer[] = {-1, -2, -3, -4};
    ex::fixed_size_simd<int, 4> a([](int i) { return i; });
    ex::where(a >= 2, a).copy_from(buffer, ex::element_aligned_tag());
    assert(a[0] == 0);
    assert(a[1] == 1);
    assert(a[2] == -3);
    assert(a[3] == -4);
  }
  {
    ex::fixed_size_simd_mask<int, 4> a;
    const bool input[] = {false, true, true, false};
    a.copy_from(input, ex::element_aligned_tag());

    const bool buffer[] = {true, true, false, false};
    ex::where(a, a).copy_from(buffer, ex::element_aligned_tag());
    assert(!a[0]);
    assert(a[1]);
    assert(!a[2]);
    assert(!a[3]);
  }
  {
    ex::fixed_size_simd_mask<int, 4> a;
    const bool input[] = {false, true, true, false};
    a.copy_from(input, ex::element_aligned_tag());

    const bool buffer[] = {true, true, false, false};
    ex::where(!a, a).copy_from(buffer, ex::element_aligned_tag());
    assert(a[0]);
    assert(a[1]);
    assert(!a[2]);
    assert(!a[3]);
  }
  {
    const int b = 1;
    int a = 3;
    ex::where(true, a).copy_from(&b, ex::element_aligned_tag());
    assert(a == 1);
  }
  {
    const int b = 1;
    int a = 3;
    ex::where(false, a).copy_from(&b, ex::element_aligned_tag());
    assert(b == 1);
  }
}

int main() {
  test_operators_simd();
  test_operators_mask();
  test_copy_from();
}