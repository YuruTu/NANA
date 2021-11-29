#pragma  once

/**
 * @file matrix.h
 * @date 2021/11/17 6:03
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief �򵥾�����(Ч�ʲ��ߣ���������⣬�ܶ�ʱ��ᴥ�����ƹ��캯��)����ͬ��Mat
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
typedef  double NAFLOAT;

/*!
 * @brief �򵥾�����
 */
class NA_API Matrix {//NA_FINAL{
public:
	/**
	 * @brief ö�پ���ĸ��ַֽⷽ��
	 */
	enum DecompositionMethod {
		LU,
		QR,
		SVD,
	};

	Matrix();

	/**
	 * @brief  ���캯������������������ڴ�
	 * @returns
	 * @param int rows
	 * @param int cols
	 * @note
	 */
	Matrix(int rows, int cols);

	/**
	 * @brief ʵ�ָ��ƹ��캯��
	 * @param M
	*/
	Matrix(const Matrix& M);

	/**
	 * @brief ����������������ͷ�������ڴ�
	 */
	~Matrix();

	/**
	 * @brief ����ǰ��������Ϊ��λ����
	 * @return
	*/
	static void setMatrixEye(Matrix& mat, const int m);




	/**
	 * @brief ��value���Matrix��ȫ������
	 * @param value
	*/
	void fill(const NAFLOAT& value);

	/**
	 * @brief ��ȡֵ��ָ��
	 * @return
	*/
	const NAFLOAT** getValPtr() const;

	/**
	 * @brief ��ȡ��ǰ���������
	 * @return
	*/
	int getRows() const;

	/**
	 * @brief ��ȡ��ǰ���������
	 * @return
	*/
	int getCols() const;


	/**
	 * @brief ����ʱ
	 * @param M
	 * @return
	*/
	Matrix& operator= (const Matrix& M);

	/**
	 * @brief ʵ�־���ļӷ�
	 * @param M
	 * @return C = A+B
	*/
	Matrix  operator+ (const Matrix& B);


	/**
	 * @brief ʵ�־���ļ���
	 * @param B
	 * @return C = A-B
	*/
	Matrix  operator- (const Matrix& M);

	/**
	 * @brief ʵ�־���ĳ˷�
	 * @param B
	 * @return C = A*B
	 */
	Matrix  operator* (const Matrix& M);

	/**
	 * @brief ʵ�־��������
	 * @param flag
	 * @return
	*/
	Matrix inv(int flag = LU);



private:



	/**
	 * @brief	�����ڴ�
	 * @returns:   void
	 * @note:
	 */
	void create(int rows, int cols);

	/**
	 * @brief �ͷ���������ڴ�
	 */
	void release();

	/// @brief ���������
	NAFLOAT** m_val;
	NAFLOAT* m_data;

	/// @brief ����
	int m_rows;
	/// @brief ����
	int m_cols;
	/// @brief ����
	int m_step;
};


//! @} core_basic
}


