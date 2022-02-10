#pragma once
/**
 * @file gene.h
 * @date 2021/12/12 19:57
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 实现基因的运算
 * \note
*/


#include <NANA/core.hpp>
#include <vector>
namespace NANA {
namespace GA {
/**
 * @brief 基因表示整数
 */
class NA_API CGeneInt NA_FINAL {
public:

    CGeneInt(int minV, int maxV);
    /**
     * @brief 基因初始化
    */
    void initGene();
    /**
     * @brief 将基因转化为对应的值
     */
    int translate();
private:
    std::vector<bool> m_gene;///<基因序列
    int m_minV;
    int m_maxV;
};


/**
 *  基因表示浮点数
 */
class  NA_API GeneFloat NA_FINAL {
public:

    GeneFloat(double minV, double maxV, double eps);
    /**
     * @brief 基因初始化
    */
    void initGene();

    /**
     * @brief 转录，将基因信息转为值
    */
    double translate();


    /**
     * @brief 基因变异
    */
    void mutate();

    /**
     * @brief 染色体的交换
     * @param father
     * @param mother
     * @param child
    */
    static void cross(const GeneFloat& father, const GeneFloat& mother, GeneFloat& child);


private:
    double            m_minV;///<最小值
    double			  m_maxV;///<最大值
    double			  m_eps;///<当前基因所需要的精度
    double			  m_rate;///<为调整精度而做的修改
    int				m_lenGene;///<基因长度
    std::vector<bool> m_gene;///<基因序列
};






}
}