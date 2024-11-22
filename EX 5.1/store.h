#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(const string& name, double price) : name(name), price(price) {}
    virtual ~Product() = default;

    string getName() const { return name; }
    double getPrice() const { return price; }

    virtual void display() const {
        cout << "Name: " << name << ", Price: $" << fixed << setprecision(2) << price << endl;
    }
};

class Shoe : public Product {
public:
    Shoe(const string& name, double price) : Product(name, price) {}
    void display() const override {
        cout << "[Shoe] ";
        Product::display();
    }
};

class Toy : public Product {
public:
    Toy(const string& name, double price) : Product(name, price) {}
    void display() const override {
        cout << "[Toy] ";
        Product::display();
    }
};

class Department {
private:
    vector<Product*> products;

public:
    ~Department() {
        for (Product* product : products) {
            delete product;
        }
    }

    void addProduct(Product* product) {
        products.push_back(product);
    }

    void addProducts(const vector<Product*>& newProducts) {
        products.insert(products.end(), newProducts.begin(), newProducts.end());
    }

    Product* findProduct(const string& name) {
        for (Product* product : products) {
            if (product->getName() == name) {
                return product;
            }
        }
        return nullptr;
    }

    void removeProduct(const string& name) {
        products.erase(remove_if(products.begin(), products.end(),
            [&name](Product* product) {
                bool toRemove = product->getName() == name;
                if (toRemove) delete product;
                return toRemove;
            }),
            products.end());
    }

    void displayAllSorted(bool sortByPrice = false) {
        vector<Product*> sortedProducts = products;
        if (sortByPrice) {
            sort(sortedProducts.begin(), sortedProducts.end(),
                [](Product* a, Product* b) { return a->getPrice() < b->getPrice(); });
        }
        else {
            sort(sortedProducts.begin(), sortedProducts.end(),
                [](Product* a, Product* b) { return a->getName() < b->getName(); });
        }
        for (Product* product : sortedProducts) {
            product->display();
        }
    }

    void displayByType(const string& type) {
        for (Product* product : products) {
            if ((type == "Shoe" && dynamic_cast<Shoe*>(product)) ||
                (type == "Toy" && dynamic_cast<Toy*>(product))) {
                product->display();
            }
        }
    }
};

class Order {
private:
    vector<Product*> items;

public:
    void addProduct(Product* product) {
        items.push_back(product);
    }

    vector<Product*> searchProduct(const string& name) {
        vector<Product*> results;
        for (Product* item : items) {
            if (item->getName() == name) {
                results.push_back(item);
            }
        }
        return results;
    }

    double computeTotal() {
        double total = 0;
        for (Product* item : items) {
            total += item->getPrice();
        }
        return total;
    }

    void display() const {
        for (Product* item : items) {
            item->display();
        }
    }
};
