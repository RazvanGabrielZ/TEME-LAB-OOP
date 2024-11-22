#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include "store.h"
using namespace std;

int main() {
    // Create departments
    Department shoesDept;
    Department toysDept;

    // Add products to departments
    shoesDept.addProduct(new Shoe("Running Shoes", 50.99));
    shoesDept.addProduct(new Shoe("Formal Shoes", 80.75));
    toysDept.addProduct(new Toy("Lego Set", 45.50));
    toysDept.addProduct(new Toy("Action Figure", 25.30));

    // Display all products sorted by name
    cout << "Shoes Department (sorted by name):" << endl;
    shoesDept.displayAllSorted();

    cout << "\nToys Department (sorted by price):" << endl;
    toysDept.displayAllSorted(true);

    // Find a product
    string searchName = "Lego Set";
    Product* found = toysDept.findProduct(searchName);
    if (found) {
        cout << "\nFound product: ";
        found->display();
    }

    // Remove a product
    toysDept.removeProduct("Action Figure");
    cout << "\nToys Department after removing 'Action Figure':" << endl;
    toysDept.displayAllSorted();

    // Create an order
    Order order1;
    order1.addProduct(new Shoe("Running Shoes", 50.99));
    order1.addProduct(new Toy("Lego Set", 45.50));

    // Display order
    cout << "\nOrder 1 contents:" << endl;
    order1.display();

    // Compute total value
    cout << "Total value of Order 1: $" << order1.computeTotal() << endl;

    // Search for a product in the order
    cout << "\nSearch for 'Lego Set' in Order 1:" << endl;
    auto results = order1.searchProduct("Lego Set");
    for (Product* result : results) {
        result->display();
    }

    return 0;
}