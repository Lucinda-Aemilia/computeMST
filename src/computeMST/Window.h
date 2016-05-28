#pragma once

#include "Graph2D.h"

namespace cmst
{
    enum Menu
    {
        NEW,
        NEW_4_10,
        NEW_11_100,
        NEW_101_1000,
        NEW_1001_5000,
        SHOW,
        SHOW_VORONOI,
        SHOW_DELAUNAY,
        QUIT,
    };
    class Window
    {
        public:

            static Window* instance()
            {
                if (m_instance == NULL)
                    m_instance = new Window();
                return m_instance;
            }

            Graph2D* curGraph() { return m_curGraph; }

            void resetCurGraph(std::vector<Point2D>& points);

            void resetCurGraph();

            void resetCurGraph(int n);

            void resetCurGraph(int low, int hi);

            void resetShowVoronoi() { m_showVoronoi = !m_showVoronoi; }

            void resetShowDelaunay() { m_showDelaunay = !m_showDelaunay; }

            void resetWidth(int width) { m_width = width; }

            void resetHeight(int height) { m_height = height; }

            int width() const { return m_width; }

            int height() const { return m_height; }

            /// Draw the current graph
            void draw();

            void printCurInfo();

        private:

            /// Constructor
            Window() : m_curGraph(NULL), m_showVoronoi(false), m_showDelaunay(true) {}

            static Window* m_instance;

            Window(const Window&);

            Graph2D* m_curGraph;

            bool m_showVoronoi;
            bool m_showDelaunay;

            int m_width, m_height;
    };

}
