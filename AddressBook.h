#include <iostream>
#include <vector>
#include "User.h"
#include <windows.h>

using namespace std;

class AddressBook {

    int idUser;
    int idLastUser;
    int idDeletedUser;

    vector <User> users;

    User addDataNewUser();
    int getNewUserId();
    bool loginCheck(string login);
    string readLine();

    public:
    void userRejestration();
    void showAllUsers();


};
