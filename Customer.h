#ifndef Project_CUSTOMER_H
#define Project_CUSTOMER_H

#include "string"
#include "iostream"
#include "vector"
#include "set"
#include "algorithm"
#include "map"

#include "Publication/Publication.h"
#include "Publication/Book/Book.h"
#include "Publication/Article/Article.h"
#include "Publication/Electronic/Electronic.h"
#include "DateTime/DT.h"
//#include "Publication/Book/TextBook.h"

using namespace std;

struct compare_Customers{
    bool operator()(const Publication* left, const Publication* right)const
    {
        return *left<*right;
    }
};

class Customer {
protected:
    int id;
    string name;
    string surnme;
    string phone;
    string address;
    multiset<Publication*,compare_Customers> use_publications;
    bool inArhive;

public:
    Customer(const int &id, const string &name, const string &surnme, const string &phone, const string &address);
    const string &getName() const;
    void setName(const string &name);
    const string &getSurnme() const;
    void setSurnme(const string &surnme);
    const string &getPhone() const;
    void setPhone(const string &phone);
    const string &getAddress() const;
    void setAddress(const string &address);
    void showCustomer()const; //клиент со списком публикаций
    bool operator <(const Customer &right) const &;
    void setInArhive(bool status);

    void addPublicationToCustomer(Publication* obj);
    void showPublicationInUse()const;


    void setId(int id);  //TODO возможно не понадобятся
    int getId()const;    //

    void ReturnEdition(int isbn);
    void ReturnAllEditions();

    friend std::ostream& operator << (std::ostream& os, const Customer& cus); //клиент без публикаций
};


#endif //Project_CUSTOMER_H
