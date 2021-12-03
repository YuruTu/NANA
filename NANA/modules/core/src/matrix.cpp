/**
 * @file matrix.cpp
 * @date 2021/11/29 6:03
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 简单矩阵类的实现
 *
 * TODO:
 *
 * @note
*/

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

Matrix::Matrix(const Matrix& M) {
	this->create(M.m_rows, M.m_cols);
	for (int i = 0; i < M.m_rows; i++)
		memcpy(m_val[i], M.m_val[i], M.m_cols * sizeof(NAFLOAT));
}


Matrix::~Matrix()
{
	this->release();
}


int Matrix::cols() const {
	return m_cols;
}

int Matrix::rows() const {
	return m_rows;
}

void Matrix::setMatrixEye(Matrix& mat, const int m) {
	mat.release();
	mat.create(m, m);
	mat.fill(0.0);
	for (int i = 0; i < m; i++)
		mat.m_val[i][i] = 1.0;
}

Matrix Matrix::zeros(int rows, int cols) {
	Matrix mat(rows, cols);
	mat.fill(0.0);
	return mat;
}

void Matrix::create(int rows,int cols)
{
#ifdef NANA_DEBUG
	std::cout << "内存申请\n";
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
	std::cout << "内存释放\n";
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

NAFLOAT** Matrix::getValPtr() const
{
	return m_val;
}

const NAFLOAT** Matrix::getConstValPtr() const {
	return const_cast<const NAFLOAT**>(m_val);
}

Matrix Matrix::T() const {
	Matrix C(m_cols, m_rows);
	for (int i = 0; i < m_rows; i++)
		for (int32_t j = 0; j < m_cols; j++)
			C.m_val[j][i] = m_val[i][j];
	return C;
}

Matrix& Matrix::operator=(const Matrix& M)
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


const NAFLOAT* Matrix::operator[](int row) const {
	return const_cast<const  NAFLOAT*>(m_val[row]);
}

Matrix Matrix::operator+ (const Matrix& B) {
	Matrix& A = *this;
	NA_Assert(A.m_cols == B.m_cols || A.m_rows == B.m_rows);

	Matrix C(A.m_rows, A.m_cols);
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			C.m_val[i][j] = A.m_val[i][j] + B.m_val[i][j];
	return C;
}


Matrix Matrix::operator-(const Matrix& B) {
	Matrix& A = *this;
	NA_Assert(A.m_cols == B.m_cols || A.m_rows == B.m_rows);

	Matrix C(A.m_rows, A.m_cols);
	for (int i = 0; i < m_rows; i++)
		for (int j = 0; j < m_cols; j++)
			C.m_val[i][j] = A.m_val[i][j] - B.m_val[i][j];
	return C;
}


Matrix Matrix::operator*(const Matrix& B) {
	Matrix& A = *this;
	NA_Assert(A.m_cols == B.m_rows );

	Matrix C(A.m_rows, B.m_cols);
	C.fill(0.0);
	for (int i = 0; i < A.m_rows; i++)
		for (int j = 0; j < B.m_cols; j++)
			for (int k = 0; k < A.m_cols; k++)
				C.m_val[i][j] += A.m_val[i][k] * B.m_val[k][j];
	return C;
}

/**
 * @brief 使用高斯-约当消去法求矩阵的逆矩阵
 * @param src 输入矩阵
 * @param dst 逆矩阵
 * @return 
*/
static int  GaussiaJordanInv(Matrix & src,Matrix &dst) {
	int rows = src.rows();
	int cols = src.cols();
	NA_Assert(rows == cols);
	///<数据拷贝
	dst = src;
	int i, j, k, temp;
	NAFLOAT** data = dst.getValPtr();

	std::vector<int> is(rows);
	std::vector<int> js(cols);
	/// 为数值计算的稳定性：交换主元
	double d, p;
	for (k = 0; k < rows; ++k) {
		d = 0.0;
		for (i = k; i < rows;++i) {
			for (j = k; j < cols; ++j) {
				p = std::fabs(data[i][j]);
				if (p > d) {
					d = p;
					is[k] = i;
					js[k] = j;
				}
			}
		}
		NA_Assert(d >= NA_EPS);
		temp = is[k];
		if (temp != k) {
			for (j = 0; j < cols; ++j) {
				p = data[k][j];
				data[k][j] = data[temp][j];
				data[temp][j] = p;
			}
		}
		temp = js[k];
		if (temp != k) {
			for (i = 0; i < rows; ++i) {
				p = data[i][k];
				data[i][k] = data[i][temp];
				data[i][temp] = p;
			}
		}
		/// 归一化
		data[k][k] = 1.0 / data[k][k];

		for (j = 0; j < cols; ++j) {
			if (k == j)
				continue;
			data[k][j] *= data[k][k];
		}
		///消元计算
		for (i = 0; i < rows; ++i) {
			if (i == k)
				continue;
			for (j = 0; j < cols; ++j) {
				if (j == k)
					continue;
				data[i][j] -= data[i][k] * data[k][j];
			}
		}
		for (i = 0; i < rows; ++i) {
			if (i == k)
				continue;
			data[i][k] *= (-data[k][k]);
		}
	}


	for (k = rows - 1; k >= 0; --k) {
		temp = js[k];
		if (k != temp) {
			for (j = 0; j < cols; ++j) {
				p = data[k][j];
				data[k][j] = data[temp][j];
				data[temp][j] = p;
			}
		}
		temp= is[k];
		if (k != temp) {
			for (i = 0; i < rows; ++i) {
				p = data[i][k];
				data[i][k] = data[i][temp];
				data[i][temp] = p;
			}
		}
	}


	return RET_OK;
}


Matrix Matrix::inv(int flag) {
	Matrix invMat;
	if (GaussiaJordan == flag) {
		GaussiaJordanInv(*this,invMat);
	}


	return invMat;
}


std::istream& operator>>(std::istream& is, Matrix& m)
{
	NAFLOAT** val =m.getValPtr();
	for (int i = 0; i < m.rows(); i++) {
		for (int j = 0; j < m.cols(); j++) {
			is>>val[i][j];
		}
	}
	return is;
}

std::ostream& operator<< (std::ostream& out, const Matrix& M) {
	if (M.m_cols == 0 || M.m_rows == 0) {
		out << "[empty matrix]";
	}
	else {
		char buffer[1024];
		for (int i = 0; i < M.m_rows; i++) {
			for (int j = 0; j < M.m_cols; j++) {
				sprintf_s(buffer, "%12.7f ", M.m_val[i][j]);
				out << buffer;
			}
			out << std::endl;
		}
	}
	return out;
}



}