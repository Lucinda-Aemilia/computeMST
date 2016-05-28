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
    {
        if (!m_test.m_displayTest)
            delete m_curGraph;
        else
        {
            m_test.m_testGraphs.clear();
            m_test.m_displayTest = false;
        }
    }
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
    std::cout << "\nCurrent tree displaying: " << std::endl;
    std::cout << "== Number of points: " << m_curGraph->pointNum() << std::endl;
    std::cout << "== Number of edges in the Delaunay Diagram: " << m_curGraph->edgeNum() << std::endl;
    std::cout << "== Length: " << m_curGraph->mstLength() << std::endl;
    std::cout << "== Delaunay Triangulation Compute Time: " << m_curGraph->delaunayTime()/1000.0 << std::endl;
    std::cout << "== Graph construct time: " << m_curGraph->graphConstructTime()/1000.0 << std::endl;
    std::cout << "== MST Compute Time: " << m_curGraph->mstTime()/1000.0 << std::endl;
}

void cmst::Window::printTestInfo()
{
    if (m_test.m_displayTest)
    {
        std::cout << "\nCurrent test displaying: " << std::endl;
        std::cout << "== Number of tests: " << m_test.m_testGraphs.size() << std::endl;
    }
}

void cmst::Window::generateTest(int n)
{
    if (!m_test.m_displayTest)
    {
        m_test.m_displayTest = true;
        delete m_curGraph;
        m_curGraph = NULL;
    }
    else
    {
        m_curGraph = NULL;
        m_test.m_testGraphs.clear();
    }

    n = std::max(n, 1);
    m_test.m_displayTestNum = 0;
    std::vector<cmst::Point2D> points;
    for (int i = 0; i < n; i++)
    {
        points = cmst::TestcaseGenerator(10000, 10000);
        m_test.m_testGraphs.push_back(cmst::Graph2D(points));
    }
    m_curGraph = &m_test.m_testGraphs[0];
}
