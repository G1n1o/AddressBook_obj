#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <filesystem>
#include "Addressee.h"
#include "SupportiveMethods.h"
#include "TextFile.h"


using namespace std;

class FileWithAddressesData : public TextFile {
    int idLastAddressee;

    string replaceDataAddresseeOnLinesSeparatedVerticalDashes(Addressee addressee);
    int getIdFromDataSeparatedByVerticalDashes(string singleAddresseeDataSeparatedbyVerticalDashes);
    int getIdUserFromDataSeparatedByVerticalDashes(string singleAddresseeDataSeparatedbyVerticalDashes);
    Addressee getAddresseeData(string addresseeDataSeparatedbyVerticalDashes);
    void removeLastEmptyLine();


public:
    FileWithAddressesData(string fileNameWithAddresses) : TextFile(fileNameWithAddresses) {
        idLastAddressee = 0;
    };
    void saveChangesAddresseeInFile(Addressee addressee);
    void saveRemovesAddresseeInFile(Addressee addressee);
    int getIdLastAddressee();
    bool addAddresseeToFile(Addressee addressee);
    vector <Addressee> loadAddressesLoggedUserFile(int idLoggedUser);

};
