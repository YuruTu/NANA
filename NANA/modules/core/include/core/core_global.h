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
#include "nadef.hpp"

#ifdef _WIN64///����windowsϵͳ��linuxϵͳ
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
 * @brief ���ر�Ҫ�Ĵ������� 
 */
enum  Error
{
	RET_OK,///<0��ʾ����ֵ����
	ERR_PARAM,///<��������
	ERR_RUNTIME,///<����ʱ����
	ERR_ASSERT,///<����ʱ����
};



}


