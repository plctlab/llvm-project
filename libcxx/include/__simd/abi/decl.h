// -*- C++ -*-
//===-------------------------- __simd/abi/decl.h -------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
#ifndef _LIBCPP___SIMD_ABI_DECL_H
#define _LIBCPP___SIMD_ABI_DECL_H

#include <experimental/__config>
#include <cstddef>

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

enum class _StorageKind {
  _Scalar,
  _Array,
  _VecExt,
};

template <_StorageKind __kind, int _Np>
struct __simd_abi {};

template <class _Tp, class _Abi>
class __simd_storage;

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_DECL_H
