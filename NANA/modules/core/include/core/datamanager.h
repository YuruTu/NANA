#pragma once
#include "core_global.h"
/**
 * @file datamanager.h
 * @date 2021/11/11 21:20
 *
 * @author Administrator
 * Contact: 707101557@qq.com
 *
 * @brief 实现一个数据管理器
 *
 * TODO: long description
 *
 * \note
*/


namespace NANA {


//! @addtogroup core_basic
//! @{
class CDataManager {
public:

    CDataManager();


    int m_refcount;///引用计数器




};

//! @} core_basic

}