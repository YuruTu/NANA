#include <core.hpp>
/**
 * @file gaussian.hpp
 * @date 2021/11/20 7:23
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 实现高斯相关的算法

 *
 *@note 1.高斯滤波
 *		2.生成高斯随机数
 * \note
*/


namespace NANA {
namespace MATH {
/**
 * @brief  二维高斯变换
 * @returns   计算的值
 * @param[in] _Tp x 
 * @param[in] _Tp y
 * @param[in] _Tp sigma 方差
 * @note
 */
template<typename _Tp>
inline _Tp Gaussian2D(const _Tp x,const _Tp y,const _Tp sigma) {
	_Tp sigma_pow2 = sigma * sigma;
	return  1.0 / std::sqrt(NA_2PI * sigma_pow2) * std::exp(-(x * x + y * y) / (2 * sigma_pow2));
}

/**
 * @brief  生成高斯滤波核
 * @returns   计算的值
 * @param[in] _Tp x
 * @param[in] _Tp y
 * @param[in] _Tp sigma 方差
 * @note
 */
template<typename _Tp>
int GenGaussianKernel(Matrix & mat,const Size & dstSize, _Tp sigma) {



	return RET_OK;
}








}
}



