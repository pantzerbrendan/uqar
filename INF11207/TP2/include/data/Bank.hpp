
#ifndef BANK_HPP_
#define BANK_HPP_

#include <list>
#include "Accounts/A_Account.hh"
#include "users/User.hpp"

class Bank
{
private:
    std::list<A_Account *>  _accounts;
    std::list<User *>       _users;

public:
    Bank();
    ~Bank();
};

#endif /* !BANK_HPP_ */
