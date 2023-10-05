#include <iostream>
#include <vector>
#include <fstream>
#include "User.h"
#include "SupportiveMethods.h"

using namespace std;

class FileWithUsersData {

     string fileNameWithUsers;
     fstream textFile;

     string replaceUserDataOnDataLineSeparatedVerticalDashes(User user);
      bool isFileEmpty();

  public:
      FileWithUsersData();
      void saveUserDataInFile(User user);


};
