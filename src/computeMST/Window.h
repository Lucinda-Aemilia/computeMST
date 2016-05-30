#pragma once

#include "Graph2D.h"
#include "Stat.h"

namespace cmst
{
    enum Menu
    {
        NEW,
        NEW_4_10,
        NEW_11_100,
        NEW_101_1000,
        NEW_1001_5000,
        NEW_5001_10000,
        SHOW,
        SHOW_VORONOI,
        SHOW_DELAUNAY,
        TEST,
        TEST_5,
        TEST_20,
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

            /// Print information about the current displayed graph
            void printCurInfo();

            bool displayTest() const { return m_test.m_displayTest; }

            /// Generate \param n tests and display the first one
            void generateTest(int n);

            /// Print information about the test displayed
            void printTestInfo();

            int testDisplayNum() const { return m_test.m_displayTestNum; }

            void changeTestDisplay(int direc)
            {
                if (direc < 0 && m_test.m_displayTestNum > 0)
                {
                    m_test.m_displayTestNum--;
                    m_curGraph = &m_test.m_testGraphs[m_test.m_displayTestNum];
                }
                else if (direc > 0 && m_test.m_displayTestNum < m_test.m_testGraphs.size()-1)
                {
                    m_test.m_displayTestNum++;
                    m_curGraph = &m_test.m_testGraphs[m_test.m_displayTestNum];
                }
            }

        protected:
            struct Test
            {
                bool m_displayTest;
                int m_displayTestNum;
                std::vector<Graph2D> m_testGraphs;

                Stat m_delaunayTimeStat;
                Stat m_graphConstructTimeStat;
                Stat m_mstTimeStat;

                Test() : m_displayTest(false), m_displayTestNum(0) {}
            } m_test;

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
