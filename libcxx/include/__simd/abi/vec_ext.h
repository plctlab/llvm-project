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

constexpr size_t __next_pow_of_2(size_t __val) {
  size_t __pow = 1;
  while (__pow < __val)
    __pow <<= 1;
  return __pow;
}

template <class _Tp, int _Np>
struct __simd_storage<_Tp, simd_abi::__vec_ext<_Np>> {
#if defined(_LIBCPP_COMPILER_CLANG_BASED)
  using _Storage = _Tp __attribute__((vector_size(sizeof(_Tp) * _Np)));
#else
  using _Storage = _Tp __attribute__((vector_size(__next_pow_of_2(sizeof(_Tp) * _Np))));
#endif

  _Storage __s;

  _Tp __get(size_t __idx) const noexcept { return __s[__idx]; }

  void __set(size_t __idx, _Tp __val) noexcept { __s[__idx] = __val; }
};

template <class _Tp, int _Np>
struct __simd_traits<_Tp, simd_abi::__vec_ext<_Np>> {
  using _Storage = __simd_storage< _Tp, simd_abi::__vec_ext<_Np>>;

  static _Storage __broadcast(_Tp __v) noexcept {
    _Storage __r;
    for (size_t __i = 0; __i < _Np; ++__i)
      __r.__set(__i, __v);
    return __r;
  }

  template <class _Generator, size_t... _Is>
  static _Storage __generate_init(_Generator&& __g, std::index_sequence<_Is...>) {
    return _Storage{{__g(std::integral_constant<size_t, _Is>())...}};
  }

  template <class _Generator>
  static _Storage __generate(_Generator&& __g) noexcept {
    return __generate_init(std::forward<_Generator>(__g), std::make_index_sequence<_Np>());
  }

  template <class _Up, class _Flags>
  static _Storage __load(const _Up* __mem, _Flags) noexcept {
    _Storage __r;
    for (size_t __i = 0; __i < _Np; __i++)
      __r.__set(__i, static_cast<_Tp>(__mem[__i]));
    return __r;
  }

  template <class _Up, class _Flags>
  static void __store(_Storage __s, _Up* __mem, _Flags) noexcept {
    // TODO: optimized implementation
    for (size_t __i = 0; __i < _Np; __i++)
      __mem[__i] = static_cast<_Up>(__s.__get(__i));
  }

  static void __increment(_Storage& __s) noexcept {
    for (size_t __i = 0; __i < _Np; __i++)
      __s.__set(__i, __s.__get(__i) + 1);
  }

  static void __decrement(_Storage& __s) noexcept {
    for (size_t __i = 0; __i < _Np; __i++)
      __s.__set(__i, __s.__get(__i) - 1);
  }

  static _Storage __negate(_Storage __s) noexcept {
    for (size_t __i = 0; __i < _Np; __i++)
      __s.__set(__i, -__s.__get(__i));
    return __s;
  }

  static _Storage __bitwise_not(_Storage __s) noexcept {
    for (size_t __i = 0; __i < _Np; __i++)
      __s.__set(__i, ~__s.__get(__i));
    return __s;
  }
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_VEC_EXT_H
