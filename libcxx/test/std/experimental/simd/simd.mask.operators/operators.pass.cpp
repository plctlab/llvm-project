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
// // unary operators [simd.mask.unary]
// simd_mask operator!() const noexcept;
//
// // simd_mask binary operators [simd.mask.binary]
// friend simd_mask operator&&(const simd_mask&, const simd_mask&) noexcept;
// friend simd_mask operator||(const simd_mask&, const simd_mask&) noexcept;
// friend simd_mask operator& (const simd_mask&, const simd_mask&) noexcept;
// friend simd_mask operator| (const simd_mask&, const simd_mask&) noexcept;
// friend simd_mask operator^ (const simd_mask&, const simd_mask&) noexcept;
//
// // simd_mask compound assignment [simd.mask.cassign]
// friend simd_mask& operator&=(simd_mask&, const simd_mask&) noexcept;
// friend simd_mask& operator|=(simd_mask&, const simd_mask&) noexcept;
// friend simd_mask& operator^=(simd_mask&, const simd_mask&) noexcept;
//
// // simd_mask compares [simd.mask.comparison]
// friend simd_mask operator==(const simd_mask&, const simd_mask&) noexcept;
// friend simd_mask operator!=(const simd_mask&, const simd_mask&) noexcept;

#include <cassert>
#include <cstdint>
#include <experimental/simd>
#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;
template <typename MaskType>
void test_pure_operators() {
  assert(all_of(!MaskType(false)));
  assert(all_of(MaskType(false) ==
                (MaskType(false) && MaskType(true))));
  assert(all_of(MaskType(true) ==
                (MaskType(false) || MaskType(true))));
  assert(all_of(MaskType(false) ==
                (MaskType(false) & MaskType(true))));
  assert(all_of(MaskType(true) ==
                (MaskType(false) | MaskType(true))));
  assert(all_of(MaskType(true) ==
                (MaskType(false) ^ MaskType(true))));
  assert(all_of(MaskType(false) ==
                (MaskType(true) ^ MaskType(true))));
  assert(all_of(MaskType(false) ==
                (MaskType(false) ^ MaskType(false))));              
}
template <typename MaskType>
void test_mutating_opreators() {
  {
    MaskType a(true);
    a &= MaskType(false);
    assert(all_of(MaskType(false) == a));
  }
  {
    MaskType a(true);
    a |= MaskType(false);
    assert(all_of(MaskType(true) == a));
  }
  {
    MaskType a(true);
    a ^= MaskType(false);
    assert(all_of(MaskType(true) == a));
  }
  {
    MaskType a(true);
    a ^= MaskType(true);
    assert(all_of(MaskType(false) == a));
  }
}
template <typename MaskType>
void test_relational_operators() {
  assert(all_of(!(MaskType(false) == MaskType(true))));
  assert(all_of(MaskType(false) != MaskType(true)));
  assert(all_of(MaskType(false) == MaskType(false)));
  assert(all_of(!(MaskType(false) != MaskType(false))));
  assert(all_of(MaskType(true) == MaskType(true)));
  assert(all_of(!(MaskType(true) != MaskType(true))));
}

int main() {
  test_pure_operators<ex::fixed_size_simd_mask<int, 4>>();
  test_pure_operators<ex::native_simd_mask<int>>();

  test_mutating_opreators<ex::fixed_size_simd_mask<int, 4>>();
  test_mutating_opreators<ex::native_simd_mask<int>>();

  test_relational_operators<ex::fixed_size_simd_mask<int, 4>>();
  test_relational_operators<ex::native_simd_mask<int>>();
}