#pragma once
/**
 * @file fft.h
 * @date 2021/12/3 19:57
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 实现傅里叶变换相关算法
 * \note
*/


#include <NANA\core.hpp>



namespace NANA {
/**
 * @brief  实现快速傅里叶变换
 * @param NAFLOAT * p n个采样输入数据
 * @param Complex<NAFLOAT> * f 傅里叶变换结果
 * @param int n 采样点数
 * @param int k n==2^k 
 * @note
 */
void NA_API fft(NAFLOAT * p,Complex<NAFLOAT> * f,  int n,int k);
}



