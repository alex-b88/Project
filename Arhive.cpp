#include "Arhive.h"

Arhive::Arhive() {
    p_base.insert(new Book(2345,"Kobzar","Shevchenko T.","Ranok",2009));
    p_base.insert(new Book(2346,"My love","Franko I.","Folio",2006));
    p_base.insert(new Book(2347,"Mavka","Ykrainka L.","Ranok",2023));
    p_base.insert(new Book(2348,"Marusya","Vovchok M.","KSD",2021));
    p_base.insert(new Article(1221,"Harakteristika predprinimatelstva","Tkachenko Y.","C Arhive",632,2006));
    p_base.insert(new Article(1223,"USA absolyutnyj lider mirovogo farmrynka","Chencova M.","Economy",321,2007));
    p_base.insert(new Article(1224,"Aptechnyj rynok vitaminov","Pautova E.","Pharm",28,2008));
    p_base.insert(new Article(1225,"Proektirovanie sistem menedzhmenta kachestva","Taratuta M.","Economy",146,2005));
    p_base.insert(new Electronic(3917,"Zond NASA","Shvartc K.","http:\/\/unian.net","Uchenye nadeyutsya, chto issledovanie obrazcov prolet svet na to, kak zarodilas zhizn vo Vselennoj."));
    p_base.insert(new Electronic(3919,"Teleskop Uebba","Topchij A.","http:\/\/news.com","Novye rezultaty raskryvayut bolshe informacii o maloizvestnom sostave okeana Evropy pod korkoj tverdogo vodyanogo lda."));
    p_base.insert(new Electronic(3920,"New virus found","Sokolenko E.","http:\/\/bbc.com","On yavlyaetsya chastyu ranee neopoznannogo semejstva virusov."));
    p_base.insert(new Electronic(3921,"Na Solnce proizoshla moshnaya vspyshka","Limanskay E.","http://news.yahoo.com","Chast izlucheniya ot etoj vspyshki mozhet dostignut nashej planety."));

    clients.push_back(Customer(1,"Olena","Popova","0663442321","Gagarina 23"));
    clients.push_back(Customer(2,"Mariya","Nesterova","0635674312","Peremogy 11"));
    clients.push_back(Customer(3,"Oleg","Memirovsky","0930935219","Pushkina 45"));
    clients.push_back(Customer(4,"Dmitrij","Melihov","0675677321","Girshmana 81"));
    clients.push_back(Customer(5,"Victorya","Polupan","0996565743","Kashubi 6"));
}

Arhive::~Arhive() {
    for(auto item:p_base){
        delete item;
    }
}


void Arhive::ShowAllPublicatios() const {
    int menu;
    do {
        bool result = false;
        cout << "Show publications" << endl;
        cout << "1. All" << endl;
        cout << "2. Available" << endl;
        cout << "3. Currently using" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> menu;
        if(menu==0) result=true;
        for (auto item: p_base) {
            switch (menu) {
                case 1:{
                    item->show();
                   // cout << endl;
                    result=true;
                    break;
                }
                case 2:{
                    if(item->getAviable()){
                    item->show();
                    //cout << endl;
                    result=true;
                    }
                    break;
                }
                case 3:{
                    if(!item->getAviable()){
                        item->show();
                   // cout << endl;
                    result=true;
                    }
                    break;
                }
            } // end switch
        }
        if (!result)
            cout <<"Nothing found!" << endl;
    }while(menu!=0);
}

