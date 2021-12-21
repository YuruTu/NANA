#include "../include/GA/population.h"
#include <cmath>
#include <algorithm>
#include <iostream>



namespace NANA {
namespace GA {

/**
 * @brief ��Ҫ�Ż��ĺ���
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
		///��ʼ�����̣����ɲ�ͬ�Ļ���
		m_members[i].initGene();
	}
}


static bool  CResultCmp(Popultation::CResult const& A, Popultation::CResult const& B) {
	return A.val > B.val;
}

void Popultation::run(int iterNum) {
	
	while (0 != (iterNum--)) {
		/// �ﾺ������ƾ���Լ���������ȡ��Դ������Խ��ǰ�ĸ�����ȥ����ԴԽ��
		for (int i = 0; i < m_groupNumber; ++i) {
			double x = m_members[i].translate();
			m_result[i].val = myFun(x);
			m_result[i].index = i;
		}
		std::sort(m_result.begin(), m_result.end(), CResultCmp);
#if 1
		///��ӡ��ǰ������ĸ���
		double x = m_members[m_result[0].index].translate();
		std::cout << "����������ĸ���:" << x << "��ǰĿ�꺯��ֵ:" << m_result[0].val << std::endl;
#endif 
		/// ����
		this->choose();
		/// ���µ���һ��
		this->update();
	}
}

void  Popultation::choose()
{
	///�÷������Ϊ�����������治��Ӱ��
	m_lives.clear();
	m_lives.push_back(m_result[0].index);
	///<ǰ�ٷ�֮10�ĸ���Ϊ����,����ӵ�аٷ�֮90�Ĵ����
	int s1 = 1;
	int s2 = m_groupNumber / 10;
	for (int i = s1; i < s2; ++i) {
		int randNum = rand() % 100;
		///ҡɸ�ӣ�ҡ������Ϊ[0-89]����Ϊ���
		if (randNum < 90) {
			m_lives.push_back(m_result[i].index);
		}
	}
	///<��Ϊ��ʿ�ĸ��壬ӵ�аٷ�֮70�Ĵ����
	s1 = s2;
	s2 = m_groupNumber / 30;
	for (int i = s1; i < s2; ++i) {
		int randNum = rand() % 100;
		///ҡɸ�ӣ�ҡ������Ϊ[0-69]����Ϊ���
		if (randNum < 70) {
			m_lives.push_back(m_result[i].index);
		}
	}
	s1 = s2;
	s2 = m_groupNumber;
	///<��Ϊƽ��ĸ����аٷ�֮50�Ĵ����
	for (int i = s1; i < s2; ++i) {
		int randNum = rand() % 100;
		///ҡɸ�ӣ�ҡ������Ϊ[0-49]����Ϊ���
		if (randNum < 50) {
			m_lives.push_back(m_result[i].index);
		}
	}
}

void Popultation::update() {
	int nSize = static_cast<int>(m_lives.size());
	/// ����Ⱥ�������
	
	m_oldmembers = m_members;
	/// �����ⲿ�������
	int remainingSpace = m_groupNumber - nSize;
	int outSize = remainingSpace >> 1;
	remainingSpace -= outSize;
	int s1 = 0;
	int s2 = outSize;
	for (int i = s1; i < s2; ++i) {
		m_members[i].initGene();
	}
	///Ϊ�˱�֤�������ʣ��ռ��ǰremainingSpace�ĸ���
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
		//������ĸ����ĸ��������
		GeneFloat::cross(m_oldmembers[mid], m_oldmembers[fid], m_members[s1++]);
		temp = rand() % 100;
		if (temp < m_mutate) {
			m_members[s1-1].mutate();
		}
	} while (s1 < s2);
}


}
}



