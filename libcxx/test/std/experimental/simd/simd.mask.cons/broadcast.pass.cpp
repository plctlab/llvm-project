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
// broadcast constructor
// explicit simd_mask(value_type) noexcept;

#include <experimental/simd>
#include <cstdint>
#include <cassert>
#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;


void test_broadcast() {
  {
    ex::native_simd_mask<int> m(false);
    for (size_t i = 0; i < m.size(); i++) {
      assert(!m[i]);
    }
  }
  {
    ex::native_simd_mask<int> m(true);
    for (size_t i = 0; i < m.size(); i++) {
      assert(m[i]);
    }
  }
  {
    ex::fixed_size_simd_mask<int,4> m(false);
    for (size_t i = 0; i < m.size(); i++) {
      assert(!m[i]);
    }
  }
  {
    ex::fixed_size_simd_mask<int,4> m(true);
    for (size_t i = 0; i < m.size(); i++) {
      assert(m[i]);
    }
  }
  {
    ex::fixed_size_simd_mask<int,15> m(false);
    for (size_t i = 0; i < m.size(); i++) {
      assert(!m[i]);
    }
  }
  {
    ex::fixed_size_simd_mask<int,15> m(true);
    for (size_t i = 0; i < m.size(); i++) {
      assert(m[i]);
    }
  }
  {
    ex::simd_mask<int> m(false);
    for (size_t i = 0; i < m.size(); i++) {
      assert(!m[i]);
    }
  }
  {
    ex::simd_mask<int> m(true);
    for (size_t i = 0; i < m.size(); i++) {
      assert(m[i]);
    }
  }
}

int main() { test_broadcast(); }