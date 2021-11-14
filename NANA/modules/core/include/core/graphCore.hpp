#pragma  once
/**
 * @file graphCore.hpp
 * @date 2021/11/14 11:21
 *
 * @author yurutu
 * Contact: 707101557@qq.com
 *
 * @brief Ϊͼ���㷨ʵ�ֵĻ������ݽṹ
 *
 * TODO: long description
 *
 * \note
*/

#include "core_global.h"

namespace NANA {
namespace GRAPH {

//! @addtogroup core_basic
//! @{

/*!
 * @brief ����
 */
template <typename T>
class Edge {

public:
    std::string vertex;
    T weight;
    Edge() {

    }
    Edge(std::string neighbour_vertex) {
        this->vertex = neighbour_vertex;
        this->weight = 0;
    }

    Edge(std::string neighbour_vertex, T weight) {
        this->vertex = neighbour_vertex;
        this->weight = weight;
    }

    bool operator<(const Edge& obj) const {
        return obj.vertex > vertex;
    }

    bool operator==(const Edge& obj) const {
        return obj.vertex == vertex;
    }
};

//! @} core_basic
}
}

