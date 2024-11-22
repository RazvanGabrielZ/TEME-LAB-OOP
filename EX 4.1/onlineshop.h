#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Product {
public:
    string name;
    double price;
    bool onPromotion;  // True if product is on promotion
    string category;

    // Constructor to initialize product
    Product(string name, double price, bool onPromotion, string category)
        : name(name), price(price), onPromotion(onPromotion), category(category) {}

    void displayProduct() const {
        cout << "Name: " << name << ", Price: $" << price
            << ", Promotion: " << (onPromotion ? "Yes" : "No")
            << ", Category: " << category << endl;
    }
};

class Category {
public:
    string name;
    vector<Product> products;

    // Constructor to initialize category
    Category(string name) : name(name) {}

    // Add product to category
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    // Remove product from category
    void removeProduct(const string& productName) {
        products.erase(remove_if(products.begin(), products.end(),
            [&productName](const Product& p) { return p.name == productName; }),
            products.end());
    }

    // Display all products in this category
    void displayCategoryProducts() const {
        cout << "Category: " << name << endl;
        for (const auto& product : products) {
            product.displayProduct();
        }
    }
};

class OnlineShop {
private:
    vector<Category> categories;
    vector<Product> allProducts;

public:
    // Add category to the shop
    void addCategory(const Category& category) {
        categories.push_back(category);
    }

    // Remove category from the shop
    void removeCategory(const string& categoryName) {
        categories.erase(remove_if(categories.begin(), categories.end(),
            [&categoryName](const Category& c) { return c.name == categoryName; }),
            categories.end());
    }

    // Add product to the shop
    void addProductToShop(const Product& product) {
        allProducts.push_back(product);
    }

    // Remove product from the shop
    void removeProductFromShop(const string& productName) {
        allProducts.erase(remove_if(allProducts.begin(), allProducts.end(),
            [&productName](const Product& p) { return p.name == productName; }),
            allProducts.end());
    }

    // Display all products in the shop
    void displayAllProducts() const {
        cout << "\nAll products in the shop:\n";
        for (const auto& product : allProducts) {
            product.displayProduct();
        }
    }

    // Display all products on promotion
    void displayPromotionProducts() const {
        cout << "\nProducts on promotion:\n";
        for (const auto& product : allProducts) {
            if (product.onPromotion) {
                product.displayProduct();
            }
        }
    }

    // Search products based on name, price, and category
    void searchProducts(const string& name = "", double minPrice = -1, double maxPrice = -1, const string& category = "") const {
        cout << "\nSearch results:\n";
        for (const auto& product : allProducts) {
            bool match = true;

            if (!name.empty() && product.name.find(name) == string::npos) {
                match = false;
            }
            if (minPrice != -1 && product.price < minPrice) {
                match = false;
            }
            if (maxPrice != -1 && product.price > maxPrice) {
                match = false;
            }
            if (!category.empty() && product.category != category) {
                match = false;
            }

            if (match) {
                product.displayProduct();
            }
        }
    }
};
