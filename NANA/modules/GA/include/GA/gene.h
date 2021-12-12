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


#include <core.hpp>
#include <vector>
namespace NANA {
namespace GA {
/**
 *  �����ʾ������
 */
class  NA_API GeneFloat {
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
	 * @param child1 
	 * @param child2 
	*/
	static void cross(const GeneFloat & father, const GeneFloat & mother , GeneFloat & child);


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