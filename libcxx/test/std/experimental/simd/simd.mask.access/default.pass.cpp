//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED: c++03, c++11, c++14

// <experimental/simd>
// scalar access [simd.mask.subscr]
// reference operator[](size_t);
// value_type operator[](size_t) const;

#include <experimental/simd>
#include <cassert>
#include <cstdint>

#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;

template <typename MaskType>
void test_access() {
  {
    MaskType a(false), b(true);

    assert(bool(a[0]) == false);
    assert(bool(!a[0]) == true);
    assert(bool(+a[0]) == false);
    assert(bool(-a[0]) == false);
    assert(bool(a[0] + b[0]) == true);
    assert(bool(int(a[0]) - int(b[0])) == true);
    assert(bool(a[0] * b[0]) == false);
    assert(bool(a[0] / b[0]) == false);
    assert(bool(a[0] % b[0]) == false);
    assert(bool(int(a[0]) << int(b[0])) == false);
    assert(bool(a[0] >> b[0]) == false);
    assert(bool(a[0] < b[0]) == true);
    assert(bool(a[0] <= b[0]) == true);
    assert(bool(a[0] > b[0]) == false);
    assert(bool(a[0] >= b[0]) == false);
    assert(bool(a[0] == b[0]) == false);
    assert(bool(a[0] != b[0]) == true);
    assert(bool((int(a[0]) & int(b[0]))) == false);
    assert(bool((int(a[0]) | int(b[0]))) == true);
    assert(bool((int(a[0]) ^ int(b[0]))) == true);
    assert(bool((a[0] && b[0])) == false);
    assert(bool((a[0] || b[0])) == true);

    {
      auto c = a;
      c[0] += b[0];
      assert(bool(c[0]) == true);
      assert(bool(c[1]) == false);
    }
    {
      auto c = a;
      c[0] -= b[0];
      assert(bool(c[0]) == true);
      assert(bool(c[1]) == false);
    }
    {
      auto c = b;
      c[0] *= a[0];
      assert(bool(c[0]) == false);
      assert(bool(c[1]) == true);
    }
    {
      auto c = a;
      c[0] /= b[0];
      assert(bool(c[0]) == false);
      assert(bool(c[1]) == false);
    }
    {
      auto c = a;
      c[0] %= b[0];
      assert(bool(c[0]) == false);
      assert(bool(c[1]) == false);
    }
    {
      auto c = a;
      c[0] &= b[0];
      assert(bool(c[0]) == false);
      assert(bool(c[1]) == false);
    }
    {
      auto c = a;
      c[0] |= b[0];
      assert(bool(c[0]) == true);
      assert(bool(c[1]) == false);
    }
    {
      auto c = a;
      c[0] ^= b[0];
      assert(bool(c[0]) == true);
      assert(bool(c[1]) == false);
    }

    {
      auto c = a;
      (void)(a[0] + (c[0] += a[0]));
    }
    {
      auto c = a;
      (void)(a[0] + (c[0] -= a[0]));
    }
    {
      auto c = a;
      (void)(a[0] + (c[0] *= a[0]));
    }
    {
      auto c = a;
      (void)(a[0] + (c[0] /= b[0]));
    }
    {
      auto c = a;
      (void)(a[0] + (c[0] %= b[0]));
    }
    {
      auto c = a;
      (void)(a[0] + (c[0] &= a[0]));
    }
    {
      auto c = a;
      (void)(a[0] + (c[0] |= a[0]));
    }
    {
      auto c = a;
      (void)(a[0] + (c[0] ^= a[0]));
    }
  }
  {
    const MaskType a(false), b(true);

    assert(bool(a[0]) == false);
    assert(bool(!a[0]) == true);
    assert(bool(+a[0]) == false);
    assert(bool(-a[0]) == false);
    assert(bool(a[0] + b[0]) == true);
    assert(bool(a[0] - b[0]) == true);
    assert(bool(int(a[0]) * int(b[0])) == false);
    assert(bool(a[0] / b[0]) == false);
    assert(bool(a[0] % b[0]) == false);
    assert(bool(int(a[0]) << int(b[0])) == false);
    assert(bool(a[0] >> b[0]) == false);
    assert(bool(a[0] < b[0]) == true);
    assert(bool(a[0] <= b[0]) == true);
    assert(bool(a[0] > b[0]) == false);
    assert(bool(a[0] >= b[0]) == false);
    assert(bool(a[0] == b[0]) == false);
    assert(bool(a[0] != b[0]) == true);
    assert(bool((int(a[0]) & int(b[0]))) == false);
    assert(bool((int(a[0]) | int(b[0]))) == true);
    assert(bool((int(a[0]) ^ int(b[0]))) == true);
    assert(bool((a[0] && b[0])) == false);
    assert(bool((a[0] || b[0])) == true);
  }


}

int main() {
  test_access<ex::fixed_size_simd_mask<int, 2>>();
  test_access<ex::native_simd_mask<int>>();

  }
