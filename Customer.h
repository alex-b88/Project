#ifndef T28_HW_CUSTOMER_H
#define T28_HW_CUSTOMER_H

#include "string"
#include "iostream"
using namespace std;

class Customer {
protected:
    int id;
    string name;
    string surnme;
    string phone;
    string address;
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
    void showCustomer()const;
    bool operator <(const Customer &right) const &;

    void setId(int id);
    int getId()const;
};


#endif //T28_HW_CUSTOMER_H
