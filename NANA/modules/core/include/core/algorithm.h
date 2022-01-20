#pragma  once

/**
 * @file algorithm.h
 * @date 2022/01/20 6:03
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 1.实现基类Algorithm
 *
 * @note  基类Algorithm是其它算法的基类
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
     * @brief 读取参数
     * @param paramFile 
     * @return 
    */
    virtual int read(std::string const& paramFile);

    /**
     * @brief 保存参数
     * @param paramFile 
     * @return 
    */
    virtual int save(std::string const& paramFile);



protected:
};



}