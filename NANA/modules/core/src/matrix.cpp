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

void Matrix::create()
{
	m_step = m_cols + m_cols *static_cast<int>(sizeof(NAFLOAT)) % 32;
	size_t nSize =static_cast<size_t> (m_rows)* m_step;
	m_data = new NAFLOAT[nSize];
}

void Matrix::release()
{
	deleteArraySafe(m_data);
}

}