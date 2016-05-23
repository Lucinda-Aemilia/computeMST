#pragma once

#include <vector>
#include <algorithm>

#include "delaunay-triangulation/delaunay.h"
#include "delaunay-triangulation/vector2.h"

class Graph2D
{
public:

    /// Constructor which does everything.
    ///
    /// - Compute naiveEdge which contains all edges
    /// - Compute Delaunay graph
    Graph2D(std::vector<Vec2f>& points);

private:
    std::vector<Vec2f> m_points;
    std::vector<Edge> m_naiveEdges;
    std::vector<Edge> m_delaunayEdges;

    Delaunay m_triangulation;
	std::vector<Triangle> m_triangles;
};

