#include "../include/GA/gene.h"
#include <cmath>
#include <random>


namespace NANA {
namespace GA {

/**
 * @brief �ж�һ����С��2�ļ��η�
 * @param vlaue
 * @return
*/
static int log2(int value) {
    int result = 0;
    while (0 != value)
    {
        value >>= 1;
        ++result;
    }
    return result;


}

CGeneInt::CGeneInt(int minV, int maxV) :
    m_minV(minV),
    m_maxV(maxV) {

}

void CGeneInt::initGene() {

}
int CGeneInt::translate() {
    int result = 0;

    ///<todo something

    return result;
}


GeneFloat::GeneFloat(double minV, double maxV, double eps) :
    m_minV(minV),
    m_maxV(maxV),
    m_eps(eps) {

    ///!<�������ֵ����Сֵ���û���ĳ���
    double range = std::round((maxV - minV) / eps);
    int nRange = static_cast<int>(range);
    m_lenGene = log2(nRange);
    double realRange = std::pow(2.0, m_lenGene) - 1.0;
    m_rate = range / realRange;
    m_gene.resize(m_lenGene);
}



void GeneFloat::initGene() {
    for (int i = 0; i < m_lenGene; ++i) {
        if (0 == (rand() % 2)) {
            m_gene[i] = false;
        }
        else {
            m_gene[i] = true;
        }
    }
}

double GeneFloat::translate() {
    double result = 0.0;
    for (int i = 0; i < m_lenGene; ++i) {
        if (m_gene[i])
            result += std::pow(2.0, i) * m_eps;
    }
    result *= m_rate;///<���￴��ȥ�ܹ֣�������Ϊ�˽�������ĺ���������������������
    return result;
}

void GeneFloat::mutate() {
    int randid = rand() % m_lenGene;
    m_gene[randid] = !m_gene[randid];///����ȡ��
}

void GeneFloat::cross(const GeneFloat& father, const GeneFloat& mother, GeneFloat& child1) {
    int randid = rand() % father.m_lenGene;
    int i;
    for (i = 0; i < randid; ++i) {
        child1.m_gene[i] = father.m_gene[i];
    }
    for (; i < father.m_lenGene; ++i) {
        child1.m_gene[i] = mother.m_gene[i];
    }
}



}
}