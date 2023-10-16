#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "User.h"
#include "SupportiveMethods.h"
#include "TextFile.h"

using namespace std;

class FileWithUsersData : public TextFile {

    string replaceUserDataOnDataLineSeparatedVerticalDashes(User user);
    User readUserData(string singleUserDataSeparatedbyVerticalDashes);


public:
    FileWithUsersData(string fileNameWithUsers) : TextFile(fileNameWithUsers) {};
    vector <User> readUsersFromFile();
    void saveUserDataInFile(User user);
    void saveAllUsersDataInFile(vector <User> &users);
};
