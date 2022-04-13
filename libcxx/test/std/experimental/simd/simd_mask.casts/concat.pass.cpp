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
// template <class T, class... Abis>
// simd_mask<T, abi_for_size_t<T, (simd_size_v<T, Abis> + ...)>> concat(const simd_mask<T, Abis>&...);

#include <experimental/simd>
#include <cstdint>
#include <cassert>
#include "test_macros.h"

namespace ex = std::experimental::parallelism_v2;

template<class _Tp>
void test_concat()
{
    bool buff_0[] = {0,1,1,1,0};
    bool buff_1[] = {0,1,0,1,1,0,1,0};
    ex::native_simd_mask<_Tp> a([](_Tp i){return i;});
    ex::fixed_size_simd_mask<_Tp,5> b(buff_0,ex::element_aligned_tag());
    ex::simd_mask<_Tp> c([](_Tp i){return i;});
    ex::fixed_size_simd_mask<_Tp,8> d(buff_1,ex::element_aligned_tag());

    {
        auto temp = ex::concat<_Tp,ex::simd_abi::native<_Tp>,ex::simd_abi::fixed_size<5>,ex::simd_abi::compatible<_Tp>>(a,b,c);
        [&](){
            int k = 0;
            for(size_t i = 0; i < a.size(); ++i){
                assert(temp[k] == a[i]);
                ++k;
            }

            for(size_t i = 0; i < b.size(); ++i){
                assert(temp[k] == b[i]);
                ++k;
            }

            for(size_t i = 0; i < c.size(); ++i){
                assert(temp[k] == c[i]);
                ++k;
            }

        }();
    }

    {
        auto temp = ex::concat<_Tp,ex::simd_abi::native<_Tp>,ex::simd_abi::fixed_size<5>,ex::simd_abi::fixed_size<8>>(a,b,d);
        [&](){
            int k = 0;
            for(size_t i = 0; i < a.size(); ++i){
                assert(temp[k] == a[i]);
                ++k;
            }

            for(size_t i = 0; i < b.size(); ++i){
                assert(temp[k] == b[i]);
                ++k;
            }

            for(size_t i = 0; i < d.size(); ++i){
                assert(temp[k] == d[i]);
                ++k;
            }

        }();
    }

    {
        auto temp = ex::concat<_Tp,ex::simd_abi::fixed_size<5>,ex::simd_abi::compatible<_Tp>,ex::simd_abi::fixed_size<8>>(b,c,d);
        [&](){
            int k = 0;
            for(size_t i = 0; i < b.size(); ++i){
                assert(temp[k] == b[i]);
                ++k;
            }

            for(size_t i = 0; i < c.size(); ++i){
                assert(temp[k] == c[i]);
                ++k;
            }

            for(size_t i = 0; i < d.size(); ++i){
                assert(temp[k] == d[i]);
                ++k;
            }

        }();
    }

    {
        auto temp = ex::concat<_Tp,ex::simd_abi::native<_Tp>,ex::simd_abi::compatible<_Tp>,ex::simd_abi::fixed_size<8>>(a,c,d);
        [&](){
            int k = 0;
            for(size_t i = 0; i < a.size(); ++i){
                assert(temp[k] == a[i]);
                ++k;
            }

            for(size_t i = 0; i < c.size(); ++i){
                assert(temp[k] == c[i]);
                ++k;
            }

            for(size_t i = 0; i < d.size(); ++i){
                assert(temp[k] == d[i]);
                ++k;
            }

        }();
    }

    {
        auto temp = ex::concat<_Tp,ex::simd_abi::fixed_size<5>>(b);
        [&](){
            int k = 0;
            for(size_t i = 0; i < b.size(); ++i){
                assert(temp[k] == b[i]);
                ++k;
            }
        }();
    }

}

int main()
{
    test_concat<int32_t>();
    test_concat<float>();
    test_concat<double>();
}