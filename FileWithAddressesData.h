#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Addressee.h"
#include "SupportiveMethods.h"

using namespace std;

class FileWithAddressesData {
    const string fileNameWithAddresses;

    string replaceDataAddresseeOnLinesSeparatedVerticalDashes(Addressee addressee);
    bool isFileEmpty(fstream &textFile);
    int getIdFromDataSeparatedByVerticalDashes(string singleAddresseeDataSeparatedbyVerticalDashes);
    int getIdUserFromDataSeparatedByVerticalDashes(string singleAddresseeDataSeparatedbyVerticalDashes);
    Addressee getAddresseeData(string addresseeDataSeparatedbyVerticalDashes);

    public:
    FileWithAddressesData(string FILENAMEWITHADDRESSES) : fileNameWithAddresses(FILENAMEWITHADDRESSES){};
    void addAddresseeToFile(Addressee addressee);
    int loadAddressesLoggedUserFile(vector <Addressee> &addresses, int idLoggedUser);

};
