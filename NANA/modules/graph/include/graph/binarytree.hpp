#pragma once
/**
 * @file binarytree.hpp
 * @date 2021/11/11 22:41
 *
 * @author Administrator
 * Contact: 707101557@qq.com
 *
 * @brief ʵ�ֶ�����������������
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
    if (nullptr == node) {
        return;
    }

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
template<typename T>
class CBinaryTree {

public:
    CBinaryTree() :
        m_root(nullptr) {

    }

    ~CBinaryTree()
    {
        destroy(m_root);
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

    
    /**
     * @Method:    isEmpty
     * @FullName:  NANA::GRAPH::CBinaryTree<_T>::isEmpty
     * @breif:     �жϵ�ǰ�������Ƿ�Ϊ��
     * @returns:   bool
     */
    bool isEmpty() const {
        return nullptr == m_root ? false, true;
    }
protected:

    /**
     * @Method:    release
     * @FullName:  NANA::GRAPH::CBinaryTree<_T>::release
     * @breif:     �ͷ��ڴ�
     * @returns:   void
     */
    void destroy(BinTreeNode<T>* node) {
        if (nullptr != node) {
            destroy(node->leftChild);
            destroy(node->rightChild);
            delete node;
        }
    }
    

    BinTreeNode<T>* m_root; ///<���ڵ�

};

/**
 * @class  BSTNode
 * @brief  ����������(binary searcgh treee)�ֳƶ���������(binary sorting tree)�Ľڵ�
 * @tparam K ��������
 * @tparam T ֵ������
*/
template<typename K, typename T>
struct BSTNode {

    
    /**
     * @Method:    operator<
     * @FullName:  NANA::GRAPH::BSTNode<K, T>::operator<
     * @breif:     �Ƚ�Node�Ĵ�С����ֵ����
     * @returns:   bool
     * @Parameter: BSTNode<K
     * @Parameter: T> const & node
     */
    bool operator<(BSTNode<K,T> const & node ) const{
        return this->key < node.key ? true ? false;
    }

    bool operator>(BSTNode<K, T> const& node) const {
        return this->key > node.key ? true ? false;
    }

    bool operator==(BSTNode<K, T> const& node) const {
        return this->key > node.key ? true ? false;
    }

    BSTNode<K, T>* left;
    BSTNode<K, T>* right;
    K key;
    T data;
};


/**
 * @class  CBST
 * @brief  ����������(binary searcgh treee)�ֳƶ���������(binary sorting tree)
 * @tparam K ��������
 * @tparam T ֵ������
*/
template<typename K, typename T>
class CBST {
public:


private:



};




//! @} Graph_basic


}
}
