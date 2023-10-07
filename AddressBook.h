#include <iostream>
#include "UserManager.h"

using namespace std;

class AddressBook {

    UserManager userManager;


public:
    AddressBook(string fileNameWithUsers) : userManager(fileNameWithUsers) {
        userManager.readUsersFromFile();
    };
    void userRegistration();
    void userLogging();
    void changePasswordLoggedUser();
    void userLogout();
    void showAllUsers();
};
