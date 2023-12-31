#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "FileWithAddressesData.h"
#include "Addressee.h"

using namespace std;

class AddresseeManager {
    FileWithAddressesData fileWithAddressesData;
    const int ID_LOGGED_USER;
    vector <Addressee> addresses;

    Addressee enterDataNewAddress();
    void showAddresseeData(Addressee addressee);
    void displayNumberofSelectedAddresses(int numberAddressers);
    int enterIdSelectedAddress();
    char selectOptionsMenuEdit();


public:
    AddresseeManager(string fileNameWithAddresses, int idLoggedUser)
        : fileWithAddressesData(fileNameWithAddresses), ID_LOGGED_USER(idLoggedUser) {
        addresses = fileWithAddressesData.loadAddressesLoggedUserFile(ID_LOGGED_USER);
    };

    void addNewAddressee();
    void showUserAddresses();
    void searchByName();
    void searchBySurname();
    void editAddressee();
    void removeAddressee();

};
