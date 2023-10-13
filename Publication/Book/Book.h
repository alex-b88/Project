#ifndef Project_BOOK_H
#define Project_BOOK_H

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
    string getPublications()const override;

    void setYear(int year);
    int getYear()const override;

    virtual void show()const override;
    virtual string getType()const override;

    //заглушки
    virtual string getMagazine_name()const override;
    virtual int geNumber()const override;
    virtual string getLink()const override;
    virtual string getAnotation()const override;

    friend std::ostream& operator << (std::ostream& os, const Book& b);
};


#endif //Project_BOOK_H
