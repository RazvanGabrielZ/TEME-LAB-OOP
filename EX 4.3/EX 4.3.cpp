#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "library.h"
using namespace std;

int main() {
    // Create some clients
    Client client1("Marian");
    Client client2("Bona");

    // Create some books
    Book book1("The Great Gatsby");
    Book book2("1984");

    // Create a library and add books to it
    Library library;
    library.addBook(book1);
    library.addBook(book2);

    // Clients leave reviews for the books
    Review review1("Amazing story, loved the characters!", &client1);
    Review review2("A bit dystopian, but very thought-provoking.", &client2);

    library.addReviewToBook("The Great Gatsby", review1);
    library.addReviewToBook("1984", review2);

    // Display all books and their reviews
    library.displayAllBooks();
    book1.displayReviews();
    book2.displayReviews();

    // Search for a term in the reviews and client names
    string searchTerm;
    cout << "\nEnter a search term (review or reviewer name): ";
    getline(cin, searchTerm);
    library.searchReviews(searchTerm);

    return 0;
}