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
// template <class T, class Abi>
// simd<T, Abi>
// max(const simd<T, Abi>&, const simd<T, Abi>&) noexcept;

#include <cassert>
#include <cstdint>
#include <algorithm>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

template <typename T, typename Abi>
bool equal(ex::simd<T, Abi> a, ex::simd<T, Abi> b){
  for(size_t i = 0; i < a.size(); i++){
    if(a[i] != b[i]){
      return false;
    }
  }
  return true;
}

void test_max() {
  int n = (int)ex::native_simd<int>::size();
  assert(
      equal(max(ex::native_simd<int>([](int i) { return i; }),
                ex::native_simd<int>([n](int i) { return n - 1 - i; })),
            ex::native_simd<int>([n](int i) { return std::max(i, n - 1 - i); })));
}

int main() { test_max(); }