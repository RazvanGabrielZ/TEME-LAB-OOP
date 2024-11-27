#include <iostream>
#include "relations.h"
using namespace std;

int main() {
    // Create addresses
    Address addr1("123 Elm St", "Springfield", "98765");
    Address addr2("456 Oak St", "Springfield", "98766");

    // Create driver, student, and commuter
    Driver driver("Jane Doe", addr1);
    Student student("Marcel", addr2);
    Commuter commuter("Sandel", addr2);

    // Create bus and assign driver
    Bus bus1("B001", "Mercedes", "Sprinter", 2022);
    bus1.setDriver(&driver);

    // Create bus station and add bus
    BusStation station("Central Station");
    station.addBus(&bus1);

    // Create mosquito and apartment
    Mosquito mosquito("Aedes");
    Apartment apartment("A101");
    apartment.addMosquito(&mosquito);

    // Start bus engine and add commuters
    bus1.startEngine();
    bus1.addCommuter(&student);
    bus1.addCommuter(&commuter); // Now you can add a commuter as well

    // Display bus information
    bus1.displayBusInfo();

    // Display buses at the station
    station.displayBuses();

    // Check if mosquito is in the apartment
    cout << "Mosquito is in apartment A101: "
        << (apartment.hasMosquito("Aedes") ? "Yes" : "No") << endl;

    // Add mosquito to the bus and check
    bus1.addMosquito(&mosquito);
    cout << "Is mosquito in bus B001: "
        << (bus1.hasMosquito("Aedes") ? "Yes" : "No") << endl;

    return 0;
}
