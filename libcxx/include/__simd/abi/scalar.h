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
struct __simd_storage_scalar {
  _Tp __data;

  _Tp __get(size_t __idx) const noexcept { return (&__data)[__idx]; }

  void __set(size_t __idx, _Tp __v) noexcept { (&__data)[__idx] = __v; }
};

template <class _Tp>
struct __simd_traits<_Tp, simd_abi::__scalar> {
  using _Storage = __simd_storage_scalar<_Tp>;

  static _Storage __broadcast(_Tp __v) noexcept { return {__v}; }

  template <class _Generator>
  static _Storage __generate(_Generator&& __g) noexcept {
    return {__g(std::integral_constant<size_t, 0>())};
  }

  template <class _Up, class _Flags>
  static _Storage __load(_Up* __mem, _Flags) noexcept {
    return {static_cast<_Tp>(*__mem)};
  }

  template <class _Up, class _Flags>
  static void __store(_Storage __s, const _Up* __mem, _Flags) noexcept {
    *__mem = static_cast<_Up>(__s.__data);
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
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_SCALAR_H
