#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

// Function prototype for the integer operation
int operate(int a, int b, int (*func)(int, int));

// Function prototype for the double operation
double operate(double a, double b, double (*func)(double, double));

// Sample functions for addition, subtraction, multiplication, and division
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero!");
    }
    return a / b;
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw runtime_error("Division by zero!");
    }
    return a / b;
}

// Function to perform an operation on two integers
int operate(int a, int b, int (*func)(int, int)) {
    try {
        return func(a, b);
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
        return 0; // or some other error value
    }
}

// Function to perform an operation on two doubles
double operate(double a, double b, double (*func)(double, double)) {
    try {
        return func(a, b);
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
        return 0.0; // or some other error value
    }
}