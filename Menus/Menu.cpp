#include "Menu.h"

void Menu::showArhiveFindPublication() {
    cout <<"1. Find by ISBN" << endl;
    cout <<"2. Find by author" << endl;
    cout <<"3. Find by title" << endl;
    cout <<"4. Find by type" << endl;
    cout <<"0. Exit" << endl;
    cout <<"Choice: ";
}

void Menu::ArhiveFindPublication_show_by_type() {
    cout <<"1.Show all books" << endl;
    cout <<"2.Show all articles" << endl;
    cout <<"3.Show all webs" << endl;
    cout <<"Choice: ";
}

void Menu::showPublications() {
    cout << "Show publications" << endl;
    cout << "1. All" << endl;
    cout << "2. Available" << endl;
    cout << "3. Currently using" << endl;
    cout << "0. Exit" << endl;
    cout << "Choice: ";
}

void Menu::MainMenu() {
    cout << "1. Add client" << endl;
    cout << "2. Del client" << endl;
    cout << "3. Show all clients" << endl;
    cout << "4. Add publication" << endl;
    cout << "5. Find a publication" << endl;
    cout << "6. Show publications" << endl;
    cout << "7. Make a session" << endl;
    cout << "8. Close the session" << endl;
    cout << "9. Show clients in the archive" << endl;
    cout << "0. Exit" << endl;
    cout <<"Choice: ";
}
void Menu::addPiblication() {
    cout << "1. Book" << endl;
    cout << "2. Article" << endl;
    cout << "3. Electronic" << endl;
    cout << "0. Exit" << endl;
    cout <<"Choice: ";
}