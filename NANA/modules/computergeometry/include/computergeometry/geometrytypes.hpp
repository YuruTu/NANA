#pragma  once
/**
 * @file geomotrytypes.hpp
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
	PointXYZ_(_Tp _x, _Tp _y,_Tp _z) {
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
		_Tp data[4];///<指针部分

	};
};


}
}