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

string SupportiveMethods::swapFirstLetterForLargeOtherForSmall(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

