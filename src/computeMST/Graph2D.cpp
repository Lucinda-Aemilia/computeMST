#include "Graph2D.h"

Graph2D::Graph2D(std::vector<Vec2f>& points) : m_points(points)
{
    int n = m_points.size();
    m_triangles = m_triangulation.triangulate(m_points);
    m_delaunayEdges = m_triangulation.getEdges();

    std::cout << m_triangles.size() << " triangles generated\n";

	std::cout << " ========= ";

	std::cout << "\nPoints : " << m_points.size() << std::endl;
	for(auto &p : m_points)
		std::cout << p << std::endl;

	std::cout << "\nTriangles : " << m_triangles.size() << std::endl;
	for(auto &t : m_triangles)
		std::cout << t << std::endl;

	std::cout << "\nEdges : " << m_delaunayEdges.size() << std::endl;
	for(auto &e : m_delaunayEdges)
		std::cout << e << std::endl;
}
