#include "AddresseeManager.h"


void AddresseeManager::addNewAddressee() {
    Addressee addressee;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    addressee = enterDataNewAddress();

    addresses.push_back(addressee);
    cout << (fileWithAddressesData.addAddresseeToFile(addressee) ? "Nowy adresat zostal dodany" : "Blad. Nie udalo sie dodac adresata do pliku" )<< endl;
    system("pause");
}

Addressee AddresseeManager::enterDataNewAddress() {
    Addressee addressee;
    string name, surname, phoneNumber, email, address;
    cout << fileWithAddressesData.getIdLastAddressee() << endl;
    system("pause");
    addressee.setId(fileWithAddressesData.getIdLastAddressee() + 1);
    addressee.setIdUser(ID_LOGGED_USER);

    cout << "Podaj imie: ";
    addressee.setName(SupportiveMethods::readLine());
    addressee.setName(SupportiveMethods::swapFirstLetterForLargeOtherForSmall(addressee.getName()));

    cout << "Podaj nazwisko: ";
    addressee.setSurname(SupportiveMethods::readLine());
    addressee.setSurname(SupportiveMethods::swapFirstLetterForLargeOtherForSmall(addressee.getSurname()));

    cout << "Podaj numer telefonu: ";
    addressee.setPhoneNumber(SupportiveMethods::readLine());

    cout << "Podaj email: ";
    addressee.setEmail(SupportiveMethods::readLine());

    cout << "Podaj adres: ";
    addressee.setAddress(SupportiveMethods::readLine());

    return addressee;
}
 void AddresseeManager::showUserAddresses(){
    system("cls");
    if (!addresses.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Addressee> :: iterator itr = addresses.begin(); itr != addresses.end(); itr++)
        {
            showAddresseeData(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AddresseeManager::showAddresseeData(Addressee addressee)
{
    cout << endl << "Id:                 " << addressee.getId() << endl;
    cout << "Imie:               " << addressee.getName() << endl;
    cout << "Nazwisko:           " << addressee.getSurname() << endl;
    cout << "Numer telefonu:     " << addressee.getPhoneNumber() << endl;
    cout << "Email:              " << addressee.getEmail() << endl;
    cout << "Adres:              " << addressee.getAddress() << endl;
}
void AddresseeManager::searchByName() {
    string nameOfWantedAddressee = "";
    int numberAddressers = 0;

    system("cls");
    if (!addresses.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        nameOfWantedAddressee = SupportiveMethods::readLine();
        nameOfWantedAddressee = SupportiveMethods::swapFirstLetterForLargeOtherForSmall(nameOfWantedAddressee);

        for (vector <Addressee>::iterator  itr = addresses.begin(); itr != addresses.end(); itr++)
        {
            if (itr -> getName() == nameOfWantedAddressee)
            {
                showAddresseeData(*itr);
                numberAddressers++;
            }
        }
        displayNumberofSelectedAddresses(numberAddressers);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AddresseeManager::searchBySurname() {
    string surnameOfWantedAddressee;
    int numberAddressers = 0;

    system("cls");
    if (!addresses.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        surnameOfWantedAddressee = SupportiveMethods::readLine();
        surnameOfWantedAddressee = SupportiveMethods::swapFirstLetterForLargeOtherForSmall(surnameOfWantedAddressee);

        for (vector <Addressee>::iterator itr = addresses.begin(); itr != addresses.end(); itr++)
        {
            if (itr -> getSurname() == surnameOfWantedAddressee)
            {
                showAddresseeData(*itr);
                numberAddressers++;
            }
        }
         displayNumberofSelectedAddresses(numberAddressers);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}

void AddresseeManager::displayNumberofSelectedAddresses(int numberAddressers)
{
    if (numberAddressers == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << numberAddressers << endl << endl;
}

void AddresseeManager::editAddressee()
{
    system("cls");
    int idEditedAddressee = 0;

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEditedAddressee = enterIdSelectedAddress();

    char choice;
    bool isExistingAddress = false;

    for (size_t i = 0; i < addresses.size(); i++)
    {
        if (addresses[i].getId() == idEditedAddressee)
        {
            isExistingAddress = true;
            choice = selectOptionsMenuEdit();

            switch (choice) {

            case '1':
                cout << "Podaj nowe imie: " << endl;
                addresses[i].setName(SupportiveMethods::readLine());
                addresses[i].setName(SupportiveMethods::swapFirstLetterForLargeOtherForSmall(addresses[i].getName()));
                break;

            case '2':
                cout << "Podaj nowe nazwisko: " << endl;
                addresses[i].setSurname(SupportiveMethods::readLine());
                addresses[i].setSurname(SupportiveMethods::swapFirstLetterForLargeOtherForSmall(addresses[i].getSurname()));
                break;

            case '3':
                cout << "Podaj nowy numer telefonu: " << endl;
                addresses[i].setPhoneNumber(SupportiveMethods::readLine());
                break;

            case '4':
                cout << "Podaj nowy adres mailowy: " << endl;
                addresses[i].setEmail(SupportiveMethods::readLine());
                break;

            case '5':
                cout << "Podaj nowy adres: " << endl;
                addresses[i].setAddress(SupportiveMethods::readLine());
                break;

            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;

            default:
                cout << "Nie ma takiej opcji!. Wpisz ponownie!"<< endl;
            }
            fileWithAddressesData.saveChangesAddresseeInFile(addresses[i]);
        }
    }
    if(!isExistingAddress) {
        cout << endl <<"Nie ma w bazie adresata z takim ID" << endl << endl;
    }

    system("pause");
}

int AddresseeManager::enterIdSelectedAddress()
{
    cout << "Podaj numer ID Adresata: ";
    return SupportiveMethods::readNumber();
}

char AddresseeManager::selectOptionsMenuEdit()
{
    char choice;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    choice = SupportiveMethods::readSign();

    return choice;
}

void AddresseeManager::removeAddressee() {

    int idDeletedAddressee = 0;
    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idDeletedAddressee = enterIdSelectedAddress();

    char sign;
    bool isExistingAddress = false;

    for (size_t i = 0; i < addresses.size(); i++) {
        if (addresses[i].getId() == idDeletedAddressee) {
            isExistingAddress = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            sign = SupportiveMethods::readSign();
            if (sign == 't') {
                fileWithAddressesData.saveRemovesAddresseeInFile(addresses[i]);
                addresses.erase(addresses.begin() + i);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
            }  else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
            }
        }
    }
    if (!isExistingAddress) {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
}

