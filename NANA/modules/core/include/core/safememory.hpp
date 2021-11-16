
#include "core_global.h"
/**
 * @file safememory.hpp
 * @date 2021/11/11 22:14
 *
 * @author Administrator
 * Contact: 707101557@qq.com
 *
 * @brief 实现安全的内存管理
 *
 * TODO: long description
 *
 * \note
*/

#include <memory>

namespace NANA {
/**
 * @brief 继承自std::shared_ptr的智能指针
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
 * @brief  deleteArraySafe 安全释放 xxx * a = new xxx[num];申请的内存
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


