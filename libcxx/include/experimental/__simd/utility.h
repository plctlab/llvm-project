// -*- C++ -*-
//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP_EXPERIMENTAL___SIMD_UTILITY_H
#define _LIBCPP_EXPERIMENTAL___SIMD_UTILITY_H

#include <cstddef>
#include <cstdint>
#include <tuple>

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

class _Bool {
  const bool __v;

public:
  constexpr _Bool(bool __b) : __v(__b) {}
  _Bool(int) = delete;
  constexpr operator bool() const { return __v; }
};

// TODO: replace it by std::bit_ceil when bump to C++20
constexpr size_t __next_pow_of_2(size_t __val) {
  size_t __pow = 1;
  while (__pow < __val)
    __pow <<= 1;
  return __pow;
}

template <class _Tp>
auto __choose_mask_type() {
  if constexpr (sizeof(_Tp) == 1) {
    return uint8_t{};
  } else if constexpr (sizeof(_Tp) == 2) {
    return uint16_t{};
  } else if constexpr (sizeof(_Tp) == 4) {
    return uint32_t{};
  } else if constexpr (sizeof(_Tp) == 8) {
    return uint64_t{};
  }
#ifndef _LIBCPP_HAS_NO_INT128
  else if constexpr (sizeof(_Tp) == 16) {
    return __uint128_t{};
  }
#endif
}

template <class _Tp>
auto __set_all_bits(bool __v) {
  using _Up = decltype(__choose_mask_type<_Tp>());
  _Up __res = 0;
  for (unsigned long __i = 0; __i < __CHAR_BIT__ * sizeof(_Tp); __i++)
    __res |= static_cast<_Up>(__v) << __i;
  return __res;
}

template <class _To, class _From>
constexpr decltype(_To{std::declval<_From>()}, true) __is_non_narrowing_convertible_impl(_From) {
  return true;
}

template <class _To>
constexpr bool __is_non_narrowing_convertible_impl(...) {
  return false;
}

template <class _From, class _To>
constexpr bool __is_non_narrowing_arithmetic_convertible() {
  if constexpr (std::is_arithmetic_v<_To> && std::is_arithmetic_v<_From>)
    return __is_non_narrowing_convertible_impl<_To>(_From{});
  else
    return false;
}

template <class _Tp, class... _Args>
constexpr _Tp __variadic_sum(_Args... __args) {
  return (static_cast<_Tp>(__args) + ...);
}

template <class _Tp>
constexpr bool __is_vectorizable() {
  return std::is_arithmetic_v<_Tp> && !std::is_const_v<_Tp> && !std::is_volatile_v<_Tp> && !std::is_same_v<_Tp, bool>;
}

template <class _Tp, class _Up>
constexpr bool __can_broadcast() {
  return (std::is_arithmetic_v<_Up> && __is_non_narrowing_arithmetic_convertible<_Up, _Tp>()) ||
         (!std::is_arithmetic_v<_Up> && std::is_convertible_v<_Up, _Tp>) ||
         std::is_same_v<std::remove_const_t<_Up>, int> ||
         (std::is_same_v<std::remove_const_t<_Up>, unsigned int> && std::is_unsigned_v<_Tp>);
}

template <class _Tp, class _Generator, size_t... __indicies>
constexpr decltype(std::forward_as_tuple(std::declval<_Generator>()(std::integral_constant<size_t, __indicies>())...),
                   bool())
__can_generate(std::index_sequence<__indicies...>) {
  return !__variadic_sum<bool>(
      !__can_broadcast<_Tp, decltype(std::declval<_Generator>()(std::integral_constant<size_t, __indicies>()))>()...);
}

template <class _Tp, class _Generator>
bool __can_generate(...) {
  return false;
}

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP_EXPERIMENTAL___SIMD_UTILITY_H
