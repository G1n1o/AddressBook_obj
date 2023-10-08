#include "Addressee.h"

void Addressee::setId (int newId) {
    if (newId >= 0) {
        id = newId;
    }
}
void Addressee::setIdUser (int newIdUser) {
    if (newIdUser >= 0) {
        idUser = newIdUser;
    }
}
void Addressee::setName (string newName) {
    name = newName;
}
void Addressee::setSurname (string newSurname) {
    surname = newSurname;
}
void Addressee::setPhoneNumber (string newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}
void Addressee::setAddress (string newAddress) {
    address = newAddress;
}
void Addressee::setEmail (string newEmail) {
    email = newEmail;
}

int Addressee::getId() {
    return id;
}
int Addressee::getIdUser() {
    return idUser;
}
string Addressee::getName() {
    return name;
}
string Addressee::getSurname() {
    return surname;
}
string Addressee::getPhoneNumber() {
    return phoneNumber;
}
string Addressee::getAddress() {
    return address;
}
string Addressee::getEmail() {
    return email;
}


