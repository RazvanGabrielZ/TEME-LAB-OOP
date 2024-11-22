#pragma once
#include <iostream>
#include <cmath>
using namespace std;

class QuadraticEquation {
private:
    double a, b, c;  

public:
    // Constructor to initialize the coefficients
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    void solve() {
        // Calculate the discriminant
        double discriminant = b * b - 4 * a * c;

        // Check the discriminant to determine the nature of the roots
        if (discriminant > 0) {
            double root1 = (-b + sqrt(discriminant)) / (2 * a);
            double root2 = (-b - sqrt(discriminant)) / (2 * a);
            cout << "The roots are real and different.\n";                                     // Two real roots
            cout << "Root 1 = " << root1 << endl;
            cout << "Root 2 = " << root2 << endl;
        }
        else if (discriminant == 0) {
            double root = -b / (2 * a);
            cout << "The root is real and the same.\n";                                        // One real root (repeated root)
            cout << "Root = " << root << endl;
        }
        else {
            double realPart = -b / (2 * a);
            double imaginaryPart = sqrt(-discriminant) / (2 * a);                              // No real roots, complex roots
            cout << "The roots are complex and different.\n";
            cout << "Root 1 = " << realPart << " + " << imaginaryPart << "i" << endl;
            cout << "Root 2 = " << realPart << " - " << imaginaryPart << "i" << endl;
        }
    }

    // Accessor methods for the coefficients (if needed)
    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }
};
