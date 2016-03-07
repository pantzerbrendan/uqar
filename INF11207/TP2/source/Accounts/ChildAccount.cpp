#include "Accounts/ChildAccount.hh"

ChildAccount::ChildAccount(u_int idParent, User *owner, u_int id) : A_Account(owner, id) {
    this->_idParent = idParent;
}

ChildAccount::~ChildAccount() {

}

double      ChildAccount::withdrawal(const double amount) {
    /* Traitement authorisation */
    try {
        return (A_Account::withdrawal(amount));
    } catch (const std::string &e) {
        throw;
    }
}
