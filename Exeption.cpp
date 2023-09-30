
#include "Exeption.h"

string NameExeption::showMessage() const {
    return "The field can't be empty";
}

string MenuExeption::showMessage() const {
    return "The choice must be numerical";
}

string IntExeption::showMessage() const {
    return "The choice must be numerical";
}
