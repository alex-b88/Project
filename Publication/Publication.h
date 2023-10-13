#ifndef Project_PUBLICATION_H
#define Project_PUBLICATION_H

#include "string"
#include "../Exeption.h"
#include "../Menus/Menu.h"

using namespace std;

class Publication {
protected:
    int isbn;
    string title;
    string author;
    bool isAviable;

public:
    Publication();
    virtual ~Publication();
    Publication(int isbn, string title, string author);
    void setIsbn(int isbn);
    int getIsbn()const;
    void setTitile(string title);
    string getTitile()const;
    void setAuthor(string author);
    string getAuthor()const;

    void setAviavle(bool status);
    bool getAviable()const;

    bool operator < (const Publication& obj)const;

    virtual void show()const=0;
    virtual string getType()const=0;

    //виртуальные методы для класса Article
    virtual string getMagazine_name()const=0;
    virtual int geNumber()const=0;
    virtual int getYear()const=0;
    //виртуальные методы для класса Book
    virtual string getPublications()const=0;

    //виртуальные методы для класса Link
    virtual string getLink()const=0;
    virtual string getAnotation()const=0;
};


#endif //Project_PUBLICATION_H
