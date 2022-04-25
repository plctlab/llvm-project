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
// // unary operators [simd.unary]
// simd& operator++();
// simd operator++(int);
// simd& operator--();
// simd operator--(int);
// mask_type operator!() const;
// simd operator~() const; // see below
// simd operator+() const;
// simd operator-() const;
//
// // binary operators [simd.binary]
// friend simd operator+ (const simd&, const simd&);
// friend simd operator- (const simd&, const simd&);
// friend simd operator* (const simd&, const simd&);
// friend simd operator/ (const simd&, const simd&);
// friend simd operator% (const simd&, const simd&);
// friend simd operator& (const simd&, const simd&);
// friend simd operator| (const simd&, const simd&);
// friend simd operator^ (const simd&, const simd&);
// friend simd operator<<(const simd&, const simd&);
// friend simd operator>>(const simd&, const simd&);
// friend simd operator<<(const simd&, int);
// friend simd operator>>(const simd&, int);
//
// // compound assignment [simd.cassign]
// friend simd& operator+= (simd&, const simd&);
// friend simd& operator-= (simd&, const simd&);
// friend simd& operator*= (simd&, const simd&);
// friend simd& operator/= (simd&, const simd&);
// friend simd& operator%= (simd&, const simd&);
//
// friend simd& operator&= (simd&, const simd&);
// friend simd& operator|= (simd&, const simd&);
// friend simd& operator^= (simd&, const simd&);
// friend simd& operator<<=(simd&, const simd&);
// friend simd& operator>>=(simd&, const simd&);
// friend simd& operator<<=(simd&, int);
// friend simd& operator>>=(simd&, int);

// // simd compare operators
//friend mask_type operator==(const simd&, const simd&) noexcept;
//friend mask_type operator!=(const simd&, const simd&) noexcept;
//friend mask_type operator>=(const simd&, const simd&) noexcept;
//friend mask_type operator<=(const simd&, const simd&) noexcept;
//friend mask_type operator>(const simd&, const simd&) noexcept;
//friend mask_type operator<(const simd&, const simd&) noexcept;

#include <cassert>
#include <cstdint>
#include <experimental/simd>
using namespace std;
namespace ex = std::experimental::parallelism_v2;

template <typename T, typename Abi>
bool equal(ex::simd<T, Abi> a, ex::simd<T, Abi> b) {
  for (size_t i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) {
      return false;
    }
  }
  return true;
}

void test_pure_operators() {
  {
    ex::native_simd<int> a(42), b(4);

    assert(equal(~a, ex::native_simd<int>(~42)));
    assert(equal(+a, a));
    assert(equal(-a, ex::native_simd<int>(-42)));
    assert(equal(a + b, ex::native_simd<int>(42 + 4)));
    assert(equal(a - b, ex::native_simd<int>(42 - 4)));
    assert(equal(a * b, ex::native_simd<int>(42 * 4)));
    assert(equal(a / b, ex::native_simd<int>(42 / 4)));
    assert(equal(a % b, ex::native_simd<int>(42 % 4)));
    assert(equal(a & b, ex::native_simd<int>(42 & 4)));
    assert(equal(a | b, ex::native_simd<int>(42 | 4)));
    assert(equal(a ^ b, ex::native_simd<int>(42 ^ 4)));
    assert(equal(a << b, ex::native_simd<int>(42 << 4)));
    assert(equal(a >> b, ex::native_simd<int>(42 >> 4)));
    assert(equal(a << 4, ex::native_simd<int>(42 << 4)));
    assert(equal(a >> 4, ex::native_simd<int>(42 >> 4)));
  }
  {
    ex::native_simd<int> a([](int i) { return 2 * i + 1; }),
        b([](int i) { return i + 1; });

    assert(equal(~a, ex::native_simd<int>([](int i) { return ~(2 * i + 1); })));
    assert(equal(+a, a));
    assert(equal(-a, ex::native_simd<int>([](int i) { return -(2 * i + 1); })));
    assert(equal(a + b, ex::native_simd<int>([](int i) { return 3 * i + 2; })));
    assert(equal(a - b, ex::native_simd<int>([](int i) { return i; })));
    assert(equal(
        a * b, ex::native_simd<int>([](int i) { return (2 * i + 1) * (i + 1); })));
    assert(equal(
        a / b, ex::native_simd<int>([](int i) { return (2 * i + 1) / (i + 1); })));
    assert(equal(
        a % b, ex::native_simd<int>([](int i) { return (2 * i + 1) % (i + 1); })));
    assert(equal(
        a & b, ex::native_simd<int>([](int i) { return (2 * i + 1) & (i + 1); })));
    assert(equal(
        a | b, ex::native_simd<int>([](int i) { return (2 * i + 1) | (i + 1); })));
    assert(equal(
        a ^ b, ex::native_simd<int>([](int i) { return (2 * i + 1) ^ (i + 1); })));
  }
}

