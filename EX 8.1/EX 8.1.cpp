#include <iostream>
#include <cmath>
using namespace std;

// Template for comparison
template <typename T>
bool compare(const T& a, const T& b) {
    return a < b;
}

// Specialization for complex numbers
class Complex {
private:
    double real, imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload ~ for module
    double operator~() const {
        return sqrt(real * real + imag * imag);
    }

    // Overload < for module comparison
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
    float f1 = 5.5, f2 = 3.3;

    cout << "Comparing Complex Numbers: ";
    c1.display();
    c2.display();
    if (compare(c1, c2))
        cout << "c1 is smaller than c2 by module." << endl;
    else
        cout << "c1 is not smaller than c2 by module." << endl;

    cout << "Comparing Float Numbers: " << f1 << " and " << f2 << endl;
    if (compare(f1, f2))
        cout << f1 << " is smaller than " << f2 << endl;
    else
        cout << f1 << " is not smaller than " << f2 << endl;

    return 0;
}
