#include "..\include\math\polynomialevaluation.hpp"


namespace NANA {
namespace MATH {

double PolynomialEvaluation2D(const Matrix& mat, double x, double y, int n) {
	NA_Assert(n == mat.cols());
	double ret, s, xx;
	int m = mat.rows();
	ret = 0.0;
	xx = 1.0;
	for (int i = 0; i < m; ++i) {
		s = mat[i][n - 1] * xx;
		for (int j = n - 2; j >= 0; --j) {
			s = s * y +mat[i][j] * xx;
		}
		ret += s;
		xx *= x;
	}

	return ret;
}



}
}