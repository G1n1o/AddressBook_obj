#include <iostream>
#include <vector>
#include "User.h"
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

class AddressBook {

    int idUser;
    int idLastUser;
    int idDeletedUser;
    string fileNameWithUsers;

    vector <User> users;

    User addDataNewUser();
    int getNewUserId();
    bool loginCheck(string login);
    string readLine();
    void saveUserDataInFile(User user);
    string replaceUserDataOnDataLineSeparatedVerticalDashes(User user);
    string convertFromIntToString(int number);
    bool isFileEmpty(fstream &textFile);

    public:
    AddressBook();
    void userRejestration();
    void showAllUsers();


};
