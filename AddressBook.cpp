#include "AddressBook.h"

void AddressBook::userRegistration() {
userManager.userRegistration();
}

void AddressBook::showAllUsers() {
userManager.showAllUsers();
}

void AddressBook::userLogging() {
userManager.userLogging();
addresseeManager.setIdLoggedUser(userManager.getidLoggedUser());
addresseeManager.loadAddressesLoggedUserFile();
}

void AddressBook::changePasswordLoggedUser() {
userManager.changePasswordLoggedUser();
}


void AddressBook::userLogout() {
userManager.userLogout();
addresseeManager.userLogout();

}
void AddressBook::addNewAdrressee(){
addresseeManager.addNewAddressee();
}
