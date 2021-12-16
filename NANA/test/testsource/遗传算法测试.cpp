#include <core.hpp>
#include <ga.hpp>
#include <iostream>
/**
 * @file main.cpp
 * @date 2021/11/14 12:45
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief ≤‚ ‘œ‡πÿŒƒµµ
 *
 * TODO: long description
 *
 * \note
*/



using namespace NANA;
using namespace GA;


int main() {
	Popultation mPopulation(500, 5);
	mPopulation.run(300);
	system("pause");
	return 0;
}

