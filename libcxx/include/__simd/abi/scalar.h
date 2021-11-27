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
class __simd_storage<_Tp, simd_abi::__scalar> {
  _Tp __s_;

  template <class, class>
  friend struct simd;

  template <class, class>
  friend struct simd_mask;

  template <class, class>
  friend struct __simd_traits;

public:
  _Tp __get(size_t __idx) const noexcept { return (&__s_)[__idx]; }

  void __set(size_t __idx, _Tp __val) noexcept { (&__s_)[__idx] = __val; }
};

template <class _Tp>
struct __simd_traits<_Tp, simd_abi::__scalar> {
  using _Storage = __simd_storage<_Tp, simd_abi::__scalar>;

  static _Storage __broadcast(_Tp __v) noexcept { return __v; }
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_SCALAR_H
