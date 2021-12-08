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
 * @note  Matrix也是可以用C方法实现高效运算的，但这样一来就背离了笔者的初心:一个用于教学的SDK
*/
#include "core_global.h"
#include "error.h"
#include "nadef.hpp"


namespace NANA {

//! @addtogroup core_basic
//! @{

/////////////////////////////////////// Matrix ///////////////////////////////////////////
/**
 * @brief 简单矩阵类
 * @note  允许其它地方继承
 */
class NA_API  Matrix {
public:
	/**
	 * @brief 枚举矩阵的各种分解方法
	 */
	enum DecompositionMethod {
		GaussiaJordan,///<高斯-约当消去法
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
	virtual ~Matrix();

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
	 * @brief 实现矩阵的LU分解
	 * @param A  带分解矩阵
	 * @param L  下三角矩阵L
	 * @param U  上三角矩阵U
	 * @note   由于此方法没有选主元，其数值运算是不稳定的
	*/
	static void LU(const Matrix& A, Matrix& L, Matrix& U);

	/**
	 * @brief 基于豪斯荷尔德变换实现矩阵的QR分解
	 * @param A 
	 * @param Q 
	 * @param R 
	*/
	static void QR(const Matrix & A, Matrix& Q, Matrix& R);

	/**
	 * @brief 实现奇异值分解
	 * @param A 输入矩阵A
	 * @param U 左奇异向量U
	 * @param D 对角线给出奇异值
	 * @param V 右奇异向量V^T
	 * @note  基于Householder变换以及变星QR算法对一般实矩阵A进行奇异值分解
	*/
	static void SVD(const Matrix A, Matrix& U, Matrix& D, Matrix& v );

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
	NAFLOAT** getValPtr() const;

	/**
	 * @brief 获取常量指针
	 * @return 
	*/
	const NAFLOAT** getConstValPtr() const;


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
	 * @brief 返回第row行的起始指针
	 * @param row 
	 * @return 
	*/
	const NAFLOAT* operator[](int row) const ;

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
	Matrix  operator* (const Matrix& B);

	/**
	 * @brief 实现矩阵的点乘
	 * @param B 与当前矩阵行列相等的矩阵
	 * @return 
	*/
	Matrix dot(const Matrix& B) const;



	/**
	 * @brief 矩阵的点乘
	 * @param b  
	 * @return 
	*/
	Matrix dot(NAFLOAT b) const;

	/**
	 * @brief 实现矩阵的求逆
	 * @param flag
	 * @return
	*/
	Matrix inv(int flag = GaussiaJordan);

	/**
	 * @brief 求矩阵行列式的值
	 * @return 行列式的值
	 * @note   用选主元高斯消去法计算n阶方阵(也只有方阵才能求行列式)所对应的行列式	
	*/
	NAFLOAT det() const;

	/**
	 * @brief 求矩阵的秩
	 * @return 矩阵的秩
	 * @note 用选主元高斯消去法计算矩阵的秩
	*/
	int rank() const;

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




	/**
	 * @brief	申请内存
	 * @returns:   void
	 * @note:  未看底层代码，不要轻易调用
	 */
	void create(int rows, int cols);

	/**
	 * @brief 释放已申请的内存
	 * @note 未看底层代码，不要轻易调用
	 */
	void release();

protected:
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

/**
 * @brief 实现的稀疏矩阵
*/
class NA_API SparseMatrix {
public:


private:


};


///@note 

/**
 * @brief 复数矩阵
*/
class NA_API  CMatrix {
public:
	CMatrix();
	/**
	 * @brief 析构
	*/
	virtual ~CMatrix();

	/**
	 * @brief 申请内存
	 * @param rows 
	 * @param cols 
	*/
	void create(int rows, int cols);


	/**
	 * @brief 释放已申请的内存
	 * @note 未看底层代码，不要轻易调用
	 */
	void release();
private:
	NAFLOAT* m_redata;///<实部数据指针
	NAFLOAT* m_imdata;///<虚部数据指针
	NAFLOAT** m_reval;///<实部二维指针
	NAFLOAT** m_imval;///<虚部数据指针
	int		m_rows;///行数
	int     m_cols;///列数
	int     m_step;

};






//! @} core_basic
}


