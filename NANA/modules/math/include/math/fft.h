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
/**
 * @brief  ʵ�ֿ��ٸ���Ҷ�任
 * @param NAFLOAT * p n��������������
 * @param Complex<NAFLOAT> * f ����Ҷ�任���
 * @param int n ��������
 * @param int k n==2^k 
 * @note
 */
void NA_API fft(NAFLOAT * p,Complex<NAFLOAT> * f,  int n,int k);
}



