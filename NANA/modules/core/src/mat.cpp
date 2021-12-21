#include "..\include\core\mat.h"
/**
 * @file mat.cpp
 * @date 2021/11/12 11:36
 *
 * @author Administrator
 * Contact: 707101557@qq.com
 *
 * @brief 实现Mat的相关功能
 *
 * TODO: long description
 *
 * \note
*/
#pragma once

namespace NANA {


template<typename _T>
Mat<_T>::Mat()
{
    m_rows = 0;
    m_cols = 0;
    m_stride = 0;
    m_data = nullptr;
    m_datamanager = nullptr;
}

template<typename _T>
Mat<_T>::Mat(int rows, int cols)
{
    m_rows = rows;
    m_cols = cols;
    m_stride = cols * sizeof(_T);
    m_stride = m_stride + m_stride % 32;
    m_datamanager = new CDataManager();
    this->allocateMemory(m_rows, m_stride);
}

template<typename _T>
Mat<_T>::~Mat()
{
    this->release();
}



template<typename _T>
void Mat<_T>::allocateMemory(const int32_t rows, const int32_t m_stride)
{
    m_data = reinterpret_cast<char*>(malloc(rows * m_stride));
}

template<typename _T>
void Mat<_T>::releaseMemory()
{
    if (nullptr != m_data) {
        delete[] m_data;
        m_data = nullptr;
    }
}

template<typename _T>
void Mat<_T>::release()
{
    if (nullptr == m_datamanager)
        return;
    if ((m_datamanager->m_refcount--) != 1)
        return;
    this->releaseMemory();
    deleteSafe(m_datamanager);
}



}

