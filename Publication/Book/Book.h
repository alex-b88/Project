#ifndef T28_HW_BOOK_H
#define T28_HW_BOOK_H

#include "../Publication.h"

class Book : public Publication {
protected:
    string publications;
    int year;

public:
    Book();
    Book(int isbn, string title, string author, string publications,int year);
    virtual ~Book();

    void setPublications(string publications);
    string getPublications()const;

    void setYear(int year);
    int getYear()const;

    virtual void show()const override;
    virtual string getType()const override;
};


#endif //T28_HW_BOOK_H
