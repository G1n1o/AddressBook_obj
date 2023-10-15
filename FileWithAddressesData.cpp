#include "FileWithAddressesData.h"

bool FileWithAddressesData::addAddresseeToFile(Addressee addressee) {
    string lineWithUserData = "";
    fstream textFile;
    textFile.open(FILE_NAME_WITH_ADDRESSES.c_str(), ios::out | ios::app);

    if (textFile.good()) {
        lineWithUserData = replaceDataAddresseeOnLinesSeparatedVerticalDashes(addressee);

        if (isFileEmpty(textFile)) {
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
    return  (textFile.tellg() == 0) ? true : false;
}

vector <Addressee> FileWithAddressesData::loadAddressesLoggedUserFile(int idLoggedUser) {
    vector <Addressee> addresses;
    Addressee addressee;
    string singleAddresseeDataSeparatedbyVerticalDashes = "";
    string dataLastAddresseeInFile = "";
    fstream textFile;
    textFile.open(FILE_NAME_WITH_ADDRESSES.c_str(), ios::in);

    if (textFile.good()) {
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
    return SupportiveMethods::convertFromStringToInt(SupportiveMethods::getNumber(singleAddresseeDataSeparatedbyVerticalDashes, 0));
}

int FileWithAddressesData::getIdUserFromDataSeparatedByVerticalDashes(string singleAddresseeDataSeparatedbyVerticalDashes) {
    int startPositionIdUser = singleAddresseeDataSeparatedbyVerticalDashes.find_first_of('|') + 1;
    return SupportiveMethods::convertFromStringToInt(SupportiveMethods::getNumber(singleAddresseeDataSeparatedbyVerticalDashes, startPositionIdUser));
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

void FileWithAddressesData::saveChangesAddresseeInFile (Addressee addressee) {
    int idEditedAddressee = 0;
    string editedLine ="";
    string line = "";
    ifstream addressesFile (FILE_NAME_WITH_ADDRESSES.c_str());
    ofstream userAddressesFile ("addresses_temp.txt");

    while(getline(addressesFile, line))    {
        idEditedAddressee = stoi(line);
        if (idEditedAddressee == addressee.getId()) {
            editedLine = replaceDataAddresseeOnLinesSeparatedVerticalDashes(addressee);
            userAddressesFile << editedLine << endl;
        } else {
            userAddressesFile << line << endl;
        }
    }
    addressesFile.close();
    userAddressesFile.close();
    remove(FILE_NAME_WITH_ADDRESSES.c_str());
    rename("addresses_temp.txt", FILE_NAME_WITH_ADDRESSES.c_str());
    removeLastEmptyLine();

}

void FileWithAddressesData::saveRemovesAddresseeInFile (Addressee addressee) {
    int idDeletedAddressee = 0;
    string line = "";
    ifstream addressesFile (FILE_NAME_WITH_ADDRESSES.c_str());
    ofstream userAddressesFile ("addresses_temp.txt");

    while(getline(addressesFile, line)) {
        idDeletedAddressee = stoi(line);

        if (idDeletedAddressee == addressee.getId()) {
            continue;
        } else {
            userAddressesFile << line << endl ;
        }
    }

    if (addressee.getId() == idLastAddressee) {
        idLastAddressee--;
    }

    addressesFile.close();
    userAddressesFile.close();
    remove(FILE_NAME_WITH_ADDRESSES.c_str());
    rename("addresses_temp.txt", FILE_NAME_WITH_ADDRESSES.c_str());
    removeLastEmptyLine();
}

void FileWithAddressesData::removeLastEmptyLine() {
    vector <string> lines;
    string line;

    ifstream inputFile(FILE_NAME_WITH_ADDRESSES);

    if (inputFile.good()) {
        while (getline(inputFile, line)) {
            lines.push_back(line);
        }
    } else {
        cout << "Nie udalo sie otworzyc pliku" << endl;
    }
    inputFile.close();

    ofstream outputFile(FILE_NAME_WITH_ADDRESSES);
    if (outputFile.good()) {
        for (size_t i = 0; i < lines.size(); ++i) {
            if (i < lines.size() -1 ) {
                outputFile << lines[i] << endl;
            } else {
                outputFile << lines[i];
            }
        }
    } else {
        cout << "Nie udalo sie otworzyc pliku" << endl;
    }
    outputFile.close();
}

