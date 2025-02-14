#include <iostream>
#include <string>

using namespace std;

class Library {
private:
    string bookList[100];   
    bool isBorrowed[100];  
    int totalBooks;         
    
public:
    Library() {
        totalBooks = 0;
    }

    void addBook(string title) {
        if (totalBooks < 100) {
            bookList[totalBooks] = title;
            isBorrowed[totalBooks] = false;  
            totalBooks++;
            cout << "Book '" << title << "' added to the library." << endl;
        } else {
            cout << "Library is full! Cannot add more books." << endl;
        }
    }

    void lendBook(string title) {
        bool found = false;
        for (int i = 0; i < totalBooks; ++i) {
            if (bookList[i] == title && !isBorrowed[i]) {
                isBorrowed[i] = true;
                cout << "The book '" << title << "' has been borrowed." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Sorry, the book '" << title << "' is either not available or already borrowed." << endl;
        }
    }

    void returnBook(string title) {
        bool found = false;
        for (int i = 0; i < totalBooks; ++i) {
            if (bookList[i] == title && isBorrowed[i]) {
                isBorrowed[i] = false; 
                cout << "The book '" << title << "' has been returned." << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Sorry, the book '" << title << "' was not borrowed or does not exist." << endl;
        }
    }

    void displayBooks() {
        if (totalBooks == 0) {
            cout << "No books in the library." << endl;
            return;
        }

        cout << "Library Book List:" << endl;
        for (int i = 0; i < totalBooks; ++i) {
            cout << bookList[i];
            if (isBorrowed[i]) {
                cout << " (Borrowed)";
            }
            cout << endl;
        }
    }
};

int main() {
    Library library;

    library.addBook("The Great Gatsby");
    library.addBook("1984");
    library.addBook("To Kill a Mockingbird");
    library.addBook("The Catcher in the Rye");

    library.displayBooks();

    library.lendBook("1984");
    library.lendBook("The Great Gatsby");

    library.lendBook("1984");

    library.displayBooks();

    library.returnBook("1984");

    library.displayBooks();

    library.returnBook("1984");

    return 0;
}
