#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include "UserManager.h"
#include "AddresseeManager.h"

using namespace std;

class AddressBook {

    UserManager userManager;
    AddresseeManager *addresseeManager;
    const string FILE_NAME_WITH_ADDRESSES;

public:
    AddressBook(string fileNameWithUsers, string fileNameWithAddresses)
        : userManager(fileNameWithUsers), FILE_NAME_WITH_ADDRESSES(fileNameWithAddresses) {
        addresseeManager = NULL;
    };
    ~AddressBook() {
        delete addresseeManager;
        addresseeManager = NULL;
    }

    void userRegistration();
    void userLogging();
    void changePasswordLoggedUser();
    void addNewAdrressee();
    void showUserAddresses();
    void userLogout();
    bool isUserLoggedin();
    void showAllUsers();
    char selectOptionFromGeneralMenu();
    char selectOptionFromUserMenu();
};

#endif
