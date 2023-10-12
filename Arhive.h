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
    vector<Customer> clients; //клиенты
    multiset<Publication*,compareOublication> p_base; //база публикаций
    map<DT, vector<Customer>> orders; // активные сессии клиентов

public:
    Arhive();
    ~Arhive();
    void addCustomer();
    void delCustomer();
    void showAllCustomers()const;
    void addPublication();
    void FindPublication()const;
    void ShowAllPublicatios()const;
    void makeSession();
    void showCustomersInArhive()const;
    void delSession();
    bool CheckIfExistISBN(int x);
};


#endif //Project_ARHIVE_H
