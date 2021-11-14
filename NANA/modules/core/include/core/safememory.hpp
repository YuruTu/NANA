
#include "core_global.h"
/**
 * @file safememory.hpp
 * @date 2021/11/11 22:14
 *
 * @author Administrator
 * Contact: 707101557@qq.com
 *
 * @brief ʵ�ְ�ȫ���ڴ����
 *
 * TODO: long description
 *
 * \note
*/

namespace NANA {






///************************************
/// @brief:    deleteSafe ��ȫ�ڴ��ͷ�
/// @fullname:  deleteSafe
/// @access:    public 
/// @returns:   void
/// @qualifier:
/// @param: _T * & p
///************************************
template<typename _T>
inline void deleteSafe(_T*& p) {
	if (nullptr == p)
		return;
	delete p;
	p = nullptr;
}


}


