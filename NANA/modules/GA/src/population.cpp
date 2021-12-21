#include "../include/GA/population.h"
#include <cmath>
#include <algorithm>
#include <iostream>



namespace NANA {
namespace GA {

/**
 * @brief 需要优化的函数
 * @param x 
 * @return 
*/
static double myFun(const double& x) {
	return x * std::sin(10.0 * NA_PI * x) + 1.0;
}



Popultation::Popultation(int groupNumber, int mutate):
m_groupNumber(groupNumber),
m_mutate(mutate){
	GeneFloat initGene(-1.0, 2.0, 1e-6);
	m_members.clear();
	m_result.resize(groupNumber);
	for (int i = 0; i < groupNumber; ++i) {
		m_members.push_back(initGene);
		///初始化过程，生成不同的基因
		m_members[i].initGene();
	}
}


static bool  CResultCmp(Popultation::CResult const& A, Popultation::CResult const& B) {
	return A.val > B.val;
}

void Popultation::run(int iterNum) {
	
	while (0 != (iterNum--)) {
		/// 物竞，个体凭借自己的力量获取资源，排名越靠前的个体月去的资源越多
		for (int i = 0; i < m_groupNumber; ++i) {
			double x = m_members[i].translate();
			m_result[i].val = myFun(x);
			m_result[i].index = i;
		}
		std::sort(m_result.begin(), m_result.end(), CResultCmp);
#if 1
		///打印当前最优秀的个体
		double x = m_members[m_result[0].index].translate();
		std::cout << "当代最优秀的个体:" << x << "当前目标函数值:" << m_result[0].val << std::endl;
#endif 
		/// 天择
		this->choose();
		/// 更新到下一代
		this->update();
	}
}

void  Popultation::choose()
{
	///得分最佳者为国王，其生存不受影响
	m_lives.clear();
	m_lives.push_back(m_result[0].index);
	///<前百分之10的个体为贵族,贵族拥有百分之90的存活率
	int s1 = 1;
	int s2 = m_groupNumber / 10;
	for (int i = s1; i < s2; ++i) {
		int randNum = rand() % 100;
		///摇筛子，摇出点数为[0-89]则认为存活
		if (randNum < 90) {
			m_lives.push_back(m_result[i].index);
		}
	}
	///<作为骑士的个体，拥有百分之70的存活率
	s1 = s2;
	s2 = m_groupNumber / 30;
	for (int i = s1; i < s2; ++i) {
		int randNum = rand() % 100;
		///摇筛子，摇出点数为[0-69]则认为存活
		if (randNum < 70) {
			m_lives.push_back(m_result[i].index);
		}
	}
	s1 = s2;
	s2 = m_groupNumber;
	///<作为平民的个体有百分之50的存活率
	for (int i = s1; i < s2; ++i) {
		int randNum = rand() % 100;
		///摇筛子，摇出点数为[0-49]则认为存活
		if (randNum < 50) {
			m_lives.push_back(m_result[i].index);
		}
	}
}

void Popultation::update() {
	int nSize = static_cast<int>(m_lives.size());
	/// 补充群落的数量
	
	m_oldmembers = m_members;
	/// 允许外部个体进来
	int remainingSpace = m_groupNumber - nSize;
	int outSize = remainingSpace >> 1;
	remainingSpace -= outSize;
	int s1 = 0;
	int s2 = outSize;
	for (int i = s1; i < s2; ++i) {
		m_members[i].initGene();
	}
	///为了保证优秀基因，剩余空间给前remainingSpace的个体
	s1 = s2;
	s2 += remainingSpace;
	for (int i = s1; i < s2; ++i) {
		m_members[i] = m_oldmembers[m_result[i].index];
	}
	/// 
	s1 = s2;
	s2 = m_groupNumber-1;
	int id, fid, mid,temp,j;
	std::list<int>::iterator iter = m_lives.begin();
	if (1 == (nSize % 2)) {
		id = rand() % nSize;
		for ( j = 0; j < (id-1);j++)
			iter++;
		m_lives.erase(iter);
		--nSize;
		fid = m_result[id].index;
		m_members[s1++] = m_oldmembers[fid];
	}

	do{
		id = rand() % nSize;
		iter = m_lives.begin();
		for (j = 0; j < (id - 1); j++)
			iter++;
		m_lives.erase(iter);
		--nSize;
		fid = m_result[id].index;
		nSize = static_cast<int>(m_lives.size());
		id = rand() % nSize;
		iter = m_lives.begin();
		for (j = 0; j < (id - 1); j++)
			iter++;
		m_lives.erase(iter);
		--nSize;
		mid = m_result[id].index;
		GeneFloat::cross(m_oldmembers[fid], m_oldmembers[mid], m_members[s1++]);
		temp = rand() % 100;
		if (temp < m_mutate) {
			m_members[s1-1].mutate();
		}
		//父本做母本，母本做父本
		GeneFloat::cross(m_oldmembers[mid], m_oldmembers[fid], m_members[s1++]);
		temp = rand() % 100;
		if (temp < m_mutate) {
			m_members[s1-1].mutate();
		}
	} while (s1 < s2);
}


}
}



