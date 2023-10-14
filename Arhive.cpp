#include "Arhive.h"

Arhive::Arhive() {
    Arhive::loadClientsFromFile();
    Arhive::loadPublicationFromFile();
    /*
    p_base.insert(new Book(2345,"Kobzar","Shevchenko T.","Ranok",2009));
    p_base.insert(new Book(2346,"My love","Franko I.","Folio",2006));
    p_base.insert(new Book(2347,"Mavka","Ykrainka L.","Ranok",2023));
    p_base.insert(new Book(2348,"Marusya","Vovchok M.","KSD",2021));
    p_base.insert(new Article(1221,"Harakteristika predprinimatelstva","Tkachenko Y.","C Arhive",632,2006));
    p_base.insert(new Article(1223,"USA absolyutnyj lider mirovogo farmrynka","Chencova M.","Economy",321,2007));
    p_base.insert(new Article(1224,"Aptechnyj rynok vitaminov","Pautova E.","Pharm",28,2008));
    p_base.insert(new Article(3924,"Proektirovanie sistem menedzhmenta kachestva","Taratuta M.","Economy",146,2005));
    p_base.insert(new Electronic(3917,"Zond NASA","Shvartc K.","http:\/\/unian.net","Uchenye nadeyutsya, chto issledovanie obrazcov prolet svet na to, kak zarodilas zhizn vo Vselennoj."));
    p_base.insert(new Electronic(1225,"Teleskop Uebba","Topchij A.","http:\/\/news.com","Novye rezultaty raskryvayut bolshe informacii o maloizvestnom sostave okeana Evropy pod korkoj tverdogo vodyanogo lda."));
    p_base.insert(new Electronic(3920,"New virus found","Sokolenko E.","http:\/\/bbc.com","On yavlyaetsya chastyu ranee neopoznannogo semejstva virusov."));
    p_base.insert(new Electronic(3921,"Na Solnce proizoshla moshnaya vspyshka","Limanskay E.","http://news.yahoo.com","Chast izlucheniya ot etoj vspyshki mozhet dostignut nashej planety."));


    clients.push_back(Customer(1,"Olena","Popova","0663442321","Gagarina 23"));
    clients.push_back(Customer(2,"Mariya","Nesterova","0635674312","Peremogy 11"));
    clients.push_back(Customer(3,"Oleg","Memirovsky","0930935219","Pushkina 45"));
    clients.push_back(Customer(4,"Dmitrij","Melihov","0675677321","Girshmana 81"));
    clients.push_back(Customer(5,"Victorya","Polupan","0996565743","Kashubi 6"));
*/
}

Arhive::~Arhive() {
    Arhive::saveClientsToFile();
    Arhive::savePublicationToFile();
    for(auto item:p_base){
        delete item;
    }
}

void Arhive::addPublication() {
    int add_menu;
    do{
        Menu::addPiblication();
        cin >> add_menu;
        switch(add_menu){
            case 1:{
                int isbn,year;
                string title,author,publication;
                cout <<"=Adding a book="<< endl;
                cout <<"Enter isbn: ";
                cin >> isbn;
                if(CheckIfExistISBN(isbn)){
                    cout << "This ISBN is already exist" << endl;
                    break;
                }
                cout << "Enter title: ";
                cin >> ws;
                getline(cin,title);
                cout <<"Enter author: ";
                getline(cin,author);
                cout <<"Enter publication: ";
                getline(cin,publication);
                cout <<"Enter year: ";
                cin >> year;
                p_base.insert(new Book(isbn,title,author,publication,year));
                cout << "Book added!" << endl;
                break;
            }
            case 2:{
                cout <<"=Adding an article="<< endl;
                int isbn,number,year;
                string title,author,m_name;
                cout <<"Enter isbn: ";
                cin >> isbn;
                if(CheckIfExistISBN(isbn)){
                    cout << "This ISBN is already exist" << endl;
                    break;
                }
                cout << "Enter title: ";
                cin >> ws;
                getline(cin,title);
                cout <<"Enter author: ";
                getline(cin,author);
                cout <<"Enter magazine: ";
                getline(cin,m_name);
                cout <<"Enter number: ";
                cin >> number;
                cout <<"Enter year: ";
                cin >> year;
                p_base.insert(new Article(isbn,title,author,m_name,number,year));
                cout << "Article added!" << endl;
                break;
            }
            case 3:{
                cout <<"=Adding an electronic="<< endl;
                int isbn;
                string title,author,link, anotation;
                cout <<"Enter isbn: ";
                cin >> isbn;
                if(CheckIfExistISBN(isbn)){
                    cout << "This ISBN is already exist" << endl;
                    break;
                }
                cout << "Enter title: ";
                cin >> ws;
                getline(cin,title);
                cout <<"Enter author: ";
                getline(cin,author);
                cout <<"Enter link: ";
                getline(cin,link);
                cout <<"Enter annotation: ";
                getline(cin,anotation);
                p_base.insert(new Electronic(isbn,title,author,link,anotation));
                cout << "Electronic added!" << endl;
                break;
            }
        }
    }while(add_menu!=0);
}

