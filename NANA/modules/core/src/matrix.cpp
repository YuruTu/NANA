#include "..\include\core\matrix.h"
#include "..\include\core\safememory.hpp"
#include <iostream>
namespace NANA {

Matrix::Matrix() {
	m_rows = 0;
	m_cols = 0;
	m_data = nullptr;
	m_val = nullptr;
}

Matrix::Matrix(int rows, int cols)
{
	this->create(rows, cols);
}

Matrix::~Matrix()
{
	this->release();
}

void Matrix::setMatrixEye(Matrix& mat, const int m) {
	mat.release();
	mat.create(m, m);
	mat.fill(0.0);
	for (int i = 0; i < m; i++)
		mat.m_val[i][i] = 1.0;
}


void Matrix::create(int rows,int cols)
{
#ifdef NANA_DEBUG
	std::cout << "�ڴ�����\n";
#endif
	m_rows = rows;
	m_cols = cols;
	int temp = m_cols % 32;
	if (0 == temp)
		m_step = m_cols;
	else
		m_step = m_cols + 32 - temp;
	size_t nSize =static_cast<size_t> (m_rows)* m_step;
	m_data = new NAFLOAT[nSize];
	m_val = new NAFLOAT * [m_rows];
	m_val[0] = m_data;
	for(int i=1;i<m_rows;i++)
		m_val[i] = m_val[i - 1] + m_step;
}

void Matrix::release()
{
#ifdef NANA_DEBUG
	std::cout << "�ڴ��ͷ�\n";
#endif
	deleteArraySafe(m_data);
	deleteArraySafe(m_val);
}

void Matrix::fill(const NAFLOAT& value)
{
	int i;
	for (i = 0; i < m_cols; ++i) {
		m_val[0][i] = value;
	}
	size_t nLen = static_cast<size_t>(m_cols*sizeof(NAFLOAT));
	for (i = 1; i < m_rows; ++i) {
		memcpy(m_val[i], m_val[i-1], nLen);
	}

}

const NAFLOAT** Matrix::getValPtr() const
{
	return const_cast<const NAFLOAT**>(m_val);
}

int Matrix::getRows() const
{
	return m_rows;
}

int Matrix::getCols() const
{
	return m_cols;
}

Matrix Matrix::operator=(const Matrix& M)
{
	if (this != &M) {
		if (M.m_cols != m_cols || M.m_rows != m_rows) {
			this->release();
			this->create(M.m_rows, M.m_cols);
		}
		if (M.m_cols > 0)
			for (int i = 0; i < M.m_rows; i++)
				memcpy(m_val[i], M.m_val[i], m_step* sizeof(NAFLOAT));
	}
	return *this;
}

}