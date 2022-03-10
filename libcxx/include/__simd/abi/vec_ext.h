// -*- C++ -*-
//===------------------------ __simd/abi/vec_ext.h ------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#ifndef _LIBCPP___SIMD_ABI_VEC_EXT_H
#define _LIBCPP___SIMD_ABI_VEC_EXT_H

#include <experimental/__config>
#include <__simd/abi/decl.h>

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD_ABI

template <int _Np>
struct __vec_ext {
  static constexpr bool __is_abi_tag = _Np > 0;
  static constexpr size_t __simd_size = _Np;
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD_ABI

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

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
}

template <class _Tp, int _Np>
struct __simd_storage_vec_ext {
#if defined(_LIBCPP_COMPILER_CLANG_BASED)
  _Tp __data __attribute__((vector_size(sizeof(_Tp) * _Np)));
#else
  _Tp __data __attribute__((vector_size(__next_pow_of_2(sizeof(_Tp) * _Np))));
#endif

  _Tp __get(size_t __idx) const noexcept { return __data[__idx]; }

  void __set(size_t __idx, _Tp __v) noexcept { __data[__idx] = __v; }
};

template <class _Tp, int _Np>
struct __mask_storage_vec_ext : __simd_storage_vec_ext<decltype(__choose_mask_type<_Tp>()), _Np> {};

template <class _Tp, int _Np>
struct __simd_traits<_Tp, simd_abi::__vec_ext<_Np>> {
  using _Simd = __simd_storage_vec_ext<_Tp, _Np>;
  using _Mask = __mask_storage_vec_ext<_Tp, _Np>;

  static _Simd __broadcast(_Tp __v) noexcept {
    return __generate([=](size_t) { return __v; });
  }

  template <class _Generator, size_t... _Is>
  static _Simd __generate_init(_Generator&& __g, std::index_sequence<_Is...>) {
    // _Simd specified here is to work around GCC
    return _Simd{{__g(std::integral_constant<size_t, _Is>())...}};
  }

  template <class _Generator>
  static _Simd __generate(_Generator&& __g) noexcept {
    return __generate_init(std::forward<_Generator>(__g), std::make_index_sequence<_Np>());
  }

  template <class _Up, class _Flags>
  static _Simd __load(const _Up* __mem, _Flags) noexcept {
    // TODO: optimized implementation
    return __generate([=](size_t __i) { return static_cast<_Tp>(__mem[__i]); });
  }

  template <class _Up, class _Flags>
  static void __store(_Simd __s, _Up* __mem, _Flags) noexcept {
    // TODO: optimized implementation
    for (size_t __i = 0; __i < _Np; __i++)
      __mem[__i] = static_cast<_Up>(__s.__data[__i]);
  }

  static void __increment(_Simd& __s) noexcept { ++__s.__data; }

  static void __decrement(_Simd& __s) noexcept { --__s.__data; }

  static _Simd __negate(_Simd __s) noexcept { return {!__s.__data}; }

  static _Simd __bitwise_not(_Simd __s) noexcept { return {~__s.__data}; }

  static _Simd __unary_minus(_Simd __s) noexcept { return {-__s.__data}; }

  static _Simd __plus(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data + __rhs.__data}; }

  static _Simd __minus(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data - __rhs.__data}; }

  static _Simd __multiplies(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data * __rhs.__data}; }

  static _Simd __divides(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data / __rhs.__data}; }

  static _Simd __modulus(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data % __rhs.__data}; }

  static _Simd __bitwise_and(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data & __rhs.__data}; }

  static _Simd __bitwise_or(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data | __rhs.__data}; }

  static _Simd __bitwise_xor(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data ^ __rhs.__data}; }

  static _Simd __shift_left(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data << __rhs.__data}; }

  static _Simd __shift_right(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data >> __rhs.__data}; }

  static _Simd __shift_left(_Simd __lhs, int __rhs) noexcept { return {__lhs.__data << __rhs}; }

  static _Simd __shift_right(_Simd __lhs, int __rhs) noexcept { return {__lhs.__data >> __rhs}; }

  static _Simd __equal_to(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data == __rhs.__data}; }

  static _Simd __not_equal_to(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data != __rhs.__data}; }

  static _Simd __less_equal(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data <= __rhs.__data}; }

  static _Simd __less(_Simd __lhs, _Simd __rhs) noexcept { return {__lhs.__data < __rhs.__data}; }

  static _Tp __hmin(_Simd __s) {
    _Tp __min = __s.__data[0];
    for (auto __v : __s.__data)
      __min = std::min(__min, __v);
    return __min;
  }

  static _Tp __hmax(_Simd __s) {
    _Tp __max = __s.__data[0];
    for (auto __v : __s.__data)
      __max = std::max(__max, __v);
    return __max;
  }

  static _Simd __min(_Simd __a, _Simd __b) noexcept {
    _Simd __r;
    for (size_t __i = 0; __i < _Np; ++__i)
      __r.__data[__i] = std::min(__a.__data[__i], __b.__data[__i]);
    return __r;
  }

  static _Simd __max(_Simd __a, _Simd __b) noexcept {
    _Simd __r;
    for (size_t __i = 0; __i < _Np; ++__i)
      __r.__data[__i] = std::max(__a.__data[__i], __b.__data[__i]);
    return __r;
  }

  static std::pair<_Simd, _Simd> __minmax(_Simd __a, _Simd __b) noexcept {
    _Simd __min, __max;
    for (size_t __i = 0; __i < _Np; ++__i) {
      __min.__data[__i] = std::min(__a.__data[__i], __b.__data[__i]);
      __max.__data[__i] = std::max(__a.__data[__i], __b.__data[__i]);
    }
    return {__min, __max};
  }

  static _Simd __clamp(_Simd __v, _Simd __lo, _Simd __hi) noexcept {
    _Simd __r;
    for (size_t __i = 0; __i < _Np; ++__i)
      __r.__data[__i] = std::min(std::max(__v.__data[__i], __lo.__data[__i]), __hi.__data[__i]);
    return __r;
  }

  static _Simd __masked_unary_minus(_Simd __s, _Mask __m) noexcept {
    _Simd __r;
    for (size_t __i = 0; __i < _Np; ++__i)
      __r.__data[__i] = __m.__data[__i] ? -__s.__data[__i] : __s.__data[__i];
    return __r;
  }

  static _Simd __masked_assign(_Simd& __s, _Mask __m, _Tp __v) noexcept {
    for (size_t __i = 0; __i < _Np; ++__i)
      __s.__data[__i] = __m.__data[__i] ? __v : __s.__data[__i];
    return __s;
  }
};

