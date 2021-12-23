#pragma once
/**
 * @file sort.hpp
 * @date 2021/11/17 18:52
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 实现快速排序等算法
 *
 * TODO: long description
 *
 * \note
*/

namespace NANA {
namespace GRAPH {




/**
 * @brief  基于递归的快速排序
 * @returns   void
 * @param[in|out] _Tp * datas 数据指针
 * @param[in] int l 排序最左端
 * @param[in] int r 排序最后端
 * @note
 */
template<typename _Tp>
void quickSort(_Tp* datas, int l, int r)
{
    if (l < r)
    {
        int i = l, j = r;
        _Tp temp = datas[l];
        while (i < j)
        {
            while (i < j && datas[j] >= temp)
            {
                j--;
            }
            s[i] = s[j];
            while (i < j && datas[i] <= temp)
            {
                i++;
            }
            s[j] = s[i];
        }
        s[i] = temp;
        quickSort(datas, l, i - 1);
        quickSort(datas, i + 1, r);
    }
}

/**
 * @brief 冒泡排序
 * @param datas
 * @param l
 * @param r
*/
template<typename _Tp>
void bubSort(_Tp* datas, int l, int r) {
    for (int i = l; i < r; ++i) {

    }


}





}
}