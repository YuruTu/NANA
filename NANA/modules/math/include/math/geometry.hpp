#pragma once
/*@
 * @file geometry.hpp
 * @brief ʵ�ּ���ԭ���е�����㷨
 * @author yuru tu
 * @date 2022/05/24
 *
 * 
 */
namespace NANA {
namespace MATH {
/**
 * @brief ���ڼ���ԭ��ʵ����������С��Լ��
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