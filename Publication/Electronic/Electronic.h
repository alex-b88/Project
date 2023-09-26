#ifndef PROJECT_ELECTRONIC_H
#define PROJECT_ELECTRONIC_H

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
    string getLink()const;

    void setAnotation(string anotation);
    string getAnotation()const;

    virtual void show()const override;
    virtual string getType()const override;
};


#endif //PROJECT_ELECTRONIC_H
