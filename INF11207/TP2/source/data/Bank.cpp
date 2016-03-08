
#include "data/Bank.hpp"

Bank::Bank() {}

Bank::~Bank()
{
    std::list<A_Account *>::const_iterator acc_iter = this->_accounts.begin();
    std::list<User *>::const_iterator users_iter = this->_users.begin();

    for (; acc_iter != this->_accounts.end(); acc_iter++)
        delete *acc_iter;
    for (; users_iter != this->_users.end(); users_iter++)
        delete *users_iter;
}
