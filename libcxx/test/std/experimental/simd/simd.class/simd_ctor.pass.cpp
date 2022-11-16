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
#include<iostream>
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
    constexpr size_t array_size = ex::simd_size_v<_Tp, SimdAbi>;
    std::array<_Tp, array_size> origin_value;
    for (size_t i = 0; i < array_size; ++i)
      origin_value[i] = static_cast<_Tp>(3);

    ex::simd<_Tp, SimdAbi> expected_simd_from_vectorizable_type(ex::simd<_Tp, SimdAbi>(static_cast<_Tp>(3)));
    assert_simd_value_correct<array_size>(expected_simd_from_vectorizable_type, origin_value);

    zero_init<_Tp> implicit_convert_to_3(3);
    ex::simd<_Tp, SimdAbi> expected_simd_from_implicit_convert(std::move(implicit_convert_to_3));
    assert_simd_value_correct<array_size>(expected_simd_from_implicit_convert, origin_value);

    int int_value_3 = 3;
    ex::simd<_Tp, SimdAbi> expected_simd_from_int(std::move(int_value_3));
    assert_simd_value_correct<array_size>(expected_simd_from_int, origin_value);

    if constexpr (std::is_unsigned_v<_Tp>) {
      unsigned int uint_value_3 = static_cast<unsigned int>(3);
      ex::simd<_Tp, SimdAbi> expected_simd_from_uint(std::move(uint_value_3));
      assert_simd_value_correct<array_size>(expected_simd_from_uint, origin_value);
    }
  }
};

struct CheckFixedSimdCtor {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    if constexpr (std::is_same_v<SimdAbi, ex::simd_abi::fixed_size<_Np>>) {
      constexpr size_t array_size = ex::simd_size_v<_Tp, SimdAbi>;
      if constexpr (std::is_integral_v<_Tp>) {
        if constexpr (std::is_same_v<_Tp, char> || std::is_same_v<_Tp, unsigned char> ||
                      std::is_same_v<_Tp, signed char>) {
          return;
        }
        {
          ex::simd<char, SimdAbi> char_simd([](char i) { return i; });
          ex::simd<_Tp, SimdAbi> convert_from_char(char_simd);
          // std::array<char, array_size> expected_value;
          // for (size_t i = 0; i < array_size; i++)
          //   expected_value[i] = static_cast<char>(i);
          // assert_simd_value_correct<array_size, char>(convert_from_char, expected_value);
        }
        if constexpr (std::is_same_v<_Tp, short> || std::is_same_v<_Tp, unsigned short>) {
          return;
        }
        {
          ex::simd<short, SimdAbi> short_simd([](short i) { return i; });
          ex::simd<_Tp, SimdAbi> convert_from_short(short_simd);

          std::array<short, array_size> expected_value_in_short;
          for (size_t i = 0; i < array_size; i++)
            expected_value_in_short[i] = static_cast<short>(i);
          assert_simd_value_correct<array_size, short>(convert_from_short, expected_value_in_short);
        }
        if constexpr (std::is_same_v<_Tp, wchar_t> || std::is_same_v<_Tp, char16_t>) {
          return;
        }
        {
          ex::simd<wchar_t, SimdAbi> wchar_simd([](wchar_t i) { return i; });
          ex::simd<_Tp, SimdAbi> convert_from_wchar(wchar_simd);

          std::array<wchar_t, array_size> expected_value_in_wchar;
          for (size_t i = 0; i < array_size; i++)
            expected_value_in_wchar[i] = static_cast<wchar_t>(i);
          assert_simd_value_correct<array_size, wchar_t>(convert_from_wchar, expected_value_in_wchar);

          ex::simd<char16_t, SimdAbi> char16_simd([](char16_t i) { return i; });
          ex::simd<_Tp, SimdAbi> convert_from_char16(char16_simd);

          std::array<char16_t, array_size> expected_value_in_char16;
          for (size_t i = 0; i < array_size; i++)
            expected_value_in_char16[i] = static_cast<char16_t>(i);
          assert_simd_value_correct<array_size, char16_t>(convert_from_char16, expected_value_in_char16);
        }
        if constexpr (std::is_same_v<_Tp, int> || std::is_same_v<_Tp, unsigned int> || std::is_same_v<_Tp, char32_t>) {
          return;
        }
        {
          ex::simd<int, SimdAbi> int_simd([](int i) { return i; });
          ex::simd<_Tp, SimdAbi> convert_from_int(int_simd);

          std::array<int, array_size> expected_value_in_int;
          for (size_t i = 0; i < array_size; i++)
            expected_value_in_int[i] = static_cast<int>(i);
          assert_simd_value_correct<array_size, int>(convert_from_int, expected_value_in_int);

          ex::simd<char32_t, SimdAbi> char32_simd([](char32_t i) { return i; });
          ex::simd<_Tp, SimdAbi> convert_from_char32(int_simd);

          std::array<char32_t, array_size> expected_value_in_char32;
          for (size_t i = 0; i < array_size; i++)
            expected_value_in_char32[i] = static_cast<char32_t>(i);
          assert_simd_value_correct<array_size, char32_t>(convert_from_char32, expected_value_in_char32);
        }
        if constexpr (std::is_same_v<_Tp, long> || std::is_same_v<_Tp, unsigned long>) {
          return;
        }
        {
          ex::simd<long, SimdAbi> long_simd([](long i) { return i; });
          ex::simd<_Tp, SimdAbi> convert_from_long(long_simd);

          std::array<long, array_size> expected_value_in_long;
          for (size_t i = 0; i < array_size; i++)
            expected_value_in_long[i] = static_cast<long>(i);
          assert_simd_value_correct<array_size, long>(convert_from_long, expected_value_in_long);
        }
      } else {
        {
          const ex::simd<float, SimdAbi> float_simd([](float i) { return i; });
          ex::simd<_Tp, SimdAbi> convert_from_float(float_simd);

          std::array<float, array_size> expected_value_in_float;
          for (size_t i = 0; i < array_size; i++)
            expected_value_in_float[i] = static_cast<float>(i);
          assert_simd_value_correct<array_size, float>(convert_from_float, expected_value_in_float);
        }
        {
          const ex::simd<double, SimdAbi> double_simd([](double i) { return i; });
          std::cout << double_simd.size()<<'\n';
          
          // ex::simd<_Tp, SimdAbi> convert_from_double(double_simd);

          // std::array<double, array_size> expected_value_in_double;
          // for (size_t i = 0; i < array_size; i++)
          //   expected_value_in_double[i] = static_cast<double>(i);
          // assert_simd_value_correct<array_size, double>(convert_from_double, expected_value_in_double);
        }
        {
          const ex::simd<long double, SimdAbi> long_double_simd([](long double i) { return i; });
          std::cout << long_double_simd.size()<<'\n';
          // ex::simd<_Tp, SimdAbi> convert_from_long_double(long_double_simd);

          // std::array<long double, array_size> expected_value_in_long_double;
          // for (size_t i = 0; i < array_size; i++)
          //   expected_value_in_long_double[i] = static_cast<long double>(i);
          // assert_simd_value_correct<array_size, long double>(convert_from_long_double, expected_value_in_long_double);
        }
      }
    }
  }
};

