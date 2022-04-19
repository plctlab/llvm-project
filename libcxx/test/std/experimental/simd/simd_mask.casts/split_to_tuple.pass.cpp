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
// template <size_t... Sizes, class T, class Abi>
// tuple<simd_mask<T, abi_for_size_t<Sizes>>...> split(const simd_mask<T, Abi>&);

#include <experimental/simd>
#include <cstdint>
#include <cassert>
#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;


template<typename _SimdMaskType,typename _Abi>
void test_split()
{
  bool buffer[] = {1, 0, 1, 1};
  _SimdMaskType M;
  M.copy_from(buffer, ex::element_aligned_tag());
  
 { 
  auto temp =  split<2,2>(M);
  int k = 0;
  for_tuple(temp,[M,&k](auto&& item)
  {
    for(size_t i = 0; i < item.size(); ++i){
      assert(item[i] == M[k]);
      ++k;
    }
  });
 }

 { 
  auto temp =  split<1,3>(M);
  int k = 0;
  for_tuple(temp,[M,&k](auto&& item)
  {
    for(size_t i = 0; i < item.size(); ++i){
      assert(item[i] == M[k]);
      ++k;
    }
  });
 }

 { 
  auto temp =  split<3,1>(M);
  int k = 0;
  for_tuple(temp,[M,&k](auto&& item)
  {
    for(size_t i = 0; i < item.size(); ++i){
      assert(item[i] == M[k]);
      ++k;
    }
  });
 }
}

int main(int, char**) {
  test_split<ex::native_simd_mask<int>,ex::simd_abi::native<int>>();
  test_split<ex::fixed_size_simd_mask<int,4>,ex::simd_abi::fixed_size<4>>();
  //test_split<ex::fixed_size_simd_mask<int,15>,ex::simd_abi::fixed_size<15>>();
}
