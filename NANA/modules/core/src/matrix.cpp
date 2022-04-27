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

Matrix::Matrix() :
    m_rows(0),
    m_cols(0),
    m_step(0),
    m_data(nullptr),
    m_val(nullptr) {

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
Matrix::Matrix(int m, int n, NAFLOAT const* val) {
    this->create(m, n);
    int32_t k = 0;
    for (int32_t i = 0; i < m; i++)
        for (int32_t j = 0; j < n; j++)
            m_val[i][j] = val[k++];
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


Matrix Matrix::getMat(int i1, int j1, int i2, int j2 ) {

    if (i2 == -1) i2 = m_rows - 1;
    if (j2 == -1) j2 = m_cols - 1;
    if (i1 < 0 || i2 >= m_rows || j1 < 0 || j2 >= m_cols || i2 < i1 || j2 < j1) {
        std::cerr << "ERROR: Cannot get submatrix [" << i1 << ".." << i2 <<
            "] x [" << j1 << ".." << j2 << "]" <<
            " of a (" << m_rows << "x" << m_cols << ") matrix." << std::endl;
        exit(0);
    }
    Matrix M(i2 - i1 + 1, j2 - j1 + 1);
    for (int32_t i = 0; i < M.m_rows; i++)
        for (int32_t j = 0; j < M.m_cols; j++)
            M.m_val[i][j] = m_val[i1 + i][j1 + j];
    return M;
}


void   Matrix::setMat(const Matrix& M, int i1, int j1) {
    if (i1<0 || j1<0 || i1 + M.m_rows>m_rows || j1 + M.m_cols>m_cols) {
        std::cerr << "ERROR: Cannot set submatrix [" << i1 << ".." << i1 + M.m_rows - 1 <<
            "] x [" << j1 << ".." << j1 + M.m_cols - 1 << "]" <<
            " of a (" << m_rows << "x" << m_cols << ") matrix." << std::endl;
        exit(0);
    }
    for (int32_t i = 0; i < M.m_rows; i++)
        for (int32_t j = 0; j < M.m_cols; j++)
            m_val[i1 + i][j1 + j] = M.m_val[i][j];
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
    for (k = 0; k < rows - 1; ++k) {
        NA_Assert(std::fabs(q[k][k]) > NA_EPS);
        for (i = k + 1; i < rows; ++i) {
            q[i][k] /= q[k][k];
            for (j = k + 1; j < cols; ++j) {
                q[i][j] -= (q[i][k] * q[k][j]);
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

void Matrix::QR(const Matrix& A, Matrix& Q, Matrix& R) {
    int rows = A.rows();
    int cols = A.cols();
    R = A;
    NA_Assert(rows >= cols);///QR分解要求矩阵的行数大于等于列数
    setMatrixEye(Q, rows);///<设置一个单位矩阵
    int ncols, i, j, k;
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

static NAFLOAT SIGN(NAFLOAT a, NAFLOAT b) {
    if (b >= 0.0)
        return std::fabs(a);
    return -std::fabs(a);
}

static NAFLOAT SQR(NAFLOAT a) {
    if (a == 0.0)
        return 0.0;
    return a * a;
}

NAFLOAT pythag(NAFLOAT a, NAFLOAT b) {
    NAFLOAT absa, absb;
    absa = fabs(a);
    absb = fabs(b);
    if (absa > absb)
        return absa * std::sqrt(1.0 + SQR(absb / absa));
    else
        return (absb == 0.0 ? 0.0 : absb * sqrt(1.0 + SQR(absa / absb)));
}

/**
 * @brief 实现奇异值分解
 * @note  基于Householder变换以及变星QR算法对一般实矩阵A进行奇异值分解
 * step1 用豪斯荷尔德变换将A约化为双对角线矩阵
 * step2 用变星的QR算法进行迭代，计算所有奇异值
 * steo3 对奇异值按非递增次序进行排列
*/
void Matrix::SVD( const Matrix & A, Matrix& U2, Matrix& W, Matrix& V) {
    Matrix U = A;
    int m = A.rows();
    int n = A.cols();
    U2 = Matrix(m, m);
    V = Matrix(n, n);

    NAFLOAT* w = (NAFLOAT*)malloc(n * sizeof(NAFLOAT));
    NAFLOAT* rv1 = (NAFLOAT*)malloc(n * sizeof(NAFLOAT));

    int32_t flag, i, its, j, jj, k, l, nm;
    NAFLOAT   anorm, c, f, g, h, s, scale, x, y, z;

    g = scale = anorm = 0.0;
    for (i = 0; i < n; i++) {
        l = i + 1;
        rv1[i] = scale * g;
        g = s = scale = 0.0;
        if (i < m) {
            for (k = i; k < m; k++) scale += fabs(U.m_val[k][i]);
            if (scale) {
                for (k = i; k < m; k++) {
                    U.m_val[k][i] /= scale;
                    s += U.m_val[k][i] * U.m_val[k][i];
                }
                f = U.m_val[i][i];
                g = -SIGN(sqrt(s), f);
                h = f * g - s;
                U.m_val[i][i] = f - g;
                for (j = l; j < n; j++) {
                    for (s = 0.0, k = i; k < m; k++) s += U.m_val[k][i] * U.m_val[k][j];
                    f = s / h;
                    for (k = i; k < m; k++) U.m_val[k][j] += f * U.m_val[k][i];
                }
                for (k = i; k < m; k++) U.m_val[k][i] *= scale;
            }
        }
        w[i] = scale * g;
        g = s = scale = 0.0;
        if (i < m && i != n - 1) {
            for (k = l; k < n; k++) scale += fabs(U.m_val[i][k]);
            if (scale) {
                for (k = l; k < n; k++) {
                    U.m_val[i][k] /= scale;
                    s += U.m_val[i][k] * U.m_val[i][k];
                }
                f = U.m_val[i][l];
                g = -SIGN(sqrt(s), f);
                h = f * g - s;
                U.m_val[i][l] = f - g;
                for (k = l; k < n; k++) rv1[k] = U.m_val[i][k] / h;
                for (j = l; j < m; j++) {
                    for (s = 0.0, k = l; k < n; k++) s += U.m_val[j][k] * U.m_val[i][k];
                    for (k = l; k < n; k++) U.m_val[j][k] += s * rv1[k];
                }
                for (k = l; k < n; k++) U.m_val[i][k] *= scale;
            }
        }
        anorm = std::max(anorm, (std::fabs(w[i]) + std::fabs(rv1[i])));
    }
    for (i = n - 1; i >= 0; i--) { // Accumulation of right-hand transformations.
        if (i < n - 1) {
            if (g) {
                for (j = l; j < n; j++) // Double division to avoid possible underflow.
                    V.m_val[j][i] = (U.m_val[i][j] / U.m_val[i][l]) / g;
                for (j = l; j < n; j++) {
                    for (s = 0.0, k = l; k < n; k++) s += U.m_val[i][k] * V.m_val[k][j];
                    for (k = l; k < n; k++) V.m_val[k][j] += s * V.m_val[k][i];
                }
            }
            for (j = l; j < n; j++) V.m_val[i][j] = V.m_val[j][i] = 0.0;
        }
        V.m_val[i][i] = 1.0;
        g = rv1[i];
        l = i;
    }
    for (i = std::min(m, n) - 1; i >= 0; --i) { // Accumulation of left-hand transformations.
        l = i + 1;
        g = w[i];
        for (j = l; j < n; j++) U.m_val[i][j] = 0.0;
        if (g) {
            g = 1.0 / g;
            for (j = l; j < n; j++) {
                for (s = 0.0, k = l; k < m; k++) s += U.m_val[k][i] * U.m_val[k][j];
                f = (s / U.m_val[i][i]) * g;
                for (k = i; k < m; k++) U.m_val[k][j] += f * U.m_val[k][i];
            }
            for (j = i; j < m; j++) U.m_val[j][i] *= g;
        }
        else for (j = i; j < m; j++) U.m_val[j][i] = 0.0;
        ++U.m_val[i][i];
    }
    for (k = n - 1; k >= 0; k--) { // Diagonalization of the bidiagonal form: Loop over singular values,
        for (its = 0; its < 30; its++) { // and over allowed iterations.
            flag = 1;
            for (l = k; l >= 0; l--) { // Test for splitting.
                nm = l - 1;
                if ((NAFLOAT)(fabs(rv1[l]) + anorm) == anorm) { flag = 0; break; }
                if ((NAFLOAT)(fabs(w[nm]) + anorm) == anorm) { break; }
            }
            if (flag) {
                c = 0.0; // Cancellation of rv1[l], if l > 1.
                s = 1.0;
                for (i = l; i <= k; i++) {
                    f = s * rv1[i];
                    rv1[i] = c * rv1[i];
                    if ((NAFLOAT)(fabs(f) + anorm) == anorm) break;
                    g = w[i];
                    h = pythag(f, g);
                    w[i] = h;
                    h = 1.0 / h;
                    c = g * h;
                    s = -f * h;
                    for (j = 0; j < m; j++) {
                        y = U.m_val[j][nm];
                        z = U.m_val[j][i];
                        U.m_val[j][nm] = y * c + z * s;
                        U.m_val[j][i] = z * c - y * s;
                    }
                }
            }
            z = w[k];
            if (l == k) { // Convergence.
                if (z < 0.0) { // Singular value is made nonnegative.
                    w[k] = -z;
                    for (j = 0; j < n; j++) V.m_val[j][k] = -V.m_val[j][k];
                }
                break;
            }

            NA_Assert(its != 29,"ERROR in SVD: No convergence in 30 iterations");
            x = w[l]; // Shift from bottom 2-by-2 minor.
            nm = k - 1;
            y = w[nm];
            g = rv1[nm];
            h = rv1[k];
            f = ((y - z) * (y + z) + (g - h) * (g + h)) / (2.0 * h * y);
            g = pythag(f, 1.0);
            f = ((x - z) * (x + z) + h * ((y / (f + SIGN(g, f))) - h)) / x;
            c = s = 1.0; // Next QR transformation:
            for (j = l; j <= nm; j++) {
                i = j + 1;
                g = rv1[i];
                y = w[i];
                h = s * g;
                g = c * g;
                z = pythag(f, h);
                rv1[j] = z;
                c = f / z;
                s = h / z;
                f = x * c + g * s;
                g = g * c - x * s;
                h = y * s;
                y *= c;
                for (jj = 0; jj < n; jj++) {
                    x = V.m_val[jj][j];
                    z = V.m_val[jj][i];
                    V.m_val[jj][j] = x * c + z * s;
                    V.m_val[jj][i] = z * c - x * s;
                }
                z = pythag(f, h);
                w[j] = z; // Rotation can be arbitrary if z = 0.
                if (z) {
                    z = 1.0 / z;
                    c = f * z;
                    s = h * z;
                }
                f = c * g + s * y;
                x = c * y - s * g;
                for (jj = 0; jj < m; jj++) {
                    y = U.m_val[jj][j];
                    z = U.m_val[jj][i];
                    U.m_val[jj][j] = y * c + z * s;
                    U.m_val[jj][i] = z * c - y * s;
                }
            }
            rv1[l] = 0.0;
            rv1[k] = f;
            w[k] = x;
        }
    }

    // sort singular values and corresponding columns of u and v
    // by decreasing magnitude. Also, signs of corresponding columns are
    // flipped so as to maximize the number of positive elements.
    int32_t s2, inc = 1;
    NAFLOAT   sw;
    NAFLOAT* su = (NAFLOAT*)malloc(m * sizeof(NAFLOAT));
    NAFLOAT* sv = (NAFLOAT*)malloc(n * sizeof(NAFLOAT));
    do { inc *= 3; inc++; } while (inc <= n);
    do {
        inc /= 3;
        for (i = inc; i < n; i++) {
            sw = w[i];
            for (k = 0; k < m; k++) su[k] = U.m_val[k][i];
            for (k = 0; k < n; k++) sv[k] = V.m_val[k][i];
            j = i;
            while (w[j - inc] < sw) {
                w[j] = w[j - inc];
                for (k = 0; k < m; k++) U.m_val[k][j] = U.m_val[k][j - inc];
                for (k = 0; k < n; k++) V.m_val[k][j] = V.m_val[k][j - inc];
                j -= inc;
                if (j < inc) break;
            }
            w[j] = sw;
            for (k = 0; k < m; k++) U.m_val[k][j] = su[k];
            for (k = 0; k < n; k++) V.m_val[k][j] = sv[k];
        }
    } while (inc > 1);
    for (k = 0; k < n; k++) { // flip signs
        s2 = 0;
        for (i = 0; i < m; i++) if (U.m_val[i][k] < 0.0) s2++;
        for (j = 0; j < n; j++) if (V.m_val[j][k] < 0.0) s2++;
        if (s2 > (m + n) / 2) {
            for (i = 0; i < m; i++) U.m_val[i][k] = -U.m_val[i][k];
            for (j = 0; j < n; j++) V.m_val[j][k] = -V.m_val[j][k];
        }
    }

    // create vector and copy singular values
    W = Matrix(std::min(m, n), 1, w);

    // extract mxm submatrix U
    U2.setMat(U.getMat(0, 0, m - 1, std::min(m - 1, n - 1)), 0, 0);

    // release temporary memory
    free(w);
    free(rv1);
    free(su);
    free(sv);
}




void Matrix::solve(const Matrix& A, const Matrix& b, Matrix& x, int flag) {
    if (DecompositionMethod::GaussiaJordan == flag) {
        x = A.inv(DecompositionMethod::GaussiaJordan) * b;
    }
}

Matrix Matrix::zeros(int rows, int cols) {
    Matrix mat(rows, cols);
    mat.fill(0.0);
    return mat;
}

void Matrix::create(int rows, int cols)
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
    size_t nSize = static_cast<size_t> (m_rows) * m_step;
    m_data = new NAFLOAT[nSize];
    m_val = new NAFLOAT * [m_rows];
    m_val[0] = m_data;
    for (int i = 1; i < m_rows; i++)
        m_val[i] = m_val[i - 1] + m_step;
}

void Matrix::release()
{
#ifdef NANA_DEBUG
    std::cout << "内存释放\n";
#endif
    deleteArraySafe(m_data);
    deleteArraySafe(m_val);
    m_rows = m_cols = 0;
}

void Matrix::fill(const NAFLOAT& value)
{
    int i;
    for (i = 0; i < m_cols; ++i) {
        m_val[0][i] = value;
    }
    size_t nLen = static_cast<size_t>(m_cols * sizeof(NAFLOAT));
    for (i = 1; i < m_rows; ++i) {
        memcpy(m_val[i], m_val[i - 1], nLen);
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
                memcpy(m_val[i], M.m_val[i], m_step * sizeof(NAFLOAT));
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
    NA_Assert(A.m_cols == B.m_rows);

    Matrix C(A.m_rows, B.m_cols);
    C.fill(0.0);
    for (int i = 0; i < A.m_rows; i++)
        for (int j = 0; j < B.m_cols; j++)
            for (int k = 0; k < A.m_cols; k++)
                C.m_val[i][j] += A.m_val[i][k] * B.m_val[k][j];
    return C;
}

Matrix Matrix::dot(const Matrix& B) const {

    NA_Assert((m_cols == B.m_cols) && (m_rows == B.m_rows));

    Matrix C(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m_cols; j++)
            C.m_val[i][j] = m_val[i][j] * B.m_val[i][j];
    return C;
}

Matrix Matrix::dot(NAFLOAT b) const {
    Matrix C(m_rows, m_cols);
    for (int i = 0; i < m_rows; i++)
        for (int j = 0; j < m_cols; j++)
            C.m_val[i][j] = m_val[i][j] * b;
    return C;
}

/**
 * @brief 使用高斯-约当消去法求矩阵的逆矩阵
 * @param src 输入矩阵
 * @param dst 逆矩阵
 * @return
*/
static int  GaussiaJordanInv(const Matrix& src, Matrix& dst) {
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
        for (i = k; i < rows; ++i) {
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
        temp = is[k];
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


Matrix Matrix::inv(int flag) const {
    Matrix invMat;
    if (GaussiaJordan == flag) {
        GaussiaJordanInv(*this, invMat);
    }


    return invMat;
}

NAFLOAT Matrix::det() const {
    ///只有方阵才能求行列式
    NA_Assert(m_rows == m_cols);
    double f, detVal, q, d;
    int i, j, k, is, js;
    int n = m_rows;
    f = 1.0;
    detVal = 1.0;
    Matrix A = *this;
    double** a = A.getValPtr();
    for (k = 0; k < n - 1; ++k) {
        q = 0.0;
        for (i = k; i < n; ++i) {
            for (j = k; j < n; ++j) {
                d = std::fabs(a[i][j]);
                if (d > q) {
                    q = d;
                    is = i;
                    js = j;
                }
            }
        }

        if (q < NA_EPS) {
            return 0.0;
        }
        if (is != k) {
            f = -f;
            for (j = k; j < n; ++j) {
                d = a[k][j];
                a[k][j] = a[is][j];
                a[is][j] = d;
            }
        }

        if (js != k) {
            f = -f;
            for (i = k; i < n; ++i) {
                d = a[i][js];
                a[i][js] = a[i][k];
                a[i][k] = d;
            }
        }

        detVal *= a[k][k];
        for (i = k + 1; i < n; ++i) {
            d = a[i][k] / a[k][k];
            for (j = k + 1; j < n; ++j) {
                a[i][j] -= d * a[k][j];
            }
        }
    }
    detVal *= f * a[n - 1][n - 1];
    return detVal;
}


int Matrix::rank() const {
    int i, j, k, nn, is, js, cycle;
    double q, d;
    ///拷贝一份数据，计算秩的过程，不应该改变矩阵的内容
    Matrix A = *this;
    double** a = A.getValPtr();
    nn = std::min(m_rows, m_cols);
    k = 0;
    for (cycle = 0; cycle < nn; ++cycle) {
        q = 0.0;
        for (i = 1; i < m_rows; ++i) {
            for (j = 1; j < m_cols; ++j) {
                d = std::fabs(a[i][j]);
                if (d > q) {
                    q = d;
                    is = i;
                    js = j;
                }
            }
        }

        if (q < NA_EPS)
            return k;

        ++k;
        if (is != cycle) {
            for (j = 1; j < m_cols; ++j) {
                d = a[cycle][j];
                a[cycle][j] = a[is][j];
                a[is][j] = d;
            }
        }
        if (js != cycle) {
            for (i = 1; i < m_rows; ++i) {
                d = a[i][js];
                a[i][js] = a[i][cycle];
                a[i][cycle] = d;
            }
        }
        for (i = cycle + 1; i < m_rows; ++i) {
            d = a[i][cycle] / a[cycle][cycle];
            for (j = cycle + 1; j < m_cols; ++j) {
                a[i][j] -= d * a[cycle][j];
            }
        }


    }

    return k;

}

std::istream& operator>>(std::istream& is, Matrix& m)
{
    NAFLOAT** val = m.getValPtr();
    for (int i = 0; i < m.rows(); i++) {
        for (int j = 0; j < m.cols(); j++) {
            is >> val[i][j];
        }
    }
    return is;
}

std::ostream& operator<< (std::ostream& out, const Matrix& M){
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








///////////////////////////////////////////////复数矩阵开始/////////////////////////////////////////
CMatrix::CMatrix() {
    m_redata = nullptr;
    m_imdata = nullptr;
    m_reval = nullptr;
    m_imval = nullptr;
    m_rows = 0;
    m_cols = 0;
}

CMatrix::~CMatrix() {
    this->release();
}

void CMatrix::create(int rows, int cols) {
    m_rows = rows;
    m_cols = cols;
    int temp = m_cols % 32;
    if (0 == temp)
        m_step = m_cols;
    else
        m_step = m_cols + 32 - temp;
    size_t nSize = static_cast<size_t> (m_rows) * m_step;
    ///为实部申请数据
    m_redata = new NAFLOAT[nSize];
    m_reval = new NAFLOAT * [m_rows];
    m_reval[0] = m_redata;
    for (int i = 1; i < m_rows; i++)
        m_reval[i] = m_reval[i - 1] + m_step;
    m_imdata = new NAFLOAT[nSize];
    m_imval = new NAFLOAT * [m_rows];
    m_imval[0] = m_imdata;
    for (int i = 1; i < m_rows; i++)
        m_imval[i] = m_imval[i - 1] + m_step;
}



/**
 * @brief 释放已申请的内存
 * @note 未看底层代码，不要轻易调用
 */
void CMatrix::release() {
    deleteArraySafe(m_redata);
    deleteArraySafe(m_reval);
    deleteArraySafe(m_imdata);
    deleteArraySafe(m_imval);
    m_rows = m_cols = 0;
}




}