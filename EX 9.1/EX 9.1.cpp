#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Abstract base class Vehicle
class Vehicle {
public:
    virtual void start() = 0; // Pure virtual function
    virtual ~Vehicle() {}     // Virtual destructor
};

// Rocket class inheriting from Vehicle
class Rocket : public Vehicle {
private:
    string name; // Name of the Rocket
public:
    Rocket(string n) : name(n) {} // Constructor to set the name

    void start() override {
        cout << "start " << name << " rocket" << endl;
    }
};

// Car class inheriting from Vehicle
class Car : public Vehicle {
private:
    string name; // Name of the Car
public:
    Car(string n) : name(n) {} // Constructor to set the name

    void start() override {
        cout << "start " << name << " car" << endl;
    }
};

int main() {
    vector<Vehicle*> vehicles; // Vector of pointers to Vehicle

    // Add vehicles with names
    vehicles.push_back(new Car("red"));
    vehicles.push_back(new Car("awesome"));
    vehicles.push_back(new Rocket("NASA"));

    // Start all vehicles using range-based for loop
    for (auto element : vehicles) {
        element->start();
    }

    // Free allocated memory
    for (auto element : vehicles) {
        delete element;
    }

    return 0;
}
