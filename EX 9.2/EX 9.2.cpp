#include <iostream>
#include <vector>
#include <cmath> // For M_PI
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846 // Define Pi manually if not already defined
#endif

// Abstract base class Shape
class Shape {
public:
    virtual void draw() = 0;       // Pure virtual function for drawing shapes
    virtual double getArea() = 0;  // Pure virtual function for calculating area
    virtual ~Shape() {}            // Virtual destructor
};

// Circle class inheriting from Shape
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    void draw() override {
        cout << "Drawing Circle with radius: " << radius << endl;
    }
    double getArea() override {
        return M_PI * radius * radius; // Area = PI * r²
    }
};

// Triangle class inheriting from Shape
class Triangle : public Shape {
private:
    double base, height;
public:
    Triangle(double b, double h) : base(b), height(h) {}
    void draw() override {
        cout << "Drawing Triangle with base: " << base << " and height: " << height << endl;
    }
    double getArea() override {
        return 0.5 * base * height; // Area = 1/2 * base * height
    }
};

// Square class inheriting from Shape
class Square : public Shape {
private:
    double side;
public:
    Square(double s) : side(s) {}
    void draw() override {
        cout << "Drawing Square with side: " << side << endl;
    }
    double getArea() override {
        return side * side; // Area = side²
    }
};

// Placeholder for additional shape or behavior
// Possible missing reference implementation:
// For example, a Rectangle or a Pentagon could go here
class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    void draw() override {
        cout << "Drawing Rectangle with length: " << length << " and width: " << width << endl;
    }
    double getArea() override {
        return length * width; // Area = length * width
    }
};

int main() {
    vector<Shape*> shapes; // Vector to store pointers to shapes

    // Adding different shapes to the vector
    shapes.push_back(new Circle(5));      // Circle with radius 5
    shapes.push_back(new Triangle(4, 6)); // Triangle with base 4 and height 6
    shapes.push_back(new Square(3));      // Square with side 3
    shapes.push_back(new Circle(7));      // Circle with radius 7

    // Placeholder for "missing reference" shape
    shapes.push_back(new Rectangle(4, 8)); // Rectangle as additional example

    double totalArea = 0; // To store the sum of areas

    // Iterating through the vector, drawing shapes, and summing their areas
    for (auto shape : shapes) {
        shape->draw();
        totalArea += shape->getArea();
    }

    cout << "\nThe total area of all shapes is: " << totalArea << endl;

    // Free allocated memory
    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}
