#include "AddresseeManager.h"


void AddresseeManager::addNewAddressee() {
    Addressee addressee;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    addressee = enterDataNewAddress();

    addresses.push_back(addressee);
    fileWithAddressesData.addAddresseeToFile(addressee);
}

Addressee AddresseeManager::enterDataNewAddress() {
    Addressee addressee;

    addressee.setId(fileWithAddressesData.getIdLastAddressee()+1);
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
   fileWithAddressesData.loadAddressesLoggedUserFile(addresses,idLoggedUser);
}
 void AddresseeManager::showUserAddresses(){
    system("cls");
    if (!addresses.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Addressee> :: iterator itr = addresses.begin(); itr != addresses.end(); itr++)
        {
            showAddresseeData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AddresseeManager::showAddresseeData(Addressee addressee)
{
    cout << endl << "Id:                 " << addressee.getId() << endl;
    cout << "Imie:               " << addressee.getName() << endl;
    cout << "Nazwisko:           " << addressee.getSurname() << endl;
    cout << "Numer telefonu:     " << addressee.getPhoneNumber() << endl;
    cout << "Email:              " << addressee.getEmail() << endl;
    cout << "Adres:              " << addressee.getAddress() << endl;
}
