#include <iostream>
#include <list>
#include <algorithm> 
#include <string>
#include "listing.h"

using namespace std;

int main() {
    list<Person> people;
    int numberofpeople;

    cout << "Enter the number of people: ";
    cin >> numberofpeople;

    // Details for each person
    for (int i = 0; i < numberofpeople; i++) {
        string name;
        int age;

        cout << "Enter name of person " << (i + 1) << ": ";
        cin >> name;
        cout << "Enter age of person " << (i + 1) << ": ";
        cin >> age;

        // Add the new person to the list
        people.emplace_back(name, age);
    }

    // Sort by age in descending order
    people.sort(compareByAge);

    cout << "\nSorted by age (descending):" << endl;
    for (const auto& person : people) {
        cout << person.name << ", Age: " << person.age << endl;
    }

    // Sort by name in ascending order
    people.sort(compareByName);

    cout << "\nSorted by name (ascending):" << endl;
    for (const auto& person : people) {
        cout << person.name << ", Age: " << person.age << endl;
    }

    return 0;
}