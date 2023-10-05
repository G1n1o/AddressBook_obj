#include "AddressBook.h"

void AddressBook::userRejestration() {

    User user = addDataNewUser();

    users.push_back(user);
    //saveUserDataInFile(user);

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
