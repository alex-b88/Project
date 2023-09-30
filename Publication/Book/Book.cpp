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
    cout << "\t |-ISBN:" << isbn<< " (" << getType() <<"); Author: "<< author << "; Title: \"" << title <<"\";" << endl;
/*    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout <<"Publications: " << publications << endl;
    cout <<"Year: " << year << endl;*/
}

string Book::getType() const {
    return "Book";
}


void Book::setPublications(string publications) {
    if(publications.size()<=0)
        throw new MenuExeption;
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

std::ostream& operator<<(std::ostream& os, const Book& b){
    os << "ISBN: " << b.isbn << endl;
    os << "Title: " << b.title << endl;
    os << "Author: " << b.author << endl;
    os <<"Publications: " << b.publications << endl;
    os <<"Year: " << b.year << endl;
    return os;
}

/*
bool Book::operator<(const Book &obj) const &{
    return this->isbn<obj.isbn;
}*/
