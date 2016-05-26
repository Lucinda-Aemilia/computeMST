#include <GL/glut.h>

#include "Window.h"
#include "TestcaseGenerator.h"

cmst::Window* cmst::Window::m_instance = NULL;

void cmst::Window::draw()
{
    m_curGraph->drawVoronoi();
    m_curGraph->drawDelaunay();
    m_curGraph->drawMST();
    m_curGraph->drawPoint();
}

void cmst::Window::resetCurGraph(std::vector<Point2D>& points)
{
    if (m_curGraph != NULL)
        delete m_curGraph;
    m_curGraph = NULL;
    m_curGraph = new Graph2D(points);

    double mstLength = m_curGraph->Kruskal();
    std::cout << "The length of the minimal spanning tree: " << mstLength << std::endl;
}

void cmst::Window::resetCurGraph()
{
    std::vector<cmst::Point2D> points(cmst::TestcaseGenerator());
    resetCurGraph(points);
}
