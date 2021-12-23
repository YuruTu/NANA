#pragma once
#include <core.hpp>
/**
 * @file binarytree.hpp
 * @date 2021/11/11 22:41
 *
 * @author Administrator
 * Contact: 707101557@qq.com
 *
 * @brief 实现二叉树的模板
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
 * @brief  二叉树的节点
 * @tparam T 
*/
template<typename T>
struct BinTreeNode
{
    T data;///<结点中存储的数据
    BinTreeNode<T>* leftChild;///<左子树
    BinTreeNode<T>* rightChild;///<右子树
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

///<基于递归的二叉树先序遍历(根->左->右)
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

///<基于递归的中序遍历(左->根->右)
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

///<基于递归的后续遍历(左->右->根)
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
 * @brief 二叉树的类
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
    BinTreeNode<T>* m_root; ///<根节点


};

//! @} Graph_basic


}
}
