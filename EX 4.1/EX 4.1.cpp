#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "onlineshop.h"
using namespace std;

int main() {
    // Create some products
    Product product1("Laptop", 1200.00, true, "Electronics");
    Product product2("Smartphone", 800.00, false, "Electronics");
    Product product3("Shirt", 30.00, true, "Clothing");
    Product product4("Jeans", 50.00, false, "Clothing");

    // Create categories
    Category electronics("Electronics");
    Category clothing("Clothing");

    // Add products to categories
    electronics.addProduct(product1);
    electronics.addProduct(product2);
    clothing.addProduct(product3);
    clothing.addProduct(product4);

    // Create OnlineShop object
    OnlineShop shop;

    // Add categories to the shop
    shop.addCategory(electronics);
    shop.addCategory(clothing);

    // Add products to the shop
    shop.addProductToShop(product1);
    shop.addProductToShop(product2);
    shop.addProductToShop(product3);
    shop.addProductToShop(product4);

    // Display all products in the shop
    shop.displayAllProducts();

    // Display all products on promotion
    shop.displayPromotionProducts();

    // Search products by name
    shop.searchProducts("Shirt");

    // Search products by price range
    shop.searchProducts("", 30.00, 100.00);

    // Search products by category
    shop.searchProducts("", -1, -1, "Electronics");

    // Remove a product from the shop
    shop.removeProductFromShop("Jeans");
    cout << "\nAfter removing 'Jeans':\n";
    shop.displayAllProducts();

    return 0;
}