template <class _Tp, int _Np>
struct __mask_traits<_Tp, simd_abi::__vec_ext<_Np>> {
  using _Mask = __mask_storage_vec_ext<_Tp, _Np>;

  static _Mask __broadcast(_Tp __v) noexcept {
    return __generate([=](size_t) { return  static_cast<decltype(__choose_mask_type<_Tp>())>(__v); });
  }
 template <class _Generator, size_t... _Is>
  static _Mask __generate_init(_Generator&& __g, std::index_sequence<_Is...>) {
    // _Simd specified here is to work around GCC
    return _Mask{{__g(std::integral_constant<size_t, _Is>())...}};
  }

  template <class _Generator>
  static _Mask __generate(_Generator&& __g) noexcept {
    return __generate_init(std::forward<_Generator>(__g), std::make_index_sequence<_Np>());
  }


  template <class _Up, class _Flags>
  static _Mask __load(const _Up* __mem, _Flags) noexcept {
    // TODO: optimized implementation
    return __generate([=](size_t __i) { return static_cast<decltype(__choose_mask_type<_Tp>())>(__mem[__i]); });
  }

  template <class _Up, class _Flags>
  static void __store(_Mask __s, _Up* __mem, _Flags) noexcept {
    // TODO: optimized implementation
    for (size_t __i = 0; __i < _Np; __i++)
      __mem[__i] = static_cast<_Up>(__s.__data[__i]);
  }

  static _Mask __logical_and(_Mask __lhs, _Mask __rhs) noexcept { return {__lhs.__data & __rhs.__data}; }

  static _Mask __logical_or(_Mask __lhs, _Mask __rhs) noexcept { return {__lhs.__data | __rhs.__data}; }

  static _Mask __bitwise_and(_Mask __lhs, _Mask __rhs) noexcept { return {__lhs.__data & __rhs.__data}; }

  static _Mask __bitwise_or(_Mask __lhs, _Mask __rhs) noexcept { return {__lhs.__data | __rhs.__data}; }

  static _Mask __bitwise_xor(_Mask __lhs, _Mask __rhs) noexcept { return {__lhs.__data ^ __rhs.__data}; }

  static _Mask __equal_to(_Mask __lhs, _Mask __rhs) noexcept { return {__lhs.__data == __rhs.__data}; }

  static _Mask __not_equal_to(_Mask __lhs, _Mask __rhs) noexcept { return {__lhs.__data != __rhs.__data}; }

  static bool __all_of(_Mask __s) noexcept {
    for (auto __v : __s.__data)
      if (!__v)
        return false;
    return true;
  }

  static bool __any_of(_Mask __s) noexcept {
    for (auto __v : __s.__data)
      if (__v)
        return true;
    return false;
  }

  static bool __none_of(_Mask __s) noexcept {
    for (auto __v : __s.__data)
      if (__v)
        return false;
    return true;
  }

  static bool __some_of(_Mask __s) noexcept {
    for (size_t __i = 1; __i < _Np; ++__i)
      if (__s[__i] != __s[__i - 1])
        return true;
    return false;
  }

  static int __popcount(_Mask __s) noexcept {
    int __count = 0;
    for (auto __v : __s.__data)
      __count += __v != 0;
    return __count;
  }

  static int __find_first_set(_Mask __s) {
    size_t __i = 0;
    for (; __i < _Np; ++__i)
      if (__s.__data[__i])
        break;
    return __i;
  }

  static int __find_last_set(_Mask __s) {
    size_t __i = _Np - 1;
    for (; __i != -1; --__i)
      if (__s.__data[__i])
        break;
    return __i;
  }
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_VEC_EXT_H
