#pragma once
/*!
 * @file core_global.h
 * @date 2021/11/11 18:28
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief ȫ��ͷ�ļ�
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

/**
 * @brief ���ر�Ҫ�Ĵ������� 
 */
enum  Error
{
	RetOk,///<0��ʾ����ֵ����
	ErrParam,///<��������
	ErrRuntime,///<����ʱ����
	ErrAssert,///<����ʱ����
};



}


