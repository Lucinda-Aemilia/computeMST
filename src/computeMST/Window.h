#pragma once

#include "Graph2D.h"

namespace cmst
{
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

            void resetCurGraph(std::vector<Point2D> points);

            void draw();

        private:

            static Window* m_instance;

            Window() : m_curGraph(NULL) {}

            Window(const Window&);

            Graph2D* m_curGraph;
    };

}
