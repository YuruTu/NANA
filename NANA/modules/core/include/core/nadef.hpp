#pragma once
/*!
 * \file nadef.h
 * \date 2021/11/11 18:17
 *
 * \author yurutu
 * Contact: 707101557@qq.com
 *
 * \brief ��ֵ�����������Ķ���
 *
 * TODO: long description
 *
 * \note
*/

#include <vector>
#include <string>
#include <map>
#include <memory>


namespace NANA {

#if defined _MSC_VER || defined __BORLANDC__
typedef __int64 int64;
typedef unsigned __int64 uint64;
#else
typedef int64_t int64;
typedef uint64_t uint64;

#endif

#pragma region  �����Ҫ�ĺ�
/// Բ����
#define NA_PI   3.1415926535897932384626433832795
 ///����Բ����
#define NA_2PI  6.283185307179586476925286766559

/// ��ѧ����
#define NA_EulerNum 2.7182818284590452353602874713526



#pragma endregion

#pragma region  �����ض���

typedef  std::string String;



#pragma endregion

/*!
 * @brief ��ά����ĳߴ�
 */
template<typename _Tp>
struct Size_{
	Size_():
		width(0),
		height(0)
	{

	}

	Size_(_Tp _width, _Tp _height) {
		width = _width;
		height = _height;
	}

	_Tp width;///<����
	_Tp height;///<�߶�
};
typedef Size_<int> Size2i;
typedef Size_<int64> Size2l;
typedef Size_<float> Size2f;
typedef Size_<double> Size2d;
typedef Size2i Size;






}