#ifndef Project_ARTICLE_H
#define Project_ARTICLE_H

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

    //заглушки
/*    virtual string getPublications()const override;
    virtual string getLink()const override;
    virtual string getAnotation()const override;*/


    friend std::ostream& operator << (std::ostream& os, const Article& a);
};


#endif //Project_ARTICLE_H
