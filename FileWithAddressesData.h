#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <filesystem>
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
    void removeLastEmptyLine();


public:
    FileWithAddressesData(string fileNameWithAddresses) : FILE_NAME_WITH_ADDRESSES(fileNameWithAddresses) {
        idLastAddressee = 0;
    };
    void saveChangesAddresseeInFile(Addressee addressee);
    void saveRemovesAddresseeInFile(Addressee addressee);
    int getIdLastAddressee();
    bool addAddresseeToFile(Addressee addressee);
    vector <Addressee> loadAddressesLoggedUserFile(int idLoggedUser);

};
