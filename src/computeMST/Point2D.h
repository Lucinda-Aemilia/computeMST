#pragma once

#include <cmath>

#include "Delaunay.h"

namespace euclidean_graph
{
    class Point2D
    {
    public:
        Point2D(double x, double y);

        double getX() const;
        double getY() const;

        Point2D operator + (const Point2D& right)
        {
            return euclidean_graph::Point2D(m_x + right.m_x, m_y + right.m_y);
        }
        Point2D operator - (const Point2D& right)
        {
            return euclidean_graph::Point2D(m_x - right.m_x, m_y - right.m_y);
        }

        double length()
        {
            return sqrt(m_x*m_x + m_y*m_y);
        }

        /// Return the length squared.
        ///
        /// Use this for performance.
        double lengthSquared()
        {
            return m_x*m_x + m_y*m_y;
        }

        /// The type conversion function to ayron_delaunay::Point
        ///
        /// The point of doing this is, the library does not follow the OOP design principals.
        /// I just wrapped it up in a namespace and will replace or rewrite it some day.
        operator ayron_delaunay::Point()
        {
            return ayron_delaunay::Point(m_x, m_y);
        }

    private:
        double m_x;
        double m_y;
    };
}
