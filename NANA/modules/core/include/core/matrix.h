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
 * TODO:
 *
 * @note
*/
#include "core_global.h"
#include "error.h"
#include "nadef.hpp"


namespace NANA {



//! @addtogroup core_basic
//! @{


/*!
 * @brief 简单矩阵类
 */
class NA_API Matrix NA_FINAL{
public:
	/**
	 * @brief 枚举矩阵的各种分解方法
	 */
	enum DecompositionMethod {
		LU,
		QR,
		SVD,
	};

	Matrix();

	/**
	 * @brief  构造函数，主动申请与管理内存
	 * @returns
	 * @param int rows
	 * @param int cols
	 * @note
	 */
	Matrix(int rows, int cols);

	/**
	 * @brief 实现复制构造函数
	 * @param M
	*/
	Matrix(const Matrix& M);

	/**
	 * @brief 矩阵的析构函数，释放申请的内存
	 */
	~Matrix();

	/**
	 * @brief 获取矩阵的列数
	 * @return 
	*/
	int cols() const;

	/**
	 * @brief 获取矩阵的行数
	 * @return 
	*/
	int rows() const;

	/**
	 * @brief 将当前矩阵设置为单位矩阵
	 * @return
	*/
	static void setMatrixEye(Matrix& mat, const int m);

	/**
	 * @brief 生成全0矩阵
	 * @param rows 
	 * @param cols 
	 * @return 
	*/
	static Matrix zeros(int rows, int cols);

	/**
	 * @brief 用value填充Matrix的全部内容
	 * @param value
	*/
	void fill(const NAFLOAT& value);

	/**
	 * @brief 获取值的指针
	 * @return
	*/
	const NAFLOAT** getValPtr() const;



	/**
	 * @brief 实现矩阵的转置
	 * @return 
	*/
	Matrix T() const;

	/**
	 * @brief 等于时
	 * @param M
	 * @return
	*/
	Matrix& operator= (const Matrix& M);

	/**
	 * @brief 实现矩阵的加法
	 * @param M
	 * @return C = A+B
	*/
	Matrix  operator+ (const Matrix& B);


	/**
	 * @brief 实现矩阵的减法
	 * @param B
	 * @return C = A-B
	*/
	Matrix  operator- (const Matrix& M);

	/**
	 * @brief 实现矩阵的乘法
	 * @param B
	 * @return C = A*B
	 */
	Matrix  operator* (const Matrix& M);

	/**
	 * @brief 实现矩阵的求逆
	 * @param flag
	 * @return
	*/
	Matrix inv(int flag = LU);

	/**
	 * @brief 用istream的形式给矩阵赋值
	 * @param is 
	 * @param m 
	 * @return 
	*/
	friend NA_API std::istream& operator>>(std::istream& is, Matrix& m);

	/**
	 * @brief 将矩阵中的内容导出
	 * @param out 
	 * @param M 
	 * @return 
	*/
	friend NA_API std::ostream& operator<< (std::ostream& out, const Matrix& M);
private:



	/**
	 * @brief	申请内存
	 * @returns:   void
	 * @note:
	 */
	void create(int rows, int cols);

	/**
	 * @brief 释放已申请的内存
	 */
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


