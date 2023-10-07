#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt");
    addressBook.showAllUsers();
    //addressBook.userRegistration();
    addressBook.userLogging();
    addressBook.changePasswordLoggedUser();
    addressBook.userLogout();
    addressBook.showAllUsers();


    return 0;
}
