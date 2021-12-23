#pragma once
#include <core.hpp>
/**
 * @file binarytree.hpp
 * @date 2021/11/11 22:41
 *
 * @author Administrator
 * Contact: 707101557@qq.com
 *
 * @brief ʵ�ֶ�������ģ��
 *
 * TODO: long description
 *
 * \note
*/
#include <queue>

namespace NANA {
namespace GRAPH {
//! @addtogroup Graph_basic
//! @{

/**
 * @class  BinTreeNode
 * @brief  �������Ľڵ�
 * @tparam T 
*/
template<typename T>
struct BinTreeNode
{
    T data;///<����д洢������
    BinTreeNode<T>* leftChild;///<������
    BinTreeNode<T>* rightChild;///<������
    BinTreeNode() :
        leftChild(nullptr),
        rightChild(nullptr) {
    }
    BinTreeNode(T x, BinTreeNode<T>* l = nullptr, BinTreeNode<T>* r = nullptr) :
        data(x),
        leftChild(l),
        rightChild(r) {
    }
};

///<���ڵݹ�Ķ������������(��->��->��)
template<typename T>
void PreOrder(BinTreeNode<T>*& subTree,std::queue<T> & curQueue)
{
    if (nullptr!=subTree)
    {
        curQueue.push(subTree->data);
        PreOrder(subTree->leftChild, curQueue);
        PreOrder(subTree->rightChild, curQueue);
    }
}

///<���ڵݹ���������(��->��->��)
template<typename T>
void InOrder(BinTreeNode<T>*& subTree, std::queue<T>& curQueue)
{
    if (nullptr != subTree )
    {
        InOrder(subTree->leftChild, curQueue);
        curQueue.push(subTree->data);
        InOrder(subTree->rightChild, curQueue);
    }
}

///<���ڵݹ�ĺ�������(��->��->��)
template<typename T>
void PostOrder(BinTreeNode<T>*& subTree, std::queue<T>& curQueue)
{
    if (nullptr!= subTree)
    {
        PostOrder(subTree->leftChild, curQueue);
        PostOrder(subTree->rightChild, curQueue);
        curQueue.push(subTree->data);
    }
}



/**
 * @brief ����������
 * @tparam _T 
*/
template<typename _T>
class CBinaryTree {

public:
    CBinaryTree() :
        m_root(nullptr) {

    }

    bool empty() {
        if (nullptr == m_root)
            return true;
        return false;
    }


protected:
    BinTreeNode<T>* m_root; ///<���ڵ�


};

//! @} Graph_basic


}
}
