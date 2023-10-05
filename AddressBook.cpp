#include "AddressBook.h"

AddressBook::AddressBook() {
fileNameWithUsers = "Users.txt";
}

void AddressBook::userRejestration() {

    User user = addDataNewUser();

    users.push_back(user);
    saveUserDataInFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");

}
User AddressBook::addDataNewUser() {
    User user;

    user.setIdUser(getNewUserId());

    do {
        cout << "Podaj login: ";
        user.setLogin(readLine());
    } while (loginCheck(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(readLine());

    return user;
}

int AddressBook::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getIdUser() + 1;
}

bool AddressBook::loginCheck(string login) {
    for (size_t i = 0 ; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

string AddressBook::readLine() {
    string input;
    getline(cin, input);
    return input;
}

void AddressBook::showAllUsers() {
    for (size_t i = 0 ; i < users.size(); i++) {
        cout << users[i].getIdUser()<<endl;
        cout << users[i].getLogin()<<endl;
        cout << users[i].getPassword()<<endl;
    }
}

void AddressBook::saveUserDataInFile(User user)
{
    fstream textFile;
    string lineWithUserData = "";
    textFile.open(fileNameWithUsers.c_str(), ios::app);

    if (textFile.good() == true)
    {
        lineWithUserData = replaceUserDataOnDataLineSeparatedVerticalDashes(user);

        if (isFileEmpty(textFile) == true)
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

string AddressBook::replaceUserDataOnDataLineSeparatedVerticalDashes(User user)
{
    string lineWithUserData = "";

    lineWithUserData += convertFromIntToString(user.getIdUser())+ '|';
    lineWithUserData += user.getLogin() + '|';
    lineWithUserData += user.getPassword() + '|';

    return lineWithUserData;
}
string AddressBook::convertFromIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
bool AddressBook::isFileEmpty(fstream &textFile)
{
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}
