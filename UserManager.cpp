#include "UserManager.h"

void UserManager::userRegistration() {

    User user = addDataNewUser();

    users.push_back(user);
    fileWithUsersData.saveUserDataInFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");

}

User UserManager::addDataNewUser() {
    User user;

    user.setIdUser(getNewUserId());

    do {
        cout << "Podaj login: ";
        user.setLogin(SupportiveMethods::readLine());
    } while (loginCheck(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(SupportiveMethods::readLine());

    return user;
}

int UserManager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getIdUser() + 1;
}

bool UserManager::loginCheck(string login) {
    for (size_t i = 0 ; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::showAllUsers() {
    for (size_t i = 0 ; i < users.size(); i++) {
        cout << users[i].getIdUser()<<endl;
        cout << users[i].getLogin()<<endl;
        cout << users[i].getPassword()<<endl;
    }
}
