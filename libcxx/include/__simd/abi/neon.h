#ifndef _LIBCPP___SIMD_ABI_NEON_H
#define _LIBCPP___SIMD_ABI_NEON_H

#include <__simd/abi/simd_storage.h>

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

template <class _Tp, int _Np>
struct __simd_neon {
  using _Simd = __simd_storage<_Tp, simd_abi::__neon<_Np>>;
  using _Mask = __mask_storage<_Tp, simd_abi::__neon<_Np>>;

};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_NEON_H
