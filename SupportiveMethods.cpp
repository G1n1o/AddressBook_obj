#include "SupportiveMethods.h"

string SupportiveMethods::readLine() {
    string input;
    getline(cin, input);
    return input;
}


string SupportiveMethods::convertFromIntToString(int number){
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

