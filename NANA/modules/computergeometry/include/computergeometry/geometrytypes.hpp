#pragma  once
/**
 * @file geomotrytypes.hpp
 * @date 2021/11/17 7:23
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief ʵ�ֱ���ļ�������
 *
 * TODO: long description
 *
 * \note
*/





namespace NANA {
namespace ComputerGeometry {

/**
 * @brief 2D�㼯
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
 * @brief 3D�㼯
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
			_Tp x;///<x����
			_Tp y;///<y����
			_Tp z;///<z����
		};
		_Tp data[4];///<ָ�벿��

	};
};


}
}