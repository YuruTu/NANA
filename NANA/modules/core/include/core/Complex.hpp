#pragma once
#include "core_global.h"

/**
 * @file Complex.hpp
 * @date 2021/11/11 18:30
 *
 * @author Administrator
 * Contact: 707101557@qq.com
 *
 * @brief ʵ�ָ�����������
 *
 * TODO: long description
 *
 * \note
*/
namespace NANA{
//! @addtogroup core_basic
//! @{

/**
 * @brief �����࣬����ʵ�ָ����ļӼ��˳�����
 * @note ����ʵ�ָ����ļӼ��˳�����
 */
template <typename _T>
class Complex NA_FINAL {
public:
	Complex():
		re(0),
		im(0)
	{

	}

	Complex(_T& _re, _T& _im = 0) {
		re = _re;
		im = _im;
	}

	/**
	 * @brief  ���ع����
	 * @returns   NANA::Complex<_T>
	 * @note
	 */
	Complex<_T> conj() const {
		return Complex<_T>(re, -im);
	}

	/**
	 * @brief ʵ�ָ����ļӷ�����
	 * @param B 
	 * @return 
	*/
	Complex<_T>  operator+ (const Complex<_T>& B) {
		return Complex<_T>(re + B.re, im + B.im);
	}

	/**
	 * @brief �����ļ���
	 * @param B 
	 * @return 
	*/
	Complex<_T>  operator- (const Complex<_T>& B) {
		return Complex<_T>(re -B.re, im - B.im);
	}

	/**
	 * @brief ʵ�ָ����ĳ˷�����
	 * @param B 
	 * @return 
	*/
	Complex<_T>  operator* (const Complex<_T>& B) {
		return Complex<_T>(re * B.re-im*B.im, im*B.re - re*B.im);
	}

	/**
	 * @brief ʵ�ָ����ĳ�������
	 * @param B 
	 * @return 
	*/
	Complex<_T>  operator/(const Complex<_T>& B) {
		_T  p = re * B.re;
		_T q = im * B.im;
		_T s = (re + im) * (B.re - B.im);
		_T w = (B.re * B.re + B.im * B.im);
		return Complex<_T>((p-q)/w, (s-p-q)/w);
	}
private:
	_T re, im;

};


//! @} core_basic

}