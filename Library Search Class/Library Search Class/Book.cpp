// Book.cpp

#include "Book.h"
#include <iostream>
#include <algorithm>

Book::Book() {
    title = "";
    author = "";
    publicationYear = 0;
}

Book::Book(const string& title, const string& author, int publicationYear) {
    this->title = title;
    this->author = author;
    this->publicationYear = publicationYear;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

int Book::getPublicationYear() const {
    return publicationYear;
}

void Book::setTitle(const string& book_title) {
    title = book_title;
}

void Book::setAuthor(const string& book_author) {
    author = book_author;
}

void Book::setPublicationYear(int book_publicationYear) {
    publicationYear = book_publicationYear;
}

string Book::getAuthorLastName() const {
    string lastName = author.substr(author.find_last_of(' ') + 1);
    transform(lastName.begin(), lastName.end(), lastName.begin(), [](char c) {
        return tolower(c);
        });
    return lastName;
}

void Book::display() const {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Publication Year: " << publicationYear << endl;
}
