#ifndef Project_TEXTBOOK_H
#define Project_TEXTBOOK_H


#include "Book.h"

class TextBook : public Book {
    int _class;

public:
    TextBook();
    TextBook(int isbn, string title, string author, string publications,int year, int _class);
    void setClass(int);
    int getClass()const;

    virtual void show()const override;
    virtual string getType()const override;
};


#endif //Project_TEXTBOOK_H
