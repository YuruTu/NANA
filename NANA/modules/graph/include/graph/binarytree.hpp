#pragma once
/**
 * @file binarytree.hpp
 * @date 2021/11/11 22:41
 *
 * @author Administrator
 * Contact: 707101557@qq.com
 *
 * @brief 实现二叉树，二叉搜索树
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

    
    /**
     * @Method:    isEmpty
     * @FullName:  NANA::GRAPH::CBinaryTree<_T>::isEmpty
     * @breif:     判断当前二叉树是否为空
     * @returns:   bool
     */
    bool isEmpty() const {
        return nullptr == m_root ? false, true;
    }
protected:

    /**
     * @Method:    release
     * @FullName:  NANA::GRAPH::CBinaryTree<_T>::release
     * @breif:     释放内存
     * @returns:   void
     */
    void destroy(BinTreeNode<T>* node) {
        if (nullptr != node) {
            destroy(node->leftChild);
            destroy(node->rightChild);
            delete node;
        }
    }
    

    BinTreeNode<T>* m_root; ///<根节点

};

/**
 * @class  BSTNode
 * @brief  二叉搜索树(binary searcgh treee)又称二叉排序树(binary sorting tree)的节点
 * @tparam K 键的类型
 * @tparam T 值的类型
*/
template<typename K, typename T>
struct BSTNode {

    
    /**
     * @Method:    operator<
     * @FullName:  NANA::GRAPH::BSTNode<K, T>::operator<
     * @breif:     比较Node的大小，以值排序
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
 * @brief  二叉搜索树(binary searcgh treee)又称二叉排序树(binary sorting tree)
 * @tparam K 键的类型
 * @tparam T 值的类型
*/
template<typename K, typename T>
class CBST {
public:


private:



};




//! @} Graph_basic


}
}
