#include "Publication.h"

Publication::Publication() {
    isbn=0;
    title="";
    author="";
    isAviable=true;
}
Publication::~Publication() {}

Publication::Publication(int isbn, string title, string author) {
    setIsbn(isbn);
    setAuthor(author);
    setTitile(title);
    isAviable=true;
}

void Publication::setIsbn(int isbn) {
    this->isbn=isbn;
}

int Publication::getIsbn() const {
    return isbn;
}

void Publication::setTitile(string title) {
    if(title.size()<=0)
        throw new NameExeption;
    this->title=title;
}

string Publication::getTitile() const {
    return title;
}

void Publication::setAuthor(string author) {
    if(author.size()<=0)
        throw new NameExeption;
    this->author=author;
}

string Publication::getAuthor() const {
    return author;
}

void Publication::setAviavle(bool status) {
    this->isAviable=status;
}

bool Publication::getAviable() const {
    if(isAviable)
    return true;
    return false;
}

bool Publication::operator<(const Publication &obj) const {
    return this->getIsbn()<obj.getIsbn();
}
