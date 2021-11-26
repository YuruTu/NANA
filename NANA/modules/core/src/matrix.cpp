#include "..\include\core\matrix.h"
#include "..\include\core\safememory.hpp"

namespace NANA {



Matrix::Matrix(int rows, int cols):
	m_rows(rows),
	m_cols(cols)
{
	this->create();
}

Matrix::~Matrix()
{
	this->release();
}

Matrix Matrix::eye(const int m) {
	Matrix M(m, m);
	M.fill(0.0);
	for (int32_t i = 0; i < m; i++)
		M.m_val[i][i] = 1.0;
	return M;
}


void Matrix::create()
{
	m_step = m_cols + m_cols *static_cast<int>(sizeof(NAFLOAT)) % 32;
	size_t nSize =static_cast<size_t> (m_rows)* m_step;
	m_data = new NAFLOAT[nSize];
	m_val = new NAFLOAT * [m_rows];
	m_val[0] = m_data;
	for(int i=1;i<m_rows;i++)
		m_val[i] = m_val[i - 1] + m_step/sizeof(NAFLOAT);
}

void Matrix::release()
{
	deleteArraySafe(m_data);
	deleteArraySafe(m_val);
}

void Matrix::fill(const NAFLOAT& value)
{
	int i;
	for (i = 0; i < m_cols; ++i) {
		m_val[0][i] = value;
	}
	size_t nLen = static_cast<size_t>(m_cols*sizeof(double));
	for (i = 1; i < m_rows; ++i) {
		memcpy(m_val[i], m_val[i-1], nLen);
	}

}

const NAFLOAT** Matrix::getValPtr()
{
	return const_cast<const NAFLOAT**>(m_val);
}

}