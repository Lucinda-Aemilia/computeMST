#pragma once

#include <vector>
#include <ctime>
#include <cmath>

#include "Graph2D.h"
#include "Settings.h"

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

///
///
/// To-do: output the testcase file to ../testcase
std::vector<Vec2f> TestcaseGenerator(int num_lower_bound = 100, int num_upper_bound = 500,
                              double x_upper_bound = MAX_X, double y_upper_bound = MAX_Y)
{
    srand(time(NULL));
	int numberPoints = randomInt(num_lower_bound, num_upper_bound);

	#ifdef DEBUG
	debugout << "Generating " << numberPoints << " random points" << std::endl;
	#endif // DEBUG

	std::vector<Vec2f> points;
	for(int i = 0; i < numberPoints; i++) {
		points.push_back(Vec2f(randomDouble(0.0, x_upper_bound), randomDouble(0.0, y_upper_bound)));
	}

	return points;
}
