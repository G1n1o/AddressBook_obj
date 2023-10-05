#include "User.h"

void User::setIdUser(int newIdUser) {
    if (newIdUser >= 0) {
        idUser = newIdUser;
    }
}
void User::setLogin (string newLogin) {
    login = newLogin;
}
void User::setPassword (string newPassword) {
    password = newPassword;
}

int User::getIdUser() {
    return idUser;
}
string User::getLogin() {
    return login;
}
string User::getPassword() {
    return password;
}

