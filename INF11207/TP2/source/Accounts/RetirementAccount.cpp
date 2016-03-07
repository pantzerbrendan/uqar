#include "Accounts/RetirementAccount.hh"

RetirementAccount::RetirementAccount(User *owner, u_int id) : A_Account(owner, id) {
    this->_auth = false;
}

RetirementAccount::~RetirementAccount() {

}

double      RetirementAccount::withdrawal(const double amount) {
    if (!this->_auth)
        throw std::string("Transaction refused");
    try {
        return (A_Account::withdrawal(amount));
    } catch (const std::string &e) {
        throw;
    }
}

void        RetirementAccount::setAuth(const bool auth) {
    this->_auth = auth;
}
