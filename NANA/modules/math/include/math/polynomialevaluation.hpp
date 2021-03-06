#pragma once
/**
 * @file polynomialevaluation.hpp
 * @date 2021/12/02 19:42
 *
 * @author tuyuru
 * Contact: 707101557@qq.com
 *
 * @brief 实现多项式的求值
 *
 *
 * \note
*/

#include "NANA\core/error.h"
#include "NANA\core/matrix.h"
namespace NANA {
namespace MATH {
/**
 * @brief 一维多项式求值
 * @param a 数组指针(高次项在前)
 * @param n 数组长度
 * @param x 
 * @return 
*/
template<typename _Tp>
_Tp PolynomialEvaluation1D(const _Tp* a, int n, _Tp x) {
	NA_Assert(n > 0);
	_Tp ret = a[0];
	for (int i = 1; i < n; i++) {
		ret = ret * x + a[i];
	}
	return ret;
}


/**
 * @brief 二维多项式求值
 * @param mat 低次项在前
 * @param x 
 * @param y 
 * @param n 
 * @return 
*/
double NA_API PolynomialEvaluation2D(const Matrix& mat, double x, double y, int n);




}



}
