#pragma once

namespace NANA {
namespace MATH {
/**
 * @brief 基于几何原本实现两数的最小公约数
 * @param a 
 * @param b 
 * @return 
*/
template<typename _Tp>
_Tp LeastCommonDivisor(_Tp a, _Tp b)
{
    _Tp r;
    while (b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

}
}