#include "AddressBook.h"

AddressBook::AddressBook() {
   userManager.readUsersFromFile();
}

void AddressBook::userRegistration() {
userManager.userRegistration();
}

void AddressBook::showAllUsers() {
userManager.showAllUsers();
}
