#include "FileWithAddressesData.h"

void FileWithAddressesData::addAddresseeToFile(Addressee addressee)
{
    string lineWithUserData = "";
    fstream textFile;
    textFile.open(fileNameWithAddresses.c_str(), ios::out | ios::app);

    if (textFile.good() == true)
    {
        lineWithUserData = replaceDataAddresseeOnLinesSeparatedVerticalDashes(addressee);

        if (isFileEmpty(textFile) == true)
        {
            textFile << lineWithUserData;
        }
        else
        {
            textFile << endl << lineWithUserData ;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    textFile.close();
    system("pause");
}
string FileWithAddressesData::replaceDataAddresseeOnLinesSeparatedVerticalDashes(Addressee addressee)
{
    string lineWithAddresseeData = "";

    lineWithAddresseeData += SupportiveMethods::convertFromIntToString(addressee.getId()) + '|';
    lineWithAddresseeData += SupportiveMethods::convertFromIntToString(addressee.getIdUser()) + '|';
    lineWithAddresseeData += addressee.getName() + '|';
    lineWithAddresseeData += addressee.getSurname() + '|';
    lineWithAddresseeData += addressee.getPhoneNumber() + '|';
    lineWithAddresseeData += addressee.getEmail() + '|';
    lineWithAddresseeData += addressee.getAddress() + '|';

    return lineWithAddresseeData;
}

bool FileWithAddressesData::isFileEmpty(fstream &textFile) {
    textFile.seekg(0, ios::end);
    if (textFile.tellg() == 0)
        return true;
    else
        return false;
}
