#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

double solveEquation(double a, double b) {

    if (a == 0 && b == 0) {
        throw runtime_error ("Infinite solutions: Both coefficients are zero.");
    }
    if (a == 0) {
        throw invalid_argument ("No solution: a is zero, b is non-zero.");
    }

    return -b / a;  // Solve:  ax + b = 0  -->  x = - b/a
}
