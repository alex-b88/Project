#include "Arhive.h"

int Arhive::customer_id=5;

int main() {
   Arhive m;
/*    TextBook tb(1234,"Math","Bevz","Ranok",2002,9);
    tb.show();*/
 //   m.FindPublication();
   //m.showAllCustomers();
 //   cout << (m.search(3920));

    /*Customer c(1,"Olena","Popova","0663442321","Gagarina 23");
    c.addPublicationToCustomer(new Book(2346,"My love","Franko I.","Folio",2006));
    c.addPublicationToCustomer(new Book(2148,"Marusya","Vovchok M.","KSD",2021));
    c.addPublicationToCustomer(new Article(1221,"Harakteristika predprinimatelstva","Tkachenko Y.","C Arhive",632,2006));
    c.addPublicationToCustomer(new Electronic(3919,"Teleskop Uebba","Topchij A.","http:\/\/news.com","Novye rezultaty raskryvayut bolshe informacii o maloizvestnom sostave okeana Evropy pod korkoj tverdogo vodyanogo lda."));
    c.showPublicationInUse();*/

//    m.ShowAllPublicatios();
    m.makeSession();
    m.makeSession();
    m.showCustomersInArhive();
    m.delSession();
    m.showCustomersInArhive();
    m.ShowAllPublicatios();

/*    Customer c1(10,"Victorya","Polupan","0996565743","Kashubi 6");
    Publication* p1 = new Book(2345,"Kobzar","Shevchenko T.","Ranok",2009);
    Publication* p2 = new Book(2348,"Marusya","Vovchok M.","KSD",2021);
    c1.addPublicationToCustomer(p1);
    c1.addPublicationToCustomer(p2);
    c1.showPublicationInUse();
    c1.ReturnAllEditions();
    c1.showPublicationInUse();*/

 //   m.FindPublication();

    return 0;
}
