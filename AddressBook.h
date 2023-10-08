#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <iostream>
#include "UserManager.h"
#include "AddresseeManager.h"

using namespace std;

class AddressBook {

    UserManager userManager;
    AddresseeManager addresseeManager;


public:
    AddressBook(string fileNameWithUsers, string fileNameWithAddresses)
    : userManager(fileNameWithUsers), addresseeManager(fileNameWithAddresses) {
        userManager.readUsersFromFile();
    };
    void userRegistration();
    void userLogging();
    void changePasswordLoggedUser();
    void addNewAdrressee();
    void userLogout();
    void showAllUsers();
};

#endif
