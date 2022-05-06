#pragma once
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


/**
 * @brief  基于递归的二叉树先序遍历(根->左->右)
 * @returns   void
 * @param BinTreeNode<T> * & subTree
 * @param std::queue<T> & curQueue
 * @note
 */
template<typename T>
void PreOrder(BinTreeNode<T>* node,std::queue<T> & curQueue)
{
    if (nullptr == node)
        return;

    curQueue.push(node->data);
    PreOrder(node->leftChild, curQueue);
    PreOrder(node->rightChild, curQueue);
    
}

/**
 * @Method:    InOrder
 * @FullName:  NANA::GRAPH::InOrder
 * @Returns:   void
 * @Qualifier: 基于递归的中序遍历(左->根->右)
 * @Parameter: BinTreeNode<T> * node 节点
 * @Parameter: std::queue<T> & curQueue 保存的队列
 */
template<typename T>
void InOrder(BinTreeNode<T>* node, std::queue<T>& curQueue)
{
    if (nullptr == node)
        return;

    InOrder(node->leftChild, curQueue);
    curQueue.push(node->data);
    InOrder(node->rightChild, curQueue);
    
}


/**
 * @Method:    PostOrder
 * @FullName:  NANA::GRAPH::PostOrder
 * @Returns:   void
 * @Qualifier: 基于递归的后续遍历(左->右->根)
 * @Parameter: BinTreeNode<T> *  subTree 传入的节点
 * @Parameter: std::queue<T> & curQueue 顺序队列
 */
template<typename T>
void PostOrder(BinTreeNode<T>* node, std::queue<T>& curQueue)
{
    if (nullptr == node)
        return;
    PostOrder(node->leftChild, curQueue);
    PostOrder(node->rightChild, curQueue);
    curQueue.push(node->data);
    
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

    /**
     * @brief   当前树是否维空
     * @returns   bool
     * @note
     */
    bool empty() {
        if (nullptr == m_root)
            return true;
        return false;
    }
    
    /**
     * @brief  二叉树的最大深度
     * @returns   int
     * @param TreeNode * root
     * @note
     */
    static int maxDepth(BinTreeNode<T>* root) {
        if (nullptr == root)
            return 0;
        int left = maxDepth(root->leftChild) + 1;
        int right = maxDepth(root->rightChild) + 1;
        return std::max(left, right);
    }

protected:
    BinTreeNode<T>* m_root; ///<根节点


};

//! @} Graph_basic


}
}
