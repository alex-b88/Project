#ifndef T28_HW_ARHIVE_H
#define T28_HW_ARHIVE_H

#include "Customer.h"

class Arhive {
protected:
    static int customer_id;
    vector<Customer> clients;
    map<DT, vector<Customer>> orders;
    multiset<Publication*> p_base;

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


#endif //T28_HW_ARHIVE_H
