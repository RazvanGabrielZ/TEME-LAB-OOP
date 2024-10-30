#pragma once
#include <iostream>
#include <list>
#include <algorithm> 
#include <string>    

using namespace std;

struct Person {
    string name;
    int age;

    Person(string n, int a) : name(n), age(a) {}
};

// Comparator to sort by age in descending order
bool compareByAge(const Person& a, const Person& b) {
    return a.age > b.age; // greater than for descending order
}

// Comparator to sort by name in ascending order
bool compareByName(const Person& a, const Person& b) {
    return a.name < b.name; // less than for ascending order
}
