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

bool AddressBook::isUserLoggedin() {
    return userManager.isUserLoggedIn();
}

char AddressBook::selectOptionFromGeneralMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SupportiveMethods::readSign();
    return choice;
}

char AddressBook::selectOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = SupportiveMethods::readSign();
    return choice;
}
