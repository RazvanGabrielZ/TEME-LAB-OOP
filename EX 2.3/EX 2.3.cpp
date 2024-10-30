#include <iostream>
#include <stdexcept>
#include "Function.h"

using namespace std;

int main() {
    double a, b;

    cout << "Enter coefficients a and b: ";
    cin >> a >> b;

    try {
        double solution = solveEquation(a, b);
        cout << "The solution is: x = " << solution << endl;
    }
    catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}