#include <core.hpp>
#include <iostream>
/**
 * @file main.cpp
 * @date 2021/11/14 12:45
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief ��������ĵ�
 *
 * TODO: long description
 *
 * \note
*/



using namespace NANA;

void showMatrix(const Matrix & a) {
	std::cout << "������ʾ��\n";
	int width = a.cols();
	int height = a.rows();
	double** pdata = a.getValPtr();
	int u, v;
	for (v = 0; v < height; v++) {
		for (u = 0; u < width; u++) {
			std::cout << pdata[v][u] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


int main() {

	Matrix A(4, 4);
	std::cin >> A;
	std::cout << A.det();
#if 0
	Matrix A(4, 4);
	std::cin >> A;
	Matrix L, U;
	Matrix::LU(A, L, U);
	std::cout << "L:\n" << L << "U:\n" << U;
	Matrix A(4, 4);
	std::cin >> A;
	Matrix B = A.inv();
	std::cout << "����A-1" << B;
	Matrix C = A * B;
	std::cout << "����A*A-1" << C;
	Matrix a = Matrix::zeros(4, 5);
	std::cout << a;

	Matrix a;
	Matrix::setMatrixEye(a, 3);
	Matrix b;
	Matrix::setMatrixEye(b,3);
	showMatrix(a);
	showMatrix(b);
	Matrix c = a + b;
	showMatrix(c);
	Matrix d(3, 1);
	std::cin >> d;
	showMatrix(d);
#endif
	system("pause");
	return 0;
}

