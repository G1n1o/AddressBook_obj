#ifndef ADDRESSEE_H
#define ADDRESSEE_H

#include <iostream>

using namespace std;

class Addressee {
    int id, idUser;
    string name, surname, phoneNumber, address, email;

public:
    Addressee(int id=0, int idUser=0, string name="", string surname="", string phoneNumber="", string address="", string email="") {
        this->id = id;
        this->idUser = idUser;
        this->name = name;
        this->surname = surname;
        this->phoneNumber = phoneNumber;
        this->email = email;
        this->address = address;
    };
    void setId(int newId);
    void setIdUser(int newIdUser);
    void setName(string newName);
    void setSurname(string newSurname);
    void setPhoneNumber(string newPhoneNumber);
    void setAddress(string newAddress);
    void setEmail(string newEmail);

    int getId();
    int getIdUser();
    string getName();
    string getSurname();
    string getPhoneNumber();
    string getAddress();
    string getEmail();

};

#endif
