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
        double Kruskal();

        double Prim();

        void drawPoint();

        void drawDelaunay();

        // void drawVoronoi();

        void drawMST();

        void changeSTDisplay(int direc)
        {
            if (m_ST.size() == 0) return;
            else if (m_displaySTNum == -1)
            {
                m_displaySTNum = 0;
                return;
            }
            if (direc < 0 && m_displaySTNum > 0)
                m_displaySTNum--;
            else if (direc > 0 && m_displaySTNum < m_ST.size()-1)
                m_displaySTNum++;
        }

        void printSTInfo()
        {
            if (m_displaySTNum != -1)
            {
                std::cout << "\nCurrent MST(naive) displaying: " << m_displaySTNum << " th" << std::endl;
                std::cout << "== Number of edges: " << m_ST[m_displaySTNum].m_edges.size() << std::endl;
                std::cout << "== Length: " << m_ST[m_displaySTNum].m_length << std::endl;
                // std::cout << "== Delaunay Triangulation Compute Time: " << m_curGraph->delaunayTime()/1000.0 << std::endl;
                // std::cout << "== Graph construct time: " << m_curGraph->graphConstructTime()/1000.0 << std::endl;
                // std::cout << "== MST Compute Time: " << m_curGraph->mstTime()/1000.0 << std::endl;
            }
        }

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

        int pointNum() const { return m_points.size(); }

        int edgeNum() const { return m_delaunayEdge.size(); }

        bool validateDone() const { return m_validateDone; }


    protected:

        std::vector<int> father;

        int findFather(int x);

        void initFather();

        std::vector<Point2D> m_points;
        std::vector<IndexEdge2D> m_delaunayEdge;

        std::vector<IndexEdge2D> m_MSTEdge;

        std::vector<IndexEdge2D> m_edges;
        std::vector<CGAL::Object> m_voronoiEdge;
        std::vector<std::vector<int>> m_graph;
        Delaunay m_delaunay;

        struct ST
        {
            std::vector<IndexEdge2D> m_edges;
            int m_stTime;
            double m_length;

            ST(std::vector<IndexEdge2D> edges = std::vector<IndexEdge2D>(), int stTime = 0, double length = 0.0) :
                m_edges(edges), m_stTime(stTime), m_length(length) {}
        };
        std::vector<ST> m_ST;

    private:

        bool m_mstDone;
        bool m_validateDone;

        double m_mstLength;

        int m_delaunayTime;
        int m_mstTime;
        int m_graphConstructTime;
        int m_kMSTTime;

        int m_displaySTNum;
    };
}
