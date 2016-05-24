#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <array>
#include <ctime>

#include "delaunay-triangulation/delaunay.h"
#include "Graph2D.h"
#include "TestcaseGenerator.h"

void Initialize()
{

}

void CleanUp()
{
    #ifdef DEBUG
    // Write to log
    std::ofstream logout("log.txt");
    logout << debugout.str();
    logout.close();
    #endif // DEBUG
}

std::stringstream debugout;

int main()
{
    Initialize();

	std::vector<Vec2f> points(TestcaseGenerator());

    Graph2D graph(points);
    double mstLength = graph.Kruskal();
    std::cout << "The length of the minimal spanning tree: " << mstLength << std::endl;

    CleanUp();

	return 0;
}
