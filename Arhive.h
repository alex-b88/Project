#ifndef Project_ARHIVE_H
#define Project_ARHIVE_H

#include "Customer.h"

struct compareOublication{
    bool operator()(const Publication* left, const Publication*right)const{
        if(left->getType()<right->getType())
            return true;
        else if(left->getType()==right->getType())
            return left->getIsbn()<right->getIsbn();
        else{
            return false;
        }
    }
};

class Arhive {
protected:
    static int customer_id;
    vector<Customer> clients;
    map<DT, vector<Customer>> orders;
    multiset<Publication*,compareOublication> p_base;

public:
    Arhive();
    ~Arhive();
    void addCustomer();
    void showAllCustomers()const;
    void FindPublication()const;
    void ShowAllPublicatios()const;
    void makeSession();
    void showCustomersInArhive()const;
    //TODO создать удаление сессии
};


#endif //Project_ARHIVE_H
