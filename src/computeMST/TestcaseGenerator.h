#pragma once

#include <vector>
#include <ctime>
#include <cmath>
#include <random>

#include "Graph2D.h"
#include "Settings.h"

namespace cmst
{

    /// Generate an integer in the range [a, b]
    ///
    /// Needs to be improved using other random classes
    int randomInt(int a, int b);

    /// Generate a floating-point number in the range [a, b]
    ///
    /// Needs to be improved using other random classes
    double randomDouble(double a, double b);

    ///
    ///
    /// To-do: output the testcase file to ../testcase; Add erase and unique
    std::vector<Point2D> TestcaseGenerator(int num_lower_bound = 100, int num_upper_bound = 500,
                                  double x_upper_bound = MAX_X, double y_upper_bound = MAX_Y);
}
