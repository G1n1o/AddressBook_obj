#include "FileWithUsersData.h"

void FileWithUsersData::saveUserDataInFile(User user) {
    fstream textFile;
    string lineWithUserData = "";
    textFile.open(FILE_NAME_WITH_USERS.c_str(), ios::app);

    if (textFile.good() == true) {
        lineWithUserData = replaceUserDataOnDataLineSeparatedVerticalDashes(user);

        if (isFileEmpty(textFile) == true) {
            textFile << lineWithUserData;
        } else {
            textFile << endl << lineWithUserData ;
        }
    } else
        cout << "Nie udalo sie otworzyc pliku " << FILE_NAME_WITH_USERS << " i zapisac w nim danych." << endl;
    textFile.close();
}

bool FileWithUsersData::isFileEmpty(fstream &textFile) {
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

string FileWithUsersData::replaceUserDataOnDataLineSeparatedVerticalDashes(User user) {
    string lineWithUserData = "";
    lineWithUserData += SupportiveMethods::convertFromIntToString(user.getIdUser())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';
    return lineWithUserData;
}

vector <User> FileWithUsersData::readUsersFromFile() {
    User user;
    vector <User> users;
    fstream textFile;
    string singleUserDataSeparatedbyVerticalDashes = "";

    textFile.open(FILE_NAME_WITH_USERS.c_str(), ios::in);

    if (textFile.good() == true) {
        while (getline(textFile, singleUserDataSeparatedbyVerticalDashes)) {
            user = readUserData(singleUserDataSeparatedbyVerticalDashes);
            users.push_back(user);
        }

    }
    textFile.close();
    return users;
}

User FileWithUsersData::readUserData(string singleUserDataSeparatedbyVerticalDashes) {
    User user;
    string singleUserData = "";
    int numberSingleDataUser = 1;

    for (size_t itemSign = 0; itemSign < singleUserDataSeparatedbyVerticalDashes.length(); itemSign++) {
        if (singleUserDataSeparatedbyVerticalDashes[itemSign] != '|') {
            singleUserData += singleUserDataSeparatedbyVerticalDashes[itemSign];
        } else {
            switch(numberSingleDataUser) {
            case 1:
                user.setIdUser(atoi(singleUserData.c_str()));
                break;
            case 2:
                user.setLogin(singleUserData);
                break;
            case 3:
                user.setPassword(singleUserData);
                break;
            }
            singleUserData = "";
            numberSingleDataUser++;
        }
    }
    return user;
}

void FileWithUsersData::saveAllUsersDataInFile(vector <User> &users) {
    fstream textFile;
    string lineWithUserData = "";
    vector <User>::iterator itrEnd = --users.end();

    textFile.open(FILE_NAME_WITH_USERS.c_str(), ios::out);

    if (textFile.good() == true) {
        for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
            lineWithUserData = replaceUserDataOnDataLineSeparatedVerticalDashes(*itr);

            if (itr == itrEnd) {
                textFile << lineWithUserData;
            } else {
                textFile << lineWithUserData << endl;
            }
            lineWithUserData = "";
        }
    } else {
        cout << "Nie mozna otworzyc pliku " << FILE_NAME_WITH_USERS << endl;
    }
    textFile.close();
}


