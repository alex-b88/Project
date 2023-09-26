#ifndef PROJECT_PUBLICATION_H
#define PROJECT_PUBLICATION_H

#include "string"
#include "iostream"

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

    virtual void show()const=0;
    virtual string getType()const=0;

};


#endif //TPROJECT_PUBLICATION_H
