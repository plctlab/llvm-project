#ifndef _LIBCPP___SIMD_ABI_PPC_H
#define _LIBCPP___SIMD_ABI_PPC_H

#include <__simd/abi/simd_storage.h>

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

template <class _Tp>
struct __simd_ppc {
  using _Simd = __simd_storage<_Tp, simd_abi::__ppc>;
  using _Mask = __mask_storage<_Tp, simd_abi::__ppc>;

};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_PPC_H
