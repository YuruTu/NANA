#pragma once
/**
 * @file Complex.hpp
 * @date 2021/11/11 18:30
 *
 * @author Administrator
 * Contact: 707101557@qq.com
 *
 * @brief 实现复数
 *
 * TODO: long description
 *
 * \note
*/
namespace NANA{
//! @addtogroup core_basic
//! @{
/**
 * @brief 复数类，用于实现复数的加减乘除运算
 * @note 用于实现复数的加减乘除运算
 */
template <typename _T>
class Complex {
public:
	Complex();
	Complex(_T& _re, _T& _im = 0);

	/**
	 * @brief  返回共轭复数
	 * @returns   NANA::Complex<_T>
	 * @note
	 */
	Complex<_T> conj() const;
private:
	_T re, im;

};



template<typename _T>
inline Complex<_T>::Complex() :
	re(0),
	img(0)
{
}

template<typename _T>
inline Complex<_T>::Complex(_T& _re, _T& _im)
{
	re = _re;
	im = _im;
}

template<typename _T>
inline Complex<_T> Complex<_T>::conj() const
{
	return Complex<_T>(re, -im);
}

//! @} core_basic

}