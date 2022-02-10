#pragma once
/**
 * @file gene.h
 * @date 2021/12/12 19:57
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief ʵ�ֻ��������
 * \note
*/


#include <NANA/core.hpp>
#include <vector>
namespace NANA {
namespace GA {
/**
 * @brief �����ʾ����
 */
class NA_API CGeneInt NA_FINAL {
public:

    CGeneInt(int minV, int maxV);
    /**
     * @brief �����ʼ��
    */
    void initGene();
    /**
     * @brief ������ת��Ϊ��Ӧ��ֵ
     */
    int translate();
private:
    std::vector<bool> m_gene;///<��������
    int m_minV;
    int m_maxV;
};


/**
 *  �����ʾ������
 */
class  NA_API GeneFloat NA_FINAL {
public:

    GeneFloat(double minV, double maxV, double eps);
    /**
     * @brief �����ʼ��
    */
    void initGene();

    /**
     * @brief ת¼����������ϢתΪֵ
    */
    double translate();


    /**
     * @brief �������
    */
    void mutate();

    /**
     * @brief Ⱦɫ��Ľ���
     * @param father
     * @param mother
     * @param child
    */
    static void cross(const GeneFloat& father, const GeneFloat& mother, GeneFloat& child);


private:
    double            m_minV;///<��Сֵ
    double			  m_maxV;///<���ֵ
    double			  m_eps;///<��ǰ��������Ҫ�ľ���
    double			  m_rate;///<Ϊ�������ȶ������޸�
    int				m_lenGene;///<���򳤶�
    std::vector<bool> m_gene;///<��������
};






}
}