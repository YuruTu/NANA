#pragma once
/**
 * @file gene.h
 * @date 2021/12/12 20:57
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 实现种群类
 * @note  这里将基因类抽象出来了，但还有很多概念可以进行抽象，
   实现更通用的软件,由于时间急促未能实现，后续将补上
 */


#include "gene.h"
#include <list>


namespace NANA {
namespace GA {

class NA_API Popultation {
public:

    /**
     * @brief 记录结果和序号
     */
    struct CResult {
        double val;
        int	   index;
    };



    Popultation(int groupNumber, int mutate);

    /**
     * @brief 迭代多少次
     * @param iterNum
    */
    void run(int iterNum);



protected:
    /**
     * @brief 天择(从种群中选择优秀的个体，认为是存活下来的个体)
    */
    void  choose();

    /**
     * @brief 更新到下一代
    */
    void update();
    int m_groupNumber;///<种群数量
    int						m_mutate;///<百分之
    std::vector<GeneFloat>  m_members;///<成员
    std::vector<GeneFloat>  m_oldmembers;///上一代的成员
    std::vector<CResult>	m_result;///<结果
    std::list<int>		    m_lives;///<活下来的个体
};




}
}