struct CheckGenerateSimdCtor {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    ex::simd<_Tp, SimdAbi> origin_simd([](_Tp i) { return i; });

    for (size_t i = 0; i < origin_simd.size(); ++i) {
      assert(origin_simd[i] == static_cast<_Tp>(i));
    }
  }
};

// credit to: https://stackoverflow.com/a/466242
constexpr size_t next_pow2(size_t v) noexcept {
  v--;
  v |= v >> 1;
  v |= v >> 2;
  v |= v >> 4;
  v |= v >> 8;
  v |= v >> 16;
  v++;
  return v;
}

struct CheckLoadSimdCtor {
  template <class _Tp, class SimdAbi, std::size_t _Np>
  void operator()() {
    {
      constexpr auto alignas_size = ex::memory_alignment_v<ex::simd<_Tp, SimdAbi>, _Tp>;

      constexpr auto array_length = ex::simd_size_v<_Tp, SimdAbi>;

      alignas(alignas_size) _Tp buffer[array_length];
      for (size_t i = 0; i < array_length; i++)
        buffer[i] = static_cast<_Tp>(i + 1);

      ex::simd<_Tp, SimdAbi> origin_simd(buffer, ex::vector_aligned_tag());
      assert_simd_value_correct(origin_simd, buffer);
    }

    {
      constexpr auto alignas_size = std::max(next_pow2(sizeof(_Tp)), next_pow2(_Np));

      constexpr auto array_length = ex::simd_size_v<_Tp, SimdAbi>;

      alignas(alignas_size) _Tp buffer[array_length];
      for (size_t i = 0; i < array_length; i++)
        buffer[i] = static_cast<_Tp>(i);

      ex::simd<_Tp, SimdAbi> origin_simd(buffer, ex::overaligned_tag<alignas_size>());
      assert_simd_value_correct(origin_simd, buffer);
    }

    {
      constexpr auto alignas_size = std::max(next_pow2(sizeof(_Tp)), next_pow2(alignof(_Tp)));

      constexpr auto array_length = ex::simd_size_v<_Tp, SimdAbi>;

      alignas(alignas_size) _Tp buffer[array_length];
      for (size_t i = 0; i < array_length; i++)
        buffer[i] = static_cast<_Tp>(i);

      ex::simd<_Tp, SimdAbi> origin_simd(buffer, ex::element_aligned_tag());
      assert_simd_value_correct(origin_simd, buffer);
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
  test_all_simd_abi<CheckFixedSimdCtor>();
  test_all_simd_abi<CheckGenerateSimdCtor>();
  test_all_simd_abi<CheckLoadSimdCtor>();
}
