#include "Article.h"

Article::Article() {
    magazine_name="";
    number=0;
    year=0;
}

Article::Article(int isbn, string title, string author, string magazine_name, int number, int year)
: Publication(isbn,title,author)
{
    setMagazine_name(magazine_name);
    setNumber(number);
    setYear(year);
}

Article::~Article() {}

void Article::show() const {
    cout << "\t |-ISBN:" << isbn<< " (" << getType() <<"); Author: "<< author << "; Title: \"" << title <<"\""<< endl;
/*    cout << "#" << number <<". Magazine: \"" << magazine_name <<"\"" << endl;
    cout << "Title: \"" << title <<"\"";
    cout << " Author: " << author << endl;*/

}

string Article::getType() const {
    return "Article";
}

void Article::setMagazine_name(string magazine_name) {
    if(magazine_name.size()<=0)
        throw new NameExeption();
    this->magazine_name = magazine_name;
}

string Article::getMagazine_name() const {
    return magazine_name;
}

void Article::setNumber(int number) {
    this->number=number;
}

int Article::geNumber() const {
    return number;
}

void Article::setYear(int year) {
    this->year=year;
}

int Article::getYear() const {
    return year;
}

std::ostream& operator<<(std::ostream& os, const Article& a){
    os << "ISBN: " << a.isbn << endl;
    os << "#" << a.number <<". Magazine: \"" << a.magazine_name <<"\"" << endl;
    os << "Title: \"" << a.title <<"\"";
    os << " Author: " << a.author << endl;
    return os;
}
