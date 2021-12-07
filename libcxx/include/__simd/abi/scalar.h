// -*- C++ -*-
//===------------------------- __simd/abi/scalar.h ------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#ifndef _LIBCPP___SIMD_ABI_SCALAR_H
#define _LIBCPP___SIMD_ABI_SCALAR_H

#include <experimental/__config>
#include <__simd/abi/decl.h>

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD_ABI

struct __scalar {
  static constexpr bool __is_abi_tag = true;
  static constexpr size_t __simd_size = 1;
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD_ABI

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

template <class _Tp>
struct __simd_storage<_Tp, simd_abi::__scalar> {
  _Tp __s;

  _Tp __get(size_t __idx) const noexcept { return (&__s)[__idx]; }

  void __set(size_t __idx, _Tp __val) noexcept { (&__s)[__idx] = __val; }
};

template <class _Tp>
struct __simd_traits<_Tp, simd_abi::__scalar> {
  using _Storage = __simd_storage<_Tp, simd_abi::__scalar>;

  static _Storage __broadcast(_Tp __v) noexcept { return __v; }

  template <class _Generator>
  static _Storage __generate(_Generator&& __g) noexcept {
    return __g(std::integral_constant<size_t, 0>());
  }

  template <class _Up, class _Flags>
  static _Storage __load(_Up* __mem, _Flags) noexcept {
    return static_cast<_Tp>(*__mem);
  }

  template <class _Up, class _Flags>
  static void __store(_Storage __s, const _Up* __mem, _Flags) noexcept {
    *__mem = static_cast<_Up>(__s);
  }

  static void __increment(_Storage& __s) noexcept { ++__s.__get(0); }

  static void __decrement(_Storage& __s) noexcept { --__s.__get(0); }

  static _Storage __negate(_Storage __s) noexcept { return !__s.__get(0); }

  static _Storage __bitwise_not(_Storage __s) noexcept { return ~__s.__get(0); }
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_SCALAR_H
