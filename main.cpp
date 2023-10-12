#include "Menus/Menu.h"
#include "Arhive.h"

int Arhive::customer_id=5;

int main() {
   Arhive m;
    int main_menu;
    do{
        Menu::MainMenu();
        cin >> main_menu;
        switch(main_menu){
            case 1:{
                m.addCustomer();
                break;
            }
            case 2:{
                m.delCustomer();
                break;
            }
            case 3:{
                m.showAllCustomers();
                break;
            }
            case 4:{
                m.addPublication();
                break;
            }
            case 5:{
                m.FindPublication();
                break;
            }
            case 6:{
                m.ShowAllPublicatios();
                break;
            }
            case 7:{
                m.makeSession();
                break;
            }
            case 8:{
                m.delSession();
                break;
            }
            case 9:{
                m.showCustomersInArhive();
                break;
            }
        }
    }while(main_menu!=0);

    return 0;
}
