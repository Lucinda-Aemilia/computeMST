#pragma once

#include <cmath>
#include <iostream>

namespace cmst
{
    class Point2D
    {
    public:
        Point2D(double x = 0.0, double y = 0.0) : m_x(x), m_y(y) {}
        Point2D(const Point2D& other) : m_x(other.x()), m_y(other.y()) {}

        double x() const { return m_x; }
        double y() const { return m_y; }

        bool operator < (const Point2D& right)
        {
            if (m_x != right.m_x) return m_x < right.m_x;
            return m_y < right.m_y;
        }

        bool operator == (const Point2D& right)
        {
            return abs(m_x - right.m_x) <= EPS_MIN && abs(m_y - right.m_y) <= EPS_MIN;
        }

        friend std::ostream& operator << (std::ostream& out, const Point2D& p)
        {
            return out << "Point (" << p.m_x << ", " << p.m_y << ")";
        }

    private:
        double m_x;
        double m_y;
    };
}
