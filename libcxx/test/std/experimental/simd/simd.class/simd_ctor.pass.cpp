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
// [simd.class]
// template<class U> simd(U&& value) noexcept;
// template<class U> simd(const simd<U, simd_abi::fixed_size<size()>>&) noexcept;
// template<class G> explicit simd(G&& gen) noexcept;
// template<class U, class Flags> simd(const U* mem, Flags f);

#include "../test_utils.h"
#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;
template <typename T>
class zero_init {
  T val;

public:
  zero_init() : val(static_cast<T>(0)) {}
  zero_init(T val) : val(val) {}
  operator T&() { return val; }
  operator T() const { return val; }
};
struct CheckBroadCastSimdCtor {
  template <class _Tp, class SimdAbi, std::size_t>
  void operator()() {
    ex::simd<_Tp, SimdAbi> origin_simd(static_cast<_Tp>(3));

    ex::simd<_Tp, SimdAbi> expected_simd_from_vectorizable_type(std::move(origin_simd));
    assert(ex::all_of(expected_simd_from_vectorizable_type == origin_simd) == true);

    zero_init<_Tp> implicit_convert_to_3 = 3;
    ex::simd<_Tp, SimdAbi> expected_simd_from_implicit_convert(std::move(implicit_convert_to_3));
    assert(ex::all_of(expected_simd_from_implicit_convert == origin_simd) == true);

    int int_value_3 = static_cast<int>(3);
    ex::simd<_Tp, SimdAbi> expected_simd_from_int(std::move(int_value_3));
    assert(ex::all_of(expected_simd_from_int == origin_simd) == true);

    if constexpr (std::is_unsigned_v<_Tp>) {
      unsigned int uint_value_3 = static_cast<unsigned int>(3);
      ex::simd<_Tp, SimdAbi> expected_simd_from_uint(std::move(uint_value_3));
      assert(ex::all_of(expected_simd_from_uint == origin_simd) == true);
    }
  }
};

/*
The conversion rank above increases in order bool, signed char, short, int, long, long long (since C++11).
The rank of any unsigned type is equal to the rank of the corresponding signed type.
The rank of char is equal to the rank of signed char and unsigned char. 
The ranks of char8_t, (since C++20)char16_t, char32_t, and (since C++11)wchar_t are equal to the ranks of their corresponding underlying types.

— abi_type is simd_abi::fixed_size<size()>, and
(4.2) — every possible value of U can be represented with type value_type, and
(4.3) — if both U and value_type are integral, the integer conversion rank (C++17 §7.15) of value_type
is greater than the integer conversion rank of U.
*/
struct CheckFixedSimdCtor{
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    if constexpr (std::is_same_v<SimdAbi, ex::simd_abi::fixed_size<_Np>) {
        
        ex::simd<_Tp, SimdAbi> origin_simd;
        if constexpr (std::is_integral_v<_Tp> ) {
/*
            if constexpr(std::is_same_v<_Tp, signed char> || std::is_same_v<_Tp, char> || std::is_same_v<_Tp, unsigned char>) {
                ex::simd<bool, SimdAbi> fixed_size_bool_simd([](_Tp i){return static_cast<_Tp>(i);});
                origin_simd(fixed_size_bool_simd);
                for (size_t i = 0; i < )
            }
            if constexpr(std::is_same_v<_Tp, signed short>|| std::is_same_v<_Tp, unsigned short>) {
                //copy from char simd
            }
            if constexpr(std::is_same_v<_Tp, signed int>|| std::is_same_v<_Tp, unsigned int>) {
                // copy from short simd
            }
            if constexpr(std::is_same_v<_Tp, signed long>|| std::is_same_v<_Tp, unsigned long>) {
                // copy from int simd
            }
            if constexpr(std::is_same_v<_Tp, signed long long>|| std::is_same_v<_Tp, unsigned long long >) {
                // copy from long simd and long long simd
            } else  if constexpr(std::is_same_v<_Tp, signed long>|| std::is_same_v<_Tp, unsigned long>) {
                // copy from int simd
            } else if constexpr(std::is_same_v<_Tp, signed int>|| std::is_same_v<_Tp, unsigned int>) {
                // copy from short simd
            }else  if constexpr(std::is_same_v<_Tp, signed short>|| std::is_same_v<_Tp, unsigned short>) {
                //copy from char simd
            } else {

            }


            if () {
                // A B C D
            } else if () {
                // B C D
            } else if () // C D 
            */
        }
        else {
            const ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i){return i;});
            ex::simd<_Tp, SimdAbi> expected_simd(origin_simd);
            assert(ex::all_of(expected_simd == origin_simd) == true);
        }
    }
  }
};
template <class F, std::size_t _Np, class _Tp>
void test_simd_abi() {
}
template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi() {
  F{}.template operator()<_Tp, SimdAbi, _Np>();
  test_simd_abi<F, _Np, _Tp, SimdAbis...>();
}
int main(int, char**) {
  test_all_simd_abi<CheckBroadCastSimdCtor>();
  return 0;
}