#include <iostream>
#include "AddressBook.h"

using namespace std;

int main()
{
    AddressBook addressBook("Users.txt","Addresses.txt");
    addressBook.showAllUsers();
    //addressBook.userRegistration();
    addressBook.userLogging();
    //addressBook.changePasswordLoggedUser();
    addressBook.addNewAdrressee();
    addressBook.userLogout();
    addressBook.showAllUsers();


    return 0;
}
