#pragma once
/*@
 * @file geometry.hpp
 * @brief 实现几何原本中的相关算法
 * @author yuru tu
 * @date 2022/05/24
 *
 * 
 */
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