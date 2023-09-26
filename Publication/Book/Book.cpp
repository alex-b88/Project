#include "Book.h"

Book::Book() {
    publications="";
    year=0;
}

Book::Book(int isbn, string title, string author, string publications, int year)
        : Publication(isbn,title,author)
{
    setPublications(publications);
    setYear(year);
}

Book::~Book() {}

void Book::show() const {
    cout << "ISBN: " << isbn << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout <<"Publications: " << publications << endl;
    cout <<"Year: " << year << endl;
}

string Book::getType() const {
    return "Book";
}


void Book::setPublications(string publications) {
    this->publications=publications;
}

void Book::setYear(int year) {
    this->year=year;
}

string Book::getPublications() const {
    return publications;
}

int Book::getYear() const {
    return year;
}