void Arhive::FindPublication() const {
    int menu;
    do{
        bool result =false;
        cout <<"1. Find by ISBN" << endl;
        cout <<"2. Find by author" << endl;
        cout <<"3. Find by title" << endl;
        cout <<"4. Find by type" << endl;
        cout <<"0. Exit" << endl;
        cout <<"Choice: ";
        cin >> menu;
        if(menu==0) result=true;
        switch (menu) {
            case 1:{
                int input;
                cout <<"Enter ISBN: ";
                cin >> input;
                for(auto item : p_base){
                    if(item->getIsbn()==input){
                        item->show();
                        //cout << endl;
                        result=true;
                    }
                }
                break;
            }
            case 2:{
                string input;
                cout <<"Enter author: ";
                cin >> ws;
                getline(cin,input);
                for(auto item:p_base){
                    if(item->getAuthor()==input){
                        item->show();
                        //cout << endl;
                        result=true;
                    }
                }
                break;
            }
            case 3:{
                string input;
                cout <<"Enter titile: ";
                cin >> ws;
                getline(cin,input);
                for(auto item:p_base){
                    if(item->getTitile()==input){
                        item->show();
                        //cout << endl;
                        result=true;
                    }
                }
                break;
            }
            case 4:{
                int input4;
                cout <<"1.Show all books" << endl;
                cout <<"2.Show all articles" << endl;
                cout <<"3.Show all webs" << endl;
                cout <<"Choice: ";
                cin >> input4;
                for(auto item:p_base){
                    switch(input4) {
                        case 1:{
                            if(item->getType()=="Book"){
                                item->show();
                                //cout << endl;
                                result=true;
                            }
                            break;
                        }
                        case 2:{
                            if(item->getType()=="Article"){
                                item->show();
                               // cout << endl;
                                result=true;
                            }
                            break;
                        }
                        case 3:{
                            if(item->getType()=="Electronic"){
                                item->show();
                                //cout << endl;
                                result=true;
                            }
                            break;
                        }
                    }
                }
                break;
            }
        }
    if (!result)
        cout <<"Nothing found!" << endl;
    } while(menu!=0);
}

void Arhive::addCustomer() {
    string t_name, t_surname,t_phone, t_address;
    cout <<"Adding a customer" << endl;
    cout <<"Enter name: ";
 //   cin >> ws;
    getline(cin, t_name);
    cout <<"Enter surname: ";
    getline(cin,t_surname);
    cout <<"Enter phone: ";
    getline(cin,t_phone);
    cout <<"Enter address: ";
    getline(cin, t_address);
    customer_id++;
    clients.push_back(Customer(customer_id,t_name,t_surname,t_phone,t_address));
    cout << "Client added successfully!" << endl;
}

void Arhive::showAllCustomers() const {
    if(clients.size()==0){
        cout <<"No clients in base!" << endl;
        return;
    }
    for (auto item : clients) {
        cout << item;
        cout << endl;
    }
}

void Arhive::makeSession() {
    int cus_id;
    bool check_client = false;
    cout <<"Enter client id: ";
    cin>> cus_id;
    for(auto item:clients)
    if(item.getId()==cus_id){
        check_client=true;
    //поиск и вставка публикации в клиента
        int publication_id;
        bool check_publication = false;
        int menu;
        do{
            cout << "1. Add publication" << endl;
            cout << "0. Exit" << endl;
            cout <<"Choice: ";
            cin >> menu;
            if(menu==1) {
                cout << "Enter ISBN: ";
                cin >> publication_id;
                for (auto it: p_base) {
                        if(it->getIsbn() == publication_id) {
                            if(!it->getAviable()){
                                cout <<"Publication isn't available!\n";
                                break;
                            }
                            check_publication = true;
                            item.addPublicationToCustomer(it);
                            it->setAviavle(false);
                            item.setInArhive(true);
                            cout << "Added to session" << endl;
                            break;
                        }
                }
                if(!check_publication) cout << "No publication found with this ISBN" << endl;
            }
        }while(menu!=0);
        orders[DT()].push_back(Customer(item));
        break;
    }
    if(!check_client)
        cout << "No client found"<< endl;
}

void Arhive::showCustomersInArhive() const {
    for(auto obj : orders){
        cout << obj.first << endl;
        for(auto obj2 : obj.second){
                obj2.showCustomer();
        }
    }
}
