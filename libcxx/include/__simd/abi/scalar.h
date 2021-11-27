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
  _Tp __storage_;

  template <class, class>
  friend struct simd;

  template <class, class>
  friend struct simd_mask;

public:
  _Tp __get(size_t __index) const noexcept { return (&__storage_)[__index]; }
  void __set(size_t __index, _Tp __val) noexcept { (&__storage_)[__index] = __val; }
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_SCALAR_H
