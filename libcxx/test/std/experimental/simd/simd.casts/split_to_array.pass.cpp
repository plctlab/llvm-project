

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
// [simd.casts]
// template <class V, class Abi>
// array<V, simd_size_v<typename V::value_type, Abi> / V::size()> split(
// const simd<typename V::value_type, Abi>&);

#include <experimental/simd>
#include <cstdint>
#include<array>
#include <cassert>
#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;

template<typename _SimdType,typename _Abi>
void test_split()
{
    ex::simd<int32_t,_Abi> data([](int i) { return 8 - i; });
    { 
        auto temp =  split<_SimdType,_Abi>(data);
        size_t k = 0;
        for(size_t i = 0; i < temp.size(); ++i){
            for(size_t j = 0; j < temp[i].size(); ++j){
                assert(temp[i][j] == data[k]);
                ++k;
            }
        }
    }
}

int main(int, char**) {
  test_split<ex::native_simd<int32_t>,ex::simd_abi::native<int32_t>>();
  test_split<ex::simd<int32_t,ex::simd_abi::compatible<int32_t>>,ex::simd_abi::compatible<int32_t>>();
  test_split<ex::fixed_size_simd<int32_t,1>,ex::simd_abi::fixed_size<8>>();
  test_split<ex::fixed_size_simd<int32_t,2>,ex::simd_abi::fixed_size<8>>();
  test_split<ex::fixed_size_simd<int32_t,4>,ex::simd_abi::fixed_size<8>>();
  test_split<ex::fixed_size_simd<int32_t,8>,ex::simd_abi::fixed_size<8>>();
  return 0;
}
