#pragma once
/**
 * @file bpnn.h
 * @date 2022/02/10 19:57
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief ʵ��BP������
 * \note
*/

#include <NANA/core.hpp>
namespace NANA {

namespace DNN {
/**
 * @class BPNN
 *
 * @brief BPNN������������
 *
 * @date 2022/05/24
 */
struct BPNN {
    int sample_count;///<��������
    int input_count;///<����������ά��
    int output_count;///<���������ά��
    int hidden_count;///<ʵ��ʹ��������Ԫ����
    double study_rate;///<ѧϰ����
    double precision;///<���ȿ��Ʋ���
    int loop_count;///<ѭ������
    Matrix v;///<������Ȩ����
    Matrix   w;///<�����Ȩ����
};
class NA_API CBPNN :public Algorithm {
public:
    CBPNN();

private:



};



}
}