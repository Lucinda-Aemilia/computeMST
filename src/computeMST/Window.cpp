#include "Window.h"

cmst::Window* cmst::Window::m_instance = NULL;

void cmst::Window::draw()
{
    m_curGraph->drawVoronoi();
    m_curGraph->drawDelaunay();
    m_curGraph->drawPoint();
}

void cmst::Window::resetCurGraph(std::vector<Point2D> points)
{
    if (m_curGraph != NULL)
        delete m_curGraph;
    m_curGraph = new Graph2D(points);
}
