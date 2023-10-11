#include "FileWithAddressesData.h"

bool FileWithAddressesData::addAddresseeToFile(Addressee addressee) {
    string lineWithUserData = "";
    fstream textFile;
    textFile.open(FILE_NAME_WITH_ADDRESSES.c_str(), ios::out | ios::app);

    if (textFile.good() == true) {
        lineWithUserData = replaceDataAddresseeOnLinesSeparatedVerticalDashes(addressee);

        if (isFileEmpty(textFile) == true) {
            textFile << lineWithUserData;
        } else {
            textFile << endl << lineWithUserData ;
        }
        idLastAddressee++;
        textFile.close();
        return true;
    }
    return false;
}

string FileWithAddressesData::replaceDataAddresseeOnLinesSeparatedVerticalDashes(Addressee addressee) {
    string lineWithAddresseeData = "";

    lineWithAddresseeData += SupportiveMethods::convertFromIntToString(addressee.getId()) + '|';
    lineWithAddresseeData += SupportiveMethods::convertFromIntToString(addressee.getIdUser()) + '|';
    lineWithAddresseeData += addressee.getName() + '|';
    lineWithAddresseeData += addressee.getSurname() + '|';
    lineWithAddresseeData += addressee.getPhoneNumber() + '|';
    lineWithAddresseeData += addressee.getEmail() + '|';
    lineWithAddresseeData += addressee.getAddress() + '|';

    return lineWithAddresseeData;
}

bool FileWithAddressesData::isFileEmpty(fstream &textFile) {
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

vector <Addressee> FileWithAddressesData::loadAddressesLoggedUserFile(int idLoggedUser) {
    vector <Addressee> addresses;
    Addressee addressee;
    string singleAddresseeDataSeparatedbyVerticalDashes = "";
    string dataLastAddresseeInFile = "";
    fstream textFile;
    textFile.open(FILE_NAME_WITH_ADDRESSES.c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, singleAddresseeDataSeparatedbyVerticalDashes)) {
            if(idLoggedUser == getIdUserFromDataSeparatedByVerticalDashes(singleAddresseeDataSeparatedbyVerticalDashes)) {
                addressee = getAddresseeData(singleAddresseeDataSeparatedbyVerticalDashes);
                addresses.push_back(addressee);
            }
        }
        dataLastAddresseeInFile = singleAddresseeDataSeparatedbyVerticalDashes;
        textFile.close();
    } else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;

    if (dataLastAddresseeInFile != "") {
        idLastAddressee = getIdFromDataSeparatedByVerticalDashes(dataLastAddresseeInFile);
    }
    return addresses;
}

int FileWithAddressesData::getIdFromDataSeparatedByVerticalDashes(string singleAddresseeDataSeparatedbyVerticalDashes) {
    int startPositionIdAddressee = 0;
    int id = SupportiveMethods::convertFromStringToInt(SupportiveMethods::getNumber(singleAddresseeDataSeparatedbyVerticalDashes, startPositionIdAddressee));
    return id;
}
int FileWithAddressesData::getIdUserFromDataSeparatedByVerticalDashes(string singleAddresseeDataSeparatedbyVerticalDashes) {
    int startPositionIdUser = singleAddresseeDataSeparatedbyVerticalDashes.find_first_of('|') + 1;
    int idUser = SupportiveMethods::convertFromStringToInt(SupportiveMethods::getNumber(singleAddresseeDataSeparatedbyVerticalDashes, startPositionIdUser));

    return idUser;
}


Addressee FileWithAddressesData::getAddresseeData(string addresseeDataSeparatedbyVerticalDashes) {
    Addressee addressee;
    string singleAddresseeData = "";
    int numberOfSingleAddresseeData = 1;

    for (size_t signPosition = 0; signPosition < addresseeDataSeparatedbyVerticalDashes.length(); signPosition++) {
        if (addresseeDataSeparatedbyVerticalDashes[signPosition] != '|') {
            singleAddresseeData += addresseeDataSeparatedbyVerticalDashes[signPosition];
        } else {
            switch(numberOfSingleAddresseeData) {
            case 1:
                addressee.setId(atoi(singleAddresseeData.c_str()));
                break;
            case 2:
                addressee.setIdUser(atoi(singleAddresseeData.c_str()));
                break;
            case 3:
                addressee.setName(singleAddresseeData);
                break;
            case 4:
                addressee.setSurname(singleAddresseeData);
                break;
            case 5:
                addressee.setPhoneNumber(singleAddresseeData);
                break;
            case 6:
                addressee.setEmail(singleAddresseeData);
                break;
            case 7:
                addressee.setAddress(singleAddresseeData);
                break;
            }
            singleAddresseeData = "";
            numberOfSingleAddresseeData++;
        }
    }
    return addressee;
}

int FileWithAddressesData::getIdLastAddressee() {
    return idLastAddressee;
}
