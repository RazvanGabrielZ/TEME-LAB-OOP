#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Student {
private:
    string name;
    int id;

public:
    // Constructor
    Student(const string& name, int id) : name(name), id(id) {}

    // Accessors
    string getName() const { return name; }
    int getId() const { return id; }
};

// Function to search for a student by name
void searchStudentByName(const vector<Student>& students, const string& searchName) {
    // Use find_if with a lambda function
    auto it = find_if(students.begin(), students.end(),
        [&searchName](const Student& student) {
            return student.getName() == searchName;
        });

    // Output the result
    if (it != students.end()) {
        cout << "Student found: " << it->getName() << " (ID: " << it->getId() << ")\n";
    }
    else {
        cout << "Student not found.\n";
    }
}