#include "Arhive.h"

int Arhive::customer_id=5;

int main() {
    Arhive m;
 //   m.FindPublication();
   //m.showAllCustomers();
 //   cout << (m.search(3920));

    /*Customer c(1,"Olena","Popova","0663442321","Gagarina 23");
    c.addPublicationToCustomer(new Book(2346,"My love","Franko I.","Folio",2006));
    c.addPublicationToCustomer(new Book(2148,"Marusya","Vovchok M.","KSD",2021));
    c.addPublicationToCustomer(new Article(1221,"Harakteristika predprinimatelstva","Tkachenko Y.","C Arhive",632,2006));
    c.addPublicationToCustomer(new Electronic(3919,"Teleskop Uebba","Topchij A.","http:\/\/news.com","Novye rezultaty raskryvayut bolshe informacii o maloizvestnom sostave okeana Evropy pod korkoj tverdogo vodyanogo lda."));
    c.showPublicationInUse();*/

    m.ShowAllPublicatios();
/*    m.showAllCustomers();
    m.makeSession();
    m.makeSession();
    m.showCustomersInArhive();
    m.FindPublication();*/

    return 0;
}
