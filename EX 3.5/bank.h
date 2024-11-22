#pragma once
#include <iostream>
#include <string>
using namespace std;

class BankApp {
private:
    string username = "user123";  // Hardcoded username
    string password = "pass123";  // Hardcoded password
    double balance = 0.0;         // Account balance
    bool isLoggedIn = false;      // Login status
    static int userCount;         // Static variable to count the number of logged-in users

public:
    // Constructor to initialize the BankApp object
    BankApp() {}

    // Login function to authenticate the user
    void login(const string& inputUsername, const string& inputPassword) {
        if (inputUsername == username && inputPassword == password) {
            isLoggedIn = true;
            userCount++;  // Increment user count when a successful login occurs
            cout << "Login successful.\n";
        }
        else {
            cout << "Invalid username or password.\n";
        }
    }

    void deposit(double amount) {
        if (!isLoggedIn) {
            cout << "Please log in first to perform this operation.\n";
            return;
        }
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << "\n";
        }
        else {
            cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (!isLoggedIn) {
            cout << "Please log in first to perform this operation.\n";
            return;
        }
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << "\n";
        }
        else {
            cout << "Invalid withdrawal amount or insufficient balance.\n";
        }
    }

    void displayBalance() {
        if (!isLoggedIn) {
            cout << "Please log in first to perform this operation.\n";
            return;
        }
        cout << "Current balance: $" << balance << "\n";
    }

    // Static method to display the number of users who have logged in
    static void displayUserCount() {
        cout << "Total users who have logged in: " << userCount << "\n";
    }

    void logout() {
        if (isLoggedIn) {
            isLoggedIn = false;
            cout << "You have logged out.\n";
        }
        else {
            cout << "No user is currently logged in.\n";
        }
    }
};

// Initialize static variable to count users
int BankApp::userCount = 0;
