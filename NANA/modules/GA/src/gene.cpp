#include "../include/GA/gene.h"
#include <cmath>
#include <random>


namespace NANA {
namespace GA {

/**
 * @brief 判断一个数小于2的几次方
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

    ///!<根据最大值和最小值设置基因的长度
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
    result *= m_rate;///<这里看上去很怪，但我是为了解决后续的汉明悬崖问题而保留的设计
    return result;
}

void GeneFloat::mutate() {
    int randid = rand() % m_lenGene;
    m_gene[randid] = !m_gene[randid];///类型取反
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