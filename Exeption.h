#ifndef Project_EXEPTION_H
#define Project_EXEPTION_H

#include "iostream"
#include "string"

using namespace std;

class Exeption {
public:
    virtual string showMessage()const=0;
};

class NameExeption : public Exeption {
public:
    string showMessage()const override;
};

class MenuExeption : public Exeption{
public:
    string showMessage()const override;
};

class IntExeption : public Exeption{
public:
    string showMessage()const override;
};


#endif //Project_EXEPTION_H
