#include <iostream>
#include <vector>
#include "User.h"
#include "FileWithUsersData.h"
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;

class UserManager {
     int idUser;
     vector <User> users;

    User addDataNewUser();
    int getNewUserId();
    bool loginCheck(string login);
    FileWithUsersData fileWithUsersData;

      public:
    void userRegistration();
    void showAllUsers();

     };
