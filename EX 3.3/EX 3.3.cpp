#include <iostream>
#include <vector>
#include <string>
#include "students.h"
using namespace std;

int main() {
    vector<Student> students;
    int numStudents;

    // Get the number of students
    cout << "Enter the number of students: ";
    cin >> numStudents;

    // Input student details
    for (int i = 0; i < numStudents; ++i) {
        string name;
        double grade;

        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter grade of student " << i + 1 << ": ";
        cin >> grade;

        students.emplace_back(name, grade); // Add the student to the vector
    }

    // Find and display the student/students with the highest grade
    findTopStudents(students);

    return 0;
}