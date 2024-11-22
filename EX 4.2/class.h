#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Address {
private:
    string street;
    string city;
    string postalCode;

public:
    // Constructor
    Address(string street, string city, string postalCode)
        : street(street), city(city), postalCode(postalCode) {}

    // Display address
    void displayAddress() const {
        cout << "Street: " << street << ", City: " << city << ", Postal Code: " << postalCode << endl;
    }
};

// Engine Class
class Engine {
private:
    int horsepower;
    string engineType;

public:
    // Constructor
    Engine(int horsepower, string engineType)
        : horsepower(horsepower), engineType(engineType) {}

    // Display engine information
    void displayEngineInfo() const {
        cout << "Horsepower: " << horsepower << " HP, Engine Type: " << engineType << endl;
    }
};

// Driver Class
class Driver {
private:
    string name;
    string licenseNumber;

public:
    // Constructor
    Driver(string name, string licenseNumber)
        : name(name), licenseNumber(licenseNumber) {}

    // Display driver details
    void displayDriverInfo() const {
        cout << "Driver Name: " << name << ", License Number: " << licenseNumber << endl;
    }
};

// Commuter Class
class Commuter {
private:
    string name;
    string ticketNumber;

public:
    // Constructor
    Commuter(string name, string ticketNumber)
        : name(name), ticketNumber(ticketNumber) {}

    // Getter method for ticketNumber
    string getTicketNumber() const {
        return ticketNumber;
    }

    // Display commuter details
    void displayCommuterInfo() const {
        cout << "Commuter Name: " << name << ", Ticket Number: " << ticketNumber << endl;
    }
};

// Mosquito Class (as a simple class that interacts with others)
class Mosquito {
private:
    string species;
    string location;

public:
    // Constructor
    Mosquito(string species, string location)
        : species(species), location(location) {}

    // Display mosquito info
    void displayMosquitoInfo() const {
        cout << "Mosquito Species: " << species << ", Location: " << location << endl;
    }
};

// Car Class (Generic vehicle class)
class Car {
private:
    string make;
    string model;
    int year;

public:
    // Constructor
    Car(string make, string model, int year)
        : make(make), model(model), year(year) {}

    // Display car info
    void displayCarInfo() const {
        cout << "Car Make: " << make << ", Model: " << model << ", Year: " << year << endl;
    }
};

// Bus Class (inherits from Car, since a Bus is a type of Car)
class Bus : public Car {
private:
    string busNumber;
    Engine engine;
    Driver driver;
    int capacity;
    vector<Commuter> commuters;

public:
    // Constructor
    Bus(string busNumber, Engine engine, Driver driver, int capacity, string make, string model, int year)
        : Car(make, model, year), busNumber(busNumber), engine(engine), driver(driver), capacity(capacity) {}

    // Getter method for busNumber
    string getBusNumber() const {
        return busNumber;
    }

    // Add commuter to the bus
    void addCommuter(const Commuter& commuter) {
        if (commuters.size() < capacity) {
            commuters.push_back(commuter);
        }
        else {
            cout << "Bus is full!" << endl;
        }
    }

    // Remove commuter from the bus
    void removeCommuter(const string& ticketNumber) {
        for (auto it = commuters.begin(); it != commuters.end(); ++it) {
            if (it->getTicketNumber() == ticketNumber) {  // Use the getter for ticketNumber
                commuters.erase(it);
                return;
            }
        }
        cout << "Commuter not found!" << endl;
    }

    // Display bus details
    void displayBusDetails() const {
        cout << "\nBus Number: " << busNumber << endl;
        engine.displayEngineInfo();
        driver.displayDriverInfo();
        cout << "Capacity: " << capacity << endl;
        for (const auto& commuter : commuters) {
            commuter.displayCommuterInfo();
        }
    }
};

// BusStation Class
class BusStation {
private:
    string name;
    Address address;
    vector<Bus> buses;

public:
    // Constructor
    BusStation(string name, Address address) : name(name), address(address) {}

    // Add bus to the station
    void addBus(const Bus& bus) {
        buses.push_back(bus);
    }

    // Remove bus from the station
    void removeBus(const string& busNumber) {
        for (auto it = buses.begin(); it != buses.end(); ++it) {
            if (it->getBusNumber() == busNumber) {  // Use the getter for busNumber
                buses.erase(it);
                return;
            }
        }
        cout << "Bus not found!" << endl;
    }

    // Display all buses at the station
    void displayBuses() const {
        cout << "\nBuses at " << name << " Station:" << endl;
        for (const auto& bus : buses) {
            bus.displayBusDetails();
        }
    }
};
