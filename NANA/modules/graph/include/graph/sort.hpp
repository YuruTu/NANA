#pragma once
/**
 * @file sort.hpp
 * @date 2021/11/17 18:52
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief ʵ�ֿ���������㷨
 *
 * TODO: long description
 *
 * \note
*/

namespace NANA {
namespace GRAPH {




/**
 * @brief  ���ڵݹ�Ŀ�������
 * @returns   void
 * @param[in|out] _Tp * datas ����ָ��
 * @param[in] int l ���������
 * @param[in] int r ��������
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
 * @brief ð������
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