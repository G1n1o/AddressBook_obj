#include "AddresseeManager.h"


int AddresseeManager::addNewAddressee() {
    Addressee addressee;

    //cout <<idLastAddressee<<endl;
   // system("pause");

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    addressee = enterDataNewAddress();

    addresses.push_back(addressee);
    fileWithAddressesData.addAddresseeToFile(addressee);

    return ++idLastAddressee;
}

Addressee AddresseeManager::enterDataNewAddress() {
    Addressee addressee;

    addressee.setId(++idLastAddressee);
    addressee.setIdUser(idLoggedUser);

    cout << "Podaj imie: ";
    addressee.setName(SupportiveMethods::readLine());
    addressee.setName(SupportiveMethods::swapFirstLetterForLargeOtherForSmall(addressee.getName()));

    cout << "Podaj nazwisko: ";
    addressee.setSurname(SupportiveMethods::readLine());
    addressee.setSurname(SupportiveMethods::swapFirstLetterForLargeOtherForSmall(addressee.getSurname()));

    cout << "Podaj numer telefonu: ";
    addressee.setPhoneNumber(SupportiveMethods::readLine());

    cout << "Podaj email: ";
    addressee.setEmail(SupportiveMethods::readLine());

    cout << "Podaj adres: ";
    addressee.setAddress(SupportiveMethods::readLine());

    return addressee;
}
int AddresseeManager::setIdLoggedUser(int newIdLoggedUser) {
    idLoggedUser = newIdLoggedUser;
    return idLoggedUser;
}

void AddresseeManager::userLogout() {
    idLoggedUser = 0;
    addresses.clear();
}

void AddresseeManager::loadAddressesLoggedUserFile() {
    idLastAddressee = fileWithAddressesData.loadAddressesLoggedUserFile(addresses,idLoggedUser);
    cout <<idLastAddressee<<endl;
    system("pause");
}

