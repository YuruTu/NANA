#pragma once
/**
 * @file list.hpp
 * @date 2021/11/30 6:03
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief 实现双向链表类
 *
 * TODO:
 *
 * @note
*/

namespace NANA {
namespace GRAPH {

//! @addtogroup Graph_basic
//! @{


template <typename T>
struct ListNode
{
    ListNode* m_next;
    ListNode* m_prev;
    T m_data;

    ListNode(T x)
        :m_next(nullptr)
        , m_prev(nullptr)
        , m_data(x)
    {}
};

/**
 * @brief 双向循环链表
 * @tparam T
*/
template <typename T>
class CicList {
    typedef ListNode<T> Node;
public:
    CicList()
        :_head(new Node(T()))
    {
        _head->_next = _head;
        _head->_prev = _head;
    }


    virtual	~CicList()
    {
        Node* tmp = _head->_next;
        while (tmp != _head)
        {
            Node* cur = tmp->_next;
            delete tmp;
            tmp = cur;
        }
    }

    void setHead(T x) {
        _head->_data = x;
    }

    void push_front(const T& x) {
        Insert(_head->_next, x);
    }

    void push_back(const T& x) {
        Insert(_head->_prev, x);
    }


private:
    //插入一个元素
    void Insert(Node* pos, T x)
    {
        Node* newnode = new Node(x);
        newnode->m_next = pos;
        pos->m_prev->m_next = newnode;
        newnode->m_prev = pos->m_prev;
        pos->m_prev = newnode;
    }
    //data
    Node* m_head;
};

/**
 * @brief 普通链表，不同于循环链表
 * @tparam T 
*/
template <typename T>
class CList {
    typedef ListNode<T> Node;
public:


protected:
};




//! @} Graph_basic

}
}