void Arhive::ShowAllPublicatios() const {
    int menu;
    do {
        bool result = false;
        Menu::showPublications();
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
        Menu::showArhiveFindPublication();
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
                Menu::ArhiveFindPublication_show_by_type();
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
    cin >> ws;
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

void Arhive::delCustomer() {
    int t_id;
    cout <<"=Deleting the customer=" << endl;
    cout <<"Enter customer's id: ";
    cin >> t_id;
    for (int i = 0; i < clients.size(); ++i) {
        if(clients[i].getId()==t_id){
            clients.erase(clients.begin()+i);
            cout << "The client was removed!" << endl;
            return;
        }
    }
    cout <<"No client found with id:\"" << t_id <<"\" in base!" << endl;
}

void Arhive::showAllCustomers() const {
    if(clients.begin()==clients.end()){
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
    bool isAdded=false;
    cout <<"=Adding a session to the archive=" << endl;
    cout <<"Enter client id: ";
    cin>> cus_id;
    for(auto item:clients)
    if(item.getId()==cus_id){
        check_client=true;
    //поиск и вставка публикации в клиента
        int publication_id;
        int menu;
        do{
            bool check_publication = false;
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
                            else {
                            check_publication = true;
                            item.addPublicationToCustomer(it);
                            it->setAviavle(false);
                            item.setInArhive(true);
                            cout << "Added to session" << endl;
                            isAdded = true;
                            break;
                            }
                        }
                }
                if(!check_publication) cout << "No publication found with this ISBN" << endl;
            }
        }while(menu!=0);
        if(isAdded){
            orders[DT()].push_back(item);
            cout <<"Session made successfully!" << endl;
            break;
        }
    }
    if(!check_client)
        cout << "No client found"<< endl;
}

void Arhive::showCustomersInArhive() const {
    if(orders.begin()==orders.end()){
        cout <<"No clients in archive" << endl;
        return;
    }
    for(auto obj : orders){
        cout << obj.first << endl;
        for(auto obj2 : obj.second){
                obj2.showCustomer();
        }
    }
}

void Arhive::delSession() {
    int cus_id;
    bool check_client = false;
    cout <<"=Closing the session in archive=" << endl;
    cout <<"Enter client id: ";
    cin>> cus_id;
    for(auto obj=orders.begin(); obj!=orders.end(); ++obj){
        for(auto obj2 : obj->second){
            if(obj2.getId()==cus_id){
                check_client = true;
                obj2.ReturnAllEditions();
                obj2.setInArhive(false);
                orders.erase(obj);
                cout <<"Session closed successfully!" << endl;
                return;
            }
        }
    }
    if(!check_client){
        cout <<"No client is in the archive with this id!" << endl;
        return;
    }
}

bool Arhive::CheckIfExistISBN(int x) {
    for(auto it:p_base){
        if(it->getIsbn()==x)
            return true;
    }
    return false;
}

void Arhive::saveClientsToFile() {
    if(clients.begin()==clients.end())
        return;
    ofstream file("Clients.txt");
    if(file.is_open()){
        for (int i = 0; i < clients.size(); ++i) {
            file << clients[i].getId() << endl;
            file << clients[i].getName() << endl;
            file << clients[i].getSurnme() << endl;
            file << clients[i].getPhone() << endl;
            file << clients[i].getAddress() << endl;
        }
        cout << "Clients saved to file" << endl;
        file.close();
    }
}

void Arhive::loadClientsFromFile() {
    ifstream file("Clients.txt");
    if(!file.is_open()){
        cout <<"File with clients not found!" << endl;
        return;
    }
    int id;
    string name,surname,phone,address;
    while (file >> id) {
        file.get();
        getline(file, name);
        getline(file, surname);
        getline(file, phone);
        getline(file, address);
        clients.push_back(Customer(id, name, surname, phone, address));
    }
    file.close();
}

void Arhive::savePublicationToFile() {
    if(p_base.begin()==p_base.end())
        return;
    ofstream file("Publications.txt");
    if(!file.is_open())
        return;
    for(auto item : p_base)
    {
        file << item->getIsbn() << endl;
        file << item->getType() << endl;
        file << item->getTitile() << endl;
        file << item->getAuthor() << endl;
        if(item->getType()=="Article"){
            file << item->getMagazine_name() << endl;
            file << item->geNumber() << endl;
            file << item->getYear() << endl;
        }
        else if(item->getType()=="Book"){
            file << item->getPublications() << endl;
            file << item->getYear() << endl;
        }
        else if(item->getType()=="Electronic"){
            file << item->getLink() << endl;
            file << item->getAnotation() << endl;
            //file << ((Electronic*)item)->getLink();
        }
    }
    file.close();
}

void Arhive::loadPublicationFromFile() {
    ifstream file("Publications.txt");
    if(!file.is_open()){
        cout <<"File with publication not find" << endl;
        return;
    }
    int id;
    string title,author,type;
    while(file >> id){
        file.get();
        getline(file,type);
        getline(file,title);
        getline(file,author);
        if(type=="Article"){
            int number, year;
            string mag_name;
            getline(file,mag_name);
            file >> number;
            file >> year;
            p_base.insert(new Article(id,title,author,mag_name,number,year));
        }
        else if(type=="Book"){
            string publication;
            int year;
            getline(file,publication);
            file >> year;
            p_base.insert(new Book(id,title,author,publication,year));
        }
        else if(type=="Electronic"){
            string link,annotation;
            getline(file,link);
            getline(file,annotation);
            p_base.insert(new Electronic(id,title,author,link,annotation));
        }
    }
    file.close();
}

void Arhive::saveHistory() {
    ofstream file("Hostory.txt", ios::app);
    if(!file.is_open()){
        cout <<"History file not found" << endl;
        return;
    }
/*    for(auto it : orders){
        file << it.first.to_String();
    }*/ // TODO доделать

}
