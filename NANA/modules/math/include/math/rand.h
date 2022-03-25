#pragma once
/**
 * @file rand.h
 * @date 2022/03/25 14:08
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 增加随机算法
 *
 * TODO: long description
 *
 * \note
*/
#include <NANA\core.hpp>





namespace NANA {
namespace MATH {


/**
 * @brief  独立同分布的中心极限定理生成正态分布的随机数
 * @returns   double NA_API
 * @param double r_me
 * @param double sd
 * @author Tu Yuru
 * @note https://blog.csdn.net/m0_37772174/article/details/81054183?spm=1001.2014.3001.5502
 */
double NA_API randNormal(double r_me, double sd);



}
}


