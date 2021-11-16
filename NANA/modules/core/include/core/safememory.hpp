
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

#include <memory>

namespace NANA {
/**
 * @brief �̳���std::shared_ptr������ָ��
 */
template<typename _T>
class Ptr : public std::shared_ptr<_T>
{
public:

private:

};


/**
 * @brief  
 * @returns   void
 * @param _T * & p
 * @note
 */
template<typename _T>
inline void deleteSafe(_T*& p) {
	if (nullptr == p)
		return;
	delete p;
	p = nullptr;
}


/**
 * @brief  deleteArraySafe ��ȫ�ͷ� xxx * a = new xxx[num];������ڴ�
 * @returns   void
 * @param _T * & p
 * @note
 */
template<typename _T>
inline void deleteArraySafe(_T*& p) {
	if (nullptr == p)
		return;
	delete [] p;
	p = nullptr;
}


}


