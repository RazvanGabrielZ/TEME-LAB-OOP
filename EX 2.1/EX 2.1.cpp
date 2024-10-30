#include <iostream>
#include <string>
#include <stdexcept>
#include "AreaCalc.h"

using namespace std;

int main() {

    string length, width;

    // Example 1: Square

    cout << "Enter the side length of the square: ";
    cin >> length;
    double SquareArea = ExceptionHandler(length);
    if (SquareArea != -1) {
        cout << "Area of square: " << SquareArea << endl;
    }

    // Example 2: Rectangle

    cout << "\nEnter the length and width of the rectangle: ";
    cin >> length >> width;
    double RectangleArea = ExceptionHandler(length, width);
    if (RectangleArea != -1) {
        cout << "Area of rectangle: " << RectangleArea << endl;
    }

    return 0;
}