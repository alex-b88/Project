
#include "Customer.h"

Customer::Customer(const int &id,const string &name, const string &surnme, const string &phone, const string &address)
        :id(id), name(name), surnme(surnme), phone(phone), address(address) {}

const string &Customer::getName() const {
    return name;
}

void Customer::setName(const string &name) {
    Customer::name = name;
}

const string &Customer::getSurnme() const {
    return surnme;
}

void Customer::setSurnme(const string &surnme) {
    Customer::surnme = surnme;
}

const string &Customer::getPhone() const {
    return phone;
}

void Customer::setPhone(const string &phone) {
    Customer::phone = phone;
}

const string &Customer::getAddress() const {
    return address;
}

void Customer::setAddress(const string &address) {
    Customer::address = address;
}

bool Customer::operator<(const Customer &right) const &{
    return this->surnme<right.surnme;
}

void Customer::showCustomer() const {
    cout <<"ID: " << id <<". Client: " << name << " " << surnme << endl;
    cout <<"Contact phone: " << phone << endl;
    cout <<"Address: " << address << endl;
}

void Customer::setId(int id) {
    this->id=id;
}

int Customer::getId() const {
    return id;
}
