#pragma  once

/**
 * @file algorithm.h
 * @date 2022/01/20 6:03
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 1.ʵ�ֻ���Algorithm
 *
 * @note  ����Algorithm�������㷨�Ļ���
*/
#include "core_global.h"
#include "error.h"
#include "nadef.hpp"



namespace NANA {

class NA_API Algorithm {
public:
    Algorithm();

    virtual ~Algorithm();
    
    /**
     * @brief ��ȡ����
     * @param paramFile 
     * @return 
    */
    virtual int Read(std::string const& paramFile);

    /**
     * @brief �������
     * @param paramFile 
     * @return 
    */
    virtual int Save(std::string const& paramFile);



protected:
};



}