#ifndef _LIBCPP___SIMD_ABI_PPC_H
#define _LIBCPP___SIMD_ABI_PPC_H

#include <__simd/abi/simd_storage.h>

_LIBCPP_BEGIN_NAMESPACE_EXPERIMENTAL_SIMD

template <class _Tp, int _Np>
struct __simd_impl<_Tp, simd_abi::__ppc<_Np>> {
  using _Simd = __simd_storage<_Tp, simd_abi::__ppc<_Np>>;
  using _Mask = __mask_storage<_Tp, simd_abi::__ppc<_Np>>;
  using _Base = __simd_serial<_Tp, simd_abi::__ppc<_Np>>;

  static _Mask __equal_to(_Simd __lhs, _Simd __rhs) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__equal_to(__lhs, __rhs);
  }

  static _Mask __not_equal_to(_Simd __lhs, _Simd __rhs) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__not_equal_to(__lhs, __rhs);
  }

  static _Mask __less_equal(_Simd __lhs, _Simd __rhs) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__less_equal(__lhs, __rhs);
  }

  static _Mask __less(_Simd __lhs, _Simd __rhs) noexcept{
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__less(__lhs, __rhs);
  }

  static _Tp __hmin(_Simd __s) noexcept{
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__hmin(__s);
  }

  static _Tp __hmax(_Simd __s) noexcept{
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__hmax(__s);
  }

  static _Simd __min(_Simd __a, _Simd __b) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__min(__a, __b);
  }

  static _Simd __max(_Simd __a, _Simd __b) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__max(__a, __b);
  }

  static std::pair<_Simd, _Simd> __minmax(_Simd __a, _Simd __b) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__minmax(__a, __b);
  }

  static _Simd __clamp(_Simd __v, _Simd __lo, _Simd __hi) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__clamp(__v, __lo, __hi);
  }

  static _Simd __masked_unary_minus(_Simd __s, _Mask __m) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__masked_unary_minus(__s, __m);
  }

  static _Simd __masked_assign(_Simd& __s, _Mask __m, _Tp __v) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__masked_assign(__s, __m, __v);
  }
#define _LIBCXX_MASKED_OP_(__op, __name)                                    \
  static void __masked##__name(_Simd& __s, _Mask __m, _Tp __v) noexcept {   \
    return _Base::__masked##__name(__s, __m, __v);                          \
  }
  _LIBCXX_MASKED_OP_(+, _plus)
  _LIBCXX_MASKED_OP_(-, _minus)
  _LIBCXX_MASKED_OP_(*, _multiplues)
  _LIBCXX_MASKED_OP_(/, _divides)
  _LIBCXX_MASKED_OP_(%, _modulus)
  _LIBCXX_MASKED_OP_(&, _bit_and)
  _LIBCXX_MASKED_OP_(|, _bit_or)
  _LIBCXX_MASKED_OP_(^, _bit_xor)
  _LIBCXX_MASKED_OP_(<<, _shift_left)
  _LIBCXX_MASKED_OP_(>>, _shift_right)
#undef _LIBCXX_MASKED_OP_
  static void __masked_incre(_Simd& __s, _Mask __m) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__masked_incre(__s, __m);
  }

  static void __masked_decre(_Simd& __s, _Mask __m) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__masked_decre(__s, __m);
  }
  template<class _Up>
  static void __masked_load(_Simd& __s, _Mask __m, _Up* __mem) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__masked_load(__s, __m, __mem);
  }
 template<class _Up>
 static void __masked_store(const _Simd& __s,  _Mask __m, _Up* __mem) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__masked_store(__s, __m, __mem);
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
  static _Mask __masked_unary_minus(_Mask __s, _Mask __m) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__masked_unary_minus(__s, __m);
  }

  static _Mask __masked_assign(_Mask& __s, _Mask __m, _Tp __v) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__masked_assign(__s, __m, __v);
  }
#define _LIBCXX_MASKED_OP_M(__op, __name)                                   \
  static void __masked##__name(_Mask& __s, _Mask __m, _Tp __v) noexcept {   \
    return _Base::__masked##__name(__s, __m, __v);                          \
  }
  _LIBCXX_MASKED_OP_M(+, _plus)
  _LIBCXX_MASKED_OP_M(-, _minus)
  _LIBCXX_MASKED_OP_M(*, _multiplues)
  _LIBCXX_MASKED_OP_M(/, _divides)
  _LIBCXX_MASKED_OP_M(%, _modulus)
  _LIBCXX_MASKED_OP_M(&, _bit_and)
  _LIBCXX_MASKED_OP_M(|, _bit_or)
  _LIBCXX_MASKED_OP_M(^, _bit_xor)
  _LIBCXX_MASKED_OP_M(<<, _shift_left)
  _LIBCXX_MASKED_OP_M(>>, _shift_right)
#undef _LIBCXX_MASKED_OP_M
  static void __masked_incre(_Mask& __s, _Mask __m) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__masked_incre(__s, __m);
  }
  static void __masked_decre(_Mask& __s, _Mask __m) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__masked_decre(__s, __m);
  }
  template<class _Up>
  static void __masked_load(_Mask& __s, _Mask __m, _Up* __mem) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__masked_load(__s, __m, __mem);
  }
 template<class _Up>
 static void __masked_store(const _Mask& __s, _Mask __m, _Up* __mem) noexcept {
    // if constexpr (__have_ppc)
    //   ppc_intrinsics
    // else
    return _Base::__masked_store(__s, __m, __mem);
  }

};

_LIBCPP_END_NAMESPACE_EXPERIMENTAL_SIMD

#endif // _LIBCPP___SIMD_ABI_PPC_H
