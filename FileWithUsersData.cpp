#include "FileWithUsersData.h"

FileWithUsersData::FileWithUsersData() {
fileNameWithUsers = "Users.txt";
}

void FileWithUsersData::saveUserDataInFile(User user){

    string lineWithUserData = "";
    textFile.open(fileNameWithUsers.c_str(), ios::app);

    if (textFile.good() == true)
    {
        lineWithUserData = replaceUserDataOnDataLineSeparatedVerticalDashes(user);

        if (isFileEmpty() == true)
        {
            textFile << lineWithUserData;
        }
        else
        {
            textFile << endl << lineWithUserData ;
        }
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << fileNameWithUsers << " i zapisac w nim danych." << endl;
    textFile.close();
}

bool FileWithUsersData::isFileEmpty(){
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}

string FileWithUsersData::replaceUserDataOnDataLineSeparatedVerticalDashes(User user){
    string lineWithUserData = "";

    lineWithUserData += SupportiveMethods::convertFromIntToString(user.getIdUser())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}

