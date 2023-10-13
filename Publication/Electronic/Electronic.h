#ifndef T28_HW_ELECTRONIC_H
#define T28_HW_ELECTRONIC_H

#include "../Publication.h"

class Electronic : public Publication {
protected:
    string link;
    string anotation;

public:
    Electronic();
    Electronic(int isbn, string title, string author, string link, string anotation);
    virtual ~Electronic();

    void setLink(string link);
    string getLink()const override;

    void setAnotation(string anotation);
    string getAnotation()const override;

    virtual void show()const override;
    virtual string getType()const override;

    friend std::ostream& operator << (std::ostream& os, const Electronic& e);

    //заглушки
    virtual string getMagazine_name()const override;
    virtual int geNumber()const override;
    virtual int getYear()const override;
    virtual string getPublications()const override;
};


#endif //T28_HW_ELECTRONIC_H
