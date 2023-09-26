#include "Electronic.h"

Electronic::Electronic() {
    link="";
    anotation="";
}

Electronic::~Electronic() {}

Electronic::Electronic(int isbn, string title, string author, string link, string anotation)
        : Publication(isbn, title, author)
{
    setLink(link);
    setAnotation(anotation);
}

void Electronic::setLink(string link) {
    this->link=link;
}

string Electronic::getLink() const {
    return link;
}

void Electronic::setAnotation(string anotation) {
    this->anotation=anotation;
}

string Electronic::getAnotation() const {
    return anotation;
}

void Electronic::show() const {
    cout << "ISBN: " << isbn << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout <<"Link: " << link << endl;
    cout <<"Anotation: " << anotation << endl;
}

string Electronic::getType() const {
    return "Electronic";
}