void test_mutating_opreators() {
  ex::native_simd<int> b(4);
  {
    ex::native_simd<int> a(42);
    assert(equal(++a, ex::native_simd<int>(43)));
    assert(equal(a, ex::native_simd<int>(43)));
  }
  {
    ex::native_simd<int> a(42);
    assert(equal(a++, ex::native_simd<int>(42)));
    assert(equal(a, ex::native_simd<int>(43)));
  }
  {
    ex::native_simd<int> a(42);
    assert(equal(--a, ex::native_simd<int>(41)));
    assert(equal(a, ex::native_simd<int>(41)));
  }
  {
    ex::native_simd<int> a(42);
    assert(equal(a--, ex::native_simd<int>(42)));
    assert(equal(a, ex::native_simd<int>(41)));
  }
  {
    ex::native_simd<int> a(42);
    assert(equal(a += b, ex::native_simd<int>(42 + 4)));
    assert(equal(a, ex::native_simd<int>(42 + 4)));
  }
  {
    ex::native_simd<int> a(42);
    assert(equal(a -= b, ex::native_simd<int>(42 - 4)));
    assert(equal(a, ex::native_simd<int>(42 - 4)));
  }
  {
    ex::native_simd<int> a(42);
    assert(equal(a *= b, ex::native_simd<int>(42 * 4)));
    assert(equal(a, ex::native_simd<int>(42 * 4)));
  }
  {
    ex::native_simd<int> a(42);
    assert(equal(a /= b, ex::native_simd<int>(42 / 4)));
    assert(equal(a, ex::native_simd<int>(42 / 4)));
  }
  {
    ex::native_simd<int> a(42);
    assert(equal(a %= b, ex::native_simd<int>(42 % 4)));
    assert(equal(a, ex::native_simd<int>(42 % 4)));
  }
  {
    ex::native_simd<int> a(42);
    assert(equal(a &= b, ex::native_simd<int>(42 & 4)));
    assert(equal(a, ex::native_simd<int>(42 & 4)));
  }
  {
    ex::native_simd<int> a(42);
    assert(equal(a |= b, ex::native_simd<int>(42 | 4)));
    assert(equal(a, ex::native_simd<int>(42 | 4)));
  }
  {
    ex::native_simd<int> a(42);
    assert(equal(a ^= b, ex::native_simd<int>(42 ^ 4)));
    assert(equal(a, ex::native_simd<int>(42 ^ 4)));
  }
  {
    ex::native_simd<int> a(42);
    assert(equal(a <<= b, ex::native_simd<int>(42 << 4)));
    assert(equal(a, ex::native_simd<int>(42 << 4)));
  }
  {
    ex::native_simd<int> a(42);
    assert(equal(a >>= b, ex::native_simd<int>(42 >> 4)));
    assert(equal(a, ex::native_simd<int>(42 >> 4)));
  }
  {
    ex::native_simd<int> a(42);
    assert(equal(a <<= 4, ex::native_simd<int>(42 << 4)));
    assert(equal(a, ex::native_simd<int>(42 << 4)));
  }
  {
    ex::native_simd<int> a(42);
    assert(equal(a >>= 4, ex::native_simd<int>(42 >> 4)));
    assert(equal(a, ex::native_simd<int>(42 >> 4)));
  }
}

void test_compare_opreators() {
  ex::fixed_size_simd<int, 4> a, b;
  {
    int buf[] = {1, 2, 3, 4};
    a.copy_from(buf, ex::element_aligned_tag());
  }
  {
    int buf[] = {1, 2, 1, 2};
    b.copy_from(buf, ex::element_aligned_tag());
  }
  {
    bool expected[] = {
      true, true, false, false,
    };
    assert(ex::all_of((a == b) == ex::fixed_size_simd_mask<int, 4>(
                                expected, ex::element_aligned_tag())));
  }
  {
    bool expected[] = {
      false, false, true,true, 
    };
    assert(all_of((a != b) == ex::fixed_size_simd_mask<int, 4>(
                                  expected, ex::element_aligned_tag())));
  }
  {
    bool expected[] = {
      false,false,false,false,
    };
    assert(all_of((a < b) == ex::fixed_size_simd_mask<int, 4>(
                                 expected, ex::element_aligned_tag())));
  }
  {
    bool expected[] = {
      true, true, false,false,
    };
    assert(all_of((a <= b) == ex::fixed_size_simd_mask<int, 4>(
                                  expected, ex::element_aligned_tag())));
  }
  {
    bool expected[] = {
      false,false,true,true,
    };
    assert(all_of((a > b) == ex::fixed_size_simd_mask<int, 4>(
                                 expected, ex::element_aligned_tag())));
  }
  {
    bool expected[] = {
      true,true,true,true,
    };
    assert(all_of((a >= b) == ex::fixed_size_simd_mask<int, 4>(
                                  expected, ex::element_aligned_tag())));
  }
}
int main() {
  test_pure_operators();
  test_mutating_opreators();
  test_compare_opreators(); 
}