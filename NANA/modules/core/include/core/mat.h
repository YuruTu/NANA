#pragma once
/**
 * @file mat.h
 * @date 2021/11/11 19:47
 *
 * @author Administrator
 * Contact: 707101557@qq.com
 *
 * @brief  实现一个用于矩阵运算的模板类(仍在实现当中)
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
 * @brief 高效矩阵运算类
 * @note 不同于OpenCV的Mat，实现了32位对齐(因为Cuda等加速算法是针对32数据的)
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

	///************************************
	/// @brief:    ~Mat
	/// @fullname:  NANA::Mat<_T>::~Mat
	/// @access:    public 
	/// @returns:   
	/// @qualifier:
	///************************************
	virtual ~Mat();







private:

	///************************************
	/// @brief:    allocateMemory 内存申请
	/// @fullname:  NANA::Mat<_T>::allocateMemory
	/// @access:    private 
	/// @returns:   void
	/// @qualifier:
	/// @param: const int32_t rows
	/// @param: const int32_t cols
	///************************************
	void allocateMemory(const int32_t rows, const int32_t cols);

	///************************************
	/// @brief:    releaseMemory 内存释放
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

	char * m_data;///指针数组
	int m_stride;///步长
	int m_rows;///行数
	int m_cols;///列数
	CDataManager* m_datamanager;
};





//////////////////////////////////////////////////////////////////////////
// 导出模板类
//////////////////////////////////////////////////////////////////////////
template class  NA_API  Mat<float>;
template class  NA_API  Mat<double>;




class MatOp {
public:

private:


};

//! @} core_basic


}

