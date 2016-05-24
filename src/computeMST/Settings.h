#pragma once

#include <sstream>

#ifdef DEBUG
extern std::stringstream debugout;
#endif // DEBUG

extern const double MAX_X;
extern const double MAX_Y;

class Graph2D;
extern Graph2D* myGraph;
