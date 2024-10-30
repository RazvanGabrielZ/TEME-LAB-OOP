#include <iostream>
#include <stdexcept>
#include "operate.h"

using namespace std;

int main() {
    int x, y;
    double a, b;

    // Input integers 
    cout << "Enter two integers:\n";
    cout << "Integer 1: ";
    cin >> x;
    cout << "Integer 2: ";
    cin >> y;

    // Input doubles 
    cout << "Enter two doubles:\n";
    cout << "Double 1: ";
    cin >> a;
    cout << "Double 2: ";
    cin >> b;

    // Testing integer operations
    cout << "\nInteger Operations:" << endl;
    cout << "Add: " << operate(x, y, add) << endl;
    cout << "Subtract: " << operate(x, y, subtract) << endl;
    cout << "Multiply: " << operate(x, y, multiply) << endl;
    cout << "Divide: " << operate(x, y, divide) << endl;

    // Testing double operations
    cout << "\nDouble Operations:" << endl;
    cout << "Add: " << operate(a, b, add) << endl;
    cout << "Subtract: " << operate(a, b, subtract) << endl;
    cout << "Multiply: " << operate(a, b, multiply) << endl;
    cout << "Divide: " << operate(a, b, divide) << endl;

    return 0;
}