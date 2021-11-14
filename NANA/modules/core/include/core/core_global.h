#pragma once
/*!
 * @file core_global.h
 * @date 2021/11/11 18:28
 *
 * @author Administrator
 * Contact: 707101557@qq.com
 *
 * @brief 全局头文件
 *
 * TODO: long description
 *
 * \note
*/
#include "nadef.h"

#ifdef NA_EXPORT
#define NA_API __declspec(dllexport)
#else
#define NA_API __declspec(dllimport)
#endif

namespace NANA {
enum  Error
{
	RetOk,//!<0表示返回值正常
	ErrParam,
	ErrRuntime,
	ErrAssert,///断言时出错
};



}


