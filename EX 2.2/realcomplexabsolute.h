#pragma once
#include <cmath> 
using namespace std;

struct nrComplex {
    float a; // Real part
    float b; // Imaginary part
};

// Function to compute the absolute value of a real number
float absolute(float x) {
    return fabs(x);
}

// Function to compute the absolute value of a complex number
float absolute(const nrComplex& complex) {
    return sqrt(complex.a * complex.a + complex.b * complex.b);
}

