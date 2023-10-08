
#include "Customer.h"

Customer::Customer(const int &id,const string &name, const string &surnme, const string &phone, const string &address)
:id(id), name(name), surnme(surnme), phone(phone), address(address) {
    inArhive = false;
}

const string &Customer::getName() const {
    return name;
}

void Customer::setName(const string &name) {
    if(name.size()<=0)
        throw new NameExeption;
    Customer::name = name;
}

const string &Customer::getSurnme() const {
    return surnme;
}

void Customer::setSurnme(const string &surnme) {
    if(surnme.size()<=0)
        throw new NameExeption;
    Customer::surnme = surnme;
}

const string &Customer::getPhone() const {
    return phone;
}

void Customer::setPhone(const string &phone) {
    if(phone.size()<=0)
        throw new NameExeption;
    Customer::phone = phone;
}

const string &Customer::getAddress() const {
    return address;
}

void Customer::setAddress(const string &address) {
    if(address.size()<=0)
        throw new NameExeption;
    Customer::address = address;
}

bool Customer::operator<(const Customer &right) const &{
    return this->surnme<right.surnme;
}

void Customer::showCustomer() const {
    cout <<"ID: " << id <<". Client: " << name << " " << surnme <<". Contact phone: " << phone << endl;
    showPublicationInUse();
}

void Customer::setId(int id) {
    this->id=id;
}

int Customer::getId() const {
    return id;
}

std::ostream& operator<<(std::ostream& os, const Customer& cus){
    os <<"ID: " << cus.id <<". Client: " << cus.name << " " << cus.surnme << endl;
    os <<"Contact phone: " << cus.phone << endl;
    os <<"Address: " << cus.address << endl;
    return os;
}

void Customer::addPublicationToCustomer(Publication *obj) {
    use_publications.insert(obj);
}

void Customer::showPublicationInUse() const {
    for(auto item : use_publications){
        item->show();
       // cout << endl;
    }
}

void Customer::setInArhive(bool status) {
    this->inArhive=status;
}

void Customer::ReturnEdition(int isbn) {
    for(auto item:use_publications){
        if (item->getIsbn()==isbn){
            use_publications.erase(item);
            item->setAviavle(true);
        }
    }
}//TODO проверить как работает