#include <iostream>
#include "AddressBook.h"

using namespace std;

int main() {
    AddressBook addressBook("Users.txt","Addresses.txt");
    char choice;

    while (true) {
        if (!addressBook.isUserLoggedin()) {
            choice = addressBook.selectOptionFromGeneralMenu();

            switch (choice) {
            case '1':
                addressBook.userRegistration();
                break;
            case '2':
                addressBook.userLogging();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {

            choice = addressBook.selectOptionFromUserMenu();

            switch (choice) {
            case '1':
                addressBook.addNewAdrressee();
                break;
            case '2':

                break;
            case '3':

                break;
            case '4':
                addressBook.showUserAddresses();
                break;
            case '5':

                break;
            case '6':

                break;
            case '7':
                addressBook.changePasswordLoggedUser();
                break;
            case '8':
                addressBook.userLogout();
                break;
            }
        }
    }
    return 0;
}


