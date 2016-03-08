
#ifndef BANK_HPP_
#define BANK_HPP_

#include <list>
#include "Accounts/A_Account.hh"

class Bank
{
private:
    std::list<A_Account *>  _accounts;

public:
    Bank();
    ~Bank();
};

#endif /* !BANK_HPP_ */
