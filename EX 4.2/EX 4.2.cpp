#include <iostream>
#include <vector>
#include <string>
#include "class.h"
using namespace std;

int main() {
    // Creating Address object
    Address address("123 Main St", "Springfield", "98765");

    // Creating Engine object
    Engine engine(450, "Diesel");

    // Creating Driver object
    Driver driver("Jane Doe", "D12345");

    // Creating Commuter objects
    Commuter commuter1("Marian", "C001");
    Commuter commuter2("Sandel", "C002");

    // Creating Bus object
    Bus bus1("B001", engine, driver, 50, "Mercedes", "Sprinter", 2022);
    bus1.addCommuter(commuter1);
    bus1.addCommuter(commuter2);

    // Creating BusStation object
    BusStation station("Central Station", address);
    station.addBus(bus1);

    // Display station information
    station.displayBuses();

    // Creating Mosquito object (just for interaction)
    Mosquito mosquito("Anopheles", "Near Station");

    // Display mosquito info
    mosquito.displayMosquitoInfo();

    return 0;
}