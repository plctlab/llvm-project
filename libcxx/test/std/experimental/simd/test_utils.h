//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef TEST_UTIL_H
#define TEST_UTIL_H

#include <cassert>
#include <experimental/simd>

namespace ex = std::experimental::parallelism_v2;

template <typename T>
struct is_tuple : public std::false_type {};
 
template <typename... Ts>
struct is_tuple<std::tuple<Ts...>> : public std::true_type {};

template <class T>
struct is_simd_reference : std::false_type {};

template <class _Tp, class _Storage, class _ValueType>
struct is_simd_reference<ex::__simd_reference<_Tp, _Storage, _ValueType>> : std::true_type {};

template <class SimdAbi, class _Tp>
void assert_simd_value_correct(const ex::simd<_Tp, SimdAbi>& origin_simd, _Tp* expected_value) {
  for (size_t i = 0; i < origin_simd.size(); ++i)
    assert(origin_simd[i] == expected_value[i]);
}

template <class SimdAbi, class _Tp>
void assert_simd_mask_value_correct(const ex::simd_mask<_Tp, SimdAbi>& origin_mask, bool* expected_value) {
  for (size_t i = 0; i < origin_mask.size(); ++i)
    assert(origin_mask[i] == expected_value[i]);
}

template <std::size_t ArraySize, class SimdAbi, class _Tp>
void assert_simd_value_correct(const ex::simd<_Tp, SimdAbi>& origin_simd,
                               const std::array<_Tp, ArraySize>& expected_value) {
  for (size_t i = 0; i < origin_simd.size(); ++i)
    assert(origin_simd[i] == expected_value[i]);
}

template <std::size_t ArraySize, class SimdAbi, class _Tp>
void assert_simd_mask_value_correct(const ex::simd_mask<_Tp, SimdAbi>& origin_mask,
                                    const std::array<_Tp, ArraySize>& expected_value) {
  for (size_t i = 0; i < origin_mask.size(); ++i)
    assert(origin_mask[i] == expected_value[i]);
}

template <std::size_t ArraySize, class ArrayType, class SimdAbi, class _Tp>
void assert_simd_value_correct(const ex::simd<_Tp, SimdAbi>& origin_simd,
                               const std::array<ArrayType, ArraySize>& expected_value) {
  for (size_t i = 0; i < origin_simd.size(); ++i)
    assert(origin_simd[i] == static_cast<_Tp>(expected_value[i]));
}

template <std::size_t ArraySize, class ArrayType, class SimdAbi, class _Tp>
void assert_simd_mask_value_correct(const ex::simd_mask<_Tp, SimdAbi>& origin_mask,
                                    const std::array<ArrayType, ArraySize>& expected_value) {
  for (size_t i = 0; i < origin_mask.size(); ++i)
    assert(origin_mask[i] == static_cast<_Tp>(expected_value[i]));
}

template <class F, std::size_t _Np, class _Tp, class SimdAbi, class... SimdAbis>
void test_simd_abi();

template <class F, class _Tp, std::size_t... _Np>
void test_all_simd_abi(std::integer_sequence<std::size_t, _Np...>) {
  using namespace ex;

  (test_simd_abi<F,
                 _Np + 1,
                 _Tp,
                //  simd_abi::native<_Tp>,
                //  simd_abi::fixed_size<_Np + 1>,
                //  simd_abi::scalar,
                //  simd_abi::compatible<_Tp>,
                 simd_abi::deduce_t<_Tp, _Np + 1>>(),
   ...);
}

template <class F>
void test_all_simd_abi() {
  // test_all_simd_abi<F, long double>(std::make_integer_sequence<std::size_t, 1>());
  // test_all_simd_abi<F, double>(std::make_integer_sequence<std::size_t, 1>());
  // test_all_simd_abi<F, float>(std::make_integer_sequence<std::size_t, 1>());
  // test_all_simd_abi<F, long long>(std::make_integer_sequence<std::size_t, 1>());
  // test_all_simd_abi<F, unsigned long long>(std::make_integer_sequence<std::size_t, 1>());
  // test_all_simd_abi<F, long>(std::make_integer_sequence<std::size_t, 1>());
  // test_all_simd_abi<F, unsigned long>(std::make_integer_sequence<std::size_t, 1>());
  test_all_simd_abi<F, int>(std::make_integer_sequence<std::size_t, 5>());
  // test_all_simd_abi<F, unsigned int>(std::make_integer_sequence<std::size_t, 1>());
  // test_all_simd_abi<F, short>(std::make_integer_sequence<std::size_t, 1>());
  // test_all_simd_abi<F, unsigned short>(std::make_integer_sequence<std::size_t, 1>());
  // test_all_simd_abi<F, wchar_t>(std::make_integer_sequence<std::size_t, 1>());
  // test_all_simd_abi<F, signed char>(std::make_integer_sequence<std::size_t, 1>());
  // test_all_simd_abi<F, unsigned char>(std::make_integer_sequence<std::size_t, 1>());
  // test_all_simd_abi<F, char32_t>(std::make_integer_sequence<std::size_t, 1>());
  // test_all_simd_abi<F, char16_t>(std::make_integer_sequence<std::size_t, 1>());
}

#include <iostream>
#include <algorithm>
#include <array>
#include <cstddef>
#include <string_view>

namespace impl
{
    template <typename T>
    [[nodiscard]] constexpr std::string_view RawTypeName()
    {
        #ifndef _MSC_VER
        return __PRETTY_FUNCTION__;
        #else
        return __FUNCSIG__;
        #endif
    }

    struct TypeNameFormat
    {
        std::size_t junk_leading = 0;
        std::size_t junk_total = 0;
    };

    constexpr TypeNameFormat type_name_format = []{
        TypeNameFormat ret;
        std::string_view sample = RawTypeName<int>();
        ret.junk_leading = sample.find("int");
        ret.junk_total = sample.size() - 3;
        return ret;
    }();
    static_assert(type_name_format.junk_leading != std::size_t(-1), "Unable to determine the type name format on this compiler.");

    template <typename T>
    static constexpr auto type_name_storage = []{
        std::array<char, RawTypeName<T>().size() - type_name_format.junk_total + 1> ret{};
        std::copy_n(RawTypeName<T>().data() + type_name_format.junk_leading, ret.size() - 1, ret.data());
        return ret;
    }();
}

template <typename T>
[[nodiscard]] constexpr std::string_view TypeName()
{
    return {impl::type_name_storage<T>.data(), impl::type_name_storage<T>.size() - 1};
}

template <typename T>
[[nodiscard]] constexpr const char *TypeNameCstr()
{
    return impl::type_name_storage<T>.data();
}

#endif // TEST_UTIL_H