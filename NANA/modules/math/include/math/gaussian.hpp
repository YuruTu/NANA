#include <core.hpp>
/**
 * @file gaussian.hpp
 * @date 2021/11/20 7:23
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief ʵ�ָ�˹��ص��㷨

 *
 *@note 1.��˹�˲�
 *		2.���ɸ�˹�����
 * \note
*/


namespace NANA {
namespace MATH {
/**
 * @brief  ��ά��˹�任
 * @returns   �����ֵ
 * @param[in] _Tp x 
 * @param[in] _Tp y
 * @param[in] _Tp sigma ����
 * @note
 */
template<typename _Tp>
inline _Tp Gaussian2D(const _Tp x,const _Tp y,const _Tp sigma) {
	_Tp sigma_pow2 = sigma * sigma;
	return  1.0 / std::sqrt(NA_2PI * sigma_pow2) * std::exp(-(x * x + y * y) / (2 * sigma_pow2));
}

/**
 * @brief  ���ɸ�˹�˲���
 * @returns   �����ֵ
 * @param[in] _Tp x
 * @param[in] _Tp y
 * @param[in] _Tp sigma ����
 * @note
 */
template<typename _Tp>
int GenGaussianKernel(Matrix & mat,const Size & dstSize, _Tp sigma) {



	return RET_OK;
}








}
}



