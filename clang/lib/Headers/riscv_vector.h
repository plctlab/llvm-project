 
/*===---- riscv_vector.h - rvv intrinsics -------------------------------------===
 *
 */

#ifndef __RISCV_VECTOR_H__
#define __RISCV_VECTOR_H__

#include <stddef.h>
  
typedef struct {
  size_t _vl;
} _VL_T;

#define _E8 8 
#define _M1 1 

static inline _VL_T vsetvl_e8m1(size_t avl)
{
  _VL_T new_vl;
  int vtype = _E8 | _M1;
  new_vl._vl = __builtin_riscv_vsetvl(avl, vtype);
  return new_vl;
}


#endif 