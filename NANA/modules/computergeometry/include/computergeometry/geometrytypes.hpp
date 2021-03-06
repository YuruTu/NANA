#pragma  once

/**
 * @file geometrytypes.hpp
 * @date 2021/11/17 7:23
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 实现必须的几何类型
 *
 * TODO: long description
 *
 * \note
*/





namespace NANA {
namespace ComputerGeometry {
//! @addtogroup geometry_basic
//! @{
/**
 * @brief 2D直线
 */
template<typename _Tp>
struct Line2D_ {
    union {
        struct {
            _Tp x, y, dx, dy;
        };
        _Tp data[4];
    };
   
};

/**
 * @brief 3D直线
 */
template<typename _Tp>
struct Line3D_ {
    union {
        struct {
            _Tp x, y,z, dx, dy,dz;
        };
        _Tp data[6];
    };
};

/**
 * @brief 2D点集
 */
template<typename _Tp>
struct PointXY_ {
    PointXY_(_Tp _x, _Tp _y) {
        x = _x;
        y = _y;
        data[2] = static_cast<_Tp>(1);
    }
    union {
        struct {
            _Tp x, y;
        };
        _Tp data[3];
    };
};


/**
 * @brief 3D点集
 */
template<typename _Tp>
struct PointXYZ_ {
    PointXYZ_(_Tp _x, _Tp _y, _Tp _z) {
        x = _x;
        y = _y;
        z = _z;
        data[3] = static_cast<_Tp>(1);
    }
    union {
        struct {
            _Tp x;///<x坐标
            _Tp y;///<y坐标
            _Tp z;///<z坐标
        };
        _Tp data[4];///<数据部分

    };
};

/**
 * @brief 正矩形
 */
template<typename _Tp>
struct Rect_ {
    _Tp x, y, w, h;
};

/**
 * @class  Plane_
 *
 * @brief 自定义平面类
 *
 * @author yurutu
 * @date 2022/03/25
 */
template<typename _Tp>
struct Plane_ {
    union {
        struct {
            _Tp a;///<
            _Tp b;///<
            _Tp c;///<
            _Tp d;
        };
        _Tp data[4];///<数据部分
    };
};

//! @} geometry_basic


}
}