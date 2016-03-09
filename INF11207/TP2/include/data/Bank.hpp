
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

    u_int       maxAID() const;
    std::list<A_Account *>  getAccounts() const;
};

#endif /* !BANK_HPP_ */
