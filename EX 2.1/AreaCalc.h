#pragma once
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

double Area(double length, double width) {
    return length * width;
}

double ExceptionHandler(const string& lengthStr, const string& widthStr = "") {
    try {
        size_t lengthPos, widthPos;

        // Convert length string to double and check for any remaining characters
        double length = stod(lengthStr, &lengthPos);
        if (lengthPos != lengthStr.size()) {  // Check if the entire string was parsed
            throw invalid_argument("Non-numeric character found in length");
        }

        // Convert width string to double and check for any remaining characters
        double width = (widthStr.empty()) ? length : stod(widthStr, &widthPos);
        if (!widthStr.empty() && widthPos != widthStr.size()) {  // Check if the entire width string was parsed
            throw invalid_argument("Non-numeric character found in width");
        }

        // Use a function pointer to call Area
        double (*AreaFunction)(double, double) = Area;
        return AreaFunction(length, width);
    }
    catch (const invalid_argument& e) {
        cerr << "Invalid input: Please enter numeric values only." << endl;

        return -1;
    }
    catch (const out_of_range& e) {
        cerr << "Invalid input: The number is out of range." << endl;
        return -1;
    }
}
