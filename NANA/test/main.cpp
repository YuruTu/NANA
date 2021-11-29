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
	int width = a.getCols();
	int height = a.getRows();
	const double** pdata = a.getValPtr();
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
	Matrix a;
	Matrix::setMatrixEye(a, 3);
	Matrix b;
	Matrix::setMatrixEye(b, 4);
	showMatrix(a);
	showMatrix(b);
	Matrix c = a + b;
	showMatrix(c);
	system("pause");
	return 0;
}

