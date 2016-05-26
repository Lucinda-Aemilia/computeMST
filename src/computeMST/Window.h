#pragma once

#include "Graph2D.h"

namespace cmst
{
    enum Menu
    {
        Refresh,
        Quit,
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

            /// Draw the current graph
            void draw();

        private:

            static Window* m_instance;

            Window() : m_curGraph(NULL) {}

            Window(const Window&);

            Graph2D* m_curGraph;

            int menu; ///< The menu of current window
    };

}
