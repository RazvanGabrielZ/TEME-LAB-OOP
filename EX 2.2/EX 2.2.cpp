#include <iostream>
#include <cmath> // For sqrt function
#include "realcomplexabsolute.h"
using namespace std;


int main() {
    float realValue;
    nrComplex complexValue;

    // REAL NUMBER
    cout << "Enter a real number: ";
    cin >> realValue;

    // Calculate and display the absolute value of the real number
    cout << "Absolute value of real number " << realValue << " is: " << absolute(realValue) << endl;


    // COMPLEX NUMBER
    cout << "Enter the real part of the complex number: ";
    cin >> complexValue.a;
    cout << "Enter the imaginary part of the complex number: ";
    cin >> complexValue.b;

    // Calculate and display the absolute value of the complex number
    cout << "Absolute value of complex number " << complexValue.a
        << " + " << complexValue.b << "i is: "
        << absolute(complexValue) << endl;

    return 0;
}
