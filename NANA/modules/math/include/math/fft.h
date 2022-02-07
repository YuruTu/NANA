#pragma once
/**
 * @file fft.h
 * @date 2021/12/3 19:57
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief ʵ�ָ���Ҷ�任����㷨
 * \note
*/


#include <NANA\core.hpp>



namespace NANA {
namespace MATH {

/**
 * @brief ʵ�ֿ��ٸ���Ҷ�任
 * @param p n��������������
 * @param f ����Ҷ�任���
 * @param n ��������
 * @param k n==2^k
*/
void NA_API fft(NAFLOAT * p,Complex<NAFLOAT> * f,  int n,int k);


}
}



