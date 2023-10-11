#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "User.h"
#include "SupportiveMethods.h"

using namespace std;

class FileWithUsersData {

    const string FILE_NAME_WITH_USERS;

    string replaceUserDataOnDataLineSeparatedVerticalDashes(User user);
    User readUserData(string singleUserDataSeparatedbyVerticalDashes);
    bool isFileEmpty(fstream &textFile);


public:
    FileWithUsersData(string fileNameWithUsers) : FILE_NAME_WITH_USERS (fileNameWithUsers) {};
    vector <User> readUsersFromFile();
    void saveUserDataInFile(User user);
    void saveAllUsersDataInFile(vector <User> &users);
};
