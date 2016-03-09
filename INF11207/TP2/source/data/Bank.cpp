
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

u_int   Bank::maxAID() const
{
    std::list<A_Account *>::const_iterator it = this->_accounts.begin();
    u_int id = (*it)->getId();
    for (; it != this->_accounts.end(); it++)
    {
        if ((*it)->getId() > id)
            id = (*it)->getId();
    }
}

std::list<A_Account *>  Bank::getAccounts() const { return this->_accounts; }
