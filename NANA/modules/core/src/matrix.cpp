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



void Matrix::LU(const Matrix& A, Matrix& L, Matrix& U) {
	int rows = A.rows();
	int cols = A.cols();
	NA_Assert(rows == cols);
	Matrix Q = A;
	L.release();
	L.create(rows, cols);
	U.release();
	U.create(rows, cols);
	NAFLOAT** q = Q.getValPtr();
	NAFLOAT** l = L.getValPtr();
	NAFLOAT** u = U.getValPtr();

	int i, j, k;
	for (k = 0; k < rows- 1; ++k) {
		NA_Assert(std::fabs(q[k][k]) > NA_EPS);
		for (i = k+1; i < rows; ++i) {
			q[i][k] /= q[k][k];
			for (j = k + 1; j < cols; ++j) {
				q[i][j] -= (q[i][k]*q[k][j]);
			}

		}
	}

	for (i = 0; i < rows; ++i) {
		for (j = 0; j < i; ++j) {
			l[i][j] = q[i][j];
			u[i][j] = 0.0;
		}
		l[i][i] = 1.0;
		u[i][i] = q[i][i];
		for (j = i + 1; j < cols; ++j) {
			l[i][j] = 0.0;
			u[i][j] = q[i][j];
		}
	}
}

void Matrix::QR(const Matrix & A, Matrix& Q, Matrix& R) {
	int rows = A.rows();
	int cols = A.cols();
	R = A;
	NA_Assert(rows>=cols);///QR分解要求矩阵的行数大于等于列数
	setMatrixEye(Q,rows);///<设置一个单位矩阵
	int ncols, i, j,k;
	if (rows == cols)
		ncols = rows - 1;
	else
		ncols = cols;
	double u, alpha, w, t;
	NAFLOAT** a = R.getValPtr();
	NAFLOAT** q = Q.getValPtr();
	for (k = 0; k < ncols; ++k) {
		u = 0.0;
		for (i = k; i < rows; ++i) {
			w = std::fabs(a[i][k]);
			if (w > u)
				u = w;
		}
		NA_Assert(u >= NA_EPS);
		alpha = 0.0;
		for (i = k; i < rows; ++i) {
			t = a[i][k] / u;
			alpha += (t * t);
		}
		if (a[k][k] > 0.0)
			u = -u;
		alpha = u * std::sqrtf(alpha);
		NA_Assert(std::fabs(alpha) >= NA_EPS);
		u = std::sqrtf(2.0 * alpha * (alpha - a[k][k]));
		NA_Assert(!isNan(u));
		a[k][k] = (a[k][k] - alpha) / u;

		for (i = k + 1; i < rows; ++i) 
			a[i][k] /= u;
		
		for (j = 0; j < rows; ++j) {
			t = 0.0;
			for (i = k; i < rows; ++i)
				t += a[i][k] * q[i][j];
			for (i = k; i < rows; ++i)
				q[i][j] -= 2.0 * t * a[i][k];
		}
		for (j = k + 1; j < cols; ++j) {
			t = 0.0;
			for (i = k; i < rows; ++i) 
				t += a[i][k] * a[i][j];
			for (i = k; i < rows; ++i)
				a[i][j] -= 2.0 * t * a[i][k];
		}
		a[k][k] = alpha;
		for (i = k + 1; i < rows; ++i)
			a[i][k] = 0.0;
	}
	for (i = 0; i < ncols; ++i) {
		for (j = i + 1; j < rows; ++j) {
			t = q[i][j];
			q[i][j] = q[j][i];
			q[j][i] = t;
		}
	}
}


/**
 * @brief 实现奇异值分解
 * @note  基于Householder变换以及变星QR算法对一般实矩阵A进行奇异值分解
 * step1 用豪斯荷尔德变换将A约化为双对角线矩阵
 * step2 用变星的QR算法进行迭代，计算所有奇异值
 * steo3 对奇异值按非递增次序进行排列
*/
void Matrix::SVD(const Matrix A, Matrix& U, Matrix& D, Matrix& V) {
	int rows = A.rows();
	int cols = A.cols();
	int ka = std::max(rows, cols) + 1;
	std::vector<NAFLOAT> s(ka);
	std::vector<NAFLOAT> e(ka);
	std::vector<NAFLOAT> w(ka);
	//it's too difficult ,wait...


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