#include <iostream>

using namespace std;

class User {
int idUser;
string login;
string password;

public:
    void setIdUser (int newIdUser);
    void setLogin (string newLogin);
    void setPassword (string newPassword);

    int getIdUser();
    string getLogin();
    string getPassword();

};
