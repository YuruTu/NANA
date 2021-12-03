#pragma  once
/**
 * @file warp.hpp
 * @date 2021/11/20 7:23
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief ʵ�ֵ㼯�ķ���任��͸�ӱ任
 *
 * TODO: long description
 *
 * \note
*/

#include <core.hpp>
#include "geometrytypes.hpp"

namespace NANA {
namespace ComputerGeometry {

//! @addtogroup geometrywarp
//! @{



/** @brief �Ե�ǰ�㼯���з���任

	����任�����С:
		\f$2 \times 3\f$ 
		\f[\begin{bmatrix} x'_i \\ y'_i\\1 \end{bmatrix} = \texttt{map_matrix} \cdot \begin{bmatrix} x_i \\ y_i \\ 1 \end{bmatrix}\f]
where

\f[dst(i)=(x'_i,y'_i), src(i)=(x_i, y_i), i=0,1,2\f]

@param[in]  const  PointXY_<_Tp> & src ԭ��
@param[out] PointXY_<_Tp> & dst Ŀ���
 */
template<typename _Tp>
void warpAffinePoint(const Matrix& M,const  PointXY_<_Tp> & src, PointXY_<_Tp>&dst ) {
	NA_Assert((M.m_rows == 2) && (M.m_cols == 3));
	NAFLOAT* pdata = M.m_data;
	dst.x = pdata[0] * src.x + pdata[1] * src.y + pdata[2];
	pdata += M.m_step;
	dst.y = pdata[0] * src.x + pdata[1] * src.y + pdata[2];
	return ;
}


/** @brief ʵ�ֵ㼯��͸�ӱ任����
	͸�ӱ任�����С:
		\f$3 \times 3\f$ 
\f[(x, y)  \rightarrow (x'/w, y'/w)\f]
where
\f[(x', y', w') =  \texttt{mat} \cdot \begin{bmatrix} x & y &  1  \end{bmatrix}\f]
and
w = \left\{\begin{matrix}
w^{'}\quad if \quad\(w' \ne 0\)\\
{\infty} \quad{otherwise}
\end{matrix}\right.
@note ʵ�ֶ�ά�㼯��͸�ӱ任
*/

template<typename _Tp>
void warpPerspectivePoint2D(const Matrix& M, const  PointXY_<_Tp>& src, PointXY_<_Tp>& dst) {
	NA_Assert((M.m_rows == 3) && (M.m_cols == 3));
	NAFLOAT* pdata = M.m_data;

	dst.x = pdata[0] * src.x + pdata[1] * src.y + pdata[2];
	pdata += M.m_step;
	dst.y = pdata[0] * src.x + pdata[1] * src.y + pdata[2];
	pdata += M.m_step;
	NAFLOAT w = pdata[0] * src.x + pdata[1] * src.y + pdata[2];
	dst.x /= w;
	dst.y /= w;
	return;
}





//! @} geometrywarp



}
}



