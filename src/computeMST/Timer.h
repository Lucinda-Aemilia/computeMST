#include <ctime>

namespace cmst
{
    class Timer
    {
    public:
        Timer() { m_begin = std::clock(); }
        int time() { return std::clock() - m_begin; }
        void reset() { m_begin = std::clock(); }
    private:
        int m_begin;
    };
}
