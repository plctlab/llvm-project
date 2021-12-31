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
struct __simd_traits<_Tp, simd_abi::__vec_ext<_Np>> {
  using _Storage = __simd_storage_vec_ext<_Tp, _Np>;

  static _Storage __broadcast(_Tp __v) noexcept {
    return __generate([=](size_t) { return __v; });
  }

  template <class _Generator, size_t... _Is>
  static _Storage __generate_init(_Generator&& __g, std::index_sequence<_Is...>) {
    // _Storage specified here is to work around GCC
    return _Storage{{__g(std::integral_constant<size_t, _Is>())...}};
  }

  template <class _Generator>
  static _Storage __generate(_Generator&& __g) noexcept {
    return __generate_init(std::forward<_Generator>(__g), std::make_index_sequence<_Np>());
  }

  template <class _Up, class _Flags>
  static _Storage __load(const _Up* __mem, _Flags) noexcept {
    // TODO: optimized implementation
    return __generate([=](size_t __i) { return static_cast<_Tp>(__mem[__i]); });
  }

  template <class _Up, class _Flags>
  static void __store(_Storage __s, _Up* __mem, _Flags) noexcept {
    // TODO: optimized implementation
    for (size_t __i = 0; __i < _Np; __i++)
      __mem[__i] = static_cast<_Up>(__s.__data[__i]);
  }

  static void __increment(_Storage& __s) noexcept { ++__s.__data; }

  static void __decrement(_Storage& __s) noexcept { --__s.__data; }

  static _Storage __negate(_Storage __s) noexcept { return {!__s.__data}; }

  static _Storage __bitwise_not(_Storage __s) noexcept { return {~__s.__data}; }

  static _Storage __unary_minus(_Storage __s) noexcept { return {-__s.__data}; }

  static _Storage __plus(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data + __rhs.__data}; }

  static _Storage __minus(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data - __rhs.__data}; }

  static _Storage __multiplies(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data * __rhs.__data}; }

  static _Storage __divides(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data / __rhs.__data}; }

  static _Storage __modulus(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data % __rhs.__data}; }

  static _Storage __bitwise_and(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data & __rhs.__data}; }

  static _Storage __bitwise_or(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data | __rhs.__data}; }

  static _Storage __bitwise_xor(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data ^ __rhs.__data}; }

  static _Storage __shift_left(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data << __rhs.__data}; }

  static _Storage __shift_right(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data >> __rhs.__data}; }

  static _Storage __shift_left(_Storage __lhs, int __rhs) noexcept { return {__lhs.__data << __rhs}; }

  static _Storage __shift_right(_Storage __lhs, int __rhs) noexcept { return {__lhs.__data >> __rhs}; }

  static _Storage __equal_to(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data == __rhs.__data}; }

  static _Storage __not_equal_to(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data != __rhs.__data}; }

  static _Storage __less_equal(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data <= __rhs.__data}; }

  static _Storage __less(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data < __rhs.__data}; }

  static _Storage __logical_and(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data & __rhs.__data}; }

  static _Storage __logical_or(_Storage __lhs, _Storage __rhs) noexcept { return {__lhs.__data | __rhs.__data}; }

  static bool __all_of(_Storage __s) noexcept {
    for (auto __v : __s.__data)
      if (!__v)
        return false;
    return true;
  }

  static bool __any_of(_Storage __s) noexcept {
    for (auto __v : __s.__data)
      if (__v)
        return true;
    return false;
  }

  static bool __none_of(_Storage __s) noexcept {
    for (auto __v : __s.__data)
      if (__v)
        return false;
    return true;
  }

  static bool __some_of(_Storage __s) noexcept {
    for (size_t __i = 1; __i < _Np; ++__i)
      if (__s[__i] != __s[__i - 1])
        return true;
    return false;
  }

  static int __popcount(_Storage __s) noexcept {
    int __count = 0;
    for (auto __v : __s.__data)
      __count += __v != 0;
    return __count;
  }

  static int __find_first_set(_Storage __s) {
    size_t __i = 0;
    for (; __i < _Np; ++__i)
      if (__s.__data[__i])
        break;
    return __i;
  }

  static int __find_last_set(_Storage __s) {
    size_t __i = _Np - 1;
    for (; __i != -1; --__i)
      if (__s.__data[__i])
        break;
    return __i;
  }

  static _Tp __hmin(_Storage __s) {
    _Tp __min = __s.__data[0];
    for (auto __v : __s.__data)
      __min = std::min(__min, __v);
    return __min;
  }

  static _Tp __hmax(_Storage __s) {
    _Tp __max = __s.__data[0];
    for (auto __v : __s.__data)
      __max = std::max(__max, __v);
    return __max;
  }

  static _Storage __min(_Storage __a, _Storage __b) noexcept {
    _Storage __r;
    for (size_t __i = 0; __i < _Np; ++__i)
      __r.__data[__i] = std::min(__a.__data[__i], __b.__data[__i]);
    return __r;
  }

  static _Storage __max(_Storage __a, _Storage __b) noexcept {
    _Storage __r;
    for (size_t __i = 0; __i < _Np; ++__i)
      __r.__data[__i] = std::max(__a.__data[__i], __b.__data[__i]);
    return __r;
  }

  static std::pair<_Storage, _Storage> __minmax(_Storage __a, _Storage __b) noexcept {
    _Storage __min, __max;
    for (size_t __i = 0; __i < _Np; ++__i) {
      __min.__data[__i] = std::min(__a.__data[__i], __b.__data[__i]);
      __max.__data[__i] = std::max(__a.__data[__i], __b.__data[__i]);
    }
    return {__min, __max};
  }

  static _Storage __clamp(_Storage __v, _Storage __lo, _Storage __hi) noexcept {
    _Storage __r;
    for (size_t __i = 0; __i < _Np; ++__i)
      __r.__data[__i] = std::min(std::max(__v.__data[__i], __lo.__data[__i]), __hi.__data[__i]);
    return __r;
  }
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_VEC_EXT_H
