#include "Graph2D.h"

Graph2D::Graph2D(std::vector<Vec2f>& points) : m_points(points)
{
    int n = m_points.size();

    // compute Delaunay Edges
    m_triangles = m_triangulation.triangulate(m_points);
    std::vector<Edge> delaunayEdges( m_triangulation.getEdges() );

    #ifdef DEBUG

    debugout << "========================================================================\n";

    debugout << "Delaunay Triangulation algorithm running\n";

    debugout << m_triangles.size() << " triangles generated\n";

	debugout << "========================================================================\n";

	debugout << "\nPoints : " << m_points.size() << std::endl;
	for(auto &p : m_points)
		debugout << p << std::endl;

	debugout << "\nTriangles : " << m_triangles.size() << std::endl;
	for(auto &t : m_triangles)
		debugout << t << std::endl;

	debugout << "\nEdges : " << m_delaunayEdges.size() << std::endl;
	for(auto &e : m_delaunayEdges)
		debugout << e << std::endl;

    debugout << "========================================================================\n";
    #endif // DEBUG

    // reconstruct the Delaunay graph
    std::sort(m_points.begin(), m_points.end());
    for (int i = delaunayEdges.size() - 1; i >= 0; i--)
    {
        int index1 = std::lower_bound(m_points.begin(), m_points.end(), delaunayEdges[i].p1) - m_points.begin();
        int index2 = std::lower_bound(m_points.begin(), m_points.end(), delaunayEdges[i].p2) - m_points.begin();
        m_delaunayEdges.push_back(IndexEdge(delaunayEdges[i].p1, delaunayEdges[i].p2, index1, index2));
    }

    std::sort(m_delaunayEdges.begin(), m_delaunayEdges.end());
    m_delaunayEdges.erase(unique(m_delaunayEdges.begin(), m_delaunayEdges.end()), m_delaunayEdges.end());

    #ifdef DEBUG
    debugout << "\nReconstructed graph\n";
    for (int i = 0; i < n; i++)
        debugout << m_points[i] << std::endl;
    debugout << "========================================================================\n";
    for (int i = 0; i < m_delaunayEdges.size(); i++)
        debugout << m_delaunayEdges[i] << std::endl;
    debugout << "========================================================================\n";
    #endif // DEBUG

}

double Graph2D::Kruskal(bool naive /*= false*/)
{
    father.clear();
    int n = m_points.size();
    for (int i = 0; i < n; i++) father.push_back(i);

    double mstLength = 0.0;
    m_kruskalMSTEdges.clear();

    for (int i = 0; i < m_delaunayEdges.size(); i++)
    {
        int start = m_delaunayEdges[i].startIndex();
        int end = m_delaunayEdges[i].endIndex();

        // std::cout << start << ' ' << end << ' ' << m_delaunayEdges[i].length() << std::endl;

        start = findFather(start);
        end = findFather(end);
        if (start != end)
        {
            father[start] = end;
            mstLength += m_delaunayEdges[i].length();
            m_kruskalMSTEdges.push_back(m_delaunayEdges[i]);
        }
    }

    return mstLength;
}

int Graph2D::findFather(int x)
{
    if (father[x] == x) return x;
    return father[x] = findFather(father[x]);
}
