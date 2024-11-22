#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "relations.h"
using namespace std;

int main() {
    Address addr1("123 Elm St", "Springfield", "98765");
    Address addr2("456 Oak St", "Springfield", "98766");

    Driver driver("Jane Doe", addr1);
    Student student("Marcel", addr2);
    Commuter commuter("Sandel", addr2);

    Bus bus1("B001", "Mercedes", "Sprinter", 2022);
    bus1.setDriver(&driver);

    BusStation station("Central Station");
    station.addBus(&bus1);

    Mosquito mosquito("Aedes");

    Apartment apartment("A101");
    apartment.addMosquito(&mosquito);

    // Operations
    bus1.startEngine();
    bus1.addCommuter(&student);
    bus1.displayBuses();
    station.displayBuses();

    cout << "Mosquito is in apartment A101: " << apartment.hasMosquito("Aedes") << endl;

    // Check if a specific mosquito is in a bus, car, or apartment
    cout << "Is mosquito in bus B001: " << (bus1.hasMosquito("Aedes") ? "Yes" : "No") << endl;

    return 0;
}