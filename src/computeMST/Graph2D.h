#pragma once

#include <vector>
#include <algorithm>

#include <CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include <CGAL/Triangulation_euclidean_traits_xy_3.h>
#include <CGAL/Delaunay_triangulation_2.h>

#include "Settings.h"
#include "IndexEdge2D.h"
#include "Timer.h"

typedef CGAL::Exact_predicates_inexact_constructions_kernel K;
typedef CGAL::Delaunay_triangulation_2<K> Delaunay;
typedef Delaunay::Vertex_handle Vertex_handle;

namespace cmst
{
    class Graph2D
    {
    public:

        /// Constructor which does everything.
        ///
        /// - Compute naiveEdge which contains all edges
        /// - Compute Delaunay graph
        Graph2D(std::vector<Point2D>& points);

        /// The Kruskal algorithm for finding the minimal spanning tree.
        /// \return The length of the MST.
        double Kruskal(bool naive = false);

        void drawPoint();

        void drawDelaunay();

        // void drawVoronoi();

        void drawMST();

        double mstLength()
        {
            if (!m_mstDone)
                Kruskal();
            return m_mstLength;
        }

        int delaunayTime() const { return m_delaunayTime; }

        int mstTime()
        {
            if (!m_mstDone)
                Kruskal();
            return m_mstTime;
        }

        int graphConstructTime() const { return m_graphConstructTime; }

    protected:

        std::vector<int> father;

        int findFather(int x);

        void initFather();

        std::vector<Point2D> m_points;
        std::vector<IndexEdge2D> m_delaunayEdge;
        std::vector<IndexEdge2D> m_MSTEdge;
        std::vector<CGAL::Object> m_voronoiEdge;
        std::vector<std::vector<int>> m_graph;
        Delaunay m_delaunay;

    private:

        bool m_mstDone;

        double m_mstLength;

        int m_delaunayTime;
        int m_mstTime;
        int m_graphConstructTime;
        int m_kMSTTime;
    };
}
