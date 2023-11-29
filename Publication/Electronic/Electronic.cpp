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
    if(link.size()<=0)
        throw new NameExeption;
    this->link=link;
}

string Electronic::getLink() const {
    return link;
}

void Electronic::setAnotation(string anotation) {
    if(anotation.size()<=0)
        throw new NameExeption;
    this->anotation=anotation;
}

string Electronic::getAnotation() const {
    return anotation;
}

void Electronic::show() const {
    cout << "\t |-ISBN:" << isbn<< " (" << getType() <<"); Author: "<< author << "; Title: \"" << title <<"\";" << endl;
   /* cout << "ISBN: " << isbn << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout <<"Link: " << link << endl;
    cout <<"Annotation: " << anotation << endl;*/
}

string Electronic::getType() const {
    return "Electronic";
}

std::ostream& operator<<(std::ostream& os, const Electronic& e){
    os << "ISBN: " << e.isbn << endl;
    os << "Title: " << e.title << endl;
    os << "Author: " << e.author << endl;
    os <<"Link: " << e.link << endl;
    os <<"Annotation: " << e.anotation << endl;
    return os;
}
