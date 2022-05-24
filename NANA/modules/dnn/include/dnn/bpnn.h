#pragma once
/**
 * @file bpnn.h
 * @date 2022/02/10 19:57
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 实现BP神经网络
 * \note
*/

#include <NANA/core.hpp>
namespace NANA {

namespace DNN {
/**
 * @class BPNN
 *
 * @brief BPNN所依赖的数据
 *
 * @date 2022/05/24
 */
struct BPNN {
    int sample_count;///<样本数量
    int input_count;///<输入向量的维数
    int output_count;///<输出向量的维数
    int hidden_count;///<实际使用隐层神经元数量
    double study_rate;///<学习速率
    double precision;///<精度控制参数
    int loop_count;///<循环次数
    Matrix v;///<隐含层权矩阵
    Matrix   w;///<输出层权矩阵
};
class NA_API CBPNN :public Algorithm {
public:
    CBPNN();

private:



};



}
}