#ifndef _LIBCPP___SIMD_ABI_PPC_H
#define _LIBCPP___SIMD_ABI_PPC_H

#include <__simd/abi/simd_storage.h>

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

template <class _Tp, int _Np>
struct __simd_impl<_Tp, simd_abi::__ppc<_Np>> {
  using _Simd = __simd_storage<_Tp, simd_abi::__ppc<_Np>>;
  using _Mask = __mask_storage<_Tp, simd_abi::__ppc<_Np>>;
  using _Base = __simd_serial<_Tp, simd_abi::__ppc<_Np>>;

  static _Simd __masked_assign(_Simd& __s, _Mask __m, _Simd __v) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__masked_assign(__s, __m, __v);
  }

  template<class _BinaryOp>
  static _Tp __reduce(const _Simd& __s, _BinaryOp __op) {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__reduce(__s, __op);
  }


};

template <class _Tp, int _Np>
struct __mask_impl<_Tp, simd_abi::__ppc<_Np>> {
  using _Mask = __mask_storage<_Tp, simd_abi::__ppc<_Np>>;
  using _Base = __mask_serial<_Tp, simd_abi::__ppc<_Np>>;

  static bool __all_of(_Mask __s) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__all_of(__s);
  }

  static bool __any_of(_Mask __s) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__any_of(__s);
  }

  static bool __none_of(_Mask __s) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__none_of(__s);
  }

  static bool __some_of(_Mask __s) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__some_of(__s);
  }

  static int __popcount(_Mask __s) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__popcount(__s);
  }

  static int __find_first_set(_Mask __s) {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__find_first_set(__s);
  }

  static int __find_last_set(_Mask __s) {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__find_last_set(__s);
  }

  static _Mask __masked_assign(_Mask& __s, _Mask __m, _Mask __v) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__masked_assign(__s, __m, __v);
  }
};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_PPC_H
