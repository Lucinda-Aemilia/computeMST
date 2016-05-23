#include "Point2D.h"

euclidean_graph::Point2D::Point2D(double x = 0, double y = 0) : m_x(x), m_y(y) { }

double euclidean_graph::Point2D::getX() const { return m_x; }

double euclidean_graph::Point2D::getY() const { return m_y; }
