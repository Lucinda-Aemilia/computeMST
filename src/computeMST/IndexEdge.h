#pragma once

#include "delaunay-triangulation/edge.h"
#include "Settings.h"

class IndexEdge : public Edge
{
public:

    IndexEdge(Vec2f p1, Vec2f p2, int index1, int index2) : Edge(p1, p2)
    {
        if (index1 > index2)
        {
            std::swap(index1, index2);
            std::swap(this->p1, this->p2);
        }
        m_index[0] = index1;
        m_index[1] = index2;
        m_length = std::sqrt(p1.dist2(p2));
    }

    double length() const { return m_length; }

    int startIndex() const { return m_index[0]; }

    int endIndex() const { return m_index[1]; }

    Vec2f start() const { return p1; }

    Vec2f end() const { return p2; }

    bool operator < (const IndexEdge& right) const { return m_length < right.m_length; }

    friend std::ostream &operator << (std::ostream &str, const IndexEdge& e)
    {
        str << "Edge " << e.m_index[0] << ", " << e.m_index[1] << std::endl;
        str << "     length: " << e.m_length << std::endl;
        str << "     " << e.p1 << ", " << e.p2;
        return str;
    }

private:

    int m_index[2];
    double m_length;
};
