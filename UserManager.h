#include <iostream>
#include <vector>
#include "User.h"
#include "FileWithUsersData.h"
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

class UserManager {
     int idLoggedUser;
     vector <User> users;

    User addDataNewUser();
    int getNewUserId();
    bool loginCheck(string login);
    FileWithUsersData fileWithUsersData;

      public:
    UserManager(string fileNameWithUsers) : fileWithUsersData(fileNameWithUsers) {};
    void readUsersFromFile();
    void userRegistration();
    void userLogging();
    void changePasswordLoggedUser();
    void showAllUsers();
     };
