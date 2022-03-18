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
// loads [simd_mask.load]
// template <class Flags> void copy_from(const value_type* mem, Flags);

#include <experimental/simd>
#include <cstdint>
#include <cassert>

#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;

template <class T, class... Args>
auto not_supported_load(Args&&... args) -> decltype(
    std::declval<ex::native_simd<T>>().copy_from(std::forward<Args>(args)...),
    void()) = delete;

template <class T>
void not_supported_load(...) {}

template <class T, class... Args>
auto supported_load(Args&&... args) -> decltype(
    std::declval<ex::native_simd<T>>().copy_from(std::forward<Args>(args)...),
    void()) {}

template <class T>
void supported_load(...) = delete;

void compile_load() {
  supported_load<int>((int*)nullptr, ex::element_aligned_tag());
  supported_load<uint32_t>((int*)nullptr, ex::element_aligned_tag());
  supported_load<double>((float*)nullptr, ex::element_aligned_tag());
  supported_load<uint16_t>((unsigned int*)nullptr, ex::element_aligned_tag());
  supported_load<uint32_t>((float*)nullptr, ex::element_aligned_tag());

  not_supported_load<int>((int*)nullptr, int());
}

template <typename Simd_MaskType>
void test_load() {
  alignas(8) bool buffer[] = {1, 0, 1, 1};
  {
    Simd_MaskType a;
    a.copy_from(buffer, ex::element_aligned_tag());
    assert(a[0] == 1);
    assert(a[1] == 0);
    assert(a[2] == 1);
    assert(a[3] == 1);
  }
  {
    Simd_MaskType a;
    a.copy_from(buffer, ex::vector_aligned_tag());
    assert(a[0] == 1);
    assert(a[1] == 0);
    assert(a[2] == 1);
    assert(a[3] == 1);
  }
  {
    Simd_MaskType a;
    a.copy_from(buffer, ex::overaligned_tag<8>());
    assert(a[0] == 1);
    assert(a[1] == 0);
    assert(a[2] == 1);
    assert(a[3] == 1);
  }

  {
    Simd_MaskType a;
    a.copy_from(buffer, ex::element_aligned);
    assert(a[0] == 1);
    assert(a[1] == 0);
    assert(a[2] == 1);
    assert(a[3] == 1);
  }
  {
    Simd_MaskType a;
    a.copy_from(buffer, ex::vector_aligned);
    assert(a[0] == 1);
    assert(a[1] == 0);
    assert(a[2] == 1);
    assert(a[3] == 1);
  }
  {
    Simd_MaskType a;
    a.copy_from(buffer, ex::overaligned<8>);
    assert(a[0] == 1);
    assert(a[1] == 0);
    assert(a[2] == 1);
    assert(a[3] == 1);
  }
}


int main(int, char**) {

  assert(ex::native_simd_mask<int32_t>::size() >= 4);
  test_load<ex::native_simd_mask<int32_t>>();
  test_load<ex::fixed_size_simd_mask<int32_t, 4>>();
  return 0;
}