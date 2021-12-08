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
 * @note  MatrixҲ�ǿ�����C����ʵ�ָ�Ч����ģ�������һ���ͱ����˱��ߵĳ���:һ�����ڽ�ѧ��SDK
*/
#include "core_global.h"
#include "error.h"
#include "nadef.hpp"


namespace NANA {

//! @addtogroup core_basic
//! @{

/////////////////////////////////////// Matrix ///////////////////////////////////////////
/**
 * @brief �򵥾�����
 * @note  ���������ط��̳�
 */
class NA_API  Matrix {
public:
	/**
	 * @brief ö�پ���ĸ��ַֽⷽ��
	 */
	enum DecompositionMethod {
		GaussiaJordan,///<��˹-Լ����ȥ��
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
	virtual ~Matrix();

	/**
	 * @brief ��ȡ���������
	 * @return 
	*/
	int cols() const;

	/**
	 * @brief ��ȡ���������
	 * @return 
	*/
	int rows() const;

	/**
	 * @brief ����ǰ��������Ϊ��λ����
	 * @return
	*/
	static void setMatrixEye(Matrix& mat, const int m);


	/**
	 * @brief ʵ�־����LU�ֽ�
	 * @param A  ���ֽ����
	 * @param L  �����Ǿ���L
	 * @param U  �����Ǿ���U
	 * @note   ���ڴ˷���û��ѡ��Ԫ������ֵ�����ǲ��ȶ���
	*/
	static void LU(const Matrix& A, Matrix& L, Matrix& U);

	/**
	 * @brief ���ں�˹�ɶ��±任ʵ�־����QR�ֽ�
	 * @param A 
	 * @param Q 
	 * @param R 
	*/
	static void QR(const Matrix & A, Matrix& Q, Matrix& R);

	/**
	 * @brief ʵ������ֵ�ֽ�
	 * @param A �������A
	 * @param U ����������U
	 * @param D �Խ��߸�������ֵ
	 * @param V ����������V^T
	 * @note  ����Householder�任�Լ�����QR�㷨��һ��ʵ����A��������ֵ�ֽ�
	*/
	static void SVD(const Matrix A, Matrix& U, Matrix& D, Matrix& v );

	/**
	 * @brief ����ȫ0����
	 * @param rows 
	 * @param cols 
	 * @return 
	*/
	static Matrix zeros(int rows, int cols);

	/**
	 * @brief ��value���Matrix��ȫ������
	 * @param value
	*/
	void fill(const NAFLOAT& value);

	/**
	 * @brief ��ȡֵ��ָ��
	 * @return
	*/
	NAFLOAT** getValPtr() const;

	/**
	 * @brief ��ȡ����ָ��
	 * @return 
	*/
	const NAFLOAT** getConstValPtr() const;


	/**
	 * @brief ʵ�־����ת��
	 * @return 
	*/
	Matrix T() const;

	/**
	 * @brief ����ʱ
	 * @param M
	 * @return
	*/
	Matrix& operator= (const Matrix& M);
	/**
	 * @brief ���ص�row�е���ʼָ��
	 * @param row 
	 * @return 
	*/
	const NAFLOAT* operator[](int row) const ;

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
	Matrix  operator* (const Matrix& B);

	/**
	 * @brief ʵ�־���ĵ��
	 * @param B �뵱ǰ����������ȵľ���
	 * @return 
	*/
	Matrix dot(const Matrix& B) const;



	/**
	 * @brief ����ĵ��
	 * @param b  
	 * @return 
	*/
	Matrix dot(NAFLOAT b) const;

	/**
	 * @brief ʵ�־��������
	 * @param flag
	 * @return
	*/
	Matrix inv(int flag = GaussiaJordan);

	/**
	 * @brief ���������ʽ��ֵ
	 * @return ����ʽ��ֵ
	 * @note   ��ѡ��Ԫ��˹��ȥ������n�׷���(Ҳֻ�з������������ʽ)����Ӧ������ʽ	
	*/
	NAFLOAT det() const;

	/**
	 * @brief ��������
	 * @return �������
	 * @note ��ѡ��Ԫ��˹��ȥ������������
	*/
	int rank() const;

	/**
	 * @brief ��istream����ʽ������ֵ
	 * @param is 
	 * @param m 
	 * @return 
	*/
	friend NA_API std::istream& operator>>(std::istream& is, Matrix& m);

	/**
	 * @brief �������е����ݵ���
	 * @param out 
	 * @param M 
	 * @return 
	*/
	friend NA_API std::ostream& operator<< (std::ostream& out, const Matrix& M);




	/**
	 * @brief	�����ڴ�
	 * @returns:   void
	 * @note:  δ���ײ���룬��Ҫ���׵���
	 */
	void create(int rows, int cols);

	/**
	 * @brief �ͷ���������ڴ�
	 * @note δ���ײ���룬��Ҫ���׵���
	 */
	void release();

protected:
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

/**
 * @brief ʵ�ֵ�ϡ�����
*/
class NA_API SparseMatrix {
public:


private:


};


///@note 

/**
 * @brief ��������
*/
class NA_API  CMatrix {
public:
	CMatrix();
	/**
	 * @brief ����
	*/
	virtual ~CMatrix();

	/**
	 * @brief �����ڴ�
	 * @param rows 
	 * @param cols 
	*/
	void create(int rows, int cols);


	/**
	 * @brief �ͷ���������ڴ�
	 * @note δ���ײ���룬��Ҫ���׵���
	 */
	void release();
private:
	NAFLOAT* m_redata;///<ʵ������ָ��
	NAFLOAT* m_imdata;///<�鲿����ָ��
	NAFLOAT** m_reval;///<ʵ����άָ��
	NAFLOAT** m_imval;///<�鲿����ָ��
	int		m_rows;///����
	int     m_cols;///����
	int     m_step;

};






//! @} core_basic
}


