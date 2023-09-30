#ifndef T28_HW_PUBLICATION_H
#define T28_HW_PUBLICATION_H

#include "string"
#include "iostream"
#include "../Exeption.h"

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

    bool operator < (const Publication& obj)const; //TODO сортирует от большего в меньшему, надо на оборот

    virtual void show()const=0;
    virtual string getType()const=0;

};


#endif //T28_HW_PUBLICATION_H
