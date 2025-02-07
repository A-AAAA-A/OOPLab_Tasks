#include<iostream>
using namespace std;

struct LibraryBook
{
    string name;
    string writer;
    int publicationYear;
};

void enterBookDetails(LibraryBook *bookCollection, int numBooks){
    for(int i=0; i<numBooks; i++){
        cout << "Enter details for book " << i+1 << ":" << endl;
        cout << "Title of the book: ";
        cin.ignore();  // Ignore any leftover newline
        getline(cin, bookCollection[i].name);
        cout << "Author's name: ";
        getline(cin, bookCollection[i].writer);
        cout << "Year of publication: ";
        cin >> bookCollection[i].publicationYear;
    }
}

void showAllBooks(LibraryBook *bookCollection, int numBooks){
    for(int i=0; i<numBooks; i++){
        cout << "Book " << i+1 << " details:" << endl;
        cout << "Title: " << bookCollection[i].name << endl;
        cout << "Author: " << bookCollection[i].writer << endl;
        cout << "Published Year: " << bookCollection[i].publicationYear << endl;
    }
}

void showBooksAfterYear(LibraryBook *bookCollection, int numBooks){
    int yearLimit;
    cout << "Enter a year to filter books published after it: ";
    cin >> yearLimit;
    bool found=false;
    for(int i=0; i<numBooks; i++){
        if(bookCollection[i].publicationYear > yearLimit){
            cout << "Title: " << bookCollection[i].name << endl;
            cout << "Author: " << bookCollection[i].writer << endl;
            cout << "Published Year: " << bookCollection[i].publicationYear << endl;
            found=true;
        }
    }
    if(!found){
        cout << "No books were found published after " << yearLimit << endl;
    }
}

int main(){
    int numBooks;
    cout << "How many books would you like to enter? ";
    cin >> numBooks;
    
    LibraryBook *bookCollection = new LibraryBook[numBooks];
    
    enterBookDetails(bookCollection, numBooks);
    showAllBooks(bookCollection, numBooks);
    showBooksAfterYear(bookCollection, numBooks);
    
    delete[] bookCollection;
}

