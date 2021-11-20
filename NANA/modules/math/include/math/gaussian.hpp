#include <core.hpp>

namespace NANA {
namespace Math {
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




}
}



