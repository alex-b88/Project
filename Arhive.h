#ifndef PROJECT_ARHIVE_H
#define PROJECT_ARHIVE_H


#include "Publication/Publication.h"
#include "Publication/Book/Book.h"
#include "Publication/Article/Article.h"
#include "Publication/Electronic/Electronic.h"
#include "Customer.h"
#include "DateTime/DT.h"
#include "set"
#include "algorithm"
#include "vector"
#include "map"

class Arhive {
protected:
    multiset<Publication*> p_base;
    vector<Customer> clients;
    multimap<Customer, Publication*> orders;

public:
    Arhive();
    ~Arhive();
    void addCustomer();
    void showAllCustomers()const;
    void FindPublication()const;
    void ShowAllPublicatios()const;
};

#endif //PROJECT_ARHIVE_H
