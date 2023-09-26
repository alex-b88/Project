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
    this->title=title;
}

string Publication::getTitile() const {
    return title;
}

void Publication::setAuthor(string author) {
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
