//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// UNSUPPORTED:c++03, c++11, c++14

// <experimental/simd>
//
// template <class T, class Abi>
// simd<T, Abi>
// clamp(const simd<T, Abi>& v, const simd<T, Abi>& lo, const simd<T, Abi>& hi);

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

void test_clamp() {
  auto actual = clamp(ex::fixed_size_simd<int, 16>([](int i) { return i; }),
                      ex::fixed_size_simd<int, 16>([](int) { return 5; }),
                      ex::fixed_size_simd<int, 16>([](int) { return 10; }));

  int expected[16] = {5,5,5,5,5,5,6,7,8,9,10,10,10,10,10,10};

  assert(
      equal(ex::fixed_size_simd<int, 16>(expected, ex::element_aligned_tag()), actual));
}

int main() { test_clamp(); }