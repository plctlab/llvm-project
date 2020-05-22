#include <riscv_vector.h>

_VL_T test_vsetvl__e8m1(size_t rvl)
{
    _VL_T gvl = vsetvl_e8m1(rvl);
    return gvl;
}

