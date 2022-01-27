#include <core.hpp>
#include <iostream>
#include<sstream>

/**
 * @file main.cpp
 * @date 2021/11/14 12:45
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 测试相关文档
 *
 * TODO: long description
 *
 * \note
*/



using namespace NANA;



int main() {

	///<实现矩阵奇异值分解测试
	Matrix A(4, 5);
	Matrix U, W, v;
	std::cin >> A;
	Matrix::SVD(A, U, W, v);
	std::cout << U;
	std::cout << W;
	std::cout << v;
#if 0
	Matrix A(4, 4);
	std::cin >> A;
	Matrix L, U;
	Matrix::LU(A, L, U);
	std::cout << "L:\n" << L << "U:\n" << U;
	Matrix A(4, 4);
	std::cin >> A;
	Matrix B = A.inv();
	std::cout << "矩阵A-1" << B;
	Matrix C = A * B;
	std::cout << "矩阵A*A-1" << C;
	Matrix a = Matrix::zeros(4, 5);
	std::cout << a;

	Matrix a;
	Matrix::setMatrixEye(a, 3);
	Matrix b;
	Matrix::setMatrixEye(b, 3);
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