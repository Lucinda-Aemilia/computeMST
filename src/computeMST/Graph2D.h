#pragma once

#include <vector>
#include <algorithm>

#include "delaunay-triangulation/delaunay.h"
#include "delaunay-triangulation/vector2.h"
#include "Settings.h"
#include "IndexEdge.h"

class Graph2D
{
public:

    /// Constructor which does everything.
    ///
    /// - Compute naiveEdge which contains all edges
    /// - Compute Delaunay graph
    Graph2D(std::vector<Vec2f>& points);

    /// The Kruskal algorithm for finding the minimal spanning tree.
    /// \return The length of the MST.
    double Kruskal();

protected:

    std::vector<int> father;

    int findFather(int x);

private:

    std::vector<Vec2f> m_points;
    // std::vector<Edge> m_naiveEdges;
    // std::vector<Edge> m_delaunayEdges;
    std::vector<IndexEdge> m_delaunayEdges;

    Delaunay m_triangulation;
	std::vector<Triangle> m_triangles;
};

