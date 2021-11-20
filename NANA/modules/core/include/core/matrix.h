#pragma  once

/**
 * @file matrix.h
 * @date 2021/11/17 6:03
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 简单矩阵类(效率不高，但易于理解，很多时候会触发复制构造函数)，不同于Mat 
 *
 * TODO: long description
 *
 * \note
*/
#include "core_global.h"
#include "nadef.hpp"


namespace NANA{



//! @addtogroup core_basic
//! @{
typedef  double NAFLOAT;

/*!
 * @brief 简单矩阵类
 */
class Matrix {
public:
	
	/**
	 * @brief  构造函数，主动申请与管理内存
	 * @returns   
	 * @param int rows
	 * @param int cols
	 * @note
	 */
	Matrix(int rows, int cols);

	~Matrix();

private:



	/**
	 * @brief	申请内存
	 * @returns:   void
	 * @note:	
	 */
	void create();

	///************************************
	/// @brief:    release 内存释放
	/// @fullname:  NANA::Matrix::release
	/// @access:    private 
	/// @returns:   void
	/// @qualifier: 
	///************************************
	void release();

	/// @brief 矩阵的数据
	NAFLOAT* m_data;
	/// @brief 行数
	int m_rows;
	/// @brief 列数
	int m_cols;
	/// @brief 步长
	int m_step;
};


//! @} core_basic
}