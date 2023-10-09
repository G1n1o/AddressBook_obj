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

string SupportiveMethods::getNumber(string text, int signPosition)
{
    string number = "";
    while(isdigit(text[signPosition]) == true)
    {
        number += text[signPosition];
        signPosition ++;
    }
    return number;
}
int SupportiveMethods::convertFromStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}


