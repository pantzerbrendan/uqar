#include "Accounts/A_Account.hh"

A_Account::A_Account(User *owner, u_int id) {
    this->_id = id;
    this->_owner = owner;
    this->_balance = 0;
}

A_Account::~A_Account() {

}

double          A_Account::getBalance() const {
    return (this->_balance);
}

double          A_Account::withdrawal(const double amount) {
    if (amount < 0)
        throw std::string("Ammount can't be negative");
    if ((this->_balance - amount) < 0)
        throw std::string("Insufficient funds");
    this->_balance -= amount;
    return (amount);
}

void            A_Account::deposit(const double amount) {
    if (amount < 0)
        throw std::string("Ammount can't be negative");
    this->_balance += amount;
}
