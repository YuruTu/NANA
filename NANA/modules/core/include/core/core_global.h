#pragma once
/*!
 * @file core_global.h
 * @date 2021/11/11 18:28
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 全局头文件
 *
 * TODO: long description
 *
 * \note
*/
#include "nadef.hpp"

#ifdef _WIN64///兼容windows系统与linux系统
#ifdef NA_EXPORT
#define NA_API __declspec(dllexport)
#else
#define NA_API __declspec(dllimport)
#endif
#else
#define NA_API
#endif

#define NA_FINAL final

namespace NANA {

/**
 * @brief 返回必要的错误类型 
 */
enum  Error
{
	RET_OK,///<0表示返回值正常
	ERR_PARAM,///<参数出错
	ERR_RUNTIME,///<运行时出错
	ERR_ASSERT,///<断言时出错
};



}


