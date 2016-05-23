#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <array>
#include <ctime>

#include "delaunay-triangulation/delaunay.h"

#include "Graph2D.h"

typedef Vector2<float> Vec2f;

float RandomFloat(float a, float b) {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = b - a;
    float r = random * diff;
    return a + r;
}

int main()
{
	srand (time(NULL));
	float numberPoints = roundf(RandomFloat(4, 40));

	std::cout << "Generating " << numberPoints << " random points" << std::endl;

	std::vector<Vec2f> points;
	for(int i = 0; i < numberPoints; i++) {
		points.push_back(Vec2f(RandomFloat(0, 800), RandomFloat(0, 600)));
	}

	/*
	Delaunay triangulation;
	std::vector<Triangle> triangles = triangulation.triangulate(points);
	std::cout << triangles.size() << " triangles generated\n";
	std::vector<Edge> edges = triangulation.getEdges();

	std::cout << " ========= ";

	std::cout << "\nPoints : " << points.size() << std::endl;
	for(auto &p : points)
		std::cout << p << std::endl;

	std::cout << "\nTriangles : " << triangles.size() << std::endl;
	for(auto &t : triangles)
		std::cout << t << std::endl;

	std::cout << "\nEdges : " << edges.size() << std::endl;
	for(auto &e : edges)
		std::cout << e << std::endl;
    */

    Graph2D graph(points);
	return 0;
}
