#ifndef T28_HW_ARTICLE_H
#define T28_HW_ARTICLE_H

#include "../Publication.h"

class Article : public Publication {
protected:
    string magazine_name;
    int number;
    int year;

public:
    Article();
    Article(int isbn, string title, string author, string magazine_name, int number, int year);
    virtual ~Article();

    void setMagazine_name(string magazine_name);
    string getMagazine_name()const;
    void setNumber(int number);
    int geNumber()const;

    void setYear(int year);
    int getYear()const;

    virtual void show()const override;
    virtual string getType()const override;

    friend std::ostream& operator << (std::ostream& os, const Article& a);
};


#endif //T28_HW_ARTICLE_H
