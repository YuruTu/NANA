#pragma once
/**
 * @file nadef.hpp
 * @date 2021/11/11 18:17
 *
 * \author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 数值分析所依赖的定义
 *
 * TODO: long description
 *
 * @note
*/

#include <vector>
#include <string>
#include <map>
#include <memory>
#include <float.h>

namespace NANA {

#if defined _MSC_VER || defined __BORLANDC__
typedef __int64 int64;
typedef unsigned __int64 uint64;
#else
typedef int64_t int64;
typedef uint64_t uint64;

#endif

#pragma region 定义数学上的常量和浮点数
/// 圆周率
#define NA_PI   3.1415926535897932384626433832795
 ///二倍圆周率
#define NA_2PI  6.283185307179586476925286766559

///定义一个极小的正数 smallest such that 1.0+DBL_EPSILON != 1.0
#define NA_EPS	 DBL_EPSILON

/// 数学常数
#define NA_EulerNum 2.7182818284590452353602874713526

typedef  double NAFLOAT;

#pragma endregion

#pragma region  类型重定义

typedef  std::string String;



#pragma endregion

/*!
 * @brief 二维数组的尺寸
 */
template<typename _Tp>
struct Size_ {
    Size_() :
        width(0),
        height(0)
    {

    }

    Size_(_Tp _width, _Tp _height) {
        width = _width;
        height = _height;
    }

    _Tp width;///<宽度
    _Tp height;///<高度
};
typedef Size_<int> Size2i;
typedef Size_<int64> Size2l;
typedef Size_<float> Size2f;
typedef Size_<double> Size2d;
typedef Size2i Size;

/**
 * @brief 判断一个数是否是Not a number
 * @param x
 * @return
*/
template<typename _Tp>
inline bool isNan(_Tp x) {
    if (x != x)
        return true;
    return false;
}



}