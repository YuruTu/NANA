#pragma once
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


/**
 * @brief  ���ڵݹ�Ķ������������(��->��->��)
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
 * @Qualifier: ���ڵݹ���������(��->��->��)
 * @Parameter: BinTreeNode<T> * node �ڵ�
 * @Parameter: std::queue<T> & curQueue ����Ķ���
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
 * @Qualifier: ���ڵݹ�ĺ�������(��->��->��)
 * @Parameter: BinTreeNode<T> *  subTree ����Ľڵ�
 * @Parameter: std::queue<T> & curQueue ˳�����
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
 * @brief ����������
 * @tparam _T 
*/
template<typename _T>
class CBinaryTree {

public:
    CBinaryTree() :
        m_root(nullptr) {

    }

    /**
     * @brief   ��ǰ���Ƿ�ά��
     * @returns   bool
     * @note
     */
    bool empty() {
        if (nullptr == m_root)
            return true;
        return false;
    }
    
    /**
     * @brief  ��������������
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
    BinTreeNode<T>* m_root; ///<���ڵ�


};

//! @} Graph_basic


}
}
