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
class NA_API Matrix  {
public:
	
	Matrix();
	/**
	 * @brief  构造函数，主动申请与管理内存
	 * @returns   
	 * @param int rows
	 * @param int cols
	 * @note
	 */
	Matrix(int rows, int cols);

	~Matrix();

	/**
	 * @brief 将当前矩阵设置为单位矩阵
	 * @return 
	*/
	static void setMatrixEye(Matrix & mat,const int m);

	/**
	 * @brief 用value填充Matrix的全部内容
	 * @param value 
	*/
	void fill(const NAFLOAT & value);
	
	/**
	 * @brief 获取值的指针
	 * @return 
	*/
	const NAFLOAT** getValPtr() const ;

	/**
	 * @brief 获取当前矩阵的行数
	 * @return 
	*/
	int getRows() const;

	/**
	 * @brief 获取当前矩阵的列数
	 * @return 
	*/
	int getCols() const;


	/**
	 * @brief 等于时
	 * @param M 
	 * @return 
	*/
	Matrix operator= (const Matrix& M);
private:



	/**
	 * @brief	申请内存
	 * @returns:   void
	 * @note:	
	 */
	void create(int rows,int cols);

	///************************************
	/// @brief:    release 内存释放
	/// @fullname:  NANA::Matrix::release
	/// @access:    private 
	/// @returns:   void
	/// @qualifier: 
	///************************************
	void release();

	/// @brief 矩阵的数据
	NAFLOAT** m_val;
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