#pragma once
/**
 * @file mat.h
 * @date 2021/11/11 19:47
 *
 * @author Administrator
 * Contact: 707101557@qq.com
 *
 * @brief  ʵ��һ�����ھ��������ģ����(����ʵ�ֵ���)
 *
 * TODO: long description
 *
 * \note
*/
#include "core_global.h"
#include "error.h"
#include "datamanager.h"
#include "safememory.hpp"

namespace NANA {

//! @addtogroup core_basic
//! @{

/**
 * @brief ��Ч����������
 * @note ��ͬ��OpenCV��Mat��ʵ����32λ����(��ΪCuda�ȼ����㷨�����32���ݵ�)
 *		 Mat��Ϊ�˼̳ж�д��
 */
template <typename _T>
class Mat {
public:

	/**
	 * @brief  
	 * @returns   
	 * @note
	 */
	Mat();


	/**
	 * @brief  
	 * @returns   
	 * @param int rows
	 * @param int cols
	 * @note
	 */
	Mat(int rows, int cols);

	/**
	 * @brief ��������
	 * @returns
	 * @note �����ͷ�Mat�����������
	 */
	virtual ~Mat();







private:


	/**
	 * @brief �ڴ�����
 	 * @returns
	 * @param[in] const int32_t rows
	 * @param[in] const int32_t rows
	 * @note
	 */
	void allocateMemory(const int32_t rows, const int32_t cols);

	///************************************
	/// @brief:    releaseMemory �ڴ��ͷ�
	/// @fullname:  NANA::Mat<_T>::releaseMemory
	/// @access:    private 
	/// @returns:   void
	/// @qualifier:
	///************************************
	void releaseMemory();

	///************************************
	/// @brief:    release
	/// @fullname:  NANA::Mat<_T>::release
	/// @access:    private 
	/// @returns:   void
	/// @qualifier:
	///************************************
	void release();

	char * m_data;///<ָ������
	int m_stride;///<����
	int m_rows;///<����
	int m_cols;///<����
	CDataManager* m_datamanager;
};





//////////////////////////////////////////////////////////////////////////
// ����ģ����
//////////////////////////////////////////////////////////////////////////
template class  NA_API  Mat<float>;
template class  NA_API  Mat<double>;




class MatOp {
public:

private:


};

//! @} core_basic


}

