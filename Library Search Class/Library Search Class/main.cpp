#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include "Book.h"

using namespace std;

bool compareByLastName(const Book& book1, const Book& book2) {
    string lastName1 = book1.getAuthorLastName();
    string lastName2 = book2.getAuthorLastName();

    return (lastName1 != lastName2) ? (lastName1 < lastName2) : (book1.getTitle() < book2.getTitle());
}

vector<Book> sorter(const vector<Book>& books) {
    vector<Book> sortedBooks = books;
    sort(sortedBooks.begin(), sortedBooks.end(), compareByLastName);
    return sortedBooks;
}

void addBook(vector<Book>& books) {
    string title, author;
    int year;
    cout << "Enter the new book details:\n";
    cout << "Enter book's title: ";
    getline(cin >> ws, title);

    cout << "Enter book's author: ";
    getline(cin >> ws, author);

    cout << "Enter book's publication year: ";
    cin >> year;

    books.push_back(Book(title, author, year));
    books = sorter(books);
}

void searchByAuthor(const vector<Book>& books) {
    string author;

    cout << "Enter the author of the book you want to search for: ";
    getline(cin >> ws, author);
    string lowerAuthor = author;
    transform(lowerAuthor.begin(), lowerAuthor.end(), lowerAuthor.begin(), [](char c) {
        return tolower(c);
        });

    vector<int> positions;

    for (int i = 0; i < books.size(); i++) {
        string bookAuthor = books[i].getAuthor();
        string lowerBookAuthor = bookAuthor;
        transform(lowerBookAuthor.begin(), lowerBookAuthor.end(), lowerBookAuthor.begin(), [](char c) {
            return tolower(c);
            });

        if (lowerBookAuthor == lowerAuthor) {
            positions.push_back(i + 1);
        }
    }

    if (positions.empty()) {
        cout << "No books were found.\n";
    }
    else {
        cout << "Books by " << author.substr(author.find_last_of(' ') + 1) << ":\n";
        for (const auto& position : positions) {
            const auto& book = books[position - 1];
            cout << "Title: " << book.getTitle() << ", Publication Year: " << book.getPublicationYear() << ", Position: " << position << endl;
        }
    }
}

void searchByTitle(const vector<Book>& books) {
    string title;

    cout << "Enter the title of the book you want to search for: ";
    getline(cin >> ws, title);
    cout << "Books matching the title \"" << title << "\":\n";
    transform(title.begin(), title.end(), title.begin(), [](char c) {
        return tolower(c);
        });

    vector<int> positions;

    for (int i = 0; i < books.size(); i++) {
        string bookTitle = books[i].getTitle();
        transform(bookTitle.begin(), bookTitle.end(), bookTitle.begin(), [](char c) {
            return tolower(c);
            });

        if (bookTitle == title) {
            positions.push_back(i + 1);
        }
    }

    if (positions.empty()) {
        cout << "No books were found.\n";
    }
    else {
        for (const auto& position : positions) {
            const auto& book = books[position - 1];
            cout << "Title: " << book.getTitle() << ", Author: " << book.getAuthor() << ", Publication Year: " << book.getPublicationYear() << ", Position: " << position << endl;
        }
    }
}

void displayBooks(const vector<Book>& sortedBooks) {
    int counter = 0;

    cout << "Sorted books by author's last name:\n";
    for (const auto& book : sortedBooks) {
        counter++;
        cout << counter << ". " << book.getTitle() << ", " << book.getAuthor() << ", " << book.getPublicationYear() << "\n";
    }
    cout << endl;
}

int main() {
    vector<Book> books = {
        Book("The Great Gatsby", "F Scott Fitzgerald", 1925),
        Book("Moby Dick", "Herman Melville", 1851),
        Book("To Kill a Mockingbird", "Harper Lee", 1960),
        Book("Pride and Prejudice", "Jane Austen", 1813),
        Book("Burmese Days", "George Orwell", 1934),
        Book("Brave New World", "Aldous Huxley", 1932),
        Book("Animal Farm", "George Orwell", 1945)
    };

    int choice;
    books = sorter(books);

    do {
        cout << "Library System Menu:\n";
        cout << "1. Add books\n";
        cout << "2. Search for an author\n";
        cout << "3. Search for by book title\n";
        cout << "4. Display books\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBook(books);
            books = sorter(books);
            break;
        case 2:
            searchByAuthor(books);
            break;
        case 3:
            searchByTitle(books);
            break;
        case 4:
            books = sorter(books);
            displayBooks(books);
            break;
        case 5:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice, please try again.\n";
            break;
        }
    } while (choice != 5);

    return 0;
}
