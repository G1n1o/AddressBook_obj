#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "FileWithAddressesData.h"
#include "Addressee.h"

using namespace std;

class AddresseeManager {
    const int ID_LOGGED_USER;
    vector <Addressee> addresses;
    FileWithAddressesData fileWithAddressesData;

    Addressee enterDataNewAddress();
    void showAddresseeData(Addressee addressee);


public:
    AddresseeManager(string fileNameWithAddresses, int idLoggedUser)
    : fileWithAddressesData(fileNameWithAddresses), ID_LOGGED_USER(idLoggedUser) {
    addresses = fileWithAddressesData.loadAddressesLoggedUserFile(ID_LOGGED_USER);
    };
    //int setIdLoggedUser(int newIdLoggedUser);
    void addNewAddressee();
    //void userLogout();
    //void loadAddressesLoggedUserFile();
    void showUserAddresses();

};
