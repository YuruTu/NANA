#pragma  once

/**
 * @file matrix.h
 * @date 2021/11/17 6:03
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief �򵥾�����(Ч�ʲ��ߣ����������⣬�ܶ�ʱ��ᴥ�����ƹ��캯��)����ͬ��Mat 
 *
 * TODO: long description
 *
 * \note
*/
#include "core_global.h"



namespace NANA{
typedef  double NAFLOAT;

/*!
 * @brief �򵥾�����
 */
class Matrix {
public:
	
	/**
	 * @brief  ���캯������������������ڴ�
	 * @returns   
	 * @param int rows
	 * @param int cols
	 * @note
	 */
	Matrix(int rows, int cols);

	~Matrix();

private:



	/**
	 * @brief	�����ڴ�
	 * @returns:   void
	 * @note:	
	 */
	void create();

	///************************************
	/// @brief:    release �ڴ��ͷ�
	/// @fullname:  NANA::Matrix::release
	/// @access:    private 
	/// @returns:   void
	/// @qualifier: 
	///************************************
	void release();

	/// @brief ���������
	NAFLOAT* m_data;
	/// @brief ����
	int m_rows;
	/// @brief ����
	int m_cols;
	/// @brief ����
	int m_step;
};



}