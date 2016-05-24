#pragma once

#include <vector>
#include <ctime>
#include <cmath>

#include "Graph2D.h"

/// Generate an integer in the range [a, b]
///
/// Needs to be improved using other random classes
int randomInt(int a, int b)
{
    if (a > b) std::swap(a, b);
    int random = rand();
    random = a + random % (b - a + 1);
    return random;
}

/// Generate a floating-point number in the range [a, b]
///
/// Needs to be improved using other random classes
double randomDouble(double a, double b)
{
    if (a > b) std::swap(a, b);
    double random = ((double) rand()) / (double) RAND_MAX;
    double diff = b - a;
    double r = random * diff;
    return a + r;
}

std::vector<Vec2f> TestcaseGenerator(int num_lower_bound = 4, int num_upper_bound = 40,
                              double x_upper_bound = 800.0, double y_upper_bound = 600.0)
{
    srand(time(NULL));
	int numberPoints = randomInt(4, 40);

	#ifdef DEBUG
	debugout << "Generating " << numberPoints << " random points" << std::endl;
	#endif // DEBUG

	std::vector<Vec2f> points;
	for(int i = 0; i < numberPoints; i++) {
		points.push_back(Vec2f(randomDouble(0, 800), randomDouble(0, 600)));
	}

	return points;
}
