#include <cstring>

#include <GL/glut.h>

#include "Window.h"
#include "TestcaseGenerator.h"

cmst::Window* cmst::Window::m_instance = NULL;

void cmst::Window::draw()
{
    /*
    if (m_showVoronoi)
        m_curGraph->drawVoronoi();
    */
    if (m_showDelaunay)
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
}

void cmst::Window::resetCurGraph()
{
    std::vector<cmst::Point2D> points(cmst::TestcaseGenerator());
    resetCurGraph(points);
}

void cmst::Window::resetCurGraph(int n)
{
    std::vector<cmst::Point2D> points(cmst::TestcaseGenerator(n, n));
    resetCurGraph(points);
}

void cmst::Window::resetCurGraph(int low, int hi)
{
    std::vector<cmst::Point2D> points(cmst::TestcaseGenerator(low, hi));
    resetCurGraph(points);
}

void cmst::Window::printCurInfo()
{
    std::cout << "Current tree displaying: " << std::endl;
    std::cout << "Length: " << m_curGraph->mstLength() << std::endl;
    std::cout << "Delaunay Triangulation Compute Time: " << m_curGraph->delaunayTime()/1000.0 << std::endl;
    std::cout << "Graph construct time: " << m_curGraph->graphConstructTime()/1000.0 << std::endl;
    std::cout << "MST Compute Time: " << m_curGraph->mstTime()/1000.0 << std::endl;
}
