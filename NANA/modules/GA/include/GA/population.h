#pragma once
/**
 * @file gene.h
 * @date 2021/12/12 20:57
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief ʵ����Ⱥ��
 * @note  ���ｫ�������������ˣ������кܶ������Խ��г���
   ʵ�ָ�ͨ�õ����,����ʱ�伱��δ��ʵ�֣�����������
 */


#include "gene.h"
#include <list>


namespace NANA {
namespace GA {

class NA_API Popultation {
public:

    /**
     * @brief ��¼��������
     */
    struct CResult {
        double val;
        int	   index;
    };



    Popultation(int groupNumber, int mutate);

    /**
     * @brief �������ٴ�
     * @param iterNum
    */
    void run(int iterNum);



protected:
    /**
     * @brief ����(����Ⱥ��ѡ������ĸ��壬��Ϊ�Ǵ�������ĸ���)
    */
    void  choose();

    /**
     * @brief ���µ���һ��
    */
    void update();
    int m_groupNumber;///<��Ⱥ����
    int						m_mutate;///<�ٷ�֮
    std::vector<GeneFloat>  m_members;///<��Ա
    std::vector<GeneFloat>  m_oldmembers;///��һ���ĳ�Ա
    std::vector<CResult>	m_result;///<���
    std::list<int>		    m_lives;///<�������ĸ���
};




}
}