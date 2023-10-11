#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Addressee.h"
#include "SupportiveMethods.h"

using namespace std;

class FileWithAddressesData {
    const string FILE_NAME_WITH_ADDRESSES;
    int idLastAddressee;

    string replaceDataAddresseeOnLinesSeparatedVerticalDashes(Addressee addressee);
    bool isFileEmpty(fstream &textFile);
    int getIdFromDataSeparatedByVerticalDashes(string singleAddresseeDataSeparatedbyVerticalDashes);
    int getIdUserFromDataSeparatedByVerticalDashes(string singleAddresseeDataSeparatedbyVerticalDashes);
    Addressee getAddresseeData(string addresseeDataSeparatedbyVerticalDashes);

public:
    FileWithAddressesData(string fileNameWithAddresses) : FILE_NAME_WITH_ADDRESSES(fileNameWithAddresses) {
        idLastAddressee = 0;
    };
    int getIdLastAddressee();
    void addAddresseeToFile(Addressee addressee);
    void loadAddressesLoggedUserFile(vector <Addressee> &addresses, int idLoggedUser);

};
