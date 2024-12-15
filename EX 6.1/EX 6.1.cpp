#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overloading ~ operator for absolute value
    double operator~() const {
        return sqrt(real * real + imag * imag);
    }

    // Overloading ^ operator for power (default exponent = 2)
    Complex operator^(int power) const {
        Complex result(1, 0); // Initialize with 1
        Complex base = *this;
        for (int i = 0; i < power; i++) {
            double tempReal = result.real * base.real - result.imag * base.imag;
            double tempImag = result.real * base.imag + result.imag * base.real;
            result.real = tempReal;
            result.imag = tempImag;
        }
        return result;
    }

    // Overloading + operator for addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Display method
    void display() const {
        cout << real << (imag >= 0 ? "+" : "") << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(1, -2);

    cout << "Absolute value of c1: " << ~c1 << endl;

    Complex powerResult = c1 ^ 2;
    cout << "c1 raised to power 2: ";
    powerResult.display();

    Complex sum = c1 + c2;
    cout << "Sum of c1 and c2: ";
    sum.display();

    return 0;
}
