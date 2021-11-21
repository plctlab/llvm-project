// -*- C++ -*-
//===------------------------- __simd/abi/array.h -------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#ifndef _LIBCPP___SIMD_ABI_ARRAY_H
#define _LIBCPP___SIMD_ABI_ARRAY_H

#include <experimental/__config>
#include <array>
#include <__simd/abi/decl.h>

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

template <class _Tp, int __num_element>
class __simd_storage<_Tp, __simd_abi<_StorageKind::_Array, __num_element>> {
  std::array<_Tp, __num_element> __storage_;

  template <class, class>
  friend struct simd;

  template <class, class>
  friend struct simd_mask;

public:
  _Tp __get(size_t __index) const noexcept { return __storage_[__index]; };
  void __set(size_t __index, _Tp __val) noexcept { __storage_[__index] = __val; }
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_ARRAY_H
