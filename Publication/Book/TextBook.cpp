#include "TextBook.h"

TextBook::TextBook() {
    _class=0;
}

TextBook::TextBook(int isbn, string title, string author, string publications,int year, int _class)
:Book(isbn,title,author, publications, year)
{
    setClass(_class);
}

void TextBook::setClass(int _class) {
    if(_class<0 || _class>12)
        throw new IntExeption;
    this->_class=_class;
}

int TextBook::getClass() const {
    return _class;
}

string TextBook::getType() const {
    return "TextBook";
}

void TextBook::show() const {
    cout << "\t |-ISBN:" << isbn<< " (" << getType() <<"); Author: "<< author << "; Title: \"" << title <<"\";" <<" Class:" << _class <<endl;
}