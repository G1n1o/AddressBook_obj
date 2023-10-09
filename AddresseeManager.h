#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "FileWithAddressesData.h"
#include "Addressee.h"

using namespace std;

class AddresseeManager {
    int idLoggedUser;
    int idLastAddressee;

    vector <Addressee> addresses;
    FileWithAddressesData fileWithAddressesData;
    Addressee enterDataNewAddress();


public:
    AddresseeManager(string fileNameWithAddresses) : fileWithAddressesData(fileNameWithAddresses) {};
    int setIdLoggedUser(int newIdLoggedUser);
    int addNewAddressee();
    void userLogout();
    void loadAddressesLoggedUserFile();

};
