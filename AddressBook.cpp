#include "AddressBook.h"

void AddressBook::userRegistration() {
    userManager.userRegistration();
}

void AddressBook::showAllUsers() {
    userManager.showAllUsers();
}

void AddressBook::userLogging() {
    userManager.userLogging();
    if (userManager.isUserLoggedIn()) {
        addresseeManager = new AddresseeManager(FILE_NAME_WITH_ADDRESSES,userManager.getidLoggedUser());
    }
}

void AddressBook::changePasswordLoggedUser() {
    userManager.changePasswordLoggedUser();
}

void AddressBook::userLogout() {
    userManager.userLogout();
    delete addresseeManager;
    addresseeManager = NULL;

}
void AddressBook::addNewAdrressee() {
    if (userManager.isUserLoggedIn()) {
        addresseeManager->addNewAddressee();
    } else {
        cout << "Aby dodac adresata, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}

void AddressBook::showUserAddresses() {
    if (userManager.isUserLoggedIn()) {
        addresseeManager->showUserAddresses();
    }  else {
        cout << "Aby wyswietlic adresatow, nalezy sie najpierw zalogowac" << endl;
        system("pause");
    }
}
