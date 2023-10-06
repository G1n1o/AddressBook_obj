#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "User.h"
#include "SupportiveMethods.h"

using namespace std;

class FileWithUsersData {

    const string fileNameWithUsers;

    string replaceUserDataOnDataLineSeparatedVerticalDashes(User user);
    User readUserData(string singleUserDataSeparatedbyVerticalDashes);
    bool isFileEmpty();


public:
    FileWithUsersData(string FILENAMEWITHUSERS) : fileNameWithUsers (FILENAMEWITHUSERS) {};
    vector <User> readUsersFromFile();
    void saveUserDataInFile(User user);


};
