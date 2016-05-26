#pragma once

#include <cmath>
#include <iostream>

#include "Point2D.h"

namespace cmst
{
    class Edge2D
    {
    public:
        Edge2D(const Point2D& start, const Point2D& end) : m_start(start), m_end(end)
        {
            m_length = (m_start.x() - m_end.x()) * (m_start.x() - m_end.x())
                +  (m_start.y() - m_end.y()) * (m_start.y() - m_end.y());
            m_length = sqrt(m_length);
        }

        double length() const { return m_length; }

        Point2D start() const { return m_start; }

        Point2D end() const { return m_end; }

        bool operator < (const Edge2D& right)
        {
            return m_length < right.m_length;
        }

        bool operator == (const Edge2D& right)
        {
            return (m_start==right.m_start && m_end==right.m_end) || (m_start==right.m_end && m_end==right.m_start);
        }

        friend std::ostream& operator << (std::ostream& out, const Edge2D& e)
        {
            return out << "Edge " << std::endl << e.m_length << std::endl << e.m_start << ' ' << e.m_end;
        }

    protected:
        void swap_points() { std::swap(m_start, m_end); }

    private:
        Point2D m_start;
        Point2D m_end;
        double m_length;
    };
}
