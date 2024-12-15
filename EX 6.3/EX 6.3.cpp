#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overloading ~ operator for absolute value (module)
    double operator~() const {
        return sqrt(real * real + imag * imag);
    }

    // Overloading < operator for comparison by module
    bool operator<(const Complex& other) const {
        return ~(*this) < ~other;
    }

    // Display method
    void display() const {
        cout << real << (imag >= 0 ? "+" : "") << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(1, -2);

    cout << "ComplexNumber1: ";
    c1.display();
    cout << "ComplexNumber2: ";
    c2.display();

    if (c1 < c2) {
        cout << "ComplexNumber1 is smaller than ComplexNumber2 based on module." << endl;
    }
    else {
        cout << "ComplexNumber1 is not smaller than ComplexNumber2 based on module." << endl;
    }

    return 0;
}
