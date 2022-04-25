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
// load constructor
// template <class Flags> simd_mask(const value_type* mem, Flags);

#include <experimental/simd>
#include <cstdint>
#include <cassert>

#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;

void test_load_ctor() {
  {
    bool buf[] = {false, true, true, false};
    ex::fixed_size_simd_mask<int, 4> m(buf, ex::element_aligned_tag());
    assert(buf[0] == m[0]);
    assert(buf[1] == m[1]);
    assert(buf[2] == m[2]);
    assert(buf[3] == m[3]);
  }
  {
    bool buf[] = {false, true, true, false};
    ex::fixed_size_simd_mask<int, 4> m(buf, ex::vector_aligned_tag());
    assert(buf[0] == m[0]);
    assert(buf[1] == m[1]);
    assert(buf[2] == m[2]);
    assert(buf[3] == m[3]);
  }
  {
    bool buf[] = {false, true, true, false};
    ex::fixed_size_simd_mask<int, 4> m(buf, ex::overaligned_tag<32>());
    assert(buf[0] == m[0]);
    assert(buf[1] == m[1]);
    assert(buf[2] == m[2]);
    assert(buf[3] == m[3]);
  }

  {
    bool buf[] = {false, true, true, false};
    ex::fixed_size_simd_mask<int, 4> m(buf, ex::element_aligned);
    assert(buf[0] == m[0]);
    assert(buf[1] == m[1]);
    assert(buf[2] == m[2]);
    assert(buf[3] == m[3]);
  }
  {
    bool buf[] = {false, true, true, false};
    ex::fixed_size_simd_mask<int, 4> m(buf, ex::vector_aligned);
    assert(buf[0] == m[0]);
    assert(buf[1] == m[1]);
    assert(buf[2] == m[2]);
    assert(buf[3] == m[3]);
  }
  {
    bool buf[] = {false, true, true, false};
    ex::fixed_size_simd_mask<int, 4> m(buf, ex::overaligned<32>);
    assert(buf[0] == m[0]);
    assert(buf[1] == m[1]);
    assert(buf[2] == m[2]);
    assert(buf[3] == m[3]);
  }


 {
    bool buf[] = {false, true, true, false};
    ex::native_simd_mask<int> m(buf, ex::element_aligned_tag());
    assert(buf[0] == m[0]);
    assert(buf[1] == m[1]);
    assert(buf[2] == m[2]);
    assert(buf[3] == m[3]);
  }
  {
    bool buf[] = {false, true, true, false};
    ex::native_simd_mask<int> m(buf, ex::vector_aligned_tag());
    assert(buf[0] == m[0]);
    assert(buf[1] == m[1]);
    assert(buf[2] == m[2]);
    assert(buf[3] == m[3]);
  }
  {
    bool buf[] = {false, true, true, false};
    ex::native_simd_mask<int> m(buf, ex::overaligned_tag<32>());
    assert(buf[0] == m[0]);
    assert(buf[1] == m[1]);
    assert(buf[2] == m[2]);
    assert(buf[3] == m[3]);
  }

  {
    bool buf[] = {false, true, true, false};
    ex::native_simd_mask<int> m(buf, ex::element_aligned);
    assert(buf[0] == m[0]);
    assert(buf[1] == m[1]);
    assert(buf[2] == m[2]);
    assert(buf[3] == m[3]);
  }
  {
    bool buf[] = {false, true, true, false};
    ex::native_simd_mask<int> m(buf, ex::vector_aligned);
    assert(buf[0] == m[0]);
    assert(buf[1] == m[1]);
    assert(buf[2] == m[2]);
    assert(buf[3] == m[3]);
  }
  {
    bool buf[] = {false, true, true, false};
    ex::native_simd_mask<int> m(buf, ex::overaligned<32>);
    assert(buf[0] == m[0]);
    assert(buf[1] == m[1]);
    assert(buf[2] == m[2]);
    assert(buf[3] == m[3]);
  }

}

int main() { test_load_ctor(); }